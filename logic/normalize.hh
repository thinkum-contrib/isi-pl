// normalize.hh

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


// Function signatures:
void collect_flat_conjuncts(Proposition* self, List* flatconjuncts);
void overlay_with_constant_proposition(Proposition* self, Proposition* constantproposition);
Proposition* conjoin_propositions(Cons* conjuncts);
void collect_flat_disjuncts(Proposition* self, List* flatdisjuncts);
Proposition* disjoin_propositions(Cons* disjuncts);
void overlay_proposition(Proposition* self, Proposition* overlayingprop);
void normalize_exists_proposition(Proposition* self);
Proposition* help_migrate_goals(List* negatedgoals, Proposition* antecedent);
void migrate_consequent_goals_to_antecedent(Proposition* self);
void normalize_forall_proposition(Proposition* self);
void normalize_not_proposition(Proposition* self);
void normalize_and_proposition(Proposition* self);
void normalize_or_proposition(Proposition* self);
void normalize_proposition(Proposition* self);
void invert_atomic_proposition(Proposition* self);
void invert_exists_proposition(Proposition* self);
void invert_forall_proposition(Proposition* self);
Proposition* extract_proposition(Description* self, Key_Value_List* mapping);
void invert_implies_proposition(Proposition* self);
void invert_proposition(Proposition* self);
void recursively_deassign_truth_values(Proposition* self);
void reassign_truth_values(Proposition* self);
void startup_normalize();

// Global declarations:
extern Keyword* KWD_NORMALIZE_AND;
extern Keyword* KWD_NORMALIZE_CONSTANT;
extern Surrogate* SGT_NORMALIZE_TRUE;
extern Symbol* SYM_NORMALIZE_CONSTANT;
extern Symbol* SYM_NORMALIZE_AND;
extern Keyword* KWD_NORMALIZE_OR;
extern Symbol* SYM_NORMALIZE_OR;
extern Symbol* SYM_NORMALIZE_IO_VARIABLES;
extern Keyword* KWD_NORMALIZE_EXISTS;
extern Keyword* KWD_NORMALIZE_NOT;
extern Keyword* KWD_NORMALIZE_FUNCTION;
extern Keyword* KWD_NORMALIZE_IN;
extern Keyword* KWD_NORMALIZE_EQUIVALENT;
extern Keyword* KWD_NORMALIZE_PREDICATE;
extern Surrogate* SGT_NORMALIZE_FALSE;
extern Symbol* SYM_NORMALIZE_EXISTS;
extern Surrogate* SGT_NORMALIZE_PROPOSITION;
extern Keyword* KWD_NORMALIZE_FORALL;
extern Keyword* KWD_NORMALIZE_IMPLIES;
extern Symbol* SYM_NORMALIZE_NOT;
extern Surrogate* SGT_NORMALIZE_NOT;
extern Surrogate* SGT_NORMALIZE_FORALL;
extern Surrogate* SGT_NORMALIZE_EXISTS;
extern Surrogate* SGT_NORMALIZE_OR;
extern Surrogate* SGT_NORMALIZE_AND;
extern Keyword* KWD_NORMALIZE_DESCRIPTION;

