// api-support.hh

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
class Slot_Value_Iterator;

// Function signatures:
boolean filtered_types_to_classes_nextP(All_Purpose_Iterator* self);
boolean filtered_types_nextP(All_Purpose_Iterator* self);
boolean get_types_nextP(All_Purpose_Iterator* self);
boolean class_names_nextP(All_Purpose_Iterator* self);
void collect_subtypes(Surrogate* type, List* result);
Slot_Value_Iterator* new_slot_value_iterator();
Object* access_slot_value_iterator_slot_value(Slot_Value_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
boolean all_propositions_nextP(All_Purpose_Iterator* self);
Iterator* all_propositions(Module* module, boolean localP);
boolean visible_termP(Logic_Object* term, Context* context, boolean localP);
boolean term_linked_to_visible_surrogateP(Logic_Object* term, Context* context, boolean localP);
Iterator* all_unnamed_terms(Module* module, boolean localP);
boolean all_named_terms_nextP(All_Purpose_Iterator* self);
Iterator* all_named_terms(Module* module, boolean localP);
Iterator* all_terms(Module* module, boolean localP);
boolean filter_instanceP(Logic_Object* self, All_Purpose_Iterator* iterator);
Iterator* all_named_instances(Module* module, boolean localP);
Iterator* all_instances(Module* module, boolean localP);
Logic_Object* string_to_logic_object(char* string);
void startup_api_support();

// Global declarations:
extern Symbol* SYM_API_SUPPORT_NESTED_ITERATOR;
extern Surrogate* SGT_API_SUPPORT_SLOT_VALUE_ITERATOR;
extern Surrogate* SGT_API_SUPPORT_DESCRIPTION;
extern Surrogate* SGT_API_SUPPORT_SLOT;
extern Symbol* SYM_API_SUPPORT_SURROGATE_VALUE_INVERSE;
extern Surrogate* SGT_API_SUPPORT_RELATION;
extern Symbol* SYM_API_SUPPORT_DESCRIPTION;
extern Symbol* SYM_API_SUPPORT_DEFINITION;
extern Surrogate* SGT_API_SUPPORT_LOGIC_OBJECT;
extern Surrogate* SGT_API_SUPPORT_PATTERN_VARIABLE;
extern Surrogate* SGT_API_SUPPORT_SKOLEM;

class Slot_Value_Iterator : public Dictionary_Iterator {
public:
  Iterator* nested_iterator;
public:
  virtual Surrogate* primary_type();
  virtual boolean nextP();
};

