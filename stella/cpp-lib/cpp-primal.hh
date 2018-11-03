// -*- Mode: C++ -*-

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

// Version: cpp-primal.hh,v 1.12 1997/12/11 23:42:30 hans Exp

// Native C++ stuff for STELLA


// Currently all useful system libraries are included.  Later, we'll
//   either analyze code or include facilities in modules to specify
//   #includes.
#include <iostream.h>
#include <fstream.h>
#include <strstream.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <setjmp.h>

// Garbage collector declarations
#include "gc.hh"

// Native data structures: vectors, hash tables, etc.
#include "ObjectPtr.Vec.hh"
#include "String.int.VHMap.hh"
#include "String.ObjectPtr.VHMap.hh"
#include "ObjectPtr.ObjectPtr.VHMap.hh"

// Primitive types
typedef int boolean;
typedef int fat_boolean;
typedef int one_bit_boolean;
typedef void* cpp_function_code;
typedef Object* (Object::*cpp_method_code) ();

typedef ObjectPtrVec cpp_vector;
typedef void cpp_hash_table;

class cpp_class {};
class cpp_cons {};  // actually needed to handle 'Lisp_Cons_Iterator'
class cpp_nil {};

// Forward declarations
class Object;
class Vector;
class Stream;

// Parsing stuff
Object* bison_unstringify(char* string);
Object* parse_stella_object(istream* stream);
extern istream* CURRENT_STREAM;
extern boolean END_OF_FILE_P;

// Function signatures:
boolean definedP (void* p); 
boolean definedP (int i);
boolean definedP (double f);
boolean nullP (void* p);
boolean nullP (int i);
boolean nullP (double f);

boolean zeroP(int x);
boolean plusP(int x);
boolean evenP(int x);
boolean oddP(int x);
int mod(int x, int modulo);
int ceiling(int n);
int ceiling(double n);
int floor_(int n);
int floor_(double n); // `double floor(double)' already exists in math.h

int character_code(char c);
char code_character(int i);

boolean string_eqlP(char* x, char* y);
char* make_string(int size, char initialElement);
char* string_concatenate(char* string1, char* string2);
char* permanent_string_upcase(char* string);
char* string_upcase(char* string);
char* string_downcase(char* string);
char* string_capitalize(char* string);
char* string_copy(char* string);
char* string_substitute(char* self, char newchar, char oldchar);
boolean string_memberP(char* self, char character);
char string_nth(char* self, int position);
char string_nth_setter (char* self, char c, int pos);
char* string_rest(char* self);
int string_length(char* self);
int string_position(char* string, char character, int start);
int string_search(char* string, char* substring, int start);
char* string_subsequence(char* string, int start, int end);
char* stringify(Object* expression);
Object* unstringify(char* string);
char* integer_to_string(int i);
char* float_to_string(double f);
int string_to_integer(char* string);
double string_to_float(char* string);

void resize_vector(Vector* self, int size);

void unmake(Object* x);

ostream& get_ostream(Stream* s);
ifstream* open_input_file_stream(char* filename);
ofstream* open_output_file_stream(char* filename);
boolean open_native_streamP(Stream* stream);
boolean close_native_streamP(Stream* stream);
Object* read_s_expression(istream* stream, boolean& return4);
char* read_line(istream* stream, boolean& return4);
char read_character(istream* stream, boolean& return4);
void unread_character(char c, istream* stream);

boolean probe_fileP(char* filename);
int file_write_date(char* filename);
int file_length(char* filename);
void delete_file(char* filename);

class jump_buffer {
public:
  jmp_buf buffer;
  void operator=(const jump_buffer&);
  jump_buffer(void*);
};
// Have to use a macro here, since `setjmp' cannot be called in a
//    function that returns before the jump back occurs:
#define setup_long_jumpP(jb) (setjmp(jb.buffer)?FALSE:TRUE)
void long_jump(jump_buffer&);

void startup_cpp_primal();
