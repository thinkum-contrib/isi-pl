//  -*- Mode: C++ -*-

// rules.hh

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

// Global declarations:
extern boolean oLAZY_SATELLITE_RULESpo;
extern DECLARE_STELLA_SPECIAL(oDERIVE_DEFERRED_SATELLITE_RULES_INVOCATIONSo, List* );

// Function signatures:
List* findMatchableGoals(Proposition* forallprop, Keyword* headortail);
void collectMatchingRuleGoals(Proposition* proposition, Cons* toplevelvars, Keyword* headortail, List* collection);
boolean atomicForallArgumentP(Proposition* forallprop, Keyword* headortail);
boolean atomicGoalPropositionP(Proposition* proposition);
boolean atomicGoalDescriptionP(Description* description);
boolean variableArityGoalPropositionP(Proposition* proposition);
boolean chainableRelationP(NamedDescription* description, Keyword* headortail);
Description* extractGoalDescription(Proposition* goal, Keyword* headortail);
Cons* extractGoalArguments(Proposition* goal);
Proposition* substituteProposition(Proposition* proposition, Proposition* outprop, Proposition* inprop);
Proposition* extractInvertedGoal(Proposition* proposition, Proposition* goal);
Proposition* invertForallAroundGoal(Proposition* forallprop, Proposition* goal, Keyword* headortail, boolean contrapositiveP);
Object* constructDescriptionFromForallProposition(Proposition* forallprop, Keyword* headortail);
void markAsForwardRule(Proposition* impliesprop);
void deriveOneSatelliteRule(Proposition* masterforall, Proposition* goal, Keyword* headortail, boolean contrapositiveP);
void equateAndSimplifyForallArgument(Proposition* proposition);
boolean deriveSatelliteRulesForGoalP(Proposition* forallprop, Description* goaldescription, Keyword* direction, boolean lazysatellitesP);
void deriveSatelliteRules(Proposition* forallprop);
void deriveDeferredSatelliteRules(Description* self);
void deriveDeferredContrapositiveSatelliteRules(Description* self);
Description* getInferableComplementDescription(Description* self);
Proposition* deriveImpliesFromForall(Proposition* forallprop);
Cons* deconstructForallTree(Cons* foralltree, Object*& _Return1, Cons*& _Return2);
Cons* removeExistsVariable(Cons* existsproposition, Symbol* variable);
ForwardChainingIndex* createForwardChainingIndex(Proposition* goal, Proposition* masterforall);
void deriveComplexForwardRule(Proposition* goal, Proposition* masterforall);
Cons* helpGetForwardChainingRules(Description* description);
Cons* callGetRules(Object* relationref);
Cons* getRules(Object* relation);
void deleteRules(Object* relation);
void printRules(Object* relation);
void printSatellites(Proposition* forallprop);
Proposition* getRule(Object* rulename);
Proposition* findRule(Object* rulename);
Proposition* assertRule(Object* rulename);
Proposition* retractRule(Object* rulename);
void deleteRuleCachesOnRelation(Relation* relation);
void resetQueryCaches();
void helpStartupRules1();
void startupRules();

// Auxiliary global declarations:
extern Keyword* KWD_RULES_HEAD;
extern Symbol* SYM_RULES_LOGIC_IO_VARIABLES;
extern Keyword* KWD_RULES_TAIL;
extern Keyword* KWD_RULES_AND;
extern Keyword* KWD_RULES_EXISTS;
extern Keyword* KWD_RULES_OR;
extern Keyword* KWD_RULES_FORALL;
extern Keyword* KWD_RULES_ISA;
extern Keyword* KWD_RULES_PREDICATE;
extern Keyword* KWD_RULES_FUNCTION;
extern Keyword* KWD_RULES_NOT;
extern Keyword* KWD_RULES_IMPLIES;
extern Surrogate* SGT_RULES_PL_KERNEL_KB_HOLDS;
extern Surrogate* SGT_RULES_LOGIC_PATTERN_VARIABLE;
extern Symbol* SYM_RULES_LOGIC_COMPLEMENT_DESCRIPTION;
extern Surrogate* SGT_RULES_STELLA_SURROGATE;
extern Keyword* KWD_RULES_ERROR;
extern Surrogate* SGT_RULES_LOGIC_PROPOSITION;
extern Surrogate* SGT_RULES_STELLA_FALSE;
extern Surrogate* SGT_RULES_STELLA_TRUE;
extern Symbol* SYM_RULES_STELLA_FORALL;
extern Keyword* KWD_RULES_DESCRIPTION;
extern Symbol* SYM_RULES_LOGIC_FORWARD_ONLYp;
extern Keyword* KWD_RULES_EXTENSIONAL_ASSERTION;
extern Symbol* SYM_RULES_LOGIC_SATELLITE_PROPOSITIONS;
extern Symbol* SYM_RULES_LOGIC_MASTER_PROPOSITION;
extern Symbol* SYM_RULES_LOGIC_BACKWARD_ONLYp;
extern Symbol* SYM_RULES_LOGIC_DONT_OPTIMIZEp;
extern Keyword* KWD_RULES_POSITIVE;
extern Keyword* KWD_RULES_CONTRAPOSITIVE;
extern Symbol* SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES;
extern Keyword* KWD_RULES_NON_PAGING;
extern Symbol* SYM_RULES_LOGIC_DEFERRED_CONTRAPOSITIVESp;
extern Keyword* KWD_RULES_POSITIVE_AND_CONTRAPOSITIVE;
extern Symbol* SYM_RULES_STELLA_TRUE;
extern Symbol* SYM_RULES_STELLA_EXISTS;
extern Symbol* SYM_RULES_LOGIC_KAPPA;
extern Symbol* SYM_RULES_LOGIC_FORWARD_CHAINING_INDICES;
extern Surrogate* SGT_RULES_LOGIC_NAMED_DESCRIPTION;
extern Keyword* KWD_RULES_FORWARD;
extern Keyword* KWD_RULES_BACKWARD;
extern Keyword* KWD_RULES_ASSERT_TRUE;
extern Keyword* KWD_RULES_RETRACT_TRUE;
extern Symbol* SYM_RULES_LOGIC_DESCRIPTION;
extern Symbol* SYM_RULES_LOGIC_STARTUP_RULES;
extern Symbol* SYM_RULES_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
