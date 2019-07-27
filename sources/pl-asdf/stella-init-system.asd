;; stella-init.asd - System definition support for STELLA-INIT     -*- lisp -*-

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


;; NB: This system definition presents a portion of source code used by
;; the stella-init.asd system definition.
;;
;; The latter system definition is defined as to emulate some
;; characteristics of the original STELLA system definition, defined in
;; pl:sources;systems;stella-system.ste
;;
;; More directly, the stella-init system emulates the original
;; load-stella source forms, as defined in
;; pl:sources;stella;load-stella.lisp
;;
;; This source code has been patched for purpose of interoperability
;; with ASDF.



(in-package #:cl-user)

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
          *stella-verbose?*
          ;; ^ NB used in STELLA cl-translate-file
          *stella-compiler-optimization*
          ;; ^ NB used in STELLA cl-translate-file
          ;;   - NB macro (ASDF) UIOP/LISP-BUILD:WITH-OPTIMIZATION-SETTINGS
          ;;   - NB GF (PL-ASDF) PROCLAMATIONS-FOR
          *stella-memoization-default?* ;; NB New (contrib) (Needs QA)
          *stella-default-external-format*  ;; NB New (contrib) onto PL 4.0.10
          *use-stella-hash-tables?* ;; cf. pl:sources;stella;load-stella.lisp
          ;; ^ NB usage notes
          ;; - STELLA::CLSYS-TEST-SXHASH-SUPPORT & subsq.
          ;; - STELLA collections src
          ;;   - STELLA source forms: sources/stella/collections.ste
          ;;   - Implementation source (non-struct STELLA):
          ;;     native/lisp/stella/collections.lisp
          )))))



(eval-when (:compile-toplevel :load-toplevel :execute)
  (defpackage #:stella-system
    (:use #:asdf #:cl)
    #.(list* :shadowing-import-from
             (quote #:cl-user)
             +stella-user-symbols+)))


(in-package #:stella-system)

#+NIL
(defmacro defconst (name value &optional docstr)
  ;; NB utility macro - DEFCONSTANT like DEFVAR
  ;; TBD - move into an init-macros source file, if used
  `(defconstant ,name
     ,@(when docstr (list docstr))
     (cond
       ((boundp (quote ,name))
        (symbol-value (quote ,name)))
,       (t ,value))))


(defsystem #:stella-init-system
  :components
  ((:file "init-user")
   (:file "init-parse-path")
   (:file "init-features")
   (:file "init-sys"
          :depends-on ("init-features"
                       #+NIL "init-parse-path" ;; not used in this file [FIXME]
                       ))
   (:file "init-compo"
          :depends-on ("init-user"
                       "init-sys"
                       "init-parse-path"
                       ))
   (:file "init-pathname"
          :depends-on ("init-sys"
                       ))
   (:file "init-oprn"
          :depends-on ("init-compo"
                       "init-pathname"
                       "init-features"
                       ))
   (:file "init-fcall")
   ))
