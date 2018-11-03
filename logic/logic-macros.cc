// logic-macros.cc

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

#include "stella-includes.hh"

Surrogate* SGT_LOGIC_MACROS_LOGIC_EXCEPTION = NULL;

Surrogate* SGT_LOGIC_MACROS_PROPOSITION_ERROR = NULL;

Surrogate* SGT_LOGIC_MACROS_PARSING_ERROR = NULL;

Surrogate* SGT_LOGIC_MACROS_CLASH = NULL;

Surrogate* SGT_LOGIC_MACROS_FAIL = NULL;

Surrogate* SGT_LOGIC_MACROS_QUERY_THREAD_LIMIT_VIOLATION = NULL;

Proposition_Error* oTHE_PROPOSITION_ERRORo = NULL;

Parsing_Error* oTHE_PARSING_ERRORo = NULL;

Clash* oTHE_CLASH_EXCEPTIONo = NULL;

Fail* oTHE_FAIL_EXCEPTIONo = NULL;

Query_Thread_Limit_Violation* oTHE_QUERY_THREAD_LIMIT_VIOLATIONo = NULL;

Symbol* SYM_LOGIC_MACROS_SPECIAL = NULL;

Symbol* SYM_LOGIC_MACROS_oPRINTREADABLYpo = NULL;

Symbol* SYM_LOGIC_MACROS_TRUE = NULL;

Symbol* SYM_LOGIC_MACROS_INFORM = NULL;

Symbol* SYM_LOGIC_MACROS_EOL = NULL;

Symbol* SYM_LOGIC_MACROS_SIGNAL = NULL;

Symbol* SYM_LOGIC_MACROS_oTHE_PARSING_ERRORo = NULL;

Symbol* SYM_LOGIC_MACROS_SIGNAL_PARSING_ERROR = NULL;

Symbol* SYM_LOGIC_MACROS_SIGNAL_PARSING_ERROR_EXPANDER = NULL;

Symbol* SYM_LOGIC_MACROS_PRINT = NULL;

Symbol* SYM_LOGIC_MACROS_oPROPOSITIONUNDERCONSTRUCTIONo = NULL;

Symbol* SYM_LOGIC_MACROS_oTHE_PROPOSITION_ERRORo = NULL;

Symbol* SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_ERROR = NULL;

Symbol* SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_ERROR_EXPANDER = NULL;

Symbol* SYM_LOGIC_MACROS_WARN = NULL;

Symbol* SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_WARNING = NULL;

Symbol* SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_WARNING_EXPANDER = NULL;

Symbol* SYM_LOGIC_MACROS_SETQ = NULL;

Symbol* SYM_LOGIC_MACROS_LASTMOVE = NULL;

Keyword* KWD_LOGIC_MACROS_DOWN = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_IN_PLACE = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_IN_PLACE_EXPANDER = NULL;

Symbol* SYM_LOGIC_MACROS_LET = NULL;

Symbol* SYM_LOGIC_MACROS_BACKFRAME = NULL;

Symbol* SYM_LOGIC_MACROS_FRAME = NULL;

Symbol* SYM_LOGIC_MACROS_UPFRAME = NULL;

Symbol* SYM_LOGIC_MACROS_UP = NULL;

Symbol* SYM_LOGIC_MACROS_CREATE_DOWN_FRAME = NULL;

Symbol* SYM_LOGIC_MACROS_PROPOSITION = NULL;

Symbol* SYM_LOGIC_MACROS_SETF = NULL;

Symbol* SYM_LOGIC_MACROS_BACK = NULL;

Symbol* SYM_LOGIC_MACROS_STATE = NULL;

Keyword* KWD_LOGIC_MACROS_AND = NULL;

Symbol* SYM_LOGIC_MACROS_ARGUMENT_CURSOR = NULL;

Symbol* SYM_LOGIC_MACROS_1i = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_FORWARD = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_FORWARD_EXPANDER = NULL;

Symbol* SYM_LOGIC_MACROS_FORWARDFRAME = NULL;

Symbol* SYM_LOGIC_MACROS_NULL = NULL;

Symbol* SYM_LOGIC_MACROS_DOWN = NULL;

Symbol* SYM_LOGIC_MACROS_POP_CONTROL_FRAME = NULL;

Symbol* SYM_LOGIC_MACROS_QUERYENVIRONMENT = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_BACKWARD = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_BACKWARD_EXPANDER = NULL;

Symbol* SYM_LOGIC_MACROS_PROGN = NULL;

Symbol* SYM_LOGIC_MACROS_DEPTH = NULL;

Symbol* SYM_LOGIC_MACROS_COND = NULL;

Symbol* SYM_LOGIC_MACROS_g = NULL;

Symbol* SYM_LOGIC_MACROS_CURRENT_DEPTH_CUTOFF = NULL;

Symbol* SYM_LOGIC_MACROS_WHEN = NULL;

Symbol* SYM_LOGIC_MACROS_DEFINEDp = NULL;

Symbol* SYM_LOGIC_MACROS_POP_FRAMES_DOWN_TO = NULL;

Symbol* SYM_LOGIC_MACROS_1_ = NULL;

Symbol* SYM_LOGIC_MACROS_MV_SETQ = NULL;

Symbol* SYM_LOGIC_MACROS_HANDLE_DEPTH_VIOLATION = NULL;

Keyword* KWD_LOGIC_MACROS_UP_FAIL = NULL;

Symbol* SYM_LOGIC_MACROS_OTHERWISE = NULL;

Symbol* SYM_LOGIC_MACROS_NTH = NULL;

Symbol* SYM_LOGIC_MACROS_ARGUMENTS = NULL;

Symbol* SYM_LOGIC_MACROS_DEBUG_DEPTH = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_DOWN = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_DOWN_EXPANDER = NULL;

Symbol* SYM_LOGIC_MACROS_IF = NULL;

Symbol* SYM_LOGIC_MACROS_ge = NULL;

Symbol* SYM_LOGIC_MACROS_DEFINING_PROPOSITION = NULL;

Symbol* SYM_LOGIC_MACROS_CAST = NULL;

Symbol* SYM_LOGIC_MACROS_PATTERN_VARIABLE = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_DOWN_TO_FUNCTION = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_DOWN_TO_FUNCTION_EXPANDER = NULL;

Symbol* SYM_LOGIC_MACROS_FAIL = NULL;

Keyword* KWD_LOGIC_MACROS_UP_TRUE = NULL;

Symbol* SYM_LOGIC_MACROS_UPDATE_GOAL_CACHE = NULL;

Symbol* SYM_LOGIC_MACROS_FALSE = NULL;

Symbol* SYM_LOGIC_MACROS_KEEP_FRAME = NULL;

Symbol* SYM_LOGIC_MACROS_SAFETY = NULL;

Symbol* SYM_LOGIC_MACROS_NULLp = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_UP = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_UP_EXPANDER = NULL;

Symbol* SYM_LOGIC_MACROS_RETURN = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_UP_OR_EXIT = NULL;

Symbol* SYM_LOGIC_MACROS_MOVE_UP_OR_EXIT_EXPANDER = NULL;

Logic_Exception* new_logic_exception() {
  { Logic_Exception* self = NULL;

    self = new Logic_Exception;
    return (self);
  }
}

Surrogate* Logic_Exception::primary_type() {
  { Logic_Exception* self = this;

    return (SGT_LOGIC_MACROS_LOGIC_EXCEPTION);
  }
}

Proposition_Error* new_proposition_error() {
  { Proposition_Error* self = NULL;

    self = new Proposition_Error;
    return (self);
  }
}

Surrogate* Proposition_Error::primary_type() {
  { Proposition_Error* self = this;

    return (SGT_LOGIC_MACROS_PROPOSITION_ERROR);
  }
}

Parsing_Error* new_parsing_error() {
  { Parsing_Error* self = NULL;

    self = new Parsing_Error;
    return (self);
  }
}

Surrogate* Parsing_Error::primary_type() {
  { Parsing_Error* self = this;

    return (SGT_LOGIC_MACROS_PARSING_ERROR);
  }
}

Clash* new_clash() {
  { Clash* self = NULL;

    self = new Clash;
    return (self);
  }
}

Surrogate* Clash::primary_type() {
  { Clash* self = this;

    return (SGT_LOGIC_MACROS_CLASH);
  }
}

Fail* new_fail() {
  { Fail* self = NULL;

    self = new Fail;
    return (self);
  }
}

Surrogate* Fail::primary_type() {
  { Fail* self = this;

    return (SGT_LOGIC_MACROS_FAIL);
  }
}

Query_Thread_Limit_Violation* new_query_thread_limit_violation() {
  { Query_Thread_Limit_Violation* self = NULL;

    self = new Query_Thread_Limit_Violation;
    return (self);
  }
}

Surrogate* Query_Thread_Limit_Violation::primary_type() {
  { Query_Thread_Limit_Violation* self = this;

    return (SGT_LOGIC_MACROS_QUERY_THREAD_LIMIT_VIOLATION);
  }
}

Object* signal_parsing_error_expander(Cons* body) {
  return (listO(5, SYM_LOGIC_MACROS_SPECIAL, cons(listO(3, SYM_LOGIC_MACROS_oPRINTREADABLYpo, SYM_LOGIC_MACROS_TRUE, NIL), NIL), listO(3, SYM_LOGIC_MACROS_INFORM, string_wrap_literal("PARSING ERROR: "), body->concatenate(listO(3, string_wrap_literal("."), SYM_LOGIC_MACROS_EOL, NIL))), listO(3, SYM_LOGIC_MACROS_SIGNAL, SYM_LOGIC_MACROS_oTHE_PARSING_ERRORo, NIL), NIL));
}

Object* signal_proposition_error_expander(Cons* message) {
  return (listO(8, SYM_LOGIC_MACROS_SPECIAL, cons(listO(3, SYM_LOGIC_MACROS_oPRINTREADABLYpo, SYM_LOGIC_MACROS_TRUE, NIL), NIL), listO(4, SYM_LOGIC_MACROS_PRINT, string_wrap_literal("Error in logical expression."), SYM_LOGIC_MACROS_EOL, NIL), listO(3, SYM_LOGIC_MACROS_PRINT, string_wrap_literal("   "), message->concatenate(cons(SYM_LOGIC_MACROS_EOL, NIL))), listO(4, SYM_LOGIC_MACROS_PRINT, string_wrap_literal("   Error occured while parsing the proposition: "), SYM_LOGIC_MACROS_EOL, NIL), listO(5, SYM_LOGIC_MACROS_PRINT, string_wrap_literal("   "), SYM_LOGIC_MACROS_oPROPOSITIONUNDERCONSTRUCTIONo, SYM_LOGIC_MACROS_EOL, NIL), listO(3, SYM_LOGIC_MACROS_SIGNAL, SYM_LOGIC_MACROS_oTHE_PROPOSITION_ERRORo, NIL), NIL));
}

Object* signal_proposition_warning_expander(Cons* message) {
  return (listO(4, SYM_LOGIC_MACROS_SPECIAL, cons(listO(3, SYM_LOGIC_MACROS_oPRINTREADABLYpo, SYM_LOGIC_MACROS_TRUE, NIL), NIL), cons(SYM_LOGIC_MACROS_WARN, message->concatenate(NIL)), NIL));
}

Object* move_in_place_expander() {
  return (listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_LASTMOVE, KWD_LOGIC_MACROS_DOWN, NIL));
}

Object* move_forward_expander() {
  return (listO(7, SYM_LOGIC_MACROS_LET, listO(3, listO(3, SYM_LOGIC_MACROS_BACKFRAME, SYM_LOGIC_MACROS_FRAME, NIL), listO(3, SYM_LOGIC_MACROS_UPFRAME, listO(3, SYM_LOGIC_MACROS_UP, SYM_LOGIC_MACROS_BACKFRAME, NIL), NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_FRAME, listO(4, SYM_LOGIC_MACROS_CREATE_DOWN_FRAME, SYM_LOGIC_MACROS_UPFRAME, listO(3, SYM_LOGIC_MACROS_PROPOSITION, SYM_LOGIC_MACROS_BACKFRAME, NIL), NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETF, listO(3, SYM_LOGIC_MACROS_BACK, SYM_LOGIC_MACROS_FRAME, NIL), SYM_LOGIC_MACROS_BACKFRAME, NIL), listO(4, SYM_LOGIC_MACROS_SETF, listO(3, SYM_LOGIC_MACROS_STATE, SYM_LOGIC_MACROS_FRAME, NIL), KWD_LOGIC_MACROS_AND, NIL), listO(4, SYM_LOGIC_MACROS_SETF, listO(3, SYM_LOGIC_MACROS_ARGUMENT_CURSOR, SYM_LOGIC_MACROS_FRAME, NIL), listO(3, SYM_LOGIC_MACROS_1i, listO(3, SYM_LOGIC_MACROS_ARGUMENT_CURSOR, SYM_LOGIC_MACROS_BACKFRAME, NIL), NIL), NIL), NIL));
}

Object* move_backward_expander() {
  return (listO(8, SYM_LOGIC_MACROS_LET, cons(listO(3, SYM_LOGIC_MACROS_FORWARDFRAME, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_FRAME, listO(3, SYM_LOGIC_MACROS_BACK, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_PROPOSITION, listO(3, SYM_LOGIC_MACROS_PROPOSITION, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETF, listO(3, SYM_LOGIC_MACROS_BACK, SYM_LOGIC_MACROS_FORWARDFRAME, NIL), SYM_LOGIC_MACROS_NULL, NIL), listO(4, SYM_LOGIC_MACROS_SETF, listO(3, SYM_LOGIC_MACROS_DOWN, listO(3, SYM_LOGIC_MACROS_UP, SYM_LOGIC_MACROS_FORWARDFRAME, NIL), NIL), SYM_LOGIC_MACROS_FRAME, NIL), listO(3, SYM_LOGIC_MACROS_POP_CONTROL_FRAME, SYM_LOGIC_MACROS_QUERYENVIRONMENT, NIL), NIL));
}

Object* move_down_expander() {
  return (listO(4, SYM_LOGIC_MACROS_PROGN, listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_DEPTH, listO(3, SYM_LOGIC_MACROS_1i, SYM_LOGIC_MACROS_DEPTH, NIL), NIL), listO(5, SYM_LOGIC_MACROS_COND, listO(7, listO(4, SYM_LOGIC_MACROS_g, SYM_LOGIC_MACROS_DEPTH, listO(3, SYM_LOGIC_MACROS_CURRENT_DEPTH_CUTOFF, SYM_LOGIC_MACROS_QUERYENVIRONMENT, NIL), NIL), listO(4, SYM_LOGIC_MACROS_WHEN, listO(3, SYM_LOGIC_MACROS_DEFINEDp, listO(3, SYM_LOGIC_MACROS_DOWN, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(3, SYM_LOGIC_MACROS_POP_FRAMES_DOWN_TO, listO(3, SYM_LOGIC_MACROS_DOWN, SYM_LOGIC_MACROS_FRAME, NIL), NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_DEPTH, listO(3, SYM_LOGIC_MACROS_1_, SYM_LOGIC_MACROS_DEPTH, NIL), NIL), listO(4, SYM_LOGIC_MACROS_MV_SETQ, listO(3, SYM_LOGIC_MACROS_FRAME, SYM_LOGIC_MACROS_DEPTH, NIL), listO(4, SYM_LOGIC_MACROS_HANDLE_DEPTH_VIOLATION, SYM_LOGIC_MACROS_FRAME, SYM_LOGIC_MACROS_DEPTH, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_PROPOSITION, listO(3, SYM_LOGIC_MACROS_PROPOSITION, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_LASTMOVE, KWD_LOGIC_MACROS_UP_FAIL, NIL), NIL), listO(5, listO(3, SYM_LOGIC_MACROS_DEFINEDp, listO(3, SYM_LOGIC_MACROS_DOWN, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_FRAME, listO(3, SYM_LOGIC_MACROS_DOWN, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_PROPOSITION, listO(3, SYM_LOGIC_MACROS_PROPOSITION, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_LASTMOVE, KWD_LOGIC_MACROS_DOWN, NIL), NIL), listO(3, SYM_LOGIC_MACROS_OTHERWISE, listO(7, SYM_LOGIC_MACROS_LET, cons(listO(3, SYM_LOGIC_MACROS_UPFRAME, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_PROPOSITION, listO(4, SYM_LOGIC_MACROS_NTH, listO(3, SYM_LOGIC_MACROS_ARGUMENTS, SYM_LOGIC_MACROS_PROPOSITION, NIL), listO(3, SYM_LOGIC_MACROS_ARGUMENT_CURSOR, SYM_LOGIC_MACROS_UPFRAME, NIL), NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_FRAME, listO(4, SYM_LOGIC_MACROS_CREATE_DOWN_FRAME, SYM_LOGIC_MACROS_UPFRAME, SYM_LOGIC_MACROS_PROPOSITION, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETF, listO(3, SYM_LOGIC_MACROS_DEBUG_DEPTH, SYM_LOGIC_MACROS_FRAME, NIL), SYM_LOGIC_MACROS_DEPTH, NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_LASTMOVE, KWD_LOGIC_MACROS_DOWN, NIL), NIL), NIL), NIL), NIL));
}

Object* move_down_to_function_expander() {
  return (listO(4, SYM_LOGIC_MACROS_PROGN, listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_DEPTH, listO(3, SYM_LOGIC_MACROS_1i, SYM_LOGIC_MACROS_DEPTH, NIL), NIL), listO(5, SYM_LOGIC_MACROS_IF, listO(4, SYM_LOGIC_MACROS_ge, SYM_LOGIC_MACROS_DEPTH, listO(3, SYM_LOGIC_MACROS_CURRENT_DEPTH_CUTOFF, SYM_LOGIC_MACROS_QUERYENVIRONMENT, NIL), NIL), listO(6, SYM_LOGIC_MACROS_PROGN, listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_DEPTH, listO(3, SYM_LOGIC_MACROS_1_, SYM_LOGIC_MACROS_DEPTH, NIL), NIL), listO(4, SYM_LOGIC_MACROS_MV_SETQ, listO(3, SYM_LOGIC_MACROS_FRAME, SYM_LOGIC_MACROS_DEPTH, NIL), listO(4, SYM_LOGIC_MACROS_HANDLE_DEPTH_VIOLATION, SYM_LOGIC_MACROS_FRAME, SYM_LOGIC_MACROS_DEPTH, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_PROPOSITION, listO(3, SYM_LOGIC_MACROS_PROPOSITION, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_LASTMOVE, KWD_LOGIC_MACROS_UP_FAIL, NIL), NIL), listO(6, SYM_LOGIC_MACROS_LET, cons(listO(3, SYM_LOGIC_MACROS_UPFRAME, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_FRAME, listO(4, SYM_LOGIC_MACROS_CREATE_DOWN_FRAME, SYM_LOGIC_MACROS_UPFRAME, listO(3, SYM_LOGIC_MACROS_DEFINING_PROPOSITION, listO(4, SYM_LOGIC_MACROS_CAST, listO(4, SYM_LOGIC_MACROS_NTH, listO(3, SYM_LOGIC_MACROS_ARGUMENTS, SYM_LOGIC_MACROS_PROPOSITION, NIL), listO(3, SYM_LOGIC_MACROS_ARGUMENT_CURSOR, SYM_LOGIC_MACROS_UPFRAME, NIL), NIL), SYM_LOGIC_MACROS_PATTERN_VARIABLE, NIL), NIL), NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETF, listO(3, SYM_LOGIC_MACROS_DEBUG_DEPTH, SYM_LOGIC_MACROS_FRAME, NIL), SYM_LOGIC_MACROS_DEPTH, NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_LASTMOVE, KWD_LOGIC_MACROS_DOWN, NIL), NIL), NIL), NIL));
}

Object* move_up_expander(Symbol* successP, Symbol* keepframeP) {
  { Keyword* lastmove = NULL;

    if (successP == SYM_LOGIC_MACROS_TRUE) {
      lastmove = KWD_LOGIC_MACROS_UP_TRUE;
    }
    else if (successP == SYM_LOGIC_MACROS_FAIL) {
      lastmove = KWD_LOGIC_MACROS_UP_FAIL;
    }
    else {
      cerr << "`" << successP << "'" << " is not a valid case option";
    }
    return (listO(6, SYM_LOGIC_MACROS_PROGN, listO(4, SYM_LOGIC_MACROS_UPDATE_GOAL_CACHE, SYM_LOGIC_MACROS_FRAME, ((successP == SYM_LOGIC_MACROS_TRUE) ? ((Symbol*)(SYM_LOGIC_MACROS_TRUE)) : ((Symbol*)(SYM_LOGIC_MACROS_FALSE))), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_DEPTH, listO(3, SYM_LOGIC_MACROS_1_, SYM_LOGIC_MACROS_DEPTH, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_FRAME, listO(3, SYM_LOGIC_MACROS_UP, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_PROPOSITION, listO(3, SYM_LOGIC_MACROS_PROPOSITION, SYM_LOGIC_MACROS_FRAME, NIL), NIL), ((keepframeP == SYM_LOGIC_MACROS_KEEP_FRAME) ? ((Cons*)(NIL)) : ((Cons*)(listO(4, listO(3, SYM_LOGIC_MACROS_POP_CONTROL_FRAME, SYM_LOGIC_MACROS_QUERYENVIRONMENT, NIL), listO(6, SYM_LOGIC_MACROS_SAFETY, integer_wrap_literal(3), listO(3, SYM_LOGIC_MACROS_NULLp, listO(3, SYM_LOGIC_MACROS_DOWN, listO(3, SYM_LOGIC_MACROS_DOWN, SYM_LOGIC_MACROS_FRAME, NIL), NIL), NIL), string_wrap_literal("INTERNAL ERROR: Forgot to pop frame "), string_wrap_literal("below top frame."), NIL), listO(4, SYM_LOGIC_MACROS_SETF, listO(3, SYM_LOGIC_MACROS_DOWN, SYM_LOGIC_MACROS_FRAME, NIL), SYM_LOGIC_MACROS_NULL, NIL), NIL))))->concatenate(cons(listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_LASTMOVE, lastmove, NIL), NIL))));
  }
}

Object* move_up_or_exit_expander(Symbol* successP, Symbol* keepframeP) {
  { Keyword* lastmove = NULL;

    if (successP == SYM_LOGIC_MACROS_TRUE) {
      lastmove = KWD_LOGIC_MACROS_UP_TRUE;
    }
    else if (successP == SYM_LOGIC_MACROS_FAIL) {
      lastmove = KWD_LOGIC_MACROS_UP_FAIL;
      successP = SYM_LOGIC_MACROS_FALSE;
    }
    else {
      cerr << "`" << successP << "'" << " is not a valid case option";
    }
    return (listO(6, SYM_LOGIC_MACROS_PROGN, listO(4, SYM_LOGIC_MACROS_WHEN, listO(3, SYM_LOGIC_MACROS_DEFINEDp, listO(3, SYM_LOGIC_MACROS_UP, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_UPDATE_GOAL_CACHE, SYM_LOGIC_MACROS_FRAME, ((successP == SYM_LOGIC_MACROS_TRUE) ? ((Symbol*)(SYM_LOGIC_MACROS_TRUE)) : ((Symbol*)(SYM_LOGIC_MACROS_FALSE))), NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_DEPTH, listO(3, SYM_LOGIC_MACROS_1_, SYM_LOGIC_MACROS_DEPTH, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_FRAME, listO(3, SYM_LOGIC_MACROS_UP, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_WHEN, listO(3, SYM_LOGIC_MACROS_NULLp, SYM_LOGIC_MACROS_FRAME, NIL), listO(3, SYM_LOGIC_MACROS_RETURN, successP, NIL), NIL), ((keepframeP == SYM_LOGIC_MACROS_KEEP_FRAME) ? ((Cons*)(NIL)) : ((Cons*)(listO(3, listO(3, SYM_LOGIC_MACROS_POP_CONTROL_FRAME, SYM_LOGIC_MACROS_QUERYENVIRONMENT, NIL), listO(5, SYM_LOGIC_MACROS_WHEN, listO(3, SYM_LOGIC_MACROS_DEFINEDp, SYM_LOGIC_MACROS_FRAME, NIL), listO(6, SYM_LOGIC_MACROS_SAFETY, integer_wrap_literal(3), listO(3, SYM_LOGIC_MACROS_NULLp, listO(3, SYM_LOGIC_MACROS_DOWN, listO(3, SYM_LOGIC_MACROS_DOWN, SYM_LOGIC_MACROS_FRAME, NIL), NIL), NIL), string_wrap_literal("INTERNAL ERROR: Forgot to pop frame "), string_wrap_literal("below top frame."), NIL), listO(4, SYM_LOGIC_MACROS_SETF, listO(3, SYM_LOGIC_MACROS_DOWN, SYM_LOGIC_MACROS_FRAME, NIL), SYM_LOGIC_MACROS_NULL, NIL), NIL), NIL))))->concatenate(listO(4, listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_PROPOSITION, listO(3, SYM_LOGIC_MACROS_PROPOSITION, SYM_LOGIC_MACROS_FRAME, NIL), NIL), listO(4, SYM_LOGIC_MACROS_SETQ, SYM_LOGIC_MACROS_LASTMOVE, lastmove, NIL), SYM_LOGIC_MACROS_LASTMOVE, NIL))));
  }
}

void startup_logic_macros() {
  if (current_startup_time_phaseP(1)) {
    define_module_from_stringified_source("/LOGIC", "(:CLEARABLE? FALSE :PACKAGE \"STELLA\")");
  }
  { Module* old_OmoduleO_001 = oMODULEo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = string_get_module("/LOGIC", TRUE);
          oCONTEXTo = oMODULEo;
          if (current_startup_time_phaseP(2)) {
            SGT_LOGIC_MACROS_LOGIC_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-EXCEPTION", NULL, 1)));
            SGT_LOGIC_MACROS_PROPOSITION_ERROR = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPOSITION-ERROR", NULL, 1)));
            SGT_LOGIC_MACROS_PARSING_ERROR = ((Surrogate*)(intern_rigid_symbol_wrt_module("PARSING-ERROR", NULL, 1)));
            SGT_LOGIC_MACROS_CLASH = ((Surrogate*)(intern_rigid_symbol_wrt_module("CLASH", NULL, 1)));
            SGT_LOGIC_MACROS_FAIL = ((Surrogate*)(intern_rigid_symbol_wrt_module("FAIL", NULL, 1)));
            SGT_LOGIC_MACROS_QUERY_THREAD_LIMIT_VIOLATION = ((Surrogate*)(intern_rigid_symbol_wrt_module("QUERY-THREAD-LIMIT-VIOLATION", NULL, 1)));
            SYM_LOGIC_MACROS_SPECIAL = ((Symbol*)(intern_rigid_symbol_wrt_module("SPECIAL", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_oPRINTREADABLYpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PRINTREADABLY?*", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_INFORM = ((Symbol*)(intern_rigid_symbol_wrt_module("INFORM", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_EOL = ((Symbol*)(intern_rigid_symbol_wrt_module("EOL", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_SIGNAL = ((Symbol*)(intern_rigid_symbol_wrt_module("SIGNAL", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_oTHE_PARSING_ERRORo = ((Symbol*)(intern_rigid_symbol_wrt_module("*THE-PARSING-ERROR*", NULL, 0)));
            SYM_LOGIC_MACROS_SIGNAL_PARSING_ERROR = ((Symbol*)(intern_rigid_symbol_wrt_module("SIGNAL-PARSING-ERROR", NULL, 0)));
            SYM_LOGIC_MACROS_SIGNAL_PARSING_ERROR_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("SIGNAL-PARSING-ERROR-EXPANDER", NULL, 0)));
            SYM_LOGIC_MACROS_PRINT = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_oPROPOSITIONUNDERCONSTRUCTIONo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PROPOSITIONUNDERCONSTRUCTION*", NULL, 0)));
            SYM_LOGIC_MACROS_oTHE_PROPOSITION_ERRORo = ((Symbol*)(intern_rigid_symbol_wrt_module("*THE-PROPOSITION-ERROR*", NULL, 0)));
            SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_ERROR = ((Symbol*)(intern_rigid_symbol_wrt_module("SIGNAL-PROPOSITION-ERROR", NULL, 0)));
            SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_ERROR_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("SIGNAL-PROPOSITION-ERROR-EXPANDER", NULL, 0)));
            SYM_LOGIC_MACROS_WARN = ((Symbol*)(intern_rigid_symbol_wrt_module("WARN", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_WARNING = ((Symbol*)(intern_rigid_symbol_wrt_module("SIGNAL-PROPOSITION-WARNING", NULL, 0)));
            SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_WARNING_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("SIGNAL-PROPOSITION-WARNING-EXPANDER", NULL, 0)));
            SYM_LOGIC_MACROS_SETQ = ((Symbol*)(intern_rigid_symbol_wrt_module("SETQ", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_LASTMOVE = ((Symbol*)(intern_rigid_symbol_wrt_module("LASTMOVE", NULL, 0)));
            KWD_LOGIC_MACROS_DOWN = ((Keyword*)(intern_rigid_symbol_wrt_module("DOWN", NULL, 2)));
            SYM_LOGIC_MACROS_MOVE_IN_PLACE = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-IN-PLACE", NULL, 0)));
            SYM_LOGIC_MACROS_MOVE_IN_PLACE_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-IN-PLACE-EXPANDER", NULL, 0)));
            SYM_LOGIC_MACROS_LET = ((Symbol*)(intern_rigid_symbol_wrt_module("LET", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_BACKFRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("BACKFRAME", NULL, 0)));
            SYM_LOGIC_MACROS_FRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("FRAME", NULL, 0)));
            SYM_LOGIC_MACROS_UPFRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("UPFRAME", NULL, 0)));
            SYM_LOGIC_MACROS_UP = ((Symbol*)(intern_rigid_symbol_wrt_module("UP", NULL, 0)));
            SYM_LOGIC_MACROS_CREATE_DOWN_FRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("CREATE-DOWN-FRAME", NULL, 0)));
            SYM_LOGIC_MACROS_PROPOSITION = ((Symbol*)(intern_rigid_symbol_wrt_module("PROPOSITION", NULL, 0)));
            SYM_LOGIC_MACROS_SETF = ((Symbol*)(intern_rigid_symbol_wrt_module("SETF", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_BACK = ((Symbol*)(intern_rigid_symbol_wrt_module("BACK", NULL, 0)));
            SYM_LOGIC_MACROS_STATE = ((Symbol*)(intern_rigid_symbol_wrt_module("STATE", string_get_module("/STELLA", TRUE), 0)));
            KWD_LOGIC_MACROS_AND = ((Keyword*)(intern_rigid_symbol_wrt_module("AND", NULL, 2)));
            SYM_LOGIC_MACROS_ARGUMENT_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("ARGUMENT-CURSOR", NULL, 0)));
            SYM_LOGIC_MACROS_1i = ((Symbol*)(intern_rigid_symbol_wrt_module("1+", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_MOVE_FORWARD = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-FORWARD", NULL, 0)));
            SYM_LOGIC_MACROS_MOVE_FORWARD_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-FORWARD-EXPANDER", NULL, 0)));
            SYM_LOGIC_MACROS_FORWARDFRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("FORWARDFRAME", NULL, 0)));
            SYM_LOGIC_MACROS_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_DOWN = ((Symbol*)(intern_rigid_symbol_wrt_module("DOWN", NULL, 0)));
            SYM_LOGIC_MACROS_POP_CONTROL_FRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("POP-CONTROL-FRAME", NULL, 0)));
            SYM_LOGIC_MACROS_QUERYENVIRONMENT = ((Symbol*)(intern_rigid_symbol_wrt_module("QUERYENVIRONMENT", NULL, 0)));
            SYM_LOGIC_MACROS_MOVE_BACKWARD = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-BACKWARD", NULL, 0)));
            SYM_LOGIC_MACROS_MOVE_BACKWARD_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-BACKWARD-EXPANDER", NULL, 0)));
            SYM_LOGIC_MACROS_PROGN = ((Symbol*)(intern_rigid_symbol_wrt_module("PROGN", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_DEPTH = ((Symbol*)(intern_rigid_symbol_wrt_module("DEPTH", NULL, 0)));
            SYM_LOGIC_MACROS_COND = ((Symbol*)(intern_rigid_symbol_wrt_module("COND", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_g = ((Symbol*)(intern_rigid_symbol_wrt_module(">", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_CURRENT_DEPTH_CUTOFF = ((Symbol*)(intern_rigid_symbol_wrt_module("CURRENT-DEPTH-CUTOFF", NULL, 0)));
            SYM_LOGIC_MACROS_WHEN = ((Symbol*)(intern_rigid_symbol_wrt_module("WHEN", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_DEFINEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINED?", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_POP_FRAMES_DOWN_TO = ((Symbol*)(intern_rigid_symbol_wrt_module("POP-FRAMES-DOWN-TO", NULL, 0)));
            SYM_LOGIC_MACROS_1_ = ((Symbol*)(intern_rigid_symbol_wrt_module("1-", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_MV_SETQ = ((Symbol*)(intern_rigid_symbol_wrt_module("MV-SETQ", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_HANDLE_DEPTH_VIOLATION = ((Symbol*)(intern_rigid_symbol_wrt_module("HANDLE-DEPTH-VIOLATION", NULL, 0)));
            KWD_LOGIC_MACROS_UP_FAIL = ((Keyword*)(intern_rigid_symbol_wrt_module("UP-FAIL", NULL, 2)));
            SYM_LOGIC_MACROS_OTHERWISE = ((Symbol*)(intern_rigid_symbol_wrt_module("OTHERWISE", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_NTH = ((Symbol*)(intern_rigid_symbol_wrt_module("NTH", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_ARGUMENTS = ((Symbol*)(intern_rigid_symbol_wrt_module("ARGUMENTS", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_DEBUG_DEPTH = ((Symbol*)(intern_rigid_symbol_wrt_module("DEBUG-DEPTH", NULL, 0)));
            SYM_LOGIC_MACROS_MOVE_DOWN = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-DOWN", NULL, 0)));
            SYM_LOGIC_MACROS_MOVE_DOWN_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-DOWN-EXPANDER", NULL, 0)));
            SYM_LOGIC_MACROS_IF = ((Symbol*)(intern_rigid_symbol_wrt_module("IF", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_ge = ((Symbol*)(intern_rigid_symbol_wrt_module(">=", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_DEFINING_PROPOSITION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINING-PROPOSITION", NULL, 0)));
            SYM_LOGIC_MACROS_CAST = ((Symbol*)(intern_rigid_symbol_wrt_module("CAST", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_PATTERN_VARIABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("PATTERN-VARIABLE", NULL, 0)));
            SYM_LOGIC_MACROS_MOVE_DOWN_TO_FUNCTION = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-DOWN-TO-FUNCTION", NULL, 0)));
            SYM_LOGIC_MACROS_MOVE_DOWN_TO_FUNCTION_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-DOWN-TO-FUNCTION-EXPANDER", NULL, 0)));
            SYM_LOGIC_MACROS_FAIL = ((Symbol*)(intern_rigid_symbol_wrt_module("FAIL", NULL, 0)));
            KWD_LOGIC_MACROS_UP_TRUE = ((Keyword*)(intern_rigid_symbol_wrt_module("UP-TRUE", NULL, 2)));
            SYM_LOGIC_MACROS_UPDATE_GOAL_CACHE = ((Symbol*)(intern_rigid_symbol_wrt_module("UPDATE-GOAL-CACHE", NULL, 0)));
            SYM_LOGIC_MACROS_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_KEEP_FRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("KEEP-FRAME", NULL, 0)));
            SYM_LOGIC_MACROS_SAFETY = ((Symbol*)(intern_rigid_symbol_wrt_module("SAFETY", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_NULLp = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL?", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_MOVE_UP = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-UP", NULL, 0)));
            SYM_LOGIC_MACROS_MOVE_UP_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-UP-EXPANDER", NULL, 0)));
            SYM_LOGIC_MACROS_RETURN = ((Symbol*)(intern_rigid_symbol_wrt_module("RETURN", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_MACROS_MOVE_UP_OR_EXIT = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-UP-OR-EXIT", NULL, 0)));
            SYM_LOGIC_MACROS_MOVE_UP_OR_EXIT_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("MOVE-UP-OR-EXIT-EXPANDER", NULL, 0)));
          }
          if (current_startup_time_phaseP(4)) {
            oTHE_PROPOSITION_ERRORo = new_proposition_error();
            oTHE_PARSING_ERRORo = new_parsing_error();
            oTHE_CLASH_EXCEPTIONo = new_clash();
            oTHE_FAIL_EXCEPTIONo = new_fail();
            oTHE_QUERY_THREAD_LIMIT_VIOLATIONo = new_query_thread_limit_violation();
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("LOGIC-EXCEPTION", "(DEFCLASS LOGIC-EXCEPTION (EXCEPTION))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_logic_exception));
            }
            { Class* renamed_Class = define_class_from_stringified_source("PROPOSITION-ERROR", "(DEFCLASS PROPOSITION-ERROR (LOGIC-EXCEPTION))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_proposition_error));
            }
            { Class* renamed_Class = define_class_from_stringified_source("PARSING-ERROR", "(DEFCLASS PARSING-ERROR (LOGIC-EXCEPTION))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_parsing_error));
            }
            { Class* renamed_Class = define_class_from_stringified_source("CLASH", "(DEFCLASS CLASH (LOGIC-EXCEPTION))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_clash));
            }
            { Class* renamed_Class = define_class_from_stringified_source("FAIL", "(DEFCLASS FAIL (LOGIC-EXCEPTION))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_fail));
            }
            { Class* renamed_Class = define_class_from_stringified_source("QUERY-THREAD-LIMIT-VIOLATION", "(DEFCLASS QUERY-THREAD-LIMIT-VIOLATION (LOGIC-EXCEPTION))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_query_thread_limit_violation));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-PARSING-ERROR-EXPANDER", "CONS", "(DEFUN (SIGNAL-PARSING-ERROR-EXPANDER OBJECT) (|&BODY| (BODY CONS)))");

              method->function_code = ((cpp_function_code)(&signal_parsing_error_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-PROPOSITION-ERROR-EXPANDER", "CONS", "(DEFUN (SIGNAL-PROPOSITION-ERROR-EXPANDER OBJECT) (|&BODY| (MESSAGE CONS)))");

              method->function_code = ((cpp_function_code)(&signal_proposition_error_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-PROPOSITION-WARNING-EXPANDER", "CONS", "(DEFUN (SIGNAL-PROPOSITION-WARNING-EXPANDER OBJECT) (|&BODY| (MESSAGE CONS)))");

              method->function_code = ((cpp_function_code)(&signal_proposition_warning_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("MOVE-IN-PLACE-EXPANDER", NULL, "(DEFUN (MOVE-IN-PLACE-EXPANDER OBJECT) ())");

              method->function_code = ((cpp_function_code)(&move_in_place_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("MOVE-FORWARD-EXPANDER", NULL, "(DEFUN (MOVE-FORWARD-EXPANDER OBJECT) ())");

              method->function_code = ((cpp_function_code)(&move_forward_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("MOVE-BACKWARD-EXPANDER", NULL, "(DEFUN (MOVE-BACKWARD-EXPANDER OBJECT) ())");

              method->function_code = ((cpp_function_code)(&move_backward_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("MOVE-DOWN-EXPANDER", NULL, "(DEFUN (MOVE-DOWN-EXPANDER OBJECT) ())");

              method->function_code = ((cpp_function_code)(&move_down_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("MOVE-DOWN-TO-FUNCTION-EXPANDER", NULL, "(DEFUN (MOVE-DOWN-TO-FUNCTION-EXPANDER OBJECT) ())");

              method->function_code = ((cpp_function_code)(&move_down_to_function_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("MOVE-UP-EXPANDER", "SYMBOL", "(DEFUN (MOVE-UP-EXPANDER OBJECT) ((SUCCESS? SYMBOL) (KEEPFRAME? SYMBOL)))");

              method->function_code = ((cpp_function_code)(&move_up_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("MOVE-UP-OR-EXIT-EXPANDER", "SYMBOL", "(DEFUN (MOVE-UP-OR-EXIT-EXPANDER OBJECT) ((SUCCESS? SYMBOL) (KEEPFRAME? SYMBOL)))");

              method->function_code = ((cpp_function_code)(&move_up_or_exit_expander));
            }
            define_method_from_stringified_source("STARTUP-LOGIC-MACROS", NULL, "(DEFUN STARTUP-LOGIC-MACROS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *THE-PROPOSITION-ERROR* PROPOSITION-ERROR (NEW PROPOSITION-ERROR))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *THE-PARSING-ERROR* PARSING-ERROR (NEW PARSING-ERROR))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *THE-CLASH-EXCEPTION* CLASH (NEW CLASH))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *THE-FAIL-EXCEPTION* FAIL (NEW FAIL))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *THE-QUERY-THREAD-LIMIT-VIOLATION* QUERY-THREAD-LIMIT-VIOLATION (NEW QUERY-THREAD-LIMIT-VIOLATION))");
            store_macro(SYM_LOGIC_MACROS_SIGNAL_PARSING_ERROR, SYM_LOGIC_MACROS_SIGNAL_PARSING_ERROR_EXPANDER, ((cpp_function_code)(&signal_parsing_error_expander)));
            store_macro(SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_ERROR, SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_ERROR_EXPANDER, ((cpp_function_code)(&signal_proposition_error_expander)));
            store_macro(SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_WARNING, SYM_LOGIC_MACROS_SIGNAL_PROPOSITION_WARNING_EXPANDER, ((cpp_function_code)(&signal_proposition_warning_expander)));
            store_macro(SYM_LOGIC_MACROS_MOVE_IN_PLACE, SYM_LOGIC_MACROS_MOVE_IN_PLACE_EXPANDER, ((cpp_function_code)(&move_in_place_expander)));
            store_macro(SYM_LOGIC_MACROS_MOVE_FORWARD, SYM_LOGIC_MACROS_MOVE_FORWARD_EXPANDER, ((cpp_function_code)(&move_forward_expander)));
            store_macro(SYM_LOGIC_MACROS_MOVE_BACKWARD, SYM_LOGIC_MACROS_MOVE_BACKWARD_EXPANDER, ((cpp_function_code)(&move_backward_expander)));
            store_macro(SYM_LOGIC_MACROS_MOVE_DOWN, SYM_LOGIC_MACROS_MOVE_DOWN_EXPANDER, ((cpp_function_code)(&move_down_expander)));
            store_macro(SYM_LOGIC_MACROS_MOVE_DOWN_TO_FUNCTION, SYM_LOGIC_MACROS_MOVE_DOWN_TO_FUNCTION_EXPANDER, ((cpp_function_code)(&move_down_to_function_expander)));
            store_macro(SYM_LOGIC_MACROS_MOVE_UP, SYM_LOGIC_MACROS_MOVE_UP_EXPANDER, ((cpp_function_code)(&move_up_expander)));
            store_macro(SYM_LOGIC_MACROS_MOVE_UP_OR_EXIT, SYM_LOGIC_MACROS_MOVE_UP_OR_EXIT_EXPANDER, ((cpp_function_code)(&move_up_or_exit_expander)));
          }
          oCONTEXTo = old_OcontextO_001;
          oMODULEo = old_OmoduleO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oCONTEXTo = old_OcontextO_001;
        oMODULEo = old_OmoduleO_001;
        resignal();
      }
    }
  }
}

