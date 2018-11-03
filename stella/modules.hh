// modules.hh

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
Context* compute_context_or_module_from_pathname(char* pathname, boolean moduleP, boolean symbolnameP, int& return1);
boolean component_matchP(char* component, char* string, int start, int end);
Module* compute_module_and_bare_name(char* name, char*& return1);
Generalized_Symbol* intern_qualified_name(char* name);
Context* get_context(char* pathname, boolean warnP);
Module* string_scan_for_module(char* name, Module* vantagepoint);
Module* string_get_module(char* pathname, boolean warnP);
char* coerce_to_module_name(Object* namespec, boolean warnP);
Module* coerce_to_module(Object* object, boolean warnP);
Module* find_or_create_module(char* pathname);
Module* change_current_module(Module* module);
Context* change_current_context(Context* context);
Context* string_change_context(char* contextname);
Module* string_change_module(char* modulename);
void normalize_parent_modules(Module* self);
void inherit_supercontexts(Module* module);
void uninherit_supercontexts(Module* module);
void inherit_used_modules(Module* module);
void uninherit_used_modules(Module* module);
Cons* read_OshadowedsurrogatesO();
Cons* write_OshadowedsurrogatesO(Cons* value);
void finalize_module(Module* self);
void finalize_world(World* self);
void destroy_module(Module* self);
void destroy_world(World* self);
void string_destroy_context(char* self);
void link_to_parent_module(Module* self, Module* parent, boolean insert_firstP);
void incorporate_module_name(Module* module, char* name);
void incorporate_includes_modules(Module* module, Object* includees);
void incorporate_uses_modules(Module* module, Object* usees);
void incorporate_module_options(Module* self, Cons* options);
void undefine_module(Module* oldmodule, Module* newmodule);
Module* define_module(char* name, Cons* options);
Module* define_module_from_stringified_source(char* name, char* stringifiedoptions);
Cons* yield_define_module(Module* module);
void defmodule(Object* name, Cons* options);
void defmodule_evaluator_wrapper(Cons* arguments);
World* create_world(Context* parentcontext, char* name);
World* push_world();
Context* pop_world();
All_Purpose_Iterator* all_subcontexts(Context* context, Keyword* traversal);
boolean all_subcontexts_nextP(All_Purpose_Iterator* self);
Iterator* all_contexts();
boolean filter_moduleP(Object* self, All_Purpose_Iterator* iterator);
Iterator* all_modules();
Iterator* visible_modules(Module* from);
boolean cardinal_moduleP(Module* self);
boolean visible_fromP(Module* viewedmodule, Module* frommodule);
void clear_one_context(Context* self);
void clear_context(Context* self);
void clear_module(Cons* name);
void clear_module_evaluator_wrapper(Cons* arguments);
void startup_modules();

// Global declarations:
extern Keyword* oSUBCONTEXT_REVISION_POLICYo;
extern Keyword* KWD_MODULES_DESTROY;
extern Surrogate* SGT_MODULES_MODULE;
extern Symbol* SYM_MODULES_NAME;
extern Cons* oSHADOWEDSURROGATESo;
extern Symbol* SYM_MODULES_oSHADOWEDSURROGATESo;
extern Symbol* SYM_MODULES_SHADOWED_SURROGATES;
extern Keyword* KWD_MODULES_INCLUDES;
extern Keyword* KWD_MODULES_USES;
extern Keyword* KWD_MODULES_SHADOW;
extern Keyword* KWD_MODULES_DOCUMENTATION;
extern Keyword* KWD_MODULES_CASE_SENSITIVEp;
extern Symbol* SYM_MODULES_TRUE;
extern Keyword* KWD_MODULES_PACKAGE;
extern Keyword* KWD_MODULES_REQUIRES;
extern Keyword* KWD_MODULES_DIRECTORY_FILE;
extern Keyword* KWD_MODULES_CODE_FILES;
extern Keyword* KWD_MODULES_DEFINITIONS_FILE;
extern Keyword* KWD_MODULES_PRESERVE;
extern Keyword* KWD_MODULES_CLEAR;
extern Keyword* KWD_MODULES_PREORDER;
extern Surrogate* SGT_MODULES_WORLD;
extern Symbol* SYM_MODULES_DEFINE_MODULE_FROM_STRINGIFIED_SOURCE;
extern Symbol* SYM_MODULES_EVALUATOR_WRAPPER_CODE;
extern Symbol* SYM_MODULES_WORLD_NAME;
extern Keyword* KWD_MODULES_POSTORDER;
extern Keyword* KWD_MODULES_INORDER;
extern Symbol* SYM_MODULES_CLEARABLEp;

