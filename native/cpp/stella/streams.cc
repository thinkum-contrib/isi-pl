//  -*- Mode: C++ -*-

// streams.cc

/*--------------------------- BEGIN LICENSE BLOCK ---------------------------+
|                                                                            |
| Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          |
|                                                                            |
| The contents of this file are subject to the Mozilla Public License        |
| Version 1.1 (the "License"); you may not use this file except in           |
| compliance with the License. You may obtain a copy of the License at       |
| http://www.mozilla.org/MPL/                                                |
|                                                                            |
| Software distributed under the License is distributed on an "AS IS" basis, |
| WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   |
| for the specific language governing rights and limitations under the       |
| License.                                                                   |
|                                                                            |
| The Original Code is the STELLA Programming Language.                      |
|                                                                            |
| The Initial Developer of the Original Code is                              |
| UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
| 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
|                                                                            |
| Portions created by the Initial Developer are Copyright (C) 1996-2003      |
| the Initial Developer. All Rights Reserved.                                |
|                                                                            |
| Contributor(s):                                                            |
|                                                                            |
| Alternatively, the contents of this file may be used under the terms of    |
| either the GNU General Public License Version 2 or later (the "GPL"), or   |
| the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   |
| in which case the provisions of the GPL or the LGPL are applicable instead |
| of those above. If you wish to allow use of your version of this file only |
| under the terms of either the GPL or the LGPL, and not to allow others to  |
| use your version of this file under the terms of the MPL, indicate your    |
| decision by deleting the provisions above and replace them with the notice |
| and other provisions required by the GPL or the LGPL. If you do not delete |
| the provisions above, a recipient may use your version of this file under  |
| the terms of any one of the MPL, the GPL or the LGPL.                      |
|                                                                            |
+---------------------------- END LICENSE BLOCK ----------------------------*/

#include "stella/stella-system.hh"

namespace stella {

// Generates a newline character when passed to a stream.
Symbol* EOL = NULL;

// A string constant containing the character sequence
// necessary to generate a newline.
char* EOL_STRING = "\n";

// Denotes the standard input stream for the host language.
InputStream* STANDARD_INPUT = NULL;

// Denotes the standard output stream for the host language.
OutputStream* STANDARD_OUTPUT = NULL;

// Denotes the standard warning stream for the host language.
OutputStream* STANDARD_WARNING = NULL;

// Denotes the standard error stream for the host language.
OutputStream* STANDARD_ERROR = NULL;

// If `true' all passes of a translation will always be performed
// regardless of whether any errors were encountered.  Otherwise, translation
// ends with the first pass that encountered an error.
DEFINE_STELLA_SPECIAL(oIGNORETRANSLATIONERRORSpo, boolean , FALSE);

// Holds a string containing the single quote character.
StringWrapper* SINGLE_QUOTE_STRING = NULL;

// Holds a string containing the single backquote character.
StringWrapper* SINGLE_BQUOTE_STRING = NULL;

Cons* formatMessageArguments(Cons* messageargumentstree, boolean trailingeolP) {
  { Cons* augmentedarguments = NIL;

    { Object* item = NULL;
      Cons* iter000 = messageargumentstree;

      while (!(iter000 == NIL)) {
        item = iter000->value;
        iter000 = iter000->rest;
        if (stringP(item) ||
            (item == EOL)) {
          augmentedarguments = cons(item, augmentedarguments);
        }
        else {
          augmentedarguments = cons(SINGLE_BQUOTE_STRING, augmentedarguments);
          augmentedarguments = cons(item, augmentedarguments);
          augmentedarguments = cons(SINGLE_QUOTE_STRING, augmentedarguments);
        }
      }
    }
    if (trailingeolP) {
      augmentedarguments = cons(EOL, augmentedarguments);
    }
    return (augmentedarguments->reverse());
  }
}

Object* print(Cons* body) {
  // Print arguments to the standard output stream.
  return (listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, SYM_STREAMS_STELLA_STANDARD_OUTPUT, body->concatenate(NIL, 0)));
}

Object* printSpaces(Cons* body) {
  // (print-spaces [stream] N) prints N spaces onto stream.  If
  // no stream form is provided, then STANDARD-OUTPUT will be used.
  if (body->rest == NIL) {
    return (listO(8, SYM_STREAMS_STELLA_FOREACH, SYM_STREAMS_STELLA_I, SYM_STREAMS_STELLA_IN, listO(4, SYM_STREAMS_STELLA_INTERVAL, wrapInteger(1), body->value, NIL), SYM_STREAMS_STELLA_DO, listO(3, SYM_STREAMS_STELLA_IGNORE, SYM_STREAMS_STELLA_I, NIL), listO(4, SYM_STREAMS_STELLA_PRINT_STREAM, SYM_STREAMS_STELLA_STANDARD_OUTPUT, wrapString(" "), NIL), NIL));
  }
  else {
    return (listO(8, SYM_STREAMS_STELLA_FOREACH, SYM_STREAMS_STELLA_I, SYM_STREAMS_STELLA_IN, listO(4, SYM_STREAMS_STELLA_INTERVAL, wrapInteger(1), body->rest->value, NIL), SYM_STREAMS_STELLA_DO, listO(3, SYM_STREAMS_STELLA_IGNORE, SYM_STREAMS_STELLA_I, NIL), listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, body->value, cons(wrapString(" "), NIL)), NIL));
  }
}

Object* inform(Cons* body) {
  // Print informative message, placing non-string arguments in quotes,
  // and terminating with a newline.
  body = formatMessageArguments(body, TRUE);
  return (listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, SYM_STREAMS_STELLA_STANDARD_OUTPUT, body->concatenate(NIL, 0)));
}

Object* warn(Cons* body) {
  // Signal warning message, placing non-string arguments in quotes.
  body = formatMessageArguments(body, FALSE);
  if (oTRANSLATOROUTPUTLANGUAGEo.get() == KWD_STREAMS_COMMON_LISP) {
    return (listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, KWD_STREAMS_WARN, body->concatenate(NIL, 0)));
  }
  else {
    return (listO(4, SYM_STREAMS_STELLA_PRINT_STREAM, SYM_STREAMS_STELLA_STANDARD_WARNING, wrapString("Warning: "), body->concatenate(cons(SYM_STREAMS_STELLA_EOL, NIL), 0)));
  }
}

Object* signal(Symbol* type, Cons* body) {
  // Signal error message, placing non-string arguments in quotes.
  if (type == SYM_STREAMS_STELLA_NULL) {
    type = SYM_STREAMS_STELLA_STELLA_EXCEPTION;
  }
  if ((body->length() == 1) &&
      isaP(body->value, SGT_STREAMS_STELLA_STRING_WRAPPER)) {
    return (listO(3, SYM_STREAMS_STELLA_SIGNAL_EXCEPTION, listO(3, SYM_STREAMS_STELLA_NEW, type, listO(3, KWD_STREAMS_MESSAGE, body->value, NIL)), NIL));
  }
  else {
    { Symbol* streamvar = localGensym("STREAM");

      return (listO(5, SYM_STREAMS_STELLA_LET, cons(cons(streamvar, cons(listO(3, SYM_STREAMS_STELLA_NEW, SYM_STREAMS_STELLA_OUTPUT_STRING_STREAM, NIL), NIL)), NIL), listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, streamvar, formatMessageArguments(body, FALSE)->concatenate(NIL, 0)), listO(3, SYM_STREAMS_STELLA_SIGNAL_EXCEPTION, listO(3, SYM_STREAMS_STELLA_NEW, type, listO(3, KWD_STREAMS_MESSAGE, listO(3, SYM_STREAMS_STELLA_THE_STRING, streamvar, NIL), NIL)), NIL), NIL));
    }
  }
}

Object* error(Cons* body) {
  // Signal error message, placing non-string arguments in quotes.
  return (listO(3, SYM_STREAMS_STELLA_SIGNAL, SYM_STREAMS_STELLA_STELLA_EXCEPTION, body->concatenate(NIL, 0)));
}

Object* continuableError(Cons* body) {
  // Signal error message, placing non-string arguments in quotes.
  body = formatMessageArguments(body, FALSE);
  if (oTRANSLATOROUTPUTLANGUAGEo.get() == KWD_STREAMS_JAVA) {
    if ((body->length() == 1) &&
        isaP(body->value, SGT_STREAMS_STELLA_STRING_WRAPPER)) {
      return (listO(4, SYM_STREAMS_STELLA_LET, cons(listO(3, SYM_STREAMS_STELLA_ERROR_MESSAGE_, wrapString(((StringWrapper*)(body->value))->wrapperValue), NIL), NIL), listO(4, SYM_STREAMS_STELLA_VERBATIM, KWD_STREAMS_JAVA, wrapString("Native.continuableError(error_message_)"), NIL), NIL));
    }
    else {
      { Symbol* streamvar = localGensym("STREAM");

        return (listO(5, SYM_STREAMS_STELLA_LET, cons(cons(streamvar, cons(listO(3, SYM_STREAMS_STELLA_NEW, SYM_STREAMS_STELLA_OUTPUT_STRING_STREAM, NIL), NIL)), NIL), listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, streamvar, formatMessageArguments(body, FALSE)->concatenate(NIL, 0)), listO(4, SYM_STREAMS_STELLA_LET, cons(listO(3, SYM_STREAMS_STELLA_ERROR_MESSAGE_, listO(3, SYM_STREAMS_STELLA_THE_STRING, streamvar, NIL), NIL), NIL), listO(4, SYM_STREAMS_STELLA_VERBATIM, KWD_STREAMS_JAVA, wrapString("Native.continuableError(error_message_)"), NIL), NIL), NIL));
      }
    }
  }
  else {
    return (listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, KWD_STREAMS_CONTINUABLE_ERROR, body->concatenate(NIL, 0)));
  }
}

Object* signalReadError(Cons* body) {
  // Specialized version of `signal' that throws a READ-EXCEPTION.
  return (listO(3, SYM_STREAMS_STELLA_SIGNAL, SYM_STREAMS_STELLA_READ_EXCEPTION, body->concatenate(NIL, 0)));
}

Cons* formatWalkMessageArguments(Cons* messageargumentstree) {
  { ConsIterator* it = messageargumentstree->allocateIterator();

    while (it->nextP()) {
      { Object* item = it->value;

        if (subtypeOfSymbolP(safePrimaryType(item))) {
          { Object* item000 = item;
            Symbol* item = ((Symbol*)(item000));

            if (!(item == EOL)) {
              it->valueSetter(listO(3, SYM_STREAMS_STELLA_DE_UGLIFY_PARSE_TREE, item, NIL));
            }
          }
        }
        else {
        }
      }
    }
  }
  return (messageargumentstree);
}

Object* walkError(Cons* body) {
  { Cons* messagearguments = formatMessageArguments(formatWalkMessageArguments(body), FALSE);

    return (listO(5, SYM_STREAMS_STELLA_SPECIAL, cons(listO(3, SYM_STREAMS_STELLA_oPRINTREADABLYpo, SYM_STREAMS_STELLA_TRUE, NIL), NIL), cons(SYM_STREAMS_STELLA_SIGNAL_TRANSLATION_ERROR, NIL), listO(5, SYM_STREAMS_STELLA_UNLESS, cons(SYM_STREAMS_STELLA_SUPPRESS_WARNINGSp, NIL), listO(4, SYM_STREAMS_STELLA_PRINT_ERROR_CONTEXT, wrapString(">> ERROR: "), SYM_STREAMS_STELLA_STANDARD_ERROR, NIL), listO(5, SYM_STREAMS_STELLA_PRINT_STREAM, SYM_STREAMS_STELLA_STANDARD_ERROR, SYM_STREAMS_STELLA_EOL, wrapString(" "), messagearguments->concatenate(listO(3, wrapString("."), SYM_STREAMS_STELLA_EOL, NIL), 0)), NIL), NIL));
  }
}

Object* walkInform(Cons* body) {
  { Cons* messagearguments = formatMessageArguments(formatWalkMessageArguments(body), FALSE);

    return (listO(5, SYM_STREAMS_STELLA_SPECIAL, cons(listO(3, SYM_STREAMS_STELLA_oPRINTREADABLYpo, SYM_STREAMS_STELLA_TRUE, NIL), NIL), cons(SYM_STREAMS_STELLA_SIGNAL_TRANSLATION_WARNING, NIL), listO(5, SYM_STREAMS_STELLA_UNLESS, cons(SYM_STREAMS_STELLA_SUPPRESS_WARNINGSp, NIL), listO(4, SYM_STREAMS_STELLA_PRINT_ERROR_CONTEXT, wrapString(">> WARNING: "), SYM_STREAMS_STELLA_STANDARD_OUTPUT, NIL), listO(5, SYM_STREAMS_STELLA_PRINT_STREAM, SYM_STREAMS_STELLA_STANDARD_OUTPUT, SYM_STREAMS_STELLA_EOL, wrapString(" "), messagearguments->concatenate(listO(3, wrapString("."), SYM_STREAMS_STELLA_EOL, NIL), 0)), NIL), NIL));
  }
}

Object* walkWarn(Cons* body) {
  { Cons* messagearguments = formatMessageArguments(formatWalkMessageArguments(body), FALSE);

    return (listO(5, SYM_STREAMS_STELLA_SPECIAL, cons(listO(3, SYM_STREAMS_STELLA_oPRINTREADABLYpo, SYM_STREAMS_STELLA_TRUE, NIL), NIL), cons(SYM_STREAMS_STELLA_SIGNAL_TRANSLATION_WARNING, NIL), listO(5, SYM_STREAMS_STELLA_UNLESS, cons(SYM_STREAMS_STELLA_SUPPRESS_WARNINGSp, NIL), listO(4, SYM_STREAMS_STELLA_PRINT_ERROR_CONTEXT, wrapString(">> WARNING: "), SYM_STREAMS_STELLA_STANDARD_WARNING, NIL), listO(5, SYM_STREAMS_STELLA_PRINT_STREAM, SYM_STREAMS_STELLA_STANDARD_WARNING, SYM_STREAMS_STELLA_EOL, wrapString(" "), messagearguments->concatenate(listO(3, wrapString("."), SYM_STREAMS_STELLA_EOL, NIL), 0)), NIL), NIL));
  }
}

Object* safety(IntegerWrapper* level, Object* test, Cons* body) {
  // Signal warning message, placing non-string arguments in quotes.
  if (level->wrapperValue > oSAFETYo.get()) {
    return (NULL);
  }
  body = formatMessageArguments(body, FALSE);
  return (listO(4, SYM_STREAMS_STELLA_WHEN, listO(3, SYM_STREAMS_STELLA_NOT, test, NIL), listO(4, SYM_STREAMS_STELLA_PRINT_STREAM, KWD_STREAMS_ERROR, wrapString("Safety violation: "), body->concatenate(NIL, 0)), NIL));
}

Object* evaluationError(Cons* body) {
  { Symbol* streamvar = localGensym("STREAM");

    return (listO(8, SYM_STREAMS_STELLA_LET, cons(cons(streamvar, cons(listO(3, SYM_STREAMS_STELLA_NEW, SYM_STREAMS_STELLA_OUTPUT_STRING_STREAM, NIL), NIL)), NIL), listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, streamvar, listO(3, wrapString("While evaluating '"), SYM_STREAMS_STELLA_oEVALUATIONTREEo, NIL)), listO(4, SYM_STREAMS_STELLA_WHEN, listO(3, SYM_STREAMS_STELLA_DEFINEDp, SYM_STREAMS_STELLA_oEVALUATIONPARENTTREEo, NIL), listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, streamvar, listO(4, SYM_STREAMS_STELLA_EOL, wrapString("' inside '"), SYM_STREAMS_STELLA_oEVALUATIONPARENTTREEo, NIL)), NIL), listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, streamvar, listO(3, wrapString("':"), SYM_STREAMS_STELLA_EOL, NIL)), listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, streamvar, formatMessageArguments(body, FALSE)->concatenate(NIL, 0)), listO(3, SYM_STREAMS_STELLA_SIGNAL_EXCEPTION, listO(5, SYM_STREAMS_STELLA_NEW, SYM_STREAMS_STELLA_EVALUATION_EXCEPTION, KWD_STREAMS_MESSAGE, listO(3, SYM_STREAMS_STELLA_THE_STRING, streamvar, NIL), NIL), NIL), NIL));
  }
}

Cons* formatStringMessageArguments(Cons* messagearguments, boolean trailingeolP) {
  { Cons* formattedarguments = formatMessageArguments(messagearguments, trailingeolP);

    { ConsIterator* it = formattedarguments->allocateIterator();

      while (it->nextP()) {
        { Surrogate* testValue000 = safePrimaryType(it->value);

          if (subtypeOfStringP(testValue000)) {
          }
          else if (subtypeOfP(testValue000, SGT_STREAMS_STELLA_LITERAL_WRAPPER)) {
            it->valueSetter(wrapString(stringify(it->value)));
          }
          else {
            if (it->value == SYM_STREAMS_STELLA_EOL) {
              it->valueSetter(wrapString(EOL_STRING));
            }
            else {
              it->valueSetter(listO(3, SYM_STREAMS_STELLA_STRINGIFY, it->value, NIL));
            }
          }
        }
      }
    }
    return (formattedarguments);
  }
}

Object* messageToString(Cons* body) {
  { Cons* messagearguments = formatStringMessageArguments(body, FALSE);
    Symbol* messagevar = localGensym("MESSAGE");

    return (listO(5, SYM_STREAMS_STELLA_VRLET, cons(cons(messagevar, listO(3, SYM_STREAMS_STELLA_STRING, SYM_STREAMS_STELLA_NULL, NIL)), NIL), listO(4, SYM_STREAMS_STELLA_SPECIAL, cons(listO(3, SYM_STREAMS_STELLA_oPRINTREADABLYpo, SYM_STREAMS_STELLA_TRUE, NIL), NIL), listO(3, SYM_STREAMS_STELLA_SETQ, messagevar, cons(cons(SYM_STREAMS_STELLA_CONCATENATE, messagearguments->concatenate(NIL, 0)), NIL)), NIL), messagevar, NIL));
  }
}

boolean terminateOutputStreamP(OutputStream* self) {
  { std::ostream* nativeStream = self->nativeStream;

    if (!(nativeStream == NULL)) {
      delete nativeStream;
    }
    self->nativeStream = NULL;
    self->state = KWD_STREAMS_CLOSED;
    return (TRUE);
  }
}

boolean terminateInputStreamP(InputStream* self) {
  { std::istream* nativeStream = self->nativeStream;

    if (!(nativeStream == NULL)) {
      delete nativeStream;
    }
    self->nativeStream = NULL;
    self->state = KWD_STREAMS_CLOSED;
    return (TRUE);
  }
}

// List of file streams that are currently open.
List* oOPEN_FILE_STREAMSo = NULL;

void initializeFileOutputStream(OutputFileStream* self) {
  { char* filename = translateLogicalPathname(self->filename);
    char* ifexistsaction = self->ifExistsAction->symbolName;

    self->nativeStream = (new std::ofstream(filename));
    if (self->nativeStream == NULL) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "initialize-file-output-stream: Could not open " << "`" << self << "'";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    self->state = KWD_STREAMS_OPEN;
    oOPEN_FILE_STREAMSo->push(self);
  }
}

boolean terminateFileOutputStreamP(OutputFileStream* self) {
  { std::ostream* nativeStream = self->nativeStream;

    if (!(nativeStream == NULL)) {
      delete nativeStream;
    }
    self->nativeStream = NULL;
    self->state = KWD_STREAMS_CLOSED;
    oOPEN_FILE_STREAMSo->remove(self);
    return (TRUE);
  }
}

void initializeFileInputStream(InputFileStream* self) {
  { char* filename = translateLogicalPathname(self->filename);
    char* ifnotexistsaction = self->ifNotExistsAction->symbolName;

    self->nativeStream = (new std::ifstream(filename));
    if (self->nativeStream == NULL) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "initialize-file-input-stream: Could not open " << "`" << self << "'";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    self->state = KWD_STREAMS_OPEN;
    oOPEN_FILE_STREAMSo->push(self);
  }
}

boolean terminateFileInputStreamP(InputFileStream* self) {
  { std::istream* nativeStream = self->nativeStream;

    if (!(nativeStream == NULL)) {
      delete nativeStream;
    }
    self->nativeStream = NULL;
    self->state = KWD_STREAMS_CLOSED;
    oOPEN_FILE_STREAMSo->remove(self);
    return (TRUE);
  }
}

void initializeStringOutputStream(OutputStringStream* self) {
  self->nativeStream = (new (GC) std::ostringstream());
}

char* OutputStringStream::theStringReader() {
  { OutputStringStream* self = this;

    { std::ostream* nativeStream = self->nativeStream;
      char* string = NULL;

      string = ostringstream_to_c_string((std::ostringstream*)nativeStream);
      if (string == NULL) {
        string = "";
      }
      return (string);
    }
  }
}

void initializeStringInputStream(InputStringStream* self) {
  { char* string = self->theString;

    self->nativeStream = (new (GC) std::istringstream(string));
  }
}

void closeStream(Stream* self) {
  // Close the stream `self'.
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_STREAMS_STELLA_FILE_INPUT_STREAM)) {
      { Stream* self000 = self;
        InputFileStream* self = ((InputFileStream*)(self000));

        terminateFileInputStreamP(self);
      }
    }
    else if (subtypeOfP(testValue000, SGT_STREAMS_STELLA_FILE_OUTPUT_STREAM)) {
      { Stream* self001 = self;
        OutputFileStream* self = ((OutputFileStream*)(self001));

        terminateFileOutputStreamP(self);
      }
    }
    else if (subtypeOfP(testValue000, SGT_STREAMS_STELLA_INPUT_STREAM)) {
      { Stream* self002 = self;
        InputStream* self = ((InputStream*)(self002));

        terminateInputStreamP(self);
      }
    }
    else if (subtypeOfP(testValue000, SGT_STREAMS_STELLA_OUTPUT_STREAM)) {
      { Stream* self003 = self;
        OutputStream* self = ((OutputStream*)(self003));

        terminateOutputStreamP(self);
      }
    }
    else {
    }
  }
}

void flushOutput(OutputStream* self) {
  // Flush all buffered output of `self'.
  { std::ostream* nativeStream = self->nativeStream;

    flush(*nativeStream);
  }
}

void closeAllFiles() {
  // Close all currently open file streams.  Use for emergencies or for cleanup.
  { List* openstreams = oOPEN_FILE_STREAMSo->copy();

    { Stream* stream = NULL;
      Cons* iter000 = openstreams->theConsList;

      while (!(iter000 == NIL)) {
        stream = ((Stream*)(iter000->value));
        iter000 = iter000->rest;
        closeStream(stream);
      }
    }
    openstreams->free();
  }
}

InputStream* openNetworkStream(char* host, int port, OutputStream*& _Return1) {
  // Open a TCP/IP network stream to `host' at `port' and return the result
  // as an input/output stream pair.
  { std::istream* in = NULL;
    std::ostream* out = NULL;

    throw *newStellaException("Network streams not yet implemented for this target language");
    { InputStream* self001 = newInputStream();

      self001->nativeStream = in;
      self001->state = KWD_STREAMS_OPEN;
      { InputStream* value000 = self001;

        { OutputStream* self002 = newOutputStream();

          self002->nativeStream = out;
          self002->state = KWD_STREAMS_OPEN;
          { OutputStream* value001 = self002;

            _Return1 = value001;
            return (value000);
          }
        }
      }
    }
  }
}

Object* withInputFile(Cons* binding, Cons* body) {
  // Sets up an unwind-protected form which opens a file for
  // input and closes it afterwards.  The stream for reading is bound to the
  // variable provided in the macro form.
  // Syntax is (WITH-INPUT-FILE (var filename) body+)
  { Symbol* var = ((Symbol*)(binding->value));

    return (listO(4, SYM_STREAMS_STELLA_LET, cons(cons(var, listO(3, SYM_STREAMS_STELLA_FILE_INPUT_STREAM, SYM_STREAMS_STELLA_NULL, NIL)), NIL), listO(4, SYM_STREAMS_STELLA_UNWIND_PROTECT, listO(3, SYM_STREAMS_STELLA_PROGN, listO(3, SYM_STREAMS_STELLA_SETQ, var, cons(listO(5, SYM_STREAMS_STELLA_NEW, SYM_STREAMS_STELLA_FILE_INPUT_STREAM, KWD_STREAMS_FILENAME, binding->rest->value, NIL), NIL)), body->concatenate(NIL, 0)), listO(4, SYM_STREAMS_STELLA_WHEN, listO(3, SYM_STREAMS_STELLA_DEFINEDp, var, NIL), listO(3, SYM_STREAMS_STELLA_FREE, var, NIL), NIL), NIL), NIL));
  }
}

Object* withOutputFile(Cons* binding, Cons* body) {
  // Sets up an unwind-protected form which opens a file for
  // output and closes it afterwards.  The stream for writing is bound to the
  // variable provided in the macro form.
  // Syntax is (WITH-OUTPUT-FILE (var filename) body+)
  { Symbol* var = ((Symbol*)(binding->value));

    return (listO(4, SYM_STREAMS_STELLA_LET, cons(cons(var, listO(3, SYM_STREAMS_STELLA_FILE_OUTPUT_STREAM, SYM_STREAMS_STELLA_NULL, NIL)), NIL), listO(4, SYM_STREAMS_STELLA_UNWIND_PROTECT, listO(3, SYM_STREAMS_STELLA_PROGN, listO(3, SYM_STREAMS_STELLA_SETQ, var, cons(listO(5, SYM_STREAMS_STELLA_NEW, SYM_STREAMS_STELLA_FILE_OUTPUT_STREAM, KWD_STREAMS_FILENAME, binding->rest->value, NIL), NIL)), body->concatenate(NIL, 0)), listO(4, SYM_STREAMS_STELLA_WHEN, listO(3, SYM_STREAMS_STELLA_DEFINEDp, var, NIL), listO(3, SYM_STREAMS_STELLA_FREE, var, NIL), NIL), NIL), NIL));
  }
}

Object* withNetworkStream(Cons* binding, Cons* body) {
  // Sets up an unwind-protected form which opens a network
  // socket stream to a host and port for input and output and closes it afterwards.
  // Separate variables as provided in the call are bound to the input and output
  // streams. Syntax is (WITH-NETWORK-STREAM (varIn varOut hostname port) body+)
  { Symbol* varIn = ((Symbol*)(binding->value));
    Symbol* varOut = ((Symbol*)(binding->rest->value));

    return (listO(4, SYM_STREAMS_STELLA_LET, listO(3, cons(varIn, listO(3, SYM_STREAMS_STELLA_INPUT_STREAM, SYM_STREAMS_STELLA_NULL, NIL)), cons(varOut, listO(3, SYM_STREAMS_STELLA_OUTPUT_STREAM, SYM_STREAMS_STELLA_NULL, NIL)), NIL), listO(5, SYM_STREAMS_STELLA_UNWIND_PROTECT, listO(3, SYM_STREAMS_STELLA_PROGN, listO(4, SYM_STREAMS_STELLA_MV_SETQ, cons(varIn, cons(varOut, NIL)), listO(3, SYM_STREAMS_STELLA_OPEN_NETWORK_STREAM, binding->rest->rest->value, cons(binding->fourth(), NIL)), NIL), body->concatenate(NIL, 0)), listO(4, SYM_STREAMS_STELLA_WHEN, listO(3, SYM_STREAMS_STELLA_DEFINEDp, varIn, NIL), listO(3, SYM_STREAMS_STELLA_FREE, varIn, NIL), NIL), listO(4, SYM_STREAMS_STELLA_WHEN, listO(3, SYM_STREAMS_STELLA_DEFINEDp, varOut, NIL), listO(3, SYM_STREAMS_STELLA_FREE, varOut, NIL), NIL), NIL), NIL));
  }
}

char* oHTML_QUOTED_CHARACTERSo = "><&\"";

Cons* expandMarkupTagFunction(Cons* tagAndStream, Cons* body, boolean xmlP) {
  { Object* tag = tagAndStream->value;
    Symbol* tagvar = NULL;
    char* tagvalue = NULL;
    Object* stream = tagAndStream->rest->value;
    Object* eolargument = tagAndStream->rest->rest->value;
    boolean eolP = ((boolean)(eolargument)) &&
        coerceWrappedBooleanToBoolean(coerceToBoolean(eolargument));

    if (body == NIL) {
      { Surrogate* testValue000 = safePrimaryType(tag);

        if (subtypeOfStringP(testValue000)) {
          { Object* tag000 = tag;
            StringWrapper* tag = ((StringWrapper*)(tag000));

            if (eolP) {
              return (listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, cons(wrapString(stringConcatenate("<", tag->wrapperValue, 1, (xmlP ? (char*)"/>" : (char*)">"))), cons(SYM_STREAMS_STELLA_EOL, NIL))));
            }
            else {
              return (listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, cons(wrapString(stringConcatenate("<", tag->wrapperValue, 1, (xmlP ? (char*)"/>" : (char*)">"))), NIL)));
            }
          }
        }
        else if (subtypeOfP(testValue000, SGT_STREAMS_STELLA_OBJECT)) {
          { Object* tag001 = tag;
            Object* tag = tag001;

            if (eolP) {
              return (listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, listO(3, wrapString("<"), tag, cons((xmlP ? wrapString("/>") : wrapString(">")), cons(SYM_STREAMS_STELLA_EOL, NIL)))));
            }
            else {
              return (listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, listO(3, wrapString("<"), tag, cons((xmlP ? wrapString("/>") : wrapString(">")), NIL))));
            }
          }
        }
        else {
          { OutputStringStream* stream000 = newOutputStringStream();

            *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
            throw *newStellaException(stream000->theStringReader());
          }
        }
      }
    }
    else {
      { Surrogate* testValue001 = safePrimaryType(tag);

        if (subtypeOfStringP(testValue001)) {
          { Object* tag002 = tag;
            StringWrapper* tag = ((StringWrapper*)(tag002));

            tagvalue = tag->wrapperValue;
            if (eolP) {
              return (listO(3, SYM_STREAMS_STELLA_PROGN, listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, cons(wrapString(stringConcatenate("<", tagvalue, 1, ">")), NIL)), body->concatenate(cons(listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, cons(wrapString(stringConcatenate("</", stringSubsequence(tagvalue, 0, stringPosition(tagvalue, ' ', 0)), 1, ">")), cons(SYM_STREAMS_STELLA_EOL, NIL))), NIL), 0)));
            }
            else {
              return (listO(3, SYM_STREAMS_STELLA_PROGN, listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, cons(wrapString(stringConcatenate("<", tagvalue, 1, ">")), NIL)), body->concatenate(cons(listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, cons(wrapString(stringConcatenate("</", stringSubsequence(tagvalue, 0, stringPosition(tagvalue, ' ', 0)), 1, ">")), NIL)), NIL), 0)));
            }
          }
        }
        else if (subtypeOfSymbolP(testValue001)) {
          { Object* tag003 = tag;
            Symbol* tag = ((Symbol*)(tag003));

            if (eolP) {
              return (listO(3, SYM_STREAMS_STELLA_PROGN, listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, listO(3, wrapString("<"), tag, cons(wrapString(">"), NIL))), body->concatenate(cons(listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, listO(5, wrapString("</"), listO(3, SYM_STREAMS_STELLA_SUBSEQUENCE, tag, listO(3, wrapInteger(0), listO(3, SYM_STREAMS_STELLA_POSITION, tag, listO(3, wrapCharacter(' '), wrapInteger(0), NIL)), NIL)), wrapString(">"), SYM_STREAMS_STELLA_EOL, NIL)), NIL), 0)));
            }
            else {
              return (listO(3, SYM_STREAMS_STELLA_PROGN, listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, listO(3, wrapString("<"), tag, cons(wrapString(">"), NIL))), body->concatenate(cons(listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, listO(4, wrapString("</"), listO(3, SYM_STREAMS_STELLA_SUBSEQUENCE, tag, listO(3, wrapInteger(0), listO(3, SYM_STREAMS_STELLA_POSITION, tag, listO(3, wrapCharacter(' '), wrapInteger(0), NIL)), NIL)), wrapString(">"), NIL)), NIL), 0)));
            }
          }
        }
        else if (subtypeOfP(testValue001, SGT_STREAMS_STELLA_OBJECT)) {
          { Object* tag004 = tag;
            Object* tag = tag004;

            tagvar = gensym("TAG");
            if (eolP) {
              return (listO(4, SYM_STREAMS_STELLA_LET, cons(cons(tagvar, listO(3, SYM_STREAMS_STELLA_STRING, tag, NIL)), NIL), listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, listO(3, wrapString("<"), tagvar, cons(wrapString(">"), NIL))), body->concatenate(cons(listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, listO(5, wrapString("</"), listO(3, SYM_STREAMS_STELLA_SUBSEQUENCE, tagvar, listO(3, wrapInteger(0), listO(3, SYM_STREAMS_STELLA_POSITION, tagvar, listO(3, wrapCharacter(' '), wrapInteger(0), NIL)), NIL)), wrapString(">"), SYM_STREAMS_STELLA_EOL, NIL)), NIL), 0)));
            }
            else {
              return (listO(4, SYM_STREAMS_STELLA_LET, cons(cons(tagvar, listO(3, SYM_STREAMS_STELLA_STRING, tag, NIL)), NIL), listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, listO(3, wrapString("<"), tagvar, cons(wrapString(">"), NIL))), body->concatenate(cons(listO(3, SYM_STREAMS_STELLA_PRINT_STREAM, stream, listO(4, wrapString("</"), listO(3, SYM_STREAMS_STELLA_SUBSEQUENCE, tagvar, listO(3, wrapInteger(0), listO(3, SYM_STREAMS_STELLA_POSITION, tagvar, listO(3, wrapCharacter(' '), wrapInteger(0), NIL)), NIL)), wrapString(">"), NIL)), NIL), 0)));
            }
          }
        }
        else {
          { OutputStringStream* stream001 = newOutputStringStream();

            *(stream001->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
            throw *newStellaException(stream001->theStringReader());
          }
        }
      }
    }
  }
}

Object* withHtmlTag(Cons* tagAndStream, Cons* body) {
  return (expandMarkupTagFunction(tagAndStream, body, FALSE));
}

Object* withXmlTag(Cons* tagAndStream, Cons* body) {
  return (expandMarkupTagFunction(tagAndStream, body, TRUE));
}

boolean htmlCharacterNeedsQuotingP(char ch) {
  return (stringMemberP(oHTML_QUOTED_CHARACTERSo, ch));
}

void writeHtmlCharacterQuotingSpecialCharacters(std::ostream* stream, char ch) {
  switch (ch) {
    case '>': 
      *(stream) << "&gt;";
    break;
    case '<': 
      *(stream) << "&lt;";
    break;
    case '&': 
      *(stream) << "&amp;";
    break;
    case '"': 
      *(stream) << "&quot;";
    break;
    default:
      *(stream) << ch;
    break;
  }
  return;
}

void writeHtmlQuotingSpecialCharacters(std::ostream* stream, char* input) {
  { char ch = NULL_CHARACTER;
    char* vector000 = input;
    int index000 = 0;
    int length000 = strlen(vector000);

    while (index000 < length000) {
      ch = vector000[index000];
      index000 = index000 + 1;
      writeHtmlCharacterQuotingSpecialCharacters(stream, ch);
    }
  }
  return;
}

void writeHtmlEscapingUrlSpecialCharacters(std::ostream* stream, char* input) {
  // Writes a string and replaces unallowed URL characters according to RFC 2396
  // with %-format URL escape sequences.
  { char ch = NULL_CHARACTER;
    char* vector000 = input;
    int index000 = 0;
    int length000 = strlen(vector000);

    while (index000 < length000) {
      ch = vector000[index000];
      index000 = index000 + 1;
      switch (ch) {
        case ' ': 
          *(stream) << "%20";
        break;
        case '?': 
          *(stream) << "%3F";
        break;
        case '#': 
          *(stream) << "%23";
        break;
        case '=': 
          *(stream) << "%3D";
        break;
        case '&': 
          *(stream) << "%26";
        break;
        case '%': 
          *(stream) << "%25";
        break;
        case '+': 
          *(stream) << "%2B";
        break;
        case '<': 
          *(stream) << "%3C";
        break;
        case '>': 
          *(stream) << "%3E";
        break;
        case '/': 
          *(stream) << "%2F";
        break;
        case ':': 
          *(stream) << "%3A";
        break;
        case '"': 
          *(stream) << "%22";
        break;
        case '\'': 
          *(stream) << "%27";
        break;
        default:
          *(stream) << ch;
        break;
      }
    }
  }
  return;
}

int hexCharacterValue(char c) {
  { int v = stringPosition("0123456789ABCDEF", c, 0);

    if (v == NULL_INTEGER) {
      v = stringPosition("0123456789abcdef", c, 0);
    }
    return (v);
  }
}

char* unescapeUrlString(char* input) {
  // Takes a string and replaces %-format URL escape sequences with their real
  // character equivalent according to RFC 2396.
  if (stringPosition(input, '%', 0) == NULL_INTEGER) {
    return (input);
  }
  else {
    { char* result = makeRawMutableString(strlen(input));
      int iOut = 0;
      int iIn = 0;
      char charSave = NULL_CHARACTER;
      int charValue = 0;
      int escapeValue = 0;
      int iMax = strlen(input);

      while (iIn < iMax) {
        if (input[iIn] == '%') {
          {
            iIn = iIn + 1;
            if (iIn < iMax) {
              {
                charSave = input[iIn];
                charValue = hexCharacterValue(charSave);
                iIn = iIn + 1;
                if ((charValue != NULL_INTEGER) &&
                    (iIn < iMax)) {
                  {
                    escapeValue = 16 * charValue;
                    charValue = hexCharacterValue(input[iIn]);
                    if (charValue != NULL_INTEGER) {
                      {
                        result[iOut] = ((char) (escapeValue + charValue));
                      }
                    }
                    else {
                      {
                        result[iOut] = '%';
                        result[(iOut = iOut + 1)] = charSave;
                        result[(iOut = iOut + 1)] = (input[iIn]);
                      }
                    }
                  }
                }
                else {
                  {
                    result[iOut] = '%';
                    result[(iOut = iOut + 1)] = charSave;
                  }
                }
                iOut = iOut + 1;
                iIn = iIn + 1;
              }
            }
            else {
              {
                result[iOut] = '%';
                iOut = iOut + 1;
              }
            }
          }
        }
        else {
          {
            result[iOut] = (input[iIn]);
            iOut = iOut + 1;
            iIn = iIn + 1;
          }
        }
      }
      return (mutableStringSubsequence(result, 0, iOut));
    }
  }
}

KeyValueList* oHTML_ESCAPE_TABLEo = NULL;

char* unescapeHtmlString(char* input) {
  // Replaces HTML escape sequences such as &amp; with their
  // associated characters.
  { int incursor = 0;
    int outcursor = 0;
    int escapestart = stringPosition(input, '&', incursor);
    int escapeend = -1;
    int inputlength = -1;
    char* output = NULL;
    CharacterWrapper* character = NULL;

    for (;;) {
      if (escapestart == NULL_INTEGER) {
        if (output == NULL) {
          return (input);
        }
        else {
          break;
        }
      }
      escapeend = stringPosition(input, ';', escapestart);
      if (escapeend == NULL_INTEGER) {
        if (output == NULL) {
          return (input);
        }
        else {
          break;
        }
      }
      character = ((CharacterWrapper*)(oHTML_ESCAPE_TABLEo->lookup(wrapString(stringSubsequence(input, escapestart + 1, escapeend)))));
      if (!((boolean)(character))) {
        escapestart = stringPosition(input, '&', escapeend);
        continue;
      }
      if (output == NULL) {
        inputlength = strlen(input);
        output = makeRawMutableString(inputlength);
      }
      while (incursor < escapestart) {
        output[outcursor] = (input[incursor]);
        incursor = incursor + 1;
        outcursor = outcursor + 1;
      }
      output[outcursor] = (character->wrapperValue);
      outcursor = outcursor + 1;
      incursor = escapeend + 1;
      escapestart = stringPosition(input, '&', escapeend);
    }
    while (incursor < inputlength) {
      output[outcursor] = (input[incursor]);
      incursor = incursor + 1;
      outcursor = outcursor + 1;
    }
    return (stringSubsequence(output, 0, outcursor));
  }
}

Object* accessStreamIteratorSlotValue(StreamIterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_STREAMS_STELLA_THE_STREAM) {
    if (setvalueP) {
      self->theStream = ((InputStream*)(value));
    }
    else {
      value = self->theStream;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << slotname << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (value);
}

SExpressionIterator* newSExpressionIterator() {
  { SExpressionIterator* self = NULL;

    self = new SExpressionIterator();
    self->firstIterationP = TRUE;
    self->value = NULL;
    self->theStream = NULL;
    return (self);
  }
}

void SExpressionIterator::free() {
  { SExpressionIterator* self = this;

    if (terminateStreamIteratorP(self)) {
      unmake(self);
    }
  }
}

Surrogate* SExpressionIterator::primaryType() {
  { SExpressionIterator* self = this;

    return (SGT_STREAMS_STELLA_S_EXPRESSION_ITERATOR);
  }
}

LineIterator* newLineIterator() {
  { LineIterator* self = NULL;

    self = new LineIterator();
    self->firstIterationP = TRUE;
    self->value = NULL;
    self->theStream = NULL;
    return (self);
  }
}

void LineIterator::free() {
  { LineIterator* self = this;

    if (terminateStreamIteratorP(self)) {
      unmake(self);
    }
  }
}

Surrogate* LineIterator::primaryType() {
  { LineIterator* self = this;

    return (SGT_STREAMS_STELLA_LINE_ITERATOR);
  }
}

CharacterIterator* newCharacterIterator() {
  { CharacterIterator* self = NULL;

    self = new CharacterIterator();
    self->firstIterationP = TRUE;
    self->value = NULL_CHARACTER;
    self->theStream = NULL;
    return (self);
  }
}

void CharacterIterator::free() {
  { CharacterIterator* self = this;

    if (terminateStreamIteratorP(self)) {
      unmake(self);
    }
  }
}

Surrogate* CharacterIterator::primaryType() {
  { CharacterIterator* self = this;

    return (SGT_STREAMS_STELLA_CHARACTER_ITERATOR);
  }
}

boolean terminateStreamIteratorP(StreamIterator* self) {
  if (((boolean)(self->theStream))) {
    self->theStream->free();
  }
  return (TRUE);
}

SExpressionIterator* sExpressions(InputStream* stream) {
  { SExpressionIterator* self000 = newSExpressionIterator();

    self000->theStream = stream;
    { SExpressionIterator* value000 = self000;

      return (value000);
    }
  }
}

boolean SExpressionIterator::nextP() {
  { SExpressionIterator* self = this;

    self->firstIterationP = FALSE;
    { Object* object = NULL;
      boolean eofP = FALSE;

      object = readSExpression(self->theStream, eofP);
      if (eofP) {
        closeStream(self->theStream);
        return (FALSE);
      }
      else {
        self->value = object;
        return (TRUE);
      }
    }
  }
}

LineIterator* lines(InputStream* stream) {
  { LineIterator* self000 = newLineIterator();

    self000->theStream = stream;
    { LineIterator* value000 = self000;

      return (value000);
    }
  }
}

boolean LineIterator::nextP() {
  { LineIterator* self = this;

    self->firstIterationP = FALSE;
    { char* line = NULL;
      boolean eofP = FALSE;

      line = readLine(self->theStream, eofP);
      if (eofP) {
        closeStream(self->theStream);
        return (FALSE);
      }
      else {
        self->value = line;
        return (TRUE);
      }
    }
  }
}

CharacterIterator* characters(InputStream* stream) {
  { CharacterIterator* self000 = newCharacterIterator();

    self000->theStream = stream;
    { CharacterIterator* value000 = self000;

      return (value000);
    }
  }
}

boolean CharacterIterator::nextP() {
  { CharacterIterator* self = this;

    self->firstIterationP = FALSE;
    { char chaR = NULL_CHARACTER;
      boolean eofP = FALSE;

      chaR = readCharacter(self->theStream, eofP);
      if (eofP) {
        closeStream(self->theStream);
        return (FALSE);
      }
      else {
        self->value = chaR;
        return (TRUE);
      }
    }
  }
}

void helpStartupStreams1() {
  {
    SYM_STREAMS_STELLA_EOL = ((Symbol*)(internRigidSymbolWrtModule("EOL", NULL, 0)));
    SYM_STREAMS_STELLA_PRINT_STREAM = ((Symbol*)(internRigidSymbolWrtModule("PRINT-STREAM", NULL, 0)));
    SYM_STREAMS_STELLA_STANDARD_OUTPUT = ((Symbol*)(internRigidSymbolWrtModule("STANDARD-OUTPUT", NULL, 0)));
    SYM_STREAMS_STELLA_FOREACH = ((Symbol*)(internRigidSymbolWrtModule("FOREACH", NULL, 0)));
    SYM_STREAMS_STELLA_I = ((Symbol*)(internRigidSymbolWrtModule("I", NULL, 0)));
    SYM_STREAMS_STELLA_IN = ((Symbol*)(internRigidSymbolWrtModule("IN", NULL, 0)));
    SYM_STREAMS_STELLA_INTERVAL = ((Symbol*)(internRigidSymbolWrtModule("INTERVAL", NULL, 0)));
    SYM_STREAMS_STELLA_DO = ((Symbol*)(internRigidSymbolWrtModule("DO", NULL, 0)));
    SYM_STREAMS_STELLA_IGNORE = ((Symbol*)(internRigidSymbolWrtModule("IGNORE", NULL, 0)));
    KWD_STREAMS_COMMON_LISP = ((Keyword*)(internRigidSymbolWrtModule("COMMON-LISP", NULL, 2)));
    KWD_STREAMS_WARN = ((Keyword*)(internRigidSymbolWrtModule("WARN", NULL, 2)));
    SYM_STREAMS_STELLA_STANDARD_WARNING = ((Symbol*)(internRigidSymbolWrtModule("STANDARD-WARNING", NULL, 0)));
    SYM_STREAMS_STELLA_NULL = ((Symbol*)(internRigidSymbolWrtModule("NULL", NULL, 0)));
    SYM_STREAMS_STELLA_STELLA_EXCEPTION = ((Symbol*)(internRigidSymbolWrtModule("STELLA-EXCEPTION", NULL, 0)));
    SGT_STREAMS_STELLA_STRING_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("STRING-WRAPPER", NULL, 1)));
    SYM_STREAMS_STELLA_SIGNAL_EXCEPTION = ((Symbol*)(internRigidSymbolWrtModule("SIGNAL-EXCEPTION", NULL, 0)));
    SYM_STREAMS_STELLA_NEW = ((Symbol*)(internRigidSymbolWrtModule("NEW", NULL, 0)));
    KWD_STREAMS_MESSAGE = ((Keyword*)(internRigidSymbolWrtModule("MESSAGE", NULL, 2)));
    SYM_STREAMS_STELLA_LET = ((Symbol*)(internRigidSymbolWrtModule("LET", NULL, 0)));
    SYM_STREAMS_STELLA_OUTPUT_STRING_STREAM = ((Symbol*)(internRigidSymbolWrtModule("OUTPUT-STRING-STREAM", NULL, 0)));
    SYM_STREAMS_STELLA_THE_STRING = ((Symbol*)(internRigidSymbolWrtModule("THE-STRING", NULL, 0)));
    SYM_STREAMS_STELLA_SIGNAL = ((Symbol*)(internRigidSymbolWrtModule("SIGNAL", NULL, 0)));
    KWD_STREAMS_JAVA = ((Keyword*)(internRigidSymbolWrtModule("JAVA", NULL, 2)));
    SYM_STREAMS_STELLA_ERROR_MESSAGE_ = ((Symbol*)(internRigidSymbolWrtModule("ERROR_MESSAGE_", NULL, 0)));
    SYM_STREAMS_STELLA_VERBATIM = ((Symbol*)(internRigidSymbolWrtModule("VERBATIM", NULL, 0)));
    KWD_STREAMS_CONTINUABLE_ERROR = ((Keyword*)(internRigidSymbolWrtModule("CONTINUABLE-ERROR", NULL, 2)));
    SYM_STREAMS_STELLA_READ_EXCEPTION = ((Symbol*)(internRigidSymbolWrtModule("READ-EXCEPTION", NULL, 0)));
    SYM_STREAMS_STELLA_DE_UGLIFY_PARSE_TREE = ((Symbol*)(internRigidSymbolWrtModule("DE-UGLIFY-PARSE-TREE", NULL, 0)));
    SYM_STREAMS_STELLA_SPECIAL = ((Symbol*)(internRigidSymbolWrtModule("SPECIAL", NULL, 0)));
    SYM_STREAMS_STELLA_oPRINTREADABLYpo = ((Symbol*)(internRigidSymbolWrtModule("*PRINTREADABLY?*", NULL, 0)));
    SYM_STREAMS_STELLA_TRUE = ((Symbol*)(internRigidSymbolWrtModule("TRUE", NULL, 0)));
    SYM_STREAMS_STELLA_SIGNAL_TRANSLATION_ERROR = ((Symbol*)(internRigidSymbolWrtModule("SIGNAL-TRANSLATION-ERROR", NULL, 0)));
    SYM_STREAMS_STELLA_UNLESS = ((Symbol*)(internRigidSymbolWrtModule("UNLESS", NULL, 0)));
    SYM_STREAMS_STELLA_SUPPRESS_WARNINGSp = ((Symbol*)(internRigidSymbolWrtModule("SUPPRESS-WARNINGS?", NULL, 0)));
    SYM_STREAMS_STELLA_PRINT_ERROR_CONTEXT = ((Symbol*)(internRigidSymbolWrtModule("PRINT-ERROR-CONTEXT", NULL, 0)));
    SYM_STREAMS_STELLA_STANDARD_ERROR = ((Symbol*)(internRigidSymbolWrtModule("STANDARD-ERROR", NULL, 0)));
    SYM_STREAMS_STELLA_SIGNAL_TRANSLATION_WARNING = ((Symbol*)(internRigidSymbolWrtModule("SIGNAL-TRANSLATION-WARNING", NULL, 0)));
    SYM_STREAMS_STELLA_WHEN = ((Symbol*)(internRigidSymbolWrtModule("WHEN", NULL, 0)));
    SYM_STREAMS_STELLA_NOT = ((Symbol*)(internRigidSymbolWrtModule("NOT", NULL, 0)));
    KWD_STREAMS_ERROR = ((Keyword*)(internRigidSymbolWrtModule("ERROR", NULL, 2)));
    SYM_STREAMS_STELLA_oEVALUATIONTREEo = ((Symbol*)(internRigidSymbolWrtModule("*EVALUATIONTREE*", NULL, 0)));
    SYM_STREAMS_STELLA_DEFINEDp = ((Symbol*)(internRigidSymbolWrtModule("DEFINED?", NULL, 0)));
    SYM_STREAMS_STELLA_oEVALUATIONPARENTTREEo = ((Symbol*)(internRigidSymbolWrtModule("*EVALUATIONPARENTTREE*", NULL, 0)));
    SYM_STREAMS_STELLA_EVALUATION_EXCEPTION = ((Symbol*)(internRigidSymbolWrtModule("EVALUATION-EXCEPTION", NULL, 0)));
    SGT_STREAMS_STELLA_LITERAL_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("LITERAL-WRAPPER", NULL, 1)));
    SYM_STREAMS_STELLA_STRINGIFY = ((Symbol*)(internRigidSymbolWrtModule("STRINGIFY", NULL, 0)));
    SYM_STREAMS_STELLA_VRLET = ((Symbol*)(internRigidSymbolWrtModule("VRLET", NULL, 0)));
    SYM_STREAMS_STELLA_STRING = ((Symbol*)(internRigidSymbolWrtModule("STRING", NULL, 0)));
    SYM_STREAMS_STELLA_SETQ = ((Symbol*)(internRigidSymbolWrtModule("SETQ", NULL, 0)));
    SYM_STREAMS_STELLA_CONCATENATE = ((Symbol*)(internRigidSymbolWrtModule("CONCATENATE", NULL, 0)));
    KWD_STREAMS_CLOSED = ((Keyword*)(internRigidSymbolWrtModule("CLOSED", NULL, 2)));
    KWD_STREAMS_OPEN = ((Keyword*)(internRigidSymbolWrtModule("OPEN", NULL, 2)));
    SGT_STREAMS_STELLA_FILE_INPUT_STREAM = ((Surrogate*)(internRigidSymbolWrtModule("FILE-INPUT-STREAM", NULL, 1)));
    SGT_STREAMS_STELLA_FILE_OUTPUT_STREAM = ((Surrogate*)(internRigidSymbolWrtModule("FILE-OUTPUT-STREAM", NULL, 1)));
    SGT_STREAMS_STELLA_INPUT_STREAM = ((Surrogate*)(internRigidSymbolWrtModule("INPUT-STREAM", NULL, 1)));
    SGT_STREAMS_STELLA_OUTPUT_STREAM = ((Surrogate*)(internRigidSymbolWrtModule("OUTPUT-STREAM", NULL, 1)));
    SYM_STREAMS_STELLA_FILE_INPUT_STREAM = ((Symbol*)(internRigidSymbolWrtModule("FILE-INPUT-STREAM", NULL, 0)));
    SYM_STREAMS_STELLA_UNWIND_PROTECT = ((Symbol*)(internRigidSymbolWrtModule("UNWIND-PROTECT", NULL, 0)));
    SYM_STREAMS_STELLA_PROGN = ((Symbol*)(internRigidSymbolWrtModule("PROGN", NULL, 0)));
    KWD_STREAMS_FILENAME = ((Keyword*)(internRigidSymbolWrtModule("FILENAME", NULL, 2)));
  }
}

void helpStartupStreams2() {
  {
    SYM_STREAMS_STELLA_FREE = ((Symbol*)(internRigidSymbolWrtModule("FREE", NULL, 0)));
    SYM_STREAMS_STELLA_FILE_OUTPUT_STREAM = ((Symbol*)(internRigidSymbolWrtModule("FILE-OUTPUT-STREAM", NULL, 0)));
    SYM_STREAMS_STELLA_INPUT_STREAM = ((Symbol*)(internRigidSymbolWrtModule("INPUT-STREAM", NULL, 0)));
    SYM_STREAMS_STELLA_OUTPUT_STREAM = ((Symbol*)(internRigidSymbolWrtModule("OUTPUT-STREAM", NULL, 0)));
    SYM_STREAMS_STELLA_MV_SETQ = ((Symbol*)(internRigidSymbolWrtModule("MV-SETQ", NULL, 0)));
    SYM_STREAMS_STELLA_OPEN_NETWORK_STREAM = ((Symbol*)(internRigidSymbolWrtModule("OPEN-NETWORK-STREAM", NULL, 0)));
    SGT_STREAMS_STELLA_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("OBJECT", NULL, 1)));
    SYM_STREAMS_STELLA_SUBSEQUENCE = ((Symbol*)(internRigidSymbolWrtModule("SUBSEQUENCE", NULL, 0)));
    SYM_STREAMS_STELLA_POSITION = ((Symbol*)(internRigidSymbolWrtModule("POSITION", NULL, 0)));
    SYM_STREAMS_STELLA_THE_STREAM = ((Symbol*)(internRigidSymbolWrtModule("THE-STREAM", NULL, 0)));
    SGT_STREAMS_STELLA_S_EXPRESSION_ITERATOR = ((Surrogate*)(internRigidSymbolWrtModule("S-EXPRESSION-ITERATOR", NULL, 1)));
    SGT_STREAMS_STELLA_LINE_ITERATOR = ((Surrogate*)(internRigidSymbolWrtModule("LINE-ITERATOR", NULL, 1)));
    SGT_STREAMS_STELLA_CHARACTER_ITERATOR = ((Surrogate*)(internRigidSymbolWrtModule("CHARACTER-ITERATOR", NULL, 1)));
    SYM_STREAMS_STELLA_STARTUP_STREAMS = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-STREAMS", NULL, 0)));
    SYM_STREAMS_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", NULL, 0)));
  }
}

void helpStartupStreams3() {
  {
    EOL = SYM_STREAMS_STELLA_EOL;
    { InputStream* self000 = newInputStream();

      self000->nativeStream = &std::cin;
      STANDARD_INPUT = self000;
    }
    oIGNORETRANSLATIONERRORSpo.set(TRUE);
    SINGLE_QUOTE_STRING = wrapString("'");
    SINGLE_BQUOTE_STRING = wrapString("`");
    oOPEN_FILE_STREAMSo = newList();
    oHTML_ESCAPE_TABLEo = newKeyValueList();
  }
}

void helpStartupStreams4() {
  {
    defineFunctionObject("FORMAT-MESSAGE-ARGUMENTS", "(DEFUN (FORMAT-MESSAGE-ARGUMENTS CONS) ((MESSAGEARGUMENTSTREE CONS) (TRAILINGEOL? BOOLEAN)))", ((cpp_function_code)(&formatMessageArguments)), NULL);
    defineFunctionObject("PRINT", "(DEFUN PRINT (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Print arguments to the standard output stream.\")", ((cpp_function_code)(&print)), NULL);
    defineFunctionObject("PRINT-SPACES", "(DEFUN PRINT-SPACES (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"(print-spaces [stream] N) prints N spaces onto stream.  If\nno stream form is provided, then STANDARD-OUTPUT will be used.\")", ((cpp_function_code)(&printSpaces)), NULL);
    defineFunctionObject("INFORM", "(DEFUN INFORM (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Print informative message, placing non-string arguments in quotes,\nand terminating with a newline.\")", ((cpp_function_code)(&inform)), NULL);
    defineFunctionObject("WARN", "(DEFUN WARN (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Signal warning message, placing non-string arguments in quotes.\")", ((cpp_function_code)(&warn)), NULL);
    defineFunctionObject("SIGNAL", "(DEFUN SIGNAL ((TYPE SYMBOL) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Signal error message, placing non-string arguments in quotes.\")", ((cpp_function_code)(&signal)), NULL);
    defineFunctionObject("ERROR", "(DEFUN ERROR (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Signal error message, placing non-string arguments in quotes.\")", ((cpp_function_code)(&error)), NULL);
    defineFunctionObject("CONTINUABLE-ERROR", "(DEFUN CONTINUABLE-ERROR (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Signal error message, placing non-string arguments in quotes.\")", ((cpp_function_code)(&continuableError)), NULL);
    defineFunctionObject("SIGNAL-READ-ERROR", "(DEFUN SIGNAL-READ-ERROR (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Specialized version of `signal' that throws a READ-EXCEPTION.\")", ((cpp_function_code)(&signalReadError)), NULL);
    defineFunctionObject("FORMAT-WALK-MESSAGE-ARGUMENTS", "(DEFUN (FORMAT-WALK-MESSAGE-ARGUMENTS CONS) ((MESSAGEARGUMENTSTREE CONS)))", ((cpp_function_code)(&formatWalkMessageArguments)), NULL);
    defineFunctionObject("WALK-ERROR", "(DEFUN WALK-ERROR (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&walkError)), NULL);
    defineFunctionObject("WALK-INFORM", "(DEFUN WALK-INFORM (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&walkInform)), NULL);
    defineFunctionObject("WALK-WARN", "(DEFUN WALK-WARN (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&walkWarn)), NULL);
    defineFunctionObject("SAFETY", "(DEFUN SAFETY ((LEVEL INTEGER-WRAPPER) (TEST OBJECT) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Signal warning message, placing non-string arguments in quotes.\")", ((cpp_function_code)(&safety)), NULL);
    defineFunctionObject("EVALUATION-ERROR", "(DEFUN EVALUATION-ERROR (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&evaluationError)), NULL);
    defineFunctionObject("FORMAT-STRING-MESSAGE-ARGUMENTS", "(DEFUN (FORMAT-STRING-MESSAGE-ARGUMENTS CONS) ((MESSAGEARGUMENTS CONS) (TRAILINGEOL? BOOLEAN)))", ((cpp_function_code)(&formatStringMessageArguments)), NULL);
    defineFunctionObject("MESSAGE-TO-STRING", "(DEFUN MESSAGE-TO-STRING (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&messageToString)), NULL);
    defineFunctionObject("TERMINATE-OUTPUT-STREAM?", "(DEFUN (TERMINATE-OUTPUT-STREAM? BOOLEAN) ((SELF OUTPUT-STREAM)))", ((cpp_function_code)(&terminateOutputStreamP)), NULL);
    defineFunctionObject("TERMINATE-INPUT-STREAM?", "(DEFUN (TERMINATE-INPUT-STREAM? BOOLEAN) ((SELF INPUT-STREAM)))", ((cpp_function_code)(&terminateInputStreamP)), NULL);
    defineFunctionObject("INITIALIZE-FILE-OUTPUT-STREAM", "(DEFUN INITIALIZE-FILE-OUTPUT-STREAM ((SELF FILE-OUTPUT-STREAM)))", ((cpp_function_code)(&initializeFileOutputStream)), NULL);
    defineFunctionObject("TERMINATE-FILE-OUTPUT-STREAM?", "(DEFUN (TERMINATE-FILE-OUTPUT-STREAM? BOOLEAN) ((SELF FILE-OUTPUT-STREAM)))", ((cpp_function_code)(&terminateFileOutputStreamP)), NULL);
    defineFunctionObject("INITIALIZE-FILE-INPUT-STREAM", "(DEFUN INITIALIZE-FILE-INPUT-STREAM ((SELF FILE-INPUT-STREAM)))", ((cpp_function_code)(&initializeFileInputStream)), NULL);
    defineFunctionObject("TERMINATE-FILE-INPUT-STREAM?", "(DEFUN (TERMINATE-FILE-INPUT-STREAM? BOOLEAN) ((SELF FILE-INPUT-STREAM)))", ((cpp_function_code)(&terminateFileInputStreamP)), NULL);
    defineFunctionObject("INITIALIZE-STRING-OUTPUT-STREAM", "(DEFUN INITIALIZE-STRING-OUTPUT-STREAM ((SELF STRING-OUTPUT-STREAM)))", ((cpp_function_code)(&initializeStringOutputStream)), NULL);
    defineMethodObject("(DEFMETHOD (THE-STRING-READER STRING) ((SELF STRING-OUTPUT-STREAM)))", ((cpp_method_code)(&OutputStringStream::theStringReader)), ((cpp_method_code)(NULL)));
    defineFunctionObject("INITIALIZE-STRING-INPUT-STREAM", "(DEFUN INITIALIZE-STRING-INPUT-STREAM ((SELF STRING-INPUT-STREAM)))", ((cpp_function_code)(&initializeStringInputStream)), NULL);
    defineFunctionObject("CLOSE-STREAM", "(DEFUN CLOSE-STREAM ((SELF STREAM)) :DOCUMENTATION \"Close the stream `self'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&closeStream)), NULL);
    defineFunctionObject("FLUSH-OUTPUT", "(DEFUN FLUSH-OUTPUT ((SELF OUTPUT-STREAM)) :DOCUMENTATION \"Flush all buffered output of `self'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&flushOutput)), NULL);
    defineFunctionObject("CLOSE-ALL-FILES", "(DEFUN CLOSE-ALL-FILES () :DOCUMENTATION \"Close all currently open file streams.  Use for emergencies or for cleanup.\" :PUBLIC? TRUE)", ((cpp_function_code)(&closeAllFiles)), NULL);
    defineFunctionObject("OPEN-NETWORK-STREAM", "(DEFUN (OPEN-NETWORK-STREAM INPUT-STREAM OUTPUT-STREAM) ((HOST STRING) (PORT INTEGER)) :DOCUMENTATION \"Open a TCP/IP network stream to `host' at `port' and return the result\nas an input/output stream pair.\" :PUBLIC? TRUE)", ((cpp_function_code)(&openNetworkStream)), NULL);
    defineFunctionObject("WITH-INPUT-FILE", "(DEFUN WITH-INPUT-FILE ((BINDING CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Sets up an unwind-protected form which opens a file for\ninput and closes it afterwards.  The stream for reading is bound to the\nvariable provided in the macro form.\nSyntax is (WITH-INPUT-FILE (var filename) body+)\")", ((cpp_function_code)(&withInputFile)), NULL);
    defineFunctionObject("WITH-OUTPUT-FILE", "(DEFUN WITH-OUTPUT-FILE ((BINDING CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Sets up an unwind-protected form which opens a file for\noutput and closes it afterwards.  The stream for writing is bound to the\nvariable provided in the macro form.\nSyntax is (WITH-OUTPUT-FILE (var filename) body+)\")", ((cpp_function_code)(&withOutputFile)), NULL);
    defineFunctionObject("WITH-NETWORK-STREAM", "(DEFUN WITH-NETWORK-STREAM ((BINDING CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Sets up an unwind-protected form which opens a network\nsocket stream to a host and port for input and output and closes it afterwards.\nSeparate variables as provided in the call are bound to the input and output\nstreams. Syntax is (WITH-NETWORK-STREAM (varIn varOut hostname port) body+)\")", ((cpp_function_code)(&withNetworkStream)), NULL);
    defineFunctionObject("EXPAND-MARKUP-TAG-FUNCTION", "(DEFUN (EXPAND-MARKUP-TAG-FUNCTION CONS) ((TAG-AND-STREAM CONS) (BODY CONS) (XML? BOOLEAN)))", ((cpp_function_code)(&expandMarkupTagFunction)), NULL);
    defineFunctionObject("WITH-HTML-TAG", "(DEFUN WITH-HTML-TAG ((TAG-AND-STREAM CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&withHtmlTag)), NULL);
    defineFunctionObject("WITH-XML-TAG", "(DEFUN WITH-XML-TAG ((TAG-AND-STREAM CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&withXmlTag)), NULL);
    defineFunctionObject("HTML-CHARACTER-NEEDS-QUOTING?", "(DEFUN (HTML-CHARACTER-NEEDS-QUOTING? BOOLEAN) ((CH CHARACTER)))", ((cpp_function_code)(&htmlCharacterNeedsQuotingP)), NULL);
    defineFunctionObject("WRITE-HTML-CHARACTER-QUOTING-SPECIAL-CHARACTERS", "(DEFUN WRITE-HTML-CHARACTER-QUOTING-SPECIAL-CHARACTERS ((STREAM NATIVE-OUTPUT-STREAM) (CH CHARACTER)) :GLOBALLY-INLINE? TRUE (CASE CH (#\\> (PRINT-STREAM STREAM \"&gt;\")) (#\\< (PRINT-STREAM STREAM \"&lt;\")) (#\\& (PRINT-STREAM STREAM \"&amp;\")) (#\\\" (PRINT-STREAM STREAM \"&quot;\")) (OTHERWISE (PRINT-STREAM STREAM CH))) (RETURN))", ((cpp_function_code)(&writeHtmlCharacterQuotingSpecialCharacters)), NULL);
    defineFunctionObject("WRITE-HTML-QUOTING-SPECIAL-CHARACTERS", "(DEFUN WRITE-HTML-QUOTING-SPECIAL-CHARACTERS ((STREAM NATIVE-OUTPUT-STREAM) (INPUT STRING)))", ((cpp_function_code)(&writeHtmlQuotingSpecialCharacters)), NULL);
    defineFunctionObject("WRITE-HTML-ESCAPING-URL-SPECIAL-CHARACTERS", "(DEFUN WRITE-HTML-ESCAPING-URL-SPECIAL-CHARACTERS ((STREAM NATIVE-OUTPUT-STREAM) (INPUT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Writes a string and replaces unallowed URL characters according to RFC 2396\nwith %-format URL escape sequences.\")", ((cpp_function_code)(&writeHtmlEscapingUrlSpecialCharacters)), NULL);
    defineFunctionObject("HEX-CHARACTER-VALUE", "(DEFUN (HEX-CHARACTER-VALUE INTEGER) ((C CHARACTER)) :GLOBALLY-INLINE? TRUE (LET ((V (POSITION \"0123456789ABCDEF\" C 0))) (WHEN (NULL? V) (SETQ V (POSITION \"0123456789abcdef\" C 0))) (RETURN V)))", ((cpp_function_code)(&hexCharacterValue)), NULL);
    defineFunctionObject("UNESCAPE-URL-STRING", "(DEFUN (UNESCAPE-URL-STRING STRING) ((INPUT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Takes a string and replaces %-format URL escape sequences with their real\ncharacter equivalent according to RFC 2396.\")", ((cpp_function_code)(&unescapeUrlString)), NULL);
    defineFunctionObject("UNESCAPE-HTML-STRING", "(DEFUN (UNESCAPE-HTML-STRING STRING) ((INPUT STRING)) :DOCUMENTATION \"Replaces HTML escape sequences such as &amp; with their\nassociated characters.\" :PUBLIC? TRUE)", ((cpp_function_code)(&unescapeHtmlString)), NULL);
    defineFunctionObject("TERMINATE-STREAM-ITERATOR?", "(DEFUN (TERMINATE-STREAM-ITERATOR? BOOLEAN) ((SELF STREAM-ITERATOR)))", ((cpp_function_code)(&terminateStreamIteratorP)), NULL);
    defineFunctionObject("S-EXPRESSIONS", "(DEFUN (S-EXPRESSIONS S-EXPRESSION-ITERATOR) ((STREAM INPUT-STREAM)) :PUBLIC? TRUE)", ((cpp_function_code)(&sExpressions)), NULL);
    defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF S-EXPRESSION-ITERATOR)) :PUBLIC? TRUE)", ((cpp_method_code)(&SExpressionIterator::nextP)), ((cpp_method_code)(NULL)));
    defineFunctionObject("LINES", "(DEFUN (LINES LINE-ITERATOR) ((STREAM INPUT-STREAM)) :PUBLIC? TRUE)", ((cpp_function_code)(&lines)), NULL);
    defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF LINE-ITERATOR)) :PUBLIC? TRUE)", ((cpp_method_code)(&LineIterator::nextP)), ((cpp_method_code)(NULL)));
    defineFunctionObject("CHARACTERS", "(DEFUN (CHARACTERS CHARACTER-ITERATOR) ((STREAM INPUT-STREAM)) :PUBLIC? TRUE)", ((cpp_function_code)(&characters)), NULL);
    defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF CHARACTER-ITERATOR)) :PUBLIC? TRUE)", ((cpp_method_code)(&CharacterIterator::nextP)), ((cpp_method_code)(NULL)));
    defineFunctionObject("STARTUP-STREAMS", "(DEFUN STARTUP-STREAMS () :PUBLIC? TRUE)", ((cpp_function_code)(&startupStreams)), NULL);
    { MethodSlot* function = lookupFunction(SYM_STREAMS_STELLA_STARTUP_STREAMS);

      setDynamicSlotValue(function->dynamicSlots, SYM_STREAMS_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Streams"), NULL_STRING_WRAPPER);
    }
  }
}

void startupStreams() {
  if (currentStartupTimePhaseP(0)) {
    { OutputStream* self001 = newOutputStream();

      self001->nativeStream = &std::cout;
      STANDARD_OUTPUT = self001;
    }
    if (!(((boolean)(STANDARD_WARNING)))) {
      { OutputStream* self002 = newOutputStream();

        self002->nativeStream = &std::cerr;
        STANDARD_WARNING = self002;
      }
    }
    { OutputStream* self003 = newOutputStream();

      self003->nativeStream = &std::cerr;
      STANDARD_ERROR = self003;
    }
  }
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oSTELLA_MODULEo);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupStreams1();
      helpStartupStreams2();
    }
    if (currentStartupTimePhaseP(4)) {
      helpStartupStreams3();
    }
    if (currentStartupTimePhaseP(5)) {
      { Class* clasS = defineClassFromStringifiedSource("STREAM-ITERATOR", "(DEFCLASS STREAM-ITERATOR (ABSTRACT-ITERATOR) :PUBLIC? TRUE :ABSTRACT? TRUE :DOCUMENTATION \"Iterator that yields tokens from an input stream.\" :SLOTS ((THE-STREAM :TYPE INPUT-STREAM)) :TERMINATOR TERMINATE-STREAM-ITERATOR?)");

        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessStreamIteratorSlotValue));
      }
      { Class* clasS = defineClassFromStringifiedSource("S-EXPRESSION-ITERATOR", "(DEFCLASS S-EXPRESSION-ITERATOR (STREAM-ITERATOR) :PUBLIC? TRUE :DOCUMENTATION \"Iterator that yields s-expressions from an input stream.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newSExpressionIterator));
      }
      { Class* clasS = defineClassFromStringifiedSource("LINE-ITERATOR", "(DEFCLASS LINE-ITERATOR (STREAM-ITERATOR) :PUBLIC? TRUE :DOCUMENTATION \"Iterator that yields lines from an input stream.\" :PARAMETERS ((ANY-VALUE :TYPE STRING)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newLineIterator));
      }
      { Class* clasS = defineClassFromStringifiedSource("CHARACTER-ITERATOR", "(DEFCLASS CHARACTER-ITERATOR (STREAM-ITERATOR) :PUBLIC? TRUE :DOCUMENTATION \"Iterator that yields characters from an input stream.\" :PARAMETERS ((ANY-VALUE :TYPE CHARACTER)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newCharacterIterator));
      }
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupStreams4();
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL EOL SYMBOL (QUOTE EOL) :DOCUMENTATION \"Generates a newline character when passed to a stream.\" :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL EOL-STRING STRING \"\n\" :DOCUMENTATION \"A string constant containing the character sequence\nnecessary to generate a newline.\" :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL STANDARD-INPUT INPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard input stream for the host language.\" :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL STANDARD-OUTPUT OUTPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard output stream for the host language.\" :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL STANDARD-WARNING OUTPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard warning stream for the host language.\" :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL STANDARD-ERROR OUTPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard error stream for the host language.\" :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *IGNORETRANSLATIONERRORS?* BOOLEAN TRUE :DOCUMENTATION \"If `true' all passes of a translation will always be performed\nregardless of whether any errors were encountered.  Otherwise, translation\nends with the first pass that encountered an error.\" :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL SINGLE-QUOTE-STRING STRING-WRAPPER (WRAP-LITERAL \"'\") :DOCUMENTATION \"Holds a string containing the single quote character.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL SINGLE-BQUOTE-STRING STRING-WRAPPER (WRAP-LITERAL \"`\") :DOCUMENTATION \"Holds a string containing the single backquote character.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *OPEN-FILE-STREAMS* (LIST OF STREAM) (NEW (LIST OF STREAM)) :DOCUMENTATION \"List of file streams that are currently open.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *HTML-QUOTED-CHARACTERS* STRING \"><&\\\"\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *HTML-ESCAPE-TABLE* KEY-VALUE-LIST (NEW KEY-VALUE-LIST))");
      oHTML_ESCAPE_TABLEo->insertAt(wrapString("lt"), wrapCharacter('<'));
      oHTML_ESCAPE_TABLEo->insertAt(wrapString("gt"), wrapCharacter('>'));
      oHTML_ESCAPE_TABLEo->insertAt(wrapString("amp"), wrapCharacter('&'));
      oHTML_ESCAPE_TABLEo->insertAt(wrapString("quot"), wrapCharacter('"'));
      oHTML_ESCAPE_TABLEo->insertAt(wrapString("apos"), wrapCharacter('\''));
      oHTML_ESCAPE_TABLEo->insertAt(wrapString("nbsp"), wrapCharacter(' '));
      oHTML_ESCAPE_TABLEo->insertAt(wrapString("NBSP"), wrapCharacter(' '));
    }
  }
}

Symbol* SYM_STREAMS_STELLA_EOL = NULL;

Symbol* SYM_STREAMS_STELLA_PRINT_STREAM = NULL;

Symbol* SYM_STREAMS_STELLA_STANDARD_OUTPUT = NULL;

Symbol* SYM_STREAMS_STELLA_FOREACH = NULL;

Symbol* SYM_STREAMS_STELLA_I = NULL;

Symbol* SYM_STREAMS_STELLA_IN = NULL;

Symbol* SYM_STREAMS_STELLA_INTERVAL = NULL;

Symbol* SYM_STREAMS_STELLA_DO = NULL;

Symbol* SYM_STREAMS_STELLA_IGNORE = NULL;

Keyword* KWD_STREAMS_COMMON_LISP = NULL;

Keyword* KWD_STREAMS_WARN = NULL;

Symbol* SYM_STREAMS_STELLA_STANDARD_WARNING = NULL;

Symbol* SYM_STREAMS_STELLA_NULL = NULL;

Symbol* SYM_STREAMS_STELLA_STELLA_EXCEPTION = NULL;

Surrogate* SGT_STREAMS_STELLA_STRING_WRAPPER = NULL;

Symbol* SYM_STREAMS_STELLA_SIGNAL_EXCEPTION = NULL;

Symbol* SYM_STREAMS_STELLA_NEW = NULL;

Keyword* KWD_STREAMS_MESSAGE = NULL;

Symbol* SYM_STREAMS_STELLA_LET = NULL;

Symbol* SYM_STREAMS_STELLA_OUTPUT_STRING_STREAM = NULL;

Symbol* SYM_STREAMS_STELLA_THE_STRING = NULL;

Symbol* SYM_STREAMS_STELLA_SIGNAL = NULL;

Keyword* KWD_STREAMS_JAVA = NULL;

Symbol* SYM_STREAMS_STELLA_ERROR_MESSAGE_ = NULL;

Symbol* SYM_STREAMS_STELLA_VERBATIM = NULL;

Keyword* KWD_STREAMS_CONTINUABLE_ERROR = NULL;

Symbol* SYM_STREAMS_STELLA_READ_EXCEPTION = NULL;

Symbol* SYM_STREAMS_STELLA_DE_UGLIFY_PARSE_TREE = NULL;

Symbol* SYM_STREAMS_STELLA_SPECIAL = NULL;

Symbol* SYM_STREAMS_STELLA_oPRINTREADABLYpo = NULL;

Symbol* SYM_STREAMS_STELLA_TRUE = NULL;

Symbol* SYM_STREAMS_STELLA_SIGNAL_TRANSLATION_ERROR = NULL;

Symbol* SYM_STREAMS_STELLA_UNLESS = NULL;

Symbol* SYM_STREAMS_STELLA_SUPPRESS_WARNINGSp = NULL;

Symbol* SYM_STREAMS_STELLA_PRINT_ERROR_CONTEXT = NULL;

Symbol* SYM_STREAMS_STELLA_STANDARD_ERROR = NULL;

Symbol* SYM_STREAMS_STELLA_SIGNAL_TRANSLATION_WARNING = NULL;

Symbol* SYM_STREAMS_STELLA_WHEN = NULL;

Symbol* SYM_STREAMS_STELLA_NOT = NULL;

Keyword* KWD_STREAMS_ERROR = NULL;

Symbol* SYM_STREAMS_STELLA_oEVALUATIONTREEo = NULL;

Symbol* SYM_STREAMS_STELLA_DEFINEDp = NULL;

Symbol* SYM_STREAMS_STELLA_oEVALUATIONPARENTTREEo = NULL;

Symbol* SYM_STREAMS_STELLA_EVALUATION_EXCEPTION = NULL;

Surrogate* SGT_STREAMS_STELLA_LITERAL_WRAPPER = NULL;

Symbol* SYM_STREAMS_STELLA_STRINGIFY = NULL;

Symbol* SYM_STREAMS_STELLA_VRLET = NULL;

Symbol* SYM_STREAMS_STELLA_STRING = NULL;

Symbol* SYM_STREAMS_STELLA_SETQ = NULL;

Symbol* SYM_STREAMS_STELLA_CONCATENATE = NULL;

Keyword* KWD_STREAMS_CLOSED = NULL;

Keyword* KWD_STREAMS_OPEN = NULL;

Surrogate* SGT_STREAMS_STELLA_FILE_INPUT_STREAM = NULL;

Surrogate* SGT_STREAMS_STELLA_FILE_OUTPUT_STREAM = NULL;

Surrogate* SGT_STREAMS_STELLA_INPUT_STREAM = NULL;

Surrogate* SGT_STREAMS_STELLA_OUTPUT_STREAM = NULL;

Symbol* SYM_STREAMS_STELLA_FILE_INPUT_STREAM = NULL;

Symbol* SYM_STREAMS_STELLA_UNWIND_PROTECT = NULL;

Symbol* SYM_STREAMS_STELLA_PROGN = NULL;

Keyword* KWD_STREAMS_FILENAME = NULL;

Symbol* SYM_STREAMS_STELLA_FREE = NULL;

Symbol* SYM_STREAMS_STELLA_FILE_OUTPUT_STREAM = NULL;

Symbol* SYM_STREAMS_STELLA_INPUT_STREAM = NULL;

Symbol* SYM_STREAMS_STELLA_OUTPUT_STREAM = NULL;

Symbol* SYM_STREAMS_STELLA_MV_SETQ = NULL;

Symbol* SYM_STREAMS_STELLA_OPEN_NETWORK_STREAM = NULL;

Surrogate* SGT_STREAMS_STELLA_OBJECT = NULL;

Symbol* SYM_STREAMS_STELLA_SUBSEQUENCE = NULL;

Symbol* SYM_STREAMS_STELLA_POSITION = NULL;

Symbol* SYM_STREAMS_STELLA_THE_STREAM = NULL;

Surrogate* SGT_STREAMS_STELLA_S_EXPRESSION_ITERATOR = NULL;

Surrogate* SGT_STREAMS_STELLA_LINE_ITERATOR = NULL;

Surrogate* SGT_STREAMS_STELLA_CHARACTER_ITERATOR = NULL;

Symbol* SYM_STREAMS_STELLA_STARTUP_STREAMS = NULL;

Symbol* SYM_STREAMS_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace stella
