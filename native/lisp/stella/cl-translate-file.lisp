;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; cl-translate-file.lisp

#|
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
| Portions created by the Initial Developer are Copyright (C) 1996-2017      |
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
|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR SYM-CL-TRANSLATE-FILE-STELLA-LPTRANS NULL)
(CL:DEFVAR KWD-CL-TRANSLATE-FILE-COMMON-LISP NULL)
(CL:DEFVAR KWD-CL-TRANSLATE-FILE-FUNCTION NULL)
(CL:DEFVAR SYM-CL-TRANSLATE-FILE-STELLA-PTRANS NULL)
(CL:DEFVAR SYM-CL-TRANSLATE-FILE-STELLA-GLOBAL-VARIABLE NULL)
(CL:DEFVAR SGT-CL-TRANSLATE-FILE-STELLA-CONS NULL)
(CL:DEFVAR KWD-CL-TRANSLATE-FILE-LISP NULL)
(CL:DEFVAR KWD-CL-TRANSLATE-FILE-USE-COMMON-LISP-STRUCTS NULL)
(CL:DEFVAR KWD-CL-TRANSLATE-FILE-USE-COMMON-LISP-VECTOR-STRUCTS NULL)
(CL:DEFVAR SYM-CL-TRANSLATE-FILE-STELLA-CLASS NULL)
(CL:DEFVAR KWD-CL-TRANSLATE-FILE-STELLA NULL)
(CL:DEFVAR KWD-CL-TRANSLATE-FILE-FINALIZE NULL)
(CL:DEFVAR KWD-CL-TRANSLATE-FILE-TWO-PASS? NULL)
(CL:DEFVAR KWD-CL-TRANSLATE-FILE-FORCE-TRANSLATION? NULL)
(CL:DEFVAR KWD-CL-TRANSLATE-FILE-PRODUCTION-SETTINGS? NULL)
(CL:DEFVAR KWD-CL-TRANSLATE-FILE-LISP-BINARY NULL)
(CL:DEFVAR SYM-CL-TRANSLATE-FILE-STELLA-STARTUP-CL-TRANSLATE-FILE NULL)
(CL:DEFVAR SYM-CL-TRANSLATE-FILE-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STELLA-MODULE* FALSE-WRAPPER TRUE-WRAPPER *CURRENTFILE* *CURRENTSYSTEMDEFINITION* *MODULE* *TRANSLATIONVERBOSITYLEVEL* *TRANSLATIONUNITS*
  *CURRENT-STELLA-FEATURES* EOL *TRANSLATOROUTPUTLANGUAGE* NULL-INTEGER NIL STANDARD-OUTPUT))

;;; (DEFUN LPTRANS ...)

(CL:DEFUN %LPTRANS (STATEMENT)
  "Translate `statement' to Common-Lisp and print the result."
  (HELP-LPTRANS STATEMENT)
  :VOID)

(CL:DEFMACRO LPTRANS (CL:&WHOLE EXPRESSION CL:&REST IGNORE)
  "Translate `statement' to Common-Lisp and print the result."
  (CL:DECLARE (CL:IGNORE IGNORE))
  (CL:LET ((*IGNORETRANSLATIONERRORS?* FALSE)) (CL-INCREMENTALLY-TRANSLATE EXPRESSION)))

(CL:SETF (CL:MACRO-FUNCTION (CL:QUOTE |/STELLA/LPTRANS|)) (CL:MACRO-FUNCTION (CL:QUOTE LPTRANS)))

;;; (DEFUN PTRANS ...)

(CL:DEFUN %PTRANS (STATEMENT)
  "Translate `statement' to Common-Lisp and print the result."
  (HELP-LPTRANS STATEMENT)
  :VOID)

(CL:DEFMACRO PTRANS (CL:&WHOLE EXPRESSION CL:&REST IGNORE)
  "Translate `statement' to Common-Lisp and print the result."
  (CL:DECLARE (CL:IGNORE IGNORE))
  (CL:LET ((*IGNORETRANSLATIONERRORS?* FALSE)) (CL-INCREMENTALLY-TRANSLATE EXPRESSION)))

(CL:SETF (CL:MACRO-FUNCTION (CL:QUOTE |/STELLA/PTRANS|)) (CL:MACRO-FUNCTION (CL:QUOTE PTRANS)))

;;; (DEFUN HELP-LPTRANS ...)

(CL:DEFUN HELP-LPTRANS (STATEMENT)
  (CL:LET* ((*TRANSLATOROUTPUTLANGUAGE* *TRANSLATOROUTPUTLANGUAGE*) (*PRINTPRETTYCODE?* CL:T)) (CL:DECLARE (CL:SPECIAL *TRANSLATOROUTPUTLANGUAGE* *PRINTPRETTYCODE?*))
   (%SET-TRANSLATOR-OUTPUT-LANGUAGE KWD-CL-TRANSLATE-FILE-COMMON-LISP)
   (CL:LET* ((DECLARATION? (DECLARATION-TREE? STATEMENT)) (TRANSLATION (INCREMENTALLY-TRANSLATE STATEMENT)))
    (CL:COND
     ((CL:AND DECLARATION? (CONS? TRANSLATION) (CL:EQ (%%VALUE TRANSLATION) (INTERN-COMMON-LISP-SYMBOL "PROGN")))
      (CL:LET* ((ELT NULL) (ITER-000 (%%REST TRANSLATION)) (I NULL-INTEGER) (ITER-001 1)) (CL:DECLARE (CL:TYPE CL:FIXNUM I ITER-001))
       (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ ELT (%%VALUE ITER-000)) (CL:SETQ I ITER-001)
        (CL:IF (CL:= I 1) (PRINT-STELLA-DEFINITION ELT (%NATIVE-STREAM STANDARD-OUTPUT)) (PRINT-STELLA-CODE ELT (%NATIVE-STREAM STANDARD-OUTPUT)))
        (CL:SETQ ITER-000 (%%REST ITER-000)) (CL:SETQ ITER-001 (CL:1+ ITER-001)))))
     (CL:T (PRINT-STELLA-CODE TRANSLATION (%NATIVE-STREAM STANDARD-OUTPUT))))))
  :VOID)

;;; (DEFUN (AUXILIARY-VARIABLE-UNIT? BOOLEAN) ...)

(CL:DEFUN AUXILIARY-VARIABLE-UNIT? (UNIT)
  (CL:RETURN-FROM AUXILIARY-VARIABLE-UNIT? (CL:AND (%AUXILIARY? UNIT) (CL:EQ (%CATEGORY UNIT) SYM-CL-TRANSLATE-FILE-STELLA-GLOBAL-VARIABLE))))

;;; (DEFUN CL-OUTPUT-ONE-UNIT ...)

(CL:DEFUN CL-OUTPUT-ONE-UNIT (UNIT STREAM)
  (CL:LET* ((TRANSLATION (%TRANSLATION UNIT)))
   (CL:WHEN (CL:EQ TRANSLATION NULL) (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "`" UNIT "' has a NULL translation." EOL) (CL:RETURN-FROM CL-OUTPUT-ONE-UNIT))
   (CL:WHEN (CL:NOT (CL:EQ (%CATEGORY UNIT) NULL)) (CL:WHEN (CL:NOT (AUXILIARY-VARIABLE-UNIT? UNIT)) (%%PRINT-STREAM STREAM EOL))
    (CL:WHEN (CL:NOT (CL:EQ (%ANNOTATION UNIT) STELLA::NULL-STRING)) (%%PRINT-STREAM STREAM ";;; " (%ANNOTATION UNIT) EOL EOL))
    (CL:IF (CL:AND (ISA? TRANSLATION SGT-CL-TRANSLATE-FILE-STELLA-CONS) (CL:EQ (%%VALUE TRANSLATION) (INTERN-COMMON-LISP-SYMBOL "PROGN")))
     (CL:LET* ((FORM NULL) (ITER-000 (%%REST TRANSLATION)))
      (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ FORM (%%VALUE ITER-000)) (PRINT-STELLA-DEFINITION FORM STREAM) (CL:SETQ ITER-000 (%%REST ITER-000))))
     (PRINT-STELLA-DEFINITION TRANSLATION STREAM))
    (CL:SETF (%CATEGORY UNIT) NULL)))
  :VOID)

;;; (DEFUN CL-OUTPUT-ALL-UNITS-TO-FILE ...)

(CL:DEFUN CL-OUTPUT-ALL-UNITS-TO-FILE (SOURCEFILE)
  (CL:LET*
   ((OUTPUTFILE (MAKE-FILE-NAME SOURCEFILE KWD-CL-TRANSLATE-FILE-LISP CL:NIL)) (OUTPUTSTREAM (NEW-OUTPUT-FILE-STREAM OUTPUTFILE))
    (NATIVEOUTPUTSTREAM (%NATIVE-STREAM OUTPUTSTREAM)))
   (CL:WHEN (CL:>= *TRANSLATIONVERBOSITYLEVEL* 1) (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "Writing `" OUTPUTFILE "'..." EOL))
   (OUTPUT-FILE-HEADER OUTPUTSTREAM OUTPUTFILE) (%%PRINT-STREAM NATIVEOUTPUTSTREAM ";;; Auxiliary variables:" EOL EOL)
   (CL:LET* ((UNIT NULL) (ITER-000 (%THE-CONS-LIST *TRANSLATIONUNITS*)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ UNIT (%%VALUE ITER-000))
     (CL:WHEN (AUXILIARY-VARIABLE-UNIT? UNIT) (CL-OUTPUT-ONE-UNIT UNIT NATIVEOUTPUTSTREAM)) (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL-OUTPUT-FORWARD-DECLARATIONS NATIVEOUTPUTSTREAM)
   (CL:WHEN
    (CL:AND (MEMB? *CURRENT-STELLA-FEATURES* KWD-CL-TRANSLATE-FILE-USE-COMMON-LISP-STRUCTS)
     (CL:NOT (MEMB? *CURRENT-STELLA-FEATURES* KWD-CL-TRANSLATE-FILE-USE-COMMON-LISP-VECTOR-STRUCTS)))
    (CL:LET* ((UNIT NULL) (ITER-001 (%THE-CONS-LIST *TRANSLATIONUNITS*)))
     (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO (CL:SETQ UNIT (%%VALUE ITER-001))
      (CL:WHEN (CL:EQ (%CATEGORY UNIT) SYM-CL-TRANSLATE-FILE-STELLA-CLASS) (CL-OUTPUT-ONE-UNIT UNIT NATIVEOUTPUTSTREAM)) (CL:SETQ ITER-001 (%%REST ITER-001)))))
   (CL:LET* ((UNIT NULL) (ITER-002 (%THE-CONS-LIST *TRANSLATIONUNITS*)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-002 NIL)) DO (CL:SETQ UNIT (%%VALUE ITER-002))
     (CL:WHEN (CL:NOT (AUXILIARY-VARIABLE-UNIT? UNIT)) (CL-OUTPUT-ONE-UNIT UNIT NATIVEOUTPUTSTREAM)) (CL:SETQ ITER-002 (%%REST ITER-002))))
   (FREE OUTPUTSTREAM))
  :VOID)

;;; (DEFUN CL-OUTPUT-FILE-HEADER ...)

(CL:DEFUN CL-OUTPUT-FILE-HEADER (STREAM FILE ENSUREPACKAGE?)
  (CL:LET* ((PACKAGE (LISP-PACKAGE *MODULE*))) (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PACKAGE))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM) ";;; -*- Mode: Lisp; Package: " PACKAGE "; Syntax: COMMON-LISP; Base: 10 -*-" EOL EOL)
   (CL:WHEN (CL:NOT (CL:EQ FILE STELLA::NULL-STRING)) (%%PRINT-STREAM (%NATIVE-STREAM STREAM) ";;; " (FILE-NAME-WITHOUT-DIRECTORY FILE) EOL EOL))
   (CL:LET* ((*TRANSLATOROUTPUTLANGUAGE* KWD-CL-TRANSLATE-FILE-COMMON-LISP)) (CL:DECLARE (CL:SPECIAL *TRANSLATOROUTPUTLANGUAGE*)) (OUTPUT-COPYRIGHT-HEADER STREAM))
   (CL:WHEN (CL:NOT (CL:OR (STRING-EQL? PACKAGE "STELLA") (CL:NOT ENSUREPACKAGE?))) (CL-OUTPUT-ENSURE-PACKAGE-DEFINITION STREAM PACKAGE)
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM) EOL))
   (CL-OUTPUT-IN-PACKAGE-DECLARATION STREAM PACKAGE) (%%PRINT-STREAM (%NATIVE-STREAM STREAM) EOL))
  :VOID)

;;; (DEFUN CL-OUTPUT-ENSURE-PACKAGE-DEFINITION ...)

(CL:DEFUN CL-OUTPUT-ENSURE-PACKAGE-DEFINITION (STREAM PACKAGE)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PACKAGE))
  #+(or MCL OpenMCL)
  (CL:CHECK-TYPE PACKAGE CL:SIMPLE-STRING)
  (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "(CL:EVAL-WHEN (:COMPILE-TOPLEVEL :LOAD-TOPLEVEL :EXECUTE)" EOL "  (CL:UNLESS (CL:FIND-PACKAGE \"" PACKAGE "\")" EOL
   "     (CL:DEFPACKAGE \"" PACKAGE "\" (:USE))))" EOL)
  :VOID)

;;; (DEFUN CL-OUTPUT-IN-PACKAGE-DECLARATION ...)

(CL:DEFUN CL-OUTPUT-IN-PACKAGE-DECLARATION (STREAM PACKAGE)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PACKAGE))
  #+(or MCL OpenMCL)
  (CL:CHECK-TYPE PACKAGE CL:SIMPLE-STRING)
  (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "(CL:IN-PACKAGE \"" PACKAGE "\")" EOL)
  :VOID)

;;; (DEFUN CL-OUTPUT-FORWARD-DECLARATIONS ...)

(CL:DEFUN CL-OUTPUT-FORWARD-DECLARATIONS (STREAM)
  (CL:LET* ((DEFINEDVARIABLES (NEW-LIST)) (FORWARDREFERENCEDVARIABLES (NEW-LIST)))
   (CL:LET* ((UNIT NULL) (ITER-000 (%THE-CONS-LIST *TRANSLATIONUNITS*)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ UNIT (%%VALUE ITER-000))
     (CL:WHEN (AUXILIARY-VARIABLE-UNIT? UNIT) (PUSH DEFINEDVARIABLES (%THE-OBJECT UNIT))) (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:LET* ((UNIT NULL) (ITER-001 (%THE-CONS-LIST *TRANSLATIONUNITS*)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO (CL:SETQ UNIT (%%VALUE ITER-001))
     (CL:WHEN (CL:NOT (AUXILIARY-VARIABLE-UNIT? UNIT))
      (CL:WHEN (CL:EQ (%CATEGORY UNIT) SYM-CL-TRANSLATE-FILE-STELLA-GLOBAL-VARIABLE) (PUSH DEFINEDVARIABLES (%THE-OBJECT UNIT)))
      (CL:LET* ((VARIABLE NULL) (ITER-002 (%THE-CONS-LIST (%REFERENCED-GLOBALS UNIT))))
       (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-002 NIL)) DO (CL:SETQ VARIABLE (%%VALUE ITER-002))
        (CL:WHEN (CL:AND (CL:NOT (MEMBER? DEFINEDVARIABLES VARIABLE)) (CL:NOT (MEMBER? FORWARDREFERENCEDVARIABLES VARIABLE))) (PUSH FORWARDREFERENCEDVARIABLES VARIABLE))
        (CL:SETQ ITER-002 (%%REST ITER-002)))))
     (CL:SETQ ITER-001 (%%REST ITER-001))))
   (CL:LET* ((IT (ALLOCATE-ITERATOR FORWARDREFERENCEDVARIABLES))) (CL:LOOP WHILE (NEXT? IT) DO (VALUE-SETTER IT (%VARIABLE-NAME (%VALUE IT)))))
   (CL:WHEN (NON-EMPTY? FORWARDREFERENCEDVARIABLES) (%%PRINT-STREAM STREAM EOL ";;; Forward declarations:" EOL EOL)
    (PRINT-STELLA-DEFINITION
     (LIST* (INTERN-COMMON-LISP-SYMBOL "DECLAIM")
      (CONS (INTERN-COMMON-LISP-SYMBOL "SPECIAL") (CONCATENATE (CL-TRANSLATE-LIST-OF-TREES (%THE-CONS-LIST FORWARDREFERENCEDVARIABLES)) NIL)) NIL)
     STREAM))
   (FREE DEFINEDVARIABLES) (FREE FORWARDREFERENCEDVARIABLES))
  :VOID)

;;; (DEFUN CL-TRANSLATE-FILE ...)

(CL:DEFUN CL-TRANSLATE-FILE (FILE RELATIVE?)
  "Translate a Stella `file' to Common-Lisp.  If
`relative?', concatenate root directory to `file'."
  (CL:WHEN RELATIVE? (CL:SETQ FILE (MAKE-FILE-NAME FILE KWD-CL-TRANSLATE-FILE-STELLA CL:T)))
  (TRANSLATE-FILE FILE KWD-CL-TRANSLATE-FILE-COMMON-LISP CL:NIL)
  :VOID)

;;; (DEFUN CL-TRANSLATE-WALKED-SYSTEM-UNITS ...)

(CL:DEFUN CL-TRANSLATE-WALKED-SYSTEM-UNITS (SYSTEMUNITS)
  (CL:LET* ((*CURRENTFILE* STELLA::NULL-STRING) (*TRANSLATIONUNITS* NULL)) (CL:DECLARE (CL:SPECIAL *CURRENTFILE* *TRANSLATIONUNITS*))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING *CURRENTFILE*))
   (CL:LET* ((CLASSUNITS (NEW-LIST)) (USECLSTRUCTS? (MEMB? *CURRENT-STELLA-FEATURES* KWD-CL-TRANSLATE-FILE-USE-COMMON-LISP-STRUCTS)) (FILENAME STELLA::NULL-STRING))
    (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING FILENAME))
    (CL:LET* ((FILE NULL) (UNITS NULL) (ITER-000 (%THE-KV-LIST SYSTEMUNITS)))
     (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NULL)) DO (CL:SETQ FILE (%KEY ITER-000)) (CL:SETQ UNITS (%VALUE ITER-000))
      (CL:SETQ *CURRENTFILE* (FILE-BASE-NAME (%WRAPPER-VALUE FILE)))
      (CL:COND
       (USECLSTRUCTS? (CL:SETQ *TRANSLATIONUNITS* (NEW-LIST))
        (CL:LET* ((UNIT NULL) (ITER-001 (%THE-CONS-LIST UNITS)))
         (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO (CL:SETQ UNIT (%%VALUE ITER-001))
          (CL:IF (CL:EQ (%CATEGORY UNIT) SYM-CL-TRANSLATE-FILE-STELLA-CLASS) (PUSH CLASSUNITS UNIT) (PUSH *TRANSLATIONUNITS* UNIT))
          (CL:SETQ ITER-001 (%%REST ITER-001))))
        (REVERSE *TRANSLATIONUNITS*))
       (CL:T (CL:SETQ *TRANSLATIONUNITS* UNITS)))
      (CL:LET* ((*MODULE* (COMPUTE-FILE-UNITS-MODULE UNITS)) (*CONTEXT* *MODULE*)) (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
       (TRANSLATE-AND-OUTPUT-UNITS-TO-FILE (%WRAPPER-VALUE FILE) "Common Lisp"))
      (CLEAN-UP-TRANSLATION-UNITS-SPECIAL) (CL:SETQ ITER-000 (%REST ITER-000))))
    (CL:WHEN USECLSTRUCTS?
     (CL:WHEN (CL:>= *TRANSLATIONVERBOSITYLEVEL* 1) (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "Collecting CL structure class definitions..." EOL))
     (CL:LET* ((FILE NULL) (ITER-002 (FILES-PLUS-SYSTEM-STARTUP (SYSTEM-DEFINITION-SOURCE-FILES *CURRENTSYSTEMDEFINITION*))))
      (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-002 NIL)) DO (CL:SETQ FILE (%%VALUE ITER-002))
       (CL:WHEN (CL:EQ (LOOKUP SYSTEMUNITS (WRAP-STRING (CL:SETQ FILENAME (MAKE-FILE-NAME (%WRAPPER-VALUE FILE) KWD-CL-TRANSLATE-FILE-STELLA CL:T)))) NULL)
        (CL:SETQ *TRANSLATIONUNITS* (NEW-LIST)) (CL:SETQ *CURRENTFILE* (FILE-BASE-NAME FILENAME)) (CL:SETQ *TRANSLATIONUNITS* (NEW-LIST))
        (OPERATE-ON-FILE FILENAME KWD-CL-TRANSLATE-FILE-FINALIZE)
        (CL:LET* ((UNIT NULL) (ITER-003 (%THE-CONS-LIST *TRANSLATIONUNITS*)) (COLLECT-000 NULL))
         (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-003 NIL)) DO (CL:SETQ UNIT (%%VALUE ITER-003))
          (CL:WHEN (CL:AND (CL:EQ (%CATEGORY UNIT) SYM-CL-TRANSLATE-FILE-STELLA-CLASS) (CREATE-NATIVE-CLASS? (%THE-OBJECT UNIT)) (CL:NOT (%MIXIN? (%THE-OBJECT UNIT))))
           (CL:IF (CL:EQ COLLECT-000 NULL)
            (CL:PROGN (CL:SETQ COLLECT-000 (CONS UNIT NIL))
             (CL:IF (CL:EQ (%THE-CONS-LIST CLASSUNITS) NIL) (CL:SETF (%THE-CONS-LIST CLASSUNITS) COLLECT-000)
              (ADD-CONS-TO-END-OF-CONS-LIST (%THE-CONS-LIST CLASSUNITS) COLLECT-000)))
            (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS UNIT NIL)) (CL:SETQ COLLECT-000 (%%REST COLLECT-000)))))
          (CL:SETQ ITER-003 (%%REST ITER-003))))
        (CLEAN-UP-TRANSLATION-UNITS-SPECIAL))
       (CL:SETQ ITER-002 (%%REST ITER-002))))
     (CL-OUTPUT-SYSTEM-CL-STRUCTS-FILE CLASSUNITS))))
  :VOID)

;;; (DEFUN (SORT-CL-STRUCT-CLASSES (LIST OF CLASS)) ...)

(CL:DEFUN SORT-CL-STRUCT-CLASSES (UNSORTEDCLASSES)
  (CL:LET* ((CLASSTABLE (NEW-HASH-TABLE)) (ROOTS (LIST)) (SORTEDCLASSES (LIST)))
   (CL:LET* ((CLASS NULL) (ITER-000 (%THE-CONS-LIST UNSORTEDCLASSES)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ CLASS (%%VALUE ITER-000)) (INSERT-AT CLASSTABLE (%CLASS-TYPE CLASS) TRUE-WRAPPER)
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:LET* ((CLASS NULL) (ITER-001 (%THE-CONS-LIST UNSORTEDCLASSES)) (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO (CL:SETQ CLASS (%%VALUE ITER-001))
     (CL:LET* ((TEST-VALUE-000 CL:NIL))
      (CL:LET* ((FOUND?-000 CL:NIL))
       (CL:LET* ((SUPER NULL) (ITER-002 (%THE-CONS-LIST (%CLASS-DIRECT-SUPERS CLASS))))
        (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-002 NIL)) DO (CL:SETQ SUPER (%%VALUE ITER-002))
         (CL:WHEN (CL:NOT (CL:EQ (LOOKUP CLASSTABLE SUPER) NULL)) (CL:SETQ FOUND?-000 CL:T) (CL:RETURN)) (CL:SETQ ITER-002 (%%REST ITER-002))))
       (CL:SETQ TEST-VALUE-000 FOUND?-000))
      (CL:SETQ TEST-VALUE-000 (CL:NOT TEST-VALUE-000))
      (CL:WHEN TEST-VALUE-000
       (CL:IF (CL:EQ COLLECT-000 NULL)
        (CL:PROGN (CL:SETQ COLLECT-000 (CONS CLASS NIL))
         (CL:IF (CL:EQ (%THE-CONS-LIST ROOTS) NIL) (CL:SETF (%THE-CONS-LIST ROOTS) COLLECT-000) (ADD-CONS-TO-END-OF-CONS-LIST (%THE-CONS-LIST ROOTS) COLLECT-000)))
        (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS CLASS NIL)) (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
     (CL:SETQ ITER-001 (%%REST ITER-001))))
   (CL:LOOP WHILE (NON-EMPTY? ROOTS) DO (PUSH SORTEDCLASSES (FIRST ROOTS))
    (CL:LET* ((SUB NULL) (ITER-003 (%THE-CONS-LIST (%CLASS-DIRECT-SUBS (POP ROOTS)))))
     (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-003 NIL)) DO (CL:SETQ SUB (%%VALUE ITER-003))
      (CL:WHEN (CL:NOT (CL:EQ (LOOKUP CLASSTABLE SUB) NULL)) (PUSH ROOTS (%SURROGATE-VALUE SUB))) (CL:SETQ ITER-003 (%%REST ITER-003)))))
   (CL:RETURN-FROM SORT-CL-STRUCT-CLASSES (REVERSE SORTEDCLASSES))))

;;; (DEFUN (CL-YIELD-STRUCT-CLASS-FILE-NAME FILE-NAME) ...)

(CL:DEFUN CL-YIELD-STRUCT-CLASS-FILE-NAME (SYSTEMNAME)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SYSTEMNAME))
  #+(or MCL OpenMCL)
  (CL:CHECK-TYPE SYSTEMNAME CL:SIMPLE-STRING)
  (CL:RETURN-FROM CL-YIELD-STRUCT-CLASS-FILE-NAME (CONCATENATE (STRING-DOWNCASE SYSTEMNAME) "-system-structs")))

;;; (DEFUN CL-OUTPUT-SYSTEM-CL-STRUCTS-FILE ...)

(CL:DEFUN CL-OUTPUT-SYSTEM-CL-STRUCTS-FILE (CLASSUNITS)
  (CL:LET*
   ((OUTPUTFILE (MAKE-FILE-NAME (CL-YIELD-STRUCT-CLASS-FILE-NAME (%NAME *CURRENTSYSTEMDEFINITION*)) KWD-CL-TRANSLATE-FILE-LISP CL:T))
    (OUTPUTSTREAM (NEW-OUTPUT-FILE-STREAM OUTPUTFILE)) (CLASSES (NEW-LIST)) (CURRENTMODULE *MODULE*) (PACKAGE STELLA::NULL-STRING) (ENSUREDPACKAGES (LIST)))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PACKAGE))
   (CL:LET* ((UNIT NULL) (ITER-000 (%THE-CONS-LIST CLASSUNITS)) (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ UNIT (%%VALUE ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS (%THE-OBJECT UNIT) NIL))
       (CL:IF (CL:EQ (%THE-CONS-LIST CLASSES) NIL) (CL:SETF (%THE-CONS-LIST CLASSES) COLLECT-000) (ADD-CONS-TO-END-OF-CONS-LIST (%THE-CONS-LIST CLASSES) COLLECT-000)))
      (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS (%THE-OBJECT UNIT) NIL)) (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:SETQ CLASSES (SORT-CL-STRUCT-CLASSES CLASSES))
   (CL:WHEN (CL:>= *TRANSLATIONVERBOSITYLEVEL* 1) (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "Writing `" OUTPUTFILE "'..." EOL))
   (CL:LET* ((*MODULE* *MODULE*) (*CONTEXT* *MODULE*)) (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
    (CL:IF (NON-EMPTY? CLASSES) (CL:SETQ *MODULE* (HOME-MODULE (FIRST CLASSES)))
     (CL:SETQ *MODULE* (GET-STELLA-MODULE (%CARDINAL-MODULE *CURRENTSYSTEMDEFINITION*) CL:T)))
    (CL:SETQ CURRENTMODULE *MODULE*) (CL-OUTPUT-FILE-HEADER OUTPUTSTREAM OUTPUTFILE CL:T)
    (CL:LET* ((UNIT NULL) (ITER-001 (%THE-CONS-LIST CLASSUNITS)) (CLASS NULL) (ITER-002 (%THE-CONS-LIST CLASSES)))
     (CL:LOOP WHILE (CL:AND (CL:NOT (CL:EQ ITER-001 NIL)) (CL:NOT (CL:EQ ITER-002 NIL))) DO (CL:SETQ UNIT (%%VALUE ITER-001)) (CL:SETQ CLASS (%%VALUE ITER-002))
      (CL:SETF (%THE-OBJECT UNIT) CLASS) (CL:SETF (%ANNOTATION UNIT) STELLA::NULL-STRING) (CL:SETQ *MODULE* (HOME-MODULE CLASS))
      (CL:WHEN (CL:NOT (CL:EQ *MODULE* CURRENTMODULE)) (CL:SETQ CURRENTMODULE *MODULE*) (CL:SETQ PACKAGE (LISP-PACKAGE *MODULE*))
       (CL:WHEN (CL:NOT (MEMBER? ENSUREDPACKAGES (WRAP-STRING PACKAGE))) (PUSH ENSUREDPACKAGES (WRAP-STRING PACKAGE)) (%%PRINT-STREAM (%NATIVE-STREAM OUTPUTSTREAM) EOL)
        (CL-OUTPUT-ENSURE-PACKAGE-DEFINITION OUTPUTSTREAM PACKAGE))
       (%%PRINT-STREAM (%NATIVE-STREAM OUTPUTSTREAM) EOL) (CL-OUTPUT-IN-PACKAGE-DECLARATION OUTPUTSTREAM PACKAGE))
      (CL:SETF (%TRANSLATION UNIT) (CL-TRANSLATE-DEFINE-NATIVE-CLASS-UNIT UNIT)) (CL-OUTPUT-ONE-UNIT UNIT (%NATIVE-STREAM OUTPUTSTREAM))
      (CL:SETQ ITER-001 (%%REST ITER-001)) (CL:SETQ ITER-002 (%%REST ITER-002)))))
   (FREE OUTPUTSTREAM))
  :VOID)

;;; (DEFUN CL-TRANSLATE-SYSTEM ...)

(CL:DEFUN CL-TRANSLATE-SYSTEM (SYSTEM-NAME)
  "Translate a Stella system named `system-name' to Common Lisp."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SYSTEM-NAME))
  #+(or MCL OpenMCL)
  (CL:CHECK-TYPE SYSTEM-NAME CL:SIMPLE-STRING)
  (%TRANSLATE-SYSTEM SYSTEM-NAME
   (CONS-LIST KWD-CL-TRANSLATE-FILE-COMMON-LISP KWD-CL-TRANSLATE-FILE-TWO-PASS? TRUE-WRAPPER KWD-CL-TRANSLATE-FILE-FORCE-TRANSLATION? TRUE-WRAPPER
    KWD-CL-TRANSLATE-FILE-PRODUCTION-SETTINGS? TRUE-WRAPPER))
  :VOID)

;;; (DEFUN (CL-COMPILE-AND-LOAD-FILES BOOLEAN) ...)

(CL:DEFUN CL-COMPILE-AND-LOAD-FILES (FILES RELATIVE? FORCERECOMPILATION?)
  (CL:LET* ((LISPKEY KWD-CL-TRANSLATE-FILE-LISP) (BINARYKEY KWD-CL-TRANSLATE-FILE-LISP-BINARY) (TRANSLATEDFILE? CL:NIL))   (with-redefinition-warnings-suppressed
      (with-undefined-function-warnings-suppressed
        (with-style-warnings-suppressed
          (CL:let ((CL:*compile-verbose* CL-USER::*stella-verbose?*))
	    (CL:proclaim CL-USER::*stella-compiler-optimization*)
	    (CL:loop for file in files
		     as translatedfile = (make-file-name (unwrap-string file) lispkey relative?)
		     as binaryfile = (make-file-name (unwrap-string file) binarykey relative?)
		     when (Cl:or (CL-USER::stella-need-to-compile?
				  translatedFile binaryFile)
				 forceRecompilation?)
		     do (CL:ensure-directories-exist binaryFile)
                        (CL:compile-file translatedFile :output-file binaryFile)
		     do (CL:load binaryFile))))))
      (CL:setq translatedFile? TRUE) (CL:RETURN-FROM CL-COMPILE-AND-LOAD-FILES TRANSLATEDFILE?)))

;;; (DEFUN CL-TRANSLATE-STELLA ...)

(CL:DEFUN CL-TRANSLATE-STELLA (PRODUCTIONSETTINGS?)
  (%TRANSLATE-SYSTEM "stella"
   (CONS-LIST KWD-CL-TRANSLATE-FILE-COMMON-LISP KWD-CL-TRANSLATE-FILE-FORCE-TRANSLATION? TRUE-WRAPPER KWD-CL-TRANSLATE-FILE-PRODUCTION-SETTINGS?
    (CL:IF PRODUCTIONSETTINGS? TRUE-WRAPPER FALSE-WRAPPER)))
  :VOID)

;;; (DEFUN CL-RETRANSLATE-STELLA ...)

(CL:DEFUN CL-RETRANSLATE-STELLA (PRODUCTIONSETTINGS?)
  (%TRANSLATE-SYSTEM "stella"
   (CONS-LIST KWD-CL-TRANSLATE-FILE-COMMON-LISP KWD-CL-TRANSLATE-FILE-TWO-PASS? TRUE-WRAPPER KWD-CL-TRANSLATE-FILE-FORCE-TRANSLATION? TRUE-WRAPPER
    KWD-CL-TRANSLATE-FILE-PRODUCTION-SETTINGS? (CL:IF PRODUCTIONSETTINGS? TRUE-WRAPPER FALSE-WRAPPER)))
  :VOID)

(CL:DEFUN STARTUP-CL-TRANSLATE-FILE ()
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*)) (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2) (CL:SETQ SYM-CL-TRANSLATE-FILE-STELLA-LPTRANS (INTERN-RIGID-SYMBOL-WRT-MODULE "LPTRANS" NULL 0))
    (CL:SETQ KWD-CL-TRANSLATE-FILE-COMMON-LISP (INTERN-RIGID-SYMBOL-WRT-MODULE "COMMON-LISP" NULL 2))
    (CL:SETQ KWD-CL-TRANSLATE-FILE-FUNCTION (INTERN-RIGID-SYMBOL-WRT-MODULE "FUNCTION" NULL 2))
    (CL:SETQ SYM-CL-TRANSLATE-FILE-STELLA-PTRANS (INTERN-RIGID-SYMBOL-WRT-MODULE "PTRANS" NULL 0))
    (CL:SETQ SYM-CL-TRANSLATE-FILE-STELLA-GLOBAL-VARIABLE (INTERN-RIGID-SYMBOL-WRT-MODULE "GLOBAL-VARIABLE" NULL 0))
    (CL:SETQ SGT-CL-TRANSLATE-FILE-STELLA-CONS (INTERN-RIGID-SYMBOL-WRT-MODULE "CONS" NULL 1))
    (CL:SETQ KWD-CL-TRANSLATE-FILE-LISP (INTERN-RIGID-SYMBOL-WRT-MODULE "LISP" NULL 2))
    (CL:SETQ KWD-CL-TRANSLATE-FILE-USE-COMMON-LISP-STRUCTS (INTERN-RIGID-SYMBOL-WRT-MODULE "USE-COMMON-LISP-STRUCTS" NULL 2))
    (CL:SETQ KWD-CL-TRANSLATE-FILE-USE-COMMON-LISP-VECTOR-STRUCTS (INTERN-RIGID-SYMBOL-WRT-MODULE "USE-COMMON-LISP-VECTOR-STRUCTS" NULL 2))
    (CL:SETQ SYM-CL-TRANSLATE-FILE-STELLA-CLASS (INTERN-RIGID-SYMBOL-WRT-MODULE "CLASS" NULL 0))
    (CL:SETQ KWD-CL-TRANSLATE-FILE-STELLA (INTERN-RIGID-SYMBOL-WRT-MODULE "STELLA" NULL 2))
    (CL:SETQ KWD-CL-TRANSLATE-FILE-FINALIZE (INTERN-RIGID-SYMBOL-WRT-MODULE "FINALIZE" NULL 2))
    (CL:SETQ KWD-CL-TRANSLATE-FILE-TWO-PASS? (INTERN-RIGID-SYMBOL-WRT-MODULE "TWO-PASS?" NULL 2))
    (CL:SETQ KWD-CL-TRANSLATE-FILE-FORCE-TRANSLATION? (INTERN-RIGID-SYMBOL-WRT-MODULE "FORCE-TRANSLATION?" NULL 2))
    (CL:SETQ KWD-CL-TRANSLATE-FILE-PRODUCTION-SETTINGS? (INTERN-RIGID-SYMBOL-WRT-MODULE "PRODUCTION-SETTINGS?" NULL 2))
    (CL:SETQ KWD-CL-TRANSLATE-FILE-LISP-BINARY (INTERN-RIGID-SYMBOL-WRT-MODULE "LISP-BINARY" NULL 2))
    (CL:SETQ SYM-CL-TRANSLATE-FILE-STELLA-STARTUP-CL-TRANSLATE-FILE (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-CL-TRANSLATE-FILE" NULL 0))
    (CL:SETQ SYM-CL-TRANSLATE-FILE-STELLA-METHOD-STARTUP-CLASSNAME (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "LPTRANS"
     "(DEFUN LPTRANS ((STATEMENT OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Translate `statement' to Common-Lisp and print the result.\")"
     (CL:FUNCTION %LPTRANS) NULL)
    (DEFINE-FUNCTION-OBJECT "PTRANS"
     "(DEFUN PTRANS ((STATEMENT OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Translate `statement' to Common-Lisp and print the result.\")"
     (CL:FUNCTION %PTRANS) NULL)
    (DEFINE-FUNCTION-OBJECT "HELP-LPTRANS" "(DEFUN HELP-LPTRANS ((STATEMENT OBJECT)))" (CL:FUNCTION HELP-LPTRANS) NULL)
    (DEFINE-FUNCTION-OBJECT "AUXILIARY-VARIABLE-UNIT?" "(DEFUN (AUXILIARY-VARIABLE-UNIT? BOOLEAN) ((UNIT TRANSLATION-UNIT)))" (CL:FUNCTION AUXILIARY-VARIABLE-UNIT?)
     NULL)
    (DEFINE-FUNCTION-OBJECT "CL-OUTPUT-ONE-UNIT" "(DEFUN CL-OUTPUT-ONE-UNIT ((UNIT TRANSLATION-UNIT) (STREAM NATIVE-OUTPUT-STREAM)))" (CL:FUNCTION CL-OUTPUT-ONE-UNIT)
     NULL)
    (DEFINE-FUNCTION-OBJECT "CL-OUTPUT-ALL-UNITS-TO-FILE" "(DEFUN CL-OUTPUT-ALL-UNITS-TO-FILE ((SOURCEFILE FILE-NAME)))" (CL:FUNCTION CL-OUTPUT-ALL-UNITS-TO-FILE) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-OUTPUT-FILE-HEADER" "(DEFUN CL-OUTPUT-FILE-HEADER ((STREAM OUTPUT-STREAM) (FILE FILE-NAME) (ENSUREPACKAGE? BOOLEAN)))"
     (CL:FUNCTION CL-OUTPUT-FILE-HEADER) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-OUTPUT-ENSURE-PACKAGE-DEFINITION" "(DEFUN CL-OUTPUT-ENSURE-PACKAGE-DEFINITION ((STREAM OUTPUT-STREAM) (PACKAGE STRING)))"
     (CL:FUNCTION CL-OUTPUT-ENSURE-PACKAGE-DEFINITION) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-OUTPUT-IN-PACKAGE-DECLARATION" "(DEFUN CL-OUTPUT-IN-PACKAGE-DECLARATION ((STREAM OUTPUT-STREAM) (PACKAGE STRING)))"
     (CL:FUNCTION CL-OUTPUT-IN-PACKAGE-DECLARATION) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-OUTPUT-FORWARD-DECLARATIONS" "(DEFUN CL-OUTPUT-FORWARD-DECLARATIONS ((STREAM NATIVE-OUTPUT-STREAM)))"
     (CL:FUNCTION CL-OUTPUT-FORWARD-DECLARATIONS) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-TRANSLATE-FILE"
     "(DEFUN CL-TRANSLATE-FILE ((FILE FILE-NAME) (RELATIVE? BOOLEAN)) :DOCUMENTATION \"Translate a Stella `file' to Common-Lisp.  If
`relative?', concatenate root directory to `file'.\" :PUBLIC? TRUE)" (CL:FUNCTION CL-TRANSLATE-FILE) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-TRANSLATE-WALKED-SYSTEM-UNITS" "(DEFUN CL-TRANSLATE-WALKED-SYSTEM-UNITS ((SYSTEMUNITS SYSTEM-UNITS-ALIST)))"
     (CL:FUNCTION CL-TRANSLATE-WALKED-SYSTEM-UNITS) NULL)
    (DEFINE-FUNCTION-OBJECT "SORT-CL-STRUCT-CLASSES" "(DEFUN (SORT-CL-STRUCT-CLASSES (LIST OF CLASS)) ((UNSORTEDCLASSES (LIST OF CLASS))))"
     (CL:FUNCTION SORT-CL-STRUCT-CLASSES) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-YIELD-STRUCT-CLASS-FILE-NAME" "(DEFUN (CL-YIELD-STRUCT-CLASS-FILE-NAME FILE-NAME) ((SYSTEMNAME STRING)))"
     (CL:FUNCTION CL-YIELD-STRUCT-CLASS-FILE-NAME) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-OUTPUT-SYSTEM-CL-STRUCTS-FILE" "(DEFUN CL-OUTPUT-SYSTEM-CL-STRUCTS-FILE ((CLASSUNITS (LIST OF TRANSLATION-UNIT))))"
     (CL:FUNCTION CL-OUTPUT-SYSTEM-CL-STRUCTS-FILE) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-TRANSLATE-SYSTEM"
     "(DEFUN CL-TRANSLATE-SYSTEM ((SYSTEM-NAME STRING)) :DOCUMENTATION \"Translate a Stella system named `system-name' to Common Lisp.\" :PUBLIC? TRUE)"
     (CL:FUNCTION CL-TRANSLATE-SYSTEM) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-COMPILE-AND-LOAD-FILES"
     "(DEFUN (CL-COMPILE-AND-LOAD-FILES BOOLEAN) ((FILES (CONS OF STRING-WRAPPER)) (RELATIVE? BOOLEAN) (FORCERECOMPILATION? BOOLEAN)))"
     (CL:FUNCTION CL-COMPILE-AND-LOAD-FILES) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-TRANSLATE-STELLA" "(DEFUN CL-TRANSLATE-STELLA ((PRODUCTIONSETTINGS? BOOLEAN)))" (CL:FUNCTION CL-TRANSLATE-STELLA) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-RETRANSLATE-STELLA" "(DEFUN CL-RETRANSLATE-STELLA ((PRODUCTIONSETTINGS? BOOLEAN)))" (CL:FUNCTION CL-RETRANSLATE-STELLA) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-CL-TRANSLATE-FILE" "(DEFUN STARTUP-CL-TRANSLATE-FILE () :PUBLIC? TRUE)" (CL:FUNCTION STARTUP-CL-TRANSLATE-FILE) NULL)
    (CL:LET* ((FUNCTION (LOOKUP-FUNCTION SYM-CL-TRANSLATE-FILE-STELLA-STARTUP-CL-TRANSLATE-FILE)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION) SYM-CL-TRANSLATE-FILE-STELLA-METHOD-STARTUP-CLASSNAME (WRAP-STRING "_StartupClTranslateFile")
      NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS) (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9) (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "STELLA")))
    (REGISTER-NATIVE-NAME SYM-CL-TRANSLATE-FILE-STELLA-LPTRANS KWD-CL-TRANSLATE-FILE-COMMON-LISP KWD-CL-TRANSLATE-FILE-FUNCTION)
    (REGISTER-NATIVE-NAME SYM-CL-TRANSLATE-FILE-STELLA-PTRANS KWD-CL-TRANSLATE-FILE-COMMON-LISP KWD-CL-TRANSLATE-FILE-FUNCTION)))
  :VOID)
