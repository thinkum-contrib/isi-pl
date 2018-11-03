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

// Version: cpp-primal.cc,v 1.20 1997/12/11 23:43:50 hans Exp

// Native C++ stuff for STELLA


#include "stella-includes.hh"

  //
///// 'null?' and 'defined?':
 //

// NOTE: 'definedP' and 'nullP' really aren't called anymore, since they
//       get translated directly into '==' tests by the C++ translator.

boolean definedP (void* p) {
  if (p)
    return TRUE;
  else
    return FALSE;
}

boolean definedP (int i) {
  if (i == NULL_INTEGER)
    return FALSE;
  else
    return TRUE;
}

boolean definedP (double f) {
  if (f == NULL_FLOAT)
    return FALSE;
  else
    return TRUE;
}

boolean nullP (void* p) {
  if (p)
    return FALSE;
  else
    return TRUE;
}

boolean nullP (int i) {
  if (i == NULL_INTEGER)
    return TRUE;
  else
    return FALSE;
}

boolean nullP (double f) {
  if (f == NULL_FLOAT)
    return TRUE;
  else
    return FALSE;
}

  //
///// Arithmetic functions
 //

boolean zeroP(int x) {
  return !x;
}

boolean plusP(int x) {
  if (x > 0)
    return TRUE;
  else
    return FALSE;
}

boolean evenP(int x) {
  return (!oddP(x));
}

boolean oddP(int x) {
  return (x % 2); 
}

int mod(int x, int modulo) {
  return (x % modulo);
}

int ceiling(int n) {
  return n;
}
int ceiling(double n) {
  return (int) ceil(n);
}

int floor_(int n) {
  return n;
}
// `double floor(double)' already exists in math.h:
int floor_(double n) {
  return (int) floor(n);
}

  //
///// Character library functions
 //

int character_code(char c) {
  return (int)c;
}

char code_character(int i) {
  return (char)i;
}

  //
///// String library functions
 //

// Buffer used by 'integer_to_string', 'stringify', and 'read_line'.
// NOTE: Using a hard upper bound here really needs to be fixed!!

const int STRING_BUFFER_SIZE = 32 * 1024;
char STRING_BUFFER[STRING_BUFFER_SIZE];

boolean string_eqlP(char* x, char* y) {
  if (x == NULL)
    return (y == NULL);
  else
    return (!(y == NULL) && !strcmp (x, y));
}

char* make_string(int size, char initialElement) {
  char* newstring = new (GC) char[size+1];
  for (int i = 0; i< size; i++) {
    newstring[i] = initialElement;
  }
  newstring[size] = '\0';
  return newstring;
}

char* string_concatenate(char* string1, char* string2) {
  char* newstring = new (GC) char[strlen(string1) + strlen(string2) + 1];
  strcpy(newstring, string1);
  strcat(newstring, string2);
  return newstring;
}

char* permanent_string_upcase(char* string) {
  // Q: whats the difference between permanent and non permanent strings?
  return string_upcase(string);
}

char* string_upcase(char* string) {
  // Return an upper-case copy of 'string'.
  char* newstring = new (GC) char[strlen(string) + 1];
  strcpy(newstring, string);
  int offset = ('a' - 'A');
  for (char* p = newstring; *p != '\0'; p++)
    if (islower(*p))
      *p = *p - offset;
  return newstring;
}

char* string_downcase(char* string) {
  // Return a lower-case copy of 'string'.
  char* newstring = new (GC) char[strlen(string) + 1];
  strcpy(newstring, string);
  int offset = ('A' - 'a');
  for (char* p = newstring; *p != '\0'; p++)
    if (isupper(*p))
      *p = *p - offset;
  return newstring;
}

char* string_capitalize(char* string) {
  // Return a capitalized version of 'string'.
  // Upcase first character and characters after non-alphanumeric characters.
  char* newstring = string_downcase(string);
  int offset = ('a' - 'A');
  int capitalizeFlag = TRUE;
  for (char* p = newstring; *p != '\0'; p++) {
    if ((capitalizeFlag) && (isalpha(*p))) {
      *p = *p - offset;
      capitalizeFlag = FALSE;
    }
    if (!isalpha(*p)) {
      capitalizeFlag = TRUE;
    }
  }
  return newstring;
}

char* string_copy(char* string) {
  char* newstring = new (GC) char[strlen(string) + 1];
  strcpy(newstring, string);
  return newstring;
}

char* string_substitute(char* self, char newchar, char oldchar) {
  char* newstring = string_copy(self);
  for (char* p = newstring; *p != '\0'; p++)
    if (*p == oldchar)
      *p = newchar;
  return newstring;
}

boolean string_memberP(char* self, char character) {
  for (char* p = self; *p != '\0'; p++)
    if (*p == character)
      return TRUE;
  return FALSE;
}

char string_nth(char* self, int position) {
  return self[position];
}

char string_nth_setter (char* self, char c, int pos) {
  return (self[pos] = c);
}

char* string_rest(char* self) {
  // Return pointer to second character.
  return self+1;
}

int string_length(char* self) {
  return strlen(self);
}

int string_position(char* string, char character, int start) {
  // Return the position of 'character' within 'string' (counting
  // from zero), or return NULL if 'character' does not occur within 'string'.

  int i = start;
  int string_length = strlen(string);
  for (; i < string_length; i++) {
    if (string[i] == character) {
      return i;
    }
  }
  return NULL_INTEGER;
}

int string_search(char* string, char* substring, int start) {
  // Return start position of the left-most occurrence right of
  // 'start' of 'substring' in 'string'.  Return NULL if it is not 
  // a substring.
  int begin, end;

  begin = start;
  int stringLength = strlen(string);
  if (stringLength < (strlen(substring) + begin))
    return NULL_INTEGER;

  char* newstring = string_copy(string);
  for (end = (strlen(substring) + begin); end <= stringLength;
       begin++, end++) {
    char savedEndChar = string[end];
    // Temporarily truncate string to the same size of substring
    newstring[end] = '\0';
    if (!strcmp((newstring + begin), substring)) {
      return begin;
    }
    newstring[end] = savedEndChar;
  }
  return NULL_INTEGER;
}

char* string_subsequence(char* string, int start, int end) {
  // Return a substring of 'string' beginning at position 'start'
  // and ending up to but not including position 'end', counting from zero.  
  // An 'end' value of NULL stands for the rest of the string.

  int i, j;
  if (end == NULL_INTEGER) 
    end = strlen(string);
  char* newstring = new (GC) char[end-start + 1];
  for(i = 0, j = start; j < end; i++, j++)
    newstring[i] = string[j];
  newstring[i] = '\0';
  return newstring;
}

//  Converting to and from string representations:

char* stringify(Object* expression) {
  ostrstream s(STRING_BUFFER, STRING_BUFFER_SIZE);
  boolean old_printreadablyp = oPRINTREADABLYpo;
  oPRINTREADABLYpo = TRUE;
  boolean old_printprettyp = oPRINTPRETTYpo;
  oPRINTPRETTYpo = FALSE;
  s << expression;
  s << '\0';
  char* newstring = new (GC) char[strlen(STRING_BUFFER)+1];
  strcpy(newstring, STRING_BUFFER);
  oPRINTREADABLYpo = old_printreadablyp;
  oPRINTPRETTYpo = old_printprettyp;
  return newstring;
}

Object* unstringify(char* string) {
  boolean old_transientobjectsp = oTRANSIENTOBJECTSpo;
  oTRANSIENTOBJECTSpo = TRUE;
  Object* tree = bison_unstringify(string);
  oTRANSIENTOBJECTSpo = old_transientobjectsp;
  return tree;
}

char* integer_to_string(int i) {
  ostrstream s(STRING_BUFFER, STRING_BUFFER_SIZE);
  s << i;
  s << '\0';
  char* newstring = new (GC) char[strlen(STRING_BUFFER)+1];
  strcpy(newstring, STRING_BUFFER);
  return newstring;
}

char* float_to_string(double f) {
  ostrstream s(STRING_BUFFER, STRING_BUFFER_SIZE);
  s << f;
  s << '\0';
  char* newstring = new (GC) char[strlen(STRING_BUFFER)+1];
  strcpy(newstring, STRING_BUFFER);
  return newstring;
}

int string_to_integer(char* string) {
  istrstream s(string);
  int result;
  s >> result;
  return result;
}

double string_to_float(char* string) {
  istrstream s(string);
  double result;
  s >> result;
  return result;
}

  //
///// Hash tables
 //

// NOTE: This really should be Hash_Table::initialize_hash_table(), and
//   Abstract_Hash_Table::initialize_hash_table() should be empty!

void Abstract_Hash_Table::initialize_hash_table() {
  this->the_hash_table =
    ((cpp_hash_table*)(new (GC) ObjectPtrObjectPtrVHMap(NULL)));
}

void Abstract_Hash_Table::free_hash_table_values() {
  cout << "WARNING: free_hash_table_values not yet implemented" << endl;
  return;
}

// --------- Objects to Objects ------------

Object* Hash_Table::lookup(Object* key) {
  return ((*((ObjectPtrObjectPtrVHMap*)(this->the_hash_table)))[key]);
}

void Hash_Table::insert_at(Object* key, Object* value) {
  (*((ObjectPtrObjectPtrVHMap*)(this->the_hash_table)))[key] = value;
}

void Hash_Table::remove_at(Object* key) {
  (*((ObjectPtrObjectPtrVHMap*)(this->the_hash_table)))[key] = NULL;
  return;
}

// --------- Integers to Objects ------------

Object* Integer_Hash_Table::lookup(int key) {
  cout << "ERROR: 'Integer_Hash_Table::lookup' not yet implemented" << endl;
  exit(1);
  return NULL;
}

void Integer_Hash_Table::insert_at(int key, Object* value) {
  cout << "ERROR: 'Integer_Hash_Table::insert_at' not yet implemented" << endl;
  exit(1);
}

// --------- Floats to Objects ------------

Object* Float_Hash_Table::lookup(double key) {
  cout << "ERROR: 'Float_Hash_Table::lookup' not yet implemented" << endl;
  exit(1);
  return NULL;
}

void Float_Hash_Table::insert_at(double key, Object* value) {
  cout << "ERROR: 'Float_Hash_Table::insert_at' not yet implemented" << endl;
  exit(1);
}

// --------- Strings to Objects ------------

void String_Hash_Table::initialize_hash_table() {
  this->the_hash_table =
    ((cpp_hash_table*)(new (GC) StringObjectPtrVHMap(NULL)));
  return;
}

Object* String_Hash_Table::lookup(char* key) {
  return ((*((StringObjectPtrVHMap*)(this->the_hash_table)))[key]);
}

void String_Hash_Table::insert_at(char* key, Object* value) {
  (*((StringObjectPtrVHMap*)(this->the_hash_table)))[key] = value;
  return;
}

void String_Hash_Table::remove_at(char* key) {
  ((StringObjectPtrVHMap*)this->the_hash_table)->del(key);
}

// --------- Strings to Integers ------------

void String_To_Integer_Hash_Table::initialize_hash_table() {
  this->the_hash_table =
    ((cpp_hash_table*)new (GC) StringintVHMap(NULL_INTEGER));
  return;
}

void String_To_Integer_Hash_Table::insert_at(char* key, int value) {
  (*((StringintVHMap*)(this->the_hash_table)))[key] = value;
  return;
}

int String_To_Integer_Hash_Table::lookup(char* key) {
  return ((*((StringintVHMap*)(this->the_hash_table)))[key]);
}

void String_To_Integer_Hash_Table::remove_at(char* key) {
  ((StringintVHMap*)this->the_hash_table)->del(key);
}

  //
///// Vectors, extensible vectors, and vector sequences
 //

void Vector::initialize_vector() {
  this->the_array = new (GC) ObjectPtrVec(this->array_size);
  // NOTE: Must initialize all elements so that ObjectCenter doesn't
  //   complain about uninitialized values when resizing
  for (int i = 0; i < this->array_size; i++) {
    // For now do it directly, since otherwise we get too many prints during
    //   initialization
    (*(this->the_array))[i] = (Object*)NULL;
    // this->insert_at(i, (Object*)NULL);
  }
}

Object* Vector::first() {
  return (*(this->the_array))[0];
}

Object* Vector::nth(int offset) {
  return (*(this->the_array))[offset];
}

Object* Vector::nth_setter(Object* value, int offset) {
  (*(this->the_array))[offset] = value;
  return (value);
}

int Vector::length() {
  return (this->array_size);
}

boolean Vector::memberP(Object* object) {
  cpp_vector array = *(this->the_array);
  int array_size = this->array_size;
  
  for (int i = 0; i < array_size; i++)
    if (eqlP(array[i], object))
      return (TRUE);
  return (FALSE);
}

void Vector::insert_at(int offset, Object* value) {
  if (offset >= this->array_size) {
    cerr << "Out-of-bounds array access";
  }
  (*(this->the_array))[offset] = value;
}

void resize_vector(Vector* self, int size) {
  int oldsize = self->array_size;
  self->the_array->resize(size);
  self->array_size = size;
  // Initialize new indices: this is necessary for objectcenter
  for (int i = oldsize; i < size; i++) {
    // For now do it directly, since otherwise we get too  many prints during
    //   initialization
    (*(self->the_array))[i] = (Object*)NULL;
    //self->insert_at(i, (Object*)NULL);
  }
}

void Vector::clear() {
  for (int i = 0; i < this->array_size; i++) {
    (*(this->the_array))[i] = (Object*)NULL;
  }
}

void Extensible_Vector::insert_at(int offset, Object* value) {
  if (offset >= this->array_size) {
    int size;
    for (size = this->array_size * 2; offset >= size; size *= 2);
    resize_vector(this, size);
  }
  (*(this->the_array))[offset] = value;
}

void Extensible_Symbol_Array::insert_at(int offset, Object* value) {
  if (offset >= this->array_size) {
    int size;
    for (size = this->array_size * 2; offset >= size; size *= 2);
    resize_vector(this, size);
  }
  (*(this->the_array))[offset] = value;
  if (offset > this->top_symbol_offset)
    this->top_symbol_offset = offset;
}

void Vector_Sequence::insert(Object* value) {
  { int oldlength = this->sequence_length;

    cout << "WARNING: 'Vector_Sequence::insert' not yet tested" << endl;

    if (oldlength == this->array_size) {
      resize_vector(this, this->array_size + this->resize_increment_reader());
    }
    (*(this->the_array))[oldlength] = value;
    this->sequence_length = 1 + oldlength;
  }
}

Abstract_Collection* Vector_Sequence::remove(Object* value) {
  { cpp_vector* array = this->the_array;
    int firstshiftoffset = -1;
    int lastshiftoffset = this->sequence_length - 1;

    for (int i = 0; i <= lastshiftoffset; i++) {
      if ((*array)[i] == value) {
        firstshiftoffset = i + 1;
        break;
      }
    }
    if (firstshiftoffset == -1) {
      return (this);
    }
    if (firstshiftoffset <= lastshiftoffset) {
      for (int j = firstshiftoffset; j <= lastshiftoffset; j++) {
        (*array)[j-1] = (*array)[j];
      }
    }
    (*array)[lastshiftoffset] = NULL;
    this->sequence_length = lastshiftoffset;
    return (this);
  }
}

  //
///// Object destruction
 //

void unmake(Object* x) {
  // delete x;
}

  //
///// Stream operations
 //

Surrogate* sgt_STELLA_OUTPUT_STREAM = NULL;
Surrogate* sgt_STELLA_INPUT_FILE_STREAM = NULL;
Surrogate* sgt_STELLA_OUTPUT_FILE_STREAM = NULL;

ostream& get_ostream(Stream* s) {
  // return a reference to a stream based on s's type.
  // NOTE: This is horribly ugly, but necessary because overriden
  //   slots in C++ classes (i.e. native_stream slots in stella Stream 
  //   classes in this case) are allocated separately and their base
  //   class must be explicitly cast in order to retrieve the appropriate 
  //   slot.
  // TODO: Add other stream types, e.g. input and string streams

  if (s->primary_type() == sgt_STELLA_OUTPUT_STREAM) {
    return *(((Output_Stream*)s)->native_stream);
  }
  else if (s->primary_type() == sgt_STELLA_OUTPUT_FILE_STREAM) {
    return *(((Output_File_Stream*)s)->native_stream);
  }
  else {
    cerr << "** ERROR: get_stream does not know stream type ";
    cerr << s->primary_type() << endl;
  }
}

ifstream* open_input_file_stream(char* filename) {
  return (new (GC) ifstream(filename));
}

ofstream* open_output_file_stream(char* filename) {
  return (new (GC) ofstream(filename));
}

boolean open_native_streamP(Stream* stream) {

  if (isaP(stream, sgt_STELLA_INPUT_FILE_STREAM)) {
    ((Input_File_Stream*)stream)->native_stream = 
      open_input_file_stream(((Input_File_Stream*)stream)->filename);
    return TRUE;
  }
  else if (isaP(stream, sgt_STELLA_OUTPUT_FILE_STREAM)) {
    ((Output_File_Stream*)stream)->native_stream = 
      open_output_file_stream(((Output_File_Stream*)stream)->filename);
    return TRUE;
  }
  else {
    cerr << "*** UNKNOWN STREAM TYPE:" << stream->primary_type() << endl;
    return FALSE;
  }
}

boolean close_native_streamP(Stream* stream) {
  if (isaP(stream, sgt_STELLA_INPUT_FILE_STREAM)) {
      delete ((Input_File_Stream*)stream)->native_stream;
    return TRUE;
  }
  else if (isaP(stream, sgt_STELLA_OUTPUT_FILE_STREAM)) {
      delete ((Output_File_Stream*)stream)->native_stream;
    return TRUE;
  }
  else {
    cerr << "*** UNKNOWN STREAM TYPE:" << stream->primary_type() << endl;
    return FALSE;
  }

  return TRUE;
}

Object* read_s_expression(istream* stream, boolean& return4) {
  // Read an object from a stream.  
  Object* result;

  boolean old_transientobjectsp = oTRANSIENTOBJECTSpo;
  oTRANSIENTOBJECTSpo = TRUE;
  result = parse_stella_object(stream);
  return4 = END_OF_FILE_P;
  oTRANSIENTOBJECTSpo = old_transientobjectsp;
  return result;
}

char* read_line(istream* stream, boolean& eofP) {
  // probe for eof
  char c;
  stream->get(c);
  eofP = ((stream->rdstate()) & ios::eofbit);
  if (eofP) 
    return "";
  stream->putback(c);

  stream->get(STRING_BUFFER, STRING_BUFFER_SIZE, '\n');
  char* result = new (GC) char[strlen(STRING_BUFFER) + 1];
  strcpy(result, STRING_BUFFER);

  // Eat newline (or EOF)
  stream->get(c);

  return result;
}

char read_character(istream* stream, boolean& eofP) {
  // Q: Should this go after the read?  - I don't think so
  // probe for eof
  char c;
  stream->get(c);
  eofP = ((stream->rdstate()) & ios::eofbit);
  if (eofP) 
    return '\0';

  stream->putback(c);
  stream->get(c);

  return c;
}

void unread_character(char c, istream* stream) {
  stream->putback(c);
}

  //
///// File operations
 //

boolean probe_fileP(char* filename) {
  ifstream fStream(filename);
  if (fStream.bad())
    return FALSE;
  else
    return TRUE;
}

int file_write_date(char* filename) {
  // Don't yet know how to handle this (will be OS-specific):
  // NOTE: Using 'int' to store times might not be sufficient!!
  // cout << "WARNING: 'file_write_date' not yet implemented" << endl;
  return (NULL_INTEGER);
}

int file_length(char* filename) {
  // NOTE: Using 'int' to store sizes might not be sufficient!!
  ifstream fStream(filename);
  if (fStream.bad()) {
    cerr << "ERROR in 'file_length': File '"
         << filename << "' does not exist!" << endl;
    exit(1);
  }
  else {
    fStream.seekg(0, ios::end);
    return (fStream.tellg());
  }
}

void delete_file(char* filename) {
  ofstream fStream(filename);
  if (fStream.bad()) {
    cerr << "ERROR in 'delete_file': File '"
         << filename << "' does not exist!" << endl;
    exit(1);
  }
  else {
    // Don't yet know how to delete files (will be OS-specific):
    cout << "ERROR: 'delete_file' not yet implemented" << endl;
    exit(1);
  }
}

  //
///// Exception-handling support
 //

// C++ support to handle the pesky 'jmp_buf's (they are arrays which
//     makes them unassignable with '=', which in turn screws up
//     initialization as well as special unbinding).

void jump_buffer::operator=(const jump_buffer& jb) {
  // Handles 'jump_buffer' assignment (necessary for special unbinding).
  for (int i = 0; i< _JBLEN; i++) // most probably OS-specific!
    buffer[i] = jb.buffer[i];
}

jump_buffer::jump_buffer(void* jb) {
  // Handles 'jump_buffer' initialization with NULL.
}

// Have to use a macro instead, since `setjmp' cannot be called in a
//    function that returns before the jump back occurs:
// boolean setup_long_jumpP(jump_buffer& jb) {
//   // Setup the jump buffer 'jb'.  Return TRUE if it really was
//   //    an initial setup, FALSE otherwise.
//   if (setjmp(jb.buffer))
//     return FALSE;
//   else
//     return TRUE;
// }

void long_jump(jump_buffer& jb) {
  // Perform a long jump to the address stored in the jump buffer 'jb'.
  longjmp(jb.buffer, 1);
}

  //
///// Startup
 //

void startup_cpp_primal() {
  // Do this one phase after :symbols, so we'll be sure everything is ready:
  if (current_startup_time_phaseP(3)) {
    sgt_STELLA_OUTPUT_STREAM =
      (Surrogate*) intern_generalized_symbol("/STELLA/@OUTPUT-STREAM");
    sgt_STELLA_INPUT_FILE_STREAM =
      (Surrogate*) intern_generalized_symbol("/STELLA/@INPUT-FILE-STREAM");
    sgt_STELLA_OUTPUT_FILE_STREAM =
      (Surrogate*) intern_generalized_symbol("/STELLA/@OUTPUT-FILE-STREAM");
  }
}

  //
///// Dummy implementations for methods on non-C++ or abstract classes:
 //

boolean Lisp_Cons_Iterator::nextP() {
  // This can never be called.
  return FALSE;
}

int Null_Terminated_Array::length() {
  cout << "WARNING: 'Null_Terminated_Array::length' not yet implemented"
       << endl;
  return 0;
}
