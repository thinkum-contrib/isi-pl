;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

#|--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996, 1997             | 
 |  University of Southern California, Information Sciences Institute       |
 |  4676 Admiralty Way                                                      |
 |  Marina Del Rey, California 90292                                        |
 |                                                                          |
 |  This software was developed under the terms and conditions of Contract  |
 |  No. N00014-94-C-0245 between the Defense Advanced Research Projects     |
 |  Agency and the University of Southern California, Information Sciences  | 
 |  Institute.  Use and distribution of this software is further subject    |
 |  to the provisions of that contract and any other agreements developed   |
 |  between the user of the software and the University of Southern         |
 |  California, Information Sciences Institute.  It is supplied "AS IS",    |
 |  without any warranties of any kind.  It is furnished only on the basis  |
 |  that any party who receives it indemnifies and holds harmless the       |
 |  parties who furnish and originate it against any claims, demands, or    |
 |  liabilities connected with using it, furnishing it to others or         |
 |  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    |
 |  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  |
 |  BE ATTACHED TO EVERY PART.                                              |
 |                                                                          |
 +--------------------------------------------------------------------------|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:


;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STELLA-MODULE* *MODULE*))

;;; (DEFUN CPP-OUTPUT-ALL-UNITS-TO-FILE ...)

(CL:DEFUN CPP-OUTPUT-ALL-UNITS-TO-FILE (SOURCEFILE)
  NULL
  :VOID)

;;; (DEFUN CPP-TRANSLATE-FILE ...)

(CL:DEFUN CPP-TRANSLATE-FILE (FILENAME)
  NULL
  :VOID)

(CL:DEFUN STARTUP-CPP-TRANSLATE-FILE ()
  (CL:LET*
   ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 6) 1) (FINALIZE-CLASSES))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 7) 1)
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "CPP-OUTPUT-ALL-UNITS-TO-FILE"
        "FILE-NAME"
        "(DEFUN CPP-OUTPUT-ALL-UNITS-TO-FILE ((SOURCEFILE FILE-NAME)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION CPP-OUTPUT-ALL-UNITS-TO-FILE)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "CPP-TRANSLATE-FILE"
        "FILE-NAME"
        "(DEFUN CPP-TRANSLATE-FILE ((FILENAME FILE-NAME)))")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION CPP-TRANSLATE-FILE)))
    (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
     "STARTUP-CPP-TRANSLATE-FILE"
     NULL
     "(DEFUN STARTUP-CPP-TRANSLATE-FILE ())"))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 8) 1)
    (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES)))
  :VOID)
