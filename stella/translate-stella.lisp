;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                          ;
;  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996, 1997             ; 
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


;;; Version: translate-stella.lisp,v 1.8 1997/04/15 19:57:41 hans Exp

;;; Define and CL-translate the Stella module.

;;; This is a (hopefully) temporary solution until we can
;;;    generate these translation files automatically.

(in-package "STELLA")

(in-module "/STELLA")


;;(setq *safety* 0) ;; avoid generation of casts
(setq *gensym-counter* -1)

(enable-environment-feature 
 (intern-keyword "TRANSLATE-WITH-COPYRIGHT-HEADER")
 (intern-keyword "WARN-ABOUT-MISSING-METHODS")
 (intern-keyword "WARN-ABOUT-UNDEFINED-METHODS"))
(disable-environment-feature
 (intern-keyword "USE-HARDCODED-SYMBOLS"))

;; Note: *stella-files* is defined in `translate-file'
   
(simple-translate-system
 *stella-files*
 ;; This relies on the fact that startup.ste gets translated last:
 (null? (lookup-function-or-stella-function (intern-symbol "STARTUP")))
 TRUE)

(create-symbol-startup-file "PL:sources;stella;boot-symbols.ste")
(translate-file "PL:sources;stella;boot-symbols.ste" FALSE)

(disable-environment-feature 
 (intern-keyword "TRANSLATE-WITH-COPYRIGHT-HEADER"))
