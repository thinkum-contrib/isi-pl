// cl-translate-file.hh

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
char* cl_make_output_file_name(char* sourcefile);
char* stella_make_output_file_name(char* sourcefile);
boolean auxiliary_variable_unitP(Translation_Unit* unit);
void cl_output_one_unit(Translation_Unit* unit, ostream* stream);
void cl_output_all_units_to_file(char* sourcefile);
void cl_output_file_header(Output_Stream* stream, char* package, boolean copyrightP, boolean ensurepackageP);
void cl_output_forward_declarations(ostream* stream);
void cl_translate_file(char* file);
void cl_translate_stella();
void cl_compile_and_load_file(char* file, int args, ...);
void startup_cl_translate_file();

// Global declarations:
extern char* oCL_TRANSLATED_FILE_SUFFIXo;
extern char* oSTELLA_TRANSLATED_FILE_SUFFIXo;
extern Symbol* SYM_CL_TRANSLATE_FILE_GLOBAL_VARIABLE;
extern Symbol* SYM_CL_TRANSLATE_FILE_CLASS;
extern Keyword* KWD_CL_TRANSLATE_FILE_COMMON_LISP;
extern Keyword* KWD_CL_TRANSLATE_FILE_TRANSLATE;
extern Keyword* KWD_CL_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER;
extern Keyword* KWD_CL_TRANSLATE_FILE_WARN_ABOUT_MISSING_METHODS;
extern Keyword* KWD_CL_TRANSLATE_FILE_WARN_ABOUT_UNDEFINED_METHODS;
extern Keyword* KWD_CL_TRANSLATE_FILE_USE_HARDCODED_SYMBOLS;
extern Symbol* SYM_CL_TRANSLATE_FILE_STARTUP;

