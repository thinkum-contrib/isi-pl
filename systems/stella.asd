;; stella.asd 						-*- lisp -*-

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
;; Sean Champ spchamp@users.noreply.github.com                                ;
;;                                                                            ;
;; Portions created by the Initial Developer are Copyright (C) 2015           ;
;; the Initial Developer. All Rights Reserved.                                ;
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

#|

# Synopsis

This system definition serves as providing an interface onto ASDF, for
evaluating the STELLA source system, as effectively defined in the
files

 * <PL:native;lisp;stella;load-stella.lisp>
 * <PL:native;lisp;stella;cl-lib;cl-setup.lisp> so far as some
   top-level forms that are, in effect, provided with ananalogous
   implementations in this system definition
 * <PL:native;lisp;stella;cl-lib;make-stella.lisp> so far as the
   effective system definition originally provided with PowerLOOM


# Synopsis (Previous)

This system definition provides a functionality analogous to the
procedures provided of load-stella.lisp. An outline of those
procedures:

1) Define compile-time configuration properties

- CL-USER::*LOAD-CL-STRUCT-STELLA?*
- Original definition location: <PL:load-stella.lisp>

- CL-USER::*LOAD-USE-STELLA-HASH-TABLES?*
- Original definition location: <PL:load-stella.lisp>

- Compiler optimization and compiler printout policies
- Forms affected:

- CL:OPTIMIZE declaration signature 
in CL-USER::*STELLA-COMPILER-OPTIMIZATION*

- CL-USER::*COMPILE-VERBOSE* [typically provided via CL package]

- CL-USER::*COMPILE-PRINT* [typically provided via CL package]

- CL-USER::*GC-VERBOSE* [CMUCL? - FIXME, verify source of this varaible]

- Original definition locations:

- <PL:load-stella.lisp> - forms specific to in CMUCL and SBCL,

- <PL:native;lisp;stella;load-stella.lisp>


2) Define runtime configuration properties

- Logical pathname translations, onto "PL" logical pathname host


3) Load the Common Lisp translation of the STELLA system 'stella'

- This STELLA system is defined in a Common Lisp translation
in the file <PL:native;lisp;stella;load-stella.lisp>

- contrast to C++ system translation as provided via the files
<PL:native;cpp;stella;Makefile>,
<PL:native;cpp;stella;stella-system.hh>, 
and other files under 'cpp;stella;' source branch

- contrast to Java system translation as provided via the files
<PL:native;java;edu;isi;stella;*.java> furthermore as
compiled (upstream) and packaged in the Java Zip archive
<PL:native;java;lib;stella.jar>

- Note also, <PL:sources;stella;idl-*.ste>,
<PL:native;**;idl-*.*>

- Observe that the file <PL:native;lisp;stella;load-stella.slisp>
provides an effective definition  source for the file
<PL:native;lisp;stella;load-stella.lisp>. See also:
TRANSFORM-OP, as provided in this system definition

# STELLA Systems

... *.ste source files ...

... pl:sources; and pl:native; ...

## STELLA Source File Pathnames - Common Lisp Transformation

The STELLA implementation in Common Lisp is defined in two distinct
sets of files, such that one of the sets of files must be selected as
per the value of CL-USER::*LOAD-CL-STRUCT-STELLA?*

In this system definition, the variable CL-USER::*LOAD-CL-STRUCT-STELLA?*  
is accompanied with the Common Lisp feature expression,
:STELLA-STRUCT. If :STELLA-STRUCT is defined as a Common Lisp feature
when this system definition "stella.asd" is evaluated, then:

1) the 'stella' system definition will be defined as to include the
component 'stella-system-structs' 

2) the method ASDF:SOURCE-FILE-TYPE (STELLA-LISP-FILE STELLA-SYSTEM-ASDF) 
will be defined as to ensure that the respective "*.slisp" files
will be selected for operations in ASDF

The selection of :STELLA-STRUCT should be consistent across any
single STELLA application.


FIXME: The *.ste source files ... Common Lisp ... STELLA KB modules ...

FIXME: Transformation of the *.ste source files ...  ??? 

## Functions - "Legacy" STELLA System Definitions (In Package: CL-USER)

*  STELLA-LOAD-SOURCE
*  STELLA-LOAD-LISP
*  STELLA-LOAD-TRANSLATED
*  STELLA-LOAD-BINARY

*  STELLA-C&L-SOURCE
*  STELLA-C&L-LISP
*  STELLA-C&L-TRANSLATED
*  STELLA-C&L-BINARY


# DOCUMENTATION

pl:sources;powerloom;doc;*.pdf

|#


;; FIXME: STELLA BOOTSTRAP (??)

(eval-when (:compile-toplevel :load-toplevel :execute)

  (let ((p (find-package '#:cl-user)))
    (dolist (s '(#:*load-cl-struct-stella?*
                 #:*stella-verbose?*
                 #:*source-truename* ;; [new]
                 #:*system-asdf* ;; [new]
                 ))
      (intern (symbol-name s) p)))
  
  (defpackage #:stella-system
    (:use #:asdf #:cl)

    #+CMUCL
    (:shadowing-import-from #:ext #:inhibit-warnings)
    #+SBCL
    (:shadowing-import-from #:sb-ext #:muffle-conditions #:inhibit-warnings)
    #+SBCL
    (:shadowing-import-from #:sb-kernel #:redefinition-warning)
    #+EXCL
    (:shadowing-import-from #:excl compiler-undefined-functions-called-warning)
    
    (:shadowing-import-from
     #:cl-user
     #:*load-cl-struct-stella?*
     #:*stella-verbose?*
     #:*source-truename*
     #:*system-asdf*
     ))

  #+NIL ;; e.g
  (pushnew :stella-struct *features*
           ;; ^ another way to represent
           ;; CL-USER::*load-cl-struct-stella?* => T
           ;; developed in this system definition
           :test #'eq)
  
  (unless (find-package "STELLA")
    ;; emulating forms defined in
    ;; file native/lisp/stella/cl-lib/cl-setup.lisp
    (defpackage "STELLA"
      (:use)
      (:intern
       #:with-redefinition-warnings-surpressed
       #:with-undefined-function-warnings-suppressed
       )
      (:shadowing-import-from
       #:CL
       #:SETQ #:SETF
       #:PRINT-OBJECT
       #:IN-PACKAGE #:EXPORT
       #:TRACE #:UNTRACE #:INSPECT
       #:apropos
       #+Allegro #:COMPILE
       #+Allegro #:EVAL-WHEN
       #+Allegro #:READTABLE
       )))
  
  ) ;; EVAL-WHEN


;; n.b
;;
;;   *STELLA-SOURCE-EXTENSION* =default=> ".ste" 
;;   *STELLA-TRANSLATED-EXTENSION*  =default=> ".lisp"

(in-package #:stella-system)


(defmacro setv (name value &optional docstring)
  `(cond
     ((boundp (quote ,name))
      ,@(when docstring `(progn (setf (documentation (quote ,name) 'variable)
                                      ,docstring)))
      (setq ,name ,value))
     (t
      (defvar ,name ,value ,@(when docstring (list docstring))))))

(defmacro mksys (name &rest args)
  ;; FIXME: STELLA::MAKE-SYSTEM may be useful in powerloom.asd
  ;; That *macro* is UNDEF when this system definition is evaluated
  ;;
  ;; As such, "This" -- or rather, the implementation form that this
  ;;    macro provides an effective "Wrapper" for, in this macro's
  ;;    macroexpansion environment -- thus, STELLA::MAKE-SYSTEM may be
  ;;    useful (??) in providing an ASDF system definition interface,
  ;;    in effect, "Onto", if not in all ways "alternate to" the
  ;;    original STELLA system definitions. In any single form, those
  ;;    system definitions may then be applied for generating the
  ;;    PowerLOOM system, in any single platform-specific
  ;;    representation language, i.e one or more of CLtL2, C++,
  ;;    Java. or (??) "IDL".
  ;;
  ;; See also:
  ;;
  ;; * macro definition body of STELLA::MAKE-SYSTEM
  ;;
  ;; ** esp. STELLA::*IGNORETRANSLATIONERRORS?* => FALSE
  ;;      and STELLA::CL-INCREMENTALLY-TRANSLATE for the
  ;;      call to STELLA::MAKE-SYSTEM
  ;;
  ;; *** thus, also STELLA::CONS-TREE-TO-LISP-CODE in
  ;;     <PL:native;lisp;stella;cl-lib;cl-primal.lisp> ... that
  ;;     function providing, in effect, an evaluative
  ;;     transformation from a manner of an abstract syntax tree -
  ;;     principally, a STELLA expression - with evaluation in Common
  ;;     Lisp. (Orthogonal - developer context: STELLA as an abstract
  ;;     syntax for term definitions, inference declarations, query
  ;;     declarations ... PowerLOOM, principally a system for
  ;;     evaluating and/or serializing STELLA expressions, in any
  ;;     single implementation environment.)
  ;;
  ;; * Source code remnants of "Previous efforts for reflection onto
  ;;   STELLA system definitions," in the GraniteLoom project.
  ;;
  ;; cf. <PL:native;lisp;stella;cl-lib;stella-to-cl.lisp>
  ;;
  
  ;; FIXME: Contrast, in documentation
  ;;
  ;; 1) *Common Lisp system defining the STELLA interpreter* (provided
  ;;    in this system definition -- here in an implementation onto
  ;;    ASDF -- alternate to/extensional after the original STELLA
  ;;    "Load" forms)
  ;;
  ;;    (principally, this may be applied in "providing a principal
  ;;    STELLA source generator," such that may be applied
  ;;    subsequently for generating any single platform-specific
  ;;    "STELLA representation language," in any of CLtL2, C++, Java,
  ;;    or (??) IDL))
  ;;
  ;; 2) *Common Lisp system[s] generated with the STELLA interpreter*
  ;;
  ;;    (principally, this may be applied towards "Providing a
  ;;    PowerLOOM system," as may be provided in any "Source asset
  ;;    bundle," such as may be generated for any single "Source asset
  ;;    language," when using the STELLA implementation in translation
  ;;    of the "PowerLOOM source code" from STELLA format to any
  ;;    single "Platform-specific representation language")
  ;;
  ;;    Concerning the second instance:
  ;;
  ;;    In a manner of a single "Platform-specific generation" for STELLA expressions
  ;;    -- principally, in a representation in CLtL2 language --
  ;;    furthermore, in a manner, "PowerLOOM in CLtL2" may be provided
  ;;    when this system definition is applied -- and successfully so
  ;;    -- applied ... as, procedurally, after evaluation of the
  ;;    "STELLA Sources" ... principally as would be evaluated in a
  ;;    CLtL2 implementation ... in a sense, the "PowerLOOM bootstrap"
  ;;    system .., then generating the source code for PowerLOOM in a
  ;;    CLtL2 representation ... "in this context" viz. ASDF "Load Op"
  ;;    or "Load Source Op" ... alternate to C++, Java, or "IDL'
  ;;
  ;;    Common Lisp, along with C++, Java, and a "Manner of IDL" (??)
  ;;    are among the "Possible source languages" for the generated
  ;;    STELLA/PowerLOOM "Platform-specific" codebase ... i.e STELLA
  ;;    representation ... as may be produced in any of CLtL2, C++,
  ;;    Java, or "IDL," ... as may be produced, procedurally, previous
  ;;    to "Linking" the "STELLA representation" into any single
  ;;    implementation system, whether in CLtL2, C++, Java, (??) CORBA
  ;;    environments, ... or in any extensional systems e.g in Python,
  ;;    Ruby, jQuery, ... see also: LLVM.
  ;;
  ;; NOTES:
  ;; STELLA::MAKE-SYSTEM is defined in <PL:native;lisp;stella;systems.lisp>
  ;;
  `(apply (fdefinition 'stella::make-system)
          ,name (quote ,args)))

(defclass stella-source-file (source-file)
  ;; intermediary source file
  ;; may be processed to generate a c++, java,
  ;; or lisp source file
  ;;
  ;; (FIXME: Translation is performed with what functions ?)
  ;;  ... STELLA::CL-INCREMENTALLY-TRANSLATE, ...
  ;;
  ;; (NOTE: <sources;**;*.ste> )
  ()
  (:default-initargs :type "ste"))

(defclass java-source-file (source-file)
  ()
  (:default-initargs :type "java"))

(defclass c-header-file (source-file)
  ()
  (:default-initargs :type "h"))

;; asdf:c-source-file - defined in ASDF upstream

(defclass c++-source-file (source-file)
  ()
  (:default-initargs :type "cc"))

(defclass makefile (source-file)
  ()
  ;; e.g. ./native/cpp/stella/cpp-lib/Makefile
  (:default-initargs :type nil))


(defclass powerloom-kb (source-file)
  ()
  (:default-initargs :type "plm"))


(defclass stella-sytem (system)
  ()
  (:default-initargs :type nil))


(deftype stella-language ()
  ;; cf. STELLA::%MAKE-SYSTEM - syntax tho?
  ;;
  ;; informative typedef

  ;; NB: The :common-lisp translation is furthermore affected as per
  ;; the value of CL-USER::*LOAD-CL-STRUCT-STELLA?* and the
  ;; corresponding feature expression :STELLA-STRUCT - see previous
  ;; notes 
  '(member :common-lisp :cpp :java))




(defclass stella-system-asdf (system)
  ;; TO DO: Rename this clasa
  ;;  => stella-lisp-system
  ;;
  ;; Subsequently, define a class, "Stella-System" onto which the
  ;; respective MKSYS calls would be evaluated
  ())




(defclass transform-op (operation)


  ;; [x] !! FIXME:
  ;;  1) PROVIDE A COMPLETE TRANSFORM-OP AND "TARGET PLATFORMS" MODEL
  ;;
  ;;     REFERENCE
  ;;
  ;;     TRANSFORMATION TARGET PLATFORMS:
  ;;          Common Lisp 
  ;;          C++
  ;;          Java
  ;;
  ;;     ... cf. STELLA-LANGUAGE type definition (above)
  ;;
  ;;     See also: ASDF 3
  ;;
  ;;  2) DOCUMENT THE [A] STRUCTURAL DEFINITION AND [B] THE `OPERATE'
  ;;     AND `PERFORM' PROCEDURES OF THE RESULTING `TRANSFORM-OP'
  ())


(defun impl-check ()
  ;; sourcing <PL:native;lisp;stella;cl-lib;cl-setup.lisp>
  ;;
  ;; Here, this is applied onto COMPILE-OP and LOAD-OP onto any
  ;; STELLA-SYSTEM-ASDF 
  (let ((len (integer-length most-positive-fixnum)))
  (unless (>= len 24) ;; use `eval' to avoid unreachable code warns
    (error "The maximum fixnum size of this lisp implementation ~
(~D)~%is too small.  It must be at least 24 bits."
	   len))))



(defmethod operate ((o transform-op) (c stella-system-asdf)
                    &key (production t) &allow-other-keys)
  ;; defined for operation on STELLA 'ste' files,
  ;; approximately as a "Quick Hack," however
  (mksys
   (component-name c)
   :force-translation? t
   :load-system? t
   (cond
     ;; FIXME: Document the 'production' keyword
     ;; cf. STELLA::MAKE-SYSTEM
     (production '(:production-settings? t
                   :developmen-settings? nil))
     (t '(:production-settings? nil
          :developmen-settings? tx)))))

(defmethod operate ((o load-op) (c stella-system-asdf)
                    &key &allow-other-keys)
  (impl-check)

  ;; defined for operation on STELLA 'ste' files,
  ;; approximately as a "Quick Hack," however

  ;; FIXME: FINALIZE DEFINITION
  ;;  - STELLA system definitions
  ;;  - PLATFORM MODEL
  ;;  - INTEGRATION WITH ASDF
  
  ;; FIXME: pathname handling
  ;;
  ;; FIXME: Provide a custom IN-ORDER-TO method ?

  ;; loads <...> then calls 'the system startup function" <...>
  ;;
  ;;; referring to docstriing of STELLA::MAKE-SYSTEM, STELLA::%MAKE-SYSTEM
  ;;(macroexpand (quote ;; DEBUG TMP
  (mksys (component-name c) :load-system? t)
  ;;))
  )


(defmethod operate ((o compile-op) (c stella-system-asdf)
                    &key &allow-other-keys)
  (impl-check)

  ;; defined for operation on STELLA 'ste' files,
  ;; approximately as a "Quick Hack," however

  ;; FIXME: FINALIZE DEFINITION
  
  ;; FIXME: pathname handling'
  ;;
  ;; FIXME: Provide a custom IN-ORDER-TO method ?

  ;; FIXME: What exactly is the diff between 'operate' and 'perform' in ASDF?
  
  ;; compiles <...>
  ;;
  ;; referring to docstriing of STELLA::MAKE-SYSTEM, STELLA::%MAKE-SYSTEM
  (mksys (component-name c)
         :load-system? nil
         :force-recompilation? t))

(defmacro stella::with-redefinition-warnings-suppressed
    (&body forms)
  ;; modified from <PL:native;lisp;stella;cl-lib;cl-setup.lisp>
  `(locally
       #+(or CMUCL SBCL)
       (declare
        #+CMUCL (optimize (inhibit-warnings 3))
        #+SBCL (muffle-conditions redefinition-warning))
       (handler-bind
           #-SBCL ()
           #+SBCL ((redefinition-warning #'muffle-warning))
           (let (#+:MCL(CCL::*WARN-IF-REDEFINE* CL:NIL)
                       #+:EXCL(EXCL::*REDEFINITION-WARNINGS* CL:NIL)
                       #+:LUCID(USER::*REDEFINITION-ACTION* CL:NIL)
                       #+:TI(TICL::INHIBIT-FDEFINE-WARNINGS CL:T)
                       #+:LISPWORKS(LISPWORKS::*REDEFINITION-ACTION* CL:NIL)
                       #+:CLISP(CLOS::*WARN-IF-GF-ALREADY-CALLED* CL:NIL)
                       #+:CLISP(CLOS::*GF-WARN-ON-REPLACING-METHOD* CL:NIL)
                       #+:CLISP(CUSTOM:*SUPPRESS-CHECK-REDEFINITION* CL:T)
                       )
             ,@forms))))

(defmacro stella::with-undefined-function-warnings-suppressed
    (&body forms)
  ;; modified from <PL:native;lisp;stella;cl-lib;cl-setup.lisp>
  `(locally
       #+(or CMUCL SBCL) (declare (optimize (inhibit-warnings 3)))
       (handler-bind 
           (#+EXCL
            (compiler-undefined-functions-called-warning #'muffle-warning)
            )
         (progn ,@forms))))


;; [new] (FIXME: DO not define here)

#+NIL_UTIL
(defun unwrap-literal (value) ;; UTIL
  ;; see also: stella::wrap-literal; |L| reader macro
  (declare (type stella::literal-wrapper value))
  (etypecase value
    (stella::string-wrapper (stella::unwrap-string value))
    (stella::integer-wrapper (stella::unwrap-integer value))
    (stella::long-integer-wrapper (stella::unwrap-long-integer value))
    (stella::float-wrapper (stella::unwrap-float value))
    (stella::boolean-wrapper (stella::unwrap-boolean value))
    (stella::character-wrapper (stella::unwrap-character value))))

#+NIL_UTIL
(defun unencapsulate-object (value)
  (declare (type (or stella::literal-wrapper
                     stella::list)
                 value))
  (etypecase value
    (stella::literal-wrapper (values (unwrap-literal value)))
    (stella::list (values (stella::%the-cons-list value)))))

(defclass stella-lisp-file (cl-source-file)
  ())

(defmethod source-file-type ((component stella-lisp-file)
                             (system stella-system-asdf))
  ;; sourcing <PL:native;lisp;stella;load-stella.lisp>
  #+:stella-struct
  (values "slisp")
  #-:stella-struct
  (values "lisp"))


(defvar *source-truename*) ;; FIXME [Hack]

(defvar *system-asdf*) ;; FIXME [Hack]

(defvar *stella-verbose?* (or *compile-verbose* *load-verbose*))

(defmethod perform :around ((o compile-op) (c stella-lisp-file))
  (let ((*compile-verbose* *stella-verbose?*)
        (*system-asdf* (component-system c)) ;; FIXME: Remove `*SYSTEM-ASDF*'?
        (*source-truename*
         (truename (component-pathname c))))
    (stella::with-redefinition-warnings-suppressed
      (stella::with-undefined-function-warnings-suppressed
        (call-next-method)))))

(defmethod perform :around ((o load-op) (c stella-lisp-file))
  (let ((*load-verbose* *stella-verbose?*)
        (*system-asdf* (component-system c)) ;; FIXME: Remove `*SYSTEM-ASDF*'?
        (*source-truename*
         (truename (component-pathname c))))
    (stella::with-redefinition-warnings-suppressed
      (stella::with-undefined-function-warnings-suppressed
        (call-next-method)))))



(defmethod perform :around ((op operation) (c stella-system-asdf))
  (let ((*system-asdf* c))
    ;; because ....
    
    ;; NB: PERFORM might not be applied recursively onto system components
    (call-next-method)))


(defsystem #:stella ;; xref: ./load-stella.lisp , ...
  :class stella-system-asdf
  :depends-on
  (#:usocket ;; portable sockets interface
   ;; ^ cf. socket handling in STELLA 
   ;; ^ see native/lisp/stella/cl-lib/cl-setup.lisp , ...
   ;; ^ #+Allegro, #+(And MCL (not OPENMCL)), #+Lispworks, #+SBCL

   #:bordeaux-threads ;; portable threads interface
   ;; ^ cf. process locks in STELLA
   ;; ^ see native/lisp/stella/cl-lib/cl-setup.lisp , ...
   ;; ^ #+Allegro, #+Lispworks #+MCL, #+CMUCL, #+SBCL
   )
  
  :perform
  (compile-op :before (o c)
              
              ;; [new] in COMPILE-OP :BEFORE
              #+stella-struct
              (setv *load-cl-struct-stella?* t)
              ;; ^ set CL-USER::*load-cl-struct-stella?*
              ;; per #+STELLA-STRUCT
              
              ) ;; :BEFORE COMPILE-OP

  ;; :perform
  ;; (compile-op :after (o c)
  ;;;; tmp. reflection onto STELLA system definitions - GraniteLoom early dev't
  ;;             (trace STELLA::DEFINE-SYSTEM)
  ;;             #+NIL (trace STELLA::%MAKE_SYSTEM))
  
  
  :perform
  (load-op :after (o c)
           (macrolet ((func (name pkg)
                        `(funcall (symbol-function
                                   (find-symbol ,(symbol-name name)
                                                (quote ,pkg))))))
             ;; convenience - emulating a top-level form defined in
             ;; <PL:native;lisp;stella;cl-lib;make-stella.lisp>
             (func #:startup-stella-system #:stella) 
             (func #:startup-stella-to-cl #:stella))

           ;; emulating a form defined in
           ;; file ./load-stella.lisp
           (when *stella-verbose?* 
             (format t "~&~a loaded.~%~
Type `(in-package \"STELLA\")' to execute STELLA commands."
                     (symbol-value (find-symbol
                                    (symbol-name '#:*stella-version-string*)
                                    '#:stella)))
             #+allegro ;; cf. STELLA Lisp dialect; Allegro Emacs FI
             (tpl:setq-default cl-user::*redefinition-warnings* nil)
             )) ;; :AFTER LOAD-OP

  :components
  ((stella-lisp-file "translations")
   ;; ^ Defines LPN translations - "PL:" + {sorces|native|bin|kbs} + ";" ...
   (:module
    "native"
    :depends-on ("translations")
    :pathname "native/lisp/stella"
    :serial t
    :components
    (#+TBD (stella-lisp-file "load-stella") ;; X !

     (:module "cl-lib"
              :serial t
              :components
              ((:file "cl-setup")
               #+NIL
               (:file "make-stella" ;; transposed to this system definition
                      :depends-on ("cl-setup"))))
     
     #+:stella-struct (stella-lisp-file "stella-system-structs") ;; [X] !!
     ;; following elements transposed from make-stella.lisp
     (stella-lisp-file "hierarchy")
     (stella-lisp-file "streams")
     (stella-lisp-file "taxonomies")
     (stella-lisp-file "primal")
     (stella-lisp-file "cl-primal" :pathname "cl-lib/cl-primal")
     (stella-lisp-file "startup")
     (stella-lisp-file "type-predicates")
     (stella-lisp-file "conses")
     (stella-lisp-file "lists")
     (stella-lisp-file "collections")
     (stella-lisp-file "iterators")
     (stella-lisp-file "symbols")
     ;; (stella-lisp-file "boot-symbols") ;; unused in original make-stella.lisp
     (stella-lisp-file "literals")
     (stella-lisp-file "classes")
     (stella-lisp-file "methods")
     (stella-lisp-file "defclass")
     (stella-lisp-file "date-time")
     (stella-lisp-file "date-time-parser")
     (stella-lisp-file "stella-in")
     (stella-lisp-file "foreach")
     (stella-lisp-file "walk")
     (stella-lisp-file "dynamic-slots")
     (stella-lisp-file "dynamic-literal-slots")
     (stella-lisp-file "cl-translate")
     (stella-lisp-file "macros")
     (stella-lisp-file "memoize")
     (stella-lisp-file "describe")
     (stella-lisp-file "demons")
     (stella-lisp-file "more-demons")
     (stella-lisp-file "name-utility")
     (stella-lisp-file "modules")
     (stella-lisp-file "contexts")
     (stella-lisp-file "read")
     (stella-lisp-file "xml") ;; [X]
     (stella-lisp-file "translate-file")
     (stella-lisp-file "systems")
     (stella-lisp-file "cl-translate-file")
     (stella-lisp-file "cpp-translate")
     (stella-lisp-file "cpp-translate-file")
     (stella-lisp-file "cpp-class-out")
     (stella-lisp-file "cpp-output")
     (stella-lisp-file "java-translate")
     (stella-lisp-file "java-translate-file")
     (stella-lisp-file "java-class-out")
     (stella-lisp-file "java-output")
     (stella-lisp-file "idl-translate")
     (stella-lisp-file "idl-translate-file")
     (stella-lisp-file "idl-class-out")
     (stella-lisp-file "idl-output")
     (stella-lisp-file "tools")
     (stella-lisp-file "stella-to-cl" :pathname "cl-lib/stella-to-cl")
     (stella-lisp-file "startup-system")
     ))
   ))
 
