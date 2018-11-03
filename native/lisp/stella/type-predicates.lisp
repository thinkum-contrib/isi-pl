;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; type-predicates.lisp

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
|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-UNKNOWN NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-BOOLEAN-WRAPPER NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-INTEGER-WRAPPER NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-FLOAT-WRAPPER NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-STRING-WRAPPER NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-VERBATIM-STRING-WRAPPER NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-CHARACTER-WRAPPER NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-WRAPPER NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-SURROGATE NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-SYMBOL NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-TRANSIENT-SYMBOL NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-KEYWORD NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-CONS NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-CLASS NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-STORAGE-SLOT NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-METHOD-SLOT NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-ANCHORED-TYPE-SPECIFIER NULL)
(CL:DEFVAR SGT-TYPE-PREDICATES-STELLA-PARAMETRIC-TYPE-SPECIFIER NULL)
(CL:DEFVAR SYM-TYPE-PREDICATES-STELLA-STARTUP-TYPE-PREDICATES NULL)
(CL:DEFVAR SYM-TYPE-PREDICATES-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STELLA-MODULE* *MODULE* TRUE FALSE))

;;; (DEFGLOBAL *CLASS-HIERARCHY-BOOTED?* ...)

(CL:DEFVAR *CLASS-HIERARCHY-BOOTED?* FALSE)

;;; (DEFUN (SAFE-PRIMARY-TYPE TYPE) ...)

(CL:DEFUN SAFE-PRIMARY-TYPE (X)
  (CL:RETURN-FROM SAFE-PRIMARY-TYPE
   (CL:IF (CL:EQ X NULL) SGT-TYPE-PREDICATES-STELLA-UNKNOWN
    (PRIMARY-TYPE X))))

;;; (DEFUN (BOOTSTRAP-ISA? BOOLEAN) ...)

(CL:DEFUN BOOTSTRAP-ISA? (X TYPE)
  (CL:RETURN-FROM BOOTSTRAP-ISA?
   (CL:AND (CL:NOT (CL:EQ X NULL))
    (CL:OR (CL:EQ (PRIMARY-TYPE X) TYPE)
     (CL:AND (CL:NOT (CL:EQ (%SURROGATE-VALUE TYPE) NULL))
      (CL:NOT (CL:EQ (%SURROGATE-VALUE (PRIMARY-TYPE X)) NULL))
      (ISA? X TYPE))))))

;;; (DEFUN (BOOTSTRAP-SUBTYPE-OF? BOOLEAN) ...)

(CL:DEFUN BOOTSTRAP-SUBTYPE-OF? (SUBTYPE SUPERTYPE)
  (CL:RETURN-FROM BOOTSTRAP-SUBTYPE-OF?
   (CL:OR (CL:EQ SUBTYPE SUPERTYPE)
    (CL:AND (CL:NOT (CL:EQ (%SURROGATE-VALUE SUBTYPE) NULL))
     (CL:NOT (CL:EQ (%SURROGATE-VALUE SUPERTYPE) NULL))
     (SUBTYPE-OF? SUBTYPE SUPERTYPE)))))

;;; (DEFUN (BOOLEAN? BOOLEAN) ...)

(CL:DEFUN BOOLEAN? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM BOOLEAN?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-BOOLEAN-WRAPPER))))
  (CL:RETURN-FROM BOOLEAN?
   (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-BOOLEAN-WRAPPER)))

;;; (DEFUN (SUBTYPE-OF-BOOLEAN? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-BOOLEAN? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-BOOLEAN?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-BOOLEAN-WRAPPER)))
   (CL:RETURN-FROM SUBTYPE-OF-BOOLEAN?
    (BOOTSTRAP-SUBTYPE-OF? TYPE
     SGT-TYPE-PREDICATES-STELLA-BOOLEAN-WRAPPER))))

;;; (DEFUN (INTEGER? BOOLEAN) ...)

(CL:DEFUN INTEGER? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM INTEGER?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-INTEGER-WRAPPER))))
  (CL:RETURN-FROM INTEGER?
   (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-INTEGER-WRAPPER)))

;;; (DEFUN (SUBTYPE-OF-INTEGER? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-INTEGER? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-INTEGER?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-INTEGER-WRAPPER)))
   (CL:RETURN-FROM SUBTYPE-OF-INTEGER?
    (BOOTSTRAP-SUBTYPE-OF? TYPE
     SGT-TYPE-PREDICATES-STELLA-INTEGER-WRAPPER))))

;;; (DEFUN (FLOAT? BOOLEAN) ...)

(CL:DEFUN FLOAT? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM FLOAT?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-FLOAT-WRAPPER))))
  (CL:RETURN-FROM FLOAT?
   (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-FLOAT-WRAPPER)))

;;; (DEFUN (SUBTYPE-OF-FLOAT? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-FLOAT? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-FLOAT?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-FLOAT-WRAPPER)))
   (CL:RETURN-FROM SUBTYPE-OF-FLOAT?
    (BOOTSTRAP-SUBTYPE-OF? TYPE
     SGT-TYPE-PREDICATES-STELLA-FLOAT-WRAPPER))))

;;; (DEFUN (STRING? BOOLEAN) ...)

(CL:DEFUN STRING? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM STRING?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-STRING-WRAPPER))))
  (CL:RETURN-FROM STRING?
   (CL:OR (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-STRING-WRAPPER)
    (BOOTSTRAP-ISA? X
     SGT-TYPE-PREDICATES-STELLA-VERBATIM-STRING-WRAPPER))))

;;; (DEFUN (SUBTYPE-OF-STRING? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-STRING? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-STRING?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-STRING-WRAPPER)))
   (CL:RETURN-FROM SUBTYPE-OF-STRING?
    (CL:OR
     (BOOTSTRAP-SUBTYPE-OF? TYPE
      SGT-TYPE-PREDICATES-STELLA-STRING-WRAPPER)
     (BOOTSTRAP-SUBTYPE-OF? TYPE
      SGT-TYPE-PREDICATES-STELLA-VERBATIM-STRING-WRAPPER)))))

;;; (DEFUN (VERBATIM-STRING? BOOLEAN) ...)

(CL:DEFUN VERBATIM-STRING? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM VERBATIM-STRING?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-VERBATIM-STRING-WRAPPER))))
  (CL:RETURN-FROM VERBATIM-STRING?
   (BOOTSTRAP-ISA? X
    SGT-TYPE-PREDICATES-STELLA-VERBATIM-STRING-WRAPPER)))

;;; (DEFUN (SUBTYPE-OF-VERBATIM-STRING? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-VERBATIM-STRING? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-VERBATIM-STRING?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE
      SGT-TYPE-PREDICATES-STELLA-VERBATIM-STRING-WRAPPER)))
   (CL:RETURN-FROM SUBTYPE-OF-VERBATIM-STRING?
    (BOOTSTRAP-SUBTYPE-OF? TYPE
     SGT-TYPE-PREDICATES-STELLA-VERBATIM-STRING-WRAPPER))))

;;; (DEFUN (CHARACTER? BOOLEAN) ...)

(CL:DEFUN CHARACTER? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM CHARACTER?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-CHARACTER-WRAPPER))))
  (CL:RETURN-FROM CHARACTER?
   (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-CHARACTER-WRAPPER)))

;;; (DEFUN (SUBTYPE-OF-CHARACTER? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-CHARACTER? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-CHARACTER?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-CHARACTER-WRAPPER)))
   (CL:RETURN-FROM SUBTYPE-OF-CHARACTER?
    (BOOTSTRAP-SUBTYPE-OF? TYPE
     SGT-TYPE-PREDICATES-STELLA-CHARACTER-WRAPPER))))

;;; (DEFUN (WRAPPER? BOOLEAN) ...)

(CL:DEFUN WRAPPER? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM WRAPPER?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-WRAPPER))))
  (CL:RETURN-FROM WRAPPER?
   (CL:OR (BOOLEAN? X) (INTEGER? X) (FLOAT? X) (STRING? X)
    (CHARACTER? X)
    (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-WRAPPER))))

;;; (DEFUN (SUBTYPE-OF-WRAPPER? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-WRAPPER? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-WRAPPER?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-WRAPPER)))
   (CL:RETURN-FROM SUBTYPE-OF-WRAPPER?
    (CL:OR (SUBTYPE-OF-BOOLEAN? TYPE) (SUBTYPE-OF-INTEGER? TYPE)
     (SUBTYPE-OF-FLOAT? TYPE) (SUBTYPE-OF-STRING? TYPE)
     (SUBTYPE-OF-CHARACTER? TYPE)
     (BOOTSTRAP-SUBTYPE-OF? TYPE SGT-TYPE-PREDICATES-STELLA-WRAPPER)))))

;;; (DEFUN (SURROGATE? BOOLEAN) ...)

(CL:DEFUN SURROGATE? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SURROGATE?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-SURROGATE))))
  (CL:RETURN-FROM SURROGATE?
   (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-SURROGATE)))

;;; (DEFUN (SUBTYPE-OF-SURROGATE? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-SURROGATE? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-SURROGATE?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-SURROGATE)))
   (CL:RETURN-FROM SUBTYPE-OF-SURROGATE?
    (BOOTSTRAP-SUBTYPE-OF? TYPE SGT-TYPE-PREDICATES-STELLA-SURROGATE))))

;;; (DEFUN (TYPE? BOOLEAN) ...)

(CL:DEFUN TYPE? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM TYPE?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-SURROGATE))))
  (CL:RETURN-FROM TYPE?
   (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-SURROGATE)))

;;; (DEFUN (SUBTYPE-OF-TYPE? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-TYPE? (TYPE)
  (CL:RETURN-FROM SUBTYPE-OF-TYPE? (SUBTYPE-OF-SURROGATE? TYPE)))

;;; (DEFUN (SYMBOL? BOOLEAN) ...)

(CL:DEFUN SYMBOL? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SYMBOL?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-SYMBOL))))
  (CL:RETURN-FROM SYMBOL?
   (CL:OR (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-SYMBOL)
    (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-TRANSIENT-SYMBOL))))

;;; (DEFUN (SUBTYPE-OF-SYMBOL? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-SYMBOL? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-SYMBOL?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-SYMBOL)))
   (CL:RETURN-FROM SUBTYPE-OF-SYMBOL?
    (CL:OR
     (BOOTSTRAP-SUBTYPE-OF? TYPE SGT-TYPE-PREDICATES-STELLA-SYMBOL)
     (BOOTSTRAP-SUBTYPE-OF? TYPE
      SGT-TYPE-PREDICATES-STELLA-TRANSIENT-SYMBOL)))))

;;; (DEFUN (TRANSIENT-SYMBOL? BOOLEAN) ...)

(CL:DEFUN TRANSIENT-SYMBOL? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM TRANSIENT-SYMBOL?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-TRANSIENT-SYMBOL))))
  (CL:RETURN-FROM TRANSIENT-SYMBOL?
   (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-TRANSIENT-SYMBOL)))

;;; (DEFUN (SUBTYPE-OF-TRANSIENT-SYMBOL? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-TRANSIENT-SYMBOL? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-TRANSIENT-SYMBOL?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-TRANSIENT-SYMBOL)))
   (CL:RETURN-FROM SUBTYPE-OF-TRANSIENT-SYMBOL?
    (BOOTSTRAP-SUBTYPE-OF? TYPE
     SGT-TYPE-PREDICATES-STELLA-TRANSIENT-SYMBOL))))

;;; (DEFUN (KEYWORD? BOOLEAN) ...)

(CL:DEFUN KEYWORD? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM KEYWORD?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-KEYWORD))))
  (CL:RETURN-FROM KEYWORD?
   (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-KEYWORD)))

;;; (DEFUN (SUBTYPE-OF-KEYWORD? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-KEYWORD? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-KEYWORD?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-KEYWORD)))
   (CL:RETURN-FROM SUBTYPE-OF-KEYWORD?
    (BOOTSTRAP-SUBTYPE-OF? TYPE SGT-TYPE-PREDICATES-STELLA-KEYWORD))))

;;; (DEFUN (CONS? BOOLEAN) ...)

(CL:DEFUN CONS? (X)
  (CL:IF (CL:NOT (CL:EQ X NULL))
   (CL:RETURN-FROM CONS?
    (CL:EQ (PRIMARY-TYPE X) SGT-TYPE-PREDICATES-STELLA-CONS))
   (CL:RETURN-FROM CONS? FALSE)))

;;; (DEFUN (SUBTYPE-OF-CONS? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-CONS? (TYPE)
  (CL:RETURN-FROM SUBTYPE-OF-CONS?
   (CL:EQ TYPE SGT-TYPE-PREDICATES-STELLA-CONS)))

;;; (DEFUN (STELLA-CLASS? BOOLEAN) ...)

(CL:DEFUN STELLA-CLASS? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:IF (CL:NOT (CL:EQ X NULL))
    (CL:LET* ((TYPECLASS (%SURROGATE-VALUE (PRIMARY-TYPE X))))
     (CL:RETURN-FROM STELLA-CLASS?
      (CL:AND (CL:NOT (CL:EQ TYPECLASS NULL))
       (SUBCLASS-OF? TYPECLASS
        (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-CLASS)))))
    (CL:RETURN-FROM STELLA-CLASS? FALSE)))
  (CL:RETURN-FROM STELLA-CLASS?
   (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-CLASS)))

;;; (DEFUN (SUBTYPE-OF-CLASS? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-CLASS? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:LET* ((TYPECLASS (%SURROGATE-VALUE TYPE)))
    (CL:RETURN-FROM SUBTYPE-OF-CLASS?
     (CL:AND (CL:NOT (CL:EQ TYPECLASS NULL))
      (SUBCLASS-OF? TYPECLASS
       (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-CLASS)))))
   (CL:RETURN-FROM SUBTYPE-OF-CLASS?
    (BOOTSTRAP-SUBTYPE-OF? TYPE SGT-TYPE-PREDICATES-STELLA-CLASS))))

;;; (DEFUN (STORAGE-SLOT? BOOLEAN) ...)

(CL:DEFUN STORAGE-SLOT? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM STORAGE-SLOT?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-STORAGE-SLOT))))
  (CL:RETURN-FROM STORAGE-SLOT?
   (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-STORAGE-SLOT)))

;;; (DEFUN (SUBTYPE-OF-STORAGE-SLOT? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-STORAGE-SLOT? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-STORAGE-SLOT?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-STORAGE-SLOT)))
   (CL:RETURN-FROM SUBTYPE-OF-STORAGE-SLOT?
    (BOOTSTRAP-SUBTYPE-OF? TYPE
     SGT-TYPE-PREDICATES-STELLA-STORAGE-SLOT))))

;;; (DEFUN (METHOD-SLOT? BOOLEAN) ...)

(CL:DEFUN METHOD-SLOT? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM METHOD-SLOT?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-METHOD-SLOT))))
  (CL:RETURN-FROM METHOD-SLOT?
   (BOOTSTRAP-ISA? X SGT-TYPE-PREDICATES-STELLA-METHOD-SLOT)))

;;; (DEFUN (SUBTYPE-OF-METHOD-SLOT? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-METHOD-SLOT? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-METHOD-SLOT?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE SGT-TYPE-PREDICATES-STELLA-METHOD-SLOT)))
   (CL:RETURN-FROM SUBTYPE-OF-METHOD-SLOT?
    (BOOTSTRAP-SUBTYPE-OF? TYPE
     SGT-TYPE-PREDICATES-STELLA-METHOD-SLOT))))

;;; (DEFUN (ANCHORED-TYPE-SPECIFIER? BOOLEAN) ...)

(CL:DEFUN ANCHORED-TYPE-SPECIFIER? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM ANCHORED-TYPE-SPECIFIER?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-ANCHORED-TYPE-SPECIFIER))))
  (CL:RETURN-FROM ANCHORED-TYPE-SPECIFIER?
   (BOOTSTRAP-ISA? X
    SGT-TYPE-PREDICATES-STELLA-ANCHORED-TYPE-SPECIFIER)))

;;; (DEFUN (SUBTYPE-OF-ANCHORED-TYPE-SPECIFIER? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-ANCHORED-TYPE-SPECIFIER? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-ANCHORED-TYPE-SPECIFIER?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE
      SGT-TYPE-PREDICATES-STELLA-ANCHORED-TYPE-SPECIFIER)))
   (CL:RETURN-FROM SUBTYPE-OF-ANCHORED-TYPE-SPECIFIER?
    (BOOTSTRAP-SUBTYPE-OF? TYPE
     SGT-TYPE-PREDICATES-STELLA-ANCHORED-TYPE-SPECIFIER))))

;;; (DEFUN (PARAMETRIC-TYPE-SPECIFIER? BOOLEAN) ...)

(CL:DEFUN PARAMETRIC-TYPE-SPECIFIER? (X)
  (CL:WHEN *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM PARAMETRIC-TYPE-SPECIFIER?
    (CL:AND (CL:NOT (CL:EQ X NULL))
     (ISA? X SGT-TYPE-PREDICATES-STELLA-PARAMETRIC-TYPE-SPECIFIER))))
  (CL:RETURN-FROM PARAMETRIC-TYPE-SPECIFIER?
   (BOOTSTRAP-ISA? X
    SGT-TYPE-PREDICATES-STELLA-PARAMETRIC-TYPE-SPECIFIER)))

;;; (DEFUN (SUBTYPE-OF-PARAMETRIC-TYPE-SPECIFIER? BOOLEAN) ...)

(CL:DEFUN SUBTYPE-OF-PARAMETRIC-TYPE-SPECIFIER? (TYPE)
  (CL:IF *CLASS-HIERARCHY-BOOTED?*
   (CL:RETURN-FROM SUBTYPE-OF-PARAMETRIC-TYPE-SPECIFIER?
    (SUBCLASS-OF? (%SURROGATE-VALUE TYPE)
     (%SURROGATE-VALUE
      SGT-TYPE-PREDICATES-STELLA-PARAMETRIC-TYPE-SPECIFIER)))
   (CL:RETURN-FROM SUBTYPE-OF-PARAMETRIC-TYPE-SPECIFIER?
    (BOOTSTRAP-SUBTYPE-OF? TYPE
     SGT-TYPE-PREDICATES-STELLA-PARAMETRIC-TYPE-SPECIFIER))))

;;; (DEFMETHOD (STANDARD-OBJECT? BOOLEAN) ...)

(CL:DEFMETHOD STANDARD-OBJECT? ((SELF OBJECT))
  (CL:RETURN-FROM STANDARD-OBJECT? FALSE))

;;; (DEFMETHOD (STANDARD-OBJECT? BOOLEAN) ...)

(%%DEFCONSMETHOD STANDARD-OBJECT? ((SELF STANDARD-OBJECT))
  (CL:RETURN-FROM STANDARD-OBJECT? TRUE))

(CL:DEFUN HELP-STARTUP-TYPE-PREDICATES1 ()
  (CL:PROGN
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-UNKNOWN
    (INTERN-RIGID-SYMBOL-WRT-MODULE "UNKNOWN" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-BOOLEAN-WRAPPER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "BOOLEAN-WRAPPER" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-INTEGER-WRAPPER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "INTEGER-WRAPPER" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-FLOAT-WRAPPER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "FLOAT-WRAPPER" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-STRING-WRAPPER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STRING-WRAPPER" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-VERBATIM-STRING-WRAPPER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "VERBATIM-STRING-WRAPPER" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-CHARACTER-WRAPPER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "CHARACTER-WRAPPER" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-WRAPPER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "WRAPPER" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-SURROGATE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "SURROGATE" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-SYMBOL
    (INTERN-RIGID-SYMBOL-WRT-MODULE "SYMBOL" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-TRANSIENT-SYMBOL
    (INTERN-RIGID-SYMBOL-WRT-MODULE "TRANSIENT-SYMBOL" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-KEYWORD
    (INTERN-RIGID-SYMBOL-WRT-MODULE "KEYWORD" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-CONS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "CONS" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-CLASS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "CLASS" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-STORAGE-SLOT
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STORAGE-SLOT" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-METHOD-SLOT
    (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-SLOT" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-ANCHORED-TYPE-SPECIFIER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "ANCHORED-TYPE-SPECIFIER" NULL 1))
   (CL:SETQ SGT-TYPE-PREDICATES-STELLA-PARAMETRIC-TYPE-SPECIFIER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PARAMETRIC-TYPE-SPECIFIER" NULL
     1))
   (CL:SETQ SYM-TYPE-PREDICATES-STELLA-STARTUP-TYPE-PREDICATES
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-TYPE-PREDICATES" NULL 0))
   (CL:SETQ SYM-TYPE-PREDICATES-STELLA-METHOD-STARTUP-CLASSNAME
    (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL 0)))
  :VOID)

(CL:DEFUN STARTUP-TYPE-PREDICATES ()
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (HELP-STARTUP-TYPE-PREDICATES1))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ *CLASS-HIERARCHY-BOOTED?* FALSE))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "SAFE-PRIMARY-TYPE"
     "(DEFUN (SAFE-PRIMARY-TYPE TYPE) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION SAFE-PRIMARY-TYPE) NULL)
    (DEFINE-FUNCTION-OBJECT "BOOTSTRAP-ISA?"
     "(DEFUN (BOOTSTRAP-ISA? BOOLEAN) ((X OBJECT) (TYPE TYPE)))"
     (CL:FUNCTION BOOTSTRAP-ISA?) NULL)
    (DEFINE-FUNCTION-OBJECT "BOOTSTRAP-SUBTYPE-OF?"
     "(DEFUN (BOOTSTRAP-SUBTYPE-OF? BOOLEAN) ((SUBTYPE TYPE) (SUPERTYPE TYPE)))"
     (CL:FUNCTION BOOTSTRAP-SUBTYPE-OF?) NULL)
    (DEFINE-FUNCTION-OBJECT "BOOLEAN?"
     "(DEFUN (BOOLEAN? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION BOOLEAN?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-BOOLEAN?"
     "(DEFUN (SUBTYPE-OF-BOOLEAN? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-BOOLEAN?) NULL)
    (DEFINE-FUNCTION-OBJECT "INTEGER?"
     "(DEFUN (INTEGER? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION INTEGER?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-INTEGER?"
     "(DEFUN (SUBTYPE-OF-INTEGER? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-INTEGER?) NULL)
    (DEFINE-FUNCTION-OBJECT "FLOAT?"
     "(DEFUN (FLOAT? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION FLOAT?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-FLOAT?"
     "(DEFUN (SUBTYPE-OF-FLOAT? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-FLOAT?) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING?"
     "(DEFUN (STRING? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION STRING?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-STRING?"
     "(DEFUN (SUBTYPE-OF-STRING? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-STRING?) NULL)
    (DEFINE-FUNCTION-OBJECT "VERBATIM-STRING?"
     "(DEFUN (VERBATIM-STRING? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION VERBATIM-STRING?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-VERBATIM-STRING?"
     "(DEFUN (SUBTYPE-OF-VERBATIM-STRING? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-VERBATIM-STRING?) NULL)
    (DEFINE-FUNCTION-OBJECT "CHARACTER?"
     "(DEFUN (CHARACTER? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION CHARACTER?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-CHARACTER?"
     "(DEFUN (SUBTYPE-OF-CHARACTER? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-CHARACTER?) NULL)
    (DEFINE-FUNCTION-OBJECT "WRAPPER?"
     "(DEFUN (WRAPPER? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION WRAPPER?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-WRAPPER?"
     "(DEFUN (SUBTYPE-OF-WRAPPER? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-WRAPPER?) NULL)
    (DEFINE-FUNCTION-OBJECT "SURROGATE?"
     "(DEFUN (SURROGATE? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION SURROGATE?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-SURROGATE?"
     "(DEFUN (SUBTYPE-OF-SURROGATE? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-SURROGATE?) NULL)
    (DEFINE-FUNCTION-OBJECT "TYPE?"
     "(DEFUN (TYPE? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION TYPE?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-TYPE?"
     "(DEFUN (SUBTYPE-OF-TYPE? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (SUBTYPE-OF-SURROGATE? TYPE)))"
     (CL:FUNCTION SUBTYPE-OF-TYPE?) NULL)
    (DEFINE-FUNCTION-OBJECT "SYMBOL?"
     "(DEFUN (SYMBOL? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION SYMBOL?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-SYMBOL?"
     "(DEFUN (SUBTYPE-OF-SYMBOL? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-SYMBOL?) NULL)
    (DEFINE-FUNCTION-OBJECT "TRANSIENT-SYMBOL?"
     "(DEFUN (TRANSIENT-SYMBOL? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION TRANSIENT-SYMBOL?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-TRANSIENT-SYMBOL?"
     "(DEFUN (SUBTYPE-OF-TRANSIENT-SYMBOL? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-TRANSIENT-SYMBOL?) NULL)
    (DEFINE-FUNCTION-OBJECT "KEYWORD?"
     "(DEFUN (KEYWORD? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION KEYWORD?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-KEYWORD?"
     "(DEFUN (SUBTYPE-OF-KEYWORD? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-KEYWORD?) NULL)
    (DEFINE-FUNCTION-OBJECT "CONS?"
     "(DEFUN (CONS? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION CONS?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-CONS?"
     "(DEFUN (SUBTYPE-OF-CONS? BOOLEAN) ((TYPE TYPE)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (EQL? TYPE @CONS)))"
     (CL:FUNCTION SUBTYPE-OF-CONS?) NULL)
    (DEFINE-FUNCTION-OBJECT "STELLA-CLASS?"
     "(DEFUN (STELLA-CLASS? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION STELLA-CLASS?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-CLASS?"
     "(DEFUN (SUBTYPE-OF-CLASS? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-CLASS?) NULL)
    (DEFINE-FUNCTION-OBJECT "STORAGE-SLOT?"
     "(DEFUN (STORAGE-SLOT? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION STORAGE-SLOT?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-STORAGE-SLOT?"
     "(DEFUN (SUBTYPE-OF-STORAGE-SLOT? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-STORAGE-SLOT?) NULL)
    (DEFINE-FUNCTION-OBJECT "METHOD-SLOT?"
     "(DEFUN (METHOD-SLOT? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION METHOD-SLOT?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-METHOD-SLOT?"
     "(DEFUN (SUBTYPE-OF-METHOD-SLOT? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-METHOD-SLOT?) NULL)
    (DEFINE-FUNCTION-OBJECT "ANCHORED-TYPE-SPECIFIER?"
     "(DEFUN (ANCHORED-TYPE-SPECIFIER? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION ANCHORED-TYPE-SPECIFIER?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-ANCHORED-TYPE-SPECIFIER?"
     "(DEFUN (SUBTYPE-OF-ANCHORED-TYPE-SPECIFIER? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-ANCHORED-TYPE-SPECIFIER?) NULL)
    (DEFINE-FUNCTION-OBJECT "PARAMETRIC-TYPE-SPECIFIER?"
     "(DEFUN (PARAMETRIC-TYPE-SPECIFIER? BOOLEAN) ((X OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION PARAMETRIC-TYPE-SPECIFIER?) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBTYPE-OF-PARAMETRIC-TYPE-SPECIFIER?"
     "(DEFUN (SUBTYPE-OF-PARAMETRIC-TYPE-SPECIFIER? BOOLEAN) ((TYPE TYPE)) :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTYPE-OF-PARAMETRIC-TYPE-SPECIFIER?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (STANDARD-OBJECT? BOOLEAN) ((SELF OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION STANDARD-OBJECT?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (STANDARD-OBJECT? BOOLEAN) ((SELF STANDARD-OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION STANDARD-OBJECT?) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-TYPE-PREDICATES"
     "(DEFUN STARTUP-TYPE-PREDICATES () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-TYPE-PREDICATES) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION
        SYM-TYPE-PREDICATES-STELLA-STARTUP-TYPE-PREDICATES)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-TYPE-PREDICATES-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_Startup-Type-Predicates") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *CLASS-HIERARCHY-BOOTED?* BOOLEAN FALSE)")))
  :VOID)
