;; init-compo.lisp - Component Extensions for STELLA-INIT

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


;; -- More Protocol functions

(defgeneric proclamations-for (op component)
  ;; NB: Methods defined on this generic function may - in effect - be
  ;;     evaluated within the compilation environment.
  ;;
  ;; Usage: Used in PROCLAIM-FOR, subsequently in PERFORM-MAIN
  (:method ((op operation) (component source-file))
    (values nil)))


(defgeneric muffle-conditions-list (op component)
  ;; return a list of symbolic condition designators for conditions to
  ;; muffle in an environment of OP on COMPONENT
  ;;
  (:method ((op t) (component asdf:cl-source-file))
    ;; FIXME This list of conditions may seem to have been shadowed,
    ;; under some source configurations in SBCL, such as in which the
    ;; list is used within a HANDLER-BIND form in WITH-MUFFLING
    ;;
    ;; When using a PROCLAIM form specifying SB-EXT:MUFFLE-CONDITIONS
    ;; for this list of conditions, within PERFORM -- as below -- then
    ;; it does not seem to have been shadowed as such. Of course, then
    ;; the usage of WITH-MUFFLING is simply redundant.
    (values
     (append
      #+sbcl '(sb-ext:compiler-note

               sb-c:inlining-dependency-failure
               ;; ^ FIXME: Try not to muffle that style-warning
               ;;
               ;; Ensure that those functions are declared as inline, at
               ;; top level. Meanwhile, this serves to work around a
               ;; certain low-level bug as when a warning would be
               ;; produced about the unusable inline decl the sources,
               ;; when using SBCL. This bug may also occur when some
               ;; other warnings are produced, e.g when DEFGENERIC
               ;; shadows an FTYPE declaration. Seen with SBCL 1.5.2.8
               ;; and other versions not including 1.3.12

               ;;; NB Available in SBCL - unused since the source has
               ;;; been updated for the newer PRINT-BACKTRACE
               ;; sb-ext:early-deprecation-warning
               )
      (let* ((s (list (quote #:conditions)))
             (%s s))
        (dolist (spec uiop/lisp-build:*usual-uninteresting-conditions*
                 (cdr %s))
          (when (symbolp spec)
            (setf (cdr s) (list spec))
            (setq s (cdr s))))))))
  ;; TO DO ^ specialize onto LOAD-OP, COMPILE-OP
  ;; cf. ASDF *uninteresting-loader-conditions*, *uninteresting-compiler-conditions*

  (:method ((op t) (component asdf:system))
    ;; NB This might not be called when expected, if ASDF is not
    ;; producing recursive PERFORM calls
    (let ((proto (make-instance
                  (asdf/component:module-default-component-class component))))
      (muffle-conditions-list op proto))))

;; NB also
;; UIOP/LISP-BUILD:*UNINTERESTING-CONDITIONS*


;; -- Utility Macros

(defmacro with-muffling (s &body forms)
  ;; juxtaposed to UIOP/UTILITY:MATCH-ANY-CONDITION-P

  ;; NB: This emulates some behaviors of ASDF UIOP/UTILITY:CALL-WITH-MUFFLED-CONDITIONS
  ;;     though not towards specializing on a condition type designator, T
  ;;     and not with accessing any format-control objects of the
  ;;     respective conditions.

  (let ((cdn (make-symbol "%cdn"))
        (typ (make-symbol "%typ"))
        (types (make-symbol "%types")))
    `(let ((,types ,s))
       (declare (dynamic-extent ,types))
       (handler-bind ((warning (lambda (,cdn)
                                 (cond
                                   ((dolist (,typ ,types)
                                      (when (typep ,cdn ,typ) (return ,typ)))
                                    ;; (format *debug-io* "~%Muffle ~S" ,cdn)
                                    (muffle-warning ,cdn))
                                   (t
                                    ;;; NB: Does not always display the condition class:
                                    ;; (format *debug-io* "~%Do not muffle ~S" ,cdn)
                                    (warn ,cdn))))))
         ,@forms))))

;; Concerning a "certain bug" in SBCL - with SBCL 1.5.x and other versions -
;; part of the error outcome:
;;
;; #<SB-FORMAT::FMT-CONTROL "~@<Generic function
;; ~/SB-EXT:PRINT-SYMBOL-WITH-PREFIX/
;; clobbers an earlier ~S proclamation ~/SB-IMPL:PRINT-TYPE/ for the
;; same name with ~/SB-IMPL:PRINT-TYPE/.~:@>"> is not a string
;; designator.
;; ... during %WARN
;; ..... during SB-PCL::NOTE-GF-SIGNATURE
;; ....... during SB-PCL::REAL-ENSURE-GF-USING-CLASS--NULL
;;
;; So, perhaps something from SB-PCL DEFMETHOD is resulting in the
;; FMT-CONTROL being packed into that slot, mistakenly?
;;
;; .. at which, note "FORMAT control string best-effort sanity checker
;; and compactor" in SBCL sys:src;compiler;srctran.lisp
;;
;; NB: The error still occurs, even with SBCL built with
;;     (setq SB-C::*OPTIMIZE-FORMAT-STRINGS* nil)
;; in SBCL sys:src;compiler;srctran.lisp
;;
;; [Needs QA]


;; -- Generic Component Class Definitions, PERFORM Specializations, API

(defclass stella-component (asdf:component)
  ())


(defmethod proclamations-for ((op asdf:operation)
                              (component stella-component))
  (declare (ignore op component))
  (values *stella-compiler-optimization*))


(defclass stella-source-component (stella-component asdf:source-file)
  ())


(defmethod asdf/component:component-pathname ((component stella-source-component))
  ;; NB Integrate SYSTEM-COMPONENT-SOURCE-PREFIX
  (let* ((container (asdf/component:component-parent component))
         (cpath (component-pathname container))
         ;; NB Assumption: CONTAINER is a STELLA-ASDF-SYSTEM
         ;; (This feature of the API may be revised at a later time)
         (prefix (system-component-source-prefix container)))
    (cond
      (prefix
       (merge-pathnames (asdf/component:component-relative-pathname component)
                        (parse-prefix-path prefix cpath)))
      (t (call-next-method)))))


;; -- Components for the STELLA Lisp Implementation

(defclass stella-implementation-source-file (stella-source-component)
  ;; NB In subclass STELLA-LISP-SOURCE-FILE this obsoletes STELLA-LISP-SOURCE-COMPONENT

  () ;; TBD: Mapping to original *.ste sys defn, *.ste source file
  ;; NB: Integrate this class into the following
  ;;  - STELLA-LISP-SOURCE-FILE (TD: STELLA-SLISP-SOURCE-FILE)
  ;;  - STELLA-C++-SOURCE-FILE (NB: CPP-CODE and CPP-HEADER files w/ STELLA)
  ;;  - STELLA-JAVA-SOURCE-FILE (NB: Java Class defns)
  ;;  - STELLA-IDL-SOURCE-FILE (TBD)
  ;;
  ;; NB: Generic class, disjunct to STELLA-SOURCE-FILE (*.ste)
  ;;
  ;; TD: Document this API, in class and method signatures, w/
  ;; synopses (pl-asdf reference manual)
  )

(defclass stella-lisp-source-file (asdf:cl-source-file stella-implementation-source-file)
  ())

(defmethod asdf/component:source-file-type ((c stella-lisp-source-file)
                                            (container stella-asdf-system))
  (declare (ignore c container))
  ;; FIXME STELLA-STRUCT builds - needs [QA] w/ and w/o Emacs
  #+stella-struct
  (values "slisp")
  #-stella-struct
  (values "lisp"))

;; TD: output translations => fasl, sfasl (under impl subdir w/i output
;; component lib prefix) (NB: XDG-dirs adoption in devo w/ ASDF)


(defclass stella-cl-lib-source-file (stella-lisp-source-file)
  ;; FIXME suffix "cl-lib" dirname to an appropriate xdg/staging/system
  ;; prefix path dir, when calculating source files and output files
  ;;
  ;; FIXME also address STELLA cpp-lib. javalib sources (non-CL STELLA Impls)
  ;;
  ;; Note specifications in stella-system.ste for language-specific
  ;; source files, and STELLA::VERBATIM for inline specification of
  ;; language-specific  STELLA source forms
  ())

(defmethod asdf/component:component-pathname ((component stella-cl-lib-source-file))
  ;; NB Convenience method for computing the source pathname from a
  ;; specification of a STELLA cl-lib source file.
  ;;
  ;; Used in STELLA-INIT ASDF sysdef

  ;; FIXME this should be by-in-large portable onto STELLA cpp-lib and
  ;; javalib source components (May be revised subsequent of deriving
  ;; ASDF system definitions from STELLA system specifications)

  (let* ((container (asdf/component:component-parent component))
         ;; NB Assumption: CONTAINER is a STELLA-ASDF-SYSTEM
         ;; (This feature of the API may be revised at a later time)
         (src-type (asdf/component:source-file-type component container))
         ;; NB Assumption: Next-method is
         ;;   ASDF/COMPONENT:COMPONENT-PATHNAME (STELLA-SOURCE-COMPONENT)
         (notpath (call-next-method)))
    (merge-pathnames (make-pathname
                      :directory '(:relative "cl-lib")
                      :name (component-name component)
                      :type src-type
                      :defaults notpath)
                     notpath)))



;; -- Utility Macros

(defmacro proclaim-for (op component)
  ;; NB ASDF GET-OPTIMIZATION-SETTINGS
  (let ((procls (make-symbol "%procls")))
    `(let ((,procls (proclamations-for ,op ,component)))
       (when ,procls
         (proclaim ,procls)))))

(defmacro perform-main (pm-o pm-c)
  ;; NB - SBCL - Note remarks in MUFFLE-CONDITIONS-LIST src
  (let ((%pm-o (make-symbol "%pm-o"))
        (%pm-c (make-symbol "%pm-c")))
  `(with-compilation-unit ()
     ;; NB: This uses WITH-COMPILATION-UNIT and PROCLAIM in something of
     ;;     a runtime-dispatched analogy to LOCALLY - such that, albeit,
     ;;     may not be evaluated in exactly the same way as a LOCALLY
     ;;     form.
     ;;
     ;;    This extent of compiler tooling may not be, per se, well
     ;;    supported in CLtL2.
     (let ((,%pm-o ,pm-o)
           (,%pm-c ,pm-c))
       (proclaim-for ,%pm-o ,%pm-c)
       #+SBCL
       ;; FIXME - impl-specific workaround, for a purpose of ensuring
       ;; that the list of warning conditions may actually be muffled in
       ;; the compiler environment.
       (proclaim
        (list* 'sb-ext:muffle-conditions
               (muffle-conditions-list ,%pm-o ,%pm-c)))
       (with-muffling (muffle-conditions-list ,pm-o ,pm-c)
         (call-next-method))))))


;; - Perform methods

(defmethod asdf:perform ((o asdf:compile-op) (c stella-lisp-source-file))
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:PERFORM~< (ASDF:COMPILE-OP ~
STELLA-LISP-SOURCE-FILE)~>~< : (~A ~A)~>" o c)
  (perform-main o c))

(defmethod asdf:perform ((o asdf:load-op) (c stella-lisp-source-file))
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:PERFORM~< (ASDF:LOAD-OP ~
STELLA-LISP-SOURCE-FILE)~>~< : (~A ~A)~>" o c)
  (perform-main o c))

(defmethod asdf:perform ((o asdf:load-source-op) (c stella-lisp-source-file))
  #+PL-ASDF-DEBUG
  (format *debug-io* "~%ASDF:PERFORM~< (ASDF:LOAD-SOURCE-OP ~
STELLA-LISP-SOURCE-FILE)~>~< : (~A ~A)~>" o c)
  (perform-main o c))

