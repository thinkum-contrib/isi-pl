;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; systems.lisp

#|--------------------------- BEGIN LICENSE BLOCK ---------------------------+
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
+---------------------------- END LICENSE BLOCK ----------------------------|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR KWD-SYSTEMS-DEFINE NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-IN-MODULE NULL)
(CL:DEFVAR SGT-SYSTEMS-STELLA-CONS NULL)
(CL:DEFVAR KWD-SYSTEMS-FINALIZE NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-DEFMODULE NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-DEFSYSTEM NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-DEFCLASS NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-DEFSLOT NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-DEFUN NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-DEFMETHOD NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-LOAD-FILE NULL)
(CL:DEFVAR KWD-SYSTEMS-COMMON-LISP NULL)
(CL:DEFVAR KWD-SYSTEMS-FUNCTION NULL)
(CL:DEFVAR KWD-SYSTEMS-DIRECTORY NULL)
(CL:DEFVAR KWD-SYSTEMS-FILES NULL)
(CL:DEFVAR KWD-SYSTEMS-REQUIRED-SYSTEMS NULL)
(CL:DEFVAR KWD-SYSTEMS-LISP-ONLY-FILES NULL)
(CL:DEFVAR KWD-SYSTEMS-CPP-ONLY-FILES NULL)
(CL:DEFVAR KWD-SYSTEMS-JAVA-ONLY-FILES NULL)
(CL:DEFVAR KWD-SYSTEMS-PREPROCESSED-FILES NULL)
(CL:DEFVAR KWD-SYSTEMS-CARDINAL-MODULE NULL)
(CL:DEFVAR KWD-SYSTEMS-ROOT-SOURCE-DIRECTORY NULL)
(CL:DEFVAR KWD-SYSTEMS-ROOT-NATIVE-DIRECTORY NULL)
(CL:DEFVAR KWD-SYSTEMS-ROOT-BINARY-DIRECTORY NULL)
(CL:DEFVAR KWD-SYSTEMS-BANNER NULL)
(CL:DEFVAR KWD-SYSTEMS-COPYRIGHT-HEADER NULL)
(CL:DEFVAR KWD-SYSTEMS-PRODUCTION-SETTINGS NULL)
(CL:DEFVAR KWD-SYSTEMS-DEVELOPMENT-SETTINGS NULL)
(CL:DEFVAR KWD-SYSTEMS-FINALIZATION-FUNCTION NULL)
(CL:DEFVAR KWD-SYSTEMS-JAVA NULL)
(CL:DEFVAR KWD-SYSTEMS-LISP NULL)
(CL:DEFVAR KWD-SYSTEMS-CPP NULL)
(CL:DEFVAR KWD-SYSTEMS-LISP-BINARY NULL)
(CL:DEFVAR SGT-SYSTEMS-STELLA-PROPERTY-LIST NULL)
(CL:DEFVAR SGT-SYSTEMS-STELLA-LIST NULL)
(CL:DEFVAR KWD-SYSTEMS-DEVELOPMENT-SETTINGS? NULL)
(CL:DEFVAR KWD-SYSTEMS-PRODUCTION-SETTINGS? NULL)
(CL:DEFVAR KWD-SYSTEMS-FORCE-TRANSLATION? NULL)
(CL:DEFVAR KWD-SYSTEMS-FORCE-RECOMPILATION? NULL)
(CL:DEFVAR KWD-SYSTEMS-TWO-PASS? NULL)
(CL:DEFVAR KWD-SYSTEMS-LOAD-SYSTEM? NULL)
(CL:DEFVAR KWD-SYSTEMS-STARTUP? NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-MAKE-SYSTEM NULL)
(CL:DEFVAR KWD-SYSTEMS-USE-COMMON-LISP-STRUCTS NULL)
(CL:DEFVAR KWD-SYSTEMS-STELLA NULL)
(CL:DEFVAR KWD-SYSTEMS-WARN-ABOUT-UNDEFINED-METHODS NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-UNLESS NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-SYSTEM-STARTED-UP? NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-STARTUP-TIME-PROGN NULL)
(CL:DEFVAR KWD-SYSTEMS-EARLY-INITS NULL)
(CL:DEFVAR KWD-SYSTEMS-MODULES NULL)
(CL:DEFVAR KWD-SYSTEMS-PUBLIC? NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-TRUE NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-STARTUP NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-FALSE NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-FOREACH NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-PHASE NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-IN NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-INTERVAL NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-PHASE-TO-INTEGER NULL)
(CL:DEFVAR KWD-SYSTEMS-FINAL NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-DO NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-SETQ NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-*STARTUP-TIME-PHASE* NULL)
(CL:DEFVAR KWD-SYSTEMS-WHITE-SPACE NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-CONFIGURATION-TABLE NULL)
(CL:DEFVAR KWD-SYSTEMS-ROOT-DIRECTORY NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-STARTUP-SYSTEMS NULL)
(CL:DEFVAR SYM-SYSTEMS-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STELLA-MODULE* *CHARACTER-TYPE-TABLE* NULL-INTEGER
  *CURRENT-STELLA-FEATURES* TRUE-WRAPPER FALSE-WRAPPER NIL-LIST STANDARD-ERROR
  *TRANSLATOROUTPUTLANGUAGE* *CURRENTFILE* *MODULE* TRUE FALSE *TRANSLATIONUNITS*
  *EVALUATIONTREE* *EVALUATIONPARENTTREE* EOL NIL *TRANSLATIONPHASE*
  *CURRENTSYSTEMDEFINITION* STANDARD-OUTPUT))

;;; (DEFUN (EVALUATE-COMMAND OBJECT) ...)

(CL:DEFUN EVALUATE-COMMAND (COMMAND FINALIZE?)
  (CL:LET*
   ((*TRANSLATIONERRORS* 0) (*TRANSLATIONWARNINGS* 0)
    (*IGNORETRANSLATIONERRORS?* FALSE) (*TRANSLATIONUNITS* NULL)
    (*TRANSLATIONPHASE* KWD-SYSTEMS-DEFINE) (*EVALUATIONTREE* NULL))
   (CL:DECLARE
    (CL:SPECIAL *TRANSLATIONERRORS* *TRANSLATIONWARNINGS*
     *IGNORETRANSLATIONERRORS?* *TRANSLATIONUNITS* *TRANSLATIONPHASE*
     *EVALUATIONTREE*))
   (CL:DECLARE (CL:TYPE CL:FIXNUM *TRANSLATIONERRORS* *TRANSLATIONWARNINGS*))
   (CL:LET* ((OPERATOR NULL) (RESULT NULL))
    (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE COMMAND)))
     (CL:COND
      ((CL:EQ TEST-VALUE-000 SGT-SYSTEMS-STELLA-CONS)
       (CL:PROGN (CL:SETQ OPERATOR (%%VALUE COMMAND))
        (CL:COND
         ((SUBTYPE-OF-SYMBOL? (SAFE-PRIMARY-TYPE OPERATOR))
          (CL:PROGN
           (CL:COND
            ((CL:EQ OPERATOR SYM-SYSTEMS-STELLA-IN-MODULE)
             (HANDLE-IN-MODULE-TREE COMMAND FALSE))
            (CL:T
             (CL:COND
              ((DECLARATION-TREE? COMMAND) (CL:SETQ *TRANSLATIONUNITS* (LIST))
               (WALK-TOP-LEVEL-TREE COMMAND FALSE)
               (CL:CASE (LENGTH (REVERSE *TRANSLATIONUNITS*))
                (0
                 (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
                  (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
                   "While evaluating '" *EVALUATIONTREE*)
                  (CL:WHEN (CL:NOT (CL:EQ *EVALUATIONPARENTTREE* NULL))
                   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) EOL "' inside '"
                    *EVALUATIONPARENTTREE*))
                  (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "':" EOL)
                  (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
                   "Couldn't translate `" COMMAND "'")
                  (CL:ERROR
                   (NEW-EVALUATION-EXCEPTION (THE-STRING-READER STREAM-000)))))
                (1 (CL:SETQ RESULT (%THE-OBJECT (FIRST *TRANSLATIONUNITS*))))
                (CL:OTHERWISE
                 (CL:LET* ((RESULTS NIL))
                  (CL:LET*
                   ((UNIT NULL) (ITER-000 (%THE-CONS-LIST *TRANSLATIONUNITS*))
                    (COLLECT-000 NULL))
                   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
                    (CL:PROGN (CL:SETQ UNIT (%%VALUE ITER-000))
                     (CL:SETQ ITER-000 (%%REST ITER-000)))
                    (CL:IF (CL:EQ COLLECT-000 NULL)
                     (CL:PROGN
                      (CL:SETQ COLLECT-000 (CONS (%THE-OBJECT UNIT) NIL))
                      (CL:IF (CL:EQ RESULTS NIL) (CL:SETQ RESULTS COLLECT-000)
                       (ADD-CONS-TO-END-OF-CONS-LIST RESULTS COLLECT-000)))
                     (CL:PROGN
                      (CL:SETF (%%REST COLLECT-000)
                       (CONS (%THE-OBJECT UNIT) NIL))
                      (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
                  (CL:SETQ RESULT RESULTS)))))
              ((STRING-EQUAL? (%SYMBOL-NAME OPERATOR) "in-package"))
              (CL:T (%EVALUATE COMMAND)))))))
         (CL:T (%EVALUATE COMMAND)))))
      ((SUBTYPE-OF-KEYWORD? TEST-VALUE-000) (CL:PROGN (CL:SETQ RESULT COMMAND)))
      ((SUBTYPE-OF-SURROGATE? TEST-VALUE-000)
       (CL:PROGN (CL:SETQ RESULT COMMAND)))
      (CL:T (%EVALUATE COMMAND))))
    (CL:WHEN (CL:AND (CL:NOT (TRANSLATION-ERRORS?)) FINALIZE?)
     (CL:SETQ *TRANSLATIONPHASE* KWD-SYSTEMS-FINALIZE)
     (CL:IF (CL:NOT (CL:EQ *CURRENTSYSTEMDEFINITION* NULL))
      (RUN-SYSTEM-FINALIZATION *CURRENTSYSTEMDEFINITION*)
      (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
       "Can't run finalization because *currentSystemDefinition* is not set."
       EOL)))
    (CL:RETURN-FROM EVALUATE-COMMAND RESULT))))

;;; (DEFUN LOAD-FILE ...)

(CL:DEFUN %LOAD-FILE (FILE)
  "Read STELLA commands from `file' and evaluate them.
The file should begin with an `in-module' declaration that specifies
the module within which all remaining commands are to be evaluated
The remaining commands are evaluated one-by-one, applying the function
`evaluate' to each of them."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING FILE))
  #+MCL
  (CL:CHECK-TYPE FILE CL:SIMPLE-STRING)
  (CL:WHEN (CL:NOT (PROBE-FILE? FILE))
   (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "File `" FILE
     "' does not exist.")
    (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))
  (CL:LET*
   ((TOPLEVELINVOCATION? (CL:EQ *CURRENTFILE* STELLA::NULL-STRING))
    (SKIPCOMMAND? FALSE) (SEENINMODULE? FALSE) (COMMANDS NIL) (INPUTSTREAM NULL))
   (CL:UNWIND-PROTECT
    (CL:LET* ((*CURRENTFILE* (FILE-BASE-NAME FILE)))
     (CL:DECLARE (CL:SPECIAL *CURRENTFILE*))
     (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING *CURRENTFILE*))
     (CL:SETQ INPUTSTREAM (NEW-INPUT-FILE-STREAM FILE))
     (CL:LET* ((*MODULE* *MODULE*) (*CONTEXT* *MODULE*))
      (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
      (CL:LET* ((TREE NULL) (ITER-000 (S-EXPRESSIONS INPUTSTREAM)))
       (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ TREE (%VALUE ITER-000))
        (CL:TAGBODY
         (CL:COND
          ((CL:EQ (SAFE-PRIMARY-TYPE TREE) SGT-SYSTEMS-STELLA-CONS)
           (CL:PROGN
            (CL:MULTIPLE-VALUE-SETQ (SKIPCOMMAND? SEENINMODULE?)
             (HANDLE-IN-MODULE-TREE TREE SEENINMODULE?))
            (CL:WHEN SKIPCOMMAND? (CL:GO :CONTINUE))
            (CL:LET* ((OPERATOR (%%VALUE TREE)))
             (CL:COND
              ((SUBTYPE-OF-SYMBOL? (SAFE-PRIMARY-TYPE OPERATOR))
               (CL:PROGN
                (CL:COND
                 ((CL:OR (CL:EQ OPERATOR SYM-SYSTEMS-STELLA-DEFMODULE)
                   (CL:EQ OPERATOR SYM-SYSTEMS-STELLA-DEFSYSTEM)
                   (CL:EQ OPERATOR SYM-SYSTEMS-STELLA-DEFCLASS)
                   (CL:EQ OPERATOR SYM-SYSTEMS-STELLA-DEFSLOT)
                   (CL:EQ OPERATOR SYM-SYSTEMS-STELLA-DEFUN)
                   (CL:EQ OPERATOR SYM-SYSTEMS-STELLA-DEFMETHOD))
                  (EVALUATE-COMMAND TREE FALSE))
                 (CL:T
                  (CL:IF (CL:NOT (CL:EQ (LOOKUP-COMMAND OPERATOR) NULL))
                   (CL:SETQ COMMANDS (CONS TREE COMMANDS))
                   (EVALUATE-COMMAND TREE FALSE))))))
              (CL:T (EVALUATE-COMMAND TREE FALSE))))))
          (CL:T (EVALUATE-COMMAND TREE FALSE)))
         :CONTINUE)))
      (CL:LET* ((*TRANSLATIONPHASE* KWD-SYSTEMS-FINALIZE))
       (CL:DECLARE (CL:SPECIAL *TRANSLATIONPHASE*))
       (RUN-SYSTEM-FINALIZATION *CURRENTSYSTEMDEFINITION*))
      (CL:LET* ((TREE NULL) (ITER-001 (REVERSE COMMANDS)))
       (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
        (CL:PROGN (CL:SETQ TREE (%%VALUE ITER-001))
         (CL:SETQ ITER-001 (%%REST ITER-001)))
        (EVALUATE-COMMAND TREE TRUE)))))
    (CL:WHEN TOPLEVELINVOCATION? (SWEEP-TRANSIENTS))
    (CL:WHEN (CL:NOT (CL:EQ INPUTSTREAM NULL)) (FREE INPUTSTREAM))))
  :VOID)

(CL:DEFUN LOAD-FILE-EVALUATOR-WRAPPER (ARGUMENTS)
  (%LOAD-FILE (%WRAPPER-VALUE (%%VALUE ARGUMENTS)))
  :VOID)

(CL:DEFMACRO LOAD-FILE (CL:&WHOLE EXPRESSION CL:&REST IGNORE)
  "Read STELLA commands from `file' and evaluate them.
The file should begin with an `in-module' declaration that specifies
the module within which all remaining commands are to be evaluated
The remaining commands are evaluated one-by-one, applying the function
`evaluate' to each of them."
  (CL:DECLARE (CL:IGNORE IGNORE))
  (CL:LET ((*IGNORETRANSLATIONERRORS?* FALSE))
   (CL-INCREMENTALLY-TRANSLATE EXPRESSION)))

(CL:SETF (CL:MACRO-FUNCTION (CL:QUOTE /STELLA/LOAD-FILE)) (CL:MACRO-FUNCTION (CL:QUOTE LOAD-FILE)))

;;; (DEFGLOBAL *SYSTEMDEFINITIONS* ...)

(CL:DEFVAR *SYSTEMDEFINITIONS* NULL
  "A list of all defined systems.")

;;; (DEFUN (MAKE-SYSTEM-DEFINITION-FILE-NAME FILE-NAME) ...)

(CL:DEFUN MAKE-SYSTEM-DEFINITION-FILE-NAME (NAME)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING NAME))
  #+MCL
  (CL:CHECK-TYPE NAME CL:SIMPLE-STRING)
  (CL:RETURN-FROM MAKE-SYSTEM-DEFINITION-FILE-NAME
   (CONCATENATE (SYSTEM-DEFINITIONS-DIRECTORY) (DIRECTORY-SEPARATOR-STRING)
    (STRING-DOWNCASE NAME) "-system.ste")))

;;; (DEFUN (PARSE-LIST-OF-FILE-PATHS (CONS OF STRING-WRAPPER)) ...)

(CL:DEFUN PARSE-LIST-OF-FILE-PATHS (FILES)
  (CL:LET* ((STRINGS NIL))
   (CL:LET* ((FILESPEC NULL) (ITER-000 FILES))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:PROGN (CL:SETQ FILESPEC (%%VALUE ITER-000))
      (CL:SETQ ITER-000 (%%REST ITER-000)))
     (CL:SETQ STRINGS (CONS (WRAP-STRING (IMPLODE-PATHNAME FILESPEC)) STRINGS))))
   (CL:RETURN-FROM PARSE-LIST-OF-FILE-PATHS (REVERSE STRINGS))))

;;; (DEFUN (DEFINE-SYSTEM SYSTEM-DEFINITION) ...)

(CL:DEFUN DEFINE-SYSTEM (NAME OPTIONS)
  (CL:LET* ((STRINGNAME STELLA::NULL-STRING))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRINGNAME))
   (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE NAME)))
    (CL:COND
     ((SUBTYPE-OF-STRING? TEST-VALUE-000)
      (CL:PROGN (CL:SETQ STRINGNAME (%WRAPPER-VALUE NAME))))
     ((SUBTYPE-OF-SYMBOL? TEST-VALUE-000)
      (CL:PROGN (CL:SETQ STRINGNAME (STRING-DOWNCASE (%SYMBOL-NAME NAME)))))
     (CL:T
      (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "Illegal system name: "
       NAME)
      (CL:RETURN-FROM DEFINE-SYSTEM NULL))))
   (CL:LET* ((SELF-000 (NEW-SYSTEM-DEFINITION)))
    (CL:SETF (%NAME SELF-000) STRINGNAME)
    (CL:LET* ((SYSTEM SELF-000) (REQUIRED-SYSTEM NULL))
     (CL:LET* ((SELF-001 (NEW-PROPERTY-LIST)))
      (CL:SETF (%THE-PLIST SELF-001) OPTIONS)
      (CL:LET* ((PLIST SELF-001))
       (CL:LET* ((VALUE-000 NULL))
        (CL:LET* ((S NULL) (ITER-000 (%THE-CONS-LIST *SYSTEMDEFINITIONS*)))
         (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
          (CL:PROGN (CL:SETQ S (%%VALUE ITER-000))
           (CL:SETQ ITER-000 (%%REST ITER-000)))
          (CL:WHEN (STRING-EQL? (%NAME S) STRINGNAME) (CL:SETQ VALUE-000 S)
           (CL:RETURN))))
        (CL:LET* ((OLDSYSTEM VALUE-000))
         (CL:LET* ((VALUE NULL) (KEY NULL) (ITER-001 (%THE-PLIST PLIST)))
          (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
           (CL:SETQ KEY (%%VALUE ITER-001))
           (CL:PROGN (CL:SETQ VALUE (%%VALUE (%%REST ITER-001)))
            (CL:SETQ ITER-001 (%%REST (%%REST ITER-001))))
           (CL:LET* ((TEST-VALUE-001 KEY))
            (CL:COND
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-DIRECTORY)
              (CL:SETF (%DIRECTORY SYSTEM) (IMPLODE-PATHNAME VALUE)))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-FILES)
              (CL:SETF (%FILES SYSTEM) (PARSE-LIST-OF-FILE-PATHS VALUE)))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-REQUIRED-SYSTEMS)
              (CL:SETF (%REQUIRED-SYSTEMS SYSTEM) VALUE)
              (CL:LET* ((SYS NULL) (ITER-002 VALUE))
               (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-002 NIL)) DO
                (CL:PROGN (CL:SETQ SYS (%%VALUE ITER-002))
                 (CL:SETQ ITER-002 (%%REST ITER-002)))
                (CL:SETQ REQUIRED-SYSTEM
                 (GET-SYSTEM-DEFINITION (%WRAPPER-VALUE SYS)))
                (CL:WHEN
                 (CL:AND (CL:NOT (STRING-EQUAL? (%WRAPPER-VALUE SYS) "stella"))
                  (CL:NOT (%LOADED? REQUIRED-SYSTEM)))
                 (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
                  "Making dependent system " (%WRAPPER-VALUE SYS) EOL)
                 (%MAKE-SYSTEM (%WRAPPER-VALUE SYS) *TRANSLATOROUTPUTLANGUAGE*
                  NIL)
                 (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) EOL EOL)))))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-LISP-ONLY-FILES)
              (CL:SETF (%LISP-ONLY-FILES SYSTEM)
               (PARSE-LIST-OF-FILE-PATHS VALUE)))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-CPP-ONLY-FILES)
              (CL:SETF (%CPP-ONLY-FILES SYSTEM)
               (PARSE-LIST-OF-FILE-PATHS VALUE)))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-JAVA-ONLY-FILES)
              (CL:SETF (%JAVA-ONLY-FILES SYSTEM)
               (PARSE-LIST-OF-FILE-PATHS VALUE)))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-PREPROCESSED-FILES)
              (CL:SETF (%PREPROCESSED-FILES SYSTEM)
               (PARSE-LIST-OF-FILE-PATHS VALUE)))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-CARDINAL-MODULE)
              (CL:SETF (%CARDINAL-MODULE SYSTEM) (%WRAPPER-VALUE VALUE)))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-ROOT-SOURCE-DIRECTORY)
              (CL:SETF (%SOURCE-ROOT-DIRECTORY SYSTEM) (%WRAPPER-VALUE VALUE)))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-ROOT-NATIVE-DIRECTORY)
              (CL:SETF (%NATIVE-ROOT-DIRECTORY SYSTEM) (%WRAPPER-VALUE VALUE)))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-ROOT-BINARY-DIRECTORY)
              (CL:SETF (%BINARY-ROOT-DIRECTORY SYSTEM) (%WRAPPER-VALUE VALUE)))
             ((CL:OR (CL:EQ TEST-VALUE-001 KWD-SYSTEMS-BANNER)
               (CL:EQ TEST-VALUE-001 KWD-SYSTEMS-COPYRIGHT-HEADER))
              (CL:SETF (%BANNER SYSTEM) (%WRAPPER-VALUE VALUE)))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-PRODUCTION-SETTINGS)
              (CL:SETF (%PRODUCTION-SETTINGS SYSTEM) VALUE))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-DEVELOPMENT-SETTINGS)
              (CL:SETF (%DEVELOPMENT-SETTINGS SYSTEM) VALUE))
             ((CL:EQ TEST-VALUE-001 KWD-SYSTEMS-FINALIZATION-FUNCTION)
              (CL:SETF (%FINALIZATION-FUNCTION SYSTEM) VALUE))
             (CL:T
              (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
               (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" TEST-VALUE-001
                "' is not a valid case option")
               (CL:ERROR
                (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))))))
         (PUSH *SYSTEMDEFINITIONS* SYSTEM)
         (CL:WHEN (CL:NOT (CL:EQ OLDSYSTEM NULL))
          (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "Redefining system `"
           (%NAME SYSTEM) "'" EOL EOL)
          (REMOVE *SYSTEMDEFINITIONS* OLDSYSTEM))
         (CL:RETURN-FROM DEFINE-SYSTEM SYSTEM)))))))))

;;; (DEFUN (DEFSYSTEM SYSTEM-DEFINITION) ...)

(CL:DEFUN %DEFSYSTEM (NAME OPTIONS)
  "Define a system of files that collectively define
a Stella application.
   Required options are:
   :directory -- the path from the Stella root directory to the directory
                 containing the system files.  Can be a string or a list
                 of strings (do not include directory separators).
   :files -- a list of files in the system, containing strings and lists
             of strings; the latter defines exploded paths to files
             in subdirectories.
   Optional options are:
   :required-systems -- a list of systems (strings) that should be loaded
                        prior to loading this system.
   :cardinal-module -- the name (a string) of the principal module for this
                       system.
   :copyright-header -- string with a header for inclusion into all translated
                        files produced by Stella.
   :lisp-only-files  -- Like the :files keyword, but these are only included
   :cpp-only-files      in the translation for the specific language, namely
   :java-only-files     Common Lisp, C++ or Java"
  (CL:RETURN-FROM %DEFSYSTEM (DEFINE-SYSTEM NAME OPTIONS)))

(CL:DEFUN DEFSYSTEM-EVALUATOR-WRAPPER (ARGUMENTS)
  (CL:RETURN-FROM DEFSYSTEM-EVALUATOR-WRAPPER
   (%DEFSYSTEM (%%VALUE ARGUMENTS) (%%REST ARGUMENTS))))

(CL:DEFMACRO DEFSYSTEM (CL:&WHOLE EXPRESSION CL:&REST IGNORE)
  "Define a system of files that collectively define
a Stella application.
   Required options are:
   :directory -- the path from the Stella root directory to the directory
                 containing the system files.  Can be a string or a list
                 of strings (do not include directory separators).
   :files -- a list of files in the system, containing strings and lists
             of strings; the latter defines exploded paths to files
             in subdirectories.
   Optional options are:
   :required-systems -- a list of systems (strings) that should be loaded
                        prior to loading this system.
   :cardinal-module -- the name (a string) of the principal module for this
                       system.
   :copyright-header -- string with a header for inclusion into all translated
                        files produced by Stella.
   :lisp-only-files  -- Like the :files keyword, but these are only included
   :cpp-only-files      in the translation for the specific language, namely
   :java-only-files     Common Lisp, C++ or Java"
  (CL:DECLARE (CL:IGNORE IGNORE))
  (CL:LET ((*IGNORETRANSLATIONERRORS?* FALSE))
   (CL-INCREMENTALLY-TRANSLATE EXPRESSION)))

(CL:SETF (CL:MACRO-FUNCTION (CL:QUOTE /STELLA/DEFSYSTEM)) (CL:MACRO-FUNCTION (CL:QUOTE DEFSYSTEM)))

;;; (DEFUN (GET-SYSTEM-DEFINITION SYSTEM-DEFINITION) ...)

(CL:DEFUN GET-SYSTEM-DEFINITION (NAME)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING NAME))
  #+MCL
  (CL:CHECK-TYPE NAME CL:SIMPLE-STRING)
  (CL:LET* ((VALUE-000 NULL))
   (CL:LET* ((S NULL) (ITER-000 (%THE-CONS-LIST *SYSTEMDEFINITIONS*)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:PROGN (CL:SETQ S (%%VALUE ITER-000))
      (CL:SETQ ITER-000 (%%REST ITER-000)))
     (CL:WHEN (STRING-EQUAL? (%NAME S) NAME) (CL:SETQ VALUE-000 S) (CL:RETURN))))
   (CL:LET* ((SYSTEM VALUE-000))
    (CL:WHEN (CL:EQ SYSTEM NULL)
     (CL:LET* ((SYSTEMFILENAME (MAKE-SYSTEM-DEFINITION-FILE-NAME NAME)))
      (CL:WHEN (CL:NOT (PROBE-FILE? SYSTEMFILENAME))
       (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-ERROR) "ERROR>> File "
        SYSTEMFILENAME " does not exist." EOL "   Can't define system " NAME EOL)
       (CL:RETURN-FROM GET-SYSTEM-DEFINITION NULL))
      (%LOAD-FILE SYSTEMFILENAME)
      (CL:LET* ((VALUE-001 NULL))
       (CL:LET* ((S NULL) (ITER-001 (%THE-CONS-LIST *SYSTEMDEFINITIONS*)))
        (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
         (CL:PROGN (CL:SETQ S (%%VALUE ITER-001))
          (CL:SETQ ITER-001 (%%REST ITER-001)))
         (CL:WHEN (STRING-EQUAL? (%NAME S) NAME) (CL:SETQ VALUE-001 S)
          (CL:RETURN))))
       (CL:SETQ SYSTEM VALUE-001))
      (CL:WHEN (CL:EQ SYSTEM NULL)
       (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-ERROR)
        "ERROR>>  Can't find a system definition for system " NAME EOL
        "   within file " SYSTEMFILENAME "." EOL))))
    (CL:RETURN-FROM GET-SYSTEM-DEFINITION SYSTEM))))

;;; (DEFUN (GET-CARDINAL-MODULE MODULE) ...)

(CL:DEFUN GET-CARDINAL-MODULE (SYSTEM)
  (CL:LET* ((NAME (%CARDINAL-MODULE SYSTEM)) (MODULE NULL))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING NAME))
   (CL:WHEN (CL:NOT (CL:EQ NAME STELLA::NULL-STRING))
    (CL:SETQ MODULE (GET-STELLA-MODULE NAME FALSE))
    (CL:WHEN (CL:EQ MODULE NULL)
     (CL:SETQ MODULE (GET-STELLA-MODULE (STRING-UPCASE NAME) FALSE))))
   (CL:WHEN (CL:EQ MODULE NULL)
    (CL:WARN "No cardinal module defined for system: `~A'~%" SYSTEM))
   (CL:RETURN-FROM GET-CARDINAL-MODULE MODULE)))

;;; (DEFUN HELP-GET-SYSTEM-FILES ...)

(CL:DEFUN HELP-GET-SYSTEM-FILES (FILENAME COLLECTION PROBEFILE?)
  (CL:WHEN (CL:OR (CL:NOT PROBEFILE?) (PROBE-FILE? FILENAME))
   (PUSH COLLECTION (WRAP-STRING FILENAME)))
  :VOID)

;;; (DEFUN (GET-SYSTEM-FILES (LIST OF STRING-WRAPPER)) ...)

(CL:DEFUN GET-SYSTEM-FILES (SYSTEM TYPE PROBEFILES?)
  (CL:LET* ((FILES (NEW-LIST)) (FILENAME STELLA::NULL-STRING))
   (CL:LET*
    ((*CURRENTSYSTEMDEFINITION* (GET-SYSTEM-DEFINITION (%NAME SYSTEM)))
     (*CURRENTSYSTEMDEFINITIONSUBDIRECTORY*
      (CL:IF (CL:NOT (CL:EQ *CURRENTSYSTEMDEFINITION* NULL))
       (%DIRECTORY *CURRENTSYSTEMDEFINITION*) STELLA::NULL-STRING)))
    (CL:DECLARE
     (CL:SPECIAL *CURRENTSYSTEMDEFINITION*
      *CURRENTSYSTEMDEFINITIONSUBDIRECTORY*))
    (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING *CURRENTSYSTEMDEFINITIONSUBDIRECTORY*))
    (CL:IF (CL:NOT (CL:EQ *CURRENTSYSTEMDEFINITION* NULL))
     (CL:PROGN
      (CL:LET* ((F NULL) (ITER-000 (%FILES *CURRENTSYSTEMDEFINITION*)))
       (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
        (CL:PROGN (CL:SETQ F (%%VALUE ITER-000))
         (CL:SETQ ITER-000 (%%REST ITER-000)))
        (CL:COND
         ((CL:EQ TYPE KWD-SYSTEMS-JAVA)
          (CL:SETQ FILENAME
           (%WRAPPER-VALUE
            (JAVA-TRANSLATE-CLASS-NAMESTRING
             (WRAP-STRING (CONCATENATE "Startup-" (%WRAPPER-VALUE F)))))))
         (CL:T (CL:SETQ FILENAME (MAKE-FILE-NAME-FROM-RELATIVE-PATH F TYPE))))
        (HELP-GET-SYSTEM-FILES FILENAME FILES PROBEFILES?)))
      (CL:COND
       ((CL:EQ TYPE KWD-SYSTEMS-JAVA)
        (CL:WHEN (CL:EQ (GET-CARDINAL-MODULE *CURRENTSYSTEMDEFINITION*) NULL)
         (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
          "No cardinal module defined for system `" (%NAME SYSTEM) "'" EOL EOL)
         (CL:RETURN-FROM GET-SYSTEM-FILES NIL-LIST))
        (CL:LET*
         ((CLASS NULL)
          (ITER-001
           (ALL-CLASSES (GET-CARDINAL-MODULE *CURRENTSYSTEMDEFINITION*) TRUE)))
         (CL:LOOP WHILE (NEXT? ITER-001) DO (CL:SETQ CLASS (%VALUE ITER-001))
          (CL:SETQ FILENAME (JAVA-MAKE-CODE-OUTPUT-FILE-NAME CLASS FALSE))
          (HELP-GET-SYSTEM-FILES FILENAME FILES PROBEFILES?)))
        (CL:SETQ FILENAME
         (JAVA-MAKE-CODE-OUTPUT-FILE-NAME
          (JAVA-YIELD-FLOTSAM-CLASS-NAME
           (GET-CARDINAL-MODULE *CURRENTSYSTEMDEFINITION*))
          FALSE))
        (HELP-GET-SYSTEM-FILES FILENAME FILES PROBEFILES?))
       (CL:T)))
     (CL:WARN "Can't find a system named `~A'~%" (%NAME SYSTEM))))
   (CL:RETURN-FROM GET-SYSTEM-FILES FILES)))

;;; (DEFUN CLEAN-SYSTEM ...)

(CL:DEFUN CLEAN-SYSTEM (SYSTEMNAME)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SYSTEMNAME))
  #+MCL
  (CL:CHECK-TYPE SYSTEMNAME CL:SIMPLE-STRING)
  (CL:LET* ((SYSTEM (GET-SYSTEM-DEFINITION SYSTEMNAME)))
   (CL:WHEN (CL:EQ SYSTEM NULL) (CL:RETURN-FROM CLEAN-SYSTEM))
   (CL:LET*
    ((F NULL)
     (ITER-000 (%THE-CONS-LIST (GET-SYSTEM-FILES SYSTEM KWD-SYSTEMS-LISP TRUE))))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:PROGN (CL:SETQ F (%%VALUE ITER-000))
      (CL:SETQ ITER-000 (%%REST ITER-000)))
     (DELETE-FILE (%WRAPPER-VALUE F))))
   (CL:LET*
    ((F NULL)
     (ITER-001 (%THE-CONS-LIST (GET-SYSTEM-FILES SYSTEM KWD-SYSTEMS-JAVA TRUE))))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
     (CL:PROGN (CL:SETQ F (%%VALUE ITER-001))
      (CL:SETQ ITER-001 (%%REST ITER-001)))
     (DELETE-FILE (%WRAPPER-VALUE F))))
   (CL:LET*
    ((F NULL)
     (ITER-002 (%THE-CONS-LIST (GET-SYSTEM-FILES SYSTEM KWD-SYSTEMS-CPP TRUE))))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-002 NIL)) DO
     (CL:PROGN (CL:SETQ F (%%VALUE ITER-002))
      (CL:SETQ ITER-002 (%%REST ITER-002)))
     (DELETE-FILE (%WRAPPER-VALUE F))))
   (CL:LET*
    ((F NULL)
     (ITER-003
      (%THE-CONS-LIST (GET-SYSTEM-FILES SYSTEM KWD-SYSTEMS-LISP-BINARY TRUE))))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-003 NIL)) DO
     (CL:PROGN (CL:SETQ F (%%VALUE ITER-003))
      (CL:SETQ ITER-003 (%%REST ITER-003)))
     (DELETE-FILE (%WRAPPER-VALUE F)))))
  :VOID)

;;; (DEFUN COMPUTE-OPTIMIZATION-LEVELS ...)

(CL:DEFUN COMPUTE-OPTIMIZATION-LEVELS (SYSTEM PRODUCTIONMODE?)
  (CL:LET* ((SETTINGS NULL))
   (CL:IF PRODUCTIONMODE? (CL:SETQ SETTINGS (%PRODUCTION-SETTINGS SYSTEM))
    (CL:SETQ SETTINGS (%DEVELOPMENT-SETTINGS SYSTEM)))
   (CL:WHEN (CL:EQ SETTINGS NULL)
    (CL:SETQ SETTINGS (GET-QUOTED-TREE "((3 2 3 3) \"/STELLA\")" "/STELLA")))
   (SET-OPTIMIZATION-LEVELS (%WRAPPER-VALUE (NTH SETTINGS 0))
    (%WRAPPER-VALUE (NTH SETTINGS 1)) (%WRAPPER-VALUE (NTH SETTINGS 2))
    (%WRAPPER-VALUE (NTH SETTINGS 3))))
  :VOID)

;;; (DEFUN (LISP-KEYWORD-TO-STELLA-KEYWORD KEYWORD) ...)

(CL:DEFUN LISP-KEYWORD-TO-STELLA-KEYWORD (KEY)
  (CL:LET* ((STELLAKEYWORD NULL)) (cl:when (cl:typep key 'CL:KEYWORD)
        (cl:setq stellaKeyword (stellify key)))
   (CL:RETURN-FROM LISP-KEYWORD-TO-STELLA-KEYWORD STELLAKEYWORD)))

;;; (DEFUN (VET-OPTIONS PROPERTY-LIST) ...)

(CL:DEFUN VET-OPTIONS (PLIST LEGALOPTIONS)
  (CL:LET* ((PROPERTYLIST NULL))
   (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE PLIST)))
    (CL:COND
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-SYSTEMS-STELLA-PROPERTY-LIST)
      (CL:PROGN (CL:SETQ PROPERTYLIST PLIST)))
     ((CL:EQ TEST-VALUE-000 SGT-SYSTEMS-STELLA-CONS)
      (CL:PROGN
       (CL:LET* ((SELF-000 (NEW-PROPERTY-LIST)))
        (CL:SETF (%THE-PLIST SELF-000) PLIST) (CL:SETQ PROPERTYLIST SELF-000))))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-SYSTEMS-STELLA-LIST)
      (CL:PROGN
       (CL:LET* ((SELF-001 (NEW-PROPERTY-LIST)))
        (CL:SETF (%THE-PLIST SELF-001) (%THE-CONS-LIST PLIST))
        (CL:SETQ PROPERTYLIST SELF-001))))
     (CL:T (CL:WARN "Illegal argument passed to 'vet-options'")
      (CL:RETURN-FROM VET-OPTIONS (NEW-PROPERTY-LIST)))))
   (CL:LET* ((VALUE NULL) (KEY NULL) (ITER-000 (%THE-PLIST PROPERTYLIST)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ KEY (%%VALUE ITER-000))
     (CL:PROGN (CL:SETQ VALUE (%%VALUE (%%REST ITER-000)))
      (CL:SETQ ITER-000 (%%REST (%%REST ITER-000))))
     (CL:WHEN
      (CL:OR (CL:NOT (STELLA-OBJECT? KEY)) (CL:NOT (KEYWORD? KEY))
       (CL:AND (CL:NOT (CL:EQ LEGALOPTIONS NULL))
        (CL:NOT (MEMBER? LEGALOPTIONS KEY))))
      (CL:SETQ VALUE VALUE)
      (CL:WHEN (CL:NOT (STELLA-OBJECT? KEY))
       (CL:LET* ((NEWPLIST (NEW-PROPERTY-LIST)))
        (CL:LET* ((VALUE NULL) (KEY NULL) (ITER-001 (%THE-PLIST PROPERTYLIST)))
         (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
          (CL:SETQ KEY (%%VALUE ITER-001))
          (CL:PROGN (CL:SETQ VALUE (%%VALUE (%%REST ITER-001)))
           (CL:SETQ ITER-001 (%%REST (%%REST ITER-001))))
          (INSERT-AT NEWPLIST (STELLIFY KEY) (STELLIFY VALUE))))
        (CL:SETF (%THE-PLIST PROPERTYLIST) (%THE-PLIST NEWPLIST)))
       (VET-OPTIONS PROPERTYLIST LEGALOPTIONS)
       (CL:RETURN-FROM VET-OPTIONS PROPERTYLIST))
      (REMOVE-AT PROPERTYLIST KEY)
      (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
       "Skipping illegal option: `" KEY "'" EOL EOL)
      (CL:IF (KEYWORD? KEY)
       (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "   Legal options are: `"
        LEGALOPTIONS "'" EOL EOL)
       (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
        "   Option must be a keyword." EOL))
      (VET-OPTIONS PROPERTYLIST LEGALOPTIONS)
      (CL:RETURN-FROM VET-OPTIONS PROPERTYLIST))))
   (CL:RETURN-FROM VET-OPTIONS PROPERTYLIST)))

;;; (DEFUN (MAKE-SYSTEM BOOLEAN) ...)

(CL:DEFUN %MAKE-SYSTEM (SYSTEMNAME LANGUAGE OPTIONS)
  "Translate all out-of-date files of system `systemName'
into `language' and then compile and load them (the latter is only possible
for Lisp right now).  The following keyword/value `options' are recognized:

`:two-pass?': if true, all files will be scanned twice, once to
load the signatures of objects defined in them, and once to actually
translate the definitions.  Otherwise, the translator will make one pass in
the case that the system is already loaded (and is being remade), and two
passes otherwise.

`:development-settings?' (default false): if true translation will favor
safe, readable and debuggable code over efficiency (according to the value
of `:development-settings' on the system definition).  If false, efficiency
will be favored instead (according to the value of `:production-settings'
on the system definition).

`:production-settings?' (default true): inverse to `:development-settings?'.

`:force-translation?' (default false): if true, files will be translated
whether or not their translations are up-to-date.

`:force-recompilation?' (default false): if true, translated files will be
recompiled whether or not their compilations are up-to-date (only supported
in Lisp right now).

`:load-system?' (default true): if true, compiled files will be loaded into
the current STELLA image (only supported in Lisp right now).

`:startup?' (default true): if true, the system startup function will
be called once all files have been loaded."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SYSTEMNAME))
  #+MCL
  (CL:CHECK-TYPE SYSTEMNAME CL:SIMPLE-STRING)
  (CL:SETQ LANGUAGE (STELLIFY LANGUAGE))
  (CL:LET* ((*TRANSLATOROUTPUTLANGUAGE* LANGUAGE))
   (CL:DECLARE (CL:SPECIAL *TRANSLATOROUTPUTLANGUAGE*))
   (%SET-TRANSLATOR-OUTPUT-LANGUAGE LANGUAGE)
   (CL:LET* ((SELF-000 (NEW-PROPERTY-LIST)))
    (CL:SETF (%THE-PLIST SELF-000) OPTIONS)
    (CL:LET*
     ((PLIST SELF-000) (DEVELOPMENTSETTINGS? FALSE) (FORCETRANSLATION? FALSE)
      (FORCERECOMPILATION? FALSE)
      (TWOPASS?
       (CL:AND (CL:NOT (CL:EQ (GET-SYSTEM-DEFINITION SYSTEMNAME) NULL))
        (CL:NOT (%LOADED? (GET-SYSTEM-DEFINITION SYSTEMNAME)))))
      (LOADSYSTEM? (CL:EQ LANGUAGE KWD-SYSTEMS-COMMON-LISP))
      (STARTUPSYSTEM? (CL:EQ LANGUAGE KWD-SYSTEMS-COMMON-LISP))
      (UPDATEDSYSTEM? FALSE) (SYSTEM (GET-SYSTEM-DEFINITION SYSTEMNAME)))
     (CL:WHEN (CL:EQ SYSTEM NULL)
      (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
       "Can't find a declaration for system named " SYSTEMNAME EOL
       "  Possibly a global path name needs to be set." EOL)
      (CL:RETURN-FROM %MAKE-SYSTEM FALSE))
     (VET-OPTIONS PLIST
      (GET-QUOTED-TREE
       "((:TWO-PASS? :DEVELOPMENT-SETTINGS? :PRODUCTION-SETTINGS? :FORCE-TRANSLATION? :FORCE-RECOMPILATION? :LOAD-SYSTEM? :STARTUP?) \"/STELLA\")"
       "/STELLA"))
     (CL:LET* ((VALUE NULL) (KEY NULL) (ITER-000 (%THE-PLIST PLIST)))
      (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
       (CL:SETQ KEY (%%VALUE ITER-000))
       (CL:PROGN (CL:SETQ VALUE (%%VALUE (%%REST ITER-000)))
        (CL:SETQ ITER-000 (%%REST (%%REST ITER-000))))
       (CL:LET* ((TRUEVALUE? (EQL? VALUE TRUE-WRAPPER)))
        (CL:LET* ((TEST-VALUE-000 KEY))
         (CL:COND
          ((CL:EQ TEST-VALUE-000 KWD-SYSTEMS-DEVELOPMENT-SETTINGS?)
           (CL:SETQ DEVELOPMENTSETTINGS? TRUEVALUE?))
          ((CL:EQ TEST-VALUE-000 KWD-SYSTEMS-PRODUCTION-SETTINGS?)
           (CL:SETQ DEVELOPMENTSETTINGS? (CL:NOT TRUEVALUE?)))
          ((CL:EQ TEST-VALUE-000 KWD-SYSTEMS-FORCE-TRANSLATION?)
           (CL:SETQ FORCETRANSLATION? TRUEVALUE?))
          ((CL:EQ TEST-VALUE-000 KWD-SYSTEMS-FORCE-RECOMPILATION?)
           (CL:SETQ FORCERECOMPILATION? TRUEVALUE?))
          ((CL:EQ TEST-VALUE-000 KWD-SYSTEMS-TWO-PASS?)
           (CL:SETQ TWOPASS? TRUEVALUE?))
          ((CL:EQ TEST-VALUE-000 KWD-SYSTEMS-LOAD-SYSTEM?)
           (CL:SETQ LOADSYSTEM? TRUEVALUE?))
          ((CL:EQ TEST-VALUE-000 KWD-SYSTEMS-STARTUP?)
           (CL:SETQ STARTUPSYSTEM? TRUEVALUE?))
          (CL:T
           (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
            (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" TEST-VALUE-000
             "' is not a valid case option")
            (CL:ERROR
             (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))))))
     (CL:WHEN
      (CL:OR FORCERECOMPILATION?
       (CL:AND (CL:NOT (%LOADED? SYSTEM))
        (CL:OR FORCETRANSLATION?
         (SYSTEM-NEEDS-TRANSLATION? SYSTEMNAME LANGUAGE))))
      (LOAD-PREPROCESSED-FILES SYSTEMNAME))
     (CL:SETQ UPDATEDSYSTEM?
      (TRANSLATE-SYSTEM SYSTEMNAME LANGUAGE KWD-SYSTEMS-TWO-PASS?
       (CL:IF TWOPASS? TRUE-WRAPPER FALSE-WRAPPER) KWD-SYSTEMS-FORCE-TRANSLATION?
       (CL:IF FORCETRANSLATION? TRUE-WRAPPER FALSE-WRAPPER)
       KWD-SYSTEMS-DEVELOPMENT-SETTINGS?
       (CL:IF DEVELOPMENTSETTINGS? TRUE-WRAPPER FALSE-WRAPPER)))
     (CL:WHEN
      (CL:AND LOADSYSTEM?
       (LOAD-SYSTEM SYSTEMNAME LANGUAGE KWD-SYSTEMS-FORCE-RECOMPILATION?
        (CL:IF FORCERECOMPILATION? TRUE-WRAPPER FALSE-WRAPPER)
        KWD-SYSTEMS-STARTUP? (CL:IF STARTUPSYSTEM? TRUE-WRAPPER FALSE-WRAPPER)))
      (CL:SETQ UPDATEDSYSTEM? TRUE))
     (CL:RETURN-FROM %MAKE-SYSTEM UPDATEDSYSTEM?)))))

(CL:DEFUN MAKE-SYSTEM-EVALUATOR-WRAPPER (ARGUMENTS)
  (CL:RETURN-FROM MAKE-SYSTEM-EVALUATOR-WRAPPER
   (CL:IF
    (%MAKE-SYSTEM (%WRAPPER-VALUE (%%VALUE ARGUMENTS))
     (%%VALUE (%%REST ARGUMENTS)) (%%REST (%%REST ARGUMENTS)))
    TRUE-WRAPPER FALSE-WRAPPER)))

(CL:DEFMACRO MAKE-SYSTEM (CL:&WHOLE EXPRESSION CL:&REST IGNORE)
  "Translate all out-of-date files of system `systemName'
into `language' and then compile and load them (the latter is only possible
for Lisp right now).  The following keyword/value `options' are recognized:

`:two-pass?': if true, all files will be scanned twice, once to
load the signatures of objects defined in them, and once to actually
translate the definitions.  Otherwise, the translator will make one pass in
the case that the system is already loaded (and is being remade), and two
passes otherwise.

`:development-settings?' (default false): if true translation will favor
safe, readable and debuggable code over efficiency (according to the value
of `:development-settings' on the system definition).  If false, efficiency
will be favored instead (according to the value of `:production-settings'
on the system definition).

`:production-settings?' (default true): inverse to `:development-settings?'.

`:force-translation?' (default false): if true, files will be translated
whether or not their translations are up-to-date.

`:force-recompilation?' (default false): if true, translated files will be
recompiled whether or not their compilations are up-to-date (only supported
in Lisp right now).

`:load-system?' (default true): if true, compiled files will be loaded into
the current STELLA image (only supported in Lisp right now).

`:startup?' (default true): if true, the system startup function will
be called once all files have been loaded."
  (CL:DECLARE (CL:IGNORE IGNORE))
  (CL:LET ((*IGNORETRANSLATIONERRORS?* FALSE))
   (CL-INCREMENTALLY-TRANSLATE EXPRESSION)))

(CL:SETF (CL:MACRO-FUNCTION (CL:QUOTE /STELLA/MAKE-SYSTEM)) (CL:MACRO-FUNCTION (CL:QUOTE MAKE-SYSTEM)))

;;; (DEFUN RUN-SYSTEM-FINALIZATION ...)

(CL:DEFUN RUN-SYSTEM-FINALIZATION (SYSTEM)
  (CL:LET* ((FNNAME STELLA::NULL-STRING) (FINALIZATIONFN NULL))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING FNNAME))
   (CL:WHEN (CL:NOT (CL:EQ FNNAME STELLA::NULL-STRING))
    (CL:SETQ FINALIZATIONFN (LOOKUP-FUNCTION-BY-NAME FNNAME)))
   (CL:WHEN (CL:NOT (CL:EQ FINALIZATIONFN NULL))
    (CL:FUNCALL (%FUNCTION-CODE FINALIZATIONFN))))
  :VOID)

;;; (DEFUN (SYSTEM-DEFINITION-SOURCE-FILES (CONS OF STRING-WRAPPER)) ...)

(CL:DEFUN SYSTEM-DEFINITION-SOURCE-FILES (SYSTEM)
  (CL:LET* ((FILES (COPY-CONS-LIST (%FILES SYSTEM))))
   (CL:COND
    ((CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-SYSTEMS-COMMON-LISP)
     (CL:SETQ FILES (SUBTRACT FILES (%JAVA-ONLY-FILES SYSTEM)))
     (CL:SETQ FILES (SUBTRACT FILES (%CPP-ONLY-FILES SYSTEM))))
    ((CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-SYSTEMS-JAVA)
     (CL:SETQ FILES (SUBTRACT FILES (%LISP-ONLY-FILES SYSTEM)))
     (CL:SETQ FILES (SUBTRACT FILES (%CPP-ONLY-FILES SYSTEM))))
    ((CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-SYSTEMS-CPP)
     (CL:SETQ FILES (SUBTRACT FILES (%LISP-ONLY-FILES SYSTEM)))
     (CL:SETQ FILES (SUBTRACT FILES (%JAVA-ONLY-FILES SYSTEM))))
    (CL:T
     (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
      (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" *TRANSLATOROUTPUTLANGUAGE*
       "' is not a valid case option")
      (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
   (CL:RETURN-FROM SYSTEM-DEFINITION-SOURCE-FILES FILES)))

;;; (DEFUN (FILES-PLUS-SYSTEM-STARTUP (CONS OF STRING-WRAPPER)) ...)

(CL:DEFUN FILES-PLUS-SYSTEM-STARTUP (FILES)
  (CL:RETURN-FROM FILES-PLUS-SYSTEM-STARTUP
   (CONCATENATE FILES (CONS-LIST (WRAP-STRING (SYSTEM-STARTUP-FILE-NAME NULL))))))

;;; (DEFUN (SYSTEM-DEFINITION-NATIVE-FILES (CONS OF STRING-WRAPPER)) ...)

(CL:DEFUN SYSTEM-DEFINITION-NATIVE-FILES (SYSTEM)
  (CL:LET* ((FILES (COPY-CONS-LIST (%FILES SYSTEM))))
   (CL:COND
    ((CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-SYSTEMS-COMMON-LISP)
     (CL:SETQ FILES (UNION FILES (%LISP-ONLY-FILES SYSTEM)))
     (CL:WHEN
      (MEMB? *CURRENT-STELLA-FEATURES* KWD-SYSTEMS-USE-COMMON-LISP-STRUCTS)
      (CL:SETQ FILES
       (CONS (WRAP-STRING (CL-YIELD-STRUCT-CLASS-FILE-NAME (%NAME SYSTEM)))
        FILES))))
    ((CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-SYSTEMS-JAVA)
     (CL:SETQ FILES (UNION FILES (%JAVA-ONLY-FILES SYSTEM))))
    ((CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-SYSTEMS-CPP)
     (CL:SETQ FILES (UNION FILES (%CPP-ONLY-FILES SYSTEM))))
    (CL:T
     (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
      (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" *TRANSLATOROUTPUTLANGUAGE*
       "' is not a valid case option")
      (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
   (CL:RETURN-FROM SYSTEM-DEFINITION-NATIVE-FILES FILES)))

;;; (DEFUN (SYSTEM-LOADED? BOOLEAN) ...)

(CL:DEFUN SYSTEM-LOADED? (NAME)
  "Return `true' if system `name' has been loaded."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING NAME))
  #+MCL
  (CL:CHECK-TYPE NAME CL:SIMPLE-STRING)
  (CL:LET* ((TEST-VALUE-000 FALSE))
   (CL:IF (STRING-EQUAL? NAME "STELLA") (CL:SETQ TEST-VALUE-000 TRUE)
    (CL:LET* ((FOUND?-000 FALSE))
     (CL:LET* ((SYS NULL) (ITER-000 (%THE-CONS-LIST *SYSTEMDEFINITIONS*)))
      (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
       (CL:PROGN (CL:SETQ SYS (%%VALUE ITER-000))
        (CL:SETQ ITER-000 (%%REST ITER-000)))
       (CL:WHEN (CL:AND (STRING-EQUAL? (%NAME SYS) NAME) (%LOADED? SYS))
        (CL:SETQ FOUND?-000 TRUE) (CL:RETURN))))
     (CL:SETQ TEST-VALUE-000 FOUND?-000)))
   (CL:LET* ((VALUE-000 TEST-VALUE-000))
    (CL:RETURN-FROM SYSTEM-LOADED? VALUE-000))))

;;; (DEFUN CLEAR-SYSTEM ...)

(CL:DEFUN CLEAR-SYSTEM (NAME)
  "Clears out the system definition named `name'.  If
`name' is `null', then clear out all system definitions.  This function
is useful when changes have been made to the system definition, and one
wants to have it reloaded from the standard location in the file system."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING NAME))
  #+MCL
  (CL:CHECK-TYPE NAME CL:SIMPLE-STRING)
  (CL:IF (CL:EQ NAME STELLA::NULL-STRING)
   (CL:SETQ *SYSTEMDEFINITIONS* (NEW-LIST))
   (CL:LET* ((VALUE-000 NULL))
    (CL:LET* ((S NULL) (ITER-000 (%THE-CONS-LIST *SYSTEMDEFINITIONS*)))
     (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
      (CL:PROGN (CL:SETQ S (%%VALUE ITER-000))
       (CL:SETQ ITER-000 (%%REST ITER-000)))
      (CL:WHEN (STRING-EQL? (%NAME S) NAME) (CL:SETQ VALUE-000 S) (CL:RETURN))))
    (CL:LET* ((SYS VALUE-000))
     (CL:WHEN (CL:NOT (CL:EQ SYS NULL)) (REMOVE *SYSTEMDEFINITIONS* SYS)))))
  :VOID)

;;; (DEFUN LOAD-PREPROCESSED-FILES ...)

(CL:DEFUN LOAD-PREPROCESSED-FILES (SYSTEMNAME)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SYSTEMNAME))
  #+MCL
  (CL:CHECK-TYPE SYSTEMNAME CL:SIMPLE-STRING)
  (CL:WHEN
   (CL:OR (CL:NOT (RUNNING-AS-LISP?))
    (CL:EQ (%PREPROCESSED-FILES (GET-SYSTEM-DEFINITION SYSTEMNAME)) NULL))
   (CL:RETURN-FROM LOAD-PREPROCESSED-FILES))
  (CL:LET* ((*TRANSLATOROUTPUTLANGUAGE* KWD-SYSTEMS-COMMON-LISP))
   (CL:DECLARE (CL:SPECIAL *TRANSLATOROUTPUTLANGUAGE*))
   (CL:LET*
    ((*CURRENTSYSTEMDEFINITION* (GET-SYSTEM-DEFINITION SYSTEMNAME))
     (*CURRENTSYSTEMDEFINITIONSUBDIRECTORY*
      (CL:IF (CL:NOT (CL:EQ *CURRENTSYSTEMDEFINITION* NULL))
       (%DIRECTORY *CURRENTSYSTEMDEFINITION*) STELLA::NULL-STRING)))
    (CL:DECLARE
     (CL:SPECIAL *CURRENTSYSTEMDEFINITION*
      *CURRENTSYSTEMDEFINITIONSUBDIRECTORY*))
    (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING *CURRENTSYSTEMDEFINITIONSUBDIRECTORY*))
    (CL:IF (CL:NOT (CL:EQ *CURRENTSYSTEMDEFINITION* NULL))
     (CL:PROGN
      (CL:LET* ((PREPROCESSEDFILES NIL))
       (CL:LET*
        ((F NULL) (ITER-000 (%PREPROCESSED-FILES *CURRENTSYSTEMDEFINITION*))
         (COLLECT-000 NULL))
        (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
         (CL:PROGN (CL:SETQ F (%%VALUE ITER-000))
          (CL:SETQ ITER-000 (%%REST ITER-000)))
         (CL:IF (CL:EQ COLLECT-000 NULL)
          (CL:PROGN
           (CL:SETQ COLLECT-000
            (CONS
             (WRAP-STRING
              (MAKE-FILE-NAME (%WRAPPER-VALUE F) KWD-SYSTEMS-STELLA TRUE))
             NIL))
           (CL:IF (CL:EQ PREPROCESSEDFILES NIL)
            (CL:SETQ PREPROCESSEDFILES COLLECT-000)
            (ADD-CONS-TO-END-OF-CONS-LIST PREPROCESSEDFILES COLLECT-000)))
          (CL:PROGN
           (CL:SETF (%%REST COLLECT-000)
            (CONS
             (WRAP-STRING
              (MAKE-FILE-NAME (%WRAPPER-VALUE F) KWD-SYSTEMS-STELLA TRUE))
             NIL))
           (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
       (CL:LET* ((*CURRENT-STELLA-FEATURES* (COPY *CURRENT-STELLA-FEATURES*)))
        (CL:DECLARE (CL:SPECIAL *CURRENT-STELLA-FEATURES*))
        (%UNSET-STELLA-FEATURE
         (CONS-LIST KWD-SYSTEMS-WARN-ABOUT-UNDEFINED-METHODS))
        (CL:LET* ((F NULL) (ITER-001 PREPROCESSEDFILES))
         (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
          (CL:PROGN (CL:SETQ F (%%VALUE ITER-001))
           (CL:SETQ ITER-001 (%%REST ITER-001)))
          (TRANSLATE-FILE (%WRAPPER-VALUE F) *TRANSLATOROUTPUTLANGUAGE* FALSE))))
       (COMPILE-AND-LOAD-FILES (%PREPROCESSED-FILES *CURRENTSYSTEMDEFINITION*)
        *TRANSLATOROUTPUTLANGUAGE* FALSE)
       (CL:WHEN
        (MEMB? *CURRENT-STELLA-FEATURES* KWD-SYSTEMS-USE-COMMON-LISP-STRUCTS)
        (CL:LET*
         ((F NULL) (ITER-002 (%PREPROCESSED-FILES *CURRENTSYSTEMDEFINITION*)))
         (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-002 NIL)) DO
          (CL:PROGN (CL:SETQ F (%%VALUE ITER-002))
           (CL:SETQ ITER-002 (%%REST ITER-002)))
          (DELETE-FILE
           (MAKE-FILE-NAME (%WRAPPER-VALUE F) KWD-SYSTEMS-LISP TRUE)))))
       (CL:LET*
        ((STARTUPFN NULL)
         (ITER-003
          (STARTUP-NAMES-FROM-FILES
           (%PREPROCESSED-FILES *CURRENTSYSTEMDEFINITION*))))
        (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-003 NIL)) DO
         (CL:PROGN (CL:SETQ STARTUPFN (%%VALUE ITER-003))
          (CL:SETQ ITER-003 (%%REST ITER-003)))
         (CL:funcall (lispify startupFn))))))
     (CL:WARN "Can't find a system named `~A'~%" SYSTEMNAME))))
  :VOID)

;;; (DEFUN (LOAD-SYSTEM BOOLEAN) ...)

(CL:DEFUN LOAD-SYSTEM (SYSTEMNAME LANGUAGE CL:&REST OPTIONS)
  "Natively `language'-compile out-of-date translated files of system
`systemName' and then load them into the running system (this is only
supported/possible for Lisp at the moment).  Return true if at least one
file was compiled. The following keyword/value `options' are recognized:

`:force-recompilation?' (default false): if true, files will be compiled
whether or not their compilations are up-to-date.

`:startup?' (default true): if true, the system startup function will
be called once all files have been loaded."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SYSTEMNAME))
  #+MCL
  (CL:CHECK-TYPE SYSTEMNAME CL:SIMPLE-STRING)
  (CL:WHEN (CL:NOT (RUNNING-AS-LISP?)) (CL:RETURN-FROM LOAD-SYSTEM FALSE))
  (CL:SETQ LANGUAGE (STELLIFY LANGUAGE))
  (CL:LET* ((SELF-000 (NEW-PROPERTY-LIST)))
   (CL:LET* ((ARGLIST-000 NIL))
    (CL:LET* ((ARG-000 NULL) (ITER-000 OPTIONS) (COLLECT-000 NULL))
     (CL:LOOP WHILE ITER-000 DO (CL:SETQ ARG-000 (CL:POP ITER-000))
      (CL:IF (CL:EQ COLLECT-000 NULL)
       (CL:PROGN (CL:SETQ COLLECT-000 (CONS ARG-000 NIL))
        (CL:IF (CL:EQ ARGLIST-000 NIL) (CL:SETQ ARGLIST-000 COLLECT-000)
         (ADD-CONS-TO-END-OF-CONS-LIST ARGLIST-000 COLLECT-000)))
       (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS ARG-000 NIL))
        (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
    (CL:SETF (%THE-PLIST SELF-000) ARGLIST-000))
   (CL:LET*
    ((PLIST SELF-000) (FORCERECOMPILATION? FALSE) (STARTUPSYSTEM? TRUE)
     (TRANSLATEDFILE? FALSE))
    (VET-OPTIONS PLIST
     (GET-QUOTED-TREE "((:FORCE-RECOMPILATION? :STARTUP?) \"/STELLA\")"
      "/STELLA"))
    (CL:LET* ((VALUE NULL) (KEY NULL) (ITER-001 (%THE-PLIST PLIST)))
     (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
      (CL:SETQ KEY (%%VALUE ITER-001))
      (CL:PROGN (CL:SETQ VALUE (%%VALUE (%%REST ITER-001)))
       (CL:SETQ ITER-001 (%%REST (%%REST ITER-001))))
      (CL:LET* ((TEST-VALUE-000 KEY))
       (CL:COND
        ((CL:EQ TEST-VALUE-000 KWD-SYSTEMS-FORCE-RECOMPILATION?)
         (CL:SETQ FORCERECOMPILATION? (EQL? VALUE TRUE-WRAPPER)))
        ((CL:EQ TEST-VALUE-000 KWD-SYSTEMS-STARTUP?)
         (CL:SETQ STARTUPSYSTEM? (EQL? VALUE TRUE-WRAPPER)))
        (CL:T
         (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
          (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" TEST-VALUE-000
           "' is not a valid case option")
          (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))))))
    (CL:LET*
     ((*CURRENTSYSTEMDEFINITION* (GET-SYSTEM-DEFINITION SYSTEMNAME))
      (*CURRENTSYSTEMDEFINITIONSUBDIRECTORY*
       (CL:IF (CL:NOT (CL:EQ *CURRENTSYSTEMDEFINITION* NULL))
        (%DIRECTORY *CURRENTSYSTEMDEFINITION*) STELLA::NULL-STRING)))
     (CL:DECLARE
      (CL:SPECIAL *CURRENTSYSTEMDEFINITION*
       *CURRENTSYSTEMDEFINITIONSUBDIRECTORY*))
     (CL:DECLARE
      (CL:TYPE CL:SIMPLE-STRING *CURRENTSYSTEMDEFINITIONSUBDIRECTORY*))
     (CL:IF (CL:NOT (CL:EQ *CURRENTSYSTEMDEFINITION* NULL))
      (CL:PROGN
       (CL:WHEN (%LOADED? *CURRENTSYSTEMDEFINITION*)
        (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "Loading system `"
         SYSTEMNAME "' over top of itself." EOL EOL))
       (CL:SETQ TRANSLATEDFILE?
        (COMPILE-AND-LOAD-FILES
         (FILES-PLUS-SYSTEM-STARTUP
          (SYSTEM-DEFINITION-NATIVE-FILES *CURRENTSYSTEMDEFINITION*))
         LANGUAGE FORCERECOMPILATION?))
       (CL:SETF (%LOADED? *CURRENTSYSTEMDEFINITION*) TRUE)
       (CL:WHEN STARTUPSYSTEM?
        (RUN-SYSTEM-STARTUP-FUNCTION *CURRENTSYSTEMDEFINITION*)))
      (CL:WARN "Can't find a system named `~A'~%" SYSTEMNAME)))
    (CL:RETURN-FROM LOAD-SYSTEM TRANSLATEDFILE?))))

;;; (DEFUN (COMPILE-AND-LOAD-FILES BOOLEAN) ...)

(CL:DEFUN COMPILE-AND-LOAD-FILES (FILES LANGUAGE FORCERECOMPILATION?)
  (CL:COND
   ((CL:EQ LANGUAGE KWD-SYSTEMS-COMMON-LISP)
    (CL:RETURN-FROM COMPILE-AND-LOAD-FILES
     (CL-COMPILE-AND-LOAD-FILES FILES TRUE FORCERECOMPILATION?)))
   (CL:T
    (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
     "'compile-and-load-files' NOT IMPLEMENTED FOR " LANGUAGE EOL)
    (CL:RETURN-FROM COMPILE-AND-LOAD-FILES FALSE))))

;;; (DEFUN RUN-SYSTEM-STARTUP-FUNCTION ...)

(CL:DEFUN RUN-SYSTEM-STARTUP-FUNCTION (SYSTEM)
  (CL:WHEN (CL:NOT (RUNNING-AS-LISP?))
   (CL:RETURN-FROM RUN-SYSTEM-STARTUP-FUNCTION))
  (CL:FUNCALL (LISPIFY (SYSTEM-STARTUP-FUNCTION-SYMBOL SYSTEM)))
  :VOID)

;;; (DEFMETHOD (SYSTEM-STARTUP-FUNCTION-NAME STRING) ...)

(CL:DEFMETHOD SYSTEM-STARTUP-FUNCTION-NAME ((SYSTEM SYSTEM-DEFINITION))
  (CL:RETURN-FROM SYSTEM-STARTUP-FUNCTION-NAME
   (SYSTEM-STARTUP-FUNCTION-NAME (%NAME SYSTEM))))

;;; (DEFMETHOD (SYSTEM-STARTUP-FUNCTION-NAME STRING) ...)

(CL:DEFMETHOD SYSTEM-STARTUP-FUNCTION-NAME ((SYSTEMNAME CL:STRING))
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SYSTEMNAME))
  #+MCL
  (CL:CHECK-TYPE SYSTEMNAME CL:SIMPLE-STRING)
  (CL:RETURN-FROM SYSTEM-STARTUP-FUNCTION-NAME
   (STRING-UPCASE (CONCATENATE "startup-" SYSTEMNAME "-system"))))

;;; (DEFUN (SYSTEM-STARTUP-FUNCTION-SYMBOL SYMBOL) ...)

(CL:DEFUN SYSTEM-STARTUP-FUNCTION-SYMBOL (SYSTEM)
  (CL:RETURN-FROM SYSTEM-STARTUP-FUNCTION-SYMBOL
   (INTERN-SYMBOL-IN-MODULE (SYSTEM-STARTUP-FUNCTION-NAME SYSTEM)
    (GET-CARDINAL-MODULE SYSTEM) TRUE)))

;;; (DEFUN (STARTUP-NAME-FROM-FILE SYMBOL) ...)

(CL:DEFUN STARTUP-NAME-FROM-FILE (FILE)
  (CL:WHEN (CL:NOT (PROBE-FILE? (MAKE-FILE-NAME FILE KWD-SYSTEMS-STELLA TRUE)))
   (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "STELLA source file `"
     (MAKE-FILE-NAME FILE KWD-SYSTEMS-STELLA TRUE) "' does not exist")
    (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))
  (CL:LET*
   ((LONGNAME (MAKE-FILE-NAME FILE KWD-SYSTEMS-STELLA TRUE))
    (INPUTSTREAM (NEW-INPUT-FILE-STREAM LONGNAME)) (SAVEDMODULE *MODULE*)
    (SEENINMODULE? FALSE) (UNUSED? FALSE) (STARTUPFNNAME NULL))
   (CL:LET* ((*TRANSIENTOBJECTS?* TRUE))
    (CL:DECLARE (CL:SPECIAL *TRANSIENTOBJECTS?*))
    (CL:LET* ((TREE NULL) (ITER-000 (S-EXPRESSIONS INPUTSTREAM)))
     (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ TREE (%VALUE ITER-000))
      (CL:LET* ((*TRANSIENTOBJECTS?* FALSE))
       (CL:DECLARE (CL:SPECIAL *TRANSIENTOBJECTS?*))
       (CL:COND
        ((CL:EQ (SAFE-PRIMARY-TYPE TREE) SGT-SYSTEMS-STELLA-CONS)
         (CL:PROGN
          (CL:MULTIPLE-VALUE-SETQ (UNUSED? SEENINMODULE?)
           (HANDLE-IN-MODULE-TREE TREE SEENINMODULE?))
          (CL:SETQ UNUSED? UNUSED?)
          (CL:WHEN SEENINMODULE?
           (CL:SETQ STARTUPFNNAME (YIELD-STARTUP-FUNCTION-NAME FILE))
           (CHANGE-MODULE SAVEDMODULE) (FREE INPUTSTREAM)
           (CL:RETURN-FROM STARTUP-NAME-FROM-FILE STARTUPFNNAME))))
        (CL:T))))))
   (CL:WARN "Missing IN-MODULE declaration for file `~A'~%" FILE)
   (CL:RETURN-FROM STARTUP-NAME-FROM-FILE NULL)))

;;; (DEFUN (STARTUP-NAMES-FROM-FILES (CONS OF SYMBOL)) ...)

(CL:DEFUN STARTUP-NAMES-FROM-FILES (FILES)
  (CL:LET* ((NAMES NIL))
   (CL:LET* ((F NULL) (ITER-000 FILES) (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:PROGN (CL:SETQ F (%%VALUE ITER-000))
      (CL:SETQ ITER-000 (%%REST ITER-000)))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN
       (CL:SETQ COLLECT-000
        (CONS (STARTUP-NAME-FROM-FILE (%WRAPPER-VALUE F)) NIL))
       (CL:IF (CL:EQ NAMES NIL) (CL:SETQ NAMES COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST NAMES COLLECT-000)))
      (CL:PROGN
       (CL:SETF (%%REST COLLECT-000)
        (CONS (STARTUP-NAME-FROM-FILE (%WRAPPER-VALUE F)) NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
   (CL:RETURN-FROM STARTUP-NAMES-FROM-FILES NAMES)))

;;; (DEFUN (SYSTEM-STARTUP-FILE-NAME STRING) ...)

(CL:DEFUN SYSTEM-STARTUP-FILE-NAME (SYSTEM)
  (CL:WHEN (CL:EQ SYSTEM NULL) (CL:SETQ SYSTEM *CURRENTSYSTEMDEFINITION*))
  (CL:IF (CL:NOT (CL:EQ SYSTEM NULL))
   (CL:RETURN-FROM SYSTEM-STARTUP-FILE-NAME "startup-system")
   (CL:RETURN-FROM SYSTEM-STARTUP-FILE-NAME STELLA::NULL-STRING)))
(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING) SYSTEM-STARTUP-FILE-NAME))

;;; (DEFUN (SYSTEM-STARTUP-FILE? BOOLEAN) ...)

(CL:DEFUN SYSTEM-STARTUP-FILE? (FILE)
  (CL:WHEN (CL:EQ FILE STELLA::NULL-STRING) (CL:SETQ FILE *CURRENTFILE*))
  (CL:RETURN-FROM SYSTEM-STARTUP-FILE?
   (CL:AND (CL:NOT (CL:EQ FILE STELLA::NULL-STRING))
    (STRING-EQL? (FILE-BASE-NAME FILE) (SYSTEM-STARTUP-FILE-NAME NULL)))))

;;; (DEFUN (SYSTEM-STARTED-UP? BOOLEAN) ...)

(CL:DEFUN SYSTEM-STARTED-UP? (SYSTEMNAME SYSTEMMODULENAME)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SYSTEMNAME SYSTEMMODULENAME))
  #+MCL
  (CL:CHECK-TYPE SYSTEMNAME CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE SYSTEMMODULENAME CL:SIMPLE-STRING)
  (CL:WHEN (STRING-EQL? (STRING-UPCASE SYSTEMNAME) "STELLA")
   (CL:RETURN-FROM SYSTEM-STARTED-UP? (CL:NOT (CL:EQ *MODULE* NULL))))
  (CL:WHEN (CL:EQ (GET-STELLA-MODULE SYSTEMMODULENAME FALSE) NULL)
   (CL:RETURN-FROM SYSTEM-STARTED-UP? FALSE))
  (CL:LET*
   ((STARTUPFUNCTIONSYMBOL
     (LOOKUP-SYMBOL-IN-MODULE (SYSTEM-STARTUP-FUNCTION-NAME SYSTEMNAME)
      (GET-STELLA-MODULE SYSTEMMODULENAME FALSE) TRUE))
    (STARTUPFUNCTION
     (CL:IF (CL:NOT (CL:EQ STARTUPFUNCTIONSYMBOL NULL))
      (LOOKUP-FUNCTION STARTUPFUNCTIONSYMBOL) NULL)))
   (CL:RETURN-FROM SYSTEM-STARTED-UP?
    (CL:AND (CL:NOT (CL:EQ STARTUPFUNCTION NULL))
     (CL:NOT (CL:EQ (%FUNCTION-CODE STARTUPFUNCTION) NULL))))))

;;; (DEFUN (YIELD-STARTUP-REQUIRED-SYSTEMS CONS) ...)

(CL:DEFUN YIELD-STARTUP-REQUIRED-SYSTEMS (SYSTEM)
  (CL:LET* ((STARTUPFORMS NIL))
   (CL:LET*
    ((SYSTEMNAME NULL) (ITER-000 (%REQUIRED-SYSTEMS SYSTEM)) (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:PROGN (CL:SETQ SYSTEMNAME (%%VALUE ITER-000))
      (CL:SETQ ITER-000 (%%REST ITER-000)))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN
       (CL:SETQ COLLECT-000
        (CONS
         (LIST* SYM-SYSTEMS-STELLA-UNLESS
          (LIST* SYM-SYSTEMS-STELLA-SYSTEM-STARTED-UP? SYSTEMNAME
           (CONS
            (WRAP-STRING
             (%MODULE-FULL-NAME
              (GET-CARDINAL-MODULE
               (GET-SYSTEM-DEFINITION (%WRAPPER-VALUE SYSTEMNAME)))))
            NIL))
          (CONS
           (SYSTEM-STARTUP-FUNCTION-SYMBOL
            (GET-SYSTEM-DEFINITION (%WRAPPER-VALUE SYSTEMNAME)))
           NIL)
          NIL)
         NIL))
       (CL:IF (CL:EQ STARTUPFORMS NIL) (CL:SETQ STARTUPFORMS COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST STARTUPFORMS COLLECT-000)))
      (CL:PROGN
       (CL:SETF (%%REST COLLECT-000)
        (CONS
         (LIST* SYM-SYSTEMS-STELLA-UNLESS
          (LIST* SYM-SYSTEMS-STELLA-SYSTEM-STARTED-UP? SYSTEMNAME
           (CONS
            (WRAP-STRING
             (%MODULE-FULL-NAME
              (GET-CARDINAL-MODULE
               (GET-SYSTEM-DEFINITION (%WRAPPER-VALUE SYSTEMNAME)))))
            NIL))
          (CONS
           (SYSTEM-STARTUP-FUNCTION-SYMBOL
            (GET-SYSTEM-DEFINITION (%WRAPPER-VALUE SYSTEMNAME)))
           NIL)
          NIL)
         NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
   (CL:RETURN-FROM YIELD-STARTUP-REQUIRED-SYSTEMS
    (LIST* SYM-SYSTEMS-STELLA-STARTUP-TIME-PROGN KWD-SYSTEMS-EARLY-INITS
     (CONCATENATE STARTUPFORMS NIL)))))

;;; (DEFUN (COLLECT-STARTUP-FORMS-FROM-SYSTEM-FILE (CONS OF CONS)) ...)

(CL:DEFUN COLLECT-STARTUP-FORMS-FROM-SYSTEM-FILE (SYSTEM)
  (CL:LET*
   ((SYSTEMFILENAME (MAKE-SYSTEM-DEFINITION-FILE-NAME (%NAME SYSTEM)))
    (INPUTSTREAM (NEW-INPUT-FILE-STREAM SYSTEMFILENAME)) (MODULE NULL)
    (STARTUPFORM NULL) (STARTUPFORMS NIL))
   (CL:LET* ((*MODULE* *MODULE*) (*CONTEXT* *MODULE*))
    (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
    (CL:LET*
     ((TREE NULL) (ITER-000 (S-EXPRESSIONS INPUTSTREAM)) (COLLECT-000 NULL))
     (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ TREE (%VALUE ITER-000))
      (CL:TAGBODY (CL:SETQ STARTUPFORM NULL)
       (CL:COND
        ((CL:EQ (SAFE-PRIMARY-TYPE TREE) SGT-SYSTEMS-STELLA-CONS)
         (CL:PROGN
          (CL:WHEN (CL:EQ (%%VALUE TREE) SYM-SYSTEMS-STELLA-DEFMODULE)
           (%EVALUATE TREE)
           (CL:SETQ MODULE
            (GET-STELLA-MODULE
             (COERCE-TO-MODULE-NAME (%%VALUE (%%REST TREE)) TRUE) TRUE))
           (CL:WHEN (CL:NOT (CL:EQ MODULE NULL))
            (CL:SETQ STARTUPFORM
             (LIST* SYM-SYSTEMS-STELLA-STARTUP-TIME-PROGN KWD-SYSTEMS-MODULES
              (YIELD-DEFINE-MODULE MODULE) NIL))))
          (CL:WHEN (CL:EQ (%%VALUE TREE) SYM-SYSTEMS-STELLA-IN-MODULE)
           (%EVALUATE TREE))))
        (CL:T))
       (CL:WHEN (CL:EQ STARTUPFORM NULL) (CL:GO :CONTINUE))
       (CL:IF (CL:EQ COLLECT-000 NULL)
        (CL:PROGN (CL:SETQ COLLECT-000 (CONS STARTUPFORM NIL))
         (CL:IF (CL:EQ STARTUPFORMS NIL) (CL:SETQ STARTUPFORMS COLLECT-000)
          (ADD-CONS-TO-END-OF-CONS-LIST STARTUPFORMS COLLECT-000)))
        (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS STARTUPFORM NIL))
         (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))
       :CONTINUE))))
   (CL:RETURN-FROM COLLECT-STARTUP-FORMS-FROM-SYSTEM-FILE STARTUPFORMS)))

;;; (DEFUN CREATE-SYSTEM-STARTUP-FILE ...)

(CL:DEFUN CREATE-SYSTEM-STARTUP-FILE (SYSTEM)
  (CL:WHEN (CL:EQ *CURRENTSYSTEMDEFINITION* NULL)
   (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
    "Must be within a system environment to create startup file " EOL
    "   for system `" (%NAME SYSTEM) "'." EOL EOL)
   (CL:RETURN-FROM CREATE-SYSTEM-STARTUP-FILE))
  (CL:LET* ((*MODULE* (GET-CARDINAL-MODULE SYSTEM)) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:LET*
    ((FILE
      (MAKE-FILE-NAME (SYSTEM-STARTUP-FILE-NAME SYSTEM) KWD-SYSTEMS-STELLA TRUE))
     (OUTPUTSTREAM (NEW-OUTPUT-FILE-STREAM FILE)) (STARTUPFNNAMES NIL)
     (STARTUPFORMS NIL))
    (CL:LET*
     ((F NULL) (ITER-000 (SYSTEM-DEFINITION-SOURCE-FILES SYSTEM))
      (COLLECT-000 NULL))
     (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
      (CL:PROGN (CL:SETQ F (%%VALUE ITER-000))
       (CL:SETQ ITER-000 (%%REST ITER-000)))
      (CL:IF (CL:EQ COLLECT-000 NULL)
       (CL:PROGN
        (CL:SETQ COLLECT-000
         (CONS (STARTUP-NAME-FROM-FILE (%WRAPPER-VALUE F)) NIL))
        (CL:IF (CL:EQ STARTUPFNNAMES NIL) (CL:SETQ STARTUPFNNAMES COLLECT-000)
         (ADD-CONS-TO-END-OF-CONS-LIST STARTUPFNNAMES COLLECT-000)))
       (CL:PROGN
        (CL:SETF (%%REST COLLECT-000)
         (CONS (STARTUP-NAME-FROM-FILE (%WRAPPER-VALUE F)) NIL))
        (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
    (CL-OUTPUT-FILE-HEADER OUTPUTSTREAM FILE FALSE)
    (CL:SETQ STARTUPFORMS
     (CONS
      (LIST* SYM-SYSTEMS-STELLA-IN-MODULE
       (WRAP-STRING (%MODULE-FULL-NAME (GET-CARDINAL-MODULE SYSTEM))) NIL)
      STARTUPFORMS))
    (CL:SETQ STARTUPFORMS
     (CONS
      (LIST* SYM-SYSTEMS-STELLA-DEFUN (SYSTEM-STARTUP-FUNCTION-SYMBOL SYSTEM)
       (LIST* NIL KWD-SYSTEMS-PUBLIC? SYM-SYSTEMS-STELLA-TRUE NIL))
      STARTUPFORMS))
    (CL:COND
     ((STRING-EQL? (STRING-UPCASE (%NAME SYSTEM)) "STELLA")
      (CL:SETQ STARTUPFORMS
       (CONS
        (LIST* SYM-SYSTEMS-STELLA-STARTUP-TIME-PROGN KWD-SYSTEMS-EARLY-INITS
         (LIST* SYM-SYSTEMS-STELLA-STARTUP SYM-SYSTEMS-STELLA-FALSE NIL) NIL)
        STARTUPFORMS)))
     (CL:T
      (CL:WHEN (CL:NOT (CL:EQ (%REQUIRED-SYSTEMS SYSTEM) NULL))
       (CL:SETQ STARTUPFORMS
        (CONS (YIELD-STARTUP-REQUIRED-SYSTEMS SYSTEM) STARTUPFORMS)))
      (CL:LET*
       ((FORM NULL) (ITER-001 (COLLECT-STARTUP-FORMS-FROM-SYSTEM-FILE SYSTEM)))
       (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
        (CL:PROGN (CL:SETQ FORM (%%VALUE ITER-001))
         (CL:SETQ ITER-001 (%%REST ITER-001)))
        (CL:SETQ STARTUPFORMS (CONS FORM STARTUPFORMS))))
      (CL:LET* ((STARTUPFN NULL) (ITER-002 STARTUPFNNAMES))
       (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-002 NIL)) DO
        (CL:PROGN (CL:SETQ STARTUPFN (%%VALUE ITER-002))
         (CL:SETQ ITER-002 (%%REST ITER-002)))
        (CL:WHEN (CL:EQ (LOOKUP-FUNCTION STARTUPFN) NULL)
         (CL:LET* ((*MODULE* (HOME-MODULE STARTUPFN)) (*CONTEXT* *MODULE*))
          (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
          (DEFINE-METHOD-FROM-PARSE-TREE
           (LIST* SYM-SYSTEMS-STELLA-DEFUN STARTUPFN
            (LIST* NIL KWD-SYSTEMS-PUBLIC? SYM-SYSTEMS-STELLA-TRUE NIL)))))))
      (CL:LET* ((STARTUPFNCALLS NIL))
       (CL:LET* ((STARTUPFN NULL) (ITER-003 STARTUPFNNAMES) (COLLECT-001 NULL))
        (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-003 NIL)) DO
         (CL:PROGN (CL:SETQ STARTUPFN (%%VALUE ITER-003))
          (CL:SETQ ITER-003 (%%REST ITER-003)))
         (CL:IF (CL:EQ COLLECT-001 NULL)
          (CL:PROGN (CL:SETQ COLLECT-001 (CONS (CONS STARTUPFN NIL) NIL))
           (CL:IF (CL:EQ STARTUPFNCALLS NIL) (CL:SETQ STARTUPFNCALLS COLLECT-001)
            (ADD-CONS-TO-END-OF-CONS-LIST STARTUPFNCALLS COLLECT-001)))
          (CL:PROGN
           (CL:SETF (%%REST COLLECT-001) (CONS (CONS STARTUPFN NIL) NIL))
           (CL:SETQ COLLECT-001 (%%REST COLLECT-001))))))
       (CL:SETQ STARTUPFORMS
        (CONS
         (LIST* SYM-SYSTEMS-STELLA-STARTUP-TIME-PROGN
          (LIST* SYM-SYSTEMS-STELLA-FOREACH SYM-SYSTEMS-STELLA-PHASE
           SYM-SYSTEMS-STELLA-IN
           (LIST* SYM-SYSTEMS-STELLA-INTERVAL
            (LIST* SYM-SYSTEMS-STELLA-PHASE-TO-INTEGER KWD-SYSTEMS-EARLY-INITS
             NIL)
            (LIST* SYM-SYSTEMS-STELLA-PHASE-TO-INTEGER KWD-SYSTEMS-FINAL NIL)
            NIL)
           SYM-SYSTEMS-STELLA-DO
           (LIST* SYM-SYSTEMS-STELLA-SETQ SYM-SYSTEMS-STELLA-*STARTUP-TIME-PHASE*
            SYM-SYSTEMS-STELLA-PHASE NIL)
           (CONCATENATE STARTUPFNCALLS NIL))
          (LIST* SYM-SYSTEMS-STELLA-SETQ SYM-SYSTEMS-STELLA-*STARTUP-TIME-PHASE*
           (WRAP-INTEGER 999) NIL)
          NIL)
         STARTUPFORMS)))))
    (CL:LET* ((*PRINTREADABLY?* TRUE) (*PRINTPRETTY?* TRUE))
     (CL:DECLARE (CL:SPECIAL *PRINTREADABLY?* *PRINTPRETTY?*))
     (CL:LET* ((FORM NULL) (ITER-004 (REVERSE STARTUPFORMS)))
      (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-004 NIL)) DO
       (CL:PROGN (CL:SETQ FORM (%%VALUE ITER-004))
        (CL:SETQ ITER-004 (%%REST ITER-004)))
       (%%PRINT-STREAM (%NATIVE-STREAM OUTPUTSTREAM) FORM EOL EOL))))
    (FREE OUTPUTSTREAM)))
  :VOID)

;;; (DEFUN MAKE-STELLA ...)

(CL:DEFUN MAKE-STELLA (FORCERECOMPILATION?)
  (%MAKE-SYSTEM "STELLA" KWD-SYSTEMS-COMMON-LISP
   (CONS-LIST KWD-SYSTEMS-FORCE-TRANSLATION?
    (CL:IF FORCERECOMPILATION? TRUE-WRAPPER FALSE-WRAPPER)
    KWD-SYSTEMS-DEVELOPMENT-SETTINGS? FALSE-WRAPPER))
  :VOID)

;;; (DEFUN (PARSE-CONFIGURATION-FILE-LINE STRING-WRAPPER WRAPPER) ...)

(CL:DEFUN PARSE-CONFIGURATION-FILE-LINE (LINE)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING LINE))
  #+MCL
  (CL:CHECK-TYPE LINE CL:SIMPLE-STRING)
  (CL:LET*
   ((START 0) (HASHPOS (POSITION LINE #\# 0)) (EQUALPOS (POSITION LINE #\= 0))
    (END EQUALPOS) (LENGTH (CL:THE CL:FIXNUM (CL:LENGTH LINE)))
    (PROPERTY STELLA::NULL-STRING) (VALUESTRING STELLA::NULL-STRING)
    (VALUE NULL))
   (CL:DECLARE (CL:TYPE CL:FIXNUM START HASHPOS EQUALPOS END LENGTH)
    (CL:TYPE CL:SIMPLE-STRING PROPERTY VALUESTRING))
   (CL:LET* ((ALWAYS?-000 TRUE))
    (CL:LET*
     ((I NULL-INTEGER) (ITER-000 0)
      (UPPER-BOUND-000 (CL:1- (CL:IF (DEFINED? HASHPOS) HASHPOS LENGTH))))
     (CL:DECLARE (CL:TYPE CL:FIXNUM ITER-000 UPPER-BOUND-000 I))
     (CL:LOOP WHILE (CL:<= ITER-000 UPPER-BOUND-000) DO
      (CL:PROGN (CL:SETQ I ITER-000) (CL:SETQ ITER-000 (CL:1+ ITER-000)))
      (CL:WHEN
       (CL:NOT
        (CL:EQ
         (CL:AREF *CHARACTER-TYPE-TABLE*
          (CL:THE CL:FIXNUM
           (CL:CHAR-CODE
            (CL:LET ((SELF LINE) (POSITION I))
             (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF)
              (CL:TYPE CL:FIXNUM POSITION))
             (CL:SCHAR (CL:THE CL:SIMPLE-STRING SELF)
              (CL:THE CL:FIXNUM POSITION))))))
         KWD-SYSTEMS-WHITE-SPACE))
       (CL:SETQ ALWAYS?-000 FALSE) (CL:RETURN))))
    (CL:WHEN ALWAYS?-000
     (CL:RETURN-FROM PARSE-CONFIGURATION-FILE-LINE (CL:VALUES NULL NULL))))
   (CL:WHEN (CL:OR (NULL? EQUALPOS) (CL:= EQUALPOS 0))
    (CL:WARN "Illegal line in configuration file: `~A'" LINE)
    (CL:RETURN-FROM PARSE-CONFIGURATION-FILE-LINE (CL:VALUES NULL NULL)))
   (CL:LOOP WHILE
    (CL:EQ
     (CL:AREF *CHARACTER-TYPE-TABLE*
      (CL:THE CL:FIXNUM
       (CL:CHAR-CODE
        (CL:LET ((SELF LINE) (POSITION START))
         (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF)
          (CL:TYPE CL:FIXNUM POSITION))
         (CL:SCHAR (CL:THE CL:SIMPLE-STRING SELF)
          (CL:THE CL:FIXNUM POSITION))))))
     KWD-SYSTEMS-WHITE-SPACE)
    DO (CL:SETQ START (CL:1+ START)))
   (CL:LOOP WHILE
    (CL:EQ
     (CL:AREF *CHARACTER-TYPE-TABLE*
      (CL:THE CL:FIXNUM
       (CL:CHAR-CODE
        (CL:LET ((SELF LINE) (POSITION (CL:1- END)))
         (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF)
          (CL:TYPE CL:FIXNUM POSITION))
         (CL:SCHAR (CL:THE CL:SIMPLE-STRING SELF)
          (CL:THE CL:FIXNUM POSITION))))))
     KWD-SYSTEMS-WHITE-SPACE)
    DO (CL:SETQ END (CL:1- END)))
   (CL:WHEN (CL:<= END START)
    (CL:WARN "Illegal property in configuration file: `~A'" LINE)
    (CL:RETURN-FROM PARSE-CONFIGURATION-FILE-LINE (CL:VALUES NULL NULL)))
   (CL:SETQ PROPERTY (SUBSEQUENCE LINE START END))
   (CL:SETQ VALUESTRING (SUBSEQUENCE LINE (CL:1+ EQUALPOS) LENGTH))
   (CL:COND ((STRING-EQUAL? VALUESTRING "TRUE") (CL:SETQ VALUE TRUE-WRAPPER))
    ((STRING-EQUAL? VALUESTRING "FALSE") (CL:SETQ VALUE FALSE-WRAPPER))
    (CL:T
     (CL:HANDLER-CASE
      (CL:LET*
       ((TEST-VALUE-000
         (SAFE-PRIMARY-TYPE
          (CL:SETQ VALUE (READ-S-EXPRESSION-FROM-STRING VALUESTRING)))))
       (CL:COND
        ((CL:OR (SUBTYPE-OF-INTEGER? TEST-VALUE-000)
          (SUBTYPE-OF-FLOAT? TEST-VALUE-000)))
        (CL:T (CL:SETQ VALUE (WRAP-STRING VALUESTRING)))))
      (READ-EXCEPTION () (CL:SETQ VALUE (WRAP-STRING VALUESTRING))))))
   (CL:RETURN-FROM PARSE-CONFIGURATION-FILE-LINE
    (CL:VALUES (WRAP-STRING PROPERTY) VALUE))))

;;; (DEFGLOBAL *SYSTEM-CONFIGURATION-TABLE* ...)

(CL:DEFVAR *SYSTEM-CONFIGURATION-TABLE* NULL)

;;; (DEFUN (LOAD-CONFIGURATION-FILE CONFIGURATION-TABLE) ...)

(CL:DEFUN LOAD-CONFIGURATION-FILE (FILE)
  "Read a configuration `file' and return its content as a configuration table.
Also enter each property read into the global system configuration table.
Assumes Java-style property file syntax.  Each property name is represented
as a wrapped string and each value as a wrapped string/integer/float or boolean."
  (CL:LET* ((CONFIGURATION (NEW-KEY-VALUE-LIST)))
   (CL:LET*
    ((LINE STELLA::NULL-STRING) (ITER-000 (LINES (NEW-INPUT-FILE-STREAM FILE))))
    (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING LINE))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ LINE (%VALUE ITER-000))
     (CL:LET* ((KEY NULL) (VALUE NULL))
      (CL:MULTIPLE-VALUE-SETQ (KEY VALUE) (PARSE-CONFIGURATION-FILE-LINE LINE))
      (CL:WHEN (CL:NOT (CL:EQ KEY NULL)) (INSERT-AT CONFIGURATION KEY VALUE)
       (INSERT-AT *SYSTEM-CONFIGURATION-TABLE* KEY VALUE)))))
   (CL:RETURN-FROM LOAD-CONFIGURATION-FILE CONFIGURATION)))

;;; (DEFUN (LOOKUP-CONFIGURATION-PROPERTY WRAPPER) ...)

(CL:DEFUN LOOKUP-CONFIGURATION-PROPERTY (PROPERTY DEFAULTVALUE CONFIGURATION)
  "Lookup `property' in `configuration' and return its value.
Use the global system configuration table if `configuration' is NULL.  Return
`defaultValue' if `property' is not defined."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PROPERTY))
  #+MCL
  (CL:CHECK-TYPE PROPERTY CL:SIMPLE-STRING)
  (CL:WHEN (CL:EQ CONFIGURATION NULL)
   (CL:SETQ CONFIGURATION *SYSTEM-CONFIGURATION-TABLE*))
  (CL:LET* ((VALUE (LOOKUP CONFIGURATION (WRAP-STRING PROPERTY))))
   (CL:IF (CL:NOT (CL:EQ VALUE NULL))
    (CL:RETURN-FROM LOOKUP-CONFIGURATION-PROPERTY VALUE)
    (CL:RETURN-FROM LOOKUP-CONFIGURATION-PROPERTY DEFAULTVALUE))))

;;; (DEFUN (SET-CONFIGURATION-PROPERTY WRAPPER) ...)

(CL:DEFUN SET-CONFIGURATION-PROPERTY (PROPERTY VALUE CONFIGURATION)
  "Set `property' in `configuration' to `value' and return it.
Use the global system configuration table if `configuration' is NULL."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PROPERTY))
  #+MCL
  (CL:CHECK-TYPE PROPERTY CL:SIMPLE-STRING)
  (CL:WHEN (CL:EQ CONFIGURATION NULL)
   (CL:SETQ CONFIGURATION *SYSTEM-CONFIGURATION-TABLE*))
  (INSERT-AT CONFIGURATION (WRAP-STRING PROPERTY) VALUE)
  (CL:RETURN-FROM SET-CONFIGURATION-PROPERTY VALUE))

;;; (DEFUN CONFIGURE-STELLA ...)

(CL:DEFUN CONFIGURE-STELLA (FILE)
  "Perform STELLA run-time configuration.  If supplied, load the
configuration file `file' first which should be supplied with a physical pathname."
  (CL:WHEN (CL:AND (CL:NOT (CL:EQ FILE STELLA::NULL-STRING)) (PROBE-FILE? FILE))
   (LOAD-CONFIGURATION-FILE FILE))
  (DEFINE-LOGICAL-HOST-PROPERTY "PL" KWD-SYSTEMS-ROOT-DIRECTORY
   (LOOKUP-CONFIGURATION-PROPERTY "PowerLoomRootDirectory" NULL NULL))
  :VOID)

(CL:DEFUN HELP-STARTUP-SYSTEMS1 ()
  (CL:PROGN
   (CL:SETQ KWD-SYSTEMS-DEFINE (INTERN-RIGID-SYMBOL-WRT-MODULE "DEFINE" NULL 2))
   (CL:SETQ SYM-SYSTEMS-STELLA-IN-MODULE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "IN-MODULE" NULL 0))
   (CL:SETQ SGT-SYSTEMS-STELLA-CONS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "CONS" NULL 1))
   (CL:SETQ KWD-SYSTEMS-FINALIZE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "FINALIZE" NULL 2))
   (CL:SETQ SYM-SYSTEMS-STELLA-DEFMODULE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "DEFMODULE" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-DEFSYSTEM
    (INTERN-RIGID-SYMBOL-WRT-MODULE "DEFSYSTEM" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-DEFCLASS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "DEFCLASS" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-DEFSLOT
    (INTERN-RIGID-SYMBOL-WRT-MODULE "DEFSLOT" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-DEFUN
    (INTERN-RIGID-SYMBOL-WRT-MODULE "DEFUN" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-DEFMETHOD
    (INTERN-RIGID-SYMBOL-WRT-MODULE "DEFMETHOD" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-LOAD-FILE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "LOAD-FILE" NULL 0))
   (CL:SETQ KWD-SYSTEMS-COMMON-LISP
    (INTERN-RIGID-SYMBOL-WRT-MODULE "COMMON-LISP" NULL 2))
   (CL:SETQ KWD-SYSTEMS-FUNCTION
    (INTERN-RIGID-SYMBOL-WRT-MODULE "FUNCTION" NULL 2))
   (CL:SETQ KWD-SYSTEMS-DIRECTORY
    (INTERN-RIGID-SYMBOL-WRT-MODULE "DIRECTORY" NULL 2))
   (CL:SETQ KWD-SYSTEMS-FILES (INTERN-RIGID-SYMBOL-WRT-MODULE "FILES" NULL 2))
   (CL:SETQ KWD-SYSTEMS-REQUIRED-SYSTEMS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "REQUIRED-SYSTEMS" NULL 2))
   (CL:SETQ KWD-SYSTEMS-LISP-ONLY-FILES
    (INTERN-RIGID-SYMBOL-WRT-MODULE "LISP-ONLY-FILES" NULL 2))
   (CL:SETQ KWD-SYSTEMS-CPP-ONLY-FILES
    (INTERN-RIGID-SYMBOL-WRT-MODULE "CPP-ONLY-FILES" NULL 2))
   (CL:SETQ KWD-SYSTEMS-JAVA-ONLY-FILES
    (INTERN-RIGID-SYMBOL-WRT-MODULE "JAVA-ONLY-FILES" NULL 2))
   (CL:SETQ KWD-SYSTEMS-PREPROCESSED-FILES
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PREPROCESSED-FILES" NULL 2))
   (CL:SETQ KWD-SYSTEMS-CARDINAL-MODULE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "CARDINAL-MODULE" NULL 2))
   (CL:SETQ KWD-SYSTEMS-ROOT-SOURCE-DIRECTORY
    (INTERN-RIGID-SYMBOL-WRT-MODULE "ROOT-SOURCE-DIRECTORY" NULL 2))
   (CL:SETQ KWD-SYSTEMS-ROOT-NATIVE-DIRECTORY
    (INTERN-RIGID-SYMBOL-WRT-MODULE "ROOT-NATIVE-DIRECTORY" NULL 2))
   (CL:SETQ KWD-SYSTEMS-ROOT-BINARY-DIRECTORY
    (INTERN-RIGID-SYMBOL-WRT-MODULE "ROOT-BINARY-DIRECTORY" NULL 2))
   (CL:SETQ KWD-SYSTEMS-BANNER (INTERN-RIGID-SYMBOL-WRT-MODULE "BANNER" NULL 2))
   (CL:SETQ KWD-SYSTEMS-COPYRIGHT-HEADER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "COPYRIGHT-HEADER" NULL 2))
   (CL:SETQ KWD-SYSTEMS-PRODUCTION-SETTINGS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PRODUCTION-SETTINGS" NULL 2))
   (CL:SETQ KWD-SYSTEMS-DEVELOPMENT-SETTINGS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "DEVELOPMENT-SETTINGS" NULL 2))
   (CL:SETQ KWD-SYSTEMS-FINALIZATION-FUNCTION
    (INTERN-RIGID-SYMBOL-WRT-MODULE "FINALIZATION-FUNCTION" NULL 2))
   (CL:SETQ KWD-SYSTEMS-JAVA (INTERN-RIGID-SYMBOL-WRT-MODULE "JAVA" NULL 2))
   (CL:SETQ KWD-SYSTEMS-LISP (INTERN-RIGID-SYMBOL-WRT-MODULE "LISP" NULL 2))
   (CL:SETQ KWD-SYSTEMS-CPP (INTERN-RIGID-SYMBOL-WRT-MODULE "CPP" NULL 2))
   (CL:SETQ KWD-SYSTEMS-LISP-BINARY
    (INTERN-RIGID-SYMBOL-WRT-MODULE "LISP-BINARY" NULL 2))
   (CL:SETQ SGT-SYSTEMS-STELLA-PROPERTY-LIST
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PROPERTY-LIST" NULL 1))
   (CL:SETQ SGT-SYSTEMS-STELLA-LIST
    (INTERN-RIGID-SYMBOL-WRT-MODULE "LIST" NULL 1))
   (CL:SETQ KWD-SYSTEMS-DEVELOPMENT-SETTINGS?
    (INTERN-RIGID-SYMBOL-WRT-MODULE "DEVELOPMENT-SETTINGS?" NULL 2))
   (CL:SETQ KWD-SYSTEMS-PRODUCTION-SETTINGS?
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PRODUCTION-SETTINGS?" NULL 2))
   (CL:SETQ KWD-SYSTEMS-FORCE-TRANSLATION?
    (INTERN-RIGID-SYMBOL-WRT-MODULE "FORCE-TRANSLATION?" NULL 2))
   (CL:SETQ KWD-SYSTEMS-FORCE-RECOMPILATION?
    (INTERN-RIGID-SYMBOL-WRT-MODULE "FORCE-RECOMPILATION?" NULL 2))
   (CL:SETQ KWD-SYSTEMS-TWO-PASS?
    (INTERN-RIGID-SYMBOL-WRT-MODULE "TWO-PASS?" NULL 2))
   (CL:SETQ KWD-SYSTEMS-LOAD-SYSTEM?
    (INTERN-RIGID-SYMBOL-WRT-MODULE "LOAD-SYSTEM?" NULL 2))
   (CL:SETQ KWD-SYSTEMS-STARTUP?
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP?" NULL 2))
   (CL:SETQ SYM-SYSTEMS-STELLA-MAKE-SYSTEM
    (INTERN-RIGID-SYMBOL-WRT-MODULE "MAKE-SYSTEM" NULL 0))
   (CL:SETQ KWD-SYSTEMS-USE-COMMON-LISP-STRUCTS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "USE-COMMON-LISP-STRUCTS" NULL 2))
   (CL:SETQ KWD-SYSTEMS-STELLA (INTERN-RIGID-SYMBOL-WRT-MODULE "STELLA" NULL 2))
   (CL:SETQ KWD-SYSTEMS-WARN-ABOUT-UNDEFINED-METHODS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "WARN-ABOUT-UNDEFINED-METHODS" NULL 2))
   (CL:SETQ SYM-SYSTEMS-STELLA-UNLESS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "UNLESS" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-SYSTEM-STARTED-UP?
    (INTERN-RIGID-SYMBOL-WRT-MODULE "SYSTEM-STARTED-UP?" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-STARTUP-TIME-PROGN
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-TIME-PROGN" NULL 0))
   (CL:SETQ KWD-SYSTEMS-EARLY-INITS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "EARLY-INITS" NULL 2))
   (CL:SETQ KWD-SYSTEMS-MODULES
    (INTERN-RIGID-SYMBOL-WRT-MODULE "MODULES" NULL 2))
   (CL:SETQ KWD-SYSTEMS-PUBLIC?
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PUBLIC?" NULL 2))
   (CL:SETQ SYM-SYSTEMS-STELLA-TRUE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "TRUE" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-STARTUP
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-FALSE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "FALSE" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-FOREACH
    (INTERN-RIGID-SYMBOL-WRT-MODULE "FOREACH" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-PHASE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PHASE" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-IN (INTERN-RIGID-SYMBOL-WRT-MODULE "IN" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-INTERVAL
    (INTERN-RIGID-SYMBOL-WRT-MODULE "INTERVAL" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-PHASE-TO-INTEGER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PHASE-TO-INTEGER" NULL 0)))
  :VOID)

(CL:DEFUN HELP-STARTUP-SYSTEMS2 ()
  (CL:PROGN
   (CL:SETQ KWD-SYSTEMS-FINAL (INTERN-RIGID-SYMBOL-WRT-MODULE "FINAL" NULL 2))
   (CL:SETQ SYM-SYSTEMS-STELLA-DO (INTERN-RIGID-SYMBOL-WRT-MODULE "DO" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-SETQ
    (INTERN-RIGID-SYMBOL-WRT-MODULE "SETQ" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-*STARTUP-TIME-PHASE*
    (INTERN-RIGID-SYMBOL-WRT-MODULE "*STARTUP-TIME-PHASE*" NULL 0))
   (CL:SETQ KWD-SYSTEMS-WHITE-SPACE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "WHITE-SPACE" NULL 2))
   (CL:SETQ SYM-SYSTEMS-STELLA-CONFIGURATION-TABLE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "CONFIGURATION-TABLE" NULL 0))
   (CL:SETQ KWD-SYSTEMS-ROOT-DIRECTORY
    (INTERN-RIGID-SYMBOL-WRT-MODULE "ROOT-DIRECTORY" NULL 2))
   (CL:SETQ SYM-SYSTEMS-STELLA-STARTUP-SYSTEMS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-SYSTEMS" NULL 0))
   (CL:SETQ SYM-SYSTEMS-STELLA-METHOD-STARTUP-CLASSNAME
    (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL 0)))
  :VOID)

(CL:DEFUN STARTUP-SYSTEMS ()
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2) (HELP-STARTUP-SYSTEMS1)
    (HELP-STARTUP-SYSTEMS2))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ *SYSTEMDEFINITIONS* (NEW-LIST))
    (CL:SETQ *SYSTEM-CONFIGURATION-TABLE* (NEW-KEY-VALUE-LIST)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 5)
    (DEFINE-STELLA-TYPE-FROM-STRINGIFIED-SOURCE
     "(DEFTYPE CONFIGURATION-TABLE (KEY-VALUE-LIST OF STRING-WRAPPER WRAPPER))"))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "EVALUATE-COMMAND"
     "(DEFUN (EVALUATE-COMMAND OBJECT) ((COMMAND OBJECT) (FINALIZE? BOOLEAN)))"
     (CL:FUNCTION EVALUATE-COMMAND) NULL)
    (DEFINE-FUNCTION-OBJECT "LOAD-FILE"
     "(DEFUN LOAD-FILE ((FILE STRING)) :DOCUMENTATION \"Read STELLA commands from `file' and evaluate them.
The file should begin with an `in-module' declaration that specifies
the module within which all remaining commands are to be evaluated
The remaining commands are evaluated one-by-one, applying the function
`evaluate' to each of them.\" :COMMAND? TRUE :PUBLIC? TRUE)"
     (CL:FUNCTION %LOAD-FILE) (CL:FUNCTION LOAD-FILE-EVALUATOR-WRAPPER))
    (DEFINE-FUNCTION-OBJECT "MAKE-SYSTEM-DEFINITION-FILE-NAME"
     "(DEFUN (MAKE-SYSTEM-DEFINITION-FILE-NAME FILE-NAME) ((NAME STRING)))"
     (CL:FUNCTION MAKE-SYSTEM-DEFINITION-FILE-NAME) NULL)
    (DEFINE-FUNCTION-OBJECT "PARSE-LIST-OF-FILE-PATHS"
     "(DEFUN (PARSE-LIST-OF-FILE-PATHS (CONS OF STRING-WRAPPER)) ((FILES CONS)))"
     (CL:FUNCTION PARSE-LIST-OF-FILE-PATHS) NULL)
    (DEFINE-FUNCTION-OBJECT "DEFINE-SYSTEM"
     "(DEFUN (DEFINE-SYSTEM SYSTEM-DEFINITION) ((NAME OBJECT) (OPTIONS CONS)))"
     (CL:FUNCTION DEFINE-SYSTEM) NULL)
    (DEFINE-FUNCTION-OBJECT "DEFSYSTEM"
     "(DEFUN (DEFSYSTEM SYSTEM-DEFINITION) ((NAME SYMBOL) |&REST| (OPTIONS OBJECT)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE :DOCUMENTATION \"Define a system of files that collectively define
a Stella application.
   Required options are:
   :directory -- the path from the Stella root directory to the directory
                 containing the system files.  Can be a string or a list
                 of strings (do not include directory separators).
   :files -- a list of files in the system, containing strings and lists
             of strings; the latter defines exploded paths to files
             in subdirectories.
   Optional options are:
   :required-systems -- a list of systems (strings) that should be loaded
                        prior to loading this system.
   :cardinal-module -- the name (a string) of the principal module for this
                       system.
   :copyright-header -- string with a header for inclusion into all translated
                        files produced by Stella.
   :lisp-only-files  -- Like the :files keyword, but these are only included
   :cpp-only-files      in the translation for the specific language, namely
   :java-only-files     Common Lisp, C++ or Java\")" (CL:FUNCTION %DEFSYSTEM)
     (CL:FUNCTION DEFSYSTEM-EVALUATOR-WRAPPER))
    (DEFINE-FUNCTION-OBJECT "GET-SYSTEM-DEFINITION"
     "(DEFUN (GET-SYSTEM-DEFINITION SYSTEM-DEFINITION) ((NAME STRING)))"
     (CL:FUNCTION GET-SYSTEM-DEFINITION) NULL)
    (DEFINE-FUNCTION-OBJECT "GET-CARDINAL-MODULE"
     "(DEFUN (GET-CARDINAL-MODULE MODULE) ((SYSTEM SYSTEM-DEFINITION)))"
     (CL:FUNCTION GET-CARDINAL-MODULE) NULL)
    (DEFINE-FUNCTION-OBJECT "HELP-GET-SYSTEM-FILES"
     "(DEFUN HELP-GET-SYSTEM-FILES ((FILENAME FILE-NAME) (COLLECTION LIST) (PROBEFILE? BOOLEAN)))"
     (CL:FUNCTION HELP-GET-SYSTEM-FILES) NULL)
    (DEFINE-FUNCTION-OBJECT "GET-SYSTEM-FILES"
     "(DEFUN (GET-SYSTEM-FILES (LIST OF STRING-WRAPPER)) ((SYSTEM SYSTEM-DEFINITION) (TYPE KEYWORD) (PROBEFILES? BOOLEAN)))"
     (CL:FUNCTION GET-SYSTEM-FILES) NULL)
    (DEFINE-FUNCTION-OBJECT "CLEAN-SYSTEM"
     "(DEFUN CLEAN-SYSTEM ((SYSTEMNAME STRING)))" (CL:FUNCTION CLEAN-SYSTEM)
     NULL)
    (DEFINE-FUNCTION-OBJECT "COMPUTE-OPTIMIZATION-LEVELS"
     "(DEFUN COMPUTE-OPTIMIZATION-LEVELS ((SYSTEM SYSTEM-DEFINITION) (PRODUCTIONMODE? BOOLEAN)))"
     (CL:FUNCTION COMPUTE-OPTIMIZATION-LEVELS) NULL)
    (DEFINE-FUNCTION-OBJECT "LISP-KEYWORD-TO-STELLA-KEYWORD"
     "(DEFUN (LISP-KEYWORD-TO-STELLA-KEYWORD KEYWORD) ((KEY KEYWORD)))"
     (CL:FUNCTION LISP-KEYWORD-TO-STELLA-KEYWORD) NULL)
    (DEFINE-FUNCTION-OBJECT "VET-OPTIONS"
     "(DEFUN (VET-OPTIONS PROPERTY-LIST) ((PLIST OBJECT) (LEGALOPTIONS (CONS OF KEYWORD))))"
     (CL:FUNCTION VET-OPTIONS) NULL)
    (DEFINE-FUNCTION-OBJECT "MAKE-SYSTEM"
     "(DEFUN (MAKE-SYSTEM BOOLEAN) ((SYSTEMNAME STRING) (LANGUAGE KEYWORD) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Translate all out-of-date files of system `systemName'
into `language' and then compile and load them (the latter is only possible
for Lisp right now).  The following keyword/value `options' are recognized:

`:two-pass?': if true, all files will be scanned twice, once to
load the signatures of objects defined in them, and once to actually
translate the definitions.  Otherwise, the translator will make one pass in
the case that the system is already loaded (and is being remade), and two
passes otherwise.

`:development-settings?' (default false): if true translation will favor
safe, readable and debuggable code over efficiency (according to the value
of `:development-settings' on the system definition).  If false, efficiency
will be favored instead (according to the value of `:production-settings'
on the system definition).

`:production-settings?' (default true): inverse to `:development-settings?'.

`:force-translation?' (default false): if true, files will be translated
whether or not their translations are up-to-date.

`:force-recompilation?' (default false): if true, translated files will be
recompiled whether or not their compilations are up-to-date (only supported
in Lisp right now).

`:load-system?' (default true): if true, compiled files will be loaded into
the current STELLA image (only supported in Lisp right now).

`:startup?' (default true): if true, the system startup function will
be called once all files have been loaded.\" :PUBLIC? TRUE :COMMAND? TRUE)"
     (CL:FUNCTION %MAKE-SYSTEM) (CL:FUNCTION MAKE-SYSTEM-EVALUATOR-WRAPPER))
    (DEFINE-FUNCTION-OBJECT "RUN-SYSTEM-FINALIZATION"
     "(DEFUN RUN-SYSTEM-FINALIZATION ((SYSTEM SYSTEM-DEFINITION)))"
     (CL:FUNCTION RUN-SYSTEM-FINALIZATION) NULL)
    (DEFINE-FUNCTION-OBJECT "SYSTEM-DEFINITION-SOURCE-FILES"
     "(DEFUN (SYSTEM-DEFINITION-SOURCE-FILES (CONS OF STRING-WRAPPER)) ((SYSTEM SYSTEM-DEFINITION)))"
     (CL:FUNCTION SYSTEM-DEFINITION-SOURCE-FILES) NULL)
    (DEFINE-FUNCTION-OBJECT "FILES-PLUS-SYSTEM-STARTUP"
     "(DEFUN (FILES-PLUS-SYSTEM-STARTUP (CONS OF STRING-WRAPPER)) ((FILES (CONS OF STRING-WRAPPER))))"
     (CL:FUNCTION FILES-PLUS-SYSTEM-STARTUP) NULL)
    (DEFINE-FUNCTION-OBJECT "SYSTEM-DEFINITION-NATIVE-FILES"
     "(DEFUN (SYSTEM-DEFINITION-NATIVE-FILES (CONS OF STRING-WRAPPER)) ((SYSTEM SYSTEM-DEFINITION)))"
     (CL:FUNCTION SYSTEM-DEFINITION-NATIVE-FILES) NULL)
    (DEFINE-FUNCTION-OBJECT "SYSTEM-LOADED?"
     "(DEFUN (SYSTEM-LOADED? BOOLEAN) ((NAME STRING)) :DOCUMENTATION \"Return `true' if system `name' has been loaded.\" :PUBLIC? TRUE)"
     (CL:FUNCTION SYSTEM-LOADED?) NULL)
    (DEFINE-FUNCTION-OBJECT "CLEAR-SYSTEM"
     "(DEFUN CLEAR-SYSTEM ((NAME STRING)) :DOCUMENTATION \"Clears out the system definition named `name'.  If
`name' is `null', then clear out all system definitions.  This function
is useful when changes have been made to the system definition, and one
wants to have it reloaded from the standard location in the file system.\" :PUBLIC? TRUE)"
     (CL:FUNCTION CLEAR-SYSTEM) NULL)
    (DEFINE-FUNCTION-OBJECT "LOAD-PREPROCESSED-FILES"
     "(DEFUN LOAD-PREPROCESSED-FILES ((SYSTEMNAME STRING)))"
     (CL:FUNCTION LOAD-PREPROCESSED-FILES) NULL)
    (DEFINE-FUNCTION-OBJECT "LOAD-SYSTEM"
     "(DEFUN (LOAD-SYSTEM BOOLEAN) ((SYSTEMNAME STRING) (LANGUAGE KEYWORD) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Natively `language'-compile out-of-date translated files of system
`systemName' and then load them into the running system (this is only
supported/possible for Lisp at the moment).  Return true if at least one
file was compiled. The following keyword/value `options' are recognized:

`:force-recompilation?' (default false): if true, files will be compiled
whether or not their compilations are up-to-date.

`:startup?' (default true): if true, the system startup function will
be called once all files have been loaded.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LOAD-SYSTEM) NULL)
    (DEFINE-FUNCTION-OBJECT "COMPILE-AND-LOAD-FILES"
     "(DEFUN (COMPILE-AND-LOAD-FILES BOOLEAN) ((FILES (CONS OF STRING-WRAPPER)) (LANGUAGE KEYWORD) (FORCERECOMPILATION? BOOLEAN)))"
     (CL:FUNCTION COMPILE-AND-LOAD-FILES) NULL)
    (DEFINE-FUNCTION-OBJECT "RUN-SYSTEM-STARTUP-FUNCTION"
     "(DEFUN RUN-SYSTEM-STARTUP-FUNCTION ((SYSTEM SYSTEM-DEFINITION)))"
     (CL:FUNCTION RUN-SYSTEM-STARTUP-FUNCTION) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (SYSTEM-STARTUP-FUNCTION-NAME STRING) ((SYSTEM SYSTEM-DEFINITION)))"
     (CL:FUNCTION SYSTEM-STARTUP-FUNCTION-NAME) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (SYSTEM-STARTUP-FUNCTION-NAME STRING) ((SYSTEMNAME STRING)))"
     (CL:FUNCTION SYSTEM-STARTUP-FUNCTION-NAME) NULL)
    (DEFINE-FUNCTION-OBJECT "SYSTEM-STARTUP-FUNCTION-SYMBOL"
     "(DEFUN (SYSTEM-STARTUP-FUNCTION-SYMBOL SYMBOL) ((SYSTEM SYSTEM-DEFINITION)))"
     (CL:FUNCTION SYSTEM-STARTUP-FUNCTION-SYMBOL) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-NAME-FROM-FILE"
     "(DEFUN (STARTUP-NAME-FROM-FILE SYMBOL) ((FILE FILE-NAME)))"
     (CL:FUNCTION STARTUP-NAME-FROM-FILE) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-NAMES-FROM-FILES"
     "(DEFUN (STARTUP-NAMES-FROM-FILES (CONS OF SYMBOL)) ((FILES (CONS OF STRING-WRAPPER))))"
     (CL:FUNCTION STARTUP-NAMES-FROM-FILES) NULL)
    (DEFINE-FUNCTION-OBJECT "SYSTEM-STARTUP-FILE-NAME"
     "(DEFUN (SYSTEM-STARTUP-FILE-NAME STRING) ((SYSTEM SYSTEM-DEFINITION)))"
     (CL:FUNCTION SYSTEM-STARTUP-FILE-NAME) NULL)
    (DEFINE-FUNCTION-OBJECT "SYSTEM-STARTUP-FILE?"
     "(DEFUN (SYSTEM-STARTUP-FILE? BOOLEAN) ((FILE FILE-NAME)))"
     (CL:FUNCTION SYSTEM-STARTUP-FILE?) NULL)
    (DEFINE-FUNCTION-OBJECT "SYSTEM-STARTED-UP?"
     "(DEFUN (SYSTEM-STARTED-UP? BOOLEAN) ((SYSTEMNAME STRING) (SYSTEMMODULENAME STRING)))"
     (CL:FUNCTION SYSTEM-STARTED-UP?) NULL)
    (DEFINE-FUNCTION-OBJECT "YIELD-STARTUP-REQUIRED-SYSTEMS"
     "(DEFUN (YIELD-STARTUP-REQUIRED-SYSTEMS CONS) ((SYSTEM SYSTEM-DEFINITION)))"
     (CL:FUNCTION YIELD-STARTUP-REQUIRED-SYSTEMS) NULL)
    (DEFINE-FUNCTION-OBJECT "COLLECT-STARTUP-FORMS-FROM-SYSTEM-FILE"
     "(DEFUN (COLLECT-STARTUP-FORMS-FROM-SYSTEM-FILE (CONS OF CONS)) ((SYSTEM SYSTEM-DEFINITION)))"
     (CL:FUNCTION COLLECT-STARTUP-FORMS-FROM-SYSTEM-FILE) NULL)
    (DEFINE-FUNCTION-OBJECT "CREATE-SYSTEM-STARTUP-FILE"
     "(DEFUN CREATE-SYSTEM-STARTUP-FILE ((SYSTEM SYSTEM-DEFINITION)))"
     (CL:FUNCTION CREATE-SYSTEM-STARTUP-FILE) NULL)
    (DEFINE-FUNCTION-OBJECT "MAKE-STELLA"
     "(DEFUN MAKE-STELLA ((FORCERECOMPILATION? BOOLEAN)))"
     (CL:FUNCTION MAKE-STELLA) NULL)
    (DEFINE-FUNCTION-OBJECT "PARSE-CONFIGURATION-FILE-LINE"
     "(DEFUN (PARSE-CONFIGURATION-FILE-LINE STRING-WRAPPER WRAPPER) ((LINE STRING)))"
     (CL:FUNCTION PARSE-CONFIGURATION-FILE-LINE) NULL)
    (DEFINE-FUNCTION-OBJECT "LOAD-CONFIGURATION-FILE"
     "(DEFUN (LOAD-CONFIGURATION-FILE CONFIGURATION-TABLE) ((FILE FILE-NAME)) :DOCUMENTATION \"Read a configuration `file' and return its content as a configuration table.
Also enter each property read into the global system configuration table.
Assumes Java-style property file syntax.  Each property name is represented
as a wrapped string and each value as a wrapped string/integer/float or boolean.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LOAD-CONFIGURATION-FILE) NULL)
    (DEFINE-FUNCTION-OBJECT "LOOKUP-CONFIGURATION-PROPERTY"
     "(DEFUN (LOOKUP-CONFIGURATION-PROPERTY WRAPPER) ((PROPERTY STRING) (DEFAULTVALUE WRAPPER) (CONFIGURATION CONFIGURATION-TABLE)) :DOCUMENTATION \"Lookup `property' in `configuration' and return its value.
Use the global system configuration table if `configuration' is NULL.  Return
`defaultValue' if `property' is not defined.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LOOKUP-CONFIGURATION-PROPERTY) NULL)
    (DEFINE-FUNCTION-OBJECT "SET-CONFIGURATION-PROPERTY"
     "(DEFUN (SET-CONFIGURATION-PROPERTY WRAPPER) ((PROPERTY STRING) (VALUE WRAPPER) (CONFIGURATION CONFIGURATION-TABLE)) :DOCUMENTATION \"Set `property' in `configuration' to `value' and return it.
Use the global system configuration table if `configuration' is NULL.\" :PUBLIC? TRUE)"
     (CL:FUNCTION SET-CONFIGURATION-PROPERTY) NULL)
    (DEFINE-FUNCTION-OBJECT "CONFIGURE-STELLA"
     "(DEFUN CONFIGURE-STELLA ((FILE FILE-NAME)) :DOCUMENTATION \"Perform STELLA run-time configuration.  If supplied, load the
configuration file `file' first which should be supplied with a physical pathname.\" :PUBLIC? TRUE)"
     (CL:FUNCTION CONFIGURE-STELLA) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-SYSTEMS"
     "(DEFUN STARTUP-SYSTEMS () :PUBLIC? TRUE)" (CL:FUNCTION STARTUP-SYSTEMS)
     NULL)
    (CL:LET* ((FUNCTION (LOOKUP-FUNCTION SYM-SYSTEMS-STELLA-STARTUP-SYSTEMS)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-SYSTEMS-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_Startup-Systems") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (REGISTER-NATIVE-NAME SYM-SYSTEMS-STELLA-LOAD-FILE KWD-SYSTEMS-COMMON-LISP
     KWD-SYSTEMS-FUNCTION)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *SYSTEMDEFINITIONS* (LIST OF SYSTEM-DEFINITION) (NEW LIST) :DOCUMENTATION \"A list of all defined systems.\")")
    (REGISTER-NATIVE-NAME SYM-SYSTEMS-STELLA-DEFSYSTEM KWD-SYSTEMS-COMMON-LISP
     KWD-SYSTEMS-FUNCTION)
    (REGISTER-NATIVE-NAME SYM-SYSTEMS-STELLA-MAKE-SYSTEM KWD-SYSTEMS-COMMON-LISP
     KWD-SYSTEMS-FUNCTION)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *SYSTEM-CONFIGURATION-TABLE* CONFIGURATION-TABLE (NEW CONFIGURATION-TABLE))")))
  :VOID)
