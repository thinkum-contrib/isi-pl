;; init-user.lisp -- user configuration forms for PL STELLA

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

;; sourcing root load-stella.lisp and impl load-stella.lisp

(in-package #:cl-user)

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
