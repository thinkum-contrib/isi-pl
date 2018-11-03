/* -*- Mode: C -*- */

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

/* Version: stella-parser.y,v 1.3 1997/08/25 21:05:54 melz Exp */

/* Stella reader/parser implementation using bison. */

     
%{
#include <iostream.h>
#include <fstream.h>
#include <strstream.h>
#include "stella-includes.hh"

#define YYSTYPE Object*


Object* THE_PARSE_TREE = NULL;
boolean END_OF_FILE_P = FALSE;
// Flag which indicates if a sexp has been read.
// If it has, the scanner sends a `false' EOF token to trick the 
//   parser into thinking it is done, so it returns control to the 
//   caller of yyparse()
boolean SEXP_RECOGNIZED_P = FALSE;

/* prototypes for stuff in for yylex, defined in stella-scanner.l */
void reset_scanner();
int yylex();
extern char* INPUT_STRING;
extern istream* CURRENT_STREAM;

void yyerror (char* s)  /* Called by yyparse on error */
{
  static Read_Exception* the_read_exception = new_read_exception();

  cout << ">> Bison Error: " << s << endl;
  signal(the_read_exception);
}


%}
     
%token	INTEGER	
%token	FLOAT	
%token	KEYWORD	
%token	SYMBOL	
%token	SURROGATE	
%token	STRING	
%token	CHARACTER	
%token	NIL_TOKEN	
%token	COMMENT	
%token	LEFT_PAREN
%token	RIGHT_PAREN
%token  END_OF_FILE
%token	ERROR	

%start exp
    
%% /* Grammar rules and actions follow */


exp:      end 
        | sexp 
          { /* cout << "** recognized sexp" << endl;  */
	    SEXP_RECOGNIZED_P = TRUE;
	    THE_PARSE_TREE = $1; }

end:      END_OF_FILE 
          { /* cout << "** recognized END_OF_FILE" << endl; */
	    SEXP_RECOGNIZED_P = TRUE;
            END_OF_FILE_P = TRUE; }         

sexp:     atom
          { /* cout << "** recognized sexp atom" << endl; */
            $$ = $1; }
        | LEFT_PAREN list RIGHT_PAREN 
          { /* cout << "** recognized sexp list" << endl; */
            $$ = $2; }
;

list:     sexp list 
	  {  /* cout << "** consing " << endl; */
             $$ = cons($1, ((Cons*)$2)); }
        | 
	  {  $$ = NIL; }
;

atom:     INTEGER 
          { $$ = $1; }
        | FLOAT
          { $$ = $1; }
        | SYMBOL
          { $$ = $1; }
        | SURROGATE
          { $$ = $1; }
        | KEYWORD
          { $$ = $1; }
        | STRING
          { $$ = $1; }
        | CHARACTER
          { $$ = $1; }
        | COMMENT
          { $$ = $1; }
        | NIL_TOKEN
          { $$ = $1; }
;


%%

#include <ctype.h>
#include <stdio.h>
     
/* given a string, return a stella parse tree */
Object* bison_unstringify(char* string) 
{
  /* cout << "----------------------" << endl; */
  // Set yy debug to 1 to print parsing info.
  // yydebug = 1;
  /* create a string stream with the string and call the parser */
  istrstream* stream = new istrstream(string, strlen(string) + 1);
  istream* prev_current_stream = CURRENT_STREAM;
  CURRENT_STREAM = stream;
  END_OF_FILE_P = FALSE;
  SEXP_RECOGNIZED_P = FALSE;
  yyparse ();
  // restore old stream
  CURRENT_STREAM = prev_current_stream;
  return THE_PARSE_TREE;
}

/* given a file stream, parse and object and return a stella parse tree */
Object* parse_stella_object(istream* stream) {
  istream* prev_current_stream = CURRENT_STREAM;
  CURRENT_STREAM = stream;
  END_OF_FILE_P = FALSE;
  SEXP_RECOGNIZED_P = FALSE;
  yyparse();
  CURRENT_STREAM = prev_current_stream;
  return THE_PARSE_TREE;
}
