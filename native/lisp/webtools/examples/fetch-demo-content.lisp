;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; fetch-demo-content.lisp

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
| Portions created by the Initial Developer are Copyright (C) 2003-2014      |
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

(CL:DEFVAR |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-arg0| NULL)
(CL:DEFVAR |SYM-FETCH-DEMO-CONTENT-XSI-type| NULL)
(CL:DEFVAR |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-arg1| NULL)
(CL:DEFVAR |SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-item| NULL)
(CL:DEFVAR |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-item| NULL)
(CL:DEFVAR |SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-key| NULL)
(CL:DEFVAR |SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-val| NULL)
(CL:DEFVAR |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-key| NULL)
(CL:DEFVAR |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-value| NULL)
(CL:DEFVAR |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-arg2| NULL)
(CL:DEFVAR SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-STARTUP-FETCH-DEMO-CONTENT NULL)
(CL:DEFVAR SYM-FETCH-DEMO-CONTENT-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE*))

;;; (DEFCLASS arg0 ...)

(CL:DEFCLASS |arg0| (|XMLObject|)
  ((|type| :TYPE CL:SIMPLE-STRING :INITFORM STELLA::NULL-STRING
    :ALLOCATION :INSTANCE :ACCESSOR |%type|)))

(CL:DEFUN |new-arg0| ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE |arg0|)))
   (CL:SETF (|%cdataContent| SELF) STELLA::NULL-STRING)
   (CL:SETF (|%textContent| SELF) STELLA::NULL-STRING)
   (CL:SETF (|%type| SELF) "XSD:string") SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF |arg0|))
  |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-arg0|)

(CL:DEFUN |access-arg0-Slot-Value| (SELF SLOTNAME VALUE SETVALUE?)
  (CL:COND
   ((CL:EQ SLOTNAME |SYM-FETCH-DEMO-CONTENT-XSI-type|)
    (CL:IF SETVALUE? (CL:SETF (|%type| SELF) (%WRAPPER-VALUE VALUE))
     (CL:SETQ VALUE (WRAP-STRING (|%type| SELF)))))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" SLOTNAME
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
  VALUE)

;;; (DEFCLASS arg1 ...)

(CL:DEFCLASS |arg1| (|XMLObject|)
  ((|item| :ALLOCATION :INSTANCE :ACCESSOR |%item|)))

(CL:DEFUN |new-arg1| ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE |arg1|)))
   (CL:SETF (|%cdataContent| SELF) STELLA::NULL-STRING)
   (CL:SETF (|%textContent| SELF) STELLA::NULL-STRING)
   (CL:SETF (|%item| SELF) NULL) SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF |arg1|))
  |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-arg1|)

(CL:DEFUN |access-arg1-Slot-Value| (SELF SLOTNAME VALUE SETVALUE?)
  (CL:COND
   ((CL:EQ SLOTNAME |SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-item|)
    (CL:IF SETVALUE? (CL:SETF (|%item| SELF) VALUE)
     (CL:SETQ VALUE (|%item| SELF))))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" SLOTNAME
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
  VALUE)

;;; (DEFCLASS item ...)

(CL:DEFCLASS |item| (|XMLObject|)
  ((|key| :ALLOCATION :INSTANCE :ACCESSOR |%key|)
   (|val| :ALLOCATION :INSTANCE :ACCESSOR |%val|)))

(CL:DEFUN |new-item| ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE |item|)))
   (CL:SETF (|%cdataContent| SELF) STELLA::NULL-STRING)
   (CL:SETF (|%textContent| SELF) STELLA::NULL-STRING)
   (CL:SETF (|%val| SELF) NULL) (CL:SETF (|%key| SELF) NULL) SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF |item|))
  |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-item|)

(CL:DEFUN |access-item-Slot-Value| (SELF SLOTNAME VALUE SETVALUE?)
  (CL:COND
   ((CL:EQ SLOTNAME |SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-key|)
    (CL:IF SETVALUE? (CL:SETF (|%key| SELF) VALUE)
     (CL:SETQ VALUE (|%key| SELF))))
   ((CL:EQ SLOTNAME |SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-val|)
    (CL:IF SETVALUE? (CL:SETF (|%val| SELF) VALUE)
     (CL:SETQ VALUE (|%val| SELF))))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" SLOTNAME
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
  VALUE)

;;; (DEFCLASS key ...)

(CL:DEFCLASS |key| (|XMLObject|)
  ((|type| :TYPE CL:SIMPLE-STRING :INITFORM STELLA::NULL-STRING
    :ALLOCATION :INSTANCE :ACCESSOR |%type|)))

(CL:DEFUN |new-key| ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE |key|)))
   (CL:SETF (|%cdataContent| SELF) STELLA::NULL-STRING)
   (CL:SETF (|%textContent| SELF) STELLA::NULL-STRING)
   (CL:SETF (|%type| SELF) "XSD:string") SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF |key|))
  |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-key|)

(CL:DEFUN |access-key-Slot-Value| (SELF SLOTNAME VALUE SETVALUE?)
  (CL:COND
   ((CL:EQ SLOTNAME |SYM-FETCH-DEMO-CONTENT-XSI-type|)
    (CL:IF SETVALUE? (CL:SETF (|%type| SELF) (%WRAPPER-VALUE VALUE))
     (CL:SETQ VALUE (WRAP-STRING (|%type| SELF)))))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" SLOTNAME
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
  VALUE)

;;; (DEFCLASS value ...)

(CL:DEFCLASS |value| (|XMLObject|)
  ((|type| :TYPE CL:SIMPLE-STRING :INITFORM STELLA::NULL-STRING
    :ALLOCATION :INSTANCE :ACCESSOR |%type|)))

(CL:DEFUN |new-value| ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE |value|)))
   (CL:SETF (|%cdataContent| SELF) STELLA::NULL-STRING)
   (CL:SETF (|%textContent| SELF) STELLA::NULL-STRING)
   (CL:SETF (|%type| SELF) "XSD:string") SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF |value|))
  |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-value|)

(CL:DEFUN |access-value-Slot-Value| (SELF SLOTNAME VALUE SETVALUE?)
  (CL:COND
   ((CL:EQ SLOTNAME |SYM-FETCH-DEMO-CONTENT-XSI-type|)
    (CL:IF SETVALUE? (CL:SETF (|%type| SELF) (%WRAPPER-VALUE VALUE))
     (CL:SETQ VALUE (WRAP-STRING (|%type| SELF)))))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" SLOTNAME
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
  VALUE)

;;; (DEFCLASS arg2 ...)

(CL:DEFCLASS |arg2| (|XMLObject|)
  ())

(CL:DEFUN |new-arg2| ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE |arg2|)))
   (CL:SETF (|%cdataContent| SELF) STELLA::NULL-STRING)
   (CL:SETF (|%textContent| SELF) STELLA::NULL-STRING) SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF |arg2|))
  |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-arg2|)

(CL:DEFUN STARTUP-FETCH-DEMO-CONTENT ()
  (CL:LET*
   ((*MODULE*
     (GET-STELLA-MODULE "/STELLA/XML-OBJECTS/FETCH-CONTENT"
      (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-arg0|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "arg0" NULL 1))
    (CL:SETQ |SYM-FETCH-DEMO-CONTENT-XSI-type|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "type"
      (GET-STELLA-MODULE "/STELLA/XML-OBJECTS/XSI" CL:T) 0))
    (CL:SETQ |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-arg1|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "arg1" NULL 1))
    (CL:SETQ |SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-item|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "item" NULL 0))
    (CL:SETQ |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-item|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "item" NULL 1))
    (CL:SETQ |SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-key|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "key" NULL 0))
    (CL:SETQ |SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-val|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "val" NULL 0))
    (CL:SETQ |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-key|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "key" NULL 1))
    (CL:SETQ |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-value|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "value" NULL 1))
    (CL:SETQ |SGT-FETCH-DEMO-CONTENT-FETCH-CONTENT-arg2|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "arg2" NULL 1))
    (CL:SETQ
     SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-STARTUP-FETCH-DEMO-CONTENT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-FETCH-DEMO-CONTENT" NULL
      0))
    (CL:SETQ SYM-FETCH-DEMO-CONTENT-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 5)
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "arg0"
        "(DEFCLASS arg0 (XMLObject) :PUBLIC-SLOTS ((/STELLA/XML-OBJECTS/XSI/type :TYPE STRING :INITIALLY \"XSD:string\")))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS) (CL:FUNCTION |new-arg0|))
     (CL:SETF (%CLASS-SLOT-ACCESSOR-CODE CLASS)
      (CL:FUNCTION |access-arg0-Slot-Value|)))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "arg1"
        "(DEFCLASS arg1 (XMLObject) :PUBLIC-SLOTS ((item :TYPE item)))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS) (CL:FUNCTION |new-arg1|))
     (CL:SETF (%CLASS-SLOT-ACCESSOR-CODE CLASS)
      (CL:FUNCTION |access-arg1-Slot-Value|)))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "item"
        "(DEFCLASS item (XMLObject) :PUBLIC-SLOTS ((key :TYPE key) (val :TYPE value)))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS) (CL:FUNCTION |new-item|))
     (CL:SETF (%CLASS-SLOT-ACCESSOR-CODE CLASS)
      (CL:FUNCTION |access-item-Slot-Value|)))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "key"
        "(DEFCLASS key (XMLObject) :PUBLIC-SLOTS ((/STELLA/XML-OBJECTS/XSI/type :TYPE STRING :INITIALLY \"XSD:string\")))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS) (CL:FUNCTION |new-key|))
     (CL:SETF (%CLASS-SLOT-ACCESSOR-CODE CLASS)
      (CL:FUNCTION |access-key-Slot-Value|)))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "value"
        "(DEFCLASS value (XMLObject) :PUBLIC-SLOTS ((/STELLA/XML-OBJECTS/XSI/type :TYPE STRING :INITIALLY \"XSD:string\")))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS)
      (CL:FUNCTION |new-value|))
     (CL:SETF (%CLASS-SLOT-ACCESSOR-CODE CLASS)
      (CL:FUNCTION |access-value-Slot-Value|)))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "arg2"
        "(DEFCLASS arg2 (XMLObject))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS)
      (CL:FUNCTION |new-arg2|))))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "STARTUP-FETCH-DEMO-CONTENT"
     "(DEFUN STARTUP-FETCH-DEMO-CONTENT () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-FETCH-DEMO-CONTENT) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION
        SYM-FETCH-DEMO-CONTENT-FETCH-CONTENT-STARTUP-FETCH-DEMO-CONTENT)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-FETCH-DEMO-CONTENT-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupFetchDemoContent") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "FETCH-CONTENT")))
    (INSERT-AT *NAMESPACE-PREFIX-URI-TABLE*
     (WRAP-STRING "FETCH-CONTENT")
     (WRAP-STRING "urn:fetchDemoContent"))
    (INSERT-AT *NAMESPACE-URI-PREFIX-TABLE*
     (WRAP-STRING "urn:fetchDemoContent")
     (WRAP-STRING "FETCH-CONTENT"))
    (CL:SETQ *INVISIBLE-NAMESPACES-ON-OUTPUT*
     (CONS (WRAP-STRING "FETCH-CONTENT")
      *INVISIBLE-NAMESPACES-ON-OUTPUT*)))))
