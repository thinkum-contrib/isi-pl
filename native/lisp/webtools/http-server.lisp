;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; http-server.lisp

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

(CL:DEFVAR SYM-HTTP-SERVER-HTTP-HTTP-SERVER-EXIT-HOOK NULL)
(CL:DEFVAR SYM-HTTP-SERVER-HTTP-START-HTTP-SERVER NULL)
(CL:DEFVAR KWD-HTTP-SERVER-COMMON-LISP NULL)
(CL:DEFVAR KWD-HTTP-SERVER-FUNCTION NULL)
(CL:DEFVAR KWD-HTTP-SERVER-OK NULL)
(CL:DEFVAR KWD-HTTP-SERVER-REDIRECT NULL)
(CL:DEFVAR KWD-HTTP-SERVER-FORBIDDEN NULL)
(CL:DEFVAR KWD-HTTP-SERVER-NOT-FOUND NULL)
(CL:DEFVAR KWD-HTTP-SERVER-BAD-REQUEST NULL)
(CL:DEFVAR KWD-HTTP-SERVER-INTERNAL-ERROR NULL)
(CL:DEFVAR KWD-HTTP-SERVER-NOT-IMPLEMENTED NULL)
(CL:DEFVAR KWD-HTTP-SERVER-PLAIN-TEXT NULL)
(CL:DEFVAR KWD-HTTP-SERVER-HTML NULL)
(CL:DEFVAR KWD-HTTP-SERVER-XML NULL)
(CL:DEFVAR KWD-HTTP-SERVER-BINARY NULL)
(CL:DEFVAR KWD-HTTP-SERVER-IMAGE-GIF NULL)
(CL:DEFVAR KWD-HTTP-SERVER-IMAGE-JPG NULL)
(CL:DEFVAR KWD-HTTP-SERVER-IMAGE-PNG NULL)
(CL:DEFVAR KWD-HTTP-SERVER-AUDIO-MPEG NULL)
(CL:DEFVAR KWD-HTTP-SERVER-PDF NULL)
(CL:DEFVAR KWD-HTTP-SERVER-MSWORD NULL)
(CL:DEFVAR KWD-HTTP-SERVER-HANDLER-TYPE NULL)
(CL:DEFVAR KWD-HTTP-SERVER-FILE NULL)
(CL:DEFVAR KWD-HTTP-SERVER-DIRECTORY NULL)
(CL:DEFVAR KWD-HTTP-SERVER-HANDLER NULL)
(CL:DEFVAR KWD-HTTP-SERVER-CONTENT-TYPE NULL)
(CL:DEFVAR KWD-HTTP-SERVER-PATH NULL)
(CL:DEFVAR KWD-HTTP-SERVER-DOCUMENTATION NULL)
(CL:DEFVAR SYM-HTTP-SERVER-STELLA-LOAD-SYSTEM NULL)
(CL:DEFVAR KWD-HTTP-SERVER-GET NULL)
(CL:DEFVAR KWD-HTTP-SERVER-POST NULL)
(CL:DEFVAR SYM-HTTP-SERVER-HTTP-STARTUP-HTTP-SERVER NULL)
(CL:DEFVAR SYM-HTTP-SERVER-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE* EOL NULL-INTEGER NIL
  STANDARD-OUTPUT *STELLA-EXIT-HOOKS*))

;;; (DEFCLASS HTTP-SERVER ...)

(CL:DEFCLASS HTTP-SERVER (STANDARD-OBJECT)
  ()
  (:DOCUMENTATION
   "Abstract class that will be implemented by specific server implementations
and instantiated with a single instance used to dispatch all API methods."))

;;; (DEFGLOBAL *HTTP-SERVER-IMPLEMENTATION* ...)

(CL:DEFVAR *HTTP-SERVER-IMPLEMENTATION* NULL
  "Server instance used for method dispatch - not to be confused
with an actual native server object.")

;;; (DEFUN (GET-DEFAULT-HTTP-SERVER-IMPL STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING)
  GET-DEFAULT-HTTP-SERVER-IMPL))
(CL:DEFUN GET-DEFAULT-HTTP-SERVER-IMPL (ERROR?)
  "Return a default HTTP server implementation system for the case
where none has been loaded yet.  If `error?' is TRUE, raise an error if none
is defined for the current native language environment."
  (CL:IF (CL:or (CL:member :allegro CL:*features*)
                               (CL:find-package :net.aserve)
                               (CL:let ((loader-function-symbol (CL:find-symbol "LOAD-ASERVE"
                                                                                "CL-USER")))
                                   (CL:and loader-function-symbol
                                           (CL:fboundp loader-function-symbol))))
   "webtools-aserve"
   (CL:WHEN ERROR?
    (CL:ERROR
     (NEW-STELLA-EXCEPTION "HTTP server not supported in this Lisp")))))

;;; (DEFGLOBAL *DEFAULT-HTTP-SERVER-PORT* ...)

(CL:DEFVAR *DEFAULT-HTTP-SERVER-PORT* 9090)
(CL:DECLAIM (CL:TYPE CL:FIXNUM *DEFAULT-HTTP-SERVER-PORT*))

;;; (DEFUN (START-HTTP-SERVER STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:FIXNUM) CL:SIMPLE-STRING)
  %START-HTTP-SERVER))
(CL:DEFUN %START-HTTP-SERVER (PORT)
  "Start an HTTP server running at `port'.  If there is already
a server instance running, it will be stopped first.  If `port' is <= 0 or
NULL, use the value of `*default-http-server-port*'.  Returns the listening
address of the started server instance."
  (CL:DECLARE (CL:TYPE CL:FIXNUM PORT))
  #+MCL
  (CL:CHECK-TYPE PORT CL:FIXNUM)
  (CL:WHEN (CL:EQ *HTTP-SERVER-IMPLEMENTATION* NULL)
   (AUTOLOAD "HTTP-SERVER-IMPL-SYSTEM"
    (GET-DEFAULT-HTTP-SERVER-IMPL CL:T) NULL CL:NIL)
   (CL:WHEN (CL:EQ *HTTP-SERVER-IMPLEMENTATION* NULL)
    (CL:ERROR
     (NEW-STELLA-EXCEPTION
      "start-http-server: no HTTP server implementation loaded"))))
  (CL:WHEN (CL:<= PORT 0) (CL:SETQ PORT *DEFAULT-HTTP-SERVER-PORT*))
  (CL:LET*
   ((TEMP-000
     (START-HTTP-SERVER-IMPL *HTTP-SERVER-IMPLEMENTATION* PORT)))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING TEMP-000))
   (CL:LET*
    ((ADDRESS
      (CL:IF (CL:NOT (CL:EQ TEMP-000 STELLA::NULL-STRING)) TEMP-000
       (CONCATENATE "http://localhost:"
        (INTEGER-TO-STRING (CL:TRUNCATE PORT)) "/"))))
    (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING ADDRESS))
    (ADD-HOOK *STELLA-EXIT-HOOKS*
     SYM-HTTP-SERVER-HTTP-HTTP-SERVER-EXIT-HOOK)
    (PUBLISH-REGISTERED-HTTP-HANDLERS) ADDRESS)))

(CL:DEFUN START-HTTP-SERVER-EVALUATOR-WRAPPER (ARGUMENTS)
  (CL:LET*
   ((RESULT (%START-HTTP-SERVER (%WRAPPER-VALUE (%%VALUE ARGUMENTS)))))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING RESULT))
   (CL:IF (CL:NOT (CL:EQ RESULT STELLA::NULL-STRING))
    (WRAP-STRING RESULT) NULL)))

(CL:DEFMACRO START-HTTP-SERVER (CL:&WHOLE EXPRESSION CL:&REST IGNORE)
  "Start an HTTP server running at `port'.  If there is already
a server instance running, it will be stopped first.  If `port' is <= 0 or
NULL, use the value of `*default-http-server-port*'.  Returns the listening
address of the started server instance."
  (CL:DECLARE (CL:IGNORE IGNORE))
  (CL:LET ((*IGNORETRANSLATIONERRORS?* FALSE))
   (CL-INCREMENTALLY-TRANSLATE EXPRESSION)))

(CL:SETF (CL:MACRO-FUNCTION (CL:QUOTE |/HTTP/START-HTTP-SERVER|)) (CL:MACRO-FUNCTION (CL:QUOTE START-HTTP-SERVER)))

;;; (DEFMETHOD (START-HTTP-SERVER-IMPL STRING) ...)

(CL:DEFMETHOD START-HTTP-SERVER-IMPL ((SERVER HTTP-SERVER) PORT)
  (CL:DECLARE (CL:TYPE CL:FIXNUM PORT))
  #+MCL
  (CL:CHECK-TYPE PORT CL:FIXNUM)
  (CL:SETQ PORT PORT)
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "start-http-server-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN STOP-HTTP-SERVER ...)

(CL:DEFUN STOP-HTTP-SERVER ()
  "Stop any currently running HTTP server.  If there is no
server instance running, this is a no-op."
  (CL:WHEN (CL:EQ *HTTP-SERVER-IMPLEMENTATION* NULL)
   (AUTOLOAD "HTTP-SERVER-IMPL-SYSTEM"
    (GET-DEFAULT-HTTP-SERVER-IMPL CL:T) NULL CL:NIL)
   (CL:WHEN (CL:EQ *HTTP-SERVER-IMPLEMENTATION* NULL)
    (CL:ERROR
     (NEW-STELLA-EXCEPTION
      "stop-http-server: no HTTP server implementation loaded"))))
  (STOP-HTTP-SERVER-IMPL *HTTP-SERVER-IMPLEMENTATION*))

;;; (DEFMETHOD STOP-HTTP-SERVER-IMPL ...)

(CL:DEFMETHOD STOP-HTTP-SERVER-IMPL ((SERVER HTTP-SERVER))
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "stop-http-server-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN HTTP-SERVER-EXIT-HOOK ...)

(CL:DEFUN HTTP-SERVER-EXIT-HOOK (ARGUMENT)
  "Hook function that will be called upon PowerLoom exit.
This is a no-op if no server is running or if the server is not supported."
  (CL:SETQ ARGUMENT ARGUMENT)
  (CL:WHEN (CL:NOT (CL:EQ *HTTP-SERVER-IMPLEMENTATION* NULL))
   (CL:HANDLER-CASE (STOP-HTTP-SERVER)
    (CL:CONDITION (E)
     (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
      "ERROR: http-server-exit-hook: " (EXCEPTION-MESSAGE E))))))

;;; (DEFCLASS HTTP-EXCHANGE ...)

(CL:DEFCLASS HTTP-EXCHANGE (STANDARD-OBJECT)
  ()
  (:DOCUMENTATION
   "Abstract class that represents exchange objects that encapsulate all necessary
state needed by a http handler function to understand the request and generate the
appropriate response.  This is mirrored somewhat after Sun's basic HTTP server
implementation in com.sun.net.httpserver."))

;;; (DEFUN (GET-HEADER-VALUE STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T CL:T) CL:SIMPLE-STRING) GET-HEADER-VALUE))
(CL:DEFUN GET-HEADER-VALUE (XCHG KEY)
  "Returns the value associated with `key' in `xchg's request
headers represented as a string.  If no value is found, NULL will be returned.
If there are multiple values, an arbitrary one will be returned."
  (GET-HEADER-VALUE-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG KEY))

;;; (DEFMETHOD (GET-HEADER-VALUE-IMPL STRING) ...)

(CL:DEFMETHOD GET-HEADER-VALUE-IMPL ((SERVER HTTP-SERVER) XCHG KEY)
  (CL:PROGN (CL:SETQ XCHG XCHG) (CL:SETQ KEY KEY))
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "get-header-value-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN SET-REPLY-HEADER-VALUE ...)

(CL:DEFUN SET-REPLY-HEADER-VALUE (XCHG KEY VALUE)
  "Set the value associated with `key' in `xchg's reply headers to `value'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING VALUE))
  #+MCL
  (CL:CHECK-TYPE VALUE CL:SIMPLE-STRING)
  (SET-REPLY-HEADER-VALUE-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG KEY
   VALUE))

;;; (DEFMETHOD SET-REPLY-HEADER-VALUE-IMPL ...)

(CL:DEFMETHOD SET-REPLY-HEADER-VALUE-IMPL ((SERVER HTTP-SERVER) XCHG KEY VALUE)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING VALUE))
  #+MCL
  (CL:CHECK-TYPE VALUE CL:SIMPLE-STRING)
  (CL:PROGN (CL:SETQ XCHG XCHG) (CL:SETQ KEY KEY) (CL:SETQ VALUE VALUE))
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "set-reply-header-value-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN (GET-REQUEST-URI STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING) GET-REQUEST-URI))
(CL:DEFUN GET-REQUEST-URI (XCHG)
  "Return the raw URI associated with `xchg' as a string.  It is ensured
that any URI-encoded characters are not yet decoded to facilitate further parsing.
This does not include any protocol/scheme and host/port information.  For example, if
the user typed http://a.b.c:42/foo/bar.html#frag?a+b+c into the client, this function
will return /foo/bar.html#frag?a+b+c ."
  (GET-REQUEST-URI-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG))

;;; (DEFMETHOD (GET-REQUEST-URI-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-URI-IMPL ((SERVER HTTP-SERVER) XCHG)
  (CL:SETQ XCHG XCHG)
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "get-request-uri-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN (GET-REQUEST-URI-QUERY STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING) GET-REQUEST-URI-QUERY))
(CL:DEFUN GET-REQUEST-URI-QUERY (XCHG)
  "Return the raw query portion of the URI associated with `xchg'.  It is ensured
that any URI-encoded characters are not yet decoded to facilitate further parsing.  For example,
if the user typed http://a.b.c:42/foo/bar.html#frag?a+b+c into the client, this function will
return a+b+c ."
  (GET-REQUEST-URI-QUERY-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG))

;;; (DEFMETHOD (GET-REQUEST-URI-QUERY-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-URI-QUERY-IMPL ((SERVER HTTP-SERVER) XCHG)
  (CL:SETQ XCHG XCHG)
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "get-request-uri-query-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN (GET-REQUEST-URI-PATH STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING) GET-REQUEST-URI-PATH))
(CL:DEFUN GET-REQUEST-URI-PATH (XCHG)
  "Return the raw path portion of the URI associated with `xchg'.  It is ensured
that any URI-encoded characters are not yet decoded to facilitate further parsing.  For example,
if the user typed http://a.b.c:42/foo/bar.html#frag?a+b+c into the client, this function will
return /foo/bar.html."
  (GET-REQUEST-URI-PATH-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG))

;;; (DEFMETHOD (GET-REQUEST-URI-PATH-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-URI-PATH-IMPL ((SERVER HTTP-SERVER) XCHG)
  (CL:SETQ XCHG XCHG)
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "get-request-uri-path-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN (GET-REQUEST-METHOD KEYWORD) ...)

(CL:DEFUN GET-REQUEST-METHOD (XCHG)
  "Return the method associated with `xchg' (:get, :put or :post)."
  (GET-REQUEST-METHOD-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG))

;;; (DEFMETHOD (GET-REQUEST-METHOD-IMPL KEYWORD) ...)

(CL:DEFMETHOD GET-REQUEST-METHOD-IMPL ((SERVER HTTP-SERVER) XCHG)
  (CL:SETQ XCHG XCHG)
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "get-request-method-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN (GET-REQUEST-BODY STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING) GET-REQUEST-BODY))
(CL:DEFUN GET-REQUEST-BODY (XCHG)
  "Returns the body of `xchg' as a string.  If there was no body (e.g.,
if this was a GET), the result will be the empty string."
  (GET-REQUEST-BODY-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG))

;;; (DEFMETHOD (GET-REQUEST-BODY-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-BODY-IMPL ((SERVER HTTP-SERVER) XCHG)
  (CL:SETQ XCHG XCHG)
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "get-request-body-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN (GET-REQUEST-LOCAL-ADDRESS STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING)
  GET-REQUEST-LOCAL-ADDRESS))
(CL:DEFUN GET-REQUEST-LOCAL-ADDRESS (XCHG)
  "Returns the local-address that received `xchg' as a string.
Concatenates the hostname with a port in standard : notation.  If the hostname
can be resolved it will be, otherwise a numeric representation will be returned.
Note that different implementations have slightly different behavior."
  (GET-REQUEST-LOCAL-ADDRESS-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG))

;;; (DEFMETHOD (GET-REQUEST-LOCAL-ADDRESS-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-LOCAL-ADDRESS-IMPL ((SERVER HTTP-SERVER) XCHG)
  (CL:SETQ XCHG XCHG)
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "get-request-local-address-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN (GET-REQUEST-REMOTE-ADDRESS STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING)
  GET-REQUEST-REMOTE-ADDRESS))
(CL:DEFUN GET-REQUEST-REMOTE-ADDRESS (XCHG)
  "Returns the remote-address that sent `xchg' as a string.
Concatenates the hostname with a port in standard : notation.  If the hostname
can be resolved it will be, otherwise a numeric representation will be returned.
Note that different implementations have slightly different behavior."
  (GET-REQUEST-REMOTE-ADDRESS-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG))

;;; (DEFMETHOD (GET-REQUEST-REMOTE-ADDRESS-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-REMOTE-ADDRESS-IMPL ((SERVER HTTP-SERVER) XCHG)
  (CL:SETQ XCHG XCHG)
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "get-request-remote-address-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN (GET-REPLY-STREAM NATIVE-OUTPUT-STREAM) ...)

(CL:DEFUN GET-REPLY-STREAM (XCHG)
  "Return the stream to which response methods have to write their output."
  (GET-REPLY-STREAM-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG))

;;; (DEFMETHOD (GET-REPLY-STREAM-IMPL NATIVE-OUTPUT-STREAM) ...)

(CL:DEFMETHOD GET-REPLY-STREAM-IMPL ((SERVER HTTP-SERVER) XCHG)
  (CL:SETQ XCHG XCHG)
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "get-reply-stream-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN SET-RESPONSE-CODE ...)

(CL:DEFUN SET-RESPONSE-CODE (XCHG CODE)
  "Set the response code of the generated reply to `code'.  By default
:OK (code 200) is used."
  (SET-RESPONSE-CODE-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG CODE))

;;; (DEFMETHOD SET-RESPONSE-CODE-IMPL ...)

(CL:DEFMETHOD SET-RESPONSE-CODE-IMPL ((SERVER HTTP-SERVER) XCHG CODE)
  (CL:PROGN (CL:SETQ XCHG XCHG) (CL:SETQ CODE CODE))
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "set-response-code-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFGLOBAL *HTTP-RESPONSE-CODES* ...)

(CL:DEFVAR *HTTP-RESPONSE-CODES* NULL)

;;; (DEFGLOBAL *HTTP-MIME-TYPES* ...)

(CL:DEFVAR *HTTP-MIME-TYPES* NULL)

;;; (DEFUN (GET-HTTP-RESPONSE-CODE INTEGER) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T CL:T) CL:FIXNUM) GET-HTTP-RESPONSE-CODE))
(CL:DEFUN GET-HTTP-RESPONSE-CODE (CODENAME DEFAULT)
  (CL:LET* ((ENTRY NULL) (ITER-000 *HTTP-RESPONSE-CODES*))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
    (CL:SETQ ENTRY (%%VALUE ITER-000))
    (CL:WHEN (CL:EQ (%%VALUE ENTRY) CODENAME)
     (CL:RETURN-FROM GET-HTTP-RESPONSE-CODE
      (%WRAPPER-VALUE (%%VALUE (%%REST ENTRY)))))
    (CL:SETQ ITER-000 (%%REST ITER-000))))
  (CL:IF (CL:EQ DEFAULT NULL)
   (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
     "get-http-response-code: undefined response code: `" CODENAME "'")
    (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))
   (GET-HTTP-RESPONSE-CODE DEFAULT NULL)))

;;; (DEFUN (GET-HTTP-RESPONSE-DESC STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T CL:T) CL:SIMPLE-STRING)
  GET-HTTP-RESPONSE-DESC))
(CL:DEFUN GET-HTTP-RESPONSE-DESC (CODENAME DEFAULT)
  (CL:LET* ((ENTRY NULL) (ITER-000 *HTTP-RESPONSE-CODES*))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
    (CL:SETQ ENTRY (%%VALUE ITER-000))
    (CL:WHEN (CL:EQ (%%VALUE ENTRY) CODENAME)
     (CL:RETURN-FROM GET-HTTP-RESPONSE-DESC
      (%WRAPPER-VALUE (%%VALUE (%%REST (%%REST ENTRY))))))
    (CL:SETQ ITER-000 (%%REST ITER-000))))
  (CL:IF (CL:EQ DEFAULT NULL)
   (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
     "get-http-response-desc: undefined response code: `" CODENAME "'")
    (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))
   (GET-HTTP-RESPONSE-DESC DEFAULT NULL)))

;;; (DEFUN (HTTP-SUCCESS-RESPONSE-CODE? BOOLEAN) ...)

(CL:DEFUN HTTP-SUCCESS-RESPONSE-CODE? (CODE)
  (CL:DECLARE (CL:TYPE CL:FIXNUM CODE))
  #+MCL
  (CL:CHECK-TYPE CODE CL:FIXNUM)
  (CL:AND (CL:>= CODE 200) (CL:<= CODE 205)))

;;; (DEFUN (GET-HTTP-MIME-TYPE STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T CL:T) CL:SIMPLE-STRING)
  GET-HTTP-MIME-TYPE))
(CL:DEFUN GET-HTTP-MIME-TYPE (TYPENAME DEFAULT)
  (CL:LET* ((ENTRY NULL) (ITER-000 *HTTP-MIME-TYPES*))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
    (CL:SETQ ENTRY (%%VALUE ITER-000))
    (CL:WHEN (CL:EQ (%%VALUE ENTRY) TYPENAME)
     (CL:RETURN-FROM GET-HTTP-MIME-TYPE
      (%WRAPPER-VALUE (%%VALUE (%%REST ENTRY)))))
    (CL:SETQ ITER-000 (%%REST ITER-000))))
  (CL:IF (CL:EQ DEFAULT NULL)
   (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
    (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
     "get-http-mime-type: undefined mime type: `" TYPENAME "'")
    (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))
   (GET-HTTP-MIME-TYPE DEFAULT NULL)))

;;; (DEFUN (GET-HTTP-MIME-TYPE-FROM-EXTENSION STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:SIMPLE-STRING) CL:SIMPLE-STRING)
  GET-HTTP-MIME-TYPE-FROM-EXTENSION))
(CL:DEFUN GET-HTTP-MIME-TYPE-FROM-EXTENSION (EXTENSION)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING EXTENSION))
  #+MCL
  (CL:CHECK-TYPE EXTENSION CL:SIMPLE-STRING)
  (CL:LET* ((ENTRY NULL) (ITER-000 *HTTP-MIME-TYPES*))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
    (CL:SETQ ENTRY (%%VALUE ITER-000))
    (CL:LET* ((FOUND?-000 CL:NIL))
     (CL:LET* ((EXT NULL) (ITER-001 (%%REST (%%REST ENTRY))))
      (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
       (CL:SETQ EXT (%%VALUE ITER-001))
       (CL:WHEN (EQL-TO-STRING? EXT EXTENSION)
        (CL:SETQ FOUND?-000 CL:T) (CL:RETURN))
       (CL:SETQ ITER-001 (%%REST ITER-001))))
     (CL:WHEN FOUND?-000
      (CL:RETURN-FROM GET-HTTP-MIME-TYPE-FROM-EXTENSION
       (%WRAPPER-VALUE (%%VALUE (%%REST ENTRY))))))
    (CL:SETQ ITER-000 (%%REST ITER-000))))
  "application/octet-stream")

;;; (DEFUN (GUESS-FILE-CONTENT-TYPE STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:SIMPLE-STRING) CL:SIMPLE-STRING)
  GUESS-FILE-CONTENT-TYPE))
(CL:DEFUN GUESS-FILE-CONTENT-TYPE (FILE)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING FILE))
  #+MCL
  (CL:CHECK-TYPE FILE CL:SIMPLE-STRING)
  (GET-HTTP-MIME-TYPE-FROM-EXTENSION
   (SUBSEQUENCE (STRING-DOWNCASE (FILE-EXTENSION FILE)) 1 NULL-INTEGER)))

;;; (DEFUN (PARSE-AND-DECODE-URL-ARGUMENTS (CONS OF STRING-WRAPPER)) ...)

(CL:DEFUN PARSE-AND-DECODE-URL-ARGUMENTS (ARGUMENTS SEPARATOR)
  "Given the `arguments' following the `?' character in a URL, split them at
`separator' and return them as a list of properly decoded strings."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING ARGUMENTS))
  #+MCL
  (CL:CHECK-TYPE ARGUMENTS CL:SIMPLE-STRING)
  (CL:WHEN (BLANK-STRING? ARGUMENTS)
   (CL:RETURN-FROM PARSE-AND-DECODE-URL-ARGUMENTS NIL))
  (CL:LET*
   ((RESULT (SPLIT-STRING ARGUMENTS SEPARATOR)) (CURSOR RESULT))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NIL)) DO
    (FIRST-SETTER CURSOR
     (WRAP-STRING
      (UNESCAPE-URL-STRING (%WRAPPER-VALUE (%%VALUE CURSOR)))))
    (CL:SETQ CURSOR (%%REST CURSOR)))
   RESULT))

;;; (DEFUN (PARSE-AND-DECODE-FORM-VALUES (KEY-VALUE-LIST OF STRING-WRAPPER STRING-WRAPPER)) ...)

(CL:DEFUN PARSE-AND-DECODE-FORM-VALUES (VALUES)
  "Given the `values' returned by a form, parse and decode them and return them as
a key-value-list.  NOTE: values will not be trimmed and empty values will be represented by the empty
string rather than NULL.  Also, if the same input name occurs more than once, only the value of the
last input will be recorded in the resulting key-value-list."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING VALUES))
  #+MCL
  (CL:CHECK-TYPE VALUES CL:SIMPLE-STRING)
  (CL:LET*
   ((RESULT (NEW-KEY-VALUE-LIST)) (BAREENTRY STELLA::NULL-STRING)
    (SPLIT 0))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING BAREENTRY)
    (CL:TYPE CL:FIXNUM SPLIT))
   (CL:SETQ VALUES (SUBSTITUTE VALUES #\  #\+))
   (CL:LET* ((ENTRY NULL) (ITER-000 (SPLIT-STRING VALUES #\&)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ ENTRY (%%VALUE ITER-000))
     (CL:SETQ BAREENTRY (UNWRAP-STRING ENTRY))
     (CL:SETQ SPLIT (POSITION BAREENTRY #\= 0))
     (CL:WHEN (CL:NOT (CL:= SPLIT NULL-INTEGER))
      (INSERT-AT RESULT
       (WRAP-STRING
        (UNESCAPE-URL-STRING (SUBSEQUENCE BAREENTRY 0 SPLIT)))
       (WRAP-STRING
        (UNESCAPE-URL-STRING
         (SUBSEQUENCE BAREENTRY (CL:1+ SPLIT) NULL-INTEGER)))))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   RESULT))

;;; (DEFUN (PARSE-AND-DECODE-NON-UNIQUE-FORM-VALUES (PROPERTY-LIST OF STRING-WRAPPER STRING-WRAPPER)) ...)

(CL:DEFUN PARSE-AND-DECODE-NON-UNIQUE-FORM-VALUES (VALUES)
  "Given the `values' returned by a form, parse and decode them and return them as
a property-list.  NOTE: values will not be trimmed and empty values will be represented by the empty
string rather than NULL.  Keys will be inserted into the result in the order they appear in the form.
If they are non-unique, multiple entries per key will result which can be iterated over, however,
standard `lookup' calls will return the value of the first key only."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING VALUES))
  #+MCL
  (CL:CHECK-TYPE VALUES CL:SIMPLE-STRING)
  (CL:LET* ((RESULT NIL) (BAREENTRY STELLA::NULL-STRING) (SPLIT 0))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING BAREENTRY)
    (CL:TYPE CL:FIXNUM SPLIT))
   (CL:SETQ VALUES (SUBSTITUTE VALUES #\  #\+))
   (CL:LET* ((ENTRY NULL) (ITER-000 (SPLIT-STRING VALUES #\&)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ ENTRY (%%VALUE ITER-000))
     (CL:SETQ BAREENTRY (UNWRAP-STRING ENTRY))
     (CL:SETQ SPLIT (POSITION BAREENTRY #\= 0))
     (CL:WHEN (CL:NOT (CL:= SPLIT NULL-INTEGER))
      (CL:SETQ RESULT
       (CONS
        (WRAP-STRING
         (UNESCAPE-URL-STRING (SUBSEQUENCE BAREENTRY 0 SPLIT)))
        RESULT))
      (CL:SETQ RESULT
       (CONS
        (WRAP-STRING
         (UNESCAPE-URL-STRING
          (SUBSEQUENCE BAREENTRY (CL:1+ SPLIT) NULL-INTEGER)))
        RESULT)))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:LET* ((SELF-000 (NEW-PROPERTY-LIST)))
    (CL:SETF (%THE-PLIST SELF-000) (REVERSE RESULT))
    (CL:LET* ((VALUE-000 SELF-000)) VALUE-000))))

;;; (DEFGLOBAL *HTTP-DOCUMENT-ROOT* ...)

(CL:DEFVAR *HTTP-DOCUMENT-ROOT* STELLA::NULL-STRING)
(CL:DECLAIM (CL:TYPE CL:SIMPLE-STRING *HTTP-DOCUMENT-ROOT*))

;;; (DEFUN (GET-HTTP-DOCUMENT-ROOT STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION () CL:SIMPLE-STRING) GET-HTTP-DOCUMENT-ROOT))
(CL:DEFUN GET-HTTP-DOCUMENT-ROOT ()
  *HTTP-DOCUMENT-ROOT*)

;;; (DEFUN SET-HTTP-DOCUMENT-ROOT ...)

(CL:DEFUN SET-HTTP-DOCUMENT-ROOT (ROOT)
  "Set the document root to `root'.  Important: this needs to be
called before any handlers are published, otherwise it won't be effective."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING ROOT))
  #+MCL
  (CL:CHECK-TYPE ROOT CL:SIMPLE-STRING)
  (CL:SETQ *HTTP-DOCUMENT-ROOT* ROOT))

;;; (DEFGLOBAL *HTTP-HANDLER-REGISTRY* ...)

(CL:DEFVAR *HTTP-HANDLER-REGISTRY* NULL)

;;; (DEFMETHOD (LOOKUP-HANDLER PROPERTY-LIST) ...)

(CL:DEFMETHOD LOOKUP-HANDLER ((SERVER HTTP-SERVER) PATH)
  "Simple default handler lookup implementation.  Return the registered
handler whose path is identical to `path' or is the longest prefix of `path'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  (CL:WHEN (CL:EQ *HTTP-SERVER-IMPLEMENTATION* NULL)
   (CL:ERROR
    (NEW-STELLA-EXCEPTION
     "lookup-handler: no HTTP server implementation loaded")))
  (CL:LET*
   ((HANDLER (LOOKUP *HTTP-HANDLER-REGISTRY* (WRAP-STRING PATH)))
    (HANDLERPATH STELLA::NULL-STRING) (HANDLERPATHLENGTH 0))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING HANDLERPATH)
    (CL:TYPE CL:FIXNUM HANDLERPATHLENGTH))
   (CL:WHEN (CL:NOT (CL:EQ HANDLER NULL))
    (CL:RETURN-FROM LOOKUP-HANDLER HANDLER))
   (CL:LET*
    ((P NULL) (H NULL)
     (ITER-000 (ALLOCATE-ITERATOR *HTTP-HANDLER-REGISTRY*)))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ P (%KEY ITER-000))
     (CL:SETQ H (%VALUE ITER-000))
     (CL:WHEN (STARTS-WITH? PATH (%WRAPPER-VALUE P) 0)
      (CL:WHEN
       (CL:OR (CL:EQ HANDLER NULL)
        (CL:>
         (CL:THE CL:FIXNUM
          (CL:LENGTH (CL:THE CL:SIMPLE-STRING (UNWRAP-STRING P))))
         HANDLERPATHLENGTH))
       (CL:SETQ HANDLER H) (CL:SETQ HANDLERPATH (%WRAPPER-VALUE P))
       (CL:SETQ HANDLERPATHLENGTH
        (CL:THE CL:FIXNUM (CL:LENGTH HANDLERPATH)))))))
   HANDLER))

;;; (DEFUN PUBLISH-REGISTERED-HTTP-HANDLERS ...)

(CL:DEFUN PUBLISH-REGISTERED-HTTP-HANDLERS ()
  "Publish all currently registered HTTP handler with the current HTTP server.
This is run every time a server is started with `start-http-server'."
  (CL:WHEN (CL:EQ *HTTP-SERVER-IMPLEMENTATION* NULL)
   (CL:ERROR
    (NEW-STELLA-EXCEPTION
     "publish-registered-http-handlers: no HTTP server implementation loaded")))
  (CL:LET*
   ((PATH NULL) (OPTIONS NULL)
    (ITER-000 (ALLOCATE-ITERATOR *HTTP-HANDLER-REGISTRY*)))
   (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ PATH (%KEY ITER-000))
    (CL:SETQ OPTIONS (%VALUE ITER-000))
    (CL:LET*
     ((TEST-VALUE-000 (LOOKUP OPTIONS KWD-HTTP-SERVER-HANDLER-TYPE)))
     (CL:COND
      ((CL:EQ TEST-VALUE-000 KWD-HTTP-SERVER-FILE)
       (PUBLISH-FILE-IMPL *HTTP-SERVER-IMPLEMENTATION*
        (%WRAPPER-VALUE PATH)
        (%WRAPPER-VALUE (LOOKUP OPTIONS KWD-HTTP-SERVER-FILE))
        OPTIONS))
      ((CL:EQ TEST-VALUE-000 KWD-HTTP-SERVER-DIRECTORY)
       (PUBLISH-DIRECTORY-IMPL *HTTP-SERVER-IMPLEMENTATION*
        (%WRAPPER-VALUE PATH)
        (%WRAPPER-VALUE (LOOKUP OPTIONS KWD-HTTP-SERVER-DIRECTORY))
        OPTIONS))
      ((CL:EQ TEST-VALUE-000 KWD-HTTP-SERVER-HANDLER)
       (PUBLISH-HANDLER-IMPL *HTTP-SERVER-IMPLEMENTATION*
        (%WRAPPER-VALUE PATH)
        (%WRAPPER-VALUE (LOOKUP OPTIONS KWD-HTTP-SERVER-HANDLER))
        OPTIONS))
      (CL:T
       (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
        (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" TEST-VALUE-000
         "' is not a valid case option")
        (CL:ERROR
         (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))))))

;;; (DEFUN PRINT-REGISTERED-HTTP-HANDLERS ...)

(CL:DEFUN PRINT-REGISTERED-HTTP-HANDLERS ()
  (CL:LET* ((PATHS NIL))
   (CL:LET*
    ((PATH NULL) (OPTIONS NULL)
     (ITER-000 (ALLOCATE-ITERATOR *HTTP-HANDLER-REGISTRY*)))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ PATH (%KEY ITER-000))
     (CL:SETQ OPTIONS (%VALUE ITER-000)) (CL:SETQ OPTIONS OPTIONS)
     (CL:SETQ PATHS (CONS PATH PATHS))))
   (CL:SETQ PATHS (SORT PATHS NULL))
   (CL:LET* ((*PRINTPRETTY?* CL:NIL) (*PRINTREADABLY?* CL:T))
    (CL:DECLARE (CL:SPECIAL *PRINTPRETTY?* *PRINTREADABLY?*))
    (CL:LET* ((PATH NULL) (ITER-001 PATHS))
     (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-001 NIL)) DO
      (CL:SETQ PATH (%%VALUE ITER-001))
      (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT)
       (UNWRAP-STRING PATH) " ->" EOL)
      (CL:LET*
       ((KEY NULL) (VALUE NULL)
        (ITER-002
         (%THE-PLIST
          (LOOKUP-HANDLER *HTTP-SERVER-IMPLEMENTATION*
           (%WRAPPER-VALUE PATH)))))
       (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-002 NIL)) DO
        (CL:SETQ KEY (%%VALUE ITER-002))
        (CL:SETQ VALUE (%%VALUE (%%REST ITER-002)))
        (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "      " KEY
         " " VALUE EOL)
        (CL:SETQ ITER-002 (%%REST (%%REST ITER-002)))))
      (CL:SETQ ITER-001 (%%REST ITER-001)))))))

;;; (DEFUN PUBLISH-FILE ...)

(CL:DEFUN PUBLISH-FILE (PATH FILE CL:&REST OPTIONS)
  "Publish `path' to be served with `file' which must exist and be readable.
If :content-type is supplied, it will be used when serving `file', otherwise, a content
type is guessed from `file's extension."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH FILE))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE FILE CL:SIMPLE-STRING)
  (CL:SETQ FILE (TRANSLATE-LOGICAL-PATHNAME FILE))
  (ENSURE-FILE-EXISTS FILE "publish-file")
  (CL:LET* ((ARGLIST-000 NIL))
   (CL:LET* ((ARG-000 NULL) (ITER-000 OPTIONS) (COLLECT-000 NULL))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ ARG-000 (CL:POP ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS ARG-000 NIL))
       (CL:IF (CL:EQ ARGLIST-000 NIL) (CL:SETQ ARGLIST-000 COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST ARGLIST-000 COLLECT-000)))
      (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS ARG-000 NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
   (CL:LET*
    ((THEOPTIONS
      (VET-OPTIONS ARGLIST-000
       (GET-QUOTED-TREE "((:CONTENT-TYPE :DOCUMENTATION) \"/HTTP\")"
        "/HTTP"))))
    (CL:WHEN
     (CL:EQ (LOOKUP THEOPTIONS KWD-HTTP-SERVER-CONTENT-TYPE) NULL)
     (INSERT-AT THEOPTIONS KWD-HTTP-SERVER-CONTENT-TYPE
      (WRAP-STRING (GUESS-FILE-CONTENT-TYPE FILE))))
    (INSERT-AT THEOPTIONS KWD-HTTP-SERVER-HANDLER-TYPE
     KWD-HTTP-SERVER-FILE)
    (INSERT-AT THEOPTIONS KWD-HTTP-SERVER-PATH (WRAP-STRING PATH))
    (INSERT-AT THEOPTIONS KWD-HTTP-SERVER-FILE (WRAP-STRING FILE))
    (INSERT-AT *HTTP-HANDLER-REGISTRY* (WRAP-STRING PATH) THEOPTIONS))))

;;; (DEFMETHOD PUBLISH-FILE-IMPL ...)

(CL:DEFMETHOD PUBLISH-FILE-IMPL ((SERVER HTTP-SERVER) PATH FILE OPTIONS)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH FILE))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE FILE CL:SIMPLE-STRING)
  (CL:PROGN (CL:SETQ PATH PATH) (CL:SETQ FILE FILE)
   (CL:SETQ OPTIONS OPTIONS))
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "publish-file-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN PUBLISH-DIRECTORY ...)

(CL:DEFUN PUBLISH-DIRECTORY (PATH DIRECTORY CL:&REST OPTIONS)
  "Make all files descending from `directory' available on the server.
`path' will be coerced to end in a delimiter and `directory' must exist.
This is very rudimentary right now and does not provide any sophisticated access
control.  It recurses into subdirectories of `directory', prevents escape via `..'
and does not (yet) support directory listings."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH DIRECTORY))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE DIRECTORY CL:SIMPLE-STRING)
  (CL:SETQ DIRECTORY (TRANSLATE-LOGICAL-PATHNAME DIRECTORY))
  (CL:SETQ DIRECTORY (FILE-NAME-AS-DIRECTORY DIRECTORY))
  (CL:WHEN (CL:NOT (PROBE-FILE? DIRECTORY))
   (CL:WARN "HTTP/publish-directory: `~A' does not exist" DIRECTORY))
  (CL:WHEN (CL:NOT (ENDS-WITH? PATH "/" NULL-INTEGER))
   (CL:SETQ PATH (CONCATENATE PATH "/")))
  (CL:LET* ((ARGLIST-000 NIL))
   (CL:LET* ((ARG-000 NULL) (ITER-000 OPTIONS) (COLLECT-000 NULL))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ ARG-000 (CL:POP ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS ARG-000 NIL))
       (CL:IF (CL:EQ ARGLIST-000 NIL) (CL:SETQ ARGLIST-000 COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST ARGLIST-000 COLLECT-000)))
      (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS ARG-000 NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
   (CL:LET*
    ((THEOPTIONS
      (VET-OPTIONS ARGLIST-000
       (GET-QUOTED-TREE "((:DOCUMENTATION) \"/HTTP\")" "/HTTP"))))
    (INSERT-AT THEOPTIONS KWD-HTTP-SERVER-HANDLER-TYPE
     KWD-HTTP-SERVER-DIRECTORY)
    (INSERT-AT THEOPTIONS KWD-HTTP-SERVER-PATH (WRAP-STRING PATH))
    (INSERT-AT THEOPTIONS KWD-HTTP-SERVER-DIRECTORY
     (WRAP-STRING DIRECTORY))
    (INSERT-AT *HTTP-HANDLER-REGISTRY* (WRAP-STRING PATH) THEOPTIONS))))

;;; (DEFMETHOD PUBLISH-DIRECTORY-IMPL ...)

(CL:DEFMETHOD PUBLISH-DIRECTORY-IMPL ((SERVER HTTP-SERVER) PATH DIRECTORY OPTIONS)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH DIRECTORY))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE DIRECTORY CL:SIMPLE-STRING)
  (CL:PROGN (CL:SETQ PATH PATH) (CL:SETQ DIRECTORY DIRECTORY)
   (CL:SETQ OPTIONS OPTIONS))
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "publish-directory-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN PUBLISH-HANDLER ...)

(CL:DEFUN PUBLISH-HANDLER (PATH HANDLER CL:&REST OPTIONS)
  "Publish `path' to be handled by the handler function `handler' which must
take a single argument of type HTTP-EXCHANGE and use the API functions to read request
information and generate a result page.  If :content-type is supplied, it will be used as
the content type of the resulting page, otherwise, text/html will be used by default."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  (CL:LET* ((ARGLIST-000 NIL))
   (CL:LET* ((ARG-000 NULL) (ITER-000 OPTIONS) (COLLECT-000 NULL))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ ARG-000 (CL:POP ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS ARG-000 NIL))
       (CL:IF (CL:EQ ARGLIST-000 NIL) (CL:SETQ ARGLIST-000 COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST ARGLIST-000 COLLECT-000)))
      (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS ARG-000 NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
   (CL:LET*
    ((THEOPTIONS
      (VET-OPTIONS ARGLIST-000
       (GET-QUOTED-TREE "((:CONTENT-TYPE :DOCUMENTATION) \"/HTTP\")"
        "/HTTP"))))
    (CL:WHEN
     (CL:EQ (LOOKUP THEOPTIONS KWD-HTTP-SERVER-CONTENT-TYPE) NULL)
     (INSERT-AT THEOPTIONS KWD-HTTP-SERVER-CONTENT-TYPE
      (WRAP-STRING (GET-HTTP-MIME-TYPE KWD-HTTP-SERVER-HTML NULL))))
    (INSERT-AT THEOPTIONS KWD-HTTP-SERVER-HANDLER-TYPE
     KWD-HTTP-SERVER-HANDLER)
    (INSERT-AT THEOPTIONS KWD-HTTP-SERVER-PATH (WRAP-STRING PATH))
    (INSERT-AT THEOPTIONS KWD-HTTP-SERVER-HANDLER
     (WRAP-FUNCTION-CODE HANDLER))
    (INSERT-AT *HTTP-HANDLER-REGISTRY* (WRAP-STRING PATH) THEOPTIONS))))

;;; (DEFMETHOD PUBLISH-HANDLER-IMPL ...)

(CL:DEFMETHOD PUBLISH-HANDLER-IMPL ((SERVER HTTP-SERVER) PATH HANDLER OPTIONS)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  (CL:PROGN (CL:SETQ PATH PATH) (CL:SETQ HANDLER HANDLER)
   (CL:SETQ OPTIONS OPTIONS))
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "publish-handler-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFUN (GET-HANDLER-OPTIONS PROPERTY-LIST) ...)

(CL:DEFUN GET-HANDLER-OPTIONS (XCHG)
  "Return the options supplied when the handler for this exchange was published.
This includes required as well as optional arguments.  This will never return NULL."
  (GET-HANDLER-OPTIONS-IMPL *HTTP-SERVER-IMPLEMENTATION* XCHG))

;;; (DEFMETHOD (GET-HANDLER-OPTIONS-IMPL PROPERTY-LIST) ...)

(CL:DEFMETHOD GET-HANDLER-OPTIONS-IMPL ((SERVER HTTP-SERVER) XCHG)
  (CL:SETQ XCHG XCHG)
  (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
    "get-handler-options-impl: not implemented on `" SERVER "'")
   (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))

;;; (DEFGLOBAL *HTTP-SERVER-COPYRIGHT-TRAILER* ...)

(CL:DEFVAR *HTTP-SERVER-COPYRIGHT-TRAILER* STELLA::NULL-STRING)
(CL:DECLAIM (CL:TYPE CL:SIMPLE-STRING *HTTP-SERVER-COPYRIGHT-TRAILER*))

;;; (DEFUN GENERATE-ERROR-RESPONSE ...)

(CL:DEFUN GENERATE-ERROR-RESPONSE (XCHG CODE MESSAGE)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING MESSAGE))
  #+MCL
  (CL:CHECK-TYPE MESSAGE CL:SIMPLE-STRING)
  (CL:LET* ((STREAM (GET-REPLY-STREAM XCHG)))
   (SET-RESPONSE-CODE XCHG CODE)
   (SET-REPLY-HEADER-VALUE XCHG KWD-HTTP-SERVER-CONTENT-TYPE
    (GET-HTTP-MIME-TYPE KWD-HTTP-SERVER-HTML NULL))
   (CL:PROGN (%%PRINT-STREAM STREAM "<BODY BGCOLOR='FF9999'>")
    (%%PRINT-STREAM STREAM "ERROR: " (GET-HTTP-RESPONSE-CODE CODE NULL)
     " " (GET-HTTP-RESPONSE-DESC CODE NULL))
    (CL:WHEN (CL:NOT (CL:EQ MESSAGE STELLA::NULL-STRING))
     (%%PRINT-STREAM STREAM "<BR><BR>" MESSAGE EOL))
    (%%PRINT-STREAM STREAM "</BODY>" EOL))))

;;; (DEFUN FILE-HANDLER ...)

(CL:DEFUN FILE-HANDLER (XCHG)
  "Serve the specific file specified when the associated handler was published.
Simple default implementation for minimal servers such as the Sun JRE HttpServer."
  (CL:LET*
   ((URIPATH (GET-REQUEST-URI-PATH XCHG))
    (OPTIONS (GET-HANDLER-OPTIONS XCHG))
    (PATH (%WRAPPER-VALUE (LOOKUP OPTIONS KWD-HTTP-SERVER-PATH)))
    (FILE (%WRAPPER-VALUE (LOOKUP OPTIONS KWD-HTTP-SERVER-FILE)))
    (CONTENTTYPE
     (LOOKUP-WITH-DEFAULT OPTIONS KWD-HTTP-SERVER-CONTENT-TYPE
      (WRAP-STRING (GET-HTTP-MIME-TYPE KWD-HTTP-SERVER-HTML NULL))))
    (STREAM (GET-REPLY-STREAM XCHG)))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING URIPATH PATH FILE))
   (CL:SETQ URIPATH (STRING-TRIM (UNESCAPE-URL-STRING URIPATH)))
   (CL:COND
    ((CL:NOT (STRING-EQL? URIPATH PATH))
     (GENERATE-ERROR-RESPONSE XCHG KWD-HTTP-SERVER-NOT-FOUND
      STELLA::NULL-STRING))
    (CL:T
     (SET-REPLY-HEADER-VALUE XCHG KWD-HTTP-SERVER-CONTENT-TYPE
      (%WRAPPER-VALUE CONTENTTYPE))
     (CL:LET* ((IN NULL))
      (CL:UNWIND-PROTECT
       (CL:PROGN (CL:SETQ IN (OPEN-INPUT-FILE FILE))
        (CL:LET* ((SELF-000 (NEW-OUTPUT-STREAM)))
         (CL:SETF (%NATIVE-STREAM SELF-000) STREAM)
         (COPY-STREAM-TO-STREAM IN SELF-000)))
       (CL:WHEN (CL:NOT (CL:EQ IN NULL)) (FREE IN))))))))

;;; (DEFUN DIRECTORY-HANDLER ...)

(CL:DEFUN DIRECTORY-HANDLER (XCHG)
  "Serve files located anywhere in the directory specified when the associated
handler was published (including subdirectories).  Simple default implementation for minimal
servers such as the Sun JRE HttpServer."
  (CL:LET*
   ((URIPATH (GET-REQUEST-URI-PATH XCHG))
    (OPTIONS (GET-HANDLER-OPTIONS XCHG))
    (PATH (%WRAPPER-VALUE (LOOKUP OPTIONS KWD-HTTP-SERVER-PATH)))
    (DIRECTORY
     (%WRAPPER-VALUE (LOOKUP OPTIONS KWD-HTTP-SERVER-DIRECTORY)))
    (RESOLVEDURI STELLA::NULL-STRING) (ISDIRECTORY? CL:NIL)
    (CONTENTTYPE (GET-HTTP-MIME-TYPE KWD-HTTP-SERVER-BINARY NULL))
    (STREAM (GET-REPLY-STREAM XCHG)))
   (CL:DECLARE
    (CL:TYPE CL:SIMPLE-STRING URIPATH PATH DIRECTORY RESOLVEDURI
     CONTENTTYPE))
   (CL:SETQ URIPATH (STRING-TRIM (UNESCAPE-URL-STRING URIPATH)))
   (CL:SETQ ISDIRECTORY? (ENDS-WITH? URIPATH "/" NULL-INTEGER))
   (CL:WHEN (CL:NOT (STARTS-WITH? URIPATH PATH NULL-INTEGER))
    (GENERATE-ERROR-RESPONSE XCHG KWD-HTTP-SERVER-NOT-FOUND
     STELLA::NULL-STRING)
    (CL:RETURN-FROM DIRECTORY-HANDLER))
   (CL:SETQ URIPATH
    (SUBSEQUENCE URIPATH (CL:THE CL:FIXNUM (CL:LENGTH PATH))
     NULL-INTEGER))
   (CL:WHEN
    (CL:OR (STARTS-WITH? URIPATH "../" NULL-INTEGER)
     (STARTS-WITH? URIPATH "/.." NULL-INTEGER)
     (CL:NOT
      (CL:= (STRING-SEARCH URIPATH "/../" NULL-INTEGER) NULL-INTEGER)))
    (GENERATE-ERROR-RESPONSE XCHG KWD-HTTP-SERVER-FORBIDDEN
     STELLA::NULL-STRING)
    (CL:RETURN-FROM DIRECTORY-HANDLER))
   (CL:SETQ RESOLVEDURI (SUBSTITUTE URIPATH (DIRECTORY-SEPARATOR) #\/))
   (CL:SETQ RESOLVEDURI (CONCATENATE DIRECTORY RESOLVEDURI))
   (CL:WHEN ISDIRECTORY?
    (CL:COND
     ((PROBE-FILE? (CONCATENATE RESOLVEDURI "index.html"))
      (CL:SETQ RESOLVEDURI (CONCATENATE RESOLVEDURI "index.html")))
     ((PROBE-FILE? (CONCATENATE RESOLVEDURI "index.htm"))
      (CL:SETQ RESOLVEDURI (CONCATENATE RESOLVEDURI "index.htm")))
     (CL:T
      (GENERATE-ERROR-RESPONSE XCHG KWD-HTTP-SERVER-FORBIDDEN
       STELLA::NULL-STRING)
      (CL:RETURN-FROM DIRECTORY-HANDLER))))
   (CL:WHEN (CL:NOT (PROBE-FILE? RESOLVEDURI))
    (GENERATE-ERROR-RESPONSE XCHG KWD-HTTP-SERVER-NOT-FOUND
     STELLA::NULL-STRING)
    (CL:RETURN-FROM DIRECTORY-HANDLER))
   (CL:SETQ CONTENTTYPE (GUESS-FILE-CONTENT-TYPE RESOLVEDURI))
   (SET-REPLY-HEADER-VALUE XCHG KWD-HTTP-SERVER-CONTENT-TYPE
    CONTENTTYPE)
   (CL:LET* ((IN NULL))
    (CL:UNWIND-PROTECT
     (CL:PROGN (CL:SETQ IN (OPEN-INPUT-FILE RESOLVEDURI))
      (CL:LET* ((SELF-000 (NEW-OUTPUT-STREAM)))
       (CL:SETF (%NATIVE-STREAM SELF-000) STREAM)
       (COPY-STREAM-TO-STREAM IN SELF-000)))
     (CL:WHEN (CL:NOT (CL:EQ IN NULL)) (FREE IN))))))

;;; (DEFUN UNKNOWN-URL-HANDLER ...)

(CL:DEFUN UNKNOWN-URL-HANDLER (XCHG)
  "Simple default handler for unknown/unhandled URLs."
  (GENERATE-ERROR-RESPONSE XCHG KWD-HTTP-SERVER-NOT-FOUND
   STELLA::NULL-STRING))

;;; (DEFUN LOAD-SYSTEM-HANDLER ...)

(CL:DEFUN LOAD-SYSTEM-HANDLER (XCHG)
  "Load the STELLA system with options identified by the URL parameters."
  (CL:LET*
   ((ARGUMENTS
     (PARSE-AND-DECODE-URL-ARGUMENTS (GET-REQUEST-URI-QUERY XCHG) #\+))
    (SYSTEMNAME (%%VALUE ARGUMENTS))
    (LOADCOMMAND
     (LIST* SYM-HTTP-SERVER-STELLA-LOAD-SYSTEM SYSTEMNAME NIL))
    (STREAM (GET-REPLY-STREAM XCHG)))
   (CL:LET*
    ((ARG NULL) (ITER-000 (%%REST ARGUMENTS)) (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ ARG (%%VALUE ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN
       (CL:SETQ COLLECT-000
        (CONS (READ-S-EXPRESSION-FROM-STRING (%WRAPPER-VALUE ARG))
         NIL))
       (CL:IF (CL:EQ LOADCOMMAND NIL) (CL:SETQ LOADCOMMAND COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST LOADCOMMAND COLLECT-000)))
      (CL:PROGN
       (CL:SETF (%%REST COLLECT-000)
        (CONS (READ-S-EXPRESSION-FROM-STRING (%WRAPPER-VALUE ARG))
         NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:HANDLER-CASE
    (CL:PROGN (%EVALUATE LOADCOMMAND)
     (CL:PROGN (%%PRINT-STREAM STREAM "<BODY>")
      (%%PRINT-STREAM STREAM "Successfully evaluated: "
       (STRINGIFY LOADCOMMAND))
      (%%PRINT-STREAM STREAM "<BR><BR>" EOL)
      (%%PRINT-STREAM STREAM "<HR SIZE=2>" EOL)
      (%%PRINT-STREAM STREAM *HTTP-SERVER-COPYRIGHT-TRAILER*)
      (%%PRINT-STREAM STREAM "</BODY>" EOL)))
    (CL:CONDITION (E)
     (GENERATE-ERROR-RESPONSE XCHG KWD-HTTP-SERVER-BAD-REQUEST
      (EXCEPTION-MESSAGE E))))))

;;; (DEFGLOBAL *TEST-HTTP-API-HANDLER-LAST-XCHG* ...)

(CL:DEFVAR *TEST-HTTP-API-HANDLER-LAST-XCHG* NULL)

;;; (DEFUN TEST-HTTP-API-HANDLER-SERVE-FORM ...)

(CL:DEFUN TEST-HTTP-API-HANDLER-SERVE-FORM (XCHG)
  (CL:LET* ((STREAM (GET-REPLY-STREAM XCHG)))
   (%%PRINT-STREAM STREAM "
<FORM NAME=\"frank\" METHOD=\"POST\">
<b>Execute Query</b><BR>
<b>Theory:</b> <INPUT TYPE=\"text\" NAME=\"CONTEXT\" VALUE=\"INSPECT\" SIZE=40 ><BR>
<b>Package:</b><INPUT TYPE=\"text\" NAME=\"PACKAGE\" VALUE=\"EXPECT\" SIZE=40 ><P>
<b>Output Variable(s):</b><INPUT TYPE=\"text\" NAME=\"VARIABLES\" SIZE=60 ><P>
<b>Query:</b><TEXTAREA NAME=\"QUERY\" ROWS=10 COLS=72 ></TEXTAREA><P>
<INPUT TYPE=submit  NAME=\"submit\" VALUE=\"submit\">
</FORM>")))

;;; (DEFUN TEST-HTTP-API-HANDLER ...)

(CL:DEFUN TEST-HTTP-API-HANDLER (XCHG)
  (CL:SETQ *TEST-HTTP-API-HANDLER-LAST-XCHG* XCHG)
  (CL:LET*
   ((URI (GET-REQUEST-URI XCHG)) (PATH (GET-REQUEST-URI-PATH XCHG))
    (QUERY (GET-REQUEST-URI-QUERY XCHG))
    (ARGS (PARSE-AND-DECODE-URL-ARGUMENTS QUERY #\+))
    (METHOD (GET-REQUEST-METHOD XCHG))
    (LOCALHOST (GET-REQUEST-LOCAL-ADDRESS XCHG))
    (REMOTEHOST (GET-REQUEST-REMOTE-ADDRESS XCHG))
    (BODY (GET-REQUEST-BODY XCHG)) (STREAM (GET-REPLY-STREAM XCHG)))
   (CL:DECLARE
    (CL:TYPE CL:SIMPLE-STRING URI PATH QUERY LOCALHOST REMOTEHOST
     BODY))
   (CL:COND
    ((CL:EQ METHOD KWD-HTTP-SERVER-GET)
     (CL:WHEN (MEMBER? ARGS (WRAP-STRING "plain"))
      (SET-REPLY-HEADER-VALUE XCHG KWD-HTTP-SERVER-CONTENT-TYPE
       (GET-HTTP-MIME-TYPE KWD-HTTP-SERVER-PLAIN-TEXT NULL)))
     (%%PRINT-STREAM STREAM "<PRE>" EOL)
     (%%PRINT-STREAM STREAM "It worked, here are some parameters: "
      EOL)
     (%%PRINT-STREAM STREAM "URI=`" URI "'" EOL)
     (%%PRINT-STREAM STREAM "Path=`" PATH "'" EOL)
     (%%PRINT-STREAM STREAM "Query=`" QUERY "'" EOL)
     (%%PRINT-STREAM STREAM "Args=`" ARGS "'" EOL)
     (%%PRINT-STREAM STREAM "Method=`" METHOD "'" EOL)
     (%%PRINT-STREAM STREAM "Local host=`" LOCALHOST "'" EOL)
     (%%PRINT-STREAM STREAM "Remote host=`" REMOTEHOST "'" EOL)
     (%%PRINT-STREAM STREAM "Body=`" BODY "'" EOL)
     (%%PRINT-STREAM STREAM "</PRE>" EOL)
     (TEST-HTTP-API-HANDLER-SERVE-FORM XCHG))
    ((CL:EQ METHOD KWD-HTTP-SERVER-POST)
     (CL:LET* ((VALUES (PARSE-AND-DECODE-FORM-VALUES BODY)))
      (%%PRINT-STREAM STREAM "<PRE>" EOL)
      (%%PRINT-STREAM STREAM "It worked, here are some parameters: "
       EOL)
      (%%PRINT-STREAM STREAM "URI=`" URI "'" EOL)
      (%%PRINT-STREAM STREAM "Path=`" PATH "'" EOL)
      (%%PRINT-STREAM STREAM "Query=`" QUERY "'" EOL)
      (%%PRINT-STREAM STREAM "Args=`" ARGS "'" EOL)
      (%%PRINT-STREAM STREAM "Method=`" METHOD "'" EOL)
      (%%PRINT-STREAM STREAM "Local host=`" LOCALHOST "'" EOL)
      (%%PRINT-STREAM STREAM "Remote host=`" REMOTEHOST "'" EOL)
      (%%PRINT-STREAM STREAM "Body=`" BODY "'" EOL)
      (%%PRINT-STREAM STREAM "Values=`" VALUES "'" EOL EOL)
      (%%PRINT-STREAM STREAM "</PRE>" EOL)))
    (CL:T
     (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
      (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "`" METHOD
       "' is not a valid case option")
      (CL:ERROR
       (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))))

(CL:DEFUN HELP-STARTUP-HTTP-SERVER1 ()
  (CL:PROGN
   (CL:SETQ SYM-HTTP-SERVER-HTTP-HTTP-SERVER-EXIT-HOOK
    (INTERN-RIGID-SYMBOL-WRT-MODULE "HTTP-SERVER-EXIT-HOOK" NULL 0))
   (CL:SETQ SYM-HTTP-SERVER-HTTP-START-HTTP-SERVER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "START-HTTP-SERVER" NULL 0))
   (CL:SETQ KWD-HTTP-SERVER-COMMON-LISP
    (INTERN-RIGID-SYMBOL-WRT-MODULE "COMMON-LISP" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-FUNCTION
    (INTERN-RIGID-SYMBOL-WRT-MODULE "FUNCTION" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-OK
    (INTERN-RIGID-SYMBOL-WRT-MODULE "OK" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-REDIRECT
    (INTERN-RIGID-SYMBOL-WRT-MODULE "REDIRECT" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-FORBIDDEN
    (INTERN-RIGID-SYMBOL-WRT-MODULE "FORBIDDEN" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-NOT-FOUND
    (INTERN-RIGID-SYMBOL-WRT-MODULE "NOT-FOUND" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-BAD-REQUEST
    (INTERN-RIGID-SYMBOL-WRT-MODULE "BAD-REQUEST" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-INTERNAL-ERROR
    (INTERN-RIGID-SYMBOL-WRT-MODULE "INTERNAL-ERROR" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-NOT-IMPLEMENTED
    (INTERN-RIGID-SYMBOL-WRT-MODULE "NOT-IMPLEMENTED" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-PLAIN-TEXT
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PLAIN-TEXT" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-HTML
    (INTERN-RIGID-SYMBOL-WRT-MODULE "HTML" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-XML
    (INTERN-RIGID-SYMBOL-WRT-MODULE "XML" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-BINARY
    (INTERN-RIGID-SYMBOL-WRT-MODULE "BINARY" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-IMAGE-GIF
    (INTERN-RIGID-SYMBOL-WRT-MODULE "IMAGE-GIF" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-IMAGE-JPG
    (INTERN-RIGID-SYMBOL-WRT-MODULE "IMAGE-JPG" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-IMAGE-PNG
    (INTERN-RIGID-SYMBOL-WRT-MODULE "IMAGE-PNG" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-AUDIO-MPEG
    (INTERN-RIGID-SYMBOL-WRT-MODULE "AUDIO-MPEG" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-PDF
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PDF" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-MSWORD
    (INTERN-RIGID-SYMBOL-WRT-MODULE "MSWORD" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-HANDLER-TYPE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "HANDLER-TYPE" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-FILE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "FILE" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-DIRECTORY
    (INTERN-RIGID-SYMBOL-WRT-MODULE "DIRECTORY" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-HANDLER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "HANDLER" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-CONTENT-TYPE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "CONTENT-TYPE" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-PATH
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PATH" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-DOCUMENTATION
    (INTERN-RIGID-SYMBOL-WRT-MODULE "DOCUMENTATION" NULL 2))
   (CL:SETQ SYM-HTTP-SERVER-STELLA-LOAD-SYSTEM
    (INTERN-RIGID-SYMBOL-WRT-MODULE "LOAD-SYSTEM"
     (GET-STELLA-MODULE "/STELLA" CL:T) 0))
   (CL:SETQ KWD-HTTP-SERVER-GET
    (INTERN-RIGID-SYMBOL-WRT-MODULE "GET" NULL 2))
   (CL:SETQ KWD-HTTP-SERVER-POST
    (INTERN-RIGID-SYMBOL-WRT-MODULE "POST" NULL 2))
   (CL:SETQ SYM-HTTP-SERVER-HTTP-STARTUP-HTTP-SERVER
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-HTTP-SERVER" NULL 0))
   (CL:SETQ SYM-HTTP-SERVER-STELLA-METHOD-STARTUP-CLASSNAME
    (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
     (GET-STELLA-MODULE "/STELLA" CL:T) 0))))

(CL:DEFUN HELP-STARTUP-HTTP-SERVER2 ()
  (CL:PROGN
   (DEFINE-FUNCTION-OBJECT "GET-DEFAULT-HTTP-SERVER-IMPL"
    "(DEFUN (GET-DEFAULT-HTTP-SERVER-IMPL STRING) ((ERROR? BOOLEAN)) :DOCUMENTATION \"Return a default HTTP server implementation system for the case
where none has been loaded yet.  If `error?' is TRUE, raise an error if none
is defined for the current native language environment.\" :PUBLIC? TRUE)"
    (CL:FUNCTION GET-DEFAULT-HTTP-SERVER-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "START-HTTP-SERVER"
    "(DEFUN (START-HTTP-SERVER STRING) ((PORT INTEGER)) :DOCUMENTATION \"Start an HTTP server running at `port'.  If there is already
a server instance running, it will be stopped first.  If `port' is <= 0 or
NULL, use the value of `*default-http-server-port*'.  Returns the listening
address of the started server instance.\" :PUBLIC? TRUE :COMMAND? TRUE)"
    (CL:FUNCTION %START-HTTP-SERVER)
    (CL:FUNCTION START-HTTP-SERVER-EVALUATOR-WRAPPER))
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (START-HTTP-SERVER-IMPL STRING) ((SERVER HTTP-SERVER) (PORT INTEGER)))"
    (CL:FUNCTION START-HTTP-SERVER-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "STOP-HTTP-SERVER"
    "(DEFUN STOP-HTTP-SERVER () :DOCUMENTATION \"Stop any currently running HTTP server.  If there is no
server instance running, this is a no-op.\" :PUBLIC? TRUE :COMMAND? TRUE)"
    (CL:FUNCTION STOP-HTTP-SERVER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD STOP-HTTP-SERVER-IMPL ((SERVER HTTP-SERVER)))"
    (CL:FUNCTION STOP-HTTP-SERVER-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "HTTP-SERVER-EXIT-HOOK"
    "(DEFUN HTTP-SERVER-EXIT-HOOK ((ARGUMENT OBJECT)) :DOCUMENTATION \"Hook function that will be called upon PowerLoom exit.
This is a no-op if no server is running or if the server is not supported.\" :PUBLIC? TRUE)"
    (CL:FUNCTION HTTP-SERVER-EXIT-HOOK) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-HEADER-VALUE"
    "(DEFUN (GET-HEADER-VALUE STRING) ((XCHG HTTP-EXCHANGE) (KEY KEYWORD)) :DOCUMENTATION \"Returns the value associated with `key' in `xchg's request
headers represented as a string.  If no value is found, NULL will be returned.
If there are multiple values, an arbitrary one will be returned.\" :PUBLIC? TRUE)"
    (CL:FUNCTION GET-HEADER-VALUE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (GET-HEADER-VALUE-IMPL STRING) ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE) (KEY KEYWORD)))"
    (CL:FUNCTION GET-HEADER-VALUE-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "SET-REPLY-HEADER-VALUE"
    "(DEFUN SET-REPLY-HEADER-VALUE ((XCHG HTTP-EXCHANGE) (KEY KEYWORD) (VALUE STRING)) :DOCUMENTATION \"Set the value associated with `key' in `xchg's reply headers to `value'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION SET-REPLY-HEADER-VALUE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD SET-REPLY-HEADER-VALUE-IMPL ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE) (KEY KEYWORD) (VALUE STRING)))"
    (CL:FUNCTION SET-REPLY-HEADER-VALUE-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-REQUEST-URI"
    "(DEFUN (GET-REQUEST-URI STRING) ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Return the raw URI associated with `xchg' as a string.  It is ensured
that any URI-encoded characters are not yet decoded to facilitate further parsing.
This does not include any protocol/scheme and host/port information.  For example, if
the user typed http://a.b.c:42/foo/bar.html#frag?a+b+c into the client, this function
will return /foo/bar.html#frag?a+b+c .\" :PUBLIC? TRUE)"
    (CL:FUNCTION GET-REQUEST-URI) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (GET-REQUEST-URI-IMPL STRING) ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE)))"
    (CL:FUNCTION GET-REQUEST-URI-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-REQUEST-URI-QUERY"
    "(DEFUN (GET-REQUEST-URI-QUERY STRING) ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Return the raw query portion of the URI associated with `xchg'.  It is ensured
that any URI-encoded characters are not yet decoded to facilitate further parsing.  For example,
if the user typed http://a.b.c:42/foo/bar.html#frag?a+b+c into the client, this function will
return a+b+c .\" :PUBLIC? TRUE)" (CL:FUNCTION GET-REQUEST-URI-QUERY)
    NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (GET-REQUEST-URI-QUERY-IMPL STRING) ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE)))"
    (CL:FUNCTION GET-REQUEST-URI-QUERY-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-REQUEST-URI-PATH"
    "(DEFUN (GET-REQUEST-URI-PATH STRING) ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Return the raw path portion of the URI associated with `xchg'.  It is ensured
that any URI-encoded characters are not yet decoded to facilitate further parsing.  For example,
if the user typed http://a.b.c:42/foo/bar.html#frag?a+b+c into the client, this function will
return /foo/bar.html.\" :PUBLIC? TRUE)"
    (CL:FUNCTION GET-REQUEST-URI-PATH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (GET-REQUEST-URI-PATH-IMPL STRING) ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE)))"
    (CL:FUNCTION GET-REQUEST-URI-PATH-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-REQUEST-METHOD"
    "(DEFUN (GET-REQUEST-METHOD KEYWORD) ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Return the method associated with `xchg' (:get, :put or :post).\" :PUBLIC? TRUE)"
    (CL:FUNCTION GET-REQUEST-METHOD) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (GET-REQUEST-METHOD-IMPL KEYWORD) ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE)))"
    (CL:FUNCTION GET-REQUEST-METHOD-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-REQUEST-BODY"
    "(DEFUN (GET-REQUEST-BODY STRING) ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Returns the body of `xchg' as a string.  If there was no body (e.g.,
if this was a GET), the result will be the empty string.\" :PUBLIC? TRUE)"
    (CL:FUNCTION GET-REQUEST-BODY) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (GET-REQUEST-BODY-IMPL STRING) ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE)))"
    (CL:FUNCTION GET-REQUEST-BODY-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-REQUEST-LOCAL-ADDRESS"
    "(DEFUN (GET-REQUEST-LOCAL-ADDRESS STRING) ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Returns the local-address that received `xchg' as a string.
Concatenates the hostname with a port in standard : notation.  If the hostname
can be resolved it will be, otherwise a numeric representation will be returned.
Note that different implementations have slightly different behavior.\" :PUBLIC? TRUE)"
    (CL:FUNCTION GET-REQUEST-LOCAL-ADDRESS) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (GET-REQUEST-LOCAL-ADDRESS-IMPL STRING) ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE)))"
    (CL:FUNCTION GET-REQUEST-LOCAL-ADDRESS-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-REQUEST-REMOTE-ADDRESS"
    "(DEFUN (GET-REQUEST-REMOTE-ADDRESS STRING) ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Returns the remote-address that sent `xchg' as a string.
Concatenates the hostname with a port in standard : notation.  If the hostname
can be resolved it will be, otherwise a numeric representation will be returned.
Note that different implementations have slightly different behavior.\" :PUBLIC? TRUE)"
    (CL:FUNCTION GET-REQUEST-REMOTE-ADDRESS) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (GET-REQUEST-REMOTE-ADDRESS-IMPL STRING) ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE)))"
    (CL:FUNCTION GET-REQUEST-REMOTE-ADDRESS-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-REPLY-STREAM"
    "(DEFUN (GET-REPLY-STREAM NATIVE-OUTPUT-STREAM) ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Return the stream to which response methods have to write their output.\" :PUBLIC? TRUE)"
    (CL:FUNCTION GET-REPLY-STREAM) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (GET-REPLY-STREAM-IMPL NATIVE-OUTPUT-STREAM) ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE)))"
    (CL:FUNCTION GET-REPLY-STREAM-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "SET-RESPONSE-CODE"
    "(DEFUN SET-RESPONSE-CODE ((XCHG HTTP-EXCHANGE) (CODE KEYWORD)) :DOCUMENTATION \"Set the response code of the generated reply to `code'.  By default
:OK (code 200) is used.\" :PUBLIC? TRUE)"
    (CL:FUNCTION SET-RESPONSE-CODE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD SET-RESPONSE-CODE-IMPL ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE) (CODE KEYWORD)))"
    (CL:FUNCTION SET-RESPONSE-CODE-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-HTTP-RESPONSE-CODE"
    "(DEFUN (GET-HTTP-RESPONSE-CODE INTEGER) ((CODENAME KEYWORD) (DEFAULT KEYWORD)))"
    (CL:FUNCTION GET-HTTP-RESPONSE-CODE) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-HTTP-RESPONSE-DESC"
    "(DEFUN (GET-HTTP-RESPONSE-DESC STRING) ((CODENAME KEYWORD) (DEFAULT KEYWORD)))"
    (CL:FUNCTION GET-HTTP-RESPONSE-DESC) NULL)
   (DEFINE-FUNCTION-OBJECT "HTTP-SUCCESS-RESPONSE-CODE?"
    "(DEFUN (HTTP-SUCCESS-RESPONSE-CODE? BOOLEAN) ((CODE INTEGER)))"
    (CL:FUNCTION HTTP-SUCCESS-RESPONSE-CODE?) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-HTTP-MIME-TYPE"
    "(DEFUN (GET-HTTP-MIME-TYPE STRING) ((TYPENAME KEYWORD) (DEFAULT KEYWORD)))"
    (CL:FUNCTION GET-HTTP-MIME-TYPE) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-HTTP-MIME-TYPE-FROM-EXTENSION"
    "(DEFUN (GET-HTTP-MIME-TYPE-FROM-EXTENSION STRING) ((EXTENSION STRING)))"
    (CL:FUNCTION GET-HTTP-MIME-TYPE-FROM-EXTENSION) NULL)
   (DEFINE-FUNCTION-OBJECT "GUESS-FILE-CONTENT-TYPE"
    "(DEFUN (GUESS-FILE-CONTENT-TYPE STRING) ((FILE STRING)))"
    (CL:FUNCTION GUESS-FILE-CONTENT-TYPE) NULL)
   (DEFINE-FUNCTION-OBJECT "PARSE-AND-DECODE-URL-ARGUMENTS"
    "(DEFUN (PARSE-AND-DECODE-URL-ARGUMENTS (CONS OF STRING-WRAPPER)) ((ARGUMENTS STRING) (SEPARATOR CHARACTER)) :DOCUMENTATION \"Given the `arguments' following the `?' character in a URL, split them at
`separator' and return them as a list of properly decoded strings.\" :PUBLIC? TRUE)"
    (CL:FUNCTION PARSE-AND-DECODE-URL-ARGUMENTS) NULL)
   (DEFINE-FUNCTION-OBJECT "PARSE-AND-DECODE-FORM-VALUES"
    "(DEFUN (PARSE-AND-DECODE-FORM-VALUES (KEY-VALUE-LIST OF STRING-WRAPPER STRING-WRAPPER)) ((VALUES STRING)) :DOCUMENTATION \"Given the `values' returned by a form, parse and decode them and return them as
a key-value-list.  NOTE: values will not be trimmed and empty values will be represented by the empty
string rather than NULL.  Also, if the same input name occurs more than once, only the value of the
last input will be recorded in the resulting key-value-list.\" :PUBLIC? TRUE)"
    (CL:FUNCTION PARSE-AND-DECODE-FORM-VALUES) NULL)
   (DEFINE-FUNCTION-OBJECT "PARSE-AND-DECODE-NON-UNIQUE-FORM-VALUES"
    "(DEFUN (PARSE-AND-DECODE-NON-UNIQUE-FORM-VALUES (PROPERTY-LIST OF STRING-WRAPPER STRING-WRAPPER)) ((VALUES STRING)) :DOCUMENTATION \"Given the `values' returned by a form, parse and decode them and return them as
a property-list.  NOTE: values will not be trimmed and empty values will be represented by the empty
string rather than NULL.  Keys will be inserted into the result in the order they appear in the form.
If they are non-unique, multiple entries per key will result which can be iterated over, however,
standard `lookup' calls will return the value of the first key only.\" :PUBLIC? TRUE)"
    (CL:FUNCTION PARSE-AND-DECODE-NON-UNIQUE-FORM-VALUES) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-HTTP-DOCUMENT-ROOT"
    "(DEFUN (GET-HTTP-DOCUMENT-ROOT STRING) () :PUBLIC? TRUE)"
    (CL:FUNCTION GET-HTTP-DOCUMENT-ROOT) NULL)
   (DEFINE-FUNCTION-OBJECT "SET-HTTP-DOCUMENT-ROOT"
    "(DEFUN SET-HTTP-DOCUMENT-ROOT ((ROOT STRING)) :DOCUMENTATION \"Set the document root to `root'.  Important: this needs to be
called before any handlers are published, otherwise it won't be effective.\" :PUBLIC? TRUE)"
    (CL:FUNCTION SET-HTTP-DOCUMENT-ROOT) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (LOOKUP-HANDLER PROPERTY-LIST) ((SERVER HTTP-SERVER) (PATH STRING)) :DOCUMENTATION \"Simple default handler lookup implementation.  Return the registered
handler whose path is identical to `path' or is the longest prefix of `path'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION LOOKUP-HANDLER) NULL)
   (DEFINE-FUNCTION-OBJECT "PUBLISH-REGISTERED-HTTP-HANDLERS"
    "(DEFUN PUBLISH-REGISTERED-HTTP-HANDLERS () :DOCUMENTATION \"Publish all currently registered HTTP handler with the current HTTP server.
This is run every time a server is started with `start-http-server'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION PUBLISH-REGISTERED-HTTP-HANDLERS) NULL)
   (DEFINE-FUNCTION-OBJECT "PRINT-REGISTERED-HTTP-HANDLERS"
    "(DEFUN PRINT-REGISTERED-HTTP-HANDLERS () :PUBLIC? TRUE :COMMAND? TRUE)"
    (CL:FUNCTION PRINT-REGISTERED-HTTP-HANDLERS) NULL)
   (DEFINE-FUNCTION-OBJECT "PUBLISH-FILE"
    "(DEFUN PUBLISH-FILE ((PATH STRING) (FILE STRING) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Publish `path' to be served with `file' which must exist and be readable.
If :content-type is supplied, it will be used when serving `file', otherwise, a content
type is guessed from `file's extension.\" :PUBLIC? TRUE)"
    (CL:FUNCTION PUBLISH-FILE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD PUBLISH-FILE-IMPL ((SERVER HTTP-SERVER) (PATH STRING) (FILE STRING) (OPTIONS PROPERTY-LIST)))"
    (CL:FUNCTION PUBLISH-FILE-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "PUBLISH-DIRECTORY"
    "(DEFUN PUBLISH-DIRECTORY ((PATH STRING) (DIRECTORY STRING) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Make all files descending from `directory' available on the server.
`path' will be coerced to end in a delimiter and `directory' must exist.
This is very rudimentary right now and does not provide any sophisticated access
control.  It recurses into subdirectories of `directory', prevents escape via `..'
and does not (yet) support directory listings.\" :PUBLIC? TRUE)"
    (CL:FUNCTION PUBLISH-DIRECTORY) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD PUBLISH-DIRECTORY-IMPL ((SERVER HTTP-SERVER) (PATH STRING) (DIRECTORY STRING) (OPTIONS PROPERTY-LIST)))"
    (CL:FUNCTION PUBLISH-DIRECTORY-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "PUBLISH-HANDLER"
    "(DEFUN PUBLISH-HANDLER ((PATH STRING) (HANDLER FUNCTION-CODE) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Publish `path' to be handled by the handler function `handler' which must
take a single argument of type HTTP-EXCHANGE and use the API functions to read request
information and generate a result page.  If :content-type is supplied, it will be used as
the content type of the resulting page, otherwise, text/html will be used by default.\" :PUBLIC? TRUE)"
    (CL:FUNCTION PUBLISH-HANDLER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD PUBLISH-HANDLER-IMPL ((SERVER HTTP-SERVER) (PATH STRING) (HANDLER FUNCTION-CODE) (OPTIONS PROPERTY-LIST)))"
    (CL:FUNCTION PUBLISH-HANDLER-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "GET-HANDLER-OPTIONS"
    "(DEFUN (GET-HANDLER-OPTIONS PROPERTY-LIST) ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Return the options supplied when the handler for this exchange was published.
This includes required as well as optional arguments.  This will never return NULL.\" :PUBLIC? TRUE)"
    (CL:FUNCTION GET-HANDLER-OPTIONS) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (GET-HANDLER-OPTIONS-IMPL PROPERTY-LIST) ((SERVER HTTP-SERVER) (XCHG HTTP-EXCHANGE)))"
    (CL:FUNCTION GET-HANDLER-OPTIONS-IMPL) NULL)
   (DEFINE-FUNCTION-OBJECT "GENERATE-ERROR-RESPONSE"
    "(DEFUN GENERATE-ERROR-RESPONSE ((XCHG HTTP-EXCHANGE) (CODE KEYWORD) (MESSAGE STRING)))"
    (CL:FUNCTION GENERATE-ERROR-RESPONSE) NULL)
   (DEFINE-FUNCTION-OBJECT "FILE-HANDLER"
    "(DEFUN FILE-HANDLER ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Serve the specific file specified when the associated handler was published.
Simple default implementation for minimal servers such as the Sun JRE HttpServer.\" :PUBLIC? TRUE)"
    (CL:FUNCTION FILE-HANDLER) NULL)
   (DEFINE-FUNCTION-OBJECT "DIRECTORY-HANDLER"
    "(DEFUN DIRECTORY-HANDLER ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Serve files located anywhere in the directory specified when the associated
handler was published (including subdirectories).  Simple default implementation for minimal
servers such as the Sun JRE HttpServer.\" :PUBLIC? TRUE)"
    (CL:FUNCTION DIRECTORY-HANDLER) NULL)
   (DEFINE-FUNCTION-OBJECT "UNKNOWN-URL-HANDLER"
    "(DEFUN UNKNOWN-URL-HANDLER ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Simple default handler for unknown/unhandled URLs.\" :PUBLIC? TRUE)"
    (CL:FUNCTION UNKNOWN-URL-HANDLER) NULL)
   (DEFINE-FUNCTION-OBJECT "LOAD-SYSTEM-HANDLER"
    "(DEFUN LOAD-SYSTEM-HANDLER ((XCHG HTTP-EXCHANGE)) :DOCUMENTATION \"Load the STELLA system with options identified by the URL parameters.\" :PUBLIC? TRUE)"
    (CL:FUNCTION LOAD-SYSTEM-HANDLER) NULL)
   (DEFINE-FUNCTION-OBJECT "TEST-HTTP-API-HANDLER-SERVE-FORM"
    "(DEFUN TEST-HTTP-API-HANDLER-SERVE-FORM ((XCHG HTTP-EXCHANGE)))"
    (CL:FUNCTION TEST-HTTP-API-HANDLER-SERVE-FORM) NULL)
   (DEFINE-FUNCTION-OBJECT "TEST-HTTP-API-HANDLER"
    "(DEFUN TEST-HTTP-API-HANDLER ((XCHG HTTP-EXCHANGE)))"
    (CL:FUNCTION TEST-HTTP-API-HANDLER) NULL)
   (DEFINE-FUNCTION-OBJECT "STARTUP-HTTP-SERVER"
    "(DEFUN STARTUP-HTTP-SERVER () :PUBLIC? TRUE)"
    (CL:FUNCTION STARTUP-HTTP-SERVER) NULL)
   (CL:LET*
    ((FUNCTION
      (LOOKUP-FUNCTION SYM-HTTP-SERVER-HTTP-STARTUP-HTTP-SERVER)))
    (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
     SYM-HTTP-SERVER-STELLA-METHOD-STARTUP-CLASSNAME
     (WRAP-STRING "_StartupHttpServer") NULL-STRING-WRAPPER))))

(CL:DEFUN STARTUP-HTTP-SERVER ()
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE "/HTTP" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (HELP-STARTUP-HTTP-SERVER1))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 4)
    (CL:SETQ *HTTP-RESPONSE-CODES*
     (LIST*
      (LIST* KWD-HTTP-SERVER-OK (WRAP-INTEGER 200) (WRAP-STRING "OK")
       NIL)
      (LIST* KWD-HTTP-SERVER-REDIRECT (WRAP-INTEGER 301)
       (WRAP-STRING "Moved Permanently") NIL)
      (LIST* KWD-HTTP-SERVER-FORBIDDEN (WRAP-INTEGER 403)
       (WRAP-STRING "Forbidden") NIL)
      (LIST* KWD-HTTP-SERVER-NOT-FOUND (WRAP-INTEGER 404)
       (WRAP-STRING "Not Found") NIL)
      (LIST* KWD-HTTP-SERVER-BAD-REQUEST (WRAP-INTEGER 400)
       (WRAP-STRING "Bad Request") NIL)
      (LIST* KWD-HTTP-SERVER-INTERNAL-ERROR (WRAP-INTEGER 500)
       (WRAP-STRING "Internal Server Error") NIL)
      (LIST* KWD-HTTP-SERVER-NOT-IMPLEMENTED (WRAP-INTEGER 501)
       (WRAP-STRING "Not Implemented") NIL)
      NIL))
    (CL:SETQ *HTTP-MIME-TYPES*
     (LIST*
      (LIST* KWD-HTTP-SERVER-PLAIN-TEXT (WRAP-STRING "text/plain")
       (WRAP-STRING "txt") (WRAP-STRING "text") (WRAP-STRING "asc")
       NIL)
      (LIST* KWD-HTTP-SERVER-HTML (WRAP-STRING "text/html")
       (WRAP-STRING "htm") (WRAP-STRING "html") NIL)
      (LIST* KWD-HTTP-SERVER-XML (WRAP-STRING "text/xml")
       (WRAP-STRING "xml") (WRAP-STRING "rdf") (WRAP-STRING "owl") NIL)
      (LIST* KWD-HTTP-SERVER-BINARY
       (WRAP-STRING "application/octet-stream") (WRAP-STRING "zip")
       (WRAP-STRING "exe") (WRAP-STRING "class") NIL)
      (LIST* KWD-HTTP-SERVER-IMAGE-GIF (WRAP-STRING "image/gif")
       (WRAP-STRING "gif") NIL)
      (LIST* KWD-HTTP-SERVER-IMAGE-JPG (WRAP-STRING "image/jpeg")
       (WRAP-STRING "jpg") (WRAP-STRING "jpeg") NIL)
      (LIST* KWD-HTTP-SERVER-IMAGE-PNG (WRAP-STRING "image/png")
       (WRAP-STRING "png") NIL)
      (LIST* KWD-HTTP-SERVER-AUDIO-MPEG (WRAP-STRING "audio/mpeg")
       (WRAP-STRING "mp3") NIL)
      (LIST* KWD-HTTP-SERVER-PDF (WRAP-STRING "application/pdf")
       (WRAP-STRING "pdf") NIL)
      (LIST* KWD-HTTP-SERVER-MSWORD (WRAP-STRING "application/msword")
       (WRAP-STRING "doc") NIL)
      NIL))
    (CL:SETQ *HTTP-DOCUMENT-ROOT*
     (CL:IF (CL:NOT (CL:EQ *HTTP-DOCUMENT-ROOT* STELLA::NULL-STRING))
      *HTTP-DOCUMENT-ROOT*
      (CL:IF (PROBE-FILE? "PL:htdocs;powerloom.html")
       (TRANSLATE-LOGICAL-PATHNAME "PL:htdocs;")
       (TRANSLATE-LOGICAL-PATHNAME "PL:"))))
    (CL:SETQ *HTTP-HANDLER-REGISTRY* (NEW-KEY-VALUE-MAP))
    (CL:SETQ *HTTP-SERVER-COPYRIGHT-TRAILER*
     (CONCATENATE *STELLA-VERSION-STRING* " HTTP Server" "<BR>"
      "Copyright 1996-"
      (INTEGER-TO-STRING
       (CL:TRUNCATE
        (GET-CALENDAR-DATE (MAKE-CURRENT-DATE-TIME)
         (GET-LOCAL-TIME-ZONE))))
      " University of Southern California Information Sciences Institute")))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 5)
    (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "HTTP-SERVER"
     "(DEFCLASS HTTP-SERVER (STANDARD-OBJECT) :DOCUMENTATION \"Abstract class that will be implemented by specific server implementations
and instantiated with a single instance used to dispatch all API methods.\" :ABSTRACT? TRUE :PUBLIC? TRUE)")
    (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "HTTP-EXCHANGE"
     "(DEFCLASS HTTP-EXCHANGE (STANDARD-OBJECT) :DOCUMENTATION \"Abstract class that represents exchange objects that encapsulate all necessary
state needed by a http handler function to understand the request and generate the
appropriate response.  This is mirrored somewhat after Sun's basic HTTP server
implementation in com.sun.net.httpserver.\" :ABSTRACT? TRUE :PUBLIC? TRUE)"))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (HELP-STARTUP-HTTP-SERVER2))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "HTTP")))
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *HTTP-SERVER-IMPLEMENTATION* HTTP-SERVER NULL :DOCUMENTATION \"Server instance used for method dispatch - not to be confused
with an actual native server object.\")")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *DEFAULT-HTTP-SERVER-PORT* INTEGER 9090)")
    (REGISTER-NATIVE-NAME SYM-HTTP-SERVER-HTTP-START-HTTP-SERVER
     KWD-HTTP-SERVER-COMMON-LISP KWD-HTTP-SERVER-FUNCTION)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *HTTP-RESPONSE-CODES* (CONS OF CONS) (BQUOTE ((:OK 200 \"OK\") (:REDIRECT 301 \"Moved Permanently\") (:FORBIDDEN 403 \"Forbidden\") (:NOT-FOUND 404 \"Not Found\") (:BAD-REQUEST 400 \"Bad Request\") (:INTERNAL-ERROR 500 \"Internal Server Error\") (:NOT-IMPLEMENTED 501 \"Not Implemented\"))))")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *HTTP-MIME-TYPES* (CONS OF CONS) (BQUOTE ((:PLAIN-TEXT \"text/plain\" \"txt\" \"text\" \"asc\") (:HTML \"text/html\" \"htm\" \"html\") (:XML \"text/xml\" \"xml\" \"rdf\" \"owl\") (:BINARY \"application/octet-stream\" \"zip\" \"exe\" \"class\") (:IMAGE-GIF \"image/gif\" \"gif\") (:IMAGE-JPG \"image/jpeg\" \"jpg\" \"jpeg\") (:IMAGE-PNG \"image/png\" \"png\") (:AUDIO-MPEG \"audio/mpeg\" \"mp3\") (:PDF \"application/pdf\" \"pdf\") (:MSWORD \"application/msword\" \"doc\"))))")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *HTTP-DOCUMENT-ROOT* STRING (FIRST-DEFINED *HTTP-DOCUMENT-ROOT* (CHOOSE (PROBE-FILE? \"PL:htdocs;powerloom.html\") (TRANSLATE-LOGICAL-PATHNAME \"PL:htdocs;\") (TRANSLATE-LOGICAL-PATHNAME \"PL:\"))))")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *HTTP-HANDLER-REGISTRY* (KEY-VALUE-MAP OF STRING-WRAPPER PROPERTY-LIST) (NEW KEY-VALUE-MAP))")
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *HTTP-SERVER-COPYRIGHT-TRAILER* STRING (CONCATENATE *STELLA-VERSION-STRING* \" HTTP Server\" \"<BR>\" \"Copyright 1996-\" (INTEGER-TO-STRING (GET-CALENDAR-DATE (MAKE-CURRENT-DATE-TIME) (GET-LOCAL-TIME-ZONE))) \" University of Southern California Information Sciences Institute\"))")
    (PUBLISH-DIRECTORY "/ploom/" (GET-HTTP-DOCUMENT-ROOT)
     KWD-HTTP-SERVER-DOCUMENTATION
     (WRAP-STRING "Top-level htdocs directory."))
    (PUBLISH-HANDLER "/ploom/load-system"
     (CL:FUNCTION LOAD-SYSTEM-HANDLER) KWD-HTTP-SERVER-CONTENT-TYPE
     (WRAP-STRING (GET-HTTP-MIME-TYPE KWD-HTTP-SERVER-HTML NULL))
     KWD-HTTP-SERVER-DOCUMENTATION
     (WRAP-STRING
      "Triggers a load-system operation at the server for the argument system."))
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *TEST-HTTP-API-HANDLER-LAST-XCHG* HTTP-EXCHANGE NULL)")
    (PUBLISH-HANDLER "/ploom/test-http-api"
     (CL:FUNCTION TEST-HTTP-API-HANDLER) KWD-HTTP-SERVER-CONTENT-TYPE
     (WRAP-STRING (GET-HTTP-MIME-TYPE KWD-HTTP-SERVER-HTML NULL))
     KWD-HTTP-SERVER-DOCUMENTATION
     (WRAP-STRING
      "Useful for comparing different HTTP API implementations.")))))
