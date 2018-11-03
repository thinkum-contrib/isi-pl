;;; -*- Mode: Lisp; Package: CL-USER; Syntax: COMMON-LISP; Base: 10 -*-

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


;;; Version: load-stella.lisp,v 1.19 1997/11/07 00:56:01 hans Exp

;;; Load STELLA.

(in-package "CL-USER")


;;; These need to include a directory separator at the end:

(defvar *stella-source-directory* "PL:sources;stella;")
(defvar *stella-binary-directory* "PL:binaries;stella;")

#|
;;; Either uncomment these translations or put a copy into your Lisp init-file.
;;; Replace the '/u0/stella' with the actual location of the Stella directory.
(setf (logical-pathname-translations "PL")
  '(("PL:sources;stella;**;*.*" "/u0/stella/**/*.*")
    #+allegro-v4.2
    ("PL:binaries;stella;**;*.*" "/u0/stella/LISP-BIN/ACL4.2/**/*.*")
    #+allegro-v4.3
    ("PL:binaries;stella;**;*.*" "/u0/stella/LISP-BIN/ACL4.3/**/*.*")
    #-(or allegro-v4.2 allegro-v4.3)
    ("PL:binaries;stella;**;*.*" "/u0/stella/LISP-BIN/LISP/**/*.*")))
|#

;;; Use these switches to load a version of Stella that uses structs:
(defvar *load-cl-struct-stella?* NIL)
(defvar *load-vector-struct-stella?* NIL)

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
            #+(or :mcl :allegro) "fasl"
            #+:lucid "sbin"
            #-(or :mcl :allegro :lucid) "fasl"))

;;; If this is T, Stella will be bootstrapped with the early walker:
(defvar *bootstrap-stella?* NIL)

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
  (let (file extension)
    (unless (consp relativePath)
      (setq relativePath (list relativePath)))
    (ecase type
      (:stella (setq extension *stella-source-extension*)
               (setq root (or root *stella-source-directory*)))
      (:lisp (setq extension *stella-lisp-extension*)
             (setq root (or root *stella-source-directory*)))
      (:translated (setq extension *stella-translated-extension*)
                   (setq root (or root *stella-source-directory*)))
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

(defun stella-load-binary (&rest file)
  ;; Load a binary 'file'.
  (let ((*load-verbose* *stella-verbose?*))
    (load (stella-make-file-name file :binary))))

(defun stella-need-to-compile? (sourceFile binaryFile)
  ;; T if 'sourceFile' needs to be compiled to yield 'binaryFile'.
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
      (compile-file stellaFileName :output-file binaryFileName))
    (load binaryFileName)))

(defun stella-c&l-translated (&rest file)
  ;; Compile translated Stella sources into binaries and load binaries.
  ;; Do not compile if the compiled file is up-to-date.
  (let ((stellaFileName (stella-make-file-name file :translated))
        (binaryFileName (stella-make-file-name file :binary))
        (*compile-verbose* *stella-verbose?*)
        (*load-verbose* *stella-verbose?*))
    (when (stella-need-to-compile? stellaFileName binaryFileName)
      (proclaim *stella-compiler-optimization*)
      (compile-file stellaFileName :output-file binaryFileName))
    (load binaryFileName)))

#+allegro (setq excl:*print-nickname* t)
#+allegro (tpl:setq-default excl:*print-nickname* t)

(unless (fboundp 'with-compilation-unit)
  (defmacro with-compilation-unit ((&rest options) &body body)
    (declare (ignore options))
    `(progn ,@body)))

(stella-c&l-lisp "cl-lib" "cl-setup")

(if *bootstrap-stella?*
    (stella-load-lisp "bootstrap" "boot-stella")
  (stella-load-lisp "cl-lib" "make-stella"))
