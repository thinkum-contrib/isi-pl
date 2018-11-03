// partial-match.hh

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
class Partial_Match_Frame;
class Naive_Partial_Match;
class Incremental_Partial_Match;

// Function signatures:
Object* access_partial_match_frame_slot_value(Partial_Match_Frame* self, Symbol* slotname, Object* value, boolean setvalueP);
void reset_combinator_settings();
double proposition_weight(Proposition* proposition);
Naive_Partial_Match* new_naive_partial_match();
Object* access_naive_partial_match_slot_value(Naive_Partial_Match* self, Symbol* slotname, Object* value, boolean setvalueP);
Incremental_Partial_Match* new_incremental_partial_match();
Object* access_incremental_partial_match_slot_value(Incremental_Partial_Match* self, Symbol* slotname, Object* value, boolean setvalueP);
void create_and_link_partial_match_frame(Control_Frame* frame, Keyword* kind);
void record_latest_partial_match_score(Control_Frame* frame);
boolean compute_partial_match_and_failureP(Control_Frame* frame);
boolean compute_partial_match_or_successP(Control_Frame* frame);
boolean compute_partial_match_scoreP(Control_Frame* frame);
void startup_partial_match();

// Global declarations:
extern Symbol* SYM_PARTIAL_MATCH_KIND;
extern double oMINIMUM_SCORE_CUTOFFo;
extern double oMAXIMUM_SCORE_CUTOFFo;
extern double oDEFAULT_MINIMUM_SCOREo;
extern double oDEFAULT_MAXIMUM_SCOREo;
extern Symbol* SYM_PARTIAL_MATCH_ARGUMENT_SCORES;
extern Symbol* SYM_PARTIAL_MATCH_ARGUMENT_WEIGHTS;
extern Surrogate* SGT_PARTIAL_MATCH_NAIVE_PARTIAL_MATCH;
extern Keyword* KWD_PARTIAL_MATCH_AND;
extern Symbol* SYM_PARTIAL_MATCH_TOTAL_WEIGHT;
extern Symbol* SYM_PARTIAL_MATCH_ACCUMULATED_SCORE;
extern Symbol* SYM_PARTIAL_MATCH_ACCUMULATED_WEIGHT;
extern Symbol* SYM_PARTIAL_MATCH_MAXIMUM_SCORE;
extern Surrogate* SGT_PARTIAL_MATCH_INCREMENTAL_PARTIAL_MATCH;
extern Keyword* KWD_PARTIAL_MATCH_OR;
extern Keyword* KWD_PARTIAL_MATCH_NOT;

class Partial_Match_Frame : public Standard_Object {
public:
  Keyword* kind;
public:
  virtual double compute_rule_score(double antecedentscore, Truth_Value* rulescore);
  virtual double clip_positive_score(double score);
  virtual boolean early_partial_match_or_successP();
  virtual boolean early_partial_match_and_failureP();
  virtual double compute_not_score();
  virtual double compute_or_score();
  virtual double compute_and_score();
  virtual void record_partial_match_score(double score, double weight);
  virtual Partial_Match_Frame* create_partial_match_frame(Control_Frame* frame, Keyword* kind);
};

class Naive_Partial_Match : public Partial_Match_Frame {
public:
  Cons* argument_scores;
  Cons* argument_weights;
public:
  virtual Surrogate* primary_type();
  virtual double compute_not_score();
  virtual double compute_or_score();
  virtual double compute_and_score();
  virtual void record_partial_match_score(double score, double weight);
  virtual Partial_Match_Frame* create_partial_match_frame(Control_Frame* frame, Keyword* kind);
};

class Incremental_Partial_Match : public Partial_Match_Frame {
public:
  double total_weight;
  double accumulated_score;
  double accumulated_weight;
  double maximum_score;
public:
  virtual Surrogate* primary_type();
  virtual boolean early_partial_match_or_successP();
  virtual boolean early_partial_match_and_failureP();
  virtual double compute_not_score();
  virtual double compute_or_score();
  virtual double compute_and_score();
  virtual void record_partial_match_score(double score, double weight);
  virtual Partial_Match_Frame* create_partial_match_frame(Control_Frame* frame, Keyword* kind);
};

