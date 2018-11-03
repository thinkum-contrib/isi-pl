;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

#|--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | 
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

(CL:DECLAIM
 (CL:SPECIAL
  *MODULE*
  *EXCEPTIONHANDLERADDRESS*
  *EXCEPTION*
  STANDARD-OUTPUT
  EOL))

;;; (DEFGLOBAL *POWERLOOM-MAJOR-VERSION-NUMBER* ...)

(CL:DEFVAR *POWERLOOM-MAJOR-VERSION-NUMBER* 1)

;;; (DEFGLOBAL *POWERLOOM-MINOR-VERSION-NUMBER* ...)

(CL:DEFVAR *POWERLOOM-MINOR-VERSION-NUMBER* 0)

;;; (DEFGLOBAL *POWERLOOM-RELEASE-STATE* ...)

(CL:DEFVAR *POWERLOOM-RELEASE-STATE* ".alpha")

;;; (DEFGLOBAL *POWERLOOM-PATCH-LEVEL* ...)

(CL:DEFVAR *POWERLOOM-PATCH-LEVEL* 1)

;;; (DEFGLOBAL *POWERLOOM-VERSION-STRING* ...)

(CL:DEFVAR *POWERLOOM-VERSION-STRING* NULL)

;;; (DEFGLOBAL *POWERLOOM-COPYRIGHT-HEADER* ...)

(CL:DEFVAR *POWERLOOM-COPYRIGHT-HEADER* "--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | 
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
 |  California, Information Sciences Institute.  It is supplied \"AS IS\",    |
 |  without any warranties of any kind.  It is furnished only on the basis  |
 |  that any party who receives it indemnifies and holds harmless the       |
 |  parties who furnish and originate it against any claims, demands, or    |
 |  liabilities connected with using it, furnishing it to others or         |
 |  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    |
 |  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  |
 |  BE ATTACHED TO EVERY PART.                                              |
 |                                                                          |
 +--------------------------------------------------------------------------")

;;; (DEFUN COPYRIGHT ...)

(CL:DEFUN COPYRIGHT ()
  "Print detailed PowerLoom copyright information."
  (CL:LET
   ((%%STREAM (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT)))
   (CL:WRITE-STRING " +" %%STREAM)
   (CL:WRITE-STRING *POWERLOOM-COPYRIGHT-HEADER* %%STREAM)
   (CL:WRITE-STRING "+" %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM))
  :VOID)

;;; (DEFUN (COPYRIGHT-YEARS STRING) ...)

(CL:DEFUN COPYRIGHT-YEARS ()
  (CL:LET*
   ((START (STRING-SEARCH *POWERLOOM-COPYRIGHT-HEADER* "1997" 0))
    (END (STRING-SEARCH *POWERLOOM-COPYRIGHT-HEADER* "  " START)))
   (CL:RETURN-FROM
    COPYRIGHT-YEARS
    (SUBSEQUENCE *POWERLOOM-COPYRIGHT-HEADER* START END)))
  :VOID)

;;; (DEFUN POWERLOOM ...)

(CL:DEFUN POWERLOOM ()
  "Run the PowerLoom listener.  Read logic commands from the
standard input, evaluate them, and print their results.  Exit if the user
entered `bye', `exit', `halt', `quit', or `stop'."
  (CL:LET
   ((%%STREAM (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT)))
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM)
   (CL:WRITE-STRING "    Welcome to " %%STREAM)
   (CL:WRITE-STRING *POWERLOOM-VERSION-STRING* %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM)
   (CL:WRITE-STRING
    "Copyright (C) USC Information Sciences Institute, "
    %%STREAM)
   (CL:WRITE-STRING (COPYRIGHT-YEARS) %%STREAM)
   (CL:WRITE-STRING "." %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM)
   (CL:WRITE-STRING "PowerLoom comes with ABSOLUTELY NO WARRANTY!" %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM)
   (CL:WRITE-STRING
    "Type `(copyright)' for detailed copyright information."
    %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM)
   (CL:WRITE-STRING
    "Type `(help)' for a list of available commands."
    %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM)
   (CL:WRITE-STRING
    "Type `(demo)' for a list of example applications."
    %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM)
   (CL:WRITE-STRING
    "Type `bye', `exit', `halt', `quit', or `stop', to exit."
    %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM))
  (CL:PROGN
   (CL:LET*
    ((*PENDINGEXCEPTIONHANDLER?* TRUE))
    (CL:DECLARE (CL:SPECIAL *PENDINGEXCEPTIONHANDLER?*))
    (CL:CATCH
     *EXCEPTIONHANDLERADDRESS*
     (CL:PROGN (LOGIC-COMMAND-LOOP) (CL:SETQ *EXCEPTION* NULL))))
   (CL:WHEN
    (CL:NOT (CL:EQ *EXCEPTION* NULL))
    (CL:COND
     ((CL:EQ TRUE 1)
      (CL:LET*
       ((E *EXCEPTION*))
       (CL:ERROR
        "Caught `~A' at top level.~%Exiting PowerLoom.~%"
        (PRIMARY-TYPE E)))))))
  (CL:LET
   ((%%STREAM (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT)))
   (CL:WRITE-STRING "Bye." %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM))
  :VOID)

;;; (DEFUN STARTUP-LOGIC ...)

(CL:DEFUN STARTUP-LOGIC ()
  (STARTUP-LOGIC-MACROS)
  (STARTUP-KIF-IN)
  (STARTUP-PROPOSITIONS)
  (STARTUP-CACHES)
  (STARTUP-DESCRIPTIONS)
  (STARTUP-QUERY)
  (STARTUP-RULES)
  (STARTUP-PARTIAL-MATCH)
  (STARTUP-KIF-OUT)
  (STARTUP-PRINT)
  (STARTUP-SPECIALIZE)
  (STARTUP-OPTIMIZE)
  (STARTUP-NORMALIZE)
  (STARTUP-LOGIC-IN)
  (STARTUP-API-SUPPORT)
  (STARTUP-API)
  (STARTUP-POWERLOOM)
  :VOID)

;;; (DEFUN (MAIN INTEGER) ...)

(CL:DEFUN MAIN ()
  "Main PowerLoom entry point for your code in C++."
  (CL:LET
   ((%%STREAM (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT)))
   (CL:WRITE-STRING "Initializing Stella..." %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM))
  (STARTUP FALSE)
  (CL:LET
   ((%%STREAM (CLSYS-SVAL OUTPUT-STREAM NATIVE-STREAM STANDARD-OUTPUT)))
   (CL:WRITE-STRING "Initializing PowerLoom..." %%STREAM)
   (CL:TERPRI %%STREAM)
   (CL:FORCE-OUTPUT %%STREAM))
  (STARTUP-LOGIC)
  (POWERLOOM)
  (CL:RETURN-FROM MAIN NULL-INTEGER)
  :VOID)

(CL:DEFUN STARTUP-POWERLOOM ()
  (CL:LET*
   ((*MODULE* (GET-MODULE "/LOGIC" TRUE)) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 4) 1)
    (CL:SETQ
     *POWERLOOM-VERSION-STRING*
     (CONCATENATE
      "PowerLoom "
      (CONCATENATE
       (INTEGER-TO-STRING *POWERLOOM-MAJOR-VERSION-NUMBER*)
       (CONCATENATE
        "."
        (CONCATENATE
         (INTEGER-TO-STRING *POWERLOOM-MINOR-VERSION-NUMBER*)
         (CONCATENATE
          *POWERLOOM-RELEASE-STATE*
          (CONCATENATE
           " (patch-level "
           (CONCATENATE
            (INTEGER-TO-STRING *POWERLOOM-PATCH-LEVEL*)
            ")")))))))))
   (CL:WHEN (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 6) 1) (FINALIZE-CLASSES))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 7) 1)
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "COPYRIGHT"
        NULL
        "(DEFUN COPYRIGHT () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Print detailed PowerLoom copyright information.\")")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION COPYRIGHT)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "COPYRIGHT-YEARS"
        NULL
        "(DEFUN (COPYRIGHT-YEARS STRING) ())")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION COPYRIGHT-YEARS)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "POWERLOOM"
        NULL
        "(DEFUN POWERLOOM () :DOCUMENTATION \"Run the PowerLoom listener.  Read logic commands from the
standard input, evaluate them, and print their results.  Exit if the user
entered `bye', `exit', `halt', `quit', or `stop'.\" :PUBLIC? TRUE)")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION POWERLOOM)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "STARTUP-LOGIC"
        NULL
        "(DEFUN STARTUP-LOGIC ())")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION STARTUP-LOGIC)))
    (CL:LET*
     ((METHOD
       (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
        "MAIN"
        NULL
        "(DEFUN (MAIN INTEGER) () :DOCUMENTATION \"Main PowerLoom entry point for your code in C++.\" :PUBLIC? TRUE)")))
     (CL:SETF
      (CLSYS-SVAL METHOD-SLOT FUNCTION-CODE METHOD)
      (CL:FUNCTION MAIN)))
    (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE
     "STARTUP-POWERLOOM"
     NULL
     "(DEFUN STARTUP-POWERLOOM ())"))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 8) 1)
    (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN
    (CL:EQ (CURRENT-STARTUP-TIME-PHASE? 9) 1)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-MAJOR-VERSION-NUMBER* INTEGER 1)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-MINOR-VERSION-NUMBER* INTEGER 0)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-RELEASE-STATE* STRING \".alpha\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-PATCH-LEVEL* INTEGER 1)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-VERSION-STRING* STRING (CONCATENATE \"PowerLoom \" (CONCATENATE (INTEGER-TO-STRING *POWERLOOM-MAJOR-VERSION-NUMBER*) (CONCATENATE \".\" (CONCATENATE (INTEGER-TO-STRING *POWERLOOM-MINOR-VERSION-NUMBER*) (CONCATENATE *POWERLOOM-RELEASE-STATE* (CONCATENATE \" (patch-level \" (CONCATENATE (INTEGER-TO-STRING *POWERLOOM-PATCH-LEVEL*) \")\"))))))))")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-COPYRIGHT-HEADER* STRING \"--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | 
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
 |  California, Information Sciences Institute.  It is supplied \\\"AS IS\\\",    |
 |  without any warranties of any kind.  It is furnished only on the basis  |
 |  that any party who receives it indemnifies and holds harmless the       |
 |  parties who furnish and originate it against any claims, demands, or    |
 |  liabilities connected with using it, furnishing it to others or         |
 |  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    |
 |  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  |
 |  BE ATTACHED TO EVERY PART.                                              |
 |                                                                          |
 +--------------------------------------------------------------------------\")")))
  :VOID)
