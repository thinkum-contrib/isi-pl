;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; explanations.lisp

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
 | The Original Code is the PowerLoom KR&R System.                            |
 |                                                                            |
 | The Initial Developer of the Original Code is                              |
 | UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
 | 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
 |                                                                            |
 | Portions created by the Initial Developer are Copyright (C) 2002-2010      |
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
 +----------------------------- END LICENSE BLOCK ----------------------------+
|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR KWD-EXPLANATIONS-KIF NULL)
(CL:DEFVAR KWD-EXPLANATIONS-ISA NULL)
(CL:DEFVAR KWD-EXPLANATIONS-FUNCTION NULL)
(CL:DEFVAR KWD-EXPLANATIONS-PREDICATE NULL)
(CL:DEFVAR KWD-EXPLANATIONS-NOT NULL)
(CL:DEFVAR KWD-EXPLANATIONS-EQUIVALENT NULL)
(CL:DEFVAR SGT-EXPLANATIONS-LOGIC-PROPOSITION NULL)
(CL:DEFVAR SGT-EXPLANATIONS-STELLA-LITERAL-WRAPPER NULL)
(CL:DEFVAR SGT-EXPLANATIONS-LOGIC-PATTERN-VARIABLE NULL)
(CL:DEFVAR SGT-EXPLANATIONS-LOGIC-SKOLEM NULL)
(CL:DEFVAR SGT-EXPLANATIONS-LOGIC-LOGIC-OBJECT NULL)
(CL:DEFVAR SGT-EXPLANATIONS-STELLA-GENERALIZED-SYMBOL NULL)
(CL:DEFVAR SGT-EXPLANATIONS-STELLA-MODULE NULL)
(CL:DEFVAR SGT-EXPLANATIONS-STELLA-THING NULL)
(CL:DEFVAR KWD-EXPLANATIONS-JAVA-GUI-HTML NULL)
(CL:DEFVAR KWD-EXPLANATIONS-HTML NULL)
(CL:DEFVAR KWD-EXPLANATIONS-LAY NULL)
(CL:DEFVAR KWD-EXPLANATIONS-KIF-ONTOSAURUS NULL)
(CL:DEFVAR KWD-EXPLANATIONS-BRIEF NULL)
(CL:DEFVAR SYM-EXPLANATIONS-GUI-SERVER-STARTUP-EXPLANATIONS NULL)
(CL:DEFVAR SYM-EXPLANATIONS-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE* NULL-FLOAT
  *LOGIC-DIALECT-PRINT-FUNCTIONS* *LOGIC-DIALECT*
  *MOST-RECENT-EXPLANATION-MAPPING* NULL-INTEGER STANDARD-OUTPUT
  STANDARD-ERROR VALUE-OF-SEPARATOR *PLGUI-URL-ACTION* EOL))

;;; (DEFUN PLGUI-HTML-PPRINT-OBJECT ...)

(CL:DEFUN PLGUI-HTML-PPRINT-OBJECT (SELF STREAM)
  (CL:LET*
   ((*LOGIC-DIALECT* KWD-EXPLANATIONS-KIF)
    (*PPRINT-ATOMIC-OBJECT-RENDERER*
     (CL:FUNCTION PLGUI-HTML-PPRINT-ATOMIC-OBJECT)))
   (CL:DECLARE (CL:SPECIAL *LOGIC-DIALECT* *PPRINT-ATOMIC-OBJECT-RENDERER*))
   (CL:COND
    ((SUBTYPE-OF? (SAFE-PRIMARY-TYPE SELF) SGT-EXPLANATIONS-LOGIC-PROPOSITION)
     (CL:PROGN
      (CL:LET* ((TEST-VALUE-000 (%KIND SELF)))
       (CL:COND
        ((CL:OR (CL:EQ TEST-VALUE-000 KWD-EXPLANATIONS-ISA)
          (CL:EQ TEST-VALUE-000 KWD-EXPLANATIONS-FUNCTION)
          (CL:EQ TEST-VALUE-000 KWD-EXPLANATIONS-PREDICATE)
          (CL:EQ TEST-VALUE-000 KWD-EXPLANATIONS-NOT)
          (CL:EQ TEST-VALUE-000 KWD-EXPLANATIONS-EQUIVALENT)))
        (CL:T
         (CL:PROGN (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "<PRE>")
          (PPRINT-OBJECT SELF (%NATIVE-STREAM STREAM))
          (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "</PRE>" EOL))
         (CL:RETURN-FROM PLGUI-HTML-PPRINT-OBJECT))))))
    (CL:T))
   (PPRINT-OBJECT SELF (%NATIVE-STREAM STREAM))))

;;; (DEFUN PLGUI-HTML-PPRINT-ATOMIC-OBJECT ...)

(CL:DEFUN PLGUI-HTML-PPRINT-ATOMIC-OBJECT (SELF STREAM)
  (CL:WHEN (CL:NOT (CL:EQ SELF NULL))
   (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE SELF)))
    (CL:COND
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-EXPLANATIONS-STELLA-LITERAL-WRAPPER)
      (CL:PROGN (PPRINT-LITERAL-WRAPPER-FOR-HTML SELF STREAM)))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-EXPLANATIONS-LOGIC-PATTERN-VARIABLE)
      (CL:PROGN (PPRINT-ATOMIC-OBJECT SELF STREAM)))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-EXPLANATIONS-LOGIC-SKOLEM)
      (CL:PROGN
       (CL:COND
        ((CL:NOT (CL:EQ (NATIVE-VALUE-OF SELF) NULL))
         (PPRINT-ATOMIC-OBJECT (NATIVE-VALUE-OF SELF) STREAM))
        ((CL:NOT (CL:EQ (INNERMOST-OF SELF) NULL))
         (CL:IF (CL:EQ (INNERMOST-OF SELF) SELF)
          (CL:PROGN (%%PRINT-STREAM STREAM "<FONT COLOR='#666666'>")
           (%%PRINT-STREAM STREAM
            (STRING-DOWNCASE (GET-SKOLEM-PRINT-NAME SELF)))
           (%%PRINT-STREAM STREAM "</FONT>"))
          (CL:PROGN
           (CL:PROGN (%%PRINT-STREAM STREAM "<FONT COLOR='#996633'>")
            (%%PRINT-STREAM STREAM
             (STRING-DOWNCASE (GET-SKOLEM-PRINT-NAME SELF)))
            (%%PRINT-STREAM STREAM VALUE-OF-SEPARATOR)
            (%%PRINT-STREAM STREAM "</FONT>"))
           (PPRINT-OBJECT (INNERMOST-OF SELF) STREAM))))
        (CL:T (%%PRINT-STREAM STREAM (GENERATE-SKOLEM SELF))))))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-EXPLANATIONS-LOGIC-LOGIC-OBJECT)
      (CL:PROGN
       (CL:IF (CL:NOT (CL:EQ (%SURROGATE-VALUE-INVERSE SELF) NULL))
        (PRINT-PLGUI-URL SELF STREAM)
        (%%PRINT-STREAM STREAM "Unamed_Object"))))
     ((SUBTYPE-OF-SURROGATE? TEST-VALUE-000)
      (CL:PROGN
       (CL:IF (CL:NOT (CL:EQ (%SURROGATE-VALUE SELF) NULL))
        (PPRINT-OBJECT (%SURROGATE-VALUE SELF) STREAM)
        (%%PRINT-STREAM STREAM (SURROGATE-TO-SYMBOL SELF)))))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-EXPLANATIONS-STELLA-GENERALIZED-SYMBOL)
      (CL:PROGN
       (WRITE-HTML-QUOTING-SPECIAL-CHARACTERS STREAM (%SYMBOL-NAME SELF))))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-EXPLANATIONS-STELLA-MODULE)
      (CL:PROGN (PLGUI-WRITE-URL STREAM *PLGUI-URL-ACTION* "context" SELF)))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-EXPLANATIONS-STELLA-THING)
      (CL:PROGN
       (CL:IF (CL:NOT (CL:EQ (%SURROGATE-VALUE-INVERSE SELF) NULL))
        (%%PRINT-STREAM STREAM (%SYMBOL-NAME (%SURROGATE-VALUE-INVERSE SELF)))
        (%%PRINT-STREAM STREAM SELF))))
     (CL:T (%%PRINT-STREAM STREAM SELF))))))

;;; (DEFSPECIAL *PLGUI-URL-ACTION* ...)

(CL:DEFVAR *PLGUI-URL-ACTION* "show"
  "The action parameter for URL printing")
(CL:DECLAIM (CL:TYPE CL:SIMPLE-STRING *PLGUI-URL-ACTION*))

;;; (DEFUN PRINT-PLGUI-URL ...)

(CL:DEFUN PRINT-PLGUI-URL (THE-OBJECT NATIVESTREAM)
  "Prints a URL following PowerLoom Plgui conventions."
  (PLGUI-WRITE-URL NATIVESTREAM *PLGUI-URL-ACTION*
   (LOGIC-OBJECT-DISPLAY-TYPE THE-OBJECT) THE-OBJECT))

;;; (DEFUN PLGUI-WRITE-URL-IN-DETAIL ...)

(CL:DEFUN PLGUI-WRITE-URL-IN-DETAIL (STREAM TARGET ACTION OBJECTTYPE CONTEXTNAME OBJECTNAME OBJECTTITLE RAWTITLE?)
  (CL:DECLARE
   (CL:TYPE CL:SIMPLE-STRING TARGET ACTION OBJECTTYPE CONTEXTNAME OBJECTNAME
    OBJECTTITLE))
  #+MCL
  (CL:CHECK-TYPE TARGET CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE ACTION CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE OBJECTTYPE CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE CONTEXTNAME CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE OBJECTNAME CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE OBJECTTITLE CL:SIMPLE-STRING)
  (CL:SETQ ACTION ACTION)
  (%%PRINT-STREAM STREAM "<A ")
  (CL:WHEN (CL:NOT (CL:EQ TARGET STELLA::NULL-STRING))
   (%%PRINT-STREAM STREAM "TARGET='" TARGET "' "))
  (%%PRINT-STREAM STREAM "HREF='plgui:navigateTo?type="
   (STRING-UPCASE OBJECTTYPE) "&id=")
  (WRITE-HTML-ESCAPING-URL-SPECIAL-CHARACTERS STREAM OBJECTNAME)
  (%%PRINT-STREAM STREAM "&module=")
  (WRITE-HTML-ESCAPING-URL-SPECIAL-CHARACTERS STREAM CONTEXTNAME)
  (%%PRINT-STREAM STREAM "'>")
  (CL:IF RAWTITLE? (%%PRINT-STREAM STREAM OBJECTTITLE)
   (WRITE-HTML-QUOTING-SPECIAL-CHARACTERS STREAM OBJECTTITLE))
  (%%PRINT-STREAM STREAM "</A>")
  NULL)

;;; (DEFUN PLGUI-WRITE-URL ...)

(CL:DEFUN PLGUI-WRITE-URL (STREAM ACTION OBJECTTYPE OBJECT)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING ACTION OBJECTTYPE))
  #+MCL
  (CL:CHECK-TYPE ACTION CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE OBJECTTYPE CL:SIMPLE-STRING)
  (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE OBJECT)))
   (CL:COND
    ((SUBTYPE-OF? TEST-VALUE-000 SGT-EXPLANATIONS-LOGIC-LOGIC-OBJECT)
     (CL:PROGN
      (CL:LET* ((WRITEMODULE (HOME-MODULE OBJECT)))
       (PLGUI-WRITE-URL-IN-DETAIL STREAM STELLA::NULL-STRING ACTION OBJECTTYPE
        (NAME WRITEMODULE) (OBJECT-STRING-NAME OBJECT)
        (OBJECT-STRING-NAME OBJECT) CL:NIL))))
    ((SUBTYPE-OF? TEST-VALUE-000 SGT-EXPLANATIONS-STELLA-MODULE)
     (CL:PROGN
      (PLGUI-WRITE-URL-IN-DETAIL STREAM STELLA::NULL-STRING ACTION OBJECTTYPE
       (NAME OBJECT) (NAME OBJECT) (NAME OBJECT) CL:NIL)))
    (CL:T
     (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) STANDARD-ERROR
      "Don't know how to write URL for object" OBJECT)
     (%%PRINT-STREAM STREAM OBJECT))))
  NULL)

;;; (DEFUN PRINT-JUSTIFICATION-TO-HTML-FILE ...)

(CL:DEFUN PRINT-JUSTIFICATION-TO-HTML-FILE (JUSTIFICATION FILE)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING FILE))
  #+MCL
  (CL:CHECK-TYPE FILE CL:SIMPLE-STRING)
  (CL:LET*
   ((*EXPLANATION-FORMAT* KWD-EXPLANATIONS-HTML)
    (*EXPLANATION-AUDIENCE* KWD-EXPLANATIONS-LAY)
    (*LOGIC-DIALECT* KWD-EXPLANATIONS-KIF-ONTOSAURUS)
    (*MOST-RECENT-EXPLANATION-MAPPING* (NEW-KEY-VALUE-LIST)))
   (CL:DECLARE
    (CL:SPECIAL *EXPLANATION-FORMAT* *EXPLANATION-AUDIENCE* *LOGIC-DIALECT*
     *MOST-RECENT-EXPLANATION-MAPPING*))
   (CL:WHEN
    (CL:EQ (LOOKUP *LOGIC-DIALECT-PRINT-FUNCTIONS* *LOGIC-DIALECT*) NULL)
    (CL:SETQ *LOGIC-DIALECT* KWD-EXPLANATIONS-KIF))
   (CL:LET*
    ((INFO
      (REGISTER-JUSTIFICATION (VISIBLE-JUSTIFICATION JUSTIFICATION)
       *MOST-RECENT-EXPLANATION-MAPPING*)))
    (CL:SETF (%LABEL INFO) "1") (CL:SETF (%DEPTH INFO) 1))
   (CL:LET* ((STREAM NULL))
    (CL:UNWIND-PROTECT
     (CL:PROGN (CL:SETQ STREAM (OPEN-OUTPUT-FILE FILE))
      (%%PRINT-STREAM (%NATIVE-STREAM STREAM) EOL "Explanation #1 score="
       (%POSITIVE-SCORE JUSTIFICATION) ":" EOL EOL)
      (PRINT-WHYNOT-JUSTIFICATION (VISIBLE-JUSTIFICATION JUSTIFICATION) STREAM
       NULL-INTEGER KWD-EXPLANATIONS-BRIEF CL:NIL))
     (CL:WHEN (CL:NOT (CL:EQ STREAM NULL)) (FREE STREAM))))))

;;; (DEFGLOBAL *PLGUI-EXPLANATION-TRACE-FILE* ...)

(CL:DEFVAR *PLGUI-EXPLANATION-TRACE-FILE* STELLA::NULL-STRING)
(CL:DECLAIM (CL:TYPE CL:SIMPLE-STRING *PLGUI-EXPLANATION-TRACE-FILE*))

;;; (DEFUN (GET-JUSTIFICATION-STRING STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING) GET-JUSTIFICATION-STRING))
(CL:DEFUN GET-JUSTIFICATION-STRING (JUSTIFICATION)
  (CL:LET*
   ((*EXPLANATION-FORMAT* KWD-EXPLANATIONS-HTML)
    (*EXPLANATION-AUDIENCE* KWD-EXPLANATIONS-LAY)
    (*LOGIC-DIALECT* KWD-EXPLANATIONS-JAVA-GUI-HTML)
    (*MOST-RECENT-EXPLANATION-MAPPING* (NEW-KEY-VALUE-LIST)))
   (CL:DECLARE
    (CL:SPECIAL *EXPLANATION-FORMAT* *EXPLANATION-AUDIENCE* *LOGIC-DIALECT*
     *MOST-RECENT-EXPLANATION-MAPPING*))
   (CL:LET*
    ((STRINGSTREAM (NEW-OUTPUT-STRING-STREAM))
     (INFO
      (REGISTER-JUSTIFICATION (VISIBLE-JUSTIFICATION JUSTIFICATION)
       *MOST-RECENT-EXPLANATION-MAPPING*)))
    (CL:SETF (%LABEL INFO) "1") (CL:SETF (%DEPTH INFO) 1)
    (%%PRINT-STREAM (%NATIVE-STREAM STRINGSTREAM) EOL "Explanation #1")
    (CL:WHEN (CL:NOT (CL:= (%POSITIVE-SCORE JUSTIFICATION) NULL-FLOAT))
     (%%PRINT-STREAM (%NATIVE-STREAM STRINGSTREAM) " score="
      (%POSITIVE-SCORE JUSTIFICATION)))
    (%%PRINT-STREAM (%NATIVE-STREAM STRINGSTREAM) ":" EOL EOL)
    (PRINT-WHYNOT-JUSTIFICATION (VISIBLE-JUSTIFICATION JUSTIFICATION)
     STRINGSTREAM NULL-INTEGER KWD-EXPLANATIONS-BRIEF CL:NIL)
    (CL:LET* ((RESULT (THE-STRING-READER STRINGSTREAM)))
     (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING RESULT))
     (CL:WHEN
      (CL:NOT (CL:EQ *PLGUI-EXPLANATION-TRACE-FILE* STELLA::NULL-STRING))
      (CL:LET* ((OUT NULL))
       (CL:UNWIND-PROTECT
        (CL:PROGN
         (CL:SETQ OUT (OPEN-OUTPUT-FILE *PLGUI-EXPLANATION-TRACE-FILE*))
         (%%PRINT-STREAM (%NATIVE-STREAM OUT) RESULT EOL))
        (CL:WHEN (CL:NOT (CL:EQ OUT NULL)) (FREE OUT)))))
     RESULT))))

(CL:DEFUN STARTUP-EXPLANATIONS ()
  (CL:LET*
   ((*MODULE*
     (GET-STELLA-MODULE "/POWERLOOM-SERVER/GUI-SERVER"
      (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ KWD-EXPLANATIONS-KIF
     (INTERN-RIGID-SYMBOL-WRT-MODULE "KIF" NULL 2))
    (CL:SETQ KWD-EXPLANATIONS-ISA
     (INTERN-RIGID-SYMBOL-WRT-MODULE "ISA" NULL 2))
    (CL:SETQ KWD-EXPLANATIONS-FUNCTION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FUNCTION" NULL 2))
    (CL:SETQ KWD-EXPLANATIONS-PREDICATE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "PREDICATE" NULL 2))
    (CL:SETQ KWD-EXPLANATIONS-NOT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "NOT" NULL 2))
    (CL:SETQ KWD-EXPLANATIONS-EQUIVALENT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "EQUIVALENT" NULL 2))
    (CL:SETQ SGT-EXPLANATIONS-LOGIC-PROPOSITION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "PROPOSITION"
      (GET-STELLA-MODULE "/LOGIC" CL:T) 1))
    (CL:SETQ SGT-EXPLANATIONS-STELLA-LITERAL-WRAPPER
     (INTERN-RIGID-SYMBOL-WRT-MODULE "LITERAL-WRAPPER"
      (GET-STELLA-MODULE "/STELLA" CL:T) 1))
    (CL:SETQ SGT-EXPLANATIONS-LOGIC-PATTERN-VARIABLE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "PATTERN-VARIABLE"
      (GET-STELLA-MODULE "/LOGIC" CL:T) 1))
    (CL:SETQ SGT-EXPLANATIONS-LOGIC-SKOLEM
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SKOLEM"
      (GET-STELLA-MODULE "/LOGIC" CL:T) 1))
    (CL:SETQ SGT-EXPLANATIONS-LOGIC-LOGIC-OBJECT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "LOGIC-OBJECT"
      (GET-STELLA-MODULE "/LOGIC" CL:T) 1))
    (CL:SETQ SGT-EXPLANATIONS-STELLA-GENERALIZED-SYMBOL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "GENERALIZED-SYMBOL"
      (GET-STELLA-MODULE "/STELLA" CL:T) 1))
    (CL:SETQ SGT-EXPLANATIONS-STELLA-MODULE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "MODULE"
      (GET-STELLA-MODULE "/STELLA" CL:T) 1))
    (CL:SETQ SGT-EXPLANATIONS-STELLA-THING
     (INTERN-RIGID-SYMBOL-WRT-MODULE "THING"
      (GET-STELLA-MODULE "/STELLA" CL:T) 1))
    (CL:SETQ KWD-EXPLANATIONS-JAVA-GUI-HTML
     (INTERN-RIGID-SYMBOL-WRT-MODULE "JAVA-GUI-HTML" NULL 2))
    (CL:SETQ KWD-EXPLANATIONS-HTML
     (INTERN-RIGID-SYMBOL-WRT-MODULE "HTML" NULL 2))
    (CL:SETQ KWD-EXPLANATIONS-LAY
     (INTERN-RIGID-SYMBOL-WRT-MODULE "LAY" NULL 2))
    (CL:SETQ KWD-EXPLANATIONS-KIF-ONTOSAURUS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "KIF-ONTOSAURUS" NULL 2))
    (CL:SETQ KWD-EXPLANATIONS-BRIEF
     (INTERN-RIGID-SYMBOL-WRT-MODULE "BRIEF" NULL 2))
    (CL:SETQ SYM-EXPLANATIONS-GUI-SERVER-STARTUP-EXPLANATIONS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-EXPLANATIONS" NULL 0))
    (CL:SETQ SYM-EXPLANATIONS-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ *PLGUI-EXPLANATION-TRACE-FILE* STELLA::NULL-STRING))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "PLGUI-HTML-PPRINT-OBJECT"
     "(DEFUN PLGUI-HTML-PPRINT-OBJECT ((SELF OBJECT) (STREAM OUTPUT-STREAM)))"
     (CL:FUNCTION PLGUI-HTML-PPRINT-OBJECT) NULL)
    (DEFINE-FUNCTION-OBJECT "PLGUI-HTML-PPRINT-ATOMIC-OBJECT"
     "(DEFUN PLGUI-HTML-PPRINT-ATOMIC-OBJECT ((SELF OBJECT) (STREAM NATIVE-OUTPUT-STREAM)) :PUBLIC? TRUE)"
     (CL:FUNCTION PLGUI-HTML-PPRINT-ATOMIC-OBJECT) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-PLGUI-URL"
     "(DEFUN PRINT-PLGUI-URL ((THE-OBJECT LOGIC-OBJECT) (NATIVESTREAM NATIVE-OUTPUT-STREAM)) :PUBLIC? TRUE :DOCUMENTATION \"Prints a URL following PowerLoom Plgui conventions.\")"
     (CL:FUNCTION PRINT-PLGUI-URL) NULL)
    (DEFINE-FUNCTION-OBJECT "PLGUI-WRITE-URL-IN-DETAIL"
     "(DEFUN PLGUI-WRITE-URL-IN-DETAIL ((STREAM NATIVE-OUTPUT-STREAM) (TARGET STRING) (ACTION STRING) (OBJECTTYPE STRING) (CONTEXTNAME STRING) (OBJECTNAME STRING) (OBJECTTITLE STRING) (RAWTITLE? BOOLEAN)))"
     (CL:FUNCTION PLGUI-WRITE-URL-IN-DETAIL) NULL)
    (DEFINE-FUNCTION-OBJECT "PLGUI-WRITE-URL"
     "(DEFUN PLGUI-WRITE-URL ((STREAM NATIVE-OUTPUT-STREAM) (ACTION STRING) (OBJECTTYPE STRING) (OBJECT STANDARD-OBJECT)))"
     (CL:FUNCTION PLGUI-WRITE-URL) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-JUSTIFICATION-TO-HTML-FILE"
     "(DEFUN PRINT-JUSTIFICATION-TO-HTML-FILE ((JUSTIFICATION JUSTIFICATION) (FILE STRING)))"
     (CL:FUNCTION PRINT-JUSTIFICATION-TO-HTML-FILE) NULL)
    (DEFINE-FUNCTION-OBJECT "GET-JUSTIFICATION-STRING"
     "(DEFUN (GET-JUSTIFICATION-STRING STRING) ((JUSTIFICATION JUSTIFICATION)))"
     (CL:FUNCTION GET-JUSTIFICATION-STRING) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-EXPLANATIONS"
     "(DEFUN STARTUP-EXPLANATIONS () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-EXPLANATIONS) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION SYM-EXPLANATIONS-GUI-SERVER-STARTUP-EXPLANATIONS)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-EXPLANATIONS-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupExplanations") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "GUI-SERVER")))
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *PLGUI-URL-ACTION* STRING \"show\" :DOCUMENTATION \"The action parameter for URL printing\" :PUBLIC? TRUE)")
    (REGISTER-LOGIC-DIALECT-PRINT-FUNCTION KWD-EXPLANATIONS-JAVA-GUI-HTML
     (WRAP-FUNCTION-CODE (CL:FUNCTION PLGUI-HTML-PPRINT-OBJECT)))
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *PLGUI-EXPLANATION-TRACE-FILE* STRING NULL)"))))
