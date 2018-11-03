// primal.hh

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
int random(int n);
int min(int x, int y);
int max(int x, int y);
boolean read_OtransientobjectsPO();
boolean write_OtransientobjectsPO(boolean value);
int string_compare(char* x, char* y);
boolean stringL(char* x, char* y);
boolean stringLE(char* x, char* y);
boolean stringGE(char* x, char* y);
boolean stringG(char* x, char* y);
void startup_primal();

// Global declarations:
extern boolean TRUE;
extern boolean FALSE;
extern boolean NULL_BOOLEAN;
extern int NULL_INTEGER;
extern short int NULL_SHORT_INTEGER;
extern long int NULL_LONG_INTEGER;
extern unsigned short int NULL_UNSIGNED_SHORT_INTEGER;
extern unsigned long int NULL_UNSIGNED_LONG_INTEGER;
extern double NULL_FLOAT;
extern float NULL_SINGLE_FLOAT;
extern double NULL_DOUBLE_FLOAT;
extern char NULL_CHARACTER;
extern char NULL_OCTET;
extern Symbol* SYM_PRIMAL_FLOOR;
extern Keyword* KWD_PRIMAL_CPP;
extern Keyword* KWD_PRIMAL_FUNCTION;
extern boolean oTRANSIENTOBJECTSpo;
extern Symbol* SYM_PRIMAL_oTRANSIENTOBJECTSpo;

