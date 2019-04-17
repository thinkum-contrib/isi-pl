;; stella.asd - Extending ASDF onto PowerLOOM(r), STELLA runtime   -*- lisp -*-

;; NB May be renamed to stella-template.asd

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


(in-package #:cl-user)

;; NB PL impl source files
;;   native/lisp/powerloom/powerloom.lisp
;;   native/lisp/powerloom/startup-system.lisp
;;   and native/lisp/logic/*.lisp
;; subsq #'stella::powerloom (??)
;; or (stella::startup-powerloom-system)
;; and (in-module "STELLA") by default
;; cf. load-powerloom.lisp
;;
;; or (TBD side effects)
;; (stella::make-system "powerloom")
;; .. which needs an implementation of
;;    CL-USER::STELLA-NEED-TO-COMPILE? [Function]
;;    or a broader port/patch for PL-ASDF [FIXME]
;;
;; see also
;; - sources/systems/logic-system.ste
;;   and correspondingly sources/logic/*.ste
;;   - as towards native/lisp/logic/*.lisp
;;   - NB :lisp-only-files ("loom-api.lisp")
;; - sources/systems/powerloom.ste
;; * note that *.ste files can be evaluated, subsq of stella-init
;;   - see also: stella.asd
;;

;; *Concept* Constructing an ASDF sysdef for a STELLA system for which,
;;   Common Lisp implementation source code has already been produced.
;;
;; TBD subsq. concept: Producing an ASDF sysdef and implementation
;;   source files, using an extension to ASDF and PL STELLA

;; NB: load-logic.lisp not avl - refer to logic-system.ste for
;; information about corresponding STELLA (ste) and implememtation
;; (lisp, slisp, C++, Java) source filea.

;; TBD: ordering of language-specific source files onto each STELLA
;; system :files list
;;
;;   - Note, stella-system.ste overlays some :lisp-only-files within the
;;     system's :files list. (Those that are not listed e.g in
;;     make-stella.lisp may be loaded otherwise within the original
;;     load-stella.lisp process flow.) This system definition may be
;;     unique, as such. (TBD: Testing STELLA source synthesis with STELLA
;;     init in each of C++, Java, IDL)


;; NB in lieu of a system definition lib, extensional to ASDF,
;; the following should result in stella-init.asd being evaluated
;; as a Lisp source file
(eval-when (:compile-toplevel :load-toplevel :execute)
  (asdf:find-system "stella-init")
  )

(in-package #:stella-system)

;; NB some stella-init.asd code may be reused in stella.asd

#|

# Remarks

A STELLA system may be viewed as a correlation of four models
* A STELLA Source API, providing ...
* A STELLA Implementation API, in each of three supported programming
  languages -- principally, Common Lisp, C++, and Java


(TBD: IDL programming with STELLA and PL)


|#


(defclass stella-system (stella-asdf-system)
  ;; FIXME: Generalize STELLA-ASDF-SYSTEM
  ;; particularly, concerning handling for component-source-prefix
  ;; such that, in this instance, will map to a prefix for *.ste files
  ())

(defgeneric stella-system-name (sysdef)
  ;; NB: Providing a manner of abstraction with regards to
  ;; representation of STELLA source systems in ASDF
  ;;
  ;; NB Usage of the STELLA system name of a STELLA system, in this API,
  ;; should remain consistent across changes in revision to this API
  (:method ((sysdef stella-system))
    (component-name sysdef)))

(defgeneric find-implementation (language component))
;; LANGUAGE - trivial classifiers e.g
;;   :lisp :slisp :java :c++ :idl
;;   NB Variations in language definitions - C++11, ... Java subsq. of Generics, Annotations, ...
;;      ... and configuration specifiers for arbitrary build environments
;; COMPONENT - specialization e.g
;;  STELLA-SYSTEM
;;  STELLA-LISP-SYSTEM [TD]
;;  STELLA-SLISP-SYSTEM [TD] NB :slisp language classifier, stella-struct feature; STELLA uaage of *LOAD-CL-STRUCT-STELLA?*
;;  STELLA-C++-SYSTEM [TD
;;  STELLA-JAVA-SYSTEM [TD]
;;  STELLA-IDL-SYSTEM [TD]
;;
;;  STELLA-SOURCE-FILE
;;  STELLA-LISP-SOURCE-FILE
;;  STELLA-C++-SOURCE-FILE
;;  STELLA-JAVA-SOURCE-FILE
;;  STELLA-IDL-SOURCE-FILE
;;  * NB: STELLA cpp-lib. javalib files; STELLA cl-lib files & pathname inference
;;
;; TBD: sysdef configuration specifiers
;;  - feature specifiers
;;  - param/variable specifiers
;;  - 'NIX environment specifiers (insofar as entailing discrete build-time side effects)
;;
;; TD: SLIME/SWANK ext libs (Emacs & subsq)
;;
;;
;; (defgeneric find-implementations (component))
;; ^ for all of a well-known set of language classifiers
;; => various components
;;
;; (defgeneric find-implementation-source (component))
;; => *.ste component or stella system/template

(defmethod asdf/component:module-default-component-class ((sys stella-system))
  ;; NB Specialization of MODULE-DEFAULT-COMPONENT-CLASS
  ;;    juxtaposed to adding :DEFAULT-INITARGS to the class
  ;;    definition for STELLA-SYSTEM
  (find-class 'stella-source-file))

(defclass stella-source-file (stella-source-component)
  ;; i.e *.ste file
  ;;
  ;; NB juxtapose to *.plm files subsq. - e.g w/ powerloom-init.asd
  ;; and the PLI interpreter (as provided by the STELLA logic system
  ;; and extensionally, the powerloom system)
  ())

(defmethod asdf/component:source-file-type ((c stella-source-file)
                                            (container stella-system)
  (declare (ignore c container))
  (values "ste")))


;; Topic: System Definition Templates

;; - rel: System Definition Templates for interpretation of STELLA
;;   system definitions, with an API extensional to ASDF
;;
;; - rel: System Definition Templates for processing (configure, build,
;;   install, etc) of non-lisp source components, onto arbitrary
;;   software component frameworks


;; defclass stella-system-template [x]
;; ^ TBD generalization beside, or replacement of STELLA-SYSTEM
;;   - Concept, generically: A STELLA-SYSTEM-TEMPLATE represents a
;;      manner of binding for a STELLA system definition onto ASDF

;;; TBD Generic support for non-lisp source systems
;;; (needs a complete OS portability system + build configuration support)
;;
;;
;; defclass c++-source-system
;;
;; - NB Makefile (generalized to Make kinds, and generalized to
;; projects/components)  (closed onto a corresponding mk-files source
;; tree - NB bmake and MAKESYSPATH) as a system definition temlpate
;;
;;
;; defclass java-source-system
;;
;; - NB Ant/Maven/Gradle file (closed onto a corresponding
;; Ant/Maven/Gradle source tree) as a system definition temlpate
;;
;; - NB Java component tools; Ivy (ASF)
;;
;; - NB OSGi, servlet application environments
;;
;;
;; defclass idl-source-system
;; [...]
;; defclass sml-source-system (NB: Twelf; xduce)
;; defclass simula-source-system (NB: Participatory Design in Systems Modeling; VDM; MOF, UML, OCL)
;; [...]
;;
;;; ... and subsq. extension onto PL
;;
;; defclass stella-c++-system
;; - NB boehm GC & stella-system.ste => C++ src => build
;;   - TBD: CMake synthesis for STELLA C++ support
;; - NB STELLA cpp-*.ste, cpp-*.lisp, cpp-*.slisp
;;   - NB hard-coded name, "Makefile" [x]
;;     - TD: Parameterize makefile-name for reflection/interop support
;;     - NB Assumption: "Designed for GNU Make" (j/t bmake, ...)
;;
;;
;; defclass stella-java-system
;; - TBD castor.jar, castor-core.jae in PL SRC (PL SOAP?)
;; - NB commoms-logging.jar in PL SRC (PL SOAP?)
;;   - NB Java Servlet environments, PL SOAP
;; - ... and compoment frameworks, e.g pkgsrc
;; - NB pl:sources;stella;javalib;*.*
;; - NB STELLA JAR synthesis [x]
;;      - pl:native;java;edu;isi;powerloom;powerloom-meta.inf
;;      - pl:native;java;edu;isi;stella;stella-meta.inf
;;
;;
;; defclass stella-idl-system
;; - TBD @ FOSS for computing w/ the IDL language
