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

(CL:DEFVAR SGT-CONTEXTS-CS-VALUE NULL)
(CL:DEFVAR SYM-CONTEXTS-CC NULL)
(CL:DEFVAR KWD-CONTEXTS-COMMON-LISP NULL)
(CL:DEFVAR KWD-CONTEXTS-FUNCTION NULL)
(CL:DEFVAR SYM-CONTEXTS-EVALUATOR-WRAPPER-CODE NULL)
(CL:DEFVAR SGT-CONTEXTS-MODULE NULL)
(CL:DEFVAR SGT-CONTEXTS-WORLD NULL)
(CL:DEFVAR SYM-CONTEXTS-WORLD-NAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL
  *STELLA-MODULE*
  *MODULE*
  *CLASS-HIERARCHY-BOOTED?*
  NULL-STRING-WRAPPER
  *CONTEXT*
  STANDARD-OUTPUT
  EOL
  *ROOT-MODULE*))

;;; (DEFGLOBAL *UNLINK-DISCARDED-CONTEXTS-ON-READ?* ...)

(CL:DEFVAR *UNLINK-DISCARDED-CONTEXTS-ON-READ?* TRUE
  "Eliminate pointers to discarded contexts while
accessing a CS-VALUE context table.")

;;; (DEFGLOBAL *UNLINK-DISCARDED-CONTEXTS-ON-WRITE?* ...)

(CL:DEFVAR *UNLINK-DISCARDED-CONTEXTS-ON-WRITE?* TRUE
  "Eliminate pointers to discarded contexts while
inserting into a CS-VALUE context table.")

;;; (DEFGLOBAL *CONTEXT-BACKTRACKING-MODE* ...)

(CL:DEFVAR *CONTEXT-BACKTRACKING-MODE* FALSE
  "If true, indicates that contexts are being allocated
and deallocated in depth-first fashion, and that deallocation of
CS-VALUE entries is taken care of during context destruction.")

;;; (DEFUN (CS-VALUE? BOOLEAN) ...)

(CL:DEFUN CS-VALUE? (SELF)
  (CL:RETURN-FROM
   CS-VALUE?
   (CL:IF
    (CL:AND
     (CL:NOT (CL:EQ SELF NULL))
     (CL:EQ (PRIMARY-TYPE SELF) SGT-CONTEXTS-CS-VALUE))
    TRUE
    FALSE))
  :VOID)

;;; (DEFUN (SUBCONTEXT? BOOLEAN) ...)

(CL:DEFUN SUBCONTEXT? (SUBCONTEXT SUPERCONTEXT)
  (CL:RETURN-FROM
   SUBCONTEXT?
   (CL:IF
    (CL:OR
     (CL:EQ SUBCONTEXT SUPERCONTEXT)
     (CL:EQ
      (MEMBER?
       (CLSYS-SVAL CONTEXT ALL-SUPER-CONTEXTS SUBCONTEXT)
       SUPERCONTEXT)
      1))
    TRUE
    FALSE))
  :VOID)

;;; (DEFUN (DISCARDED-CONTEXT? BOOLEAN) ...)

(CL:DEFUN DISCARDED-CONTEXT? (CONTEXT)
  (CL:RETURN-FROM
   DISCARDED-CONTEXT?
   (ODD? (CLSYS-SVAL CONTEXT CONTEXT-NUMBER CONTEXT)))
  :VOID)

;;; (DEFUN (HELP-FIND-CONTEXT-BY-NUMBER CONTEXT) ...)

(CL:DEFUN HELP-FIND-CONTEXT-BY-NUMBER (NUMBER SIBLINGS)
  (CL:LET*
   ((C NULL) (ITER-001 (CLSYS-SVAL LIST THE-CONS-LIST SIBLINGS)))
   (CL:LOOP
    WHILE
    (CL:NOT (CL:EQ ITER-001 NIL))
    DO
    (CL:PROGN
     (CL:SETQ C (CLSYS-SVAL CONS VALUE ITER-001))
     (CL:SETQ ITER-001 (CLSYS-SVAL CONS REST ITER-001)))
    (CL:TAGBODY
     (CL:COND
      ((CL:= (CLSYS-SVAL CONTEXT CONTEXT-NUMBER C) NUMBER)
       (CL:RETURN-FROM HELP-FIND-CONTEXT-BY-NUMBER C))
      ((CL:< (CLSYS-SVAL CONTEXT CONTEXT-NUMBER C) NUMBER)
       (CL:RETURN-FROM
        HELP-FIND-CONTEXT-BY-NUMBER
        (HELP-FIND-CONTEXT-BY-NUMBER
         NUMBER
         (CLSYS-SVAL CONTEXT CHILD-CONTEXTS C))))
      (CL:T (CL:GO :CONTINUE)))
     :CONTINUE)))
  (CL:RETURN-FROM HELP-FIND-CONTEXT-BY-NUMBER NULL)
  :VOID)

;;; (DEFUN (FIND-CONTEXT-BY-NUMBER CONTEXT) ...)

(CL:DEFUN FIND-CONTEXT-BY-NUMBER (CONTEXTNUMBER)
  (CL:RETURN-FROM
   FIND-CONTEXT-BY-NUMBER
   (HELP-FIND-CONTEXT-BY-NUMBER
    CONTEXTNUMBER
    (CLSYS-SVAL MODULE CHILD-CONTEXTS *ROOT-MODULE*)))
  :VOID)

;;; (DEFMETHOD (SLOWLY-GET-CONTEXT CONTEXT) ...)

(CL:DEFMETHOD SLOWLY-GET-CONTEXT ((SELF CL:STRING))
  (CL:LET*
   ((CONTEXT (GET-CONTEXT SELF FALSE)))
   (CL:WHEN
    (CL:NOT (CL:EQ CONTEXT NULL))
    (CL:RETURN-FROM SLOWLY-GET-CONTEXT CONTEXT))
   (CL:LET*
    ((CXT NULL)
     (ITER-001
      (CLSYS-SVAL
       LIST
       THE-CONS-LIST
       (CLSYS-SVAL MODULE CHILD-CONTEXTS *ROOT-MODULE*))))
    (CL:LOOP
     WHILE
     (CL:NOT (CL:EQ ITER-001 NIL))
     DO
     (CL:PROGN
      (CL:SETQ CXT (CLSYS-SVAL CONS VALUE ITER-001))
      (CL:SETQ ITER-001 (CLSYS-SVAL CONS REST ITER-001)))
     (CL:WHEN
      (CL:EQ (STRING-EQL? (CONTEXT-NAME CXT) SELF) 1)
      (CL:RETURN-FROM SLOWLY-GET-CONTEXT CXT))))
   (CL:LET*
    ((CXT NULL) (ITER-002 (ALL-CONTEXTS)))
    (CL:LOOP
     WHILE
     (CL:EQ (NEXT? ITER-002) 1)
     DO
     (CL:PROGN (CL:SETQ CXT (CLSYS-SVAL ITERATOR VALUE ITER-002)))
     (CL:WHEN
      (CL:EQ (STRING-EQL? (CONTEXT-NAME CXT) SELF) 1)
      (CL:WHEN
       (CL:NOT (CL:EQ CONTEXT NULL))
       (CL:LET
        ((%%STREAM (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT)))
        (CL:WRITE-STRING "More than one context has the name `" %%STREAM)
        (CL:WRITE-STRING SELF %%STREAM)
        (CL:WRITE-STRING "'" %%STREAM)
        (CL:TERPRI %%STREAM)
        (CL:FORCE-OUTPUT %%STREAM))
       (CL:RETURN-FROM SLOWLY-GET-CONTEXT NULL))
      (CL:SETQ CONTEXT CXT))))
   (CL:RETURN-FROM SLOWLY-GET-CONTEXT CONTEXT))
  :VOID)

;;; (DEFMETHOD (SLOWLY-GET-CONTEXT CONTEXT) ...)

(CL:DEFMETHOD SLOWLY-GET-CONTEXT ((SELF CL:INTEGER))
  (CL:RETURN-FROM SLOWLY-GET-CONTEXT (FIND-CONTEXT-BY-NUMBER SELF))
  :VOID)

;;; (DEFMETHOD (SLOWLY-GET-CONTEXT CONTEXT) ...)

(CL:DEFMETHOD SLOWLY-GET-CONTEXT ((SELF SYMBOL))
  (CL:RETURN-FROM SLOWLY-GET-CONTEXT (SLOWLY-GET-CONTEXT (RELATIVE-NAME SELF)))
  :VOID)

;;; (DEFUN (SLOWLY-CHANGE-CONTEXT CONTEXT) ...)

(CL:DEFUN SLOWLY-CHANGE-CONTEXT (SELF)
  (CL:IF
   (CL:NOT (CL:EQ SELF NULL))
   (CL:RETURN-FROM SLOWLY-CHANGE-CONTEXT (CHANGE-CONTEXT SELF))
   (CL:RETURN-FROM SLOWLY-CHANGE-CONTEXT *CONTEXT*))
  :VOID)

;;; (DEFUN (CC CONTEXT) ...)

(CL:DEFUN %%CC (NAME)
  "Change the current context to the one named `name'.  Return the
value of the new current context.  If no `name' is supplied, return
the value of `*context*'.  `cc' is a no-op if the context reference
cannot be successfully evaluated."
  (CL:LET*
   ((CONTEXT *CONTEXT*) (NAMESPEC (FIRST NAME)))
   (CL:WHEN
    (CL:NOT (CL:EQ NAMESPEC NULL))
    (CL:LET*
     ((NAMESPEC-001 NAMESPEC))
     (CL:COND
      ((CL:EQ (INTEGER? NAMESPEC) 1)
       (CL:LET*
        ((NAMESPEC NULL))
        (CL:SETQ NAMESPEC NAMESPEC-001)
        (CL:SETQ
         CONTEXT
         (SLOWLY-GET-CONTEXT
          (CLSYS-SVAL INTEGER-WRAPPER WRAPPER-VALUE NAMESPEC)))))
      (CL:T
       (CL:LET*
        ((CONTEXTNAME (COERCE-TO-MODULE-NAME NAMESPEC TRUE)))
        (CL:WHEN
         (CL:NOT (CL:EQ CONTEXTNAME NULL))
         (CL:SETQ CONTEXT (SLOWLY-GET-CONTEXT CONTEXTNAME))))))))
   (CL:RETURN-FROM %%CC (SLOWLY-CHANGE-CONTEXT CONTEXT)))
  :VOID)

(CL:DEFUN CC-EVALUATOR-WRAPPER (ARGUMENTS)
  (CL:RETURN-FROM CC-EVALUATOR-WRAPPER (%%CC ARGUMENTS))
  :VOID)

(CL:DEFMACRO CC (CL:&WHOLE EXPRESSION CL:&REST IGNORE)
  "Change the current context to the one named `name'.  Return the
value of the new current context.  If no `name' is supplied, return
the value of `*context*'.  `cc' is a no-op if the context reference
cannot be successfully evaluated."
  (CL:DECLARE (CL:IGNORE IGNORE))
  (CL:LET
   ((*IGNORETRANSLATIONERRORS?* FALSE))
   (INCREMENTALLY-TRANSLATE EXPRESSION FALSE)))

(SETF (CL:MACRO-FUNCTION (CL:QUOTE /STELLA/CC)) (CL:MACRO-FUNCTION (CL:QUOTE CC)))

;;; (DEFUN PRINT-CONTEXT ...)

(CL:DEFUN PRINT-CONTEXT (SELF STREAM)
  (CL:LET*
   ((TYPESTRING NULL)
    (NAME NULL)
    (NUMBER (CLSYS-SVAL CONTEXT CONTEXT-NUMBER SELF)))
   (CL:WHEN
    (CL:EQ *CLASS-HIERARCHY-BOOTED?* 0)
    (CL:PROGN
     (CL:WRITE-STRING "|MDL|" STREAM)
     (CL:WRITE-STRING (CLSYS-SVAL MODULE MODULE-NAME SELF) STREAM))
    (CL:RETURN-FROM PRINT-CONTEXT))
   (CL:LET*
    ((SELF-001 SELF))
    (CL:COND
     ((CL:EQ (TAXONOMY-ISA? SELF SGT-CONTEXTS-MODULE) 1)
      (CL:LET*
       ((SELF NULL))
       (CL:SETQ SELF SELF-001)
       (CL:SETQ NAME (CLSYS-SVAL MODULE MODULE-FULL-NAME SELF))
       (CL:IF
        (CL:EQ (DISCARDED-CONTEXT? SELF) 1)
        (CL:SETQ TYPESTRING "|DISCARDED MDL|")
        (CL:SETQ TYPESTRING "|MDL|"))))
     ((CL:EQ (TAXONOMY-ISA? SELF SGT-CONTEXTS-WORLD) 1)
      (CL:LET*
       ((SELF NULL))
       (CL:SETQ SELF SELF-001)
       (CL:SETQ
        NAME
        (CLSYS-SVAL
         STRING-WRAPPER
         WRAPPER-VALUE
         (DYNAMIC-SLOT-VALUE
          SELF
          SYM-CONTEXTS-WORLD-NAME
          NULL-STRING-WRAPPER)))
       (CL:IF
        (CL:EQ (DISCARDED-CONTEXT? SELF) 1)
        (CL:SETQ TYPESTRING "|DISCARDED WLD|")
        (CL:SETQ TYPESTRING "|WLD|"))))
     (CL:T (CL:ERROR "`~A' is not a valid case option" SELF))))
   (CL:WHEN
    (CL:EQ (DISCARDED-CONTEXT? SELF) 1)
    (CL:SETQ NUMBER (CL:1+ NUMBER)))
   (CL:IF
    (CL:NOT (CL:EQ NAME NULL))
    (CL:PROGN
     (CL:WRITE-STRING TYPESTRING STREAM)
     (CL:WRITE-STRING NAME STREAM))
    (CL:PROGN (CL:WRITE-STRING TYPESTRING STREAM) (CL:PRINC NUMBER STREAM))))
  :VOID)

;;; (DEFUN HELP-PRINT-CONTEXT-TREE ...)

(CL:DEFUN HELP-PRINT-CONTEXT-TREE (LIST LEVEL)
  (CL:LET*
   ((C NULL) (ITER-001 (CLSYS-SVAL LIST THE-CONS-LIST LIST)))
   (CL:LOOP
    WHILE
    (CL:NOT (CL:EQ ITER-001 NIL))
    DO
    (CL:PROGN
     (CL:SETQ C (CLSYS-SVAL CONS VALUE ITER-001))
     (CL:SETQ ITER-001 (CLSYS-SVAL CONS REST ITER-001)))
    (CL:LET
     ((%%STREAM (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT)))
     (CL:TERPRI %%STREAM)
     (CL:FORCE-OUTPUT %%STREAM))
    (CL:LET*
     ((I NULL) (ITER-002 1) (UPPER-BOUND-001 (CL:* 3 LEVEL)))
     (CL:LOOP
      WHILE
      (CL:<= ITER-002 UPPER-BOUND-001)
      DO
      (CL:PROGN (CL:SETQ I ITER-002) (CL:SETQ ITER-002 (CL:1+ ITER-002)))
      (CL:PROGN I)
      (CL:WRITE-STRING
       " "
       (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT))))
    (CL:PRINC
     (CLSYS-SVAL CONTEXT CONTEXT-NUMBER C)
     (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT))
    (CL:WHEN
     (CL:NOT (CL:EQ (CONTEXT-NAME C) NULL))
     (CL:LET
      ((%%STREAM (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT)))
      (CL:WRITE-STRING "   " %%STREAM)
      (CL:WRITE-STRING (CONTEXT-NAME C) %%STREAM)))
    (CL:LET
     ((%%STREAM (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT)))
     (CL:TERPRI %%STREAM)
     (CL:FORCE-OUTPUT %%STREAM))
    (HELP-PRINT-CONTEXT-TREE
     (CLSYS-SVAL CONTEXT CHILD-CONTEXTS C)
     (CL:1+ LEVEL))))
  :VOID)

;;; (DEFUN PRINT-CONTEXT-TREE ...)

(CL:DEFUN PRINT-CONTEXT-TREE (ROOT)
  (CL:WHEN (CL:EQ ROOT NULL) (CL:SETQ ROOT *ROOT-MODULE*))
  (CL:LET*
   ((TOPLIST (LIST ROOT)))
   (HELP-PRINT-CONTEXT-TREE TOPLIST 0)
   (FREE TOPLIST))
  :VOID)

;;; (DEFUN (ACCESS-IN-CONTEXT OBJECT) ...)

(CL:DEFUN ACCESS-IN-CONTEXT (VALUE OBJECT DONTINHERIT?)
  (CL:WHEN
   (CL:OR (CL:EQ VALUE NULL) (CL:EQ (CS-VALUE? VALUE) 0))
   (CL:LET*
    ((HOMECONTEXT (CLSYS-SVAL CONTEXT-SENSITIVE-OBJECT HOME-CONTEXT OBJECT)))
    (CL:IF
     (CL:EQ DONTINHERIT? 1)
     (CL:WHEN
      (CL:EQ *CONTEXT* HOMECONTEXT)
      (CL:RETURN-FROM ACCESS-IN-CONTEXT VALUE))
     (CL:WHEN
      (CL:OR
       (CL:EQ HOMECONTEXT NULL)
       (CL:EQ (SUBCONTEXT? *CONTEXT* HOMECONTEXT) 1)
       (CL:AND
        (CL:EQ (ISA? HOMECONTEXT SGT-CONTEXTS-MODULE) 1)
        (CL:EQ (VISIBLE-FROM? HOMECONTEXT *MODULE*) 1)))
      (CL:RETURN-FROM ACCESS-IN-CONTEXT VALUE)))
    (CL:RETURN-FROM ACCESS-IN-CONTEXT NULL)))
  (CL:LET*
   ((KVCONS (CLSYS-SVAL CS-VALUE THE-KV-LIST VALUE))
    (CONTEXTNUMBER NULL-INTEGER))
   (CL:LET*
    ((TARGET *CONTEXT*))
    (CL:SETQ CONTEXTNUMBER (CLSYS-SVAL CONTEXT CONTEXT-NUMBER TARGET))
    (CL:LOOP
     WHILE
     (CL:AND
      (CL:NOT (CL:EQ KVCONS NULL))
      (CL:<
       CONTEXTNUMBER
       (CLSYS-SVAL CONTEXT CONTEXT-NUMBER (CLSYS-SVAL KV-CONS KEY KVCONS))))
     DO
     (CL:IF
      (CL:AND
       (CL:EQ (DISCARDED-CONTEXT? (CLSYS-SVAL KV-CONS KEY KVCONS)) 1)
       (CL:EQ *CONTEXT-BACKTRACKING-MODE* 0)
       (CL:EQ *UNLINK-DISCARDED-CONTEXTS-ON-READ?* 1))
      (CL:IF
       (CL:NOT (CL:EQ (CLSYS-SVAL KV-CONS REST KVCONS) NULL))
       (CL:LET*
        ((NEXTKVCONS (CLSYS-SVAL KV-CONS REST KVCONS)))
        (CL:SETF
         (CLSYS-SVAL KV-CONS KEY KVCONS)
         (CLSYS-SVAL KV-CONS KEY NEXTKVCONS))
        (CL:SETF
         (CLSYS-SVAL KV-CONS VALUE KVCONS)
         (CLSYS-SVAL KV-CONS VALUE NEXTKVCONS))
        (CL:SETF
         (CLSYS-SVAL KV-CONS REST KVCONS)
         (CLSYS-SVAL KV-CONS REST NEXTKVCONS))
        (FREE NEXTKVCONS))
       (CL:PROGN
        (REMOVE-AT VALUE (CLSYS-SVAL KV-CONS KEY KVCONS))
        (CL:RETURN-FROM ACCESS-IN-CONTEXT NULL)))
      (CL:SETQ KVCONS (CLSYS-SVAL KV-CONS REST KVCONS))))
    (CL:WHEN (CL:EQ KVCONS NULL) (CL:RETURN-FROM ACCESS-IN-CONTEXT NULL))
    (CL:WHEN
     (CL:EQ TARGET (CLSYS-SVAL KV-CONS KEY KVCONS))
     (CL:RETURN-FROM ACCESS-IN-CONTEXT (CLSYS-SVAL KV-CONS VALUE KVCONS)))
    (CL:WHEN (CL:EQ DONTINHERIT? 1) (CL:RETURN-FROM ACCESS-IN-CONTEXT NULL)))
   (CL:LET*
    ((TARGET NULL)
     (ITER-001 (CLSYS-SVAL CONTEXT ALL-SUPER-CONTEXTS *CONTEXT*)))
    (CL:LOOP
     WHILE
     (CL:NOT (CL:EQ ITER-001 NIL))
     DO
     (CL:PROGN
      (CL:SETQ TARGET (CLSYS-SVAL CONS VALUE ITER-001))
      (CL:SETQ ITER-001 (CLSYS-SVAL CONS REST ITER-001)))
     (CL:SETQ CONTEXTNUMBER (CLSYS-SVAL CONTEXT CONTEXT-NUMBER TARGET))
     (CL:LOOP
      WHILE
      (CL:AND
       (CL:NOT (CL:EQ KVCONS NULL))
       (CL:<
        CONTEXTNUMBER
        (CLSYS-SVAL CONTEXT CONTEXT-NUMBER (CLSYS-SVAL KV-CONS KEY KVCONS))))
      DO
      (CL:IF
       (CL:AND
        (CL:EQ (DISCARDED-CONTEXT? (CLSYS-SVAL KV-CONS KEY KVCONS)) 1)
        (CL:EQ *CONTEXT-BACKTRACKING-MODE* 0)
        (CL:EQ *UNLINK-DISCARDED-CONTEXTS-ON-READ?* 1))
       (CL:IF
        (CL:NOT (CL:EQ (CLSYS-SVAL KV-CONS REST KVCONS) NULL))
        (CL:LET*
         ((NEXTKVCONS (CLSYS-SVAL KV-CONS REST KVCONS)))
         (CL:SETF
          (CLSYS-SVAL KV-CONS KEY KVCONS)
          (CLSYS-SVAL KV-CONS KEY NEXTKVCONS))
         (CL:SETF
          (CLSYS-SVAL KV-CONS VALUE KVCONS)
          (CLSYS-SVAL KV-CONS VALUE NEXTKVCONS))
         (CL:SETF
          (CLSYS-SVAL KV-CONS REST KVCONS)
          (CLSYS-SVAL KV-CONS REST NEXTKVCONS))
         (FREE NEXTKVCONS))
        (CL:PROGN
         (REMOVE-AT VALUE (CLSYS-SVAL KV-CONS KEY KVCONS))
         (CL:RETURN-FROM ACCESS-IN-CONTEXT NULL)))
       (CL:SETQ KVCONS (CLSYS-SVAL KV-CONS REST KVCONS))))
     (CL:WHEN (CL:EQ KVCONS NULL) (CL:RETURN-FROM ACCESS-IN-CONTEXT NULL))
     (CL:WHEN
      (CL:EQ TARGET (CLSYS-SVAL KV-CONS KEY KVCONS))
      (CL:RETURN-FROM ACCESS-IN-CONTEXT (CLSYS-SVAL KV-CONS VALUE KVCONS)))
     (CL:WHEN
      (CL:EQ DONTINHERIT? 1)
      (CL:RETURN-FROM ACCESS-IN-CONTEXT NULL))))
   (CL:RETURN-FROM ACCESS-IN-CONTEXT NULL))
  :VOID)

;;; (DEFUN (COMPUTE-NEAREST-CONTEXT CONTEXT) ...)

(CL:DEFUN COMPUTE-NEAREST-CONTEXT (VALUE OBJECT CONTEXT)
  (CL:WHEN
   (CL:OR (CL:EQ VALUE NULL) (CL:EQ (CS-VALUE? VALUE) 0))
   (CL:RETURN-FROM
    COMPUTE-NEAREST-CONTEXT
    (CLSYS-SVAL CONTEXT-SENSITIVE-OBJECT HOME-CONTEXT OBJECT)))
  (CL:LET*
   ((KVCONS (CLSYS-SVAL CS-VALUE THE-KV-LIST VALUE))
    (CONTEXTNUMBER NULL-INTEGER))
   (CL:LET*
    ((TARGET CONTEXT))
    (CL:SETQ CONTEXTNUMBER (CLSYS-SVAL CONTEXT CONTEXT-NUMBER TARGET))
    (CL:LOOP
     WHILE
     (CL:AND
      (CL:NOT (CL:EQ KVCONS NULL))
      (CL:<
       CONTEXTNUMBER
       (CLSYS-SVAL CONTEXT CONTEXT-NUMBER (CLSYS-SVAL KV-CONS KEY KVCONS))))
     DO
     (CL:SETQ KVCONS (CLSYS-SVAL KV-CONS REST KVCONS)))
    (CL:WHEN
     (CL:EQ KVCONS NULL)
     (CL:RETURN-FROM COMPUTE-NEAREST-CONTEXT NULL))
    (CL:WHEN
     (CL:EQ TARGET (CLSYS-SVAL KV-CONS KEY KVCONS))
     (CL:RETURN-FROM COMPUTE-NEAREST-CONTEXT TARGET)))
   (CL:LET*
    ((TARGET NULL) (ITER-001 (CLSYS-SVAL CONTEXT ALL-SUPER-CONTEXTS CONTEXT)))
    (CL:LOOP
     WHILE
     (CL:NOT (CL:EQ ITER-001 NIL))
     DO
     (CL:PROGN
      (CL:SETQ TARGET (CLSYS-SVAL CONS VALUE ITER-001))
      (CL:SETQ ITER-001 (CLSYS-SVAL CONS REST ITER-001)))
     (CL:SETQ CONTEXTNUMBER (CLSYS-SVAL CONTEXT CONTEXT-NUMBER TARGET))
     (CL:LOOP
      WHILE
      (CL:AND
       (CL:NOT (CL:EQ KVCONS NULL))
       (CL:<
        CONTEXTNUMBER
        (CLSYS-SVAL CONTEXT CONTEXT-NUMBER (CLSYS-SVAL KV-CONS KEY KVCONS))))
      DO
      (CL:SETQ KVCONS (CLSYS-SVAL KV-CONS REST KVCONS)))
     (CL:WHEN
      (CL:EQ KVCONS NULL)
      (CL:RETURN-FROM COMPUTE-NEAREST-CONTEXT NULL))
     (CL:WHEN
      (CL:EQ TARGET (CLSYS-SVAL KV-CONS KEY KVCONS))
      (CL:RETURN-FROM COMPUTE-NEAREST-CONTEXT TARGET))))
   (CL:RETURN-FROM COMPUTE-NEAREST-CONTEXT NULL))
  :VOID)

;;; (DEFUN HELP-INSERT-A-CS-VALUE ...)

(CL:DEFUN HELP-INSERT-A-CS-VALUE (KVCONS NEWVALUE TARGET OVERWRITE?)
  (CL:LET*
   ((CONTEXTNUMBER (CLSYS-SVAL CONTEXT CONTEXT-NUMBER TARGET)))
   (CL:LOOP
    (CL:WHEN
     (CL:AND
      (CL:EQ *CONTEXT-BACKTRACKING-MODE* 0)
      (CL:EQ *UNLINK-DISCARDED-CONTEXTS-ON-WRITE?* 1)
      (CL:EQ (DISCARDED-CONTEXT? (CLSYS-SVAL KV-CONS KEY KVCONS)) 1))
     (CL:IF
      (CL:NOT (CL:EQ (CLSYS-SVAL KV-CONS REST KVCONS) NULL))
      (CL:LET*
       ((NEXTKVCONS (CLSYS-SVAL KV-CONS REST KVCONS)))
       (CL:SETF
        (CLSYS-SVAL KV-CONS KEY KVCONS)
        (CLSYS-SVAL KV-CONS KEY NEXTKVCONS))
       (CL:SETF
        (CLSYS-SVAL KV-CONS VALUE KVCONS)
        (CLSYS-SVAL KV-CONS VALUE NEXTKVCONS))
       (CL:SETF
        (CLSYS-SVAL KV-CONS REST KVCONS)
        (CLSYS-SVAL KV-CONS REST NEXTKVCONS))
       (FREE NEXTKVCONS))
      (CL:PROGN
       (CL:SETF (CLSYS-SVAL KV-CONS KEY KVCONS) TARGET)
       (CL:SETF (CLSYS-SVAL KV-CONS VALUE KVCONS) NEWVALUE)
       (CL:RETURN-FROM HELP-INSERT-A-CS-VALUE))))
    (CL:COND
     ((CL:EQ (CLSYS-SVAL KV-CONS KEY KVCONS) TARGET)
      (CL:WHEN
       (CL:EQ OVERWRITE? 1)
       (CL:SETF (CLSYS-SVAL KV-CONS VALUE KVCONS) NEWVALUE))
      (CL:RETURN-FROM HELP-INSERT-A-CS-VALUE))
     ((CL:<
       (CLSYS-SVAL CONTEXT CONTEXT-NUMBER (CLSYS-SVAL KV-CONS KEY KVCONS))
       CONTEXTNUMBER)
      (CL:SETF
       (CLSYS-SVAL KV-CONS REST KVCONS)
       (KV-CONS
        (CLSYS-SVAL KV-CONS KEY KVCONS)
        (CLSYS-SVAL KV-CONS VALUE KVCONS)
        (CLSYS-SVAL KV-CONS REST KVCONS)))
      (CL:SETF (CLSYS-SVAL KV-CONS KEY KVCONS) TARGET)
      (CL:SETF (CLSYS-SVAL KV-CONS VALUE KVCONS) NEWVALUE)
      (CL:RETURN-FROM HELP-INSERT-A-CS-VALUE))
     ((CL:EQ (CLSYS-SVAL KV-CONS REST KVCONS) NULL)
      (CL:SETF
       (CLSYS-SVAL KV-CONS REST KVCONS)
       (KV-CONS TARGET NEWVALUE NULL))
      (CL:RETURN-FROM HELP-INSERT-A-CS-VALUE))
     (CL:T (CL:SETQ KVCONS (CLSYS-SVAL KV-CONS REST KVCONS))))))
  :VOID)

;;; (DEFMETHOD INSERT-AT ...)

(CL:DEFMETHOD INSERT-AT ((SELF CS-VALUE) CONTEXT NEWVALUE)
  (CL:WHEN
   (CL:EQ (CLSYS-SVAL CS-VALUE THE-KV-LIST SELF) NULL)
   (CL:LET*
    ((KVCONS (NEW-KV-CONS)))
    (CL:SETF (CLSYS-SVAL KV-CONS KEY KVCONS) CONTEXT)
    (CL:SETF (CLSYS-SVAL KV-CONS VALUE KVCONS) NEWVALUE)
    (CL:SETF (CLSYS-SVAL CS-VALUE THE-KV-LIST SELF) KVCONS)
    (CL:RETURN-FROM INSERT-AT)))
  (HELP-INSERT-A-CS-VALUE
   (CLSYS-SVAL CS-VALUE THE-KV-LIST SELF)
   NEWVALUE
   CONTEXT
   TRUE)
  :VOID)

;;; (DEFUN (UPDATE-IN-CONTEXT OBJECT) ...)

(CL:DEFUN UPDATE-IN-CONTEXT (OLDVALUE NEWVALUE OBJECT COPYTOCHILDREN?)
  (CL:LET*
   ((CSVALUE NULL)
    (HOMECONTEXT (CLSYS-SVAL CONTEXT-SENSITIVE-OBJECT HOME-CONTEXT OBJECT)))
   (CL:IF
    (CL:EQ (CS-VALUE? OLDVALUE) 1)
    (CL:SETQ CSVALUE OLDVALUE)
    (CL:IF
     (CL:AND
      (CL:EQ HOMECONTEXT *CONTEXT*)
      (CL:OR
       (CL:EQ (EMPTY? (CLSYS-SVAL CONTEXT CHILD-CONTEXTS *CONTEXT*)) 1)
       (CL:EQ COPYTOCHILDREN? 0)))
     (CL:RETURN-FROM UPDATE-IN-CONTEXT NEWVALUE)
     (CL:PROGN
      (CL:SETQ CSVALUE (NEW-CS-VALUE))
      (CL:WHEN
       (CL:NOT (CL:EQ OLDVALUE NULL))
       (INSERT-AT CSVALUE HOMECONTEXT OLDVALUE)))))
   (INSERT-AT CSVALUE *CONTEXT* NEWVALUE)
   (CL:WHEN
    (CL:EQ COPYTOCHILDREN? 1)
    (COPY-CURRENT-VALUE-TO-CHILDREN CSVALUE OBJECT NEWVALUE))
   (CL:RETURN-FROM UPDATE-IN-CONTEXT CSVALUE))
  :VOID)

;;; (DEFUN COPY-CURRENT-VALUE-TO-CHILDREN ...)

(CL:DEFUN COPY-CURRENT-VALUE-TO-CHILDREN (CSVALUE OBJECT PARENTVALUE)
  (CL:LET*
   ((CHILDCXT NULL)
    (ITER-001
     (CLSYS-SVAL
      LIST
      THE-CONS-LIST
      (CLSYS-SVAL CONTEXT CHILD-CONTEXTS *CONTEXT*))))
   (CL:LOOP
    WHILE
    (CL:NOT (CL:EQ ITER-001 NIL))
    DO
    (CL:PROGN
     (CL:SETQ CHILDCXT (CLSYS-SVAL CONS VALUE ITER-001))
     (CL:SETQ ITER-001 (CLSYS-SVAL CONS REST ITER-001)))
    (CL:LET*
     ((*CONTEXT* CHILDCXT))
     (CL:DECLARE (CL:SPECIAL *CONTEXT*))
     (CL:LET*
      ((CURRENTVALUE (ACCESS-IN-CONTEXT CSVALUE OBJECT FALSE)))
      (CL:WHEN
       (CL:EQ (EQL? CURRENTVALUE PARENTVALUE) 0)
       (HELP-INSERT-A-CS-VALUE
        (CLSYS-SVAL CS-VALUE THE-KV-LIST CSVALUE)
        CURRENTVALUE
        CHILDCXT
        FALSE))))))
  :VOID)

(CL:DEFUN STARTUP-CONTEXTS ()
  (CL:LET*
   ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 2) 1)
    (CL:SETQ
     SGT-CONTEXTS-CS-VALUE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CS-VALUE" NULL 1))
    (CL:SETQ SYM-CONTEXTS-CC (INTERN-RIGID-SYMBOL-WRT-MODULE "CC" NULL 0))
    (CL:SETQ
     KWD-CONTEXTS-COMMON-LISP
     (INTERN-RIGID-SYMBOL-WRT-MODULE "COMMON-LISP" NULL 2))
    (CL:SETQ
     KWD-CONTEXTS-FUNCTION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FUNCTION" NULL 2))
    (CL:SETQ
     SYM-CONTEXTS-EVALUATOR-WRAPPER-CODE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "EVALUATOR-WRAPPER-CODE" NULL 0))
    (CL:SETQ
     SGT-CONTEXTS-MODULE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "MODULE" NULL 1))
    (CL:SETQ
     SGT-CONTEXTS-WORLD
     (INTERN-RIGID-SYMBOL-WRT-MODULE "WORLD" NULL 1))
    (CL:SETQ
     SYM-CONTEXTS-WORLD-NAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "WORLD-NAME" NULL 0)))
   (CL:WHEN (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 6) 1) (FINALIZE-CLASSES))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 7) 1)
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "CS-VALUE?"
        "OBJECT"
        "(DEFUN (CS-VALUE? BOOLEAN) ((SELF OBJECT)) :GLOBALLY-INLINE? TRUE)")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION CS-VALUE?)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "SUBCONTEXT?"
        "CONTEXT"
        "(DEFUN (SUBCONTEXT? BOOLEAN) ((SUBCONTEXT CONTEXT) (SUPERCONTEXT CONTEXT)) :GLOBALLY-INLINE? TRUE)")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION SUBCONTEXT?)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "DISCARDED-CONTEXT?"
        "CONTEXT"
        "(DEFUN (DISCARDED-CONTEXT? BOOLEAN) ((CONTEXT CONTEXT)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION DISCARDED-CONTEXT?)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "HELP-FIND-CONTEXT-BY-NUMBER"
        "INTEGER"
        "(DEFUN (HELP-FIND-CONTEXT-BY-NUMBER CONTEXT) ((NUMBER INTEGER) (SIBLINGS (LIST OF CONTEXT))))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION HELP-FIND-CONTEXT-BY-NUMBER)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "FIND-CONTEXT-BY-NUMBER"
        "INTEGER"
        "(DEFUN (FIND-CONTEXT-BY-NUMBER CONTEXT) ((CONTEXTNUMBER INTEGER)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION FIND-CONTEXT-BY-NUMBER)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "SLOWLY-GET-CONTEXT"
        "STRING"
        "(DEFMETHOD (SLOWLY-GET-CONTEXT CONTEXT) ((SELF STRING)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT METHOD-CODE METHOD)
      (CL:FUNCTION SLOWLY-GET-CONTEXT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "SLOWLY-GET-CONTEXT"
        "INTEGER"
        "(DEFMETHOD (SLOWLY-GET-CONTEXT CONTEXT) ((SELF INTEGER)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT METHOD-CODE METHOD)
      (CL:FUNCTION SLOWLY-GET-CONTEXT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "SLOWLY-GET-CONTEXT"
        "SYMBOL"
        "(DEFMETHOD (SLOWLY-GET-CONTEXT CONTEXT) ((SELF SYMBOL)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT METHOD-CODE METHOD)
      (CL:FUNCTION SLOWLY-GET-CONTEXT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "SLOWLY-CHANGE-CONTEXT"
        "CONTEXT"
        "(DEFUN (SLOWLY-CHANGE-CONTEXT CONTEXT) ((SELF CONTEXT)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION SLOWLY-CHANGE-CONTEXT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "CC"
        "ARGUMENT-LIST"
        "(DEFUN (CC CONTEXT) (|&REST| (NAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Change the current context to the one named `name'.  Return the
value of the new current context.  If no `name' is supplied, return
the value of `*context*'.  `cc' is a no-op if the context reference
cannot be successfully evaluated.\")")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION %%CC))
     (SET-DYNAMIC-SLOT-VALUE
      METHOD
      SYM-CONTEXTS-EVALUATOR-WRAPPER-CODE
      (WRAP-FUNCTION-CODE (CL:FUNCTION CC-EVALUATOR-WRAPPER))
      NULL-FUNCTION-CODE-WRAPPER))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "PRINT-CONTEXT"
        "CONTEXT"
        "(DEFUN PRINT-CONTEXT ((SELF CONTEXT) (STREAM NATIVE-OUTPUT-STREAM)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION PRINT-CONTEXT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "HELP-PRINT-CONTEXT-TREE"
        "LIST"
        "(DEFUN HELP-PRINT-CONTEXT-TREE ((LIST (LIST OF CONTEXT)) (LEVEL INTEGER)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION HELP-PRINT-CONTEXT-TREE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "PRINT-CONTEXT-TREE"
        "CONTEXT"
        "(DEFUN PRINT-CONTEXT-TREE ((ROOT CONTEXT)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION PRINT-CONTEXT-TREE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "ACCESS-IN-CONTEXT"
        "OBJECT"
        "(DEFUN (ACCESS-IN-CONTEXT OBJECT) ((VALUE OBJECT) (OBJECT CONTEXT-SENSITIVE-OBJECT) (DONTINHERIT? BOOLEAN)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION ACCESS-IN-CONTEXT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "COMPUTE-NEAREST-CONTEXT"
        "OBJECT"
        "(DEFUN (COMPUTE-NEAREST-CONTEXT CONTEXT) ((VALUE OBJECT) (OBJECT CONTEXT-SENSITIVE-OBJECT) (CONTEXT CONTEXT)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION COMPUTE-NEAREST-CONTEXT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "HELP-INSERT-A-CS-VALUE"
        "KV-CONS"
        "(DEFUN HELP-INSERT-A-CS-VALUE ((KVCONS KV-CONS) (NEWVALUE OBJECT) (TARGET CONTEXT) (OVERWRITE? BOOLEAN)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION HELP-INSERT-A-CS-VALUE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "INSERT-AT"
        "CS-VALUE"
        "(DEFMETHOD INSERT-AT ((SELF CS-VALUE) (CONTEXT CONTEXT) (NEWVALUE OBJECT)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT METHOD-CODE METHOD)
      (CL:FUNCTION INSERT-AT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "UPDATE-IN-CONTEXT"
        "OBJECT"
        "(DEFUN (UPDATE-IN-CONTEXT OBJECT) ((OLDVALUE OBJECT) (NEWVALUE OBJECT) (OBJECT CONTEXT-SENSITIVE-OBJECT) (COPYTOCHILDREN? BOOLEAN)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION UPDATE-IN-CONTEXT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "COPY-CURRENT-VALUE-TO-CHILDREN"
        "CS-VALUE"
        "(DEFUN COPY-CURRENT-VALUE-TO-CHILDREN ((CSVALUE CS-VALUE) (OBJECT CONTEXT-SENSITIVE-OBJECT) (PARENTVALUE OBJECT)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION COPY-CURRENT-VALUE-TO-CHILDREN)))
    (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
     "STARTUP-CONTEXTS"
     NULL
     "(DEFUN STARTUP-CONTEXTS ())"))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 8) 1)
    (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 9) 1)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *UNLINK-DISCARDED-CONTEXTS-ON-READ?* BOOLEAN TRUE :DOCUMENTATION \"Eliminate pointers to discarded contexts while
accessing a CS-VALUE context table.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *UNLINK-DISCARDED-CONTEXTS-ON-WRITE?* BOOLEAN TRUE :DOCUMENTATION \"Eliminate pointers to discarded contexts while
inserting into a CS-VALUE context table.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *CONTEXT-BACKTRACKING-MODE* BOOLEAN FALSE :DOCUMENTATION \"If true, indicates that contexts are being allocated
and deallocated in depth-first fashion, and that deallocation of
CS-VALUE entries is taken care of during context destruction.\")")
    (REGISTER-NATIVE-NAME
     SYM-CONTEXTS-CC
     KWD-CONTEXTS-COMMON-LISP
     KWD-CONTEXTS-FUNCTION)))
  :VOID)
