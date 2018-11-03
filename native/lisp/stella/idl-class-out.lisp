;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; idl-class-out.lisp

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
| Portions created by the Initial Developer are Copyright (C) 1996-2014      |
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

(CL:DEFVAR SYM-IDL-CLASS-OUT-STELLA-IDL_INTERFACE NULL)
(CL:DEFVAR KWD-IDL-CLASS-OUT-EMBEDDED NULL)
(CL:DEFVAR KWD-IDL-CLASS-OUT-INSTANCE NULL)
(CL:DEFVAR KWD-IDL-CLASS-OUT-CLASS NULL)
(CL:DEFVAR SGT-IDL-CLASS-OUT-STELLA-METHOD-SLOT NULL)
(CL:DEFVAR SGT-IDL-CLASS-OUT-STELLA-VOID NULL)
(CL:DEFVAR |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/interface| NULL)
(CL:DEFVAR |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/struct| NULL)
(CL:DEFVAR |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/enum| NULL)
(CL:DEFVAR |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/typedef| NULL)
(CL:DEFVAR SYM-IDL-CLASS-OUT-STELLA-IDL_STRUCT NULL)
(CL:DEFVAR SYM-IDL-CLASS-OUT-STELLA-IDL_ENUM NULL)
(CL:DEFVAR SYM-IDL-CLASS-OUT-STELLA-IDL_TYPEDEF NULL)
(CL:DEFVAR SYM-IDL-CLASS-OUT-STELLA-IDL_DECLARATIONS NULL)
(CL:DEFVAR SYM-IDL-CLASS-OUT-STELLA-IDL_SIGNATURES NULL)
(CL:DEFVAR SYM-IDL-CLASS-OUT-STELLA-STARTUP-IDL-CLASS-OUT NULL)
(CL:DEFVAR SYM-IDL-CLASS-OUT-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STELLA-MODULE* *MODULE* *METHODBEINGWALKED* NIL))

;;; (DEFUN (IDL-YIELD-INITIAL-NULL-VALUE CONS) ...)

(CL:DEFUN IDL-YIELD-INITIAL-NULL-VALUE ()
  (CL:RETURN-FROM IDL-YIELD-INITIAL-NULL-VALUE
   (IDL-TRANSLATE-A-TREE NULL)))

;;; (DEFUN (IDL-YIELD-ATTRIBUTE-TREE CONS) ...)

(CL:DEFUN IDL-YIELD-ATTRIBUTE-TREE (SLOT CLASS)
  (CL:LET*
   ((SLOTNAME (TRUE-SLOT-NAME (%SLOT-NAME SLOT) (%CLASS-TYPE CLASS)))
    (INITIALVALUEFORM (INITIALLY SLOT)) (FACETFORM NIL)
    (MOSTGENERALSLOT NULL))
   (CL:WHEN
    (CL:EQ (IDL-CLASS-CATEGORY CLASS)
     SYM-IDL-CLASS-OUT-STELLA-IDL_INTERFACE)
    (CL:IF (%SLOT-READ-ONLY? SLOT)
     (CL:SETQ FACETFORM
      (LIST* (WRAP-STRING "readonly") (WRAP-STRING "attribute") NIL))
     (CL:SETQ FACETFORM (CONS (WRAP-STRING "attribute") NIL))))
   (CL:WHEN (CL:EQ INITIALVALUEFORM NULL)
    (CL:SETQ INITIALVALUEFORM (IDL-YIELD-INITIAL-NULL-VALUE)))
   (CL:SETQ MOSTGENERALSLOT SLOT)
   (CL:RETURN-FROM IDL-YIELD-ATTRIBUTE-TREE
    (LIST*
     (CONCATENATE FACETFORM
      (CONS
       (IDL-TRANSLATE-TYPE-SPEC
        (COMPUTE-RETURN-TYPE-SPEC MOSTGENERALSLOT (%CLASS-TYPE CLASS)))
       NIL))
     (IDL-TRANSLATE-NAME SLOTNAME) (CONS INITIALVALUEFORM NIL)))))

;;; (DEFUN (IDL-YIELD-PARAMETERIZED-ATTRIBUTE-TREE CONS) ...)

(CL:DEFUN IDL-YIELD-PARAMETERIZED-ATTRIBUTE-TREE (SLOT CLASS)
  (CL:LET*
   ((SLOTNAME (TRUE-SLOT-NAME (%SLOT-NAME SLOT) (%CLASS-TYPE CLASS)))
    (INITIALVALUEFORM (INITIALLY SLOT)) (ALLOCATION (ALLOCATION SLOT))
    (ALLOCATIONFORM NIL))
   (CL:WHEN (CL:EQ INITIALVALUEFORM NULL)
    (CL:SETQ INITIALVALUEFORM (IDL-YIELD-INITIAL-NULL-VALUE)))
   (CL:COND
    ((CL:EQ ALLOCATION KWD-IDL-CLASS-OUT-EMBEDDED)
     (CL:SETQ ALLOCATIONFORM NIL))
    ((CL:EQ ALLOCATION KWD-IDL-CLASS-OUT-INSTANCE)
     (CL:SETQ ALLOCATIONFORM NIL))
    ((CL:EQ ALLOCATION KWD-IDL-CLASS-OUT-CLASS)
     (CL:SETQ ALLOCATIONFORM (CONS-LIST (WRAP-STRING "static"))))
    (CL:T (CL:SETQ ALLOCATIONFORM NIL)))
   (CL:RETURN-FROM IDL-YIELD-PARAMETERIZED-ATTRIBUTE-TREE
    (LIST*
     (CONCATENATE ALLOCATIONFORM
      (CONS
       (IDL-TRANSLATE-CLASS-PARAMETER-NAME
        (GET-SLOT-CLASS-PARAMETER-NAME SLOT))
       NIL))
     (IDL-TRANSLATE-NAME SLOTNAME) (CONS INITIALVALUEFORM NIL)))))

;;; (DEFUN (IDL-YIELD-STATIC-MEMBER-ALLOCATION-TREE CONS) ...)

(CL:DEFUN IDL-YIELD-STATIC-MEMBER-ALLOCATION-TREE (SLOT CLASS)
  (CL:LET*
   ((SLOTNAME (%SLOT-NAME SLOT)) (INITIALVALUEFORM (INITIALLY SLOT))
    (ALLOCATIONFORM NIL) (MOSTGENERALSLOT NULL))
   (CL:WHEN (CL:EQ INITIALVALUEFORM NULL)
    (CL:SETQ INITIALVALUEFORM (IDL-YIELD-INITIAL-NULL-VALUE)))
   (CL:SETQ MOSTGENERALSLOT SLOT)
   (CL:LOOP
    (CL:IF
     (CL:NOT (CL:EQ (%SLOT-DIRECT-EQUIVALENT MOSTGENERALSLOT) NULL))
     (CL:SETQ MOSTGENERALSLOT
      (%SLOT-DIRECT-EQUIVALENT MOSTGENERALSLOT))
     (CL:RETURN)))
   (CL:RETURN-FROM IDL-YIELD-STATIC-MEMBER-ALLOCATION-TREE
    (LIST*
     (CONCATENATE ALLOCATIONFORM
      (CONS
       (IDL-TRANSLATE-TYPE-SPEC
        (COMPUTE-RETURN-TYPE-SPEC MOSTGENERALSLOT (%CLASS-TYPE CLASS)))
       NIL))
     (IDL-TRANSLATE-NAME SLOTNAME) (CONS INITIALVALUEFORM NIL)))))

;;; (DEFUN (IDL-YIELD-OPERATION-SIGNATURE-TREE CONS) ...)

(CL:DEFUN IDL-YIELD-OPERATION-SIGNATURE-TREE (METHOD)
  (CL:LET* ((MOSTGENERALMETHOD METHOD) (RETURNTYPE NULL))
   (CL:SETQ *METHODBEINGWALKED* METHOD)
   (CL:LOOP WHILE
    (CL:AND
     (CL:NOT (CL:EQ (%SLOT-DIRECT-EQUIVALENT MOSTGENERALMETHOD) NULL))
     (ISA? (%SLOT-DIRECT-EQUIVALENT MOSTGENERALMETHOD)
      SGT-IDL-CLASS-OUT-STELLA-METHOD-SLOT)
     (CL:NOT
      (METHOD-CONTAINS-UNKNOWN-TYPE?
       (%SLOT-DIRECT-EQUIVALENT MOSTGENERALMETHOD))))
    DO
    (CL:SETQ MOSTGENERALMETHOD
     (%SLOT-DIRECT-EQUIVALENT MOSTGENERALMETHOD)))
   (CL:SETQ RETURNTYPE (%SLOT-BASE-TYPE MOSTGENERALMETHOD))
   (CL:RETURN-FROM IDL-YIELD-OPERATION-SIGNATURE-TREE
    (CONS
     (CL:IF (%METHOD-FUNCTION? METHOD) NULL
      (IDL-TRANSLATE-CLASS-NAME
       (INTERN-SYMBOL-IN-MODULE (%SYMBOL-NAME (%SLOT-OWNER METHOD))
        (%HOME-CONTEXT (%SLOT-OWNER METHOD)) CL:NIL)))
     (LIST* (CONS (IDL-TRANSLATE-TYPE-SPEC RETURNTYPE) NIL)
      (IDL-TRANSLATE-FUNCTION-NAME METHOD)
      (CONS (IDL-TRANSLATE-METHOD-PARAMETERS METHOD) NIL))))))

;;; (DEFUN (IDL-YIELD-CONSTRUCTOR-SIGNATURE-TREE CONS) ...)

(CL:DEFUN IDL-YIELD-CONSTRUCTOR-SIGNATURE-TREE (METHOD)
  (CL:SETQ *METHODBEINGWALKED* METHOD)
  (CL:RETURN-FROM IDL-YIELD-CONSTRUCTOR-SIGNATURE-TREE
   (CONS
    (IDL-TRANSLATE-CLASS-NAME
     (INTERN-SYMBOL-IN-MODULE (%SYMBOL-NAME (%SLOT-OWNER METHOD))
      (%HOME-CONTEXT (%SLOT-OWNER METHOD)) CL:NIL))
    (LIST* NIL (IDL-TRANSLATE-CONSTRUCTOR-NAME METHOD)
     (CONS (IDL-TRANSLATE-METHOD-PARAMETERS METHOD) NIL)))))

;;; (DEFUN (ILLEGAL-IDL-METHOD? BOOLEAN) ...)

(CL:DEFUN ILLEGAL-IDL-METHOD? (METHODSLOT)
  (CL:RETURN-FROM ILLEGAL-IDL-METHOD?
   (MEMBER?
    (GET-QUOTED-TREE "((DEFINED? NULL?) \"/STELLA\")" "/STELLA")
    (%SLOT-NAME METHODSLOT))))

;;; (DEFUN (IDL-GET-PARAMETERIZED-ATTRIBUTE-DEFINITIONS CONS) ...)

(CL:DEFUN IDL-GET-PARAMETERIZED-ATTRIBUTE-DEFINITIONS (CLASS)
  (CL:LET* ((ATTRIBUTEDEFS NIL))
   (CL:LET*
    ((SLOT NULL) (ITER-000 (%THE-CONS-LIST (%CLASS-LOCAL-SLOTS CLASS)))
     (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ SLOT (%%VALUE ITER-000))
     (CL:WHEN
      (CL:AND (STORAGE-SLOT? SLOT) (NATIVE-SLOT? SLOT)
       (SLOT-HAS-CLASS-PARAMETER-TYPE? SLOT CLASS))
      (CL:IF (CL:EQ COLLECT-000 NULL)
       (CL:PROGN
        (CL:SETQ COLLECT-000
         (CONS (IDL-YIELD-PARAMETERIZED-ATTRIBUTE-TREE SLOT CLASS)
          NIL))
        (CL:IF (CL:EQ ATTRIBUTEDEFS NIL)
         (CL:SETQ ATTRIBUTEDEFS COLLECT-000)
         (ADD-CONS-TO-END-OF-CONS-LIST ATTRIBUTEDEFS COLLECT-000)))
       (CL:PROGN
        (CL:SETF (%%REST COLLECT-000)
         (CONS (IDL-YIELD-PARAMETERIZED-ATTRIBUTE-TREE SLOT CLASS)
          NIL))
        (CL:SETQ COLLECT-000 (%%REST COLLECT-000)))))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:RETURN-FROM IDL-GET-PARAMETERIZED-ATTRIBUTE-DEFINITIONS
    ATTRIBUTEDEFS)))

;;; (DEFUN (IDL-GET-ATTRIBUTE-DEFINITIONS CONS) ...)

(CL:DEFUN IDL-GET-ATTRIBUTE-DEFINITIONS (CLASS)
  (CL:LET* ((ATTRIBUTEDEFS NIL))
   (CL:LET* ((SLOT NULL) (ITER-000 (CLASS-SLOTS CLASS)))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ SLOT (%VALUE ITER-000))
     (CL:WHEN
      (CL:AND (STORAGE-SLOT? SLOT) (NATIVE-SLOT? SLOT)
       (CL:EQ (NATIVE-SLOT-HOME SLOT CLASS) CLASS))
      (CL:SETQ ATTRIBUTEDEFS
       (CONS (IDL-YIELD-ATTRIBUTE-TREE SLOT CLASS) ATTRIBUTEDEFS)))))
   (CL:RETURN-FROM IDL-GET-ATTRIBUTE-DEFINITIONS
    (REVERSE ATTRIBUTEDEFS))))

;;; (DEFUN (IDL-GET-STATIC-VARIABLE-DEFINITIONS CONS) ...)

(CL:DEFUN IDL-GET-STATIC-VARIABLE-DEFINITIONS (CLASS)
  (CL:LET* ((STATICATTRIBUTEDEFS NIL))
   (CL:LET* ((SLOT NULL) (ITER-000 (CLASS-SLOTS CLASS)))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ SLOT (%VALUE ITER-000))
     (CL:WHEN
      (CL:AND (STORAGE-SLOT? SLOT) (NATIVE-SLOT? SLOT)
       (CL:EQ (SLOT-ALLOCATION SLOT) KWD-IDL-CLASS-OUT-CLASS)
       (CL:NOT (SLOT-HAS-UNKNOWN-TYPE? SLOT CLASS))
       (CL:NOT (%SLOT-HARDWIRED? SLOT)) (CL:NOT (%SLOT-MARKED? SLOT)))
      (CL:SETQ STATICATTRIBUTEDEFS
       (CONS (IDL-YIELD-STATIC-MEMBER-ALLOCATION-TREE SLOT CLASS)
        STATICATTRIBUTEDEFS)))))
   (CL:RETURN-FROM IDL-GET-STATIC-VARIABLE-DEFINITIONS
    STATICATTRIBUTEDEFS)))

;;; (DEFUN (IDL-CONSTRUCTOR? BOOLEAN) ...)

(CL:DEFUN IDL-CONSTRUCTOR? (METHOD)
  (CL:RETURN-FROM IDL-CONSTRUCTOR?
   (CL:AND (CL:EQ (TYPE METHOD) SGT-IDL-CLASS-OUT-STELLA-VOID)
    (CL:= (LENGTH (METHOD-PARAMETER-NAMES METHOD)) 1)
    (STRING-EQL? (%SYMBOL-NAME (%SLOT-OWNER METHOD))
     (%SYMBOL-NAME (%SLOT-NAME METHOD)))
    (CL:EQ (%HOME-CONTEXT (%SLOT-OWNER METHOD))
     (%HOME-CONTEXT (%SLOT-NAME METHOD))))))

;;; (DEFUN (IDL-GET-CONSTRUCTOR-DEFINITIONS CONS) ...)

(CL:DEFUN IDL-GET-CONSTRUCTOR-DEFINITIONS (CLASS)
  (CL:LET* ((CONSTRUCTORDEFS NIL))
   (CL:LET*
    ((SLOT NULL) (ITER-000 (CLASS-SLOTS CLASS)) (COLLECT-000 NULL))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ SLOT (%VALUE ITER-000))
     (CL:WHEN
      (CL:AND (CL:NOT (%SLOT-MARKED? SLOT))
       (CL:EQ (PRIMARY-TYPE SLOT) SGT-IDL-CLASS-OUT-STELLA-METHOD-SLOT)
       (LOCAL-SLOT? SLOT CLASS) (IDL-CONSTRUCTOR? SLOT))
      (CL:IF (CL:EQ COLLECT-000 NULL)
       (CL:PROGN
        (CL:SETQ COLLECT-000
         (CONS (IDL-YIELD-CONSTRUCTOR-SIGNATURE-TREE SLOT) NIL))
        (CL:IF (CL:EQ CONSTRUCTORDEFS NIL)
         (CL:SETQ CONSTRUCTORDEFS COLLECT-000)
         (ADD-CONS-TO-END-OF-CONS-LIST CONSTRUCTORDEFS COLLECT-000)))
       (CL:PROGN
        (CL:SETF (%%REST COLLECT-000)
         (CONS (IDL-YIELD-CONSTRUCTOR-SIGNATURE-TREE SLOT) NIL))
        (CL:SETQ COLLECT-000 (%%REST COLLECT-000)))))))
   (CL:RETURN-FROM IDL-GET-CONSTRUCTOR-DEFINITIONS CONSTRUCTORDEFS)))

;;; (DEFUN (IDL-GET-OPERATION-DEFINITIONS CONS) ...)

(CL:DEFUN IDL-GET-OPERATION-DEFINITIONS (CLASS)
  (CL:LET* ((OPERATIONDEFS NIL))
   (CL:LET*
    ((SLOT NULL) (ITER-000 (CLASS-SLOTS CLASS)) (COLLECT-000 NULL))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ SLOT (%VALUE ITER-000))
     (CL:WHEN
      (CL:AND (CL:NOT (%SLOT-MARKED? SLOT))
       (CL:EQ (PRIMARY-TYPE SLOT) SGT-IDL-CLASS-OUT-STELLA-METHOD-SLOT)
       (LOCAL-SLOT? SLOT CLASS) (CL:NOT (IDL-CONSTRUCTOR? SLOT))
       (CL:NOT (%METHOD-FUNCTION? SLOT))
       (CL:NOT (ILLEGAL-IDL-METHOD? SLOT))
       (CL:NOT (METHOD-CONTAINS-UNKNOWN-TYPE? SLOT)))
      (CL:IF (CL:EQ COLLECT-000 NULL)
       (CL:PROGN
        (CL:SETQ COLLECT-000
         (CONS (IDL-YIELD-OPERATION-SIGNATURE-TREE SLOT) NIL))
        (CL:IF (CL:EQ OPERATIONDEFS NIL)
         (CL:SETQ OPERATIONDEFS COLLECT-000)
         (ADD-CONS-TO-END-OF-CONS-LIST OPERATIONDEFS COLLECT-000)))
       (CL:PROGN
        (CL:SETF (%%REST COLLECT-000)
         (CONS (IDL-YIELD-OPERATION-SIGNATURE-TREE SLOT) NIL))
        (CL:SETQ COLLECT-000 (%%REST COLLECT-000)))))))
   (CL:LET*
    ((AUXILIARY NULL)
     (ITER-001 (%THE-CONS-LIST (CLASS-AUXILIARY-METHODS CLASS)))
     (COLLECT-001 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
     (CL:SETQ AUXILIARY (%%VALUE ITER-001))
     (CL:IF (CL:EQ COLLECT-001 NULL)
      (CL:PROGN
       (CL:SETQ COLLECT-001
        (CONS (IDL-YIELD-OPERATION-SIGNATURE-TREE AUXILIARY) NIL))
       (CL:IF (CL:EQ OPERATIONDEFS NIL)
        (CL:SETQ OPERATIONDEFS COLLECT-001)
        (ADD-CONS-TO-END-OF-CONS-LIST OPERATIONDEFS COLLECT-001)))
      (CL:PROGN
       (CL:SETF (%%REST COLLECT-001)
        (CONS (IDL-YIELD-OPERATION-SIGNATURE-TREE AUXILIARY) NIL))
       (CL:SETQ COLLECT-001 (%%REST COLLECT-001))))
     (CL:SETQ ITER-001 (%%REST ITER-001))))
   (CL:RETURN-FROM IDL-GET-OPERATION-DEFINITIONS OPERATIONDEFS)))

;;; (DEFUN (IDL-CLASS-CATEGORY SYMBOL) ...)

(CL:DEFUN IDL-CLASS-CATEGORY (CLASS)
  (CL:WHEN (CL:EQ (PROPERTIES CLASS) NULL)
   (CL:RETURN-FROM IDL-CLASS-CATEGORY
    SYM-IDL-CLASS-OUT-STELLA-IDL_INTERFACE))
  (CL:LET* ((TEST-VALUE-000 (FIRST (PROPERTIES CLASS))))
   (CL:COND
    ((CL:EQ TEST-VALUE-000
      |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/interface|)
     (CL:RETURN-FROM IDL-CLASS-CATEGORY
      SYM-IDL-CLASS-OUT-STELLA-IDL_INTERFACE))
    ((CL:EQ TEST-VALUE-000
      |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/struct|)
     (CL:RETURN-FROM IDL-CLASS-CATEGORY
      SYM-IDL-CLASS-OUT-STELLA-IDL_STRUCT))
    ((CL:EQ TEST-VALUE-000 |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/enum|)
     (CL:RETURN-FROM IDL-CLASS-CATEGORY
      SYM-IDL-CLASS-OUT-STELLA-IDL_ENUM))
    ((CL:EQ TEST-VALUE-000
      |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/typedef|)
     (CL:RETURN-FROM IDL-CLASS-CATEGORY
      SYM-IDL-CLASS-OUT-STELLA-IDL_TYPEDEF))
    (CL:T
     (CL:RETURN-FROM IDL-CLASS-CATEGORY
      SYM-IDL-CLASS-OUT-STELLA-IDL_INTERFACE)))))

;;; (DEFUN (IDL-TRANSLATE-DEFINE-NATIVE-CLASS-UNIT CONS) ...)

(CL:DEFUN IDL-TRANSLATE-DEFINE-NATIVE-CLASS-UNIT (UNIT)
  (CL:LET*
   ((CLASS (%THE-OBJECT UNIT)) (DERIVEDCLASSES NIL)
    (PARAMETERIZEDATTRIBUTEDEFS NIL) (ATTRIBUTEDEFS NIL)
    (OPERATIONDEFS NIL) (CONSTRUCTORDEFS NIL) (PARAMETERS NIL)
    (STATICATTRIBUTEDEFS NIL))
   (CL:LET*
    ((SUPER NULL)
     (ITER-000 (%THE-CONS-LIST (%CLASS-DIRECT-SUPERS CLASS)))
     (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ SUPER (%%VALUE ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN
       (CL:SETQ COLLECT-000
        (CONS
         (IDL-TRANSLATE-CLASS-NAME
          (INTERN-SYMBOL-IN-MODULE (%SYMBOL-NAME SUPER)
           (%HOME-CONTEXT SUPER) CL:NIL))
         NIL))
       (CL:IF (CL:EQ DERIVEDCLASSES NIL)
        (CL:SETQ DERIVEDCLASSES COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST DERIVEDCLASSES COLLECT-000)))
      (CL:PROGN
       (CL:SETF (%%REST COLLECT-000)
        (CONS
         (IDL-TRANSLATE-CLASS-NAME
          (INTERN-SYMBOL-IN-MODULE (%SYMBOL-NAME SUPER)
           (%HOME-CONTEXT SUPER) CL:NIL))
         NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:LET*
    ((PARAMETER NULL)
     (ITER-001 (%THE-CONS-LIST (CLASS-PARAMETERS CLASS)))
     (COLLECT-001 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
     (CL:SETQ PARAMETER (%%VALUE ITER-001))
     (CL:IF (CL:EQ COLLECT-001 NULL)
      (CL:PROGN
       (CL:SETQ COLLECT-001
        (CONS (IDL-TRANSLATE-CLASS-PARAMETER-NAME PARAMETER) NIL))
       (CL:IF (CL:EQ PARAMETERS NIL) (CL:SETQ PARAMETERS COLLECT-001)
        (ADD-CONS-TO-END-OF-CONS-LIST PARAMETERS COLLECT-001)))
      (CL:PROGN
       (CL:SETF (%%REST COLLECT-001)
        (CONS (IDL-TRANSLATE-CLASS-PARAMETER-NAME PARAMETER) NIL))
       (CL:SETQ COLLECT-001 (%%REST COLLECT-001))))
     (CL:SETQ ITER-001 (%%REST ITER-001))))
   (CL:LET* ((SLOT NULL) (ITER-002 (CLASS-SLOTS CLASS)))
    (CL:LOOP WHILE (NEXT? ITER-002) DO (CL:SETQ SLOT (%VALUE ITER-002))
     (CL:SETF (%SLOT-MARKED? SLOT) CL:NIL)))
   (CL:LET* ((SLOT NULL) (ITER-003 (CLASS-SLOTS CLASS)))
    (CL:LOOP WHILE (NEXT? ITER-003) DO (CL:SETQ SLOT (%VALUE ITER-003))
     (CL:WHEN (CL:NOT (%SLOT-MARKED? SLOT))
      (CL:WHEN
       (CL:AND (CL:NOT (CL:EQ (%SLOT-DIRECT-EQUIVALENT SLOT) NULL))
        (CL:NOT (%SLOT-RENAMED? (%SLOT-DIRECT-EQUIVALENT SLOT))))
       (MARK-DIRECT-EQUIVALENT-SLOT SLOT)
       (CL:SETF (%SLOT-MARKED? SLOT) CL:NIL)))))
   (CL:SETQ CONSTRUCTORDEFS (IDL-GET-CONSTRUCTOR-DEFINITIONS CLASS))
   (CL:SETQ PARAMETERIZEDATTRIBUTEDEFS
    (IDL-GET-PARAMETERIZED-ATTRIBUTE-DEFINITIONS CLASS))
   (CL:SETQ ATTRIBUTEDEFS (IDL-GET-ATTRIBUTE-DEFINITIONS CLASS))
   (CL:SETQ OPERATIONDEFS (IDL-GET-OPERATION-DEFINITIONS CLASS))
   (CL:SETQ STATICATTRIBUTEDEFS
    (IDL-GET-STATIC-VARIABLE-DEFINITIONS CLASS))
   (CL:RETURN-FROM IDL-TRANSLATE-DEFINE-NATIVE-CLASS-UNIT
    (CONS (IDL-CLASS-CATEGORY CLASS)
     (CONS
      (IDL-TRANSLATE-CLASS-NAME
       (INTERN-SYMBOL-IN-MODULE (%SYMBOL-NAME (%CLASS-TYPE CLASS))
        (%HOME-CONTEXT (%CLASS-TYPE CLASS)) CL:NIL))
      (CONS PARAMETERS
       (CONS DERIVEDCLASSES
        (CONS STATICATTRIBUTEDEFS
         (CONCATENATE
          (CL:IF (CL:NOT (CL:EQ PARAMETERIZEDATTRIBUTEDEFS NIL))
           (CONS
            (LIST* SYM-IDL-CLASS-OUT-STELLA-IDL_DECLARATIONS
             PARAMETERIZEDATTRIBUTEDEFS NIL)
            NIL)
           NIL)
          (CONCATENATE
           (CL:IF (CL:NOT (CL:EQ ATTRIBUTEDEFS NIL))
            (CONS
             (LIST* SYM-IDL-CLASS-OUT-STELLA-IDL_DECLARATIONS
              ATTRIBUTEDEFS NIL)
             NIL)
            NIL)
           (CONCATENATE
            (CL:IF (CL:NOT (CL:EQ CONSTRUCTORDEFS NIL))
             (CONS
              (LIST* SYM-IDL-CLASS-OUT-STELLA-IDL_SIGNATURES
               CONSTRUCTORDEFS NIL)
              NIL)
             NIL)
            (CONCATENATE
             (CL:IF (CL:NOT (CL:EQ OPERATIONDEFS NIL))
              (CONS
               (LIST* SYM-IDL-CLASS-OUT-STELLA-IDL_SIGNATURES
                OPERATIONDEFS NIL)
               NIL)
              NIL)
             NIL))))))))))))

(CL:DEFUN STARTUP-IDL-CLASS-OUT ()
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ SYM-IDL-CLASS-OUT-STELLA-IDL_INTERFACE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_INTERFACE" NULL 0))
    (CL:SETQ KWD-IDL-CLASS-OUT-EMBEDDED
     (INTERN-RIGID-SYMBOL-WRT-MODULE "EMBEDDED" NULL 2))
    (CL:SETQ KWD-IDL-CLASS-OUT-INSTANCE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "INSTANCE" NULL 2))
    (CL:SETQ KWD-IDL-CLASS-OUT-CLASS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CLASS" NULL 2))
    (CL:SETQ SGT-IDL-CLASS-OUT-STELLA-METHOD-SLOT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-SLOT" NULL 1))
    (CL:SETQ SGT-IDL-CLASS-OUT-STELLA-VOID
     (INTERN-RIGID-SYMBOL-WRT-MODULE "VOID" NULL 1))
    (CL:SETQ |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/interface|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "/IDL-THEORY/interface" NULL 0))
    (CL:SETQ |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/struct|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "/IDL-THEORY/struct" NULL 0))
    (CL:SETQ |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/enum|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "/IDL-THEORY/enum" NULL 0))
    (CL:SETQ |SYM-IDL-CLASS-OUT-STELLA-/IDL-THEORY/typedef|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "/IDL-THEORY/typedef" NULL 0))
    (CL:SETQ SYM-IDL-CLASS-OUT-STELLA-IDL_STRUCT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_STRUCT" NULL 0))
    (CL:SETQ SYM-IDL-CLASS-OUT-STELLA-IDL_ENUM
     (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_ENUM" NULL 0))
    (CL:SETQ SYM-IDL-CLASS-OUT-STELLA-IDL_TYPEDEF
     (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_TYPEDEF" NULL 0))
    (CL:SETQ SYM-IDL-CLASS-OUT-STELLA-IDL_DECLARATIONS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_DECLARATIONS" NULL 0))
    (CL:SETQ SYM-IDL-CLASS-OUT-STELLA-IDL_SIGNATURES
     (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_SIGNATURES" NULL 0))
    (CL:SETQ SYM-IDL-CLASS-OUT-STELLA-STARTUP-IDL-CLASS-OUT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-IDL-CLASS-OUT" NULL 0))
    (CL:SETQ SYM-IDL-CLASS-OUT-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL
      0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "IDL-YIELD-INITIAL-NULL-VALUE"
     "(DEFUN (IDL-YIELD-INITIAL-NULL-VALUE CONS) ())"
     (CL:FUNCTION IDL-YIELD-INITIAL-NULL-VALUE) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-YIELD-ATTRIBUTE-TREE"
     "(DEFUN (IDL-YIELD-ATTRIBUTE-TREE CONS) ((SLOT STORAGE-SLOT) (CLASS CLASS)))"
     (CL:FUNCTION IDL-YIELD-ATTRIBUTE-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-YIELD-PARAMETERIZED-ATTRIBUTE-TREE"
     "(DEFUN (IDL-YIELD-PARAMETERIZED-ATTRIBUTE-TREE CONS) ((SLOT STORAGE-SLOT) (CLASS CLASS)))"
     (CL:FUNCTION IDL-YIELD-PARAMETERIZED-ATTRIBUTE-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-YIELD-STATIC-MEMBER-ALLOCATION-TREE"
     "(DEFUN (IDL-YIELD-STATIC-MEMBER-ALLOCATION-TREE CONS) ((SLOT STORAGE-SLOT) (CLASS CLASS)))"
     (CL:FUNCTION IDL-YIELD-STATIC-MEMBER-ALLOCATION-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-YIELD-OPERATION-SIGNATURE-TREE"
     "(DEFUN (IDL-YIELD-OPERATION-SIGNATURE-TREE CONS) ((METHOD METHOD-SLOT)))"
     (CL:FUNCTION IDL-YIELD-OPERATION-SIGNATURE-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-YIELD-CONSTRUCTOR-SIGNATURE-TREE"
     "(DEFUN (IDL-YIELD-CONSTRUCTOR-SIGNATURE-TREE CONS) ((METHOD METHOD-SLOT)))"
     (CL:FUNCTION IDL-YIELD-CONSTRUCTOR-SIGNATURE-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "ILLEGAL-IDL-METHOD?"
     "(DEFUN (ILLEGAL-IDL-METHOD? BOOLEAN) ((METHODSLOT METHOD-SLOT)))"
     (CL:FUNCTION ILLEGAL-IDL-METHOD?) NULL)
    (DEFINE-FUNCTION-OBJECT
     "IDL-GET-PARAMETERIZED-ATTRIBUTE-DEFINITIONS"
     "(DEFUN (IDL-GET-PARAMETERIZED-ATTRIBUTE-DEFINITIONS CONS) ((CLASS CLASS)))"
     (CL:FUNCTION IDL-GET-PARAMETERIZED-ATTRIBUTE-DEFINITIONS) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-GET-ATTRIBUTE-DEFINITIONS"
     "(DEFUN (IDL-GET-ATTRIBUTE-DEFINITIONS CONS) ((CLASS CLASS)))"
     (CL:FUNCTION IDL-GET-ATTRIBUTE-DEFINITIONS) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-GET-STATIC-VARIABLE-DEFINITIONS"
     "(DEFUN (IDL-GET-STATIC-VARIABLE-DEFINITIONS CONS) ((CLASS CLASS)))"
     (CL:FUNCTION IDL-GET-STATIC-VARIABLE-DEFINITIONS) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-CONSTRUCTOR?"
     "(DEFUN (IDL-CONSTRUCTOR? BOOLEAN) ((METHOD METHOD-SLOT)))"
     (CL:FUNCTION IDL-CONSTRUCTOR?) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-GET-CONSTRUCTOR-DEFINITIONS"
     "(DEFUN (IDL-GET-CONSTRUCTOR-DEFINITIONS CONS) ((CLASS CLASS)))"
     (CL:FUNCTION IDL-GET-CONSTRUCTOR-DEFINITIONS) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-GET-OPERATION-DEFINITIONS"
     "(DEFUN (IDL-GET-OPERATION-DEFINITIONS CONS) ((CLASS CLASS)))"
     (CL:FUNCTION IDL-GET-OPERATION-DEFINITIONS) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-CLASS-CATEGORY"
     "(DEFUN (IDL-CLASS-CATEGORY SYMBOL) ((CLASS CLASS)))"
     (CL:FUNCTION IDL-CLASS-CATEGORY) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-TRANSLATE-DEFINE-NATIVE-CLASS-UNIT"
     "(DEFUN (IDL-TRANSLATE-DEFINE-NATIVE-CLASS-UNIT CONS) ((UNIT TRANSLATION-UNIT)))"
     (CL:FUNCTION IDL-TRANSLATE-DEFINE-NATIVE-CLASS-UNIT) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-IDL-CLASS-OUT"
     "(DEFUN STARTUP-IDL-CLASS-OUT () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-IDL-CLASS-OUT) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION
        SYM-IDL-CLASS-OUT-STELLA-STARTUP-IDL-CLASS-OUT)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-IDL-CLASS-OUT-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupIdlClassOut") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "/STELLA")))))
  :VOID)
