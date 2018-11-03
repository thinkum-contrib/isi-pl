;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

#|--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997-2000              | 
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

(CL:DEFVAR |SYM-STRING-API-CASE-SENSITIVE-API-NAME| NULL)
(CL:DEFVAR |SYM-STRING-API-CASE-SENSITIVE-API-STARTUP-STRING-API| NULL)
(CL:DEFVAR |SYM-STRING-API-STELLA-METHOD-STARTUP-CLASSNAME| NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE*))

;;; (DEFUN (getInstance OBJECT) ...)

(CL:DEFUN |getInstance| (name)
  "Return an instance named 'name'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING name))
  (GET-INSTANCE (WRAP-STRING name)))

;;; (DEFUN (getTerm OBJECT) ...)

(CL:DEFUN |getTerm| (name)
  "Return a logic term named 'name'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING name))
  (GET-INSTANCE (WRAP-STRING name)))

;;; (DEFUN (gi OBJECT) ...)

(CL:DEFUN |gi| (name)
  "Return an instance named 'name'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING name))
  (GET-INSTANCE (WRAP-STRING name)))

;;; (DEFUN (getClass LOGIC-OBJECT) ...)

(CL:DEFUN |getClass| (name)
  "Return a class/concept named 'name'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING name))
  (GET-CLASS (WRAP-STRING name)))

;;; (DEFUN (getConcept LOGIC-OBJECT) ...)

(CL:DEFUN |getConcept| (name)
  "Return a class/concept named 'name'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING name))
  (GET-CLASS (WRAP-STRING name)))

;;; (DEFUN (getRelation LOGIC-OBJECT) ...)

(CL:DEFUN |getRelation| (name)
  "Return a relation named 'name'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING name))
  (GET-RELATION (WRAP-STRING name)))

;;; (DEFUN (getRules (CONS OF PROPOSITION)) ...)

(CL:DEFUN |getRules| (name)
  "Return a list of rules attached to the class/relation
named 'name'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING name))
  (%GET-RULES |SYM-STRING-API-CASE-SENSITIVE-API-NAME|))

;;; (DEFUN printRules ...)

(CL:DEFUN |printRules| (name)
  "Print a list of rules attached to the class/relation
named 'name'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING name))
  (%PRINT-RULES |SYM-STRING-API-CASE-SENSITIVE-API-NAME|))

;;; (DEFUN (relationName STRING) ...)

(CL:DEFUN |relationName| (self)
  "Given a relation object, return it's name."
  (%SYMBOL-NAME (%SURROGATE-VALUE-INVERSE self)))

(CL:DEFUN |STARTUP-STRING-API| ()
  (CL:LET*
   ((*MODULE*
     (GET-STELLA-MODULE "/LOGIC/CASE-SENSITIVE-API"
      (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ |SYM-STRING-API-CASE-SENSITIVE-API-NAME|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "name" NULL 0))
    (CL:SETQ |SYM-STRING-API-CASE-SENSITIVE-API-STARTUP-STRING-API|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-STRING-API" NULL 0))
    (CL:SETQ |SYM-STRING-API-STELLA-METHOD-STARTUP-CLASSNAME|
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" TRUE) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "getInstance"
     "(DEFUN (getInstance OBJECT) ((name STRING)) :DOCUMENTATION \"Return an instance named 'name'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION |getInstance|) NULL)
    (DEFINE-FUNCTION-OBJECT "getTerm"
     "(DEFUN (getTerm OBJECT) ((name STRING)) :DOCUMENTATION \"Return a logic term named 'name'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION |getTerm|) NULL)
    (DEFINE-FUNCTION-OBJECT "gi"
     "(DEFUN (gi OBJECT) ((name STRING)) :DOCUMENTATION \"Return an instance named 'name'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION |gi|) NULL)
    (DEFINE-FUNCTION-OBJECT "getClass"
     "(DEFUN (getClass LOGIC-OBJECT) ((name STRING)) :DOCUMENTATION \"Return a class/concept named 'name'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION |getClass|) NULL)
    (DEFINE-FUNCTION-OBJECT "getConcept"
     "(DEFUN (getConcept LOGIC-OBJECT) ((name STRING)) :DOCUMENTATION \"Return a class/concept named 'name'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION |getConcept|) NULL)
    (DEFINE-FUNCTION-OBJECT "getRelation"
     "(DEFUN (getRelation LOGIC-OBJECT) ((name STRING)) :DOCUMENTATION \"Return a relation named 'name'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION |getRelation|) NULL)
    (DEFINE-FUNCTION-OBJECT "getRules"
     "(DEFUN (getRules (CONS OF PROPOSITION)) ((name STRING)) :DOCUMENTATION \"Return a list of rules attached to the class/relation
named 'name'.\" :PUBLIC? TRUE)" (CL:FUNCTION |getRules|) NULL)
    (DEFINE-FUNCTION-OBJECT "printRules"
     "(DEFUN printRules ((name STRING)) :DOCUMENTATION \"Print a list of rules attached to the class/relation
named 'name'.\" :PUBLIC? TRUE)" (CL:FUNCTION |printRules|) NULL)
    (DEFINE-FUNCTION-OBJECT "relationName"
     "(DEFUN (relationName STRING) ((self NAMED-DESCRIPTION)) :DOCUMENTATION \"Given a relation object, return it's name.\")"
     (CL:FUNCTION |relationName|) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-STRING-API"
     "(DEFUN STARTUP-STRING-API () :PUBLIC? TRUE)"
     (CL:FUNCTION |STARTUP-STRING-API|) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION
        |SYM-STRING-API-CASE-SENSITIVE-API-STARTUP-STRING-API|)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      |SYM-STRING-API-STELLA-METHOD-STARTUP-CLASSNAME|
      (WRAP-STRING "Startup-String-Api") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))))
