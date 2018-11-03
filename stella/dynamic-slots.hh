// dynamic-slots.hh

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996, 1997             | 
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
Object* dynamic_slot_value(Dynamic_Slots_Mixin* self, Symbol* slotname, Object* nullvalue);
Object* help_set_dynamic_slot_value(Key_Value_List* dynamicslots, Symbol* slotname, Object* value, Object*& return1);
Object* set_dynamic_slot_value(Dynamic_Slots_Mixin* self, Symbol* slotname, Object* value, Wrapper* nullwrapper);
boolean standard_dynamic_slot_accessP(Storage_Slot* slot);
Cons* yield_down_cast_tree(Cons* tree, Standard_Object* returntype);
Cons* yield_standard_dynamic_slot_value_tree(Storage_Slot* slot, Object* objectref, Standard_Object* returntype);
Cons* yield_standard_dynamic_slot_value_setter_tree(Storage_Slot* slot, Object* objectref, Object* valueref, Standard_Object* returntype);
void startup_dynamic_slots();

// Global declarations:
extern Keyword* KWD_DYNAMIC_SLOTS_DYNAMIC;
extern Keyword* KWD_DYNAMIC_SLOTS_NULL_WRAPPER;
extern Keyword* KWD_DYNAMIC_SLOTS_COMMON_LISP;
extern Surrogate* SGT_DYNAMIC_SLOTS_OBJECT;
extern Symbol* SYM_DYNAMIC_SLOTS_WRAPPER_VALUE;
extern Symbol* SYM_DYNAMIC_SLOTS_SAFE_CAST;
extern Symbol* SYM_DYNAMIC_SLOTS_DYNAMIC_SLOT_VALUE;
extern Symbol* SYM_DYNAMIC_SLOTS_QUOTE;
extern Symbol* SYM_DYNAMIC_SLOTS_NULL;
extern Symbol* SYM_DYNAMIC_SLOTS_SET_DYNAMIC_SLOT_VALUE;
extern Symbol* SYM_DYNAMIC_SLOTS_BQUOTE;
extern Keyword* KWD_DYNAMIC_SLOTS_WRAP_FUNCTION;

