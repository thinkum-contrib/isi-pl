//  -*- Mode: C++ -*-

// read.hh

/*
+---------------------------- BEGIN LICENSE BLOCK ---------------------------+
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
| Portions created by the Initial Developer are Copyright (C) 1996-2006      |
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
+---------------------------- END LICENSE BLOCK -----------------------------+
*/


namespace stella {

// Class definitions:
class TokenizerTable : public StandardObject {
public:
  char* transitions;
  Vector* uniqueStateNames;
  Vector* stateNames;
  Vector* legalEofStates;
public:
  virtual Surrogate* primaryType();
};

class TokenizerToken : public StandardObject {
public:
  Keyword* type;
  char* content;
  TokenizerToken* next;
public:
  virtual Surrogate* primaryType();
};

class TokenizerStreamState : public StandardObject {
public:
  char* buffer;
  int bufferSize;
  int cursor;
  int end;
  int state;
  TokenizerTable* table;
  Dictionary* stateDictionary;
  TokenizerToken* tokenList;
public:
  virtual int getSavedState(TokenizerTable* table);
  virtual Surrogate* primaryType();
};

class StreamTokenizer : public Iterator {
// Iterator that generates tokens by tokenizing a `stream'
// according to a particular tokenization `table'.
public:
  InputStream* stream;
  TokenizerTable* table;
public:
  virtual boolean nextP();
  virtual Surrogate* primaryType();
};

class StellaToken : public TokenizerToken {
public:
  Keyword* logicalTokenType;
  char* module;
  Keyword* escapeMode;
public:
  virtual Surrogate* primaryType();
};


// Global declarations:
extern int oMAX_TOKENIZER_STATESo;
extern int oMAX_TOKENIZER_CHARACTERSo;
extern int oTOKENIZER_INITIAL_BUFFER_SIZEo;
extern DECLARE_STELLA_SPECIAL(oWITHTOKENIZERINPUTTYPEo, Surrogate* );
extern Cons* oSTELLA_TOKENIZER_TABLE_DEFINITIONo;
extern TokenizerTable* oSTELLA_TOKENIZER_TABLEo;
extern Vector* oSTELLA_LOGICAL_STATE_NAMESo;
extern PropertyList* oSTELLA_LOGICAL_STATE_NAMES_TABLEo;
extern int oSTELLA_TOKENIZER_WHITE_SPACE_STATEo;
extern Cons* oREAD_LINE_TOKENIZER_TABLE_DEFINITIONo;
extern Cons* oREAD_LINE2_TOKENIZER_TABLE_DEFINITIONo;
extern TokenizerTable* oREAD_LINE_TOKENIZER_TABLEo;
extern TokenizerTable* oREAD_LINE2_TOKENIZER_TABLEo;
extern DECLARE_STELLA_SPECIAL(oUSER_QUERY_ACTIONo, Keyword* );

// Function signatures:
TokenizerTable* newTokenizerTable();
Object* accessTokenizerTableSlotValue(TokenizerTable* self, Symbol* slotname, Object* value, boolean setvalueP);
TokenizerTable* parseTokenizerDefinition(Cons* definition);
boolean legalTokenizerStateP(Object* x);
boolean legalTokenizerFromStateP(Object* x);
boolean legalTokenizerToStateP(Object* x);
GeneralizedSymbol* tokenizerToStateName(Object* state);
GeneralizedSymbol* tokenizerToStateAlias(Object* state);
int parseTokenizerStateModifiers(Object* modifier);
boolean tokenizerIncludeSpecP(Object* x);
Cons* parseTokenizerCharacterSpec(Object* characterspec, List* allcharactersets);
char* stringifyTokenizerTable(TokenizerTable* table);
TokenizerTable* unstringifyTokenizerTable(char* table);
char* makeTokenizerByteArray(int size);
char* stringToTokenizerByteArray(char* string);
char* tokenizerByteArrayToString(char* bytes);
char tokenizerByteArrayByteArrayNth(char* buffer, int position);
char tokenizerByteArrayByteArrayNthSetter(char* buffer, char ch, int position);
int nativeByteArrayReadSequence(char* buffer, std::istream* stream, int start, int end);
int tokenizerByteArrayReadSequence(char* buffer, InputStream* stream, int start, int end);
int byteArrayReadSequence(char* buffer, InputStream* stream, int start, int end);
void nativeByteArrayWriteSequence(char* buffer, std::ostream* stream, int start, int end);
void byteArrayWriteSequence(char* buffer, std::ostream* stream, int start, int end);
void ensureTokenizerBufferSize(TokenizerStreamState* state, int currenttokenstart, int requiredspace);
boolean readIntoTokenizerBuffer(InputStream* stream, TokenizerStreamState* state, int currenttokenstart);
char readCharacterFromTokenizerBuffer(InputStream* stream, boolean& _Return1);
void unreadCharacterFromTokenizerBuffer(char chaR, InputStream* stream);
char* readLineFromTokenizerBuffer(InputStream* stream);
TokenizerToken* newTokenizerToken();
Object* accessTokenizerTokenSlotValue(TokenizerToken* self, Symbol* slotname, Object* value, boolean setvalueP);
TokenizerStreamState* newTokenizerStreamState();
Object* accessTokenizerStreamStateSlotValue(TokenizerStreamState* self, Symbol* slotname, Object* value, boolean setvalueP);
Object* withTokenizer(Object* table, Object* input, Cons* body);
boolean withTokenizerStringInputP();
boolean insideWithTokenizerP();
Object* endOfTokensP();
Object* getTokenText(Cons* options);
char* getTokenTextInternal(char* buffer, int start, int end, int size, boolean upcaseP);
Object* getTokenType();
Object* saveTokenizerStreamState();
Object* getNextToken(Cons* options);
char* unescapeTokenString(char* token, char escapechar, boolean upcaseP);
StreamTokenizer* newStreamTokenizer(InputStream* stream, TokenizerTable* table);
Object* accessStreamTokenizerSlotValue(StreamTokenizer* self, Symbol* slotname, Object* value, boolean setvalueP);
Object* withStellaTokenizer(Object* input, Cons* body);
Object* getNextStellaToken(Cons* options);
Object* getStellaTokenType();
Object* getQualifiedSymbolSeparatorPosition(Cons* escapemode);
int getQualifiedSymbolSeparatorPositionInternal(char* buffer, int tokenstart, int tokenend, int size, Keyword* escapemode);
StellaToken* newStellaToken();
Object* accessStellaTokenSlotValue(StellaToken* self, Symbol* slotname, Object* value, boolean setvalueP);
StellaToken* tokenizeSExpression(InputStream* stream, StellaToken* tokenlist);
char* parseStellaName(char* name, boolean enablecaseconversionP, char*& _Return1, Keyword*& _Return2);
boolean qualifiedStellaNameP(char* name);
Object* stellaTokenListToSExpression(StellaToken* tokenlist);
void expandQuoteMacroToken(StellaToken* quotedlist);
char stringToCharacter(char* name);
Object* readSExpression(InputStream* stream, boolean& _Return1);
boolean eatNextCharacterIfWhitespace(InputStream* stream);
boolean consumeWhitespace(InputStream* stream);
Object* readSExpressionFromString(char* string);
InputStringStream* makeTokenizerStringStream(char* string);
char* nativeReadLine(InputStream* inputstream);
char* readLine(InputStream* stream);
char* readLine2(InputStream* stream, Keyword*& _Return1);
char readCharacter(InputStream* inputstream, boolean& _Return1);
void unreadCharacter(char ch, InputStream* inputstream);
boolean yesOrNoP(char* message);
boolean yOrNP(char* message);
void helpStartupRead1();
void helpStartupRead2();
void helpStartupRead3();
void helpStartupRead4();
void helpStartupRead5();
void helpStartupRead6();
void helpStartupRead7();
void startupRead();

// Auxiliary global declarations:
extern Surrogate* SGT_READ_STELLA_TOKENIZER_TABLE;
extern Symbol* SYM_READ_STELLA_TRANSITIONS;
extern Symbol* SYM_READ_STELLA_UNIQUE_STATE_NAMES;
extern Symbol* SYM_READ_STELLA_STATE_NAMES;
extern Symbol* SYM_READ_STELLA_LEGAL_EOF_STATES;
extern Symbol* SYM_READ_STELLA_CHARACTER_SET;
extern Keyword* KWD_READ_ERROR;
extern Keyword* KWD_READ_START;
extern Keyword* KWD_READ_EOF;
extern Surrogate* SGT_READ_STELLA_GENERALIZED_SYMBOL;
extern Surrogate* SGT_READ_STELLA_CONS;
extern Keyword* KWD_READ_BLOCK;
extern Keyword* KWD_READ_LINE;
extern Keyword* KWD_READ_CHARACTER;
extern Surrogate* SGT_READ_STELLA_TOKENIZER_TOKEN;
extern Symbol* SYM_READ_STELLA_TYPE;
extern Symbol* SYM_READ_STELLA_CONTENT;
extern Symbol* SYM_READ_STELLA_NEXT;
extern Surrogate* SGT_READ_STELLA_TOKENIZER_STREAM_STATE;
extern Symbol* SYM_READ_STELLA_BUFFER_SIZE;
extern Symbol* SYM_READ_STELLA_CURSOR;
extern Symbol* SYM_READ_STELLA_END;
extern Symbol* SYM_READ_STELLA_STATE;
extern Symbol* SYM_READ_STELLA_TABLE;
extern Symbol* SYM_READ_STELLA_STATE_DICTIONARY;
extern Symbol* SYM_READ_STELLA_TOKEN_LIST;
extern Surrogate* SGT_READ_STELLA_INPUT_STREAM;
extern Surrogate* SGT_READ_STELLA_STRING;
extern Surrogate* SGT_READ_STELLA_VOID;
extern Surrogate* SGT_READ_STELLA_MUTABLE_STRING;
extern Symbol* SYM_READ_STELLA_LET;
extern Symbol* SYM_READ_STELLA_TOK_TABLE_;
extern Symbol* SYM_READ_STELLA_TOK_TRANSITIONS_;
extern Symbol* SYM_READ_STELLA_TOK_STATENAMES_;
extern Symbol* SYM_READ_STELLA_THE_ARRAY;
extern Symbol* SYM_READ_STELLA_TOK_TOKENSTART_;
extern Symbol* SYM_READ_STELLA_TOK_ENDOFTOKENSp_;
extern Symbol* SYM_READ_STELLA_FALSE;
extern Symbol* SYM_READ_STELLA_IGNORE;
extern Symbol* SYM_READ_STELLA_TOK_STREAMSTATE_;
extern Symbol* SYM_READ_STELLA_TOKENIZER_STREAM_STATE;
extern Symbol* SYM_READ_STELLA_NULL;
extern Symbol* SYM_READ_STELLA_TOK_BUFFER_;
extern Symbol* SYM_READ_STELLA_STRING_TO_TOKENIZER_BYTE_ARRAY;
extern Symbol* SYM_READ_STELLA_TOK_STATE_;
extern Symbol* SYM_READ_STELLA_TOK_NEXTSTATE_;
extern Symbol* SYM_READ_STELLA_TOK_CURSOR_;
extern Symbol* SYM_READ_STELLA_TOK_SIZE_;
extern Symbol* SYM_READ_STELLA_LENGTH;
extern Symbol* SYM_READ_STELLA_TOK_END_;
extern Symbol* SYM_READ_STELLA_TOK_INPUTSTREAM_;
extern Symbol* SYM_READ_STELLA_TOK_ECHOSTREAM_;
extern Symbol* SYM_READ_STELLA_ECHO_STREAM;
extern Symbol* SYM_READ_STELLA_CHOOSE;
extern Symbol* SYM_READ_STELLA_NULLp;
extern Symbol* SYM_READ_STELLA_TOKENIZER_STATE;
extern Symbol* SYM_READ_STELLA_SETF;
extern Symbol* SYM_READ_STELLA_NEW;
extern Symbol* SYM_READ_STELLA_BUFFER;
extern Symbol* SYM_READ_STELLA_GET_SAVED_STATE;
extern Symbol* SYM_READ_STELLA_TOK_CHECKPOINT_;
extern Symbol* SYM_READ_STELLA_le;
extern Symbol* SYM_READ_STELLA_END_OF_TOKENSp;
extern Symbol* SYM_READ_STELLA_GET_TOKEN_TEXT;
extern Symbol* SYM_READ_STELLA_GET_TOKEN_TEXT_INTERNAL;
extern Symbol* SYM_READ_STELLA_i;
extern Symbol* SYM_READ_STELLA_l;
extern Symbol* SYM_READ_STELLA_GET_TOKEN_TYPE;
extern Symbol* SYM_READ_STELLA_NTH;
extern Symbol* SYM_READ_STELLA_WHEN;
extern Symbol* SYM_READ_STELLA_DEFINEDp;
extern Symbol* SYM_READ_STELLA_GET_NEXT_TOKEN;
extern Symbol* SYM_READ_STELLA_SAVE_TOKENIZER_STREAM_STATE;
extern Symbol* SYM_READ_STELLA_TRUE;
extern Symbol* SYM_READ_STELLA_PROGN;
extern Symbol* SYM_READ_STELLA_SETQ;
extern Symbol* SYM_READ_STELLA_LOOP;
extern Symbol* SYM_READ_STELLA_CHARACTER_CODE;
extern Symbol* SYM_READ_STELLA_LOGOR;
extern Symbol* SYM_READ_STELLA_SHIFT_LEFT;
extern Symbol* SYM_READ_STELLA_BYTE_ARRAY_NTH;
extern Symbol* SYM_READ_STELLA_COND;
extern Symbol* SYM_READ_STELLA_e;
extern Symbol* SYM_READ_STELLA_LOGAND;
extern Symbol* SYM_READ_STELLA_ii;
extern Symbol* SYM_READ_STELLA_OTHERWISE;
extern Symbol* SYM_READ_STELLA_BREAK;
extern Symbol* SYM_READ_STELLA_READ_INTO_TOKENIZER_BUFFER;
extern Symbol* SYM_READ_STELLA_MOD;
extern Symbol* SYM_READ_STELLA_UNLESS;
extern Symbol* SYM_READ_STELLA_IF;
extern Symbol* SYM_READ_STELLA_ge;
extern Symbol* SYM_READ_STELLA_PRINT_STREAM;
extern Symbol* SYM_READ_STELLA_1_;
extern Surrogate* SGT_READ_STELLA_STREAM_TOKENIZER;
extern Symbol* SYM_READ_STELLA_STREAM;
extern Keyword* KWD_READ_INCLUDE;
extern Keyword* KWD_READ_DELIMITER;
extern Keyword* KWD_READ_ATOM;
extern Symbol* SYM_READ_STELLA_o;
extern Keyword* KWD_READ_OPEN_PAREN;
extern Keyword* KWD_READ_CLOSE_PAREN;
extern Keyword* KWD_READ_OPEN_STRING;
extern Keyword* KWD_READ_STRING;
extern Keyword* KWD_READ_SINGLE_QUOTE;
extern Keyword* KWD_READ_BACK_QUOTE;
extern Keyword* KWD_READ_COMMA;
extern Symbol* SYM_READ_STELLA_x;
extern Keyword* KWD_READ_COMMENT;
extern Keyword* KWD_READ_HASH;
extern Keyword* KWD_READ_WHITE_SPACE;
extern Keyword* KWD_READ_OTHERWISE;
extern Keyword* KWD_READ_PAREN_COMMENT;
extern Keyword* KWD_READ_PAREN_COMMENT_ESCAPE;
extern Keyword* KWD_READ_PAREN_COMMENT_BAR;
extern Keyword* KWD_READ_ANY;
extern Keyword* KWD_READ_COMMA_SPLICE;
extern Keyword* KWD_READ_SYMBOL_OR_SIGNED_NUMBER;
extern Keyword* KWD_READ_SYMBOL;
extern Keyword* KWD_READ_SYMBOL_OR_NUMBER;
extern Keyword* KWD_READ_INTEGER;
extern Keyword* KWD_READ_SYMBOL_OR_CL_SYMBOL;
extern Keyword* KWD_READ_OPEN_FULLY_ESCAPED_SYMBOL;
extern Keyword* KWD_READ_FULLY_ESCAPED_SYMBOL;
extern Keyword* KWD_READ_ESCAPED_SYMBOL_ESCAPE;
extern Keyword* KWD_READ_QUALIFIED_NAME;
extern Keyword* KWD_READ_OPEN_KEYWORD;
extern Keyword* KWD_READ_KEYWORD;
extern Keyword* KWD_READ_OPEN_SURROGATE;
extern Keyword* KWD_READ_SURROGATE;
extern Keyword* KWD_READ_CLOSE_STRING;
extern Keyword* KWD_READ_STRING_ESCAPE;
extern Keyword* KWD_READ_ESCAPED_STRING;
extern Keyword* KWD_READ_CHARACTER_CONSTANT;
extern Keyword* KWD_READ_SYMBOL_OR_MANTISSA;
extern Keyword* KWD_READ_SYMBOL_OR_MANTISSA2;
extern Keyword* KWD_READ_FLOAT;
extern Keyword* KWD_READ_SYMBOL_OR_EXPONENT_DELIMITER;
extern Keyword* KWD_READ_SYMBOL_OR_EXPONENT;
extern Keyword* KWD_READ_SYMBOL_OR_EXPONENT2;
extern Keyword* KWD_READ_SYMBOL_OR_CL_SYMBOL2;
extern Keyword* KWD_READ_SYMBOL_OR_CL_SYMBOL3;
extern Keyword* KWD_READ_CL_SYMBOL;
extern Keyword* KWD_READ_ESCAPED_SYMBOL;
extern Keyword* KWD_READ_CLOSE_FULLY_ESCAPED_NAME;
extern Keyword* KWD_READ_FULLY_ESCAPED_SYMBOL_ESCAPE;
extern Keyword* KWD_READ_FULLY_ESCAPED_KEYWORD;
extern Keyword* KWD_READ_ESCAPED_KEYWORD_ESCAPE;
extern Keyword* KWD_READ_ESCAPED_KEYWORD;
extern Keyword* KWD_READ_FULLY_ESCAPED_KEYWORD_ESCAPE;
extern Keyword* KWD_READ_FULLY_ESCAPED_SURROGATE;
extern Keyword* KWD_READ_ESCAPED_SURROGATE_ESCAPE;
extern Keyword* KWD_READ_ESCAPED_SURROGATE;
extern Keyword* KWD_READ_FULLY_ESCAPED_SURROGATE_ESCAPE;
extern Keyword* KWD_READ_QUALIFIED_SURROGATE;
extern Keyword* KWD_READ_QUALIFIED_ESCAPED_SYMBOL_ESCAPE;
extern Keyword* KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL;
extern Keyword* KWD_READ_QUALIFIED_SYMBOL;
extern Keyword* KWD_READ_QUALIFIED_ESCAPED_SURROGATE_ESCAPE;
extern Keyword* KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE;
extern Keyword* KWD_READ_QUALIFIED_ESCAPED_SYMBOL;
extern Keyword* KWD_READ_QUALIFIED_ESCAPED_SURROGATE;
extern Keyword* KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL_ESCAPE;
extern Keyword* KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE_ESCAPE;
extern Keyword* KWD_READ_CLOSE_BALANCED_QUOTE;
extern Symbol* SYM_READ_STELLA_WITH_TOKENIZER;
extern Symbol* SYM_READ_STELLA_oSTELLA_TOKENIZER_TABLEo;
extern Symbol* SYM_READ_STELLA_TOK_STELLALOGICALSTATENAMES_;
extern Symbol* SYM_READ_STELLA_oSTELLA_LOGICAL_STATE_NAMESo;
extern Symbol* SYM_READ_STELLA_TOK_STELLALOGICALSTATENAME_;
extern Symbol* SYM_READ_STELLA_KEYWORD;
extern Keyword* KWD_READ_NONE;
extern Symbol* SYM_READ_STELLA_GET_QUALIFIED_SYMBOL_SEPARATOR_POSITION_INTERNAL;
extern Keyword* KWD_READ_FULLY_ESCAPED;
extern Surrogate* SGT_READ_STELLA_STELLA_TOKEN;
extern Symbol* SYM_READ_STELLA_LOGICAL_TOKEN_TYPE;
extern Symbol* SYM_READ_STELLA_MODULE;
extern Symbol* SYM_READ_STELLA_ESCAPE_MODE;
extern Keyword* KWD_READ_FULL;
extern Keyword* KWD_READ_PARTIAL;
extern Keyword* KWD_READ_ESCAPED;
extern Symbol* SYM_READ_STELLA_a;
extern Symbol* SYM_READ_STELLA_aa;
extern Keyword* KWD_READ_INITIAL_LINEFEED;
extern Keyword* KWD_READ_INITIAL_RETURN;
extern Keyword* KWD_READ_LINEFEED;
extern Keyword* KWD_READ_RETURN;
extern Keyword* KWD_READ_RETURN_LINEFEED;
extern Keyword* KWD_READ_LF;
extern Keyword* KWD_READ_CRLF;
extern Keyword* KWD_READ_CR;
extern Keyword* KWD_READ_ASK;
extern Keyword* KWD_READ_YES;
extern Keyword* KWD_READ_NO;
extern Keyword* KWD_READ_YES_VERBOSE;
extern Keyword* KWD_READ_NO_VERBOSE;
extern Symbol* SYM_READ_STELLA_STARTUP_READ;
extern Symbol* SYM_READ_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace stella
