// partial-match.cc

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

Symbol* SYM_PARTIAL_MATCH_KIND = NULL;

double oMINIMUM_SCORE_CUTOFFo = 0.0;

double oMAXIMUM_SCORE_CUTOFFo = 0.0;

double oDEFAULT_MINIMUM_SCOREo = 0.0;

double oDEFAULT_MAXIMUM_SCOREo = 0.0;

Symbol* SYM_PARTIAL_MATCH_ARGUMENT_SCORES = NULL;

Symbol* SYM_PARTIAL_MATCH_ARGUMENT_WEIGHTS = NULL;

Surrogate* SGT_PARTIAL_MATCH_NAIVE_PARTIAL_MATCH = NULL;

Keyword* KWD_PARTIAL_MATCH_AND = NULL;

Symbol* SYM_PARTIAL_MATCH_TOTAL_WEIGHT = NULL;

Symbol* SYM_PARTIAL_MATCH_ACCUMULATED_SCORE = NULL;

Symbol* SYM_PARTIAL_MATCH_ACCUMULATED_WEIGHT = NULL;

Symbol* SYM_PARTIAL_MATCH_MAXIMUM_SCORE = NULL;

Surrogate* SGT_PARTIAL_MATCH_INCREMENTAL_PARTIAL_MATCH = NULL;

Keyword* KWD_PARTIAL_MATCH_OR = NULL;

Keyword* KWD_PARTIAL_MATCH_NOT = NULL;

Object* access_partial_match_frame_slot_value(Partial_Match_Frame* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_PARTIAL_MATCH_KIND) {
    if (setvalueP) {
      self->kind = ((Keyword*)(value));
    }
    else {
      return (self->kind);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

void reset_combinator_settings() {
  // Reset the partial match combinator functions to
  // the system-defined default settings.
  oMINIMUM_SCORE_CUTOFFo = oDEFAULT_MINIMUM_SCOREo;
  oMAXIMUM_SCORE_CUTOFFo = oDEFAULT_MAXIMUM_SCOREo;
}

double proposition_weight(Proposition* proposition) {
  return (1.0);
}

Partial_Match_Frame* Partial_Match_Frame::create_partial_match_frame(Control_Frame* frame, Keyword* kind) {
  { Partial_Match_Frame* self = this;

    {
      frame = frame;
      kind = kind;
    }
    cerr << "Missing concrete method named 'create-partial-match-frame' on the" << endl << "   class " << "`" << self->primary_type() << "'";
    return (NULL);
  }
}

void Partial_Match_Frame::record_partial_match_score(double score, double weight) {
  { Partial_Match_Frame* self = this;

    {
      score = score;
      weight = weight;
    }
  }
}

double Partial_Match_Frame::compute_and_score() {
  { Partial_Match_Frame* self = this;

    return (NULL_FLOAT);
  }
}

double Partial_Match_Frame::compute_or_score() {
  { Partial_Match_Frame* self = this;

    return (NULL_FLOAT);
  }
}

double Partial_Match_Frame::compute_not_score() {
  { Partial_Match_Frame* self = this;

    return (NULL_FLOAT);
  }
}

boolean Partial_Match_Frame::early_partial_match_and_failureP() {
  { Partial_Match_Frame* self = this;

    return (FALSE);
  }
}

boolean Partial_Match_Frame::early_partial_match_or_successP() {
  { Partial_Match_Frame* self = this;

    return (FALSE);
  }
}

double Partial_Match_Frame::clip_positive_score(double score) {
  // If 'score' is below the minimum or
  // above the maximum, make it zero or one.
  { Partial_Match_Frame* self = this;

    if (score < oMINIMUM_SCORE_CUTOFFo) {
      score = 0.0;
    }
    else if (score > oMAXIMUM_SCORE_CUTOFFo) {
      score = 1.0;
    }
    return (score);
  }
}

double Partial_Match_Frame::compute_rule_score(double antecedentscore, Truth_Value* rulescore) {
  // Return a score representing the combination of
  // 'antecedentScore', the score for the match of a rule antecedent, and
  // 'ruleScore', the score assigned to the rule being interpreted.
  { Partial_Match_Frame* self = this;

    return (antecedentscore * rulescore->positive_score);
  }
}

Naive_Partial_Match* new_naive_partial_match() {
  { Naive_Partial_Match* self = NULL;

    self = new Naive_Partial_Match;
    self->kind = NULL;
    self->argument_weights = NULL;
    self->argument_scores = NULL;
    return (self);
  }
}

Object* access_naive_partial_match_slot_value(Naive_Partial_Match* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_PARTIAL_MATCH_ARGUMENT_SCORES) {
    if (setvalueP) {
      self->argument_scores = ((Cons*)(value));
    }
    else {
      return (self->argument_scores);
    }
  }
  else if (slotname == SYM_PARTIAL_MATCH_ARGUMENT_WEIGHTS) {
    if (setvalueP) {
      self->argument_weights = ((Cons*)(value));
    }
    else {
      return (self->argument_weights);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Naive_Partial_Match::primary_type() {
  { Naive_Partial_Match* self = this;

    return (SGT_PARTIAL_MATCH_NAIVE_PARTIAL_MATCH);
  }
}

Partial_Match_Frame* Naive_Partial_Match::create_partial_match_frame(Control_Frame* frame, Keyword* kind) {
  { Naive_Partial_Match* self = this;

    { Naive_Partial_Match* partialmatchframe = new_naive_partial_match();

      frame->partial_match_frame = partialmatchframe;
      partialmatchframe->argument_scores = NIL;
      partialmatchframe->argument_weights = NIL;
      return (partialmatchframe);
    }
  }
}

void Naive_Partial_Match::record_partial_match_score(double score, double weight) {
  { Naive_Partial_Match* self = this;

    { Cons* listofscores = self->argument_scores;

      if (nilP(listofscores)) {
        self->argument_scores = cons(float_wrap_literal(score), NIL);
      }
      else {
        add_cons_to_end_of_cons_list(listofscores, cons(float_wrap_literal(score), NIL));
      }
    }
    if (self->kind == KWD_PARTIAL_MATCH_AND) {
      { Cons* listofweights = self->argument_weights;

        if (nilP(listofweights)) {
          self->argument_weights = cons(float_wrap_literal(weight), NIL);
        }
        else {
          add_cons_to_end_of_cons_list(listofweights, cons(float_wrap_literal(weight), NIL));
        }
      }
    }
  }
}

double Naive_Partial_Match::compute_and_score() {
  { Naive_Partial_Match* self = this;

    { double weightedsum = 0.0;
      double totalweight = 0.0;

      { Float_Wrapper* w = NULL;
        Float_Wrapper* s = NULL;
        Cons* iter_001 = self->argument_scores;
        Cons* iter_002 = self->argument_weights;

        while ((!nilP(iter_001)) &&
            (!nilP(iter_002))) {
          {
            s = ((Float_Wrapper*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          {
            w = ((Float_Wrapper*)(iter_002->value));
            iter_002 = iter_002->rest;
          }
          weightedsum = weightedsum + (s->wrapper_value * w->wrapper_value);
          totalweight = totalweight + w->wrapper_value;
        }
      }
      return (weightedsum / totalweight);
    }
  }
}

double Naive_Partial_Match::compute_or_score() {
  { Naive_Partial_Match* self = this;

    { double maxscore = 0.0;

      { Float_Wrapper* s = NULL;
        Cons* iter_001 = self->argument_scores;

        while (!nilP(iter_001)) {
          {
            s = ((Float_Wrapper*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          if (s->wrapper_value > maxscore) {
            maxscore = s->wrapper_value;
          }
        }
      }
      return (maxscore);
    }
  }
}

double Naive_Partial_Match::compute_not_score() {
  { Naive_Partial_Match* self = this;

    return (1.0 - ((Float_Wrapper*)(self->argument_scores->first()))->wrapper_value);
  }
}

Incremental_Partial_Match* new_incremental_partial_match() {
  { Incremental_Partial_Match* self = NULL;

    self = new Incremental_Partial_Match;
    self->kind = NULL;
    self->maximum_score = NULL_FLOAT;
    self->accumulated_weight = NULL_FLOAT;
    self->accumulated_score = NULL_FLOAT;
    self->total_weight = NULL_FLOAT;
    return (self);
  }
}

Object* access_incremental_partial_match_slot_value(Incremental_Partial_Match* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_PARTIAL_MATCH_TOTAL_WEIGHT) {
    if (setvalueP) {
      self->total_weight = ((Float_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (float_wrap_literal(self->total_weight));
    }
  }
  else if (slotname == SYM_PARTIAL_MATCH_ACCUMULATED_SCORE) {
    if (setvalueP) {
      self->accumulated_score = ((Float_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (float_wrap_literal(self->accumulated_score));
    }
  }
  else if (slotname == SYM_PARTIAL_MATCH_ACCUMULATED_WEIGHT) {
    if (setvalueP) {
      self->accumulated_weight = ((Float_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (float_wrap_literal(self->accumulated_weight));
    }
  }
  else if (slotname == SYM_PARTIAL_MATCH_MAXIMUM_SCORE) {
    if (setvalueP) {
      self->maximum_score = ((Float_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (float_wrap_literal(self->maximum_score));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Incremental_Partial_Match::primary_type() {
  { Incremental_Partial_Match* self = this;

    return (SGT_PARTIAL_MATCH_INCREMENTAL_PARTIAL_MATCH);
  }
}

Partial_Match_Frame* Incremental_Partial_Match::create_partial_match_frame(Control_Frame* frame, Keyword* kind) {
  { Incremental_Partial_Match* self = this;

    { Incremental_Partial_Match* partialmatchframe = new_incremental_partial_match();

      partialmatchframe->maximum_score = 0.0;
      if (kind == KWD_PARTIAL_MATCH_AND) {
        partialmatchframe->accumulated_score = 0.0;
        partialmatchframe->accumulated_weight = 0.0;
        { double totalweight = 0.0;

          { Object* arg = NULL;
            Vector* vector_001 = frame->proposition->arguments;
            int index_001 = 0;
            int length_001 = vector_001->length();

            while (index_001 < length_001) {
              {
                arg = vector_001->nth(index_001);
                index_001 = index_001 + 1;
              }
              totalweight = totalweight + proposition_weight(((Proposition*)(arg)));
            }
          }
          partialmatchframe->total_weight = totalweight;
        }
      }
      else {
      }
      return (partialmatchframe);
    }
  }
}

void Incremental_Partial_Match::record_partial_match_score(double score, double weight) {
  { Incremental_Partial_Match* self = this;

    { Keyword* test_value_001 = self->kind;

      if (test_value_001 == KWD_PARTIAL_MATCH_AND) {
        self->accumulated_score = self->accumulated_score + (score * weight);
        self->accumulated_weight = self->accumulated_weight + weight;
      }
      else if ((test_value_001 == KWD_PARTIAL_MATCH_OR) ||
          (test_value_001 == KWD_PARTIAL_MATCH_NOT)) {
        if (score > self->maximum_score) {
          self->maximum_score = score;
        }
      }
      else {
        cerr << "`" << test_value_001 << "'" << " is not a valid case option";
      }
    }
  }
}

double Incremental_Partial_Match::compute_and_score() {
  { Incremental_Partial_Match* self = this;

    return (self->accumulated_score / self->total_weight);
  }
}

double Incremental_Partial_Match::compute_or_score() {
  { Incremental_Partial_Match* self = this;

    return (self->maximum_score);
  }
}

double Incremental_Partial_Match::compute_not_score() {
  { Incremental_Partial_Match* self = this;

    return (1.0 - (self->accumulated_score / self->total_weight));
  }
}

boolean Incremental_Partial_Match::early_partial_match_and_failureP() {
  { Incremental_Partial_Match* self = this;

    { double maxpossiblescore = (self->accumulated_score + (self->total_weight - self->accumulated_weight)) / self->total_weight;

      if (maxpossiblescore < oMINIMUM_SCORE_CUTOFFo) {
        oQUERYENVIRONMENTo->latest_positive_score = 0.0;
        return (TRUE);
      }
      return (FALSE);
    }
  }
}

boolean Incremental_Partial_Match::early_partial_match_or_successP() {
  { Incremental_Partial_Match* self = this;

    if (self->maximum_score > oMAXIMUM_SCORE_CUTOFFo) {
      oQUERYENVIRONMENTo->latest_positive_score = 1.0;
      return (TRUE);
    }
    return (FALSE);
  }
}

void create_and_link_partial_match_frame(Control_Frame* frame, Keyword* kind) {
  { Partial_Match_Frame* strategy = oQUERYENVIRONMENTo->partial_match_strategy;
    Partial_Match_Frame* partialmatchframe = strategy->create_partial_match_frame(frame, kind);

    partialmatchframe->kind = kind;
    frame->partial_match_frame = partialmatchframe;
  }
}

void record_latest_partial_match_score(Control_Frame* frame) {
  frame->partial_match_frame->record_partial_match_score(oQUERYENVIRONMENTo->latest_positive_score, proposition_weight(frame->proposition));
}

boolean compute_partial_match_and_failureP(Control_Frame* frame) {
  return (frame->partial_match_frame->early_partial_match_and_failureP());
}

boolean compute_partial_match_or_successP(Control_Frame* frame) {
  return (frame->partial_match_frame->early_partial_match_or_successP());
}

boolean compute_partial_match_scoreP(Control_Frame* frame) {
  { Partial_Match_Frame* partialmatchframe = frame->partial_match_frame;
    double score = NULL_FLOAT;

    { Keyword* test_value_001 = partialmatchframe->kind;

      if (test_value_001 == KWD_PARTIAL_MATCH_AND) {
        score = partialmatchframe->compute_and_score();
      }
      else if (test_value_001 == KWD_PARTIAL_MATCH_OR) {
        score = partialmatchframe->compute_or_score();
      }
      else if (test_value_001 == KWD_PARTIAL_MATCH_NOT) {
        score = partialmatchframe->compute_not_score();
      }
      else {
        cerr << "`" << test_value_001 << "'" << " is not a valid case option";
      }
    }
    score = partialmatchframe->clip_positive_score(score);
    oQUERYENVIRONMENTo->latest_positive_score = score;
    return (!(score == 0.0));
  }
}

void startup_partial_match() {
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
            SYM_PARTIAL_MATCH_KIND = ((Symbol*)(intern_rigid_symbol_wrt_module("KIND", NULL, 0)));
            SYM_PARTIAL_MATCH_ARGUMENT_SCORES = ((Symbol*)(intern_rigid_symbol_wrt_module("ARGUMENT-SCORES", NULL, 0)));
            SYM_PARTIAL_MATCH_ARGUMENT_WEIGHTS = ((Symbol*)(intern_rigid_symbol_wrt_module("ARGUMENT-WEIGHTS", NULL, 0)));
            SGT_PARTIAL_MATCH_NAIVE_PARTIAL_MATCH = ((Surrogate*)(intern_rigid_symbol_wrt_module("NAIVE-PARTIAL-MATCH", NULL, 1)));
            KWD_PARTIAL_MATCH_AND = ((Keyword*)(intern_rigid_symbol_wrt_module("AND", NULL, 2)));
            SYM_PARTIAL_MATCH_TOTAL_WEIGHT = ((Symbol*)(intern_rigid_symbol_wrt_module("TOTAL-WEIGHT", NULL, 0)));
            SYM_PARTIAL_MATCH_ACCUMULATED_SCORE = ((Symbol*)(intern_rigid_symbol_wrt_module("ACCUMULATED-SCORE", NULL, 0)));
            SYM_PARTIAL_MATCH_ACCUMULATED_WEIGHT = ((Symbol*)(intern_rigid_symbol_wrt_module("ACCUMULATED-WEIGHT", NULL, 0)));
            SYM_PARTIAL_MATCH_MAXIMUM_SCORE = ((Symbol*)(intern_rigid_symbol_wrt_module("MAXIMUM-SCORE", NULL, 0)));
            SGT_PARTIAL_MATCH_INCREMENTAL_PARTIAL_MATCH = ((Surrogate*)(intern_rigid_symbol_wrt_module("INCREMENTAL-PARTIAL-MATCH", NULL, 1)));
            KWD_PARTIAL_MATCH_OR = ((Keyword*)(intern_rigid_symbol_wrt_module("OR", NULL, 2)));
            KWD_PARTIAL_MATCH_NOT = ((Keyword*)(intern_rigid_symbol_wrt_module("NOT", NULL, 2)));
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("PARTIAL-MATCH-FRAME", "(DEFCLASS PARTIAL-MATCH-FRAME (STANDARD-OBJECT) :DOCUMENTATION \"Abstract class acting as placeholder for system and\nuser-defined partial match implementations.\" :ABSTRACT? TRUE :SLOTS ((KIND :TYPE KEYWORD)))");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_partial_match_frame_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("NAIVE-PARTIAL-MATCH", "(DEFCLASS NAIVE-PARTIAL-MATCH (PARTIAL-MATCH-FRAME) :SLOTS ((ARGUMENT-SCORES :TYPE (CONS OF FLOAT-WRAPPER)) (ARGUMENT-WEIGHTS :TYPE (CONS OF FLOAT-WRAPPER))))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_naive_partial_match));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_naive_partial_match_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("INCREMENTAL-PARTIAL-MATCH", "(DEFCLASS INCREMENTAL-PARTIAL-MATCH (PARTIAL-MATCH-FRAME) :SLOTS ((TOTAL-WEIGHT :TYPE FLOAT) (ACCUMULATED-SCORE :TYPE PARTIAL-MATCH-SCORE) (ACCUMULATED-WEIGHT :TYPE FLOAT) (MAXIMUM-SCORE :TYPE PARTIAL-MATCH-SCORE)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_incremental_partial_match));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_incremental_partial_match_slot_value));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("RESET-COMBINATOR-SETTINGS", NULL, "(DEFUN RESET-COMBINATOR-SETTINGS () :DOCUMENTATION \"Reset the partial match combinator functions to\nthe system-defined default settings.\")");

              method->function_code = ((cpp_function_code)(&reset_combinator_settings));
            }
            { Method_Slot* method = define_method_from_stringified_source("PROPOSITION-WEIGHT", "PROPOSITION", "(DEFUN (PROPOSITION-WEIGHT FLOAT) ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&proposition_weight));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-PARTIAL-MATCH-FRAME", "PARTIAL-MATCH-FRAME", "(DEFMETHOD (CREATE-PARTIAL-MATCH-FRAME PARTIAL-MATCH-FRAME) ((SELF PARTIAL-MATCH-FRAME) (FRAME CONTROL-FRAME) (KIND KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Partial_Match_Frame::create_partial_match_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("RECORD-PARTIAL-MATCH-SCORE", "PARTIAL-MATCH-FRAME", "(DEFMETHOD RECORD-PARTIAL-MATCH-SCORE ((SELF PARTIAL-MATCH-FRAME) (SCORE PARTIAL-MATCH-SCORE) (WEIGHT FLOAT)))");

              method->method_code = ((cpp_method_code)(&Partial_Match_Frame::record_partial_match_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-AND-SCORE", "PARTIAL-MATCH-FRAME", "(DEFMETHOD (COMPUTE-AND-SCORE PARTIAL-MATCH-SCORE) ((SELF PARTIAL-MATCH-FRAME)))");

              method->method_code = ((cpp_method_code)(&Partial_Match_Frame::compute_and_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-OR-SCORE", "PARTIAL-MATCH-FRAME", "(DEFMETHOD (COMPUTE-OR-SCORE PARTIAL-MATCH-SCORE) ((SELF PARTIAL-MATCH-FRAME)))");

              method->method_code = ((cpp_method_code)(&Partial_Match_Frame::compute_or_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-NOT-SCORE", "PARTIAL-MATCH-FRAME", "(DEFMETHOD (COMPUTE-NOT-SCORE PARTIAL-MATCH-SCORE) ((SELF PARTIAL-MATCH-FRAME)))");

              method->method_code = ((cpp_method_code)(&Partial_Match_Frame::compute_not_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("EARLY-PARTIAL-MATCH-AND-FAILURE?", "PARTIAL-MATCH-FRAME", "(DEFMETHOD (EARLY-PARTIAL-MATCH-AND-FAILURE? BOOLEAN) ((SELF PARTIAL-MATCH-FRAME)))");

              method->method_code = ((cpp_method_code)(&Partial_Match_Frame::early_partial_match_and_failureP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EARLY-PARTIAL-MATCH-OR-SUCCESS?", "PARTIAL-MATCH-FRAME", "(DEFMETHOD (EARLY-PARTIAL-MATCH-OR-SUCCESS? BOOLEAN) ((SELF PARTIAL-MATCH-FRAME)))");

              method->method_code = ((cpp_method_code)(&Partial_Match_Frame::early_partial_match_or_successP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLIP-POSITIVE-SCORE", "PARTIAL-MATCH-FRAME", "(DEFMETHOD (CLIP-POSITIVE-SCORE PARTIAL-MATCH-SCORE) ((SELF PARTIAL-MATCH-FRAME) (SCORE FLOAT)) :DOCUMENTATION \"If 'score' is below the minimum or\nabove the maximum, make it zero or one.\")");

              method->method_code = ((cpp_method_code)(&Partial_Match_Frame::clip_positive_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-RULE-SCORE", "PARTIAL-MATCH-FRAME", "(DEFMETHOD (COMPUTE-RULE-SCORE PARTIAL-MATCH-SCORE) ((SELF PARTIAL-MATCH-FRAME) (ANTECEDENTSCORE PARTIAL-MATCH-SCORE) (RULESCORE TRUTH-VALUE)) :DOCUMENTATION \"Return a score representing the combination of\n'antecedentScore', the score for the match of a rule antecedent, and\n'ruleScore', the score assigned to the rule being interpreted.\")");

              method->method_code = ((cpp_method_code)(&Partial_Match_Frame::compute_rule_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-PARTIAL-MATCH-FRAME", "NAIVE-PARTIAL-MATCH", "(DEFMETHOD (CREATE-PARTIAL-MATCH-FRAME PARTIAL-MATCH-FRAME) ((SELF NAIVE-PARTIAL-MATCH) (FRAME CONTROL-FRAME) (KIND KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Naive_Partial_Match::create_partial_match_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("RECORD-PARTIAL-MATCH-SCORE", "NAIVE-PARTIAL-MATCH", "(DEFMETHOD RECORD-PARTIAL-MATCH-SCORE ((SELF NAIVE-PARTIAL-MATCH) (SCORE PARTIAL-MATCH-SCORE) (WEIGHT FLOAT)))");

              method->method_code = ((cpp_method_code)(&Naive_Partial_Match::record_partial_match_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-AND-SCORE", "NAIVE-PARTIAL-MATCH", "(DEFMETHOD (COMPUTE-AND-SCORE PARTIAL-MATCH-SCORE) ((SELF NAIVE-PARTIAL-MATCH)))");

              method->method_code = ((cpp_method_code)(&Naive_Partial_Match::compute_and_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-OR-SCORE", "NAIVE-PARTIAL-MATCH", "(DEFMETHOD (COMPUTE-OR-SCORE PARTIAL-MATCH-SCORE) ((SELF NAIVE-PARTIAL-MATCH)))");

              method->method_code = ((cpp_method_code)(&Naive_Partial_Match::compute_or_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-NOT-SCORE", "NAIVE-PARTIAL-MATCH", "(DEFMETHOD (COMPUTE-NOT-SCORE PARTIAL-MATCH-SCORE) ((SELF NAIVE-PARTIAL-MATCH)))");

              method->method_code = ((cpp_method_code)(&Naive_Partial_Match::compute_not_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-PARTIAL-MATCH-FRAME", "INCREMENTAL-PARTIAL-MATCH", "(DEFMETHOD (CREATE-PARTIAL-MATCH-FRAME PARTIAL-MATCH-FRAME) ((SELF INCREMENTAL-PARTIAL-MATCH) (FRAME CONTROL-FRAME) (KIND KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Incremental_Partial_Match::create_partial_match_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("RECORD-PARTIAL-MATCH-SCORE", "INCREMENTAL-PARTIAL-MATCH", "(DEFMETHOD RECORD-PARTIAL-MATCH-SCORE ((SELF INCREMENTAL-PARTIAL-MATCH) (SCORE PARTIAL-MATCH-SCORE) (WEIGHT FLOAT)))");

              method->method_code = ((cpp_method_code)(&Incremental_Partial_Match::record_partial_match_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-AND-SCORE", "INCREMENTAL-PARTIAL-MATCH", "(DEFMETHOD (COMPUTE-AND-SCORE PARTIAL-MATCH-SCORE) ((SELF INCREMENTAL-PARTIAL-MATCH)))");

              method->method_code = ((cpp_method_code)(&Incremental_Partial_Match::compute_and_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-OR-SCORE", "INCREMENTAL-PARTIAL-MATCH", "(DEFMETHOD (COMPUTE-OR-SCORE PARTIAL-MATCH-SCORE) ((SELF INCREMENTAL-PARTIAL-MATCH)))");

              method->method_code = ((cpp_method_code)(&Incremental_Partial_Match::compute_or_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-NOT-SCORE", "INCREMENTAL-PARTIAL-MATCH", "(DEFMETHOD (COMPUTE-NOT-SCORE PARTIAL-MATCH-SCORE) ((SELF INCREMENTAL-PARTIAL-MATCH)))");

              method->method_code = ((cpp_method_code)(&Incremental_Partial_Match::compute_not_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("EARLY-PARTIAL-MATCH-AND-FAILURE?", "INCREMENTAL-PARTIAL-MATCH", "(DEFMETHOD (EARLY-PARTIAL-MATCH-AND-FAILURE? BOOLEAN) ((SELF INCREMENTAL-PARTIAL-MATCH)))");

              method->method_code = ((cpp_method_code)(&Incremental_Partial_Match::early_partial_match_and_failureP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EARLY-PARTIAL-MATCH-OR-SUCCESS?", "INCREMENTAL-PARTIAL-MATCH", "(DEFMETHOD (EARLY-PARTIAL-MATCH-OR-SUCCESS? BOOLEAN) ((SELF INCREMENTAL-PARTIAL-MATCH)))");

              method->method_code = ((cpp_method_code)(&Incremental_Partial_Match::early_partial_match_or_successP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-AND-LINK-PARTIAL-MATCH-FRAME", "CONTROL-FRAME", "(DEFUN CREATE-AND-LINK-PARTIAL-MATCH-FRAME ((FRAME CONTROL-FRAME) (KIND KEYWORD)))");

              method->function_code = ((cpp_function_code)(&create_and_link_partial_match_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("RECORD-LATEST-PARTIAL-MATCH-SCORE", "CONTROL-FRAME", "(DEFUN RECORD-LATEST-PARTIAL-MATCH-SCORE ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&record_latest_partial_match_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-PARTIAL-MATCH-AND-FAILURE?", "CONTROL-FRAME", "(DEFUN (COMPUTE-PARTIAL-MATCH-AND-FAILURE? BOOLEAN) ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&compute_partial_match_and_failureP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-PARTIAL-MATCH-OR-SUCCESS?", "CONTROL-FRAME", "(DEFUN (COMPUTE-PARTIAL-MATCH-OR-SUCCESS? BOOLEAN) ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&compute_partial_match_or_successP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-PARTIAL-MATCH-SCORE?", "CONTROL-FRAME", "(DEFUN (COMPUTE-PARTIAL-MATCH-SCORE? BOOLEAN) ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&compute_partial_match_scoreP));
            }
            define_method_from_stringified_source("STARTUP-PARTIAL-MATCH", NULL, "(DEFUN STARTUP-PARTIAL-MATCH ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *MINIMUM-SCORE-CUTOFF* PARTIAL-MATCH-SCORE 0.0 :DOCUMENTATION \"Positive scores below *minimum-score-cutoff* get trimmed\nto 0.0 during partial match operations.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *MAXIMUM-SCORE-CUTOFF* PARTIAL-MATCH-SCORE 0.0 :DOCUMENTATION \"Positive scores above *maximum-score-cutoff* get trimmed\nto 1.0 during partial match operations.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEFAULT-MINIMUM-SCORE* PARTIAL-MATCH-SCORE 0.0)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEFAULT-MAXIMUM-SCORE* PARTIAL-MATCH-SCORE 0.0)");
            reset_combinator_settings();
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

