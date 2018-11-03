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

(CL:DEFVAR KWD-API-ASSERTED NULL)
(CL:DEFVAR SYM-API-LOGIC-STARTUP-API NULL)
(CL:DEFVAR SYM-API-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE*))

;;; (DEFUN ADD-SUPERCLASS ...)

(CL:DEFUN ADD-SUPERCLASS (SUPER CLASS)
  "Add the class named 'super' to the list of
superclasses of 'class'."
  (CL:LET* ((*MODULE* (%HOME-CONTEXT (CLASS-LOGICAL-TYPE CLASS))))
   (CL:DECLARE (CL:SPECIAL *MODULE*))
   (CL:SETQ SUPER (INTERN-DERIVED-SYMBOL SUPER (%SYMBOL-NAME SUPER)))
   (CL:LET*
    ((SOURCETREE
      (READ-S-EXPRESSION-FROM-STRING (%CLASS-STRINGIFIED-SOURCE CLASS)))
     (DIRECTSUPERS (%%VALUE (%%REST (%%REST SOURCETREE)))))
    (CL:WHEN (CL:NOT (MEMBER? DIRECTSUPERS SUPER))
     (THIRD-SETTER SOURCETREE (CONCATENATE DIRECTSUPERS (CONS SUPER NIL)))
     (DEFINE-CLASS-FROM-PARSE-TREE SOURCETREE)
     (FINALIZE-CLASSES-AND-SLOTS)))))

;;; (DEFUN REMOVE-SUPERCLASS ...)

(CL:DEFUN REMOVE-SUPERCLASS (SUPER CLASS)
  "Remove the class named 'super' from the list of
superclasses of 'class'."
  (CL:LET* ((*MODULE* (%HOME-CONTEXT (CLASS-LOGICAL-TYPE CLASS))))
   (CL:DECLARE (CL:SPECIAL *MODULE*))
   (CL:SETQ SUPER (INTERN-DERIVED-SYMBOL SUPER (%SYMBOL-NAME SUPER)))
   (CL:LET*
    ((SOURCETREE
      (READ-S-EXPRESSION-FROM-STRING (%CLASS-STRINGIFIED-SOURCE CLASS)))
     (DIRECTSUPERS (%%VALUE (%%REST (%%REST SOURCETREE)))))
    (CL:WHEN (MEMBER? DIRECTSUPERS SUPER)
     (THIRD-SETTER SOURCETREE (REMOVE DIRECTSUPERS SUPER))
     (DEFINE-CLASS-FROM-PARSE-TREE SOURCETREE)
     (FINALIZE-CLASSES-AND-SLOTS)))))

;;; (DEFUN (COMPUTED? BOOLEAN) ...)

(CL:DEFUN COMPUTED? (SLOT)
  "Return TRUE if 'slot is computed by a STELLA method or
function."
  FALSE)

;;; (DEFUN (READ-ONLY? BOOLEAN) ...)

(CL:DEFUN READ-ONLY? (SLOT)
  "Return TRUE if `slot' is readonly"
  (%SLOT-READ-ONLY? SLOT))

;;; (DEFUN (ASSERTED-INSTANCE-OF-CLASS? BOOLEAN) ...)

(CL:DEFUN ASSERTED-INSTANCE-OF-CLASS? (INSTANCE CLASS)
  "Return TRUE if `instance' has been asserted to be
                  of type `class'"
  (MEMBER? (LOOM-API::GET-TYPES INSTANCE KWD-API-ASSERTED) CLASS))

;;; (DEFUN (LIST-MODULE ALL-PURPOSE-ITERATOR) ...)

(CL:DEFUN LIST-MODULE (MODULE)
  "Return all relations (descriptions) and instances in `module'"
  (CONCATENATE (ALL-NAMED-DESCRIPTIONS MODULE TRUE)
   (ALL-INSTANCES MODULE TRUE)))

;;; (DEFUN (ITERATOR-KEY OBJECT) ...)

(CL:DEFUN ITERATOR-KEY (SELF)
  "Return the current key of `self'"
  (%KEY SELF))

;;; (DEFUN (ITERATOR-VALUE OBJECT) ...)

(CL:DEFUN ITERATOR-VALUE (SELF)
  "Return the current value of `self'"
  (%VALUE SELF))

;;; (DEFUN (NEXTP LISP-CODE) ...)

(CL:DEFUN NEXTP (ITERATOR)
  "Return corresponding Lisp value of (next? `iterator')"
  (TRUE-P (NEXT? ITERATOR)))

;;; (DEFSPECIAL *SELECTED-MODULES* ...)

(CL:DEFVAR *SELECTED-MODULES* NULL
  "API functions filter out any objects whose home-context is
not mentioned in this list.  If it is NULL or an empty list all modules 
will be considered.")

;;; (DEFUN SELECT-MODULE ...)

(CL:DEFUN SELECT-MODULE (MODULE LOCAL?)
  "Add 'module' to the list of selected modules.  
If 'local?' is FALSE also select all modules visible from 'module'."
  (CL:WHEN (NULL-LIST? *SELECTED-MODULES*)
   (CL:SETQ *SELECTED-MODULES* (NEW-LIST)))
  (CL:IF LOCAL?
   (CL:WHEN (CL:NOT (MEMBER? *SELECTED-MODULES* MODULE))
    (INSERT-LAST *SELECTED-MODULES* MODULE))
   (CL:LET*
    ((MOD NULL) (ITER-000 (VISIBLE-MODULES MODULE)) (COLLECT-000 NULL))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ MOD (%VALUE ITER-000))
     (CL:WHEN (CL:NOT (MEMBER? *SELECTED-MODULES* MOD))
      (CL:IF (CL:EQ COLLECT-000 NULL)
       (CL:PROGN (CL:SETQ COLLECT-000 (CONS MOD NIL))
        (CL:IF (CL:EQ (%THE-CONS-LIST *SELECTED-MODULES*) NIL)
         (CL:SETF (%THE-CONS-LIST *SELECTED-MODULES*) COLLECT-000)
         (ADD-CONS-TO-END-OF-CONS-LIST (%THE-CONS-LIST *SELECTED-MODULES*)
          COLLECT-000)))
       (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS MOD NIL))
        (CL:SETQ COLLECT-000 (%%REST COLLECT-000)))))))))

;;; (DEFUN DESELECT-MODULE ...)

(CL:DEFUN DESELECT-MODULE (MODULE LOCAL?)
  "Remove 'module' from the list of selected modules.  
If 'local?' is FALSE also deselect all modules visible from 'module'."
  (CL:WHEN (DEFINED-LIST? *SELECTED-MODULES*)
   (CL:IF LOCAL? (REMOVE *SELECTED-MODULES* MODULE)
    (CL:LET* ((MOD NULL) (ITER-000 (VISIBLE-MODULES MODULE)))
     (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ MOD (%VALUE ITER-000))
      (REMOVE *SELECTED-MODULES* MOD))))))

;;; (DEFUN SELECT-ALL-MODULES ...)

(CL:DEFUN SELECT-ALL-MODULES ()
  "Select all modules."
  (CL:WHEN (DEFINED-LIST? *SELECTED-MODULES*) (CLEAR *SELECTED-MODULES*)))

;;; (DEFUN (VISIBLE-OBJECT? BOOLEAN) ...)

(CL:DEFUN VISIBLE-OBJECT? (OBJECT)
  "Return TRUE if 'object' is visible with respect to the
set of currently selected modules."
  (CL:IF
   (CL:OR (CL:EQ *SELECTED-MODULES* NULL) (EMPTY? *SELECTED-MODULES*))
   TRUE
   (CL:LET* ((CT (LOOM-API::GET-XCONTEXT OBJECT)))
    (CL:LET* ((FOUND?-000 FALSE))
     (CL:LET*
      ((MODULE NULL) (ITER-000 (%THE-CONS-LIST *SELECTED-MODULES*)))
      (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
       (CL:PROGN (CL:SETQ MODULE (%%VALUE ITER-000))
        (CL:SETQ ITER-000 (%%REST ITER-000)))
       (CL:WHEN (CL:EQ MODULE CT) (CL:SETQ FOUND?-000 TRUE) (CL:RETURN))))
     (CL:LET* ((VALUE-000 FOUND?-000)) VALUE-000)))))

(CL:DEFUN STARTUP-API ()
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE "/LOGIC" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ KWD-API-ASSERTED
     (INTERN-RIGID-SYMBOL-WRT-MODULE "ASSERTED" NULL 2))
    (CL:SETQ SYM-API-LOGIC-STARTUP-API
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-API" NULL 0))
    (CL:SETQ SYM-API-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" TRUE) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ *SELECTED-MODULES* (NEW-LIST)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "ADD-SUPERCLASS"
     "(DEFUN ADD-SUPERCLASS ((SUPER GENERALIZED-SYMBOL) (CLASS CLASS)) :PUBLIC? TRUE :DOCUMENTATION \"Add the class named 'super' to the list of
superclasses of 'class'.\")" (CL:FUNCTION ADD-SUPERCLASS) NULL)
    (DEFINE-FUNCTION-OBJECT "REMOVE-SUPERCLASS"
     "(DEFUN REMOVE-SUPERCLASS ((SUPER GENERALIZED-SYMBOL) (CLASS CLASS)) :PUBLIC? TRUE :DOCUMENTATION \"Remove the class named 'super' from the list of
superclasses of 'class'.\")" (CL:FUNCTION REMOVE-SUPERCLASS) NULL)
    (DEFINE-FUNCTION-OBJECT "COMPUTED?"
     "(DEFUN (COMPUTED? BOOLEAN) ((SLOT SLOT)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if 'slot is computed by a STELLA method or
function.\")" (CL:FUNCTION COMPUTED?) NULL)
    (DEFINE-FUNCTION-OBJECT "READ-ONLY?"
     "(DEFUN (READ-ONLY? BOOLEAN) ((SLOT STORAGE-SLOT)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if `slot' is readonly\")"
     (CL:FUNCTION READ-ONLY?) NULL)
    (DEFINE-FUNCTION-OBJECT "ASSERTED-INSTANCE-OF-CLASS?"
     "(DEFUN (ASSERTED-INSTANCE-OF-CLASS? BOOLEAN) ((INSTANCE LOGIC-OBJECT) (CLASS CLASS)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if `instance' has been asserted to be
                  of type `class'\")"
     (CL:FUNCTION ASSERTED-INSTANCE-OF-CLASS?) NULL)
    (DEFINE-FUNCTION-OBJECT "LIST-MODULE"
     "(DEFUN (LIST-MODULE ALL-PURPOSE-ITERATOR) ((MODULE MODULE)) :PUBLIC? TRUE :DOCUMENTATION \"Return all relations (descriptions) and instances in `module'\")"
     (CL:FUNCTION LIST-MODULE) NULL)
    (DEFINE-FUNCTION-OBJECT "ITERATOR-KEY"
     "(DEFUN (ITERATOR-KEY OBJECT) ((SELF DICTIONARY-ITERATOR)) :PUBLIC? TRUE :DOCUMENTATION \"Return the current key of `self'\")"
     (CL:FUNCTION ITERATOR-KEY) NULL)
    (DEFINE-FUNCTION-OBJECT "ITERATOR-VALUE"
     "(DEFUN (ITERATOR-VALUE OBJECT) ((SELF ITERATOR)) :PUBLIC? TRUE :DOCUMENTATION \"Return the current value of `self'\")"
     (CL:FUNCTION ITERATOR-VALUE) NULL)
    (DEFINE-FUNCTION-OBJECT "NEXTP"
     "(DEFUN (NEXTP LISP-CODE) ((ITERATOR ITERATOR)) :DOCUMENTATION \"Return corresponding Lisp value of (next? `iterator')\")"
     (CL:FUNCTION NEXTP) NULL)
    (DEFINE-FUNCTION-OBJECT "SELECT-MODULE"
     "(DEFUN SELECT-MODULE ((MODULE MODULE) (LOCAL? BOOLEAN)) :PUBLIC? TRUE :DOCUMENTATION \"Add 'module' to the list of selected modules.  
If 'local?' is FALSE also select all modules visible from 'module'.\")"
     (CL:FUNCTION SELECT-MODULE) NULL)
    (DEFINE-FUNCTION-OBJECT "DESELECT-MODULE"
     "(DEFUN DESELECT-MODULE ((MODULE MODULE) (LOCAL? BOOLEAN)) :PUBLIC? TRUE :DOCUMENTATION \"Remove 'module' from the list of selected modules.  
If 'local?' is FALSE also deselect all modules visible from 'module'.\")"
     (CL:FUNCTION DESELECT-MODULE) NULL)
    (DEFINE-FUNCTION-OBJECT "SELECT-ALL-MODULES"
     "(DEFUN SELECT-ALL-MODULES () :PUBLIC? TRUE :DOCUMENTATION \"Select all modules.\")"
     (CL:FUNCTION SELECT-ALL-MODULES) NULL)
    (DEFINE-FUNCTION-OBJECT "VISIBLE-OBJECT?"
     "(DEFUN (VISIBLE-OBJECT? BOOLEAN) ((OBJECT OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if 'object' is visible with respect to the
set of currently selected modules.\")" (CL:FUNCTION VISIBLE-OBJECT?) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-API"
     "(DEFUN STARTUP-API () :PUBLIC? TRUE)" (CL:FUNCTION STARTUP-API)
     NULL)
    (CL:LET* ((FUNCTION (LOOKUP-FUNCTION SYM-API-LOGIC-STARTUP-API)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-API-STELLA-METHOD-STARTUP-CLASSNAME (WRAP-STRING "Startup-Api")
      NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *SELECTED-MODULES* (LIST OF MODULE) (NEW LIST) :PUBLIC? TRUE :DOCUMENTATION \"API functions filter out any objects whose home-context is
not mentioned in this list.  If it is NULL or an empty list all modules 
will be considered.\")"))))
