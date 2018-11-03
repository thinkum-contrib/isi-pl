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

(CL:DEFVAR SGT-CL-PRIMAL-STELLA-CONS NULL)
(CL:DEFVAR SYM-CL-PRIMAL-STELLA-STARTUP-CL-PRIMAL NULL)
(CL:DEFVAR SYM-CL-PRIMAL-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STELLA-MODULE* *MODULE*))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFVAR NULL :NULL_VALUE)

;;; (VERBATIM :COMMON-LISP ...)

(CL:defvar NULL-STRING (cl:make-string 1 :initial-element (CL:code-char 0)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defvar NULL-NATIVE-VECTOR (cl:vector))

;;; (DEFCONSTANT CL-NIL ...)

(CL:DEFVAR CL-NIL (CL:OR))

;;; (VERBATIM :COMMON-LISP ...)

#-lispworks
   (CL:defmethod print-object ((self (CL:eql NULL)) stream)
     (CL:write-string "NULL" stream))

;;; (VERBATIM :COMMON-LISP ...)

#-lispworks
   (CL:defmethod print-object ((self (CL:eql NULL-INTEGER)) stream)
     (CL:write-string "NULL-INTEGER" stream))

;;; (VERBATIM :COMMON-LISP ...)

#-lispworks
   (CL:defmethod print-object ((self (CL:eql NULL-FLOAT)) stream)
     (CL:write-string "NULL-FLOAT" stream))

;;; (VERBATIM :COMMON-LISP ...)

(CL:defmethod cl:print-object ((self (CL:eql CL:NIL)) stream)
     (CL:write-string "()" stream))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:T))
  (CL:EQ VALUE NULL))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:INTEGER))
  (CL:OR (CL:NOT (CL:TYPEP VALUE (CL:QUOTE CL:FIXNUM)))
   (CL:= VALUE NULL-INTEGER)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:FLOAT))
  (CL:= VALUE NULL-FLOAT))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:CHARACTER))
  (CL:EQ VALUE NULL-CHARACTER))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:STRING))
  (CL:EQ VALUE NULL-STRING))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:VECTOR))
  (CL:EQ VALUE NULL-NATIVE-VECTOR))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:T))
  (CL:NOT (CL:EQ VALUE NULL)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:INTEGER))
  (CL:AND (CL:TYPEP VALUE (CL:QUOTE CL:FIXNUM))
   (CL:NOT (CL:= VALUE NULL-INTEGER))))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:FLOAT))
  (CL:NOT (CL:= VALUE NULL-FLOAT)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:CHARACTER))
  (CL:NOT (CL:EQ VALUE NULL-CHARACTER)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:STRING))
  (CL:NOT (CL:EQ VALUE NULL-STRING)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:VECTOR))
  (CL:NOT (CL:EQ VALUE NULL-NATIVE-VECTOR)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFUN EQ? (X Y)
  "Equality test equivalent to the C++ '==' and the Common Lisp 'EQL'."
  (CL:EQL X Y))

;;; (DEFUN (> BOOLEAN) ...)

(CL:DEFUN > (X Y)
  (CL:RETURN-FROM > (CL:> X Y)))

;;; (DEFUN (>= BOOLEAN) ...)

(CL:DEFUN >= (X Y)
  (CL:RETURN-FROM >= (CL:>= X Y)))

;;; (DEFUN (< BOOLEAN) ...)

(CL:DEFUN < (X Y)
  (CL:RETURN-FROM < (CL:< X Y)))

;;; (DEFUN (<= BOOLEAN) ...)

(CL:DEFUN <= (X Y)
  (CL:RETURN-FROM <= (CL:<= X Y)))

;;; (DEFUN (+ NUMBER) ...)

(CL:DEFUN + (X Y)
  (CL:RETURN-FROM + (CL:+ X Y)))

;;; (DEFUN (- NUMBER) ...)

(CL:DEFUN - (X Y)
  (CL:RETURN-FROM - (CL:- X Y)))

;;; (DEFUN (* NUMBER) ...)

(CL:DEFUN * (X Y)
  (CL:RETURN-FROM * (CL:* X Y)))

;;; (DEFUN (/ NUMBER) ...)

(CL:DEFUN / (X Y)
  (CL:RETURN-FROM / (CL:/ X Y)))

;;; (DEFUN (CEILING INTEGER) ...)

(CL:DEFUN CEILING (N)
  (CL:RETURN-FROM CEILING (CL:CEILING N)))

;;; (DEFUN (FLOOR INTEGER) ...)

(CL:DEFUN FLOOR (N)
  (CL:RETURN-FROM FLOOR (CL:FLOOR N)))

;;; (DEFUN (EXP FLOAT) ...)

(CL:DEFUN EXP (X)
  "The natural exponentiation function e^x."
  (CL:DECLARE (CL:TYPE CL:DOUBLE-FLOAT X))
  (CL:RETURN-FROM EXP (CL:EXP X)))

;;; (DEFUN (INTEGER-LENGTH INTEGER) ...)

(CL:DEFUN INTEGER-LENGTH (ARG)
  "The number of bits needed to represent `arg'"
  (CL:DECLARE (CL:TYPE CL:FIXNUM ARG))
  (CL:RETURN-FROM INTEGER-LENGTH (CL:INTEGER-LENGTH ARG)))

;;; (DEFUN (MAKE-STRING STRING) ...)

(CL:DEFUN MAKE-STRING (SIZE INITCHAR)
  "Return a new string filled with 'size' 'initchar's."
  (CL:DECLARE (CL:TYPE CL:FIXNUM SIZE))
  (CL:RETURN-FROM MAKE-STRING
   (CL:MAKE-STRING SIZE :INITIAL-ELEMENT INITCHAR)))

;;; (DEFUN (STRING-CONCATENATE STRING) ...)

(CL:DEFUN STRING-CONCATENATE (STRING1 STRING2)
  "Return a new string representing the concatenation of
'string1' and 'string2'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING1 STRING2))
  (CL:RETURN-FROM STRING-CONCATENATE
   (CL:CONCATENATE (CL:QUOTE CL:STRING) STRING1 STRING2)))

;;; (DEFUN (STRING-UPCASE STRING) ...)

(CL:DEFUN STRING-UPCASE (STRING)
  "Return an upper-case copy of 'string'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  (CL:RETURN-FROM STRING-UPCASE (CL:STRING-UPCASE STRING)))

;;; (DEFUN (STRING-DOWNCASE STRING) ...)

(CL:DEFUN STRING-DOWNCASE (STRING)
  "Return a lower-case copy of 'string'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  (CL:RETURN-FROM STRING-DOWNCASE (CL:STRING-DOWNCASE STRING)))

;;; (DEFUN (STRING-CAPITALIZE STRING) ...)

(CL:DEFUN STRING-CAPITALIZE (STRING)
  "Return a capitalized version of 'string'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  (CL:RETURN-FROM STRING-CAPITALIZE (CL:STRING-CAPITALIZE STRING)))

;;; (DEFMETHOD (COPY STRING) ...)

(CL:DEFMETHOD COPY ((STRING CL:STRING))
  "Return a copy of 'string'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  (CL:RETURN-FROM COPY (CL:COPY-SEQ STRING)))

;;; (DEFMETHOD (REMOVE STRING) ...)

(CL:DEFMETHOD REMOVE ((STRING CL:STRING) CHAR)
  "Remove all occurences of 'char' from 'string'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  (CL:RETURN-FROM REMOVE (CL:REMOVE CHAR STRING)))

;;; (DEFMETHOD (SUBSTITUTE MUTABLE-STRING) ...)

(CL:DEFMETHOD SUBSTITUTE ((SELF CL:STRING) NEWCHAR OLDCHAR)
  "Substitute all occurences of oldChar with newChar
in the string 'self'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF))
  (CL:RETURN-FROM SUBSTITUTE (CL:SUBSTITUTE NEWCHAR OLDCHAR SELF)))

;;; (DEFMETHOD (MEMBER? BOOLEAN) ...)

(CL:DEFMETHOD MEMBER? ((SELF CL:STRING) CHAR)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF))
  (CL:RETURN-FROM MEMBER? (CL:NOT (CL:NULL (CL:FIND CHAR SELF)))))

;;; (DEFMETHOD (REST STRING) ...)

(CL:DEFMETHOD REST ((SELF CL:STRING))
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF))
  (CL:RETURN-FROM REST (CL:SUBSEQ SELF 1)))

;;; (DEFMETHOD (POSITION INTEGER) ...)

(CL:DEFMETHOD POSITION ((STRING CL:STRING) CHARACTER START)
  "Return the position of 'character' within 'string' (counting
from zero); or return NULL if 'character' does not occur within 'string'.
If 'start' was supplied as non-NULL, only consider the substring starting
at 'start', however, the returned position will always be relative to the
entire string."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING) (CL:TYPE CL:FIXNUM START))
  (CL:WHEN (NULL? START) (CL:SETQ START 0))
  (CL:RETURN-FROM POSITION
   (CL:OR (CL:POSITION CHARACTER STRING :START START) NULL-INTEGER)))

;;; (DEFUN (STRING-SEARCH INTEGER) ...)

(CL:DEFUN STRING-SEARCH (STRING SUBSTRING START)
  "Return start position of the left-most occurrence right of
'start' of 'substring' in 'string'.  Return NULL if it is not a substring."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING SUBSTRING)
   (CL:TYPE CL:FIXNUM START))
  (CL:WHEN (NULL? START) (CL:SETQ START 0))
  (CL:RETURN-FROM STRING-SEARCH
   (CL:OR (CL:SEARCH SUBSTRING STRING :START2 START) NULL-INTEGER)))

;;; (DEFMETHOD (SUBSEQUENCE STRING) ...)

(CL:DEFMETHOD SUBSEQUENCE ((STRING CL:STRING) START END)
  "Return a substring of 'string' beginning at position 'start'
and ending up to but not including position 'end', counting from zero.  An
'end' value of NULL stands for the rest of the string."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING)
   (CL:TYPE CL:FIXNUM START END))
  (CL:LET* ((NULLEND? (NULL? END)))
   (CL:RETURN-FROM SUBSEQUENCE
    (CL:SUBSEQ STRING START (CL:IF NULLEND? CL:NIL END)))))

;;; (DEFUN (STRINGIFY STRING) ...)

(CL:DEFUN STRINGIFY (EXPRESSION)
  (CL:LET* ((*PRINTPRETTY?* FALSE) (*PRINTREADABLY?* TRUE))
   (CL:DECLARE (CL:SPECIAL *PRINTPRETTY?* *PRINTREADABLY?*))
   (CL:RETURN-FROM STRINGIFY
    (CL:LET ((CL:*PRINT-PRETTY* CL:NIL))
     (CL:WITH-OUTPUT-TO-STRING (S) (%%PRINT-OBJECT S EXPRESSION))))))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFVAR *STANDARD-READTABLE* (CL:COPY-READTABLE CL:NIL))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFVAR *CASE-SENSITIVE-READTABLE* (CL:COPY-READTABLE CL:NIL))

;;; (VERBATIM :COMMON-LISP ...)

(CL:progn
    #+(or :ANSI-CL :CLTL2)
    (CL:setf (CL:readtable-case *case-sensitive-readtable*) :preserve))

;;; (DEFUN (OLD-CL-READ-S-EXPRESSION-FROM-STRING OBJECT) ...)

(CL:DEFUN OLD-CL-READ-S-EXPRESSION-FROM-STRING (STRING)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  (CL:LET* ((CASESENSITIVE? (%CASE-SENSITIVE? *MODULE*)))
   (CL:RETURN-FROM OLD-CL-READ-S-EXPRESSION-FROM-STRING
    (STELLA-CODE-TO-CONS-TREE
     (CL:LET
      ((CL:*PACKAGE* (CL:FIND-PACKAGE "STELLA"))
       (CL:*READTABLE*
        (CL:IF CASESENSITIVE? *CASE-SENSITIVE-READTABLE*
         *STANDARD-READTABLE*)))
      (CL:HANDLER-CASE (CL:READ-FROM-STRING STRING)
       (CL:STREAM-ERROR ()
        (CL:ERROR (NEW-READ-EXCEPTION ">> Unstringify: Parse error~%")))
       (CL:ERROR (C)
        (CL:ERROR
         (NEW-UNHANDLED-EXCEPTION
          (CL:FORMAT NIL "Unstringify: Caught unhandled exception ~A.~%"
           C))))))))))

;;; (DEFUN (INTEGER-TO-STRING STRING) ...)

(CL:DEFUN INTEGER-TO-STRING (INTEGER)
  "Return a string representation of 'integer'."
  (CL:DECLARE (CL:TYPE CL:FIXNUM INTEGER))
  (CL:RETURN-FROM INTEGER-TO-STRING
   (CL:let ((buffer "                                ")
                (table "0123456789")
                (index 32)
                (digit 0))
         (CL:declare (CL:type CL:simple-string buffer table)
                     (CL:type CL:fixnum index digit))
         (CL:cond
          ((CL:= integer 0) "0")
          (CL:t
           (CL:loop while (CL:> integer 0)
               do (CL:decf index)
                  (CL:multiple-value-setq (integer digit)
                    (CL:floor integer 10))
                  (CL:setf (CL:aref buffer index)
                    (CL:aref table digit)))
           (CL:subseq buffer index 32))))))

;;; (DEFUN (FLOAT-TO-STRING STRING) ...)

(CL:DEFUN FLOAT-TO-STRING (FLOAT)
  "Return a string representation of 'float'."
  (CL:DECLARE (CL:TYPE CL:DOUBLE-FLOAT FLOAT))
  (CL:RETURN-FROM FLOAT-TO-STRING (CL:FORMAT CL-NIL "~A" FLOAT)))

;;; (DEFUN (FORMAT-FLOAT STRING) ...)

(CL:DEFUN FORMAT-FLOAT (VALUE NDECIMALS)
  "Return a string representation of 'float' with 'nDecimals' decimal places."
  (CL:DECLARE (CL:TYPE CL:DOUBLE-FLOAT VALUE)
   (CL:TYPE CL:FIXNUM NDECIMALS))
  (CL:RETURN-FROM FORMAT-FLOAT (CL:FORMAT CL-NIL "~,vF" NDECIMALS VALUE)))

;;; (DEFUN (STRING-TO-INTEGER INTEGER) ...)

(CL:DEFUN STRING-TO-INTEGER (STRING)
  "Convert the 'string' representation of an integer into an
integer and return the result."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  (CL:RETURN-FROM STRING-TO-INTEGER (CL:PARSE-INTEGER STRING)))

;;; (DEFUN (STRING-TO-FLOAT FLOAT) ...)

(CL:DEFUN STRING-TO-FLOAT (STRING)
  "Convert the 'string' representation of a float into a
float and return the result."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  (CL:RETURN-FROM STRING-TO-FLOAT
   (CL:LET ((CL:*read-default-float-format* (CL:quote CL:double-float)))
               (CL:float (CL:read-from-string string) 0.0d0))))

;;; (DEFUN (STELLA-CODE-TO-CONS-TREE OBJECT) ...)

(CL:DEFUN STELLA-CODE-TO-CONS-TREE (STELLACODE)
  (CL:COND
   ((CL:NULL STELLACODE) (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE NIL))
   ((CL:CONSP STELLACODE)
    (CL:LET* ((CONSTREE NIL))
     (CL:LOOP FOR ELEMENT IN STELLACODE DO
      (SETQ CONSTREE (CONS (STELLA-CODE-TO-CONS-TREE ELEMENT) CONSTREE)))
     (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE (REVERSE CONSTREE))))
   ((CL:SYMBOLP STELLACODE)
    (CL:LET* ((NAME (CL:SYMBOL-NAME STELLACODE)))
     (CL:WHEN (CL:KEYWORDP STELLACODE)
      (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE (INTERN-KEYWORD NAME)))
     (CL:IF
      (CL:AND
       (CL:EQL (CL:SYMBOL-PACKAGE STELLACODE)
        (CL:SYMBOL-PACKAGE (CL:QUOTE CL:EVAL)))
       (CL:NOT (CL:EQ (CL:FIND-SYMBOL NAME "STELLA") STELLACODE)))
      (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE
       (INTERN-COMMON-LISP-SYMBOL NAME))
      (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE
       (INTERN-GENERALIZED-SYMBOL NAME)))))
   ((CL:INTEGERP STELLACODE)
    (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE
     (WRAP-INTEGER (CL:TRUNCATE STELLACODE))))
   ((CL:FLOATP STELLACODE)
    (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE
     (WRAP-FLOAT (CL:FLOAT (CL:float stellaCode 0.0d0) 0.0d0))))
   ((CL:STRINGP STELLACODE)
    (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE (WRAP-STRING STELLACODE)))
   ((CL:CHARACTERP STELLACODE)
    (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE (WRAP-CHARACTER STELLACODE)))
   (CL:T (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE STELLACODE))))

;;; (DEFUN (CONS-TREE-TO-LISP-CODE LISP-CODE) ...)

(CL:DEFUN CONS-TREE-TO-LISP-CODE (STELLATREE)
  (CL:WHEN (CL:EQ STELLATREE NULL)
   (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE (CL:QUOTE NULL)))
  (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE STELLATREE)))
   (CL:COND
    ((CL:EQ TEST-VALUE-000 SGT-CL-PRIMAL-STELLA-CONS)
     (CL:PROGN
      (CL:IF (CL:EQ STELLATREE NIL)
       (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE CL-NIL)
       (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
        (CL:CONS (CONS-TREE-TO-LISP-CODE (%%VALUE STELLATREE))
         (CONS-TREE-TO-LISP-CODE (%%REST STELLATREE)))))))
    ((SUBTYPE-OF-KEYWORD? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (CL:INTERN (%SYMBOL-NAME STELLATREE) "KEYWORD"))))
    ((SUBTYPE-OF-SYMBOL? TEST-VALUE-000)
     (CL:PROGN
      (CL:LET*
       ((TRANSLATEDSYMBOL (CL-TRANSLATE-GLOBAL-SYMBOL STELLATREE)))
       (CL:COND
        ((SYMBOL? TRANSLATEDSYMBOL)
         (CL:LET* ((NAME (%SYMBOL-NAME TRANSLATEDSYMBOL)))
          (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING NAME))
          (CL:IF (SYMBOL-COMMON-LISP? TRANSLATEDSYMBOL)
           (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
            (CL:INTERN NAME "COMMON-LISP"))
           (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
            (CL:INTERN NAME "STELLA")))))
        (CL:T
         (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
          (CONS-TREE-TO-LISP-CODE TRANSLATEDSYMBOL)))))))
    ((SUBTYPE-OF-SURROGATE? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (CL:INTERN (CONCATENATE "@" (%SYMBOL-NAME STELLATREE)) "STELLA"))))
    ((SUBTYPE-OF-VERBATIM-STRING? TEST-VALUE-000)
     (CL:PROGN
      (CL:LET*
       ((VERBATIMSTRING (%WRAPPER-VALUE STELLATREE))
        (PACKAGENAME (LISP-PACKAGE *MODULE*)))
       (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING VERBATIMSTRING PACKAGENAME))
       (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
        (CL:LET ((CL:*PACKAGE* (CL:FIND-PACKAGE PACKAGENAME)))
         (CL:READ-FROM-STRING VERBATIMSTRING))))))
    ((SUBTYPE-OF-INTEGER? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (%WRAPPER-VALUE STELLATREE))))
    ((SUBTYPE-OF-FLOAT? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (%WRAPPER-VALUE STELLATREE))))
    ((SUBTYPE-OF-STRING? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (%WRAPPER-VALUE STELLATREE))))
    ((SUBTYPE-OF-CHARACTER? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (%WRAPPER-VALUE STELLATREE))))
    ((SUBTYPE-OF-BOOLEAN? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (%WRAPPER-VALUE STELLATREE))))
    (CL:T
     (CL:WARN
      "cons-tree-to-lisp-code: Don't know how to convert `~A' into LISP-CODE"
      STELLATREE)
     (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
      (CL:FORMAT CL-NIL "~s" STELLATREE))))))

;;; (DEFUN (CONS-LIST-TO-LISP-LIST LISP-CODE) ...)

(CL:DEFUN CONS-LIST-TO-LISP-LIST (LIST)
  (CL:LET* ((LISPLIST CL-NIL))
   (CL:LET* ((ITEM NULL) (ITER-000 LIST))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:PROGN (CL:SETQ ITEM (%%VALUE ITER-000))
      (CL:SETQ ITER-000 (%%REST ITER-000)))
     (CL:PUSH ITEM LISPLIST)))
   (CL:RETURN-FROM CONS-LIST-TO-LISP-LIST (CL:NREVERSE LISPLIST))))

;;; (DEFUN (OLD-CL-READ-S-EXPRESSION OBJECT BOOLEAN) ...)

(CL:DEFUN OLD-CL-READ-S-EXPRESSION (INPUTSTREAM)
  (CL:LET*
   ((STREAM (%NATIVE-STREAM INPUTSTREAM)) (EOFVALUE :EOF)
    (CASESENSITIVE? (%CASE-SENSITIVE? *MODULE*))
    (INPUT
     (CL:LET
      ((CL:*PACKAGE* (CL:FIND-PACKAGE "STELLA"))
       (CL:*READTABLE*
        (CL:IF CASESENSITIVE? *CASE-SENSITIVE-READTABLE*
         *STANDARD-READTABLE*)))
      (CL:READ STREAM CL-NIL EOFVALUE))))
   (CL:IF (CL:EQ INPUT EOFVALUE)
    (CL:RETURN-FROM OLD-CL-READ-S-EXPRESSION (CL:VALUES NULL TRUE))
    (CL:RETURN-FROM OLD-CL-READ-S-EXPRESSION
     (CL:VALUES (STELLA-CODE-TO-CONS-TREE INPUT) FALSE)))))

;;; (DEFUN TOGGLE-CL-BASED-READERS ...)

(CL:DEFUN TOGGLE-CL-BASED-READERS ()
  (CL:let ((unstringify
               (CL:symbol-function 'read-s-expression-from-string))
              (oldUnstringify
               (CL:symbol-function 'old-cl-read-s-expression-from-string))
              (readSExp
               (CL:symbol-function 'read-s-expression))
              (oldReadSExp
               (CL:symbol-function 'old-cl-read-s-expression)))
       (CL:setf (CL:symbol-function 'read-s-expression-from-string)
         oldUnstringify)
       (CL:setf (CL:symbol-function 'old-cl-read-s-expression-from-string)
         unstringify)
       (CL:setf (CL:symbol-function 'read-s-expression) oldReadSExp)
       (CL:setf (CL:symbol-function 'old-cl-read-s-expression) readSExp)
       (CL:setf (CL:get 'old-cl-read-s-expression 'old-cl-readers-active?)
         (CL:not (CL:get 'old-cl-read-s-expression 'old-cl-readers-active?)))
       (CL:if (CL:get 'old-cl-read-s-expression 'old-cl-readers-active?)
           (CL:format CL:t "Activated old CL-based readers.~%")
         (CL:format CL:t "Activated new STELLA-based readers.~%")))
  :VOID)

;;; (DEFUN (PROBE-FILE? BOOLEAN) ...)

(CL:DEFUN PROBE-FILE? (FILENAME)
  (CL:SETQ FILENAME (TRANSLATE-LOGICAL-PATHNAME FILENAME))
  (CL:RETURN-FROM PROBE-FILE?
   (CL:NOT (CL:NULL (CL:IGNORE-ERRORS (CL:PROBE-FILE FILENAME))))))

;;; (DEFUN (FILE-WRITE-DATE INTEGER) ...)

(CL:DEFUN FILE-WRITE-DATE (FILENAME)
  (CL:SETQ FILENAME (TRANSLATE-LOGICAL-PATHNAME FILENAME))
  (CL:RETURN-FROM FILE-WRITE-DATE
   (CL:OR (CL:FILE-WRITE-DATE FILENAME) NULL-INTEGER)))

;;; (DEFUN (FILE-LENGTH INTEGER) ...)

(CL:DEFUN FILE-LENGTH (FILENAME)
  (CL:SETQ FILENAME (TRANSLATE-LOGICAL-PATHNAME FILENAME))
  (CL:RETURN-FROM FILE-LENGTH
   (CL:WITH-OPEN-FILE (FSTREAM FILENAME :DIRECTION :INPUT)
    (CL:FILE-LENGTH FSTREAM))))

;;; (DEFUN DELETE-FILE ...)

(CL:DEFUN DELETE-FILE (FILENAME)
  (CL:SETQ FILENAME (TRANSLATE-LOGICAL-PATHNAME FILENAME))
  (CL:DELETE-FILE FILENAME)
  :VOID)

;;; (DEFUN (GET-TICKTOCK TICKTOCK) ...)

(CL:DEFUN GET-TICKTOCK ()
  (CL:RETURN-FROM GET-TICKTOCK (CL:GET-INTERNAL-RUN-TIME)))

;;; (DEFUN (TICKTOCK-DIFFERENCE FLOAT) ...)

(CL:DEFUN TICKTOCK-DIFFERENCE (T1 T2)
  "The difference in two TICKTOCK time values in seconds.
The resolution is implementation dependent but will normally be some fractional
value of a second."
  (CL:RETURN-FROM TICKTOCK-DIFFERENCE
   (CL:/ (CL:FLOAT (CL:- T2 T1))
    (CL:FLOAT CL:INTERNAL-TIME-UNITS-PER-SECOND))))

;;; (DEFUN (TICKTOCK-RESOLUTION FLOAT) ...)

(CL:DEFUN TICKTOCK-RESOLUTION ()
  "The minimum theoretically detectable resolution of the
difference in two TICKTOCK time values in seconds.  This resolution is
implementation dependent.  It may also not be realizable in practice, since
the timing grain size may be larger than this resolution."
  (CL:RETURN-FROM TICKTOCK-RESOLUTION
   (CL:FLOAT (CL:/ (CL:FLOAT CL:INTERNAL-TIME-UNITS-PER-SECOND)))))

(CL:DEFUN STARTUP-CL-PRIMAL ()
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ SGT-CL-PRIMAL-STELLA-CONS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CONS" NULL 1))
    (CL:SETQ SYM-CL-PRIMAL-STELLA-STARTUP-CL-PRIMAL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-CL-PRIMAL" NULL 0))
    (CL:SETQ SYM-CL-PRIMAL-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT ">"
     "(DEFUN (> BOOLEAN) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION >) NULL)
    (DEFINE-FUNCTION-OBJECT ">="
     "(DEFUN (>= BOOLEAN) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION >=) NULL)
    (DEFINE-FUNCTION-OBJECT "<"
     "(DEFUN (< BOOLEAN) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION <) NULL)
    (DEFINE-FUNCTION-OBJECT "<="
     "(DEFUN (<= BOOLEAN) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION <=) NULL)
    (DEFINE-FUNCTION-OBJECT "+"
     "(DEFUN (+ NUMBER) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION +) NULL)
    (DEFINE-FUNCTION-OBJECT "-"
     "(DEFUN (- NUMBER) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION -) NULL)
    (DEFINE-FUNCTION-OBJECT "*"
     "(DEFUN (* NUMBER) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION *) NULL)
    (DEFINE-FUNCTION-OBJECT "/"
     "(DEFUN (/ NUMBER) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION /) NULL)
    (DEFINE-FUNCTION-OBJECT "CEILING"
     "(DEFUN (CEILING INTEGER) ((N NUMBER)))" (CL:FUNCTION CEILING) NULL)
    (DEFINE-FUNCTION-OBJECT "FLOOR" "(DEFUN (FLOOR INTEGER) ((N NUMBER)))"
     (CL:FUNCTION FLOOR) NULL)
    (DEFINE-FUNCTION-OBJECT "EXP"
     "(DEFUN (EXP FLOAT) ((X FLOAT)) :PUBLIC? TRUE :DOCUMENTATION \"The natural exponentiation function e^x.\")"
     (CL:FUNCTION EXP) NULL)
    (DEFINE-FUNCTION-OBJECT "INTEGER-LENGTH"
     "(DEFUN (INTEGER-LENGTH INTEGER) ((ARG INTEGER)) :PUBLIC? TRUE :DOCUMENTATION \"The number of bits needed to represent `arg'\")"
     (CL:FUNCTION INTEGER-LENGTH) NULL)
    (DEFINE-FUNCTION-OBJECT "MAKE-STRING"
     "(DEFUN (MAKE-STRING STRING) ((SIZE INTEGER) (INITCHAR CHARACTER)) :DOCUMENTATION \"Return a new string filled with 'size' 'initchar's.\" :PUBLIC? TRUE)"
     (CL:FUNCTION MAKE-STRING) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-CONCATENATE"
     "(DEFUN (STRING-CONCATENATE STRING) ((STRING1 STRING) (STRING2 STRING)) :DOCUMENTATION \"Return a new string representing the concatenation of
'string1' and 'string2'.\")" (CL:FUNCTION STRING-CONCATENATE) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-UPCASE"
     "(DEFUN (STRING-UPCASE STRING) ((STRING STRING)) :DOCUMENTATION \"Return an upper-case copy of 'string'.\")"
     (CL:FUNCTION STRING-UPCASE) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-DOWNCASE"
     "(DEFUN (STRING-DOWNCASE STRING) ((STRING STRING)) :DOCUMENTATION \"Return a lower-case copy of 'string'.\")"
     (CL:FUNCTION STRING-DOWNCASE) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-CAPITALIZE"
     "(DEFUN (STRING-CAPITALIZE STRING) ((STRING STRING)) :DOCUMENTATION \"Return a capitalized version of 'string'.\")"
     (CL:FUNCTION STRING-CAPITALIZE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (COPY STRING) ((STRING STRING)) :DOCUMENTATION \"Return a copy of 'string'.\")"
     (CL:FUNCTION COPY) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (REMOVE STRING) ((STRING STRING) (CHAR CHARACTER)) :DOCUMENTATION \"Remove all occurences of 'char' from 'string'.\")"
     (CL:FUNCTION REMOVE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (SUBSTITUTE MUTABLE-STRING) ((SELF MUTABLE-STRING) (NEWCHAR CHARACTER) (OLDCHAR CHARACTER)) :DOCUMENTATION \"Substitute all occurences of oldChar with newChar
in the string 'self'.\")" (CL:FUNCTION SUBSTITUTE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF STRING) (CHAR CHARACTER)))"
     (CL:FUNCTION MEMBER?) NULL)
    (DEFINE-METHOD-OBJECT "(DEFMETHOD (REST STRING) ((SELF STRING)))"
     (CL:FUNCTION REST) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (POSITION INTEGER) ((STRING STRING) (CHARACTER CHARACTER) (START INTEGER)) :DOCUMENTATION \"Return the position of 'character' within 'string' (counting
from zero); or return NULL if 'character' does not occur within 'string'.
If 'start' was supplied as non-NULL, only consider the substring starting
at 'start', however, the returned position will always be relative to the
entire string.\" :PUBLIC? TRUE)" (CL:FUNCTION POSITION) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-SEARCH"
     "(DEFUN (STRING-SEARCH INTEGER) ((STRING STRING) (SUBSTRING STRING) (START INTEGER)) :DOCUMENTATION \"Return start position of the left-most occurrence right of
'start' of 'substring' in 'string'.  Return NULL if it is not a substring.\")"
     (CL:FUNCTION STRING-SEARCH) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (SUBSEQUENCE STRING) ((STRING STRING) (START INTEGER) (END INTEGER)) :DOCUMENTATION \"Return a substring of 'string' beginning at position 'start'
and ending up to but not including position 'end', counting from zero.  An
'end' value of NULL stands for the rest of the string.\")"
     (CL:FUNCTION SUBSEQUENCE) NULL)
    (DEFINE-FUNCTION-OBJECT "STRINGIFY"
     "(DEFUN (STRINGIFY STRING) ((EXPRESSION OBJECT)))"
     (CL:FUNCTION STRINGIFY) NULL)
    (DEFINE-FUNCTION-OBJECT "OLD-CL-READ-S-EXPRESSION-FROM-STRING"
     "(DEFUN (OLD-CL-READ-S-EXPRESSION-FROM-STRING OBJECT) ((STRING STRING)))"
     (CL:FUNCTION OLD-CL-READ-S-EXPRESSION-FROM-STRING) NULL)
    (DEFINE-FUNCTION-OBJECT "INTEGER-TO-STRING"
     "(DEFUN (INTEGER-TO-STRING STRING) ((INTEGER INTEGER)) :DOCUMENTATION \"Return a string representation of 'integer'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION INTEGER-TO-STRING) NULL)
    (DEFINE-FUNCTION-OBJECT "FLOAT-TO-STRING"
     "(DEFUN (FLOAT-TO-STRING STRING) ((FLOAT FLOAT)) :DOCUMENTATION \"Return a string representation of 'float'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION FLOAT-TO-STRING) NULL)
    (DEFINE-FUNCTION-OBJECT "FORMAT-FLOAT"
     "(DEFUN (FORMAT-FLOAT STRING) ((VALUE FLOAT) (NDECIMALS INTEGER)) :DOCUMENTATION \"Return a string representation of 'float' with 'nDecimals' decimal places.\" :PUBLIC? TRUE)"
     (CL:FUNCTION FORMAT-FLOAT) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-TO-INTEGER"
     "(DEFUN (STRING-TO-INTEGER INTEGER) ((STRING STRING)) :DOCUMENTATION \"Convert the 'string' representation of an integer into an
integer and return the result.\" :PUBLIC? TRUE)"
     (CL:FUNCTION STRING-TO-INTEGER) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-TO-FLOAT"
     "(DEFUN (STRING-TO-FLOAT FLOAT) ((STRING STRING)) :DOCUMENTATION \"Convert the 'string' representation of a float into a
float and return the result.\" :PUBLIC? TRUE)"
     (CL:FUNCTION STRING-TO-FLOAT) NULL)
    (DEFINE-FUNCTION-OBJECT "STELLA-CODE-TO-CONS-TREE"
     "(DEFUN (STELLA-CODE-TO-CONS-TREE OBJECT) ((STELLACODE LISP-CODE)))"
     (CL:FUNCTION STELLA-CODE-TO-CONS-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "CONS-TREE-TO-LISP-CODE"
     "(DEFUN (CONS-TREE-TO-LISP-CODE LISP-CODE) ((STELLATREE OBJECT)))"
     (CL:FUNCTION CONS-TREE-TO-LISP-CODE) NULL)
    (DEFINE-FUNCTION-OBJECT "CONS-LIST-TO-LISP-LIST"
     "(DEFUN (CONS-LIST-TO-LISP-LIST LISP-CODE) ((LIST CONS)))"
     (CL:FUNCTION CONS-LIST-TO-LISP-LIST) NULL)
    (DEFINE-FUNCTION-OBJECT "OLD-CL-READ-S-EXPRESSION"
     "(DEFUN (OLD-CL-READ-S-EXPRESSION OBJECT BOOLEAN) ((INPUTSTREAM INPUT-STREAM)))"
     (CL:FUNCTION OLD-CL-READ-S-EXPRESSION) NULL)
    (DEFINE-FUNCTION-OBJECT "TOGGLE-CL-BASED-READERS"
     "(DEFUN TOGGLE-CL-BASED-READERS ())"
     (CL:FUNCTION TOGGLE-CL-BASED-READERS) NULL)
    (DEFINE-FUNCTION-OBJECT "PROBE-FILE?"
     "(DEFUN (PROBE-FILE? BOOLEAN) ((FILENAME FILE-NAME)))"
     (CL:FUNCTION PROBE-FILE?) NULL)
    (DEFINE-FUNCTION-OBJECT "FILE-WRITE-DATE"
     "(DEFUN (FILE-WRITE-DATE INTEGER) ((FILENAME FILE-NAME)))"
     (CL:FUNCTION FILE-WRITE-DATE) NULL)
    (DEFINE-FUNCTION-OBJECT "FILE-LENGTH"
     "(DEFUN (FILE-LENGTH INTEGER) ((FILENAME FILE-NAME)))"
     (CL:FUNCTION FILE-LENGTH) NULL)
    (DEFINE-FUNCTION-OBJECT "DELETE-FILE"
     "(DEFUN DELETE-FILE ((FILENAME FILE-NAME)))"
     (CL:FUNCTION DELETE-FILE) NULL)
    (DEFINE-FUNCTION-OBJECT "GET-TICKTOCK"
     "(DEFUN (GET-TICKTOCK TICKTOCK) () :PUBLIC? TRUE)"
     (CL:FUNCTION GET-TICKTOCK) NULL)
    (DEFINE-FUNCTION-OBJECT "TICKTOCK-DIFFERENCE"
     "(DEFUN (TICKTOCK-DIFFERENCE FLOAT) ((T1 TICKTOCK) (T2 TICKTOCK)) :DOCUMENTATION \"The difference in two TICKTOCK time values in seconds.
The resolution is implementation dependent but will normally be some fractional
value of a second.\" :PUBLIC? TRUE)" (CL:FUNCTION TICKTOCK-DIFFERENCE)
     NULL)
    (DEFINE-FUNCTION-OBJECT "TICKTOCK-RESOLUTION"
     "(DEFUN (TICKTOCK-RESOLUTION FLOAT) () :DOCUMENTATION \"The minimum theoretically detectable resolution of the
difference in two TICKTOCK time values in seconds.  This resolution is
implementation dependent.  It may also not be realizable in practice, since
the timing grain size may be larger than this resolution.\" :PUBLIC? TRUE)"
     (CL:FUNCTION TICKTOCK-RESOLUTION) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-CL-PRIMAL"
     "(DEFUN STARTUP-CL-PRIMAL () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-CL-PRIMAL) NULL)
    (CL:LET*
     ((FUNCTION (LOOKUP-FUNCTION SYM-CL-PRIMAL-STELLA-STARTUP-CL-PRIMAL)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-CL-PRIMAL-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "Startup-Cl-Primal") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFCONSTANT CL-NIL LISP-CODE (VERBATIM :COMMON-LISP (CL:OR)))")))
  :VOID)
