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

(CL:DEFVAR KWD-STELLA-TO-CL-DEFINE NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-FINALIZE NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-WALK NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-TRANSLATE NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-COMMON-LISP NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-IDL NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-JAVA NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-CPP NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-CPP-STANDALONE NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-LIST NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-KEY-VALUE-LIST NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-ITERATOR NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-BOOLEAN NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-WRAPPED-BOOLEAN NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-CONS NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-SUPPRESS-WARNINGS NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL
  *STELLA-MODULE*
  EOL
  *MODULE*
  *TRANSLATIONUNITS*
  *TRANSLATIONPHASE*
  CL-NIL))

;;; (DEFUN (INCREMENTALLY-TRANSLATE LISP-CODE) ...)

(CL:DEFUN INCREMENTALLY-TRANSLATE (STATEMENT DECLARATION?)
  (CL:LET*
   ((TOPLEVELINVOCATION? (NULL? *TRANSLATIONUNITS*))
    (TREE (STELLA-CODE-TO-CONS-TREE STATEMENT))
    (OCODE NULL)
    (LISPCODE NULL))
   (CL:LET*
    ((*TRANSLATIONUNITS* (NEW-LIST))
     (*TRANSLATIONVERBOSITYLEVEL* 0)
     (*TRANSLATIONPHASE* NULL)
     (*TRANSLATIONERRORS* 0)
     (*TRANSLATIONWARNINGS* 0))
    (CL:DECLARE
     (CL:SPECIAL
      *TRANSLATIONUNITS*
      *TRANSLATIONVERBOSITYLEVEL*
      *TRANSLATIONPHASE*
      *TRANSLATIONERRORS*
      *TRANSLATIONWARNINGS*))
    (CL:SETQ
     DECLARATION?
     (CL:IF
      (CL:OR
       (CL:EQ DECLARATION? 1)
       (CL:AND (CL:EQ (CONS? TREE) 1) (CL:EQ (DECLARATION-TREE? TREE) 1)))
      TRUE
      FALSE))
    (CL:COND
     ((CL:EQ DECLARATION? 1)
      (CL:SETQ *TRANSLATIONPHASE* KWD-STELLA-TO-CL-DEFINE)
      (WALK-TOP-LEVEL-TREE TREE FALSE)
      (CL:WHEN
       (CL:EQ (TRANSLATION-ERRORS?) 1)
       (SUMMARIZE-TRANSLATION-ERRORS)
       (CL:RETURN-FROM INCREMENTALLY-TRANSLATE CL-NIL))
      (REVERSE *TRANSLATIONUNITS*)
      (CL:SETQ *TRANSLATIONPHASE* KWD-STELLA-TO-CL-FINALIZE)
      (FINALIZE-CLASSES-AND-SLOTS)
      (CL:SETQ *TRANSLATIONPHASE* KWD-STELLA-TO-CL-WALK)
      (CL:WHEN (CL:EQ (USE-HARDCODED-SYMBOLS?) 0) (CLEAR-SYMBOL-REGISTRY))
      (WALK-ALL-PHASE-ONE-UNITS NULL))
     (CL:T
      (CL:SETQ *TRANSLATIONPHASE* KWD-STELLA-TO-CL-WALK)
      (CL:LET*
       ((*USEHARDCODEDSYMBOLS?* TRUE))
       (CL:DECLARE (CL:SPECIAL *USEHARDCODEDSYMBOLS?*))
       (CL:LET*
        ((*TRANSIENTOBJECTS?* TRUE))
        (CL:DECLARE (CL:SPECIAL *TRANSIENTOBJECTS?*))
        (CL:SETQ OCODE (WALK-TOP-LEVEL-EXPRESSION TREE))))))
    (CL:WHEN
     (CL:EQ (TRANSLATION-ERRORS?) 1)
     (SUMMARIZE-TRANSLATION-ERRORS)
     (CL:RETURN-FROM INCREMENTALLY-TRANSLATE CL-NIL))
    (CL:LET*
     ((*TRANSIENTOBJECTS?* TRUE))
     (CL:DECLARE (CL:SPECIAL *TRANSIENTOBJECTS?*))
     (CL:SETQ *TRANSLATIONPHASE* KWD-STELLA-TO-CL-TRANSLATE)
     (CL:COND
      ((CL:EQ DECLARATION? 1)
       (TRANSLATE-ALL-UNITS)
       (CL:SETQ OCODE (COMBINE-TRANSLATED-TREES)))
      (CL:T
       (CL:LET*
        ((*USEHARDCODEDSYMBOLS?* TRUE))
        (CL:DECLARE (CL:SPECIAL *USEHARDCODEDSYMBOLS?*))
        (CL:SETQ OCODE (TRANSLATE-WALKED-TREE OCODE))))))
    (CL:WHEN
     (CL:EQ (TRANSLATION-ERRORS?) 1)
     (SUMMARIZE-TRANSLATION-ERRORS)
     (CL:RETURN-FROM INCREMENTALLY-TRANSLATE CL-NIL))
    (CL:LET*
     ((TEST-VALUE-001 (TRANSLATOR-OUTPUT-LANGUAGE)))
     (CL:COND
      ((CL:EQ TEST-VALUE-001 KWD-STELLA-TO-CL-COMMON-LISP)
       (CL:SETQ LISPCODE (CONS-TREE-TO-LISP-CODE OCODE)))
      ((CL:EQ TEST-VALUE-001 KWD-STELLA-TO-CL-IDL)
       (IDL-OUTPUT-PARSE-TREE OCODE)
       (CL:SETQ LISPCODE (CONS-TREE-TO-LISP-CODE NIL)))
      ((CL:EQ TEST-VALUE-001 KWD-STELLA-TO-CL-JAVA)
       (JAVA-OUTPUT-PARSE-TREE OCODE)
       (CL:SETQ LISPCODE (CONS-TREE-TO-LISP-CODE NIL)))
      ((CL:OR
        (CL:EQ TEST-VALUE-001 KWD-STELLA-TO-CL-CPP)
        (CL:EQ TEST-VALUE-001 KWD-STELLA-TO-CL-CPP-STANDALONE))
       (CPP-OUTPUT-PARSE-TREE OCODE)
       (CL:SETQ LISPCODE (CONS-TREE-TO-LISP-CODE NIL)))
      (CL:T (CL:ERROR "`~A' is not a valid case option" TEST-VALUE-001))))
    (CL:LET*
     ((UNIT NULL)
      (ITER-001 (CLSYS-SVAL LIST THE-CONS-LIST *TRANSLATIONUNITS*)))
     (CL:LOOP
      WHILE
      (CL:NOT (CL:EQ ITER-001 NIL))
      DO
      (CL:PROGN
       (CL:SETQ UNIT (CLSYS-SVAL CONS VALUE ITER-001))
       (CL:SETQ ITER-001 (CLSYS-SVAL CONS REST ITER-001)))
      (FREE UNIT)))
    (CLEAR *TRANSLATIONUNITS*)
    (CL:WHEN (CL:EQ TOPLEVELINVOCATION? 1) (SWEEP-TRANSIENTS))
    (SUMMARIZE-TRANSLATION-ERRORS)
    (CL:RETURN-FROM INCREMENTALLY-TRANSLATE LISPCODE)))
  :VOID)

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFUN SAFELY-EXPAND-MACRO (FORM)
  "Run the translator over 'form' to obtain its expansion.
Guard against expansions that expand repeatedly
due to the head of the result matching the head of 'form'."
  (CL:LET
   ((HEAD (CL:AND (CL:CONSP FORM) (CL:CAR FORM)))
    (EXPANDEDFORM (INCREMENTALLY-TRANSLATE FORM FALSE)))
   (CL:IF
    (CL:AND (CL:CONSP EXPANDEDFORM) (CL:EQ HEAD (CL:CAR EXPANDEDFORM)))
    (CL:PROGN
     (CL:FORMAT CL:T "Can't expand the macro ~A~%" HEAD)
     (CL:RETURN-FROM SAFELY-EXPAND-MACRO NULL))
    (CL:RETURN-FROM SAFELY-EXPAND-MACRO EXPANDEDFORM))))

;;; (DEFUN (TOGGLE KEYWORD) ...)

(CL:DEFUN TOGGLE ()
  (CL:RETURN-FROM TOGGLE (TOGGLE-TRANSLATORS))
  :VOID)

;;; (VERBATIM :COMMON-LISP ...)

(CL:WHEN (CL:NOT (CL:FBOUNDP (CL:QUOTE EARLY-TRANSLATE))) (CL:DEFUN EARLY-TRANSLATE (STATEMENT) (INCREMENTALLY-TRANSLATE STATEMENT FALSE)))

;;; (DEFUN (BI-MODAL-TRANSLATE LISP-CODE) ...)

(CL:DEFUN BI-MODAL-TRANSLATE (STATEMENT)
  (CL:RETURN-FROM BI-MODAL-TRANSLATE (HELP-BI-MODAL-TRANSLATE STATEMENT))
  :VOID)

;;; (DEFUN (HELP-BI-MODAL-TRANSLATE LISP-CODE) ...)

(CL:DEFUN HELP-BI-MODAL-TRANSLATE (STATEMENT)
  (CL:IF
   (CL:EQ (USE-BOOTSTRAP-TRANSLATOR?) 1)
   (CL:LET*
    ((*USEHARDCODEDSYMBOLS?* TRUE))
    (CL:DECLARE (CL:SPECIAL *USEHARDCODEDSYMBOLS?*))
    (CL:RETURN-FROM HELP-BI-MODAL-TRANSLATE (EARLY-TRANSLATE STATEMENT)))
   (CL:RETURN-FROM
    HELP-BI-MODAL-TRANSLATE
    (INCREMENTALLY-TRANSLATE STATEMENT FALSE)))
  :VOID)

;;; (DEFUN (LISP-EVAL-IN-MODULE LISP-CODE) ...)

(CL:DEFUN LISP-EVAL-IN-MODULE (MODULENAME STATEMENT)
  (CL:LET*
   ((*MODULE* (GET-MODULE MODULENAME TRUE)) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:RETURN-FROM LISP-EVAL-IN-MODULE (CL:EVAL STATEMENT)))
  :VOID)

;;; (DEFUN (HELP-LISP-MACROEXPAND-IN-MODULE LISP-CODE) ...)

(CL:DEFUN HELP-LISP-MACROEXPAND-IN-MODULE (EXPANDER MODULENAME STATEMENT)
  (CL:LET*
   ((*MODULE* (GET-MODULE MODULENAME TRUE)) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:RETURN-FROM
    HELP-LISP-MACROEXPAND-IN-MODULE
    (CL:FUNCALL EXPANDER STATEMENT)))
  :VOID)

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMACRO LISP-MACROEXPAND-IN-MODULE (EXPANDER MODULENAME CL:&REST STATEMENTS)
  (CL:LET
   ((EXPANSIONS
     (CL:LOOP
      FOR
      STATEMENT
      IN
      STATEMENTS
      COLLECT
      (HELP-LISP-MACROEXPAND-IN-MODULE EXPANDER MODULENAME STATEMENT))))
   (CL:IF
    (CL:= (CL:LENGTH EXPANSIONS) 1)
    (CL:FIRST EXPANSIONS)
    (CL:CONS (CL:QUOTE CL:PROGN) EXPANSIONS))))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMACRO EVAL (STATEMENT)
  "Translate and evaluate a STELLA statement or expression."
  (CL:LIST
   (CL:QUOTE CL:EVAL)
   (CL:LIST
    (CL:QUOTE BI-MODAL-TRANSLATE)
    (CL:LIST (CL:QUOTE CL:QUOTE) STATEMENT))))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMACRO TRANS (STATEMENT)
  "Translate a STELLA statement or expression."
  (CL:LIST
   (CL:QUOTE BI-MODAL-TRANSLATE)
   (CL:LIST (CL:QUOTE CL:QUOTE) STATEMENT)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMACRO PTRANS (STATEMENT)
  "Print the translation of a STELLA statement or expression."
  (CL:PPRINT (BI-MODAL-TRANSLATE STATEMENT))
  ())

;;; (DEFUN (LISPIFY LISP-CODE) ...)

(CL:DEFUN LISPIFY (THING)
  "Convert a Stella 'thing' as much as possible into a
Common-Lisp analogue.  The currently supported 'thing' types are CONS, LIST,
KEY-VALUE-LIST, ITERATOR, SYMBOL, KEYWORD, and all wrapped and unwrapped
literal types.  BOOLEANs are translated into Lisp's CL:T and CL:NIL logic.
Unsupported types are left unchanged."
  (CL:IF
   (CL:EQ (CL:TYPEP THING (CL:QUOTE OBJECT)) CL-NIL)
   (CL:IF
    (CL:EQ (DEFINED? THING) 1)
    (CL:RETURN-FROM LISPIFY THING)
    (CL:RETURN-FROM LISPIFY CL-NIL))
   (CL:LET*
    ((THING-001 THING))
    (CL:COND
     ((CL:EQ (CONS? THING) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:WHEN (CL:EQ THING NIL) (CL:RETURN-FROM LISPIFY (CL:IDENTITY ())))
       (CL:LET*
        ((FIRST (LISPIFY (CLSYS-SVAL CONS VALUE THING)))
         (REST (LISPIFY (CLSYS-SVAL CONS REST THING))))
        (CL:RETURN-FROM LISPIFY (CL:CONS FIRST REST)))))
     ((CL:EQ (TAXONOMY-ISA? THING SGT-STELLA-TO-CL-LIST) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:RETURN-FROM
        LISPIFY
        (LISPIFY (CLSYS-SVAL LIST THE-CONS-LIST THING)))))
     ((CL:EQ (TAXONOMY-ISA? THING SGT-STELLA-TO-CL-KEY-VALUE-LIST) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:LET*
        ((RESULT CL-NIL))
        (CL:LET*
         ((VALUE NULL)
          (KEY NULL)
          (ITER-001 (CLSYS-SVAL KEY-VALUE-LIST THE-KV-LIST THING)))
         (CL:LOOP
          WHILE
          (CL:NOT (CL:EQ ITER-001 NULL))
          DO
          (CL:SETQ KEY (CLSYS-SVAL KV-CONS KEY ITER-001))
          (CL:PROGN
           (CL:SETQ VALUE (CLSYS-SVAL KV-CONS VALUE ITER-001))
           (CL:SETQ ITER-001 (CLSYS-SVAL KV-CONS REST ITER-001)))
          (CL:PUSH (CL:CONS (LISPIFY KEY) (LISPIFY VALUE)) RESULT)))
        (CL:RETURN-FROM LISPIFY (CL:NREVERSE RESULT)))))
     ((CL:EQ (TAXONOMY-ISA? THING SGT-STELLA-TO-CL-ITERATOR) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:RETURN-FROM LISPIFY (LISPIFY (LISTIFY THING)))))
     ((CL:EQ (SYMBOL? THING) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:RETURN-FROM
        LISPIFY
        (CONS-TREE-TO-LISP-CODE (CL-TRANSLATE-GLOBAL-SYMBOL THING)))))
     ((CL:EQ (KEYWORD? THING) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:RETURN-FROM LISPIFY (CONS-TREE-TO-LISP-CODE THING))))
     ((CL:EQ (BOOLEAN? THING) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:LET*
        ((TRUTHVALUE (CLSYS-SVAL BOOLEAN-WRAPPER WRAPPER-VALUE THING)))
        (CL:RETURN-FROM LISPIFY (TRUE-P TRUTHVALUE)))))
     ((CL:EQ (INTEGER? THING) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:RETURN-FROM
        LISPIFY
        (CLSYS-SVAL INTEGER-WRAPPER WRAPPER-VALUE THING))))
     ((CL:EQ (FLOAT? THING) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:RETURN-FROM
        LISPIFY
        (CLSYS-SVAL FLOAT-WRAPPER WRAPPER-VALUE THING))))
     ((CL:EQ (STRING? THING) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:RETURN-FROM
        LISPIFY
        (CLSYS-SVAL STRING-WRAPPER WRAPPER-VALUE THING))))
     ((CL:EQ (CHARACTER? THING) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:RETURN-FROM
        LISPIFY
        (CLSYS-SVAL CHARACTER-WRAPPER WRAPPER-VALUE THING))))
     ((CL:EQ (VERBATIM-STRING? THING) 1)
      (CL:LET*
       ((THING NULL))
       (CL:SETQ THING THING-001)
       (CL:RETURN-FROM LISPIFY (CONS-TREE-TO-LISP-CODE THING))))
     (CL:T (CL:RETURN-FROM LISPIFY THING)))))
  :VOID)

;;; (DEFUN (LISPIFY-BOOLEAN LISP-CODE) ...)

(CL:DEFUN LISPIFY-BOOLEAN (THING)
  "Lispify 'thing' which is assumed to be a (possibly wrapped) 
Stella boolean."
  (CL:IF
   (CL:EQ (CL:TYPEP THING (CL:QUOTE OBJECT)) CL-NIL)
   (CL:RETURN-FROM LISPIFY-BOOLEAN (TRUE-P THING))
   (CL:RETURN-FROM LISPIFY-BOOLEAN (LISPIFY THING)))
  :VOID)

;;; (DEFUN (STELLAFY OBJECT) ...)

(CL:DEFUN STELLAFY (THING TARGETTYPE)
  "Partial inverse to 'lispify'.  Convert the Lisp object 
'thing' into a Stella analogue of type 'targetType'."
  (CL:COND
   ((CL:OR
     (CL:EQ TARGETTYPE SGT-STELLA-TO-CL-BOOLEAN)
     (CL:EQ TARGETTYPE SGT-STELLA-TO-CL-WRAPPED-BOOLEAN))
    (CL:RETURN-FROM
     STELLAFY
     (WRAP-BOOLEAN (CL:IF (CL:NOT (CL:EQ THING CL-NIL)) TRUE FALSE))))
   ((CL:EQ TARGETTYPE SGT-STELLA-TO-CL-CONS)
    (CL:RETURN-FROM STELLAFY (PERMANENTIFY (STELLA-CODE-TO-CONS-TREE THING))))
   (CL:T
    (CL:IF
     (CL:EQ THING CL-NIL)
     (CL:RETURN-FROM STELLAFY NULL)
     (CL:RETURN-FROM
      STELLAFY
      (PERMANENTIFY (STELLA-CODE-TO-CONS-TREE THING))))))
  :VOID)

;;; (DEFUN (CL-SLOT-VALUE LISP-CODE) ...)

(CL:DEFUN CL-SLOT-VALUE (OBJECT SLOTNAME DONTCONVERT?)
  "Lookup slot 'slotName' on 'object' and return the lispified
slot value (see 'lispify').  If 'dontConvert?' is TRUE, the returned slot value
will not be lispified.  Generate a warning if no such slot exists on 'object'.
In a call directly from Lisp 'slotName' can also be supplied as a Lisp symbol."
  (SETQ SLOTNAME (CL:STRING SLOTNAME))
  (CL:LET*
   ((OBJECTTYPE (PRIMARY-TYPE OBJECT))
    (SLOT
     (SAFE-LOOKUP-SLOT
      (TYPE-TO-CLASS OBJECTTYPE)
      (INTERN-DERIVED-SYMBOL OBJECTTYPE SLOTNAME)))
    (VALUE NULL))
   (CL:WHEN
    (CL:EQ SLOT NULL)
    (CL:WARN
     "slot-value: Slot `~A' does not exist on object `~A'."
     SLOTNAME
     OBJECT)
    (CL:RETURN-FROM CL-SLOT-VALUE NULL))
   (CL:LET*
    ((SLOT-001 SLOT))
    (CL:COND
     ((CL:EQ (STORAGE-SLOT? SLOT) 1)
      (CL:LET*
       ((SLOT NULL))
       (CL:SETQ SLOT SLOT-001)
       (CL:SETQ VALUE (READ-SLOT-VALUE OBJECT SLOT))
       (CL:IF
        (CL:= DONTCONVERT? TRUE)
        (CL:RETURN-FROM CL-SLOT-VALUE VALUE)
        (CL:IF
         (CL:EQ (TYPE SLOT) SGT-STELLA-TO-CL-BOOLEAN)
         (CL:RETURN-FROM CL-SLOT-VALUE (LISPIFY-BOOLEAN VALUE))
         (CL:RETURN-FROM CL-SLOT-VALUE (LISPIFY VALUE))))))
     (CL:T
      (CL:WARN "slot-value: Cannot read method slots.")
      (CL:RETURN-FROM CL-SLOT-VALUE NULL)))))
  :VOID)

;;; (DEFUN (CL-SLOT-VALUE-SETTER LISP-CODE) ...)

(CL:DEFUN CL-SLOT-VALUE-SETTER (OBJECT SLOTNAME VALUE DONTCONVERT?)
  "Lookup slot 'slotName' on 'object' and set its value to
the stellafied 'value' (see 'stellafy').  If 'dontConvert?' is TRUE, 'value'
will not be stellafied before it gets assigned.  Generate a warning if no
such slot exists on 'object', or if 'value' has the wrong type.  In a call
directly from Lisp 'slotName' can also be supplied as a Lisp symbol."
  (SETQ SLOTNAME (CL:STRING SLOTNAME))
  (CL:LET*
   ((OBJECTTYPE (PRIMARY-TYPE OBJECT))
    (SLOT
     (SAFE-LOOKUP-SLOT
      (TYPE-TO-CLASS OBJECTTYPE)
      (INTERN-DERIVED-SYMBOL OBJECTTYPE SLOTNAME)))
    (STELLAVALUE VALUE))
   (CL:WHEN
    (CL:EQ SLOT NULL)
    (CL:WARN
     "slot-value-setter: Slot `~A' does not exist on object `~A'."
     SLOTNAME
     OBJECT)
    (CL:RETURN-FROM CL-SLOT-VALUE-SETTER NULL))
   (CL:WHEN
    (CL:NOT (CL:= DONTCONVERT? TRUE))
    (CL:SETQ STELLAVALUE (STELLAFY VALUE (TYPE SLOT))))
   (CL:WHEN
    (CL:NOT
     (CL:AND
      (CL:NOT (CL:EQ (CL:TYPEP STELLAVALUE (CL:QUOTE OBJECT)) CL-NIL))
      (CL:EQ
       (SUBTYPE-OF?
        (PRIMARY-TYPE STELLAVALUE)
        (TYPE-TO-WRAPPED-TYPE (TYPE SLOT)))
       1)))
    (CL:WARN
     "slot-value-setter: Illegal value type for slot `~A'~% on object `~A'.  Type `~A' expected."
     SLOTNAME
     OBJECT
     (TYPE SLOT))
    (CL:RETURN-FROM CL-SLOT-VALUE-SETTER NULL))
   (CL:LET*
    ((SLOT-001 SLOT))
    (CL:COND
     ((CL:EQ (STORAGE-SLOT? SLOT) 1)
      (CL:LET*
       ((SLOT NULL))
       (CL:SETQ SLOT SLOT-001)
       (WRITE-SLOT-VALUE OBJECT SLOT STELLAVALUE)))
     (CL:T
      (CL:WARN "slot-value-setter: Cannot write method slots.")
      (CL:RETURN-FROM CL-SLOT-VALUE-SETTER NULL))))
   (CL:RETURN-FROM CL-SLOT-VALUE-SETTER VALUE))
  :VOID)

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFUN SLOT-VALUE (OBJECT SLOTNAME CL:&OPTIONAL DONTCONVERT?)
  "See 'cl-slot-value'."
  (CL:IF
   (CL:OR (CL:NOT DONTCONVERT?) (CL:EQL DONTCONVERT? FALSE))
   (CL-SLOT-VALUE OBJECT SLOTNAME FALSE)
   (CL-SLOT-VALUE OBJECT SLOTNAME TRUE)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFUN SLOT-VALUE-SETTER (OBJECT SLOTNAME VALUE CL:&OPTIONAL DONTCONVERT?)
  "See 'cl-slot-value-setter'."
  (CL:IF
   (CL:OR (CL:NOT DONTCONVERT?) (CL:EQL DONTCONVERT? FALSE))
   (CL-SLOT-VALUE-SETTER OBJECT SLOTNAME VALUE FALSE)
   (CL-SLOT-VALUE-SETTER OBJECT SLOTNAME VALUE TRUE)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defsetf slot-value (object slot CL:&optional dontConvert?) (value)
     `(slot-value-setter ,object ,slot ,value ,dontConvert?))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro defmethod (name parameters CL:&body body)
    "Define a method and a method object named 'name'.  Keyword
options are :public? :native? :globally-inline? :inline :auxiliary?
:documentation :type :return-types :storage-slot :inherits-through."
    (bi-modal-translate (CL:list* '/stella/defmethod name parameters body)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro defun (name parameters CL:&body body)
    "Define a method and a method object named 'name'."
    (bi-modal-translate (CL:list* '/stella/defun name parameters body)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro defclass (name (CL::&rest supers) CL::&rest options)
    "Define a native (Lisp/C++) class and create a Stella class object.
   Class options:
     :slots :methods :abstract? :documentation
     :creator :initializer :terminator :destructor
     :recycle-method :cl-native-type :cpp-native-type
   Storage slot options:
     :type :initially :default :allocation :public?
   Method slot options:
     :abstract?"
    ;; Create a Stella class for use during preprocessing.
    ;; Expand to native code that, at initialize time, defines a native CLOS
    ;;    class, class creator, slot accessors, etc., and also redefines
    ;;    the Stella class.
    (bi-modal-translate (CL:list* '/stella/defclass name supers options)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro defslot (class name CL:&rest options)
    "Define an external storage slot with 'name' on the class named 'class'."
    (bi-modal-translate (CL:list* '/stella/defslot class name options)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro defglobal (variable type initialValue CL::&rest options)
    "Define a global variable 'variable' of type 'type' and initial value
'initialValue'.  Legal options are ':documentation' and ':public?'."
    (incrementally-translate
     (CL:list* '/stella/defglobal variable type initialValue options)
     TRUE))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro defconstant (variable type initialValue CL::&rest options)
    "Define a constant variable 'variable' of type 'type' and initial value
'initialValue'.  Legal options are ':documentation' and ':public?'."
    (incrementally-translate
     (CL:list* '/stella/defconstant variable type initialValue options)
     TRUE))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro defspecial (variable type CL:&optional initialValue
                           CL::&rest options)
    "Define a special variable 'variable' of type 'type' and initial value
'initialValue'.  Legal options are ':documentation' and ':public?'."
    (incrementally-translate
     (CL:list* '/stella/defspecial variable type initialValue options)
     TRUE))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro deftype (type definition CL::&rest options)
    "Define 'type' to be equivalent to 'definition'."
    (incrementally-translate
     (CL:list* '/stella/deftype type definition options)
     TRUE))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro defmacro (name parameters CL:&body body)
    "Define a Stella macro.  The macro expands into a function that
returns a cons tree representing a STELLA expression or statement.
The operators 'bquote', '&' and '&&' (corresponding to the Common Lisp
backquote, ',' and '.@' respectively) can be used to splice together code
expressions.  Just as '.@', '&&' operates using destructive concatenation
rather than an append."
    (incrementally-translate
     (CL:list* '/stella/defmacro name parameters body)
     TRUE))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro in-module (moduleName)
    "Change to the module named 'moduleName'"
    ;; Side-effect:  Switch to the STELLA package.
    `(CL:eval-when (CL:compile CL:load CL:eval)
       (CL:in-package "STELLA")
       ;; Guard against bootstrap problem:
       ,(CL:when (CL:fboundp 'change-module)
          `(/stella/cc ,moduleName))))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro defdemon (name parameters CL:&body body)
    "Define (or redefine) a demon named 'name'."
    (incrementally-translate
     (CL:list* '/stella/defdemon name parameters body) TRUE))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro startup-time-progn (CL:&body body)
    "Translate 'body' into a 'progn' executed at startup time."
    (bi-modal-translate (CL:list* '/stella/startup-time-progn body)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:LOOP FOR OPERATOR
  IN
  (CL:QUOTE
   (DEFMETHOD
    DEFUN
    DEFCLASS
    DEFSLOT
    DEFGLOBAL
    DEFCONSTANT
    DEFSPECIAL
    DEFTYPE
    DEFMACRO
    DEFMODULE
    DEFDEMON
    STARTUP-TIME-PROGN))
  DO
  (SETF
   (CL:MACRO-FUNCTION
    (CL:INTERN
     (CL:CONCATENATE
      (CL:QUOTE CL:STRING)
      "/STELLA/"
      (CL:SYMBOL-NAME OPERATOR))
     "STELLA"))
   (CL:MACRO-FUNCTION OPERATOR)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFUN CREATE-NATIVE-CLASS-P (SUPERS OPTIONS)
  (CL:DECLARE
   (CL:IGNORE SUPERS OPTIONS)
   (CL:SPECIAL *CREATE-NATIVE-CLASS-ENABLED*))
  *CREATE-NATIVE-CLASS-ENABLED*)

;;; (VERBATIM :COMMON-LISP ...)

(CL:progn
    (CL:defmacro verbatim (CL:&body body)
      "Translate 'body' into a 'verbatim' statement."
      (bi-modal-translate (CL:list* '/stella/verbatim body)))
    (CL:setf (CL:macro-function '/stella/verbatim)
      (CL:macro-function 'verbatim)))

(CL:DEFUN STARTUP-STELLA-TO-CL ()
  (CL:LET*
   ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 2) 1)
    (CL:SETQ
     KWD-STELLA-TO-CL-DEFINE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DEFINE" NULL 2))
    (CL:SETQ
     KWD-STELLA-TO-CL-FINALIZE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FINALIZE" NULL 2))
    (CL:SETQ
     KWD-STELLA-TO-CL-WALK
     (INTERN-RIGID-SYMBOL-WRT-MODULE "WALK" NULL 2))
    (CL:SETQ
     KWD-STELLA-TO-CL-TRANSLATE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "TRANSLATE" NULL 2))
    (CL:SETQ
     KWD-STELLA-TO-CL-COMMON-LISP
     (INTERN-RIGID-SYMBOL-WRT-MODULE "COMMON-LISP" NULL 2))
    (CL:SETQ
     KWD-STELLA-TO-CL-IDL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL" NULL 2))
    (CL:SETQ
     KWD-STELLA-TO-CL-JAVA
     (INTERN-RIGID-SYMBOL-WRT-MODULE "JAVA" NULL 2))
    (CL:SETQ
     KWD-STELLA-TO-CL-CPP
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CPP" NULL 2))
    (CL:SETQ
     KWD-STELLA-TO-CL-CPP-STANDALONE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CPP-STANDALONE" NULL 2))
    (CL:SETQ
     SGT-STELLA-TO-CL-LIST
     (INTERN-RIGID-SYMBOL-WRT-MODULE "LIST" NULL 1))
    (CL:SETQ
     SGT-STELLA-TO-CL-KEY-VALUE-LIST
     (INTERN-RIGID-SYMBOL-WRT-MODULE "KEY-VALUE-LIST" NULL 1))
    (CL:SETQ
     SGT-STELLA-TO-CL-ITERATOR
     (INTERN-RIGID-SYMBOL-WRT-MODULE "ITERATOR" NULL 1))
    (CL:SETQ
     SGT-STELLA-TO-CL-BOOLEAN
     (INTERN-RIGID-SYMBOL-WRT-MODULE "BOOLEAN" NULL 1))
    (CL:SETQ
     SGT-STELLA-TO-CL-WRAPPED-BOOLEAN
     (INTERN-RIGID-SYMBOL-WRT-MODULE "WRAPPED-BOOLEAN" NULL 1))
    (CL:SETQ
     SGT-STELLA-TO-CL-CONS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CONS" NULL 1))
    (CL:SETQ
     KWD-STELLA-TO-CL-SUPPRESS-WARNINGS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SUPPRESS-WARNINGS" NULL 2)))
   (CL:WHEN (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 6) 1) (FINALIZE-CLASSES))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 7) 1)
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "INCREMENTALLY-TRANSLATE"
        "LISP-CODE"
        "(DEFUN (INCREMENTALLY-TRANSLATE LISP-CODE) ((STATEMENT LISP-CODE) (DECLARATION? BOOLEAN)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION INCREMENTALLY-TRANSLATE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "TOGGLE"
        NULL
        "(DEFUN (TOGGLE KEYWORD) ())")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION TOGGLE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "BI-MODAL-TRANSLATE"
        "LISP-CODE"
        "(DEFUN (BI-MODAL-TRANSLATE LISP-CODE) ((STATEMENT LISP-CODE)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION BI-MODAL-TRANSLATE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "HELP-BI-MODAL-TRANSLATE"
        "LISP-CODE"
        "(DEFUN (HELP-BI-MODAL-TRANSLATE LISP-CODE) ((STATEMENT LISP-CODE)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION HELP-BI-MODAL-TRANSLATE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "LISP-EVAL-IN-MODULE"
        "STRING"
        "(DEFUN (LISP-EVAL-IN-MODULE LISP-CODE) ((MODULENAME STRING) (STATEMENT LISP-CODE)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION LISP-EVAL-IN-MODULE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "HELP-LISP-MACROEXPAND-IN-MODULE"
        "LISP-CODE"
        "(DEFUN (HELP-LISP-MACROEXPAND-IN-MODULE LISP-CODE) ((EXPANDER LISP-CODE) (MODULENAME STRING) (STATEMENT LISP-CODE)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION HELP-LISP-MACROEXPAND-IN-MODULE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "LISPIFY"
        "UNKNOWN"
        "(DEFUN (LISPIFY LISP-CODE) ((THING UNKNOWN)) :DOCUMENTATION \"Convert a Stella 'thing' as much as possible into a
Common-Lisp analogue.  The currently supported 'thing' types are CONS, LIST,
KEY-VALUE-LIST, ITERATOR, SYMBOL, KEYWORD, and all wrapped and unwrapped
literal types.  BOOLEANs are translated into Lisp's CL:T and CL:NIL logic.
Unsupported types are left unchanged.\" :PUBLIC? TRUE)")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION LISPIFY)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "LISPIFY-BOOLEAN"
        "UNKNOWN"
        "(DEFUN (LISPIFY-BOOLEAN LISP-CODE) ((THING UNKNOWN)) :DOCUMENTATION \"Lispify 'thing' which is assumed to be a (possibly wrapped) 
Stella boolean.\" :PUBLIC? TRUE)")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION LISPIFY-BOOLEAN)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "STELLAFY"
        "LISP-CODE"
        "(DEFUN (STELLAFY OBJECT) ((THING LISP-CODE) (TARGETTYPE TYPE)) :DOCUMENTATION \"Partial inverse to 'lispify'.  Convert the Lisp object 
'thing' into a Stella analogue of type 'targetType'.\" :PUBLIC? TRUE)")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION STELLAFY)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "CL-SLOT-VALUE"
        "OBJECT"
        "(DEFUN (CL-SLOT-VALUE LISP-CODE) ((OBJECT OBJECT) (SLOTNAME STRING) (DONTCONVERT? BOOLEAN)) :DOCUMENTATION \"Lookup slot 'slotName' on 'object' and return the lispified
slot value (see 'lispify').  If 'dontConvert?' is TRUE, the returned slot value
will not be lispified.  Generate a warning if no such slot exists on 'object'.
In a call directly from Lisp 'slotName' can also be supplied as a Lisp symbol.\" :PUBLIC? TRUE)")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION CL-SLOT-VALUE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "CL-SLOT-VALUE-SETTER"
        "OBJECT"
        "(DEFUN (CL-SLOT-VALUE-SETTER LISP-CODE) ((OBJECT OBJECT) (SLOTNAME STRING) (VALUE LISP-CODE) (DONTCONVERT? BOOLEAN)) :DOCUMENTATION \"Lookup slot 'slotName' on 'object' and set its value to
the stellafied 'value' (see 'stellafy').  If 'dontConvert?' is TRUE, 'value'
will not be stellafied before it gets assigned.  Generate a warning if no
such slot exists on 'object', or if 'value' has the wrong type.  In a call
directly from Lisp 'slotName' can also be supplied as a Lisp symbol.\" :PUBLIC? TRUE)")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION CL-SLOT-VALUE-SETTER)))
    (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
     "STARTUP-STELLA-TO-CL"
     NULL
     "(DEFUN STARTUP-STELLA-TO-CL ())"))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 8) 1)
    (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 9) 1)
    (ENABLE-ENVIRONMENT-FEATURE KWD-STELLA-TO-CL-SUPPRESS-WARNINGS)
    (CL:LET*
     ((DECL NULL)
      (ITER-005
       (ALLOCATE-ITERATOR
        (CL:IF
         (CL:BOUNDP (CL:QUOTE *EARLY-DEFGLOBALS*))
         (CL:REVERSE (CL:SYMBOL-VALUE (CL:QUOTE *EARLY-DEFGLOBALS*)))
         ()))))
     (CL:LOOP
      WHILE
      (CL:EQ (NEXT? ITER-005) 1)
      DO
      (CL:PROGN (CL:SETQ DECL (CLSYS-SVAL LISP-CONS-ITERATOR VALUE ITER-005)))
      (INCREMENTALLY-TRANSLATE DECL TRUE)))
    (DISABLE-ENVIRONMENT-FEATURE KWD-STELLA-TO-CL-SUPPRESS-WARNINGS)))
  :VOID)
