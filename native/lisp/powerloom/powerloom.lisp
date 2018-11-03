;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; powerloom.lisp

#|
 +---------------------------- BEGIN LICENSE BLOCK ---------------------------+
 |                                                                            |
 | Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          |
 |                                                                            |
 | The contents of this file are subject to the Mozilla Public License        |
 | Version 1.1 (the "License"); you may not use this file except in           |
 | compliance with the License. You may obtain a copy of the License at       |
 | http://www.mozilla.org/MPL/                                                |
 |                                                                            |
 | Software distributed under the License is distributed on an "AS IS" basis, |
 | WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   |
 | for the specific language governing rights and limitations under the       |
 | License.                                                                   |
 |                                                                            |
 | The Original Code is the PowerLoom KR&R System.                            |
 |                                                                            |
 | The Initial Developer of the Original Code is                              |
 | UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
 | 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
 |                                                                            |
 | Portions created by the Initial Developer are Copyright (C) 1997-2014      |
 | the Initial Developer. All Rights Reserved.                                |
 |                                                                            |
 | Contributor(s):                                                            |
 |                                                                            |
 | Alternatively, the contents of this file may be used under the terms of    |
 | either the GNU General Public License Version 2 or later (the "GPL"), or   |
 | the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   |
 | in which case the provisions of the GPL or the LGPL are applicable instead |
 | of those above. If you wish to allow use of your version of this file only |
 | under the terms of either the GPL or the LGPL, and not to allow others to  |
 | use your version of this file under the terms of the MPL, indicate your    |
 | decision by deleting the provisions above and replace them with the notice |
 | and other provisions required by the GPL or the LGPL. If you do not delete |
 | the provisions above, a recipient may use your version of this file under  |
 | the terms of any one of the MPL, the GPL or the LGPL.                      |
 |                                                                            |
 +----------------------------- END LICENSE BLOCK ----------------------------+
|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR KWD-POWERLOOM-KEY NULL)
(CL:DEFVAR KWD-POWERLOOM-DOCUMENTATION NULL)
(CL:DEFVAR KWD-POWERLOOM-N-ARGUMENTS NULL)
(CL:DEFVAR KWD-POWERLOOM-HANDLER NULL)
(CL:DEFVAR SYM-POWERLOOM-POWERLOOM-CODE-LOAD-ALL-EXTENSIONS-OPTION-HANDLER NULL)
(CL:DEFVAR KWD-POWERLOOM-ERROR-ACTION NULL)
(CL:DEFVAR KWD-POWERLOOM-ERROR NULL)
(CL:DEFVAR SYM-POWERLOOM-POWERLOOM-CODE-START-POWERLOOM-GUI-OPTION-HANDLER NULL)
(CL:DEFVAR KWD-POWERLOOM-WARN NULL)
(CL:DEFVAR KWD-POWERLOOM-KEY2 NULL)
(CL:DEFVAR KWD-POWERLOOM-PROPERTY NULL)
(CL:DEFVAR KWD-POWERLOOM-VALUE-TYPE NULL)
(CL:DEFVAR SGT-POWERLOOM-STELLA-BOOLEAN NULL)
(CL:DEFVAR KWD-POWERLOOM-DEFAULT-VALUE NULL)
(CL:DEFVAR KWD-POWERLOOM-KEY3 NULL)
(CL:DEFVAR SYM-POWERLOOM-STELLA-EVAL-OPTION-HANDLER NULL)
(CL:DEFVAR SYM-POWERLOOM-POWERLOOM-CODE-STARTUP-POWERLOOM NULL)
(CL:DEFVAR SYM-POWERLOOM-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE* FALSE-WRAPPER
  *STELLA-EXIT-HOOKS* TRUE-WRAPPER NIL STANDARD-OUTPUT EOL))

;;; (DEFGLOBAL *POWERLOOM-EXTENSION-SYSTEMS* ...)

(CL:DEFVAR *POWERLOOM-EXTENSION-SYSTEMS* NULL
  "List of extension systems that can be loaded
dynamically (not yet in C++).")

;;; (DEFUN LOAD-ALL-EXTENSION-SYSTEMS ...)

(CL:DEFUN LOAD-ALL-EXTENSION-SYSTEMS ()
  "Load and initialize all installed extension systems."
  (CL:LET* ((SYSTEM NULL) (ITER-000 *POWERLOOM-EXTENSION-SYSTEMS*))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
    (CL:SETQ SYSTEM (%%VALUE ITER-000))
    (CL:WHEN
     (CL:NOT
      (SYSTEM-LOADED-OR-STARTED-UP?
       (STRING-DOWNCASE (%WRAPPER-VALUE SYSTEM))))
     (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "Initializing "
      (UNWRAP-STRING SYSTEM) "...")
     (CL:HANDLER-CASE
      (%LOAD-SYSTEM (STRING-DOWNCASE (%WRAPPER-VALUE SYSTEM)) NIL)
      (CL:CONDITION ()
       (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "FAILED")))
     (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) EOL))
    (CL:SETQ ITER-000 (%%REST ITER-000)))))

;;; (DEFUN LOAD-ALL-EXTENSIONS-OPTION-HANDLER ...)

(CL:DEFUN LOAD-ALL-EXTENSIONS-OPTION-HANDLER (OPTION VALUE)
  "Load and initialize all installed extension systems."
  (CL:PROGN (CL:SETQ OPTION OPTION) (CL:SETQ VALUE VALUE))
  (LOAD-ALL-EXTENSION-SYSTEMS))

;;; (DEFUN START-POWERLOOM-GUI-OPTION-HANDLER ...)

(CL:DEFUN START-POWERLOOM-GUI-OPTION-HANDLER (OPTION VALUE)
  "Start the PowerLoom GUI."
  (CL:PROGN (CL:SETQ OPTION OPTION) (CL:SETQ VALUE VALUE))
  (SET-CONFIGURATION-PROPERTY "powerloom.runInteractively" TRUE-WRAPPER
   NULL)
  (%START-POWERLOOM-GUI NIL))

;;; (DEFUN MAIN ...)

(CL:DEFUN MAIN (CL:&REST %%ARGS)
  (CL:LET*
   ((COUNT (CL:LENGTH %%ARGS))
    (ARGUMENTS
     (CL:MAKE-ARRAY (CL:LENGTH %%ARGS) :INITIAL-CONTENTS %%ARGS)))
   (CL:DECLARE (CL:TYPE CL:FIXNUM COUNT)
    (CL:TYPE CL:SIMPLE-VECTOR ARGUMENTS))
   (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
    "Initializing STELLA..." EOL)
   (STARTUP-STELLA-SYSTEM)
   (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
    "Initializing PowerLoom..." EOL)
   (STARTUP-LOGIC-SYSTEM) (STARTUP-POWERLOOM-EXTENSIONS-SYSTEM)
   (STARTUP-POWERLOOM-SYSTEM) (CHANGE-MODULE "PL-USER")
   (PROCESS-COMMAND-LINE-ARGUMENTS COUNT ARGUMENTS KWD-POWERLOOM-WARN)
   (CL:WHEN
    (CL:AND
     (CL:NOT
      (EQL?
       (%GET-PROPERTY (WRAP-STRING "powerloom.runInteractively") NIL)
       FALSE-WRAPPER))
     (CL:NOT
      (EQL? (%GET-PROPERTY (WRAP-STRING "stella.showInfoOnly") NIL)
       TRUE-WRAPPER)))
    (POWERLOOM))
   (RUN-HOOKS *STELLA-EXIT-HOOKS* NULL)))

(CL:DEFUN STARTUP-POWERLOOM ()
  (CL:LET*
   ((*MODULE*
     (GET-STELLA-MODULE "/POWERLOOM-CODE" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ KWD-POWERLOOM-KEY
     (INTERN-RIGID-SYMBOL-WRT-MODULE "KEY" NULL 2))
    (CL:SETQ KWD-POWERLOOM-DOCUMENTATION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DOCUMENTATION" NULL 2))
    (CL:SETQ KWD-POWERLOOM-N-ARGUMENTS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "N-ARGUMENTS" NULL 2))
    (CL:SETQ KWD-POWERLOOM-HANDLER
     (INTERN-RIGID-SYMBOL-WRT-MODULE "HANDLER" NULL 2))
    (CL:SETQ
     SYM-POWERLOOM-POWERLOOM-CODE-LOAD-ALL-EXTENSIONS-OPTION-HANDLER
     (INTERN-RIGID-SYMBOL-WRT-MODULE
      "LOAD-ALL-EXTENSIONS-OPTION-HANDLER" NULL 0))
    (CL:SETQ KWD-POWERLOOM-ERROR-ACTION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "ERROR-ACTION" NULL 2))
    (CL:SETQ KWD-POWERLOOM-ERROR
     (INTERN-RIGID-SYMBOL-WRT-MODULE "ERROR" NULL 2))
    (CL:SETQ
     SYM-POWERLOOM-POWERLOOM-CODE-START-POWERLOOM-GUI-OPTION-HANDLER
     (INTERN-RIGID-SYMBOL-WRT-MODULE
      "START-POWERLOOM-GUI-OPTION-HANDLER" NULL 0))
    (CL:SETQ KWD-POWERLOOM-WARN
     (INTERN-RIGID-SYMBOL-WRT-MODULE "WARN" NULL 2))
    (CL:SETQ KWD-POWERLOOM-KEY2
     (INTERN-RIGID-SYMBOL-WRT-MODULE "KEY2" NULL 2))
    (CL:SETQ KWD-POWERLOOM-PROPERTY
     (INTERN-RIGID-SYMBOL-WRT-MODULE "PROPERTY" NULL 2))
    (CL:SETQ KWD-POWERLOOM-VALUE-TYPE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "VALUE-TYPE" NULL 2))
    (CL:SETQ SGT-POWERLOOM-STELLA-BOOLEAN
     (INTERN-RIGID-SYMBOL-WRT-MODULE "BOOLEAN"
      (GET-STELLA-MODULE "/STELLA" CL:T) 1))
    (CL:SETQ KWD-POWERLOOM-DEFAULT-VALUE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DEFAULT-VALUE" NULL 2))
    (CL:SETQ KWD-POWERLOOM-KEY3
     (INTERN-RIGID-SYMBOL-WRT-MODULE "KEY3" NULL 2))
    (CL:SETQ SYM-POWERLOOM-STELLA-EVAL-OPTION-HANDLER
     (INTERN-RIGID-SYMBOL-WRT-MODULE "EVAL-OPTION-HANDLER"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-POWERLOOM-POWERLOOM-CODE-STARTUP-POWERLOOM
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-POWERLOOM" NULL 0))
    (CL:SETQ SYM-POWERLOOM-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ *POWERLOOM-EXTENSION-SYSTEMS*
     (CONS-LIST (WRAP-STRING "SDBC") (WRAP-STRING "RDBMS"))))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "LOAD-ALL-EXTENSION-SYSTEMS"
     "(DEFUN LOAD-ALL-EXTENSION-SYSTEMS () :DOCUMENTATION \"Load and initialize all installed extension systems.\" :PUBLIC? TRUE :COMMAND? TRUE)"
     (CL:FUNCTION LOAD-ALL-EXTENSION-SYSTEMS) NULL)
    (DEFINE-FUNCTION-OBJECT "LOAD-ALL-EXTENSIONS-OPTION-HANDLER"
     "(DEFUN LOAD-ALL-EXTENSIONS-OPTION-HANDLER ((OPTION CMD-LINE-OPTION) (VALUE OBJECT)) :DOCUMENTATION \"Load and initialize all installed extension systems.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LOAD-ALL-EXTENSIONS-OPTION-HANDLER) NULL)
    (DEFINE-FUNCTION-OBJECT "START-POWERLOOM-GUI-OPTION-HANDLER"
     "(DEFUN START-POWERLOOM-GUI-OPTION-HANDLER ((OPTION CMD-LINE-OPTION) (VALUE OBJECT)) :DOCUMENTATION \"Start the PowerLoom GUI.\" :PUBLIC? TRUE)"
     (CL:FUNCTION START-POWERLOOM-GUI-OPTION-HANDLER) NULL)
    (DEFINE-FUNCTION-OBJECT "MAIN"
     "(DEFUN MAIN (|&REST| (%%ARGS STRING)) :PUBLIC? TRUE)"
     (CL:FUNCTION MAIN) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-POWERLOOM"
     "(DEFUN STARTUP-POWERLOOM () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-POWERLOOM) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION
        SYM-POWERLOOM-POWERLOOM-CODE-STARTUP-POWERLOOM)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-POWERLOOM-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupPowerloom") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "POWERLOOM-CODE")))
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *POWERLOOM-EXTENSION-SYSTEMS* (CONS OF STRING-WRAPPER) (CONS-LIST \"SDBC\" \"RDBMS\") :DOCUMENTATION \"List of extension systems that can be loaded
dynamically (not yet in C++).\" :PUBLIC? TRUE)")
    (REGISTER-CMD-LINE-OPTION KWD-POWERLOOM-KEY
     (WRAP-STRING "--load-all-extensions") KWD-POWERLOOM-DOCUMENTATION
     (WRAP-STRING "
  Load all available PowerLoom extension systems.")
     KWD-POWERLOOM-N-ARGUMENTS (WRAP-INTEGER 0) KWD-POWERLOOM-HANDLER
     SYM-POWERLOOM-POWERLOOM-CODE-LOAD-ALL-EXTENSIONS-OPTION-HANDLER
     KWD-POWERLOOM-ERROR-ACTION KWD-POWERLOOM-ERROR)
    (REGISTER-CMD-LINE-OPTION KWD-POWERLOOM-KEY (WRAP-STRING "--gui")
     KWD-POWERLOOM-DOCUMENTATION
     (WRAP-STRING "
  Launch the PowerLoom GUI in addition to the read/eval/print loop.")
     KWD-POWERLOOM-N-ARGUMENTS (WRAP-INTEGER 0) KWD-POWERLOOM-HANDLER
     SYM-POWERLOOM-POWERLOOM-CODE-START-POWERLOOM-GUI-OPTION-HANDLER
     KWD-POWERLOOM-ERROR-ACTION KWD-POWERLOOM-WARN)
    (REGISTER-CMD-LINE-OPTION KWD-POWERLOOM-KEY (WRAP-STRING "-i")
     KWD-POWERLOOM-KEY2 (WRAP-STRING "--interactive")
     KWD-POWERLOOM-DOCUMENTATION
     (WRAP-STRING "
  Launch an interactive read/eval/print loop after all startup code and
  command line arguments have been processed.")
     KWD-POWERLOOM-N-ARGUMENTS (WRAP-INTEGER 0) KWD-POWERLOOM-PROPERTY
     (WRAP-STRING "powerloom.runInteractively")
     KWD-POWERLOOM-VALUE-TYPE SGT-POWERLOOM-STELLA-BOOLEAN
     KWD-POWERLOOM-DEFAULT-VALUE TRUE-WRAPPER)
    (REGISTER-CMD-LINE-OPTION KWD-POWERLOOM-KEY (WRAP-STRING "--batch")
     KWD-POWERLOOM-DOCUMENTATION
     (WRAP-STRING "
  Do not start an interactive read/eval/print loop.  Just evaluate all
  command line arguments and main function code and then exit.")
     KWD-POWERLOOM-N-ARGUMENTS (WRAP-INTEGER 0) KWD-POWERLOOM-PROPERTY
     (WRAP-STRING "powerloom.runInteractively")
     KWD-POWERLOOM-VALUE-TYPE SGT-POWERLOOM-STELLA-BOOLEAN
     KWD-POWERLOOM-DEFAULT-VALUE FALSE-WRAPPER)
    (REGISTER-CMD-LINE-OPTION KWD-POWERLOOM-KEY (WRAP-STRING "-e")
     KWD-POWERLOOM-KEY2 (WRAP-STRING "--eval") KWD-POWERLOOM-KEY3
     (WRAP-STRING "-eval") KWD-POWERLOOM-DOCUMENTATION
     (WRAP-STRING "<s-expression>
  Evaluate the STELLA <s-expression> in the PL-USER module.")
     KWD-POWERLOOM-N-ARGUMENTS (WRAP-INTEGER 1) KWD-POWERLOOM-HANDLER
     SYM-POWERLOOM-STELLA-EVAL-OPTION-HANDLER
     KWD-POWERLOOM-ERROR-ACTION KWD-POWERLOOM-WARN))))
