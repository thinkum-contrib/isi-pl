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

(CL:DEFVAR SYM-STARTUP-SYSTEM-LOGIC-STARTUP-LOGIC-SYSTEM NULL)
(CL:DEFVAR SYM-STARTUP-SYSTEM-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE*))

(CL:DEFUN STARTUP-LOGIC-SYSTEM ()
  (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 0)
   (CL:WHEN (CL:NOT (SYSTEM-STARTED-UP? "stella" "/STELLA"))
    (STARTUP-STELLA-SYSTEM)))
  (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 1)
   (DEFINE-MODULE-FROM-STRINGIFIED-SOURCE "/LOGIC"
    "(:LISP-PACKAGE \"STELLA\" :CLEARABLE? FALSE :CODE-ONLY? TRUE)")
   (DEFINE-MODULE-FROM-STRINGIFIED-SOURCE "/PL-KERNEL-KB"
    "(:DOCUMENTATION \"Defines foundation classes and relations for
PowerLoom.\" :USES (\"LOGIC\" \"STELLA\") :SHADOW (COLLECTION SET RELATION FUNCTION CLASS LIST VALUE ARITY INVERSE CLASS-PROTOTYPE NAME) :NICKNAME \"PL-KERNEL\" :PROTECT-SURROGATES? TRUE)")
   (DEFINE-MODULE-FROM-STRINGIFIED-SOURCE "/LOGIC/CASE-SENSITIVE-API"
    "(:DOCUMENTATION \"Defines an API for PowerLoom that is case-sensitive
and prefers strings for input and output.\" :LISP-PACKAGE \"STELLA\" :INCLUDES \"LOGIC\" :CASE-SENSITIVE? TRUE :USES (\"STELLA\") :CLEARABLE? FALSE)")
   (DEFINE-MODULE-FROM-STRINGIFIED-SOURCE "/PL-KERNEL-KB/PL-USER"
    "(:DOCUMENTATION \"The default module for PowerLoom users.  It does not
contain any local declarations or axioms, but it includes other modules
needed to call PowerLoom functions.\" :INCLUDES (\"PL-KERNEL\" \"CASE-SENSITIVE-API\") :USES (\"LOGIC\" \"STELLA\"))")
   (DEFINE-MODULE-FROM-STRINGIFIED-SOURCE "/PL-KERNEL-KB/LOOM-API"
    "(:DOCUMENTATION \"Defines a Loom API for PowerLoom.\" :LISP-PACKAGE \"LOOM-API\" :INCLUDES \"PL-KERNEL\" :USES (\"LOGIC\" \"STELLA\") :PROTECT-SURROGATES? TRUE)")
   (DEFINE-MODULE-FROM-STRINGIFIED-SOURCE
    "/PL-KERNEL-KB/KIF-FRAME-ONTOLOGY"
    "(:DOCUMENTATION \"Defines KIF-compatible frame predicates following
Ontolingua conventions.\" :USES (\"LOGIC\" \"STELLA\"))")
   (DEFINE-MODULE-FROM-STRINGIFIED-SOURCE
    "/PL-KERNEL-KB/CYC-FRAME-ONTOLOGY"
    "(:DOCUMENTATION \"Defines Cyc-compatible frame predicates.\" :USES (\"LOGIC\" \"STELLA\"))"))
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE "/LOGIC" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ SYM-STARTUP-SYSTEM-LOGIC-STARTUP-LOGIC-SYSTEM
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-LOGIC-SYSTEM" NULL 0))
    (CL:SETQ SYM-STARTUP-SYSTEM-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" TRUE) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "STARTUP-LOGIC-SYSTEM"
     "(DEFUN STARTUP-LOGIC-SYSTEM () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-LOGIC-SYSTEM) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION SYM-STARTUP-SYSTEM-LOGIC-STARTUP-LOGIC-SYSTEM)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-STARTUP-SYSTEM-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "Startup-Logic-System") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (CL:LET*
     ((PHASE NULL-INTEGER) (ITER-000 0) (UPPER-BOUND-001 9)
      (UNBOUNDED?-002 (NULL? UPPER-BOUND-001)))
     (CL:DECLARE (CL:TYPE CL:FIXNUM ITER-000 UPPER-BOUND-001 PHASE))
     (CL:LOOP WHILE
      (CL:OR UNBOUNDED?-002 (CL:<= ITER-000 UPPER-BOUND-001)) DO
      (CL:PROGN (CL:SETQ PHASE ITER-000)
       (CL:SETQ ITER-000 (CL:1+ ITER-000)))
      (CL:SETQ *STARTUP-TIME-PHASE* PHASE) (STARTUP-LOGIC-MACROS)
      (STARTUP-SEQUENCE-INDICES) (STARTUP-KIF-IN) (STARTUP-PROPOSITIONS)
      (STARTUP-BACKLINKS) (STARTUP-PROPAGATE) (STARTUP-INFERENCE-CACHES)
      (STARTUP-DESCRIPTIONS) (STARTUP-NORMALIZE) (STARTUP-RULES)
      (STARTUP-PARTIAL-MATCH) (STARTUP-MACHINE-LEARNING)
      (STARTUP-RULE-INDUCTION) (STARTUP-NEURAL-NETWORK)
      (STARTUP-CASE-BASED) (STARTUP-QUERY) (STARTUP-GOAL-CACHES)
      (STARTUP-STRATEGIES) (STARTUP-JUSTIFICATIONS) (STARTUP-KIF-OUT)
      (STARTUP-PRINT) (STARTUP-GENERATE) (STARTUP-SPECIALISTS)
      (STARTUP-SPECIALIZE) (STARTUP-OPTIMIZE) (STARTUP-CLASSIFY)
      (STARTUP-LOGIC-IN) (/PL-KERNEL-KB/STARTUP-PL-KERNEL-KB)
      (/PL-KERNEL-KB/STARTUP-ARITHMETIC) (STARTUP-FRAME-SUPPORT)
      (LOOM-API::STARTUP-LOOM-SUPPORT) (STARTUP-LOOM-TO-KIF)
      (STARTUP-API-SUPPORT) (STARTUP-API) (|STARTUP-STRING-API|)
      (STARTUP-POWERLOOM)))
    (CL:SETQ *STARTUP-TIME-PHASE* 999))))
