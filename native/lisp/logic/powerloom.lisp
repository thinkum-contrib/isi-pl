;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

#|--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997-2000              | 
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

(CL:DEFVAR SYM-POWERLOOM-LOGIC-STARTUP-POWERLOOM NULL)
(CL:DEFVAR SYM-POWERLOOM-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE* STANDARD-ERROR STANDARD-OUTPUT
  EOL))

;;; (DEFGLOBAL *POWERLOOM-MAJOR-VERSION-NUMBER* ...)

(CL:PROGN (CL:DEFVAR *POWERLOOM-MAJOR-VERSION-NUMBER* 2) (CL:DECLAIM (CL:TYPE CL:FIXNUM *POWERLOOM-MAJOR-VERSION-NUMBER*)))

;;; (DEFGLOBAL *POWERLOOM-MINOR-VERSION-NUMBER* ...)

(CL:PROGN (CL:DEFVAR *POWERLOOM-MINOR-VERSION-NUMBER* 0) (CL:DECLAIM (CL:TYPE CL:FIXNUM *POWERLOOM-MINOR-VERSION-NUMBER*)))

;;; (DEFGLOBAL *POWERLOOM-RELEASE-STATE* ...)

(CL:PROGN (CL:DEFVAR *POWERLOOM-RELEASE-STATE* ".alpha-") (CL:DECLAIM (CL:TYPE CL:SIMPLE-STRING *POWERLOOM-RELEASE-STATE*)))

;;; (DEFGLOBAL *POWERLOOM-PATCH-LEVEL* ...)

(CL:PROGN (CL:DEFVAR *POWERLOOM-PATCH-LEVEL* 0) (CL:DECLAIM (CL:TYPE CL:FIXNUM *POWERLOOM-PATCH-LEVEL*)))

;;; (DEFGLOBAL *POWERLOOM-VERSION-STRING* ...)

(CL:PROGN (CL:DEFVAR *POWERLOOM-VERSION-STRING* STELLA::NULL-STRING) (CL:DECLAIM (CL:TYPE CL:SIMPLE-STRING *POWERLOOM-VERSION-STRING*)))

;;; (DEFUN (POWERLOOM-COPYRIGHT-HEADER STRING) ...)

(CL:DEFUN POWERLOOM-COPYRIGHT-HEADER ()
  (CL:LET*
   ((LOGICSYSTEMFILE (MAKE-SYSTEM-DEFINITION-FILE-NAME "logic"))
    (LOGICSYSTEM
     (CL:IF (PROBE-FILE? LOGICSYSTEMFILE) (GET-SYSTEM-DEFINITION "logic")
      NULL)))
   (CL:IF (CL:NOT (CL:EQ LOGICSYSTEM NULL)) (%BANNER LOGICSYSTEM)
    "--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997-2000              | 
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
 +--------------------------------------------------------------------------")))

;;; (DEFUN COPYRIGHT ...)

(CL:DEFUN COPYRIGHT ()
  "Print detailed PowerLoom copyright information."
  (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) " +"
   (POWERLOOM-COPYRIGHT-HEADER) "+" EOL))

;;; (DEFUN (COPYRIGHT-YEARS STRING) ...)

(CL:DEFUN COPYRIGHT-YEARS ()
  (CL:LET*
   ((COPYRIGHT (POWERLOOM-COPYRIGHT-HEADER))
    (START (STRING-SEARCH COPYRIGHT "1997" 0))
    (END (STRING-SEARCH COPYRIGHT "  " START)))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING COPYRIGHT)
    (CL:TYPE CL:FIXNUM START END))
   (SUBSEQUENCE COPYRIGHT START END)))

;;; (DEFUN POWERLOOM ...)

(CL:DEFUN POWERLOOM ()
  "Run the PowerLoom listener.  Read logic commands from the
standard input, evaluate them, and print their results.  Exit if the user
entered `bye', `exit', `halt', `quit', or `stop'."
  (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) EOL "    Welcome to "
   *POWERLOOM-VERSION-STRING* EOL EOL
   "Copyright (C) USC Information Sciences Institute, " (COPYRIGHT-YEARS)
   "." EOL "PowerLoom comes with ABSOLUTELY NO WARRANTY!" EOL
   "Type `(copyright)' for detailed copyright information." EOL
   "Type `(help)' for a list of available commands." EOL
   "Type `(demo)' for a list of example applications." EOL
   "Type `bye', `exit', `halt', `quit', or `stop', to exit." EOL EOL)
  (CL:HANDLER-CASE
   (CL:PROGN (LOGIC-COMMAND-LOOP)
    (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "Bye." EOL EOL))
   (CL:CONDITION (E)
    (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-ERROR)
     "Caught native non-STELLA exception " E " at top level." EOL)
    (PRINT-EXCEPTION-CONTEXT E STANDARD-ERROR)
    (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-ERROR) "Exiting PowerLoom."
     EOL EOL))))

;;; (DEFUN MAIN ...)

(CL:DEFUN MAIN ()
  "Main PowerLoom entry point for your code in C++."
  (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
   "Initializing STELLA...")
  (STARTUP-STELLA-SYSTEM)
  (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "done" EOL)
  (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
   "Initializing PowerLoom...")
  (STARTUP-LOGIC-SYSTEM)
  (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "done" EOL)
  (POWERLOOM))

(CL:DEFUN STARTUP-POWERLOOM ()
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE "/LOGIC" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ SYM-POWERLOOM-LOGIC-STARTUP-POWERLOOM
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-POWERLOOM" NULL 0))
    (CL:SETQ SYM-POWERLOOM-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" TRUE) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ *POWERLOOM-VERSION-STRING*
     (CONCATENATE "PowerLoom "
      (INTEGER-TO-STRING *POWERLOOM-MAJOR-VERSION-NUMBER*) "."
      (INTEGER-TO-STRING *POWERLOOM-MINOR-VERSION-NUMBER*)
      *POWERLOOM-RELEASE-STATE* " (patch-level "
      (INTEGER-TO-STRING *POWERLOOM-PATCH-LEVEL*) ")")))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "POWERLOOM-COPYRIGHT-HEADER"
     "(DEFUN (POWERLOOM-COPYRIGHT-HEADER STRING) ())"
     (CL:FUNCTION POWERLOOM-COPYRIGHT-HEADER) NULL)
    (DEFINE-FUNCTION-OBJECT "COPYRIGHT"
     "(DEFUN COPYRIGHT () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Print detailed PowerLoom copyright information.\")"
     (CL:FUNCTION COPYRIGHT) NULL)
    (DEFINE-FUNCTION-OBJECT "COPYRIGHT-YEARS"
     "(DEFUN (COPYRIGHT-YEARS STRING) ())" (CL:FUNCTION COPYRIGHT-YEARS)
     NULL)
    (DEFINE-FUNCTION-OBJECT "POWERLOOM"
     "(DEFUN POWERLOOM () :DOCUMENTATION \"Run the PowerLoom listener.  Read logic commands from the
standard input, evaluate them, and print their results.  Exit if the user
entered `bye', `exit', `halt', `quit', or `stop'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION POWERLOOM) NULL)
    (DEFINE-FUNCTION-OBJECT "MAIN"
     "(DEFUN MAIN () :PUBLIC? TRUE :DOCUMENTATION \"Main PowerLoom entry point for your code in C++.\")"
     (CL:FUNCTION MAIN) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-POWERLOOM"
     "(DEFUN STARTUP-POWERLOOM () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-POWERLOOM) NULL)
    (CL:LET*
     ((FUNCTION (LOOKUP-FUNCTION SYM-POWERLOOM-LOGIC-STARTUP-POWERLOOM)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-POWERLOOM-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "Startup-Powerloom") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-MAJOR-VERSION-NUMBER* INTEGER 2)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-MINOR-VERSION-NUMBER* INTEGER 0)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-RELEASE-STATE* STRING \".alpha-\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-PATCH-LEVEL* INTEGER 0)")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-VERSION-STRING* STRING (CONCATENATE \"PowerLoom \" (INTEGER-TO-STRING *POWERLOOM-MAJOR-VERSION-NUMBER*) \".\" (INTEGER-TO-STRING *POWERLOOM-MINOR-VERSION-NUMBER*) *POWERLOOM-RELEASE-STATE* \" (patch-level \" (INTEGER-TO-STRING *POWERLOOM-PATCH-LEVEL*) \")\"))"))))
