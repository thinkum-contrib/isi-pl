;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                          ;
;  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   ; 
;  University of Southern California, Information Sciences Institute       ;
;  4676 Admiralty Way                                                      ;
;  Marina Del Rey, California 90292                                        ;
;                                                                          ;
;  This software was developed under the terms and conditions of Contract  ;
;  No. N00014-94-C-0245 between the Defense Advanced Research Projects     ;
;  Agency and the University of Southern California, Information Sciences  ; 
;  Institute.  Use and distribution of this software is further subject    ;
;  to the provisions of that contract and any other agreements developed   ;
;  between the user of the software and the University of Southern         ;
;  California, Information Sciences Institute.  It is supplied "AS IS",    ;
;  without any warranties of any kind.  It is furnished only on the basis  ;
;  that any party who receives it indemnifies and holds harmless the       ;
;  parties who furnish and originate it against any claims, demands, or    ;
;  liabilities connected with using it, furnishing it to others or         ;
;  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    ;
;  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  ;
;  BE ATTACHED TO EVERY PART.                                              ;
;                                                                          ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;; Version: translate-logic.lisp,v 1.25 1997/11/06 19:38:13 hans Exp

;;; Translate and load the logic subsystem

;;; This is a (hopefully) temporary solution until we can
;;;    generate these translation files automatically.

(in-package "STELLA")

(in-module "STELLA")


(defglobal *logic-system* (CONS OF STRING-WRAPPER)
  (bquote
   ("logic-macros"
    "kif-in"
    "propositions"
    "caches"
    "descriptions"
    "rules"
    "partial-match"
    "query"
    "kif-out"
    "print"
    "specialize"
    "optimize"
    "normalize"
    "logic-in"
    "api-support"
    "gfp"
    "api"
    "powerloom")))

(defglobal *stella-copyright-header* STRING *copyright-header*)

(defglobal *logic-loaded?* BOOLEAN
           (verbatim :common-lisp
             (not-cl-nil?
              (CL:fboundp 'startup-powerloom))))

(defun setup-logic-translation-features ()
  (setq *safety* 3)
  (disable-environment-feature
   :USE-BOOTSTRAP-TRANSLATOR
   :USE-HARDCODED-SYMBOLS)
  (enable-environment-feature
   :TRANSLATE-WITH-COPYRIGHT-HEADER
   :WARN-ABOUT-MISSING-METHODS
   :WARN-ABOUT-UNDEFINED-METHODS))

(defun bootstrap-logic ()
  (setup-logic-translation-features)
  (cl-translate-file "PL:sources;logic;logic-macros.ste")
  (cl-translate-file "PL:sources;logic;stella-patches.ste")
  (disable-environment-feature :warn-about-undefined-methods)
  (cl-translate-file "PL:sources;logic;powerloom.ste")
  (setup-logic-translation-features)
  (special ((*systemSourceDirectory* "PL:sources;logic;")
            (*systemBinaryDirectory* "PL:binaries;logic;"))
    (cl-compile-and-load-file "logic-macros")
    (cl-compile-and-load-file "stella-patches")
    (cl-compile-and-load-file "powerloom")))

(defun cl-make-logic ()
  (bootstrap-logic)
  (setup-logic-translation-features)
  (special ((*systemSourceDirectory* "PL:sources;logic;")
            (*systemBinaryDirectory* "PL:binaries;logic;"))
    (setq *copyright-header*
      (verbatim :common-lisp *powerloom-copyright-header*))
    (make-system *logic-system* (not *logic-loaded?*))
    (setq *copyright-header* *stella-copyright-header*)))

(startup-time-progn
  (unless *logic-loaded?*
    (cl-make-logic)
    (setq *logic-loaded?* TRUE)))

;;; More translation support:

(defun cl-translate-logic ()
  ;; Translate the logic subsystem to Common-Lisp.
  (setup-logic-translation-features)
  (setq *copyright-header*
    (verbatim :common-lisp *powerloom-copyright-header*))
  (special ((*systemSourceDirectory* "PL:sources;logic;"))
    (set-translator-output-language :COMMON-LISP)
    (simple-translate-system *logic-system* TRUE TRUE))
  (setq *copyright-header* *stella-copyright-header*))

(defun cl-translate-powerloom ()
  ;; Translate the complete PowerLoom system to Common-Lisp.
  (setq *copyright-header* *stella-copyright-header*)
  (cl-translate-stella)
  (cl-translate-logic))

(defun cpp-translate-logic ()
  ;; Translate the logic subsystem to C++.
  ;; This needs to be run in the logic/ directory.
  (setup-logic-translation-features)
  (setq *copyright-header*
    (verbatim :common-lisp *powerloom-copyright-header*))
  (special ((*systemSourceDirectory* ""))
    (set-translator-output-language :CPP)
    (simple-translate-system *logic-system* TRUE TRUE))
  ;;(cpp-output-includes-file)
  ;;(cpp-translate-boot-symbols)
  (setq *copyright-header* *stella-copyright-header*))

(defun cpp-translate-powerloom ()
  ;; Translate the complete PowerLoom system to C++.
  ;; Assumes we are running in the PowerLoom root directory.
  ;; NOTE: The logic must be defined before Stella gets translated
  ;;    to generate proper logic method signatures in Stella classes,
  ;;    so, to ensure that we translate the logic files first:
  (verbatim :common-lisp
    "#+ALLEGRO (excl:chdir \"logic/\") #-ALLEGRO CL:NIL")
  (cpp-translate-logic)
  (verbatim :common-lisp
    "#+ALLEGRO (excl:chdir \"../stella/\") #-ALLEGRO CL:NIL")
  (setq *copyright-header* *stella-copyright-header*)
  (cpp-translate-stella)
  (CL:delete-file "stella-includes.hh"))

(defun remove-translator-method-signatures ()
  ;; Remove method signatures for the C++, Java, and IDL translators
  ;;    from their owner classes.
  ;; This is a kludge to be able to translate a PowerLoom release
  ;;    that doesn't contain these translators without accidentally
  ;;    generating signatures of translator-specific methods in the
  ;;    translated hierarchy.ste.
  ;; If the translators were in separate modules, this would be
  ;;    a lot easier.
  ;; Modify all stringified sources, so the startup functions
  ;;    called below will redefine the method objects:
  (foreach method in (all-methods (get-module "STELLA" TRUE) TRUE)
      where (defined? (method-stringified-source method))
      do (setf (method-stringified-source method)
           (concatenate " " (method-stringified-source method))))
  (startup-cpp-translator FALSE)
  (startup-java-translator FALSE)
  (startup-idl-translator FALSE)
  (let ((methodsToRemove (new (LIST OF METHOD-SLOT))))
    ;; Collect the methods that were defined by the startup functions:
    (foreach method in (all-methods (get-module "STELLA" TRUE) TRUE)
        where (and (defined? (method-stringified-source method))
                   (not (eql? (nth (method-stringified-source method) 0)
                              #\Space)))
        collect method into methodsToRemove)
    ;; We have to do the removal in a separate step, otherwise, the
    ;;    iteration above gets disturbed by the destructive removal:
    (foreach method in methodsToRemove
        do (remove (class-local-slots
                    (type-class (slot-owner method)))
                   method)
           (unfinalize-class-slots (type-class (slot-owner method))))
    (finalize-classes-and-slots)))

(defun cpp-translate-powerloom-release ()
  ;; Translate a PowerLoom release to C++.
  (remove-translator-method-signatures)
  (cpp-translate-powerloom))
