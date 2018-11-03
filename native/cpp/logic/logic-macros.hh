//  -*- Mode: C++ -*-

// logic-macros.hh

/*--------------------------------------------------------------------------+
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
 +--------------------------------------------------------------------------*/


namespace logic {
  using namespace stella;

// Class definitions:
class LogicException : public StellaException {
public:
  LogicException(const std::string& msg) : StellaException(msg) {
}

};

class PropositionError : public LogicException {
public:
  PropositionError(const std::string& msg) : LogicException(msg) {
}

};

class ParsingError : public LogicException {
public:
  ParsingError(const std::string& msg) : LogicException(msg) {
}

};

class Clash : public LogicException {
public:
  Clash(const std::string& msg) : LogicException(msg) {
}

};

class FailException : public LogicException {
public:
  FailException(const std::string& msg) : LogicException(msg) {
}

};

class QueryThreadLimitViolation : public LogicException {
public:
  QueryThreadLimitViolation(const std::string& msg) : LogicException(msg) {
}

};


// Global declarations:
extern DECLARE_STELLA_SPECIAL(oSUPPRESSNONLOGICOBJECTWARNINGpo, boolean );
extern boolean oCYC_KLUDGES_ENABLEDpo;

// Function signatures:
LogicException* newLogicException(char* message);
PropositionError* newPropositionError(char* message);
ParsingError* newParsingError(char* message);
Clash* newClash(char* message);
FailException* newFailException(char* message);
QueryThreadLimitViolation* newQueryThreadLimitViolation(char* message);
Object* signalParsingError(Cons* message);
Object* signalPropositionError(Cons* message);
Object* signalPropositionWarning(Cons* message);
Object* defDisplayGlobals(Symbol* displayfunctionname, Cons* globalvariablenames);
Object* moveInPlace();
Object* moveDown();
Object* moveUp(Symbol* successP, Symbol* keepframeP);
Object* applyRetrieve(Cons* body);
Object* applyAsk(Cons* body);
Object* withinMetaCache(Cons* body);
Object* withinClassificationSession(Keyword* descriptionorinstance, Cons* body);
Object* defineComputedConstraint(Symbol* name, Cons* varList, Cons* constraintTest, Cons* positionComputations);
Object* defineArithmeticTestOnWrappers(Symbol* name, Symbol* testName);
Object* defineArithmeticOperationOnWrappers(Symbol* name, Symbol* operationName);
Object* withLogicEnvironment(Object* moduleform, Object* environment, Cons* body);
Object* whenCycKludgesEnabled(Cons* body);
void helpStartupLogicMacros1();
void helpStartupLogicMacros2();
void startupLogicMacros();

// Auxiliary global declarations:
extern Symbol* SYM_LOGIC_MACROS_STELLA_LET;
extern Symbol* SYM_LOGIC_MACROS_STELLA_NEW;
extern Symbol* SYM_LOGIC_MACROS_STELLA_OUTPUT_STRING_STREAM;
extern Symbol* SYM_LOGIC_MACROS_STELLA_SPECIAL;
extern Symbol* SYM_LOGIC_MACROS_STELLA_oPRINTREADABLYpo;
extern Symbol* SYM_LOGIC_MACROS_STELLA_TRUE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_PRINT_STREAM;
extern Symbol* SYM_LOGIC_MACROS_STELLA_EOL;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_HELP_SIGNAL_PROPOSITION_ERROR;
extern Keyword* KWD_LOGIC_MACROS_ERROR;
extern Symbol* SYM_LOGIC_MACROS_STELLA_SIGNAL_EXCEPTION;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_PARSING_ERROR;
extern Keyword* KWD_LOGIC_MACROS_MESSAGE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_THE_STRING;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_PROPOSITION_ERROR;
extern Symbol* SYM_LOGIC_MACROS_STELLA_STANDARD_WARNING;
extern Keyword* KWD_LOGIC_MACROS_WARNING;
extern Symbol* SYM_LOGIC_MACROS_STELLA_DEFUN;
extern Symbol* SYM_LOGIC_MACROS_STELLA_STRING;
extern Symbol* SYM_LOGIC_MACROS_STELLA_PRINT;
extern Symbol* SYM_LOGIC_MACROS_STELLA_RETURN;
extern Symbol* SYM_LOGIC_MACROS_STELLA_PROGN;
extern Symbol* SYM_LOGIC_MACROS_STELLA_SETF;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_TRUTH_VALUE;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_FRAME;
extern Symbol* SYM_LOGIC_MACROS_STELLA_NULL;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_JUSTIFICATION;
extern Symbol* SYM_LOGIC_MACROS_STELLA_WHEN;
extern Symbol* SYM_LOGIC_MACROS_STELLA_DEFINEDp;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_PARTIAL_MATCH_FRAME;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_CLEAR_FRAME_PARTIAL_TRUTH;
extern Symbol* SYM_LOGIC_MACROS_STELLA_SETQ;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_LASTMOVE;
extern Keyword* KWD_LOGIC_MACROS_DOWN;
extern Symbol* SYM_LOGIC_MACROS_STELLA_COND;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_CHECKFORMOVEOUTp;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_PARENT;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_UP;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_STARTTICKS;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_STARTING_CLOCK_TICKS;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_AVAILABLETICKS;
extern Symbol* SYM_LOGIC_MACROS_STELLA__;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_ALLOTTED_CLOCK_TICKS;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_CLOCKTICKS;
extern Symbol* SYM_LOGIC_MACROS_STELLA___;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_CURRENT_CLOCK_TICKS;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_QUERY;
extern Symbol* SYM_LOGIC_MACROS_STELLA_ii;
extern Symbol* SYM_LOGIC_MACROS_STELLA_le;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_POP_FRAMES_UP_TO;
extern Symbol* SYM_LOGIC_MACROS_STELLA_MV_SETQ;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_DEPTH;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_HANDLE_TIMEOUT;
extern Keyword* KWD_LOGIC_MACROS_UP_FAIL;
extern Symbol* SYM_LOGIC_MACROS_STELLA_1i;
extern Symbol* SYM_LOGIC_MACROS_STELLA_OTHERWISE;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_UPFRAME;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_DOWNFRAME;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_DOWN;
extern Symbol* SYM_LOGIC_MACROS_STELLA_AND;
extern Symbol* SYM_LOGIC_MACROS_STELLA_NULLp;
extern Symbol* SYM_LOGIC_MACROS_STELLA_1_;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_PROPOSITION;
extern Symbol* SYM_LOGIC_MACROS_STELLA_NTH;
extern Symbol* SYM_LOGIC_MACROS_STELLA_ARGUMENTS;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_ARGUMENT_CURSOR;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_CREATE_DOWN_FRAME;
extern Symbol* SYM_LOGIC_MACROS_STELLA_g;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_CURRENT_DEPTH_CUTOFF;
extern Symbol* SYM_LOGIC_MACROS_STELLA_EQLp;
extern Symbol* SYM_LOGIC_MACROS_STELLA_STATE;
extern Keyword* KWD_LOGIC_MACROS_PATTERN;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_HANDLE_DEPTH_VIOLATION;
extern Symbol* SYM_LOGIC_MACROS_STELLA_NOT;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_FAIL;
extern Keyword* KWD_LOGIC_MACROS_UP_TRUE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_FALSE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_RESULT;
extern Symbol* SYM_LOGIC_MACROS_STELLA_IF;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_CACHE_QUERY_RESULTSp;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_CACHE_GOAL;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_UPDATE_GOAL_CACHE;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_SUCCESSp;
extern Symbol* SYM_LOGIC_MACROS_STELLA_BREAK;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_KEEP_FRAME;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_POP_DOWN_FRAME;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_APPLY_CACHED_RETRIEVE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_BQUOTE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_CONS_LIST;
extern Symbol* SYM_LOGIC_MACROS_STELLA_QUOTE;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_APPLY_CACHED_ASK;
extern Symbol* SYM_LOGIC_MACROS_STELLA_oCONTEXTo;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_GET_INFERENCE_CACHE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_oMODULEo;
extern Keyword* KWD_LOGIC_MACROS_META;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_oCLASSIFICATIONSESSIONo;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_GET_CLASSIFICATION_SESSION;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_CLASSIFICATION_WORLD;
extern Symbol* SYM_LOGIC_MACROS_STELLA_OBJECT;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_MISSING_ARGUMENT;
extern Symbol* SYM_LOGIC_MACROS_STELLA_INTEGER_WRAPPER;
extern Symbol* SYM_LOGIC_MACROS_STELLA_CASE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_WRAPPER_VALUE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_BOOLEAN;
extern Symbol* SYM_LOGIC_MACROS_STELLA_X;
extern Symbol* SYM_LOGIC_MACROS_STELLA_NUMBER_WRAPPER;
extern Symbol* SYM_LOGIC_MACROS_STELLA_Y;
extern Keyword* KWD_LOGIC_MACROS_PUBLICp;
extern Symbol* SYM_LOGIC_MACROS_STELLA_TYPECASE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_FLOAT_WRAPPER;
extern Symbol* SYM_LOGIC_MACROS_STELLA_CAST;
extern Symbol* SYM_LOGIC_MACROS_STELLA_FLOAT;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_FLOATRESULT;
extern Symbol* SYM_LOGIC_MACROS_STELLA_WRAP_LITERAL;
extern Symbol* SYM_LOGIC_MACROS_STELLA_SAFE_CAST;
extern Symbol* SYM_LOGIC_MACROS_STELLA_INTEGER;
extern Symbol* SYM_LOGIC_MACROS_STELLA_MODULE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_CONTEXT;
extern Symbol* SYM_LOGIC_MACROS_STELLA_IGNORE;
extern Symbol* SYM_LOGIC_MACROS_STELLA_WITH_PROCESS_LOCK;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_oPOWERLOOM_LOCKo;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_oCYC_KLUDGES_ENABLEDpo;
extern Symbol* SYM_LOGIC_MACROS_LOGIC_STARTUP_LOGIC_MACROS;
extern Symbol* SYM_LOGIC_MACROS_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
