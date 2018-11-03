;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; dynamic-slots.lisp

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

(CL:DEFVAR KWD-DYNAMIC-SLOTS-DYNAMIC NULL)
(CL:DEFVAR KWD-DYNAMIC-SLOTS-NULL-WRAPPER NULL)
(CL:DEFVAR KWD-DYNAMIC-SLOTS-COMMON-LISP NULL)
(CL:DEFVAR SGT-DYNAMIC-SLOTS-STELLA-OBJECT NULL)
(CL:DEFVAR SYM-DYNAMIC-SLOTS-STELLA-WRAPPER-VALUE NULL)
(CL:DEFVAR SYM-DYNAMIC-SLOTS-STELLA-SAFE-CAST NULL)
(CL:DEFVAR SYM-DYNAMIC-SLOTS-STELLA-DYNAMIC-SLOT-VALUE NULL)
(CL:DEFVAR SYM-DYNAMIC-SLOTS-STELLA-DYNAMIC-SLOTS NULL)
(CL:DEFVAR SYM-DYNAMIC-SLOTS-STELLA-QUOTE NULL)
(CL:DEFVAR SYM-DYNAMIC-SLOTS-STELLA-NULL NULL)
(CL:DEFVAR SYM-DYNAMIC-SLOTS-STELLA-SET-DYNAMIC-SLOT-VALUE NULL)
(CL:DEFVAR SYM-DYNAMIC-SLOTS-STELLA-BQUOTE NULL)
(CL:DEFVAR SYM-DYNAMIC-SLOTS-STELLA-STARTUP-DYNAMIC-SLOTS NULL)
(CL:DEFVAR SYM-DYNAMIC-SLOTS-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STELLA-MODULE* *MODULE* NIL *TRANSLATOROUTPUTLANGUAGE*
  FALSE-WRAPPER))

;;; (DEFUN (DYNAMIC-SLOT-VALUE OBJECT) ...)

(CL:DEFUN DYNAMIC-SLOT-VALUE (DYNAMICSLOTS SLOTNAME NULLVALUE)
  (CL:LET*
   ((KEY NULL) (VALUE NULL) (ITER-000 (%THE-KV-LIST DYNAMICSLOTS)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NULL)) DO
    (CL:SETQ KEY (%KEY ITER-000)) (CL:SETQ VALUE (%VALUE ITER-000))
    (CL:WHEN (CL:EQ KEY SLOTNAME)
     (CL:IF (CL:EQ VALUE NULL)
      (CL:RETURN-FROM DYNAMIC-SLOT-VALUE NULLVALUE)
      (CL:RETURN-FROM DYNAMIC-SLOT-VALUE VALUE)))
    (CL:SETQ ITER-000 (%REST ITER-000))))
  (CL:RETURN-FROM DYNAMIC-SLOT-VALUE NULLVALUE))

;;; (DEFUN (SET-DYNAMIC-SLOT-VALUE OBJECT) ...)

(CL:DEFUN SET-DYNAMIC-SLOT-VALUE (DYNAMICSLOTS SLOTNAME VALUE NULLWRAPPER)
  (CL:LET*
   ((DELETEVALUE?
     (CL:AND (CL:EQ VALUE NULLWRAPPER)
      (CL:NOT (CL:EQ NULLWRAPPER FALSE-WRAPPER))))
    (CURSOR (%THE-KV-LIST DYNAMICSLOTS)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NULL)) DO
    (CL:WHEN (CL:EQ (%KEY CURSOR) SLOTNAME)
     (CL:IF DELETEVALUE? (REMOVE-AT DYNAMICSLOTS SLOTNAME)
      (CL:SETF (%VALUE CURSOR) VALUE))
     (CL:RETURN-FROM SET-DYNAMIC-SLOT-VALUE VALUE))
    (CL:SETQ CURSOR (%REST CURSOR)))
   (CL:WHEN (CL:NOT DELETEVALUE?)
    (CL:SETF (%THE-KV-LIST DYNAMICSLOTS)
     (KV-CONS SLOTNAME VALUE (%THE-KV-LIST DYNAMICSLOTS))))
   (CL:RETURN-FROM SET-DYNAMIC-SLOT-VALUE VALUE)))

;;; (DEFUN (STANDARD-DYNAMIC-SLOT-ACCESS? BOOLEAN) ...)

(CL:DEFUN STANDARD-DYNAMIC-SLOT-ACCESS? (SLOT)
  (CL:RETURN-FROM STANDARD-DYNAMIC-SLOT-ACCESS?
   (CL:AND (CL:NOT (ACTIVE? SLOT))
    (CL:EQ (ALLOCATION SLOT) KWD-DYNAMIC-SLOTS-DYNAMIC)
    (CL:OR (CL:NOT (SLOT-VALUE-IS-BARE-LITERAL? SLOT))
     (CL:NOT
      (CL:EQ
       (LOOKUP-LITERAL-TYPE-INFO (%SLOT-BASE-TYPE SLOT)
        KWD-DYNAMIC-SLOTS-NULL-WRAPPER)
       NULL))))))

;;; (DEFUN (YIELD-DOWN-CAST-TREE CONS) ...)

(CL:DEFUN YIELD-DOWN-CAST-TREE (TREE RETURNTYPE)
  (CL:LET* ((OTREE (SYS-TREE TREE RETURNTYPE)))
   (CL:WHEN
    (CL:NOT
     (CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-DYNAMIC-SLOTS-COMMON-LISP))
    (SET-TARGET-LANGUAGE-TYPE OTREE SGT-DYNAMIC-SLOTS-STELLA-OBJECT))
   (CL:RETURN-FROM YIELD-DOWN-CAST-TREE OTREE)))

;;; (DEFUN (YIELD-STANDARD-DYNAMIC-SLOT-VALUE-TREE CONS) ...)

(CL:DEFUN YIELD-STANDARD-DYNAMIC-SLOT-VALUE-TREE (SLOT OBJECTREF RETURNTYPE)
  (CL:LET* ((SLOTNAME (%SLOT-NAME (CANONICAL-SLOT SLOT))))
   (CL:IF (SLOT-VALUE-IS-BARE-LITERAL? SLOT)
    (CL:RETURN-FROM YIELD-STANDARD-DYNAMIC-SLOT-VALUE-TREE
     (LIST* SYM-DYNAMIC-SLOTS-STELLA-WRAPPER-VALUE
      (LIST* SYM-DYNAMIC-SLOTS-STELLA-SAFE-CAST
       (LIST* SYM-DYNAMIC-SLOTS-STELLA-DYNAMIC-SLOT-VALUE
        (LIST* SYM-DYNAMIC-SLOTS-STELLA-DYNAMIC-SLOTS OBJECTREF NIL)
        (LIST* SYM-DYNAMIC-SLOTS-STELLA-QUOTE SLOTNAME NIL)
        (LOOKUP-LITERAL-TYPE-INFO (TYPE SLOT)
         KWD-DYNAMIC-SLOTS-NULL-WRAPPER)
        NIL)
       (TYPE-TO-SYMBOL (TYPE-TO-WRAPPED-TYPE (TYPE SLOT))) NIL)
      NIL))
    (CL:RETURN-FROM YIELD-STANDARD-DYNAMIC-SLOT-VALUE-TREE
     (YIELD-DOWN-CAST-TREE
      (WALK-A-CONS-TREE
       (LIST* SYM-DYNAMIC-SLOTS-STELLA-DYNAMIC-SLOT-VALUE
        (LIST* SYM-DYNAMIC-SLOTS-STELLA-DYNAMIC-SLOTS OBJECTREF NIL)
        (LIST* SYM-DYNAMIC-SLOTS-STELLA-QUOTE SLOTNAME NIL)
        SYM-DYNAMIC-SLOTS-STELLA-NULL NIL))
      RETURNTYPE)))))

;;; (DEFUN (YIELD-STANDARD-DYNAMIC-SLOT-VALUE-SETTER-TREE CONS) ...)

(CL:DEFUN YIELD-STANDARD-DYNAMIC-SLOT-VALUE-SETTER-TREE (SLOT OBJECTREF VALUEREF RETURNTYPE)
  (CL:LET*
   ((SLOTNAME (%SLOT-NAME (CANONICAL-SLOT SLOT)))
    (LITERALSLOT? (SLOT-VALUE-IS-BARE-LITERAL? SLOT))
    (SETTERTREE NULL))
   (CL:IF LITERALSLOT?
    (CL:SETQ SETTERTREE
     (LIST* SYM-DYNAMIC-SLOTS-STELLA-SET-DYNAMIC-SLOT-VALUE
      (LIST* SYM-DYNAMIC-SLOTS-STELLA-DYNAMIC-SLOTS OBJECTREF NIL)
      (LIST* SYM-DYNAMIC-SLOTS-STELLA-BQUOTE SLOTNAME NIL) VALUEREF
      (CONS
       (LOOKUP-LITERAL-TYPE-INFO (TYPE SLOT)
        KWD-DYNAMIC-SLOTS-NULL-WRAPPER)
       NIL)))
    (CL:SETQ SETTERTREE
     (LIST* SYM-DYNAMIC-SLOTS-STELLA-SET-DYNAMIC-SLOT-VALUE
      (LIST* SYM-DYNAMIC-SLOTS-STELLA-DYNAMIC-SLOTS OBJECTREF NIL)
      (LIST* SYM-DYNAMIC-SLOTS-STELLA-BQUOTE SLOTNAME NIL) VALUEREF
      (CONS SYM-DYNAMIC-SLOTS-STELLA-NULL NIL))))
   (CL:WHEN (WALKING-EXPRESSION?)
    (CL:IF LITERALSLOT?
     (CL:SETQ SETTERTREE
      (LIST* SYM-DYNAMIC-SLOTS-STELLA-WRAPPER-VALUE
       (LIST* SYM-DYNAMIC-SLOTS-STELLA-SAFE-CAST SETTERTREE
        (CONS (TYPE-TO-SYMBOL (TYPE-TO-WRAPPED-TYPE (TYPE SLOT))) NIL))
       NIL))
     (CL:SETQ SETTERTREE
      (YIELD-DOWN-CAST-TREE (WALK-A-CONS-TREE SETTERTREE)
       RETURNTYPE))))
   (CL:RETURN-FROM YIELD-STANDARD-DYNAMIC-SLOT-VALUE-SETTER-TREE
    SETTERTREE)))

(CL:DEFUN STARTUP-DYNAMIC-SLOTS ()
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ KWD-DYNAMIC-SLOTS-DYNAMIC
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DYNAMIC" NULL 2))
    (CL:SETQ KWD-DYNAMIC-SLOTS-NULL-WRAPPER
     (INTERN-RIGID-SYMBOL-WRT-MODULE "NULL-WRAPPER" NULL 2))
    (CL:SETQ KWD-DYNAMIC-SLOTS-COMMON-LISP
     (INTERN-RIGID-SYMBOL-WRT-MODULE "COMMON-LISP" NULL 2))
    (CL:SETQ SGT-DYNAMIC-SLOTS-STELLA-OBJECT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "OBJECT" NULL 1))
    (CL:SETQ SYM-DYNAMIC-SLOTS-STELLA-WRAPPER-VALUE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "WRAPPER-VALUE" NULL 0))
    (CL:SETQ SYM-DYNAMIC-SLOTS-STELLA-SAFE-CAST
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SAFE-CAST" NULL 0))
    (CL:SETQ SYM-DYNAMIC-SLOTS-STELLA-DYNAMIC-SLOT-VALUE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DYNAMIC-SLOT-VALUE" NULL 0))
    (CL:SETQ SYM-DYNAMIC-SLOTS-STELLA-DYNAMIC-SLOTS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DYNAMIC-SLOTS" NULL 0))
    (CL:SETQ SYM-DYNAMIC-SLOTS-STELLA-QUOTE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "QUOTE" NULL 0))
    (CL:SETQ SYM-DYNAMIC-SLOTS-STELLA-NULL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "NULL" NULL 0))
    (CL:SETQ SYM-DYNAMIC-SLOTS-STELLA-SET-DYNAMIC-SLOT-VALUE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SET-DYNAMIC-SLOT-VALUE" NULL 0))
    (CL:SETQ SYM-DYNAMIC-SLOTS-STELLA-BQUOTE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "BQUOTE" NULL 0))
    (CL:SETQ SYM-DYNAMIC-SLOTS-STELLA-STARTUP-DYNAMIC-SLOTS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-DYNAMIC-SLOTS" NULL 0))
    (CL:SETQ SYM-DYNAMIC-SLOTS-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL
      0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "DYNAMIC-SLOT-VALUE"
     "(DEFUN (DYNAMIC-SLOT-VALUE OBJECT) ((DYNAMICSLOTS KEY-VALUE-LIST) (SLOTNAME SYMBOL) (NULLVALUE OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION DYNAMIC-SLOT-VALUE) NULL)
    (DEFINE-FUNCTION-OBJECT "SET-DYNAMIC-SLOT-VALUE"
     "(DEFUN (SET-DYNAMIC-SLOT-VALUE OBJECT) ((DYNAMICSLOTS KEY-VALUE-LIST) (SLOTNAME SYMBOL) (VALUE OBJECT) (NULLWRAPPER WRAPPER)) :PUBLIC? TRUE)"
     (CL:FUNCTION SET-DYNAMIC-SLOT-VALUE) NULL)
    (DEFINE-FUNCTION-OBJECT "STANDARD-DYNAMIC-SLOT-ACCESS?"
     "(DEFUN (STANDARD-DYNAMIC-SLOT-ACCESS? BOOLEAN) ((SLOT STORAGE-SLOT)))"
     (CL:FUNCTION STANDARD-DYNAMIC-SLOT-ACCESS?) NULL)
    (DEFINE-FUNCTION-OBJECT "YIELD-DOWN-CAST-TREE"
     "(DEFUN (YIELD-DOWN-CAST-TREE CONS) ((TREE CONS) (RETURNTYPE TYPE-SPEC)))"
     (CL:FUNCTION YIELD-DOWN-CAST-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "YIELD-STANDARD-DYNAMIC-SLOT-VALUE-TREE"
     "(DEFUN (YIELD-STANDARD-DYNAMIC-SLOT-VALUE-TREE CONS) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (RETURNTYPE TYPE-SPEC)))"
     (CL:FUNCTION YIELD-STANDARD-DYNAMIC-SLOT-VALUE-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT
     "YIELD-STANDARD-DYNAMIC-SLOT-VALUE-SETTER-TREE"
     "(DEFUN (YIELD-STANDARD-DYNAMIC-SLOT-VALUE-SETTER-TREE CONS) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (VALUEREF OBJECT) (RETURNTYPE TYPE-SPEC)))"
     (CL:FUNCTION YIELD-STANDARD-DYNAMIC-SLOT-VALUE-SETTER-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-DYNAMIC-SLOTS"
     "(DEFUN STARTUP-DYNAMIC-SLOTS () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-DYNAMIC-SLOTS) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION
        SYM-DYNAMIC-SLOTS-STELLA-STARTUP-DYNAMIC-SLOTS)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-DYNAMIC-SLOTS-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupDynamicSlots") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "/STELLA")))))
  :VOID)
