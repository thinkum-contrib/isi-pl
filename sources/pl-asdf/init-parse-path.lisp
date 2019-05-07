;; init-parse-path.lisp - Quasi-Logical Pathnames for STELLA-INIT

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
