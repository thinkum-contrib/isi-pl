// more-demons.hh

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
void inverse_slot_demon(Standard_Object* self, Storage_Slot* slot, Standard_Object* oldvalue, Standard_Object* newvalue);
void attach_inverse_slot_demon(Slot* slot);
void class_extension_constructor_demon(Active_Object* self, Class* renamed_Class);
void class_extension_destructor_demon(Active_Object* self, Class* renamed_Class);
void startup_more_demons();

// Global declarations:
extern Symbol* SYM_MORE_DEMONS_INVERSE;
extern Keyword* KWD_MORE_DEMONS_CODE;
extern Symbol* SYM_MORE_DEMONS_SLOT_DEMONS;
extern Keyword* KWD_MORE_DEMONS_DOCUMENTATION;
extern Keyword* KWD_MORE_DEMONS_CREATE;
extern Keyword* KWD_MORE_DEMONS_ALL;
extern Keyword* KWD_MORE_DEMONS_DESTROY;

