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

/* Version: stella-scanner.l,v 1.5 1997/08/20 00:41:15 hans Exp */

/* Stella scanner implementation using flex. */


%{
/* need this for the call to atof() below */

#include <strings.h>
#include <iostream.h>
#include <fstream.h>
#include "stella-includes.hh"

#define YYSTYPE Object*

#include "stella-parser.tab.h"

istream* CURRENT_STREAM;

int TIMES_READ = 0;
char* INPUT_STRING;


// FROM FLEXDOC MANUAL
const int MAX_STR_CONST = 8192;
char string_buf[MAX_STR_CONST];
char *string_buf_ptr;

// Flag from parser which indicates if a sexp has been read.
// If it has, we send an EOF token to trick the parser into thinking
// it is done, so it returns control to the caller of yyparse()
extern boolean SEXP_RECOGNIZED_P;

/* Input routine get input from a string instead of a stream */
/*
#define YY_INPUT(buf,result,max_size)              \
{                                                  \
  // printf ("input: %s, length = %d, ms = %d\n", INPUT_STRING, strlen(INPUT_STRING), max_size);                                  \
  if (strlen(INPUT_STRING) > max_size) {           \
    printf("*** SCANNER ERROR: line exceeds max length of %d: %s\n", max_size, INPUT_STRING);                                     \
  }                                                \
  else {                                           \
    strcpy(buf,INPUT_STRING);                      \
    if (TIMES_READ++ == 0)                         \
      result = strlen(INPUT_STRING);               \
    else                                           \
      result = 0;                                  \
  }                                                \
}                                                  \
*/


/* input routine to get input from a C++ stream */
#define YY_INPUT(buf,result,max_size)                           \
  buf[0] = '\0';                                                \
  CURRENT_STREAM->get(buf, max_size, '\0');                     \
  if (CURRENT_STREAM->eof() && (strlen(buf) == 0)) {            \
    result = 0;                                                 \
  } else {                                                      \
    result = strlen(buf);                                       \
  }                                                             \

%}

DIGIT    [0-9]
ID       [a-zA-Z0-9\-\_\*\?\&\<\>\=\+\/\:\@\.\!]+

%x stringstate
%x commentstate

%%


"-"{DIGIT}+ {
  stella_lval = integer_wrap_literal(atoi(yytext));
  return INTEGER;
}

{DIGIT}+ {
  stella_lval = integer_wrap_literal(atoi(yytext));
  return INTEGER;
}

"-"{DIGIT}+"."{DIGIT}*        {
  stella_lval = float_wrap_literal((float)atof(yytext));
  return FLOAT;
}

{DIGIT}+"."{DIGIT}*        {
  stella_lval = float_wrap_literal((float)atof(yytext));
  return FLOAT;
}

#\\[Nn][Ee][Ww][Ll][Ii][Nn][Ee] {
  stella_lval = character_wrap_literal('\n');
  return CHARACTER;
}

#\\[Bb][Aa][Cc][Kk][Ss][Pp][Aa][Cc][Ee] {
  stella_lval = character_wrap_literal('\b');
  return CHARACTER;
}

#\\[Tt][Aa][Bb] {
  stella_lval = character_wrap_literal('\t');
  return CHARACTER;
}

#\\[Rr][Ee][Tt][Uu][Rr][Nn] {
  stella_lval = character_wrap_literal('\r');
  return CHARACTER;
}

#\\[Pp][Aa][Gg][Ee] {
  stella_lval = character_wrap_literal('\f');
  return CHARACTER;
}

#\\. {
  stella_lval = character_wrap_literal((char)(yytext[2]));
  return CHARACTER;
}

":"{ID}  {
  char* buf = new (GC) char[strlen(yytext)+1];
  strcpy (buf, yytext);
  stella_lval = intern_keyword(buf+1);     
  /*  cout << "  recognized KEYWORD " << buf << endl; */
  return KEYWORD;
}

"@"{ID}  {
  char* buf = new (GC) char[strlen(yytext)+1];
  strcpy (buf, yytext);
  stella_lval = intern_generalized_symbol(buf);     
  /* cout << "  recognized SURROGATE " << buf << endl; */
  return SURROGATE;
}

"|"{ID}"|"  {
  // Case-sensitive symbol
  // NOTE: This is cheesy, since it does not check for escaped '|'s!
  int nameLength = strlen(yytext) - 2;
  char* buf = new (GC) char[nameLength + 1];
  strncpy (buf, yytext + 1, nameLength);
  buf[nameLength] = '\0';
  stella_lval = intern_generalized_symbol(buf);     
  /* cout << "  recognized case-sensitive SYMBOL " << buf << endl; */
  return SYMBOL;
}

[Cc][Oo][Mm][Mm][Oo][Nn]-[Ll][Ii][Ss][Pp]":"{ID} { 
  // Common lisp symbol
  int prefixLength = strlen("COMMON-LISP:");
  char* buf = new (GC) char[strlen(yytext)+1-prefixLength];
  strcpy (buf, (yytext + prefixLength));
  stella_lval = intern_common_lisp_symbol(buf);
  /* cout << "  recognized SYMBOL " << buf << endl; */
  return SYMBOL;
}

[Cc][Ll]":"{ID}   { 
  // Common lisp symbol
  int prefixLength = strlen("CL:");
  char* buf = new (GC) char[strlen(yytext)+1-prefixLength];
  strcpy (buf, (yytext + prefixLength));
  stella_lval = intern_common_lisp_symbol(permanent_string_upcase(buf));
  /* cout << "  recognized SYMBOL " << buf << endl; */
  return SYMBOL;
}

{ID}              { 
  char* buf = new (GC) char[strlen(yytext)+1];
  strcpy (buf, yytext);
  // NOTE: we ignore packages here, so we can't handle CL: symbols
  stella_lval = intern_generalized_symbol(buf);
  /* cout << "  recognized SYMBOL " << buf << endl; */
  return SYMBOL;
}


\"      string_buf_ptr = string_buf; BEGIN(stringstate);


<stringstate>\"        { /* saw closing quote - all done */
        BEGIN(INITIAL);
        *string_buf_ptr = '\0';
        /* return string constant token type and
         * value to parser
         */
        char* buf = new (GC) char[strlen(string_buf)+1];

        strcpy (buf, string_buf);
        stella_lval = string_wrap_literal(buf);
        /* cout << "  recognized STRING " << buf << endl; */
        return STRING;
        }

<stringstate>\n        {
        /* NOTE: I treat newlines as the case below, instead of errors.
              I think stella might be producing the wrong thing for
              newlines in strings, but for now this works... */
        /* cout << "Error: unterminated string constant " << endl;  */
        *string_buf_ptr++ = '\n';
        }

<stringstate>\\n  *string_buf_ptr++ = '\n';

<stringstate>\\(.|\n)  *string_buf_ptr++ = yytext[1];

<stringstate>[^\\\n\"]+        {
  /* cout << "  recognized string meat = " << yytext << endl; */
        char *p = yytext;

        while ( *p )
                *string_buf_ptr++ = *p++;
        }


"#|"                      {     /* start of comment */
     BEGIN(commentstate);
}
<commentstate>[^|\n]*          /* eat anything that's not a '|' */
<commentstate>"|"+[^|#\n]*     /* eat up '|'s not followed by '#'s */
<commentstate>\n
<commentstate>"|"+"#"     {     /* Saw comment close */
    BEGIN(INITIAL);
}


"("  { 
  stella_lval = NULL;
  return LEFT_PAREN;
}
 
")"  { 
  stella_lval = NULL;
  return RIGHT_PAREN;
}
 
";"[^}\n]*\n  { 
  /* TODO: Implement this, we currently ignore comments */
  // return COMMENT;
}

[ \t\n]+    { 
  /* eat whitespace */
}

.           { 
  stella_lval = NULL;
  printf( "Unrecognized character: %s\n", yytext );
  return ERROR;
}

<<EOF>> {
  return END_OF_FILE;
}

%%

/* NOTE: must include this function */
int yywrap() {
  return 1;
}

char* type_string(int type) 
{
  switch (type) {
    case END_OF_FILE     : return ("END_OF_FILE     ");
    break;
    case INTEGER         : return ("INTEGER         ");
    break;
    case FLOAT           : return ("FLOAT           ");
    break;
    case KEYWORD         : {
      char *str1 = "KEYWORD         , val = (",
           *str2 = ((Keyword*)stella_lval)->symbol_name,
           *str3 = ")";
      int reslen = strlen(str1) + strlen(str2) + strlen(str3) + 1;
      char* res =  new (GC) char[reslen];
      *res = '\0';
      return strcat(strcat(strcat(res, str1), str2), str3);
    }
    break;
    case SURROGATE       : return ("SURROGATE       ");
    break;
    case SYMBOL          : {
      char *str1 = "SYMBOL          , val = (",
           *str2 = ((Symbol*)stella_lval)->symbol_name,
           *str3 = ")";
      int reslen = strlen(str1) + strlen(str2) + strlen(str3) + 1;
      char* res =  new (GC) char[reslen];
      *res = '\0';
      return strcat(strcat(strcat(res, str1), str2), str3);
    }
    break;
    case STRING          : return ("STRING          ");
    break;
    case CHARACTER       : return ("CHARACTER       ");
    break;
    case COMMENT         : return ("COMMENT         ");
    break;
    case LEFT_PAREN      : return ("LEFT_PAREN      ");
    break;
    case RIGHT_PAREN     : return ("RIGHT_PAREN     ");
    break;
  }
}

/* NOTE: NEED TO ADD FOLLOWING LINES INSIDE `void yy_init_buffer( b, file )' */

	/* added initialization  -erm */
/*	for (char* p = b->yy_ch_buf; p < (b->yy_ch_buf + b->yy_buf_size + 2) ; p++)
	  *p = '\0';
*/


// Wrapper function for yylex()
int stella_lex() {
  /* cout << "** IN STELLA LEX" << endl; */
  // NOTE: if the parser has just read an sexp, we return a false EOF token
  if (SEXP_RECOGNIZED_P == TRUE) {  
    /* cout << "** RETURNING FALSE EOF" << endl; */
    return 0;
  }
  else {
    return yylex();
  }
}

void reset_scanner() {
  TIMES_READ = 0;
}

// Test function to test reading from strings (w/string input routine)
void scan_stella_from_string(char* str) 
{
  int type;
  /* copy string into scanner buffer */
  /* NOTE: may be able to do this *without* copying string- i.e., 
       resetting scanner buffer to point to string */
  reset_scanner();
  INPUT_STRING = str;

  /* read tokens until end-of-file occurs (actually, its the end of string) */
  while (type = stella_lex()) {
    printf("type: %s, val = (%s)\n", type_string(type));
  }
}

// Test function to test reading from streams (w/C++ stream input routine)
void scan_stella_from_stream(istream* stream) 
{
  int type;
  CURRENT_STREAM = stream;

  while ((type = stella_lex()) != END_OF_FILE) {
    printf("type: %s, val = (%s)\n", type_string(type));
  }
}

// Test function 
void test_file_stream1() {
  ifstream* s = new ifstream;
  s->open("testscan");
  cout << "---------------------" << endl;
  scan_stella_from_stream(s);
}

void test_file_stream2() {
  ifstream* s = new ifstream;
  s->open("translate-test1.lisp");
  cout << "---------------------" << endl;
  scan_stella_from_stream(s);
}

// Test using string streams
void test_string_stream1() {
  char* str = "(DEFCLASS2 OBJECT2 () :DOCUMENTATION2)  ";
  istrstream* s = new istrstream(str, strlen(str) + 1);
  cout << "---------------------" << endl;
  scan_stella_from_stream(s);
}

