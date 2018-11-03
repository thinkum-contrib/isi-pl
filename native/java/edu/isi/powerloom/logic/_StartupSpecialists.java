//  -*- Mode: Java -*-
//
// _StartupSpecialists.java

/*
 +--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997-2003              |
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
 +--------------------------------------------------------------------------+
*/

package edu.isi.powerloom.logic;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.stella.*;

public class _StartupSpecialists {
  static void helpStartupSpecialists1() {
    {
      Logic.SYM_LOGIC_PROCEDURE_NAME = ((Symbol)(Stella.internRigidSymbolWrtModule("PROCEDURE-NAME", null, 0)));
      Logic.SYM_LOGIC_PROCEDURE_CODE = ((Symbol)(Stella.internRigidSymbolWrtModule("PROCEDURE-CODE", null, 0)));
      Logic.SGT_PL_KERNEL_KB_RELATION_SPECIALIST = ((Surrogate)(Stella.internRigidSymbolWrtModule("RELATION-SPECIALIST", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_HANDLES_REVERSE_POLARITY = ((Surrogate)(Stella.internRigidSymbolWrtModule("HANDLES-REVERSE-POLARITY", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_RELATION_CONSTRAINT = ((Surrogate)(Stella.internRigidSymbolWrtModule("RELATION-CONSTRAINT", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_RELATION_EVALUATOR = ((Surrogate)(Stella.internRigidSymbolWrtModule("RELATION-EVALUATOR", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_STELLA_FUNCTION_CODE_WRAPPER = ((Surrogate)(Stella.internRigidSymbolWrtModule("FUNCTION-CODE-WRAPPER", Stella.getStellaModule("/STELLA", true), 1)));
      Logic.SGT_STELLA_METHOD_CODE_WRAPPER = ((Surrogate)(Stella.internRigidSymbolWrtModule("METHOD-CODE-WRAPPER", Stella.getStellaModule("/STELLA", true), 1)));
      Logic.SGT_LOGIC_SUBSTRING_POSITION_ITERATOR = ((Surrogate)(Stella.internRigidSymbolWrtModule("SUBSTRING-POSITION-ITERATOR", null, 1)));
      Logic.SYM_LOGIC_SUPER_STRING = ((Symbol)(Stella.internRigidSymbolWrtModule("SUPER-STRING", null, 0)));
      Logic.SYM_LOGIC_SUB_STRING = ((Symbol)(Stella.internRigidSymbolWrtModule("SUB-STRING", null, 0)));
      Logic.SYM_STELLA_START = ((Symbol)(Stella.internRigidSymbolWrtModule("START", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.SYM_LOGIC_SUB_LENGTH = ((Symbol)(Stella.internRigidSymbolWrtModule("SUB-LENGTH", null, 0)));
      Logic.SYM_STELLA_DUMMY = ((Symbol)(Stella.internRigidSymbolWrtModule("DUMMY", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.KWD_INHERIT = ((Keyword)(Stella.internRigidSymbolWrtModule("INHERIT", null, 2)));
      Logic.KWD_ALL = ((Keyword)(Stella.internRigidSymbolWrtModule("ALL", null, 2)));
      Logic.KWD_CURRENT = ((Keyword)(Stella.internRigidSymbolWrtModule("CURRENT", null, 2)));
      Logic.SYM_LOGIC_QUERY_SPECIALIST_IO_VARIABLES = ((Symbol)(Stella.internRigidSymbolWrtModule("QUERY-SPECIALIST-IO-VARIABLES", null, 0)));
      Logic.SGT_LOGIC_F_CLOSED_TERMp_MEMO_TABLE_000 = ((Surrogate)(Stella.internRigidSymbolWrtModule("F-CLOSED-TERM?-MEMO-TABLE-000", null, 1)));
      Logic.SGT_LOGIC_F_CLOSED_PROPOSITIONp_MEMO_TABLE_000 = ((Surrogate)(Stella.internRigidSymbolWrtModule("F-CLOSED-PROPOSITION?-MEMO-TABLE-000", null, 1)));
      Logic.SGT_PL_KERNEL_KB_SINGLE_VALUED = ((Surrogate)(Stella.internRigidSymbolWrtModule("SINGLE-VALUED", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_LOGIC_F_SINGLE_VALUED_TERMp_MEMO_TABLE_000 = ((Surrogate)(Stella.internRigidSymbolWrtModule("F-SINGLE-VALUED-TERM?-MEMO-TABLE-000", null, 1)));
      Logic.SYM_LOGIC_pSUPER = ((Symbol)(Stella.internRigidSymbolWrtModule("?SUPER", null, 0)));
      Logic.SYM_LOGIC_pMDC = ((Symbol)(Stella.internRigidSymbolWrtModule("?MDC", null, 0)));
      Logic.SYM_LOGIC_MEMBER_OF = ((Symbol)(Stella.internRigidSymbolWrtModule("MEMBER-OF", null, 0)));
      Logic.SYM_LOGIC_MUTUALLY_DISJOINT_COLLECTION = ((Symbol)(Stella.internRigidSymbolWrtModule("MUTUALLY-DISJOINT-COLLECTION", null, 0)));
      Logic.SYM_LOGIC_F_HELP_DERIVE_PARTITION_MEMBERSHIPS_QUERY_000 = ((Symbol)(Stella.internRigidSymbolWrtModule("F-HELP-DERIVE-PARTITION-MEMBERSHIPS-QUERY-000", null, 0)));
      Logic.SGT_PL_KERNEL_KB_MUTUALLY_DISJOINT_COLLECTION = ((Surrogate)(Stella.internRigidSymbolWrtModule("MUTUALLY-DISJOINT-COLLECTION", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_PARTITION_MEMBERSHIP = ((Surrogate)(Stella.internRigidSymbolWrtModule("PARTITION-MEMBERSHIP", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_HAS_PARTITION_MEMBERSHIP = ((Surrogate)(Stella.internRigidSymbolWrtModule("HAS-PARTITION-MEMBERSHIP", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_EMPTY = ((Surrogate)(Stella.internRigidSymbolWrtModule("EMPTY", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_LOGIC_SAVED_CONTEXT_PROOF_ADJUNCT = ((Surrogate)(Stella.internRigidSymbolWrtModule("SAVED-CONTEXT-PROOF-ADJUNCT", null, 1)));
      Logic.SYM_LOGIC_SAVED_CONTEXT = ((Symbol)(Stella.internRigidSymbolWrtModule("SAVED-CONTEXT", null, 0)));
      Logic.KWD_IST_INTRODUCTION = ((Keyword)(Stella.internRigidSymbolWrtModule("IST-INTRODUCTION", null, 2)));
      Logic.SGT_PL_KERNEL_KB_THE_ROLESET = ((Surrogate)(Stella.internRigidSymbolWrtModule("THE-ROLESET", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_CARDINALITY = ((Surrogate)(Stella.internRigidSymbolWrtModule("CARDINALITY", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.KWD_LOWER = ((Keyword)(Stella.internRigidSymbolWrtModule("LOWER", null, 2)));
      Logic.KWD_UPPER = ((Keyword)(Stella.internRigidSymbolWrtModule("UPPER", null, 2)));
      Logic.SGT_PL_KERNEL_KB_DIRECT_SUBRELATION = ((Surrogate)(Stella.internRigidSymbolWrtModule("DIRECT-SUBRELATION", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_DIRECT_SUPERRELATION = ((Surrogate)(Stella.internRigidSymbolWrtModule("DIRECT-SUPERRELATION", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_SUBRELATION = ((Surrogate)(Stella.internRigidSymbolWrtModule("SUBRELATION", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_SUPERRELATION = ((Surrogate)(Stella.internRigidSymbolWrtModule("SUPERRELATION", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_PROPER_SUBRELATION = ((Surrogate)(Stella.internRigidSymbolWrtModule("PROPER-SUBRELATION", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_PROPER_SUPERRELATION = ((Surrogate)(Stella.internRigidSymbolWrtModule("PROPER-SUPERRELATION", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_EQUIVALENT_RELATION = ((Surrogate)(Stella.internRigidSymbolWrtModule("EQUIVALENT-RELATION", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_SYNONYM = ((Surrogate)(Stella.internRigidSymbolWrtModule("SYNONYM", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SYM_LOGIC_STARTUP_SPECIALISTS = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-SPECIALISTS", null, 0)));
    }
  }

  static void helpStartupSpecialists2() {
    {
      Stella.defineFunctionObject("FUNCTION-CODE-FROM-PROCEDURE", "(DEFUN (FUNCTION-CODE-FROM-PROCEDURE FUNCTION-CODE) ((P OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "functionCodeFromProcedure", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("LOOKUP-SPECIALIST", "(DEFUN (LOOKUP-SPECIALIST FUNCTION-CODE) ((DESCRIPTION NAMED-DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.NamedDescription", "lookupSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.NamedDescription")}), null);
      Stella.defineFunctionObject("LOOKUP-CONSTRAINT", "(DEFUN (LOOKUP-CONSTRAINT FUNCTION-CODE) ((DESCRIPTION NAMED-DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.NamedDescription", "lookupConstraint", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.NamedDescription")}), null);
      Stella.defineFunctionObject("LOOKUP-COMPUTATION", "(DEFUN (LOOKUP-COMPUTATION FUNCTION-CODE) ((DESCRIPTION NAMED-DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.NamedDescription", "lookupComputation", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.NamedDescription")}), null);
      Stella.defineFunctionObject("LOOKUP-EVALUATOR", "(DEFUN (LOOKUP-EVALUATOR FUNCTION-CODE) ((DESCRIPTION NAMED-DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.NamedDescription", "lookupEvaluator", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.NamedDescription")}), null);
      Stella.defineFunctionObject("REPORT-COMPUTED-RESULT", "(DEFUN (REPORT-COMPUTED-RESULT KEYWORD) ((SUCCESS? BOOLEAN) (PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "reportComputedResult", new java.lang.Class [] {java.lang.Boolean.TYPE, Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("NULL-WRAPPER?", "(DEFUN (NULL-WRAPPER? BOOLEAN) ((SELF OBJECT)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "nullWrapperP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("NATIVE-SLOT-READER-SPECIALIST", "(DEFUN (NATIVE-SLOT-READER-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "nativeSlotReaderSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((IT SUBSTRING-POSITION-ITERATOR)))", Native.find_java_method("edu.isi.powerloom.logic.SubstringPositionIterator", "nextP", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD (LENGTH INTEGER) ((IT SUBSTRING-POSITION-ITERATOR)))", Native.find_java_method("edu.isi.powerloom.logic.SubstringPositionIterator", "length", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject(" /PL-KERNEL-KB/COMPUTATION-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/COMPUTATION-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "computationSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/CONSTRAINT-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/CONSTRAINT-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "constraintSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/SQUARE-ROOT-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/SQUARE-ROOT-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "squareRootSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject("SELECT-PROOF-RESULT", "(DEFUN (SELECT-PROOF-RESULT KEYWORD) ((SUCCESS? BOOLEAN) (CONTINUING? BOOLEAN) (TERMINAL? BOOLEAN)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "selectProofResult", new java.lang.Class [] {java.lang.Boolean.TYPE, java.lang.Boolean.TYPE, java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("ENUMERATIONS-CONTAINING-MEMBER", "(DEFUN (ENUMERATIONS-CONTAINING-MEMBER LIST) ((SELF OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "enumerationsContainingMember", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/MEMBER-OF-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/MEMBER-OF-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "memberOfSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/MEMBER-OF-EVALUATOR", "(DEFUN /PL-KERNEL-KB/MEMBER-OF-EVALUATOR ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "memberOfEvaluator", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/INSTANCE-OF-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/INSTANCE-OF-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "instanceOfSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/SUBSET-OF-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/SUBSET-OF-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "subsetOfSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/HOLDS-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/HOLDS-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "holdsSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/CUT-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/CUT-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "cutSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/BOUND-VARIABLES-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/BOUND-VARIABLES-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "boundVariablesSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/FORK-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/FORK-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "forkSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject("COMPUTE-SUBQUERY-OPTIONS", "(DEFUN (COMPUTE-SUBQUERY-OPTIONS PROPOSITION PROPERTY-LIST) ((FRAME CONTROL-FRAME)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "computeSubqueryOptions", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("[Ljava.lang.Object;")}), null);
      Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT CONTROL-FRAME QUERY-SPECIALIST-IO-VARIABLES :TYPE LIST :ALLOCATION :DYNAMIC)");
      Stella.defineFunctionObject("CREATE-QUERY-SPECIALIST-ITERATOR", "(DEFUN (CREATE-QUERY-SPECIALIST-ITERATOR QUERY-ITERATOR BOOLEAN BOOLEAN) ((FRAME CONTROL-FRAME)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "createQuerySpecialistIterator", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("[Ljava.lang.Object;")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/QUERY-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/QUERY-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "querySpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/CONCEPT-PROTOTYPE-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/CONCEPT-PROTOTYPE-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "conceptPrototypeSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject("CONCEPT-PROTOTYPE?", "(DEFUN (CONCEPT-PROTOTYPE? BOOLEAN) ((SELF LOGIC-OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.LogicObject", "conceptPrototypeP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/CLOSED-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/CLOSED-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "closedSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject("CLOSED-BY-ASSERTION?", "(DEFUN (CLOSED-BY-ASSERTION? BOOLEAN) ((SELF OBJECT)) :GLOBALLY-INLINE? TRUE (RETURN (AND (TEST-PROPERTY? SELF /PL-KERNEL-KB/@CLOSED) (NOT (MONOTONIC? *CONTEXT*)))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "closedByAssertionP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("CLOSED-TERM?", "(DEFUN (CLOSED-TERM? BOOLEAN) ((SELF OBJECT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (MEMOIZE (SELF *CONTEXT*) :TIMESTAMPS :KB-UPDATE :MAX-VALUES 500 (HELP-CLOSED-TERM? SELF NIL))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "closedTermP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("HELP-CLOSED-TERM?", "(DEFUN (HELP-CLOSED-TERM? BOOLEAN) ((SELF OBJECT) (ACTIVETERMS CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "helpClosedTermP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("CLOSED-PROPOSITION?", "(DEFUN (CLOSED-PROPOSITION? BOOLEAN) ((SELF PROPOSITION)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (MEMOIZE (SELF *CONTEXT*) :TIMESTAMPS :META-KB-UPDATE :MAX-VALUES 500 (HELP-CLOSED-PROPOSITION? SELF NIL))))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "closedPropositionP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("HELP-CLOSED-PROPOSITION?", "(DEFUN (HELP-CLOSED-PROPOSITION? BOOLEAN) ((SELF PROPOSITION) (ACTIVETERMS CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "helpClosedPropositionP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/SINGLE-VALUED-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/SINGLE-VALUED-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "singleValuedSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject("SINGLE-VALUED-TERM?", "(DEFUN (SINGLE-VALUED-TERM? BOOLEAN) ((SELF OBJECT)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "singleValuedTermP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("NON-RECURSIVE-SINGLE-VALUED-TERM?", "(DEFUN (NON-RECURSIVE-SINGLE-VALUED-TERM? BOOLEAN) ((SELF OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "nonRecursiveSingleValuedTermP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("SINGLE-VALUED-GOAL?", "(DEFUN (SINGLE-VALUED-GOAL? BOOLEAN) ((PROPOSITION PROPOSITION) (IOVARIABLES (CONS OF PATTERN-VARIABLE)) (BOUNDVARIABLES (CONS OF PATTERN-VARIABLE))) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "singleValuedGoalP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("HELP-COLLECT-SINGLY-BOUND-VARIABLES", "(DEFUN HELP-COLLECT-SINGLY-BOUND-VARIABLES ((PROPOSITION PROPOSITION) (BOUNDVARIABLES (LIST OF PATTERN-VARIABLE))))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "helpCollectSinglyBoundVariables", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.List")}), null);
      Stella.defineFunctionObject("CREATE-COLLECT-DESCRIPTION-EXTENSION-FRAME", "(DEFUN CREATE-COLLECT-DESCRIPTION-EXTENSION-FRAME ((FRAME CONTROL-FRAME) (DESCRIPTION DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "createCollectDescriptionExtensionFrame", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.powerloom.logic.Description")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/COLLECT-INTO-SET-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/COLLECT-INTO-SET-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "collectIntoSetSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/LENGTH-OF-LIST-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/LENGTH-OF-LIST-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "lengthOfListSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/MINIMUM-OF-NUMBERS-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/MINIMUM-OF-NUMBERS-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "minimumOfNumbersSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/MAXIMUM-OF-NUMBERS-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/MAXIMUM-OF-NUMBERS-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "maximumOfNumbersSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/SUM-OF-NUMBERS-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/SUM-OF-NUMBERS-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "sumOfNumbersSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/MEAN-OF-NUMBERS-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/MEAN-OF-NUMBERS-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "meanOfNumbersSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/MEDIAN-OF-NUMBERS-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/MEDIAN-OF-NUMBERS-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "medianOfNumbersSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject("COMPUTE-VARIANCE-OR-STANDARD-DEVIATION", "(DEFUN (COMPUTE-VARIANCE-OR-STANDARD-DEVIATION KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD) (STANDARD-DEVIATION? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "computeVarianceOrStandardDeviation", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/STANDARD-DEVIATION-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/STANDARD-DEVIATION-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "standardDeviationSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/VARIANCE-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/VARIANCE-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "varianceSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject("HELP-DERIVE-PARTITION-MEMBERSHIPS", "(DEFUN HELP-DERIVE-PARTITION-MEMBERSHIPS ((SELF LOGIC-OBJECT) (SUPER LOGIC-OBJECT) (TUPLES (LIST OF PROPOSITION))))", Native.find_java_method("edu.isi.powerloom.logic.LogicObject", "helpDerivePartitionMemberships", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject"), Native.find_java_class("edu.isi.powerloom.logic.LogicObject"), Native.find_java_class("edu.isi.stella.List")}), null);
      Stella.defineFunctionObject("DERIVE-PARTITION-MEMBERSHIPS?", "(DEFUN (DERIVE-PARTITION-MEMBERSHIPS? BOOLEAN) ((SELF LOGIC-OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.LogicObject", "derivePartitionMembershipsP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/HAS-PARTITION-MEMBERSHIP-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/HAS-PARTITION-MEMBERSHIP-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "hasPartitionMembershipSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/REFUTATION-DISJOINT-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/REFUTATION-DISJOINT-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "refutationDisjointSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/EMPTY-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/EMPTY-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "emptySpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject("EMPTY-TERM?", "(DEFUN (EMPTY-TERM? BOOLEAN) ((SELF OBJECT)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "emptyTermP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("CHEAP-EMPTY-TERM?", "(DEFUN (CHEAP-EMPTY-TERM? BOOLEAN) ((SELF LOGIC-OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.LogicObject", "cheapEmptyTermP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject")}), null);
      Stella.defineFunctionObject("EXPENSIVE-EMPTY-TERM?", "(DEFUN (EXPENSIVE-EMPTY-TERM? BOOLEAN) ((SELF LOGIC-OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.LogicObject", "expensiveEmptyTermP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject")}), null);
      Stella.defineFunctionObject(" /PL-KERNEL-KB/CONTEXT-OF-COMPUTATION", "(DEFUN (/PL-KERNEL-KB/CONTEXT-OF-COMPUTATION CONTEXT) ((INSTANCE OBJECT)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "contextOfComputation", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
    }
  }

  public static void startupSpecialists() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupSpecialists.helpStartupSpecialists1();
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Logic.$ACCELERATE_FRAME_COMPUTATIONSp$ = true;
        }
        if (Stella.currentStartupTimePhaseP(5)) {
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("COMPUTED-PROCEDURE", "(DEFCLASS COMPUTED-PROCEDURE (THING) :PUBLIC? TRUE :DOCUMENTATION \"Each instance denotes a programming language \nfunction that computes some procedure.  The slot 'procedure-name'\nprovides the name of the procedure.  The slot 'procedure-code'\npoints directly to the procedure itself.  Both slots are optional;\nif neither is supplied, the procedure will be invoked by extracting\nits name from the name of the instance.\" :PUBLIC-SLOTS ((PROCEDURE-NAME :TYPE SYMBOL) (PROCEDURE-CODE :TYPE FUNCTION-CODE)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.ComputedProcedure", "newComputedProcedure", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.ComputedProcedure", "accessComputedProcedureSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ComputedProcedure"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("SUBSTRING-POSITION-ITERATOR", "(DEFCLASS SUBSTRING-POSITION-ITERATOR (ITERATOR) :SLOTS ((SUPER-STRING :TYPE STRING :REQUIRED? TRUE) (SUB-STRING :TYPE STRING :REQUIRED? TRUE) (START :TYPE INTEGER :INITIALLY 0) (SUB-LENGTH :TYPE INTEGER :INITIALLY (LENGTH (SUB-STRING SELF)))))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.SubstringPositionIterator", "newSubstringPositionIterator", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String")});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.SubstringPositionIterator", "accessSubstringPositionIteratorSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.SubstringPositionIterator"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("SAVED-CONTEXT-PROOF-ADJUNCT", "(DEFCLASS SAVED-CONTEXT-PROOF-ADJUNCT (PROOF-ADJUNCT) :SLOTS ((SAVED-CONTEXT :TYPE CONTEXT)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.SavedContextProofAdjunct", "newSavedContextProofAdjunct", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.SavedContextProofAdjunct", "accessSavedContextProofAdjunctSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.SavedContextProofAdjunct"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          _StartupSpecialists.helpStartupSpecialists2();
          Stella.defineFunctionObject(" /PL-KERNEL-KB/IST-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/IST-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "istSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("GET-ROLESET-OF", "(DEFUN (GET-ROLESET-OF SKOLEM) ((RELATION NAMED-DESCRIPTION) (INSTANCE OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.NamedDescription", "getRolesetOf", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.NamedDescription"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("COMPUTE-STORED-BOUND-ON-ROLESET", "(DEFUN (COMPUTE-STORED-BOUND-ON-ROLESET INTEGER) ((RELATION NAMED-DESCRIPTION) (INSTANCE OBJECT) (LOWERORUPPER KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.NamedDescription", "computeStoredBoundOnRoleset", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.NamedDescription"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("COMPUTE-MINIMUM-CARDINALITY", "(DEFUN (COMPUTE-MINIMUM-CARDINALITY INTEGER) ((RELATION NAMED-DESCRIPTION) (INSTANCE OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.NamedDescription", "computeMinimumCardinality", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.NamedDescription"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject(" /PL-KERNEL-KB/RANGE-MIN-CARDINALITY-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/RANGE-MIN-CARDINALITY-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "rangeMinCardinalitySpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("COMPUTE-MAXIMUM-CARDINALITY", "(DEFUN (COMPUTE-MAXIMUM-CARDINALITY INTEGER) ((RELATION NAMED-DESCRIPTION) (INSTANCE OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.NamedDescription", "computeMaximumCardinality", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.NamedDescription"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject(" /PL-KERNEL-KB/RANGE-MAX-CARDINALITY-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/RANGE-MAX-CARDINALITY-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "rangeMaxCardinalitySpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("TEST-RANGE-TYPE?", "(DEFUN (TEST-RANGE-TYPE? BOOLEAN) ((RELATION NAMED-DESCRIPTION) (INSTANCE OBJECT) (VALUETYPE NAMED-DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.NamedDescription", "testRangeTypeP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.NamedDescription"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.powerloom.logic.NamedDescription")}), null);
          Stella.defineFunctionObject(" /PL-KERNEL-KB/RANGE-TYPE-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/RANGE-TYPE-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "rangeTypeSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject(" /PL-KERNEL-KB/ARITY-COMPUTATION", "(DEFUN (/PL-KERNEL-KB/ARITY-COMPUTATION INTEGER-WRAPPER) ((DESCRIPTIONARG OBJECT)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "arityComputation", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject(" /PL-KERNEL-KB/RELATION-HIERARCHY-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/RELATION-HIERARCHY-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "relationHierarchySpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("HELP-PROJECT-NTH-COLUMN", "(DEFUN (HELP-PROJECT-NTH-COLUMN LIST) ((N INTEGER) (TUPLELIST LIST)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "helpProjectNthColumn", new java.lang.Class [] {java.lang.Integer.TYPE, Native.find_java_class("edu.isi.stella.List")}), null);
          Stella.defineFunctionObject(" /PL-KERNEL-KB/PROJECT-COLUMN-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/PROJECT-COLUMN-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "projectColumnSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject(" /PL-KERNEL-KB/ASSERT-SYNONYM-DEMON", "(DEFUN /PL-KERNEL-KB/ASSERT-SYNONYM-DEMON ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "assertSynonymDemon", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject(" /PL-KERNEL-KB/RETRACT-SYNONYM-DEMON", "(DEFUN /PL-KERNEL-KB/RETRACT-SYNONYM-DEMON ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "retractSynonymDemon", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("GET-SYNONYMS", "(DEFUN (GET-SYNONYMS (CONS OF LOGIC-OBJECT)) ((TERM OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getSynonyms", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("SYNONYM-SURROGATE?", "(DEFUN (SYNONYM-SURROGATE? BOOLEAN) ((NAME SURROGATE)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "synonymSurrogateP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("TRANSFER-SYNONYMS", "(DEFUN TRANSFER-SYNONYMS ((OLDOBJECT OBJECT) (NEWOBJECT OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "transferSynonyms", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject(" /PL-KERNEL-KB/DIFFERENT-SPECIALIST", "(DEFUN (/PL-KERNEL-KB/DIFFERENT-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "differentSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("STARTUP-SPECIALISTS", "(DEFUN STARTUP-SPECIALISTS () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupSpecialists", "startupSpecialists", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_SPECIALISTS);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("_Startup-Specialists"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *PROTOTYPE-ID-COUNTER* INTEGER 0)");
          Logic.defineExplanationPhrase(Logic.KWD_IST_INTRODUCTION, Logic.KWD_TECHNICAL, "by IST-Introduction", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_IST_INTRODUCTION, Logic.KWD_LAY, "because its argument is true", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_IST_INTRODUCTION, Logic.KWD_LAY, "because its argument is partly true", Stella_Object.cons(Logic.KWD_PARTIAL, Stella.NIL));
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *ACCELERATE-FRAME-COMPUTATIONS?* BOOLEAN TRUE :DOCUMENTATION \"Used to test how big is the effect of the frame\nspecialists.\")");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
