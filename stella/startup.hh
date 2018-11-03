// startup.hh

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
boolean current_startup_time_phaseP(int phase);
int encode_startup_time_phase(Keyword* phase);
void startup_kernel(boolean verboseP);
void startup_cpp_translator(boolean verboseP);
void startup_java_translator(boolean verboseP);
void startup_idl_translator(boolean verboseP);
void startup(boolean verboseP);
void startup_startup();

// Global declarations:
extern int oSTELLA_MAJOR_VERSION_NUMBERo;
extern int oSTELLA_MINOR_VERSION_NUMBERo;
extern char* oSTELLA_RELEASE_STATEo;
extern int oSTELLA_PATCH_LEVELo;
extern char* oSTELLA_VERSION_STRINGo;
extern List* oSTARTUP_TIME_PHASESo;
extern Keyword* KWD_STARTUP_EARLY_INITS;
extern Keyword* KWD_STARTUP_MODULES;
extern Keyword* KWD_STARTUP_SYMBOLS;
extern Keyword* KWD_STARTUP_QUOTED_CONSTANTS;
extern Keyword* KWD_STARTUP_GLOBALS;
extern Keyword* KWD_STARTUP_CLASSES;
extern Keyword* KWD_STARTUP_FINALIZE_CLASSES;
extern Keyword* KWD_STARTUP_METHODS;
extern Keyword* KWD_STARTUP_FINALIZE_METHODS;
extern Keyword* KWD_STARTUP_FINAL;
extern int oSTARTUP_TIME_PHASEo;

