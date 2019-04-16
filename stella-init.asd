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
        '(*load-cl-struct-stella?* ;; FIXME/NB #:+stella-struct
          *stella-verbose?*
          ;; *stella-compiler-optimization* ;; T.D. Note corresp. to decls in STELLA system defs
          ;; *stella-memoization-default* ;; T.D New (contrib)
          ;; *use-stella-hash-tables?* ;; NB! from pl:sources;stella;load-stella.lisp
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

    ;;;; Use ASDF wrappers here - cf. local muffle-conditions-list
    ;; #+CMUCL
    ;; (:shadowing-import-from #:ext #:inhibit-warnings)
    ;; #+SBCL
    ;; (:shadowing-import-from #:sb-ext #:muffle-conditions #:inhibit-warnings)
    ;; #+SBCL
    ;; (:shadowing-import-from #:sb-kernel #:redefinition-warning)
    ;; #+EXCL
    ;; (:shadowing-import-from #:excl compiler-undefined-functions-called-warning)

    #.(list* :shadowing-import-from
             (quote #:cl-user)
             +stella-user-symbols+
             )) ;; DEFPACKAGE STELLA-SYSTEM
  ) ;; EVAL-WHEN


(in-package #:stella-system)

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
               ;; NB: Uses ASDF Class definitions insofar as dispatching for PERFORM (??)
               (mk-template-translate "bin"
                                      ;; TBD compute base pathname for "This sysdef, this ASDF, this implementation"
                                      ;;
                                      ;; cf. (??) uiop/configuration::compute-user-cache (??)
                                      ;; e.g
                                      ;;   (UIOP/CONFIGURATION::COMPUTE-USER-CACHE) and subsq UIOP/CONFIGURATION:*USER-CACHE*
                                      ;;   => #P"/home/user/.cache/common-lisp/sbcl-1.3.12-linux-arm/"
                                      ;;   ... which provides a filesytem translation onto "/"
                                      ;;
                                      ;; So, alternately
                                      ;;  (uiop/configuration:xdg-cache-home +pl-asdf-cache-name+ :implementation)
                                      *pl-asdf-output-cache*)))
  (setf (logical-pathname-translations "PL")
        ;; mk-subwild-logname + mk-src-translate "sources" "native" "kbs"
        ;; mk-subwild-logname + mk-asdf-bin-translate "bin"
        (append
         (list
          (list "*.*.*" src-prefix-path) ;; ensure files in top src dir are accessible
          (list (mk-subwild-logname "bin") (mk-asdf-bin-translate)))
         (mapcar #'(lambda (tok)
                          (list (mk-subwild-logname tok) (mk-src-translate tok)))
                 ;; NB This does not handle any install-source oprn [FIXME]
                 '("sources" "native" "kbs")))))))


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

(defgeneric system-component-source-prefix (component))
;; NB: cf. `stella-asdf-system' [class]

(defgeneric (setf system-component-source-prefix) (new-value component))

(defclass stella-source-component (asdf:source-file)
  ;; NB Generic class
  ())


(declaim (inline split-logical-dir-1))
(defun split-logical-dir-1 (str)
  (declare (type character c)
           (type string str))
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
         (prefix (system-component-source-prefix container))
         (src-type (asdf/component:source-file-type component container)))
    ;; FIXME use CPATH if PREFIX is null
    (cond
      (prefix
       (merge-pathnames (make-pathname
                         :name (component-name component)
                         ;; directory nil
                         :type src-type
                         :defaults cpath)
                        (parse-prefix-path prefix cpath)))
      (t cpath))))

(eval-when ()
  ;; FIXME This bazic form seems to "Work OK," but COMPONENT-PATHNAME still fails
  ;; w/ source prefix specified.
  ;;
  ;; is it because of method dispatching (??)
  (let* ((sys (find-system "stella-init"))
         (pfx (system-component-source-prefix sys)))
    (values pfx
            (component-pathname sys)
            (when pfx
              (parse-prefix-path pfx
                                 (component-pathname sys)))))
  )

(defclass stella-source-file (stella-source-component)
  ;; i.e *.ste file
  ())


(defclass stella-lisp-source-file (stella-source-component asdf:cl-source-file)
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
  ;; Used twice, in STELLA-INIT ASDF sysdef

  ;; FIXME this should be by-in-large portable onto STELLA cpp-lib and
  ;; javalib source components (May be revised subsequent of deriving
  ;; ASDF system definitions from STELLA system specifications)

  ;; NB asdf/component:source-file-type

  ;; NB UIOP/LISP-BUILD:COMPILE-FILE-TYPE, component output translations
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
  ())

(defclass stella-c++-source-file (stella-source-component asdf:c-source-file) ;; FIXME
  ())

(defclass stella-java-source-file (stella-source-component asdf:c-source-file) ;; FIXME
  ())

;; TBD: FOSS toolchains for IDL language - STELLA source translation & testing


(defgeneric muffle-conditions-list (op component)
  ;; return a list of ASDF condition designstors for conditions to
  ;; muffle in OP on COMPONENT
  (:method ((op t) (component t))
    (values uiop/lisp-build:*usual-uninteresting-conditions*)))


(defmethod asdf:operate ((o asdf:compile-op) (c stella-lisp-source-file)
                         &rest op-args &key &allow-other-keys)
  (declare (ignore op-args))
  (flet ((method-main ()
           (when (next-method-p) (call-next-method))))
  (uiop/utility:call-with-muffled-conditions #'method-main
                                             (muffle-conditions-list o c))))


(defmethod asdf:operate ((o asdf:load-op) (c stella-lisp-source-file)
                         &rest op-args &key &allow-other-keys)
  (declare (ignore op-args))
  (flet ((method-main ()
           (when (next-method-p) (call-next-method))))
  (uiop/utility:call-with-muffled-conditions #'method-main
                                             (muffle-conditions-list o c))))


(defmethod asdf:operate ((o asdf:load-source-op) (c stella-lisp-source-file)
                         &rest op-args &key &allow-other-keys)
  (declare (ignore op-args))
  (flet ((method-main ()
           (when (next-method-p) (call-next-method))))
  (uiop/utility:call-with-muffled-conditions #'method-main
                                             (muffle-conditions-list o c))))


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

  ;; FIXME - using portable, logical pathname syntax in :component-source-prefix DNW [SBCL]
  (when
      (and (or (eq slots 't)
               (and (consp slots)
                    (find 'component-source-prefix slots :test #'eq)))
           (not (slot-boundp instance 'component-source-prefix)))
    (setf (system-component-source-prefix instance)
          ;; FIXME May break if system definition relative-pathname not set previously
          ;;
          ;; FIXME May break calling functions if COMPONENT-PATHNAME returns NIL
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


(defmethod asdf:operate ((o asdf:compile-op) (c stella-asdf-system)
                         &key &allow-other-keys)
  ;; NB apply impl-check to all system definitions using STELLA-ASDF-SYSTEM
  (impl-check)
  (when (next-method-p) (call-next-method)))


(defmethod asdf:operate ((o asdf:compile-op) (c stella-asdf-system)
                         &key &allow-other-keys)
  ;; NB apply impl-check to all system definitions using STELLA-ASDF-SYSTEM
  (impl-check)
  (when (next-method-p) (call-next-method)))


;; -- STELLA-INIT System Definition

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
  :class stella-asdf-system ;; ? this initarg !

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

  :perform (compile-op :before (op c)
                       (ensure-feature :pl-asdf)
                       (ensure-system-pathname-tranalations))
  :perform (load-source-op :before (op c)
                           (ensure-feature :pl-asdf)
                           (ensure-system-pathname-tranalations))
  :perform (load-op :before (op c)
                    (ensure-feature :pl-asdf)
                    (ensure-system-pathname-tranalations))

  ;; NB: (STELLA::STARTUP-STELLA-SYSTEM) - make-stella.lisp

  :serial t

  ;;; NB use all of the following files as under native/lisp/stella/
  ;; :component-source-prefix "pl:native;lisp;stella;"
  :component-source-prefix "native;lisp;stella;"
  ;; :component-source-prefix ";native;lisp;stella;"
  ;;
  ;; :component-source-prefix "pl:;native;lisp;stella;" ;; this notation fails badly
  ;;
  ;;; ^ FIXME DNW when using a relative or absolute logical pathname syntax [SBCL]

  :components
  (#+stella-struct
   (:file "stella-system-structs")
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



(eval-when () ;; [TMP]

  (ensure-system-pathname-translations)

  (let* ((c1 (car (module-components (find-system "stella-init"))))
         (c1p1 (component-pathname c1))
         ;; (c1p2 (uiop/pathname:ensure-absolute-pathname c1))
         )
    (values c1p1
      (probe-file c1p1)
      ;; c1p2
      (mapcar #'component-pathname (module-components (find-system "stella-init")))
      ))
    )
