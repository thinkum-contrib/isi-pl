;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

#|--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | 
 |  University of Southern California, Information Sciences Institute       |
 |  4676 Admiralty Way                                                      |
 |  Marina Del Rey, California 90292                                        |
 |                                                                          |
 |  This software was developed under the terms and conditions of Contract  |
 |  No. N00014-94-C-0245 between the Defense Advanced Research Projects     |
 |  Agency and the University of Southern California, Information Sciences  | 
 |  Institute.  Use and distribution of this software is further subject    |
 |  to the provisions of that contract and any other agreements developed   |
 |  between the user of the software and the University of Southern         |
 |  California, Information Sciences Institute.  It is supplied "AS IS",    |
 |  without any warranties of any kind.  It is furnished only on the basis  |
 |  that any party who receives it indemnifies and holds harmless the       |
 |  parties who furnish and originate it against any claims, demands, or    |
 |  liabilities connected with using it, furnishing it to others or         |
 |  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    |
 |  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  |
 |  BE ATTACHED TO EVERY PART.                                              |
 |                                                                          |
 +--------------------------------------------------------------------------|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR SGT-GFP-SLOT NULL)
(CL:DEFVAR SGT-GFP-LOGIC-OBJECT NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *MODULE* STANDARD-OUTPUT))

;;; (DEFUN (GET-OBJECT-OR-WARN OBJECT) ...)

(CL:DEFUN GET-OBJECT-OR-WARN (NAME)
  (CL:LET*
   ((INSTANCE (GET-FRAME NAME)))
   (CL:WHEN
    (CL:EQ INSTANCE NULL)
    (CL:WARN "Can't find an individual named `~A'." NAME))
   (CL:RETURN-FROM GET-OBJECT-OR-WARN INSTANCE))
  :VOID)

;;; (DEFUN (GET-FRAME-OR-WARN OBJECT) ...)

(CL:DEFUN GET-FRAME-OR-WARN (NAME)
  (CL:LET*
   ((INSTANCE (GET-FRAME NAME)))
   (CL:WHEN
    (CL:EQ INSTANCE NULL)
    (CL:WARN "Can't find an individual named `~A'." NAME))
   (CL:RETURN-FROM GET-FRAME-OR-WARN INSTANCE))
  :VOID)

;;; (DEFUN (GET-CLASS-OR-WARN CLASS) ...)

(CL:DEFUN GET-CLASS-OR-WARN (NAME)
  (CL:LET*
   ((CLASS (GET-CLASS NAME FALSE)))
   (CL:WHEN
    (CL:EQ CLASS NULL)
    (CL:WRITE-STRING
     "A class named ' name ' does not exist."
     (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT)))
   (CL:RETURN-FROM GET-CLASS-OR-WARN CLASS))
  :VOID)

;;; (DEFMETHOD (GET-FRAME LOGIC-OBJECT) ...)

(CL:DEFMETHOD GET-FRAME ((NAME CL:STRING))
  "Return the instanced named 'name'."
  (CL:RETURN-FROM GET-FRAME (GET-INSTANCE NAME FALSE))
  :VOID)

;;; (DEFMETHOD (GET-OWN-SLOT SLOT) ...)

(CL:DEFMETHOD GET-OWN-SLOT ((SELF LOGIC-OBJECT) SLOTNAME)
  "Return the slot named 'slotName' on the instance 'self'."
  (CL:LET*
   ((SLOTREF (LOOKUP-SLOTREF-ON-INSTANCE SELF (INTERN-SYMBOL SLOTNAME))))
   (CL:IF
    (CL:EQ SLOTREF NULL)
    (CL:RETURN-FROM GET-OWN-SLOT NULL)
    (CL:RETURN-FROM
     GET-OWN-SLOT
     (CAST (CLSYS-SVAL SURROGATE SURROGATE-VALUE SLOTREF) SGT-GFP-SLOT))))
  :VOID)

;;; (DEFMETHOD (GET-TEMPLATE-SLOT SLOT) ...)

(CL:DEFMETHOD GET-TEMPLATE-SLOT ((SELF CLASS) SLOTNAME)
  "Return the slot named 'slotName' on the class 'self'."
  (CL:RETURN-FROM
   GET-TEMPLATE-SLOT
   (SAFE-LOOKUP-SLOT SELF (INTERN-SYMBOL SLOTNAME)))
  :VOID)

;;; (DEFMETHOD (GET-TEMPLATE-SLOT SLOT) ...)

(CL:DEFMETHOD GET-TEMPLATE-SLOT ((SELF CL:STRING) SLOTNAME)
  "Return the slot named 'slotName' on the class 'self'."
  (CL:LET*
   ((CLASS (GET-CLASS-OR-WARN SELF)))
   (CL:WHEN (CL:EQ CLASS NULL) (CL:RETURN-FROM GET-TEMPLATE-SLOT NULL))
   (CL:RETURN-FROM GET-TEMPLATE-SLOT (GET-TEMPLATE-SLOT CLASS SLOTNAME)))
  :VOID)

;;; (DEFMETHOD (GET-SLOT-VALUE OBJECT) ...)

(CL:DEFMETHOD GET-SLOT-VALUE ((SELF LOGIC-OBJECT) SLOTNAME)
  "Get the value of 'slot' on 'self'."
  (CL:LET*
   ((SLOT (GET-OWN-SLOT SELF SLOTNAME)))
   (CL:RETURN-FROM
    GET-SLOT-VALUE
    (GET-ATTRIBUTE-PROPOSITION-VALUE SELF (CLSYS-SVAL SLOT SLOT-SLOTREF SLOT))))
  :VOID)

;;; (DEFMETHOD (GET-SLOT-VALUE OBJECT) ...)

(CL:DEFMETHOD GET-SLOT-VALUE ((SELF CL:STRING) SLOTNAME)
  "Get the value of 'slot' on the instance named 'self'."
  (CL:LET*
   ((INSTANCE (GET-OBJECT-OR-WARN SELF)))
   (CL:WHEN (CL:EQ INSTANCE NULL) (CL:RETURN-FROM GET-SLOT-VALUE NULL))
   (CL:LET*
    ((INSTANCE-001 INSTANCE))
    (CL:COND
     ((CL:EQ (TAXONOMY-ISA? INSTANCE SGT-GFP-LOGIC-OBJECT) 1)
      (CL:LET*
       ((INSTANCE NULL))
       (CL:SETQ INSTANCE INSTANCE-001)
       (CL:RETURN-FROM GET-SLOT-VALUE (GET-SLOT-VALUE INSTANCE SLOTNAME))))
     (CL:T
      (CL:LET
       ((%%STREAM (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT)))
       (CL:WRITE-STRING
        "Don't know how to read a slot value of the non-logic object "
        %%STREAM)
       (CL:WRITE-STRING SELF %%STREAM)
       (CL:WRITE-STRING "." %%STREAM))
      (CL:RETURN-FROM GET-SLOT-VALUE NULL)))))
  :VOID)

(CL:DEFUN STARTUP-GFP ()
  (CL:LET*
   ((*MODULE* (GET-MODULE "/LOGIC" TRUE)) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 2) 1)
    (CL:SETQ
     SGT-GFP-SLOT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SLOT" (GET-MODULE "/STELLA" TRUE) 1))
    (CL:SETQ
     SGT-GFP-LOGIC-OBJECT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "LOGIC-OBJECT" NULL 1)))
   (CL:WHEN (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 6) 1) (FINALIZE-CLASSES))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 7) 1)
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "GET-OBJECT-OR-WARN"
        "STRING"
        "(DEFUN (GET-OBJECT-OR-WARN OBJECT) ((NAME STRING)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION GET-OBJECT-OR-WARN)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "GET-FRAME-OR-WARN"
        "STRING"
        "(DEFUN (GET-FRAME-OR-WARN OBJECT) ((NAME STRING)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION GET-FRAME-OR-WARN)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "GET-CLASS-OR-WARN"
        "STRING"
        "(DEFUN (GET-CLASS-OR-WARN CLASS) ((NAME STRING)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION GET-CLASS-OR-WARN)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "GET-FRAME"
        "STRING"
        "(DEFMETHOD (GET-FRAME LOGIC-OBJECT) ((NAME STRING)) :DOCUMENTATION \"Return the instanced named 'name'.\")")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT METHOD-CODE METHOD)
      (CL:FUNCTION GET-FRAME)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "GET-OWN-SLOT"
        "LOGIC-OBJECT"
        "(DEFMETHOD (GET-OWN-SLOT SLOT) ((SELF LOGIC-OBJECT) (SLOTNAME STRING)) :DOCUMENTATION \"Return the slot named 'slotName' on the instance 'self'.\")")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT METHOD-CODE METHOD)
      (CL:FUNCTION GET-OWN-SLOT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "GET-TEMPLATE-SLOT"
        "CLASS"
        "(DEFMETHOD (GET-TEMPLATE-SLOT SLOT) ((SELF CLASS) (SLOTNAME STRING)) :DOCUMENTATION \"Return the slot named 'slotName' on the class 'self'.\")")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT METHOD-CODE METHOD)
      (CL:FUNCTION GET-TEMPLATE-SLOT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "GET-TEMPLATE-SLOT"
        "STRING"
        "(DEFMETHOD (GET-TEMPLATE-SLOT SLOT) ((SELF STRING) (SLOTNAME STRING)) :DOCUMENTATION \"Return the slot named 'slotName' on the class 'self'.\")")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT METHOD-CODE METHOD)
      (CL:FUNCTION GET-TEMPLATE-SLOT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "GET-SLOT-VALUE"
        "LOGIC-OBJECT"
        "(DEFMETHOD (GET-SLOT-VALUE OBJECT) ((SELF LOGIC-OBJECT) (SLOTNAME STRING)) :DOCUMENTATION \"Get the value of 'slot' on 'self'.\")")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT METHOD-CODE METHOD)
      (CL:FUNCTION GET-SLOT-VALUE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "GET-SLOT-VALUE"
        "STRING"
        "(DEFMETHOD (GET-SLOT-VALUE OBJECT) ((SELF STRING) (SLOTNAME STRING)) :DOCUMENTATION \"Get the value of 'slot' on the instance named 'self'.\")")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT METHOD-CODE METHOD)
      (CL:FUNCTION GET-SLOT-VALUE)))
    (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
     "STARTUP-GFP"
     NULL
     "(DEFUN STARTUP-GFP ())"))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 8) 1)
    (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES)))
  :VOID)
