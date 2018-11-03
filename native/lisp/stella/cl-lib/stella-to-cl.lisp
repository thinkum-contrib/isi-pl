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

(CL:DEFVAR KWD-STELLA-TO-CL-DEFINE NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-FINALIZE NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-WALK NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-TRANSLATE NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-COMMON-LISP NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-IDL NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-JAVA NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-CPP NULL)
(CL:DEFVAR KWD-STELLA-TO-CL-CPP-STANDALONE NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-STELLA-CONS NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-STELLA-LIST NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-STELLA-KEY-VALUE-LIST NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-STELLA-ITERATOR NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-STELLA-BOOLEAN NULL)
(CL:DEFVAR SGT-STELLA-TO-CL-STELLA-WRAPPED-BOOLEAN NULL)
(CL:DEFVAR SYM-STELLA-TO-CL-STELLA-STARTUP-STELLA-TO-CL NULL)
(CL:DEFVAR SYM-STELLA-TO-CL-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STELLA-MODULE* EOL TRUE-WRAPPER FALSE-WRAPPER *MODULE*
  *TRANSLATIONUNITS* *TRANSLATIONPHASE* CL-NIL *TRANSLATOROUTPUTLANGUAGE*))

;;; (DEFUN (INCREMENTALLY-TRANSLATE LISP-CODE) ...)

(CL:DEFUN INCREMENTALLY-TRANSLATE (STATEMENT DECLARATION?)
  (CL:LET*
   ((TOPLEVELINVOCATION? (CL:EQ *TRANSLATIONUNITS* NULL)) (TREE NULL)
    (OCODE NULL) (LISPCODE NULL))
   (CL:LET* ((*TRANSIENTOBJECTS?* TRUE))
    (CL:DECLARE (CL:SPECIAL *TRANSIENTOBJECTS?*))
    (CL:SETQ TREE (STELLA-CODE-TO-CONS-TREE STATEMENT)))
   (CL:LET*
    ((*TRANSLATIONUNITS* (NEW-LIST)) (*TRANSLATIONVERBOSITYLEVEL* 0)
     (*TRANSLATIONPHASE* NULL) (*TRANSLATIONERRORS* 0)
     (*TRANSLATIONWARNINGS* 0))
    (CL:DECLARE
     (CL:SPECIAL *TRANSLATIONUNITS* *TRANSLATIONVERBOSITYLEVEL*
      *TRANSLATIONPHASE* *TRANSLATIONERRORS* *TRANSLATIONWARNINGS*))
    (CL:DECLARE
     (CL:TYPE CL:FIXNUM *TRANSLATIONVERBOSITYLEVEL* *TRANSLATIONERRORS*
      *TRANSLATIONWARNINGS*))
    (CL:SETQ DECLARATION?
     (CL:OR DECLARATION? (CL:AND (CONS? TREE) (DECLARATION-TREE? TREE))))
    (CL:COND
     (DECLARATION? (CL:SETQ *TRANSLATIONPHASE* KWD-STELLA-TO-CL-DEFINE)
      (WALK-TOP-LEVEL-TREE TREE FALSE)
      (CL:WHEN (TRANSLATION-ERRORS?) (SUMMARIZE-TRANSLATION-ERRORS)
       (CL:RETURN-FROM INCREMENTALLY-TRANSLATE CL-NIL))
      (REVERSE *TRANSLATIONUNITS*)
      (CL:SETQ *TRANSLATIONPHASE* KWD-STELLA-TO-CL-FINALIZE)
      (FINALIZE-CLASSES-AND-SLOTS)
      (CL:SETQ *TRANSLATIONPHASE* KWD-STELLA-TO-CL-WALK)
      (CL:WHEN (CL:NOT (USE-HARDCODED-SYMBOLS?)) (CLEAR-SYMBOL-REGISTRY))
      (WALK-ALL-PHASE-ONE-UNITS))
     (CL:T (CL:SETQ *TRANSLATIONPHASE* KWD-STELLA-TO-CL-WALK)
      (CL:LET* ((*USEHARDCODEDSYMBOLS?* TRUE))
       (CL:DECLARE (CL:SPECIAL *USEHARDCODEDSYMBOLS?*))
       (CL:SETQ OCODE (WALK-TOP-LEVEL-EXPRESSION TREE)))))
    (CL:WHEN (TRANSLATION-ERRORS?) (SUMMARIZE-TRANSLATION-ERRORS)
     (CL:RETURN-FROM INCREMENTALLY-TRANSLATE CL-NIL))
    (CL:SETQ *TRANSLATIONPHASE* KWD-STELLA-TO-CL-TRANSLATE)
    (CL:COND
     (DECLARATION? (TRANSLATE-ALL-UNITS)
      (CL:SETQ OCODE (COMBINE-TRANSLATED-TREES)))
     (CL:T
      (CL:LET* ((*USEHARDCODEDSYMBOLS?* TRUE))
       (CL:DECLARE (CL:SPECIAL *USEHARDCODEDSYMBOLS?*))
       (CL:SETQ OCODE (TRANSLATE-WALKED-TREE OCODE)))))
    (CL:WHEN (TRANSLATION-ERRORS?) (SUMMARIZE-TRANSLATION-ERRORS)
     (CL:RETURN-FROM INCREMENTALLY-TRANSLATE CL-NIL))
    (CL:COND
     ((CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-STELLA-TO-CL-COMMON-LISP)
      (CL:SETQ LISPCODE (CONS-TREE-TO-LISP-CODE OCODE)))
     ((CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-STELLA-TO-CL-IDL)
      (IDL-OUTPUT-PARSE-TREE OCODE)
      (CL:SETQ LISPCODE (CONS-TREE-TO-LISP-CODE NIL)))
     ((CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-STELLA-TO-CL-JAVA)
      (JAVA-OUTPUT-PARSE-TREE OCODE)
      (CL:SETQ LISPCODE (CONS-TREE-TO-LISP-CODE NIL)))
     ((CL:OR (CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-STELLA-TO-CL-CPP)
       (CL:EQ *TRANSLATOROUTPUTLANGUAGE* KWD-STELLA-TO-CL-CPP-STANDALONE))
      (CPP-OUTPUT-PARSE-TREE OCODE)
      (CL:SETQ LISPCODE (CONS-TREE-TO-LISP-CODE NIL)))
     (CL:T
      (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
       (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`"
        *TRANSLATOROUTPUTLANGUAGE* "' is not a valid case option")
       (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
    (CL:LET* ((UNIT NULL) (ITER-000 (%THE-CONS-LIST *TRANSLATIONUNITS*)))
     (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
      (CL:PROGN (CL:SETQ UNIT (%%VALUE ITER-000))
       (CL:SETQ ITER-000 (%%REST ITER-000)))
      (FREE UNIT)))
    (CLEAR *TRANSLATIONUNITS*)
    (CL:WHEN TOPLEVELINVOCATION? (SWEEP-TRANSIENTS))
    (SUMMARIZE-TRANSLATION-ERRORS)
    (CL:RETURN-FROM INCREMENTALLY-TRANSLATE LISPCODE))))

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
    (CL:PROGN (CL:FORMAT CL:T "Can't expand the macro ~A~%" HEAD)
     (CL:RETURN-FROM SAFELY-EXPAND-MACRO NULL))
    (CL:RETURN-FROM SAFELY-EXPAND-MACRO EXPANDEDFORM))))

;;; (DEFUN (BI-MODAL-TRANSLATE LISP-CODE) ...)

(CL:DEFUN BI-MODAL-TRANSLATE (STATEMENT)
  (CL:RETURN-FROM BI-MODAL-TRANSLATE (HELP-BI-MODAL-TRANSLATE STATEMENT)))

;;; (DEFUN (HELP-BI-MODAL-TRANSLATE LISP-CODE) ...)

(CL:DEFUN HELP-BI-MODAL-TRANSLATE (STATEMENT)
  (CL:RETURN-FROM HELP-BI-MODAL-TRANSLATE
   (INCREMENTALLY-TRANSLATE STATEMENT FALSE)))

;;; (DEFUN (LISP-EVAL-IN-MODULE LISP-CODE) ...)

(CL:DEFUN LISP-EVAL-IN-MODULE (MODULENAME STATEMENT)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING MODULENAME))
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE MODULENAME TRUE)) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:RETURN-FROM LISP-EVAL-IN-MODULE (CL:EVAL STATEMENT))))

;;; (DEFUN (HELP-LISP-MACROEXPAND-IN-MODULE LISP-CODE) ...)

(CL:DEFUN HELP-LISP-MACROEXPAND-IN-MODULE (EXPANDER MODULENAME STATEMENT)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING MODULENAME))
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE MODULENAME TRUE)) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:RETURN-FROM HELP-LISP-MACROEXPAND-IN-MODULE
    (CL:FUNCALL EXPANDER STATEMENT))))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMACRO LISP-MACROEXPAND-IN-MODULE (EXPANDER MODULENAME CL:&REST STATEMENTS)
  (CL:LET
   ((EXPANSIONS
     (CL:LOOP FOR STATEMENT IN STATEMENTS COLLECT
      (HELP-LISP-MACROEXPAND-IN-MODULE EXPANDER MODULENAME STATEMENT))))
   (CL:IF (CL:= (CL:LENGTH EXPANSIONS) 1) (CL:FIRST EXPANSIONS)
    (CL:CONS (CL:QUOTE CL:PROGN) EXPANSIONS))))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro eval (statement)
    "Translate and evaluate a STELLA statement or expression."
    (CL:list
     'CL:eval (CL:list 'bi-modal-translate (CL:list 'CL:quote statement))))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro trans (statement)
    "Translate a STELLA statement or expression."
    (CL:list 'bi-modal-translate (CL:list 'CL:quote statement)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro ptrans (statement)
    "Print the translation of a STELLA statement or expression."  
    (CL:pprint (bi-modal-translate statement))
    CL:nil)

;;; (DEFUN (LISPIFY LISP-CODE) ...)

(CL:DEFUN LISPIFY (THING)
  "Convert a Stella 'thing' as much as possible into a
Common-Lisp analogue.  The currently supported 'thing' types are CONS, LIST,
KEY-VALUE-LIST, ITERATOR, SYMBOL, KEYWORD, and all wrapped and unwrapped
literal types.  BOOLEANs are translated into Lisp's CL:T and CL:NIL logic.
Unsupported types are left unchanged."
  (CL:IF
   (CL:EQ
    (CL:OR (CL:TYPEP THING (CL:QUOTE OBJECT))
     (CL:AND (CL:LISTP NIL) (CL:LISTP THING)))
    CL-NIL)
   (CL:IF (DEFINED? THING) (CL:RETURN-FROM LISPIFY THING)
    (CL:RETURN-FROM LISPIFY CL-NIL))
   (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE THING)))
    (CL:COND
     ((CL:EQ TEST-VALUE-000 SGT-STELLA-TO-CL-STELLA-CONS)
      (CL:PROGN
       (CL:WHEN (CL:EQ THING NIL)
        (CL:RETURN-FROM LISPIFY (CL:IDENTITY CL-NIL)))
       (CL:LET*
        ((FIRST (LISPIFY (%%VALUE THING)))
         (REST (LISPIFY (%%REST THING))))
        (CL:RETURN-FROM LISPIFY (CL:CONS FIRST REST)))))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-STELLA-TO-CL-STELLA-LIST)
      (CL:PROGN
       (CL:RETURN-FROM LISPIFY (LISPIFY (%THE-CONS-LIST THING)))))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-STELLA-TO-CL-STELLA-KEY-VALUE-LIST)
      (CL:PROGN
       (CL:LET* ((RESULT CL-NIL))
        (CL:LET* ((VALUE NULL) (KEY NULL) (ITER-000 (%THE-KV-LIST THING)))
         (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NULL)) DO
          (CL:SETQ KEY (%KEY ITER-000))
          (CL:PROGN (CL:SETQ VALUE (%VALUE ITER-000))
           (CL:SETQ ITER-000 (%REST ITER-000)))
          (CL:PUSH (CL:CONS (LISPIFY KEY) (LISPIFY VALUE)) RESULT)))
        (CL:RETURN-FROM LISPIFY (CL:NREVERSE RESULT)))))
     ((SUBTYPE-OF? TEST-VALUE-000 SGT-STELLA-TO-CL-STELLA-ITERATOR)
      (CL:PROGN (CL:RETURN-FROM LISPIFY (LISPIFY (LISTIFY THING)))))
     ((SUBTYPE-OF-SYMBOL? TEST-VALUE-000)
      (CL:PROGN
       (CL:RETURN-FROM LISPIFY
        (CONS-TREE-TO-LISP-CODE (CL-TRANSLATE-GLOBAL-SYMBOL THING)))))
     ((SUBTYPE-OF-KEYWORD? TEST-VALUE-000)
      (CL:PROGN (CL:RETURN-FROM LISPIFY (CONS-TREE-TO-LISP-CODE THING))))
     ((SUBTYPE-OF-BOOLEAN? TEST-VALUE-000)
      (CL:PROGN
       (CL:LET* ((TRUTHVALUE (%WRAPPER-VALUE THING)))
        (CL:RETURN-FROM LISPIFY TRUTHVALUE))))
     ((SUBTYPE-OF-VERBATIM-STRING? TEST-VALUE-000)
      (CL:PROGN (CL:RETURN-FROM LISPIFY (CONS-TREE-TO-LISP-CODE THING))))
     ((SUBTYPE-OF-INTEGER? TEST-VALUE-000)
      (CL:PROGN (CL:RETURN-FROM LISPIFY (%WRAPPER-VALUE THING))))
     ((SUBTYPE-OF-FLOAT? TEST-VALUE-000)
      (CL:PROGN (CL:RETURN-FROM LISPIFY (%WRAPPER-VALUE THING))))
     ((SUBTYPE-OF-STRING? TEST-VALUE-000)
      (CL:PROGN (CL:RETURN-FROM LISPIFY (%WRAPPER-VALUE THING))))
     ((SUBTYPE-OF-CHARACTER? TEST-VALUE-000)
      (CL:PROGN (CL:RETURN-FROM LISPIFY (%WRAPPER-VALUE THING))))
     (CL:T (CL:RETURN-FROM LISPIFY THING))))))

;;; (DEFUN (LISPIFY-BOOLEAN LISP-CODE) ...)

(CL:DEFUN LISPIFY-BOOLEAN (THING)
  "Lispify 'thing' which is assumed to be a (possibly wrapped) 
Stella boolean."
  (CL:IF (CL:NOT (CL:typep thing 'OBJECT))
   (CL:RETURN-FROM LISPIFY-BOOLEAN THING)
   (CL:RETURN-FROM LISPIFY-BOOLEAN (LISPIFY THING))))

;;; (DEFUN (STELLAFY OBJECT) ...)

(CL:DEFUN STELLAFY (THING TARGETTYPE)
  "Partial inverse to 'lispify'.  Convert the Lisp object 
'thing' into a Stella analogue of type 'targetType'.
Note: See also 'stellify'. it is similar, but guesses 'targetType' on its own,
and makes somewhat different translations."
  (CL:COND
   ((CL:OR (CL:EQ TARGETTYPE SGT-STELLA-TO-CL-STELLA-BOOLEAN)
     (CL:EQ TARGETTYPE SGT-STELLA-TO-CL-STELLA-WRAPPED-BOOLEAN))
    (CL:RETURN-FROM STELLAFY
     (CL:IF (CL:NOT (CL:EQ THING CL-NIL)) TRUE-WRAPPER FALSE-WRAPPER)))
   ((CL:EQ TARGETTYPE SGT-STELLA-TO-CL-STELLA-CONS)
    (CL:RETURN-FROM STELLAFY (STELLA-CODE-TO-CONS-TREE THING)))
   (CL:T
    (CL:IF (CL:EQ THING CL-NIL) (CL:RETURN-FROM STELLAFY NULL)
     (CL:RETURN-FROM STELLAFY (STELLA-CODE-TO-CONS-TREE THING))))))

;;; (DEFUN (CL-SLOT-VALUE LISP-CODE) ...)

(CL:DEFUN CL-SLOT-VALUE (OBJECT SLOTNAME DONTCONVERT?)
  "Lookup slot 'slotName' on 'object' and return the lispified
slot value (see 'lispify').  If 'dontConvert?' is TRUE, the returned slot value
will not be lispified.  Generate a warning if no such slot exists on 'object'.
In a call directly from Lisp 'slotName' can also be supplied as a Lisp symbol."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SLOTNAME))
  (SETQ SLOTNAME (CL:STRING SLOTNAME))
  (CL:LET*
   ((OBJECTTYPE (PRIMARY-TYPE OBJECT))
    (SLOT
     (SAFE-LOOKUP-SLOT (TYPE-TO-CLASS OBJECTTYPE)
      (INTERN-DERIVED-SYMBOL OBJECTTYPE SLOTNAME)))
    (VALUE NULL))
   (CL:WHEN (CL:EQ SLOT NULL)
    (CL:WARN "slot-value: Slot `~A' does not exist on object `~A'."
     SLOTNAME OBJECT)
    (CL:RETURN-FROM CL-SLOT-VALUE NULL))
   (CL:COND
    ((SUBTYPE-OF-STORAGE-SLOT? (SAFE-PRIMARY-TYPE SLOT))
     (CL:PROGN (CL:SETQ VALUE (READ-SLOT-VALUE OBJECT SLOT))
      (CL:IF (CL:EQ DONTCONVERT? TRUE)
       (CL:RETURN-FROM CL-SLOT-VALUE VALUE)
       (CL:IF (CL:EQ (TYPE SLOT) SGT-STELLA-TO-CL-STELLA-BOOLEAN)
        (CL:RETURN-FROM CL-SLOT-VALUE (LISPIFY-BOOLEAN VALUE))
        (CL:RETURN-FROM CL-SLOT-VALUE (LISPIFY VALUE))))))
    (CL:T (CL:WARN "slot-value: Cannot read method slots.")
     (CL:RETURN-FROM CL-SLOT-VALUE NULL)))))

;;; (DEFUN (CL-SLOT-VALUE-SETTER LISP-CODE) ...)

(CL:DEFUN CL-SLOT-VALUE-SETTER (OBJECT SLOTNAME VALUE DONTCONVERT?)
  "Lookup slot 'slotName' on 'object' and set its value to
the stellafied 'value' (see 'stellafy').  If 'dontConvert?' is TRUE, 'value'
will not be stellafied before it gets assigned.  Generate a warning if no
such slot exists on 'object', or if 'value' has the wrong type.  In a call
directly from Lisp 'slotName' can also be supplied as a Lisp symbol."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SLOTNAME))
  (SETQ SLOTNAME (CL:STRING SLOTNAME))
  (CL:LET*
   ((OBJECTTYPE (PRIMARY-TYPE OBJECT))
    (SLOT
     (SAFE-LOOKUP-SLOT (TYPE-TO-CLASS OBJECTTYPE)
      (INTERN-DERIVED-SYMBOL OBJECTTYPE SLOTNAME)))
    (STELLAVALUE VALUE))
   (CL:WHEN (CL:EQ SLOT NULL)
    (CL:WARN "slot-value-setter: Slot `~A' does not exist on object `~A'."
     SLOTNAME OBJECT)
    (CL:RETURN-FROM CL-SLOT-VALUE-SETTER NULL))
   (CL:WHEN (CL:NOT (CL:EQ DONTCONVERT? TRUE))
    (CL:SETQ STELLAVALUE (STELLAFY VALUE (TYPE SLOT))))
   (CL:WHEN
    (CL:NOT
     (CL:AND
      (CL:NOT (CL:EQ (CL:TYPEP STELLAVALUE (CL:QUOTE OBJECT)) CL-NIL))
      (SUBTYPE-OF? (PRIMARY-TYPE STELLAVALUE)
       (TYPE-TO-WRAPPED-TYPE (TYPE SLOT)))))
    (CL:WARN
     "slot-value-setter: Illegal value type for slot `~A'~% on object `~A'.  Type `~A' expected."
     SLOTNAME OBJECT (TYPE SLOT))
    (CL:RETURN-FROM CL-SLOT-VALUE-SETTER NULL))
   (CL:COND
    ((SUBTYPE-OF-STORAGE-SLOT? (SAFE-PRIMARY-TYPE SLOT))
     (CL:PROGN (WRITE-SLOT-VALUE OBJECT SLOT STELLAVALUE)))
    (CL:T (CL:WARN "slot-value-setter: Cannot write method slots.")
     (CL:RETURN-FROM CL-SLOT-VALUE-SETTER NULL)))
   (CL:RETURN-FROM CL-SLOT-VALUE-SETTER VALUE)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFUN SLOT-VALUE (OBJECT SLOTNAME CL:&OPTIONAL DONTCONVERT?)
  "See 'cl-slot-value'."
  (CL:IF (CL:OR (CL:NOT DONTCONVERT?) (CL:EQL DONTCONVERT? FALSE))
   (CL-SLOT-VALUE OBJECT SLOTNAME FALSE)
   (CL-SLOT-VALUE OBJECT SLOTNAME TRUE)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFUN SLOT-VALUE-SETTER (OBJECT SLOTNAME VALUE CL:&OPTIONAL DONTCONVERT?)
  "See 'cl-slot-value-setter'."
  (CL:IF (CL:OR (CL:NOT DONTCONVERT?) (CL:EQL DONTCONVERT? FALSE))
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

(CL:defmacro defdemon (name parameters CL:&body body)
    "Define (or redefine) a demon named 'name'."
    (incrementally-translate
     (CL:list* '/stella/defdemon name parameters body) TRUE))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmacro startup-time-progn (CL:&body body)
    "Translate 'body' into a 'progn' executed at startup time."
    (bi-modal-translate (CL:list* '/stella/startup-time-progn body)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:loop for operator in '(defmethod defun defclass defslot
                             defglobal defconstant defspecial deftype
                             defmacro defmodule defdemon
                             startup-time-progn)
      do (CL:setf (CL:macro-function
                   (CL:intern
                    (CL:concatenate
                      'CL:string "/STELLA/" (CL:symbol-name operator))
                    "STELLA"))
           (CL:macro-function operator)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFUN CREATE-NATIVE-CLASS-P (SUPERS OPTIONS)
  (CL:DECLARE (CL:IGNORE SUPERS OPTIONS)
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
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ KWD-STELLA-TO-CL-DEFINE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DEFINE" NULL 2))
    (CL:SETQ KWD-STELLA-TO-CL-FINALIZE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FINALIZE" NULL 2))
    (CL:SETQ KWD-STELLA-TO-CL-WALK
     (INTERN-RIGID-SYMBOL-WRT-MODULE "WALK" NULL 2))
    (CL:SETQ KWD-STELLA-TO-CL-TRANSLATE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "TRANSLATE" NULL 2))
    (CL:SETQ KWD-STELLA-TO-CL-COMMON-LISP
     (INTERN-RIGID-SYMBOL-WRT-MODULE "COMMON-LISP" NULL 2))
    (CL:SETQ KWD-STELLA-TO-CL-IDL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL" NULL 2))
    (CL:SETQ KWD-STELLA-TO-CL-JAVA
     (INTERN-RIGID-SYMBOL-WRT-MODULE "JAVA" NULL 2))
    (CL:SETQ KWD-STELLA-TO-CL-CPP
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CPP" NULL 2))
    (CL:SETQ KWD-STELLA-TO-CL-CPP-STANDALONE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CPP-STANDALONE" NULL 2))
    (CL:SETQ SGT-STELLA-TO-CL-STELLA-CONS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CONS" NULL 1))
    (CL:SETQ SGT-STELLA-TO-CL-STELLA-LIST
     (INTERN-RIGID-SYMBOL-WRT-MODULE "LIST" NULL 1))
    (CL:SETQ SGT-STELLA-TO-CL-STELLA-KEY-VALUE-LIST
     (INTERN-RIGID-SYMBOL-WRT-MODULE "KEY-VALUE-LIST" NULL 1))
    (CL:SETQ SGT-STELLA-TO-CL-STELLA-ITERATOR
     (INTERN-RIGID-SYMBOL-WRT-MODULE "ITERATOR" NULL 1))
    (CL:SETQ SGT-STELLA-TO-CL-STELLA-BOOLEAN
     (INTERN-RIGID-SYMBOL-WRT-MODULE "BOOLEAN" NULL 1))
    (CL:SETQ SGT-STELLA-TO-CL-STELLA-WRAPPED-BOOLEAN
     (INTERN-RIGID-SYMBOL-WRT-MODULE "WRAPPED-BOOLEAN" NULL 1))
    (CL:SETQ SYM-STELLA-TO-CL-STELLA-STARTUP-STELLA-TO-CL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-STELLA-TO-CL" NULL 0))
    (CL:SETQ SYM-STELLA-TO-CL-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "INCREMENTALLY-TRANSLATE"
     "(DEFUN (INCREMENTALLY-TRANSLATE LISP-CODE) ((STATEMENT LISP-CODE) (DECLARATION? BOOLEAN)))"
     (CL:FUNCTION INCREMENTALLY-TRANSLATE) NULL)
    (DEFINE-FUNCTION-OBJECT "BI-MODAL-TRANSLATE"
     "(DEFUN (BI-MODAL-TRANSLATE LISP-CODE) ((STATEMENT LISP-CODE)))"
     (CL:FUNCTION BI-MODAL-TRANSLATE) NULL)
    (DEFINE-FUNCTION-OBJECT "HELP-BI-MODAL-TRANSLATE"
     "(DEFUN (HELP-BI-MODAL-TRANSLATE LISP-CODE) ((STATEMENT LISP-CODE)))"
     (CL:FUNCTION HELP-BI-MODAL-TRANSLATE) NULL)
    (DEFINE-FUNCTION-OBJECT "LISP-EVAL-IN-MODULE"
     "(DEFUN (LISP-EVAL-IN-MODULE LISP-CODE) ((MODULENAME STRING) (STATEMENT LISP-CODE)))"
     (CL:FUNCTION LISP-EVAL-IN-MODULE) NULL)
    (DEFINE-FUNCTION-OBJECT "HELP-LISP-MACROEXPAND-IN-MODULE"
     "(DEFUN (HELP-LISP-MACROEXPAND-IN-MODULE LISP-CODE) ((EXPANDER LISP-CODE) (MODULENAME STRING) (STATEMENT LISP-CODE)))"
     (CL:FUNCTION HELP-LISP-MACROEXPAND-IN-MODULE) NULL)
    (DEFINE-FUNCTION-OBJECT "LISPIFY"
     "(DEFUN (LISPIFY LISP-CODE) ((THING UNKNOWN)) :DOCUMENTATION \"Convert a Stella 'thing' as much as possible into a
Common-Lisp analogue.  The currently supported 'thing' types are CONS, LIST,
KEY-VALUE-LIST, ITERATOR, SYMBOL, KEYWORD, and all wrapped and unwrapped
literal types.  BOOLEANs are translated into Lisp's CL:T and CL:NIL logic.
Unsupported types are left unchanged.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LISPIFY) NULL)
    (DEFINE-FUNCTION-OBJECT "LISPIFY-BOOLEAN"
     "(DEFUN (LISPIFY-BOOLEAN LISP-CODE) ((THING UNKNOWN)) :DOCUMENTATION \"Lispify 'thing' which is assumed to be a (possibly wrapped) 
Stella boolean.\" :PUBLIC? TRUE)" (CL:FUNCTION LISPIFY-BOOLEAN) NULL)
    (DEFINE-FUNCTION-OBJECT "STELLAFY"
     "(DEFUN (STELLAFY OBJECT) ((THING LISP-CODE) (TARGETTYPE TYPE)) :DOCUMENTATION \"Partial inverse to 'lispify'.  Convert the Lisp object 
'thing' into a Stella analogue of type 'targetType'.
Note: See also 'stellify'. it is similar, but guesses 'targetType' on its own,
and makes somewhat different translations.\" :PUBLIC? TRUE)"
     (CL:FUNCTION STELLAFY) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-SLOT-VALUE"
     "(DEFUN (CL-SLOT-VALUE LISP-CODE) ((OBJECT OBJECT) (SLOTNAME STRING) (DONTCONVERT? BOOLEAN)) :DOCUMENTATION \"Lookup slot 'slotName' on 'object' and return the lispified
slot value (see 'lispify').  If 'dontConvert?' is TRUE, the returned slot value
will not be lispified.  Generate a warning if no such slot exists on 'object'.
In a call directly from Lisp 'slotName' can also be supplied as a Lisp symbol.\" :PUBLIC? TRUE)"
     (CL:FUNCTION CL-SLOT-VALUE) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-SLOT-VALUE-SETTER"
     "(DEFUN (CL-SLOT-VALUE-SETTER LISP-CODE) ((OBJECT OBJECT) (SLOTNAME STRING) (VALUE LISP-CODE) (DONTCONVERT? BOOLEAN)) :DOCUMENTATION \"Lookup slot 'slotName' on 'object' and set its value to
the stellafied 'value' (see 'stellafy').  If 'dontConvert?' is TRUE, 'value'
will not be stellafied before it gets assigned.  Generate a warning if no
such slot exists on 'object', or if 'value' has the wrong type.  In a call
directly from Lisp 'slotName' can also be supplied as a Lisp symbol.\" :PUBLIC? TRUE)"
     (CL:FUNCTION CL-SLOT-VALUE-SETTER) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-STELLA-TO-CL"
     "(DEFUN STARTUP-STELLA-TO-CL () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-STELLA-TO-CL) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION SYM-STELLA-TO-CL-STELLA-STARTUP-STELLA-TO-CL)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-STELLA-TO-CL-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "Startup-Stella-To-Cl") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES)))
  :VOID)
