;;; -*- Mode: Lisp; Package: CL-USER; Syntax: COMMON-LISP; Base: 10 -*-

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                          ;
;  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996-2001              ; 
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


;;; Version: $Id: translations.lisp,v 1.12 2001/02/13 21:23:06 hans Exp $

;;; Pathname translations for PowerLoom and related systems.

(in-package "CL-USER")


(defparameter *powerloom-root-directory*  
  (namestring (truename (make-pathname :host (pathname-host *load-pathname*)
				       :directory (pathname-directory *load-pathname*)))))

(defparameter *powerloom-binary-directory*
    (format nil "~Abin/~A/"
            *powerloom-root-directory*
            (or (some #'(lambda (entry)
                          (when (find (first entry) *features*)
                            (second entry)))
                      '((:ALLEGRO-V4.1 "acl4.1")
                        (:ALLEGRO-V4.2 "acl4.2")
                        (:ALLEGRO-V4.3 "acl4.3")
                        (:ALLEGRO-V5.0 "acl5.0")
                        (:ALLEGRO-V5.0.1 "acl5.0")
                        (:ALLEGRO      "aclx.x")
                        (:LCL4.1       "lcl4.1")
                        (:LCL4.0       "lcl4.0")
                        (:LCL          "lclx.x")
                        (:MCL          "mcl")
                        (:LISPWORKS4.0 "lw4.0")
                        ))
                "lisp")))

(let* ((directorySeparator
        (char *powerloom-root-directory*
              (1- (length *powerloom-root-directory*))))
       (sourcesTranslation
        (substitute directorySeparator #\/
                    (format nil "~Asources/**/*.*" *powerloom-root-directory*)))
       (binariesTranslation
	(substitute directorySeparator #\/
                    (format nil "~a**/*.*" *powerloom-binary-directory*)))
       (nativesTranslation
        (substitute directorySeparator #\/
                    (format nil "~anative/**/*.*" *powerloom-root-directory*))))
  (setf (logical-pathname-translations "PL")
    `(("sources;**;*.*.*" ,sourcesTranslation)
      ("binaries;**;*.*.*" ,binariesTranslation)
      ("natives;**;*.*.*" ,nativesTranslation))))
