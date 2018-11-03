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

(CL:DEFVAR SGT-API-SUPPORT-LOGIC-LOGIC-OBJECT NULL)
(CL:DEFVAR SGT-API-SUPPORT-LOGIC-PATTERN-VARIABLE NULL)
(CL:DEFVAR SGT-API-SUPPORT-LOGIC-SKOLEM NULL)
(CL:DEFVAR SGT-API-SUPPORT-STELLA-THING NULL)
(CL:DEFVAR SGT-API-SUPPORT-LOGIC-DESCRIPTION NULL)
(CL:DEFVAR SYM-API-SUPPORT-LOGIC-STARTUP-API-SUPPORT NULL)
(CL:DEFVAR SYM-API-SUPPORT-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE* *SURROGATE-ARRAY*))

;;; (DEFUN (CLASS-NAMES-NEXT? BOOLEAN) ...)

(CL:DEFUN CLASS-NAMES-NEXT? (SELF)
  (CL:WHEN (%FIRST-ITERATION? SELF)
   (CL:SETF (%FIRST-ITERATION? SELF) FALSE)
   (CL:SETF (%VALUE SELF) (%CLASS-TYPE (%ITERATOR-OBJECT SELF)))
   (CL:RETURN-FROM CLASS-NAMES-NEXT? TRUE))
  (CL:LET* ((NEXT? (NEXT? (%ITERATOR-NESTED-ITERATOR SELF))))
   (CL:WHEN NEXT?
    (CL:SETF (%VALUE SELF) (%VALUE (%ITERATOR-NESTED-ITERATOR SELF))))
   NEXT?))

;;; (DEFUN (ALL-PROPOSITIONS-NEXT? BOOLEAN) ...)

(CL:DEFUN ALL-PROPOSITIONS-NEXT? (SELF)
  (CL:LOOP
   (CL:LET* ((ITERATOR (%ITERATOR-NESTED-ITERATOR SELF)) (MODULE NULL))
    (CL:WHEN (NEXT? ITERATOR) (CL:SETF (%VALUE SELF) (%VALUE ITERATOR))
     (CL:RETURN-FROM ALL-PROPOSITIONS-NEXT? TRUE))
    (CL:SETQ MODULE (POP (%ITERATOR-OBJECT SELF)))
    (CL:WHEN (CL:EQ MODULE NULL) (CL:SETF (%VALUE SELF) NULL)
     (CL:RETURN-FROM ALL-PROPOSITIONS-NEXT? FALSE))
    (CL:SETF (%ITERATOR-NESTED-ITERATOR SELF)
     (ALLOCATE-ITERATOR (LOCALLY-CONCEIVED-PROPOSITIONS MODULE))))))

;;; (DEFUN (ALL-PROPOSITIONS (ITERATOR OF PROPOSITION)) ...)

(CL:DEFUN ALL-PROPOSITIONS (MODULE LOCAL?)
  "Iterate over all conceived propositions visible from `module'.
Only propositions that haven't been deleted will be considered.
If `local?', only return propositions conceived locally in `module'."
  (CL:LET* ((SELF-000 (NEW-ALL-PURPOSE-ITERATOR)))
   (CL:SETF (%ITERATOR-OBJECT SELF-000)
    (CL:IF LOCAL? (LIST MODULE)
     (REVERSE (LISTIFY (VISIBLE-MODULES MODULE)))))
   (CL:SETF (%ITERATOR-NESTED-ITERATOR SELF-000)
    (ALLOCATE-ITERATOR (LOCALLY-CONCEIVED-PROPOSITIONS MODULE)))
   (CL:SETF (%ITERATOR-NEXT-CODE SELF-000)
    (CL:FUNCTION ALL-PROPOSITIONS-NEXT?))
   (CL:LET* ((VALUE-000 SELF-000)) VALUE-000)))

;;; (DEFUN (VISIBLE-TERM? BOOLEAN) ...)

(CL:DEFUN VISIBLE-TERM? (TERM CONTEXT LOCAL?)
  (CL:IF LOCAL? (CL:EQ (%HOME-CONTEXT TERM) CONTEXT)
   (VISIBLE-FROM? (%HOME-CONTEXT TERM) CONTEXT)))

;;; (DEFUN (ALL-UNNAMED-TERMS ITERATOR) ...)

(CL:DEFUN ALL-UNNAMED-TERMS (MODULE LOCAL?)
  "Iterate over all unnamed terms visible from `module'.  A term can be
an instance (or individual) as well as a description.  Only terms that
haven't been deleted will be considered.  If `local?', only return
terms created locally in `module'."
  (CL:LET*
   ((TERMS NIL) (TERMSWITHDUPLICATES NIL) (VALUE NULL) (TERM NULL))
   (CL:LET*
    ((PROPOSITION NULL) (ITER-000 (ALL-PROPOSITIONS MODULE LOCAL?)))
    (CL:LOOP WHILE (NEXT? ITER-000) DO
     (CL:SETQ PROPOSITION (%VALUE ITER-000))
     (CL:TAGBODY
      (CL:LET*
       ((ARG NULL) (VECTOR-000 (%ARGUMENTS PROPOSITION)) (INDEX-000 0)
        (LENGTH-000 (LENGTH VECTOR-000)))
       (CL:DECLARE (CL:TYPE CL:FIXNUM INDEX-000 LENGTH-000))
       (CL:LOOP WHILE (CL:< INDEX-000 LENGTH-000) DO
        (CL:PROGN
         (CL:SETQ ARG
          (CL:AREF (CL:THE CL:SIMPLE-VECTOR (%THE-ARRAY VECTOR-000))
           INDEX-000))
         (CL:SETQ INDEX-000 (CL:1+ INDEX-000)))
        (CL:TAGBODY
         (CL:WHEN
          (CL:AND (CL:NOT (CL:EQ ARG NULL))
           (ISA? ARG SGT-API-SUPPORT-LOGIC-LOGIC-OBJECT)
           (CL:NOT (DELETED? ARG)))
          (CL:SETQ TERM ARG)
          (CL:WHEN
           (CL:OR (CL:NOT (VISIBLE-TERM? TERM MODULE LOCAL?))
            (CL:NOT (CL:EQ (%SURROGATE-VALUE-INVERSE TERM) NULL)))
           (CL:GO :CONTINUE))
          (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE TERM)))
           (CL:COND
            ((SUBTYPE-OF? TEST-VALUE-000
              SGT-API-SUPPORT-LOGIC-PATTERN-VARIABLE)
             (CL:PROGN))
            ((SUBTYPE-OF? TEST-VALUE-000 SGT-API-SUPPORT-LOGIC-SKOLEM)
             (CL:PROGN
              (CL:IF (CL:NOT (CL:EQ (%DEFINING-PROPOSITION TERM) NULL))
               (CL:WHEN (CL:EQ (%DEFINING-PROPOSITION TERM) PROPOSITION)
                (CL:SETQ TERMS (CONS TERM TERMS)))
               (CL:SETQ TERMSWITHDUPLICATES
                (CONS TERM TERMSWITHDUPLICATES)))))
            (CL:T
             (CL:SETQ TERMSWITHDUPLICATES
              (CONS TERM TERMSWITHDUPLICATES))))))
         :CONTINUE)))
      :CONTINUE)))
   (CL:LET* ((SELF-000 (NEW-LIST)))
    (CL:SETF (%THE-CONS-LIST SELF-000)
     (REMOVE-DUPLICATES TERMSWITHDUPLICATES))
    (CL:LET* ((VALUE-000 (ALLOCATE-DESTRUCTIVE-LIST-ITERATOR SELF-000)))
     VALUE-000))))

;;; (DEFUN (ALL-NAMED-TERMS-NEXT? BOOLEAN) ...)

(CL:DEFUN ALL-NAMED-TERMS-NEXT? (SELF)
  (CL:LET*
   ((CURSOR (%ITERATOR-INTEGER SELF)) (MODULES (%ITERATOR-CONS-LIST SELF))
    (SURROGATE NULL) (VALUE NULL))
   (CL:DECLARE (CL:TYPE CL:FIXNUM CURSOR))
   (CL:LET* ((*SUPPRESSNONLOGICOBJECTWARNING?* TRUE))
    (CL:DECLARE (CL:SPECIAL *SUPPRESSNONLOGICOBJECTWARNING?*))
    (CL:LOOP WHILE (CL:< CURSOR (%ITERATOR-SECOND-INTEGER SELF)) DO
     (CL:SETQ SURROGATE
      (CL:AREF (CL:THE CL:SIMPLE-VECTOR (%THE-ARRAY *SURROGATE-ARRAY*))
       CURSOR))
     (CL:WHEN
      (CL:AND (CL:NOT (CL:EQ SURROGATE NULL))
       (MEMBER? MODULES (%HOME-CONTEXT SURROGATE))
       (CL:NOT (CL:EQ (%SURROGATE-VALUE SURROGATE) NULL)))
      (CL:SETQ VALUE (VALUE-OF SURROGATE))
      (CL:WHEN (CL:NOT (CL:EQ VALUE NULL))
       (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE VALUE)))
        (CL:COND
         ((SUBTYPE-OF? TEST-VALUE-000 SGT-API-SUPPORT-LOGIC-LOGIC-OBJECT)
          (CL:PROGN
           (CL:WHEN
            (CL:OR (DELETED? VALUE)
             (CL:NOT (MEMBER? MODULES (%HOME-CONTEXT VALUE))))
            (CL:SETQ VALUE NULL))))
         ((SUBTYPE-OF? TEST-VALUE-000 SGT-API-SUPPORT-STELLA-THING)
          (CL:PROGN (CL:WHEN (DELETED? VALUE) (CL:SETQ VALUE NULL))))
         (CL:T (CL:SETQ VALUE NULL)))))
      (CL:WHEN (CL:NOT (CL:EQ VALUE NULL)) (CL:SETF (%VALUE SELF) VALUE)
       (CL:SETF (%ITERATOR-INTEGER SELF) (CL:1+ CURSOR))
       (CL:RETURN-FROM ALL-NAMED-TERMS-NEXT? TRUE)))
     (CL:SETQ CURSOR (CL:1+ CURSOR)))
    FALSE)))

;;; (DEFUN (ALL-NAMED-TERMS (ITERATOR OF OBJECT)) ...)

(CL:DEFUN ALL-NAMED-TERMS (MODULE LOCAL?)
  "Iterate over all named terms visible from `module'.  A term can be an
instance (or individual) as well as a description.  Only terms that
haven't been deleted will be considered.  If `local?', only return 
terms created locally in `module'."
  (ALLOCATE-ALL-META-OBJECTS-ITERATOR
   (CL:1+ (%TOP-SYMBOL-OFFSET *SURROGATE-ARRAY*))
   (CL:FUNCTION ALL-NAMED-TERMS-NEXT?) MODULE LOCAL?))

;;; (DEFUN (ALL-TERMS (ITERATOR OF OBJECT)) ...)

(CL:DEFUN ALL-TERMS (MODULE LOCAL?)
  "Return a list of all terms visible from `module'.  A term can be an
instance (or individual) as well as a description.  Only terms that
haven't been deleted will be considered.  If `local?', only return 
terms created locally in `module'."
  (CL:IF LOCAL?
   (CL:PROGN (REMOVE-DELETED-MEMBERS (LOCALLY-CONCEIVED-INSTANCES MODULE))
    (ALLOCATE-ITERATOR (LOCALLY-CONCEIVED-INSTANCES MODULE)))
   (CONCATENATE (ALL-NAMED-TERMS MODULE FALSE)
    (ALL-UNNAMED-TERMS MODULE FALSE))))

;;; (DEFUN (FILTER-INSTANCE? BOOLEAN) ...)

(CL:DEFUN FILTER-INSTANCE? (SELF ITERATOR)
  (CL:SETQ ITERATOR ITERATOR)
  (CL:NOT (ISA? SELF SGT-API-SUPPORT-LOGIC-DESCRIPTION)))

;;; (DEFUN (ALL-NAMED-INSTANCES (ITERATOR OF LOGIC-OBJECT)) ...)

(CL:DEFUN ALL-NAMED-INSTANCES (MODULE LOCAL?)
  "Iterate over all named instances (or individuals) visible from `module'.
Only instances that haven't been deleted will be considered.  If `local?',
only return instances created locally in `module'."
  (CL:LET* ((SELF-000 (NEW-ALL-PURPOSE-ITERATOR)))
   (CL:SETF (%ITERATOR-NESTED-ITERATOR SELF-000)
    (ALL-NAMED-TERMS MODULE LOCAL?))
   (CL:SETF (%ITERATOR-NEXT-CODE SELF-000)
    (CL:FUNCTION FILTERED-NESTED-ITERATOR-NEXT?))
   (CL:SETF (%ITERATOR-FILTER-CODE SELF-000)
    (CL:FUNCTION FILTER-INSTANCE?))
   (CL:LET* ((VALUE-000 SELF-000)) VALUE-000)))

;;; (DEFUN (ALL-INSTANCES (ITERATOR OF LOGIC-OBJECT)) ...)

(CL:DEFUN ALL-INSTANCES (MODULE LOCAL?)
  "Iterate over all instances (or individuals) visible from `module'.
Only instances that haven't been deleted will be considered.  If `local?',
only return instances created locally in `module'."
  (CL:LET*
   ((ITERATOR (ALL-TERMS MODULE LOCAL?)) (ALLPURPOSEITERATOR NULL))
   (CL:IF LOCAL?
    (CL:LET* ((SELF-000 (NEW-ALL-PURPOSE-ITERATOR)))
     (CL:SETF (%ITERATOR-NESTED-ITERATOR SELF-000) ITERATOR)
     (CL:SETF (%ITERATOR-NEXT-CODE SELF-000)
      (CL:FUNCTION FILTERED-NESTED-ITERATOR-NEXT?))
     (CL:SETQ ALLPURPOSEITERATOR SELF-000))
    (CL:SETQ ALLPURPOSEITERATOR ITERATOR))
   (CL:SETF (%ITERATOR-FILTER-CODE ALLPURPOSEITERATOR)
    (CL:FUNCTION FILTER-INSTANCE?))
   ALLPURPOSEITERATOR))

;;; (DEFUN (STRING-TO-LOGIC-OBJECT LOGIC-OBJECT) ...)

(CL:DEFUN STRING-TO-LOGIC-OBJECT (STRING)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  (CL:LET* ((SGT NULL) (ITER-000 (ALL-SURROGATES NULL FALSE)))
   (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ SGT (%VALUE ITER-000))
    (CL:WHEN
     (CL:AND (STRING-EQL? (%SYMBOL-NAME SGT) STRING)
      (CL:NOT (CL:EQ (%SURROGATE-VALUE SGT) NULL))
      (ISA? (%SURROGATE-VALUE SGT) SGT-API-SUPPORT-LOGIC-LOGIC-OBJECT))
     (CL:RETURN-FROM STRING-TO-LOGIC-OBJECT (%SURROGATE-VALUE SGT)))))
  NULL)

(CL:DEFUN STARTUP-API-SUPPORT ()
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE "/LOGIC" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ SGT-API-SUPPORT-LOGIC-LOGIC-OBJECT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "LOGIC-OBJECT" NULL 1))
    (CL:SETQ SGT-API-SUPPORT-LOGIC-PATTERN-VARIABLE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "PATTERN-VARIABLE" NULL 1))
    (CL:SETQ SGT-API-SUPPORT-LOGIC-SKOLEM
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SKOLEM" NULL 1))
    (CL:SETQ SGT-API-SUPPORT-STELLA-THING
     (INTERN-RIGID-SYMBOL-WRT-MODULE "THING"
      (GET-STELLA-MODULE "/STELLA" TRUE) 1))
    (CL:SETQ SGT-API-SUPPORT-LOGIC-DESCRIPTION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DESCRIPTION" NULL 1))
    (CL:SETQ SYM-API-SUPPORT-LOGIC-STARTUP-API-SUPPORT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-API-SUPPORT" NULL 0))
    (CL:SETQ SYM-API-SUPPORT-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" TRUE) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "CLASS-NAMES-NEXT?"
     "(DEFUN (CLASS-NAMES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))"
     (CL:FUNCTION CLASS-NAMES-NEXT?) NULL)
    (DEFINE-FUNCTION-OBJECT "ALL-PROPOSITIONS-NEXT?"
     "(DEFUN (ALL-PROPOSITIONS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))"
     (CL:FUNCTION ALL-PROPOSITIONS-NEXT?) NULL)
    (DEFINE-FUNCTION-OBJECT "ALL-PROPOSITIONS"
     "(DEFUN (ALL-PROPOSITIONS (ITERATOR OF PROPOSITION)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all conceived propositions visible from `module'.
Only propositions that haven't been deleted will be considered.
If `local?', only return propositions conceived locally in `module'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION ALL-PROPOSITIONS) NULL)
    (DEFINE-FUNCTION-OBJECT "VISIBLE-TERM?"
     "(DEFUN (VISIBLE-TERM? BOOLEAN) ((TERM LOGIC-OBJECT) (CONTEXT CONTEXT) (LOCAL? BOOLEAN)))"
     (CL:FUNCTION VISIBLE-TERM?) NULL)
    (DEFINE-FUNCTION-OBJECT "ALL-UNNAMED-TERMS"
     "(DEFUN (ALL-UNNAMED-TERMS ITERATOR) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all unnamed terms visible from `module'.  A term can be
an instance (or individual) as well as a description.  Only terms that
haven't been deleted will be considered.  If `local?', only return
terms created locally in `module'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION ALL-UNNAMED-TERMS) NULL)
    (DEFINE-FUNCTION-OBJECT "ALL-NAMED-TERMS-NEXT?"
     "(DEFUN (ALL-NAMED-TERMS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))"
     (CL:FUNCTION ALL-NAMED-TERMS-NEXT?) NULL)
    (DEFINE-FUNCTION-OBJECT "ALL-NAMED-TERMS"
     "(DEFUN (ALL-NAMED-TERMS (ITERATOR OF OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all named terms visible from `module'.  A term can be an
instance (or individual) as well as a description.  Only terms that
haven't been deleted will be considered.  If `local?', only return 
terms created locally in `module'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION ALL-NAMED-TERMS) NULL)
    (DEFINE-FUNCTION-OBJECT "ALL-TERMS"
     "(DEFUN (ALL-TERMS (ITERATOR OF OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Return a list of all terms visible from `module'.  A term can be an
instance (or individual) as well as a description.  Only terms that
haven't been deleted will be considered.  If `local?', only return 
terms created locally in `module'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION ALL-TERMS) NULL)
    (DEFINE-FUNCTION-OBJECT "FILTER-INSTANCE?"
     "(DEFUN (FILTER-INSTANCE? BOOLEAN) ((SELF LOGIC-OBJECT) (ITERATOR ALL-PURPOSE-ITERATOR)))"
     (CL:FUNCTION FILTER-INSTANCE?) NULL)
    (DEFINE-FUNCTION-OBJECT "ALL-NAMED-INSTANCES"
     "(DEFUN (ALL-NAMED-INSTANCES (ITERATOR OF LOGIC-OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all named instances (or individuals) visible from `module'.
Only instances that haven't been deleted will be considered.  If `local?',
only return instances created locally in `module'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION ALL-NAMED-INSTANCES) NULL)
    (DEFINE-FUNCTION-OBJECT "ALL-INSTANCES"
     "(DEFUN (ALL-INSTANCES (ITERATOR OF LOGIC-OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all instances (or individuals) visible from `module'.
Only instances that haven't been deleted will be considered.  If `local?',
only return instances created locally in `module'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION ALL-INSTANCES) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-TO-LOGIC-OBJECT"
     "(DEFUN (STRING-TO-LOGIC-OBJECT LOGIC-OBJECT) ((STRING STRING)))"
     (CL:FUNCTION STRING-TO-LOGIC-OBJECT) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-API-SUPPORT"
     "(DEFUN STARTUP-API-SUPPORT () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-API-SUPPORT) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION SYM-API-SUPPORT-LOGIC-STARTUP-API-SUPPORT)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-API-SUPPORT-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "Startup-Api-Support") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (INSERT-AT *STRING-TO-OBJECT-FUNCTIONS*
     SGT-API-SUPPORT-LOGIC-LOGIC-OBJECT
     (WRAP-FUNCTION-CODE (CL:FUNCTION STRING-TO-LOGIC-OBJECT))))))
