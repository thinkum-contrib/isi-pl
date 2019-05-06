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
;;  Sean Champ spchamp@users.noreply.github.com                               ;
;; with some code excerpted from original developments by USC ISI, i.e        ;
;;  UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE         ;
;;  4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.              ;
;;                                                                            ;
;; Portions created by the Initial Developer are Copyright (C) 2015-2019      ;
;; the Initial Developer. All Rights Reserved.                                ;
;;                                                                            ;
;; Portions created by USC ISI are Copyright (C) 1996-2006                    ;
;; USC ISI. All Rights Reserved.                                              ;
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
;; following into separate files of a source system e.g pl-asdf-systems[.asd]

;; See also: stella.asd

;; NB/QA cl-user::*stella-default-external-format* [contrib] cf. SLIME streams w/ STELLA


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
          *stella-default-external-format*
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


;; FIXME #'CL-USER::stella-need-to-compile?
;; is referenced in STELLA implementation source files
;; pl:**;cl-translate-file.lisp
;;
;; This function may need a portable implementation for PL-ASDF.
;;
;; The function is referenced within the STELLA implementation source
;; for the Common Lisp function, STELLA::CL-COMPILE-AND-LOAD-FILES

;; ---- sourcing root load-stella.lisp and impl load-stella.lisp

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
(progn (defvar *stella-compiler-optimization*
         '(optimize (speed 3) (safety 1) (space 1) (debug 1)
           ;; #+SBCL (sb-ext:inhibit-warnings 3)
           ;; ^ NB: May be too broad, however effectual [Production Builds]
           ))
       (setq *compile-verbose* nil
             *compile-print* nil)
       #+cmu
       (setq *gc-verbose* nil))

;; NB: SBCL compiler w/ (speed 3)
;; may fail to allow for some conditions muffling

;; Work around a compiler bug that surfaces with safety=1 in ACL 8.1:
#+allegro-v8.1
(defvar *stella-compiler-optimization*
  '(optimize (speed 3) (safety 2) (space 0) (debug 1)))

#-(or cmu sbcl allegro-v8.1)
;; NB: this default used in the the original pl:native;lisp;stella;load-stella.lisp
(defvar *stella-compiler-optimization*
    '(optimize (speed 3) (safety 1) (space 0) (debug 1)))


;; contrib. cf. STELLA::*MEMOIZATION-ENABLED*, memoize.lisp, memoize.ste
(defvar *stella-memoization-default* nil)

;; NB contrib/change, affecting initialization of STELLA-CHARSET
;;    added: cl-user::*stella-default-external-format*
;;    also defined in load-stella.[s]lisp

(defvar *stella-default-external-format*
  ;; NB UIOP/STREAM:*UTF-8-EXTERNAL-FORMAT* [ASDF]
  (cond
    ;; ensure portability with SLIME/SWANK streams
    ;; for interactive sessions within Emacs
    ((find :swank *features* :test #'eq) (values :default))
    (t
     #+allegro
     (CL:ignore-errors (excl::find-external-format :iso-8859-1))
     #+sbcl :latin-1
     #+ccl :iso-8859-1
     #-(or allegro sbcl ccl)
     (CL:stream-external-format CL:*standard-output*)))
   "Initial value for STELLA-CHARSET")

;; -- Initialization forms for PL-ASDF

(defmacro defconst (name value &optional docstr)
  ;; NB utility macro - DEFCONSTANT like DEFVAR
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

;; FIXME Do not rely on [XDG] for filesystem hierarchy specification
;; - Provide option to produce output within prefix <LOCALBASE>/lib/<component>/<impl>/<build>/

(defvar *pl-asdf-output-cache*
  ;; cache dir for outpit files, onto the ASDF output file translations API
  ;;
  ;; e.g used by:
  ;;  ensure-pathname-translations
  ;;

  ;; NB UIOP/LISP-BUILD:*BASE-BUILD-DIRECTORY* [ASDF]

  ;; NB UIOP/LISP-BUILD:COMPILE-FILE-TYPE [ASDF' [Function]

  ;; NB UIOP/PATHNAME:*OUTPUT-TRANSLATION-FUNCTION* [ASDF]
  ;; - usage in UIOP/LISP-BUILD:COMPILE-FILE-PATHNAME* (No Op/Component state provided)

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
  ;; - [FIXME] This, as yet, does not support any INSTALL-SOURCE-OP
  ;;
  ;; - [FIXME/TBD] Does not differentiate onto source systems, when
  ;;   computing the output translation path for the "bin" logical
  ;;   pathname (e.g "pl:bin;...") or for src. This could cause some
  ;;   concerns when generating STELLA implementation source code with
  ;;   the STELLA source translation API.
  ;;

  ;; NB These logical pathname translations may be used internally, in
  ;; STELLA systems, pursuant to software source code synthesis with
  ;; STELLA system definitions.
  ;;
  ;; See also, in translate-file.ste and subsq. implementation sources:
  ;;   stella::*rootSourceDirectory* - default, "PL:sources;"
  ;;   stella::*rootNativeDirectory* - default, "PL:native;"
  ;;   stella::*rootBinaryDirectory* - default, "PL:bin;"
  ;;   furthermore, STELLA function stella::system-definitions-directory
  ;;   such that uses, by default, the pathname "PL:sources;systems;"
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


(defun initialize-system-pathname-translations ()
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
    (error "~<The maximum fixnum size of this lisp implementation ~
(~D)~>~< is too small.  It must be at least 24 bits.~>"
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
  ;; return a list of symbolic condition designators for conditions to
  ;; muffle in an environment of OP on COMPONENT
  ;;
  (:method ((op t) (component asdf:cl-source-file))
    ;; FIXME may have to set uiop/lisp-build:*uninteresting-conditions*
    ;; lexically, to prevent these from being shadowed? [DNW]
    (values
     (append
      #+sbcl '(sb-ext:compiler-note

               sb-c:inlining-dependency-failure
               ;; ^ FIXME: Try not to muffle this.
               ;; Ensure those functions are declared as inline, at top
               ;; level. Meanwhile, this serves to work around a certain
               ;; low-level bug.

               ;; sb-ext:early-deprecation-warning
               )
      (let (s)
        (dolist (spec uiop/lisp-build:*usual-uninteresting-conditions* s)
          (when (symbolp spec)
            (setq s (cons spec s))))))))
  ;; TO DO ^ also specialize onto LOAD-OP, COMPILE-OP
  ;; cf. ASDF *uninteresting-loader-conditions*, *uninteresting-compiler-conditions*

  (:method ((op t) (component asdf:system))
    ;; NB This might not be called when expected, if ASDF is not
    ;; producing recursive PERFORM calls
    (let ((proto (make-instance
                  (asdf/component:module-default-component-class component))))
      (muffle-conditions-list op proto))))

;; NB also
;; UIOP/LISP-BUILD:*UNINTERESTING-CONDITIONS*

(defmacro with-muffling (s &body forms)
  ;; juxtaposed to the behaviors of e.g
  ;; UIOP/UTILITY:MATCH-ANY-CONDITION-P

  ;; NB: This emulates some behaviors of ASDF UIOP/UTILITY:CALL-WITH-MUFFLED-CONDITIONS
  ;;     though not towards specializing on a condition type designator, T
  ;;     and not with accessing any format-control objects of the
  ;;     respective conditions.

  (let ((cdn (make-symbol "%cdn"))
        (typ (make-symbol "%typ"))
        (types (make-symbol "%types")))
    `(let ((,types ,s))
       (declare (dynamic-extent ,types))
       (handler-bind ((warning (lambda (,cdn)
                                 (cond
                                   ((dolist (,typ ,types)
                                      (when (typep ,cdn ,typ) (return ,typ)))
                                    ;; (format *debug-io* "~%Muffle ~S" ,cdn)
                                    (muffle-warning ,cdn))
                                   (t
                                    ;;; NB: Does not always display the condition class:
                                    ;; (format *debug-io* "~%Do not muffle ~S" ,cdn)
                                    (warn ,cdn))))))
         ,@forms))))

;; Concerning a "certain bug" in SBCL - with SBCL 1.5.x and other versions -
;; part of the error outcome:
;;
;; #<SB-FORMAT::FMT-CONTROL "~@<Generic function
;; ~/SB-EXT:PRINT-SYMBOL-WITH-PREFIX/
;; clobbers an earlier ~S proclamation ~/SB-IMPL:PRINT-TYPE/ for the
;; same name with ~/SB-IMPL:PRINT-TYPE/.~:@>"> is not a string
;; designator.
;; ... during %WARN
;; ..... during SB-PCL::NOTE-GF-SIGNATURE
;; ....... during SB-PCL::REAL-ENSURE-GF-USING-CLASS--NULL
;;
;; So, perhaps something from SB-PCL DEFMETHOD is resulting in the
;; FMT-CONTROL being packed into that slot, mistakenly?
;;
;; .. at which, note "FORMAT control string best-effort sanity checker
;; and compactor" in SBCL sys:src;compiler;srctran.lisp
;;
;; NB: The error still occurs, even with SBCL built with
;;     (setq SB-C::*OPTIMIZE-FORMAT-STRINGS* nil)
;; in SBCL sys:src;compiler;srctran.lisp


;; -- PL-ASDF System Definition Extensions

(defclass stella-asdf-system (asdf:system)
  ;; NB Representative of a STELLA implementation source system
  ;;    onto Common Lisp, with a statically defined ASDF system
  ;;
  ;; NB: Shared generalizations onto STELLA-SYSTEM/STELLA-SYSTEM-TEMPLATE
  ((component-source-prefix
    ;; see also: #'SPLIT-LOGICAL-PATH
      :initarg :component-source-prefix
      :type (or simple-string simple-base-string pathname)
      :reader %system-component-source-prefix
      :writer (setf system-component-source-prefix)
      ;; FIXME Consider integrating this with a STELLA-ASDF-MODULE
      ;; class, and subsequently, inheriting the same in
      ;; STELLA-ASDF-SYSTEM. Pathname resolution onto the
      ;; COMPONENT-SOURCE-PREFIX value may then proceed recursively,
      ;; beginning at the "Topmost" system definition's prefix, resolved
      ;; (as presently) onto the system definition's own effective
      ;; COMPONENT-PATHNAME. This could serve to support an arbitrary
      ;; nesting of module/prefix specifications, juxtaposed to the
      ;; essentially flat filesystem namespace, in this present
      ;; implementation of STELLA-ASDF-SYSTEM.
      :documentation
      "Prefix path for resolving source file components in this system
definition.

If specifying a relative pathname, this pathname should be resolved as
relative to the system definition's component pathname. If unbound, this
slot's value may be interpreted as effectively NIL, as in the method
SYSTEM-COMPONENT-SOURCE-PREFIX (STELLA-ASDF-SYSTEM) - in which case, the
system definition's component pathname should be used, without prefix
mapping, when resolving relative pathnames of system component source
files.

This value may be specified using a subset of logical pathname syntax,
such as in \"PL:sources;\". Any element in this pathname may be
interpreted as representing a filesystem directory, whether or not
suffixed with a semicolon character, \";\".")
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
  ;; NB Default slot-value initialization - slot initform in
  ;; shared-initialize for COMPONENT-SOURCE-PREFIX

  (when
      (and (or (eq slots 't)
               (and (consp slots)
                    (find 'component-source-prefix (the cons slots)
                          :test #'eq)))
           (not (slot-boundp instance 'component-source-prefix)))
    (setf (system-component-source-prefix instance)
          ;; FIXME May break if system definition's relative-pathname was not set previously
          ;;
          ;; FIXME May break some calling functions if COMPONENT-PATHNAME returns NIL
          #-SWANK
          (component-pathname instance)
          ;; NB Towards supporting interactive defsystem eval e.g w/ Emacs
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
  (declare (ignore op c))
  `(progn
     ;; NB this applies impl-check to all system definitions using STELLA-ASDF-SYSTEM
     (impl-check)
     (ensure-feature :pl-asdf)
     (unless (ignore-errors (logical-pathname-translations "PL"))
       (initialize-system-pathname-translations))
     #-(and) (set-global-unconditions ,op ,c)
     (call-next-method)))


;; NB: The following methods are defined onto OPERATE, such as to ensure
;; that forms in SYSTEM-EVAL-MAIN may be evaluated previous to any
;; evaluation of ASDF:PERFORM onto objects within the provided system
;; definition.


(defmethod asdf:operate :around ((o asdf:compile-op) (c stella-asdf-system)
                                 &key &allow-other-keys)
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:OPERATE :AROUND~< (ASDF:COMPILE-OP ~
STELLA-ASDF-SYSTEM)~>~< : (~A ~A)~>" o c)
  (system-eval-main o c))

(defmethod asdf:operate :around ((o asdf:load-op) (c stella-asdf-system)
                                  &key &allow-other-keys)
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:OPERATE :AROUND~< (ASDF:LOAD-OP ~
STELLA-ASDF-SYSTEM)~>~< : (~A ~A)~>" o c)
  (system-eval-main o c))

(defmethod asdf:operate :around ((o asdf:load-source-op) (c stella-asdf-system)
                                  &key &allow-other-keys)
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:OPERATE :AROUND~< (ASDF:LOAD-SOURCE-OP ~
STELLA-ASDF-SYSTEM)~>~< : (~A ~A)~>" o c)
  (system-eval-main o c))



;; -- Generic Component Class Definitions, PERFORM Specializations, API


(defclass stella-component (asdf:component)
  ())


(defmethod proclamations-for ((op asdf:operation)
                              (component stella-component))
  (declare (ignore op component))
  (values *stella-compiler-optimization*))


(defclass stella-source-component (stella-component asdf:source-file)
  ())


;; ---- Pathname Functions

(declaim (inline split-logical-dir-1
                 parse-logical-directory
                 split-logical-path))

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
                  ;; NB approximate type decls
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
  (let* ((container (asdf/component:component-parent component))
         (cpath (component-pathname container))
         ;; NB Assumption: CONTAINER is a STELLA-ASDF-SYSTEM
         ;; (This feature of the API may be revised at a later time)
         (prefix (system-component-source-prefix container)))
    (cond
      (prefix
       (merge-pathnames (asdf/component:component-relative-pathname component)
                        (parse-prefix-path prefix cpath)))
      (t (call-next-method)))))


;; --


(defclass stella-implementation-source-file (stella-source-component)
  ;; NB In subclass STELLA-LISP-SOURCE-FILE this obsoletes STELLA-LISP-SOURCE-COMPONENT

  () ;; TBD: Mapping to original *.ste sys defn, *.ste source file
  ;; NB: Integrate this class into the following
  ;;  - STELLA-LISP-SOURCE-FILE (TD: STELLA-SLISP-SOURCE-FILE)
  ;;  - STELLA-C++-SOURCE-FILE (NB: CPP-CODE and CPP-HEADER files w/ STELLA)
  ;;  - STELLA-JAVA-SOURCE-FILE (NB: Java Class defns)
  ;;  - STELLA-IDL-SOURCE-FILE (TBD)
  ;;
  ;; NB: Generic class, disjunct to STELLA-SOURCE-FILE (*.ste)
  ;;
  ;; TD: Document this API, in class and method signatures, w/
  ;; synopses (pl-asdf reference manual)
  )

(defclass stella-lisp-source-file (stella-implementation-source-file asdf:cl-source-file)
  ())

(defmethod asdf/component:source-file-type ((c stella-lisp-source-file)
                                            (container stella-asdf-system))
  (declare (ignore c container))
  ;; FIXME STELLA-STRUCT build needs [QA] w/ and w/o Emacs
  #+stella-struct
  (values "slisp")
  #-stella-struct
  (values "lisp"))

;; TD: output translations => fasl, sfasl (under impl subdir w/i output
;; component lib prefix) (NB: XDG-dirs adoption in devo w/ ASDF)


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


(defmacro proclaim-for (op component)
  ;; NB ASDF GET-OPTIMIZATION-SETTINGS
  (let ((procls (make-symbol "%procls")))
    `(let ((,procls (proclamations-for ,op ,component)))
       (when ,procls
         (proclaim ,procls)))))

(defmacro perform-main (om-o om-c)
  (let ((%om-o (make-symbol "%om-o"))
        (%om-c (make-symbol "%om-c")))
  `(with-compilation-unit ()
     (let ((,%om-o ,om-o)
           (,%om-c ,om-c))
       (proclaim-for ,%om-o ,%om-c)
       #+SBCL ;; FIXME - impl-specific workaround for a thing
       (proclaim
        (list* 'sb-ext:muffle-conditions
               (muffle-conditions-list ,%om-o ,%om-c)))
       (with-muffling (muffle-conditions-list ,om-o ,om-c)
         (call-next-method))))))

#-(AND)
(defmacro set-global-unconditions (o c) ;; see previous NB
  ;; NB: Earlier prototype for warnings-muffling during ASDF compile/load
  ;;     onto STLELLA Lisp systems - unused, at present
  (let ((%o (make-symbol "%o"))
        (%c (make-symbol "%c")))
    `(let ((,%o ,o)
           (,%c ,c))
       (uiop/utility:style-warn
        "~<In (~A ~A)~>~< : set *uninteresting-conditions* globally~>"
        ,%o ,%c)
       (setq uiop/lisp-build:*uninteresting-conditions*
             (muffle-conditions-list ,%o ,%c))

       )))


(defmethod asdf:perform ((o asdf:compile-op) (c stella-lisp-source-file))
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:PERFORM~< (ASDF:COMPILE-OP ~
STELLA-LISP-SOURCE-COMPONENT)~>~< : (~A ~A)~>" o c)
  (perform-main o c))

(defmethod asdf:perform ((o asdf:load-op) (c stella-lisp-source-file))
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:PERFORM~< (ASDF:LOAD-OP ~
STELLA-LISP-SOURCE-COMPONENT)~>~< : (~A ~A)~>" o c)
  (perform-main o c))

(defmethod asdf:perform ((o asdf:load-source-op) (c stella-lisp-source-file))
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:PERFORM~< (ASDF:LOAD-SOURCE-OP ~
STELLA-LISP-SOURCE-COMPONENT)~>~< : (~A ~A)~>" o c)
  (perform-main o c))


;; --

;; NB
;; STELLA::*LISP-SPLITTER-PATH*
;; STELLA::*JAVA-SPLITTER-PATH*
;; STELLA::*CPP-SPLITTER-PATH*
;; - these may be folded into PL-ASDF pathname handling

(defclass stella-c++-header-file (stella-source-component asdf:c-source-file) ;; FIXME
  ;; NB C++ preprocessors & source linkage; toolchains
  ;; TBD Component model for makefile synthesis (bmake, GNU make, others)

  ;; NB STELLA-C++-SYSTEM, stella.asd
  ())

(defclass stella-c++-source-file (stella-source-component asdf:c-source-file) ;; FIXME

  ;; NB STELLA-C++-SYSTEM, stella.asd
  ())

(defclass stella-java-source-file (stella-source-component asdf:c-source-file) ;; FIXME

  ;; NB STELLA-JAVA-SYSTEM, stella.asd
  ())

;; TBD: FOSS toolchains for IDL language - STELLA source translation & testing
;; NB STELLA-IDL-SYSTEM, stella.asd

;; -- STELLA-INIT System Definition

(define-condition unbound-function (program-error cell-error)
  ()
  (:report
   (lambda (c s)
     (format s "No function definition for ~S"
             (cell-error-name c)))))

(define-condition namespace-condition ()
  ((namespace
    :initarg :namespace
    :reader namespace-condition-namespace)))

(define-condition symbol-not-found (program-error namespace-condition cell-error)
  ()
  (:report
   (lambda (c s)
     (format s "No symbol ~A found in ~S"
             (cell-error-name c)
             (namespace-condition-namespace c)))))

(define-condition package-not-found (program-error cell-error)
  ()
  (:report
   (lambda (c s)
     (format s "No package definition for name ~A"
             (cell-error-name c)))))



(defmacro safe-fcall ((name &optional (pkg *package* pkg-p))
                      &rest args)
  ;; NB Trivial macro for forward reference onto undefined functions.
  ;;    Used within :PERFORM methods, as defined in the following src
  (let ((%name (make-symbol "%name"))
        (s (make-symbol "%s"))
        (%pkg (make-symbol "%pkg"))
        (vis (make-symbol "%vis"))
        (fdef (make-symbol "%fdef")))
    `(let ((,%pkg ,(if pkg-p
                       `(or (find-package (quote ,pkg))
                            (error 'package-not-found
                                   :name (quote ,pkg)))
                       (quote *package*)))
           (,%name ,(etypecase name
                     (symbol `(symbol-name (quote ,name)))
                     (string name))))
       (multiple-value-bind (,s ,vis)
           (find-symbol ,%name ,%pkg)
         (let ((,fdef (when (and ,vis (fboundp ,s))
                        (fdefinition ,s))))
           (cond
             (,fdef (funcall (the function ,fdef) ,@args))
             (,vis (error 'unbound-function :name ,s))
             (t (error 'symbol-not-found :name ,%name
                       :namespace ,%pkg))))))))

;; (safe-fcall (#:identity #:cl-user) '#:s1243)

;; (safe-fcall (#:nop #:cl))

;; (safe-fcall (#:identity #:nop))

;; (safe-fcall (#:*standard-output* #:cl))

;; (safe-fcall (#:identity "CL-USER") '#:s1243)

;; (safe-fcall ("IDENTITY" "CL-USER") '#:s1243)



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
  ;;                      (initialize-system-pathname-translations)
  ;;                      (set-global-unconditions op c))
  ;; :perform (load-op :before (op c)
  ;;                   (ensure-feature :pl-asdf)
  ;;                   (initialize-system-pathname-translations)
  ;;                   (set-global-unconditions op c))
  ;; :perform (load-source-op :before (op c)
  ;;                          (ensure-feature :pl-asdf)
  ;;                          (initialize-system-pathname-translations)
  ;;                          (set-global-unconditions op c))

  ;; NB call STELLA system startup functions after system load
  ;; cf. source files
  ;;       pl:sources;stella;cl-lib;make-stella.lisp
  ;;       pl:native;lisp;stella;cl-lib;make-stella.lisp

  :perform (load-op :after (op c)
                    (safe-fcall (#:startup-stella-system #:stella))
                    (safe-fcall (#:startup-stella-to-cl #:stella)))
  :perform (load-source-op :after (op c)
                           (safe-fcall (#:startup-stella-system #:stella))
                           (safe-fcall (#:startup-stella-to-cl #:stella)))

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

  ;; NB: load-stella is not used in this system
  ;; but will be declared during eval of stella-system.ste

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
   ;;  (:file "boot-symbols") ;; may be obsolete
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

