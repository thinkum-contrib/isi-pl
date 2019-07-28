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




(defun compute-source-subpath-translations (src-prefix &optional subdirs)
  (declare  (type (or simple-string pathname) src-prefix))

  ;; FIXME Also write pathname translations as configuration data
  ;; storing the data in a trivially formatted file under
  ;;   (A) COMPILE-OP - some subdir of [XDG CONFIG DIR] or
  ;;   (B) SYS-COMPILE-OP (??) - some subdir of [SYSTEM CONFIG PREFIX] or
  ;;   (C) STAGE-COMPILE-OP (??) - some subdir of [SYSTEM STAGING PREFIX]

  ;; Note also
  ;; ASDF/OUTPUT-TRANSLATIONS::*OUTPUT-TRANSLATIONS-FILE*
  ;; (can be lexically/specially bound w/i specialized OPERATE mtd)

  ;; This function: Define a set of logical pathanme translations in a
  ;; manner that should retain portability onto upstream PowerLOOM(r)
  ;;
  ;; Referencing:
  ;; - PL:translations.lisp
  ;;   - NB `wild-version-value' may be addressed portably onto ASDF
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

  ;; NB, Topic: STELLA Systems -- STELLA System Definitions --
  ;; Pathnames in STELLA Systems // These logical pathname translations
  ;; may be used internally, in STELLA systems, pursuant to software
  ;; source code synthesis with STELLA system definitions (e.g
  ;; STELLA::MAKE-SYSTEM)
  ;;
  ;; See also, in translate-file.ste and subsq. implementation sources:
  ;;   stella::*rootSourceDirectory* - default, "PL:sources;"
  ;;   stella::*rootNativeDirectory* - default, "PL:native;"
  ;;   stella::*rootBinaryDirectory* - default, "PL:bin;"
  ;;
  ;;   ... such that may need to be set or mapped to a "non-default"
  ;;   value, for general purposes of source isolation (using e.g an
  ;;   INSTALL-OP onto ASDF) .. with such isolation being developed as
  ;;   to prevent unintended modification of local source changes, in
  ;;   local "native" sources, e.g by side effect of STELLA::MAKE-SYSTEM
  ;;
  ;;   furthermore, note STELLA function STELLA::SYSTEM-DEFINITIONS-DIRECTORY
  ;;   such -- in its Common Lisp implementation -- uses, by default,
  ;;   the logical pathname translation ofthe pathname "PL:sources;"
  ;;   suffixed with the namestring element "systems" as to represent -
  ;;   intrinsically - a filesystem directory, in local filesystem
  ;;   namestring syntax (assuming the value returned from
  ;;   TRANSLATE-LOGICAL-PATHNAME is suffixed with a pathname directory
  ;;   indicator)
  ;;   ... and is used in STELLA::MAKE-SYSTEM-DEFINITION-FILE-NAME
  ;;       ... which is used in STELLA::GET-SYSTEM-DEFINITION
  ;;
  ;; TBD, Topic: STELLA Systems -- General Concepts (STELLA System
  ;; Definitions and STELLA System Implementations; ...)
  ;;
  ;; TBD: Topic, STELLA Systems -- STELLA System Definitions (Note
  ;; subheading, denoted above)
  ;;
  ;; TBD, Topic: STELLA Systems -- STELLA System Implementations
  ;; - NB Topic, Generating STELLA Implementation Source
  ;;   - NB cf. MAKE-SYSTEM - source generation
  ;; - NB Topic, Evalutaing STELLA System Implementations - Common Lisp
  ;;   (with PL-ASDF), C++, Java(R)
  ;;   - NB cf. STELLA::LOAD-SYSTEM
  ;;   - NB cf. STELLA::MAKE-SYSTEM - compilation/loading for generated sources
  ;;   - NB: Makefiles in STELLA C++
  ;;   - NB: Class files in STELLA Java(R)
  ;;
  ;;   - NB: Compleat list of options accepted vis. STELLA::DEFSYSTEM
  ;;         - Refer to STELLA source code for STELLA::DEFINE-SYSTEM
  ;;         - :banner, ...
  ;;         - pathnames
  ;;         - language-specific source files (Common Lisp, C++, Java)
  ;;         - :data-files
  ;;         - :preprocessed-files (e.g in CL, C++ w/ STELLA logic-system.ste)
  ;;
  ;;   - NB: Sytnax of STELLA::DEFUN, and examples vis a vis CL:DEFMACRO
  ;;         - Refer to STELLA source code for STELLA::DEFSYSTEM
  ;;           -  i.e ':command? TRUE :evaluate-arguments? FALSE :public? TRUE'
  ;;           - juxtaposed to the STELLA source form definition of
  ;;             STELLA::DEFINE-SYSTEM

  (assert (probe-file src-prefix) (src-prefix)
          ;; NB: This does not test whether each of SUBDIRS exists
          "Prefix pathname does not exist: ~s" src-prefix)

  (let ((src-prefix-path (pathname src-prefix))
        (wild-version (pathname-version uiop/pathname:*wild-file*)))
    (labels ((mk-subdir-logical-pathname (subdir)
               (format nil "~a;**;*.*.*" subdir))
             (mk-template-translate (subdir base)
               ;; NB: Using portable pathname forms from ASDF, at runtime,
               ;;     to ensure portability across CLtL2 implementations
               (let ((stub (make-pathname
                            :directory (list :relative subdir
                                             uiop/pathname::*wild-inferiors-component*)
                            :name uiop/pathname:*wild*
                            :type uiop/pathname:*wild*
                            :version wild-version
                            :defaults base)))
                 (merge-pathnames stub base)))
             (mk-subdir-translation (subdir)
               (mk-template-translate subdir src-prefix-path))

             #+NIL ;; FIXME - This design choice needs further consideration
             ;; as to define a pathname translation for "pl:bin;"
             ;; in a manner interoperable with ASDF ouptut pathname translations
             (mk-asdf-bin-translate ()
               ;; NB ASDF UIOP/PATHNAME:*OUTPUT-TRANSLATION-FUNCTION*
               ;;    local value ASDF/OUTPUT-TRANSLATIONS:APPLY-OUTPUT-TRANSLATIONS
               ;;    used by UIOP/LISP-BUILD:COMPILE-FILE-PATHNAME*
               ;;      used by UIOP/LISP-BUILD:COMPILE-FILE-TYPE
               ;;       and sometimes by UIOP/LISP-BUILD:COMPILE-FILE*
               ;;           used by ASDF/LISP-ACTION:PERFORM-LISP-COMPILATION
               ;;                used by ASDF/ACTION:PERFORM (COMPILE-OP CL-SOURCE-FILE)
               ;;                and presumably, elsewhere in ASDF
               ;;
               ;; TBD: FASL staging prefix - configuration during
               ;; OPERATE for COMPILE-OP, LOAD-OP and PL ASDF INSTALL-OP 
               ;; w/ interop. for ASDF output pathname translation, "there."
               ;; - Classess STAGED-COMPILE-OP, STAGED-LOAD-OP,
               ;;   and method specialization for PERFORM
               ;; - Class INSTALL-OP and subsq.xs
               ;; - Application management tooling (LTP)
               ;;
               ;; See also [DOCU]:
               ;; - SYSTEM-COMPONENT-SOURCE-PREFIX
               ;;   specialized onto STELLA-ADSF-SYSTEM
               ;; - STELLA-LISP-BOOTSTRAP-SYSTEM [Class]
               ;;   slot COMPONENT-SOURCE-PREFIX
               ;; - stella-init.asd (Usage)
               ;;
               (mk-template-translate "bin" *pl-asdf-output-cache*)))

      (cons
       (list "*.*.*" (make-pathname
                      :name uiop/pathname:*wild*
                      :type uiop/pathname:*wild*
                      :version wild-version
                      :defaults src-prefix-path))
       #+NIL ;; NB Something of a "Design Artifact," by now
       (list (mk-subdir-logical-pathname "bin") (mk-asdf-bin-translate))
       (when subdirs
         (mapcar #'(lambda (subdir)
                     (list (mk-subdir-logical-pathname subdir)
                           (mk-subdir-translation subdir)))
                 subdirs))))))


(defgeneric compute-source-pathname-translations (operation system)
  (:method ((operation operation) (system system))
    (declare (ignore operation system))
    (values nil))
  (:method ((operation operation) (system stella-lisp-bootstrap-system))
    (compute-source-subpath-translations
     (system-logical-source-root system)
     ;; NB This does not handle any install-source oprn [FIXME]
     ;;
     ;; NB This does not include mappings onto the 'htdocs',
     ;; contrib 'doc' or load-stella.lisp 'bin' pathname
     ;;
     ;; FIXME: Update to provide a translation for pl:bin;
     ;; as interoperable with ASDF output pathname
     ;; translations
     (system-logical-source-subdirs system))))

(defgeneric compute-bytecode-pathname-translations (operation system)
  ;; NB See also, ENSURE-SYSTEM-PATHNAME-TRANSLATIONS
  (:method ((operation operation) (system system))
    (declare (ignore operation system))
    (values nil)))

(defgeneric compute-data-pathname-translations (operation system)
  ;; NB See also, ENSURE-SYSTEM-PATHNAME-TRANSLATIONS
  (:method ((operation operation) (system system))
    (declare (ignore operation system))
    (values nil)))

(defgeneric ensure-system-pathname-translations (operation system)
  ;; FIXME/DOCU - note where this is used
  ;; - refer to source file ./init-sys.lisp
  ;;   macro, SYSTEM-EVAL-MAIN, and methods onto ASDF:OPERATE in which
  ;;   that macro is evaluated
  ;;
  ;; NB: As such, this will be evaluated for every instance of a
  ;; STELLA-LISP-BOOTSTRAP-SYSTEM during any LOAD-OP, LOAD-SOURCE-OP or
  ;; COMPILE-OP with ASDF - as per definitions in init-sys.lisp
  ;;

  (:method ((operation operation) (system stella-lisp-bootstrap-system))
    ;; NB: This method will not destructively modify any existing
    ;; logical pathname translations onto the system logical pathname host.
    (let ((host (system-logical-pathname-host system)))
      (when (and host
                 (null (ignore-errors (logical-pathname-translations host))))
        (setf (logical-pathname-translations host)
              (append
               (compute-source-pathname-translations operation system)
               (compute-bytecode-pathname-translations operation system)
               (compute-data-pathname-translations operation system)
               )))
      )))


;;; Inline test forms
#+NIL
(eval-when ()
  (compute-source-pathname-translations
   (component-pathname (find-system "stella-init-system"))
   '("frob"))

  (compute-source-pathname-translations "DNW")


  (setf (logical-pathname-translations "PL") nil)

  (asdf:operarte 'asdf:load-op '#:stella-init)
  (probe-file "PL:sources;")
  (probe-file "PL:sources;systems;stella-system.ste")
  (probe-file "PL:stella-init.asd")
  (probe-file "PL:")
  (probe-file "PL:doc;") ;; DNW NB
  )


;; --

;; FIXME The function CL-USER::STELLA-NEED-TO-COMPILE?
;; is referenced in STELLA implementation source files
;; pl:**;cl-translate-file.lisp
;;
;; This function may need a portable implementation for PL-ASDF.
;;
;; The function is referenced within the STELLA implementation source
;; for the Common Lisp function, STELLA::CL-COMPILE-AND-LOAD-FILES
;; such that is used, in turn, from STELLA::COMPILE-AND-LOAD-FILES
;; such that, in itself, is used from within a number of STELLA
;; functions for STELLA system management, e.g
;; STELLA::LOAD-PREPROCESSED-FILES, STELLA::%LOAD-SYSTEM, ...
;;
;; Note that both of a source pathname and bytecode pathnme are provided
;; to STELLA-NEED-TO-COMPILE?
;;
;; Ideally, the function may be left undefined and unreferenced, for
;; STELLA sources evaluated using PL-ASDF

;; FIXME: This system definition extension needs to provide suitable
;; output translations, at least insofar as for supporting STELLA
;; implementation synthesis via PL-ASDF. This facility must be made to
;; interopate, somehow, towards a definition of STELLA-NEED-TO-COMPILE?
