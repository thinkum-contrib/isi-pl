;; seval-sys.lisp -

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

;; --

(declaim (ftype (function (stella::system-definition)
                          (values asdf/system:system &optional))
                wrap-stella-system))

(defun wrap-stella-system (sys)
  (let ((deps (mapcar #'find-stella-asdf-system
                      (error "TBD"))))
    ))

;; --

(define-condition stella-system-not-found (cell-error)
  ()
  (:report
   (lambda (c s)
     (format s "STELLA system not found: ~s"
             (cell-error-name c)))))


(defun find-stella-asdf-system (name)
  (let ((sys-file (stella::make-system-definition-file-name name)))
    (unless (probe-file sys-file)
      (error 'stella-system-not-found
             :name name))
    (wrap-stella-system stella-sys)))

;; (stella::get-system-definition "logic")
;; => |SYSTEM|logic
;; ^ NB Side effects (system deps)
;;
;; (stella::get-system-definition "dnw")
;; => null
;;
;; (stella::make-system-definition-file-name "logic")
;; (stella::make-system-definition-file-name "sealing-wax")
;; (stella::make-system-definition-file-name "cabbage-system-system")

;; (load (stella::make-system-definition-file-name "powerloom"))
;; ^ NB Side effects (system deps) [FIXME - Side-Effect-Free Wrappers]

