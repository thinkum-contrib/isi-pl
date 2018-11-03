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


;;; Version: $Id: load-logic.lisp,v 1.29 2000/04/07 23:30:25 tar Exp $

;;; Compile and load the logic module.

;;; This is a (hopefully) temporary solution until we can
;;;    generate these load files automatically.

(in-package "STELLA")


;; THIS ENTIRE FILE IS OBSOLETE!!!
(CL:let* ((*rootSourceDirectory* "PL:sources;logic;")
          (*rootNativeDirectory* "PL:natives;logic;")
          (*rootBinaryDirectory* "PL:binaries;logic;"))
  (CL-USER::with-compilation-unit ()
    (cl-compile-and-load-file "logic-macros" FALSE)
    (cl-compile-and-load-file "stella-patches" FALSE)
    (startup-stella-patches)
    (cl-compile-and-load-file "sequence-indices" FALSE)
    (cl-compile-and-load-file "kif-in" FALSE)
    (cl-compile-and-load-file "propositions" FALSE)
    (cl-compile-and-load-file "backlinks" FALSE)
    (cl-compile-and-load-file "propagate" FALSE)
    (cl-compile-and-load-file "inference-caches" FALSE)
    (cl-compile-and-load-file "descriptions" FALSE)
    (cl-compile-and-load-file "normalize" FALSE)
    (cl-compile-and-load-file "rules" FALSE)
    (cl-compile-and-load-file "partial-match" FALSE)
    (cl-compile-and-load-file "machine-learning" FALSE)
    (cl-compile-and-load-file "rule-induction" FALSE)
    (cl-compile-and-load-file "neural-network" FALSE)
    (cl-compile-and-load-file "case-based" FALSE)
    (cl-compile-and-load-file "query" FALSE)
    (cl-compile-and-load-file "goal-caches" FALSE)
    (cl-compile-and-load-file "strategies" FALSE)
    (cl-compile-and-load-file "justifications" FALSE)
    (cl-compile-and-load-file "kif-out" FALSE)
    (cl-compile-and-load-file "print" FALSE)
    (cl-compile-and-load-file "generate" FALSE)
    (cl-compile-and-load-file "specialists" FALSE)
    (cl-compile-and-load-file "specialize" FALSE)
    (cl-compile-and-load-file "optimize" FALSE)
    (cl-compile-and-load-file "classify" FALSE)
    (cl-compile-and-load-file "logic-in" FALSE)
    (cl-compile-and-load-file "pl-kernel-kb" FALSE)
    (cl-compile-and-load-file "arithmetic" FALSE)
    (cl-compile-and-load-file "cyc-frame-kb" FALSE)
    (cl-compile-and-load-file "frame-support" FALSE)
    (cl-compile-and-load-file "loom-support" FALSE)
    (cl-compile-and-load-file "loom-to-kif" FALSE)
    (cl-compile-and-load-file "api-support" FALSE)
    (cl-compile-and-load-file "api" FALSE)
    (cl-compile-and-load-file "okbc" FALSE)
    (cl-compile-and-load-file "powerloom" FALSE)
    (startup-logic)
    (startup-kbs)
    ))
