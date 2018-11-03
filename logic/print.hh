// print.hh

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
void print_top_level_object(Object* self, ostream* nativestream);
Keyword* read_OprintmodeO();
Keyword* write_OprintmodeO(Keyword* value);
void print_object_name(Object* self, Output_Stream* stream);
void print_logic_object(Logic_Object* self, Output_Stream* stream, boolean toplevelP);
Key_Value_List* read_OskolemnamemappingtableO();
Key_Value_List* write_OskolemnamemappingtableO(Key_Value_List* value);
char* get_skolem_print_name(Skolem* self);
void print_value_of_chain(Skolem* self, Output_Stream* stream, Object* chainend);
void print_value(Object* self, Output_Stream* stream);
void print_skolem(Skolem* self, Output_Stream* stream, boolean toplevelP);
Object* bound_to_in_frame(Pattern_Variable* self, Control_Frame* frame);
Control_Frame* read_OprintinframeO();
Control_Frame* write_OprintinframeO(Control_Frame* value);
void print_variable(Pattern_Variable* self, Output_Stream* stream);
void print_quantified_variable(Pattern_Variable* self, Output_Stream* stream);
void print_proposition(Proposition* self, Output_Stream* stream, boolean toplevelP);
void print_description(Description* self, Output_Stream* stream, boolean toplevelP);
void startup_print();

// Global declarations:
extern Output_Stream* oNON_STANDARD_OUTPUT_STREAM_WRAPPERo;
extern Surrogate* SGT_PRINT_DESCRIPTION;
extern Surrogate* SGT_PRINT_PATTERN_VARIABLE;
extern Surrogate* SGT_PRINT_SKOLEM;
extern Surrogate* SGT_PRINT_LOGIC_OBJECT;
extern Surrogate* SGT_PRINT_PROPOSITION;
extern Keyword* oPRINTMODEo;
extern Keyword* KWD_PRINT_FLAT;
extern Symbol* SYM_PRINT_oPRINTMODEo;
extern Symbol* SYM_PRINT_SURROGATE_VALUE_INVERSE;
extern Surrogate* SGT_PRINT_UNKNOWN;
extern char* VARIABLE_BINDING_SEPARATOR;
extern char* VALUE_OF_SEPARATOR;
extern Key_Value_List* oSKOLEMNAMEMAPPINGTABLEo;
extern Symbol* SYM_PRINT_oSKOLEMNAMEMAPPINGTABLEo;
extern Symbol* SYM_PRINT_SKOLEM_NAME;
extern Keyword* KWD_PRINT_REALISTIC;
extern Keyword* KWD_PRINT_ORIGINAL;
extern Keyword* KWD_PRINT_DEBUG_LOW;
extern Keyword* KWD_PRINT_DEBUG_HIGH;
extern Surrogate* SGT_PRINT_RELATION;
extern Symbol* SYM_PRINT_DESCRIPTION;
extern Control_Frame* oPRINTINFRAMEo;
extern Symbol* SYM_PRINT_oPRINTINFRAMEo;
extern Symbol* SYM_PRINT_DEFINITION;

