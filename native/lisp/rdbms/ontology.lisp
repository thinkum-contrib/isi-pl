;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; ontology.lisp

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

(CL:DEFVAR SYM-ONTOLOGY-RDBMS-DATABASE NULL)
(CL:DEFVAR KWD-ONTOLOGY-DOCUMENTATION NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-SQL-DATABASE NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-PROTOCOL NULL)
(CL:DEFVAR KWD-ONTOLOGY--> NULL)
(CL:DEFVAR KWD-ONTOLOGY-GOES-TRUE-DEMON NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON NULL)
(CL:DEFVAR KWD-ONTOLOGY-GOES-UNKNOWN-DEMON NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-SERVER-TYPE NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-DSN NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-CONNECTION-STRING NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-ODBC-CONNECTION-STRING NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-JDBC-CONNECTION-STRING NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-HOST NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-PORT NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-USER NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-PASSWORD NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-DB-NAME NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-DB-CONNECTION NULL)
(CL:DEFVAR KWD-ONTOLOGY-AXIOMS NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-RELATION-TABLE NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-RELATION-DATABASE NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-RELATION-COLUMN-NAME NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-RELATION-COLUMN-MODULE-NAME NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-RELATION-COLUMN-MODULE-REFERENCE NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-QUERY-EVALUATOR NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-SUPPORTS-DB-TYPE NULL)
(CL:DEFVAR KWD-ONTOLOGY-CLOSED NULL)
(CL:DEFVAR SYM-ONTOLOGY-STELLA-TRUE NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-QUERY-PATTERN NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-QUERY-SQL-DATABASE NULL)
(CL:DEFVAR KWD-ONTOLOGY-VARIABLE-ARITY NULL)
(CL:DEFVAR KWD-ONTOLOGY-RELATION-SPECIALIST NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-QUERY-SQL-DATABASE-SPECIALIST NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-QUERY-DATABASE NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-QUERY-DATABASE-SPECIALIST NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-FETCH-EDB-DATABASE NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-TASK-ID NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-SUBTASK-ID NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-FETCH-QUERY NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-FETCH-QUERY-TYPE-1 NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-FETCH-QUERY-TYPE-2 NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-QUERY-TABLE-NAME NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-QUERY-PARAMETER-NAME NULL)
(CL:DEFVAR SYM-ONTOLOGY-RDBMS-STARTUP-ONTOLOGY NULL)
(CL:DEFVAR SYM-ONTOLOGY-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE*))

(CL:DEFUN STARTUP-ONTOLOGY ()
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE "/RDBMS" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ SYM-ONTOLOGY-RDBMS-DATABASE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DATABASE" NULL 0))
    (CL:SETQ KWD-ONTOLOGY-DOCUMENTATION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DOCUMENTATION" NULL 2))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-SQL-DATABASE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SQL-DATABASE" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-PROTOCOL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "PROTOCOL" NULL 0))
    (CL:SETQ KWD-ONTOLOGY-->
     (INTERN-RIGID-SYMBOL-WRT-MODULE "->" NULL 2))
    (CL:SETQ KWD-ONTOLOGY-GOES-TRUE-DEMON
     (INTERN-RIGID-SYMBOL-WRT-MODULE "GOES-TRUE-DEMON" NULL 2))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DB-UPDATE-DEMON" NULL 0))
    (CL:SETQ KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
     (INTERN-RIGID-SYMBOL-WRT-MODULE "GOES-UNKNOWN-DEMON" NULL 2))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-SERVER-TYPE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SERVER-TYPE" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-DSN
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DSN" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-CONNECTION-STRING
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CONNECTION-STRING" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-ODBC-CONNECTION-STRING
     (INTERN-RIGID-SYMBOL-WRT-MODULE "ODBC-CONNECTION-STRING" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-JDBC-CONNECTION-STRING
     (INTERN-RIGID-SYMBOL-WRT-MODULE "JDBC-CONNECTION-STRING" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-HOST
     (INTERN-RIGID-SYMBOL-WRT-MODULE "HOST" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-PORT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "PORT" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-USER
     (INTERN-RIGID-SYMBOL-WRT-MODULE "USER" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-PASSWORD
     (INTERN-RIGID-SYMBOL-WRT-MODULE "PASSWORD" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-DB-NAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DB-NAME" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-DB-CONNECTION
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DB-CONNECTION" NULL 0))
    (CL:SETQ KWD-ONTOLOGY-AXIOMS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "AXIOMS" NULL 2))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-RELATION-TABLE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "RELATION-TABLE" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-RELATION-DATABASE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "RELATION-DATABASE" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-RELATION-COLUMN-NAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "RELATION-COLUMN-NAME" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-RELATION-COLUMN-MODULE-NAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "RELATION-COLUMN-MODULE-NAME" NULL
      0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-RELATION-COLUMN-MODULE-REFERENCE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "RELATION-COLUMN-MODULE-REFERENCE"
      NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-QUERY-EVALUATOR
     (INTERN-RIGID-SYMBOL-WRT-MODULE "QUERY-EVALUATOR" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-SUPPORTS-DB-TYPE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SUPPORTS-DB-TYPE" NULL 0))
    (CL:SETQ KWD-ONTOLOGY-CLOSED
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CLOSED" NULL 2))
    (CL:SETQ SYM-ONTOLOGY-STELLA-TRUE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "TRUE"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-QUERY-PATTERN
     (INTERN-RIGID-SYMBOL-WRT-MODULE "QUERY-PATTERN" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-QUERY-SQL-DATABASE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "QUERY-SQL-DATABASE" NULL 0))
    (CL:SETQ KWD-ONTOLOGY-VARIABLE-ARITY
     (INTERN-RIGID-SYMBOL-WRT-MODULE "VARIABLE-ARITY" NULL 2))
    (CL:SETQ KWD-ONTOLOGY-RELATION-SPECIALIST
     (INTERN-RIGID-SYMBOL-WRT-MODULE "RELATION-SPECIALIST" NULL 2))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-QUERY-SQL-DATABASE-SPECIALIST
     (INTERN-RIGID-SYMBOL-WRT-MODULE "QUERY-SQL-DATABASE-SPECIALIST"
      NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-QUERY-DATABASE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "QUERY-DATABASE" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-QUERY-DATABASE-SPECIALIST
     (INTERN-RIGID-SYMBOL-WRT-MODULE "QUERY-DATABASE-SPECIALIST" NULL
      0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-FETCH-EDB-DATABASE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FETCH-EDB-DATABASE" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-TASK-ID
     (INTERN-RIGID-SYMBOL-WRT-MODULE "TASK-ID" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-SUBTASK-ID
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SUBTASK-ID" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-FETCH-QUERY
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FETCH-QUERY" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-FETCH-QUERY-TYPE-1
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FETCH-QUERY-TYPE-1" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-FETCH-QUERY-TYPE-2
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FETCH-QUERY-TYPE-2" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-QUERY-TABLE-NAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "QUERY-TABLE-NAME" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-QUERY-PARAMETER-NAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "QUERY-PARAMETER-NAME" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-RDBMS-STARTUP-ONTOLOGY
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-ONTOLOGY" NULL 0))
    (CL:SETQ SYM-ONTOLOGY-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "STARTUP-ONTOLOGY"
     "(DEFUN STARTUP-ONTOLOGY () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-ONTOLOGY) NULL)
    (CL:LET*
     ((FUNCTION (LOOKUP-FUNCTION SYM-ONTOLOGY-RDBMS-STARTUP-ONTOLOGY)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-ONTOLOGY-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupOntology") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "RDBMS")))
    (CL:LET*
     ((*MODULE* (GET-STELLA-MODULE "PL-KERNEL-KB" CL:T))
      (*CONTEXT* *MODULE*))
     (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
     (%DEFCONCEPT
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DATABASE)
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "Information defining a database.  The connection relation is transient."))))
     (%DEFCONCEPT
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-SQL-DATABASE)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((DATABASE) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "Information defining a database that supports SQL queries via JDBC or ODBC."))))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-PROTOCOL)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?CS STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "The protocol that should be used to connect to the database
in case there are multiple options for the current implementation language.
For example, in Lisp and C++ we could use either \"ODBC\" or the \"MySQL\" API
(which is not yet supported), while in Java we only support `JDBC'."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-SERVER-TYPE)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?CS STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "The type of DBMS server used such as \"MySQL\" or \"Oracle\".
This information is needed if connection strings are not given directly but
need to be assembled from individual pieces."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DSN)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?DSN STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "The data source name used for a connection.  Currently, data
sources are only supported for ODBC and not (yet) JDBC.  By specifying a data
source, all connection information can be kept in some external file such as
`.odbc.ini'."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-CONNECTION-STRING)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?CS STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "The connection string used for an ODBC or JDBC connection.  Deprecated"))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-ODBC-CONNECTION-STRING)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?CS STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "The connection string used for a ODBC connection."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-JDBC-CONNECTION-STRING)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?CS STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "The connection string used for a JDBC connection."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-HOST)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?HOST STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE (WRAP-STRING "The host of a database server."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-PORT)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?PORT INTEGER) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE (WRAP-STRING "The port of a database server."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-USER)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?USER STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE (WRAP-STRING "The user for a database server."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-PASSWORD)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?PASSWORD STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "The password associated with a user for a database server."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-NAME)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?DBNAME STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING "The name of a database on a database server."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-CONNECTION)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB DATABASE)) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE
         "((?CONNECTION CONNECTION-WRAPPER) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "A connection id produced by using the rest of the information
associated with the database.  This relation is transient, i.e., it can be
reset dynamically, whereas the other relations should not change."))
       KWD-ONTOLOGY-AXIOMS
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((HIDDEN-RELATION DB-CONNECTION) \"/RDBMS\")"
         "/RDBMS"))))
     (%DEFRELATION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-RELATION-TABLE)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE
         "(((?RELATION /PL-KERNEL-KB/RELATION) (?TABLE STRING)) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "Associates a PowerLoom ?relation with a database ?table."))))
     (%DEFRELATION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-RELATION-DATABASE)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE
         "(((?RELATION /PL-KERNEL-KB/RELATION) (?DATABASE DATABASE)) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "Associates a PowerLoom ?relation with an RDBMS ?database."))))
     (%DEFFUNCTION
      (CONS-LIST
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-RELATION-COLUMN-NAME)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE
         "(((?DBRELATION /PL-KERNEL-KB/RELATION) (?COL INTEGER)) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?COLNAME STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "The name of the database table column at position ?col (1-based)
associated with the database relation ?dbrelation."))))
     (%DEFFUNCTION
      (CONS-LIST
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-RELATION-COLUMN-MODULE-NAME)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE
         "(((?DBRELATION /PL-KERNEL-KB/RELATION) (?COL INTEGER)) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?MODNAME STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "The name of the module to import the logic objects defined at table column at position ?col (1-based)
associated with the database relation ?dbrelation."))))
     (%DEFFUNCTION
      (CONS-LIST
       (COPY-CONS-TREE
        SYM-ONTOLOGY-RDBMS-RELATION-COLUMN-MODULE-REFERENCE)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE
         "(((?DBRELATION /PL-KERNEL-KB/RELATION) (?COL INTEGER)) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?MODREF STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "The name of the column from which to get the name of the module
to import the logic objects defined at table column at position ?col (1-based)
associated with the database relation ?dbrelation."))))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE
        "((COMPUTED-PROCEDURE DBTABLE-SPECIALIST) \"/RDBMS\")"
        "/RDBMS")))
     (%DEFCONCEPT
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-QUERY-EVALUATOR)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((COMPUTED-PROCEDURE) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "A specialist procedure that can evaluate generic external queries."))))
     (%DEFRELATION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-SUPPORTS-DB-TYPE)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE
         "(((?EVALUATOR QUERY-EVALUATOR) (?DBTYPE CONCEPT)) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "Specifies that ?evaluator can handle external databases of
type ?dbType."))
       KWD-ONTOLOGY-CLOSED (COPY-CONS-TREE SYM-ONTOLOGY-STELLA-TRUE)))
     (%DEFRELATION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-QUERY-PATTERN)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE
         "(((?RELATION /PL-KERNEL-KB/RELATION) (?EVALUATOR QUERY-EVALUATOR) (?DATABASE DATABASE) (?ARGUMENTS STRING)) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "Specifies a query evaluation pattern that can generate bindings
for ?relation from an external ?database.  ?evaluator is a query evaluator that
takes a query proposition, the ?database instance and an ?arguments specification
and returns an iterator that generates CONS tuples whose elements will be matched
to ?relation's arguments by position.  The format of ?arguments is specific to
each evaluator (see for example the function `RDBMS/SQL-join').

Whether a particular pattern is applicable depends on whether all the required
input arguments are bound and whether ?evaluator can handle the particular
?database type.  If there are multiple applicable patterns they will be run/
evaluated in sequence (similar to having multiple rules for ?relation)."))
       KWD-ONTOLOGY-CLOSED (COPY-CONS-TREE SYM-ONTOLOGY-STELLA-TRUE)))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE "((COMPUTED-PROCEDURE SQL-QUERY) \"/RDBMS\")"
        "/RDBMS")))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE
        "((AND (DOCUMENTATION SQL-QUERY \"Generic query evaluator that can handle arbitrary
SQL queries on an RDBMS/SQL-Database.\") (QUERY-EVALUATOR SQL-QUERY) (SUPPORTS-DB-TYPE SQL-QUERY SQL-DATABASE)) \"/RDBMS\")"
        "/RDBMS")))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE "((COMPUTED-PROCEDURE SQL-JOIN) \"/RDBMS\")"
        "/RDBMS")))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE
        "((AND (DOCUMENTATION SQL-JOIN \"Generic query evaluator that can evaluate
simple joins on an RDBMS/SQL-Database.\") (QUERY-EVALUATOR SQL-JOIN) (SUPPORTS-DB-TYPE SQL-JOIN SQL-DATABASE)) \"/RDBMS\")"
        "/RDBMS")))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE
        "((COMPUTED-PROCEDURE QUERY-SPECIALIST) \"/RDBMS\")"
        "/RDBMS")))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE
        "((DOCUMENTATION QUERY-SPECIALIST \"Top-level specialist that can dispatch generic query
evaluation specialists such as RDBMS/SQL-join.\") \"/RDBMS\")"
        "/RDBMS")))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE
        "((COMPUTED-PROCEDURE QUERY-SQL-DATABASE-SPECIALIST) \"/RDBMS\")"
        "/RDBMS")))
     (%DEFRELATION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-QUERY-SQL-DATABASE)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE
         "(((?DATABASE SQL-DATABASE) (?QUERY STRING) ?OUTPUT) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING "Run the SQL ?query against ?database and bind
one or more ?output arguments to the columns in the resulting tuples.
This can be turned into a T/F query either by binding ?output's or by
wrapping an EXISTS around this.  Result coercion is performed based on
the types of the ?output variables."))
       KWD-ONTOLOGY-VARIABLE-ARITY
       (COPY-CONS-TREE SYM-ONTOLOGY-STELLA-TRUE)
       KWD-ONTOLOGY-RELATION-SPECIALIST
       (COPY-CONS-TREE
        SYM-ONTOLOGY-RDBMS-QUERY-SQL-DATABASE-SPECIALIST)))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE
        "((COMPUTED-PROCEDURE QUERY-DATABASE-SPECIALIST) \"/RDBMS\")"
        "/RDBMS")))
     (%DEFRELATION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-QUERY-DATABASE)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE
         "(((?DATABASE DATABASE) (?QUERY STRING) ?OUTPUT) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "Run the relational ?query against ?database and bind
one or more ?output arguments to the columns in the resulting tuples.
If there are more result columns than ?output variables, they will be
ignored.  If there are fewer, that's ok as long as the remaining ?output's
had initial bindings.  Initial bindings can be used to instantiate
a parametric ?query template with them (e.g., for SQL queries).  Initial
bindings have to match result columns except for collection-valued bindings.
This can be turned into a T/F query either by binding ?output's or by
wrapping an EXISTS around this.  Result coercion is performed based on
the types of the ?output variables.  For known database types such
as `RDBMS/SQL-Database' this dispatches to the appropriate specialist.
Otherwise, this relation serves as a top-level interface that can be
linked to other database query interfaces via appropriate rules."))
       KWD-ONTOLOGY-VARIABLE-ARITY
       (COPY-CONS-TREE SYM-ONTOLOGY-STELLA-TRUE)
       KWD-ONTOLOGY-RELATION-SPECIALIST
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-QUERY-DATABASE-SPECIALIST)))
     (%DEFCONCEPT
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-FETCH-EDB-DATABASE)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((DATABASE) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "A database that supports EELD EDB database access via Fetch HTTP wrappers."))))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-TASK-ID)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB FETCH-EDB-DATABASE)) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?ID STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING "The task-id used for each access to ?db."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%DEFFUNCTION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-SUBTASK-ID)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?DB FETCH-EDB-DATABASE)) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-->
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?ID STRING) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING "The subtask-id used for each access to ?db."))
       KWD-ONTOLOGY-GOES-TRUE-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)
       KWD-ONTOLOGY-GOES-UNKNOWN-DEMON
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-DB-UPDATE-DEMON)))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE
        "((COMPUTED-PROCEDURE FETCH-EDB-QUERY) \"/RDBMS\")" "/RDBMS")))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE
        "((AND (DOCUMENTATION FETCH-EDB-QUERY \"Generic query evaluator that can handle EELD EDB
queries via the Fetch HTTP/XML interface.\") (QUERY-EVALUATOR FETCH-EDB-QUERY) (SUPPORTS-DB-TYPE FETCH-EDB-QUERY FETCH-EDB-DATABASE)) \"/RDBMS\")"
        "/RDBMS")))
     (%DEFCONCEPT
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-FETCH-QUERY)
       (COPY-CONS-TREE (GET-QUOTED-TREE "((?C) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-CLOSED (COPY-CONS-TREE SYM-ONTOLOGY-STELLA-TRUE)))
     (%DEFCONCEPT
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-FETCH-QUERY-TYPE-1)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?C FETCH-QUERY) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-CLOSED (COPY-CONS-TREE SYM-ONTOLOGY-STELLA-TRUE)))
     (%DEFCONCEPT
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-FETCH-QUERY-TYPE-2)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "((?C FETCH-QUERY) \"/RDBMS\")" "/RDBMS"))
       KWD-ONTOLOGY-CLOSED (COPY-CONS-TREE SYM-ONTOLOGY-STELLA-TRUE)))
     (%DEFRELATION
      (CONS-LIST (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-QUERY-TABLE-NAME)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?Q FETCH-QUERY) (?N STRING)) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "Database table referenced by this query.  The current set
of queries each reference only one DB table, but this is a relation
to allow for future expansion."))
       KWD-ONTOLOGY-CLOSED (COPY-CONS-TREE SYM-ONTOLOGY-STELLA-TRUE)))
     (%DEFRELATION
      (CONS-LIST
       (COPY-CONS-TREE SYM-ONTOLOGY-RDBMS-QUERY-PARAMETER-NAME)
       (COPY-CONS-TREE
        (GET-QUOTED-TREE "(((?Q FETCH-QUERY) (?N STRING)) \"/RDBMS\")"
         "/RDBMS"))
       KWD-ONTOLOGY-DOCUMENTATION
       (COPY-CONS-TREE
        (WRAP-STRING
         "Parameter name that needs to be set by this query.  The current set
of queries each take only a single parameter, but this is a relation
to allow for future expansion.  TO DO:  Figure out if this should be
a three-place relation that also has a type (concept) entry to identify
what sort of value the parameter takes on."))
       KWD-ONTOLOGY-CLOSED (COPY-CONS-TREE SYM-ONTOLOGY-STELLA-TRUE)))
     (%ASSERT
      (COPY-CONS-TREE
       (GET-QUOTED-TREE
        "((DISJOINT FETCH-QUERY-TYPE-1 FETCH-QUERY-TYPE-2) \"/RDBMS\")"
        "/RDBMS")))))))
