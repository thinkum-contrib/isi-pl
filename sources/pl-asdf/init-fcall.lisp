;; init-fcall.lisp - Safe function calls for PL-ASDF system definitions

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

;; (safe-fcall (#:identity #:cl-user) '#:s4312)

;; (safe-fcall (#:nop #:cl))

;; (safe-fcall (#:identity #:nop))

;; (safe-fcall (#:*standard-output* #:cl))

;; (safe-fcall (#:identity "CL-USER") '#:s4312)

;; (safe-fcall ("IDENTITY" "CL-USER") '#:s4312)

