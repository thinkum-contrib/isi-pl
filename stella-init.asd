;; stella-init.asd


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
    (cond
       ((boundp (quote +stella-user-symbols+))
        (symbol-value (quote +stella-user-symbols+)))
       (t
        '(*load-cl-struct-stella?*
          *stella-verbose?*
          ))))

  )


(eval-when (:compile-toplevel :load-toplevel :execute)

  ;;;; unused here - from an earlier sysdef prototype
  ;; (let ((p (find-package '#:cl-user)))
  ;;   ;; NB STELLA/POWERLOOM symbols in CL-USER
  ;;   (dolist (s  '(#:*load-cl-struct-stella?*
  ;;                #:*stella-verbose?*
  ;;                ;; #:*source-truename* ;; [new][contrib]
  ;;                ;; #:*system-asdf* ;; [new][contrib]
  ;;                ))
  ;;     (intern (symbol-name s) p)))

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

;; Misc init for PL-ASDF and PL/STELLA in Common Lisp

(defmacro defconst (name value &optional docstr)
  `(defconstant ,name
     ,@(when docstr (list docstr))
     (cond
       ((boundp (quote ,name))
        (symbol-value (quote ,name)))
       (t ,value))))

(defconst +pl-asdf-cache-name+ "pl-asdf")

(defvar *pl-asdf-bin-cache*
  (uiop/configuration:xdg-cache-home +pl-asdf-cache-name+ :implementation))

(defgeneric compute-fasl-root (op c) ;; ?
  (:method ((op asdf:compile-op) (c asdf:cl-source-file))
    
    )
  (:method ((op asdf:load-op) (c asdf:cl-source-file))
    
    )
  )

(defgeneric compute-relative-fasl-path (op c)  ;; ?
  ;; compute a relative fasl path for C onto its outermost system definition
  (:method ((op asdf:compile-op) (c asdf:cl-source-file))
    
    )
  (:method ((op asdf:load-op) (c asdf:cl-source-file))
    
    )
  )


(defun ensure-pathname-translations (basename)
  (assert (probe-file basename) (basename))
  (let* ((basenamep (pathname basename))
         (wild-version
          ;; sourcing PL:translations.lisp cf. `wild-version-value`
          (cond
            ((ignore-errors (make-pathname
                             :version :wild
                             :defaults basenamep))
             :wild)
            (t nil))))
    (declare (dynamic-extent basenamep wild-version))
    (labels ((mk-logname (tok)
               (format nil "~a;**;*.*.*" tok))
             (mk-template-translate (tok base)
               ;; NB: Using portable pathname hacks from ASDF, at runtime,
               ;;     to ensure portability across/beyond CLtL2 implementations
               (let ((stub (make-pathname
                            :directory (list :relative tok
                                             uiop/pathname::*wild-inferiors-component*)
                            :name uiop/pathname:*wild* :type uiop/pathname:*wild*
                            :version (pathname-version uiop/pathname:*wild-file*)
                            :defaults base)))
                 (merge-pathnames stub base)))
             (mk-src-translate (tok)
               (mk-template-translate tok basenamep))
             (mk-asdf-bin-translate ()
               ;; NB ASDF UIOP/PATHNAME:*OUTPUT-TRANSLATION-FUNCTION*
               ;;    default value ASDF/OUTPUT-TRANSLATIONS:APPLY-OUTPUT-TRANSLATIONS
               ;;    used by UIOP/LISP-BUILD:COMPILE-FILE-PATHNAME*
               ;;      used by UIOP/LISP-BUILD:COMPILE-FILE-TYPE
               ;;       and sometimes by UIOP/LISP-BUILD:COMPILE-FILE*
               ;;           used by ASDF/LISP-ACTION:PERFORM-LISP-COMPILATION
               ;;                used by ASDF/ACTION:PERFORM (COMPILE-OP CL-SOURCE-FILE)
               ;; ... so, it uses ASDF Class definitions only in dispatching for PERFORM (??)
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
                                      *pl-asdf-bin-cache*)))
  (setf (logical-pathname-translations "PL")
        ;; mk-logname + mk-src-translate "sources" "native" "kbs"
        ;; mk-logname + mk-asdf-bin-translate "bin"
        (cons (list (mk-logname "bin") (mk-asdf-bin-translate))
              (mapcar #'(lambda (tok)
                          (list (mk-logname tok) (mk-src-translate tok)))
                      ;; NB This does not handle any install-source oprn [FIXME]
                      '("sources" "native" "kbs")))))))


;; (ensure-pathname-translations (component-pathname (find-system "stella-init")))
;; (probe-file "PL:sources;")


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

;; --

(defclass stella-source-file (asdf:source-file)
  ())


(defclass stella-lisp-source-file (asdf:cl-source-file)
  ())


(defclass stella-c++-header-file (asdf:c-source-file) ;; FIXME
  ;; NB C++ preprocessors & source linkage
  ())

(defclass stella-c++-source-file (asdf:c-source-file) ;; FIXME
  ())

(defclass stella-java-source-file (asdf:c-source-file) ;; FIXME
  ())


(defgeneric muffle-conditions-list (op component)
  ;; return a list of ASDF condition designstors for conditions to
  ;; muffle in OP on COMPONENT
  (:method ((op t) (component t))
    (values uiop/lisp-build:*usual-uninteresting-conditions*)))


(defmethod asdf:operate ((o asdf:compile-op) (c stella-lisp-source-file)
                         &key &allow-other-keys)
  (flet ((method-main ()
           (when (next-method-p) (call-next-method))))
  (uiop/utility:call-with-muffled-conditions #'method-main
                                             (muffle-conditions-list o c))))

(defmethod asdf:operate ((o asdf:load-op) (c stella-lisp-source-file)
                         &key &allow-other-keys)
  (flet ((method-main ()
           (when (next-method-p) (call-next-method))))
  (uiop/utility:call-with-muffled-conditions #'method-main
                                             (muffle-conditions-list o c))))


(defmethod asdf:operate ((o asdf:load-source-op) (c stella-lisp-source-file)
                         &key &allow-other-keys)
  (flet ((method-main ()
           (when (next-method-p) (call-next-method))))
  (uiop/utility:call-with-muffled-conditions #'method-main
                                             (muffle-conditions o c))))


;; -----

(defclass stella-asdf-system (asdf:system)
  ())


(defmethod asdf:operate ((o asdf:compile-op) (c stella-asdf-system)
                         &key &allow-other-keys)
  (impl-check)
  (when (next-method-p) (call-next-method)))


(defmethod asdf:operate ((o asdf:compile-op) (c stella-asdf-system)
                         &key &allow-other-keys)
  (impl-check)
  (when (next-method-p) (call-next-method)))


;; --

(defsystem #:stella-init
  :class stella-asdf-system
  )
