;; stella-init.asd - Extending ASDF onto PowerLOOM(r), early init  -*- lisp -*-

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

;; NB: This system definition, in effect, is defined for a purpose of
;; loading PL STELLA in a Common Lisp implementation, using ASDF. This
;; does not assume that any PL STELLA implementation would be, as yet,
;; available in the running Common Lisp implementation.
;;
;;
;; At present, this system definition supports only the set of STELLA
;; Common Lisp implementation source files produced for the usage case
;; of CL-USER::*LOAD-VECTOR-STRUCT-STELLA?* and
;; CL-USER::*LOAD-CL-STRUCT-STELLA?* both NIL - as per the behaviors
;; of the original load-stella.lisp.
;;
;; As such, a couple of further caveats:
;;
;; - This system - in effect - uses the CLOS implementation of STELLA
;;   in Common Lisp.
;;
;; - This assumes that a set of STELLA implementation source files have
;;   been generated such as to be locally available for the CLOS
;;   implementation of STELLA in Common Lisp. Such source files would be
;;   available with the orginal PL source distribution.
;;
;;
;; This system definition, in effect, represents the STELLA system
;; defined in pl:sources;systems;stella-system.ste  i.e the STELLA
;; system definition represenging the STELLA system.
;;
;; This system definition, as well as the stella-init-system system
;; definition used in this system definition, were both defined after
;; the behaviors of the original load-stella.lisp, subsequently adapted
;; for intepoerability with ASDF. Although this is believed to reprsent
;; the original stella-system.ste STELLA system, it has not yet been
;; tested with any STELLA implementation system locally generated from
;; that STELLA source system definition.
;;
;; Pursuant towards supporting development with other STELLA
;; implemetnations, this systeam definition simply uses the
;; STELLA CLOS implementation source files -- as available with the
;; original ISI PL source distribution, subsequently patched for
;; purposes of interoperability, testing, and general development, in
;; the contrib source repository.
;;
;;
;; Pursuant of successfully loading the stella-init system with ASDF,
;; it should be possible to locally produce any updated STELLA
;; implementation source system -- i.e in any of the Common Lisp, C++,
;; or Java STELLA implementation kinds -- using a locally available
;; STELLA system definition such as in stella-system.ste. Ideally, ASDF
;; may be used throughout this generalized process, in a manner
;; principally beginning with the STELLA CLOS Common Lisp implementation.
;;
;;
;; This system definition, together with the dependent system definition
;; in stella-init-system.asd, may serve to represent a manner of a
;; bootstrap component for development with STELLA in Common Lisp
;; environments. This, in a manner, reuses the portable Common Lisp
;; source and bytecode  management facilities provided with ASDF.
;;
;; As well as supporting generalized development processes with PL
;; STELLA, itself, this system definition should also serve towards the
;; specific usage case of loading the PL PowerLoom system, for
;; development with ISI PowerLoom(R)
;;


(eval-when (:compile-toplevel :load-toplevel :execute)
  ;; Load the STELLA-INIT-SYSTEM support code, so as to permit evaluation
  ;; of the subsequent system definition
  ;;
  ;; NB/Ports: STELLA-INIT-SYSTEM represents a build-dep here
  (unless (asdf:find-system "stella-init-system" nil)
    (labels ((stwarn (msg &rest args)
               (warn 'asdf::simple-style-warning
                     :format-control msg
                     :format-arguments args)))

      ;; FIXME: This will need some adjusting, for installation to host
      ;; system and staging pathnames

      ;; The PL-ASDF source code has been moved out of this system
      ;; definition file and into the following source subtree, in the
      ;; interest of ensuring modularity of the source code for this
      ;; system definition extension.
      (let* ((pfx (or *load-truename*
                      *compile-file-pathname*
                      *default-pathname-defaults*
                      (error "Unable to compute a prefix pathname")))
             (p (merge-pathnames (make-pathname
                                  :directory '(:relative "sources" "pl-asdf")
                                  :name "stella-init-system"
                                  :type "asd"
                                  :defaults pfx)
                                 pfx))
             (f (probe-file p)))
        (cond
          (f
           (stwarn "Load system definition for stella-init-system from ~S" f)
           (load f)
           (stwarn "Load system stella-init-system")
           (asdf:operate 'asdf:load-op '#:stella-init-system))
          (t (error "Unable to locate system definition source file ~
~<sources;pl-asdf;stella-init-system.asd~>")))))))


(in-package #:stella-system)

;; FIXME - Move the following remarks into stand-alone
;; documentation.
;;
;; There's been no better location for retaining these remarks, now that
;; the system definition sources have been moved into the pl-asdf subtree

;; --

;; NB: The PL-ASDF systems may not, at this time, provide a complete
;; compatibility interface onto the original
;;   pl:sources;stella;load-stella.lisp
;; and
;;   pl:sources;stella;cl-lib;make-stella.lisp
;; but should be usable, portably, onto ASDF




;; -- STELLA-INIT System Definition


;; The following is partially referenced onto the STELLA system source
;; file, pl:sources;stella;cl-lib;make-stella.lisp
;;
;; That file will be denoted, below, as the original make-stella.lisp


;; Remark - when editing STELLA source code
;;
;; When STELLA implementation source files are rebuilt for the
;; STELLA implementation in Common Lisp, then at that time, the
;; original make-stella.lisp may be copied to e.g
;;    pl:native/lisp/stella/cl-lib/make-stella.lisp
;; if not also
;;    pl:native/lisp/stella/cl-lib/make-stella.slisp
;; thus overwriting any local edits in the corresponding implementation
;; source file.
;;
;; Ideally, this may be prevented by using an appropriate output
;; prefix for any MAKE-STELLA calls - whether configured via logical
;; pathname translations or otherwie.
;;
;; Presently, this concern has been be addressed with an application of
;; changeset management onto the implementation source code.


(defsystem #:stella-init
  :class stella-asdf-system

  :defsystem-depends-on (#:stella-init-system)
  ;; ^ NB: Also note the top-level form at the beginning of this source fike

  ;; NB The following ordered set of filenames is retained from the file
  ;; pl:sources;stella;cl-lib;make-stella.lisp
  ;;
  ;; Notably, the order of the list of filenames in the original
  ;; make-stella.lisp differs to that specified in the STELLA system
  ;; definition for STELLA, i.e pl:sources;systems;stella-system.ste
  ;; Ideally, one of those may be merged into the other, if they
  ;; are not now source-wise incompatible.
  ;;
  ;; This code assumes that the form in make-stella.lisp may be more
  ;; up-to-date in relation to the STELLA source code. Secondly, it may
  ;; be more effective to use the make-stella.lisp ordering, when
  ;; initially loading the STELLA implementatiom source code in Common
  ;; Lisp.
  ;;
  ;; The ordering provided in stella-system.ste may be tested for
  ;; compatibility, once this contributed source code may pemit for
  ;; generation of ASDF system definitions in evaluation of STELLA
  ;; system definitions.

  ;; NB: Both the implementation source code (Lisp) and original source
  ;; code (STELLA w/ Lisp library) have been partially modified in this
  ;; contributed source code, such as to ensure portability for source
  ;; management with PL-ASDF and without PL-ASDF.
  ;;
  ;; For that purpose, the feature symbol :PL-ASDF has be used in some
  ;; read-time conditional expressions, as -- in effect - patched onto
  ;; the STELLA Common Lisp implementation source code. This symbol may
  ;; also be used within verbatim/literal expressions in the original
  ;; STELLA source code, and in the original STELLA cl-lib sources
  ;;
  ;; Furthermote, the symbol may be used in read-time conditional
  ;; expressions, such as to prevent initialization of the STELLA
  ;; system, when evaluating individual STELLA source files during
  ;; compilation. Considering that this initialization would be
  ;; performed -- specificlaly, for the STELLA system -- if only when
  ;; the source file load-stella.lisp is evaluated, it may not be
  ;; needed for such application, in this specific system.


  ;; The STELLA system should be initialized, automatically, after the
  ;; STELLA-INIT system definition has been loded from FASL, loaded from
  ;; source, or compiled from source. This would be accomplished by way
  ;; of the following :PERFORM methods defined onto this system
  ;; definition.

  ;; cf. source files
  ;;       pl:sources;stella;cl-lib;make-stella.lisp
  ;;       pl:native;lisp;stella;cl-lib;make-stella.lisp

  :perform (load-op :after (op c)
                    (safe-fcall (#:startup-stella-system #:stella))
                    (safe-fcall (#:startup-stella-to-cl #:stella)))
  :perform (load-source-op :after (op c)
                           (safe-fcall (#:startup-stella-system #:stella))
                           (safe-fcall (#:startup-stella-to-cl #:stella)))

  :serial t

  ;;; NB use all of the following files as under native/lisp/stella/
  ;;; using a portable pathname syntax in the system definition
  :component-source-prefix "native;lisp;stella;"

  ;; configuration for ENSURE-SYSTEM-PATHNAME-TRANSLATIONS
  :logical-pathname-host "PL"
  :logical-source-subdirs ("sources" "native" "kbs")

  ;; FIXME note the section in sources/stella/cl-lib/cl-setup.lisp
  ;; where "Load support libraries for TCP/IP"
  ;;
  ;; - Update this system for portability @ TCP/IP - STELLA::%%OPEN-NETWORK-STREAM
  ;; - Also note the section, "Synchronization Support," in cl-setup.lisp
  ;; - Furthermore, the local addition of CL-USER::*STELLA-DEFAULT-EXTERNAL-FORMAT*
  :depends-on
  (#+SBCL :SB-BSD-SOCKETS)

  ;; NB: load-stella is not used in this system
  ;; but will be declared during eval of stella-system.ste

  :components
  ((stella-cl-lib-source-file "cl-setup")
   #+stella-struct (:file "stella-system-structs")
   (:file "hierarchy")
   (:file "streams")
   (:file "taxonomies")
   (:file "primal")
   (stella-cl-lib-source-file "cl-primal")
   (:file "startup")
   (:file "type-predicates")
   (:file "conses")
   (:file "lists")
   (:file "collections")
   (:file "iterators")
   (:file "symbols")
   ;;  (:file "boot-symbols") ;; may be obsolete
   (:file "literals")
   (:file "classes")
   (:file "methods")
   (:file "defclass")
   (:file "date-time")
   (:file "date-time-parser")
   (:file "stella-in")
   (:file "foreach")
   (:file "walk")
   (:file "dynamic-slots")
   (:file "dynamic-literal-slots")
   (:file "cl-translate")
   (:file "macros")
   (:file "memoize")
   (:file "describe")
   (:file "demons")
   (:file "more-demons")
   (:file "name-utility")
   (:file "modules")
   (:file "contexts")
   (:file "read")
   (:file "xml")
   (:file "translate-file")
   (:file "systems")
   (:file "cl-translate-file")
   (:file "cpp-translate")
   (:file "cpp-translate-file")
   (:file "cpp-class-out")
   (:file "cpp-output")
   (:file "java-translate")
   (:file "java-translate-file")
   (:file "java-class-out")
   (:file "java-output")
   (:file "idl-translate")
   (:file "idl-translate-file")
   (:file "idl-class-out")
   (:file "idl-output")
   (:file "tools")
   (stella-cl-lib-source-file "stella-to-cl")
   (:file "startup-system")
   ))

