;; init-pathname.lisp - pathname configuration utilities for STELLA-INIT

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


;; NB: The following two variables are unused at present. Refer to
;;   annotations in ENSURE-PATHNAME-TRANSLATIONS and elsewhere in this
;;   source system.
;;
;;   At this time, the lack of a "bin" pathname translation may in
;;   effect break portability onto some STELLA systems


#+NIL
(defconst +pl-asdf-cache-name+ "pl-asdf")
;; +pl-asdf-cache-name+ - remarks:
;;
;;  - Used, in the subsequent defvar, as the name of a subdirectory onto
;;    XDG DATA DIR. Subsequently, will be suffixed with a subdirectory
;;    denoting an implementation-specific pathname computed by
;;    ASDF. That pathname will then be used as a prefix pathname for
;;    output files produced with pl-asdf
;;
;;  - Used in ENSURE-PATHNAME-TRANSLATIONS, defined below
;;
;;  - May be of use elsewhere in pl-asdf (To Do: install-source-op)
;;
;;  - Denotes, in effect, a symbol used in computing a base pathname
;;    for ASDF operations onto the PL source tree and any subsequent
;;    output files, as may be produced directly with ASDF operations
;;    onto the source tree. Should be compatible across PL-ASDF system
;;    definitions, as such.
;;

;; FIXME Do not rely on [XDG] for filesystem hierarchy specification
;; - Provide option to produce output within prefix <LOCALBASE>/lib/<component>/<impl>/<build>/

#+NIL
(defvar *pl-asdf-output-cache*
  ;; cache dir for outpit files, onto the ASDF output file translations API
  ;;
  ;; e.g used by:
  ;;  ensure-pathname-translations
  ;;

  ;; NB UIOP/LISP-BUILD:*BASE-BUILD-DIRECTORY* [ASDF]

  ;; NB UIOP/LISP-BUILD:COMPILE-FILE-TYPE [ASDF' [Function]

  ;; NB UIOP/PATHNAME:*OUTPUT-TRANSLATION-FUNCTION* [ASDF]
  ;; - usage in UIOP/LISP-BUILD:COMPILE-FILE-PATHNAME* (No Op/Component state provided)

  ;; FIXME use in a method onto OUTPUT-FILES or similar
  (uiop/configuration:xdg-cache-home +pl-asdf-cache-name+ :implementation))




(defun ensure-pathname-translations (src-prefix)
  ;; FIXME Also write pathname translations as configuration data
  ;; under
  ;;   (A) COMPILE-OP - some subdir of [XDG CONFIG DIR] or
  ;;   (B) SYS-COMPILE-OP - some subdir of [SYSTEM CONFIG PREFIX] or
  ;;   (C) STAGE-COMPILE-OP - some subdir of [SYSTEM STAGING PREFIX]

  ;; Note also
  ;; ASDF/OUTPUT-TRANSLATIONS::*OUTPUT-TRANSLATIONS-FILE*
  ;; (can be lexically/specially bound w/i specialized OPERATE mtd)

  ;; define a set of logical pathanme translations in a manner that
  ;; should retain portability onto upstream PowerLOOM(r)
  ;;
  ;; referencing PL:translations.lisp,- NB `wild-version-value'
  ;; (May be addressed portably onto ASDF)
  ;;
  ;; NB:
  ;; - [FIXME] This, as yet, does not support any INSTALL-SOURCE-OP
  ;;
  ;; - [FIXME/TBD] Does not differentiate onto source systems, when
  ;;   computing the output translation path for the "bin" logical
  ;;   pathname (e.g "pl:bin;...") or for src. This could cause some
  ;;   concerns when generating STELLA implementation source code with
  ;;   the STELLA source translation API.
  ;;

  ;; NB These logical pathname translations may be used internally, in
  ;; STELLA systems, pursuant to software source code synthesis with
  ;; STELLA system definitions.
  ;;
  ;; See also, in translate-file.ste and subsq. implementation sources:
  ;;   stella::*rootSourceDirectory* - default, "PL:sources;"
  ;;   stella::*rootNativeDirectory* - default, "PL:native;"
  ;;   stella::*rootBinaryDirectory* - default, "PL:bin;"
  ;;   furthermore, STELLA function stella::system-definitions-directory
  ;;   such that uses, by default, the pathname "PL:sources;systems;"
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

             #+NIL ;; FIXME - This design choice needs further consideration
             (mk-asdf-bin-translate ()
               ;; NB ASDF UIOP/PATHNAME:*OUTPUT-TRANSLATION-FUNCTION*
               ;;    local value ASDF/OUTPUT-TRANSLATIONS:APPLY-OUTPUT-TRANSLATIONS
               ;;    used by UIOP/LISP-BUILD:COMPILE-FILE-PATHNAME*
               ;;      used by UIOP/LISP-BUILD:COMPILE-FILE-TYPE
               ;;       and sometimes by UIOP/LISP-BUILD:COMPILE-FILE*
               ;;           used by ASDF/LISP-ACTION:PERFORM-LISP-COMPILATION
               ;;                used by ASDF/ACTION:PERFORM (COMPILE-OP CL-SOURCE-FILE)
               ;; NB: Uses ASDF Class definitions insofar as pathname propertiess and dispatching for PERFORM
               (mk-template-translate "bin" *pl-asdf-output-cache*)))
  (setf (logical-pathname-translations "PL")
        (append
         (list
          (list "*.*.*" src-prefix-path) ;; ensure files in top src dir are accessible
          #+NIL
          (list (mk-subwild-logname "bin") (mk-asdf-bin-translate)))
         (mapcar #'(lambda (tok)
                          (list (mk-subwild-logname tok) (mk-src-translate tok)))
                 ;; NB This does not handle any install-source oprn [FIXME]
                 '("sources" "native" "kbs")))))))

;;; Inline test forms
;; (ensure-pathname-translations (component-pathname (find-system "stella-init")))
;; (probe-file "PL:sources;")
;; (probe-file "PL:stella-init.asd")


(defun initialize-system-pathname-translations ()
  (ensure-pathname-translations
   (asdf:component-pathname (asdf:find-system "stella-init"))))



