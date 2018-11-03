// rules.hh

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
List* find_rule_tails(Proposition* proposition, Vector* variables, boolean& return1);
List* find_rule_heads(Proposition* proposition, Vector* variables, boolean& return1);
void collect_matching_rule_goal(Proposition* goal, Vector* variables, List* collection);
Object* maybe_substitute_surrogate_argument(Object* arg1, Object* arg2);
Proposition* finish_building_implies_proposition(Object* head, Object* tail, Proposition* forallprop, boolean replacesforallP);
Object* construct_description_from_forall_proposition(Proposition* forallprop, Keyword* headortail, Vector* variables, boolean destructiveP);
Proposition* derive_one_implies_proposition(Cons* headpair, Cons* tailpair, Proposition* forallprop, boolean replacesforallP);
Proposition* derive_implies_propositions(Proposition* forallprop, Keyword* updatemode);
List* get_rules(Slot* slot);
List* drop_rules(Slot* slot);
void print_rules(char* slotname);
Proposition* define_rule(char* name, Object* ruletree);
Proposition* defrule(Object* rulename, Object* rule);
void delete_rule_caches_on_slot(Slot* slot);
void reset_query_caches();
void startup_rules();

// Global declarations:
extern Keyword* KWD_RULES_OR;
extern Keyword* KWD_RULES_AND;
extern Keyword* KWD_RULES_EXISTS;
extern Keyword* KWD_RULES_IN;
extern Surrogate* SGT_RULES_SURROGATE;
extern Surrogate* SGT_RULES_SKOLEM;
extern Keyword* KWD_RULES_PREDICATE;
extern Keyword* KWD_RULES_FUNCTION;
extern Keyword* KWD_RULES_NOT;
extern Surrogate* SGT_RULES_DESCRIPTION;
extern Symbol* SYM_RULES_IMPLIES;
extern Symbol* SYM_RULES_SATELLITE_PROPOSITIONS;
extern Symbol* SYM_RULES_MASTER_PROPOSITION;
extern Keyword* KWD_RULES_HEAD;
extern Keyword* KWD_RULES_TAIL;
extern Symbol* SYM_RULES_EXISTS;
extern Symbol* SYM_RULES_IO_VARIABLES;
extern Keyword* KWD_RULES_ASSERT_TRUE;
extern Symbol* SYM_RULES_DESCRIPTION;
extern Keyword* KWD_RULES_IMPLIES;
extern Symbol* SYM_RULES_COMPLEMENT_DESCRIPTION;
extern Surrogate* SGT_RULES_SLOT;
extern Surrogate* SGT_RULES_PROPOSITION;
extern Symbol* SYM_RULES_SURROGATE_VALUE_INVERSE;
extern Symbol* SYM_RULES_ESTIMATED_CARDINALITY;

