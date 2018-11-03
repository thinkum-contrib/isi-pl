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


;;; Version: make-stella.lisp,v 1.31 1997/11/07 00:56:28 hans Exp

;;; Load STELLA from CL-translated files.

(in-package "STELLA")

(CL-USER::with-compilation-unit ()
  (CL-USER::stella-c&l-translated "hierarchy")
  (CL-USER::stella-c&l-translated "taxonomies")
  (CL-USER::stella-c&l-translated "streams")
  (CL-USER::stella-c&l-translated "primal")
  (CL-USER::stella-c&l-translated "cl-lib" "cl-primal")
  (CL-USER::stella-c&l-translated "startup")
  (CL-USER::stella-c&l-translated "type-predicates")
  (CL-USER::stella-c&l-translated "conses")
  (CL-USER::stella-c&l-translated "lists")
  (CL-USER::stella-c&l-translated "collections")
  (CL-USER::stella-c&l-translated "iterators")
  (CL-USER::stella-c&l-translated "symbols")
  (CL-USER::stella-c&l-translated "boot-symbols")
  (CL-USER::stella-c&l-translated "literals")
  (CL-USER::stella-c&l-translated "classes")
  (CL-USER::stella-c&l-translated "methods")
  (CL-USER::stella-c&l-translated "defclass")
  (CL-USER::stella-c&l-translated "stella-in")
  (CL-USER::stella-c&l-translated "foreach")
  (CL-USER::stella-c&l-translated "walk")
  (CL-USER::stella-c&l-translated "dynamic-slots")
  (CL-USER::stella-c&l-translated "dynamic-literal-slots")
  (CL-USER::stella-c&l-translated "cl-translate")
  (CL-USER::stella-c&l-translated "macros")
  (CL-USER::stella-c&l-translated "describe")
  (CL-USER::stella-c&l-translated "demons")
  (CL-USER::stella-c&l-translated "more-demons")
  (CL-USER::stella-c&l-translated "modules")
  (CL-USER::stella-c&l-translated "contexts")
  (CL-USER::stella-c&l-translated "read")
  (CL-USER::stella-c&l-translated "translate-file")
  (CL-USER::stella-c&l-translated "cl-translate-file")
  (CL-USER::stella-c&l-translated "cpp-translate")
  (CL-USER::stella-c&l-translated "cpp-translate-file")
  (CL-USER::stella-c&l-translated "cpp-class-out")
  (CL-USER::stella-c&l-translated "cpp-output")
  (CL-USER::stella-c&l-translated "java-translate")
  (CL-USER::stella-c&l-translated "java-translate-file")
  (CL-USER::stella-c&l-translated "java-class-out")
  (CL-USER::stella-c&l-translated "java-output")
  (CL-USER::stella-c&l-translated "idl-translate")
  (CL-USER::stella-c&l-translated "idl-translate-file")
  (CL-USER::stella-c&l-translated "idl-class-out")
  (CL-USER::stella-c&l-translated "idl-output")
  (CL-USER::stella-c&l-translated "your-file")
  (CL-USER::stella-c&l-translated "your-file2")
  (CL-USER::stella-c&l-translated "cl-lib" "stella-to-cl")
  ) ;; with-compilation-unit

(startup (not-cl-nil? CL-USER::*stella-verbose?*))
(startup-stella-to-cl)

(eval (if (use-vector-structs?)
          (print EOL "*** This Stella image uses vector structs "
                 "instead of CLOS instances ***" EOL EOL)
        (when (use-cl-structs?)
          (print EOL "*** This Stella image uses CL-structs "
                 "instead of CLOS instances ***" EOL EOL))))
