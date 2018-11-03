// logic-macros.hh

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | 
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

// Class headers:
class Logic_Exception;
class Proposition_Error;
class Parsing_Error;
class Clash;
class Fail;
class Query_Thread_Limit_Violation;

// Function signatures:
Logic_Exception* new_logic_exception();
Proposition_Error* new_proposition_error();
Parsing_Error* new_parsing_error();
Clash* new_clash();
Fail* new_fail();
Query_Thread_Limit_Violation* new_query_thread_limit_violation();
Object* signal_parsing_error_expander(Cons* body);
Object* signal_proposition_error_expander(Cons* message);
Object* signal_proposition_warning_expander(Cons* message);
Object* move_in_place_expander();
Object* move_forward_expander();
Object* move_backward_expander();
Object* move_down_expander();
Object* move_down_to_function_expander();
Object* move_up_expander(Symbol* successP, Symbol* keepframeP);
Object* move_up_or_exit_expander(Symbol* successP, Symbol* keepframeP);
void startup_logic_macros();

// Global declarations:
extern Surrogate* SGT_LOGIC_MACROS_LOGIC_EXCEPTION;
extern Surrogate* SGT_LOGIC_MACROS_PROPOSITION_ERROR;
extern Surrogate* SGT_LOGIC_MACROS_PARSING_ERROR;
extern Surrogate* SGT_LOGIC_MACROS_CLASH;
extern Surrogate* SGT_LOGIC_MACROS_FAIL;
extern Surrogate* SGT_LOGIC_MACROS_QUERY_THREAD_LIMIT_VIOLATION;
extern Proposition_Error* oTHE_PROPOSITION_ERRORo;
extern Parsing_Error* oTHE_PARSING_ERRORo;
extern Clash* oTHE_CLASH_EXCEPTIONo;
extern Fail* oTHE_FAIL_EXCEPTIONo;
extern Query_Thread_Limit_Violation* oTHE_QUERY_THREAD_LIMIT_VIOLATIONo;
extern Symbol* SYM_LOGIC_MACROS_SPECIAL;
extern Symbol* SYM_LOGIC_MACROS_oPRINTREADABLYpo;
extern Symbol* SYM_LOGIC_MACROS_TRUE;
extern Symbol* SYM_LOGIC_MACROS_INFORM;
extern Symbol* SYM_LOGIC_MACROS_EOL;
extern Symbol* SYM_LOGIC_MACROS_SIGNAL;
extern Symbol* SYM_LOGIC_MACROS_oTHE_PARSING_ERRORo;
extern Symbol* SYM_LOGIC_MACROS_SIGNAL_PARSING_ERROR;
extern Symbol* SYM_LOGIC_MACROS_SIGNAL_PARSING_ERROR_EXPANDER;
extern Symbol* SYM_LOGIC_MACROS_PRINT;
extern Symbol* SYM_LOGIC_MACROS_oPROPOSITIONUNDERCONSTRUCTIONo;
extern Symbol* SYM_LOGIC_MACROS_oTHE_PROPOSITION_ERRORo;
extern Symbol* SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_ERROR;
extern Symbol* SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_ERROR_EXPANDER;
extern Symbol* SYM_LOGIC_MACROS_WARN;
extern Symbol* SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_WARNING;
extern Symbol* SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_WARNING_EXPANDER;
extern Symbol* SYM_LOGIC_MACROS_SETQ;
extern Symbol* SYM_LOGIC_MACROS_LASTMOVE;
extern Keyword* KWD_LOGIC_MACROS_DOWN;
extern Symbol* SYM_LOGIC_MACROS_MOVE_IN_PLACE;
extern Symbol* SYM_LOGIC_MACROS_MOVE_IN_PLACE_EXPANDER;
extern Symbol* SYM_LOGIC_MACROS_LET;
extern Symbol* SYM_LOGIC_MACROS_BACKFRAME;
extern Symbol* SYM_LOGIC_MACROS_FRAME;
extern Symbol* SYM_LOGIC_MACROS_UPFRAME;
extern Symbol* SYM_LOGIC_MACROS_UP;
extern Symbol* SYM_LOGIC_MACROS_CREATE_DOWN_FRAME;
extern Symbol* SYM_LOGIC_MACROS_PROPOSITION;
extern Symbol* SYM_LOGIC_MACROS_SETF;
extern Symbol* SYM_LOGIC_MACROS_BACK;
extern Symbol* SYM_LOGIC_MACROS_STATE;
extern Keyword* KWD_LOGIC_MACROS_AND;
extern Symbol* SYM_LOGIC_MACROS_ARGUMENT_CURSOR;
extern Symbol* SYM_LOGIC_MACROS_1i;
extern Symbol* SYM_LOGIC_MACROS_MOVE_FORWARD;
extern Symbol* SYM_LOGIC_MACROS_MOVE_FORWARD_EXPANDER;
extern Symbol* SYM_LOGIC_MACROS_FORWARDFRAME;
extern Symbol* SYM_LOGIC_MACROS_NULL;
extern Symbol* SYM_LOGIC_MACROS_DOWN;
extern Symbol* SYM_LOGIC_MACROS_POP_CONTROL_FRAME;
extern Symbol* SYM_LOGIC_MACROS_QUERYENVIRONMENT;
extern Symbol* SYM_LOGIC_MACROS_MOVE_BACKWARD;
extern Symbol* SYM_LOGIC_MACROS_MOVE_BACKWARD_EXPANDER;
extern Symbol* SYM_LOGIC_MACROS_PROGN;
extern Symbol* SYM_LOGIC_MACROS_DEPTH;
extern Symbol* SYM_LOGIC_MACROS_COND;
extern Symbol* SYM_LOGIC_MACROS_g;
extern Symbol* SYM_LOGIC_MACROS_CURRENT_DEPTH_CUTOFF;
extern Symbol* SYM_LOGIC_MACROS_WHEN;
extern Symbol* SYM_LOGIC_MACROS_DEFINEDp;
extern Symbol* SYM_LOGIC_MACROS_POP_FRAMES_DOWN_TO;
extern Symbol* SYM_LOGIC_MACROS_1_;
extern Symbol* SYM_LOGIC_MACROS_MV_SETQ;
extern Symbol* SYM_LOGIC_MACROS_HANDLE_DEPTH_VIOLATION;
extern Keyword* KWD_LOGIC_MACROS_UP_FAIL;
extern Symbol* SYM_LOGIC_MACROS_OTHERWISE;
extern Symbol* SYM_LOGIC_MACROS_NTH;
extern Symbol* SYM_LOGIC_MACROS_ARGUMENTS;
extern Symbol* SYM_LOGIC_MACROS_DEBUG_DEPTH;
extern Symbol* SYM_LOGIC_MACROS_MOVE_DOWN;
extern Symbol* SYM_LOGIC_MACROS_MOVE_DOWN_EXPANDER;
extern Symbol* SYM_LOGIC_MACROS_IF;
extern Symbol* SYM_LOGIC_MACROS_ge;
extern Symbol* SYM_LOGIC_MACROS_DEFINING_PROPOSITION;
extern Symbol* SYM_LOGIC_MACROS_CAST;
extern Symbol* SYM_LOGIC_MACROS_PATTERN_VARIABLE;
extern Symbol* SYM_LOGIC_MACROS_MOVE_DOWN_TO_FUNCTION;
extern Symbol* SYM_LOGIC_MACROS_MOVE_DOWN_TO_FUNCTION_EXPANDER;
extern Symbol* SYM_LOGIC_MACROS_FAIL;
extern Keyword* KWD_LOGIC_MACROS_UP_TRUE;
extern Symbol* SYM_LOGIC_MACROS_UPDATE_GOAL_CACHE;
extern Symbol* SYM_LOGIC_MACROS_FALSE;
extern Symbol* SYM_LOGIC_MACROS_KEEP_FRAME;
extern Symbol* SYM_LOGIC_MACROS_SAFETY;
extern Symbol* SYM_LOGIC_MACROS_NULLp;
extern Symbol* SYM_LOGIC_MACROS_MOVE_UP;
extern Symbol* SYM_LOGIC_MACROS_MOVE_UP_EXPANDER;
extern Symbol* SYM_LOGIC_MACROS_RETURN;
extern Symbol* SYM_LOGIC_MACROS_MOVE_UP_OR_EXIT;
extern Symbol* SYM_LOGIC_MACROS_MOVE_UP_OR_EXIT_EXPANDER;

class Logic_Exception : public Exception {
public:
  virtual Surrogate* primary_type();
};

class Proposition_Error : public Logic_Exception {
public:
  virtual Surrogate* primary_type();
};

class Parsing_Error : public Logic_Exception {
public:
  virtual Surrogate* primary_type();
};

class Clash : public Logic_Exception {
public:
  virtual Surrogate* primary_type();
};

class Fail : public Logic_Exception {
public:
  virtual Surrogate* primary_type();
};

class Query_Thread_Limit_Violation : public Logic_Exception {
public:
  virtual Surrogate* primary_type();
};

