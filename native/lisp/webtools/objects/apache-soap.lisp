;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; apache-soap.lisp

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

(CL:DEFVAR SYM-APACHE-SOAP-APACHE-SOAP-STARTUP-APACHE-SOAP NULL)
(CL:DEFVAR SYM-APACHE-SOAP-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE*))

(CL:DEFUN STARTUP-APACHE-SOAP ()
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE "/STELLA/XML-OBJECTS/APACHE-SOAP" (> *STARTUP-TIME-PHASE* 1))) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ SYM-APACHE-SOAP-APACHE-SOAP-STARTUP-APACHE-SOAP
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-APACHE-SOAP" NULL 0))
    (CL:SETQ SYM-APACHE-SOAP-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" (GET-STELLA-MODULE "/STELLA" CL:T) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "STARTUP-APACHE-SOAP" "(DEFUN STARTUP-APACHE-SOAP () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-APACHE-SOAP) NULL)
    (CL:LET* ((FUNCTION (LOOKUP-FUNCTION SYM-APACHE-SOAP-APACHE-SOAP-STARTUP-APACHE-SOAP)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION) SYM-APACHE-SOAP-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupApacheSoap") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS) (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9) (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "APACHE-SOAP")))
    (INSERT-AT *NAMESPACE-PREFIX-URI-TABLE* (WRAP-STRING "APACHE-SOAP") (WRAP-STRING "http://xml.apache.org/xml-soap"))
    (INSERT-AT *NAMESPACE-URI-PREFIX-TABLE* (WRAP-STRING "http://xml.apache.org/xml-soap")
     (WRAP-STRING "APACHE-SOAP")))))
