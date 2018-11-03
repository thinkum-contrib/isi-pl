;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

#|--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996-2000              | 
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

(CL:DEFVAR KWD-STARTUP-EARLY-INITS NULL)
(CL:DEFVAR KWD-STARTUP-MODULES NULL)
(CL:DEFVAR KWD-STARTUP-SYMBOLS NULL)
(CL:DEFVAR KWD-STARTUP-QUOTED-CONSTANTS NULL)
(CL:DEFVAR KWD-STARTUP-GLOBALS NULL)
(CL:DEFVAR KWD-STARTUP-CLASSES NULL)
(CL:DEFVAR KWD-STARTUP-FINALIZE-CLASSES NULL)
(CL:DEFVAR KWD-STARTUP-METHODS NULL)
(CL:DEFVAR KWD-STARTUP-FINALIZE-METHODS NULL)
(CL:DEFVAR KWD-STARTUP-FINAL NULL)
(CL:DEFVAR SYM-STARTUP-STELLA-STARTUP-STARTUP NULL)
(CL:DEFVAR SYM-STARTUP-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STELLA-MODULE* *MODULE* STANDARD-OUTPUT EOL
  *CLASS-HIERARCHY-BOOTED?*))

;;; (DEFGLOBAL *STELLA-MAJOR-VERSION-NUMBER* ...)

(CL:PROGN (CL:DEFVAR *STELLA-MAJOR-VERSION-NUMBER* 2) (CL:DECLAIM (CL:TYPE CL:FIXNUM *STELLA-MAJOR-VERSION-NUMBER*)))

;;; (DEFGLOBAL *STELLA-MINOR-VERSION-NUMBER* ...)

(CL:PROGN (CL:DEFVAR *STELLA-MINOR-VERSION-NUMBER* 0) (CL:DECLAIM (CL:TYPE CL:FIXNUM *STELLA-MINOR-VERSION-NUMBER*)))

;;; (DEFGLOBAL *STELLA-RELEASE-STATE* ...)

(CL:PROGN (CL:DEFVAR *STELLA-RELEASE-STATE* ".beta") (CL:DECLAIM (CL:TYPE CL:SIMPLE-STRING *STELLA-RELEASE-STATE*)))

;;; (DEFGLOBAL *STELLA-PATCH-LEVEL* ...)

(CL:PROGN (CL:DEFVAR *STELLA-PATCH-LEVEL* 0) (CL:DECLAIM (CL:TYPE CL:FIXNUM *STELLA-PATCH-LEVEL*)))

;;; (DEFGLOBAL *STELLA-VERSION-STRING* ...)

(CL:PROGN (CL:DEFVAR *STELLA-VERSION-STRING* STELLA::NULL-STRING) (CL:DECLAIM (CL:TYPE CL:SIMPLE-STRING *STELLA-VERSION-STRING*)))

;;; (DEFGLOBAL *STARTUP-TIME-PHASES* ...)

(CL:DEFVAR *STARTUP-TIME-PHASES* NULL
  "List of phases that can be legally used as an optional
phase argument to a 'startup-time-progn' form.  The corresponding code
will be executed during the execution of a startup-time-code function only
if the position of the keyword in the list corresponds to the current value of
'*startup-time-phase*', or if phasing of startup-time code is disabled.")

;;; (DEFGLOBAL *STARTUP-TIME-PHASE* ...)

(CL:PROGN (CL:DEFVAR *STARTUP-TIME-PHASE* 999 "The current phase during 'phased startup'.
The value has to correspond to the position of one of the keywords
in '*startup-time-phases*'.  999 means no phasing at all.") (CL:DECLAIM (CL:TYPE CL:FIXNUM *STARTUP-TIME-PHASE*)))

;;; (DEFUN (CURRENT-STARTUP-TIME-PHASE? BOOLEAN) ...)

(CL:DEFUN CURRENT-STARTUP-TIME-PHASE? (PHASE)
  (CL:DECLARE (CL:TYPE CL:FIXNUM PHASE))
  (CL:RETURN-FROM CURRENT-STARTUP-TIME-PHASE?
   (CL:OR (CL:= *STARTUP-TIME-PHASE* 999)
    (CL:= PHASE *STARTUP-TIME-PHASE*))))

;;; (DEFUN (ENCODE-STARTUP-TIME-PHASE INTEGER) ...)

(CL:DEFUN ENCODE-STARTUP-TIME-PHASE (PHASE)
  (CL:LET* ((STARTUPTIMEPHASEASNUMBER 0))
   (CL:DECLARE (CL:TYPE CL:FIXNUM STARTUPTIMEPHASEASNUMBER))
   (CL:WHEN (CL:NOT (MEMBER? *STARTUP-TIME-PHASES* PHASE))
    (CL:SETQ PHASE KWD-STARTUP-FINAL))
   (CL:LET* ((PH NULL) (ITER-000 (%THE-CONS-LIST *STARTUP-TIME-PHASES*)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:PROGN (CL:SETQ PH (%%VALUE ITER-000))
      (CL:SETQ ITER-000 (%%REST ITER-000)))
     (CL:IF (CL:EQ PH PHASE)
      (CL:RETURN-FROM ENCODE-STARTUP-TIME-PHASE STARTUPTIMEPHASEASNUMBER)
      (CL:SETQ STARTUPTIMEPHASEASNUMBER
       (CL:1+ STARTUPTIMEPHASEASNUMBER)))))
   (CL:ERROR
    (NEW-STELLA-EXCEPTION
     "`encode-startup-time-phase' should never get this far!"))))

;;; (DEFUN STARTUP-KERNEL ...)

(CL:DEFUN STARTUP-KERNEL (VERBOSE?)
  (CL:LET*
   ((PHASE NULL-INTEGER) (ITER-000 0) (UPPER-BOUND-000 9)
    (UNBOUNDED?-000 (NULL? UPPER-BOUND-000)))
   (CL:DECLARE (CL:TYPE CL:FIXNUM ITER-000 UPPER-BOUND-000 PHASE))
   (CL:LOOP WHILE (CL:OR UNBOUNDED?-000 (CL:<= ITER-000 UPPER-BOUND-000))
    DO
    (CL:PROGN (CL:SETQ PHASE ITER-000)
     (CL:SETQ ITER-000 (CL:1+ ITER-000)))
    (CL:TAGBODY (CL:SETQ *STARTUP-TIME-PHASE* PHASE)
     (CL:WHEN VERBOSE?
      (CL:COND ((CL:= PHASE 0))
       ((CL:= PHASE 2)
        (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
         "Running kernel startup code..." EOL)
        (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
         "Initializing symbol tables..." EOL))
       ((CL:= PHASE 3)
        (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
         "Initializing quoted constants..." EOL))
       ((CL:= PHASE 4)
        (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
         "Initializing global variables..." EOL))
       ((CL:= PHASE 5)
        (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
         "Creating class objects..." EOL))
       ((CL:= PHASE 6)
        (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
         "Finalizing classes..." EOL))
       ((CL:= PHASE 7)
        (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
         "Creating method objects..." EOL))
       ((CL:= PHASE 8)
        (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
         "Finalizing methods..." EOL))
       ((CL:= PHASE 9)
        (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
         "Running non-phased startup code..." EOL))))
     (CL:WHEN (CL:= PHASE 6) (FINALIZE-CLASSES)
      (CL:SETQ *CLASS-HIERARCHY-BOOTED?* TRUE) (CL:GO :CONTINUE))
     (CL:WHEN (CL:= PHASE 8) (FINALIZE-SLOTS)
      (CLEANUP-UNFINALIZED-CLASSES) (CL:GO :CONTINUE))
     (STARTUP-STARTUP) (STARTUP-CL-PRIMAL) (STARTUP-PRIMAL)
     (STARTUP-TYPE-PREDICATES) (STARTUP-CONSES) (STARTUP-HIERARCHY)
     (STARTUP-TAXONOMIES) (STARTUP-LISTS) (STARTUP-COLLECTIONS)
     (STARTUP-ITERATORS) (STARTUP-LITERALS) (STARTUP-SYMBOLS)
     (STARTUP-CLASSES) (STARTUP-METHODS) (STARTUP-DEFCLASS)
     (STARTUP-STELLA-IN) (STARTUP-FOREACH) (STARTUP-WALK)
     (STARTUP-DYNAMIC-SLOTS) (STARTUP-DYNAMIC-LITERAL-SLOTS)
     (STARTUP-SYSTEMS) (STARTUP-CL-TRANSLATE) (STARTUP-MACROS)
     (STARTUP-MEMOIZE) (STARTUP-STREAMS) (STARTUP-DESCRIBE)
     (STARTUP-DEMONS) (STARTUP-MORE-DEMONS) (STARTUP-MODULES)
     (STARTUP-CONTEXTS) (STARTUP-READ) :CONTINUE)))
  :VOID)

;;; (DEFUN STARTUP-CPP-TRANSLATOR ...)

(CL:DEFUN STARTUP-CPP-TRANSLATOR ()
  (STARTUP-CPP-TRANSLATE)
  (STARTUP-CPP-CLASS-OUT)
  (STARTUP-CPP-OUTPUT)
  (STARTUP-CPP-TRANSLATE-FILE)
  :VOID)

;;; (DEFUN STARTUP-JAVA-TRANSLATOR ...)

(CL:DEFUN STARTUP-JAVA-TRANSLATOR ()
  (STARTUP-JAVA-TRANSLATE)
  (STARTUP-JAVA-CLASS-OUT)
  (STARTUP-JAVA-OUTPUT)
  (STARTUP-JAVA-TRANSLATE-FILE)
  :VOID)

;;; (DEFUN STARTUP-IDL-TRANSLATOR ...)

(CL:DEFUN STARTUP-IDL-TRANSLATOR ()
  (STARTUP-IDL-TRANSLATE)
  (STARTUP-IDL-CLASS-OUT)
  (STARTUP-IDL-OUTPUT)
  (STARTUP-IDL-TRANSLATE-FILE)
  :VOID)

;;; (DEFUN STARTUP ...)

(CL:DEFUN STARTUP (VERBOSE?)
  (STARTUP-KERNEL VERBOSE?)
  (CL:WHEN VERBOSE?
   (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
    "Starting up translators..." EOL))
  (CL:LET*
   ((PHASE NULL-INTEGER) (ITER-000 0) (UPPER-BOUND-000 9)
    (UNBOUNDED?-000 (NULL? UPPER-BOUND-000)))
   (CL:DECLARE (CL:TYPE CL:FIXNUM ITER-000 UPPER-BOUND-000 PHASE))
   (CL:LOOP WHILE (CL:OR UNBOUNDED?-000 (CL:<= ITER-000 UPPER-BOUND-000))
    DO
    (CL:PROGN (CL:SETQ PHASE ITER-000)
     (CL:SETQ ITER-000 (CL:1+ ITER-000)))
    (CL:SETQ *STARTUP-TIME-PHASE* PHASE) (STARTUP-TRANSLATE-FILE)
    (STARTUP-CL-TRANSLATE-FILE) (STARTUP-CPP-TRANSLATOR)
    (STARTUP-JAVA-TRANSLATOR) (STARTUP-IDL-TRANSLATOR)))
  (CL:SETQ *STARTUP-TIME-PHASE* 999)
  (SWEEP-TRANSIENTS)
  (CL:WHEN VERBOSE?
   (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "Welcome to `"
    *STELLA-VERSION-STRING* "'" EOL))
  :VOID)

(CL:DEFUN STARTUP-STARTUP ()
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ KWD-STARTUP-EARLY-INITS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "EARLY-INITS" NULL 2))
    (CL:SETQ KWD-STARTUP-MODULES
     (INTERN-RIGID-SYMBOL-WRT-MODULE "MODULES" NULL 2))
    (CL:SETQ KWD-STARTUP-SYMBOLS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SYMBOLS" NULL 2))
    (CL:SETQ KWD-STARTUP-QUOTED-CONSTANTS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "QUOTED-CONSTANTS" NULL 2))
    (CL:SETQ KWD-STARTUP-GLOBALS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "GLOBALS" NULL 2))
    (CL:SETQ KWD-STARTUP-CLASSES
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CLASSES" NULL 2))
    (CL:SETQ KWD-STARTUP-FINALIZE-CLASSES
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FINALIZE-CLASSES" NULL 2))
    (CL:SETQ KWD-STARTUP-METHODS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHODS" NULL 2))
    (CL:SETQ KWD-STARTUP-FINALIZE-METHODS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FINALIZE-METHODS" NULL 2))
    (CL:SETQ KWD-STARTUP-FINAL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FINAL" NULL 2))
    (CL:SETQ SYM-STARTUP-STELLA-STARTUP-STARTUP
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-STARTUP" NULL 0))
    (CL:SETQ SYM-STARTUP-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ *STELLA-VERSION-STRING*
     (CONCATENATE "STELLA "
      (INTEGER-TO-STRING *STELLA-MAJOR-VERSION-NUMBER*) "."
      (INTEGER-TO-STRING *STELLA-MINOR-VERSION-NUMBER*)
      *STELLA-RELEASE-STATE* " (patch-level "
      (INTEGER-TO-STRING *STELLA-PATCH-LEVEL*) ")"))
    (CL:SETQ *STARTUP-TIME-PHASES*
     (LIST KWD-STARTUP-EARLY-INITS KWD-STARTUP-MODULES KWD-STARTUP-SYMBOLS
      KWD-STARTUP-QUOTED-CONSTANTS KWD-STARTUP-GLOBALS KWD-STARTUP-CLASSES
      KWD-STARTUP-FINALIZE-CLASSES KWD-STARTUP-METHODS
      KWD-STARTUP-FINALIZE-METHODS KWD-STARTUP-FINAL)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "CURRENT-STARTUP-TIME-PHASE?"
     "(DEFUN (CURRENT-STARTUP-TIME-PHASE? BOOLEAN) ((PHASE INTEGER)) :PUBLIC? TRUE)"
     (CL:FUNCTION CURRENT-STARTUP-TIME-PHASE?) NULL)
    (DEFINE-FUNCTION-OBJECT "ENCODE-STARTUP-TIME-PHASE"
     "(DEFUN (ENCODE-STARTUP-TIME-PHASE INTEGER) ((PHASE KEYWORD)))"
     (CL:FUNCTION ENCODE-STARTUP-TIME-PHASE) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-KERNEL"
     "(DEFUN STARTUP-KERNEL ((VERBOSE? BOOLEAN)))"
     (CL:FUNCTION STARTUP-KERNEL) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-CPP-TRANSLATOR"
     "(DEFUN STARTUP-CPP-TRANSLATOR ())"
     (CL:FUNCTION STARTUP-CPP-TRANSLATOR) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-JAVA-TRANSLATOR"
     "(DEFUN STARTUP-JAVA-TRANSLATOR ())"
     (CL:FUNCTION STARTUP-JAVA-TRANSLATOR) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-IDL-TRANSLATOR"
     "(DEFUN STARTUP-IDL-TRANSLATOR ())"
     (CL:FUNCTION STARTUP-IDL-TRANSLATOR) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP"
     "(DEFUN STARTUP ((VERBOSE? BOOLEAN)) :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-STARTUP"
     "(DEFUN STARTUP-STARTUP () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-STARTUP) NULL)
    (CL:LET*
     ((FUNCTION (LOOKUP-FUNCTION SYM-STARTUP-STELLA-STARTUP-STARTUP)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-STARTUP-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "Startup-Startup") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *STELLA-MAJOR-VERSION-NUMBER* INTEGER 2 :PUBLIC? TRUE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *STELLA-MINOR-VERSION-NUMBER* INTEGER 0 :PUBLIC? TRUE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *STELLA-RELEASE-STATE* STRING \".beta\" :PUBLIC? TRUE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *STELLA-PATCH-LEVEL* INTEGER 0 :PUBLIC? TRUE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *STELLA-VERSION-STRING* STRING (CONCATENATE \"STELLA \" (INTEGER-TO-STRING *STELLA-MAJOR-VERSION-NUMBER*) \".\" (INTEGER-TO-STRING *STELLA-MINOR-VERSION-NUMBER*) *STELLA-RELEASE-STATE* \" (patch-level \" (INTEGER-TO-STRING *STELLA-PATCH-LEVEL*) \")\") :PUBLIC? TRUE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *STARTUP-TIME-PHASES* (LIST OF KEYWORD) (CAST (LIST :EARLY-INITS :MODULES :SYMBOLS :QUOTED-CONSTANTS :GLOBALS :CLASSES :FINALIZE-CLASSES :METHODS :FINALIZE-METHODS :FINAL) (LIST OF KEYWORD)) :DOCUMENTATION \"List of phases that can be legally used as an optional
phase argument to a 'startup-time-progn' form.  The corresponding code
will be executed during the execution of a startup-time-code function only
if the position of the keyword in the list corresponds to the current value of
'*startup-time-phase*', or if phasing of startup-time code is disabled.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *STARTUP-TIME-PHASE* INTEGER 999 :PUBLIC? TRUE :DOCUMENTATION \"The current phase during 'phased startup'.
The value has to correspond to the position of one of the keywords
in '*startup-time-phases*'.  999 means no phasing at all.\")")))
  :VOID)
