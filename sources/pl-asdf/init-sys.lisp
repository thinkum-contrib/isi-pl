;; init-sy.lisp - system Definition Extensions for STELLA-INIT

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

;; -- Accessor functions

(defgeneric system-component-source-prefix (component)
  (:method ((component asdf:module))
    ;; Default method for non-PL ASDF modules and system definitions
    ;; Usage:
    ;; cf. ASDF/COMPONENT:COMPONENT-PATHNAME (STELLA-SOURCE-COMPONENT)
    ;; cf. STELLA-LISP-BOOTSTRAP-SYSTEM
    (component-pathname component)))

(defgeneric (setf system-component-source-prefix) (new-value component))

(defgeneric system-logical-pathname-host (component))
(defgeneric (setf system-logical-pathname-host) (new-value component))

(defgeneric system-logical-source-subdirs (component))
(defgeneric (setf system-logical-source-subdirs) (new-value component))

;; --

(defgeneric system-logical-source-root (component)
  (:method ((component system))
    (component-pathname component)))

;; -- System definition class & initialization

;; TBD: Define a more generalized class, such that STELLA-LISP-BOOTSTRAP-SYSTEM
;; would be defined as inheriting from, or define a more specialized
;; subclass of STELLA-LISP-BOOTSTRAP-SYSTEM singularly for purposes of STELLA-INIT
;; vis a vis, usage of ENSURE-PATHNAME-TRANSLATIONS

(defclass stella-lisp-bootstrap-system (asdf:system)
  ;; NB Representative of a STELLA implementation source system
  ;;    onto Common Lisp, with a statically defined ASDF system
  ;;
  ;; NB This represents, in effect, an abstract class.
  ;;    For usage in system definitions, refer to:
  ;;    - STELLA-LISP-CLOS-BOOTSTRAP-SYSTEM
  ;;    - STELLA-LISP-STRUCT-BOOTSTRAP-SYSTEM
  ((component-source-prefix
    ;; NB Note default initialization (effective initform) defined in
    ;; SHARED-INITIALIZE :AFTER (STELLA-LISP-BOOTSTRAP-SYSTEM T)
    ;;
    ;; This semantics could serve to support an arbitrary nesting of
    ;; prefix pathnames, across module specifications, if adopted in
    ;; an implememtation of a subclass of ASDF:MODULE. At present, this
    ;; has been used simply for locating the system definition's source
    ;; files in stella-init.asd
    ;;
    ;; See also:
    ;; ASDF/COMPONENT:COMPONENT-PATHNAME (STELLA-SOURCE-COMPONENT)
    ;; ASDF/COMPONENT:COMPONENT-PATHNAME (STELLA-CL-LIB-SOURCE-FILE)
    ;; #'PARSE-PREFIX-PATH
    ;;
    :initarg :component-source-prefix
    :type (or simple-string simple-base-string pathname)
    :reader %system-component-source-prefix
    :writer (setf system-component-source-prefix)
    :documentation
    "Prefix path for resolving source file components in this system
definition.

If specifying a relative pathname, this pathname should be resolved as
relative to the system definition's source directory. If unbound, this
slot's value may be interpreted as effectively NIL, as in the method
SYSTEM-COMPONENT-SOURCE-PREFIX (STELLA-LISP-BOOTSTRAP-SYSTEM) in which
case, the system definition's source directory may be used, without
prefix mapping, when resolving relative pathnames of system component
source files.

This value may be specified using a subset of logical pathname syntax,
such as in \"PL:sources;\". Any element in this pathname may be
interpreted as representing a filesystem directory, whether or not
suffixed with a semicolon character, \";\".")
   (logical-pathname-host
    :initarg :logical-pathname-host
    :type simple-string
    :reader %system-logical-pathname-host
    :writer (setf system-logical-pathname-host)
    :documentation
    "If bound, a simple string denoting a logical pathname host to be defined
for source and bytecode operations on the system definition.

See also:
ENSURE-SYSTEM-PATHNAME-TRANSLATIONS
COMPUTE-SOURCE-PATHNAME-TRANSLATIONS
COMPUTE-BYTECODE-PATHNAME-TRANSLATIONS
COMPUTE-DATA-PATHNAME-TRANSLATIONS
"
    )
   (logical-source-subdirs
    :initarg :logical-source-subdirs
    :type list
    :initform nil
    :accessor system-logical-source-subdirs
    ;; NB Somewhat a convenience, for the implementation of
    ;; COMPUTE-SOURCE-PATHNAME-TRANSLATIONS onto STELLA-LISP-BOOTSTRAP-SYSTEM
    )
  ))

;; TBD: Suitability of STELLA-LISP-BOOTSTRAP-SYSTEM for representing
;; STELLA systems subsequent of the initial STELLA eval. If directly
;; suitable as such, the class and subclasses should be renamed as to
;; remove the "bootstrap" infix token from the class' names.

(defclass stella-lisp-clos-bootstrap-system (stella-lisp-bootstrap-system)
  ;; FIXME: Before PERFORM, err if any system dependency
  ;;        is of type STELLA-LISP-STRUCT-BOOTSTRAP-SYSTEM
  ;;        - generalize as VALIDATE-DEPENDENT-SYSTEM (DEP SYSTEM)
  ;;
  ;; FIXME: During PERFORM, warn (style-warning) if #+stella-struct t
  ())

(defclass stella-lisp-struct-bootstrap-system (stella-lisp-bootstrap-system)
  ;; FIXME: Before PERFORM, err if any system dependency
  ;;        is of type STELLA-LISP-CLOS-BOOTSTRAP-SYSTEM
  ;;        - generalize as VALIDATE-DEPENDENT-SYSTEM (DEP SYSTEM)
  ;;
  ;; FIXME: During PERFORM, warn (style-warning) if #-stella-struct t
  ())

;; NB: Note methods onto ASDF/COMPONENT:MODULE-DEFAULT-COMPONENT-CLASS
;; defined in init-compo.lisp, specialized onto subclasses of
;; STELLA-LISP-BOOTSTRAP-SYSTEM

;; --

(defmethod system-component-source-prefix ((component stella-lisp-bootstrap-system))
  ;; => <slot-value-if-bound>, <boundp>
  (cond
    ((slot-boundp component 'component-source-prefix)
     (values (%system-component-source-prefix component)
             t))
    (t (values nil nil))))

(defmethod system-logical-pathname-host ((component stella-lisp-bootstrap-system))
  (cond
    ((slot-boundp component 'logical-pathname-host)
     (values (%system-logical-pathname-host component)
             t))
    (t (values nil nil))))

;; --

(defmethod shared-initialize :after ((instance stella-lisp-bootstrap-system)
                                     slots &rest initargs
                                     &key &allow-other-keys)
  (declare (ignore initargs))
  ;; NB Default slot-value initialization - effective slot initform in
  ;; shared-initialize for COMPONENT-SOURCE-PREFIX, initializing the
  ;; value by default from (SYSTEM-SOURCE-DIRECTORY INSTANCE) when non-nil

  (when
      (and (or (eq slots 't)
               (and (consp slots)
                    (find 'component-source-prefix (the cons slots)
                          :test #'eq)))
           (not (slot-boundp instance 'component-source-prefix)))
    (setf (system-component-source-prefix instance)
          ;; NB May break if the system definition's source directory
          ;; was not set previously, or if SYSTEM-SOURCE-DIRECTORY
          ;; otherwise returns NIL for the INSTANCE
          ;;
          ;; FIXME Somewhat less than optimal if this system is compiled
          ;; while #+SWANK t and subsequently loaded while #-SWANK t
          ;;
          ;; FIXME May not function as intended if this system is compiled
          ;; while #-SWANK t and subsequently loaded while #+SWANK t
          #-SWANK
          (asdf/system:system-source-directory instance)
          #+SWANK
          ;; Generalized usage case: System compiled or loaded from
          ;; source, within an interactive evaluation environment
          (let ((basep (asdf/system:system-source-directory instance)))
            (cond
              ((null basep)
               (warn "~<In SHARED-INITIALIZE :AFTER (STELLA-LISP-BOOTSTRAP-SYSTEM ...)~>~
~< : NULL SYSTEM-SOURCE-DIRECTORY for ~s (Interactive Eval?)~>~
~< - using *DEFAULT-PATHNAME-DEFAULTS* ~s~>"
                     instance *default-pathname-defaults*)
               (values *default-pathname-defaults*))
              ;; else
              (t (values basep)))))))

;; (system-component-source-prefix (find-system "stella-init"))
