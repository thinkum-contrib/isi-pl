;; startup-bare.lisp - load STELLA without initializing STELLA system services

;;;;;;;;;;;;;;;;;;;;;;;;;;;; BEGIN LICENSE BLOCK ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                            ;
; Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          ;
;                                                                            ;
; The contents of this file are subject to the Mozilla Public License        ;
; Version 1.1 (the "License"); you may not use this file except in           ;
; compliance with the License. You may obtain a copy of the License at       ;
; http://www.mozilla.org/MPL/                                                ;
;                                                                            ;
; Software distributed under the License is distributed on an "AS IS" basis, ;
; WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   ;
; for the specific language governing rights and limitations under the       ;
; License.                                                                   ;
;                                                                            ;
; The Original Code is the STELLA Programming Language.                      ;
;                                                                            ;
; The Initial Developer of the Original Code is                              ;
; UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          ;
; 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               ;
;                                                                            ;
; Portions created by the Initial Developer are Copyright (C) 1996-2013      ;
; the Initial Developer. All Rights Reserved.                                ;
;                                                                            ;
; Contributor(s):                                                            ;
;   Sean Champ, spchamp@users.noreply.github.com                             ;
;                                                                            ;
; Alternatively, the contents of this file may be used under the terms of    ;
; either the GNU General Public License Version 2 or later (the "GPL"), or   ;
; the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   ;
; in which case the provisions of the GPL or the LGPL are applicable instead ;
; of those above. If you wish to allow use of your version of this file only ;
; under the terms of either the GPL or the LGPL, and not to allow others to  ;
; use your version of this file under the terms of the MPL, indicate your    ;
; decision by deleting the provisions above and replace them with the notice ;
; and other provisions required by the GPL or the LGPL. If you do not delete ;
; the provisions above, a recipient may use your version of this file under  ;
; the terms of any one of the MPL, the GPL or the LGPL.                      ;
;                                                                            ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;; END LICENSE BLOCK ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;
;; startup-bare.lisp - Initialization utility for debugging with STELLA systems
;;
;; NB Early prototype for stella-init.asd
;;
;; Synopsis:
;;
;; This file serves as a partial aggregate of top-level forms from the
;; following source files in the original PowerLoom source tree.
;;
;;   #p"PL:load-stella.lisp"
;;   #p"PL:native;lisp;stella;load-stella.lisp"
;;
;; As a matter of difference, this file does not in itself initialize
;; STELLA logic servces. This may be of use, for instance, when
;; debugging how some Lisp implementations, on some hardware
;; and OS architectures, may behave when compiling some STELLA systems.
;;
;; [spchamp]


;; TD: DEFVAR CL-USER::*INITIALIZE-STELLA* NIL & patch src (STELLA, LOGIC, PL)

(in-package #:cl-user)


(eval-when (:compile-toplevel :load-toplevel :execute)
  #+ccl
  (pushnew :mcl *features* :test #'eq) ;; should not be necc.

  #+(or sbcl ccl)
  ;; (trace cl:add-method) ;; informative

  ;; prevent metacircular errors for print-object method definition
  ;; during compile (useful when loading this file with SBCL)
  (setq *COMPILE-VERBOSE* nil)


  (setq *stella-memoization-default* nil)
  ;; ^ New param for stella memoize.lisp
  ;; cf. changeset 6770bf4 [NEEDS REVIEW before introd to *.ste sources]
  ;; Default should be nil
  ;; TD: Test when set to T
  ;; NB see also, STELLA::ENABLE-MEMOIZATION, STELLA::DISABLE-MEMOIZATION
)

;; --

;;(defvar *stella-verbose?* #-sbcl t #+sbcl nil)
;; ^ try to prevent print methods during build with SBCL - cf. cl-primal

(eval-when (:compile-toplevel :load-toplevel :execute)
(defvar *stella-verbose?* t)
) ;; ... should also wrap the following two defvar (??)

(defvar *stella-compiler-optimization*
  '(optimize (debug 3) (safety 3) (space 1) (speed 1)))

(defvar *load-cl-struct-stella?* nil)

(load (make-pathname
       :name "translations"
       :defaults (or *compile-file-truename* *load-truename*)))

;; --
;; NB Later:
;; (stella-c&l-translated "cl-lib" "cl-setup")
;; --

;; -- from #p"PL:native;lisp;stella;load-stella.lisp"
;;
;; see also: #p"PL:sources;stella;load-stella.lisp"


;;; These globals are here to facilitate bootstrapping (before STELLA is up):
;;; They need to include a directory separator at the end:
(defvar *stella-source-directory* "PL:sources;stella;")
(defvar *stella-native-directory* "PL:native;lisp;stella;")
(defvar *stella-binary-directory* "PL:bin;stella;")

;;; Various switches to customize the behavior of STELLA:

(defvar *load-cl-struct-stella?* NIL
  "If T load the version of STELLA that uses Lisp structs instead of
CLOS objects to implement STELLA objects.  This greatly improves slot
access speed for the price of less flexibility with class redefinition.
Use for production versions only.")

(defvar *load-vector-struct-stella?* NIL
  "Obsolete.")

(defvar *use-stella-hash-tables?* #+allegro T #-allegro NIL
  "If T use STELLA's implementation of hash tables instead of native
Lisp hash tables.  Useful if native hash tables are fraught with
performance problems (as happens in some versions of Allegro once
hash tables grow large).")

;;; Compiler optimization for translated Stella files:
(defvar *stella-compiler-optimization*
    '(optimize (speed 3) (safety 1) (space 0) (debug 1)))

(defvar *stella-source-extension* ".ste")
(defvar *stella-lisp-extension* ".lisp")
(defvar *stella-translated-extension*
    (cond (*load-vector-struct-stella?* ".vslisp")
          (*load-cl-struct-stella?* ".slisp")
          (t *stella-lisp-extension*)))
(defvar *stella-binary-extension*
    (format nil ".~a~a"
            (cond (*load-vector-struct-stella?* "vs")
                  (*load-cl-struct-stella?* "s")
                  (t ""))
	    (CL:pathname-type (cl:compile-file-pathname "f.lisp"))))
#+:lispworks
(pushnew (concatenate 'string "s" system:*binary-file-type*)
	 system::*binary-file-types* :test #'equal)
#+:lispworks
(pushnew (concatenate 'string "vs" system:*binary-file-type*)
	 system::*binary-file-types* :test #'equal)

;;; If this is T, Stella will compile/load/startup verbosely:
(defvar *stella-verbose?* *load-verbose*)

;;; This loading scheme still tries to deal with Lisps that do not support
;;; logical pathnames.  But, are there still any "healthy" Lisps like that?

(defparameter *stella-directory-separator*
    (char *stella-source-directory* (1- (length *stella-source-directory*))))

(defun stella-make-file-name (relativePath type &optional root)
  ;; Make an absolute file-name string from 'relativePath' (a string or list
  ;;    of strings ending in the extensionless file-name), 'type', and 'root'.
  ;; 'root' defaults to '*stella-binary-directory*' for binary files, and
  ;;    '*stella-source-directory*' for all other files.
; (format t "~%RELATIVE PATH: ~S   ~S   ~S~%" relativePath type root)
; (format t "TRUENAME ~S~% " (truename *stella-native-directory*))
  (let (file extension)
    (unless (consp relativePath)
      (setq relativePath (list relativePath)))
    (ecase type
      (:stella (setq extension *stella-source-extension*)
               (setq root (or root *stella-source-directory*)))
      (:lisp (setq extension *stella-lisp-extension*)
             (setq root (or root *stella-native-directory*)))
      (:translated (setq extension *stella-translated-extension*)
                   (setq root (or root *stella-native-directory*)))
      (:binary (setq extension *stella-binary-extension*)
               (setq root (or root *stella-binary-directory*)))
      (:directory (setq extension *stella-directory-separator*)
                  (setq root (or root *stella-source-directory*))))
    (setq file (car (last relativePath)))
    (setq relativePath (butlast relativePath))
    (format nil (format nil "~~a~~{~~a~a~~}~~a~~a"
                               *stella-directory-separator*)
                   root relativePath file extension)))

(defun stella-load-source (&rest file)
  ;; Load a Stella source 'file'.
  (let ((*load-verbose* *stella-verbose?*))
    (load (stella-make-file-name file :stella))))

(defun stella-load-lisp (&rest file)
  ;; Load a Lisp source 'file'.
  (let ((*load-verbose* *stella-verbose?*))
    (load (stella-make-file-name file :lisp))))

(defun stella-load-translated (&rest file)
  ;; Load a translated Lisp source 'file'.
  (let ((*load-verbose* *stella-verbose?*))
    (load (stella-make-file-name file :translated))))

(defun stella-load-binary (&rest file)
  ;; Load a binary 'file'.
  (let ((*load-verbose* *stella-verbose?*))
    (load (stella-make-file-name file :binary))))

(defun stella-need-to-compile? (sourceFile binaryFile)
  ;; T if 'sourceFile' needs to be compiled to yield 'binaryFile'.
  ;;
  ;; NB w/ ASDF filename translations, binaryFile may be &optional
  (or (not (probe-file binaryFile))
      (not (file-write-date sourceFile))
      (not (file-write-date binaryFile))
      (< (file-write-date binaryFile)
         (file-write-date sourceFile))))

(defun stella-c&l-source (&rest file)
  ;; Compile Stella sources into binaries and load binaries.
  ;; This is exclusively used to compile Stella files with the bootstrap
  ;;    walker and translator, and, since the generated binary files can't
  ;;    be loaded independently anyway, we give them different extensions
  ;;    so they won't interfere with compiled CL-translated Stella files.
  (let* ((*stella-binary-extension* ".bfasl")
         (stellaFileName (stella-make-file-name file :stella))
         (binaryFileName (stella-make-file-name file :binary))
         (*compile-verbose* *stella-verbose?*)
         (*load-verbose* *stella-verbose?*))
    (ensure-directories-exist binaryFileName)
    (compile-file stellaFileName :output-file binaryFileName)
    (load binaryFileName)))

(defun stella-c&l-lisp (&rest file)
  ;; Compile Lisp sources into binaries and load binaries.
  ;; Do not compile if the compiled file is up-to-date.
  (let ((stellaFileName (stella-make-file-name file :lisp))
        (binaryFileName (stella-make-file-name file :binary))
        (*compile-verbose* *stella-verbose?*)
        (*load-verbose* *stella-verbose?*))
    (when (stella-need-to-compile? stellaFileName binaryFileName)
      (proclaim *stella-compiler-optimization*)
      (ensure-directories-exist binaryFileName)
      (compile-file stellaFileName :output-file binaryFileName))
    (load binaryFileName)))

(defun stella-c&l-translated (&rest file)
  ;; Compile translated Stella sources into binaries and load binaries.
  ;; Do not compile if the compiled file is up-to-date.
  (let ((stellaFileName (CL:translate-logical-pathname
                         (stella-make-file-name file :translated)))
        (binaryFileName (CL:translate-logical-pathname
                         (stella-make-file-name file :binary)))
        (*compile-verbose* *stella-verbose?*)
        (*load-verbose* *stella-verbose?*))
    (when (stella-need-to-compile? stellaFileName binaryFileName)
      (proclaim *stella-compiler-optimization*)
      (ensure-directories-exist binaryFileName)
      (compile-file stellaFileName :output-file binaryFileName))
    (load binaryFileName)))

#+allegro (setq excl:*print-nickname* t)
#+allegro (tpl:setq-default excl:*print-nickname* t)

#-:cmu
(eval-when (:compile-toplevel :load-toplevel :execute)
  (unless (fboundp 'with-compilation-unit)
    (defmacro with-compilation-unit ((&rest options) &body body)
      (declare (ignore options))
      `(progn ,@body))))


;; --

(eval-when (:compile-toplevel :load-toplevel :execute)
  (stella-c&l-translated "cl-lib" "cl-setup")
)

;; -- sourcing PL:native/lisp/stella/cl-lib/make-stella.lisp
;;
;; see also PL:sources/stella/cl-lib/make-stella.lisp
;;
;; NB also (same contents) PL:native/lisp/stella/cl-lib/make-stella.slisp
;;
;; The following represents principally a syntactic adapatation onto the
;; original (sources path) make-stella.lisp


(in-package #:stella)

(with-style-warnings-suppressed
  (with-redefinition-warnings-suppressed
    (with-undefined-function-warnings-suppressed
      (CL:when CL-USER::*load-cl-struct-stella?*
	(CL-USER::stella-c&l-translated "stella-system-structs"))
      ;; NB: The following filename list is hard-coded in STELLA,
      ;; in the original (sources path) make-stella.lisp
      ;;
      ;; This filename list differs substantially onto that provided in pl:sources/systems/stella-system.ste
      (cl:dolist (lib '("hierarchy"
                        "streams"
                        "taxonomies"
                        "primal"
                        ("cl-lib" "cl-primal")
                        "startup" ;; NB: CL:DEFUN STELLA::STARTUP-STARTUP
                        "type-predicates"
                        "conses"
                        "lists"
                        "collections"
                        "iterators"
                        "symbols" ;; NB: CL:DEFUN STELLA::INITIALIZE-KERNEL-MODULES
                        ;;  "boot-symbols" ;; NB DNE (PL Public src)
                        "literals"
                        "classes"
                        "methods"
                        "defclass"
                        "date-time"
                        "date-time-parser"
                        "stella-in"
                        "foreach"
                        "walk"
                        "dynamic-slots"
                        "dynamic-literal-slots"
                        "cl-translate"
                        "macros"
                        "memoize" ;; NB: cl-user::*STELLA-MEMOIZATION-DEFAULT*, STELLA::*MEMOIZATION-ENABLED*
                        "describe"
                        "demons"
                        "more-demons"
                        "name-utility"
                        "modules" ;; X
                        "contexts" ;; X
                        "read" ;; X
                        "xml" ;; X
                        "translate-file"
                        "systems"
                        "cl-translate-file"
                        "cpp-translate"
                        "cpp-translate-file"
                        "cpp-class-out"
                        "cpp-output"
                        "java-translate"
                        "java-translate-file"
                        "java-class-out"
                        "java-output"
                        "idl-translate"
                        "idl-translate-file"
                        "idl-class-out"
                        "idl-output"
                        "tools"
                        ("cl-lib" "stella-to-cl") ;; X...
                        "startup-system" ;; X
                        ;; [X] : Differs onto stella-system.ste (only in make-stella.lisp)
                        ))
        ;; TBD: Where is this output being dumped to w/ SLIME/SWANK?
        (cl:when cl-user::*stella-verbose?*
          ;; TD w/ ASDF-based builds, set STELLA-VERBOSE from a call
          ;; onto (oprn, component)
          (cl:terpri cl:*error-output*)
          (cl:format cl:*error-output* "#-- Startup: Load ~A" lib)
          (cl:terpri cl:*error-output*))

        ;; TD w/ ASDF-based builds, dervive the compilation-unit plist args
        ;; (allowing per-impl customization) from a call onto (oprn, component)
        (cl:with-compilation-unit #+sbcl (:policy cl-user::*stella-compiler-optimization*)
                                  #-sbcl ()
          (cl:etypecase lib
            (cl:cons
             (cl:apply #'CL-USER::stella-c&l-translated lib))
            (cl:string
             (CL-USER::stella-c&l-translated lib)))

          ) ;; with-compilation-unit
      ))))

