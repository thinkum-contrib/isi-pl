;; stella-init.asd - Extending ASDF onto PowerLOOM(r), early init  -*- lisp -*-


;;;;;;;;;;;;;;;;;;;;;;;;;;;;; BEGIN LICENSE BLOCK ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                                                                            ;
;; Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          ;
;;                                                                            ;
;; The contents of this file are subject to the Mozilla Public License        ;
;; Version 1.1 (the "License"); you may not use this file except in           ;
;; compliance with the License. You may obtain a copy of the License at       ;
;; http://www.mozilla.org/MPL/                                                ;
;;                                                                            ;
;; Software distributed under the License is distributed on an "AS IS" basis, ;
;; WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   ;
;; for the specific language governing rights and limitations under the       ;
;; License.                                                                   ;
;;                                                                            ;
;; The Original Code is this system definition                                ;
;;                                                                            ;
;; The Initial Developer of the Original Code is                              ;
;; Sean Champ spchamp@users.noreply.github.com                                ;
;;                                                                            ;
;; Portions created by the Initial Developer are Copyright (C) 2015           ;
;; the Initial Developer. All Rights Reserved.                                ;
;;                                                                            ;
;; Alternatively, the contents of this file may be used under the terms of    ;
;; either the GNU General Public License Version 2 or later (the "GPL"), or   ;
;; the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   ;
;; in which case the provisions of the GPL or the LGPL are applicable instead ;
;; of those above. If you wish to allow use of your version of this file only ;
;; under the terms of either the GPL or the LGPL, and not to allow others to  ;
;; use your version of this file under the terms of the MPL, indicate your    ;
;; decision by deleting the provisions above and replace them with the notice ;
;; and other provisions required by the GPL or the LGPL. If you do not delete ;
;; the provisions above, a recipient may use your version of this file under  ;
;; the terms of any one of the MPL, the GPL or the LGPL.                      ;
;;                                                                            ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; END LICENSE BLOCK ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(in-package #:cl-user)

;; FIXME In the interest of portability/maintainability, move the
;; following into a source system e.g pl-asdf-systems[.asd]

(eval-when (:compile-toplevel :load-toplevel :execute)

  (defconstant +stella-user-symbols+
    ;; NB: Convenience variables, principally serving as build/runtime
    ;; configuration parameters, defined in the original source files
    ;;   pl:sources;stella;load-stella.lisp
    ;; and
    ;;   pl:sources;stella;cl-lib;make-stella.lisp
    (cond
      ((boundp (quote +stella-user-symbols+))
       (symbol-value (quote +stella-user-symbols+)))
      (t
        '(*load-cl-struct-stella?* ;; NB (Needs tests)
          *stella-verbose?* ;; FIXME ASDF integr
          ;; ^ NB used in STELLA cl-translate-file
          *stella-compiler-optimization* ;;  FIXME ASDF integr. Note corresp. decls in STELLA system defs
          ;; ^ NB used in STELLA cl-translate-file
          ;;   /NB uiop/lisp-build:with-optimization-settings
          *stella-memoization-default* ;; T.D New (contrib)
          *use-stella-hash-tables?* ;; NB! from pl:sources;stella;load-stella.lisp
          ;; ^ NB usage notes
          ;; - STELLA::CLSYS-TEST-SXHASH-SUPPORT & subsq.
          ;; - STELLA collections src
          ;;   - STELLA source forms: sources/stella/collections.ste
          ;;   - Implementation source (non-struct STELLA):
          ;;     native/lisp/stella/collections.lisp
          ))))

  )


;; NB: This PL-ASDF system may not, at this time, provide a complete
;; compatibility interface onto the original
;;   pl:sources;stella;load-stella.lisp
;; and
;;   pl:sources;stella;cl-lib;make-stella.lisp
;; but should be usable, portably, onto ASDF

(eval-when (:compile-toplevel :load-toplevel :execute)
  (defpackage #:stella-system
    (:use #:asdf #:cl)
    #.(list* :shadowing-import-from
             (quote #:cl-user)
             +stella-user-symbols+
             ))
  )


(in-package #:stella-system)

;; -- Initialization forms for PL STELLA

;; ---- sourcing root load-stella.lisp and impl load-stella.lisp'

;;; If this is T, Stella will compile/load/startup verbosely:
(defvar *stella-verbose?* *load-verbose*)

(defvar *load-cl-struct-stella?* NIL
  "If T load the version of STELLA that uses Lisp structs instead of
CLOS objects to implement STELLA objects.  This greatly improves slot
access speed for the price of less flexibility with class redefinition.
Use for production versions only.")

(defvar *use-stella-hash-tables?* #+allegro T #-allegro NIL
  "If T use STELLA's implementation of hash tables instead of native
Lisp hash tables.  Useful if native hash tables are fraught with
performance problems (as happens in some versions of Allegro once
hash tables grow large).")


;; Set this to t to use structs instead of CLOS objects as the implementation
;; of STELLA classes.  Structs are significantly faster but can cause problems
;; when classes are redefined.  Use for production versions only.
#-stella-struct
(defvar *load-cl-struct-stella?* nil)
#+stella-struct
(defvar *load-cl-struct-stella?* t)

;; In CMUCL and derivatives, use low optimization levels to more
;; easily uncover issues due to imprecise type declarations (or too
;; agressive CMUCL type inference); however, to achieve reasonable
;; speed, we need speed=3; also turn down verbosity levels so we can
;; actually see what's going on during compilation:
#+(or cmu sbcl)
(progn (defparameter *stella-compiler-optimization*
         '(optimize (speed 3) (safety 1) (space 1) (debug 1)))
       (setq *compile-verbose* nil
             *compile-print* nil)
       #+cmu
       (setq *gc-verbose* nil))

;; Work around a compiler bug that surfaces with safety=1 in ACL 8.1:
#+allegro-v8.1
(defparameter *stella-compiler-optimization*
  '(optimize (speed 3) (safety 2) (space 0) (debug 1)))


;; contrib. cf. STELLA::*MEMOIZATION-ENABLED*, memoize.lisp, memoize.ste
(defvar *stella-memoization-default* nil)


;; -- Initialization forms for PL-ASDF

(defmacro defconst (name value &optional docstr)
  ;; NB utility macro
  `(defconstant ,name
     ,@(when docstr (list docstr))
     (cond
       ((boundp (quote ,name))
        (symbol-value (quote ,name)))
       (t ,value))))

(defconst +pl-asdf-cache-name+ "pl-asdf")
;; +pl-asdf-cache-name+ - remarks:
;;
;;  - Used, in the subsequent defvar, as the name of a subdirectory onto
;;    XDG DATA DIR. Subsequently, will be suffixed with a subdirectory
;;    denoting an implementation-specific pathname computed by
;;    ASDF. That pathname will then be used as a prefix pathname for
;;    output files produced with pl-asdf
;;
;;  - Used in ENSURE-PATHNAME-TRANSLATIONS, defined below
;;
;;  - May be of use elsewhere in pl-asdf (To Do: install-source-op)
;;
;;  - Denotes, in effect, a symbol used in computing a base pathname
;;    for ASDF operations onto the PL source tree and any subsequent
;;    output files, as may be produced directly with ASDF operations
;;    onto the source tree. Should be compatible across PL-ASDF system
;;    definitions, as such.
;;

(defvar *pl-asdf-output-cache*
  ;; cache dir for outpit files, onto the ASDF output file translations API
  ;;
  ;; e.g used by:
  ;;  ensure-pathname-translations
  ;;

 ;;; FIXME use in a method onto OUTPUT-FILES or similar
  (uiop/configuration:xdg-cache-home +pl-asdf-cache-name+ :implementation))


(defun ensure-pathname-translations (src-prefix)
  ;; define a set of logical pathanme translations in a manner that
  ;; should retain portability onto upstream PowerLOOM(r)
  ;;
  ;; referencing PL:translations.lisp,- NB `wild-version-value'
  ;; (May be addressed portably onto ASDF)
  ;;
  ;; NB:
  ;; - [FIXME/TO-DO] Does not support any INSTALL-SOURCE-OP
  ;;
  ;; - [FIXME/TBD] Does not differentiate onto source systems, when
  ;;   computing the output translation path for the "bin" logical
  ;;   pathname (e.g "pl:bin;...") or for src. This could cause some
  ;;   concerns when generating STELLA implementation source code with
  ;;   the STELLA source translation API.
  ;;
  (assert (probe-file src-prefix) (src-prefix))
  (let ((src-prefix-path (pathname src-prefix)))
    (declare (dynamic-extent src-prefix-path))
    (labels ((mk-subwild-logname (tok)
               (format nil "~a;**;*.*.*" tok))
             (mk-template-translate (tok base)
               ;; NB: Using portable pathname API from ASDF, at runtime,
               ;;     to ensure portability across CLtL2 implementations
               (let ((stub (make-pathname
                            :directory (list :relative tok
                                             uiop/pathname::*wild-inferiors-component*)
                            :name uiop/pathname:*wild* :type uiop/pathname:*wild*
                            :version (pathname-version uiop/pathname:*wild-file*)
                            :defaults base)))
                 (merge-pathnames stub base)))
             (mk-src-translate (tok)
               (mk-template-translate tok src-prefix-path))
             (mk-asdf-bin-translate ()
               ;; NB ASDF UIOP/PATHNAME:*OUTPUT-TRANSLATION-FUNCTION*
               ;;    local value ASDF/OUTPUT-TRANSLATIONS:APPLY-OUTPUT-TRANSLATIONS
               ;;    used by UIOP/LISP-BUILD:COMPILE-FILE-PATHNAME*
               ;;      used by UIOP/LISP-BUILD:COMPILE-FILE-TYPE
               ;;       and sometimes by UIOP/LISP-BUILD:COMPILE-FILE*
               ;;           used by ASDF/LISP-ACTION:PERFORM-LISP-COMPILATION
               ;;                used by ASDF/ACTION:PERFORM (COMPILE-OP CL-SOURCE-FILE)
               ;; NB: Uses ASDF Class definitions insofar as pathname propertiess and dispatching for PERFORM
               (mk-template-translate "bin" *pl-asdf-output-cache*)))
  (setf (logical-pathname-translations "PL")
        (append
         (list
          (list "*.*.*" src-prefix-path) ;; ensure files in top src dir are accessible
          (list (mk-subwild-logname "bin") (mk-asdf-bin-translate)))
         (mapcar #'(lambda (tok)
                          (list (mk-subwild-logname tok) (mk-src-translate tok)))
                 ;; NB This does not handle any install-source oprn [FIXME]
                 '("sources" "native" "kbs")))))))

;;; Inline test forms
;; (ensure-pathname-translations (component-pathname (find-system "stella-init")))
;; (probe-file "PL:sources;")
;; (probe-file "PL:stella-init.asd")

#-(and) ;; prototype code [TMP]
(eval-when ()
  (let* ((pfx (component-pathname (find-system "stella-init")))
         (cpath (merge-pathnames
                 (make-pathname :directory '(:relative
                                             "sources"
                                             "systems")
                                :name "stella-system"
                                :type "ste")
                 pfx)))

    (enough-namestring cpath pfx))
  ;; => "sources/systems/stella-system.ste"
  )


(defun ensure-system-pathname-translations ()
  (ensure-pathname-translations
   (asdf:component-pathname (asdf:find-system "stella-init"))))


(defun ensure-feature (feat)
  (declare (symbol feat))
  (setf *features*
        (pushnew feat *features* :test #'eq)))


(defun impl-check ()
  ;; sourcing <PL:native;lisp;stella;cl-lib;cl-setup.lisp>
  ;;
  ;; Below, this is applied onto COMPILE-OP and LOAD-OP for any
  ;; STELLA-ASDF-SYSTEM
  (let ((len (integer-length most-positive-fixnum)))
  (unless (>= len 24) ;; use `eval' to avoid unreachable code warns
    (error "The maximum fixnum size of this lisp implementation ~
(~D)~%is too small.  It must be at least 24 bits."
           len))))


;; -- PL-ASDF Source Component API


;; ---- Accessor functions onto `stella-asdf-system'

(defgeneric system-component-source-prefix (component))

(defgeneric (setf system-component-source-prefix) (new-value component))


;; ---- Protocol functions used in PERFORM methods

(defgeneric proclamations-for (op component)
  (:method ((op operation) (component source-file))
    (values nil)))

(defgeneric muffle-conditions-list (op component)
  ;; return a list of ASDF condition designators for conditions to
  ;; muffle in an environment of OP on COMPONENT
  (:method ((op t) (component asdf:cl-source-file))
    ;; FIXME may have to set uiop/lisp-build:*uninteresting-conditions*
    ;; lexically, to prevent these from being shadowed? [DNW]
    (values
     (append
      #+sbcl '(sb-ext:compiler-note)
      (let (s)
        (dolist (spec uiop/lisp-build:*usual-uninteresting-conditions* s)
          (when (symbolp spec)
            (setq s (cons spec s))))))))
  (:method ((op t) (component asdf:system))
    ;; NB This might not be called when expected, if ASDF is not
    ;; producing recursive PERFORM calls
    (let ((proto (make-instance
                  (asdf/component:module-default-component-class component))))
      (muffle-conditions-list op proto))))


(defmacro muffle-for ((op c &rest more) &body body )
  (let ((cdn (make-symbol "%cdn"))
        (types (make-symbol "%types"))
        (s (make-symbol "%s")))
    `(let ((,types (append (muffle-conditions-list ,op ,c)
                           (quote ,more))))
       (handler-bind ((t #'(lambda (,cdn)
                             (dolist (,s ,types)
                               (when (typep ,cdn ,s)
                                 (muffle-warning ,cdn))))))
         ,@body))))


;; ---- Generic Class Definitions, Method Specialations, API


(defclass stella-component (asdf:component)
  ())


(defmethod proclamations-for ((op asdf:operation)
                              (component stella-component))
  (declare (ignore op component))
  (values *stella-compiler-optimization*))


(defclass stella-source-component (stella-component asdf:source-file)
  ())

(defclass stella-lisp-source-component (stella-source-component asdf:cl-source-file)
  ())


(defmacro proclaim-for (op component)
  ;; NB ASDF GET-OPTIMIZATION-SETTINGS
  (let ((procls (make-symbol "%procls")))
    `(let ((,procls (proclamations-for ,op ,component)))
       (when ,procls
         (proclaim ,procls)))))

;; #-(and)
(defmacro operate-main (o c)
  `(with-compilation-unit ()
    (proclaim-for ,o ,c)
    (let ((uiop/lisp-build:*uninteresting-conditions*
           ;; FIXME Regardless of where it's being set locally,
           ;; it seems this muffled conditions list
           ;; - in some places - was being shadowed with NIL
           ;;
           ;; SO, try declaring the lexical binding as special, here
           ;; - also, as dynamic-extent (DNW)
           ;;
           ;; Next thing: Try declaring a lexicaly scoped function as
           ;; to shadow UIOP/UTILITY:MATCH-ANY-CONDITION-P (DNW)
           ;;
           ;; Lastly, try overriding the global special binding
           ;; onto uiop/lisp-build:*uninteresting-conditions* (...)
           ;; [FIXME] Why is this the only working approach?
           ;;
           (muffle-conditions-list o c)))
      (flet (#-(and)
               (uiop/utility:match-any-condition-p (c list)
                 ;; NB Shadowing this onto ASDF ... DNW
                 (declare (ignore list))
                 (dolist (spec uiop/lisp-build:*uninteresting-conditions*)
                   (when (uiop/utility:match-condition-p spec c)
                     (return spec)))))
        (declare (special uiop/lisp-build:*uninteresting-conditions*) ;; DNW
                 (dynamic-extent uiop/lisp-build:*uninteresting-conditions*))
        (when (next-method-p) (call-next-method))))))

;; (trace UIOP/UTILITY:MATCH-ANY-CONDITION-P)
;; ^ It's being called in ASDF.
;; Is that call possibly overriding all containing handler-bind specs?

(defun set-global-unconditions (o c) ;; see previous NB
  (uiop/utility:style-warn
   "~<In (~A ~A)~>~< : set *uninteresting-conditions* globally~>"
   o c)
  (setq uiop/lisp-build:*uninteresting-conditions*
        (muffle-conditions-list o c)))

#-(and)
(defmacro operate-main (o c) ;; DNW/sometimes
  `(with-compilation-unit ()
    (proclaim-for ,o ,c)
    (muffle-for (,o ,c)
      (when (next-method-p) (call-next-method)))))

(eval-when () ;; TMP
  (muffle-conditions-list (make-instance 'compile-op)
                          (car
                           (module-components
                            (find-system "stella-init"))))

  (muffle-conditions-list (make-instance 'load-op)
                          (car
                           (module-components
                            (find-system "stella-init"))))

  ;; WHERE is the conditions specifier list turning up null?
  )


#+NIL
(defmethod asdf:operate ((o asdf:compile-op) (c stella-lisp-source-component)
                          &key &allow-other-keys)
  (flet ((method-main () (operate-main o c)))
    (uiop/utility:call-with-muffled-conditions #'method-main
                                               ;; FIXME May be redundant now:
                                               (muffle-conditions-list o c))))


(defmethod asdf:operate :around ((o asdf:compile-op) (c stella-lisp-source-component)
                                 &key &allow-other-keys)
  ;; FIXME When is this method being called, within a build managed with ASDF?
  (operate-main o c))

(defmethod asdf:operate :around ((o asdf:load-op) (c stella-lisp-source-component)
                                 &key &allow-other-keys)
  (operate-main o c))

(defmethod asdf:operate :around ((o asdf:load-source-op) (c stella-lisp-source-component)
                                 &key &allow-other-keys)
  (operate-main o c))

;; ---- Pathname Functions

(declaim (inline split-logical-dir-1))
(defun split-logical-dir-1 (str)
  (declare (type string str))
  (let ((idx (position #\; str :test #'char=)))
    (cond
      (idx
       (let ()
         (declare (type (integer 0 #.(1- array-dimension-limit))
                        idx))
         (values (subseq str 0 idx)
                 (unless (= (1+ idx) (length str))
                   (subseq str (1+ idx))))))
      (t (values str nil)))))

;; (split-logical-dir-1 "a;b")
;; => "a", "b"

;; (split-logical-dir-1 "a;b;c")
;; => "a", "b;c"

;; (split-logical-dir-1 "a;")
;; => "a", NIL

;; (split-logical-dir-1 ";a")
;; => "", "a"

;; (split-logical-dir-1 "")
;; => "", NIL

(defun parse-logical-directory (str)
  (declare (type string str))
  (labels ((split-next (p rest)
             (multiple-value-bind (first rest*)
                 (split-logical-dir-1 p)
               (cond
                 (rest*
                  (split-next rest* (nconc rest (list first))))
                 (t
                  (nconc rest (list first)))))))
    (let ((len (length str)))
      (declare (type (integer 0 #.array-dimension-limit)
                     len))
      (cond
        ((and (>= len 1)
              (char= (char str 0) #\;))
         (cons :absolute (unless (= len 1)
                           (split-next (subseq str 1) nil))))
        (t
         (cons :relative (split-next str nil)))))))

;; (parse-logical-directory "a;b;c")
;; => (:RELATIVE "a" "b" "c")

;; (parse-logical-directory "a;")
;; => (:RELATIVE "a")

;; (parse-logical-directory ";a;b;c")
;; => (:ABSOLUTE "a" "b" "c")

;; (parse-logical-directory ";")
;; => (:ABSOLUTE)

;; (parse-logical-directory ";a")
;; => (:ABSOLUTE "a")


(defun split-logical-path (p)
  (let* ((pstr (namestring p))
         (hidx (position #\: pstr :test #'char=)))
    (declare (dynamic-extent pstr hidx)
             (type simple-string pstr))
    (cond
      (hidx
       (let ((len (length pstr))
             (hidx+ (1+ hidx)))
         (declare (dynamic-extent len)
                  ;; NB approximate types
                  (type (integer 0 #.array-dimension-limit)
                        hidx hidx+ len))
         (values (subseq pstr 0 hidx)
                 (unless (= hidx+ len)
                   (parse-logical-directory (subseq pstr hidx+))))))
      (t (values nil (parse-logical-directory pstr))))))

;; (split-logical-path "a:b;c;d")
;; "a", (:RELATIVE "b" "c" "d")

;; (split-logical-path "a:")
;; => "a", NIL

;; (split-logical-path "b;c;d")
;; NIL, (:RELATIVE "b" "c" "d")

;; (split-logical-path "a:;")
;; => "a", (:ABSOLUTE)
;; ...


(defun parse-prefix-path (p base)
  (declare (inline split-logical-path))
  (multiple-value-bind (h dir)
      (split-logical-path p)
    ;; Assumption: PATH uses a portable, logical pathname syntax
    (merge-pathnames (make-pathname
                      :host (or h (pathname-host base))
                      :directory dir
                      :name nil :type nil :version :unspecific
                      :defaults base)
                     base)))

;; (parse-prefix-path "a;b;" *default-pathname-defaults*)
;; => <varies>

;; (namestring (parse-prefix-path "c;d;" "pl:a;b;"))
;; => "PL:A;B;C;D"


(defmethod asdf/component:component-pathname ((component stella-source-component))
  ;; NB Integrate SYSTEM-COMPONENT-SOURCE-PREFIX
  ;;
  ;; NB Needs testing [FIXME]
  (let* ((container (asdf/component:component-parent component))
         (cpath (component-pathname container))
         ;; NB Assumption: CONTAINER is a STELLA-ASDF-SYSTEM
         ;; (This feature of the API may be revised at a later time)
         (prefix (system-component-source-prefix container)))
    ;; FIXME use CPATH if PREFIX is null
    (cond
      (prefix
       (merge-pathnames (asdf/component:component-relative-pathname component)
                        (parse-prefix-path prefix cpath)))
      (t (call-next-method)))))


#-(and)
(eval-when ()
  ;; NB This basic form seems to "Work OK"
  ;; Note also, tests on COMPONENT-PATHNAME w/ source prefix specified
  ;; in sysdef
  (let* ((sys (find-system "stella-init"))
         (pfx (system-component-source-prefix sys)))
    (values pfx
            (component-pathname sys)
            (when pfx
              (parse-prefix-path pfx
                                 (component-pathname sys)))))
  )


;; --

(defclass stella-source-file (stella-source-component)
  ;; i.e *.ste file
  ())


(defclass stella-lisp-source-file (stella-lisp-source-component)
  ())


(defclass stella-cl-lib-source-file (stella-lisp-source-file)
  ;; FIXME suffix "cl-lib" dirname to system prefix path dir
  ;;
  ;; FIXME also address STELLA cpp-lib. javalib sources.
  ;;
  ;; Note specifications in stella-system.ste for language-specific
  ;; source files, and STELLA::VERBATIM for inline specification of
  ;; language-specific  STELLA source forms
  ())

(defmethod asdf/component:component-pathname ((component stella-cl-lib-source-file))
  ;; NB Convenience method for computing the source pathname from a
  ;; specification of a STELLA cl-lib source file.
  ;;
  ;; Used in STELLA-INIT ASDF sysdef

  ;; FIXME this should be by-in-large portable onto STELLA cpp-lib and
  ;; javalib source components (May be revised subsequent of deriving
  ;; ASDF system definitions from STELLA system specifications)

  (let* ((container (asdf/component:component-parent component))
         ;; NB Assumption: CONTAINER is a STELLA-ASDF-SYSTEM
         ;; (This feature of the API may be revised at a later time)
         (src-type (asdf/component:source-file-type component container))
         ;; NB Assumption: Next-method is
         ;;   ASDF/COMPONENT:COMPONENT-PATHNAME (STELLA-SOURCE-COMPONENT)
         (notpath (call-next-method)))
    (merge-pathnames (make-pathname
                      :directory '(:relative "cl-lib")
                      :name (component-name component)
                      :type src-type
                      :defaults notpath)
                     notpath)))


(defclass stella-c++-header-file (stella-source-component asdf:c-source-file) ;; FIXME
  ;; NB C++ preprocessors & source linkage; toolchains
  ;; TBD Component model for makefile synthesis (bmake, GNU make, others)
  ())

(defclass stella-c++-source-file (stella-source-component asdf:c-source-file) ;; FIXME
  ())

(defclass stella-java-source-file (stella-source-component asdf:c-source-file) ;; FIXME
  ())

;; TBD: FOSS toolchains for IDL language - STELLA source translation & testing


;; -- PL-ASDF System Definition Extensions to ASDF

(defclass stella-asdf-system (asdf:system)
  ((component-source-prefix
      :initarg :component-source-prefix
      :initform nil
      :type (or simple-string simple-base-string pathname null)
      :reader %system-component-source-prefix
      :writer (setf system-component-source-prefix)
      :documentation
      "Prefix path for resolving source file components in this system
definition, relative to the system definition's component pathname")
   ))


(defmethod system-component-source-prefix ((component stella-asdf-system))
  ;; => <slot-value-if-bound>, <boundp>
  (cond
    ((slot-boundp component 'component-source-prefix)
     (values (%system-component-source-prefix component)
             t))
    (t (values nil nil))))


(defmethod shared-initialize :after ((instance stella-asdf-system)
                                     slots &rest initargs
                                     &key &allow-other-keys)
  (declare (ignore initargs))
  ;; NB Cheap/Convenient default setter - slot initform in shared-initialize
  ;;    for COMPONENT-SOURCE-PREFIX

  (when
      (and (or (eq slots 't)
               (and (consp slots)
                    (find 'component-source-prefix slots :test #'eq)))
           (not (slot-boundp instance 'component-source-prefix)))
    (setf (system-component-source-prefix instance)
          ;; FIXME May break if system definition relative-pathname not set previously
          ;;
          ;; FIXME May break some calling functions if COMPONENT-PATHNAME returns NIL
          #-SWANK
          (component-pathname instance)
          ;; ... so, support interactive defsystem eval w/ SLIME/SWANK
          #+SWANK
          (let ((basep (component-pathname instance)))
            (cond
              ((null basep)
               (warn "~<In SHARED-INITIALIZE :AFTER (STELLA-ASDF-SYSTEM ...)~> \
~<: NULL COMPONENT-PATHNAME for ~s (Interactive Eval?)~> \
~<- using *DEFAULT-PATHNAME-DEFAULTS* ~s~>"
                     instance *default-pathname-defaults*)
               (values *default-pathname-defaults*))
              ;; else
              (t (values basep)))))))

;; (system-component-source-prefix (find-system "stella-init"))


(defmethod asdf/component:module-default-component-class ((sys stella-asdf-system))
  ;; NB Specialization
  (find-class 'stella-lisp-source-file))


(defmacro system-eval-main (op c)
  `(progn
     ;; NB this applies impl-check to all system definitions using STELLA-ASDF-SYSTEM
     (impl-check)
     (ensure-feature :pl-asdf)
     (ensure-system-pathname-translations)
     (set-global-unconditions ,op ,c)
     (when (next-method-p) (call-next-method))))


(defmethod asdf:operate :around ((o asdf:compile-op) (c stella-asdf-system)
                                 &key &allow-other-keys)
  ;; is this even being called, this method? whether or not spec'd as :around?
  (system-eval-main o c))


(defmethod asdf:operate :around ((o asdf:load-op) (c stella-asdf-system)
                                 &key &allow-other-keys)
  (system-eval-main o c))

(defmethod asdf:operate :around ((o asdf:load-source-op) (c stella-asdf-system)
                                 &key &allow-other-keys)
  (system-eval-main o c))


;; -- STELLA-INIT System Definition

(defmacro safe-fcall ((name &optional pkg) &rest args)
  ;; NB Trivial macro for forward reference onto undefined functions.
  ;;    used within :PERFORM methods, defined in the following
  (let ((s (make-symbol "%s"))
        (vis (make-symbol "%vis"))
        (fdef (make-symbol "%fdef")))
    `(multiple-value-bind (,s ,vis)
         (find-symbol (symbol-name (quote ,name))
                      (or (quote ,pkg) *package*))
       (let ((,fdef (when (and ,vis (fboundp ,s))
                      (fdefinition ,s))))
       (cond
         (,fdef (funcall (the function ,fdef)
                         ,@args))
         (,vis (error "No function definition found for symbol ~S" ,s))
         (t (error "No symbol for ~A found in package ~A"
                   (quote ,name)
                   (or (quote ,pkg)
                       *package*))))))))


;; (safe-fcall (#:startup-stella-system #:stella))

;; (safe-fcall (#:nop #:cl))

;; (safe-fcall (#:*standard-output* #:cl))


;; Remark - Provenance
;;
;; The following is partially referenced onto the STELLA system source
;; file, pl:sources;stella;cl-lib;make-stella.lisp
;;
;; That file will be denoted, below, as the original make-stella.lisp

;; Remark - when editing STELLA source code
;;
;; When STELLA implementation source files are regenerated for the
;; STELLA implementation in Comon Lisp, then at that time, the
;; original make-stella.lisp may be written to e.g
;;    pl:native/lisp/stella/cl-lib/make-stella.lisp
;; if not also
;;    pl:native/lisp/stella/cl-lib/make-stella.slisp
;; thus overwriting any local edits in the implementation source
;; files.
;;
;; This remark is presented, thus, towards a manner of advice as that
;; one may retain local backups of edits onto the STELLA implementation
;; source code, whether by application of source version control systems
;; or other normal means. Similar advice may apply, when editing
;; PowerLoom implementation source code or other source code produced
;; from translation of STELLA source forms.


(defsystem #:stella-init
  :class stella-asdf-system

  ;; NB The following ordered set of filenames, under :components
  ;; locally, is retained from the file -- in STELLA cl-lib src --
  ;; pl:sources;stella;cl-lib;make-stella.lisp
  ;;
  ;; Notably, the order of the list of filenames in the original
  ;; make-stella.lisp differs to that specified in the STELLA system
  ;; definition for STELLA, i.e pl:sources;systems;stella-system.ste
  ;; Theoretically, one of those may be merged into the other, if they
  ;; are not bootstrap-wise incompatible.
  ;;
  ;; This code assumes that the form in make-stella.lisp may be more
  ;; up-to-date in relation to the STELLA source code. Secondly, it may
  ;; be more effective to use the make-stella.lisp ordering, when
  ;; initially loading the STELLA implementatiom source code in Common
  ;; Lisp.
  ;;
  ;; The ordering provided in stella-system.ste may be tested for
  ;; compatibility, once this contributed source code may pemit for
  ;; generation of ASDF system definitions in evaluation of STELLA
  ;; system definitions.

  ;; NB: Both the implementation source code (Lisp) and original source
  ;; code (STELLA w/ Lisp library) may need to have been modified, so
  ;; as to prevent initialization of the STELLA system in any source
  ;; files that this system definition will serve to evaluate.
  ;;
  ;; For that purpose, the feature symbol :PL-ASDF may be used in
  ;; read-time conditional expressions, such as may be patched onto the
  ;; STELA Common Lisp implementation source code, original STELLA
  ;; source code, and corresponding STELLA cl-lib forms.

  ;; FIXME Are these :perform :before methods being called, when defined?
  ;;       If so, called at what instance during the build?

  ;; :perform (compile-op :before (op c)
  ;;                      (ensure-feature :pl-asdf)
  ;;                      (ensure-system-pathname-translations)
  ;;                      (set-global-unconditions op c))
  ;; :perform (load-op :before (op c)
  ;;                   (ensure-feature :pl-asdf)
  ;;                   (ensure-system-pathname-translations)
  ;;                   (set-global-unconditions op c))
  ;; :perform (load-source-op :before (op c)
  ;;                          (ensure-feature :pl-asdf)
  ;;                          (ensure-system-pathname-translations)
  ;;                          (set-global-unconditions op c))

  :perform (load-op :after (op c)
                    (safe-fcall (#:startup-stella-system #:stella)))
  :perform (load-source-op :after (op c)
                           (safe-fcall (#:startup-stella-system #:stella)))


  :serial t

  ;;; NB use all of the following files as under native/lisp/stella/
  ;;; using a portable pathname syntax in the system definition
  :component-source-prefix "native;lisp;stella;"

  ;; FIXME note the section in sources/stella/cl-lib/cl-setup.lisp
  ;; where "Load support libraries for TCP/IP"
  ;;
  ;; Update this system for portability.
  ;; - STELLA::%%OPEN-NETWORK-STREAM
  ;; - Also "Synchronization Support" in cl-setup.lisp
  :depends-on
  (#+SBCL :SB-BSD-SOCKETS)

  :components
  ((stella-cl-lib-source-file "cl-setup")
   #+stella-struct (:file "stella-system-structs")
   (:file "hierarchy")
   (:file "streams")
   (:file "taxonomies")
   (:file "primal")
   (stella-cl-lib-source-file "cl-primal")
   (:file "startup")
   (:file "type-predicates")
   (:file "conses")
   (:file "lists")
   (:file "collections")
   (:file "iterators")
   (:file "symbols")
   ;;  (:file "boot-symbols")
   (:file "literals")
   (:file "classes")
   (:file "methods")
   (:file "defclass")
   (:file "date-time")
   (:file "date-time-parser")
   (:file "stella-in")
   (:file "foreach")
   (:file "walk")
   (:file "dynamic-slots")
   (:file "dynamic-literal-slots")
   (:file "cl-translate")
   (:file "macros")
   (:file "memoize")
   (:file "describe")
   (:file "demons")
   (:file "more-demons")
   (:file "name-utility")
   (:file "modules")
   (:file "contexts")
   (:file "read")
   (:file "xml")
   (:file "translate-file")
   (:file "systems")
   (:file "cl-translate-file")
   (:file "cpp-translate")
   (:file "cpp-translate-file")
   (:file "cpp-class-out")
   (:file "cpp-output")
   (:file "java-translate")
   (:file "java-translate-file")
   (:file "java-class-out")
   (:file "java-output")
   (:file "idl-translate")
   (:file "idl-translate-file")
   (:file "idl-class-out")
   (:file "idl-output")
   (:file "tools")
   (stella-cl-lib-source-file "stella-to-cl")
   (:file "startup-system")
   ))

