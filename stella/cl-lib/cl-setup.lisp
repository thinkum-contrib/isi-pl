;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                          ;
;  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996, 1997             ; 
;  University of Southern California, Information Sciences Institute       ;
;  4676 Admiralty Way                                                      ;
;  Marina Del Rey, California 90292                                        ;
;                                                                          ;
;  This software was developed under the terms and conditions of Contract  ;
;  No. N00014-94-C-0245 between the Defense Advanced Research Projects     ;
;  Agency and the University of Southern California, Information Sciences  ; 
;  Institute.  Use and distribution of this software is further subject    ;
;  to the provisions of that contract and any other agreements developed   ;
;  between the user of the software and the University of Southern         ;
;  California, Information Sciences Institute.  It is supplied "AS IS",    ;
;  without any warranties of any kind.  It is furnished only on the basis  ;
;  that any party who receives it indemnifies and holds harmless the       ;
;  parties who furnish and originate it against any claims, demands, or    ;
;  liabilities connected with using it, furnishing it to others or         ;
;  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    ;
;  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  ;
;  BE ATTACHED TO EVERY PART.                                              ;
;                                                                          ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;; Version: cl-setup.lisp,v 1.9 1997/06/25 01:13:55 hans Exp

;;; Common-Lisp package setup and boot support.

(in-package "CL-USER")


(eval-when (compile load eval)
  (unless (find-package "STELLA")
    (make-package "STELLA" :use NIL)))

(loop for symbol
      in '(CL:SETQ CL:SETF
           CL:PRINT-OBJECT
           CL:IN-PACKAGE CL:EXPORT
           CL:TRACE CL:UNTRACE CL:INSPECT CL:apropos
           ;; stuff necessary for ACL interface:
           #+allegro CL:COMPILE
           #+allegro CL:EVAL-WHEN
           #+allegro CL:*READTABLE*)
      do (shadowing-import symbol "STELLA"))


(in-package "STELLA")

;; Boot-time kludges:

#|
(CL:defun cast (value type)
  (CL:declare (CL:ignore type))
  value)

(CL:defmacro cast (value type)
  (CL:declare (CL:ignore type))
  value)
|#

(CL:defun get-sgt (offset)
  (CL:declare (CL:ignore offset)))

(CL:declaim
 (CL:special
     NULL NULL-INTEGER TRUE FALSE
     ;; Avoid some warnings:
     NIL NIL-LIST NULL-STRING-WRAPPER NULL-CODE-WRAPPER
     NULL-CHARACTER NULL-BOOLEAN))

;; Set these via 'CL:setq' so we'll avoid multiple definitions:
(CL:setq NULL :null_value)
(CL:setq NULL-INTEGER CL:MOST-NEGATIVE-FIXNUM)
(CL:setq TRUE 1)
(CL:setq FALSE 0)


  ;;
;;;;;; Low-level support for CLOS and CL-struct slot value access
  ;;

;;; The class prototype table links CLOS class prototypes to class
;;; names and vice versa.  Class prototypes are used by vector structs
;;; for method dispatch, and in an Allegro-specific "fast-slot hack"
;;; that allows fast CLOS slot access for the cost of two struct slot
;;; accesses.

(CL:defvar *clsys-class-prototype-table*
    (CL:make-hash-table :test #'CL:eq :size 200))

(CL:defun clsys-define-class-prototype (className)
  ;; Define a prototype for the class named 'className'.
  (CL:let ((prototype (CL:make-instance className)))
    ;; Make the prototype a defined key in the prototype table:
    (CL:setf (CL:gethash prototype *clsys-class-prototype-table*) className)
    ;; Link the prototype to its name:
    (CL:setf (CL:get className 'class-prototype) prototype)))

(CL:defmacro clsys-class-prototype (className)
  ;; Retrieve the prototype for the class named 'className'.
  ;; Define a prototype if necessary.
  `(CL:or (CL:get ,className 'class-prototype)
          (clsys-define-class-prototype ,className)))

(CL:defmacro clsys-class-prototype-p (thing)
  ;; True if 'thing' is a class prototype.
  `(CL:gethash ,thing *clsys-class-prototype-table*))

;;; For fast and generic access to slots in vector structs as well as for
;;; the Allegro fast-slot hack we define a vector struct that can be
;;; dynamically redefined to accomodate more slots.

(CL:defvar *clsys-fast-slots-number* CL:nil)

(CL:defun clsys-yield-fast-slot-name (index)
  (CL:intern (CL:format CL:nil "CLSYS-FAST-SLOT-~d" index) "STELLA"))

(CL:defun clsys-fast-slot-lookup (object slot-index)
  ;; A forward-declaration for the dynamically generated lookup function.
  (CL:declare (CL:ignore object slot-index)))

(CL:defun clsys-define-fast-slot-accessors (nofSlots)
  ;; Define a vector struct with 'nofSlots' and a corresponding
  ;;    'clsys-fast-slot-lookup' function.
  ;; The lookup function is only used for the Allegro fast-slot hack
  ;;    to disect CLOS instances.
  (CL:eval
   `(CL:defstruct (clsys-fast-slot-struct
                   (:type cl:vector) (:conc-name CL:nil))
      ,@(CL:loop for i from 0 to (CL:1- nofSlots)
            collect (clsys-yield-fast-slot-name i))))
  (CL:eval
   `(CL:defun clsys-fast-slot-lookup (object slot-index)
      (CL:declare
       (CL:optimize (CL:speed 3) (CL:safety 0) (CL:space 0) (CL:debug 0)))
      (CL:case slot-index
        ,@(CL:loop for i from 0 to (CL:1- nofSlots)
              collect `(,i (,(clsys-yield-fast-slot-name i) object)))
        (CL:otherwise
         (CL:error "clsys-fast-slot-lookup: 'slot-index' too high.")))))
  (CL:compile 'clsys-fast-slot-lookup)
  (CL:setq *clsys-fast-slots-number* nofSlots))

(CL:defun clsys-possibly-expand-fast-slot-accessors (minNofSlots)
  ;; Make sure the current version of 'clsys-fast-slot-struct' has
  ;;    at least 'minNofSlots' slots.
  (CL:when (CL:< *clsys-fast-slots-number* minNofSlots)
    (clsys-define-fast-slot-accessors (CL:+ minNofSlots 10))))

(clsys-define-fast-slot-accessors 30)

;;; Support for Allegro-CL (ACL) fast-slot hack:

;;; If in ACL we compile a slot access to a vector struct with the highest
;;; possible optimization, all dynamic type checking is eliminated and we
;;; we can use that slot access to disect various Lisp data structures.
;;; For example, '(clsys-fast-slot-lookup i 0)' for some CLOS instance 'i'
;;; returns the data structure that points back from the instance to the
;;; class.  '(clsys-fast-slot-lookup i 1)' returns the actual vector of
;;; slot values of 'i'.  Since in Stella we know the type of the object
;;; on which a slot is accessed, we can access the slot of a CLOS object
;;; for the cost of two struct slot accesses, if we know the index of the
;;; slot in the slot-value vector.  Luckily, these slot indicies can be
;;; determined experimentally at compile time.

(CL:defun clsys-find-fast-slot-index (object slotValue)
  ;; Return the index of the slot on 'object' that contains 'slotValue',
  ;;    or CL:nil if no such slot exists.
  (CL:let ((nofSlots (CL:length object))
           (slotIndex CL:nil))
    (clsys-possibly-expand-fast-slot-accessors nofSlots)
    (CL:dotimes (i nofSlots)
      (CL:when (CL:eq (clsys-fast-slot-lookup object i) slotValue)
        (CL:setq slotIndex i)
        (CL:return)))
    slotIndex))

(CL:defvar *clsys-safe-to-use-fast-CLOS-slot-value-p* CL:nil)
(CL:defvar *clsys-fast-CLOS-slot-value-checked-for-pathname* CL:nil)

(CL:defun clsys-safe-to-use-fast-CLOS-slot-value-p ()
  ;; Return true if it is safe to use the ACL fast-slot hack.
  ;; It is safe if we are currently compiling code with the highest
  ;;    optimization setting.  The only way to reliably know whether we are
  ;;    currently compiling is to check whether 'CL:*compile-file-pathname*'
  ;;    is bound.  The only way to check whether we have the highest
  ;;    optimization setting is to compile some actual code and see whether
  ;;    its execution triggers an error or not.  Since this test is somewhat
  ;;    expensive, we make sure it is only executed once per compiled file.
  ;; NOTE: We use CL-USER as the package for '*compile-file-pathname*' to
  ;;       avoid importing that symbol into the CL package in Lisps that
  ;;       do not define 'CL:*compile-file-pathname*'.
  (CL:when (CL:and (CL:boundp 'CL-USER::*compile-file-pathname*)
                   CL-USER::*compile-file-pathname*
                   ;; Disable fast slots for now, since multiple
                   ;;    inheritance can trip us up:
                   (CL:not :disabled-p))
    (CL:if (CL:eq CL-USER::*compile-file-pathname*
                  *clsys-fast-CLOS-slot-value-checked-for-pathname*)
        *clsys-safe-to-use-fast-CLOS-slot-value-p*
      (CL:setq *clsys-safe-to-use-fast-CLOS-slot-value-p*
        (CL:handler-case
            (CL:and (CL:setq *clsys-fast-CLOS-slot-value-checked-for-pathname*
                      CL-USER::*compile-file-pathname*)
                    (CL:funcall
                     (CL:compile
                      CL:nil
                      '(CL:lambda ()
                        (clsys-fast-slot-0
                         (CL:find-class 'CL:standard-class)))))
                    CL:T)
          (CL:error CL:NIL))))))

(CL:defun clsys-yield-fast-CLOS-slot-value-tree (className slotName objectRef)
  ;; Yield a slot access tree to the slot 'className.slotName' on 'objectRef'
  ;;    via the ACL fast-slot hack if possible.
  #-(or allegro-v4.2 allegro-v4.3)
  (CL:declare (CL:ignore className slotName objectRef))
  #+(or allegro-v4.2 allegro-v4.3)
  (CL:when (clsys-safe-to-use-fast-CLOS-slot-value-p)
    (CL:handler-case
        (CL:when (CL:find-class className CL:nil)
          (CL:let ((prototype (clsys-class-prototype className))
                   (fastSlotIndex CL:nil))
            (CL:setf (CL:slot-value prototype slotName) slotName)
            (CL:setq fastSlotIndex
              (clsys-find-fast-slot-index
               (clsys-fast-slot-lookup prototype 1) slotName))
            (CL:when fastSlotIndex
              (CL:return-from
                  clsys-yield-fast-CLOS-slot-value-tree
                `(,(clsys-yield-fast-slot-name fastSlotIndex)
                  (clsys-fast-slot-1 ,objectRef))))))
      (CL:error CL:NIL))))

(CL:defun clsys-yield-CLOS-slot-accessor-name (className slotName)
  ;; Mirrors 'yield-CLOS-slot-accessor-name'.
  (CL:intern (CL:concatenate 'CL:string (CL:symbol-name slotName) "...OF")
             (CL:symbol-package className)))

(CL:defun clsys-yield-CLOS-slot-value-tree (className slotName objectRef)
  ;; Yield a slot access tree to the slot 'className.slotName' on 'objectRef'.
  ;; If the ACL fast-slot hack can be used use it, otherwise access the slot
  ;;    via its accessor method.
  (CL:let ((fastSlotValueTree
            (clsys-yield-fast-CLOS-slot-value-tree
             className slotName objectRef)))
    (CL:or fastSlotValueTree
           `(,(clsys-yield-CLOS-slot-accessor-name className slotName)
             ,objectRef))))

(CL:defmacro CLSYS-SVAL (CL:&rest arguments)
  ;; Calls to this macro are generated by 'yield-slot-value-reader-tree'
  ;;    to access native storage slots.
  ;; CLOS slots are accessed with the format
  ;;    '(CLSYS-SVAL <class-name> <slot-name> <object-ref>)'.
  ;; Vector struct slots are accessed with the format
  ;;    '(CLSYS-SVAL <slot-offset> <class-name> <slot-name> <object-ref>)'
  ;;    (currently, all but <slot-offset> are ignored).
  (CL:if (CL:integerp (CL:first arguments))
      (clsys-yield-struct-slot-value-tree
       (CL:first arguments) (CL:second arguments)
       (CL:third arguments) (CL:fourth arguments))
    (clsys-yield-CLOS-slot-value-tree
     (CL:first arguments) (CL:second arguments) (CL:third arguments))))


;;; Support for vector struct slot access and fast method call:

(CL:defun clsys-yield-struct-slot-accessor-name (className slotName)
  ;; Mirrors 'yield-struct-slot-accessor-name'.
  ;; Not used right now.
  (CL:intern (CL:concatenate 'CL:string
                             (CL:symbol-name className)
                             "..."
                             (CL:symbol-name slotName))
             (CL:symbol-package className)))

(CL:defun clsys-yield-struct-slot-value-tree
    (slotOffset className slotName objectRef)
  ;; Yield a tree to access the vector struct slot with offset 'slotOffset'.
  (CL:declare (CL:ignore className slotName))
  (clsys-possibly-expand-fast-slot-accessors (CL:1+ slotOffset))
  `(,(clsys-yield-fast-slot-name slotOffset) ,objectRef))

(CL:defstruct (CLSYS-ROOT (:type CL:vector) (:conc-name CL:nil))
  ;; This class currently only exists for the purpose of defining
  ;;    the accessor 'clsys-prototype'.
  (clsys-prototype CL:nil))

;;; '*clsys-self*' is used to pass vector struct objects into 'print-object'
;;; methods, and to avoid multiple evaluation of complex first arguments:

(CL:defvar *clsys-self* CL:nil)

(CL:defmacro CLSYS-CALL (methodName firstArg CL:&rest otherArgs)
  ;; Calls to this macro are generated by 'cl-t-normal-call-method-tree'.
  ;; It expands into the actual method call appropriate for 'methodName'.
  (CL:if (CL:eq methodName 'print-object)
      `(CL:let ((*clsys-self* ,firstArg))
         (CL:print-object (clsys-prototype *clsys-self*) ,@otherArgs))
    (CL:if (CL:atom firstArg)
        `(,methodName (clsys-prototype ,firstArg) ,firstArg ,@otherArgs)
      `(,methodName (clsys-prototype (CL:setq *clsys-self* ,firstArg))
                    *clsys-self* ,@otherArgs))))

(CL:defmacro CLSYS-MAKE (className nofSlots)
  ;; Generate a vector struct for the class named 'className'
  ;;    with 'nofSlots' slots.  A class prototype object will
  ;;    be stored in slot 0 of the generated structure.
  `(CL:vector (clsys-class-prototype ',className)
              ,@(CL:make-list (CL:1- nofSlots))))

(CL:defun clsys-use-structs-p ()
  ;; Return true if the current instance of Stella uses standard CL structs.
  (CL:let* ((haveStandardConsClassP
             (CL:eq (CL:type-of (CL:find-class 'CONS CL:nil))
                    'CL:STANDARD-CLASS)))
    (CL:or (CL:not haveStandardConsClassP)
           (clsys-use-vector-structs-p))))

(CL:defun clsys-use-vector-structs-p ()
  ;; Return true if the current instance of Stella uses vector structs.
  (CL:let* ((haveStandardConsClassP
             (CL:eq (CL:type-of (CL:find-class 'CONS CL:nil))
                    'CL:STANDARD-CLASS)))
    (CL:and haveStandardConsClassP
            (CL:not (CL:slot-exists-p (CL:make-instance 'CONS) 'VALUE)))))

;;; Support for making 'print-object' work on vector structs:

(CL:defun clsys-vector-struct-p (thing)
  ;; Determine whether 'thing' is a vector struct by checking whether
  ;;    it is a vector whose first element is a class prototype.
  (CL:and (CL:vectorp thing)
          (CL:> (CL:length thing) 0)
          (clsys-class-prototype-p (CL:aref thing 0))))

(CL:defun clsys-print-vector-struct-as-vector (self stream)
  ;; Print the vector struct 'self' onto 'stream'.
  ;; For debugging.
  (CL:let ((length (CL:length self))
           (CL:*print-pretty* CL:nil))
    (CL:format stream "#CLSYS(")
    (CL:when (CL:> length 0)
      (CL:prin1 (CL:aref self 0) stream))
    (CL:loop for i from 1 to (CL:1- length)
        do (CL:format stream " ~s" (CL:aref self i)))
    (CL:format stream ")")))

(CL:defun clsys-print-vector-struct (self stream)
  ;; Print the vector struct 'self' onto 'stream' via a call to 'print-object'.
  ;; 'print-object' is dispatched on the class prototype, and the actual
  ;;    vector struct is passed in with help of '*clsys-self*'.
  (CL:let ((*clsys-self* self))
    (CL:print-object (CL:aref self 0) stream)))

#|
(CL:defmethod print-object :around ((self CL:vector) stream)
  ;; Advised version of 'print-object' that can handle vector structs.
  ;; This redefinition is actually performed by startup-time code of
  ;;    'cl-translate.ste', since it should only be done if the current
  ;;    instance of Stella actually uses vector structs.
  (CL:if (clsys-vector-struct-p self)
      (clsys-print-vector-struct self stream)
    (CL:call-next-method)))
|#
