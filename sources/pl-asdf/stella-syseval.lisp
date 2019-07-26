
;; NB: STELLA system-related functional forms (systems.ste)
;;
;; DEFINE-SYSTEM ...
;; DEFSYSTEM ...
;; - Provides an alternate call form for DEFINE-SYSTEM
;; MAKE-SYSTEM ...
;; - presumably, at some point, loads a file that would call one of
;;   DEFSYSTEM or DEFINE-SYSTEM
;;
;; GET-SYSTEM-DEFINITION
;; - Note the internal call to MAKE-SYSTEM-DEFINITION-FILE-NAME
;;   ... such that operates onto #'STELLA::SYSTEM-DEFINITIONS-DIRECTORY
;;       ... such that operates onto one of:
;;           - STELLA::*SYSTEMDEFINITIONSDIRECTORY* if not a STELLA null string
;;           - (STELLA::CONCATENATE (STELLA::ROOT-SOURCE-DIRECTORY) "systems")
;;             ... such that operates on STELLA::*ROOTSOURCEDIRECTORY*
;;                 ... such that may be a logical pathname, in the PL
;;                     common lisp implementation
;;                     e.g as by default, "PL:sources;"
