//  -*- Mode: C++ -*-

// powerloom.hh

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997-2003              |
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



namespace logic {
  using namespace stella;

// Global declarations:
extern int oPOWERLOOM_MAJOR_VERSION_NUMBERo;
extern int oPOWERLOOM_MINOR_VERSION_NUMBERo;
extern char* oPOWERLOOM_RELEASE_STATEo;
extern int oPOWERLOOM_PATCH_LEVELo;
extern char* oPOWERLOOM_VERSION_STRINGo;
extern char* oPOWERLOOM_LOCKo;

// Function signatures:
char* powerloomCopyrightHeader();
void copyright();
char* copyrightYears();
void powerloom();
void startupPowerloom();

// Auxiliary global declarations:
extern Symbol* SYM_POWERLOOM_LOGIC_STARTUP_POWERLOOM;
extern Symbol* SYM_POWERLOOM_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
