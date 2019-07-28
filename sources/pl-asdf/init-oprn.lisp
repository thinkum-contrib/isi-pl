;; init-oprn.lisp - Operations onto ASDF components for stella-init-system

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

(in-package #:stella-system)


#-(AND)
(defmacro set-global-unconditions (o c) ;; see previous NB
  ;; NB: Earlier prototype for warnings-muffling during ASDF compile/load
  ;;     onto STLELLA Lisp systems - unused, at present
  ;;
  ;; NB: Uses a function presently defined in init-compo.lisp
  (let ((%o (make-symbol "%o"))
        (%c (make-symbol "%c")))
    `(let ((,%o ,o)
           (,%c ,c))
       (uiop/utility:style-warn
        "~<In (~A ~A)~>~< : set *uninteresting-conditions* globally~>"
        ,%o ,%c)
       (setq uiop/lisp-build:*uninteresting-conditions*
             (muffle-conditions-list ,%o ,%c)))))


(defmacro system-eval-main (op c)
  `(progn
     ;; NB This applies the following forms to all system definitions
     ;; of a type STELLA-LISP-BOOTSTRAP-SYSTEM, for which the following OPERATE
     ;; methods would represent the primary methods
     (impl-check)
     (ensure-feature :pl-asdf)
     (ensure-system-pathname-translations ,op ,c)
     #-(and) (set-global-unconditions ,op ,c)
     (call-next-method)))


;; NB: The following methods are defined onto OPERATE, such as to ensure
;; that forms in SYSTEM-EVAL-MAIN may be evaluated previous to any
;; evaluation of ASDF:PERFORM onto objects within the provided system
;; definition.

(defmethod asdf:operate ((o asdf:compile-op) (c stella-lisp-bootstrap-system)
                         &key &allow-other-keys)
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:OPERATE :AROUND~< (ASDF:COMPILE-OP ~
STELLA-LISP-BOOTSTRAP-SYSTEM)~>~< : (~A ~A)~>" o c)
  (system-eval-main o c))


(defmethod asdf:operate ((o asdf:load-op) (c stella-lisp-bootstrap-system)
                         &key &allow-other-keys)
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:OPERATE :AROUND~< (ASDF:LOAD-OP ~
STELLA-LISP-BOOTSTRAP-SYSTEM)~>~< : (~A ~A)~>" o c)
  (system-eval-main o c))


(defmethod asdf:operate ((o asdf:load-source-op) (c stella-lisp-bootstrap-system)
                         &key &allow-other-keys)
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:OPERATE :AROUND~< (ASDF:LOAD-SOURCE-OP ~
STELLA-LISP-BOOTSTRAP-SYSTEM)~>~< : (~A ~A)~>" o c)
  (system-eval-main o c))


