// iterators.hh

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
boolean terminate_destructive_list_iteratorP(Destructive_List_Iterator* self);
boolean filtered_nested_iterator_nextP(All_Purpose_Iterator* self);
boolean iterator_cons_list_nextP(All_Purpose_Iterator* self);
boolean iterator_cons_list_emptyP(All_Purpose_Iterator* self);
boolean filtered_concatenated_iterator_nextP(All_Purpose_Iterator* self);
Integer_Interval_Iterator* interval(int lowerbound, int upperbound);
void initialize_reverse_integer_interval_iterator(Reverse_Integer_Interval_Iterator* self);
Reverse_Integer_Interval_Iterator* reverse_interval(int lowerbound, int upperbound);
boolean vector_nextP(All_Purpose_Iterator* self);
String_Iterator* string_allocate_iterator(char* self);
Cons* yield_modules_list(Module* module, boolean localP);
Iterator* allocate_all_meta_objects_iterator(int arraysize, cpp_function_code nextcode, Module* module, boolean localP);
boolean all_symbols_nextP(All_Purpose_Iterator* self);
Iterator* all_symbols(Module* module, boolean localP);
boolean filter_public_slotP(Slot* self, All_Purpose_Iterator* iterator);
boolean filter_private_slotP(Slot* self, All_Purpose_Iterator* iterator);
boolean filter_method_slotP(Slot* self, All_Purpose_Iterator* iterator);
boolean filter_public_method_slotP(Slot* self, All_Purpose_Iterator* iterator);
boolean filter_non_external_slotP(Slot* self, All_Purpose_Iterator* iterator);
boolean filter_non_parameter_slotP(Slot* self, All_Purpose_Iterator* iterator);
boolean filter_non_auxiliary_slotP(Slot* self, All_Purpose_Iterator* iterator);
boolean filter_slotP(Slot* self, All_Purpose_Iterator* iterator);
boolean all_functions_nextP(All_Purpose_Iterator* self);
Iterator* all_functions(Module* module, boolean localP);
Iterator* all_public_functions(Module* module, boolean localP);
boolean all_variables_nextP(All_Purpose_Iterator* self);
Iterator* all_variables(Module* module, boolean localP);
boolean all_surrogates_nextP(All_Purpose_Iterator* self);
Iterator* all_surrogates(Module* module, boolean localP);
boolean all_classes_nextP(All_Purpose_Iterator* self);
Iterator* all_classes(Module* module, boolean localP);
boolean slots_nextP(All_Purpose_Iterator* self);
Iterator* all_slots(Module* module, boolean localP);
Iterator* all_methods(Module* module, boolean localP);
Iterator* all_public_methods(Module* module, boolean localP);
boolean class_methods_nextP(All_Purpose_Iterator* self);
Iterator* class_methods(Class* renamed_Class, Cons* filters);
Iterator* public_class_methods(Class* renamed_Class);
Iterator* private_class_methods(Class* renamed_Class);
boolean class_storage_slots_nextP(All_Purpose_Iterator* self);
Iterator* class_storage_slots(Class* renamed_Class, Cons* filters);
boolean class_tables_nextP(All_Purpose_Iterator* self);
Iterator* class_tables(Class* renamed_Class, Cons* filters);
Iterator* public_class_storage_slots(Class* renamed_Class);
Iterator* private_class_storage_slots(Class* renamed_Class);
void startup_iterators();

// Global declarations:
extern Surrogate* SGT_ITERATORS_TABLE;

