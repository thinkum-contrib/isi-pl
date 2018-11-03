;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; conses.lisp

#|
+---------------------------- BEGIN LICENSE BLOCK ---------------------------+
|                                                                            |
| Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          |
|                                                                            |
| The contents of this file are subject to the Mozilla Public License        |
| Version 1.1 (the "License"); you may not use this file except in           |
| compliance with the License. You may obtain a copy of the License at       |
| http://www.mozilla.org/MPL/                                                |
|                                                                            |
| Software distributed under the License is distributed on an "AS IS" basis, |
| WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   |
| for the specific language governing rights and limitations under the       |
| License.                                                                   |
|                                                                            |
| The Original Code is the STELLA Programming Language.                      |
|                                                                            |
| The Initial Developer of the Original Code is                              |
| UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
| 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
|                                                                            |
| Portions created by the Initial Developer are Copyright (C) 1996-2012      |
| the Initial Developer. All Rights Reserved.                                |
|                                                                            |
| Contributor(s):                                                            |
|                                                                            |
| Alternatively, the contents of this file may be used under the terms of    |
| either the GNU General Public License Version 2 or later (the "GPL"), or   |
| the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   |
| in which case the provisions of the GPL or the LGPL are applicable instead |
| of those above. If you wish to allow use of your version of this file only |
| under the terms of either the GPL or the LGPL, and not to allow others to  |
| use your version of this file under the terms of the MPL, indicate your    |
| decision by deleting the provisions above and replace them with the notice |
| and other provisions required by the GPL or the LGPL. If you do not delete |
| the provisions above, a recipient may use your version of this file under  |
| the terms of any one of the MPL, the GPL or the LGPL.                      |
|                                                                            |
+---------------------------- END LICENSE BLOCK -----------------------------+
|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR SGT-CONSES-STELLA-GENERALIZED-SYMBOL NULL)
(CL:DEFVAR SGT-CONSES-STELLA-MUTABLE-STRING-WRAPPER NULL)
(CL:DEFVAR SGT-CONSES-STELLA-CONS NULL)
(CL:DEFVAR SYM-CONSES-STELLA-? NULL)
(CL:DEFVAR SYM-CONSES-STELLA-... NULL)
(CL:DEFVAR SYM-CONSES-STELLA-STARTUP-CONSES NULL)
(CL:DEFVAR SYM-CONSES-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STELLA-MODULE* *MODULE* EOL *INTEGER-MSB-MASK* NULL-INTEGER))

;;; (DEFGLOBAL NIL ...)

(CL:DEFVAR NIL NULL)

;;; (DEFMETHOD (EMPTY? BOOLEAN) ...)

(%%DEFCONSMETHOD EMPTY? ((SELF CL:CONS))
  "Return `true' iff `self' equals `nil'."
  (CL:RETURN-FROM EMPTY? (CL:EQ SELF NIL)))

;;; (DEFMETHOD (NON-EMPTY? BOOLEAN) ...)

(%%DEFCONSMETHOD NON-EMPTY? ((SELF CL:CONS))
  "Return `true' iff `self' is not equal to `nil'."
  (CL:RETURN-FROM NON-EMPTY? (CL:NOT (CL:EQ SELF NIL))))

;;; (DEFUN (NIL? BOOLEAN) ...)

(CL:DEFUN NIL? (X)
  "Return `true' iff `x' equals `nil'."
  (CL:RETURN-FROM NIL? (CL:EQ X NIL)))

;;; (DEFMETHOD (LENGTH INTEGER) ...)

(%%DEFCONSMETHOD LENGTH ((SELF CL:CONS))
  "Return the length of the CONS list `self'."
  (CL:LET* ((CONS SELF) (I 0)) (CL:DECLARE (CL:TYPE CL:FIXNUM I))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CONS NIL)) DO (CL:SETQ I (CL:1+ I))
    (CL:SETQ CONS (%%REST CONS)))
   (CL:RETURN-FROM LENGTH I)))

;;; (DEFMETHOD (POSITION INTEGER) ...)

(%%DEFCONSMETHOD POSITION ((SELF CL:CONS) OBJECT START)
  "Return the position of `object' within the cons-list
`self' (counting from zero); or return `null' if `object' does not occur within 
`self' (uses an `eql?' test).  If `start' was supplied as non-`null', only 
consider the sublist starting at `start', however, the returned position 
will always be relative to the entire list."
  (CL:DECLARE (CL:TYPE CL:FIXNUM START))
  #+MCL
  (CL:CHECK-TYPE START CL:FIXNUM)
  (CL:WHEN (CL:= START NULL-INTEGER) (CL:SETQ START 0))
  (CL:LET*
   ((ELEMENT NULL) (ITER-000 (NTH-REST SELF START)) (POSITION NULL-INTEGER)
    (ITER-001 START))
   (CL:DECLARE (CL:TYPE CL:FIXNUM POSITION ITER-001))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
    (CL:SETQ ELEMENT (%%VALUE ITER-000)) (CL:SETQ POSITION ITER-001)
    (CL:WHEN (EQL? ELEMENT OBJECT) (CL:RETURN-FROM POSITION POSITION))
    (CL:SETQ ITER-000 (%%REST ITER-000)) (CL:SETQ ITER-001 (CL:1+ ITER-001))))
  (CL:RETURN-FROM POSITION NULL-INTEGER))

;;; (DEFMETHOD (LAST-POSITION INTEGER) ...)

(%%DEFCONSMETHOD LAST-POSITION ((SELF CL:CONS) OBJECT END)
  "Return the position of `object' within the cons-list
`self' (counting from zero); or return `null' if `object' does not occur within 
`self' (uses an `eql?' test).  If `start' was supplied as non-`null', only 
consider the sublist ending at `end', however, the returned position 
will always be relative to the entire list."
  (CL:DECLARE (CL:TYPE CL:FIXNUM END))
  #+MCL
  (CL:CHECK-TYPE END CL:FIXNUM)
  (CL:LET* ((LAST-POS NULL-INTEGER)) (CL:DECLARE (CL:TYPE CL:FIXNUM LAST-POS))
   (CL:WHEN (CL:= END NULL-INTEGER) (CL:SETQ END (CL:1- (LENGTH SELF))))
   (CL:LET*
    ((ELEMENT NULL) (ITER-000 SELF) (POSITION NULL-INTEGER) (ITER-001 0)
     (UPPER-BOUND-000 END)
     (UNBOUNDED?-000 (CL:= UPPER-BOUND-000 NULL-INTEGER)))
    (CL:DECLARE (CL:TYPE CL:FIXNUM POSITION ITER-001 UPPER-BOUND-000))
    (CL:LOOP WHILE
     (CL:AND (CL:NOT (CL:EQ ITER-000 NIL))
      (CL:OR UNBOUNDED?-000 (CL:<= ITER-001 UPPER-BOUND-000)))
     DO (CL:SETQ ELEMENT (%%VALUE ITER-000)) (CL:SETQ POSITION ITER-001)
     (CL:WHEN (EQL? ELEMENT OBJECT) (CL:SETQ LAST-POS POSITION))
     (CL:SETQ ITER-000 (%%REST ITER-000))
     (CL:SETQ ITER-001 (CL:1+ ITER-001))))
   (CL:RETURN-FROM LAST-POSITION LAST-POS)))

;;; (DEFMETHOD (MEMBER? BOOLEAN) ...)

(%%DEFCONSMETHOD MEMBER? ((SELF CL:CONS) OBJECT)
  "Return `true' iff `object' is a member of the cons list
`self' (uses an `eql?' test)."
  (CL:IF (CL:OR (CL:EQ OBJECT NULL) (STANDARD-OBJECT? OBJECT))
   (CL:LET* ((I NULL) (ITER-000 SELF))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ I (%%VALUE ITER-000))
     (CL:WHEN (CL:EQ I OBJECT) (CL:RETURN-FROM MEMBER? CL:T))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:LET* ((I NULL) (ITER-001 SELF))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
     (CL:SETQ I (%%VALUE ITER-001))
     (CL:WHEN (EQL? I OBJECT) (CL:RETURN-FROM MEMBER? CL:T))
     (CL:SETQ ITER-001 (%%REST ITER-001)))))
  (CL:RETURN-FROM MEMBER? CL:NIL))

;;; (DEFMETHOD (MEMB? BOOLEAN) ...)

(%%DEFCONSMETHOD MEMB? ((SELF CL:CONS) OBJECT)
  "Return `true' iff `object' is a member of the cons list
`self' (uses an `eq?' test)."
  (CL:LET* ((I NULL) (ITER-000 SELF))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
    (CL:SETQ I (%%VALUE ITER-000))
    (CL:WHEN (CL:EQ I OBJECT) (CL:RETURN-FROM MEMB? CL:T))
    (CL:SETQ ITER-000 (%%REST ITER-000))))
  (CL:RETURN-FROM MEMB? CL:NIL))

;;; (DEFUN (CONS CONS) ...)

(CL:DEFUN CONS (VALUE REST)
  "Return a cons record that points to `value' and `rest'."
  (CL:LET* ((CONS (CL:CONS CL:NIL CL:NIL))) (CL:SETF (%%VALUE CONS) VALUE)
   (CL:SETF (%%REST CONS) REST) (CL:RETURN-FROM CONS CONS)))

;;; (DEFMETHOD (REMOVE (LIKE SELF)) ...)

(%%DEFCONSMETHOD REMOVE ((SELF CL:CONS) VALUE)
  "Destructively remove all entries in the cons list `self' that
match `value'.  Unless the remaining list is `nil', insure that the cons that
heads the list is unchanged."
  (CL:LET* ((CONS SELF) (PREVIOUSCONS NULL))
   (CL:WHEN (CL:NOT (CL:EQ CONS NIL))
    (CL:WHEN (CL:NOT (CL:EQ (%%REST CONS) NIL)) (CL:SETQ PREVIOUSCONS CONS)
     (CL:SETQ CONS (%%REST CONS))
     (CL:LOOP WHILE (CL:NOT (CL:EQ CONS NIL)) DO
      (CL:IF (EQL? (%%VALUE CONS) VALUE)
       (CL:PROGN (CL:SETF (%%REST PREVIOUSCONS) (%%REST CONS))
        (CL:SETQ CONS (%%REST CONS)))
       (CL:PROGN (CL:SETQ PREVIOUSCONS CONS) (CL:SETQ CONS (%%REST CONS))))))
    (CL:WHEN (EQL? (%%VALUE SELF) VALUE)
     (CL:WHEN (CL:EQ (%%REST SELF) NIL) (CL:RETURN-FROM REMOVE NIL))
     (CL:SETQ CONS (%%REST SELF)) (CL:SETF (%%VALUE SELF) (%%VALUE CONS))
     (CL:SETF (%%REST SELF) (%%REST CONS))))
   (CL:RETURN-FROM REMOVE SELF)))

;;; (DEFMETHOD (REMOVE-IF (LIKE SELF)) ...)

(%%DEFCONSMETHOD REMOVE-IF ((SELF CL:CONS) TEST?)
  "Destructively removes all members of the cons list
`self' for which `test?' evaluates to `true'.  `test' takes a single 
argument of type OBJECT and returns `true' or `false'.  Returns a cons list.
In case the first element is removed, the return result should be
assigned to a variable."
  (CL:LET* ((CURSOR SELF) (TRAILER NULL))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NIL)) DO
    (CL:IF
     (CL:AND (CL:FUNCALL TEST? (%%VALUE CURSOR))
      (CL:NOT (CL:EQ TRAILER NULL)))
     (CL:PROGN (CL:SETF (%%REST TRAILER) (%%REST CURSOR))
      (CL:SETQ CURSOR (%%REST TRAILER)))
     (CL:PROGN (CL:SETQ TRAILER CURSOR) (CL:SETQ CURSOR (%%REST CURSOR)))))
   (CL:SETQ CURSOR SELF)
   (CL:WHEN
    (CL:AND (CL:NOT (CL:EQ CURSOR NIL)) (CL:FUNCALL TEST? (%%VALUE CURSOR)))
    (CL:SETQ TRAILER (%%REST CURSOR)) (CL:RETURN-FROM REMOVE-IF TRAILER))
   (CL:RETURN-FROM REMOVE-IF SELF)))

;;; (DEFGLOBAL *REMOVE-DUPLICATES-CROSSOVER-POINT* ...)

(CL:DEFVAR *REMOVE-DUPLICATES-CROSSOVER-POINT* 20
  "Point where we switch from using a quadratic remove
duplicates algorithm to a linear one using a hash table.  For
an unoptimized Common Lisp, 20 is a good crossover point.")
(CL:DECLAIM (CL:TYPE CL:FIXNUM *REMOVE-DUPLICATES-CROSSOVER-POINT*))

;;; (DEFMETHOD (REMOVE-DUPLICATES (LIKE SELF)) ...)

(%%DEFCONSMETHOD REMOVE-DUPLICATES ((SELF CL:CONS))
  "Destructively remove duplicates from `self' and return the
result.  Removes all but the first occurrence of items in the list.
Preserves the original order of the remaining members.  Runs in linear time."
  (CL:IF (CL:> (LENGTH SELF) *REMOVE-DUPLICATES-CROSSOVER-POINT*)
   (CL:RETURN-FROM REMOVE-DUPLICATES
    (REMOVE-DUPLICATES-FROM-LONG-LIST SELF CL:NIL))
   (CL:LET* ((CURSOR SELF) (REST NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NIL)) DO
     (CL:SETQ REST (%%REST CURSOR))
     (CL:WHEN (MEMBER? REST (%%VALUE CURSOR))
      (CL:SETQ REST (REMOVE REST (%%VALUE CURSOR)))
      (CL:SETF (%%REST CURSOR) REST))
     (CL:SETQ CURSOR REST))
    (CL:RETURN-FROM REMOVE-DUPLICATES SELF))))

;;; (DEFMETHOD (REMOVE-DUPLICATES-EQUAL (LIKE SELF)) ...)

(%%DEFCONSMETHOD REMOVE-DUPLICATES-EQUAL ((SELF CL:CONS))
  "`remove-duplicates' (which see) using an `equal?' test."
  (CL:RETURN-FROM REMOVE-DUPLICATES-EQUAL
   (REMOVE-DUPLICATES-FROM-LONG-LIST SELF CL:T)))

;;; (DEFUN (REMOVE-DUPLICATES-FROM-LONG-LIST (LIKE SELF)) ...)

(CL:DEFUN REMOVE-DUPLICATES-FROM-LONG-LIST (SELF EQUALTEST?)
  (CL:LET*
   ((TABLESIZE (CEILING (CL:* (LENGTH SELF) 0.3d0)))
    (TABLE (CL:MAKE-ARRAY TABLESIZE)) (CURSOR SELF) (ITEM NULL) (BUCKET NULL)
    (BUCKETINDEX 0))
   (CL:DECLARE (CL:TYPE CL:FIXNUM TABLESIZE BUCKETINDEX)
    (CL:TYPE CL:SIMPLE-VECTOR TABLE))
   (CL:LET*
    ((I NULL-INTEGER) (ITER-000 0) (UPPER-BOUND-000 (CL:1- TABLESIZE)))
    (CL:DECLARE (CL:TYPE CL:FIXNUM I ITER-000 UPPER-BOUND-000))
    (CL:LOOP WHILE (CL:<= ITER-000 UPPER-BOUND-000) DO (CL:SETQ I ITER-000)
     (CL:SETF (CL:AREF TABLE I) NIL) (CL:SETQ ITER-000 (CL:1+ ITER-000))))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NIL)) DO
    (CL:SETQ ITEM (%%VALUE CURSOR))
    (CL:SETQ BUCKETINDEX
     (CL:LET ((CODE (HASH-CODE ITEM)) (SIZE TABLESIZE))
      (CL:DECLARE (CL:TYPE CL:FIXNUM CODE SIZE))
      (CL:THE CL:FIXNUM
       (CL:REM
        (CL:THE CL:FIXNUM (CL:LOGAND CODE *INTEGER-UNSIGNED-BITS-MASK*))
        SIZE))))
    (CL:SETQ BUCKET (CL:AREF TABLE BUCKETINDEX))
    (CL:LET* ((FOUND?-000 CL:NIL))
     (CL:LET* ((IT NULL) (ITER-001 BUCKET))
      (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
       (CL:SETQ IT (%%VALUE ITER-001))
       (CL:WHEN (CL:IF EQUALTEST? (EQUAL? IT ITEM) (EQL? IT ITEM))
        (CL:SETQ FOUND?-000 CL:T) (CL:RETURN))
       (CL:SETQ ITER-001 (%%REST ITER-001))))
     (CL:IF FOUND?-000 (CL:SETF (%%VALUE CURSOR) NULL)
      (CL:SETF (CL:AREF TABLE BUCKETINDEX) (CONS ITEM BUCKET))))
    (CL:SETQ CURSOR (%%REST CURSOR)))
   (CL:RETURN-FROM REMOVE-DUPLICATES-FROM-LONG-LIST (REMOVE SELF NULL))))

;;; (DEFMETHOD (CONCATENATE CONS) ...)

(%%DEFCONSMETHOD CONCATENATE ((LIST1 CL:CONS) LIST2 CL:&REST OTHERLISTS)
  "Return a cons list consisting of the concatenation of 
`list1', `list2', and `otherLists'.  The operation is destructive wrt all
but the last list argument which is left intact.  The two mandatory
parameters allow us to optimize the common binary case by not relying on
the somewhat less efficient variable arguments mechanism."
  (CL:IF (CL:EQ LIST1 NIL) (CL:SETQ LIST1 LIST2)
   (CL:IF (CL:EQ LIST2 NIL) (CL:SETQ LIST2 LIST1)
    (CL:SETF (%%REST (LAST-CONS LIST1)) LIST2)))
  (CL:WHEN (CL:> (CL:LENGTH OTHERLISTS) 0)
   (CL:LET* ((LIST NULL) (ITER-000 OTHERLISTS))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ LIST (CL:POP ITER-000))
     (CL:WHEN (CL:NOT (CL:EQ LIST NIL))
      (CL:IF (CL:NOT (CL:EQ LIST2 NIL))
       (CL:SETF (%%REST (LAST-CONS LIST2)) LIST) (CL:SETQ LIST1 LIST))
      (CL:SETQ LIST2 LIST)))))
  (CL:RETURN-FROM CONCATENATE LIST1))

;;; (DEFMETHOD (PREPEND CONS) ...)

(%%DEFCONSMETHOD PREPEND ((SELF CL:CONS) LIST1)
  "Return a cons list consisting of the concatenation of
`list1' and `self'.  A copy of `list1' is prepended to `self'.  This
operation results in structure sharing of `self'; to avoid this, `self'
should not be pointed to by anything other than the tail of the prepended
copy."
  (CL:WHEN (CL:EQ LIST1 NIL) (CL:RETURN-FROM PREPEND SELF))
  (CL:LET* ((COPY1 (COPY-CONS-LIST LIST1))) (CONCATENATE COPY1 SELF)
   (CL:RETURN-FROM PREPEND COPY1)))

;;; (DEFMETHOD (REVERSE (LIKE SELF)) ...)

(%%DEFCONSMETHOD REVERSE ((SELF CL:CONS))
  "Destructively reverse the members of the cons list `self'."
  (CL:WHEN (CL:EQ SELF NIL) (CL:RETURN-FROM REVERSE SELF))
  (CL:LET*
   ((REVERSEDCONSLIST SELF) (REMAININGCONSLIST (%%REST REVERSEDCONSLIST))
    (DETACHEDCONS NULL))
   (CL:WHEN (CL:EQ REMAININGCONSLIST NIL)
    (CL:RETURN-FROM REVERSE REVERSEDCONSLIST))
   (CL:SETF (%%REST REVERSEDCONSLIST) NIL)
   (CL:LOOP WHILE (CL:NOT (CL:EQ REMAININGCONSLIST NIL)) DO
    (CL:SETQ DETACHEDCONS REMAININGCONSLIST)
    (CL:SETQ REMAININGCONSLIST (%%REST REMAININGCONSLIST))
    (CL:SETF (%%REST DETACHEDCONS) REVERSEDCONSLIST)
    (CL:SETQ REVERSEDCONSLIST DETACHEDCONS))
   (CL:RETURN-FROM REVERSE REVERSEDCONSLIST)))

;;; (DEFMETHOD (SUBSTITUTE CONS) ...)

(%%DEFCONSMETHOD SUBSTITUTE ((SELF CL:CONS) INVALUE OUTVALUE)
  "Destructively replace each appearance of `outValue' by
`inValue' in the cons list `self'."
  (CL:LET* ((CURSOR SELF))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NIL)) DO
    (CL:WHEN (EQL? (%%VALUE CURSOR) OUTVALUE)
     (CL:SETF (%%VALUE CURSOR) INVALUE))
    (CL:SETQ CURSOR (%%REST CURSOR)))
   (CL:RETURN-FROM SUBSTITUTE SELF)))

;;; (DEFUN (MAP-NULL-TO-NIL (LIKE SELF)) ...)

(CL:DEFUN MAP-NULL-TO-NIL (SELF)
  "Return `nil' iff `self' is `null' or `self' otherwise."
  (CL:RETURN-FROM MAP-NULL-TO-NIL (CL:IF (CL:EQ SELF NULL) NIL SELF)))

;;; (DEFMETHOD (FIRST (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD FIRST ((SELF CL:CONS))
  "Return the first element of `self'.  The first element
of `self' can be set with `setf'.  Note that '(first NIL)' = `null'."
  (CL:RETURN-FROM FIRST (%%VALUE SELF)))

;;; (DEFMETHOD (SECOND (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD SECOND ((SELF CL:CONS))
  "Return the second element of `self'.  The second element
of `self' can be set with `setf'.  Note that '(second NIL)' = `null'."
  (CL:RETURN-FROM SECOND (%%VALUE (%%REST SELF))))

;;; (DEFMETHOD (THIRD (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD THIRD ((SELF CL:CONS))
  "Return the third element of `self'.  The third element
of `self' can be set with `setf'.  Note that '(third NIL)' = `null'."
  (CL:RETURN-FROM THIRD (%%VALUE (%%REST (%%REST SELF)))))

;;; (DEFMETHOD (FOURTH (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD FOURTH ((SELF CL:CONS))
  "Return the fourth element of `self'.  The fourth element
of `self' can be set with `setf'.  Note that '(fourth NIL)' = `null'."
  (CL:RETURN-FROM FOURTH (%%VALUE (%%REST (%%REST (%%REST SELF))))))

;;; (DEFMETHOD (FIFTH (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD FIFTH ((SELF CL:CONS))
  "Return the fifth element of `self'.  The fifth element
of `self' can be set with `setf'.  Note, that '(fifth NIL)' = `null'."
  (CL:RETURN-FROM FIFTH (%%VALUE (%%REST (%%REST (%%REST (%%REST SELF)))))))

;;; (DEFMETHOD (NTH (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD NTH ((SELF CL:CONS) POSITION)
  "Return the element of `self' at `position'.  The nth element
of `self' can be set with `setf'.  Note, that '(nth NIL <pos>)' = `null'."
  (CL:DECLARE (CL:TYPE CL:FIXNUM POSITION))
  #+MCL
  (CL:CHECK-TYPE POSITION CL:FIXNUM)
  (CL:LET* ((I -1)) (CL:DECLARE (CL:TYPE CL:FIXNUM I))
   (CL:LET* ((VALUE NULL) (ITER-000 SELF))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ VALUE (%%VALUE ITER-000))
     (CL:WHEN (CL:= (CL:SETQ I (CL:1+ I)) POSITION)
      (CL:RETURN-FROM NTH VALUE))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:RETURN-FROM NTH NULL)))

;;; (DEFMETHOD (NTH-REST (LIKE SELF)) ...)

(%%DEFCONSMETHOD NTH-REST ((SELF CL:CONS) POSITION)
  "Apply `rest' `position' times to `self'."
  (CL:DECLARE (CL:TYPE CL:FIXNUM POSITION))
  #+MCL
  (CL:CHECK-TYPE POSITION CL:FIXNUM)
  (CL:WHEN (CL:< POSITION 0) (CL:RETURN-FROM NTH-REST NULL))
  (CL:LET* ((CURSOR SELF))
   (CL:LET*
    ((I NULL-INTEGER) (ITER-000 1) (UPPER-BOUND-000 POSITION)
     (UNBOUNDED?-000 (CL:= UPPER-BOUND-000 NULL-INTEGER)))
    (CL:DECLARE (CL:TYPE CL:FIXNUM I ITER-000 UPPER-BOUND-000))
    (CL:LOOP WHILE (CL:OR UNBOUNDED?-000 (CL:<= ITER-000 UPPER-BOUND-000)) DO
     (CL:SETQ I ITER-000) (CL:SETQ I I) (CL:SETQ CURSOR (%%REST CURSOR))
     (CL:WHEN (CL:EQ CURSOR NIL) (CL:RETURN-FROM NTH-REST NIL))
     (CL:SETQ ITER-000 (CL:1+ ITER-000))))
   (CL:RETURN-FROM NTH-REST CURSOR)))

;;; (DEFUN (LAST-CONS (CONS OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFUN LAST-CONS (SELF)
  "Return the last cons of `self'."
  (CL:LOOP WHILE (CL:NOT (CL:EQ (%%REST SELF) NIL)) DO
   (CL:SETQ SELF (%%REST SELF)))
  (CL:RETURN-FROM LAST-CONS SELF))

;;; (DEFMETHOD (LAST (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD LAST ((SELF CL:CONS))
  "Return the last element of `self'."
  (CL:RETURN-FROM LAST (%%VALUE (LAST-CONS SELF))))

;;; (DEFMETHOD (FIRST-SETTER (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD FIRST-SETTER ((SELF CL:CONS) VALUE)
  (CL:WHEN (CL:EQ SELF NIL)
   (CL:WARN "Can't apply first setter to empty list.")
   (CL:RETURN-FROM FIRST-SETTER NULL))
  (CL:RETURN-FROM FIRST-SETTER (CL:SETF (%%VALUE SELF) VALUE)))

;;; (DEFMETHOD (SECOND-SETTER (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD SECOND-SETTER ((SELF CL:CONS) VALUE)
  (CL:WHEN (CL:EQ (%%REST SELF) NIL)
   (CL:WARN "'second setter' applied to too short cons list.")
   (CL:RETURN-FROM SECOND-SETTER NULL))
  (CL:RETURN-FROM SECOND-SETTER (CL:SETF (%%VALUE (%%REST SELF)) VALUE)))

;;; (DEFMETHOD (THIRD-SETTER (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD THIRD-SETTER ((SELF CL:CONS) VALUE)
  (CL:LET* ((THIRDCONS (%%REST (%%REST SELF))))
   (CL:IF (CL:NOT (CL:EQ THIRDCONS NIL))
    (CL:RETURN-FROM THIRD-SETTER (CL:SETF (%%VALUE THIRDCONS) VALUE))
    (CL:PROGN (CL:WARN "'third setter' applied to too short cons list.")
     (CL:RETURN-FROM THIRD-SETTER NULL)))))

;;; (DEFMETHOD (NTH-SETTER (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD NTH-SETTER ((SELF CL:CONS) VALUE POSITION)
  (CL:DECLARE (CL:TYPE CL:FIXNUM POSITION))
  #+MCL
  (CL:CHECK-TYPE POSITION CL:FIXNUM)
  (CL:WHEN (CL:< POSITION 0)
   (CL:WARN "Can't apply nth setter to negative position `~A'." POSITION)
   (CL:RETURN-FROM NTH-SETTER NULL))
  (CL:LET* ((CURSOR SELF))
   (CL:LET*
    ((I NULL-INTEGER) (ITER-000 1) (UPPER-BOUND-000 POSITION)
     (UNBOUNDED?-000 (CL:= UPPER-BOUND-000 NULL-INTEGER)))
    (CL:DECLARE (CL:TYPE CL:FIXNUM I ITER-000 UPPER-BOUND-000))
    (CL:LOOP WHILE (CL:OR UNBOUNDED?-000 (CL:<= ITER-000 UPPER-BOUND-000)) DO
     (CL:SETQ I ITER-000) (CL:SETQ I I) (CL:SETQ CURSOR (%%REST CURSOR))
     (CL:WHEN (CL:EQ CURSOR NIL)
      (CL:WARN "'nth setter' ran off end of cons list.")
      (CL:RETURN-FROM NTH-SETTER NULL))
     (CL:SETQ ITER-000 (CL:1+ ITER-000))))
   (CL:SETF (%%VALUE CURSOR) VALUE) (CL:RETURN-FROM NTH-SETTER VALUE)))

;;; (DEFMETHOD (FOURTH-SETTER (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD FOURTH-SETTER ((SELF CL:CONS) VALUE)
  (CL:RETURN-FROM FOURTH-SETTER (NTH-SETTER SELF VALUE 3)))

;;; (DEFMETHOD (FIFTH-SETTER (LIKE (ANY-VALUE SELF))) ...)

(%%DEFCONSMETHOD FIFTH-SETTER ((SELF CL:CONS) VALUE)
  (CL:RETURN-FROM FIFTH-SETTER (NTH-SETTER SELF VALUE 4)))

;;; (DEFMETHOD (NTH-REST-SETTER OBJECT) ...)

(%%DEFCONSMETHOD NTH-REST-SETTER ((SELF CL:CONS) VALUE POSITION)
  (CL:DECLARE (CL:TYPE CL:FIXNUM POSITION))
  #+MCL
  (CL:CHECK-TYPE POSITION CL:FIXNUM)
  (CL:WHEN (CL:<= POSITION 0)
   (CL:WARN "Can't apply nth-rest setter to negative position `~A'." POSITION))
  (CL:LET* ((CURSOR SELF))
   (CL:LET*
    ((I NULL-INTEGER) (ITER-000 2) (UPPER-BOUND-000 POSITION)
     (UNBOUNDED?-000 (CL:= UPPER-BOUND-000 NULL-INTEGER)))
    (CL:DECLARE (CL:TYPE CL:FIXNUM I ITER-000 UPPER-BOUND-000))
    (CL:LOOP WHILE (CL:OR UNBOUNDED?-000 (CL:<= ITER-000 UPPER-BOUND-000)) DO
     (CL:SETQ I ITER-000) (CL:SETQ I I) (CL:SETQ CURSOR (%%REST CURSOR))
     (CL:WHEN (CL:EQ CURSOR NIL)
      (CL:WARN "'nth-rest setter' ran off end of cons list.")
      (CL:RETURN-FROM NTH-REST-SETTER NULL))
     (CL:SETQ ITER-000 (CL:1+ ITER-000))))
   (CL:SETF (%%REST CURSOR) VALUE) (CL:RETURN-FROM NTH-REST-SETTER VALUE)))

;;; (DEFMETHOD (ALLOCATE-ITERATOR (CONS-ITERATOR OF (LIKE (ANY-VALUE SELF)))) ...)

(%%DEFCONSMETHOD ALLOCATE-ITERATOR ((SELF CL:CONS))
  (CL:LET* ((ITERATOR (NEW-CONS-ITERATOR)))
   (CL:SETF (%CONS-ITERATOR-CURSOR ITERATOR) SELF)
   (CL:SETF (%FIRST-ITERATION? ITERATOR) CL:T)
   (CL:RETURN-FROM ALLOCATE-ITERATOR ITERATOR)))

;;; (DEFUN (TERMINATE-CONS-ITERATOR? BOOLEAN) ...)

(CL:DEFUN TERMINATE-CONS-ITERATOR? (SELF)
  (CL:SETF (%CONS-ITERATOR-CURSOR SELF) NULL)
  (CL:RETURN-FROM TERMINATE-CONS-ITERATOR? CL:T))

;;; (DEFMETHOD (NEXT? BOOLEAN) ...)

(CL:DEFMETHOD NEXT? ((SELF CONS-ITERATOR))
  (CL:IF (%FIRST-ITERATION? SELF) (CL:SETF (%FIRST-ITERATION? SELF) CL:NIL)
   (CL:SETF (%CONS-ITERATOR-CURSOR SELF)
    (%%REST (%CONS-ITERATOR-CURSOR SELF))))
  (CL:SETF (%VALUE SELF) (%%VALUE (%CONS-ITERATOR-CURSOR SELF)))
  (CL:RETURN-FROM NEXT? (CL:NOT (CL:EQ (%CONS-ITERATOR-CURSOR SELF) NIL))))

;;; (DEFMETHOD (EMPTY? BOOLEAN) ...)

(CL:DEFMETHOD EMPTY? ((SELF CONS-ITERATOR))
  (CL:RETURN-FROM EMPTY?
   (CL:IF (%FIRST-ITERATION? SELF) (CL:EQ (%CONS-ITERATOR-CURSOR SELF) NIL)
    (CL:EQ (%%REST (%CONS-ITERATOR-CURSOR SELF)) NIL))))

;;; (DEFMETHOD (LENGTH INTEGER) ...)

(CL:DEFMETHOD LENGTH ((SELF CONS-ITERATOR))
  "Iterate over 'self', and count how many items there are."
  (CL:LET*
   ((COUNT
     (CL:IF (%FIRST-ITERATION? SELF) (LENGTH (%CONS-ITERATOR-CURSOR SELF))
      (LENGTH (%%REST (%CONS-ITERATOR-CURSOR SELF))))))
   (CL:DECLARE (CL:TYPE CL:FIXNUM COUNT))
   (CL:SETF (%CONS-ITERATOR-CURSOR SELF) NIL) (CL:RETURN-FROM LENGTH COUNT)))

;;; (DEFMETHOD (MEMBER? BOOLEAN) ...)

(CL:DEFMETHOD MEMBER? ((SELF CONS-ITERATOR) VALUE)
  "Iterate over values of `self' and return TRUE
if one of them is `eql?' to 'value."
  (CL:LET*
   ((RESULT
     (CL:IF (%FIRST-ITERATION? SELF)
      (MEMBER? (%CONS-ITERATOR-CURSOR SELF) VALUE)
      (MEMBER? (%%REST (%CONS-ITERATOR-CURSOR SELF)) VALUE))))
   (CL:SETF (%CONS-ITERATOR-CURSOR SELF) NIL) (CL:RETURN-FROM MEMBER? RESULT)))

;;; (DEFMETHOD (VALUE-SETTER OBJECT) ...)

(CL:DEFMETHOD VALUE-SETTER ((SELF CONS-ITERATOR) VALUE)
  (CL:SETF (%%VALUE (%CONS-ITERATOR-CURSOR SELF)) VALUE)
  (CL:SETF (%VALUE SELF) VALUE)
  (CL:RETURN-FROM VALUE-SETTER VALUE))

;;; (DEFUN ADD-CONS-TO-END-OF-CONS-LIST ...)

(CL:DEFUN ADD-CONS-TO-END-OF-CONS-LIST (SELF LASTCONS)
  (CL:LOOP WHILE (CL:NOT (CL:EQ (%%REST SELF) NIL)) DO
   (CL:SETQ SELF (%%REST SELF)))
  (CL:SETF (%%REST SELF) LASTCONS)
  :VOID)

;;; (DEFUN (BUT-LAST-NEXT? BOOLEAN) ...)

(CL:DEFUN BUT-LAST-NEXT? (SELF)
  (CL:IF (%FIRST-ITERATION? SELF) (CL:SETF (%FIRST-ITERATION? SELF) CL:NIL)
   (CL:SETF (%ITERATOR-CONS-LIST SELF) (%%REST (%ITERATOR-CONS-LIST SELF))))
  (CL:WHEN (CL:EQ (%%REST (%ITERATOR-CONS-LIST SELF)) NIL)
   (CL:RETURN-FROM BUT-LAST-NEXT? CL:NIL))
  (CL:SETF (%VALUE SELF) (%%VALUE (%ITERATOR-CONS-LIST SELF)))
  (CL:RETURN-FROM BUT-LAST-NEXT? CL:T))

;;; (DEFMETHOD (BUT-LAST (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ...)

(%%DEFCONSMETHOD BUT-LAST ((SELF CL:CONS))
  "Generate all but the last element of the cons list `self'."
  (CL:LET* ((ITERATOR (NEW-ALL-PURPOSE-ITERATOR)))
   (CL:SETF (%ITERATOR-CONS-LIST ITERATOR) SELF)
   (CL:SETF (%FIRST-ITERATION? ITERATOR) CL:T)
   (CL:SETF (%ITERATOR-NEXT-CODE ITERATOR) (CL:FUNCTION BUT-LAST-NEXT?))
   (CL:RETURN-FROM BUT-LAST ITERATOR)))

;;; (DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ...)

(%%DEFCONSMETHOD CONSIFY ((SELF CL:CONS))
  "Return `self'."
  (CL:RETURN-FROM CONSIFY SELF))

;;; (DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD CONSIFY ((SELF LIST))
  "Return a list of elements in `self'."
  (CL:RETURN-FROM CONSIFY (%THE-CONS-LIST SELF)))

;;; (DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD CONSIFY ((SELF KEY-VALUE-LIST))
  "Return a list of key-value pairs in `self'."
  (CL:LET* ((RESULT NIL))
   (CL:LET*
    ((K NULL) (V NULL) (ITER-000 (%THE-KV-LIST SELF)) (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NULL)) DO
     (CL:SETQ K (%KEY ITER-000)) (CL:SETQ V (%VALUE ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS (CONS K (CONS V NIL)) NIL))
       (CL:IF (CL:EQ RESULT NIL) (CL:SETQ RESULT COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST RESULT COLLECT-000)))
      (CL:PROGN
       (CL:SETF (%%REST COLLECT-000) (CONS (CONS K (CONS V NIL)) NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))
     (CL:SETQ ITER-000 (%REST ITER-000))))
   (CL:RETURN-FROM CONSIFY RESULT)))

;;; (DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD CONSIFY ((SELF VECTOR))
  "Return a list of elements in `self'."
  (CL:LET* ((RESULT NIL))
   (CL:LET*
    ((V NULL) (VECTOR-000 SELF) (INDEX-000 0) (LENGTH-000 (LENGTH VECTOR-000))
     (COLLECT-000 NULL))
    (CL:DECLARE (CL:TYPE CL:FIXNUM INDEX-000 LENGTH-000))
    (CL:LOOP WHILE (CL:< INDEX-000 LENGTH-000) DO
     (CL:SETQ V
      (CL:AREF (CL:THE CL:SIMPLE-VECTOR (%THE-ARRAY VECTOR-000)) INDEX-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS V NIL))
       (CL:IF (CL:EQ RESULT NIL) (CL:SETQ RESULT COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST RESULT COLLECT-000)))
      (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS V NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))
     (CL:SETQ INDEX-000 (CL:1+ INDEX-000))))
   (CL:RETURN-FROM CONSIFY RESULT)))

;;; (DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD CONSIFY ((SELF ITERATOR))
  "Return a list of elements generated by `self'."
  (CL:LET* ((LIST NIL))
   (CL:LET* ((VALUE NULL) (ITER-000 SELF))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ VALUE (%VALUE ITER-000))
     (CL:SETQ LIST (CONS VALUE LIST))))
   (CL:RETURN-FROM CONSIFY (REVERSE LIST))))

;;; (DEFMETHOD (CONSIFY CONS) ...)

(CL:DEFMETHOD CONSIFY ((SELF OBJECT))
  "If `object' is a CONS, return it.  Otherwise, return
a singleton cons list containing it."
  (CL:RETURN-FROM CONSIFY (CL:IF (CONS? SELF) SELF (CONS SELF NIL))))

;;; (DEFMETHOD (REMOVE-DELETED-MEMBERS (LIKE SELF)) ...)

(%%DEFCONSMETHOD REMOVE-DELETED-MEMBERS ((SELF CL:CONS))
  (CL:LET* ((CURSOR SELF) (TRAILER NULL))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NIL)) DO
    (CL:IF (CL:AND (DELETED? (%%VALUE CURSOR)) (CL:NOT (CL:EQ TRAILER NULL)))
     (CL:PROGN (CL:SETF (%%REST TRAILER) (%%REST CURSOR))
      (CL:SETQ CURSOR (%%REST TRAILER)))
     (CL:PROGN (CL:SETQ TRAILER CURSOR) (CL:SETQ CURSOR (%%REST CURSOR)))))
   (CL:WHEN (CL:AND (CL:NOT (CL:EQ SELF NIL)) (DELETED? (%%VALUE SELF)))
    (CL:RETURN-FROM REMOVE-DELETED-MEMBERS (%%REST SELF)))
   (CL:RETURN-FROM REMOVE-DELETED-MEMBERS SELF)))

;;; (DEFUN (COPY-CONS-LIST (LIKE SELF)) ...)

(CL:DEFUN COPY-CONS-LIST (SELF)
  "Return a copy of the cons list `self'."
  (CL:WHEN (CL:EQ SELF NIL) (CL:RETURN-FROM COPY-CONS-LIST NIL))
  (CL:LET*
   ((NEWCONSLIST (CONS (%%VALUE SELF) NIL)) (NEXTCONS NEWCONSLIST)
    (COPYFROMCONS NULL) (PREVIOUSCONS NULL))
   (CL:SETQ COPYFROMCONS (%%REST SELF))
   (CL:LOOP WHILE (CL:NOT (CL:EQ COPYFROMCONS NIL)) DO
    (CL:SETQ PREVIOUSCONS NEXTCONS)
    (CL:SETQ NEXTCONS (CONS (%%VALUE COPYFROMCONS) NIL))
    (CL:SETF (%%REST PREVIOUSCONS) NEXTCONS)
    (CL:SETQ COPYFROMCONS (%%REST COPYFROMCONS)))
   (CL:RETURN-FROM COPY-CONS-LIST NEWCONSLIST)))

;;; (DEFUN (CONS-LIST CONS) ...)

(CL:DEFUN CONS-LIST (CL:&REST VALUES)
  "Return a cons list containing `values', in order."
  (CL:LET* ((LIST NIL))
   (CL:LET* ((V NULL) (ITER-000 VALUES) (COLLECT-000 NULL))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ V (CL:POP ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS V NIL))
       (CL:IF (CL:EQ LIST NIL) (CL:SETQ LIST COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST LIST COLLECT-000)))
      (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS V NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
   (CL:RETURN-FROM CONS-LIST LIST)))

;;; (DEFUN (LIST* CONS) ...)

(CL:DEFUN LIST* (CL:&REST VALUES)
  "Return a list of conses that make up the list `values',
terminated by the last value rather than by `nil'.  Assumes that
at least one value is passed in."
  (CL:LET* ((HEADCONS NIL) (ANSWER NULL) (LASTCONS NULL))
   (CL:LET* ((V NULL) (ITER-000 VALUES))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ V (CL:POP ITER-000))
     (CL:SETQ HEADCONS (CONS V HEADCONS))))
   (CL:SETQ ANSWER (REVERSE (%%REST HEADCONS)))
   (CL:WHEN (CL:EQ ANSWER NIL) (CL:SETQ ANSWER (%%VALUE HEADCONS))
    (CL:RETURN-FROM LIST* ANSWER))
   (CL:SETQ LASTCONS ANSWER)
   (CL:LOOP WHILE (CL:NOT (CL:EQ (%%REST LASTCONS) NIL)) DO
    (CL:SETQ LASTCONS (%%REST LASTCONS)))
   (CL:SETF (%%REST LASTCONS) (%%VALUE HEADCONS))
   (CL:RETURN-FROM LIST* ANSWER)))

;;; (DEFUN (APPEND CONS) ...)

(CL:DEFUN APPEND (CONSLIST1 CONSLIST2)
  "Return a cons list representing the concatenation
of `consList1' and `consList2'.  The concatenation is NOT destructive."
  (CL:COND ((CL:EQ CONSLIST1 NIL) (CL:RETURN-FROM APPEND CONSLIST2))
   ((CL:EQ CONSLIST2 NIL) (CL:RETURN-FROM APPEND CONSLIST1))
   (CL:T
    (CL:RETURN-FROM APPEND
     (CONCATENATE (COPY-CONS-LIST CONSLIST1) CONSLIST2)))))

;;; (DEFMETHOD (SUBSET? BOOLEAN) ...)

(%%DEFCONSMETHOD SUBSET? ((SELF CL:CONS) OTHERLIST)
  "Return true if every element of `self' also occurs in `otherList'.
Uses an `eql?' test and a simple quadratic-time algorithm.  Note that
this does not check whether `self' and `otherList' actually are sets."
  (CL:LET* ((ALWAYS?-000 CL:T))
   (CL:LET* ((ITEM NULL) (ITER-000 SELF))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ ITEM (%%VALUE ITER-000))
     (CL:WHEN (CL:NOT (MEMBER? OTHERLIST ITEM)) (CL:SETQ ALWAYS?-000 CL:NIL)
      (CL:RETURN))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:LET* ((VALUE-000 ALWAYS?-000)) (CL:RETURN-FROM SUBSET? VALUE-000))))

;;; (DEFMETHOD (EQUIVALENT-SETS? BOOLEAN) ...)

(%%DEFCONSMETHOD EQUIVALENT-SETS? ((SELF CL:CONS) OTHERLIST)
  "Return true if every element of `self' occurs in `otherList' and vice versa.
Uses an `eql?' test and a simple quadratic-time algorithm.  Note that
this does not check whether `self' and `otherList' actually are sets."
  (CL:LET* ((TEST-VALUE-000 CL:NIL))
   (CL:SETQ TEST-VALUE-000 (CL:= (LENGTH SELF) (LENGTH OTHERLIST)))
   (CL:WHEN TEST-VALUE-000
    (CL:LET* ((ALWAYS?-000 CL:T))
     (CL:LET* ((ITEM NULL) (ITER-000 SELF))
      (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
       (CL:SETQ ITEM (%%VALUE ITER-000))
       (CL:WHEN (CL:NOT (MEMBER? OTHERLIST ITEM)) (CL:SETQ ALWAYS?-000 CL:NIL)
        (CL:RETURN))
       (CL:SETQ ITER-000 (%%REST ITER-000))))
     (CL:SETQ TEST-VALUE-000 ALWAYS?-000)))
   (CL:LET* ((VALUE-000 TEST-VALUE-000))
    (CL:RETURN-FROM EQUIVALENT-SETS? VALUE-000))))

;;; (DEFMETHOD (INTERSECTION CONS) ...)

(%%DEFCONSMETHOD INTERSECTION ((SELF CL:CONS) OTHERLIST)
  "Return the set intersection of `self' and `otherList'.  Uses an `eql?'
test and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if both `self' and `otherList' are sets."
  (CL:LET* ((LIST NIL))
   (CL:WHEN (CL:EQ OTHERLIST NULL) (CL:RETURN-FROM INTERSECTION LIST))
   (CL:LET* ((I NULL) (ITER-000 SELF) (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ I (%%VALUE ITER-000))
     (CL:WHEN (MEMBER? OTHERLIST I)
      (CL:IF (CL:EQ COLLECT-000 NULL)
       (CL:PROGN (CL:SETQ COLLECT-000 (CONS I NIL))
        (CL:IF (CL:EQ LIST NIL) (CL:SETQ LIST COLLECT-000)
         (ADD-CONS-TO-END-OF-CONS-LIST LIST COLLECT-000)))
       (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS I NIL))
        (CL:SETQ COLLECT-000 (%%REST COLLECT-000)))))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:RETURN-FROM INTERSECTION LIST)))

;;; (DEFMETHOD (UNION CONS) ...)

(%%DEFCONSMETHOD UNION ((SELF CL:CONS) OTHERLIST)
  "Return the set union of `self' and `otherList'.  Uses an `eql?' test
and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if both `self' and `otherList' are sets."
  (CL:LET* ((LIST (COPY-CONS-LIST SELF)) (OTHERSURVIVORS NIL))
   (CL:WHEN (CL:EQ OTHERLIST NULL) (CL:RETURN-FROM UNION LIST))
   (CL:LET* ((I NULL) (ITER-000 OTHERLIST) (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ I (%%VALUE ITER-000))
     (CL:WHEN (CL:NOT (MEMBER? LIST I))
      (CL:IF (CL:EQ COLLECT-000 NULL)
       (CL:PROGN (CL:SETQ COLLECT-000 (CONS I NIL))
        (CL:IF (CL:EQ OTHERSURVIVORS NIL) (CL:SETQ OTHERSURVIVORS COLLECT-000)
         (ADD-CONS-TO-END-OF-CONS-LIST OTHERSURVIVORS COLLECT-000)))
       (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS I NIL))
        (CL:SETQ COLLECT-000 (%%REST COLLECT-000)))))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:RETURN-FROM UNION (CONCATENATE LIST OTHERSURVIVORS))))

;;; (DEFMETHOD (DIFFERENCE CONS) ...)

(%%DEFCONSMETHOD DIFFERENCE ((SELF CL:CONS) OTHERLIST)
  "Return the set difference of `self' and `otherList' (i.e., all elements
that are in `self' but not in `otherSet').  Uses an `eql?' test and a simple
quadratic-time algorithm.  Note that the result is only guaranteed to be a
set if both `self' and `otherList' are sets."
  (CL:WHEN (CL:OR (CL:EQ OTHERLIST NULL) (CL:EQ OTHERLIST NIL))
   (CL:RETURN-FROM DIFFERENCE (COPY-CONS-LIST SELF)))
  (CL:LET* ((DIFF NIL))
   (CL:LET* ((I NULL) (ITER-000 SELF) (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ I (%%VALUE ITER-000))
     (CL:WHEN (CL:NOT (MEMBER? OTHERLIST I))
      (CL:IF (CL:EQ COLLECT-000 NULL)
       (CL:PROGN (CL:SETQ COLLECT-000 (CONS I NIL))
        (CL:IF (CL:EQ DIFF NIL) (CL:SETQ DIFF COLLECT-000)
         (ADD-CONS-TO-END-OF-CONS-LIST DIFF COLLECT-000)))
       (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS I NIL))
        (CL:SETQ COLLECT-000 (%%REST COLLECT-000)))))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:RETURN-FROM DIFFERENCE DIFF)))

;;; (DEFMETHOD (SUBTRACT CONS) ...)

(%%DEFCONSMETHOD SUBTRACT ((SELF CL:CONS) OTHERLIST)
  "Return the set difference of `self' and `otherList' by destructively
removing elements from `self' that also occur in `otherList'.  Uses an `eql?'
test and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if `self' is a set."
  (CL:WHEN (CL:EQ OTHERLIST NULL) (CL:RETURN-FROM SUBTRACT SELF))
  (CL:LET* ((I NULL) (ITER-000 OTHERLIST))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
    (CL:SETQ I (%%VALUE ITER-000))
    (CL:WHEN (MEMBER? SELF I) (CL:SETQ SELF (REMOVE SELF I)))
    (CL:SETQ ITER-000 (%%REST ITER-000))))
  (CL:RETURN-FROM SUBTRACT SELF))

;;; (DEFMETHOD (SORT (CONS OF (LIKE (ANY-VALUE SELF)))) ...)

(%%DEFCONSMETHOD SORT ((SELF CL:CONS) PREDICATE)
  "Perform a stable, destructive sort of `self' according to
`predicate', and return the result.  If `predicate' has a '<' semantics, the
result will be in ascending order.  It is not guaranteed that `self' will
point to the beginning of the sorted result.  If `predicate' is `null', a
suitable '<' predicate is chosen depending on the first element of `self',
and it is assumed that all elements of `self' have the same type (supported
element types are GENERALIZED-SYMBOL, STRING, INTEGER, and FLOAT)."
  (CL:WHEN (CL:EQ PREDICATE NULL)
   (CL:SETQ PREDICATE (CHOOSE-SORT-PREDICATE (%%VALUE SELF))))
  (CL:RETURN-FROM SORT (HELP-SORT-CONS-LIST SELF (LENGTH SELF) PREDICATE)))

;;; (DEFUN (HELP-SORT-CONS-LIST CONS) ...)

(CL:DEFUN HELP-SORT-CONS-LIST (LIST LENGTH PREDICATE)
  (CL:DECLARE (CL:TYPE CL:FIXNUM LENGTH))
  #+MCL
  (CL:CHECK-TYPE LENGTH CL:FIXNUM)
  (CL:WHEN (CL:< LENGTH 2) (CL:RETURN-FROM HELP-SORT-CONS-LIST LIST))
  (CL:LET* ((FRONTLENGTH (FLOOR (CL:/ LENGTH 2.0d0))) (TEMP LIST) (BACK NIL))
   (CL:DECLARE (CL:TYPE CL:FIXNUM FRONTLENGTH))
   (CL:LET*
    ((I NULL-INTEGER) (ITER-000 2) (UPPER-BOUND-000 FRONTLENGTH)
     (UNBOUNDED?-000 (CL:= UPPER-BOUND-000 NULL-INTEGER)))
    (CL:DECLARE (CL:TYPE CL:FIXNUM I ITER-000 UPPER-BOUND-000))
    (CL:LOOP WHILE (CL:OR UNBOUNDED?-000 (CL:<= ITER-000 UPPER-BOUND-000)) DO
     (CL:SETQ I ITER-000) (CL:SETQ I I) (CL:SETQ TEMP (%%REST TEMP))
     (CL:SETQ ITER-000 (CL:1+ ITER-000))))
   (CL:SETQ BACK (%%REST TEMP)) (CL:SETF (%%REST TEMP) NIL)
   (CL:RETURN-FROM HELP-SORT-CONS-LIST
    (MERGE-CONS-LISTS (HELP-SORT-CONS-LIST LIST FRONTLENGTH PREDICATE)
     (HELP-SORT-CONS-LIST BACK (CL:- LENGTH FRONTLENGTH) PREDICATE)
     PREDICATE))))

;;; (DEFUN (MERGE-CONS-LISTS CONS) ...)

(CL:DEFUN MERGE-CONS-LISTS (LIST1 LIST2 PREDICATE)
  (CL:LET*
   ((CURSOR1 LIST1) (CURSOR2 LIST2) (RESULT NIL) (TAIL NIL) (TEMP NIL))
   (CL:LOOP
    (CL:WHEN (CL:EQ CURSOR1 NIL)
     (CL:WHEN (CL:EQ TAIL NIL) (CL:RETURN-FROM MERGE-CONS-LISTS CURSOR2))
     (CL:SETF (%%REST TAIL) CURSOR2) (CL:RETURN-FROM MERGE-CONS-LISTS RESULT))
    (CL:WHEN (CL:EQ CURSOR2 NIL)
     (CL:WHEN (CL:EQ TAIL NIL) (CL:RETURN-FROM MERGE-CONS-LISTS CURSOR1))
     (CL:SETF (%%REST TAIL) CURSOR1) (CL:RETURN-FROM MERGE-CONS-LISTS RESULT))
    (CL:COND
     ((CL:FUNCALL PREDICATE (%%VALUE CURSOR2) (%%VALUE CURSOR1))
      (CL:SETQ TEMP CURSOR2) (CL:SETQ CURSOR2 (%%REST CURSOR2))
      (CL:SETQ LIST2 CURSOR2))
     (CL:T (CL:SETQ TEMP CURSOR1) (CL:SETQ CURSOR1 (%%REST CURSOR1))
      (CL:SETQ LIST1 CURSOR1)))
    (CL:IF (CL:EQ TAIL NIL) (CL:SETQ RESULT TEMP)
     (CL:SETF (%%REST TAIL) TEMP))
    (CL:SETQ TAIL TEMP))))

;;; (DEFUN (GENERALIZED-SYMBOL-LESS-THAN? BOOLEAN) ...)

(CL:DEFUN GENERALIZED-SYMBOL-LESS-THAN? (X Y)
  (CL:RETURN-FROM GENERALIZED-SYMBOL-LESS-THAN?
   (STRING< (%SYMBOL-NAME X) (%SYMBOL-NAME Y))))

;;; (DEFUN (WRAPPED-INTEGER-LESS-THAN? BOOLEAN) ...)

(CL:DEFUN WRAPPED-INTEGER-LESS-THAN? (X Y)
  (CL:RETURN-FROM WRAPPED-INTEGER-LESS-THAN?
   (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y))))

;;; (DEFUN (WRAPPED-LONG-INTEGER-LESS-THAN? BOOLEAN) ...)

(CL:DEFUN WRAPPED-LONG-INTEGER-LESS-THAN? (X Y)
  (CL:RETURN-FROM WRAPPED-LONG-INTEGER-LESS-THAN?
   (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y))))

;;; (DEFUN (WRAPPED-FLOAT-LESS-THAN? BOOLEAN) ...)

(CL:DEFUN WRAPPED-FLOAT-LESS-THAN? (X Y)
  (CL:RETURN-FROM WRAPPED-FLOAT-LESS-THAN?
   (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y))))

;;; (DEFUN (WRAPPED-STRING-LESS-THAN? BOOLEAN) ...)

(CL:DEFUN WRAPPED-STRING-LESS-THAN? (X Y)
  (CL:RETURN-FROM WRAPPED-STRING-LESS-THAN?
   (STRING< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y))))

;;; (DEFUN (WRAPPED-MUTABLE-STRING-LESS-THAN? BOOLEAN) ...)

(CL:DEFUN WRAPPED-MUTABLE-STRING-LESS-THAN? (X Y)
  (CL:RETURN-FROM WRAPPED-MUTABLE-STRING-LESS-THAN?
   (STRING<
    (CL:LET ((S (%WRAPPER-VALUE X))) (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING S))
     (CL:THE CL:SIMPLE-STRING S))
    (CL:LET ((S (%WRAPPER-VALUE Y))) (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING S))
     (CL:THE CL:SIMPLE-STRING S)))))

;;; (DEFUN (NUMBER-LESS-THAN? BOOLEAN) ...)

(CL:DEFUN NUMBER-LESS-THAN? (X Y)
  "Generic number comparison that works with integers, longs and floats."
  (CL:LET* ((TEST-VALUE-003 (SAFE-PRIMARY-TYPE X)))
   (CL:COND
    ((SUBTYPE-OF-INTEGER? TEST-VALUE-003)
     (CL:PROGN
      (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE Y)))
       (CL:COND
        ((SUBTYPE-OF-FLOAT? TEST-VALUE-000)
         (CL:PROGN
          (CL:RETURN-FROM NUMBER-LESS-THAN?
           (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y)))))
        ((SUBTYPE-OF-LONG-INTEGER? TEST-VALUE-000)
         (CL:PROGN
          (CL:RETURN-FROM NUMBER-LESS-THAN?
           (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y)))))
        ((SUBTYPE-OF-INTEGER? TEST-VALUE-000)
         (CL:PROGN
          (CL:RETURN-FROM NUMBER-LESS-THAN?
           (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y)))))
        (CL:T
         (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
          (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" TEST-VALUE-000
           "' is not a valid case option")
          (CL:ERROR
           (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))))))
    ((SUBTYPE-OF-LONG-INTEGER? TEST-VALUE-003)
     (CL:PROGN
      (CL:LET* ((TEST-VALUE-001 (SAFE-PRIMARY-TYPE Y)))
       (CL:COND
        ((SUBTYPE-OF-FLOAT? TEST-VALUE-001)
         (CL:PROGN
          (CL:RETURN-FROM NUMBER-LESS-THAN?
           (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y)))))
        ((SUBTYPE-OF-LONG-INTEGER? TEST-VALUE-001)
         (CL:PROGN
          (CL:RETURN-FROM NUMBER-LESS-THAN?
           (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y)))))
        ((SUBTYPE-OF-INTEGER? TEST-VALUE-001)
         (CL:PROGN
          (CL:RETURN-FROM NUMBER-LESS-THAN?
           (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y)))))
        (CL:T
         (CL:LET* ((STREAM-001 (NEW-OUTPUT-STRING-STREAM)))
          (%%PRINT-STREAM (%NATIVE-STREAM STREAM-001) "`" TEST-VALUE-001
           "' is not a valid case option")
          (CL:ERROR
           (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-001)))))))))
    ((SUBTYPE-OF-FLOAT? TEST-VALUE-003)
     (CL:PROGN
      (CL:LET* ((TEST-VALUE-002 (SAFE-PRIMARY-TYPE Y)))
       (CL:COND
        ((SUBTYPE-OF-FLOAT? TEST-VALUE-002)
         (CL:PROGN
          (CL:RETURN-FROM NUMBER-LESS-THAN?
           (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y)))))
        ((SUBTYPE-OF-LONG-INTEGER? TEST-VALUE-002)
         (CL:PROGN
          (CL:RETURN-FROM NUMBER-LESS-THAN?
           (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y)))))
        ((SUBTYPE-OF-INTEGER? TEST-VALUE-002)
         (CL:PROGN
          (CL:RETURN-FROM NUMBER-LESS-THAN?
           (< (%WRAPPER-VALUE X) (%WRAPPER-VALUE Y)))))
        (CL:T
         (CL:LET* ((STREAM-002 (NEW-OUTPUT-STRING-STREAM)))
          (%%PRINT-STREAM (%NATIVE-STREAM STREAM-002) "`" TEST-VALUE-002
           "' is not a valid case option")
          (CL:ERROR
           (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-002)))))))))
    (CL:T
     (CL:LET* ((STREAM-003 (NEW-OUTPUT-STRING-STREAM)))
      (%%PRINT-STREAM (%NATIVE-STREAM STREAM-003) "`" TEST-VALUE-003
       "' is not a valid case option")
      (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-003))))))))

;;; (DEFUN (CHOOSE-SORT-PREDICATE FUNCTION-CODE) ...)

(CL:DEFUN CHOOSE-SORT-PREDICATE (FIRSTELEMENT)
  (CL:WHEN (CL:EQ FIRSTELEMENT NULL)
   (CL:RETURN-FROM CHOOSE-SORT-PREDICATE NULL))
  (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE FIRSTELEMENT)))
   (CL:COND
    ((SUBTYPE-OF? TEST-VALUE-000 SGT-CONSES-STELLA-GENERALIZED-SYMBOL)
     (CL:PROGN
      (CL:RETURN-FROM CHOOSE-SORT-PREDICATE
       (CL:FUNCTION GENERALIZED-SYMBOL-LESS-THAN?))))
    ((SUBTYPE-OF-INTEGER? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CHOOSE-SORT-PREDICATE
       (CL:FUNCTION WRAPPED-INTEGER-LESS-THAN?))))
    ((SUBTYPE-OF-LONG-INTEGER? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CHOOSE-SORT-PREDICATE
       (CL:FUNCTION WRAPPED-LONG-INTEGER-LESS-THAN?))))
    ((SUBTYPE-OF-FLOAT? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CHOOSE-SORT-PREDICATE
       (CL:FUNCTION WRAPPED-FLOAT-LESS-THAN?))))
    ((SUBTYPE-OF-STRING? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CHOOSE-SORT-PREDICATE
       (CL:FUNCTION WRAPPED-STRING-LESS-THAN?))))
    ((SUBTYPE-OF? TEST-VALUE-000 SGT-CONSES-STELLA-MUTABLE-STRING-WRAPPER)
     (CL:PROGN
      (CL:RETURN-FROM CHOOSE-SORT-PREDICATE
       (CL:FUNCTION WRAPPED-MUTABLE-STRING-LESS-THAN?))))
    (CL:T
     (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
      (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
       "choose-sort-predicate: Don't know how to sort `"
       (PRIMARY-TYPE FIRSTELEMENT) "'s")
      (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))))

;;; (DEFSPECIAL *SORT-TUPLE-COMPARE-PREDICATE* ...)

(CL:DEFVAR *SORT-TUPLE-COMPARE-PREDICATE* NULL)

;;; (DEFSPECIAL *SORT-TUPLE-COMPARE-INDEX* ...)

(CL:DEFVAR *SORT-TUPLE-COMPARE-INDEX* 0)
(CL:DECLAIM (CL:TYPE CL:FIXNUM *SORT-TUPLE-COMPARE-INDEX*))

;;; (DEFUN (SORT-TUPLE-COMPARE? BOOLEAN) ...)

(CL:DEFUN SORT-TUPLE-COMPARE? (X Y)
  (CL:LET*
   ((N *SORT-TUPLE-COMPARE-INDEX*) (PRED *SORT-TUPLE-COMPARE-PREDICATE*))
   (CL:DECLARE (CL:TYPE CL:FIXNUM N))
   (CL:RETURN-FROM SORT-TUPLE-COMPARE? (CL:FUNCALL PRED (NTH X N) (NTH Y N)))))

;;; (DEFMETHOD (SORT-TUPLES (CONS OF (LIKE (ANY-VALUE SELF)))) ...)

(%%DEFCONSMETHOD SORT-TUPLES ((SELF CL:CONS) N PREDICATE)
  "Just like `sort' but assumes each element of `self' is a tuple (a cons)
whose `n'-th element (0-based) will be used for comparison."
  (CL:DECLARE (CL:TYPE CL:FIXNUM N))
  #+MCL
  (CL:CHECK-TYPE N CL:FIXNUM)
  (CL:WHEN (CL:AND (CL:EQ PREDICATE NULL) (CL:NOT (CL:EQ SELF NIL)))
   (CL:SETQ PREDICATE (CHOOSE-SORT-PREDICATE (NTH (%%VALUE SELF) N))))
  (CL:LET*
   ((*SORT-TUPLE-COMPARE-PREDICATE* PREDICATE) (*SORT-TUPLE-COMPARE-INDEX* N))
   (CL:DECLARE
    (CL:SPECIAL *SORT-TUPLE-COMPARE-PREDICATE* *SORT-TUPLE-COMPARE-INDEX*))
   (CL:DECLARE (CL:TYPE CL:FIXNUM *SORT-TUPLE-COMPARE-INDEX*))
   (CL:RETURN-FROM SORT-TUPLES
    (HELP-SORT-CONS-LIST SELF (LENGTH SELF)
     (CL:FUNCTION SORT-TUPLE-COMPARE?)))))

;;; (DEFUN (SEARCH-CONS-TREE? BOOLEAN) ...)

(CL:DEFUN SEARCH-CONS-TREE? (TREE VALUE)
  "Return `true' iff the value `value' is embedded within
the cons tree `tree'.  Uses an `eql?' test."
  (CL:COND
   ((CL:EQ (SAFE-PRIMARY-TYPE TREE) SGT-CONSES-STELLA-CONS)
    (CL:PROGN
     (CL:IF (CL:EQ TREE NIL)
      (CL:RETURN-FROM SEARCH-CONS-TREE? (CL:EQ VALUE NIL))
      (CL:RETURN-FROM SEARCH-CONS-TREE?
       (CL:OR (SEARCH-CONS-TREE? (%%VALUE TREE) VALUE)
        (SEARCH-CONS-TREE? (%%REST TREE) VALUE))))))
   (CL:T (CL:RETURN-FROM SEARCH-CONS-TREE? (EQL? TREE VALUE)))))

;;; (DEFUN (SEARCH-CONS-TREE-WITH-FILTER? BOOLEAN) ...)

(CL:DEFUN SEARCH-CONS-TREE-WITH-FILTER? (TREE VALUE FILTER)
  "Return `true' iff the value `value' is embedded within
the cons tree `tree'.  Uses an `eql?' test.  Does not descend into any
cons whose first element matches an element of `filter'."
  (CL:COND
   ((CL:EQ (SAFE-PRIMARY-TYPE TREE) SGT-CONSES-STELLA-CONS)
    (CL:PROGN
     (CL:COND
      ((CL:EQ TREE NIL)
       (CL:RETURN-FROM SEARCH-CONS-TREE-WITH-FILTER? (CL:EQ VALUE NIL)))
      ((MEMBER? FILTER (%%VALUE TREE))
       (CL:RETURN-FROM SEARCH-CONS-TREE-WITH-FILTER? CL:NIL))
      (CL:T
       (CL:LET* ((FOUND?-000 CL:NIL))
        (CL:LET* ((ITEM NULL) (ITER-000 TREE))
         (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
          (CL:SETQ ITEM (%%VALUE ITER-000))
          (CL:WHEN (SEARCH-CONS-TREE-WITH-FILTER? ITEM VALUE FILTER)
           (CL:SETQ FOUND?-000 CL:T) (CL:RETURN))
          (CL:SETQ ITER-000 (%%REST ITER-000))))
        (CL:LET* ((VALUE-000 FOUND?-000))
         (CL:RETURN-FROM SEARCH-CONS-TREE-WITH-FILTER? VALUE-000)))))))
   (CL:T (CL:RETURN-FROM SEARCH-CONS-TREE-WITH-FILTER? (EQL? TREE VALUE)))))

;;; (DEFUN (COPY-CONS-TREE (LIKE SELF)) ...)

(CL:DEFUN COPY-CONS-TREE (SELF)
  "Return a copy of the cons tree `self'."
  (CL:COND
   ((CL:EQ (SAFE-PRIMARY-TYPE SELF) SGT-CONSES-STELLA-CONS)
    (CL:PROGN
     (CL:IF (CL:EQ SELF NIL) (CL:RETURN-FROM COPY-CONS-TREE NIL)
      (CL:RETURN-FROM COPY-CONS-TREE
       (CONS (COPY-CONS-TREE (%%VALUE SELF))
        (COPY-CONS-TREE (%%REST SELF)))))))
   (CL:T (CL:RETURN-FROM COPY-CONS-TREE SELF))))

;;; (DEFUN (EQUAL-CONS-TREES? BOOLEAN) ...)

(CL:DEFUN EQUAL-CONS-TREES? (TREE1 TREE2)
  "Return `true' iff the cons trees `tree1' and `tree2' are
structurally equivalent.  Uses an `eql?' test."
  (CL:IF (EQL? TREE1 TREE2) (CL:RETURN-FROM EQUAL-CONS-TREES? CL:T)
   (CL:COND
    ((CL:EQ (SAFE-PRIMARY-TYPE TREE1) SGT-CONSES-STELLA-CONS)
     (CL:PROGN
      (CL:COND
       ((CL:EQ (SAFE-PRIMARY-TYPE TREE2) SGT-CONSES-STELLA-CONS)
        (CL:PROGN
         (CL:RETURN-FROM EQUAL-CONS-TREES?
          (CL:AND (EQUAL-CONS-TREES? (%%VALUE TREE1) (%%VALUE TREE2))
           (EQUAL-CONS-TREES? (%%REST TREE1) (%%REST TREE2))))))
       (CL:T (CL:RETURN-FROM EQUAL-CONS-TREES? CL:NIL)))))
    (CL:T (CL:RETURN-FROM EQUAL-CONS-TREES? CL:NIL)))))

;;; (DEFMETHOD (OBJECT-EQUAL? BOOLEAN) ...)

(%%DEFCONSMETHOD OBJECT-EQUAL? ((TREE1 CL:CONS) TREE2)
  "Return `true' iff the cons trees `tree1' and `tree2' are
structurally equivalent.  Uses `equal?' to test equality of subtrees."
  (CL:COND
   ((CL:EQ (SAFE-PRIMARY-TYPE TREE2) SGT-CONSES-STELLA-CONS)
    (CL:PROGN
     (CL:LOOP WHILE (CL:NOT (CL:EQ TREE1 NIL)) DO
      (CL:WHEN (CL:NOT (EQUAL? (%%VALUE TREE1) (%%VALUE TREE2)))
       (CL:RETURN-FROM OBJECT-EQUAL? CL:NIL))
      (CL:SETQ TREE1 (%%REST TREE1)) (CL:SETQ TREE2 (%%REST TREE2)))
     (CL:RETURN-FROM OBJECT-EQUAL? (CL:EQ TREE2 NIL))))
   (CL:T (CL:RETURN-FROM OBJECT-EQUAL? CL:NIL))))

;;; (DEFMETHOD (EQUAL-HASH-CODE INTEGER) ...)

(%%DEFCONSMETHOD EQUAL-HASH-CODE ((SELF CL:CONS))
  "Return an `equal?' hash code for `self'.  Note that this
is O(N) in the number of elements of `self'."
  (CL:LET* ((CODE 18589447)) (CL:DECLARE (CL:TYPE CL:FIXNUM CODE))
   (CL:LOOP (CL:WHEN (CL:EQ SELF NIL) (CL:RETURN))
    (CL:SETQ CODE
     (CL:THE CL:FIXNUM
      (CL:LOGXOR CODE
       (CL:THE CL:FIXNUM (SAFE-EQUAL-HASH-CODE (%%VALUE SELF))))))
    (CL:SETQ SELF (%%REST SELF))
    (CL:SETQ CODE
     (CL:IF (CL:= (CL:THE CL:FIXNUM (CL:LOGAND CODE 1)) 0)
      (CL:LET ((ARG CODE)) (CL:DECLARE (CL:TYPE CL:FIXNUM ARG))
       (CL:THE CL:FIXNUM
        (CL:LOGAND (CL:THE CL:FIXNUM (CL:ASH ARG -1))
         *INTEGER-UNSIGNED-BITS-MASK*)))
      (CL:THE CL:FIXNUM
       (CL:LOGIOR
        (CL:THE CL:FIXNUM
         (CL:LET ((ARG CODE) (COUNT 1))
          (CL:DECLARE (CL:TYPE CL:FIXNUM ARG COUNT))
          (CL:THE CL:FIXNUM (CL:ASH ARG (CL:THE CL:FIXNUM (CL:- COUNT))))))
        *INTEGER-MSB-MASK*)))))
   (CL:RETURN-FROM EQUAL-HASH-CODE CODE)))

;;; (DEFUN (SUBSTITUTE-CONS-TREE OBJECT) ...)

(CL:DEFUN SUBSTITUTE-CONS-TREE (TREE NEWVALUE OLDVALUE)
  "Destructively replace each appearance of `oldValue' by
`newValue' in the cons tree `tree'.  Return the tree.  Uses an `eql?' test."
  (CL:COND
   ((CL:EQ (SAFE-PRIMARY-TYPE TREE) SGT-CONSES-STELLA-CONS)
    (CL:PROGN
     (CL:WHEN (CL:NOT (CL:EQ TREE NIL))
      (CL:IF (EQL? (%%VALUE TREE) OLDVALUE) (CL:SETF (%%VALUE TREE) NEWVALUE)
       (SUBSTITUTE-CONS-TREE (%%VALUE TREE) NEWVALUE OLDVALUE))
      (SUBSTITUTE-CONS-TREE (%%REST TREE) NEWVALUE OLDVALUE))))
   (CL:T))
  (CL:RETURN-FROM SUBSTITUTE-CONS-TREE TREE))

;;; (DEFUN (CONS-TREE-NTH OBJECT) ...)

(CL:DEFUN CONS-TREE-NTH (TREE CL:&REST INDEX)
  "Access an arbitrary element of `tree' identified by a path
specified as a list of `index' values.  The first `index' specifies the
`index'-th element of `tree', the second `index' the `index'-th subelement
of that element, etc.  Example:
	 
  (cons-tree-nth (quote (a (b (c d e) f) g)) 1 1 2) => e
	
"
  (CL:LET* ((RESULT TREE))
   (CL:LET* ((I NULL-INTEGER) (ITER-000 INDEX))
    (CL:DECLARE (CL:TYPE CL:FIXNUM I))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ I (CL:POP ITER-000))
     (CL:COND
      ((CL:EQ (SAFE-PRIMARY-TYPE RESULT) SGT-CONSES-STELLA-CONS)
       (CL:PROGN (CL:SETQ TREE RESULT)))
      (CL:T (CL:RETURN-FROM CONS-TREE-NTH NULL)))
     (CL:SETQ RESULT (NTH TREE I))))
   (CL:RETURN-FROM CONS-TREE-NTH RESULT)))

;;; (DEFUN (CONS-TREE-NTH-REST CONS) ...)

(CL:DEFUN CONS-TREE-NTH-REST (TREE CL:&REST INDEX)
  "Access an arbitrary sublist of `tree' identified by a path
specified as a list of `index' values.  The first `index' specifies the
`index'-th element of `tree', the second `index' the `index'-th subelement
of that element, ..., the last index specifies the `nth-rest' of the previous
element (different from `cons-tree-nth').  Example:
	 
  (cons-tree-nth-rest (quote (a (b (c d e) f) g)) 1 1 1) => (d e)
	
"
  (CL:LET* ((RESULT TREE) (NOFINDICES (CL:LENGTH INDEX)))
   (CL:DECLARE (CL:TYPE CL:FIXNUM NOFINDICES))
   (CL:LET* ((I NULL-INTEGER) (ITER-000 INDEX) (J NULL-INTEGER) (ITER-001 1))
    (CL:DECLARE (CL:TYPE CL:FIXNUM I J ITER-001))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ I (CL:POP ITER-000))
     (CL:SETQ J ITER-001)
     (CL:COND
      ((CL:EQ (SAFE-PRIMARY-TYPE RESULT) SGT-CONSES-STELLA-CONS)
       (CL:PROGN (CL:SETQ TREE RESULT)))
      (CL:T (CL:RETURN-FROM CONS-TREE-NTH-REST NULL)))
     (CL:IF (CL:= J NOFINDICES) (CL:SETQ RESULT (NTH-REST TREE I))
      (CL:SETQ RESULT (NTH TREE I)))
     (CL:SETQ ITER-001 (CL:1+ ITER-001))))
   (CL:RETURN-FROM CONS-TREE-NTH-REST RESULT)))

;;; (DEFUN (MATCH-CONS-TREE KEY-VALUE-LIST) ...)

(CL:DEFUN MATCH-CONS-TREE (TREE PATTERN BINDINGS)
  "Match `pattern' against `tree' and return a list of
variable bindings if they match, or NULL otherwise.  `bindings' can
be NULL or an initial list of bindings to consider.  Pattern variables
use KIF syntax, i.e., they need to start with a `?' character.  A
single question mark is interpreted as the anonymous variable. Example:
	 
  (match-cons-tree (quote (a (b (a d) e) (a d) f g))
                   (quote (a (?x ?y ?) ?y ? g))
                   NULL)
  => |kv|(<?Y,(A D)> <?X,B>)
	
Variables can't be quoted but quoting can effectively be achieved by
inserting to-be-quoted variables bound to themselves into `bindings'."
  (CL:WHEN (CL:EQ BINDINGS NULL) (CL:SETQ BINDINGS (NEW-KEY-VALUE-LIST)))
  (CL:WHEN (CL:EQ PATTERN SYM-CONSES-STELLA-?)
   (CL:RETURN-FROM MATCH-CONS-TREE BINDINGS))
  (CL:LET* ((TEST-VALUE-001 (SAFE-PRIMARY-TYPE PATTERN)))
   (CL:COND
    ((SUBTYPE-OF-SYMBOL? TEST-VALUE-001)
     (CL:PROGN
      (CL:IF
       (CL:EQL
        (CL:LET ((SELF (%SYMBOL-NAME PATTERN)) (POSITION 0))
         (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF)
          (CL:TYPE CL:FIXNUM POSITION))
         (CL:SCHAR (CL:THE CL:SIMPLE-STRING SELF)
          (CL:THE CL:FIXNUM POSITION)))
        #\?)
       (CL:LET* ((VALUE (LOOKUP BINDINGS PATTERN)))
        (CL:COND
         ((CL:EQ VALUE NULL) (INSERT-AT BINDINGS PATTERN TREE)
          (CL:RETURN-FROM MATCH-CONS-TREE BINDINGS))
         ((EQUAL? VALUE TREE) (CL:RETURN-FROM MATCH-CONS-TREE BINDINGS))))
       (CL:WHEN (CL:EQ TREE PATTERN)
        (CL:RETURN-FROM MATCH-CONS-TREE BINDINGS)))))
    ((CL:EQ TEST-VALUE-001 SGT-CONSES-STELLA-CONS)
     (CL:PROGN
      (CL:COND
       ((CL:EQ (SAFE-PRIMARY-TYPE TREE) SGT-CONSES-STELLA-CONS)
        (CL:PROGN
         (CL:LET* ((TEST-VALUE-000 CL:NIL))
          (CL:SETQ TEST-VALUE-000 (CL:= (LENGTH TREE) (LENGTH PATTERN)))
          (CL:WHEN TEST-VALUE-000
           (CL:LET* ((ALWAYS?-000 CL:T))
            (CL:LET*
             ((ELT NULL) (ITER-000 TREE) (PAT NULL) (ITER-001 PATTERN))
             (CL:LOOP WHILE
              (CL:AND (CL:NOT (CL:EQ ITER-000 NIL))
               (CL:NOT (CL:EQ ITER-001 NIL)))
              DO (CL:SETQ ELT (%%VALUE ITER-000))
              (CL:SETQ PAT (%%VALUE ITER-001))
              (CL:WHEN (CL:EQ (MATCH-CONS-TREE ELT PAT BINDINGS) NULL)
               (CL:SETQ ALWAYS?-000 CL:NIL) (CL:RETURN))
              (CL:SETQ ITER-000 (%%REST ITER-000))
              (CL:SETQ ITER-001 (%%REST ITER-001))))
            (CL:SETQ TEST-VALUE-000 ALWAYS?-000)))
          (CL:WHEN TEST-VALUE-000
           (CL:RETURN-FROM MATCH-CONS-TREE BINDINGS)))))
       (CL:T))))
    (CL:T
     (CL:WHEN (EQL? TREE PATTERN) (CL:RETURN-FROM MATCH-CONS-TREE BINDINGS)))))
  (CL:RETURN-FROM MATCH-CONS-TREE NULL))

;;; (DEFUN (CONS-TREE-MATCH? BOOLEAN) ...)

(CL:DEFUN CONS-TREE-MATCH? (TREE PATTERN)
  "Predicate version of `match-cons-tree' (which see)."
  (CL:RETURN-FROM CONS-TREE-MATCH?
   (CL:NOT (CL:EQ (MATCH-CONS-TREE TREE PATTERN NULL) NULL))))

;;; (DEFSPECIAL *PRINTPRETTY?* ...)

(CL:DEFVAR *PRINTPRETTY?* CL:T
  "If `true' conses will be pretty printed.")

;;; (DEFSPECIAL *PRINTREADABLY?* ...)

(CL:DEFVAR *PRINTREADABLY?* CL:NIL
  "If `true' conses will be printed as readable Stella code.")

;;; (DEFSPECIAL *PRINTLENGTH* ...)

(CL:DEFVAR *PRINTLENGTH* NULL-INTEGER
  "If non-NULL list-like data structures will print at most
that many elements.")
(CL:DECLAIM (CL:TYPE CL:FIXNUM *PRINTLENGTH*))

;;; (DEFGLOBAL ELIPSIS ...)

(CL:DEFVAR ELIPSIS NULL
  "Generates an elipsis '...' when found in a
pretty-printed parse tree.")

;;; (DEFUN PRINT-CONS ...)

(CL:DEFUN PRINT-CONS (TREE STREAM LPAREN RPAREN)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING LPAREN RPAREN))
  #+MCL
  (CL:CHECK-TYPE LPAREN CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE RPAREN CL:SIMPLE-STRING)
  (CL:WHEN *PRINTREADABLY?* (CL:SETQ LPAREN "(") (CL:SETQ RPAREN ")"))
  (CL:WHEN *PRINTPRETTY?* (PPRINT-CONS TREE STREAM LPAREN RPAREN)
   (CL:RETURN-FROM PRINT-CONS))
  (%%PRINT-STREAM STREAM LPAREN)
  (CL:WHEN (CL:NOT (CL:EQ TREE NIL)) (%%PRINT-STREAM STREAM (%%VALUE TREE))
   (CL:SETQ TREE (%%REST TREE))
   (CL:IF (CL:NOT (CL:= *PRINTLENGTH* NULL-INTEGER))
    (CL:LET* ((I 1)) (CL:DECLARE (CL:TYPE CL:FIXNUM I))
     (CL:LET* ((ELEMENT NULL) (ITER-000 TREE))
      (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
       (CL:SETQ ELEMENT (%%VALUE ITER-000))
       (%%PRINT-STREAM STREAM " " ELEMENT) (CL:SETQ TREE (%%REST TREE))
       (CL:SETQ I (CL:1+ I)) (CL:WHEN (CL:>= I *PRINTLENGTH*) (CL:RETURN))
       (CL:SETQ ITER-000 (%%REST ITER-000))))
     (CL:WHEN (CL:NOT (CL:EQ TREE NIL)) (%%PRINT-STREAM STREAM " ...")))
    (CL:LET* ((ELEMENT NULL) (ITER-001 TREE))
     (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
      (CL:SETQ ELEMENT (%%VALUE ITER-001)) (%%PRINT-STREAM STREAM " " ELEMENT)
      (CL:SETQ ITER-001 (%%REST ITER-001))))))
  (%%PRINT-STREAM STREAM RPAREN)
  :VOID)

;;; (DEFUN PPRINT-CONS ...)

(CL:DEFUN PPRINT-CONS (TREE STREAM LPAREN RPAREN)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING LPAREN RPAREN))
  #+MCL
  (CL:CHECK-TYPE LPAREN CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE RPAREN CL:SIMPLE-STRING)
  #-lispworks
       (CL:let ((CL:*print-pretty* CL:t)
                (CL:*print-length* (lispify *printLength*)))
         (CL:write-string lparen stream)
         (CL:pprint-linear stream (cons-list-to-lisp-list tree) CL-NIL)
         (CL:write-string rparen stream))
       #+lispworks
        (CL:let ((*printPretty?* FALSE))
          (print-cons tree stream lparen rparen))
  :VOID)

;;; (DEFSPECIAL *PRINTPRETTYCODE?* ...)

(CL:DEFVAR *PRINTPRETTYCODE?* CL:T
  "When `true' pretty-print Stella and translated code.
Since (Lisp) pretty-printing is somewhat slow, turning this off speeds up
file translation, but it also makes translated output very unreadable.")

;;; (DEFUN PRINT-STELLA-CODE ...)

(CL:DEFUN PRINT-STELLA-CODE (TREE STREAM)
  (CL:LET* ((*PRINTPRETTY?* *PRINTPRETTYCODE?*) (*PRINTREADABLY?* CL:T))
   (CL:DECLARE (CL:SPECIAL *PRINTPRETTY?* *PRINTREADABLY?*))
   (%%PRINT-STREAM STREAM TREE EOL))
  :VOID)

;;; (DEFUN PRINT-STELLA-DEFINITION ...)

(CL:DEFUN PRINT-STELLA-DEFINITION (TREE STREAM)
  (CL:LET* ((*PRINTPRETTY?* *PRINTPRETTYCODE?*) (*PRINTREADABLY?* CL:T))
   (CL:DECLARE (CL:SPECIAL *PRINTPRETTY?* *PRINTREADABLY?*))
   (CL:COND
    ((CL:EQ (SAFE-PRIMARY-TYPE TREE) SGT-CONSES-STELLA-CONS)
     (CL:PROGN
      (CL:COND
       ((CL:>= (LENGTH TREE) 3) (CL:SETQ *PRINTPRETTY?* CL:NIL)
        (%%PRINT-STREAM STREAM "(" (%%VALUE TREE) " " (%%VALUE (%%REST TREE))
         " " (%%VALUE (%%REST (%%REST TREE))))
        (CL:SETQ *PRINTPRETTY?* *PRINTPRETTYCODE?*)
        (CL:LET* ((FORM NULL) (ITER-000 (NTH-REST TREE 3)))
         (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
          (CL:SETQ FORM (%%VALUE ITER-000))
          (%%PRINT-STREAM STREAM EOL "  " FORM)
          (CL:SETQ ITER-000 (%%REST ITER-000))))
        (%%PRINT-STREAM STREAM ")"))
       (CL:T (%%PRINT-STREAM STREAM TREE)))))
    (CL:T (%%PRINT-STREAM STREAM TREE)))
   (%%PRINT-STREAM STREAM EOL))
  :VOID)

;;; (DEFUN (TREE-SIZE INTEGER) ...)

(CL:DECLAIM (CL:FTYPE (CL:FUNCTION (CL:T) CL:FIXNUM) TREE-SIZE))
(CL:DEFUN TREE-SIZE (SELF)
  (CL:COND
   ((CL:EQ (SAFE-PRIMARY-TYPE SELF) SGT-CONSES-STELLA-CONS)
    (CL:PROGN
     (CL:IF (CL:EQ SELF NIL) (CL:RETURN-FROM TREE-SIZE 0)
      (CL:RETURN-FROM TREE-SIZE
       (CL:1+ (CL:+ (TREE-SIZE (%%VALUE SELF)) (TREE-SIZE (%%REST SELF))))))))
   (CL:T (CL:RETURN-FROM TREE-SIZE 0))))

;;; (DEFSPECIAL *DEPTHEXCEEDED?* ...)

(CL:DEFVAR *DEPTHEXCEEDED?* CL:NIL)

;;; (DEFGLOBAL *DEPTHCUTOFF* ...)

(CL:DEFVAR *DEPTHCUTOFF* 33)
(CL:DECLAIM (CL:TYPE CL:FIXNUM *DEPTHCUTOFF*))

;;; (DEFUN (SAFELY-COMPUTE-TREE-SIZE INTEGER) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T CL:FIXNUM CL:FIXNUM) CL:FIXNUM)
  SAFELY-COMPUTE-TREE-SIZE))
(CL:DEFUN SAFELY-COMPUTE-TREE-SIZE (TREE DEPTHCOUNT CUTOFF)
  (CL:DECLARE (CL:TYPE CL:FIXNUM DEPTHCOUNT CUTOFF))
  #+MCL
  (CL:CHECK-TYPE DEPTHCOUNT CL:FIXNUM)
  #+MCL
  (CL:CHECK-TYPE CUTOFF CL:FIXNUM)
  (CL:LET* ((COUNT 1) (VALUE NULL)) (CL:DECLARE (CL:TYPE CL:FIXNUM COUNT))
   (CL:WHEN (CL:> DEPTHCOUNT *DEPTHCUTOFF*) (CL:SETQ *DEPTHEXCEEDED?* CL:T)
    (CL:RETURN-FROM SAFELY-COMPUTE-TREE-SIZE 1))
   (CL:LOOP (CL:SETQ VALUE (%%VALUE TREE))
    (CL:WHEN (CONS? VALUE)
     (CL:SETQ COUNT
      (CL:+ COUNT
       (SAFELY-COMPUTE-TREE-SIZE (%%VALUE TREE) (CL:1+ DEPTHCOUNT) CUTOFF))))
    (CL:WHEN
     (CL:OR (CL:EQ (%%REST TREE) NULL) (CL:EQ (%%REST TREE) NIL)
      (CL:> COUNT CUTOFF))
     (CL:RETURN-FROM SAFELY-COMPUTE-TREE-SIZE COUNT))
    (CL:SETQ TREE (%%REST TREE)))))

;;; (DEFUN (SAFE-TREE-SIZE INTEGER STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) (CL:VALUES CL:FIXNUM CL:SIMPLE-STRING))
  SAFE-TREE-SIZE))
(CL:DEFUN SAFE-TREE-SIZE (TREE)
  (CL:LET* ((*DEPTHEXCEEDED?* CL:NIL))
   (CL:DECLARE (CL:SPECIAL *DEPTHEXCEEDED?*))
   (CL:LET* ((CUTOFF 99) (SIZE (SAFELY-COMPUTE-TREE-SIZE TREE 0 CUTOFF)))
    (CL:DECLARE (CL:TYPE CL:FIXNUM CUTOFF SIZE))
    (CL:RETURN-FROM SAFE-TREE-SIZE
     (CL:VALUES SIZE
      (CL:IF (CL:OR *DEPTHEXCEEDED?* (CL:>= SIZE CUTOFF)) "CIRCULAR" "OK"))))))

(CL:DEFUN HELP-STARTUP-CONSES1 ()
  (CL:PROGN
   (CL:SETQ SGT-CONSES-STELLA-GENERALIZED-SYMBOL
    (INTERN-RIGID-SYMBOL-WRT-MODULE "GENERALIZED-SYMBOL" NULL 1))
   (CL:SETQ SGT-CONSES-STELLA-MUTABLE-STRING-WRAPPER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "MUTABLE-STRING-WRAPPER" NULL 1))
   (CL:SETQ SGT-CONSES-STELLA-CONS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "CONS" NULL 1))
   (CL:SETQ SYM-CONSES-STELLA-? (INTERN-RIGID-SYMBOL-WRT-MODULE "?" NULL 0))
   (CL:SETQ SYM-CONSES-STELLA-...
    (INTERN-RIGID-SYMBOL-WRT-MODULE "..." NULL 0))
   (CL:SETQ SYM-CONSES-STELLA-STARTUP-CONSES
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-CONSES" NULL 0))
   (CL:SETQ SYM-CONSES-STELLA-METHOD-STARTUP-CLASSNAME
    (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL 0)))
  :VOID)

(CL:DEFUN HELP-STARTUP-CONSES2 ()
  (CL:PROGN
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF CONS)) :DOCUMENTATION \"Return `true' iff `self' equals `nil'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (EQ? SELF NIL)))"
    (CL:FUNCTION EMPTY?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (NON-EMPTY? BOOLEAN) ((SELF CONS)) :DOCUMENTATION \"Return `true' iff `self' is not equal to `nil'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (NOT (EQ? SELF NIL))))"
    (CL:FUNCTION NON-EMPTY?) NULL)
   (DEFINE-FUNCTION-OBJECT "NIL?"
    "(DEFUN (NIL? BOOLEAN) ((X OBJECT)) :DOCUMENTATION \"Return `true' iff `x' equals `nil'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (EQ? X NIL)))"
    (CL:FUNCTION NIL?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (LENGTH INTEGER) ((SELF CONS)) :DOCUMENTATION \"Return the length of the CONS list `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION LENGTH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (POSITION INTEGER) ((SELF CONS) (OBJECT OBJECT) (START INTEGER)) :DOCUMENTATION \"Return the position of `object' within the cons-list
`self' (counting from zero); or return `null' if `object' does not occur within 
`self' (uses an `eql?' test).  If `start' was supplied as non-`null', only 
consider the sublist starting at `start', however, the returned position 
will always be relative to the entire list.\" :PUBLIC? TRUE)"
    (CL:FUNCTION POSITION) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (LAST-POSITION INTEGER) ((SELF CONS) (OBJECT OBJECT) (END INTEGER)) :DOCUMENTATION \"Return the position of `object' within the cons-list
`self' (counting from zero); or return `null' if `object' does not occur within 
`self' (uses an `eql?' test).  If `start' was supplied as non-`null', only 
consider the sublist ending at `end', however, the returned position 
will always be relative to the entire list.\" :PUBLIC? TRUE)"
    (CL:FUNCTION LAST-POSITION) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF CONS) (OBJECT OBJECT)) :DOCUMENTATION \"Return `true' iff `object' is a member of the cons list
`self' (uses an `eql?' test).\" :PUBLIC? TRUE)" (CL:FUNCTION MEMBER?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (MEMB? BOOLEAN) ((SELF CONS) (OBJECT OBJECT)) :DOCUMENTATION \"Return `true' iff `object' is a member of the cons list
`self' (uses an `eq?' test).\" :PUBLIC? TRUE)" (CL:FUNCTION MEMB?) NULL)
   (DEFINE-FUNCTION-OBJECT "CONS"
    "(DEFUN (CONS CONS) ((VALUE OBJECT) (REST CONS)) :DOCUMENTATION \"Return a cons record that points to `value' and `rest'.\" :PUBLIC? TRUE :CONSTRUCTOR? TRUE)"
    (CL:FUNCTION CONS) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REMOVE (LIKE SELF)) ((SELF CONS) (VALUE OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Destructively remove all entries in the cons list `self' that
match `value'.  Unless the remaining list is `nil', insure that the cons that
heads the list is unchanged.\")" (CL:FUNCTION REMOVE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REMOVE-IF (LIKE SELF)) ((SELF CONS) (TEST? FUNCTION-CODE)) :PUBLIC? TRUE :DOCUMENTATION \"Destructively removes all members of the cons list
`self' for which `test?' evaluates to `true'.  `test' takes a single 
argument of type OBJECT and returns `true' or `false'.  Returns a cons list.
In case the first element is removed, the return result should be
assigned to a variable.\")" (CL:FUNCTION REMOVE-IF) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REMOVE-DUPLICATES (LIKE SELF)) ((SELF CONS)) :PUBLIC? TRUE :DOCUMENTATION \"Destructively remove duplicates from `self' and return the
result.  Removes all but the first occurrence of items in the list.
Preserves the original order of the remaining members.  Runs in linear time.\")"
    (CL:FUNCTION REMOVE-DUPLICATES) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REMOVE-DUPLICATES-EQUAL (LIKE SELF)) ((SELF CONS)) :DOCUMENTATION \"`remove-duplicates' (which see) using an `equal?' test.\" :PUBLIC? TRUE)"
    (CL:FUNCTION REMOVE-DUPLICATES-EQUAL) NULL)
   (DEFINE-FUNCTION-OBJECT "REMOVE-DUPLICATES-FROM-LONG-LIST"
    "(DEFUN (REMOVE-DUPLICATES-FROM-LONG-LIST (LIKE SELF)) ((SELF CONS) (EQUALTEST? BOOLEAN)))"
    (CL:FUNCTION REMOVE-DUPLICATES-FROM-LONG-LIST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (CONCATENATE CONS) ((LIST1 CONS) (LIST2 CONS) |&REST| (OTHERLISTS CONS)) :PUBLIC? TRUE :DOCUMENTATION \"Return a cons list consisting of the concatenation of 
`list1', `list2', and `otherLists'.  The operation is destructive wrt all
but the last list argument which is left intact.  The two mandatory
parameters allow us to optimize the common binary case by not relying on
the somewhat less efficient variable arguments mechanism.\")"
    (CL:FUNCTION CONCATENATE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (PREPEND CONS) ((SELF CONS) (LIST1 CONS)) :DOCUMENTATION \"Return a cons list consisting of the concatenation of
`list1' and `self'.  A copy of `list1' is prepended to `self'.  This
operation results in structure sharing of `self'; to avoid this, `self'
should not be pointed to by anything other than the tail of the prepended
copy.\")" (CL:FUNCTION PREPEND) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REVERSE (LIKE SELF)) ((SELF CONS)) :DOCUMENTATION \"Destructively reverse the members of the cons list `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION REVERSE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (SUBSTITUTE CONS) ((SELF CONS) (INVALUE OBJECT) (OUTVALUE OBJECT)) :DOCUMENTATION \"Destructively replace each appearance of `outValue' by
`inValue' in the cons list `self'.\" :PUBLIC? TRUE)" (CL:FUNCTION SUBSTITUTE)
    NULL)
   (DEFINE-FUNCTION-OBJECT "MAP-NULL-TO-NIL"
    "(DEFUN (MAP-NULL-TO-NIL (LIKE SELF)) ((SELF CONS)) :DOCUMENTATION \"Return `nil' iff `self' is `null' or `self' otherwise.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (CHOOSE (NULL? SELF) NIL SELF)))"
    (CL:FUNCTION MAP-NULL-TO-NIL) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FIRST (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the first element of `self'.  The first element
of `self' can be set with `setf'.  Note that '(first NIL)' = `null'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VALUE SELF)))"
    (CL:FUNCTION FIRST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (SECOND (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the second element of `self'.  The second element
of `self' can be set with `setf'.  Note that '(second NIL)' = `null'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VALUE (REST SELF))))"
    (CL:FUNCTION SECOND) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (THIRD (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the third element of `self'.  The third element
of `self' can be set with `setf'.  Note that '(third NIL)' = `null'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VALUE (REST (REST SELF)))))"
    (CL:FUNCTION THIRD) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FOURTH (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the fourth element of `self'.  The fourth element
of `self' can be set with `setf'.  Note that '(fourth NIL)' = `null'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION FOURTH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FIFTH (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the fifth element of `self'.  The fifth element
of `self' can be set with `setf'.  Note, that '(fifth NIL)' = `null'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION FIFTH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (NTH (LIKE (ANY-VALUE SELF))) ((SELF CONS) (POSITION INTEGER)) :DOCUMENTATION \"Return the element of `self' at `position'.  The nth element
of `self' can be set with `setf'.  Note, that '(nth NIL <pos>)' = `null'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION NTH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (NTH-REST (LIKE SELF)) ((SELF CONS) (POSITION INTEGER)) :DOCUMENTATION \"Apply `rest' `position' times to `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION NTH-REST) NULL)
   (DEFINE-FUNCTION-OBJECT "LAST-CONS"
    "(DEFUN (LAST-CONS (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF CONS)) :DOCUMENTATION \"Return the last cons of `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION LAST-CONS) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (LAST (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the last element of `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION LAST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FIRST-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION FIRST-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (SECOND-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION SECOND-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (THIRD-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION THIRD-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (NTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE (LIKE (ANY-VALUE SELF))) (POSITION INTEGER)) :PUBLIC? TRUE)"
    (CL:FUNCTION NTH-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FOURTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION FOURTH-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FIFTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION FIFTH-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (NTH-REST-SETTER OBJECT) ((SELF CONS) (VALUE OBJECT) (POSITION INTEGER)) :PUBLIC? TRUE)"
    (CL:FUNCTION NTH-REST-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (ALLOCATE-ITERATOR (CONS-ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF CONS)) :PUBLIC? TRUE)"
    (CL:FUNCTION ALLOCATE-ITERATOR) NULL)
   (DEFINE-FUNCTION-OBJECT "TERMINATE-CONS-ITERATOR?"
    "(DEFUN (TERMINATE-CONS-ITERATOR? BOOLEAN) ((SELF CONS-ITERATOR)) :PUBLIC? TRUE)"
    (CL:FUNCTION TERMINATE-CONS-ITERATOR?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (NEXT? BOOLEAN) ((SELF CONS-ITERATOR)) :PUBLIC? TRUE)"
    (CL:FUNCTION NEXT?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF CONS-ITERATOR)) :PUBLIC? TRUE)"
    (CL:FUNCTION EMPTY?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (LENGTH INTEGER) ((SELF CONS-ITERATOR)) :DOCUMENTATION \"Iterate over 'self', and count how many items there are.\" :PUBLIC? TRUE)"
    (CL:FUNCTION LENGTH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF CONS-ITERATOR) (VALUE OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Iterate over values of `self' and return TRUE
if one of them is `eql?' to 'value.\")" (CL:FUNCTION MEMBER?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (VALUE-SETTER OBJECT) ((SELF CONS-ITERATOR) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION VALUE-SETTER) NULL)
   (DEFINE-FUNCTION-OBJECT "ADD-CONS-TO-END-OF-CONS-LIST"
    "(DEFUN ADD-CONS-TO-END-OF-CONS-LIST ((SELF CONS) (LASTCONS CONS)) :PUBLIC? TRUE)"
    (CL:FUNCTION ADD-CONS-TO-END-OF-CONS-LIST) NULL)
   (DEFINE-FUNCTION-OBJECT "BUT-LAST-NEXT?"
    "(DEFUN (BUT-LAST-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)) :PUBLIC? TRUE)"
    (CL:FUNCTION BUT-LAST-NEXT?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (BUT-LAST (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF CONS)) :DOCUMENTATION \"Generate all but the last element of the cons list `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION BUT-LAST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF CONS)) :DOCUMENTATION \"Return `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION CONSIFY) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST)) :DOCUMENTATION \"Return a list of elements in `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION CONSIFY) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Return a list of key-value pairs in `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION CONSIFY) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF VECTOR)) :DOCUMENTATION \"Return a list of elements in `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION CONSIFY) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF ITERATOR)) :DOCUMENTATION \"Return a list of elements generated by `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION CONSIFY) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (CONSIFY CONS) ((SELF OBJECT)) :DOCUMENTATION \"If `object' is a CONS, return it.  Otherwise, return
a singleton cons list containing it.\" :PUBLIC? TRUE)" (CL:FUNCTION CONSIFY)
    NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REMOVE-DELETED-MEMBERS (LIKE SELF)) ((SELF CONS)) :PUBLIC? TRUE)"
    (CL:FUNCTION REMOVE-DELETED-MEMBERS) NULL)
   (DEFINE-FUNCTION-OBJECT "COPY-CONS-LIST"
    "(DEFUN (COPY-CONS-LIST (LIKE SELF)) ((SELF CONS)) :DOCUMENTATION \"Return a copy of the cons list `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION COPY-CONS-LIST) NULL)
   (DEFINE-FUNCTION-OBJECT "CONS-LIST"
    "(DEFUN (CONS-LIST CONS) (|&REST| (VALUES OBJECT)) :DOCUMENTATION \"Return a cons list containing `values', in order.\" :PUBLIC? TRUE :CONSTRUCTOR? TRUE)"
    (CL:FUNCTION CONS-LIST) NULL)
   (DEFINE-FUNCTION-OBJECT "LIST*"
    "(DEFUN (LIST* CONS) (|&REST| (VALUES OBJECT)) :DOCUMENTATION \"Return a list of conses that make up the list `values',
terminated by the last value rather than by `nil'.  Assumes that
at least one value is passed in.\" :PUBLIC? TRUE :CONSTRUCTOR? TRUE)"
    (CL:FUNCTION LIST*) NULL)
   (DEFINE-FUNCTION-OBJECT "APPEND"
    "(DEFUN (APPEND CONS) ((CONSLIST1 CONS) (CONSLIST2 CONS)) :DOCUMENTATION \"Return a cons list representing the concatenation
of `consList1' and `consList2'.  The concatenation is NOT destructive.\" :PUBLIC? TRUE)"
    (CL:FUNCTION APPEND) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (SUBSET? BOOLEAN) ((SELF CONS) (OTHERLIST CONS)) :DOCUMENTATION \"Return true if every element of `self' also occurs in `otherList'.
Uses an `eql?' test and a simple quadratic-time algorithm.  Note that
this does not check whether `self' and `otherList' actually are sets.\" :PUBLIC? TRUE)"
    (CL:FUNCTION SUBSET?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (EQUIVALENT-SETS? BOOLEAN) ((SELF CONS) (OTHERLIST CONS)) :DOCUMENTATION \"Return true if every element of `self' occurs in `otherList' and vice versa.
Uses an `eql?' test and a simple quadratic-time algorithm.  Note that
this does not check whether `self' and `otherList' actually are sets.\" :PUBLIC? TRUE)"
    (CL:FUNCTION EQUIVALENT-SETS?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (INTERSECTION CONS) ((SELF CONS) (OTHERLIST CONS)) :DOCUMENTATION \"Return the set intersection of `self' and `otherList'.  Uses an `eql?'
test and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if both `self' and `otherList' are sets.\" :PUBLIC? TRUE)"
    (CL:FUNCTION INTERSECTION) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (UNION CONS) ((SELF CONS) (OTHERLIST CONS)) :DOCUMENTATION \"Return the set union of `self' and `otherList'.  Uses an `eql?' test
and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if both `self' and `otherList' are sets.\" :PUBLIC? TRUE)"
    (CL:FUNCTION UNION) NULL))
  :VOID)

(CL:DEFUN STARTUP-CONSES ()
  (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 0)
   (CL:WHEN (CL:EQ NIL NULL) (CL:SETQ NIL (CL:CONS CL:NIL CL:NIL))
    (CL:SETF (%%VALUE NIL) NULL) (CL:SETF (%%REST NIL) NIL))
   (CL:WHEN (CL:CONSP NIL) (SETQ NIL CL:NIL)))
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2) (HELP-STARTUP-CONSES1))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ *PRINTLENGTH* NULL-INTEGER)
    (CL:SETQ ELIPSIS SYM-CONSES-STELLA-...))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7) (HELP-STARTUP-CONSES2)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (DIFFERENCE CONS) ((SELF CONS) (OTHERLIST CONS)) :DOCUMENTATION \"Return the set difference of `self' and `otherList' (i.e., all elements
that are in `self' but not in `otherSet').  Uses an `eql?' test and a simple
quadratic-time algorithm.  Note that the result is only guaranteed to be a
set if both `self' and `otherList' are sets.\" :PUBLIC? TRUE)"
     (CL:FUNCTION DIFFERENCE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (SUBTRACT CONS) ((SELF CONS) (OTHERLIST CONS)) :DOCUMENTATION \"Return the set difference of `self' and `otherList' by destructively
removing elements from `self' that also occur in `otherList'.  Uses an `eql?'
test and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if `self' is a set.\" :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTRACT) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (SORT (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF CONS) (PREDICATE FUNCTION-CODE)) :PUBLIC? TRUE :DOCUMENTATION \"Perform a stable, destructive sort of `self' according to
`predicate', and return the result.  If `predicate' has a '<' semantics, the
result will be in ascending order.  It is not guaranteed that `self' will
point to the beginning of the sorted result.  If `predicate' is `null', a
suitable '<' predicate is chosen depending on the first element of `self',
and it is assumed that all elements of `self' have the same type (supported
element types are GENERALIZED-SYMBOL, STRING, INTEGER, and FLOAT).\")"
     (CL:FUNCTION SORT) NULL)
    (DEFINE-FUNCTION-OBJECT "HELP-SORT-CONS-LIST"
     "(DEFUN (HELP-SORT-CONS-LIST CONS) ((LIST CONS) (LENGTH INTEGER) (PREDICATE FUNCTION-CODE)))"
     (CL:FUNCTION HELP-SORT-CONS-LIST) NULL)
    (DEFINE-FUNCTION-OBJECT "MERGE-CONS-LISTS"
     "(DEFUN (MERGE-CONS-LISTS CONS) ((LIST1 CONS) (LIST2 CONS) (PREDICATE FUNCTION-CODE)))"
     (CL:FUNCTION MERGE-CONS-LISTS) NULL)
    (DEFINE-FUNCTION-OBJECT "GENERALIZED-SYMBOL-LESS-THAN?"
     "(DEFUN (GENERALIZED-SYMBOL-LESS-THAN? BOOLEAN) ((X GENERALIZED-SYMBOL) (Y GENERALIZED-SYMBOL)) :PUBLIC? TRUE)"
     (CL:FUNCTION GENERALIZED-SYMBOL-LESS-THAN?) NULL)
    (DEFINE-FUNCTION-OBJECT "WRAPPED-INTEGER-LESS-THAN?"
     "(DEFUN (WRAPPED-INTEGER-LESS-THAN? BOOLEAN) ((X INTEGER-WRAPPER) (Y INTEGER-WRAPPER)) :PUBLIC? TRUE)"
     (CL:FUNCTION WRAPPED-INTEGER-LESS-THAN?) NULL)
    (DEFINE-FUNCTION-OBJECT "WRAPPED-LONG-INTEGER-LESS-THAN?"
     "(DEFUN (WRAPPED-LONG-INTEGER-LESS-THAN? BOOLEAN) ((X LONG-INTEGER-WRAPPER) (Y LONG-INTEGER-WRAPPER)) :PUBLIC? TRUE)"
     (CL:FUNCTION WRAPPED-LONG-INTEGER-LESS-THAN?) NULL)
    (DEFINE-FUNCTION-OBJECT "WRAPPED-FLOAT-LESS-THAN?"
     "(DEFUN (WRAPPED-FLOAT-LESS-THAN? BOOLEAN) ((X FLOAT-WRAPPER) (Y FLOAT-WRAPPER)) :PUBLIC? TRUE)"
     (CL:FUNCTION WRAPPED-FLOAT-LESS-THAN?) NULL)
    (DEFINE-FUNCTION-OBJECT "WRAPPED-STRING-LESS-THAN?"
     "(DEFUN (WRAPPED-STRING-LESS-THAN? BOOLEAN) ((X STRING-WRAPPER) (Y STRING-WRAPPER)) :PUBLIC? TRUE)"
     (CL:FUNCTION WRAPPED-STRING-LESS-THAN?) NULL)
    (DEFINE-FUNCTION-OBJECT "WRAPPED-MUTABLE-STRING-LESS-THAN?"
     "(DEFUN (WRAPPED-MUTABLE-STRING-LESS-THAN? BOOLEAN) ((X MUTABLE-STRING-WRAPPER) (Y MUTABLE-STRING-WRAPPER)) :PUBLIC? TRUE)"
     (CL:FUNCTION WRAPPED-MUTABLE-STRING-LESS-THAN?) NULL)
    (DEFINE-FUNCTION-OBJECT "NUMBER-LESS-THAN?"
     "(DEFUN (NUMBER-LESS-THAN? BOOLEAN) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :DOCUMENTATION \"Generic number comparison that works with integers, longs and floats.\" :PUBLIC? TRUE)"
     (CL:FUNCTION NUMBER-LESS-THAN?) NULL)
    (DEFINE-FUNCTION-OBJECT "CHOOSE-SORT-PREDICATE"
     "(DEFUN (CHOOSE-SORT-PREDICATE FUNCTION-CODE) ((FIRSTELEMENT OBJECT)))"
     (CL:FUNCTION CHOOSE-SORT-PREDICATE) NULL)
    (DEFINE-FUNCTION-OBJECT "SORT-TUPLE-COMPARE?"
     "(DEFUN (SORT-TUPLE-COMPARE? BOOLEAN) ((X CONS) (Y CONS)))"
     (CL:FUNCTION SORT-TUPLE-COMPARE?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (SORT-TUPLES (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF CONS) (N INTEGER) (PREDICATE FUNCTION-CODE)) :PUBLIC? TRUE :DOCUMENTATION \"Just like `sort' but assumes each element of `self' is a tuple (a cons)
whose `n'-th element (0-based) will be used for comparison.\")"
     (CL:FUNCTION SORT-TUPLES) NULL)
    (DEFINE-FUNCTION-OBJECT "SEARCH-CONS-TREE?"
     "(DEFUN (SEARCH-CONS-TREE? BOOLEAN) ((TREE OBJECT) (VALUE OBJECT)) :DOCUMENTATION \"Return `true' iff the value `value' is embedded within
the cons tree `tree'.  Uses an `eql?' test.\" :PUBLIC? TRUE)"
     (CL:FUNCTION SEARCH-CONS-TREE?) NULL)
    (DEFINE-FUNCTION-OBJECT "SEARCH-CONS-TREE-WITH-FILTER?"
     "(DEFUN (SEARCH-CONS-TREE-WITH-FILTER? BOOLEAN) ((TREE OBJECT) (VALUE OBJECT) (FILTER CONS)) :DOCUMENTATION \"Return `true' iff the value `value' is embedded within
the cons tree `tree'.  Uses an `eql?' test.  Does not descend into any
cons whose first element matches an element of `filter'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION SEARCH-CONS-TREE-WITH-FILTER?) NULL)
    (DEFINE-FUNCTION-OBJECT "COPY-CONS-TREE"
     "(DEFUN (COPY-CONS-TREE (LIKE SELF)) ((SELF OBJECT)) :DOCUMENTATION \"Return a copy of the cons tree `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION COPY-CONS-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "EQUAL-CONS-TREES?"
     "(DEFUN (EQUAL-CONS-TREES? BOOLEAN) ((TREE1 OBJECT) (TREE2 OBJECT)) :DOCUMENTATION \"Return `true' iff the cons trees `tree1' and `tree2' are
structurally equivalent.  Uses an `eql?' test.\" :PUBLIC? TRUE)"
     (CL:FUNCTION EQUAL-CONS-TREES?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (OBJECT-EQUAL? BOOLEAN) ((TREE1 CONS) (TREE2 OBJECT)) :DOCUMENTATION \"Return `true' iff the cons trees `tree1' and `tree2' are
structurally equivalent.  Uses `equal?' to test equality of subtrees.\" :PUBLIC? TRUE)"
     (CL:FUNCTION OBJECT-EQUAL?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (EQUAL-HASH-CODE INTEGER) ((SELF CONS)) :DOCUMENTATION \"Return an `equal?' hash code for `self'.  Note that this
is O(N) in the number of elements of `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION EQUAL-HASH-CODE) NULL)
    (DEFINE-FUNCTION-OBJECT "SUBSTITUTE-CONS-TREE"
     "(DEFUN (SUBSTITUTE-CONS-TREE OBJECT) ((TREE OBJECT) (NEWVALUE OBJECT) (OLDVALUE OBJECT)) :DOCUMENTATION \"Destructively replace each appearance of `oldValue' by
`newValue' in the cons tree `tree'.  Return the tree.  Uses an `eql?' test.\" :PUBLIC? TRUE)"
     (CL:FUNCTION SUBSTITUTE-CONS-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "CONS-TREE-NTH"
     "(DEFUN (CONS-TREE-NTH OBJECT) ((TREE CONS) |&REST| (INDEX INTEGER)) :DOCUMENTATION \"Access an arbitrary element of `tree' identified by a path
specified as a list of `index' values.  The first `index' specifies the
`index'-th element of `tree', the second `index' the `index'-th subelement
of that element, etc.  Example:
	 
  (cons-tree-nth (quote (a (b (c d e) f) g)) 1 1 2) => e
	
\" :PUBLIC? TRUE)" (CL:FUNCTION CONS-TREE-NTH) NULL)
    (DEFINE-FUNCTION-OBJECT "CONS-TREE-NTH-REST"
     "(DEFUN (CONS-TREE-NTH-REST CONS) ((TREE CONS) |&REST| (INDEX INTEGER)) :DOCUMENTATION \"Access an arbitrary sublist of `tree' identified by a path
specified as a list of `index' values.  The first `index' specifies the
`index'-th element of `tree', the second `index' the `index'-th subelement
of that element, ..., the last index specifies the `nth-rest' of the previous
element (different from `cons-tree-nth').  Example:
	 
  (cons-tree-nth-rest (quote (a (b (c d e) f) g)) 1 1 1) => (d e)
	
\" :PUBLIC? TRUE)" (CL:FUNCTION CONS-TREE-NTH-REST) NULL)
    (DEFINE-FUNCTION-OBJECT "MATCH-CONS-TREE"
     "(DEFUN (MATCH-CONS-TREE KEY-VALUE-LIST) ((TREE OBJECT) (PATTERN OBJECT) (BINDINGS KEY-VALUE-LIST)) :DOCUMENTATION \"Match `pattern' against `tree' and return a list of
variable bindings if they match, or NULL otherwise.  `bindings' can
be NULL or an initial list of bindings to consider.  Pattern variables
use KIF syntax, i.e., they need to start with a `?' character.  A
single question mark is interpreted as the anonymous variable. Example:
	 
  (match-cons-tree (quote (a (b (a d) e) (a d) f g))
                   (quote (a (?x ?y ?) ?y ? g))
                   NULL)
  => |kv|(<?Y,(A D)> <?X,B>)
	
Variables can't be quoted but quoting can effectively be achieved by
inserting to-be-quoted variables bound to themselves into `bindings'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION MATCH-CONS-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "CONS-TREE-MATCH?"
     "(DEFUN (CONS-TREE-MATCH? BOOLEAN) ((TREE OBJECT) (PATTERN OBJECT)) :DOCUMENTATION \"Predicate version of `match-cons-tree' (which see).\" :PUBLIC? TRUE)"
     (CL:FUNCTION CONS-TREE-MATCH?) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-CONS"
     "(DEFUN PRINT-CONS ((TREE CONS) (STREAM NATIVE-OUTPUT-STREAM) (LPAREN STRING) (RPAREN STRING)))"
     (CL:FUNCTION PRINT-CONS) NULL)
    (DEFINE-FUNCTION-OBJECT "PPRINT-CONS"
     "(DEFUN PPRINT-CONS ((TREE CONS) (STREAM NATIVE-OUTPUT-STREAM) (LPAREN STRING) (RPAREN STRING)))"
     (CL:FUNCTION PPRINT-CONS) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-STELLA-CODE"
     "(DEFUN PRINT-STELLA-CODE ((TREE OBJECT) (STREAM NATIVE-OUTPUT-STREAM)))"
     (CL:FUNCTION PRINT-STELLA-CODE) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-STELLA-DEFINITION"
     "(DEFUN PRINT-STELLA-DEFINITION ((TREE OBJECT) (STREAM NATIVE-OUTPUT-STREAM)) :PUBLIC? TRUE)"
     (CL:FUNCTION PRINT-STELLA-DEFINITION) NULL)
    (DEFINE-FUNCTION-OBJECT "TREE-SIZE"
     "(DEFUN (TREE-SIZE INTEGER) ((SELF OBJECT)))" (CL:FUNCTION TREE-SIZE)
     NULL)
    (DEFINE-FUNCTION-OBJECT "SAFELY-COMPUTE-TREE-SIZE"
     "(DEFUN (SAFELY-COMPUTE-TREE-SIZE INTEGER) ((TREE CONS) (DEPTHCOUNT INTEGER) (CUTOFF INTEGER)))"
     (CL:FUNCTION SAFELY-COMPUTE-TREE-SIZE) NULL)
    (DEFINE-FUNCTION-OBJECT "SAFE-TREE-SIZE"
     "(DEFUN (SAFE-TREE-SIZE INTEGER STRING) ((TREE CONS)))"
     (CL:FUNCTION SAFE-TREE-SIZE) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-CONSES"
     "(DEFUN STARTUP-CONSES () :PUBLIC? TRUE)" (CL:FUNCTION STARTUP-CONSES)
     NULL)
    (CL:LET* ((FUNCTION (LOOKUP-FUNCTION SYM-CONSES-STELLA-STARTUP-CONSES)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-CONSES-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupConses") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "/STELLA")))
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL NIL CONS NULL :PUBLIC? TRUE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *REMOVE-DUPLICATES-CROSSOVER-POINT* INTEGER 20 :DOCUMENTATION \"Point where we switch from using a quadratic remove
duplicates algorithm to a linear one using a hash table.  For
an unoptimized Common Lisp, 20 is a good crossover point.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *SORT-TUPLE-COMPARE-PREDICATE* FUNCTION-CODE NULL)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *SORT-TUPLE-COMPARE-INDEX* INTEGER 0)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *PRINTPRETTY?* BOOLEAN TRUE :DOCUMENTATION \"If `true' conses will be pretty printed.\" :PUBLIC? TRUE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *PRINTREADABLY?* BOOLEAN FALSE :DOCUMENTATION \"If `true' conses will be printed as readable Stella code.\" :PUBLIC? TRUE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *PRINTLENGTH* INTEGER NULL :DOCUMENTATION \"If non-NULL list-like data structures will print at most
that many elements.\" :PUBLIC? TRUE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL ELIPSIS SYMBOL (QUOTE ...) :DOCUMENTATION \"Generates an elipsis '...' when found in a
pretty-printed parse tree.\" :PUBLIC? TRUE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *PRINTPRETTYCODE?* BOOLEAN TRUE :DOCUMENTATION \"When `true' pretty-print Stella and translated code.
Since (Lisp) pretty-printing is somewhat slow, turning this off speeds up
file translation, but it also makes translated output very unreadable.\" :PUBLIC? TRUE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFSPECIAL *DEPTHEXCEEDED?* BOOLEAN FALSE)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *DEPTHCUTOFF* INTEGER 33)")))
  :VOID)
