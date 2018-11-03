;;; -*- Mode: Lisp; Package: CL-USER; Syntax: COMMON-LISP; Base: 10 -*-

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


;;; Version: translations.lisp,v 1.3 1997/11/09 02:11:15 hans Exp

;;; Pathname translations for PowerLoom and related systems.

(in-package "CL-USER")


;;; Edit this variable to point to your PowerLoom installation directory
;;; (make sure it ends with a directory separator character):

(defvar *powerloom-root-directory*  "/home/loom/PowerLoom/installation/")

(defvar *powerloom-binary-directory*
    (format nil "~abin/~a/"
            *powerloom-root-directory*
            (or (some #'(lambda (entry)
                          (when (find (first entry) *features*)
                            (second entry)))
                      '((:ALLEGRO-V4.1 "ACL4.1")
                        (:ALLEGRO-V4.2 "ACL4.2")
                        (:ALLEGRO-V4.3 "ACL4.3")
                        (:ALLEGRO      "ACLx.x")
                        (:LCL4.1       "LCL4.1")
                        (:LCL4.0       "LCL4.0")
                        (:LCL          "LCLx.x")
                        (:MCL          "MCL")
                        ))
                "LISP")))

(let* ((directorySeparator
        (char *powerloom-root-directory*
              (1- (length *powerloom-root-directory*))))
       (sourcesTranslation
        (substitute directorySeparator #\/
                    (format nil "~a**/*.*" *powerloom-root-directory*)))
       (binariesTranslation
        (substitute directorySeparator #\/
                    (format nil "~a**/*.*" *powerloom-binary-directory*))))
  (setf (logical-pathname-translations "PL")
    `(("PL:sources;**;*.*" ,sourcesTranslation)
      ("PL:binaries;**;*.*" ,binariesTranslation))))
