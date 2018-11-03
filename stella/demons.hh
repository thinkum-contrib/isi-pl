// demons.hh

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

// Class headers:
class Hook_List;

// Function signatures:
boolean validate_demon_referencesP(Demon* demon);
boolean incorporate_demon_optionsP(Demon* demon, Property_List* options);
Demon* lookup_demon(char* name);
Demon* define_demon(char* name, int options, ...);
List* inject_demon(List* demonlist, Demon* demon);
List* eject_demon(List* demonlist, Demon* demon);
void activate_demon(Demon* demon);
void deactivate_demon(Demon* demon);
Cons* destructure_defdemon_body(Cons* demontree, Cons*& return1);
void in_place_normalize_demon_options(Cons* optionstree);
Object* defdemon_expander(String_Wrapper* name, Cons* parameterstree, Cons* optionsandbody);
Object* read_slot_value(Standard_Object* self, Storage_Slot* slot);
Object* write_slot_value(Standard_Object* self, Storage_Slot* slot, Object* value);
Object* put_slot_value(Standard_Object* self, Storage_Slot* slot, Object* value);
void drop_slot_value(Standard_Object* self, Storage_Slot* slot, Object* value);
boolean check_for_slot_demonsP(Storage_Slot* slot);
boolean run_slot_guard_demonsP(Standard_Object* self, Storage_Slot* slot, Object* oldvalue, Object* newvalue);
void run_slot_demons(Standard_Object* self, Storage_Slot* slot, Object* oldvalue, Object* newvalue);
void run_constructor_demons(Standard_Object* self);
void run_destructor_demons(Standard_Object* self);
Cons* yield_active_slot_reader_body(Storage_Slot* slot, Object* defaultexpression);
void cant_overwrite_active_collection_slot(Standard_Object* self, Symbol* slotname);
Cons* yield_active_slot_writer_body(Storage_Slot* slot);
Hook_List* new_hook_list();
Object* access_hook_list_slot_value(Hook_List* self, Symbol* slotname, Object* value, boolean setvalueP);
void add_hook(Hook_List* hooklist, Symbol* hookfunction);
void drop_hook(Hook_List* hooklist, Symbol* hookfunction);
void run_hooks(Hook_List* hooklist, Object* argument);
void startup_demons();

// Global declarations:
extern String_Hash_Table* oDEMONS_TABLEo;
extern List* oCONSTRUCTOR_DEMONSo;
extern List* oDESTRUCTOR_DEMONSo;
extern List* oALL_SLOTS_DEMONSo;
extern List* oALL_SLOTS_GUARD_DEMONSo;
extern Keyword* KWD_DEMONS_MODIFY;
extern Keyword* KWD_DEMONS_CREATE;
extern Keyword* KWD_DEMONS_DESTROY;
extern Keyword* KWD_DEMONS_ALL;
extern Keyword* KWD_DEMONS_CLASS;
extern Keyword* KWD_DEMONS_SLOT;
extern Keyword* KWD_DEMONS_CODE;
extern Keyword* KWD_DEMONS_METHOD;
extern Keyword* KWD_DEMONS_GUARDp;
extern Keyword* KWD_DEMONS_INHERITEDp;
extern Keyword* KWD_DEMONS_DOCUMENTATION;
extern Keyword* KWD_DEMONS_ACTIVATEp;
extern Symbol* SYM_DEMONS_SLOT_GUARD_DEMONS;
extern Symbol* SYM_DEMONS_SLOT_DEMONS;
extern Symbol* SYM_DEMONS_CLASS_GUARD_CONSTRUCTOR_DEMONS;
extern Symbol* SYM_DEMONS_CLASS_CONSTRUCTOR_DEMONS;
extern Symbol* SYM_DEMONS_CLASS_GUARD_DESTRUCTOR_DEMONS;
extern Symbol* SYM_DEMONS_CLASS_DESTRUCTOR_DEMONS;
extern Symbol* SYM_DEMONS_WRAP_LITERAL;
extern Symbol* SYM_DEMONS_TRUE;
extern Symbol* SYM_DEMONS_WRAP_BOOLEAN;
extern Symbol* SYM_DEMONS_FALSE;
extern Symbol* SYM_DEMONS_PROGN;
extern Symbol* SYM_DEMONS_DEFUN;
extern Symbol* SYM_DEMONS_STARTUP_TIME_PROGN;
extern Symbol* SYM_DEMONS_DEFINE_DEMON;
extern Symbol* SYM_DEMONS_THE_CODE;
extern Keyword* KWD_DEMONS_FUNCTION;
extern Symbol* SYM_DEMONS_DEFDEMON;
extern Symbol* SYM_DEMONS_DEFDEMON_EXPANDER;
extern Symbol* SYM_DEMONS_SLOT_VALUE;
extern Symbol* SYM_DEMONS_SELF;
extern Symbol* SYM_DEMONS_LET;
extern Symbol* SYM_DEMONS_VALUE;
extern Symbol* SYM_DEMONS_WHEN;
extern Symbol* SYM_DEMONS_DEFINEDp;
extern Symbol* SYM_DEMONS_RETURN;
extern Symbol* SYM_DEMONS_SETQ;
extern Symbol* SYM_DEMONS_NEW;
extern Symbol* SYM_DEMONS_SETF;
extern Symbol* SYM_DEMONS_OWNER_INSTANCE;
extern Symbol* SYM_DEMONS_ACTIVE_SLOT;
extern Symbol* SYM_DEMONS_GET_SLOT;
extern Symbol* SYM_DEMONS_BQUOTE;
extern Surrogate* SGT_DEMONS_BOOLEAN;
extern Symbol* SYM_DEMONS_CANT_OVERWRITE_ACTIVE_COLLECTION_SLOT;
extern Surrogate* SGT_DEMONS_LITERAL;
extern Symbol* SYM_DEMONS_SLOT;
extern Symbol* SYM_DEMONS_OLDVALUE;
extern Symbol* SYM_DEMONS_NOT;
extern Symbol* SYM_DEMONS_EQLp;
extern Symbol* SYM_DEMONS_IF;
extern Symbol* SYM_DEMONS_CHECK_FOR_SLOT_DEMONSp;
extern Symbol* SYM_DEMONS_WRAPPEDOLDVALUE;
extern Symbol* SYM_DEMONS_CHOOSE;
extern Symbol* SYM_DEMONS_NULL;
extern Symbol* SYM_DEMONS_WRAPPEDNEWVALUE;
extern Symbol* SYM_DEMONS_RUN_SLOT_GUARD_DEMONSp;
extern Symbol* SYM_DEMONS_RUN_SLOT_DEMONS;
extern Symbol* SYM_DEMONS_FREE;
extern Symbol* SYM_DEMONS_AND;
extern Symbol* SYM_DEMONS_EQp;
extern Symbol* SYM_DEMONS_SIGNATURE;
extern Symbol* SYM_DEMONS_DOCUMENTATION;
extern Surrogate* SGT_DEMONS_HOOK_LIST;
extern Hook_List* oCHANGE_MODULE_HOOKSo;
extern Hook_List* oCLEAR_MODULE_HOOKSo;
extern Hook_List* oREDEFINE_RELATION_HOOKSo;
extern Hook_List* oBLOCK_NATIVE_CLASS_CREATION_HOOKSo;

class Hook_List : public Key_Value_List {
public:
  char* signature;
  char* documentation;
public:
  virtual Surrogate* primary_type();
};

