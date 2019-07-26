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

(defgeneric system-component-source-prefix (component))
;; NB: See also STELLA-ASDF-SYSTEM [Class]
;;     slot COMPONENT-SOURCE-PREFIX

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

;; TBD: Define a more generalized class, such that STELLA-ASDF-SYSTEM
;; would be defined as inheriting from, or define a more specialized
;; subclass of STELLA-ASDF-SYSTEM singularly for purposes of STELLA-INIT
;; vis a vis, usage of ENSURE-PATHNAME-TRANSLATIONS

(defclass stella-asdf-system (asdf:system)
  ;; NB Representative of a STELLA implementation source system
  ;;    onto Common Lisp, with a statically defined ASDF system
  ;;
  ;; NB: Shared generalizations onto STELLA-SYSTEM/STELLA-SYSTEM-TEMPLATE
  ((component-source-prefix
    ;; see also: #'SPLIT-LOGICAL-PATH
      :initarg :component-source-prefix
      :type (or simple-string simple-base-string pathname)
      :reader %system-component-source-prefix
      :writer (setf system-component-source-prefix)
      ;; FIXME Consider integrating this with a STELLA-ASDF-MODULE
      ;; class, and subsequently, inheriting the same in
      ;; STELLA-ASDF-SYSTEM.
      ;;
      ;; Pathname resolution onto the COMPONENT-SOURCE-PREFIX value may
      ;; then proceed up-recursively, ending at the "Topmost" system
      ;; definition's prefix, in a merge onto (like as presently) the
      ;; system definition's own effective COMPONENT-PATHNAME.
      ;;
      ;; Pathname resolution for arbitrary output files - in some
      ;; instances, FASL files - may be implemented with a similar
      ;; component/pathname prefix/template/filename mechanism, pending
      ;; further consideration of the design of appropriate user,
      ;; system, and staging install oprns. In the user instance, it may
      ;; reuse the existing filename translation methods in ASDF,
      ;; without much specialization.
      ;;
      ;; This could serve to support an arbitrary nesting of
      ;; module/prefix specifications, juxtaposed to the essentially
      ;; flat filesystem namespace in this present implementation of
      ;; STELLA-ASDF-SYSTEM.
      :documentation
      "Prefix path for resolving source file components in this system
definition.

If specifying a relative pathname, this pathname should be resolved as
relative to the system definition's component pathname. If unbound, this
slot's value may be interpreted as effectively NIL, as in the method
SYSTEM-COMPONENT-SOURCE-PREFIX (STELLA-ASDF-SYSTEM) - in which case, the
system definition's component pathname should be used, without prefix
mapping, when resolving relative pathnames of system component source
files.

This value may be specified using a subset of logical pathname syntax,
such as in \"PL:sources;\". Any element in this pathname may be
interpreted as representing a filesystem directory, whether or not
suffixed with a semicolon character, \";\".")
   (logical-pathname-host
    :initarg :logical-pathname-host
    :type simple-string
    :accessor system-logical-pathname-host
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
    ;; COMPUTE-SOURCE-PATHNAME-TRANSLATIONS onto STELLA-ASDF-SYSTEM
    )
  ))


(defmethod system-component-source-prefix ((component stella-asdf-system))
  ;; => <slot-value-if-bound>, <boundp>
  (cond
    ((slot-boundp component 'component-source-prefix)
     (values (%system-component-source-prefix component)
             t))
    (t (values nil nil))))


(defmethod shared-initialize :after ((instance stella-asdf-system)
                                     slots &rest initargs
                                     &key &allow-other-keys)
  (declare (ignore initargs))
  ;; NB Default slot-value initialization - slot initform in
  ;; shared-initialize for COMPONENT-SOURCE-PREFIX

  (when
      (and (or (eq slots 't)
               (and (consp slots)
                    (find 'component-source-prefix (the cons slots)
                          :test #'eq)))
           (not (slot-boundp instance 'component-source-prefix)))
    (setf (system-component-source-prefix instance)
          ;; NB May break if the system definition's relative-pathname
          ;; was not set previously
          ;;
          ;; NB May break some calling functions if COMPONENT-PATHNAME
          ;; returns NIL
          #-SWANK
          (component-pathname instance)
          ;; So, towards supporting interactive defsystem eval e.g w/ Emacs
          #+SWANK
          (let ((basep (component-pathname instance)))
            (cond
              ((null basep)
               (warn "~<In SHARED-INITIALIZE :AFTER (STELLA-ASDF-SYSTEM ...)~> \
~<: NULL COMPONENT-PATHNAME for ~s (Interactive Eval?)~> \
~<- using *DEFAULT-PATHNAME-DEFAULTS* ~s~>"
                     instance *default-pathname-defaults*)
               (values *default-pathname-defaults*))
              ;; else
              (t (values basep)))))))

;; (system-component-source-prefix (find-system "stella-init"))


(defmethod asdf/component:module-default-component-class ((sys stella-asdf-system))
  ;; NB Specialization
  (find-class 'stella-lisp-source-file))

