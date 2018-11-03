;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; sequence-indices.lisp

#|
 +--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997-2003              |
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
 +--------------------------------------------------------------------------+
|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR SYM-SEQUENCE-INDICES-LOGIC-SELECTION-PATTERN NULL)
(CL:DEFVAR SYM-SEQUENCE-INDICES-LOGIC-THE-SEQUENCE NULL)
(CL:DEFVAR SYM-SEQUENCE-INDICES-LOGIC-THE-SEQUENCE-LENGTH NULL)
(CL:DEFVAR SGT-SEQUENCE-INDICES-LOGIC-NON-PAGING-INDEX NULL)
(CL:DEFVAR SGT-SEQUENCE-INDICES-LOGIC-PAGING-INDEX NULL)
(CL:DEFVAR SYM-SEQUENCE-INDICES-LOGIC-STORE NULL)
(CL:DEFVAR SGT-SEQUENCE-INDICES-LOGIC-SEQUENCE-INDEX-ITERATOR NULL)
(CL:DEFVAR SYM-SEQUENCE-INDICES-STELLA-LIST-ITERATOR-CURSOR NULL)
(CL:DEFVAR SGT-SEQUENCE-INDICES-LOGIC-PAGING-INDEX-ITERATOR NULL)
(CL:DEFVAR SYM-SEQUENCE-INDICES-STELLA-MODULE NULL)
(CL:DEFVAR SYM-SEQUENCE-INDICES-LOGIC-OBJECT-STORE NULL)
(CL:DEFVAR SGT-SEQUENCE-INDICES-STELLA-MODULE NULL)
(CL:DEFVAR SGT-SEQUENCE-INDICES-LOGIC-OBJECT-STORE NULL)
(CL:DEFVAR KWD-SEQUENCE-INDICES-PAGING NULL)
(CL:DEFVAR KWD-SEQUENCE-INDICES-NON-PAGING NULL)
(CL:DEFVAR SYM-SEQUENCE-INDICES-LOGIC-STARTUP-SEQUENCE-INDICES NULL)
(CL:DEFVAR SYM-SEQUENCE-INDICES-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE* TRUE FALSE NIL NULL-INTEGER))

;;; (DEFCLASS SEQUENCE-INDEX ...)

(CL:DEFCLASS SEQUENCE-INDEX (STANDARD-OBJECT)
  ((THE-SEQUENCE :ALLOCATION :INSTANCE :ACCESSOR %THE-SEQUENCE)
   (THE-SEQUENCE-LENGTH :TYPE CL:FIXNUM :INITFORM NULL-INTEGER
    :ALLOCATION :INSTANCE :ACCESSOR %THE-SEQUENCE-LENGTH))
  (:DOCUMENTATION "Abstract class for managing a sequence of objects."))

(CL:DEFUN ACCESS-SEQUENCE-INDEX-SLOT-VALUE (SELF SLOTNAME VALUE SETVALUE?)
  (CL:COND
   ((CL:EQ SLOTNAME SYM-SEQUENCE-INDICES-LOGIC-THE-SEQUENCE)
    (CL:IF SETVALUE? (CL:SETF (%THE-SEQUENCE SELF) VALUE)
     (CL:SETQ VALUE (%THE-SEQUENCE SELF))))
   ((CL:EQ SLOTNAME SYM-SEQUENCE-INDICES-LOGIC-THE-SEQUENCE-LENGTH)
    (CL:IF SETVALUE?
     (CL:SETF (%THE-SEQUENCE-LENGTH SELF) (%WRAPPER-VALUE VALUE))
     (CL:SETQ VALUE (WRAP-INTEGER (%THE-SEQUENCE-LENGTH SELF)))))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" SLOTNAME
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
  VALUE)

(CL:DEFMETHOD PRINT-OBJECT ((SELF SEQUENCE-INDEX) STREAM)
  (PRINT-SEQUENCE-INDEX SELF STREAM))

;;; (DEFCLASS NON-PAGING-INDEX ...)

(CL:DEFCLASS NON-PAGING-INDEX (SEQUENCE-INDEX)
  ()
  (:DOCUMENTATION "Index that manages an always-in-memory data
strucure containing a sequence of objects."))

(CL:DEFUN NEW-NON-PAGING-INDEX ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE NON-PAGING-INDEX)))
   (CL:SETF (%THE-SEQUENCE-LENGTH SELF) NULL-INTEGER)
   (CL:SETF (%THE-SEQUENCE SELF) NIL) SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF NON-PAGING-INDEX))
  SGT-SEQUENCE-INDICES-LOGIC-NON-PAGING-INDEX)

;;; (DEFCLASS PAGING-INDEX ...)

(CL:DEFCLASS PAGING-INDEX (SEQUENCE-INDEX)
  ((SELECTION-PATTERN :ALLOCATION :INSTANCE :ACCESSOR
    %SELECTION-PATTERN)
   (STORE :ALLOCATION :INSTANCE :ACCESSOR %STORE))
  (:DOCUMENTATION
   "Index that manages a sequence of objects retrievable from
persistent storage.  Needs to be appropriately subclassed by actual store
implementations and facilitated with a proper iterator class."))

(CL:DEFUN NEW-PAGING-INDEX ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE PAGING-INDEX)))
   (CL:SETF (%THE-SEQUENCE-LENGTH SELF) NULL-INTEGER)
   (CL:SETF (%THE-SEQUENCE SELF) NIL) (CL:SETF (%STORE SELF) NULL)
   (CL:SETF (%SELECTION-PATTERN SELF) NULL) SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF PAGING-INDEX))
  SGT-SEQUENCE-INDICES-LOGIC-PAGING-INDEX)

(CL:DEFUN ACCESS-PAGING-INDEX-SLOT-VALUE (SELF SLOTNAME VALUE SETVALUE?)
  (CL:COND
   ((CL:EQ SLOTNAME SYM-SEQUENCE-INDICES-LOGIC-SELECTION-PATTERN)
    (CL:IF SETVALUE? (CL:SETF (%SELECTION-PATTERN SELF) VALUE)
     (CL:SETQ VALUE (%SELECTION-PATTERN SELF))))
   ((CL:EQ SLOTNAME SYM-SEQUENCE-INDICES-LOGIC-STORE)
    (CL:IF SETVALUE? (CL:SETF (%STORE SELF) VALUE)
     (CL:SETQ VALUE (%STORE SELF))))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" SLOTNAME
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
  VALUE)

(CL:DEFMETHOD PRINT-OBJECT ((SELF PAGING-INDEX) STREAM)
  (PRINT-PAGING-INDEX SELF STREAM))

;;; (DEFCONSTANT NIL-NON-PAGING-INDEX ...)

(CL:DEFVAR NIL-NON-PAGING-INDEX NULL
  "Returns a non-writable empty sequence.")

;;; (DEFCONSTANT NIL-PAGING-INDEX ...)

(CL:DEFVAR NIL-PAGING-INDEX NULL
  "Returns a non-writable empty sequence.")

;;; (DEFMETHOD INSERT ...)

(CL:DEFMETHOD INSERT ((SELF SEQUENCE-INDEX) VALUE)
  (CL:WHEN (CL:EQ SELF NIL-NON-PAGING-INDEX)
   (CL:ERROR
    "Safety violation: Attempt to insert into NIL-NON-PAGING-INDEX"))
  (CL:SETF (%THE-SEQUENCE SELF) (CONS VALUE (%THE-SEQUENCE SELF)))
  (CL:LET* ((LENGTH (%THE-SEQUENCE-LENGTH SELF)))
   (CL:DECLARE (CL:TYPE CL:FIXNUM LENGTH))
   (CL:WHEN (DEFINED? LENGTH)
    (CL:SETF (%THE-SEQUENCE-LENGTH SELF) (CL:1+ LENGTH)))))

;;; (DEFMETHOD PUSH ...)

(CL:DEFMETHOD PUSH ((SELF SEQUENCE-INDEX) VALUE)
  (INSERT SELF VALUE))

;;; (DEFMETHOD (FIRST OBJECT) ...)

(CL:DEFMETHOD FIRST ((SELF SEQUENCE-INDEX))
  (CL:LET* ((ITEM NULL) (ITER-000 (ALLOCATE-ITERATOR SELF)))
   (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ ITEM (%VALUE ITER-000))
    (CL:RETURN-FROM FIRST ITEM)))
  NULL)

;;; (DEFMETHOD (EMPTY? BOOLEAN) ...)

(CL:DEFMETHOD EMPTY? ((SELF SEQUENCE-INDEX))
  (CL:WHEN (CL:EQ (%THE-SEQUENCE SELF) NIL)
   (CL:RETURN-FROM EMPTY? TRUE))
  (CL:WHEN (CL:NOT (DELETED? (%%VALUE (%THE-SEQUENCE SELF))))
   (CL:RETURN-FROM EMPTY? FALSE))
  (REMOVE-DELETED-MEMBERS SELF)
  (CL:EQ (%THE-SEQUENCE SELF) NIL))

;;; (DEFMETHOD (ESTIMATED-LENGTH INTEGER) ...)

(CL:DEFMETHOD ESTIMATED-LENGTH ((SELF SEQUENCE-INDEX))
  (SEQUENCE-INDEX.ESTIMATED-LENGTH SELF))

;;; (DEFUN (SEQUENCE-INDEX.ESTIMATED-LENGTH INTEGER) ...)

(CL:DEFUN SEQUENCE-INDEX.ESTIMATED-LENGTH (SELF)
  (CL:LET* ((LENGTH (%THE-SEQUENCE-LENGTH SELF)))
   (CL:DECLARE (CL:TYPE CL:FIXNUM LENGTH))
   (CL:WHEN (NULL? LENGTH)
    (CL:SETQ LENGTH (LENGTH (%THE-SEQUENCE SELF)))
    (CL:SETF (%THE-SEQUENCE-LENGTH SELF) LENGTH))
   LENGTH))
(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:FIXNUM)
  SEQUENCE-INDEX.ESTIMATED-LENGTH))

;;; (DEFMETHOD (REMOVE-DELETED-MEMBERS (LIKE SELF)) ...)

(CL:DEFMETHOD REMOVE-DELETED-MEMBERS ((SELF SEQUENCE-INDEX))
  (CL:LET* ((SEQUENCE (REMOVE-DELETED-MEMBERS (%THE-SEQUENCE SELF))))
   (CL:SETF (%THE-SEQUENCE SELF) SEQUENCE)
   (CL:SETF (%THE-SEQUENCE-LENGTH SELF) NULL-INTEGER) SELF))

;;; (DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD CONSIFY ((SELF SEQUENCE-INDEX))
  (CL:LET* ((VALUE-000 NIL))
   (CL:LET*
    ((I NULL) (ITER-000 (ALLOCATE-ITERATOR SELF)) (COLLECT-000 NULL))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ I (%VALUE ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS I NIL))
       (CL:IF (CL:EQ VALUE-000 NIL) (CL:SETQ VALUE-000 COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST VALUE-000 COLLECT-000)))
      (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS I NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
   (CL:LET* ((VALUE-001 VALUE-000)) VALUE-001)))

;;; (DEFUN PRINT-SEQUENCE-INDEX ...)

(CL:DEFUN PRINT-SEQUENCE-INDEX (SELF STREAM)
  (CL:LET* ((LIMIT 10)) (CL:DECLARE (CL:TYPE CL:FIXNUM LIMIT))
   (%%PRINT-STREAM STREAM "|SEQ-IDX|(")
   (CL:LET*
    ((I NULL-INTEGER) (ELT NULL) (ITER-000 (%THE-SEQUENCE SELF))
     (ITER-001 1) (UPPER-BOUND-000 LIMIT)
     (UNBOUNDED?-000 (NULL? UPPER-BOUND-000)))
    (CL:DECLARE (CL:TYPE CL:FIXNUM ITER-001 UPPER-BOUND-000 I))
    (CL:LOOP WHILE
     (CL:AND (CL:NOT (CL:EQ ITER-000 NIL))
      (CL:OR UNBOUNDED?-000 (CL:<= ITER-001 UPPER-BOUND-000)))
     DO
     (CL:PROGN (CL:SETQ ELT (%%VALUE ITER-000))
      (CL:SETQ ITER-000 (%%REST ITER-000)))
     (CL:PROGN (CL:SETQ I ITER-001)
      (CL:SETQ ITER-001 (CL:1+ ITER-001)))
     (CL:WHEN (CL:> I 1) (%%PRINT-STREAM STREAM " "))
     (%%PRINT-STREAM STREAM ELT)
     (CL:WHEN (CL:= I LIMIT) (%%PRINT-STREAM STREAM "..."))))
   (%%PRINT-STREAM STREAM ")")))

;;; (DEFCLASS SEQUENCE-INDEX-ITERATOR ...)

(CL:DEFCLASS SEQUENCE-INDEX-ITERATOR (ITERATOR)
  ((LIST-ITERATOR-CURSOR :ALLOCATION :INSTANCE :ACCESSOR
    %LIST-ITERATOR-CURSOR))
  (:DOCUMENTATION
   "Iterator that generates successive members of a sequence index."))

(CL:DEFUN NEW-SEQUENCE-INDEX-ITERATOR ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE SEQUENCE-INDEX-ITERATOR)))
   (CL:SETF (%FIRST-ITERATION? SELF) TRUE) (CL:SETF (%VALUE SELF) NULL)
   (CL:SETF (%LIST-ITERATOR-CURSOR SELF) NULL) SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF SEQUENCE-INDEX-ITERATOR))
  SGT-SEQUENCE-INDICES-LOGIC-SEQUENCE-INDEX-ITERATOR)

(CL:DEFUN ACCESS-SEQUENCE-INDEX-ITERATOR-SLOT-VALUE (SELF SLOTNAME VALUE SETVALUE?)
  (CL:COND
   ((CL:EQ SLOTNAME SYM-SEQUENCE-INDICES-STELLA-LIST-ITERATOR-CURSOR)
    (CL:IF SETVALUE? (CL:SETF (%LIST-ITERATOR-CURSOR SELF) VALUE)
     (CL:SETQ VALUE (%LIST-ITERATOR-CURSOR SELF))))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" SLOTNAME
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
  VALUE)

;;; (DEFMETHOD (ALLOCATE-ITERATOR (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD ALLOCATE-ITERATOR ((SELF SEQUENCE-INDEX))
  (CL:LET* ((SELF-000 (NEW-SEQUENCE-INDEX-ITERATOR)))
   (CL:SETF (%LIST-ITERATOR-CURSOR SELF-000) (%THE-SEQUENCE SELF))
   (CL:LET* ((VALUE-000 SELF-000)) VALUE-000)))

;;; (DEFMETHOD (NEXT? BOOLEAN) ...)

(CL:DEFMETHOD NEXT? ((SELF SEQUENCE-INDEX-ITERATOR))
  (CL:LET* ((CURSOR (%LIST-ITERATOR-CURSOR SELF)) (VALUE NULL))
   (CL:LOOP (CL:WHEN (CL:EQ CURSOR NIL) (CL:RETURN-FROM NEXT? FALSE))
    (CL:SETQ VALUE (%%VALUE CURSOR))
    (CL:WHEN (CL:NOT (DELETED? VALUE)) (CL:SETF (%VALUE SELF) VALUE)
     (CL:SETF (%LIST-ITERATOR-CURSOR SELF) (%%REST CURSOR))
     (CL:RETURN-FROM NEXT? TRUE))
    (CL:SETQ CURSOR (%%REST CURSOR)))))

;;; (DEFMETHOD (EMPTY? BOOLEAN) ...)

(CL:DEFMETHOD EMPTY? ((SELF SEQUENCE-INDEX-ITERATOR))
  (CL:EQ (%LIST-ITERATOR-CURSOR SELF) NIL))

;;; (DEFMETHOD (COPY NON-PAGING-INDEX) ...)

(CL:DEFMETHOD COPY ((SELF NON-PAGING-INDEX))
  (CL:LET* ((SELF-000 (NEW-NON-PAGING-INDEX)))
   (CL:SETF (%THE-SEQUENCE SELF-000)
    (COPY-CONS-LIST (%THE-SEQUENCE SELF)))
   (CL:LET* ((VALUE-000 SELF-000)) VALUE-000)))

;;; (DEFMETHOD CLEAR ...)

(CL:DEFMETHOD CLEAR ((SELF NON-PAGING-INDEX))
  (CL:SETF (%THE-SEQUENCE SELF) NIL))

;;; (DEFMETHOD (REMOVE NON-PAGING-INDEX) ...)

(CL:DEFMETHOD REMOVE ((SELF NON-PAGING-INDEX) VALUE)
  (CL:SETF (%THE-SEQUENCE SELF) (REMOVE (%THE-SEQUENCE SELF) VALUE))
  SELF)

;;; (DEFMETHOD INSERT ...)

(CL:DEFMETHOD INSERT ((SELF PAGING-INDEX) VALUE)
  (CL:WHEN (CL:EQ SELF NIL-PAGING-INDEX)
   (CL:ERROR
    "Safety violation: Attempt to insert into NIL-PAGING-INDEX"))
  (CL:SETF (%THE-SEQUENCE SELF) (CONS VALUE (%THE-SEQUENCE SELF))))

;;; (DEFMETHOD PUSH ...)

(CL:DEFMETHOD PUSH ((SELF PAGING-INDEX) VALUE)
  (INSERT SELF VALUE))

;;; (DEFMETHOD (ESTIMATED-LENGTH INTEGER) ...)

(CL:DEFMETHOD ESTIMATED-LENGTH ((SELF PAGING-INDEX))
  "Return the estimated length of the sequences in 'self',
which could be too large if some of the members have been deleted."
  (CL:LET* ((LENGTH (%THE-SEQUENCE-LENGTH SELF)))
   (CL:DECLARE (CL:TYPE CL:FIXNUM LENGTH))
   (CL:WHEN (NULL? LENGTH)
    (CL:SETQ LENGTH (LENGTH (%THE-SEQUENCE SELF)))
    (CL:SETF (%THE-SEQUENCE-LENGTH SELF) LENGTH))
   LENGTH))

;;; (DEFMETHOD (REMOVE-DELETED-MEMBERS (LIKE SELF)) ...)

(CL:DEFMETHOD REMOVE-DELETED-MEMBERS ((SELF PAGING-INDEX))
  "Destructively remove all deleted members of `self'."
  (CL:LET* ((SEQUENCE (REMOVE-DELETED-MEMBERS (%THE-SEQUENCE SELF))))
   (CL:SETF (%THE-SEQUENCE SELF) SEQUENCE)
   (CL:SETF (%THE-SEQUENCE-LENGTH SELF) NULL-INTEGER) SELF))

;;; (DEFUN PRINT-PAGING-INDEX ...)

(CL:DEFUN PRINT-PAGING-INDEX (SELF STREAM)
  (CL:LET* ((LIMIT 10)) (CL:DECLARE (CL:TYPE CL:FIXNUM LIMIT))
   (%%PRINT-STREAM STREAM "|PAGING-IDX|(" (%SELECTION-PATTERN SELF))
   (CL:LET*
    ((I NULL-INTEGER) (ELT NULL) (ITER-000 (%THE-SEQUENCE SELF))
     (ITER-001 1) (UPPER-BOUND-000 LIMIT)
     (UNBOUNDED?-000 (NULL? UPPER-BOUND-000)))
    (CL:DECLARE (CL:TYPE CL:FIXNUM ITER-001 UPPER-BOUND-000 I))
    (CL:LOOP WHILE
     (CL:AND (CL:NOT (CL:EQ ITER-000 NIL))
      (CL:OR UNBOUNDED?-000 (CL:<= ITER-001 UPPER-BOUND-000)))
     DO
     (CL:PROGN (CL:SETQ ELT (%%VALUE ITER-000))
      (CL:SETQ ITER-000 (%%REST ITER-000)))
     (CL:PROGN (CL:SETQ I ITER-001)
      (CL:SETQ ITER-001 (CL:1+ ITER-001)))
     (%%PRINT-STREAM STREAM " " ELT)
     (CL:WHEN (CL:= I LIMIT) (%%PRINT-STREAM STREAM "..."))))
   (%%PRINT-STREAM STREAM ")")))

;;; (DEFCLASS PAGING-INDEX-ITERATOR ...)

(CL:DEFCLASS PAGING-INDEX-ITERATOR (SEQUENCE-INDEX-ITERATOR)
  ()
  (:DOCUMENTATION
   "Iterator that generates successive members of a paging index."))

(CL:DEFUN NEW-PAGING-INDEX-ITERATOR ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE PAGING-INDEX-ITERATOR)))
   (CL:SETF (%FIRST-ITERATION? SELF) TRUE) (CL:SETF (%VALUE SELF) NULL)
   (CL:SETF (%LIST-ITERATOR-CURSOR SELF) NULL) SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF PAGING-INDEX-ITERATOR))
  SGT-SEQUENCE-INDICES-LOGIC-PAGING-INDEX-ITERATOR)

;;; (DEFMETHOD (ALLOCATE-ITERATOR (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD ALLOCATE-ITERATOR ((SELF PAGING-INDEX))
  (CL:LET* ((SELF-000 (NEW-PAGING-INDEX-ITERATOR)))
   (CL:SETF (%LIST-ITERATOR-CURSOR SELF-000) (%THE-SEQUENCE SELF))
   (CL:LET* ((VALUE-000 SELF-000)) VALUE-000)))

;;; (DEFCLASS OBJECT-STORE ...)

(CL:DEFCLASS OBJECT-STORE (STANDARD-OBJECT)
  ((MODULE :ALLOCATION :INSTANCE :ACCESSOR %MODULE)))

(CL:DEFUN ACCESS-OBJECT-STORE-SLOT-VALUE (SELF SLOTNAME VALUE SETVALUE?)
  (CL:COND
   ((CL:EQ SLOTNAME SYM-SEQUENCE-INDICES-STELLA-MODULE)
    (CL:IF SETVALUE? (CL:SETF (%MODULE SELF) VALUE)
     (CL:SETQ VALUE (%MODULE SELF))))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" SLOTNAME
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
  VALUE)

;;; (DEFSPECIAL *LOADINGREGENERABLEOBJECTS?* ...)

(CL:DEFVAR *LOADINGREGENERABLEOBJECTS?* FALSE
  "If TRUE, objects being created are regenerable,
and should not be indexed using the backlinks procedures.")

;;; (DEFUN (HOME-OBJECT-STORE OBJECT-STORE) ...)

(CL:DEFUN HOME-OBJECT-STORE (SELF)
  (CL:LET* ((MODULE (HOME-MODULE SELF)))
   (CL:IF (CL:NOT (CL:EQ MODULE NULL))
    (DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS MODULE)
     SYM-SEQUENCE-INDICES-LOGIC-OBJECT-STORE NULL)
    NULL)))

;;; (DEFUN (CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ...)

(CL:DEFUN CREATE-SEQUENCE-INDEX (SELF PATTERN)
  (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE SELF)))
   (CL:COND
    ((SUBTYPE-OF-KEYWORD? TEST-VALUE-000)
     (CL:PROGN (KEYWORD.CREATE-SEQUENCE-INDEX SELF PATTERN)))
    ((SUBTYPE-OF? TEST-VALUE-000 SGT-SEQUENCE-INDICES-STELLA-MODULE)
     (CL:PROGN (MODULE.CREATE-SEQUENCE-INDEX SELF PATTERN)))
    ((SUBTYPE-OF? TEST-VALUE-000
      SGT-SEQUENCE-INDICES-LOGIC-OBJECT-STORE)
     (CL:PROGN (OBJECT-STORE.CREATE-SEQUENCE-INDEX SELF PATTERN)))
    (CL:T
     (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
      (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
       "Don't know how to create a sequence index on `" SELF "'")
      (CL:ERROR
       (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))))

;;; (DEFUN (KEYWORD.CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ...)

(CL:DEFUN KEYWORD.CREATE-SEQUENCE-INDEX (KIND PATTERN)
  (CL:COND
   ((CL:EQ KIND KWD-SEQUENCE-INDICES-PAGING)
    (CL:LET*
     ((ANCHOR (%%VALUE (%%REST (%%REST PATTERN)))) (STORE NULL))
     (CL:WHEN (CL:EQ ANCHOR NULL)
      (CL:ERROR
       "Safety violation: Null argument passed into paging index pattern"))
     (CL:SETQ STORE (HOME-OBJECT-STORE ANCHOR))
     (CL:IF (CL:NOT (CL:EQ STORE NULL))
      (CREATE-SEQUENCE-INDEX STORE PATTERN) (NEW-NON-PAGING-INDEX))))
   ((CL:EQ KIND KWD-SEQUENCE-INDICES-NON-PAGING)
    (NEW-NON-PAGING-INDEX))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" KIND
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))))

;;; (DEFUN (MODULE.CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ...)

(CL:DEFUN MODULE.CREATE-SEQUENCE-INDEX (MODULE PATTERN)
  (CL:LET*
   ((STORE
     (DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS MODULE)
      SYM-SEQUENCE-INDICES-LOGIC-OBJECT-STORE NULL)))
   (CL:IF (CL:NOT (CL:EQ STORE NULL))
    (CREATE-SEQUENCE-INDEX STORE PATTERN)
    (CREATE-SEQUENCE-INDEX KWD-SEQUENCE-INDICES-PAGING PATTERN))))

;;; (DEFMETHOD (OBJECT-STORE.CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ...)

(CL:DEFMETHOD OBJECT-STORE.CREATE-SEQUENCE-INDEX ((STORE OBJECT-STORE) PATTERN)
  (CL:LET* ((SELF-000 (NEW-PAGING-INDEX)))
   (CL:SETF (%STORE SELF-000) STORE)
   (CL:SETF (%SELECTION-PATTERN SELF-000) PATTERN)
   (CL:LET* ((VALUE-000 SELF-000)) VALUE-000)))

;;; (DEFMETHOD (FETCH-RELATION NAMED-DESCRIPTION) ...)

(CL:DEFMETHOD FETCH-RELATION ((STORE OBJECT-STORE) NAME)
  "Fetch the relation identified by `name' (a string or symbol) from `store'
and return it as a named description.  This needs to be appropriately 
specialized on actual OBJECT-STORE implementations."
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "Don't know how to fetch relation `" NAME "' from `" STORE "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFMETHOD (FETCH-INSTANCE OBJECT) ...)

(CL:DEFMETHOD FETCH-INSTANCE ((STORE OBJECT-STORE) NAME)
  "Fetch the instance identified by `name' (a string or symbol) from `store'
and return it as an appropriate logic object.  This needs to be appropriately
specialized on actual OBJECT-STORE implementations."
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "Don't know how to fetch instance `" NAME "' from `" STORE "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

(CL:DEFUN HELP-STARTUP-SEQUENCE-INDICES1 ()
  (CL:PROGN
   (CL:SETQ SYM-SEQUENCE-INDICES-LOGIC-SELECTION-PATTERN
    (INTERN-RIGID-SYMBOL-WRT-MODULE "SELECTION-PATTERN" NULL 0))
   (CL:SETQ SYM-SEQUENCE-INDICES-LOGIC-THE-SEQUENCE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "THE-SEQUENCE" NULL 0))
   (CL:SETQ SYM-SEQUENCE-INDICES-LOGIC-THE-SEQUENCE-LENGTH
    (INTERN-RIGID-SYMBOL-WRT-MODULE "THE-SEQUENCE-LENGTH" NULL 0))
   (CL:SETQ SGT-SEQUENCE-INDICES-LOGIC-NON-PAGING-INDEX
    (INTERN-RIGID-SYMBOL-WRT-MODULE "NON-PAGING-INDEX" NULL 1))
   (CL:SETQ SGT-SEQUENCE-INDICES-LOGIC-PAGING-INDEX
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PAGING-INDEX" NULL 1))
   (CL:SETQ SYM-SEQUENCE-INDICES-LOGIC-STORE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STORE" NULL 0))
   (CL:SETQ SGT-SEQUENCE-INDICES-LOGIC-SEQUENCE-INDEX-ITERATOR
    (INTERN-RIGID-SYMBOL-WRT-MODULE "SEQUENCE-INDEX-ITERATOR" NULL 1))
   (CL:SETQ SYM-SEQUENCE-INDICES-STELLA-LIST-ITERATOR-CURSOR
    (INTERN-RIGID-SYMBOL-WRT-MODULE "LIST-ITERATOR-CURSOR"
     (GET-STELLA-MODULE "/STELLA" TRUE) 0))
   (CL:SETQ SGT-SEQUENCE-INDICES-LOGIC-PAGING-INDEX-ITERATOR
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PAGING-INDEX-ITERATOR" NULL 1))
   (CL:SETQ SYM-SEQUENCE-INDICES-STELLA-MODULE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "MODULE"
     (GET-STELLA-MODULE "/STELLA" TRUE) 0))
   (CL:SETQ SYM-SEQUENCE-INDICES-LOGIC-OBJECT-STORE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "OBJECT-STORE" NULL 0))
   (CL:SETQ SGT-SEQUENCE-INDICES-STELLA-MODULE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "MODULE"
     (GET-STELLA-MODULE "/STELLA" TRUE) 1))
   (CL:SETQ SGT-SEQUENCE-INDICES-LOGIC-OBJECT-STORE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "OBJECT-STORE" NULL 1))
   (CL:SETQ KWD-SEQUENCE-INDICES-PAGING
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PAGING" NULL 2))
   (CL:SETQ KWD-SEQUENCE-INDICES-NON-PAGING
    (INTERN-RIGID-SYMBOL-WRT-MODULE "NON-PAGING" NULL 2))
   (CL:SETQ SYM-SEQUENCE-INDICES-LOGIC-STARTUP-SEQUENCE-INDICES
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-SEQUENCE-INDICES" NULL 0))
   (CL:SETQ SYM-SEQUENCE-INDICES-STELLA-METHOD-STARTUP-CLASSNAME
    (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
     (GET-STELLA-MODULE "/STELLA" TRUE) 0))))

(CL:DEFUN STARTUP-SEQUENCE-INDICES ()
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE "/LOGIC" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (HELP-STARTUP-SEQUENCE-INDICES1))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ NIL-NON-PAGING-INDEX (NEW-NON-PAGING-INDEX))
    (CL:LET* ((SELF-001 (NEW-PAGING-INDEX)))
     (CL:SETF (%SELECTION-PATTERN SELF-001)
      (GET-QUOTED-TREE "((:NIL-SEQUENCE) \"/LOGIC\")" "/LOGIC"))
     (CL:SETQ NIL-PAGING-INDEX SELF-001))
    (CL:SETQ *LOADINGREGENERABLEOBJECTS?* FALSE))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 5)
    (DEFINE-STELLA-TYPE-FROM-STRINGIFIED-SOURCE
     "(DEFTYPE SELECTION-PATTERN CONS)")
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "SEQUENCE-INDEX"
        "(DEFCLASS SEQUENCE-INDEX (STANDARD-OBJECT) :DOCUMENTATION \"Abstract class for managing a sequence of objects.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :ABSTRACT? TRUE :SLOTS ((THE-SEQUENCE :TYPE CONS :INITIALLY NIL) (THE-SEQUENCE-LENGTH :TYPE INTEGER :INITIALLY NULL)) :PRINT-FORM (PRINT-SEQUENCE-INDEX SELF STREAM))")))
     (CL:SETF (%CLASS-SLOT-ACCESSOR-CODE CLASS)
      (CL:FUNCTION ACCESS-SEQUENCE-INDEX-SLOT-VALUE)))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "NON-PAGING-INDEX"
        "(DEFCLASS NON-PAGING-INDEX (SEQUENCE-INDEX) :DOCUMENTATION \"Index that manages an always-in-memory data
strucure containing a sequence of objects.\")")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS)
      (CL:FUNCTION NEW-NON-PAGING-INDEX)))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "PAGING-INDEX"
        "(DEFCLASS PAGING-INDEX (SEQUENCE-INDEX) :DOCUMENTATION \"Index that manages a sequence of objects retrievable from
persistent storage.  Needs to be appropriately subclassed by actual store
implementations and facilitated with a proper iterator class.\" :SLOTS ((SELECTION-PATTERN :TYPE SELECTION-PATTERN) (STORE :TYPE OBJECT-STORE)) :PRINT-FORM (PRINT-PAGING-INDEX SELF STREAM))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS)
      (CL:FUNCTION NEW-PAGING-INDEX))
     (CL:SETF (%CLASS-SLOT-ACCESSOR-CODE CLASS)
      (CL:FUNCTION ACCESS-PAGING-INDEX-SLOT-VALUE)))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "SEQUENCE-INDEX-ITERATOR"
        "(DEFCLASS SEQUENCE-INDEX-ITERATOR (ITERATOR) :DOCUMENTATION \"Iterator that generates successive members of a sequence index.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((LIST-ITERATOR-CURSOR :TYPE CONS)))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS)
      (CL:FUNCTION NEW-SEQUENCE-INDEX-ITERATOR))
     (CL:SETF (%CLASS-SLOT-ACCESSOR-CODE CLASS)
      (CL:FUNCTION ACCESS-SEQUENCE-INDEX-ITERATOR-SLOT-VALUE)))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "PAGING-INDEX-ITERATOR"
        "(DEFCLASS PAGING-INDEX-ITERATOR (SEQUENCE-INDEX-ITERATOR) :DOCUMENTATION \"Iterator that generates successive members of a paging index.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS)
      (CL:FUNCTION NEW-PAGING-INDEX-ITERATOR)))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "OBJECT-STORE"
        "(DEFCLASS OBJECT-STORE (STANDARD-OBJECT) :ABSTRACT? TRUE :SLOTS ((MODULE :TYPE MODULE)))")))
     (CL:SETF (%CLASS-SLOT-ACCESSOR-CODE CLASS)
      (CL:FUNCTION ACCESS-OBJECT-STORE-SLOT-VALUE))))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD INSERT ((SELF SEQUENCE-INDEX) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
     (CL:FUNCTION INSERT) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD PUSH ((SELF SEQUENCE-INDEX) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
     (CL:FUNCTION PUSH) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (FIRST OBJECT) ((SELF SEQUENCE-INDEX)) :PUBLIC? TRUE)"
     (CL:FUNCTION FIRST) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF SEQUENCE-INDEX)) :PUBLIC? TRUE)"
     (CL:FUNCTION EMPTY?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (ESTIMATED-LENGTH INTEGER) ((SELF SEQUENCE-INDEX)))"
     (CL:FUNCTION ESTIMATED-LENGTH) NULL)
    (DEFINE-FUNCTION-OBJECT "SEQUENCE-INDEX.ESTIMATED-LENGTH"
     "(DEFUN (SEQUENCE-INDEX.ESTIMATED-LENGTH INTEGER) ((SELF SEQUENCE-INDEX)))"
     (CL:FUNCTION SEQUENCE-INDEX.ESTIMATED-LENGTH) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (REMOVE-DELETED-MEMBERS (LIKE SELF)) ((SELF SEQUENCE-INDEX)) :PUBLIC? TRUE)"
     (CL:FUNCTION REMOVE-DELETED-MEMBERS) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF SEQUENCE-INDEX)))"
     (CL:FUNCTION CONSIFY) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-SEQUENCE-INDEX"
     "(DEFUN PRINT-SEQUENCE-INDEX ((SELF SEQUENCE-INDEX) (STREAM NATIVE-OUTPUT-STREAM)))"
     (CL:FUNCTION PRINT-SEQUENCE-INDEX) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (ALLOCATE-ITERATOR (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF SEQUENCE-INDEX)))"
     (CL:FUNCTION ALLOCATE-ITERATOR) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (NEXT? BOOLEAN) ((SELF SEQUENCE-INDEX-ITERATOR)))"
     (CL:FUNCTION NEXT?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF SEQUENCE-INDEX-ITERATOR)))"
     (CL:FUNCTION EMPTY?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (COPY NON-PAGING-INDEX) ((SELF NON-PAGING-INDEX)))"
     (CL:FUNCTION COPY) NULL)
    (DEFINE-METHOD-OBJECT "(DEFMETHOD CLEAR ((SELF NON-PAGING-INDEX)))"
     (CL:FUNCTION CLEAR) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (REMOVE NON-PAGING-INDEX) ((SELF NON-PAGING-INDEX) (VALUE OBJECT)))"
     (CL:FUNCTION REMOVE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD INSERT ((SELF PAGING-INDEX) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
     (CL:FUNCTION INSERT) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD PUSH ((SELF PAGING-INDEX) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
     (CL:FUNCTION PUSH) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (ESTIMATED-LENGTH INTEGER) ((SELF PAGING-INDEX)) :DOCUMENTATION \"Return the estimated length of the sequences in 'self',
which could be too large if some of the members have been deleted.\" :PUBLIC? TRUE)"
     (CL:FUNCTION ESTIMATED-LENGTH) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (REMOVE-DELETED-MEMBERS (LIKE SELF)) ((SELF PAGING-INDEX)) :DOCUMENTATION \"Destructively remove all deleted members of `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION REMOVE-DELETED-MEMBERS) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-PAGING-INDEX"
     "(DEFUN PRINT-PAGING-INDEX ((SELF PAGING-INDEX) (STREAM NATIVE-OUTPUT-STREAM)))"
     (CL:FUNCTION PRINT-PAGING-INDEX) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (ALLOCATE-ITERATOR (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF PAGING-INDEX)))"
     (CL:FUNCTION ALLOCATE-ITERATOR) NULL)
    (DEFINE-EXTERNAL-SLOT-FROM-STRINGIFIED-SOURCE
     "(DEFSLOT MODULE OBJECT-STORE :TYPE OBJECT-STORE :ALLOCATION :DYNAMIC)")
    (DEFINE-FUNCTION-OBJECT "HOME-OBJECT-STORE"
     "(DEFUN (HOME-OBJECT-STORE OBJECT-STORE) ((SELF OBJECT)))"
     (CL:FUNCTION HOME-OBJECT-STORE) NULL)
    (DEFINE-FUNCTION-OBJECT "CREATE-SEQUENCE-INDEX"
     "(DEFUN (CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ((SELF OBJECT) (PATTERN SELECTION-PATTERN)))"
     (CL:FUNCTION CREATE-SEQUENCE-INDEX) NULL)
    (DEFINE-FUNCTION-OBJECT "KEYWORD.CREATE-SEQUENCE-INDEX"
     "(DEFUN (KEYWORD.CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ((KIND KEYWORD) (PATTERN SELECTION-PATTERN)))"
     (CL:FUNCTION KEYWORD.CREATE-SEQUENCE-INDEX) NULL)
    (DEFINE-FUNCTION-OBJECT "MODULE.CREATE-SEQUENCE-INDEX"
     "(DEFUN (MODULE.CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ((MODULE MODULE) (PATTERN SELECTION-PATTERN)))"
     (CL:FUNCTION MODULE.CREATE-SEQUENCE-INDEX) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (OBJECT-STORE.CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ((STORE OBJECT-STORE) (PATTERN SELECTION-PATTERN)))"
     (CL:FUNCTION OBJECT-STORE.CREATE-SEQUENCE-INDEX) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (FETCH-RELATION NAMED-DESCRIPTION) ((STORE OBJECT-STORE) (NAME OBJECT)) :DOCUMENTATION \"Fetch the relation identified by `name' (a string or symbol) from `store'
and return it as a named description.  This needs to be appropriately 
specialized on actual OBJECT-STORE implementations.\" :PUBLIC? TRUE)"
     (CL:FUNCTION FETCH-RELATION) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (FETCH-INSTANCE OBJECT) ((STORE OBJECT-STORE) (NAME OBJECT)) :DOCUMENTATION \"Fetch the instance identified by `name' (a string or symbol) from `store'
and return it as an appropriate logic object.  This needs to be appropriately
specialized on actual OBJECT-STORE implementations.\" :PUBLIC? TRUE)"
     (CL:FUNCTION FETCH-INSTANCE) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-SEQUENCE-INDICES"
     "(DEFUN STARTUP-SEQUENCE-INDICES () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-SEQUENCE-INDICES) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION
        SYM-SEQUENCE-INDICES-LOGIC-STARTUP-SEQUENCE-INDICES)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-SEQUENCE-INDICES-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_Startup-Sequence-Indices") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFCONSTANT NIL-NON-PAGING-INDEX NON-PAGING-INDEX (NEW NON-PAGING-INDEX) :DOCUMENTATION \"Returns a non-writable empty sequence.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFCONSTANT NIL-PAGING-INDEX PAGING-INDEX (NEW PAGING-INDEX :SELECTION-PATTERN (QUOTE (:NIL-SEQUENCE))) :DOCUMENTATION \"Returns a non-writable empty sequence.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *LOADINGREGENERABLEOBJECTS?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE, objects being created are regenerable,
and should not be indexed using the backlinks procedures.\")"))))
