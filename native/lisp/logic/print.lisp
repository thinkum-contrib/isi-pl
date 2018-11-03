;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; print.lisp

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
 | Portions created by the Initial Developer are Copyright (C) 1997-2012      |
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

(CL:DEFVAR SGT-PRINT-LOGIC-DESCRIPTION NULL)
(CL:DEFVAR SGT-PRINT-LOGIC-PATTERN-VARIABLE NULL)
(CL:DEFVAR SGT-PRINT-LOGIC-SKOLEM NULL)
(CL:DEFVAR SGT-PRINT-LOGIC-TRUTH-VALUE NULL)
(CL:DEFVAR SGT-PRINT-LOGIC-LOGIC-OBJECT NULL)
(CL:DEFVAR SGT-PRINT-LOGIC-PROPOSITION NULL)
(CL:DEFVAR KWD-PRINT-FLAT NULL)
(CL:DEFVAR KWD-PRINT-REALISTIC NULL)
(CL:DEFVAR KWD-PRINT-ORIGINAL NULL)
(CL:DEFVAR KWD-PRINT-DEBUG-LOW NULL)
(CL:DEFVAR KWD-PRINT-DEBUG-HIGH NULL)
(CL:DEFVAR SYM-PRINT-LOGIC-DESCRIPTION NULL)
(CL:DEFVAR SGT-PRINT-STELLA-RELATION NULL)
(CL:DEFVAR SYM-PRINT-LOGIC-DESCRIPTIVE? NULL)
(CL:DEFVAR SYM-PRINT-STELLA-SURROGATE-VALUE-INVERSE NULL)
(CL:DEFVAR SYM-PRINT-LOGIC-STARTUP-PRINT NULL)
(CL:DEFVAR SYM-PRINT-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE* *LOADINGREGENERABLEOBJECTS?*
  FALSE-WRAPPER *REVERSEPOLARITY?* *CURRENTJUSTIFICATION*
  *PRINTINFRAME* *PRINTREADABLY?* STANDARD-OUTPUT))

;;; (DEFUN (WRAP-NATIVE-OUTPUT-STREAM OUTPUT-STREAM) ...)

(CL:DEFUN WRAP-NATIVE-OUTPUT-STREAM (NATIVESTREAM)
  (CL:IF (CL:EQ NATIVESTREAM (%NATIVE-STREAM STANDARD-OUTPUT))
   STANDARD-OUTPUT
   (CL:LET* ((SELF-000 (NEW-OUTPUT-STREAM)))
    (CL:SETF (%NATIVE-STREAM SELF-000) NATIVESTREAM)
    (CL:LET* ((VALUE-000 SELF-000)) VALUE-000))))

;;; (DEFUN PRINT-TOP-LEVEL-OBJECT ...)

(CL:DEFUN PRINT-TOP-LEVEL-OBJECT (SELF NATIVESTREAM)
  (CL:LET* ((STREAM (WRAP-NATIVE-OUTPUT-STREAM NATIVESTREAM)))
   (CL:WHEN (DELETED? SELF)
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "#DELETED#"))
   (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE SELF)))
    (CL:COND
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-PRINT-LOGIC-DESCRIPTION)
      (CL:PROGN (PRINT-DESCRIPTION SELF STREAM CL:T)))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-PRINT-LOGIC-PATTERN-VARIABLE)
      (CL:PROGN (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "|V|")
       (PRINT-VARIABLE SELF STREAM)))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-PRINT-LOGIC-SKOLEM)
      (CL:PROGN (PRINT-SKOLEM SELF STREAM CL:T)))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-PRINT-LOGIC-TRUTH-VALUE)
      (CL:PROGN (PRINT-TRUTH-VALUE SELF STREAM)))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-PRINT-LOGIC-LOGIC-OBJECT)
      (CL:PROGN (PRINT-LOGIC-OBJECT SELF STREAM CL:T)))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-PRINT-LOGIC-PROPOSITION)
      (CL:PROGN (PRINT-PROPOSITION SELF STREAM CL:T)))
     (CL:T (%%PRINT-STREAM (%NATIVE-STREAM STREAM) SELF))))))

;;; (DEFSPECIAL *PRINTMODE* ...)

(CL:DEFVAR *PRINTMODE* NULL
  "Controls the kind of detail that gets printed about
individual objects.  Values are :ORIGINAL, :REALISTIC, :FLAT, :DEBUG-LOW, and
 :DEBUG-HIGH.")

;;; (DEFSPECIAL *PRINTFUNCTIONSASRELATIONS?* ...)

(CL:DEFVAR *PRINTFUNCTIONSASRELATIONS?* CL:NIL
  "Controls whether functions are printed as relations (F i v) or
as functions (= (F i) v).")

;;; (DEFUN PRINT-LOGIC-OBJECT ...)

(CL:DEFUN PRINT-LOGIC-OBJECT (SELF STREAM TOPLEVEL?)
  (CL:LET*
   ((PREFIX
     (CL:IF (CL:AND TOPLEVEL? (CL:NOT *PRINTREADABLY?*)) "|i|" "")))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PREFIX))
   (CL:COND
    ((CL:NOT (CL:EQ (%SURROGATE-VALUE-INVERSE SELF) NULL))
     (CL:WHEN
      (CL:AND
       (CL:NOT
        (CL:EQ (%SURROGATE-VALUE (%SURROGATE-VALUE-INVERSE SELF))
         SELF))
       (CL:NOT (SYNONYM-SURROGATE? (%SURROGATE-VALUE-INVERSE SELF))))
      (CL:SETQ PREFIX "|BAD surrogate|"))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM) PREFIX
      (STRINGIFIED-SURROGATE (%SURROGATE-VALUE-INVERSE SELF))))
    (CL:T
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM) PREFIX "_"
      (%SYMBOL-NAME (LOGICAL-TYPE SELF)))))))

;;; (DEFCONSTANT VARIABLE-BINDING-SEPARATOR ...)

(CL:DEFVAR VARIABLE-BINDING-SEPARATOR "/")
(CL:DECLAIM (CL:TYPE CL:SIMPLE-STRING VARIABLE-BINDING-SEPARATOR))

;;; (DEFCONSTANT VALUE-OF-SEPARATOR ...)

(CL:DEFVAR VALUE-OF-SEPARATOR "//")
(CL:DECLAIM (CL:TYPE CL:SIMPLE-STRING VALUE-OF-SEPARATOR))

;;; (DEFSPECIAL *SKOLEMNAMEMAPPINGTABLE* ...)

(CL:DEFVAR *SKOLEMNAMEMAPPINGTABLE* NULL
  "If set, maps some skolems to names other than
their own.")

;;; (DEFUN (GET-SKOLEM-PRINT-NAME STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING) GET-SKOLEM-PRINT-NAME))
(CL:DEFUN GET-SKOLEM-PRINT-NAME (SELF)
  (CL:IF (CL:NOT (CL:EQ *SKOLEMNAMEMAPPINGTABLE* NULL))
   (CL:LET* ((SUBSTITUTESKOLEM (LOOKUP *SKOLEMNAMEMAPPINGTABLE* SELF)))
    (CL:IF (CL:NOT (CL:EQ SUBSTITUTESKOLEM NULL))
     (%SYMBOL-NAME (%SKOLEM-NAME SUBSTITUTESKOLEM))
     (%SYMBOL-NAME (%SKOLEM-NAME SELF))))
   (%SYMBOL-NAME (%SKOLEM-NAME SELF))))

;;; (DEFUN PRINT-VALUE-OF-CHAIN ...)

(CL:DEFUN PRINT-VALUE-OF-CHAIN (SELF STREAM CHAINEND)
  (CL:WHEN (CL:EQ CHAINEND NULL) (CL:SETQ CHAINEND SELF))
  (CL:COND
   ((CL:OR (CL:EQ *PRINTMODE* KWD-PRINT-REALISTIC)
     (CL:EQ *PRINTMODE* KWD-PRINT-ORIGINAL))
    (CL:COND
     ((SUBTYPE-OF? (SAFE-PRIMARY-TYPE SELF)
       SGT-PRINT-LOGIC-PATTERN-VARIABLE)
      (CL:PROGN
       (CL:LET* ((*PRINTMODE* KWD-PRINT-FLAT))
        (CL:DECLARE (CL:SPECIAL *PRINTMODE*))
        (PRINT-VALUE-OF-CHAIN SELF STREAM CHAINEND))))
     (CL:T (PRINT-VARIABLE-VALUE CHAINEND STREAM))))
   ((CL:OR (CL:EQ *PRINTMODE* KWD-PRINT-FLAT)
     (CL:EQ *PRINTMODE* KWD-PRINT-DEBUG-LOW))
    (PRINT-SKOLEM-NAME SELF STREAM)
    (CL:WHEN (CL:EQ SELF CHAINEND)
     (CL:RETURN-FROM PRINT-VALUE-OF-CHAIN))
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM) VALUE-OF-SEPARATOR)
    (PRINT-VARIABLE-VALUE CHAINEND STREAM))
   ((CL:EQ *PRINTMODE* KWD-PRINT-DEBUG-HIGH)
    (PRINT-SKOLEM-NAME SELF STREAM)
    (CL:WHEN (CL:EQ SELF CHAINEND)
     (CL:RETURN-FROM PRINT-VALUE-OF-CHAIN))
    (CL:LET* ((CURSOR SELF) (NEXTVALUE NULL))
     (CL:LOOP
      (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE CURSOR)))
       (CL:COND
        ((SUBTYPE-OF? TEST-VALUE-000 SGT-PRINT-LOGIC-SKOLEM)
         (CL:PROGN
          (CL:SETQ NEXTVALUE
           (ACCESS-IN-CONTEXT (%VARIABLE-VALUE CURSOR)
            (%HOME-CONTEXT CURSOR) CL:NIL))))
        ((SUBTYPE-OF? TEST-VALUE-000 SGT-PRINT-LOGIC-LOGIC-OBJECT)
         (CL:PROGN (CL:SETQ NEXTVALUE CURSOR)))
        ((SUBTYPE-OF-SURROGATE? TEST-VALUE-000)
         (CL:PROGN (CL:SETQ NEXTVALUE (%SURROGATE-VALUE CURSOR))))
        ((SUBTYPE-OF? TEST-VALUE-000 SGT-PRINT-STELLA-RELATION)
         (CL:PROGN
          (CL:SETQ NEXTVALUE
           (DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS CURSOR)
            SYM-PRINT-LOGIC-DESCRIPTION NULL))))
        (CL:T
         (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
          (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`"
           TEST-VALUE-000 "' is not a valid case option")
          (CL:ERROR
           (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))))
      (%%PRINT-STREAM (%NATIVE-STREAM STREAM) VALUE-OF-SEPARATOR)
      (PRINT-VARIABLE-VALUE NEXTVALUE STREAM)
      (CL:WHEN (EQL? NEXTVALUE CHAINEND) (CL:RETURN))
      (CL:SETQ CURSOR NEXTVALUE))))
   (CL:T
    (CL:LET* ((STREAM-001 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-001) "`" *PRINTMODE*
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-001)))))))

;;; (DEFUN PRINT-SKOLEM-NAME ...)

(CL:DEFUN PRINT-SKOLEM-NAME (SELF STREAM)
  (%%PRINT-STREAM (%NATIVE-STREAM STREAM)
   (STRING-DOWNCASE (GET-SKOLEM-PRINT-NAME SELF))))

;;; (DEFUN PRINT-VARIABLE-NAME ...)

(CL:DEFUN PRINT-VARIABLE-NAME (SELF STREAM)
  (PRINT-SKOLEM-NAME SELF STREAM))

;;; (DEFUN PRINT-VARIABLE-VALUE ...)

(CL:DEFUN PRINT-VARIABLE-VALUE (SELF STREAM)
  (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE SELF)))
   (CL:COND
    ((SUBTYPE-OF? TEST-VALUE-000 SGT-PRINT-LOGIC-PATTERN-VARIABLE)
     (CL:PROGN (PRINT-VARIABLE-NAME SELF STREAM)))
    ((SUBTYPE-OF? TEST-VALUE-000 SGT-PRINT-LOGIC-SKOLEM)
     (CL:PROGN (PRINT-SKOLEM-NAME SELF STREAM)))
    (CL:T (PRINT-LOGICAL-FORM SELF STREAM)))))

;;; (DEFUN PRINT-SKOLEM ...)

(CL:DEFUN PRINT-SKOLEM (SELF STREAM TOPLEVEL?)
  (CL:SETQ TOPLEVEL? TOPLEVEL?)
  (CL:LET* ((PREFIX "|SK|"))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PREFIX))
   (CL:COND
    ((CL:OR (CL:EQ *PRINTMODE* KWD-PRINT-ORIGINAL)
      (CL:EQ *PRINTMODE* KWD-PRINT-REALISTIC))
     (CL:SETQ PREFIX "")
     (CL:WHEN (CL:NOT (CL:EQ (NATIVE-VALUE-OF SELF) NULL))
      (PRINT-VARIABLE-VALUE (NATIVE-VALUE-OF SELF) STREAM)
      (CL:RETURN-FROM PRINT-SKOLEM)))
    (CL:T))
   (CL:WHEN
    (CL:AND (CL:NOT (CL:EQ (%DEFINING-PROPOSITION SELF) NULL))
     (CL:EQ
      (ACCESS-IN-CONTEXT (%VARIABLE-VALUE SELF) (%HOME-CONTEXT SELF)
       CL:NIL)
      NULL))
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM) PREFIX)
    (CL:LET* ((*PRINTLOGICALFORMSTREAM* STREAM) (*INDENTCOUNTER* 20))
     (CL:DECLARE (CL:SPECIAL *PRINTLOGICALFORMSTREAM* *INDENTCOUNTER*))
     (CL:DECLARE (CL:TYPE CL:FIXNUM *INDENTCOUNTER*))
     (PRINT-KIF-FUNCTION-EXPRESSION (%DEFINING-PROPOSITION SELF)))
    (CL:RETURN-FROM PRINT-SKOLEM))
   (PRINT-VALUE-OF-CHAIN SELF STREAM (INNERMOST-OF SELF))))

;;; (DEFUN PRINT-VARIABLE ...)

(CL:DEFUN PRINT-VARIABLE (SELF STREAM)
  (CL:WHEN
   (CL:AND (CL:NOT (CL:EQ *CURRENTJUSTIFICATION* NULL))
    (CL:NOT (CL:EQ (JUSTIFICATION-ARGUMENT-BOUND-TO SELF NULL) NULL)))
   (PRETTY-PRINT-LOGICAL-FORM
    (JUSTIFICATION-ARGUMENT-BOUND-TO SELF NULL) STREAM)
   (CL:RETURN-FROM PRINT-VARIABLE))
  (CL:LET*
   ((VALUE
     (CL:IF (CL:NOT (CL:EQ *PRINTINFRAME* NULL))
      (BOUND-TO-IN-FRAME SELF *PRINTINFRAME*) (SAFE-BOUND-TO SELF))))
   (CL:WHEN (CL:NOT (CL:EQ VALUE NULL))
    (PRINT-VARIABLE-NAME SELF STREAM)
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM) VARIABLE-BINDING-SEPARATOR)
    (CL:LET* ((*PRINTREADABLY?* CL:T))
     (CL:DECLARE (CL:SPECIAL *PRINTREADABLY?*))
     (PRINT-VARIABLE-VALUE VALUE STREAM)
     (CL:RETURN-FROM PRINT-VARIABLE))))
  (PRINT-VALUE-OF-CHAIN SELF STREAM (INNERMOST-OF SELF)))

;;; (DEFUN PRINT-QUANTIFIED-VARIABLE ...)

(CL:DEFUN PRINT-QUANTIFIED-VARIABLE (SELF STREAM)
  (CL:IF *PRINTREADABLY?* (PRINT-VARIABLE-NAME SELF STREAM)
   (PRINT-VARIABLE SELF STREAM)))

;;; (DEFUN PRINT-PROPOSITION ...)

(CL:DEFUN PRINT-PROPOSITION (SELF STREAM TOPLEVEL?)
  (CL:LET* ((PREFIX STELLA::NULL-STRING))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PREFIX))
   (CL:WHEN (DELETED? SELF)
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "|dElEtEd-proposition|")
    (CL:RETURN-FROM PRINT-PROPOSITION))
   (CL:WHEN (CL:AND TOPLEVEL? (CL:NOT *PRINTREADABLY?*))
    (CL:COND
     ((CL:OR (DEFAULT-TRUE? SELF) (DEFAULT-FALSE? SELF))
      (CL:SETQ PREFIX
       (CL:IF
        (%WRAPPER-VALUE
         (DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS SELF)
          SYM-PRINT-LOGIC-DESCRIPTIVE? FALSE-WRAPPER))
        "|pd|" "|p|")))
     ((CL:OR
       (CL:AND (CL:NOT (DELETED? SELF))
        (CL:IF *REVERSEPOLARITY?* (FALSE? SELF)
         (CL:OR (TRUE? SELF) (FUNCTION-WITH-DEFINED-VALUE? SELF))))
       (FALSE? SELF))
      (CL:SETQ PREFIX
       (CL:IF
        (%WRAPPER-VALUE
         (DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS SELF)
          SYM-PRINT-LOGIC-DESCRIPTIVE? FALSE-WRAPPER))
        "|Pd|" "|P|")))
     ((INCONSISTENT? SELF)
      (CL:SETQ PREFIX
       (CL:IF
        (%WRAPPER-VALUE
         (DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS SELF)
          SYM-PRINT-LOGIC-DESCRIPTIVE? FALSE-WRAPPER))
        "|Pd#|" "|P#|")))
     (CL:T
      (CL:SETQ PREFIX
       (CL:IF
        (%WRAPPER-VALUE
         (DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS SELF)
          SYM-PRINT-LOGIC-DESCRIPTIVE? FALSE-WRAPPER))
        "|Pd?|" "|P?|")))))
   (CL:WHEN (COERCE-WRAPPED-BOOLEAN-TO-BOOLEAN (UNFASTENED? SELF))
    (CL:SETQ PREFIX
     (CL:IF
      (%WRAPPER-VALUE
       (DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS SELF)
        SYM-PRINT-LOGIC-DESCRIPTIVE? FALSE-WRAPPER))
      "|uPd|" "|uP|")))
   (CL:WHEN
    (CL:AND
     (CL:NOT
      (CL:EQ
       (DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS SELF)
        SYM-PRINT-STELLA-SURROGATE-VALUE-INVERSE NULL)
       NULL))
     (CL:NOT
      (CL:EQ
       (%SURROGATE-VALUE
        (DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS SELF)
         SYM-PRINT-STELLA-SURROGATE-VALUE-INVERSE NULL))
       SELF)))
    (CL:SETQ PREFIX "|BAD surrogate|"))
   (CL:WHEN (CL:NOT (CL:EQ PREFIX STELLA::NULL-STRING))
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM) PREFIX)))
  (PRINT-LOGICAL-FORM SELF STREAM))

;;; (DEFGLOBAL *DEBUG-MODE?* ...)

(CL:DEFVAR *DEBUG-MODE?* CL:NIL
  "If set to TRUE, simplify printing so that it
doesn't break during a debugging session.")

;;; (DEFUN PRINT-DESCRIPTION ...)

(CL:DEFUN PRINT-DESCRIPTION (SELF STREAM TOPLEVEL?)
  (CL:WHEN (DELETED? SELF)
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "|dElEtEd-description|")
   (CL:WHEN (CL:NOT (CL:EQ (%SURROGATE-VALUE-INVERSE SELF) NULL))
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM)
     (%SURROGATE-VALUE-INVERSE SELF)))
   (CL:RETURN-FROM PRINT-DESCRIPTION))
  (CL:COND
   ((CL:OR *LOADINGREGENERABLEOBJECTS?*
     (COERCE-WRAPPED-BOOLEAN-TO-BOOLEAN (BAD? SELF)) *DEBUG-MODE?*)
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "|d|"))
   ((CL:AND TOPLEVEL? (CL:NOT *PRINTREADABLY?*))
    (CL:COND
     ((CLASS? SELF) (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "|c|"))
     ((FUNCTION? SELF) (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "|f|"))
     ((RELATION? SELF) (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "|r|"))
     (CL:T (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "|d|")))))
  (PRINT-LOGICAL-FORM SELF STREAM))

(CL:DEFUN STARTUP-PRINT ()
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE "/LOGIC" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ SGT-PRINT-LOGIC-DESCRIPTION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DESCRIPTION" NULL 1))
    (CL:SETQ SGT-PRINT-LOGIC-PATTERN-VARIABLE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "PATTERN-VARIABLE" NULL 1))
    (CL:SETQ SGT-PRINT-LOGIC-SKOLEM
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SKOLEM" NULL 1))
    (CL:SETQ SGT-PRINT-LOGIC-TRUTH-VALUE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "TRUTH-VALUE" NULL 1))
    (CL:SETQ SGT-PRINT-LOGIC-LOGIC-OBJECT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "LOGIC-OBJECT" NULL 1))
    (CL:SETQ SGT-PRINT-LOGIC-PROPOSITION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "PROPOSITION" NULL 1))
    (CL:SETQ KWD-PRINT-FLAT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FLAT" NULL 2))
    (CL:SETQ KWD-PRINT-REALISTIC
     (INTERN-RIGID-SYMBOL-WRT-MODULE "REALISTIC" NULL 2))
    (CL:SETQ KWD-PRINT-ORIGINAL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "ORIGINAL" NULL 2))
    (CL:SETQ KWD-PRINT-DEBUG-LOW
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DEBUG-LOW" NULL 2))
    (CL:SETQ KWD-PRINT-DEBUG-HIGH
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DEBUG-HIGH" NULL 2))
    (CL:SETQ SYM-PRINT-LOGIC-DESCRIPTION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DESCRIPTION" NULL 0))
    (CL:SETQ SGT-PRINT-STELLA-RELATION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "RELATION"
      (GET-STELLA-MODULE "/STELLA" CL:T) 1))
    (CL:SETQ SYM-PRINT-LOGIC-DESCRIPTIVE?
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DESCRIPTIVE?" NULL 0))
    (CL:SETQ SYM-PRINT-STELLA-SURROGATE-VALUE-INVERSE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SURROGATE-VALUE-INVERSE"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-PRINT-LOGIC-STARTUP-PRINT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-PRINT" NULL 0))
    (CL:SETQ SYM-PRINT-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ *PRINTMODE* KWD-PRINT-FLAT))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "WRAP-NATIVE-OUTPUT-STREAM"
     "(DEFUN (WRAP-NATIVE-OUTPUT-STREAM OUTPUT-STREAM) ((NATIVESTREAM NATIVE-OUTPUT-STREAM)))"
     (CL:FUNCTION WRAP-NATIVE-OUTPUT-STREAM) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-TOP-LEVEL-OBJECT"
     "(DEFUN PRINT-TOP-LEVEL-OBJECT ((SELF OBJECT) (NATIVESTREAM NATIVE-OUTPUT-STREAM)))"
     (CL:FUNCTION PRINT-TOP-LEVEL-OBJECT) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-LOGIC-OBJECT"
     "(DEFUN PRINT-LOGIC-OBJECT ((SELF LOGIC-OBJECT) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))"
     (CL:FUNCTION PRINT-LOGIC-OBJECT) NULL)
    (DEFINE-FUNCTION-OBJECT "GET-SKOLEM-PRINT-NAME"
     "(DEFUN (GET-SKOLEM-PRINT-NAME STRING) ((SELF SKOLEM)))"
     (CL:FUNCTION GET-SKOLEM-PRINT-NAME) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-VALUE-OF-CHAIN"
     "(DEFUN PRINT-VALUE-OF-CHAIN ((SELF SKOLEM) (STREAM OUTPUT-STREAM) (CHAINEND OBJECT)))"
     (CL:FUNCTION PRINT-VALUE-OF-CHAIN) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-SKOLEM-NAME"
     "(DEFUN PRINT-SKOLEM-NAME ((SELF SKOLEM) (STREAM OUTPUT-STREAM)))"
     (CL:FUNCTION PRINT-SKOLEM-NAME) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-VARIABLE-NAME"
     "(DEFUN PRINT-VARIABLE-NAME ((SELF PATTERN-VARIABLE) (STREAM OUTPUT-STREAM)))"
     (CL:FUNCTION PRINT-VARIABLE-NAME) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-VARIABLE-VALUE"
     "(DEFUN PRINT-VARIABLE-VALUE ((SELF OBJECT) (STREAM OUTPUT-STREAM)))"
     (CL:FUNCTION PRINT-VARIABLE-VALUE) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-SKOLEM"
     "(DEFUN PRINT-SKOLEM ((SELF SKOLEM) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))"
     (CL:FUNCTION PRINT-SKOLEM) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-VARIABLE"
     "(DEFUN PRINT-VARIABLE ((SELF PATTERN-VARIABLE) (STREAM OUTPUT-STREAM)))"
     (CL:FUNCTION PRINT-VARIABLE) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-QUANTIFIED-VARIABLE"
     "(DEFUN PRINT-QUANTIFIED-VARIABLE ((SELF PATTERN-VARIABLE) (STREAM OUTPUT-STREAM)))"
     (CL:FUNCTION PRINT-QUANTIFIED-VARIABLE) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-PROPOSITION"
     "(DEFUN PRINT-PROPOSITION ((SELF PROPOSITION) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))"
     (CL:FUNCTION PRINT-PROPOSITION) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-DESCRIPTION"
     "(DEFUN PRINT-DESCRIPTION ((SELF DESCRIPTION) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))"
     (CL:FUNCTION PRINT-DESCRIPTION) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-PRINT"
     "(DEFUN STARTUP-PRINT () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-PRINT) NULL)
    (CL:LET*
     ((FUNCTION (LOOKUP-FUNCTION SYM-PRINT-LOGIC-STARTUP-PRINT)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-PRINT-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupPrint") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "LOGIC")))
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *PRINTMODE* KEYWORD :FLAT :DOCUMENTATION \"Controls the kind of detail that gets printed about
individual objects.  Values are :ORIGINAL, :REALISTIC, :FLAT, :DEBUG-LOW, and
 :DEBUG-HIGH.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *PRINTFUNCTIONSASRELATIONS?* BOOLEAN FALSE :DOCUMENTATION \"Controls whether functions are printed as relations (F i v) or
as functions (= (F i) v).\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFCONSTANT VARIABLE-BINDING-SEPARATOR STRING \"/\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFCONSTANT VALUE-OF-SEPARATOR STRING \"//\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *SKOLEMNAMEMAPPINGTABLE* (ENTITY-MAPPING OF SKOLEM SKOLEM) NULL :DOCUMENTATION \"If set, maps some skolems to names other than
their own.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *DEBUG-MODE?* BOOLEAN FALSE :DOCUMENTATION \"If set to TRUE, simplify printing so that it
doesn't break during a debugging session.\")"))))
