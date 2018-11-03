// classes.hh

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
char* class_name(Class* renamed_Class);
Symbol* class_symbol(Class* renamed_Class);
Symbol* type_to_symbol(Surrogate* type);
Class* string_lookup_class(char* name);
Class* type_to_class(Surrogate* type);
Class* string_get_class(char* classname, boolean errorP);
boolean bind_to_surrogateP(Object* self, char* name, boolean clipoldvalueP, boolean warnonfailureP, Object*& return1, Surrogate*& return2);
Symbol* shadow_symbol(char* name);
Surrogate* shadow_surrogate(char* name);
boolean bind_to_indexicalP(Object* self, char* name, boolean clipoldvalueP, boolean warnonfailureP, Object*& return1);
Indexical* shadow_indexical(char* name);
cpp_function_code get_constructor(Class* renamed_Class, boolean warnP);
Object* create_object(Surrogate* type, int alternatingsymbolsandvalues, ...);
Boolean_Wrapper* symbol_to_wrapped_boolean(Object* object);
Class* define_stella_class(Surrogate* name, List* supers, List* slots, Keyword_Key_Value_List* options);
Slot* define_stella_slot(Symbol* name, Surrogate* owner, Surrogate* basetype, Cons* typespecifier, Keyword_Key_Value_List* options);
void incorporate_class_options(Class* renamed_Class, Keyword_Key_Value_List* options);
boolean inline_methodP(Slot* slot);
void transfer_external_slot_to_new_class(Slot* externalslot, Class* newclass);
void transfer_demons_from_oldclass(Class* oldclass, Class* newclass);
void undefine_old_class(Class* oldclass, Class* newclass);
void destroy_class_and_subclasses(Class* self);
void insert_primitive_super(Surrogate* newsuper, List* supers);
void collect_most_specific_primitive_supers(Class* renamed_Class, List* supers);
List* most_specific_primitive_supers(Class* renamed_Class);
Iterator* class_native_supers(Class* renamed_Class);
void remember_unfinalized_class(Class* renamed_Class, boolean forceP);
void forget_unfinalized_class(Class* renamed_Class);
void finalize_classes();
void resolve_children_references();
void finalize_slots();
void cleanup_unfinalized_classes();
void finalize_classes_and_slots();
void activate_class(Class* renamed_Class);
void add_primary_type(Class* renamed_Class);
void finalize_one_class(Class* renamed_Class);
boolean finalize_class(Class* renamed_Class);
boolean help_finalize_class(Class* renamed_Class, Surrogate* finalizedparent);
void unfinalize_class_and_subclasses(Class* renamed_Class);
Slot* attach_slot_to_owner(Slot* newslot);
void compute_slot_direct_equivalent(Slot* self);
void check_conformance_of_slot_signature(Slot* self);
Surrogate* collection_to_active_collection(Surrogate* type);
void activate_slot(Storage_Slot* self);
boolean multi_valued_slot_with_duplicatesP(Slot* self);
void compute_slot_inverses(Slot* self);
void finalize_local_slot(Slot* self);
void finalize_class_slots(Class* renamed_Class);
void unfinalize_class_slots(Class* renamed_Class);
void help_unfinalize_class_slots(Class* renamed_Class);
void add_direct_supers_back_links(Class* renamed_Class);
void add_direct_subs_back_links(Class* renamed_Class);
void remove_direct_supers_back_links(Class* renamed_Class);
void collect_direct_super_classes(Class* renamed_Class, List* parents);
void inherit_superclasses(Class* renamed_Class);
void uninherit_superclasses(Class* renamed_Class);
boolean subclass_ofP(Class* subclass, Class* superclass);
boolean subtype_ofP(Surrogate* subtype, Surrogate* supertype);
boolean isaP(Object* object, Surrogate* type);
Class* two_argument_least_common_superclass(Class* class1, Class* class2);
Surrogate* two_argument_least_common_supertype(Surrogate* type1, Surrogate* type2);
void inherit_slots(Class* renamed_Class);
boolean local_slotP(Slot* slot, Class* renamed_Class);
void uninherit_slots(Class* renamed_Class);
void initialize_slot_and_method_cache(Class* renamed_Class);
void register_slot_name(Slot* slot);
void unregister_slot_name(Slot* slot);
boolean registered_slot_nameP(Symbol* slotname);
Slot* lookup_slot(Class* renamed_Class, Symbol* slotname);
Slot* safe_lookup_slot(Class* renamed_Class, Symbol* slotname);
Slot* lookup_local_slot(Class* renamed_Class, Symbol* slotname);
void clear_slot_and_method_cache(Class* renamed_Class);
boolean dynamic_slotP(Storage_Slot* slot);
void erase_dynamic_slot(Dynamic_Slots_Mixin* self, Symbol* slotname);
void resize_slot_caches(int size);
Slot* get_slot(Standard_Object* self, Symbol* slotname);
boolean conforming_type_specP(Standard_Object* subtypespec, Standard_Object* supertypespec);
boolean identical_signaturesP(Method_Slot* method1, Method_Slot* method2);
void compute_required_slot_names(Class* renamed_Class);
void free_required_slot_names(Class* renamed_Class);
boolean all_class_slots_nextP(All_Purpose_Iterator* self);
void repair_slots();
void disconnect_classes();
boolean filter_unbound_surrogateP(Surrogate* self, All_Purpose_Iterator* iterator);
Iterator* unbound_surrogates(Module* module, boolean localP);
char* name_to_string(Object* name);
void print_unbound_surrogates(Cons* args);
void print_unbound_surrogates_evaluator_wrapper(Cons* arguments);
boolean root_classP(Class* renamed_Class);
void clear_class_taxonomy();
void help_create_class_taxonomy(Class* renamed_Class, Class* parent);
void create_class_taxonomy();
boolean taxonomy_subclass_ofP(Class* subclass, Class* superclass);
boolean fast_taxonomy_subclass_ofP(Class* subclass, Class* superclass);
boolean taxonomy_isaP(Object* object, Surrogate* type);
Surrogate* intern_slotref(char* classname, char* slotname);
Surrogate* lookup_slotref(Surrogate* self, Symbol* slotname);
boolean slot_surrogateP(Surrogate* self);
Surrogate* slotref_type(Surrogate* slotref);
void startup_classes();

// Global declarations:
extern Surrogate* SGT_CLASSES_CLASS;
extern boolean oWARN_IF_REDEFINEpo;
extern Symbol* SYM_CLASSES_TRUE;
extern Symbol* SYM_CLASSES_FALSE;
extern Keyword* KWD_CLASSES_PARAMETERS;
extern Symbol* SYM_CLASSES_SLOT_TYPE_SPECIFIER;
extern Keyword* KWD_CLASSES_PUBLICp;
extern Keyword* KWD_CLASSES_REQUIREDp;
extern Keyword* KWD_CLASSES_COMPONENTp;
extern Keyword* KWD_CLASSES_READ_ONLYp;
extern Keyword* KWD_CLASSES_ACTIVEp;
extern Symbol* SYM_CLASSES_STORED_ACTIVEp;
extern Keyword* KWD_CLASSES_CONTEXT_SENSITIVEp;
extern Keyword* KWD_CLASSES_HARDWIREDp;
extern Keyword* KWD_CLASSES_ABSTRACTp;
extern Keyword* KWD_CLASSES_ALLOCATION;
extern Keyword* KWD_CLASSES_CLASS;
extern Symbol* SYM_CLASSES_SLOT_ALLOCATION;
extern Keyword* KWD_CLASSES_INITIALLY;
extern Symbol* SYM_CLASSES_SLOT_INITIAL_VALUE;
extern Keyword* KWD_CLASSES_DEFAULT;
extern Symbol* SYM_CLASSES_SLOT_DEFAULT_EXPRESSION;
extern Keyword* KWD_CLASSES_READER;
extern Symbol* SYM_CLASSES_SLOT_READER;
extern Keyword* KWD_CLASSES_WRITER;
extern Symbol* SYM_CLASSES_SLOT_WRITER;
extern Keyword* KWD_CLASSES_INVERSE;
extern Symbol* SYM_CLASSES_SLOT_INVERSE;
extern Keyword* KWD_CLASSES_RENAMES;
extern Symbol* SYM_CLASSES_SLOT_RENAMES;
extern Keyword* KWD_CLASSES_DOCUMENTATION;
extern Symbol* SYM_CLASSES_DOCUMENTATION;
extern Keyword* KWD_CLASSES_PROPERTIES;
extern Symbol* SYM_CLASSES_PROPERTIES;
extern Keyword* KWD_CLASSES_META_ATTRIBUTES;
extern Symbol* SYM_CLASSES_META_ATTRIBUTES;
extern Keyword* KWD_CLASSES_OPTION_KEYWORD;
extern Symbol* SYM_CLASSES_SLOT_OPTION_KEYWORD;
extern Keyword* KWD_CLASSES_OPTION_HANDLER;
extern Symbol* SYM_CLASSES_SLOT_OPTION_HANDLER;
extern Surrogate* SGT_CLASSES_BOOLEAN;
extern Keyword* KWD_CLASSES_BIT;
extern Keyword* KWD_CLASSES_CL_NATIVE_TYPE;
extern Symbol* SYM_CLASSES_CLASS_CL_NATIVE_TYPE;
extern Keyword* KWD_CLASSES_CPP_NATIVE_TYPE;
extern Symbol* SYM_CLASSES_CLASS_CPP_NATIVE_TYPE;
extern Keyword* KWD_CLASSES_IDL_NATIVE_TYPE;
extern Symbol* SYM_CLASSES_CLASS_IDL_NATIVE_TYPE;
extern Keyword* KWD_CLASSES_JAVA_NATIVE_TYPE;
extern Symbol* SYM_CLASSES_CLASS_JAVA_NATIVE_TYPE;
extern Keyword* KWD_CLASSES_CL_STRUCTp;
extern Keyword* KWD_CLASSES_MIXINp;
extern Keyword* KWD_CLASSES_RECYCLE_METHOD;
extern Symbol* SYM_CLASSES_CLASS_RECYCLE_METHOD;
extern Keyword* KWD_CLASSES_EXTENSION;
extern Symbol* SYM_CLASSES_CLASS_EXTENSION_NAME;
extern Keyword* KWD_CLASSES_CREATOR;
extern Symbol* SYM_CLASSES_CLASS_CREATOR;
extern Keyword* KWD_CLASSES_INITIALIZER;
extern Symbol* SYM_CLASSES_CLASS_INITIALIZER;
extern Keyword* KWD_CLASSES_TERMINATOR;
extern Symbol* SYM_CLASSES_CLASS_TERMINATOR;
extern Keyword* KWD_CLASSES_DESTRUCTOR;
extern Symbol* SYM_CLASSES_CLASS_DESTRUCTOR;
extern Keyword* KWD_CLASSES_INITIAL_VALUE;
extern Symbol* SYM_CLASSES_CLASS_INITIAL_VALUE;
extern Keyword* KWD_CLASSES_PRINT_FORM;
extern Symbol* SYM_CLASSES_PRINT_FORM;
extern Keyword* KWD_CLASSES_EQUALITY_TEST;
extern Keyword* KWD_CLASSES_KEY;
extern Symbol* SYM_CLASSES_CLASS_KEY;
extern Symbol* SYM_CLASSES_CLASS_PARAMETERS;
extern Keyword* KWD_CLASSES_SYNONYMS;
extern Symbol* SYM_CLASSES_CLASS_SYNONYMS;
extern Keyword* KWD_CLASSES_CHILDREN;
extern Surrogate* SGT_CLASSES_METHOD_SLOT;
extern Symbol* SYM_CLASSES_SLOT_GUARD_DEMONS;
extern Symbol* SYM_CLASSES_SLOT_DEMONS;
extern Symbol* SYM_CLASSES_CLASS_CONSTRUCTOR_DEMONS;
extern Symbol* SYM_CLASSES_CLASS_GUARD_CONSTRUCTOR_DEMONS;
extern Symbol* SYM_CLASSES_CLASS_DESTRUCTOR_DEMONS;
extern Symbol* SYM_CLASSES_CLASS_GUARD_DESTRUCTOR_DEMONS;
extern List* oUNFINALIZED_CLASSESo;
extern boolean oNEWLY_UNFINALIZED_CLASSESpo;
extern List* oCLASSES_WITH_UNRESOLVED_CHILDREN_REFERENCESo;
extern Surrogate* SGT_CLASSES_ACTIVE_OBJECT;
extern Surrogate* SGT_CLASSES_OBJECT;
extern Surrogate* SGT_CLASSES_STANDARD_OBJECT;
extern Symbol* SYM_CLASSES_PRIMARY_TYPE;
extern Symbol* SYM_CLASSES_SELF;
extern Keyword* KWD_CLASSES_TYPE;
extern Symbol* SYM_CLASSES_TYPE;
extern Keyword* KWD_CLASSES_AUXILIARYp;
extern Symbol* SYM_CLASSES_RETURN;
extern Symbol* SYM_CLASSES_CLASS_EXTENSION;
extern Surrogate* SGT_CLASSES_SET;
extern Surrogate* SGT_CLASSES_ACTIVE_SET;
extern Surrogate* SGT_CLASSES_LIST;
extern Surrogate* SGT_CLASSES_ACTIVE_LIST;
extern Surrogate* SGT_CLASSES_UNKNOWN;
extern Surrogate* SGT_CLASSES_COLLECTION;
extern Surrogate* SGT_CLASSES_SET_MIXIN;
extern Symbol* SYM_CLASSES_INVERSE;
extern Surrogate* SGT_CLASSES_DYNAMIC_SLOTS_MIXIN;
extern Keyword* KWD_CLASSES_INSTANCE;
extern Surrogate* SGT_CLASSES_CONTEXT_SENSITIVE_OBJECT;
extern Surrogate* SGT_CLASSES_VOID;
extern int oSYMBOL_SLOT_OFFSET_COUNTERo;
extern int oSLOT_CACHE_SIZEo;
extern Keyword* KWD_CLASSES_DYNAMIC;
extern Surrogate* SGT_CLASSES_TABLE;
extern Symbol* SYM_CLASSES_CLASS_REQUIRED_SLOT_NAMES;
extern Surrogate* SGT_CLASSES_GENERALIZED_SYMBOL;
extern Symbol* SYM_CLASSES_EVALUATOR_WRAPPER_CODE;
extern Taxonomy_Graph* oCLASS_TAXONOMY_GRAPHo;
extern Symbol* SYM_CLASSES_ANY;
extern Surrogate* SGT_CLASSES_ANY;

