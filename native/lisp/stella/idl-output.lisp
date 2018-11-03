;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; idl-output.lisp

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
| The Original Code is the STELLA Programming Language.                      |
|                                                                            |
| The Initial Developer of the Original Code is                              |
| UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
| 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
|                                                                            |
| Portions created by the Initial Developer are Copyright (C) 1996-2017      |
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
+---------------------------- END LICENSE BLOCK -----------------------------+
|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-IDL_COMMENT NULL)
(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-IDL_TYPEDEF NULL)
(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-IDL_ENUM NULL)
(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-IDL_INTERFACE NULL)
(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-IDL_STRUCT NULL)
(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-IDL_DECLARATIONS NULL)
(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-IDL_IDENT NULL)
(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-IDL_TYPE NULL)
(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-IDL_SIGNATURES NULL)
(CL:DEFVAR SGT-IDL-OUTPUT-STELLA-CONS NULL)
(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-IDL_VAR_ARGS NULL)
(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-STARTUP-IDL-OUTPUT NULL)
(CL:DEFVAR SYM-IDL-OUTPUT-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STELLA-MODULE* *MODULE* EOL NULL-INTEGER *CURRENT-STREAM* NIL))

;;; (DEFSPECIAL *IDL-INDENT-CHARS* ...)

(CL:DEFVAR *IDL-INDENT-CHARS* 0)
(CL:DECLAIM (CL:TYPE CL:FIXNUM *IDL-INDENT-CHARS*))

;;; (DEFUN IDL-OUTPUT-PARSE-TREE ...)

(CL:DEFUN IDL-OUTPUT-PARSE-TREE (CONSTREE)
  (CL:LET* ((*IDL-INDENT-CHARS* 0)) (CL:DECLARE (CL:SPECIAL *IDL-INDENT-CHARS*)) (CL:DECLARE (CL:TYPE CL:FIXNUM *IDL-INDENT-CHARS*)) (IDL-OUTPUT-STATEMENT CONSTREE))
  :VOID)

;;; (DEFUN IDL-OUTPUT-STATEMENT ...)

(CL:DEFUN IDL-OUTPUT-STATEMENT (STATEMENT)
  (CL:COND
   ((CL:EQ (SAFE-PRIMARY-TYPE STATEMENT) SGT-IDL-OUTPUT-STELLA-CONS)
    (CL:PROGN (CL:WHEN (CL:EQ STATEMENT NIL) (CL:RETURN-FROM IDL-OUTPUT-STATEMENT))
     (CL:IF (CL:OR (CONS? (%%VALUE STATEMENT)) (CL:EQ (%%VALUE STATEMENT) NULL))
      (CL:PROGN (IDL-OUTPUT-STATEMENT (%%VALUE STATEMENT)) (IDL-OUTPUT-STATEMENT (%%REST STATEMENT)))
      (CL:LET* ((TEST-VALUE-000 (%%VALUE STATEMENT)))
       (CL:COND ((CL:EQ TEST-VALUE-000 SYM-IDL-OUTPUT-STELLA-IDL_COMMENT) (IDL-OUTPUT-COMMENT (%%VALUE (%%REST STATEMENT))))
        ((CL:EQ TEST-VALUE-000 SYM-IDL-OUTPUT-STELLA-IDL_TYPEDEF) (IDL-OUTPUT-TYPEDEF (%%REST STATEMENT)))
        ((CL:EQ TEST-VALUE-000 SYM-IDL-OUTPUT-STELLA-IDL_ENUM) (IDL-OUTPUT-ENUM (%%REST STATEMENT)))
        ((CL:EQ TEST-VALUE-000 SYM-IDL-OUTPUT-STELLA-IDL_INTERFACE) (IDL-OUTPUT-INTERFACE (%%REST STATEMENT)))
        ((CL:EQ TEST-VALUE-000 SYM-IDL-OUTPUT-STELLA-IDL_STRUCT) (IDL-OUTPUT-STRUCT (%%REST STATEMENT)))
        ((CL:EQ TEST-VALUE-000 SYM-IDL-OUTPUT-STELLA-IDL_DECLARATIONS) (IDL-OUTPUT-DECLARATIONS (%%VALUE (%%REST STATEMENT))))
        ((CL:EQ TEST-VALUE-000 SYM-IDL-OUTPUT-STELLA-IDL_IDENT) (IDL-OUTPUT-IDENTIFIER (%%VALUE (%%REST STATEMENT))))
        ((CL:EQ TEST-VALUE-000 SYM-IDL-OUTPUT-STELLA-IDL_TYPE) (IDL-OUTPUT-TYPE-EXPRESSION (%%REST STATEMENT)))
        ((CL:EQ TEST-VALUE-000 SYM-IDL-OUTPUT-STELLA-IDL_SIGNATURES) (IDL-OUTPUT-SIGNATURES (%%VALUE (%%REST STATEMENT))))
        (CL:T
         (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM))) (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" TEST-VALUE-000 "' is not a valid case option")
          (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))))))
   (CL:T (CL:WHEN (CL:EQ STATEMENT NULL) (CL:RETURN-FROM IDL-OUTPUT-STATEMENT)) (IDL-OUTPUT-ATOMIC-EXPRESSION STATEMENT)))
  :VOID)

;;; (DEFUN IDL-INDENT ...)

(CL:DEFUN IDL-INDENT ()
  (CL:LET* ((I NULL-INTEGER) (ITER-000 1) (UPPER-BOUND-000 *IDL-INDENT-CHARS*) (UNBOUNDED?-000 (CL:= UPPER-BOUND-000 NULL-INTEGER)))
   (CL:DECLARE (CL:TYPE CL:FIXNUM I ITER-000 UPPER-BOUND-000))
   (CL:LOOP WHILE (CL:OR UNBOUNDED?-000 (CL:<= ITER-000 UPPER-BOUND-000)) DO (CL:SETQ I ITER-000) (CL:SETQ I I) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) " ")
    (CL:SETQ ITER-000 (CL:1+ ITER-000))))
  :VOID)

;;; (DEFUN IDL-BUMP-INDENT ...)

(CL:DEFUN IDL-BUMP-INDENT ()
  (CL:SETQ *IDL-INDENT-CHARS* (CL:+ *IDL-INDENT-CHARS* 2))
  :VOID)

;;; (DEFUN IDL-UNBUMP-INDENT ...)

(CL:DEFUN IDL-UNBUMP-INDENT ()
  (CL:SETQ *IDL-INDENT-CHARS* (CL:- *IDL-INDENT-CHARS* 2))
  :VOID)

;;; (DEFUN IDL-OUTPUT-TYPEDEF ...)

(CL:DEFUN IDL-OUTPUT-TYPEDEF (TYPEDEF)
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "typedef " (%WRAPPER-VALUE (%%VALUE (%%REST TYPEDEF))) " " (%WRAPPER-VALUE (%%VALUE TYPEDEF)) ";" EOL EOL)
  :VOID)

;;; (DEFUN IDL-OUTPUT-ENUMERANDS ...)

(CL:DEFUN IDL-OUTPUT-ENUMERANDS (ENUMERANDS)
  (CL:WHEN (CL:NOT (CL:EQ (%%VALUE ENUMERANDS) NULL)) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE (%%VALUE (%%REST (%%VALUE ENUMERANDS))))))
  (CL:LET* ((ENUMERAND NULL) (ITER-000 (%%REST ENUMERANDS)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ ENUMERAND (%%VALUE ITER-000))
    (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) ", " (%WRAPPER-VALUE (%%VALUE (%%REST ENUMERAND)))) (CL:SETQ ITER-000 (%%REST ITER-000))))
  :VOID)

;;; (DEFUN IDL-OUTPUT-ENUM ...)

(CL:DEFUN IDL-OUTPUT-ENUM (ENUM)
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "enum {")
  (IDL-OUTPUT-ENUMERANDS (%%VALUE (%%REST (NTH ENUM 4))))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "};" EOL EOL)
  :VOID)

;;; (DEFUN IDL-OUTPUT-TYPE-EXPRESSION ...)

(CL:DEFUN IDL-OUTPUT-TYPE-EXPRESSION (TYPEEXPRESSION)
  (CL:LET* ((TYPEEXPR NULL) (ITER-000 TYPEEXPRESSION))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ TYPEEXPR (%%VALUE ITER-000)) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE TYPEEXPR) " ")
    (CL:SETQ ITER-000 (%%REST ITER-000))))
  :VOID)

;;; (DEFMETHOD IDL-OUTPUT-LITERAL ...)

(%%DEFCONSMETHOD IDL-OUTPUT-LITERAL ((OBJECT OBJECT))
  :VOID)

;;; (DEFMETHOD IDL-OUTPUT-LITERAL ...)

(CL:DEFMETHOD IDL-OUTPUT-LITERAL ((STRING CL:STRING))
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "\""
   (REPLACE-SUBSTRINGS (REPLACE-SUBSTRINGS (REPLACE-SUBSTRINGS (REPLACE-SUBSTRINGS STRING "\\\\" "\\") "\\\"" (MAKE-STRING 1 #\")) "\\n" (MAKE-STRING 1 #\Linefeed))
    "\\r" (MAKE-STRING 1 #\Return))
   "\"")
  :VOID)

;;; (DEFMETHOD IDL-OUTPUT-LITERAL ...)

(CL:DEFMETHOD IDL-OUTPUT-LITERAL ((STRING STRING-WRAPPER))
  (IDL-OUTPUT-LITERAL (%WRAPPER-VALUE STRING))
  :VOID)

;;; (DEFMETHOD IDL-OUTPUT-LITERAL ...)

(CL:DEFMETHOD IDL-OUTPUT-LITERAL ((STRING MUTABLE-STRING-WRAPPER))
  (IDL-OUTPUT-LITERAL (CL:LET ((S (%WRAPPER-VALUE STRING))) (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING S)) (CL:THE CL:SIMPLE-STRING S)))
  :VOID)

;;; (DEFMETHOD IDL-OUTPUT-LITERAL ...)

(CL:DEFMETHOD IDL-OUTPUT-LITERAL ((TREE QUOTED-EXPRESSION))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "\"" TREE "\"")
  :VOID)

;;; (DEFMETHOD IDL-OUTPUT-LITERAL ...)

(CL:DEFMETHOD IDL-OUTPUT-LITERAL ((SYMBOL SYMBOL))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE (IDL-TRANSLATE-SYMBOL-NAME SYMBOL)))
  :VOID)

;;; (DEFMETHOD IDL-OUTPUT-LITERAL ...)

(CL:DEFMETHOD IDL-OUTPUT-LITERAL ((SURROGATE SURROGATE))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE (IDL-TRANSLATE-SURROGATE-NAME SURROGATE)))
  :VOID)

;;; (DEFMETHOD IDL-OUTPUT-LITERAL ...)

(CL:DEFMETHOD IDL-OUTPUT-LITERAL ((KEYWORD KEYWORD))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE (IDL-TRANSLATE-KEYWORD-NAME KEYWORD)))
  :VOID)

;;; (DEFUN IDL-OUTPUT-ATOMIC-EXPRESSION ...)

(CL:DEFUN IDL-OUTPUT-ATOMIC-EXPRESSION (ATOM)
  (IDL-OUTPUT-LITERAL ATOM)
  :VOID)

;;; (DEFUN IDL-OUTPUT-COMMENT ...)

(CL:DEFUN IDL-OUTPUT-COMMENT (TREE)
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "// " (%WRAPPER-VALUE TREE) EOL)
  :VOID)

;;; (DEFUN IDL-OUTPUT-IDENTIFIER ...)

(CL:DEFUN IDL-OUTPUT-IDENTIFIER (IDENTIFIER)
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE IDENTIFIER))
  :VOID)

;;; (DEFUN IDL-OUTPUT-DERIVED-CLASSES ...)

(CL:DEFUN IDL-OUTPUT-DERIVED-CLASSES (CLASS-LIST)
  (CL:WHEN (CL:NOT (CL:EQ (%%VALUE CLASS-LIST) NULL)) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE (%%VALUE CLASS-LIST))))
  (CL:LET* ((CLASS NULL) (ITER-000 (%%REST CLASS-LIST)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ CLASS (%%VALUE ITER-000)) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) ", " (%WRAPPER-VALUE CLASS))
    (CL:SETQ ITER-000 (%%REST ITER-000))))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) " ")
  :VOID)

;;; (DEFUN IDL-OUTPUT-TEMPLATE-PARAMETERS ...)

(CL:DEFUN IDL-OUTPUT-TEMPLATE-PARAMETERS (PARAMETERS)
  (CL:WHEN (CL:NOT (CL:EQ PARAMETERS NIL)) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "template <class " (%WRAPPER-VALUE (%%VALUE PARAMETERS)))
   (CL:LET* ((PARAMETER NULL) (ITER-000 (%%REST PARAMETERS)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ PARAMETER (%%VALUE ITER-000))
     (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) ", class " (%WRAPPER-VALUE PARAMETER)) (CL:SETQ ITER-000 (%%REST ITER-000))))
   (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) ">" EOL))
  :VOID)

;;; (DEFUN (IDL-OUTPUT-TEMPLATE-CLASSES? BOOLEAN) ...)

(CL:DEFUN IDL-OUTPUT-TEMPLATE-CLASSES? ()
  (CL:RETURN-FROM IDL-OUTPUT-TEMPLATE-CLASSES? CL:T))

;;; (DEFUN IDL-OUTPUT-INTERFACE ...)

(CL:DEFUN IDL-OUTPUT-INTERFACE (CLASSDEF)
  (CL:WHEN (IDL-OUTPUT-TEMPLATE-CLASSES?) (IDL-OUTPUT-TEMPLATE-PARAMETERS (%%VALUE (%%REST CLASSDEF))))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "interface " (%WRAPPER-VALUE (%%VALUE CLASSDEF)) " ")
  (CL:WHEN (CL:NOT (CL:EQ (%%VALUE (%%REST (%%REST CLASSDEF))) NIL)) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) ": ")
   (IDL-OUTPUT-DERIVED-CLASSES (%%VALUE (%%REST (%%REST CLASSDEF)))))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "{" EOL)
  (CL:LET* ((STATEMENT NULL) (ITER-000 (NTH-REST CLASSDEF 4)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ STATEMENT (%%VALUE ITER-000)) (IDL-OUTPUT-STATEMENT STATEMENT) (CL:SETQ ITER-000 (%%REST ITER-000))))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "};" EOL EOL)
  :VOID)

;;; (DEFUN IDL-OUTPUT-STRUCT ...)

(CL:DEFUN IDL-OUTPUT-STRUCT (CLASSDEF)
  (CL:WHEN (IDL-OUTPUT-TEMPLATE-CLASSES?) (IDL-OUTPUT-TEMPLATE-PARAMETERS (%%VALUE (%%REST CLASSDEF))))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "struct " (%WRAPPER-VALUE (%%VALUE CLASSDEF)) " ")
  (CL:WHEN (CL:NOT (CL:EQ (%%VALUE (%%REST (%%REST CLASSDEF))) NIL)) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) ": ")
   (IDL-OUTPUT-DERIVED-CLASSES (%%VALUE (%%REST (%%REST CLASSDEF)))))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "{" EOL)
  (CL:LET* ((STATEMENT NULL) (ITER-000 (NTH-REST CLASSDEF 4)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ STATEMENT (%%VALUE ITER-000)) (IDL-OUTPUT-STATEMENT STATEMENT) (CL:SETQ ITER-000 (%%REST ITER-000))))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "};" EOL EOL)
  :VOID)

;;; (DEFUN IDL-OUTPUT-ONE-FORMAL-PARAMETER ...)

(CL:DEFUN IDL-OUTPUT-ONE-FORMAL-PARAMETER (PARAMETER)
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE (%%VALUE PARAMETER)) " " (%WRAPPER-VALUE (%%VALUE (%%REST PARAMETER))) " "
   (%WRAPPER-VALUE (%%VALUE (%%REST (%%REST PARAMETER)))))
  :VOID)

;;; (DEFUN IDL-OUTPUT-FORMAL-PARAMETERS ...)

(CL:DEFUN IDL-OUTPUT-FORMAL-PARAMETERS (PARAMETERS)
  (CL:LET* ((N-PARAMETERS (LENGTH PARAMETERS))) (CL:DECLARE (CL:TYPE CL:FIXNUM N-PARAMETERS)) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "(")
   (CL:LET* ((PARAMETER NULL) (ITER-000 PARAMETERS) (N NULL-INTEGER) (ITER-001 1) (UPPER-BOUND-000 N-PARAMETERS) (UNBOUNDED?-000 (CL:= UPPER-BOUND-000 NULL-INTEGER)))
    (CL:DECLARE (CL:TYPE CL:FIXNUM N ITER-001 UPPER-BOUND-000))
    (CL:LOOP WHILE (CL:AND (CL:NOT (CL:EQ ITER-000 NIL)) (CL:OR UNBOUNDED?-000 (CL:<= ITER-001 UPPER-BOUND-000))) DO (CL:SETQ PARAMETER (%%VALUE ITER-000))
     (CL:SETQ N ITER-001)
     (CL:IF (CL:= N N-PARAMETERS)
      (CL:IF (CL:EQ (%%VALUE PARAMETER) SYM-IDL-OUTPUT-STELLA-IDL_VAR_ARGS)
       (CL:PROGN (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "int ")
        (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE (%%VALUE (%%REST PARAMETER)))) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) ", ..."))
       (IDL-OUTPUT-ONE-FORMAL-PARAMETER PARAMETER))
      (CL:PROGN (IDL-OUTPUT-ONE-FORMAL-PARAMETER PARAMETER) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) ", ")))
     (CL:SETQ ITER-000 (%%REST ITER-000)) (CL:SETQ ITER-001 (CL:1+ ITER-001))))
   (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) ")"))
  :VOID)

;;; (DEFUN IDL-OUTPUT-FUNCTION-SIGNATURE ...)

(CL:DEFUN IDL-OUTPUT-FUNCTION-SIGNATURE (FUNCTION)
  (IDL-OUTPUT-TYPE-EXPRESSION (%%VALUE FUNCTION))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE (%%VALUE (%%REST FUNCTION))))
  (IDL-OUTPUT-FORMAL-PARAMETERS (%%VALUE (%%REST (%%REST FUNCTION))))
  :VOID)

;;; (DEFUN IDL-OUTPUT-DECLARATIONS ...)

(CL:DEFUN IDL-OUTPUT-DECLARATIONS (DECLARATIONS)
  (IDL-BUMP-INDENT)
  (CL:LET* ((DECLARATION NULL) (ITER-000 DECLARATIONS))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ DECLARATION (%%VALUE ITER-000)) (IDL-INDENT) (IDL-OUTPUT-TYPE-EXPRESSION (%%VALUE DECLARATION))
    (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE (%%VALUE (%%REST DECLARATION)))) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) ";" EOL)
    (CL:SETQ ITER-000 (%%REST ITER-000))))
  (IDL-UNBUMP-INDENT)
  :VOID)

;;; (DEFUN IDL-OUTPUT-SIGNATURE ...)

(CL:DEFUN IDL-OUTPUT-SIGNATURE (SIGNATURE OUTPUTMETHODCLASS?)
  (IDL-OUTPUT-TYPE-EXPRESSION (%%VALUE (%%REST SIGNATURE)))
  (CL:WHEN (CL:AND OUTPUTMETHODCLASS? (CL:NOT (CL:EQ (%%VALUE SIGNATURE) NULL))) (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE (%%VALUE SIGNATURE)))
   (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) "::"))
  (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) (%WRAPPER-VALUE (%%VALUE (%%REST (%%REST SIGNATURE)))))
  (IDL-OUTPUT-FORMAL-PARAMETERS (FOURTH SIGNATURE))
  :VOID)

;;; (DEFUN IDL-OUTPUT-SIGNATURES ...)

(CL:DEFUN IDL-OUTPUT-SIGNATURES (SIGNATURES)
  (IDL-INDENT)
  (IDL-BUMP-INDENT)
  (CL:LET* ((SIGNATURE NULL) (ITER-000 SIGNATURES))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO (CL:SETQ SIGNATURE (%%VALUE ITER-000)) (IDL-INDENT) (IDL-OUTPUT-SIGNATURE SIGNATURE CL:NIL)
    (%%PRINT-STREAM (%NATIVE-STREAM *CURRENT-STREAM*) ";" EOL) (CL:SETQ ITER-000 (%%REST ITER-000))))
  (IDL-UNBUMP-INDENT)
  :VOID)

(CL:DEFUN STARTUP-IDL-OUTPUT ()
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*)) (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2) (CL:SETQ SYM-IDL-OUTPUT-STELLA-IDL_COMMENT (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_COMMENT" NULL 0))
    (CL:SETQ SYM-IDL-OUTPUT-STELLA-IDL_TYPEDEF (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_TYPEDEF" NULL 0))
    (CL:SETQ SYM-IDL-OUTPUT-STELLA-IDL_ENUM (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_ENUM" NULL 0))
    (CL:SETQ SYM-IDL-OUTPUT-STELLA-IDL_INTERFACE (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_INTERFACE" NULL 0))
    (CL:SETQ SYM-IDL-OUTPUT-STELLA-IDL_STRUCT (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_STRUCT" NULL 0))
    (CL:SETQ SYM-IDL-OUTPUT-STELLA-IDL_DECLARATIONS (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_DECLARATIONS" NULL 0))
    (CL:SETQ SYM-IDL-OUTPUT-STELLA-IDL_IDENT (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_IDENT" NULL 0))
    (CL:SETQ SYM-IDL-OUTPUT-STELLA-IDL_TYPE (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_TYPE" NULL 0))
    (CL:SETQ SYM-IDL-OUTPUT-STELLA-IDL_SIGNATURES (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_SIGNATURES" NULL 0))
    (CL:SETQ SGT-IDL-OUTPUT-STELLA-CONS (INTERN-RIGID-SYMBOL-WRT-MODULE "CONS" NULL 1))
    (CL:SETQ SYM-IDL-OUTPUT-STELLA-IDL_VAR_ARGS (INTERN-RIGID-SYMBOL-WRT-MODULE "IDL_VAR_ARGS" NULL 0))
    (CL:SETQ SYM-IDL-OUTPUT-STELLA-STARTUP-IDL-OUTPUT (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-IDL-OUTPUT" NULL 0))
    (CL:SETQ SYM-IDL-OUTPUT-STELLA-METHOD-STARTUP-CLASSNAME (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-PARSE-TREE" "(DEFUN IDL-OUTPUT-PARSE-TREE ((CONSTREE CONS)))" (CL:FUNCTION IDL-OUTPUT-PARSE-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-STATEMENT" "(DEFUN IDL-OUTPUT-STATEMENT ((STATEMENT OBJECT)))" (CL:FUNCTION IDL-OUTPUT-STATEMENT) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-INDENT" "(DEFUN IDL-INDENT ())" (CL:FUNCTION IDL-INDENT) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-BUMP-INDENT" "(DEFUN IDL-BUMP-INDENT ())" (CL:FUNCTION IDL-BUMP-INDENT) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-UNBUMP-INDENT" "(DEFUN IDL-UNBUMP-INDENT ())" (CL:FUNCTION IDL-UNBUMP-INDENT) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-TYPEDEF" "(DEFUN IDL-OUTPUT-TYPEDEF ((TYPEDEF CONS)))" (CL:FUNCTION IDL-OUTPUT-TYPEDEF) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-ENUMERANDS" "(DEFUN IDL-OUTPUT-ENUMERANDS ((ENUMERANDS (CONS OF CONS))))" (CL:FUNCTION IDL-OUTPUT-ENUMERANDS) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-ENUM" "(DEFUN IDL-OUTPUT-ENUM ((ENUM CONS)))" (CL:FUNCTION IDL-OUTPUT-ENUM) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-TYPE-EXPRESSION" "(DEFUN IDL-OUTPUT-TYPE-EXPRESSION ((TYPEEXPRESSION (CONS OF STRING-WRAPPER))))"
     (CL:FUNCTION IDL-OUTPUT-TYPE-EXPRESSION) NULL)
    (DEFINE-METHOD-OBJECT "(DEFMETHOD IDL-OUTPUT-LITERAL ((OBJECT OBJECT)))" (CL:FUNCTION IDL-OUTPUT-LITERAL) NULL)
    (DEFINE-METHOD-OBJECT "(DEFMETHOD IDL-OUTPUT-LITERAL ((STRING STRING)))" (CL:FUNCTION IDL-OUTPUT-LITERAL) NULL)
    (DEFINE-METHOD-OBJECT "(DEFMETHOD IDL-OUTPUT-LITERAL ((STRING STRING-WRAPPER)))" (CL:FUNCTION IDL-OUTPUT-LITERAL) NULL)
    (DEFINE-METHOD-OBJECT "(DEFMETHOD IDL-OUTPUT-LITERAL ((STRING MUTABLE-STRING-WRAPPER)))" (CL:FUNCTION IDL-OUTPUT-LITERAL) NULL)
    (DEFINE-METHOD-OBJECT "(DEFMETHOD IDL-OUTPUT-LITERAL ((TREE QUOTED-EXPRESSION)))" (CL:FUNCTION IDL-OUTPUT-LITERAL) NULL)
    (DEFINE-METHOD-OBJECT "(DEFMETHOD IDL-OUTPUT-LITERAL ((SYMBOL SYMBOL)))" (CL:FUNCTION IDL-OUTPUT-LITERAL) NULL)
    (DEFINE-METHOD-OBJECT "(DEFMETHOD IDL-OUTPUT-LITERAL ((SURROGATE SURROGATE)))" (CL:FUNCTION IDL-OUTPUT-LITERAL) NULL)
    (DEFINE-METHOD-OBJECT "(DEFMETHOD IDL-OUTPUT-LITERAL ((KEYWORD KEYWORD)))" (CL:FUNCTION IDL-OUTPUT-LITERAL) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-ATOMIC-EXPRESSION" "(DEFUN IDL-OUTPUT-ATOMIC-EXPRESSION ((ATOM OBJECT)))" (CL:FUNCTION IDL-OUTPUT-ATOMIC-EXPRESSION) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-COMMENT" "(DEFUN IDL-OUTPUT-COMMENT ((TREE STRING-WRAPPER)))" (CL:FUNCTION IDL-OUTPUT-COMMENT) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-IDENTIFIER" "(DEFUN IDL-OUTPUT-IDENTIFIER ((IDENTIFIER STRING-WRAPPER)))" (CL:FUNCTION IDL-OUTPUT-IDENTIFIER) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-DERIVED-CLASSES" "(DEFUN IDL-OUTPUT-DERIVED-CLASSES ((CLASS-LIST (CONS OF STRING-WRAPPER))))"
     (CL:FUNCTION IDL-OUTPUT-DERIVED-CLASSES) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-TEMPLATE-PARAMETERS" "(DEFUN IDL-OUTPUT-TEMPLATE-PARAMETERS ((PARAMETERS (CONS OF STRING-WRAPPER))))"
     (CL:FUNCTION IDL-OUTPUT-TEMPLATE-PARAMETERS) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-TEMPLATE-CLASSES?" "(DEFUN (IDL-OUTPUT-TEMPLATE-CLASSES? BOOLEAN) ())" (CL:FUNCTION IDL-OUTPUT-TEMPLATE-CLASSES?) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-INTERFACE" "(DEFUN IDL-OUTPUT-INTERFACE ((CLASSDEF CONS)))" (CL:FUNCTION IDL-OUTPUT-INTERFACE) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-STRUCT" "(DEFUN IDL-OUTPUT-STRUCT ((CLASSDEF CONS)))" (CL:FUNCTION IDL-OUTPUT-STRUCT) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-ONE-FORMAL-PARAMETER" "(DEFUN IDL-OUTPUT-ONE-FORMAL-PARAMETER ((PARAMETER (CONS OF STRING-WRAPPER))))"
     (CL:FUNCTION IDL-OUTPUT-ONE-FORMAL-PARAMETER) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-FORMAL-PARAMETERS" "(DEFUN IDL-OUTPUT-FORMAL-PARAMETERS ((PARAMETERS (CONS OF CONS))))"
     (CL:FUNCTION IDL-OUTPUT-FORMAL-PARAMETERS) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-FUNCTION-SIGNATURE" "(DEFUN IDL-OUTPUT-FUNCTION-SIGNATURE ((FUNCTION CONS)))" (CL:FUNCTION IDL-OUTPUT-FUNCTION-SIGNATURE) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-DECLARATIONS" "(DEFUN IDL-OUTPUT-DECLARATIONS ((DECLARATIONS (CONS OF CONS))))" (CL:FUNCTION IDL-OUTPUT-DECLARATIONS) NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-SIGNATURE" "(DEFUN IDL-OUTPUT-SIGNATURE ((SIGNATURE CONS) (OUTPUTMETHODCLASS? BOOLEAN)))" (CL:FUNCTION IDL-OUTPUT-SIGNATURE)
     NULL)
    (DEFINE-FUNCTION-OBJECT "IDL-OUTPUT-SIGNATURES" "(DEFUN IDL-OUTPUT-SIGNATURES ((SIGNATURES CONS)))" (CL:FUNCTION IDL-OUTPUT-SIGNATURES) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-IDL-OUTPUT" "(DEFUN STARTUP-IDL-OUTPUT () :PUBLIC? TRUE)" (CL:FUNCTION STARTUP-IDL-OUTPUT) NULL)
    (CL:LET* ((FUNCTION (LOOKUP-FUNCTION SYM-IDL-OUTPUT-STELLA-STARTUP-IDL-OUTPUT)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION) SYM-IDL-OUTPUT-STELLA-METHOD-STARTUP-CLASSNAME (WRAP-STRING "_StartupIdlOutput") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS) (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9) (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "/STELLA")))
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE "(DEFSPECIAL *IDL-INDENT-CHARS* INTEGER 0)")))
  :VOID)
