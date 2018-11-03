;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

#|--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996, 1997             | 
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

(CL:DEFVAR SYM-MORE-DEMONS-INVERSE NULL)
(CL:DEFVAR KWD-MORE-DEMONS-CODE NULL)
(CL:DEFVAR SYM-MORE-DEMONS-SLOT-DEMONS NULL)
(CL:DEFVAR KWD-MORE-DEMONS-DOCUMENTATION NULL)
(CL:DEFVAR KWD-MORE-DEMONS-CREATE NULL)
(CL:DEFVAR KWD-MORE-DEMONS-ALL NULL)
(CL:DEFVAR KWD-MORE-DEMONS-DESTROY NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STELLA-MODULE* *MODULE*))

;;; (DEFUN INVERSE-SLOT-DEMON ...)

(CL:DEFUN INVERSE-SLOT-DEMON (SELF SLOT OLDVALUE NEWVALUE)
  (CL:LET*
   ((INVERSESLOT (DYNAMIC-SLOT-VALUE SLOT SYM-MORE-DEMONS-INVERSE NULL)))
   (CL:WHEN
    (CL:NOT (CL:EQ OLDVALUE NULL))
    (DROP-SLOT-VALUE OLDVALUE INVERSESLOT SELF))
   (CL:WHEN
    (CL:NOT (CL:EQ NEWVALUE NULL))
    (PUT-SLOT-VALUE NEWVALUE INVERSESLOT SELF)))
  :VOID)

;;; (DEFUN ATTACH-INVERSE-SLOT-DEMON ...)

(CL:DEFUN ATTACH-INVERSE-SLOT-DEMON (SLOT)
  (CL:LET*
   ((SLOT-001 SLOT))
   (CL:COND
    ((CL:EQ (STORAGE-SLOT? SLOT) 1)
     (CL:LET*
      ((SLOT NULL))
      (CL:SETQ SLOT SLOT-001)
      (CL:LET*
       ((INVERSEDEMON (LOOKUP-DEMON "inverse-slot-demon")))
       (PUSH
        (CLSYS-SVAL DEMON DEMON-CLASS-REFS INVERSEDEMON)
        (CLSYS-SVAL STORAGE-SLOT SLOT-OWNER SLOT))
       (PUSH
        (CLSYS-SVAL DEMON DEMON-SLOT-REFS INVERSEDEMON)
        (CLSYS-SVAL STORAGE-SLOT SLOT-NAME SLOT))
       (SET-DYNAMIC-SLOT-VALUE
        SLOT
        SYM-MORE-DEMONS-SLOT-DEMONS
        (INJECT-DEMON (SLOT-DEMONS SLOT) INVERSEDEMON)
        NULL))))
    (CL:T (CL:RETURN-FROM ATTACH-INVERSE-SLOT-DEMON))))
  :VOID)

;;; (DEFUN CLASS-EXTENSION-CONSTRUCTOR-DEMON ...)

(CL:DEFUN CLASS-EXTENSION-CONSTRUCTOR-DEMON (SELF CLASS)
  (CL:LET*
   ((EXTENSION (EXTENSION CLASS)))
   (CL:WHEN (CL:NOT (CL:EQ EXTENSION NULL)) (INSERT EXTENSION SELF)))
  :VOID)

;;; (DEFUN CLASS-EXTENSION-DESTRUCTOR-DEMON ...)

(CL:DEFUN CLASS-EXTENSION-DESTRUCTOR-DEMON (SELF CLASS)
  (CL:LET*
   ((EXTENSION (EXTENSION CLASS)))
   (CL:WHEN (CL:NOT (CL:EQ EXTENSION NULL)) (REMOVE EXTENSION SELF)))
  :VOID)

(CL:DEFUN STARTUP-MORE-DEMONS ()
  (CL:LET*
   ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 2) 1)
    (CL:SETQ
     SYM-MORE-DEMONS-INVERSE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "INVERSE" NULL 0))
    (CL:SETQ
     KWD-MORE-DEMONS-CODE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CODE" NULL 2))
    (CL:SETQ
     SYM-MORE-DEMONS-SLOT-DEMONS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SLOT-DEMONS" NULL 0))
    (CL:SETQ
     KWD-MORE-DEMONS-DOCUMENTATION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DOCUMENTATION" NULL 2))
    (CL:SETQ
     KWD-MORE-DEMONS-CREATE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CREATE" NULL 2))
    (CL:SETQ
     KWD-MORE-DEMONS-ALL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "ALL" NULL 2))
    (CL:SETQ
     KWD-MORE-DEMONS-DESTROY
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DESTROY" NULL 2)))
   (CL:WHEN (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 6) 1) (FINALIZE-CLASSES))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 7) 1)
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "INVERSE-SLOT-DEMON"
        "STANDARD-OBJECT"
        "(DEFUN INVERSE-SLOT-DEMON ((SELF STANDARD-OBJECT) (SLOT STORAGE-SLOT) (OLDVALUE STANDARD-OBJECT) (NEWVALUE STANDARD-OBJECT)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION INVERSE-SLOT-DEMON)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "ATTACH-INVERSE-SLOT-DEMON"
        "SLOT"
        "(DEFUN ATTACH-INVERSE-SLOT-DEMON ((SLOT SLOT)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION ATTACH-INVERSE-SLOT-DEMON)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "CLASS-EXTENSION-CONSTRUCTOR-DEMON"
        "ACTIVE-OBJECT"
        "(DEFUN CLASS-EXTENSION-CONSTRUCTOR-DEMON ((SELF ACTIVE-OBJECT) (CLASS CLASS)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION CLASS-EXTENSION-CONSTRUCTOR-DEMON)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "CLASS-EXTENSION-DESTRUCTOR-DEMON"
        "ACTIVE-OBJECT"
        "(DEFUN CLASS-EXTENSION-DESTRUCTOR-DEMON ((SELF ACTIVE-OBJECT) (CLASS CLASS)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION CLASS-EXTENSION-DESTRUCTOR-DEMON)))
    (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
     "STARTUP-MORE-DEMONS"
     NULL
     "(DEFUN STARTUP-MORE-DEMONS ())"))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 8) 1)
    (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 9) 1)
    (DEFINE-DEMON
     "inverse-slot-demon"
     KWD-MORE-DEMONS-CODE
     (WRAP-LITERAL (CL:FUNCTION INVERSE-SLOT-DEMON)))
    (DEFINE-DEMON
     "class-extension-constructor-demon"
     KWD-MORE-DEMONS-DOCUMENTATION
     (WRAP-LITERAL
      "Demon that inserts the instance 'self' into the extension of
the class 'class'.")
     KWD-MORE-DEMONS-CREATE
     KWD-MORE-DEMONS-ALL
     KWD-MORE-DEMONS-CODE
     (WRAP-LITERAL (CL:FUNCTION CLASS-EXTENSION-CONSTRUCTOR-DEMON)))
    (DEFINE-DEMON
     "class-extension-destructor-demon"
     KWD-MORE-DEMONS-DOCUMENTATION
     (WRAP-LITERAL
      "Demon that removes the instance 'self' from the extension of
the class 'class'.  Removal removes the instance forever.  Deletion without
removal can be achieved in constant time by setting 'deleted?' on 'self'.")
     KWD-MORE-DEMONS-DESTROY
     KWD-MORE-DEMONS-ALL
     KWD-MORE-DEMONS-CODE
     (WRAP-LITERAL (CL:FUNCTION CLASS-EXTENSION-DESTRUCTOR-DEMON)))
    (CL:LET*
     ((CREATEDEMON (LOOKUP-DEMON "class-extension-constructor-demon"))
      (DESTROYDEMON (LOOKUP-DEMON "class-extension-destructor-demon")))
     (ACTIVATE-DEMON CREATEDEMON)
     (ACTIVATE-DEMON DESTROYDEMON))))
  :VOID)
