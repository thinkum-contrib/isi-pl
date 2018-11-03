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


;;; Version: load-logic.lisp,v 1.17 1997/11/04 21:51:16 hans Exp

;;; Compile and load the logic module.

;;; This is a (hopefully) temporary solution until we can
;;;    generate these load files automatically.

(in-package "STELLA")


(CL:let* ((*systemSourceDirectory* "PL:sources;logic;")
          (*systemBinaryDirectory* "PL:binaries;logic;"))
  (CL-USER::with-compilation-unit ()
    (cl-compile-and-load-file "logic-macros")
    (cl-compile-and-load-file "stella-patches")
    (cl-compile-and-load-file "kif-in")
    (cl-compile-and-load-file "propositions")
    (cl-compile-and-load-file "caches")
    (cl-compile-and-load-file "descriptions")
    (cl-compile-and-load-file "rules")
    (cl-compile-and-load-file "partial-match")
    (cl-compile-and-load-file "query")
    (cl-compile-and-load-file "kif-out")
    (cl-compile-and-load-file "print")
    (cl-compile-and-load-file "specialize")
    (cl-compile-and-load-file "optimize")
    (cl-compile-and-load-file "normalize")
    (cl-compile-and-load-file "logic-in")
    (cl-compile-and-load-file "api-support")    
    (cl-compile-and-load-file "gfp")
    (cl-compile-and-load-file "api")
    (cl-compile-and-load-file "powerloom")
    ))
