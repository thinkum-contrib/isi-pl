;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; sessions.lisp

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
| Portions created by the Initial Developer are Copyright (C) 2003-2014      |
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

(CL:DEFVAR SGT-SESSIONS-HTTP-SESSION NULL)
(CL:DEFVAR SYM-SESSIONS-STELLA-NAME NULL)
(CL:DEFVAR SYM-SESSIONS-HTTP-TIMEOUT NULL)
(CL:DEFVAR SYM-SESSIONS-HTTP-TIMESTAMP NULL)
(CL:DEFVAR SYM-SESSIONS-HTTP-OBJECTS NULL)
(CL:DEFVAR SYM-SESSIONS-HTTP-STARTUP-SESSIONS NULL)
(CL:DEFVAR SYM-SESSIONS-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE*))

;;; (DEFGLOBAL *SESSION-TABLE* ...)

(CL:DEFVAR *SESSION-TABLE* NULL
  "System-wide session table; each session is indexed on a
globally unique session name.")

;;; (DEFGLOBAL *SESSIONS-LOCK* ...)

(CL:DEFVAR *SESSIONS-LOCK* NULL)

;;; (DEFCLASS SESSION ...)

(CL:DEFCLASS SESSION (DICTIONARY)
  ((NAME :TYPE CL:SIMPLE-STRING :INITFORM STELLA::NULL-STRING
    :DOCUMENTATION "UUID uniquely identifying this session."
    :ALLOCATION :INSTANCE :ACCESSOR %NAME)
   (TIMEOUT :DOCUMENTATION
    "Timeout duration of session; NULL means no timeout." :ALLOCATION
    :INSTANCE :ACCESSOR %TIMEOUT)
   (TIMESTAMP :DOCUMENTATION "Time this object was last accessed."
    :ALLOCATION :INSTANCE :ACCESSOR %TIMESTAMP)
   (OBJECTS :DOCUMENTATION
    "Table of session-related objects indexed on string keys."
    :ALLOCATION :INSTANCE :ACCESSOR %OBJECTS))
  (:DOCUMENTATION
   "Object storing the state associated with a single session.
All session-related information is stored in a table indexed on string keys."))

(CL:DEFUN NEW-SESSION ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE SESSION)))
   (CL:SETF (%OBJECTS SELF) (NEW-KEY-VALUE-MAP))
   (CL:SETF (%TIMESTAMP SELF) (MAKE-CURRENT-DATE-TIME))
   (CL:SETF (%TIMEOUT SELF) NULL)
   (CL:SETF (%NAME SELF) STELLA::NULL-STRING) SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF SESSION))
  SGT-SESSIONS-HTTP-SESSION)

(CL:DEFUN ACCESS-SESSION-SLOT-VALUE (SELF SLOTNAME VALUE SETVALUE?)
  (CL:COND
   ((CL:EQ SLOTNAME SYM-SESSIONS-STELLA-NAME)
    (CL:IF SETVALUE? (CL:SETF (%NAME SELF) (%WRAPPER-VALUE VALUE))
     (CL:SETQ VALUE (WRAP-STRING (%NAME SELF)))))
   ((CL:EQ SLOTNAME SYM-SESSIONS-HTTP-TIMEOUT)
    (CL:IF SETVALUE? (CL:SETF (%TIMEOUT SELF) VALUE)
     (CL:SETQ VALUE (%TIMEOUT SELF))))
   ((CL:EQ SLOTNAME SYM-SESSIONS-HTTP-TIMESTAMP)
    (CL:IF SETVALUE? (CL:SETF (%TIMESTAMP SELF) VALUE)
     (CL:SETQ VALUE (%TIMESTAMP SELF))))
   ((CL:EQ SLOTNAME SYM-SESSIONS-HTTP-OBJECTS)
    (CL:IF SETVALUE? (CL:SETF (%OBJECTS SELF) VALUE)
     (CL:SETQ VALUE (%OBJECTS SELF))))
   (CL:T
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" SLOTNAME
      "' is not a valid case option")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))
  VALUE)

;;; (DEFGLOBAL *SESSION-TABLE-CLEANUP-COUNTER* ...)

(CL:DEFVAR *SESSION-TABLE-CLEANUP-COUNTER* 0)
(CL:DECLAIM (CL:TYPE CL:FIXNUM *SESSION-TABLE-CLEANUP-COUNTER*))

;;; (DEFUN CLEANUP-SESSION-TABLE ...)

(CL:DEFUN CLEANUP-SESSION-TABLE ()
  (CL:SETQ *SESSION-TABLE-CLEANUP-COUNTER*
   (CL:1+ *SESSION-TABLE-CLEANUP-COUNTER*))
  (CL:WHEN (CL:= (MOD *SESSION-TABLE-CLEANUP-COUNTER* 100) 0)
   (WITH-PROCESS-LOCK *SESSIONS-LOCK*
    (CL:LET*
     ((NAME NULL) (SESSION NULL)
      (ITER-000 (ALLOCATE-ITERATOR *SESSION-TABLE*)))
     (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ NAME (%KEY ITER-000))
      (CL:SETQ SESSION (%VALUE ITER-000))
      (CL:WHEN (TIMED-OUT? SESSION)
       (REMOVE-AT *SESSION-TABLE* NAME)))))))

;;; (DEFUN (LOOKUP-SESSION SESSION) ...)

(CL:DEFUN LOOKUP-SESSION (NAME ERRORIFTIMEOUT?)
  "Retrieve an existing session object with `name' if it exists, NULL otherwise.
If a session was found but has timed out, raise an error if `errorIfTimeout?' is true,
otherwise, return the timed-out session.  Bumps the timestamp on existing sessions that
haven't yet timed out."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING NAME))
  #+MCL
  (CL:CHECK-TYPE NAME CL:SIMPLE-STRING)
  (CL:LET* ((SESSION (LOOKUP *SESSION-TABLE* (WRAP-STRING NAME))))
   (CL:WHEN (CL:NOT (CL:EQ SESSION NULL))
    (CL:IF (TIMED-OUT? SESSION)
     (CL:WHEN ERRORIFTIMEOUT?
      (CL:ERROR
       (NEW-TIMEOUT-EXCEPTION
        (CONCATENATE "lookup-session: session timed out: " NAME))))
     (REFRESH SESSION)))
   SESSION))

;;; (DEFUN (CREATE-SESSION SESSION) ...)

(CL:DEFUN CREATE-SESSION (NAME TIMEOUT)
  "Create a new session object with `name' (replacing any existing
sessions with the same name).  If `name' is NULL, generate a random UUID for it.
Timeout after `timeout' seconds or never in case the value is <= 0 or undefined."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING NAME)
   (CL:TYPE CL:FIXNUM TIMEOUT))
  #+MCL
  (CL:CHECK-TYPE NAME CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE TIMEOUT CL:FIXNUM)
  (CL:LET* ((SESSION (NEW-SESSION)))
   (CL:WHEN (CL:EQ NAME STELLA::NULL-STRING)
    (CL:SETQ NAME (GENERATE-RANDOM-UUID)))
   (CL:SETF (%NAME SESSION) NAME)
   (CL:WHEN (CL:> TIMEOUT 0)
    (CL:SETF (%TIMEOUT SESSION)
     (MAKE-TIME-DURATION 0 (CL:* TIMEOUT 1000))))
   (WITH-PROCESS-LOCK *SESSIONS-LOCK*
    (INSERT-AT *SESSION-TABLE* (WRAP-STRING NAME) SESSION))
   (CLEANUP-SESSION-TABLE) SESSION))

;;; (DEFUN (GET-SESSION SESSION) ...)

(CL:DEFUN GET-SESSION (NAME ERRORIFTIMEOUT? TIMEOUT)
  "Retrieve an existing session object with `name' if it exists or create a new one.
If `name' is NULL, generate a random UUID for it.  If an existing object was found but has timed
out, raise an error if `errorIfTimeout?' is true.  If a new object is created, initialize its
timeout field with `timeout' seconds (0 or undefined means no timeout)."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING NAME)
   (CL:TYPE CL:FIXNUM TIMEOUT))
  #+MCL
  (CL:CHECK-TYPE NAME CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE TIMEOUT CL:FIXNUM)
  (CL:IF (CL:EQ NAME STELLA::NULL-STRING)
   (CREATE-SESSION STELLA::NULL-STRING TIMEOUT)
   (CL:LET* ((SESSION (LOOKUP-SESSION NAME ERRORIFTIMEOUT?)))
    (CL:WHEN (CL:EQ SESSION NULL)
     (CL:SETQ SESSION (CREATE-SESSION NAME TIMEOUT)))
    SESSION)))

;;; (DEFMETHOD (TIMED-OUT? BOOLEAN) ...)

(CL:DEFMETHOD TIMED-OUT? ((SESSION SESSION))
  "Return TRUE if `session' has timed out."
  (CL:LET*
   ((TIMEOUT (%TIMEOUT SESSION)) (TIMESTAMP (%TIMESTAMP SESSION)))
   (CL:IF (CL:EQ TIMEOUT NULL) CL:NIL
    (GREATER? (TIME-SUBTRACT (MAKE-CURRENT-DATE-TIME) TIMESTAMP)
     TIMEOUT))))

;;; (DEFMETHOD REFRESH ...)

(CL:DEFMETHOD REFRESH ((SESSION SESSION))
  "Bump the timestamp of `session'."
  (CL:LET* ((TIMEOUT (%TIMEOUT SESSION)))
   (CL:WHEN (CL:NOT (CL:EQ TIMEOUT NULL))
    (CL:SETF (%TIMESTAMP SESSION) (MAKE-CURRENT-DATE-TIME)))))

;;; (DEFMETHOD (LOOKUP OBJECT) ...)

(CL:DEFMETHOD LOOKUP ((SESSION SESSION) KEY)
  "Retrieve a value from a `session' based on `key'."
  (LOOKUP (%OBJECTS SESSION) KEY))

;;; (DEFMETHOD INSERT-AT ...)

(CL:DEFMETHOD INSERT-AT ((SESSION SESSION) KEY VALUE)
  "Associate `key' with `value' on `session'."
  (INSERT-AT (%OBJECTS SESSION) KEY VALUE))

(CL:DEFUN STARTUP-SESSIONS ()
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE "/HTTP" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ SGT-SESSIONS-HTTP-SESSION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SESSION" NULL 1))
    (CL:SETQ SYM-SESSIONS-STELLA-NAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "NAME"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-SESSIONS-HTTP-TIMEOUT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "TIMEOUT" NULL 0))
    (CL:SETQ SYM-SESSIONS-HTTP-TIMESTAMP
     (INTERN-RIGID-SYMBOL-WRT-MODULE "TIMESTAMP" NULL 0))
    (CL:SETQ SYM-SESSIONS-HTTP-OBJECTS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "OBJECTS" NULL 0))
    (CL:SETQ SYM-SESSIONS-HTTP-STARTUP-SESSIONS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-SESSIONS" NULL 0))
    (CL:SETQ SYM-SESSIONS-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ *SESSION-TABLE* (NEW-KEY-VALUE-MAP))
    (CL:SETQ *SESSIONS-LOCK* (MAKE-PROCESS-LOCK)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 5)
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "SESSION"
        "(DEFCLASS SESSION (DICTIONARY) :DOCUMENTATION \"Object storing the state associated with a single session.
All session-related information is stored in a table indexed on string keys.\" :PARAMETERS ((ANY-KEY :TYPE STRING-WRAPPER) (ANY-VALUE :TYPE OBJECT)) :SLOTS ((NAME :TYPE STRING :INITIALLY NULL :PUBLIC? TRUE :DOCUMENTATION \"UUID uniquely identifying this session.\") (TIMEOUT :TYPE TIME-DURATION :INITIALLY NULL :DOCUMENTATION \"Timeout duration of session; NULL means no timeout.\") (TIMESTAMP :TYPE CALENDAR-DATE :INITIALLY (MAKE-CURRENT-DATE-TIME) :DOCUMENTATION \"Time this object was last accessed.\") (OBJECTS :TYPE (KEY-VALUE-MAP OF STRING-WRAPPER OBJECT) :DOCUMENTATION \"Table of session-related objects indexed on string keys.\" :INITIALLY (NEW KEY-VALUE-MAP))))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS)
      (CL:FUNCTION NEW-SESSION))
     (CL:SETF (%CLASS-SLOT-ACCESSOR-CODE CLASS)
      (CL:FUNCTION ACCESS-SESSION-SLOT-VALUE))))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "CLEANUP-SESSION-TABLE"
     "(DEFUN CLEANUP-SESSION-TABLE ())"
     (CL:FUNCTION CLEANUP-SESSION-TABLE) NULL)
    (DEFINE-FUNCTION-OBJECT "LOOKUP-SESSION"
     "(DEFUN (LOOKUP-SESSION SESSION) ((NAME STRING) (ERRORIFTIMEOUT? BOOLEAN)) :DOCUMENTATION \"Retrieve an existing session object with `name' if it exists, NULL otherwise.
If a session was found but has timed out, raise an error if `errorIfTimeout?' is true,
otherwise, return the timed-out session.  Bumps the timestamp on existing sessions that
haven't yet timed out.\" :PUBLIC? TRUE)" (CL:FUNCTION LOOKUP-SESSION)
     NULL)
    (DEFINE-FUNCTION-OBJECT "CREATE-SESSION"
     "(DEFUN (CREATE-SESSION SESSION) ((NAME STRING) (TIMEOUT INTEGER)) :DOCUMENTATION \"Create a new session object with `name' (replacing any existing
sessions with the same name).  If `name' is NULL, generate a random UUID for it.
Timeout after `timeout' seconds or never in case the value is <= 0 or undefined.\" :PUBLIC? TRUE)"
     (CL:FUNCTION CREATE-SESSION) NULL)
    (DEFINE-FUNCTION-OBJECT "GET-SESSION"
     "(DEFUN (GET-SESSION SESSION) ((NAME STRING) (ERRORIFTIMEOUT? BOOLEAN) (TIMEOUT INTEGER)) :DOCUMENTATION \"Retrieve an existing session object with `name' if it exists or create a new one.
If `name' is NULL, generate a random UUID for it.  If an existing object was found but has timed
out, raise an error if `errorIfTimeout?' is true.  If a new object is created, initialize its
timeout field with `timeout' seconds (0 or undefined means no timeout).\" :PUBLIC? TRUE)"
     (CL:FUNCTION GET-SESSION) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (TIMED-OUT? BOOLEAN) ((SESSION SESSION)) :DOCUMENTATION \"Return TRUE if `session' has timed out.\" :PUBLIC? TRUE)"
     (CL:FUNCTION TIMED-OUT?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD REFRESH ((SESSION SESSION)) :DOCUMENTATION \"Bump the timestamp of `session'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION REFRESH) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LOOKUP OBJECT) ((SESSION SESSION) (KEY STRING-WRAPPER)) :DOCUMENTATION \"Retrieve a value from a `session' based on `key'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LOOKUP) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD INSERT-AT ((SESSION SESSION) (KEY STRING-WRAPPER) (VALUE OBJECT)) :DOCUMENTATION \"Associate `key' with `value' on `session'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION INSERT-AT) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-SESSIONS"
     "(DEFUN STARTUP-SESSIONS () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-SESSIONS) NULL)
    (CL:LET*
     ((FUNCTION (LOOKUP-FUNCTION SYM-SESSIONS-HTTP-STARTUP-SESSIONS)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-SESSIONS-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupSessions") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "HTTP")))
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *SESSION-TABLE* (KEY-VALUE-MAP OF STRING-WRAPPER SESSION) (NEW KEY-VALUE-MAP) :DOCUMENTATION \"System-wide session table; each session is indexed on a
globally unique session name.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *SESSIONS-LOCK* PROCESS-LOCK-OBJECT (MAKE-PROCESS-LOCK))")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *SESSION-TABLE-CLEANUP-COUNTER* INTEGER 0)"))))
