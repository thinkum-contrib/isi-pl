// api.hh

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
char* logic_definition(Object* object);
char* source_definition(Object* object);
char* object_name(Object* object);
Class* find_class(char* name);
Context* find_context(char* name);
Logic_Object* find_instance(char* name);
Logic_Object* get_instance(char* name, boolean errorP);
Iterator* all_superclasses(Class* renamed_Class);
boolean subclassP(Class* class1, Class* class2);
Iterator* direct_superclasses(Class* renamed_Class);
Cons* test1(Cons* parents);
Iterator* direct_supertypes(Class* renamed_Class);
Iterator* direct_subclasses(Class* renamed_Class);
All_Purpose_Iterator* class_names(Class* renamed_Class);
Cons_Iterator* get_instances(Class* renamed_Class);
Iterator* get_subclasses(Class* renamed_Class);
void add_superclass(Generalized_Symbol* super, Class* renamed_Class);
void remove_superclass(Generalized_Symbol* super, Class* renamed_Class);
Class* domain(Slot* slot);
boolean computedP(Slot* slot);
Class* range(Slot* slot);
boolean read_onlyP(Storage_Slot* slot);
boolean slotP(Object* object);
boolean asserted_instance_of_classP(Logic_Object* instance, Class* renamed_Class);
boolean constantP(Object* object);
All_Purpose_Iterator* get_types(Logic_Object* instance);
Object* get_value(Logic_Object* instance, Slot* slot);
Slot_Value_Iterator* list_slot_names_and_values(Logic_Object* instance);
Context* context(Object* object);
All_Purpose_Iterator* list_module(Module* module);
Iterator* context_parents(Module* module);
Iterator* context_children(Module* module);
Object* iterator_key(Dictionary_Iterator* self);
Object* iterator_value(Iterator* self);
List* read_Oselected_modulesO();
List* write_Oselected_modulesO(List* value);
void select_module(Module* module, boolean localP);
void deselect_module(Module* module, boolean localP);
void select_all_modules();
boolean visible_objectP(Object* object);
Iterator* slot_column_types(Slot* self);
boolean slot_column_types_nextP(All_Purpose_Iterator* self);
boolean slot_column_types_emptyP(All_Purpose_Iterator* self);
boolean instance_p(Object* object);
void startup_api();

// Global declarations:
extern Surrogate* SGT_API_RELATION;
extern Symbol* SYM_API_DEFINITION_STRING;
extern Surrogate* SGT_API_SLOT;
extern Surrogate* SGT_API_LOGIC_OBJECT;
extern Symbol* SYM_API_SURROGATE_VALUE_INVERSE;
extern Surrogate* SGT_API_MODULE;
extern Surrogate* SGT_API_GENERALIZED_SYMBOL;
extern Surrogate* SGT_API_CLASS;
extern Surrogate* SGT_API_CONTEXT;
extern Symbol* SYM_API_DESCRIPTION;
extern Surrogate* SGT_API_LITERAL_WRAPPER;
extern Surrogate* SGT_API_SYMBOL;
extern Keyword* KWD_API_IN;
extern Keyword* KWD_API_FUNCTION;
extern List* oSELECTED_MODULESo;
extern Symbol* SYM_API_oSELECTED_MODULESo;
extern Surrogate* SGT_API_BOOLEAN;
extern Surrogate* SGT_API_TABLE;

