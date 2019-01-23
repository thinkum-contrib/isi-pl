;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; xml-object.lisp

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
| Portions created by the Initial Developer are Copyright (C) 2003-2017      |
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

(CL:DEFVAR KWD-XML-OBJECT-INVISIBLE-ON-OUTPUT? NULL)
(CL:DEFVAR SYM-XML-OBJECT-STELLA-PUSHQ NULL)
(CL:DEFVAR SYM-XML-OBJECT-XML-OBJECTS-*INVISIBLE-NAMESPACES-ON-OUTPUT* NULL)
(CL:DEFVAR SYM-XML-OBJECT-STELLA-STARTUP-TIME-PROGN NULL)
(CL:DEFVAR SYM-XML-OBJECT-STELLA-INSERT-AT NULL)
(CL:DEFVAR SYM-XML-OBJECT-XML-OBJECTS-*NAMESPACE-PREFIX-URI-TABLE* NULL)
(CL:DEFVAR SYM-XML-OBJECT-XML-OBJECTS-*NAMESPACE-URI-PREFIX-TABLE* NULL)
(CL:DEFVAR |SYM-XML-OBJECT-XML-OBJECTS-textContent| NULL)
(CL:DEFVAR |SYM-XML-OBJECT-XML-OBJECTS-cdataContent| NULL)
(CL:DEFVAR SYM-XML-OBJECT-XML-OBJECTS-STARTUP-XML-OBJECT NULL)
(CL:DEFVAR SYM-XML-OBJECT-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STARTUP-TIME-PHASE* NULL-CHARACTER NULL-INTEGER *MODULE* NIL))

;;; (DEFGLOBAL *NAMESPACE-PREFIX-URI-TABLE* ...)

(CL:DEFVAR *NAMESPACE-PREFIX-URI-TABLE* NULL
  "Property list associating module names (namespace prefixes) with namespace uris.")

;;; (DEFGLOBAL *NAMESPACE-URI-PREFIX-TABLE* ...)

(CL:DEFVAR *NAMESPACE-URI-PREFIX-TABLE* NULL
  "Property list associating namespace uris with module names.")

;;; (DEFGLOBAL *INVISIBLE-NAMESPACES-ON-OUTPUT* ...)

(CL:DEFVAR *INVISIBLE-NAMESPACES-ON-OUTPUT* NULL
  "List of Namespaces which should not be output during xml generation.  
   Should be used in conjuction with *SUPRESS-NAMESPACES?*")

;;; (DEFMACRO DEFNAMESPACE ...)

(CL:DEFUN DEFNAMESPACE (|body|)
  (CL:LET* ((|namespaceURI| (%%VALUE |body|)) (|namespaceName| (%MODULE-NAME *MODULE*)) (|bodyWithHeader| (CONS NULL |body|)))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING |namespaceName|))
   (CL:LET* ((SELF-000 (NEW-PROPERTY-LIST))) (CL:SETF (%THE-PLIST SELF-000) (EXTRACT-OPTIONS |bodyWithHeader| NULL))
    (CL:LET*
     ((|options| SELF-000) (|invisible?| (LOOKUP |options| KWD-XML-OBJECT-INVISIBLE-ON-OUTPUT?))
      (|invisibleForm|
       (CL:IF (CL:AND (CL:NOT (CL:EQ |invisible?| NULL)) (STRING-EQUAL? (%SYMBOL-NAME |invisible?|) "TRUE"))
        (CONS (LIST* SYM-XML-OBJECT-STELLA-PUSHQ SYM-XML-OBJECT-XML-OBJECTS-*INVISIBLE-NAMESPACES-ON-OUTPUT* (WRAP-STRING |namespaceName|) NIL) NIL) NIL)))
     (LIST* SYM-XML-OBJECT-STELLA-STARTUP-TIME-PROGN
      (LIST* SYM-XML-OBJECT-STELLA-INSERT-AT SYM-XML-OBJECT-XML-OBJECTS-*NAMESPACE-PREFIX-URI-TABLE* (WRAP-STRING |namespaceName|) (CONS |namespaceURI| NIL))
      (LIST* SYM-XML-OBJECT-STELLA-INSERT-AT SYM-XML-OBJECT-XML-OBJECTS-*NAMESPACE-URI-PREFIX-TABLE* |namespaceURI| (CONS (WRAP-STRING |namespaceName|) NIL))
      (CONCATENATE |invisibleForm| NIL))))))

;;; (DEFCLASS XMLObject ...)

(CL:DEFCLASS |XMLObject| (STANDARD-OBJECT)
  ((|textContent| :TYPE CL:SIMPLE-STRING :INITFORM STELLA::NULL-STRING :ALLOCATION :INSTANCE :ACCESSOR |%textContent|)
   (|cdataContent| :TYPE CL:SIMPLE-STRING :INITFORM STELLA::NULL-STRING :ALLOCATION :INSTANCE :ACCESSOR |%cdataContent|))
  (:DOCUMENTATION "The Root of all XMLObjects"))

(CL:DEFUN |access-XMLObject-Slot-Value| (SELF SLOTNAME VALUE SETVALUE?)
  (CL:COND
   ((CL:EQ SLOTNAME |SYM-XML-OBJECT-XML-OBJECTS-textContent|)
    (CL:IF SETVALUE? (CL:SETF (|%textContent| SELF) (%WRAPPER-VALUE VALUE)) (CL:SETQ VALUE (WRAP-STRING (|%textContent| SELF)))))
   ((CL:EQ SLOTNAME |SYM-XML-OBJECT-XML-OBJECTS-cdataContent|)
    (CL:IF SETVALUE? (CL:SETF (|%cdataContent| SELF) (%WRAPPER-VALUE VALUE)) (CL:SETQ VALUE (WRAP-STRING (|%cdataContent| SELF)))))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM))) (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" SLOTNAME "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
  VALUE)

(CL:DEFMETHOD PRINT-OBJECT ((SELF |XMLObject|) STREAM)
  (%%PRINT-STREAM STREAM (TO-XML-STRING SELF)))

;;; (DEFMETHOD (GET-CONTENT STRING) ...)

(CL:DEFMETHOD GET-CONTENT ((OBJ |XMLObject|))
  "Returns the textContent or cdataContent slot, whichever has
a value.  If both are present, only the textContent slot is returned."
  (CL:IF (CL:NOT (CL:EQ (|%textContent| OBJ) STELLA::NULL-STRING)) (|%textContent| OBJ) (|%cdataContent| OBJ)))

;;; (DEFMETHOD SET-CONTENT ...)

(CL:DEFMETHOD SET-CONTENT ((OBJ |XMLObject|) CONTENT)
  "Sets either the textContent or cdataContent slot, depending on
whether `CONTENT' needs to be encoded as CDATA or not."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING CONTENT))
  #+(or MCL OpenMCL)
  (CL:CHECK-TYPE CONTENT CL:SIMPLE-STRING)
  (CL:LET* ((FOUND?-000 CL:NIL))
   (CL:LET* ((CH NULL-CHARACTER) (VECTOR-000 CONTENT) (INDEX-000 0) (LENGTH-000 (CL:THE CL:FIXNUM (CL:LENGTH VECTOR-000))))
    (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING VECTOR-000) (CL:TYPE CL:FIXNUM INDEX-000 LENGTH-000))
    (CL:LOOP WHILE (CL:< INDEX-000 LENGTH-000) DO
     (CL:SETQ CH
      (CL:LET ((SELF VECTOR-000) (POSITION INDEX-000)) (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF) (CL:TYPE CL:FIXNUM POSITION))
       (CL:SCHAR (CL:THE CL:SIMPLE-STRING SELF) (CL:THE CL:FIXNUM POSITION))))
     (CL:WHEN (HTML-CHARACTER-NEEDS-QUOTING? CH) (CL:SETQ FOUND?-000 CL:T) (CL:RETURN)) (CL:SETQ INDEX-000 (CL:1+ INDEX-000))))
   (CL:IF FOUND?-000
    (CL:IF (CL:NOT (CL:= (STRING-SEARCH CONTENT "]]>" 0) NULL-INTEGER))
     (CL:LET* ((S (NEW-OUTPUT-STRING-STREAM))) (WRITE-HTML-QUOTING-SPECIAL-CHARACTERS (%NATIVE-STREAM S) CONTENT) (CL:SETF (|%textContent| OBJ) (THE-STRING-READER S)))
     (CL:SETF (|%cdataContent| OBJ) CONTENT))
    (CL:SETF (|%textContent| OBJ) CONTENT))))

(CL:DEFUN STARTUP-XML-OBJECT ()
  (CL:LET* ((*MODULE* (GET-STELLA-MODULE "/STELLA/XML-OBJECTS" (> *STARTUP-TIME-PHASE* 1))) (*CONTEXT* *MODULE*)) (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2) (CL:SETQ KWD-XML-OBJECT-INVISIBLE-ON-OUTPUT? (INTERN-RIGID-SYMBOL-WRT-MODULE "INVISIBLE-ON-OUTPUT?" NULL 2))
    (CL:SETQ SYM-XML-OBJECT-STELLA-PUSHQ (INTERN-RIGID-SYMBOL-WRT-MODULE "PUSHQ" (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-XML-OBJECT-XML-OBJECTS-*INVISIBLE-NAMESPACES-ON-OUTPUT* (INTERN-RIGID-SYMBOL-WRT-MODULE "*INVISIBLE-NAMESPACES-ON-OUTPUT*" NULL 0))
    (CL:SETQ SYM-XML-OBJECT-STELLA-STARTUP-TIME-PROGN (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-TIME-PROGN" (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-XML-OBJECT-STELLA-INSERT-AT (INTERN-RIGID-SYMBOL-WRT-MODULE "INSERT-AT" (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-XML-OBJECT-XML-OBJECTS-*NAMESPACE-PREFIX-URI-TABLE* (INTERN-RIGID-SYMBOL-WRT-MODULE "*NAMESPACE-PREFIX-URI-TABLE*" NULL 0))
    (CL:SETQ SYM-XML-OBJECT-XML-OBJECTS-*NAMESPACE-URI-PREFIX-TABLE* (INTERN-RIGID-SYMBOL-WRT-MODULE "*NAMESPACE-URI-PREFIX-TABLE*" NULL 0))
    (CL:SETQ |SYM-XML-OBJECT-XML-OBJECTS-textContent| (INTERN-RIGID-SYMBOL-WRT-MODULE "textContent" NULL 0))
    (CL:SETQ |SYM-XML-OBJECT-XML-OBJECTS-cdataContent| (INTERN-RIGID-SYMBOL-WRT-MODULE "cdataContent" NULL 0))
    (CL:SETQ SYM-XML-OBJECT-XML-OBJECTS-STARTUP-XML-OBJECT (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-XML-OBJECT" NULL 0))
    (CL:SETQ SYM-XML-OBJECT-STELLA-METHOD-STARTUP-CLASSNAME (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" (GET-STELLA-MODULE "/STELLA" CL:T) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4) (CL:SETQ *NAMESPACE-PREFIX-URI-TABLE* (NEW-PROPERTY-LIST)) (CL:SETQ *NAMESPACE-URI-PREFIX-TABLE* (NEW-PROPERTY-LIST))
    (CL:SETQ *INVISIBLE-NAMESPACES-ON-OUTPUT* NIL))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 5)
    (DEFINE-EXTERNAL-SLOT-FROM-PARSE-TREE
     (GET-QUOTED-TREE
      "((DEFSLOT STORAGE-SLOT ENCODING-SCHEME :TYPE KEYWORD :OPTION-KEYWORD :ENCODING-SCHEME :DOCUMENTATION \"Specify an encoding scheme used to encode the value
of a slot.  The currently understood values are :PLAIN (or NULL) and :BASE64\") \"/STELLA/XML-OBJECTS\")" "/STELLA/XML-OBJECTS"))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "XMLObject"
        "(DEFCLASS XMLObject (STANDARD-OBJECT) :DOCUMENTATION \"The Root of all XMLObjects\" :ABSTRACT? TRUE :PUBLIC-SLOTS ((textContent :TYPE STRING) (cdataContent :TYPE STRING)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM (TO-XML-STRING SELF)))")))
     (CL:SETF (%CLASS-SLOT-ACCESSOR-CODE CLASS) (CL:FUNCTION |access-XMLObject-Slot-Value|))))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "DEFNAMESPACE" "(DEFUN DEFNAMESPACE (|&BODY| (body CONS)) :TYPE OBJECT :MACRO? TRUE)" (CL:FUNCTION DEFNAMESPACE) NULL)
    (DEFINE-EXTERNAL-SLOT-FROM-STRINGIFIED-SOURCE
     "(DEFSLOT STORAGE-SLOT ENCODING-SCHEME :TYPE KEYWORD :OPTION-KEYWORD :ENCODING-SCHEME :DOCUMENTATION \"Specify an encoding scheme used to encode the value
of a slot.  The currently understood values are :PLAIN (or NULL) and :BASE64\" :ALLOCATION :DYNAMIC)")
    (DEFINE-METHOD-OBJECT "(DEFMETHOD (GET-CONTENT STRING) ((OBJ XMLObject)) :PUBLIC? TRUE :DOCUMENTATION \"Returns the textContent or cdataContent slot, whichever has
a value.  If both are present, only the textContent slot is returned.\")" (CL:FUNCTION GET-CONTENT) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD SET-CONTENT ((OBJ XMLObject) (CONTENT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Sets either the textContent or cdataContent slot, depending on
whether `CONTENT' needs to be encoded as CDATA or not.\")" (CL:FUNCTION SET-CONTENT) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-XML-OBJECT" "(DEFUN STARTUP-XML-OBJECT () :PUBLIC? TRUE)" (CL:FUNCTION STARTUP-XML-OBJECT) NULL)
    (CL:LET* ((FUNCTION (LOOKUP-FUNCTION SYM-XML-OBJECT-XML-OBJECTS-STARTUP-XML-OBJECT)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION) SYM-XML-OBJECT-STELLA-METHOD-STARTUP-CLASSNAME (WRAP-STRING "_StartupXmlObject") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS) (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9) (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "XML-OBJECTS")))
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *NAMESPACE-PREFIX-URI-TABLE* PROPERTY-LIST (NEW PROPERTY-LIST) :DOCUMENTATION \"Property list associating module names (namespace prefixes) with namespace uris.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *NAMESPACE-URI-PREFIX-TABLE* PROPERTY-LIST (NEW PROPERTY-LIST) :DOCUMENTATION \"Property list associating namespace uris with module names.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *INVISIBLE-NAMESPACES-ON-OUTPUT* CONS NIL :DOCUMENTATION \"List of Namespaces which should not be output during xml generation.  
   Should be used in conjuction with *SUPRESS-NAMESPACES?*\")"))))
