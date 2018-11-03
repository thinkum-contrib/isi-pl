//  -*- Mode: C++ -*-

// api-support.hh

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

// Function signatures:
boolean classNamesNextP(AllPurposeIterator* self);
boolean allPropositionsNextP(AllPurposeIterator* self);
Iterator* allPropositions(Module* module, boolean localP);
boolean visibleTermP(LogicObject* term, Context* context, boolean localP);
Iterator* allUnnamedTerms(Module* module, boolean localP);
boolean allNamedTermsNextP(AllPurposeIterator* self);
Iterator* allNamedTerms(Module* module, boolean localP);
Iterator* allTerms(Module* module, boolean localP);
boolean filterInstanceP(LogicObject* self, AllPurposeIterator* iterator);
Iterator* allNamedInstances(Module* module, boolean localP);
Iterator* allInstances(Module* module, boolean localP);
LogicObject* stringToLogicObject(char* string);
void startupApiSupport();

// Auxiliary global declarations:
extern Surrogate* SGT_API_SUPPORT_LOGIC_LOGIC_OBJECT;
extern Surrogate* SGT_API_SUPPORT_LOGIC_PATTERN_VARIABLE;
extern Surrogate* SGT_API_SUPPORT_LOGIC_SKOLEM;
extern Surrogate* SGT_API_SUPPORT_STELLA_THING;
extern Surrogate* SGT_API_SUPPORT_LOGIC_DESCRIPTION;
extern Symbol* SYM_API_SUPPORT_LOGIC_STARTUP_API_SUPPORT;
extern Symbol* SYM_API_SUPPORT_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
