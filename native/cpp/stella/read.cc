//  -*- Mode: C++ -*-

// read.cc

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

TokenizerTable* newTokenizerTable() {
  { TokenizerTable* self = NULL;

    self = new TokenizerTable();
    self->legalEofStates = NULL;
    self->stateNames = NULL;
    self->uniqueStateNames = NULL;
    self->transitions = NULL;
    return (self);
  }
}

Surrogate* TokenizerTable::primaryType() {
  { TokenizerTable* self = this;

    return (SGT_READ_STELLA_TOKENIZER_TABLE);
  }
}

Object* accessTokenizerTableSlotValue(TokenizerTable* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_READ_STELLA_TRANSITIONS) {
    if (setvalueP) {
      self->transitions = ((StringWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapString(self->transitions);
    }
  }
  else if (slotname == SYM_READ_STELLA_UNIQUE_STATE_NAMES) {
    if (setvalueP) {
      self->uniqueStateNames = ((Vector*)(value));
    }
    else {
      value = self->uniqueStateNames;
    }
  }
  else if (slotname == SYM_READ_STELLA_STATE_NAMES) {
    if (setvalueP) {
      self->stateNames = ((Vector*)(value));
    }
    else {
      value = self->stateNames;
    }
  }
  else if (slotname == SYM_READ_STELLA_LEGAL_EOF_STATES) {
    if (setvalueP) {
      self->legalEofStates = ((Vector*)(value));
    }
    else {
      value = self->legalEofStates;
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

int oMAX_TOKENIZER_STATESo = 64;

int oMAX_TOKENIZER_CHARACTERSo = 256;

TokenizerTable* parseTokenizerDefinition(Cons* definition) {
  { Vector* transitiontable = newVector(oMAX_TOKENIZER_STATESo);
    char* transitions = makeString(oMAX_TOKENIZER_CHARACTERSo, NULL_CHARACTER);
    Vector* uniquestatenames = newVector(oMAX_TOKENIZER_STATESo);
    Vector* statenames = newVector(oMAX_TOKENIZER_STATESo);
    Vector* legaleofstates = newVector(oMAX_TOKENIZER_STATESo);
    GeneralizedSymbol* fromstatename = NULL;
    int fromstateid = NULL_INTEGER;
    GeneralizedSymbol* tostatename = NULL;
    GeneralizedSymbol* tostatealias = NULL;
    int tostateid = NULL_INTEGER;
    int freestateid = 2;
    Object* characterspec = NULL;
    Cons* characterset = NULL;
    List* allcharactersets = newList();
    int statemodifiers = 0;
    boolean errorsP = FALSE;
    TokenizerTable* table = newTokenizerTable();

    (uniquestatenames->theArray)[0] = KWD_READ_ERROR;
    (statenames->theArray)[0] = KWD_READ_ERROR;
    (uniquestatenames->theArray)[1] = KWD_READ_START;
    (statenames->theArray)[1] = KWD_READ_START;
    { Cons* statedefinition = NULL;
      Cons* iter000 = definition;

      while (!(iter000 == NIL)) {
        statedefinition = ((Cons*)(iter000->value));
        iter000 = iter000->rest;
        if (!(legalTokenizerFromStateP(statedefinition->value))) {
          *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal from state: " << "`" << statedefinition->value << "'" << std::endl;
          errorsP = TRUE;
          continue;
        }
        fromstatename = ((GeneralizedSymbol*)(statedefinition->value));
        statedefinition = statedefinition->rest;
        fromstateid = uniquestatenames->position(fromstatename, 0);
        if (fromstateid == NULL_INTEGER) {
          if (freestateid == oMAX_TOKENIZER_STATESo) {
            *(STANDARD_WARNING->nativeStream) << "Warning: " << "Too many tokenizer states; maximum is " << "`" << oMAX_TOKENIZER_STATESo << "'" << std::endl;
            errorsP = TRUE;
            break;
          }
          (uniquestatenames->theArray)[freestateid] = fromstatename;
          (statenames->theArray)[freestateid] = fromstatename;
          fromstateid = freestateid;
          freestateid = freestateid + 1;
        }
        allcharactersets->clear();
        { int i = NULL_INTEGER;
          int iter001 = 0;
          int upperBound000 = oMAX_TOKENIZER_CHARACTERSo - 1;

          while (iter001 <= upperBound000) {
            i = iter001;
            iter001 = iter001 + 1;
            transitions[i] = ((char) 0);
          }
        }
        while (!(statedefinition == NIL)) {
          if (tokenizerIncludeSpecP(statedefinition->value)) {
            if (!(legalTokenizerFromStateP(statedefinition->rest->value))) {
              *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal include specification for state " << "`" << fromstatename << "'" << std::endl;
              errorsP = TRUE;
              break;
            }
            statedefinition = copyConsList(statedefinition);
            { Cons* statedef = NULL;
              Cons* iter002 = definition;

              while (!(iter002 == NIL)) {
                statedef = ((Cons*)(iter002->value));
                iter002 = iter002->rest;
                if (eqlP(statedef->value, statedefinition->rest->value)) {
                  statedefinition->firstSetter(statedef->rest->value);
                  statedefinition->rest = copyConsList(statedef->rest->rest)->concatenate(statedefinition->rest->rest, 0);
                  break;
                }
              }
            }
            continue;
          }
          statemodifiers = parseTokenizerStateModifiers(statedefinition->value);
          if (statemodifiers > 0) {
            statedefinition = statedefinition->rest;
          }
          characterspec = statedefinition->value;
          statedefinition = statedefinition->rest;
          if (!(((boolean)(characterspec)))) {
            *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal definition of " << "`" << fromstatename << "'" << " state" << std::endl;
            errorsP = TRUE;
            break;
          }
          if (!(legalTokenizerToStateP(statedefinition->value))) {
            *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal to state " << "`" << statedefinition->value << "'" << " for state " << "`" << fromstatename << "'" << std::endl;
            errorsP = TRUE;
            break;
          }
          if (characterspec == KWD_READ_EOF) {
            (legaleofstates->theArray)[fromstateid] = TRUE_WRAPPER;
            statedefinition = statedefinition->rest;
            continue;
          }
          tostatename = tokenizerToStateName(statedefinition->value);
          tostatealias = tokenizerToStateAlias(statedefinition->value);
          statedefinition = statedefinition->rest;
          tostateid = uniquestatenames->position(tostatename, 0);
          if (tostateid == NULL_INTEGER) {
            if (freestateid == oMAX_TOKENIZER_STATESo) {
              *(STANDARD_WARNING->nativeStream) << "Warning: " << "Too many tokenizer states; maximum is " << "`" << oMAX_TOKENIZER_STATESo << "'" << std::endl;
              errorsP = TRUE;
              break;
            }
            (uniquestatenames->theArray)[freestateid] = tostatename;
            (statenames->theArray)[freestateid] = tostatealias;
            tostateid = freestateid;
            freestateid = freestateid + 1;
          }
          if ((!(((GeneralizedSymbol*)((statenames->theArray)[tostateid])) == tostatealias)) &&
              ((boolean)(((GeneralizedSymbol*)((statenames->theArray)[tostateid]))))) {
            *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal redefinition of alias " << "`" << tostatealias << "'" << " for state " << "`" << tostatename << "'" << " in state " << "`" << fromstatename << "'" << std::endl;
            errorsP = TRUE;
          }
          characterset = parseTokenizerCharacterSpec(characterspec, allcharactersets);
          if (!((boolean)(characterset))) {
            *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal character specification " << "`" << characterspec << "'" << " for state " << "`" << fromstatename << "'" << std::endl;
            errorsP = TRUE;
            continue;
          }
          allcharactersets->push(characterset);
          { CharacterWrapper* chaR = NULL;
            Cons* iter003 = characterset;

            while (!(iter003 == NIL)) {
              chaR = ((CharacterWrapper*)(iter003->value));
              iter003 = iter003->rest;
              transitions[((int)(unsigned char) (chaR->wrapperValue))] = ((char) ((((statemodifiers << 6)) | tostateid)));
            }
          }
        }
        (transitiontable->theArray)[fromstateid] = (wrapMutableString(transitions));
        transitions = makeString(oMAX_TOKENIZER_CHARACTERSo, NULL_CHARACTER);
      }
    }
    { int i = NULL_INTEGER;
      int iter004 = 0;
      int upperBound001 = freestateid - 1;

      while (iter004 <= upperBound001) {
        i = iter004;
        iter004 = iter004 + 1;
        if (!((boolean)(((MutableStringWrapper*)((transitiontable->theArray)[i]))))) {
          *(STANDARD_WARNING->nativeStream) << "Warning: " << "State " << "`" << ((GeneralizedSymbol*)((uniquestatenames->theArray)[i])) << "'" << " is undefined" << std::endl;
          errorsP = TRUE;
        }
      }
    }
    if (errorsP) {
      return (NULL);
    }
    transitions = makeString((freestateid * oMAX_TOKENIZER_CHARACTERSo), NULL_CHARACTER);
    { int i = NULL_INTEGER;
      int iter005 = 0;
      int upperBound002 = freestateid - 1;

      while (iter005 <= upperBound002) {
        i = iter005;
        iter005 = iter005 + 1;
        { int j = NULL_INTEGER;
          int k = NULL_INTEGER;
          int iter006 = 0;
          int upperBound003 = oMAX_TOKENIZER_CHARACTERSo - 1;
          int iter007 = oMAX_TOKENIZER_CHARACTERSo * i;

          while (iter006 <= upperBound003) {
            j = iter006;
            iter006 = iter006 + 1;
            k = iter007;
            iter007 = iter007 + 1;
            transitions[k] = ((((MutableStringWrapper*)((transitiontable->theArray)[i]))->wrapperValue)[j]);
          }
        }
      }
    }
    table->transitions = transitions;
    table->uniqueStateNames = newVector(freestateid);
    table->stateNames = newVector(freestateid);
    { int i = NULL_INTEGER;
      int iter008 = 0;
      int upperBound004 = freestateid - 1;

      while (iter008 <= upperBound004) {
        i = iter008;
        iter008 = iter008 + 1;
        (table->uniqueStateNames->theArray)[i] = (((GeneralizedSymbol*)((uniquestatenames->theArray)[i])));
        (table->stateNames->theArray)[i] = (((GeneralizedSymbol*)((statenames->theArray)[i])));
      }
    }
    table->legalEofStates = newVector(freestateid);
    { int i = NULL_INTEGER;
      int iter009 = 0;
      int upperBound005 = freestateid - 1;

      while (iter009 <= upperBound005) {
        i = iter009;
        iter009 = iter009 + 1;
        (table->legalEofStates->theArray)[i] = (((!((boolean)(((BooleanWrapper*)((legaleofstates->theArray)[i]))))) ? FALSE_WRAPPER : ((BooleanWrapper*)((legaleofstates->theArray)[i]))));
      }
    }
    return (table);
  }
}

boolean legalTokenizerStateP(Object* x) {
  return (keywordP(x) ||
      symbolP(x));
}

boolean legalTokenizerFromStateP(Object* x) {
  return (legalTokenizerStateP(x));
}

boolean legalTokenizerToStateP(Object* x) {
  return (legalTokenizerStateP(x) ||
      (consP(x) &&
       (legalTokenizerStateP(((Cons*)(x))->value) &&
        legalTokenizerStateP(((Cons*)(x))->rest->value))));
}

GeneralizedSymbol* tokenizerToStateName(Object* state) {
  if (consP(state)) {
    return (((GeneralizedSymbol*)(((Cons*)(state))->value)));
  }
  else {
    return (((GeneralizedSymbol*)(state)));
  }
}

GeneralizedSymbol* tokenizerToStateAlias(Object* state) {
  if (consP(state)) {
    return (((GeneralizedSymbol*)(((Cons*)(state))->rest->value)));
  }
  else {
    return (((GeneralizedSymbol*)(state)));
  }
}

int parseTokenizerStateModifiers(Object* modifier) {
  if (subtypeOfP(safePrimaryType(modifier), SGT_READ_STELLA_GENERALIZED_SYMBOL)) {
    { Object* modifier000 = modifier;
      GeneralizedSymbol* modifier = ((GeneralizedSymbol*)(modifier000));

      { char* testValue000 = modifier->symbolName;

        if (stringEqlP(testValue000, "*")) {
          return (2);
        }
        else if (stringEqlP(testValue000, "!") ||
            (stringEqlP(testValue000, "*!") ||
             stringEqlP(testValue000, "!*"))) {
          return (3);
        }
        else {
          return (0);
        }
      }
    }
  }
  else {
    return (0);
  }
}

boolean tokenizerIncludeSpecP(Object* x) {
  return (isaP(x, SGT_READ_STELLA_GENERALIZED_SYMBOL) &&
      stringEqlP(((GeneralizedSymbol*)(x))->symbolName, "INCLUDE"));
}

Cons* parseTokenizerCharacterSpec(Object* characterspec, List* allcharactersets) {
  { Cons* charset = NIL;
    Cons* complementset = NIL;
    Cons* parsedspec = NULL;

    { Surrogate* testValue000 = safePrimaryType(characterspec);

      if (subtypeOfStringP(testValue000)) {
        { Object* characterspec000 = characterspec;
          StringWrapper* characterspec = ((StringWrapper*)(characterspec000));

          { char chaR = NULL_CHARACTER;
            char* vector000 = characterspec->wrapperValue;
            int index000 = 0;
            int length000 = strlen(vector000);
            Cons* collect000 = NULL;

            while (index000 < length000) {
              chaR = vector000[index000];
              index000 = index000 + 1;
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(wrapCharacter(chaR), NIL);
                  if (charset == NIL) {
                    charset = collect000;
                  }
                  else {
                    addConsToEndOfConsList(charset, collect000);
                  }
                }
              }
              else {
                {
                  collect000->rest = cons(wrapCharacter(chaR), NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
        }
      }
      else if (subtypeOfCharacterP(testValue000)) {
        { Object* characterspec001 = characterspec;
          CharacterWrapper* characterspec = ((CharacterWrapper*)(characterspec001));

          charset = cons(characterspec, charset);
        }
      }
      else if (testValue000 == SGT_READ_STELLA_CONS) {
        { Object* characterspec002 = characterspec;
          Cons* characterspec = ((Cons*)(characterspec002));

          { Object* spec = NULL;
            Cons* iter000 = characterspec;

            while (!(iter000 == NIL)) {
              spec = iter000->value;
              iter000 = iter000->rest;
              parsedspec = parseTokenizerCharacterSpec(spec, NIL_LIST);
              if (!((boolean)(parsedspec))) {
                return (NULL);
              }
              { CharacterWrapper* chaR = NULL;
                Cons* iter001 = parsedspec;
                Cons* collect001 = NULL;

                while (!(iter001 == NIL)) {
                  chaR = ((CharacterWrapper*)(iter001->value));
                  iter001 = iter001->rest;
                  if (!((boolean)(collect001))) {
                    {
                      collect001 = cons(chaR, NIL);
                      if (charset == NIL) {
                        charset = collect001;
                      }
                      else {
                        addConsToEndOfConsList(charset, collect001);
                      }
                    }
                  }
                  else {
                    {
                      collect001->rest = cons(chaR, NIL);
                      collect001 = collect001->rest;
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (subtypeOfP(testValue000, SGT_READ_STELLA_GENERALIZED_SYMBOL)) {
        { Object* characterspec003 = characterspec;
          GeneralizedSymbol* characterspec = ((GeneralizedSymbol*)(characterspec003));

          { char* testValue001 = characterspec->symbolName;

            if (stringEqlP(testValue001, "ANY")) {
              { int i = NULL_INTEGER;
                int iter002 = 0;
                int upperBound000 = oMAX_TOKENIZER_CHARACTERSo - 1;
                Cons* collect002 = NULL;

                while (iter002 <= upperBound000) {
                  i = iter002;
                  iter002 = iter002 + 1;
                  if (!((boolean)(collect002))) {
                    {
                      collect002 = cons(wrapCharacter((char) i), NIL);
                      if (charset == NIL) {
                        charset = collect002;
                      }
                      else {
                        addConsToEndOfConsList(charset, collect002);
                      }
                    }
                  }
                  else {
                    {
                      collect002->rest = cons(wrapCharacter((char) i), NIL);
                      collect002 = collect002->rest;
                    }
                  }
                }
              }
            }
            else if (stringEqlP(testValue001, "OTHERWISE")) {
              { Cons* set = NULL;
                Cons* iter003 = allcharactersets->theConsList;

                while (!(iter003 == NIL)) {
                  set = ((Cons*)(iter003->value));
                  iter003 = iter003->rest;
                  { CharacterWrapper* chaR = NULL;
                    Cons* iter004 = set;
                    Cons* collect003 = NULL;

                    while (!(iter004 == NIL)) {
                      chaR = ((CharacterWrapper*)(iter004->value));
                      iter004 = iter004->rest;
                      if (!((boolean)(collect003))) {
                        {
                          collect003 = cons(chaR, NIL);
                          if (charset == NIL) {
                            charset = collect003;
                          }
                          else {
                            addConsToEndOfConsList(charset, collect003);
                          }
                        }
                      }
                      else {
                        {
                          collect003->rest = cons(chaR, NIL);
                          collect003 = collect003->rest;
                        }
                      }
                    }
                  }
                }
              }
              { int i = NULL_INTEGER;
                int iter005 = 0;
                int upperBound001 = oMAX_TOKENIZER_CHARACTERSo - 1;
                Cons* collect004 = NULL;

                while (iter005 <= upperBound001) {
                  i = iter005;
                  iter005 = iter005 + 1;
                  if (!charset->memberP(wrapCharacter((char) i))) {
                    if (!((boolean)(collect004))) {
                      {
                        collect004 = cons(wrapCharacter((char) i), NIL);
                        if (complementset == NIL) {
                          complementset = collect004;
                        }
                        else {
                          addConsToEndOfConsList(complementset, collect004);
                        }
                      }
                    }
                    else {
                      {
                        collect004->rest = cons(wrapCharacter((char) i), NIL);
                        collect004 = collect004->rest;
                      }
                    }
                  }
                }
              }
              charset = complementset;
            }
            else {
              return (NULL);
            }
          }
        }
      }
      else {
        return (NULL);
      }
    }
    return (charset);
  }
}

char* stringifyTokenizerTable(TokenizerTable* table) {
  { OutputStringStream* result = newOutputStringStream();
    int acode = (int)(unsigned char) 'A';
    char* transitions = table->transitions;
    char* encodedtransitions = makeString((2 * oMAX_TOKENIZER_STATESo * oMAX_TOKENIZER_CHARACTERSo), NULL_CHARACTER);
    int j = -1;
    Vector* uniquestatenames = table->uniqueStateNames;
    Vector* statenames = table->stateNames;
    Vector* eofstates = table->legalEofStates;
    char* separator = "|";

    *(result->nativeStream) << (2 * oMAX_TOKENIZER_STATESo * oMAX_TOKENIZER_CHARACTERSo) << separator;
    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = (oMAX_TOKENIZER_STATESo * oMAX_TOKENIZER_CHARACTERSo) - 1;

      while (iter000 <= upperBound000) {
        i = iter000;
        iter000 = iter000 + 1;
        encodedtransitions[(j = j + 1)] = ((char) ((((int)(unsigned char) (transitions[i])) & 15) + acode));
        encodedtransitions[(j = j + 1)] = ((char) ((((int)(unsigned char) (transitions[i])) >> 4) + acode));
      }
    }
    *(result->nativeStream) << encodedtransitions << separator;
    *(result->nativeStream) << uniquestatenames->length() << separator;
    { GeneralizedSymbol* state = NULL;
      Vector* vector000 = uniquestatenames;
      int index000 = 0;
      int length000 = vector000->length();

      while (index000 < length000) {
        state = ((GeneralizedSymbol*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        *(result->nativeStream) << state->symbolName << separator;
      }
    }
    *(result->nativeStream) << statenames->length() << separator;
    { GeneralizedSymbol* state = NULL;
      Vector* vector001 = statenames;
      int index001 = 0;
      int length001 = vector001->length();

      while (index001 < length001) {
        state = ((GeneralizedSymbol*)((vector001->theArray)[index001]));
        index001 = index001 + 1;
        *(result->nativeStream) << state->symbolName << separator;
      }
    }
    *(result->nativeStream) << eofstates->length() << separator;
    { BooleanWrapper* state = NULL;
      Vector* vector002 = eofstates;
      int index002 = 0;
      int length002 = vector002->length();

      while (index002 < length002) {
        state = ((BooleanWrapper*)((vector002->theArray)[index002]));
        index002 = index002 + 1;
        *(result->nativeStream) << ((coerceWrappedBooleanToBoolean(state) ? (char*)"T" : (char*)"F"));
      }
    }
    *(result->nativeStream) << separator;
    return (result->theStringReader());
  }
}

TokenizerTable* unstringifyTokenizerTable(char* table) {
  { TokenizerTable* result = newTokenizerTable();
    int acode = (int)(unsigned char) 'A';
    char* line = NULL;
    int count = 0;
    char* transitions = NULL;
    char separator = '|';
    int start = 0;
    int end = 0;

    end = stringPosition(table, separator, start);
    line = stringSubsequence(table, start, end);
    start = end + 1;
    count = stringToInteger(line);
    end = stringPosition(table, separator, start);
    line = stringSubsequence(table, start, end);
    start = end + 1;
    transitions = makeString((((int)(count / 2.0))), NULL_CHARACTER);
    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = ((int)((count / 2.0) - 1));

      while (iter000 <= upperBound000) {
        i = iter000;
        iter000 = iter000 + 1;
        transitions[i] = ((char) ((((int)(unsigned char) (line[(2 * i)]) - acode) | ((((int)(unsigned char) (line[((2 * i) + 1)]) - acode) << 4)))));
      }
    }
    result->transitions = transitions;
    end = stringPosition(table, separator, start);
    line = stringSubsequence(table, start, end);
    start = end + 1;
    count = stringToInteger(line);
    result->uniqueStateNames = newVector(count);
    { int i = NULL_INTEGER;
      int iter001 = 0;
      int upperBound001 = count - 1;

      while (iter001 <= upperBound001) {
        i = iter001;
        iter001 = iter001 + 1;
        end = stringPosition(table, separator, start);
        line = stringSubsequence(table, start, end);
        start = end + 1;
        (result->uniqueStateNames->theArray)[i] = (internKeyword(line));
      }
    }
    end = stringPosition(table, separator, start);
    line = stringSubsequence(table, start, end);
    start = end + 1;
    count = stringToInteger(line);
    result->stateNames = newVector(count);
    { int i = NULL_INTEGER;
      int iter002 = 0;
      int upperBound002 = count - 1;

      while (iter002 <= upperBound002) {
        i = iter002;
        iter002 = iter002 + 1;
        end = stringPosition(table, separator, start);
        line = stringSubsequence(table, start, end);
        start = end + 1;
        (result->stateNames->theArray)[i] = (internKeyword(line));
      }
    }
    end = stringPosition(table, separator, start);
    line = stringSubsequence(table, start, end);
    start = end + 1;
    count = stringToInteger(line);
    end = stringPosition(table, separator, start);
    line = stringSubsequence(table, start, end);
    start = end + 1;
    result->legalEofStates = newVector(count);
    { int i = NULL_INTEGER;
      int iter003 = 0;
      int upperBound003 = count - 1;

      while (iter003 <= upperBound003) {
        i = iter003;
        iter003 = iter003 + 1;
        switch (line[i]) {
          case 'T': 
            (result->legalEofStates->theArray)[i] = TRUE_WRAPPER;
          break;
          case 'F': 
            (result->legalEofStates->theArray)[i] = FALSE_WRAPPER;
          break;
          default:
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "`" << line[i] << "'" << " is not a valid case option";
              throw *newStellaException(stream000->theStringReader());
            }
          break;
        }
      }
    }
    return (result);
  }
}

char* makeTokenizerByteArray(int size) {
  return (new (GC) char[size]);
}

char* stringToTokenizerByteArray(char* string) {
  return (string);
}

char* tokenizerByteArrayToString(char* bytes) {
  return (bytes);
}

char tokenizerByteArrayByteArrayNth(char* buffer, int position) {
  return (buffer[position]);
}

char tokenizerByteArrayByteArrayNthSetter(char* buffer, char ch, int position) {
  return (buffer[position] = ch);
}

int byteArrayReadSequence(char* buffer, std::istream* stream, int start, int end) {
  { int n = 0;

    if (stream->eof()) return start;
    stream->read(buffer + start, end - start);
    n = stream->gcount();
    return (n + start);
  }
}

void byteArrayWriteSequence(char* buffer, std::ostream* stream, int start, int end) {
  stream->write(buffer + start, end - start);
}

int oTOKENIZER_INITIAL_BUFFER_SIZEo = 2048;

void ensureTokenizerBufferSize(TokenizerStreamState* state, int currenttokenstart, int requiredspace) {
  { int size = state->bufferSize;
    int newsize = size;
    int end = ((state->end) % size);
    int freespace = ((currenttokenstart == -1) ? size : (((end <= currenttokenstart) ? (currenttokenstart - end) : (currenttokenstart + (size - end)))));
    char* buffer = state->buffer;
    char* newbuffer = buffer;

    while (freespace < requiredspace) {
      freespace = freespace + newsize;
      newsize = newsize * 2;
    }
    if (newsize > size) {
      newbuffer = new (GC) char[newsize];
      if (currenttokenstart < 0) {
        state->cursor = 0;
        state->end = newsize;
      }
      else if (end > currenttokenstart) {
        { int i = NULL_INTEGER;
          int iter000 = currenttokenstart;
          int upperBound000 = end - 1;

          while (iter000 <= upperBound000) {
            i = iter000;
            iter000 = iter000 + 1;
            newbuffer[i] = (buffer[i]);
          }
        }
      }
      else {
        { int i = NULL_INTEGER;
          int iter001 = currenttokenstart;
          int upperBound001 = size - 1;

          while (iter001 <= upperBound001) {
            i = iter001;
            iter001 = iter001 + 1;
            newbuffer[i] = (buffer[i]);
          }
        }
        { int i = NULL_INTEGER;
          int j = NULL_INTEGER;
          int iter002 = 0;
          int upperBound002 = end - 1;
          int iter003 = size;

          while (iter002 <= upperBound002) {
            i = iter002;
            iter002 = iter002 + 1;
            j = iter003;
            iter003 = iter003 + 1;
            newbuffer[j] = (buffer[i]);
          }
        }
        state->end = size + end;
        state->cursor = state->end;
      }
      state->buffer = newbuffer;
      state->bufferSize = newsize;
    }
  }
}

boolean readIntoTokenizerBuffer(InputStream* stream, TokenizerStreamState* state, int currenttokenstart) {
  { int requiredspace = ((state->bufferSize < oTOKENIZER_INITIAL_BUFFER_SIZEo) ? 1 : (oTOKENIZER_INITIAL_BUFFER_SIZEo >> 1));
    char inputchar = NULL_CHARACTER;
    char* inputline = NULL;
    boolean eofP = FALSE;

    if (!(stream->bufferingScheme == KWD_READ_BLOCK)) {
      stream->tokenizerState = NULL;
      { Keyword* testValue000 = stream->bufferingScheme;

        if (testValue000 == KWD_READ_LINE) {
          inputline = readLine(stream, eofP);
          if (inputline == NULL) {
            inputline = "";
          }
          inputline = stringConcatenate(inputline, EOL_STRING);
        }
        else if (testValue000 == KWD_READ_CHARACTER) {
          inputchar = readCharacter(stream, eofP);
          if (eofP) {
            inputline = "";
          }
          else {
            inputline = makeString(1, inputchar);
          }
        }
        else {
          { OutputStringStream* stream000 = newOutputStringStream();

            *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
            throw *newStellaException(stream000->theStringReader());
          }
        }
      }
      stream->tokenizerState = state;
      requiredspace = strlen(inputline);
    }
    ensureTokenizerBufferSize(state, currenttokenstart, requiredspace);
    { std::istream* nativestream = stream->nativeStream;
      char* buffer = state->buffer;
      int size = state->bufferSize;
      int end = state->end;
      int start = -1;

      if (end == size) {
        end = 0;
      }
      if (currenttokenstart < 0) {
        start = 0;
        end = size;
        state->cursor = 0;
      }
      else if (end <= currenttokenstart) {
        start = end;
        end = currenttokenstart;
      }
      else if (end > currenttokenstart) {
        start = end;
        end = size;
      }
      if (inputline != NULL) {
        end = start;
        { char ch = NULL_CHARACTER;
          char* vector000 = inputline;
          int index000 = 0;
          int length000 = strlen(vector000);

          while (index000 < length000) {
            ch = vector000[index000];
            index000 = index000 + 1;
            buffer[end] = ch;
            end = end + 1;
            if (end == size) {
              end = 0;
            }
          }
        }
      }
      else {
        end = byteArrayReadSequence(buffer, nativestream, start, end);
      }
      state->end = end;
      return (eofP ||
          (start == end));
    }
  }
}

char readCharacterFromTokenizerBuffer(InputStream* stream, boolean& _Return1) {
  { TokenizerStreamState* state = stream->tokenizerState;
    int cursor = state->cursor;
    int end = state->end;
    int size = state->bufferSize;
    OutputStream* echostream = stream->echoStream;
    char ch = NULL_CHARACTER;

    if (cursor == end) {
      if (readIntoTokenizerBuffer(stream, state, -1)) {
        _Return1 = TRUE;
        return (NULL_CHARACTER);
      }
      cursor = state->cursor;
      if (cursor == size) {
        cursor = 0;
      }
    }
    ch = (state->buffer)[cursor];
    if (((boolean)(echostream))) {
      *(echostream->nativeStream) << ch;
    }
    state->cursor = cursor + 1;
    _Return1 = FALSE;
    return (ch);
  }
}

void unreadCharacterFromTokenizerBuffer(char chaR, InputStream* stream) {
  { TokenizerStreamState* state = stream->tokenizerState;
    int cursor = state->cursor;

    if (cursor == 0) {
      cursor = state->bufferSize - 1;
    }
    else {
      cursor = cursor - 1;
    }
    if (!(chaR == (state->buffer)[cursor])) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Unread character " << "`" << chaR << "'" << " does not match last character read";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    state->cursor = cursor;
  }
}

char* readLineFromTokenizerBuffer(InputStream* stream, boolean& _Return1) {
  { OutputStringStream* buffer = newOutputStringStream();
    char* line = NULL;
    char ch = NULL_CHARACTER;
    char ch2 = NULL_CHARACTER;
    boolean eofP = FALSE;
    char newline = EOL_STRING[0];

    for (;;) {
      ch = readCharacterFromTokenizerBuffer(stream, eofP);
      if (eofP) {
        line = buffer->theStringReader();
        if (strlen(line) == 0) {
          line = NULL;
        }
        else {
          eofP = FALSE;
        }
        break;
      }
      if (ch == newline) {
        if (strlen(EOL_STRING) == 2) {
          ch2 = readCharacterFromTokenizerBuffer(stream, eofP);
          if (eofP) {
            line = buffer->theStringReader();
            if (strlen(line) == 0) {
              line = NULL;
            }
            else {
              eofP = FALSE;
            }
            break;
          }
          if (!(ch2 == EOL_STRING[1])) {
            *(buffer->nativeStream) << ch << ch2;
            continue;
          }
        }
        line = buffer->theStringReader();
        break;
      }
      *(buffer->nativeStream) << ch;
    }
    _Return1 = eofP;
    return (line);
  }
}

TokenizerToken* newTokenizerToken() {
  { TokenizerToken* self = NULL;

    self = new TokenizerToken();
    self->next = NULL;
    self->content = NULL;
    self->type = NULL;
    return (self);
  }
}

Surrogate* TokenizerToken::primaryType() {
  { TokenizerToken* self = this;

    return (SGT_READ_STELLA_TOKENIZER_TOKEN);
  }
}

Object* accessTokenizerTokenSlotValue(TokenizerToken* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_READ_STELLA_TYPE) {
    if (setvalueP) {
      self->type = ((Keyword*)(value));
    }
    else {
      value = self->type;
    }
  }
  else if (slotname == SYM_READ_STELLA_CONTENT) {
    if (setvalueP) {
      self->content = ((StringWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapString(self->content);
    }
  }
  else if (slotname == SYM_READ_STELLA_NEXT) {
    if (setvalueP) {
      self->next = ((TokenizerToken*)(value));
    }
    else {
      value = self->next;
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

TokenizerStreamState* newTokenizerStreamState() {
  { TokenizerStreamState* self = NULL;

    self = new TokenizerStreamState();
    self->tokenList = NULL;
    self->state = 1;
    self->end = oTOKENIZER_INITIAL_BUFFER_SIZEo;
    self->cursor = oTOKENIZER_INITIAL_BUFFER_SIZEo;
    self->bufferSize = oTOKENIZER_INITIAL_BUFFER_SIZEo;
    self->buffer = new (GC) char[oTOKENIZER_INITIAL_BUFFER_SIZEo];
    return (self);
  }
}

Surrogate* TokenizerStreamState::primaryType() {
  { TokenizerStreamState* self = this;

    return (SGT_READ_STELLA_TOKENIZER_STREAM_STATE);
  }
}

Object* accessTokenizerStreamStateSlotValue(TokenizerStreamState* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_READ_STELLA_BUFFER_SIZE) {
    if (setvalueP) {
      self->bufferSize = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->bufferSize);
    }
  }
  else if (slotname == SYM_READ_STELLA_CURSOR) {
    if (setvalueP) {
      self->cursor = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->cursor);
    }
  }
  else if (slotname == SYM_READ_STELLA_END) {
    if (setvalueP) {
      self->end = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->end);
    }
  }
  else if (slotname == SYM_READ_STELLA_STATE) {
    if (setvalueP) {
      self->state = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->state);
    }
  }
  else if (slotname == SYM_READ_STELLA_TOKEN_LIST) {
    if (setvalueP) {
      self->tokenList = ((TokenizerToken*)(value));
    }
    else {
      value = self->tokenList;
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

DEFINE_STELLA_SPECIAL(oWITHTOKENIZERINPUTTYPEo, Surrogate* , NULL);

Object* withTokenizer(Object* table, Object* input, Cons* body) {
  { StandardObject* dummy1;
    StandardObject* dummy2;
    StandardObject* dummy3;

    { Object* inputtree = NULL;
      StandardObject* inputtype = NULL;

      inputtree = walkATree(input, inputtype);
      if (!(subTypeSpecOfP(inputtype, SGT_READ_STELLA_INPUT_STREAM) ||
          subTypeSpecOfP(inputtype, SGT_READ_STELLA_STRING))) {
        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          signalTranslationError();
          if (!(suppressWarningsP())) {
            printErrorContext(">> ERROR: ", STANDARD_ERROR);
            *(STANDARD_ERROR->nativeStream) << std::endl << " " << "with-tokenizer: Can't handle input of type " << "`" << deUglifyParseTree(inputtype) << "'" << "." << std::endl;
          }
        }
        return (walkDontCallMeTree(body, SGT_READ_STELLA_VOID, dummy1));
      }
      { boolean stringP = subTypeSpecOfP(inputtype, SGT_READ_STELLA_STRING) ||
            subTypeSpecOfP(inputtype, SGT_READ_STELLA_MUTABLE_STRING);
        Cons* expansion = listO(4, SYM_READ_STELLA_LET, listO(6, listO(3, SYM_READ_STELLA_TOK_TABLE_, table, NIL), listO(3, SYM_READ_STELLA_TOK_TRANSITIONS_, listO(3, SYM_READ_STELLA_TRANSITIONS, SYM_READ_STELLA_TOK_TABLE_, NIL), NIL), listO(3, SYM_READ_STELLA_TOK_STATENAMES_, listO(3, SYM_READ_STELLA_THE_ARRAY, listO(3, SYM_READ_STELLA_STATE_NAMES, SYM_READ_STELLA_TOK_TABLE_, NIL), NIL), NIL), listO(3, SYM_READ_STELLA_TOK_TOKENSTART_, wrapInteger(-1), NIL), listO(3, SYM_READ_STELLA_TOK_ENDOFTOKENSp_, SYM_READ_STELLA_FALSE, NIL), ((stringP ? listO(8, listO(4, SYM_READ_STELLA_TOK_STREAMSTATE_, SYM_READ_STELLA_TOKENIZER_STREAM_STATE, SYM_READ_STELLA_NULL, NIL), listO(3, SYM_READ_STELLA_TOK_BUFFER_, listO(3, SYM_READ_STELLA_STRING_TO_TOKENIZER_BYTE_ARRAY, input, NIL), NIL), listO(3, SYM_READ_STELLA_TOK_STATE_, wrapInteger(1), NIL), listO(3, SYM_READ_STELLA_TOK_NEXTSTATE_, SYM_READ_STELLA_TOK_STATE_, NIL), listO(3, SYM_READ_STELLA_TOK_CURSOR_, wrapInteger(0), NIL), listO(3, SYM_READ_STELLA_TOK_SIZE_, listO(3, SYM_READ_STELLA_LENGTH, input, NIL), NIL), listO(3, SYM_READ_STELLA_TOK_END_, SYM_READ_STELLA_TOK_SIZE_, NIL), NIL) : listO(11, listO(3, SYM_READ_STELLA_TOK_INPUTSTREAM_, sysTree(inputtree, inputtype, dummy2), NIL), listO(3, SYM_READ_STELLA_TOK_ECHOSTREAM_, listO(3, SYM_READ_STELLA_ECHO_STREAM, SYM_READ_STELLA_TOK_INPUTSTREAM_, NIL), NIL), listO(3, SYM_READ_STELLA_TOK_STREAMSTATE_, listO(5, SYM_READ_STELLA_CHOOSE, listO(3, SYM_READ_STELLA_NULLp, listO(3, SYM_READ_STELLA_TOKENIZER_STATE, SYM_READ_STELLA_TOK_INPUTSTREAM_, NIL), NIL), listO(4, SYM_READ_STELLA_SETF, listO(3, SYM_READ_STELLA_TOKENIZER_STATE, SYM_READ_STELLA_TOK_INPUTSTREAM_, NIL), listO(3, SYM_READ_STELLA_NEW, SYM_READ_STELLA_TOKENIZER_STREAM_STATE, NIL), NIL), listO(3, SYM_READ_STELLA_TOKENIZER_STATE, SYM_READ_STELLA_TOK_INPUTSTREAM_, NIL), NIL), NIL), listO(3, SYM_READ_STELLA_TOK_BUFFER_, listO(3, SYM_READ_STELLA_BUFFER, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), NIL), listO(3, SYM_READ_STELLA_TOK_SIZE_, listO(3, SYM_READ_STELLA_BUFFER_SIZE, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), NIL), listO(3, SYM_READ_STELLA_TOK_STATE_, listO(3, SYM_READ_STELLA_STATE, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), NIL), listO(3, SYM_READ_STELLA_TOK_NEXTSTATE_, SYM_READ_STELLA_TOK_STATE_, NIL), listO(3, SYM_READ_STELLA_TOK_CURSOR_, listO(3, SYM_READ_STELLA_CURSOR, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), NIL), listO(3, SYM_READ_STELLA_TOK_END_, listO(3, SYM_READ_STELLA_END, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), NIL), listO(3, SYM_READ_STELLA_TOK_CHECKPOINT_, listO(5, SYM_READ_STELLA_CHOOSE, listO(4, SYM_READ_STELLA_le, SYM_READ_STELLA_TOK_CURSOR_, SYM_READ_STELLA_TOK_END_, NIL), SYM_READ_STELLA_TOK_END_, SYM_READ_STELLA_TOK_SIZE_, NIL), NIL), NIL)))->concatenate(NIL, 0)), listO(4, SYM_READ_STELLA_IGNORE, SYM_READ_STELLA_TOK_STATENAMES_, SYM_READ_STELLA_TOK_ENDOFTOKENSp_, NIL), ((stringP ? cons(listO(3, SYM_READ_STELLA_IGNORE, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), NIL) : NIL))->concatenate(body->concatenate(NIL, 0), 0));

        { 
          BIND_STELLA_SPECIAL(oWITHTOKENIZERINPUTTYPEo, Surrogate*, ((Surrogate*)(inputtype)));
          return (walkATree(((Cons*)(copyConsTree(expansion))), dummy3));
        }
      }
    }
  }
}

boolean withTokenizerStringInputP() {
  return (oWITHTOKENIZERINPUTTYPEo.get() == SGT_READ_STELLA_STRING);
}

boolean insideWithTokenizerP() {
  return (((boolean)(oWITHTOKENIZERINPUTTYPEo.get())));
}

Object* endOfTokensP() {
  if (!insideWithTokenizerP()) {
    { 
      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
      signalTranslationError();
      if (!(suppressWarningsP())) {
        printErrorContext(">> ERROR: ", STANDARD_ERROR);
        *(STANDARD_ERROR->nativeStream) << std::endl << " " << "Encountered `end-of-tokens?' outside of `with-tokenizer' macro." << "." << std::endl;
      }
    }
    return (cons(SYM_READ_STELLA_END_OF_TOKENSp, NIL));
  }
  return (SYM_READ_STELLA_TOK_ENDOFTOKENSp_);
}

Object* getTokenText(Cons* options) {
  if (!insideWithTokenizerP()) {
    { 
      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
      signalTranslationError();
      if (!(suppressWarningsP())) {
        printErrorContext(">> ERROR: ", STANDARD_ERROR);
        *(STANDARD_ERROR->nativeStream) << std::endl << " " << "Encountered `get-token-text' outside of `with-tokenizer' macro." << "." << std::endl;
      }
    }
    return (cons(SYM_READ_STELLA_GET_TOKEN_TEXT, NIL));
  }
  { Object* upcaseP = options->value;
    Object* start = options->rest->value;
    Object* end = options->rest->rest->value;

    if (upcaseP == SYM_READ_STELLA_FALSE) {
      upcaseP = NULL;
    }
    if (eqlP(start, ZERO_WRAPPER)) {
      start = NULL;
    }
    return (listO(4, SYM_READ_STELLA_GET_TOKEN_TEXT_INTERNAL, SYM_READ_STELLA_TOK_BUFFER_, ((!((boolean)(start))) ? ((StandardObject*)(SYM_READ_STELLA_TOK_TOKENSTART_)) : ((StandardObject*)(listO(4, SYM_READ_STELLA_i, SYM_READ_STELLA_TOK_TOKENSTART_, start, NIL)))), cons(((!((boolean)(end))) ? ((StandardObject*)(SYM_READ_STELLA_TOK_CURSOR_)) : ((StandardObject*)((integerP(end) ? (((((IntegerWrapper*)(end))->wrapperValue < 0) ? listO(4, SYM_READ_STELLA_i, SYM_READ_STELLA_TOK_CURSOR_, end, NIL) : listO(4, SYM_READ_STELLA_i, SYM_READ_STELLA_TOK_TOKENSTART_, end, NIL))) : listO(5, SYM_READ_STELLA_CHOOSE, listO(3, SYM_READ_STELLA_l, end, cons(wrapInteger(0), NIL)), listO(4, SYM_READ_STELLA_i, SYM_READ_STELLA_TOK_CURSOR_, end, NIL), listO(4, SYM_READ_STELLA_i, SYM_READ_STELLA_TOK_TOKENSTART_, end, NIL), NIL))))), listO(3, SYM_READ_STELLA_TOK_SIZE_, (((boolean)(upcaseP)) ? upcaseP : SYM_READ_STELLA_FALSE), NIL))));
  }
}

char* getTokenTextInternal(char* buffer, int start, int end, int size, boolean upcaseP) {
  if (start >= size) {
    start = start - size;
  }
  else if (start < 0) {
    start = size + start;
  }
  if (end > size) {
    end = end - size;
  }
  else if (end < 0) {
    end = size + end;
  }
  { int length = end - start;
    char* result = NULL;
    int cursor = 0;
    int auxend = end;

    if (length < 0) {
      length = length + size;
      auxend = size;
    }
    result = makeRawMutableString(length);
    if (upcaseP) {
      for (;;) {
        while (start < auxend) {
          result[cursor] = (oCHARACTER_UPCASE_TABLEo[((int)(unsigned char) (buffer[start]))]);
          cursor = cursor + 1;
          start = start + 1;
        }
        if (auxend == end) {
          break;
        }
        start = 0;
        auxend = end;
      }
    }
    else {
      for (;;) {
        while (start < auxend) {
          result[cursor] = (buffer[start]);
          cursor = cursor + 1;
          start = start + 1;
        }
        if (auxend == end) {
          break;
        }
        start = 0;
        auxend = end;
      }
    }
    return (result);
  }
}

Object* getTokenType() {
  if (!insideWithTokenizerP()) {
    { 
      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
      signalTranslationError();
      if (!(suppressWarningsP())) {
        printErrorContext(">> ERROR: ", STANDARD_ERROR);
        *(STANDARD_ERROR->nativeStream) << std::endl << " " << "Encountered `get-token-type' outside of `with-tokenizer' macro." << "." << std::endl;
      }
    }
    return (cons(SYM_READ_STELLA_GET_TOKEN_TYPE, NIL));
  }
  return (listO(4, SYM_READ_STELLA_NTH, SYM_READ_STELLA_TOK_STATENAMES_, SYM_READ_STELLA_TOK_STATE_, NIL));
}

Object* saveTokenizerStreamState() {
  return (listO(5, SYM_READ_STELLA_WHEN, listO(3, SYM_READ_STELLA_DEFINEDp, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), listO(4, SYM_READ_STELLA_SETF, listO(3, SYM_READ_STELLA_CURSOR, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), SYM_READ_STELLA_TOK_CURSOR_, NIL), listO(4, SYM_READ_STELLA_SETF, listO(3, SYM_READ_STELLA_STATE, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), SYM_READ_STELLA_TOK_STATE_, NIL), NIL));
}

Object* getNextToken(Cons* options) {
  if (!insideWithTokenizerP()) {
    { 
      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
      signalTranslationError();
      if (!(suppressWarningsP())) {
        printErrorContext(">> ERROR: ", STANDARD_ERROR);
        *(STANDARD_ERROR->nativeStream) << std::endl << " " << "Encountered `get-next-token' outside of `with-tokenizer' macro." << "." << std::endl;
      }
    }
    return (cons(SYM_READ_STELLA_GET_NEXT_TOKEN, NIL));
  }
  { Object* savestreamstateP = options->value;
    Cons* savestreamstatetree = cons(cons(SYM_READ_STELLA_SAVE_TOKENIZER_STREAM_STATE, NIL), NIL);

    if ((!((boolean)(savestreamstateP))) ||
        (savestreamstateP == SYM_READ_STELLA_TRUE)) {
    }
    else if (savestreamstateP == SYM_READ_STELLA_FALSE) {
      savestreamstatetree = NIL;
    }
    else {
      savestreamstatetree = cons(listO(3, SYM_READ_STELLA_WHEN, savestreamstateP, savestreamstatetree->concatenate(NIL, 0)), NIL);
    }
    return (listO(4, SYM_READ_STELLA_PROGN, listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_TOKENSTART_, wrapInteger(-1), NIL), listO(3, SYM_READ_STELLA_LOOP, (withTokenizerStringInputP() ? listO(5, SYM_READ_STELLA_WHEN, listO(4, SYM_READ_STELLA_e, SYM_READ_STELLA_TOK_CURSOR_, SYM_READ_STELLA_TOK_END_, NIL), listO(5, SYM_READ_STELLA_COND, listO(3, listO(4, SYM_READ_STELLA_e, SYM_READ_STELLA_TOK_NEXTSTATE_, wrapInteger(-1), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_ENDOFTOKENSp_, SYM_READ_STELLA_TRUE, NIL), NIL), listO(4, listO(4, SYM_READ_STELLA_NTH, listO(3, SYM_READ_STELLA_LEGAL_EOF_STATES, SYM_READ_STELLA_TOK_TABLE_, NIL), SYM_READ_STELLA_TOK_STATE_, NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_NEXTSTATE_, wrapInteger(-1), NIL), listO(4, SYM_READ_STELLA_WHEN, listO(4, SYM_READ_STELLA_e, SYM_READ_STELLA_TOK_TOKENSTART_, wrapInteger(-1), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_ENDOFTOKENSp_, SYM_READ_STELLA_TRUE, NIL), NIL), NIL), listO(4, SYM_READ_STELLA_OTHERWISE, listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_STATE_, wrapInteger(0), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_NEXTSTATE_, wrapInteger(-1), NIL), NIL), NIL), cons(SYM_READ_STELLA_BREAK, NIL), NIL) : listO(4, SYM_READ_STELLA_WHEN, listO(4, SYM_READ_STELLA_e, SYM_READ_STELLA_TOK_CURSOR_, SYM_READ_STELLA_TOK_CHECKPOINT_, NIL), listO(4, SYM_READ_STELLA_COND, listO(10, listO(4, SYM_READ_STELLA_e, SYM_READ_STELLA_TOK_CURSOR_, SYM_READ_STELLA_TOK_END_, NIL), listO(4, SYM_READ_STELLA_SETF, listO(3, SYM_READ_STELLA_CURSOR, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), SYM_READ_STELLA_TOK_CURSOR_, NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_ENDOFTOKENSp_, listO(5, SYM_READ_STELLA_READ_INTO_TOKENIZER_BUFFER, SYM_READ_STELLA_TOK_INPUTSTREAM_, SYM_READ_STELLA_TOK_STREAMSTATE_, SYM_READ_STELLA_TOK_TOKENSTART_, NIL), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_BUFFER_, listO(3, SYM_READ_STELLA_BUFFER, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_SIZE_, listO(3, SYM_READ_STELLA_BUFFER_SIZE, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_CURSOR_, listO(4, SYM_READ_STELLA_MOD, listO(3, SYM_READ_STELLA_CURSOR, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), SYM_READ_STELLA_TOK_SIZE_, NIL), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_END_, listO(3, SYM_READ_STELLA_END, SYM_READ_STELLA_TOK_STREAMSTATE_, NIL), NIL), listO(5, SYM_READ_STELLA_WHEN, SYM_READ_STELLA_TOK_ENDOFTOKENSp_, listO(5, SYM_READ_STELLA_COND, cons(listO(4, SYM_READ_STELLA_e, SYM_READ_STELLA_TOK_NEXTSTATE_, wrapInteger(-1), NIL), NIL), listO(4, listO(4, SYM_READ_STELLA_NTH, listO(3, SYM_READ_STELLA_LEGAL_EOF_STATES, SYM_READ_STELLA_TOK_TABLE_, NIL), SYM_READ_STELLA_TOK_STATE_, NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_NEXTSTATE_, wrapInteger(-1), NIL), listO(4, SYM_READ_STELLA_UNLESS, listO(4, SYM_READ_STELLA_e, SYM_READ_STELLA_TOK_TOKENSTART_, wrapInteger(-1), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_ENDOFTOKENSp_, SYM_READ_STELLA_FALSE, NIL), NIL), NIL), listO(5, SYM_READ_STELLA_OTHERWISE, listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_ENDOFTOKENSp_, SYM_READ_STELLA_FALSE, NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_STATE_, wrapInteger(0), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_NEXTSTATE_, wrapInteger(-1), NIL), NIL), NIL), cons(SYM_READ_STELLA_BREAK, NIL), NIL), listO(5, SYM_READ_STELLA_IF, listO(4, SYM_READ_STELLA_ge, SYM_READ_STELLA_TOK_CURSOR_, SYM_READ_STELLA_TOK_END_, NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_CHECKPOINT_, SYM_READ_STELLA_TOK_SIZE_, NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_CHECKPOINT_, SYM_READ_STELLA_TOK_END_, NIL), NIL), NIL), listO(4, SYM_READ_STELLA_OTHERWISE, listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_CHECKPOINT_, SYM_READ_STELLA_TOK_END_, NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_CURSOR_, wrapInteger(0), NIL), NIL), NIL), NIL)), listO(3, listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_NEXTSTATE_, listO(3, SYM_READ_STELLA_CHARACTER_CODE, listO(4, SYM_READ_STELLA_NTH, SYM_READ_STELLA_TOK_TRANSITIONS_, listO(4, SYM_READ_STELLA_LOGOR, listO(4, SYM_READ_STELLA_SHIFT_LEFT, SYM_READ_STELLA_TOK_STATE_, wrapInteger(8), NIL), listO(3, SYM_READ_STELLA_CHARACTER_CODE, listO(4, SYM_READ_STELLA_BYTE_ARRAY_NTH, SYM_READ_STELLA_TOK_BUFFER_, SYM_READ_STELLA_TOK_CURSOR_, NIL), NIL), NIL), NIL), NIL), NIL), listO(5, SYM_READ_STELLA_COND, listO(4, listO(4, SYM_READ_STELLA_e, listO(4, SYM_READ_STELLA_LOGAND, SYM_READ_STELLA_TOK_NEXTSTATE_, wrapInteger(128), NIL), wrapInteger(0), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_STATE_, SYM_READ_STELLA_TOK_NEXTSTATE_, NIL), listO(3, SYM_READ_STELLA_ii, SYM_READ_STELLA_TOK_CURSOR_, NIL), NIL), listO(5, listO(4, SYM_READ_STELLA_e, SYM_READ_STELLA_TOK_TOKENSTART_, wrapInteger(-1), NIL), listO(4, SYM_READ_STELLA_WHEN, listO(4, SYM_READ_STELLA_e, listO(4, SYM_READ_STELLA_LOGAND, SYM_READ_STELLA_TOK_NEXTSTATE_, wrapInteger(64), NIL), wrapInteger(0), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_TOKENSTART_, SYM_READ_STELLA_TOK_CURSOR_, NIL), NIL), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_STATE_, listO(4, SYM_READ_STELLA_LOGAND, SYM_READ_STELLA_TOK_NEXTSTATE_, wrapInteger(63), NIL), NIL), listO(3, SYM_READ_STELLA_ii, SYM_READ_STELLA_TOK_CURSOR_, NIL), NIL), listO(3, SYM_READ_STELLA_OTHERWISE, cons(SYM_READ_STELLA_BREAK, NIL), NIL), NIL), (((!withTokenizerStringInputP()) ? cons(listO(4, SYM_READ_STELLA_WHEN, listO(3, SYM_READ_STELLA_DEFINEDp, SYM_READ_STELLA_TOK_ECHOSTREAM_, NIL), listO(4, SYM_READ_STELLA_PRINT_STREAM, SYM_READ_STELLA_TOK_ECHOSTREAM_, listO(4, SYM_READ_STELLA_BYTE_ARRAY_NTH, SYM_READ_STELLA_TOK_BUFFER_, listO(3, SYM_READ_STELLA_1_, SYM_READ_STELLA_TOK_CURSOR_, NIL), NIL), NIL), NIL), NIL) : NIL))->concatenate(NIL, 0))), savestreamstatetree->concatenate(NIL, 0)));
  }
}

char* unescapeTokenString(char* token, char escapechar, boolean upcaseP) {
  { int nofescapes = 0;
    int cursor = 0;
    int cursor2 = 0;
    int size = strlen(token);
    char* result = NULL;
    boolean escapeP = FALSE;

    while (cursor < size) {
      if (token[cursor] == escapechar) {
        nofescapes = nofescapes + 1;
        cursor = cursor + 1;
      }
      cursor = cursor + 1;
    }
    if (nofescapes == 0) {
      return (token);
    }
    result = makeRawMutableString(size - nofescapes);
    cursor = 0;
    while (cursor < size) {
      if ((token[cursor] == escapechar) &&
          (!escapeP)) {
        escapeP = TRUE;
      }
      else if (upcaseP &&
          (!escapeP)) {
        result[cursor2] = (oCHARACTER_UPCASE_TABLEo[((int)(unsigned char) (token[cursor]))]);
        cursor2 = cursor2 + 1;
      }
      else {
        result[cursor2] = (token[cursor]);
        escapeP = FALSE;
        cursor2 = cursor2 + 1;
      }
      cursor = cursor + 1;
    }
    return (result);
  }
}

StreamTokenizer* newStreamTokenizer(InputStream* stream, TokenizerTable* table) {
  { StreamTokenizer* self = NULL;

    self = new StreamTokenizer();
    self->stream = stream;
    self->table = table;
    self->firstIterationP = TRUE;
    self->value = NULL;
    return (self);
  }
}

Surrogate* StreamTokenizer::primaryType() {
  { StreamTokenizer* self = this;

    return (SGT_READ_STELLA_STREAM_TOKENIZER);
  }
}

Object* accessStreamTokenizerSlotValue(StreamTokenizer* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_READ_STELLA_STREAM) {
    if (setvalueP) {
      self->stream = ((InputStream*)(value));
    }
    else {
      value = self->stream;
    }
  }
  else if (slotname == SYM_READ_STELLA_TABLE) {
    if (setvalueP) {
      self->table = ((TokenizerTable*)(value));
    }
    else {
      value = self->table;
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

boolean StreamTokenizer::nextP() {
  { StreamTokenizer* self = this;

    { TokenizerTable* tok_table_ = self->table;
      char* tok_transitions_ = tok_table_->transitions;
      Object** tok_statenames_ = tok_table_->stateNames->theArray;
      int tok_tokenstart_ = -1;
      boolean tok_endoftokensP_ = FALSE;
      InputStream* tok_inputstream_ = self->stream;
      OutputStream* tok_echostream_ = tok_inputstream_->echoStream;
      TokenizerStreamState* tok_streamstate_ = ((!((boolean)(tok_inputstream_->tokenizerState))) ? (tok_inputstream_->tokenizerState = newTokenizerStreamState()) : tok_inputstream_->tokenizerState);
      char* tok_buffer_ = tok_streamstate_->buffer;
      int tok_size_ = tok_streamstate_->bufferSize;
      int tok_state_ = tok_streamstate_->state;
      int tok_nextstate_ = tok_state_;
      int tok_cursor_ = tok_streamstate_->cursor;
      int tok_end_ = tok_streamstate_->end;
      int tok_checkpoint_ = ((tok_cursor_ <= tok_end_) ? tok_end_ : tok_size_);

      {
        tok_statenames_ = tok_statenames_;
        tok_endoftokensP_ = tok_endoftokensP_;
      }
      {
        tok_tokenstart_ = -1;
        for (;;) {
          if (tok_cursor_ == tok_checkpoint_) {
            if (tok_cursor_ == tok_end_) {
              tok_streamstate_->cursor = tok_cursor_;
              tok_endoftokensP_ = readIntoTokenizerBuffer(tok_inputstream_, tok_streamstate_, tok_tokenstart_);
              tok_buffer_ = tok_streamstate_->buffer;
              tok_size_ = tok_streamstate_->bufferSize;
              tok_cursor_ = mod(tok_streamstate_->cursor, tok_size_);
              tok_end_ = tok_streamstate_->end;
              if (tok_endoftokensP_) {
                if (tok_nextstate_ == -1) {
                }
                else if (coerceWrappedBooleanToBoolean(((BooleanWrapper*)((tok_table_->legalEofStates->theArray)[tok_state_])))) {
                  tok_nextstate_ = -1;
                  if (!(tok_tokenstart_ == -1)) {
                    tok_endoftokensP_ = FALSE;
                  }
                }
                else {
                  tok_endoftokensP_ = FALSE;
                  tok_state_ = 0;
                  tok_nextstate_ = -1;
                }
                break;
              }
              if (tok_cursor_ >= tok_end_) {
                tok_checkpoint_ = tok_size_;
              }
              else {
                tok_checkpoint_ = tok_end_;
              }
            }
            else {
              tok_checkpoint_ = tok_end_;
              tok_cursor_ = 0;
            }
          }
          tok_nextstate_ = (int)(unsigned char) (tok_transitions_[((((tok_state_ << 8)) | ((int)(unsigned char) (tok_buffer_[tok_cursor_]))))]);
          if ((tok_nextstate_ & 128) == 0) {
            tok_state_ = tok_nextstate_;
            tok_cursor_ = tok_cursor_ + 1;
          }
          else if (tok_tokenstart_ == -1) {
            if ((tok_nextstate_ & 64) == 0) {
              tok_tokenstart_ = tok_cursor_;
            }
            tok_state_ = (tok_nextstate_ & 63);
            tok_cursor_ = tok_cursor_ + 1;
          }
          else {
            break;
          }
          if (((boolean)(tok_echostream_))) {
            *(tok_echostream_->nativeStream) << tok_buffer_[(tok_cursor_ - 1)];
          }
        }
        if (((boolean)(tok_streamstate_))) {
          tok_streamstate_->cursor = tok_cursor_;
          tok_streamstate_->state = tok_state_;
        }
      }
      if (tok_endoftokensP_) {
        self->value = NULL;
      }
      else {
        { TokenizerToken* self001 = newTokenizerToken();

          self001->type = ((Keyword*)(((GeneralizedSymbol*)(tok_statenames_[tok_state_]))));
          self001->content = getTokenTextInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, FALSE);
          self->value = self001;
        }
      }
    }
    return (((boolean)(((TokenizerToken*)(self->value)))));
  }
}

Cons* oSTELLA_TOKENIZER_TABLE_DEFINITIONo = NULL;

TokenizerTable* oSTELLA_TOKENIZER_TABLEo = NULL;

Vector* oSTELLA_LOGICAL_STATE_NAMESo = NULL;

PropertyList* oSTELLA_LOGICAL_STATE_NAMES_TABLEo = NULL;

Object* withStellaTokenizer(Object* input, Cons* body) {
  return (listO(4, SYM_READ_STELLA_WITH_TOKENIZER, SYM_READ_STELLA_oSTELLA_TOKENIZER_TABLEo, input, cons(listO(3, SYM_READ_STELLA_LET, listO(3, listO(3, SYM_READ_STELLA_TOK_STELLALOGICALSTATENAMES_, listO(3, SYM_READ_STELLA_THE_ARRAY, SYM_READ_STELLA_oSTELLA_LOGICAL_STATE_NAMESo, NIL), NIL), listO(4, SYM_READ_STELLA_TOK_STELLALOGICALSTATENAME_, SYM_READ_STELLA_KEYWORD, SYM_READ_STELLA_NULL, NIL), NIL), body->concatenate(NIL, 0)), NIL)));
}

Object* getNextStellaToken(Cons* options) {
  return (listO(4, SYM_READ_STELLA_PROGN, cons(SYM_READ_STELLA_GET_NEXT_TOKEN, options->concatenate(NIL, 0)), listO(4, SYM_READ_STELLA_SETQ, SYM_READ_STELLA_TOK_STELLALOGICALSTATENAME_, listO(4, SYM_READ_STELLA_NTH, SYM_READ_STELLA_TOK_STELLALOGICALSTATENAMES_, SYM_READ_STELLA_TOK_STATE_, NIL), NIL), NIL));
}

Object* getStellaTokenType() {
  return (SYM_READ_STELLA_TOK_STELLALOGICALSTATENAME_);
}

Object* getQualifiedSymbolSeparatorPosition(Cons* escapemode) {
  { Object* escape = escapemode->value;

    if (!((boolean)(escape))) {
      escape = KWD_READ_NONE;
    }
    return (listO(7, SYM_READ_STELLA_GET_QUALIFIED_SYMBOL_SEPARATOR_POSITION_INTERNAL, SYM_READ_STELLA_TOK_BUFFER_, SYM_READ_STELLA_TOK_TOKENSTART_, SYM_READ_STELLA_TOK_CURSOR_, SYM_READ_STELLA_TOK_SIZE_, escape, NIL));
  }
}

int getQualifiedSymbolSeparatorPositionInternal(char* buffer, int tokenstart, int tokenend, int size, Keyword* escapemode) {
  { int cursor = tokenend - 1;
    int separatorposition = 0;
    int nofescapes = 0;
    boolean fullyescapedP = escapemode == KWD_READ_FULLY_ESCAPED;
    char targetchar = (fullyescapedP ? '|' : MODULE_SEPARATOR_CHARACTER);

    for (;;) {
      while (cursor >= 0) {
        if (buffer[cursor] == targetchar) {
          separatorposition = cursor;
          cursor = cursor - 1;
          if (cursor < 0) {
            cursor = size - 1;
          }
          nofescapes = 0;
          for (;;) {
            while ((cursor >= 0) &&
                (buffer[cursor] == '\\')) {
              nofescapes = nofescapes + 1;
              cursor = cursor - 1;
            }
            if ((cursor < 0) &&
                (buffer[0] == '\\')) {
              cursor = size - 1;
            }
            else {
              break;
            }
          }
          if (!(nofescapes % 2)) {
            separatorposition = separatorposition - tokenstart;
            if (fullyescapedP) {
              separatorposition = separatorposition - 1;
            }
            if (separatorposition < 0) {
              return (separatorposition + size);
            }
            else {
              return (separatorposition);
            }
          }
        }
        else {
          cursor = cursor - 1;
        }
      }
      cursor = size - 1;
    }
  }
}

StellaToken* newStellaToken() {
  { StellaToken* self = NULL;

    self = new StellaToken();
    self->content = NULL;
    self->type = NULL;
    self->next = NULL;
    self->escapeMode = NULL;
    self->module = NULL;
    self->logicalTokenType = NULL;
    return (self);
  }
}

Surrogate* StellaToken::primaryType() {
  { StellaToken* self = this;

    return (SGT_READ_STELLA_STELLA_TOKEN);
  }
}

Object* accessStellaTokenSlotValue(StellaToken* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_READ_STELLA_LOGICAL_TOKEN_TYPE) {
    if (setvalueP) {
      self->logicalTokenType = ((Keyword*)(value));
    }
    else {
      value = self->logicalTokenType;
    }
  }
  else if (slotname == SYM_READ_STELLA_MODULE) {
    if (setvalueP) {
      self->module = ((StringWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapString(self->module);
    }
  }
  else if (slotname == SYM_READ_STELLA_ESCAPE_MODE) {
    if (setvalueP) {
      self->escapeMode = ((Keyword*)(value));
    }
    else {
      value = self->escapeMode;
    }
  }
  else if (slotname == SYM_READ_STELLA_NEXT) {
    if (setvalueP) {
      self->next = ((StellaToken*)(value));
    }
    else {
      value = ((StellaToken*)(self->next));
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

StellaToken* tokenizeSExpression(InputStream* stream, StellaToken* tokenlist) {
  { boolean upcaseP = !oMODULEo.get()->caseSensitiveP;
    int parenbalance = 0;
    boolean endoffileP = TRUE;
    boolean skipclosingquoteP = FALSE;
    StellaToken* tokencursor = tokenlist;

    if (!((boolean)(tokenlist))) {
      tokenlist = newStellaToken();
      tokencursor = tokenlist;
    }
    { TokenizerTable* tok_table_ = oSTELLA_TOKENIZER_TABLEo;
      char* tok_transitions_ = tok_table_->transitions;
      Object** tok_statenames_ = tok_table_->stateNames->theArray;
      int tok_tokenstart_ = -1;
      boolean tok_endoftokensP_ = FALSE;
      InputStream* tok_inputstream_ = stream;
      OutputStream* tok_echostream_ = tok_inputstream_->echoStream;
      TokenizerStreamState* tok_streamstate_ = ((!((boolean)(tok_inputstream_->tokenizerState))) ? (tok_inputstream_->tokenizerState = newTokenizerStreamState()) : tok_inputstream_->tokenizerState);
      char* tok_buffer_ = tok_streamstate_->buffer;
      int tok_size_ = tok_streamstate_->bufferSize;
      int tok_state_ = tok_streamstate_->state;
      int tok_nextstate_ = tok_state_;
      int tok_cursor_ = tok_streamstate_->cursor;
      int tok_end_ = tok_streamstate_->end;
      int tok_checkpoint_ = ((tok_cursor_ <= tok_end_) ? tok_end_ : tok_size_);

      {
        tok_statenames_ = tok_statenames_;
        tok_endoftokensP_ = tok_endoftokensP_;
      }
      { Object** tok_stellalogicalstatenames_ = oSTELLA_LOGICAL_STATE_NAMESo->theArray;
        Keyword* tok_stellalogicalstatename_ = NULL;

        for (;;) {
          {
            {
              tok_tokenstart_ = -1;
              for (;;) {
                if (tok_cursor_ == tok_checkpoint_) {
                  if (tok_cursor_ == tok_end_) {
                    tok_streamstate_->cursor = tok_cursor_;
                    tok_endoftokensP_ = readIntoTokenizerBuffer(tok_inputstream_, tok_streamstate_, tok_tokenstart_);
                    tok_buffer_ = tok_streamstate_->buffer;
                    tok_size_ = tok_streamstate_->bufferSize;
                    tok_cursor_ = mod(tok_streamstate_->cursor, tok_size_);
                    tok_end_ = tok_streamstate_->end;
                    if (tok_endoftokensP_) {
                      if (tok_nextstate_ == -1) {
                      }
                      else if (coerceWrappedBooleanToBoolean(((BooleanWrapper*)((tok_table_->legalEofStates->theArray)[tok_state_])))) {
                        tok_nextstate_ = -1;
                        if (!(tok_tokenstart_ == -1)) {
                          tok_endoftokensP_ = FALSE;
                        }
                      }
                      else {
                        tok_endoftokensP_ = FALSE;
                        tok_state_ = 0;
                        tok_nextstate_ = -1;
                      }
                      break;
                    }
                    if (tok_cursor_ >= tok_end_) {
                      tok_checkpoint_ = tok_size_;
                    }
                    else {
                      tok_checkpoint_ = tok_end_;
                    }
                  }
                  else {
                    tok_checkpoint_ = tok_end_;
                    tok_cursor_ = 0;
                  }
                }
                tok_nextstate_ = (int)(unsigned char) (tok_transitions_[((((tok_state_ << 8)) | ((int)(unsigned char) (tok_buffer_[tok_cursor_]))))]);
                if ((tok_nextstate_ & 128) == 0) {
                  tok_state_ = tok_nextstate_;
                  tok_cursor_ = tok_cursor_ + 1;
                }
                else if (tok_tokenstart_ == -1) {
                  if ((tok_nextstate_ & 64) == 0) {
                    tok_tokenstart_ = tok_cursor_;
                  }
                  tok_state_ = (tok_nextstate_ & 63);
                  tok_cursor_ = tok_cursor_ + 1;
                }
                else {
                  break;
                }
                if (((boolean)(tok_echostream_))) {
                  *(tok_echostream_->nativeStream) << tok_buffer_[(tok_cursor_ - 1)];
                }
              }
            }
            tok_stellalogicalstatename_ = ((Keyword*)(tok_stellalogicalstatenames_[tok_state_]));
          }
          if (tok_endoftokensP_) {
            if (parenbalance == 0) {
              break;
            }
            if (((boolean)(tok_streamstate_))) {
              tok_streamstate_->cursor = tok_cursor_;
              tok_streamstate_->state = tok_state_;
            }
            throw *newReadException("Expression ended prematurely");
          }
          endoffileP = FALSE;
          if (!(skipclosingquoteP)) {
            tokencursor->type = ((Keyword*)(((GeneralizedSymbol*)(tok_statenames_[tok_state_]))));
            tokencursor->logicalTokenType = tok_stellalogicalstatename_;
            tokencursor->module = NULL;
            tokencursor->escapeMode = NULL;
          }
          skipclosingquoteP = FALSE;
          if (tok_stellalogicalstatename_ == KWD_READ_OPEN_PAREN) {
            parenbalance = parenbalance + 1;
            tokencursor->content = "(";
          }
          else if (tok_stellalogicalstatename_ == KWD_READ_CLOSE_PAREN) {
            parenbalance = parenbalance - 1;
            tokencursor->content = ")";
            if (parenbalance < 0) {
              if (((boolean)(tok_streamstate_))) {
                tok_streamstate_->cursor = tok_cursor_;
                tok_streamstate_->state = tok_state_;
              }
              throw *newReadException("Extra right parenthesis encountered");
            }
          }
          else if (tok_stellalogicalstatename_ == KWD_READ_SYMBOL) {
            { GeneralizedSymbol* testValue000 = ((GeneralizedSymbol*)(tok_statenames_[tok_state_]));

              if (testValue000 == KWD_READ_SYMBOL) {
                tokencursor->content = getTokenTextInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, upcaseP);
              }
              else if (testValue000 == KWD_READ_QUALIFIED_SYMBOL) {
                { int separatorpos = getQualifiedSymbolSeparatorPositionInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, KWD_READ_NONE);

                  tokencursor->content = getTokenTextInternal(tok_buffer_, tok_tokenstart_ + separatorpos + 1, tok_cursor_, tok_size_, upcaseP);
                  tokencursor->module = ((separatorpos == 0) ? (char*)"ROOT-MODULE" : getTokenTextInternal(tok_buffer_, tok_tokenstart_, ((separatorpos < 0) ? (tok_cursor_ + separatorpos) : (tok_tokenstart_ + separatorpos)), tok_size_, TRUE));
                }
              }
              else if (testValue000 == KWD_READ_FULLY_ESCAPED_SYMBOL) {
                tokencursor->content = unescapeTokenString(getTokenTextInternal(tok_buffer_, tok_tokenstart_ + 1, tok_cursor_, tok_size_, FALSE), '\\', FALSE);
                tokencursor->escapeMode = KWD_READ_FULL;
                skipclosingquoteP = TRUE;
              }
              else if (testValue000 == KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL) {
                { int separatorpos = getQualifiedSymbolSeparatorPositionInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, KWD_READ_FULLY_ESCAPED);

                  tokencursor->content = unescapeTokenString(getTokenTextInternal(tok_buffer_, tok_tokenstart_ + separatorpos + 2, tok_cursor_, tok_size_, FALSE), '\\', FALSE);
                  tokencursor->module = ((separatorpos == 0) ? (char*)"ROOT-MODULE" : getTokenTextInternal(tok_buffer_, tok_tokenstart_, ((separatorpos < 0) ? (tok_cursor_ + separatorpos) : (tok_tokenstart_ + separatorpos)), tok_size_, TRUE));
                  tokencursor->escapeMode = KWD_READ_FULL;
                }
                skipclosingquoteP = TRUE;
              }
              else if (testValue000 == KWD_READ_ESCAPED_SYMBOL) {
                tokencursor->content = unescapeTokenString(getTokenTextInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, FALSE), '\\', upcaseP);
                tokencursor->escapeMode = KWD_READ_PARTIAL;
              }
              else if (testValue000 == KWD_READ_QUALIFIED_ESCAPED_SYMBOL) {
                { int separatorpos = getQualifiedSymbolSeparatorPositionInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, KWD_READ_ESCAPED);

                  tokencursor->content = unescapeTokenString(getTokenTextInternal(tok_buffer_, tok_tokenstart_ + separatorpos + 1, tok_cursor_, tok_size_, FALSE), '\\', upcaseP);
                  tokencursor->module = ((separatorpos == 0) ? (char*)"ROOT-MODULE" : getTokenTextInternal(tok_buffer_, tok_tokenstart_, ((separatorpos < 0) ? (tok_cursor_ + separatorpos) : (tok_tokenstart_ + separatorpos)), tok_size_, TRUE));
                  tokencursor->escapeMode = KWD_READ_PARTIAL;
                }
              }
              else if (testValue000 == KWD_READ_CL_SYMBOL) {
                tokencursor->content = getTokenTextInternal(tok_buffer_, tok_tokenstart_ + 3, tok_cursor_, tok_size_, TRUE);
                tokencursor->module = "/COMMON-LISP";
              }
              else {
                { OutputStringStream* stream000 = newOutputStringStream();

                  *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
                  throw *newStellaException(stream000->theStringReader());
                }
              }
            }
          }
          else if (tok_stellalogicalstatename_ == KWD_READ_SURROGATE) {
            { GeneralizedSymbol* testValue001 = ((GeneralizedSymbol*)(tok_statenames_[tok_state_]));

              if (testValue001 == KWD_READ_SURROGATE) {
                tokencursor->content = getTokenTextInternal(tok_buffer_, tok_tokenstart_ + 1, tok_cursor_, tok_size_, upcaseP);
              }
              else if (testValue001 == KWD_READ_QUALIFIED_SURROGATE) {
                { int separatorpos = getQualifiedSymbolSeparatorPositionInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, KWD_READ_NONE);

                  tokencursor->content = getTokenTextInternal(tok_buffer_, tok_tokenstart_ + separatorpos + 2, tok_cursor_, tok_size_, upcaseP);
                  tokencursor->module = ((separatorpos == 0) ? (char*)"ROOT-MODULE" : getTokenTextInternal(tok_buffer_, tok_tokenstart_, ((separatorpos < 0) ? (tok_cursor_ + separatorpos) : (tok_tokenstart_ + separatorpos)), tok_size_, TRUE));
                }
              }
              else if (testValue001 == KWD_READ_FULLY_ESCAPED_SURROGATE) {
                tokencursor->content = unescapeTokenString(getTokenTextInternal(tok_buffer_, tok_tokenstart_ + 2, tok_cursor_, tok_size_, FALSE), '\\', FALSE);
                tokencursor->escapeMode = KWD_READ_FULL;
                skipclosingquoteP = TRUE;
              }
              else if (testValue001 == KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE) {
                { int separatorpos = getQualifiedSymbolSeparatorPositionInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, KWD_READ_FULLY_ESCAPED);

                  tokencursor->content = unescapeTokenString(getTokenTextInternal(tok_buffer_, tok_tokenstart_ + separatorpos + 3, tok_cursor_, tok_size_, FALSE), '\\', FALSE);
                  tokencursor->module = ((separatorpos == 0) ? (char*)"ROOT-MODULE" : getTokenTextInternal(tok_buffer_, tok_tokenstart_, ((separatorpos < 0) ? (tok_cursor_ + separatorpos) : (tok_tokenstart_ + separatorpos)), tok_size_, TRUE));
                  tokencursor->escapeMode = KWD_READ_FULL;
                }
                skipclosingquoteP = TRUE;
              }
              else if (testValue001 == KWD_READ_ESCAPED_SURROGATE) {
                tokencursor->content = unescapeTokenString(getTokenTextInternal(tok_buffer_, tok_tokenstart_ + 1, tok_cursor_, tok_size_, FALSE), '\\', upcaseP);
                tokencursor->escapeMode = KWD_READ_PARTIAL;
              }
              else if (testValue001 == KWD_READ_QUALIFIED_ESCAPED_SURROGATE) {
                { int separatorpos = getQualifiedSymbolSeparatorPositionInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, KWD_READ_ESCAPED);

                  tokencursor->content = unescapeTokenString(getTokenTextInternal(tok_buffer_, tok_tokenstart_ + separatorpos + 2, tok_cursor_, tok_size_, FALSE), '\\', upcaseP);
                  tokencursor->module = ((separatorpos == 0) ? (char*)"ROOT-MODULE" : getTokenTextInternal(tok_buffer_, tok_tokenstart_, ((separatorpos < 0) ? (tok_cursor_ + separatorpos) : (tok_tokenstart_ + separatorpos)), tok_size_, TRUE));
                  tokencursor->escapeMode = KWD_READ_PARTIAL;
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
          else if (tok_stellalogicalstatename_ == KWD_READ_KEYWORD) {
            { GeneralizedSymbol* testValue002 = ((GeneralizedSymbol*)(tok_statenames_[tok_state_]));

              if (testValue002 == KWD_READ_KEYWORD) {
                tokencursor->content = getTokenTextInternal(tok_buffer_, tok_tokenstart_ + 1, tok_cursor_, tok_size_, TRUE);
              }
              else if (testValue002 == KWD_READ_FULLY_ESCAPED_KEYWORD) {
                tokencursor->content = unescapeTokenString(getTokenTextInternal(tok_buffer_, tok_tokenstart_ + 2, tok_cursor_, tok_size_, FALSE), '\\', FALSE);
                tokencursor->escapeMode = KWD_READ_FULL;
                skipclosingquoteP = TRUE;
              }
              else if (testValue002 == KWD_READ_ESCAPED_KEYWORD) {
                tokencursor->content = unescapeTokenString(getTokenTextInternal(tok_buffer_, tok_tokenstart_ + 1, tok_cursor_, tok_size_, FALSE), '\\', TRUE);
                tokencursor->escapeMode = KWD_READ_PARTIAL;
              }
              else {
                { OutputStringStream* stream002 = newOutputStringStream();

                  *(stream002->nativeStream) << "`" << testValue002 << "'" << " is not a valid case option";
                  throw *newStellaException(stream002->theStringReader());
                }
              }
            }
          }
          else if (tok_stellalogicalstatename_ == KWD_READ_STRING) {
            tokencursor->content = getTokenTextInternal(tok_buffer_, tok_tokenstart_ + 1, tok_cursor_, tok_size_, FALSE);
            { GeneralizedSymbol* testValue003 = ((GeneralizedSymbol*)(tok_statenames_[tok_state_]));

              if (testValue003 == KWD_READ_STRING) {
              }
              else if (testValue003 == KWD_READ_ESCAPED_STRING) {
                tokencursor->content = unescapeTokenString(tokencursor->content, '\\', FALSE);
                tokencursor->escapeMode = KWD_READ_PARTIAL;
              }
              else {
                { OutputStringStream* stream003 = newOutputStringStream();

                  *(stream003->nativeStream) << "`" << testValue003 << "'" << " is not a valid case option";
                  throw *newStellaException(stream003->theStringReader());
                }
              }
            }
            skipclosingquoteP = TRUE;
          }
          else if ((tok_stellalogicalstatename_ == KWD_READ_INTEGER) ||
              (tok_stellalogicalstatename_ == KWD_READ_FLOAT)) {
            tokencursor->content = getTokenTextInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, FALSE);
          }
          else if (tok_stellalogicalstatename_ == KWD_READ_CHARACTER) {
            { char* name = getTokenTextInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, FALSE);

              if (strlen(name) > 1) {
                name = stringUpcase(name);
              }
              tokencursor->content = name;
            }
          }
          else if ((tok_stellalogicalstatename_ == KWD_READ_SINGLE_QUOTE) ||
              ((tok_stellalogicalstatename_ == KWD_READ_BACK_QUOTE) ||
               ((tok_stellalogicalstatename_ == KWD_READ_COMMA) ||
                (tok_stellalogicalstatename_ == KWD_READ_COMMA_SPLICE)))) {
            tokencursor->content = getTokenTextInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, FALSE);
            if (!((boolean)(((StellaToken*)(tokencursor->next))))) {
              tokencursor->next = newStellaToken();
            }
            tokencursor = ((StellaToken*)(tokencursor->next));
            continue;
          }
          else if (tok_stellalogicalstatename_ == KWD_READ_QUALIFIED_NAME) {
            { char* token = getTokenTextInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, TRUE);
              int length = strlen(token);

              if ((length >= 1) &&
                  ((token[(length - 1)] == '/') &&
                   ((length == 1) ||
                    (token[(length - 2)] == '/')))) {
                tokencursor->content = "/";
                tokencursor->type = KWD_READ_SYMBOL;
                tokencursor->logicalTokenType = KWD_READ_SYMBOL;
                if (length > 1) {
                  tokencursor->module = stringSubsequence(token, 0, length - 2);
                  tokencursor->type = KWD_READ_QUALIFIED_SYMBOL;
                }
              }
              else {
                tokencursor->content = token;
              }
            }
          }
          else if (tok_stellalogicalstatename_ == KWD_READ_CLOSE_BALANCED_QUOTE) {
          }
          else if (tok_stellalogicalstatename_ == KWD_READ_ERROR) {
            if (((boolean)(tok_streamstate_))) {
              tok_streamstate_->cursor = tok_cursor_;
              tok_streamstate_->state = tok_state_;
            }
            { OutputStringStream* stream004 = newOutputStringStream();

              *(stream004->nativeStream) << "Illegal read syntax: " << "`" << getTokenTextInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, FALSE) << "'";
              throw *newReadException(stream004->theStringReader());
            }
          }
          else {
            if (((boolean)(tok_streamstate_))) {
              tok_streamstate_->cursor = tok_cursor_;
              tok_streamstate_->state = tok_state_;
            }
            { OutputStringStream* stream005 = newOutputStringStream();

              *(stream005->nativeStream) << "Illegal read syntax: " << "`" << getTokenTextInternal(tok_buffer_, tok_tokenstart_, tok_cursor_, tok_size_, FALSE) << "'" << " in state " << "`" << ((GeneralizedSymbol*)(tok_statenames_[tok_state_])) << "'";
              throw *newReadException(stream005->theStringReader());
            }
          }
          if (!(skipclosingquoteP)) {
            if (!((boolean)(((StellaToken*)(tokencursor->next))))) {
              tokencursor->next = newStellaToken();
            }
            tokencursor = ((StellaToken*)(tokencursor->next));
            if (parenbalance == 0) {
              break;
            }
          }
        }
        tokencursor->type = NULL;
        tokencursor->logicalTokenType = NULL;
        if (((boolean)(tok_streamstate_))) {
          tok_streamstate_->cursor = tok_cursor_;
          tok_streamstate_->state = tok_state_;
        }
        if (endoffileP) {
          return (NULL);
        }
        else {
          return (tokenlist);
        }
      }
    }
  }
}

Object* stellaTokenListToSExpression(StellaToken* tokenlist) {
  { Cons* parsedtree = NULL;
    Cons* parsedtreestack = NIL;
    Object* parsedtoken = NULL;
    Cons* conscell = NULL;
    Keyword* tokentype = NULL;

    for (;;) {
      tokentype = tokenlist->logicalTokenType;
      if (tokentype == KWD_READ_OPEN_PAREN) {
        if (((boolean)(parsedtree))) {
          parsedtreestack = cons(parsedtree, parsedtreestack);
        }
        parsedtree = NIL;
        tokenlist = ((StellaToken*)(tokenlist->next));
        continue;
      }
      else if (tokentype == KWD_READ_CLOSE_PAREN) {
        if (parsedtreestack == NIL) {
          parsedtree = parsedtree->reverse();
          break;
        }
        else {
          { Cons* parenttree = parsedtreestack;

            { Cons* head000 = ((Cons*)(parsedtreestack->value));

              parsedtreestack = parsedtreestack->rest;
            }
            parenttree->rest = ((Cons*)(parenttree->value));
            parenttree->firstSetter(parsedtree->reverse());
            parsedtree = parenttree;
            tokenlist = ((StellaToken*)(tokenlist->next));
            continue;
          }
        }
      }
      else if ((tokentype == KWD_READ_SYMBOL) ||
          (tokentype == KWD_READ_SURROGATE)) {
        { char* modulename = tokenlist->module;
          char* name = tokenlist->content;
          Module* module = ((modulename != NULL) ? getStellaModule(modulename, FALSE) : oMODULEo.get());

          if (!((boolean)(module))) {
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "Module " << "`" << modulename << "'" << " does not exist";
              throw *newReadException(stream000->theStringReader());
            }
          }
          else if (tokentype == KWD_READ_SURROGATE) {
            parsedtoken = internSurrogateInModule(name, module, FALSE);
          }
          else {
            parsedtoken = ((oTRANSIENTOBJECTSpo.get() &&
                (modulename == NULL)) ? internTransientSymbol(name) : internSymbolInModule(name, module, FALSE));
          }
        }
      }
      else if (tokentype == KWD_READ_KEYWORD) {
        parsedtoken = internRigidSymbolWrtModule(tokenlist->content, NULL, KEYWORD_SYM);
      }
      else if (tokentype == KWD_READ_STRING) {
        parsedtoken = new StringWrapper();
        ((StringWrapper*)(parsedtoken))->wrapperValue = tokenlist->content;
      }
      else if (tokentype == KWD_READ_INTEGER) {
        parsedtoken = new IntegerWrapper();
        ((IntegerWrapper*)(parsedtoken))->wrapperValue = stringToInteger(tokenlist->content);
      }
      else if (tokentype == KWD_READ_FLOAT) {
        parsedtoken = new FloatWrapper();
        ((FloatWrapper*)(parsedtoken))->wrapperValue = stringToFloat(tokenlist->content);
      }
      else if (tokentype == KWD_READ_CHARACTER) {
        parsedtoken = new CharacterWrapper();
        ((CharacterWrapper*)(parsedtoken))->wrapperValue = stringToCharacter(tokenlist->content);
      }
      else if (tokentype == KWD_READ_COMMA) {
        parsedtoken = SYM_READ_STELLA_a;
      }
      else if (tokentype == KWD_READ_COMMA_SPLICE) {
        parsedtoken = SYM_READ_STELLA_aa;
      }
      else if ((tokentype == KWD_READ_SINGLE_QUOTE) ||
          (tokentype == KWD_READ_BACK_QUOTE)) {
        expandQuoteMacroToken(tokenlist);
        continue;
      }
      else {
        { OutputStringStream* stream001 = newOutputStringStream();

          *(stream001->nativeStream) << "Illegal read syntax: " << "`" << tokenlist->content << "'" << " of type " << "`" << tokentype << "'";
          throw *newReadException(stream001->theStringReader());
        }
      }
      if (((boolean)(parsedtree))) {
        conscell = new Cons();
        conscell->value = parsedtoken;
        conscell->rest = parsedtree;
        parsedtree = conscell;
        tokenlist = ((StellaToken*)(tokenlist->next));
      }
      else {
        break;
      }
    }
    if (!((boolean)(parsedtree))) {
      return (parsedtoken);
    }
    else {
      return (parsedtree);
    }
  }
}

void expandQuoteMacroToken(StellaToken* quotedlist) {
  { char* quotestring = quotedlist->content;

    { StellaToken* self000 = newStellaToken();

      self000->type = KWD_READ_SYMBOL;
      self000->logicalTokenType = KWD_READ_SYMBOL;
      self000->content = (stringEqlP(quotestring, "'") ? (char*)"QUOTE" : (char*)"BQUOTE");
      self000->module = "/STELLA";
      self000->next = ((StellaToken*)(quotedlist->next));
      { StellaToken* token = self000;
        Keyword* tokentype = NULL;
        int balance = 0;

        quotedlist->type = KWD_READ_OPEN_PAREN;
        quotedlist->logicalTokenType = KWD_READ_OPEN_PAREN;
        quotedlist->content = "(";
        quotedlist->next = token;
        quotedlist = ((StellaToken*)(token->next));
        for (;;) {
          tokentype = quotedlist->logicalTokenType;
          if (!((boolean)(tokentype))) {
            break;
          }
          if (tokentype == KWD_READ_OPEN_PAREN) {
            balance = balance + 1;
          }
          else if (tokentype == KWD_READ_CLOSE_PAREN) {
            balance = balance - 1;
            if (balance == 0) {
              break;
            }
            else if (balance < 0) {
              { OutputStringStream* stream000 = newOutputStringStream();

                *(stream000->nativeStream) << "Illegal " << "`" << quotestring << "'" << " syntax";
                throw *newReadException(stream000->theStringReader());
              }
            }
          }
          else {
            if (balance == 0) {
              break;
            }
          }
          quotedlist = ((StellaToken*)(quotedlist->next));
        }
        if (!((boolean)(tokentype))) {
          { OutputStringStream* stream001 = newOutputStringStream();

            *(stream001->nativeStream) << "EOF encountered while parsing " << "`" << quotestring << "'" << " syntax";
            throw *newReadException(stream001->theStringReader());
          }
        }
        { StellaToken* self005 = newStellaToken();

          self005->type = KWD_READ_CLOSE_PAREN;
          self005->logicalTokenType = KWD_READ_CLOSE_PAREN;
          self005->content = ")";
          self005->next = ((StellaToken*)(quotedlist->next));
          token = self005;
        }
        quotedlist->next = token;
      }
    }
  }
}

char stringToCharacter(char* name) {
  { char chaR = name[0];

    if (strlen(name) > 1) {
      if (stringEqlP(name, "SPACE")) {
        chaR = ' ';
      }
      else if (stringEqlP(name, "LINEFEED")) {
        chaR = '\n';
      }
      else if (stringEqlP(name, "NEWLINE")) {
        chaR = '\n';
      }
      else if (stringEqlP(name, "BACKSPACE")) {
        chaR = '\b';
      }
      else if (stringEqlP(name, "TAB")) {
        chaR = '\t';
      }
      else if (stringEqlP(name, "RETURN")) {
        chaR = '\r';
      }
      else if (stringEqlP(name, "PAGE")) {
        chaR = '\f';
      }
      else if (stringEqlP(name, "NULL")) {
        chaR = '\0';
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "Illegal character constant: " << "`" << stringConcatenate("#\\", name, 0) << "'";
          throw *newReadException(stream000->theStringReader());
        }
      }
    }
    return (chaR);
  }
}

Object* readSExpression(InputStream* stream, boolean& _Return1) {
  // Read one STELLA s-expression from `stream' and return
  // the result.  Return `true' as the second value on EOF.
  { TokenizerStreamState* tokenizerstate = stream->tokenizerState;
    StellaToken* tokenlist = (((boolean)(tokenizerstate)) ? ((StellaToken*)(tokenizerstate->tokenList)) : NULL);

    if (((boolean)(tokenlist))) {
      tokenlist = tokenizeSExpression(stream, tokenlist);
    }
    else {
      tokenlist = tokenizeSExpression(stream, NULL);
      stream->tokenizerState->tokenList = tokenlist;
    }
    if (!((boolean)(tokenlist))) {
      _Return1 = TRUE;
      return (NULL);
    }
    if ((stream == STANDARD_INPUT) ||
        ((boolean)(stream->echoStream))) {
      eatNextCharacterIfWhitespace(stream);
    }
    _Return1 = FALSE;
    return (stellaTokenListToSExpression(tokenlist));
  }
}

int oSTELLA_TOKENIZER_WHITE_SPACE_STATEo = NULL_INTEGER;

boolean eatNextCharacterIfWhitespace(InputStream* stream) {
  { char chaR = NULL_CHARACTER;
    boolean eofP = FALSE;

    chaR = readCharacter(stream, eofP);
    if (eofP) {
      return (TRUE);
    }
    if (oCHARACTER_TYPE_TABLEo[(int)(unsigned char) chaR] == KWD_READ_WHITE_SPACE) {
      { TokenizerStreamState* state = stream->tokenizerState;

        if (((boolean)(state))) {
          state->state = oSTELLA_TOKENIZER_WHITE_SPACE_STATEo;
        }
      }
    }
    else {
      unreadCharacter(chaR, stream);
    }
    return (FALSE);
  }
}

boolean consumeWhitespace(InputStream* stream) {
  for (;;) {
    { char chaR = NULL_CHARACTER;
      boolean eofP = FALSE;

      chaR = readCharacter(stream, eofP);
      if (eofP) {
        return (TRUE);
      }
      if (!(oCHARACTER_TYPE_TABLEo[(int)(unsigned char) chaR] == KWD_READ_WHITE_SPACE)) {
        unreadCharacter(chaR, stream);
        break;
      }
    }
  }
  return (FALSE);
}

Object* readSExpressionFromString(char* string) {
  // Read one STELLA s-expression from `string' and
  // return the result.
  { boolean dummy1;

    return (readSExpression(makeTokenizerStringStream(string), dummy1));
  }
}

InputStringStream* makeTokenizerStringStream(char* string) {
  { InputStringStream* stream = newInputStringStream(string);
    TokenizerStreamState* state = new TokenizerStreamState();
    int length = strlen(string) + 1;

    state->buffer = new (GC) char[length];
    state->bufferSize = length;
    state->cursor = length;
    state->end = length;
    state->state = 1;
    state->tokenList = newStellaToken();
    stream->tokenizerState = state;
    return (stream);
  }
}

char* readLine(InputStream* inputstream, boolean& _Return1) {
  // Read one line from `inputStream' and return the result.
  // Return `true' as the second value on EOF.
  if (((boolean)(inputstream->tokenizerState))) {
    return (readLineFromTokenizerBuffer(inputstream, _Return1));
  }
  { std::istream* stream = inputstream->nativeStream;
    OutputStream* echostream = inputstream->echoStream;
    char* input = NULL;

    input = native_read_line(stream);
    if (((boolean)(echostream)) &&
        (input != NULL)) {
      *(echostream->nativeStream) << input << std::endl;
    }
    { char* _return_temp = input;

      _Return1 = input == NULL;
      return (_return_temp);
    }
  }
}

char readCharacter(InputStream* inputstream, boolean& _Return1) {
  // Read one character from `inputStream' and return the result.
  // Return `true' as the second value on EOF.
  if (((boolean)(inputstream->tokenizerState))) {
    return (readCharacterFromTokenizerBuffer(inputstream, _Return1));
  }
  { std::istream* stream = inputstream->nativeStream;
    OutputStream* echostream = inputstream->echoStream;
    char input = NULL_CHARACTER;
    boolean eof = FALSE;

    input = native_read_character(stream, eof);
    if (((boolean)(echostream)) &&
        (!eof)) {
      *(echostream->nativeStream) << input;
    }
    _Return1 = eof;
    return (input);
  }
}

void unreadCharacter(char ch, InputStream* inputstream) {
  // Unread `ch' from `inputStream'.  Signal an error if `ch'
  // was not the last character read.
  if (((boolean)(inputstream->tokenizerState))) {
    unreadCharacterFromTokenizerBuffer(ch, inputstream);
  }
  else {
    { std::istream* stream = inputstream->nativeStream;

      stream->putback(ch);
    }
  }
}

// Controls the behavior of interactive queries.  The default is :ASK
// which asks the user.  Other options are :YES, :NO, :YES-VERBOSE, :NO-VERBOSE.  These
// return the answer indicated, with the verbose versions printing the message and answer.
DEFINE_STELLA_SPECIAL(oUSER_QUERY_ACTIONo, Keyword* , NULL);

boolean yesOrNoP(char* message) {
  // Read a line of input from STANDARD-INPUT and return `true'
  // if the input was `yes' or `false' if the input was `no'.  Loop until either
  // `yes' or `no' was entered.  If 'message' is non-`null' prompt with it before
  // the input is read.  See also special variable `*USER-QUERY-ACTION*'.
  { boolean dummy1;

    if (oUSER_QUERY_ACTIONo.get() == KWD_READ_YES) {
      return (TRUE);
    }
    else if (oUSER_QUERY_ACTIONo.get() == KWD_READ_NO) {
      return (FALSE);
    }
    else if (oUSER_QUERY_ACTIONo.get() == KWD_READ_YES_VERBOSE) {
      std::cout << message << " [Auto => YES]" << std::endl;
      return (TRUE);
    }
    else if (oUSER_QUERY_ACTIONo.get() == KWD_READ_NO_VERBOSE) {
      std::cout << message << " [Auto => NO]" << std::endl;
      return (FALSE);
    }
    else if (oUSER_QUERY_ACTIONo.get() == KWD_READ_ASK) {
      { char* input = NULL;
        int start = 0;

        for (;;) {
          if (message != NULL) {
            std::cout << message;
          }
          input = readLine(STANDARD_INPUT, dummy1);
          start = 0;
          { char ch = NULL_CHARACTER;
            char* vector000 = input;
            int index000 = 0;
            int length000 = strlen(vector000);

            while (index000 < length000) {
              ch = vector000[index000];
              index000 = index000 + 1;
              if (oCHARACTER_TYPE_TABLEo[(int)(unsigned char) ch] == KWD_READ_WHITE_SPACE) {
                start = start + 1;
              }
              else {
                break;
              }
            }
          }
          if (strlen(input) > start) {
            input = stringSubsequence(input, start, NULL_INTEGER);
            if (stringEqualP(input, "yes")) {
              return (TRUE);
            }
            if (stringEqualP(input, "no")) {
              return (FALSE);
            }
            std::cout << "Type `yes' for yes or `no' for no." << std::endl;
          }
        }
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << oUSER_QUERY_ACTIONo.get() << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

boolean yOrNP(char* message) {
  // Read a line of input from STANDARD-INPUT and return `true'
  // if the input was `y' or `false' if the input was `n'.  Loop until either
  // `y' or `n' was entered.  If 'message' is non-`null' prompt with it before
  // the input is read.  See also special variable `*USER-QUERY-ACTION*'.
  { boolean dummy1;

    if (oUSER_QUERY_ACTIONo.get() == KWD_READ_YES) {
      return (TRUE);
    }
    else if (oUSER_QUERY_ACTIONo.get() == KWD_READ_NO) {
      return (FALSE);
    }
    else if (oUSER_QUERY_ACTIONo.get() == KWD_READ_YES_VERBOSE) {
      std::cout << message << " [Auto => Y]" << std::endl;
      return (TRUE);
    }
    else if (oUSER_QUERY_ACTIONo.get() == KWD_READ_NO_VERBOSE) {
      std::cout << message << " [Auto => N]" << std::endl;
      return (FALSE);
    }
    else if (oUSER_QUERY_ACTIONo.get() == KWD_READ_ASK) {
      { char* input = NULL;
        int start = 0;

        for (;;) {
          if (message != NULL) {
            std::cout << message;
          }
          input = readLine(STANDARD_INPUT, dummy1);
          start = 0;
          { char ch = NULL_CHARACTER;
            char* vector000 = input;
            int index000 = 0;
            int length000 = strlen(vector000);

            while (index000 < length000) {
              ch = vector000[index000];
              index000 = index000 + 1;
              if (oCHARACTER_TYPE_TABLEo[(int)(unsigned char) ch] == KWD_READ_WHITE_SPACE) {
                start = start + 1;
              }
              else {
                break;
              }
            }
          }
          if (strlen(input) > start) {
            switch (input[start]) {
              case 'y': 
              case 'Y': 
                return (TRUE);
              case 'n': 
              case 'N': 
                return (FALSE);
              default:
              break;
            }
          }
          std::cout << "Type `y' for yes or `n' for no." << std::endl;
        }
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << oUSER_QUERY_ACTIONo.get() << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

void helpStartupRead1() {
  {
    SGT_READ_STELLA_TOKENIZER_TABLE = ((Surrogate*)(internRigidSymbolWrtModule("TOKENIZER-TABLE", NULL, 1)));
    SYM_READ_STELLA_TRANSITIONS = ((Symbol*)(internRigidSymbolWrtModule("TRANSITIONS", NULL, 0)));
    SYM_READ_STELLA_UNIQUE_STATE_NAMES = ((Symbol*)(internRigidSymbolWrtModule("UNIQUE-STATE-NAMES", NULL, 0)));
    SYM_READ_STELLA_STATE_NAMES = ((Symbol*)(internRigidSymbolWrtModule("STATE-NAMES", NULL, 0)));
    SYM_READ_STELLA_LEGAL_EOF_STATES = ((Symbol*)(internRigidSymbolWrtModule("LEGAL-EOF-STATES", NULL, 0)));
    SYM_READ_STELLA_CHARACTER_SET = ((Symbol*)(internRigidSymbolWrtModule("CHARACTER-SET", NULL, 0)));
    KWD_READ_ERROR = ((Keyword*)(internRigidSymbolWrtModule("ERROR", NULL, 2)));
    KWD_READ_START = ((Keyword*)(internRigidSymbolWrtModule("START", NULL, 2)));
    KWD_READ_EOF = ((Keyword*)(internRigidSymbolWrtModule("EOF", NULL, 2)));
    SGT_READ_STELLA_GENERALIZED_SYMBOL = ((Surrogate*)(internRigidSymbolWrtModule("GENERALIZED-SYMBOL", NULL, 1)));
    SGT_READ_STELLA_CONS = ((Surrogate*)(internRigidSymbolWrtModule("CONS", NULL, 1)));
    KWD_READ_BLOCK = ((Keyword*)(internRigidSymbolWrtModule("BLOCK", NULL, 2)));
    KWD_READ_LINE = ((Keyword*)(internRigidSymbolWrtModule("LINE", NULL, 2)));
    KWD_READ_CHARACTER = ((Keyword*)(internRigidSymbolWrtModule("CHARACTER", NULL, 2)));
    SGT_READ_STELLA_TOKENIZER_TOKEN = ((Surrogate*)(internRigidSymbolWrtModule("TOKENIZER-TOKEN", NULL, 1)));
    SYM_READ_STELLA_TYPE = ((Symbol*)(internRigidSymbolWrtModule("TYPE", NULL, 0)));
    SYM_READ_STELLA_CONTENT = ((Symbol*)(internRigidSymbolWrtModule("CONTENT", NULL, 0)));
    SYM_READ_STELLA_NEXT = ((Symbol*)(internRigidSymbolWrtModule("NEXT", NULL, 0)));
    SGT_READ_STELLA_TOKENIZER_STREAM_STATE = ((Surrogate*)(internRigidSymbolWrtModule("TOKENIZER-STREAM-STATE", NULL, 1)));
    SYM_READ_STELLA_BUFFER_SIZE = ((Symbol*)(internRigidSymbolWrtModule("BUFFER-SIZE", NULL, 0)));
    SYM_READ_STELLA_CURSOR = ((Symbol*)(internRigidSymbolWrtModule("CURSOR", NULL, 0)));
    SYM_READ_STELLA_END = ((Symbol*)(internRigidSymbolWrtModule("END", NULL, 0)));
    SYM_READ_STELLA_STATE = ((Symbol*)(internRigidSymbolWrtModule("STATE", NULL, 0)));
    SYM_READ_STELLA_TOKEN_LIST = ((Symbol*)(internRigidSymbolWrtModule("TOKEN-LIST", NULL, 0)));
    SGT_READ_STELLA_INPUT_STREAM = ((Surrogate*)(internRigidSymbolWrtModule("INPUT-STREAM", NULL, 1)));
    SGT_READ_STELLA_STRING = ((Surrogate*)(internRigidSymbolWrtModule("STRING", NULL, 1)));
    SGT_READ_STELLA_VOID = ((Surrogate*)(internRigidSymbolWrtModule("VOID", NULL, 1)));
    SGT_READ_STELLA_MUTABLE_STRING = ((Surrogate*)(internRigidSymbolWrtModule("MUTABLE-STRING", NULL, 1)));
    SYM_READ_STELLA_LET = ((Symbol*)(internRigidSymbolWrtModule("LET", NULL, 0)));
    SYM_READ_STELLA_TOK_TABLE_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_TABLE_", NULL, 0)));
    SYM_READ_STELLA_TOK_TRANSITIONS_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_TRANSITIONS_", NULL, 0)));
    SYM_READ_STELLA_TOK_STATENAMES_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_STATENAMES_", NULL, 0)));
    SYM_READ_STELLA_THE_ARRAY = ((Symbol*)(internRigidSymbolWrtModule("THE-ARRAY", NULL, 0)));
    SYM_READ_STELLA_TOK_TOKENSTART_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_TOKENSTART_", NULL, 0)));
    SYM_READ_STELLA_TOK_ENDOFTOKENSp_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_ENDOFTOKENS?_", NULL, 0)));
    SYM_READ_STELLA_FALSE = ((Symbol*)(internRigidSymbolWrtModule("FALSE", NULL, 0)));
    SYM_READ_STELLA_IGNORE = ((Symbol*)(internRigidSymbolWrtModule("IGNORE", NULL, 0)));
    SYM_READ_STELLA_TOK_STREAMSTATE_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_STREAMSTATE_", NULL, 0)));
    SYM_READ_STELLA_TOKENIZER_STREAM_STATE = ((Symbol*)(internRigidSymbolWrtModule("TOKENIZER-STREAM-STATE", NULL, 0)));
    SYM_READ_STELLA_NULL = ((Symbol*)(internRigidSymbolWrtModule("NULL", NULL, 0)));
    SYM_READ_STELLA_TOK_BUFFER_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_BUFFER_", NULL, 0)));
    SYM_READ_STELLA_STRING_TO_TOKENIZER_BYTE_ARRAY = ((Symbol*)(internRigidSymbolWrtModule("STRING-TO-TOKENIZER-BYTE-ARRAY", NULL, 0)));
    SYM_READ_STELLA_TOK_STATE_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_STATE_", NULL, 0)));
    SYM_READ_STELLA_TOK_NEXTSTATE_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_NEXTSTATE_", NULL, 0)));
    SYM_READ_STELLA_TOK_CURSOR_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_CURSOR_", NULL, 0)));
    SYM_READ_STELLA_TOK_SIZE_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_SIZE_", NULL, 0)));
    SYM_READ_STELLA_LENGTH = ((Symbol*)(internRigidSymbolWrtModule("LENGTH", NULL, 0)));
    SYM_READ_STELLA_TOK_END_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_END_", NULL, 0)));
    SYM_READ_STELLA_TOK_INPUTSTREAM_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_INPUTSTREAM_", NULL, 0)));
    SYM_READ_STELLA_TOK_ECHOSTREAM_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_ECHOSTREAM_", NULL, 0)));
    SYM_READ_STELLA_ECHO_STREAM = ((Symbol*)(internRigidSymbolWrtModule("ECHO-STREAM", NULL, 0)));
    SYM_READ_STELLA_CHOOSE = ((Symbol*)(internRigidSymbolWrtModule("CHOOSE", NULL, 0)));
    SYM_READ_STELLA_NULLp = ((Symbol*)(internRigidSymbolWrtModule("NULL?", NULL, 0)));
    SYM_READ_STELLA_TOKENIZER_STATE = ((Symbol*)(internRigidSymbolWrtModule("TOKENIZER-STATE", NULL, 0)));
    SYM_READ_STELLA_SETF = ((Symbol*)(internRigidSymbolWrtModule("SETF", NULL, 0)));
    SYM_READ_STELLA_NEW = ((Symbol*)(internRigidSymbolWrtModule("NEW", NULL, 0)));
    SYM_READ_STELLA_BUFFER = ((Symbol*)(internRigidSymbolWrtModule("BUFFER", NULL, 0)));
    SYM_READ_STELLA_TOK_CHECKPOINT_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_CHECKPOINT_", NULL, 0)));
    SYM_READ_STELLA_le = ((Symbol*)(internRigidSymbolWrtModule("<=", NULL, 0)));
    SYM_READ_STELLA_END_OF_TOKENSp = ((Symbol*)(internRigidSymbolWrtModule("END-OF-TOKENS?", NULL, 0)));
  }
}

void helpStartupRead2() {
  {
    SYM_READ_STELLA_GET_TOKEN_TEXT = ((Symbol*)(internRigidSymbolWrtModule("GET-TOKEN-TEXT", NULL, 0)));
    SYM_READ_STELLA_GET_TOKEN_TEXT_INTERNAL = ((Symbol*)(internRigidSymbolWrtModule("GET-TOKEN-TEXT-INTERNAL", NULL, 0)));
    SYM_READ_STELLA_i = ((Symbol*)(internRigidSymbolWrtModule("+", NULL, 0)));
    SYM_READ_STELLA_l = ((Symbol*)(internRigidSymbolWrtModule("<", NULL, 0)));
    SYM_READ_STELLA_GET_TOKEN_TYPE = ((Symbol*)(internRigidSymbolWrtModule("GET-TOKEN-TYPE", NULL, 0)));
    SYM_READ_STELLA_NTH = ((Symbol*)(internRigidSymbolWrtModule("NTH", NULL, 0)));
    SYM_READ_STELLA_WHEN = ((Symbol*)(internRigidSymbolWrtModule("WHEN", NULL, 0)));
    SYM_READ_STELLA_DEFINEDp = ((Symbol*)(internRigidSymbolWrtModule("DEFINED?", NULL, 0)));
    SYM_READ_STELLA_GET_NEXT_TOKEN = ((Symbol*)(internRigidSymbolWrtModule("GET-NEXT-TOKEN", NULL, 0)));
    SYM_READ_STELLA_SAVE_TOKENIZER_STREAM_STATE = ((Symbol*)(internRigidSymbolWrtModule("SAVE-TOKENIZER-STREAM-STATE", NULL, 0)));
    SYM_READ_STELLA_TRUE = ((Symbol*)(internRigidSymbolWrtModule("TRUE", NULL, 0)));
    SYM_READ_STELLA_PROGN = ((Symbol*)(internRigidSymbolWrtModule("PROGN", NULL, 0)));
    SYM_READ_STELLA_SETQ = ((Symbol*)(internRigidSymbolWrtModule("SETQ", NULL, 0)));
    SYM_READ_STELLA_LOOP = ((Symbol*)(internRigidSymbolWrtModule("LOOP", NULL, 0)));
    SYM_READ_STELLA_CHARACTER_CODE = ((Symbol*)(internRigidSymbolWrtModule("CHARACTER-CODE", NULL, 0)));
    SYM_READ_STELLA_LOGOR = ((Symbol*)(internRigidSymbolWrtModule("LOGOR", NULL, 0)));
    SYM_READ_STELLA_SHIFT_LEFT = ((Symbol*)(internRigidSymbolWrtModule("SHIFT-LEFT", NULL, 0)));
    SYM_READ_STELLA_BYTE_ARRAY_NTH = ((Symbol*)(internRigidSymbolWrtModule("BYTE-ARRAY-NTH", NULL, 0)));
    SYM_READ_STELLA_COND = ((Symbol*)(internRigidSymbolWrtModule("COND", NULL, 0)));
    SYM_READ_STELLA_e = ((Symbol*)(internRigidSymbolWrtModule("=", NULL, 0)));
    SYM_READ_STELLA_LOGAND = ((Symbol*)(internRigidSymbolWrtModule("LOGAND", NULL, 0)));
    SYM_READ_STELLA_ii = ((Symbol*)(internRigidSymbolWrtModule("++", NULL, 0)));
    SYM_READ_STELLA_OTHERWISE = ((Symbol*)(internRigidSymbolWrtModule("OTHERWISE", NULL, 0)));
    SYM_READ_STELLA_BREAK = ((Symbol*)(internRigidSymbolWrtModule("BREAK", NULL, 0)));
    SYM_READ_STELLA_READ_INTO_TOKENIZER_BUFFER = ((Symbol*)(internRigidSymbolWrtModule("READ-INTO-TOKENIZER-BUFFER", NULL, 0)));
    SYM_READ_STELLA_MOD = ((Symbol*)(internRigidSymbolWrtModule("MOD", NULL, 0)));
    SYM_READ_STELLA_UNLESS = ((Symbol*)(internRigidSymbolWrtModule("UNLESS", NULL, 0)));
    SYM_READ_STELLA_IF = ((Symbol*)(internRigidSymbolWrtModule("IF", NULL, 0)));
    SYM_READ_STELLA_ge = ((Symbol*)(internRigidSymbolWrtModule(">=", NULL, 0)));
    SYM_READ_STELLA_PRINT_STREAM = ((Symbol*)(internRigidSymbolWrtModule("PRINT-STREAM", NULL, 0)));
    SYM_READ_STELLA_1_ = ((Symbol*)(internRigidSymbolWrtModule("1-", NULL, 0)));
    SGT_READ_STELLA_STREAM_TOKENIZER = ((Surrogate*)(internRigidSymbolWrtModule("STREAM-TOKENIZER", NULL, 1)));
    SYM_READ_STELLA_STREAM = ((Symbol*)(internRigidSymbolWrtModule("STREAM", NULL, 0)));
    SYM_READ_STELLA_TABLE = ((Symbol*)(internRigidSymbolWrtModule("TABLE", NULL, 0)));
    KWD_READ_INCLUDE = ((Keyword*)(internRigidSymbolWrtModule("INCLUDE", NULL, 2)));
    KWD_READ_DELIMITER = ((Keyword*)(internRigidSymbolWrtModule("DELIMITER", NULL, 2)));
    KWD_READ_ATOM = ((Keyword*)(internRigidSymbolWrtModule("ATOM", NULL, 2)));
    SYM_READ_STELLA_o = ((Symbol*)(internRigidSymbolWrtModule("*", NULL, 0)));
    KWD_READ_OPEN_PAREN = ((Keyword*)(internRigidSymbolWrtModule("OPEN-PAREN", NULL, 2)));
    KWD_READ_CLOSE_PAREN = ((Keyword*)(internRigidSymbolWrtModule("CLOSE-PAREN", NULL, 2)));
    KWD_READ_OPEN_STRING = ((Keyword*)(internRigidSymbolWrtModule("OPEN-STRING", NULL, 2)));
    KWD_READ_STRING = ((Keyword*)(internRigidSymbolWrtModule("STRING", NULL, 2)));
    KWD_READ_SINGLE_QUOTE = ((Keyword*)(internRigidSymbolWrtModule("SINGLE-QUOTE", NULL, 2)));
    KWD_READ_BACK_QUOTE = ((Keyword*)(internRigidSymbolWrtModule("BACK-QUOTE", NULL, 2)));
    KWD_READ_COMMA = ((Keyword*)(internRigidSymbolWrtModule("COMMA", NULL, 2)));
    SYM_READ_STELLA_x = ((Symbol*)(internRigidSymbolWrtModule("!", NULL, 0)));
    KWD_READ_COMMENT = ((Keyword*)(internRigidSymbolWrtModule("COMMENT", NULL, 2)));
    KWD_READ_HASH = ((Keyword*)(internRigidSymbolWrtModule("HASH", NULL, 2)));
    KWD_READ_WHITE_SPACE = ((Keyword*)(internRigidSymbolWrtModule("WHITE-SPACE", NULL, 2)));
    KWD_READ_OTHERWISE = ((Keyword*)(internRigidSymbolWrtModule("OTHERWISE", NULL, 2)));
    KWD_READ_PAREN_COMMENT = ((Keyword*)(internRigidSymbolWrtModule("PAREN-COMMENT", NULL, 2)));
    KWD_READ_PAREN_COMMENT_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("PAREN-COMMENT-ESCAPE", NULL, 2)));
    KWD_READ_PAREN_COMMENT_BAR = ((Keyword*)(internRigidSymbolWrtModule("PAREN-COMMENT-BAR", NULL, 2)));
    KWD_READ_ANY = ((Keyword*)(internRigidSymbolWrtModule("ANY", NULL, 2)));
    KWD_READ_COMMA_SPLICE = ((Keyword*)(internRigidSymbolWrtModule("COMMA-SPLICE", NULL, 2)));
    KWD_READ_SYMBOL_OR_SIGNED_NUMBER = ((Keyword*)(internRigidSymbolWrtModule("SYMBOL-OR-SIGNED-NUMBER", NULL, 2)));
    KWD_READ_SYMBOL = ((Keyword*)(internRigidSymbolWrtModule("SYMBOL", NULL, 2)));
    KWD_READ_SYMBOL_OR_NUMBER = ((Keyword*)(internRigidSymbolWrtModule("SYMBOL-OR-NUMBER", NULL, 2)));
    KWD_READ_INTEGER = ((Keyword*)(internRigidSymbolWrtModule("INTEGER", NULL, 2)));
    KWD_READ_SYMBOL_OR_CL_SYMBOL = ((Keyword*)(internRigidSymbolWrtModule("SYMBOL-OR-CL-SYMBOL", NULL, 2)));
  }
}

void helpStartupRead3() {
  {
    KWD_READ_OPEN_FULLY_ESCAPED_SYMBOL = ((Keyword*)(internRigidSymbolWrtModule("OPEN-FULLY-ESCAPED-SYMBOL", NULL, 2)));
    KWD_READ_FULLY_ESCAPED_SYMBOL = ((Keyword*)(internRigidSymbolWrtModule("FULLY-ESCAPED-SYMBOL", NULL, 2)));
    KWD_READ_ESCAPED_SYMBOL_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("ESCAPED-SYMBOL-ESCAPE", NULL, 2)));
    KWD_READ_QUALIFIED_NAME = ((Keyword*)(internRigidSymbolWrtModule("QUALIFIED-NAME", NULL, 2)));
    KWD_READ_OPEN_KEYWORD = ((Keyword*)(internRigidSymbolWrtModule("OPEN-KEYWORD", NULL, 2)));
    KWD_READ_KEYWORD = ((Keyword*)(internRigidSymbolWrtModule("KEYWORD", NULL, 2)));
    KWD_READ_OPEN_SURROGATE = ((Keyword*)(internRigidSymbolWrtModule("OPEN-SURROGATE", NULL, 2)));
    KWD_READ_SURROGATE = ((Keyword*)(internRigidSymbolWrtModule("SURROGATE", NULL, 2)));
    KWD_READ_CLOSE_STRING = ((Keyword*)(internRigidSymbolWrtModule("CLOSE-STRING", NULL, 2)));
    KWD_READ_STRING_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("STRING-ESCAPE", NULL, 2)));
    KWD_READ_ESCAPED_STRING = ((Keyword*)(internRigidSymbolWrtModule("ESCAPED-STRING", NULL, 2)));
    KWD_READ_CHARACTER_CONSTANT = ((Keyword*)(internRigidSymbolWrtModule("CHARACTER-CONSTANT", NULL, 2)));
    KWD_READ_SYMBOL_OR_MANTISSA = ((Keyword*)(internRigidSymbolWrtModule("SYMBOL-OR-MANTISSA", NULL, 2)));
    KWD_READ_SYMBOL_OR_MANTISSA2 = ((Keyword*)(internRigidSymbolWrtModule("SYMBOL-OR-MANTISSA2", NULL, 2)));
    KWD_READ_FLOAT = ((Keyword*)(internRigidSymbolWrtModule("FLOAT", NULL, 2)));
    KWD_READ_SYMBOL_OR_EXPONENT_DELIMITER = ((Keyword*)(internRigidSymbolWrtModule("SYMBOL-OR-EXPONENT-DELIMITER", NULL, 2)));
    KWD_READ_SYMBOL_OR_EXPONENT = ((Keyword*)(internRigidSymbolWrtModule("SYMBOL-OR-EXPONENT", NULL, 2)));
    KWD_READ_SYMBOL_OR_EXPONENT2 = ((Keyword*)(internRigidSymbolWrtModule("SYMBOL-OR-EXPONENT2", NULL, 2)));
    KWD_READ_SYMBOL_OR_CL_SYMBOL2 = ((Keyword*)(internRigidSymbolWrtModule("SYMBOL-OR-CL-SYMBOL2", NULL, 2)));
    KWD_READ_SYMBOL_OR_CL_SYMBOL3 = ((Keyword*)(internRigidSymbolWrtModule("SYMBOL-OR-CL-SYMBOL3", NULL, 2)));
    KWD_READ_CL_SYMBOL = ((Keyword*)(internRigidSymbolWrtModule("CL-SYMBOL", NULL, 2)));
    KWD_READ_ESCAPED_SYMBOL = ((Keyword*)(internRigidSymbolWrtModule("ESCAPED-SYMBOL", NULL, 2)));
    KWD_READ_CLOSE_FULLY_ESCAPED_NAME = ((Keyword*)(internRigidSymbolWrtModule("CLOSE-FULLY-ESCAPED-NAME", NULL, 2)));
    KWD_READ_FULLY_ESCAPED_SYMBOL_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("FULLY-ESCAPED-SYMBOL-ESCAPE", NULL, 2)));
    KWD_READ_FULLY_ESCAPED_KEYWORD = ((Keyword*)(internRigidSymbolWrtModule("FULLY-ESCAPED-KEYWORD", NULL, 2)));
    KWD_READ_ESCAPED_KEYWORD_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("ESCAPED-KEYWORD-ESCAPE", NULL, 2)));
    KWD_READ_ESCAPED_KEYWORD = ((Keyword*)(internRigidSymbolWrtModule("ESCAPED-KEYWORD", NULL, 2)));
    KWD_READ_FULLY_ESCAPED_KEYWORD_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("FULLY-ESCAPED-KEYWORD-ESCAPE", NULL, 2)));
    KWD_READ_FULLY_ESCAPED_SURROGATE = ((Keyword*)(internRigidSymbolWrtModule("FULLY-ESCAPED-SURROGATE", NULL, 2)));
    KWD_READ_ESCAPED_SURROGATE_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("ESCAPED-SURROGATE-ESCAPE", NULL, 2)));
    KWD_READ_ESCAPED_SURROGATE = ((Keyword*)(internRigidSymbolWrtModule("ESCAPED-SURROGATE", NULL, 2)));
    KWD_READ_FULLY_ESCAPED_SURROGATE_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("FULLY-ESCAPED-SURROGATE-ESCAPE", NULL, 2)));
    KWD_READ_QUALIFIED_SURROGATE = ((Keyword*)(internRigidSymbolWrtModule("QUALIFIED-SURROGATE", NULL, 2)));
    KWD_READ_QUALIFIED_ESCAPED_SYMBOL_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("QUALIFIED-ESCAPED-SYMBOL-ESCAPE", NULL, 2)));
    KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL = ((Keyword*)(internRigidSymbolWrtModule("QUALIFIED-FULLY-ESCAPED-SYMBOL", NULL, 2)));
    KWD_READ_QUALIFIED_SYMBOL = ((Keyword*)(internRigidSymbolWrtModule("QUALIFIED-SYMBOL", NULL, 2)));
    KWD_READ_QUALIFIED_ESCAPED_SURROGATE_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("QUALIFIED-ESCAPED-SURROGATE-ESCAPE", NULL, 2)));
    KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE = ((Keyword*)(internRigidSymbolWrtModule("QUALIFIED-FULLY-ESCAPED-SURROGATE", NULL, 2)));
    KWD_READ_QUALIFIED_ESCAPED_SYMBOL = ((Keyword*)(internRigidSymbolWrtModule("QUALIFIED-ESCAPED-SYMBOL", NULL, 2)));
    KWD_READ_QUALIFIED_ESCAPED_SURROGATE = ((Keyword*)(internRigidSymbolWrtModule("QUALIFIED-ESCAPED-SURROGATE", NULL, 2)));
    KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("QUALIFIED-FULLY-ESCAPED-SYMBOL-ESCAPE", NULL, 2)));
    KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE_ESCAPE = ((Keyword*)(internRigidSymbolWrtModule("QUALIFIED-FULLY-ESCAPED-SURROGATE-ESCAPE", NULL, 2)));
    KWD_READ_CLOSE_BALANCED_QUOTE = ((Keyword*)(internRigidSymbolWrtModule("CLOSE-BALANCED-QUOTE", NULL, 2)));
    SYM_READ_STELLA_WITH_TOKENIZER = ((Symbol*)(internRigidSymbolWrtModule("WITH-TOKENIZER", NULL, 0)));
    SYM_READ_STELLA_oSTELLA_TOKENIZER_TABLEo = ((Symbol*)(internRigidSymbolWrtModule("*STELLA-TOKENIZER-TABLE*", NULL, 0)));
    SYM_READ_STELLA_TOK_STELLALOGICALSTATENAMES_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_STELLALOGICALSTATENAMES_", NULL, 0)));
    SYM_READ_STELLA_oSTELLA_LOGICAL_STATE_NAMESo = ((Symbol*)(internRigidSymbolWrtModule("*STELLA-LOGICAL-STATE-NAMES*", NULL, 0)));
    SYM_READ_STELLA_TOK_STELLALOGICALSTATENAME_ = ((Symbol*)(internRigidSymbolWrtModule("TOK_STELLALOGICALSTATENAME_", NULL, 0)));
    SYM_READ_STELLA_KEYWORD = ((Symbol*)(internRigidSymbolWrtModule("KEYWORD", NULL, 0)));
    KWD_READ_NONE = ((Keyword*)(internRigidSymbolWrtModule("NONE", NULL, 2)));
    SYM_READ_STELLA_GET_QUALIFIED_SYMBOL_SEPARATOR_POSITION_INTERNAL = ((Symbol*)(internRigidSymbolWrtModule("GET-QUALIFIED-SYMBOL-SEPARATOR-POSITION-INTERNAL", NULL, 0)));
    KWD_READ_FULLY_ESCAPED = ((Keyword*)(internRigidSymbolWrtModule("FULLY-ESCAPED", NULL, 2)));
    SGT_READ_STELLA_STELLA_TOKEN = ((Surrogate*)(internRigidSymbolWrtModule("STELLA-TOKEN", NULL, 1)));
    SYM_READ_STELLA_LOGICAL_TOKEN_TYPE = ((Symbol*)(internRigidSymbolWrtModule("LOGICAL-TOKEN-TYPE", NULL, 0)));
    SYM_READ_STELLA_MODULE = ((Symbol*)(internRigidSymbolWrtModule("MODULE", NULL, 0)));
    SYM_READ_STELLA_ESCAPE_MODE = ((Symbol*)(internRigidSymbolWrtModule("ESCAPE-MODE", NULL, 0)));
    KWD_READ_FULL = ((Keyword*)(internRigidSymbolWrtModule("FULL", NULL, 2)));
    KWD_READ_PARTIAL = ((Keyword*)(internRigidSymbolWrtModule("PARTIAL", NULL, 2)));
    KWD_READ_ESCAPED = ((Keyword*)(internRigidSymbolWrtModule("ESCAPED", NULL, 2)));
    SYM_READ_STELLA_a = ((Symbol*)(internRigidSymbolWrtModule("&", NULL, 0)));
  }
}

void helpStartupRead4() {
  {
    SYM_READ_STELLA_aa = ((Symbol*)(internRigidSymbolWrtModule("&&", NULL, 0)));
    KWD_READ_ASK = ((Keyword*)(internRigidSymbolWrtModule("ASK", NULL, 2)));
    KWD_READ_YES = ((Keyword*)(internRigidSymbolWrtModule("YES", NULL, 2)));
    KWD_READ_NO = ((Keyword*)(internRigidSymbolWrtModule("NO", NULL, 2)));
    KWD_READ_YES_VERBOSE = ((Keyword*)(internRigidSymbolWrtModule("YES-VERBOSE", NULL, 2)));
    KWD_READ_NO_VERBOSE = ((Keyword*)(internRigidSymbolWrtModule("NO-VERBOSE", NULL, 2)));
    SYM_READ_STELLA_STARTUP_READ = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-READ", NULL, 0)));
    SYM_READ_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", NULL, 0)));
  }
}

void helpStartupRead5() {
  {
    { Class* clasS = defineClassFromStringifiedSource("TOKENIZER-TABLE", "(DEFCLASS TOKENIZER-TABLE (STANDARD-OBJECT) :SLOTS ((TRANSITIONS :TYPE STRING) (UNIQUE-STATE-NAMES :TYPE (VECTOR OF GENERALIZED-SYMBOL)) (STATE-NAMES :TYPE (VECTOR OF GENERALIZED-SYMBOL)) (LEGAL-EOF-STATES :TYPE (VECTOR OF BOOLEAN-WRAPPER))))");

      clasS->classConstructorCode = ((cpp_function_code)(&newTokenizerTable));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessTokenizerTableSlotValue));
    }
    defineStellaTypeFromStringifiedSource("(DEFTYPE CHARACTER-SET (CONS OF CHARACTER-WRAPPER))");
    defineClassFromStringifiedSource("TOKENIZER-BYTE", "(DEFCLASS TOKENIZER-BYTE () :CL-NATIVE-TYPE \"CHARACTER\" :CPP-NATIVE-TYPE \"char\" :JAVA-NATIVE-TYPE \"byte\")");
    defineClassFromStringifiedSource("TOKENIZER-BYTE-ARRAY", "(DEFCLASS TOKENIZER-BYTE-ARRAY () :CL-NATIVE-TYPE \"STRING\" :CPP-NATIVE-TYPE \"char*\" :JAVA-NATIVE-TYPE \"byte[]\")");
    { Class* clasS = defineClassFromStringifiedSource("TOKENIZER-TOKEN", "(DEFCLASS TOKENIZER-TOKEN (STANDARD-OBJECT) :SLOTS ((TYPE :TYPE KEYWORD) (CONTENT :TYPE STRING) (NEXT :TYPE TOKENIZER-TOKEN)))");

      clasS->classConstructorCode = ((cpp_function_code)(&newTokenizerToken));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessTokenizerTokenSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("TOKENIZER-STREAM-STATE", "(DEFCLASS TOKENIZER-STREAM-STATE (STANDARD-OBJECT) :SLOTS ((BUFFER :TYPE TOKENIZER-BYTE-ARRAY :INITIALLY (MAKE-TOKENIZER-BYTE-ARRAY *TOKENIZER-INITIAL-BUFFER-SIZE*)) (BUFFER-SIZE :TYPE INTEGER :INITIALLY *TOKENIZER-INITIAL-BUFFER-SIZE*) (CURSOR :TYPE INTEGER :INITIALLY *TOKENIZER-INITIAL-BUFFER-SIZE*) (END :TYPE INTEGER :INITIALLY *TOKENIZER-INITIAL-BUFFER-SIZE*) (STATE :TYPE INTEGER :INITIALLY 1) (TOKEN-LIST :TYPE TOKENIZER-TOKEN)))");

      clasS->classConstructorCode = ((cpp_function_code)(&newTokenizerStreamState));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessTokenizerStreamStateSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("STREAM-TOKENIZER", "(DEFCLASS STREAM-TOKENIZER (ITERATOR) :DOCUMENTATION \"Iterator that generates tokens by tokenizing a `stream'\naccording to a particular tokenization `table'.\" :PUBLIC? TRUE :PARAMETERS ((ANY-VALUE :TYPE TOKENIZER-TOKEN)) :SLOTS ((STREAM :TYPE INPUT-STREAM :REQUIRED? TRUE) (TABLE :TYPE TOKENIZER-TABLE :REQUIRED? TRUE) (TOKEN :RENAMES VALUE)))");

      clasS->classConstructorCode = ((cpp_function_code)(&newStreamTokenizer));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessStreamTokenizerSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("STELLA-TOKEN", "(DEFCLASS STELLA-TOKEN (TOKENIZER-TOKEN) :SLOTS ((LOGICAL-TOKEN-TYPE :TYPE KEYWORD) (MODULE :TYPE STRING) (ESCAPE-MODE :TYPE KEYWORD) (NEXT :TYPE STELLA-TOKEN)))");

      clasS->classConstructorCode = ((cpp_function_code)(&newStellaToken));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessStellaTokenSlotValue));
    }
  }
}

void helpStartupRead6() {
  {
    defineFunctionObject("PARSE-TOKENIZER-DEFINITION", "(DEFUN (PARSE-TOKENIZER-DEFINITION TOKENIZER-TABLE) ((DEFINITION (CONS OF CONS))))", ((cpp_function_code)(&parseTokenizerDefinition)), NULL);
    defineFunctionObject("LEGAL-TOKENIZER-STATE?", "(DEFUN (LEGAL-TOKENIZER-STATE? BOOLEAN) ((X OBJECT)))", ((cpp_function_code)(&legalTokenizerStateP)), NULL);
    defineFunctionObject("LEGAL-TOKENIZER-FROM-STATE?", "(DEFUN (LEGAL-TOKENIZER-FROM-STATE? BOOLEAN) ((X OBJECT)))", ((cpp_function_code)(&legalTokenizerFromStateP)), NULL);
    defineFunctionObject("LEGAL-TOKENIZER-TO-STATE?", "(DEFUN (LEGAL-TOKENIZER-TO-STATE? BOOLEAN) ((X OBJECT)))", ((cpp_function_code)(&legalTokenizerToStateP)), NULL);
    defineFunctionObject("TOKENIZER-TO-STATE-NAME", "(DEFUN (TOKENIZER-TO-STATE-NAME GENERALIZED-SYMBOL) ((STATE OBJECT)))", ((cpp_function_code)(&tokenizerToStateName)), NULL);
    defineFunctionObject("TOKENIZER-TO-STATE-ALIAS", "(DEFUN (TOKENIZER-TO-STATE-ALIAS GENERALIZED-SYMBOL) ((STATE OBJECT)))", ((cpp_function_code)(&tokenizerToStateAlias)), NULL);
    defineFunctionObject("PARSE-TOKENIZER-STATE-MODIFIERS", "(DEFUN (PARSE-TOKENIZER-STATE-MODIFIERS INTEGER) ((MODIFIER OBJECT)))", ((cpp_function_code)(&parseTokenizerStateModifiers)), NULL);
    defineFunctionObject("TOKENIZER-INCLUDE-SPEC?", "(DEFUN (TOKENIZER-INCLUDE-SPEC? BOOLEAN) ((X OBJECT)))", ((cpp_function_code)(&tokenizerIncludeSpecP)), NULL);
    defineFunctionObject("PARSE-TOKENIZER-CHARACTER-SPEC", "(DEFUN (PARSE-TOKENIZER-CHARACTER-SPEC CHARACTER-SET) ((CHARACTERSPEC OBJECT) (ALLCHARACTERSETS (LIST OF CHARACTER-SET))))", ((cpp_function_code)(&parseTokenizerCharacterSpec)), NULL);
    defineFunctionObject("STRINGIFY-TOKENIZER-TABLE", "(DEFUN (STRINGIFY-TOKENIZER-TABLE STRING) ((TABLE TOKENIZER-TABLE)))", ((cpp_function_code)(&stringifyTokenizerTable)), NULL);
    defineFunctionObject("UNSTRINGIFY-TOKENIZER-TABLE", "(DEFUN (UNSTRINGIFY-TOKENIZER-TABLE TOKENIZER-TABLE) ((TABLE STRING)))", ((cpp_function_code)(&unstringifyTokenizerTable)), NULL);
    defineFunctionObject("MAKE-TOKENIZER-BYTE-ARRAY", "(DEFUN (MAKE-TOKENIZER-BYTE-ARRAY TOKENIZER-BYTE-ARRAY) ((SIZE INTEGER)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:MAKE-STRING SIZE) :CPP \"new (GC) char[size]\" :JAVA \"new byte[size]\")))", ((cpp_function_code)(&makeTokenizerByteArray)), NULL);
    defineFunctionObject("STRING-TO-TOKENIZER-BYTE-ARRAY", "(DEFUN (STRING-TO-TOKENIZER-BYTE-ARRAY TOKENIZER-BYTE-ARRAY) ((STRING STRING)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP STRING :CPP \"string\" :JAVA \"string.getBytes()\")))", ((cpp_function_code)(&stringToTokenizerByteArray)), NULL);
    defineFunctionObject("TOKENIZER-BYTE-ARRAY-TO-STRING", "(DEFUN (TOKENIZER-BYTE-ARRAY-TO-STRING STRING) ((BYTES TOKENIZER-BYTE-ARRAY)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP BYTES :CPP \"bytes\" :JAVA \"new String(bytes)\")))", ((cpp_function_code)(&tokenizerByteArrayToString)), NULL);
    defineMethodObject("(DEFMETHOD (BYTE-ARRAY-NTH CHARACTER) ((BUFFER TOKENIZER-BYTE-ARRAY) (POSITION INTEGER)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:SCHAR (CL:THE CL:SIMPLE-STRING BUFFER) (CL:THE CL:FIXNUM POSITION)) :CPP \"buffer[position]\" :JAVA \"((char) (0x00ff & buffer[position]))\")))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (BYTE-ARRAY-NTH-SETTER TOKENIZER-BYTE) ((BUFFER TOKENIZER-BYTE-ARRAY) (CH CHARACTER) (POSITION INTEGER)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:SETF (CL:SCHAR (CL:THE CL:SIMPLE-STRING BUFFER) (CL:THE CL:FIXNUM POSITION)) (CL:THE CL:CHARACTER CH)) :CPP \"buffer[position] = ch\" :JAVA \"buffer[position] = (byte)ch\")))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineFunctionObject("BYTE-ARRAY-READ-SEQUENCE", "(DEFUN (BYTE-ARRAY-READ-SEQUENCE INTEGER) ((BUFFER TOKENIZER-BYTE-ARRAY) (STREAM NATIVE-INPUT-STREAM) (START INTEGER) (END INTEGER)))", ((cpp_function_code)(&byteArrayReadSequence)), NULL);
    defineFunctionObject("BYTE-ARRAY-WRITE-SEQUENCE", "(DEFUN BYTE-ARRAY-WRITE-SEQUENCE ((BUFFER TOKENIZER-BYTE-ARRAY) (STREAM NATIVE-OUTPUT-STREAM) (START INTEGER) (END INTEGER)))", ((cpp_function_code)(&byteArrayWriteSequence)), NULL);
    defineFunctionObject("ENSURE-TOKENIZER-BUFFER-SIZE", "(DEFUN ENSURE-TOKENIZER-BUFFER-SIZE ((STATE TOKENIZER-STREAM-STATE) (CURRENTTOKENSTART INTEGER) (REQUIREDSPACE INTEGER)))", ((cpp_function_code)(&ensureTokenizerBufferSize)), NULL);
    defineFunctionObject("READ-INTO-TOKENIZER-BUFFER", "(DEFUN (READ-INTO-TOKENIZER-BUFFER BOOLEAN) ((STREAM INPUT-STREAM) (STATE TOKENIZER-STREAM-STATE) (CURRENTTOKENSTART INTEGER)))", ((cpp_function_code)(&readIntoTokenizerBuffer)), NULL);
    defineFunctionObject("READ-CHARACTER-FROM-TOKENIZER-BUFFER", "(DEFUN (READ-CHARACTER-FROM-TOKENIZER-BUFFER CHARACTER BOOLEAN) ((STREAM INPUT-STREAM)))", ((cpp_function_code)(&readCharacterFromTokenizerBuffer)), NULL);
    defineFunctionObject("UNREAD-CHARACTER-FROM-TOKENIZER-BUFFER", "(DEFUN UNREAD-CHARACTER-FROM-TOKENIZER-BUFFER ((CHAR CHARACTER) (STREAM INPUT-STREAM)))", ((cpp_function_code)(&unreadCharacterFromTokenizerBuffer)), NULL);
    defineFunctionObject("READ-LINE-FROM-TOKENIZER-BUFFER", "(DEFUN (READ-LINE-FROM-TOKENIZER-BUFFER STRING BOOLEAN) ((STREAM INPUT-STREAM)))", ((cpp_function_code)(&readLineFromTokenizerBuffer)), NULL);
    defineFunctionObject("WITH-TOKENIZER", "(DEFUN WITH-TOKENIZER ((TABLE OBJECT) (INPUT OBJECT) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE)", ((cpp_function_code)(&withTokenizer)), NULL);
    defineFunctionObject("WITH-TOKENIZER-STRING-INPUT?", "(DEFUN (WITH-TOKENIZER-STRING-INPUT? BOOLEAN) ())", ((cpp_function_code)(&withTokenizerStringInputP)), NULL);
    defineFunctionObject("INSIDE-WITH-TOKENIZER?", "(DEFUN (INSIDE-WITH-TOKENIZER? BOOLEAN) ())", ((cpp_function_code)(&insideWithTokenizerP)), NULL);
    defineFunctionObject("END-OF-TOKENS?", "(DEFUN END-OF-TOKENS? () :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE)", ((cpp_function_code)(&endOfTokensP)), NULL);
    defineFunctionObject("GET-TOKEN-TEXT", "(DEFUN GET-TOKEN-TEXT (|&BODY| (OPTIONS CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE)", ((cpp_function_code)(&getTokenText)), NULL);
    defineFunctionObject("GET-TOKEN-TEXT-INTERNAL", "(DEFUN (GET-TOKEN-TEXT-INTERNAL STRING) ((BUFFER TOKENIZER-BYTE-ARRAY) (START INTEGER) (END INTEGER) (SIZE INTEGER) (UPCASE? BOOLEAN)))", ((cpp_function_code)(&getTokenTextInternal)), NULL);
    defineFunctionObject("GET-TOKEN-TYPE", "(DEFUN GET-TOKEN-TYPE () :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&getTokenType)), NULL);
    defineFunctionObject("SAVE-TOKENIZER-STREAM-STATE", "(DEFUN SAVE-TOKENIZER-STREAM-STATE () :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&saveTokenizerStreamState)), NULL);
    defineFunctionObject("GET-NEXT-TOKEN", "(DEFUN GET-NEXT-TOKEN (|&BODY| (OPTIONS CONS)) :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&getNextToken)), NULL);
    defineFunctionObject("UNESCAPE-TOKEN-STRING", "(DEFUN (UNESCAPE-TOKEN-STRING STRING) ((TOKEN STRING) (ESCAPECHAR CHARACTER) (UPCASE? BOOLEAN)))", ((cpp_function_code)(&unescapeTokenString)), NULL);
    defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF STREAM-TOKENIZER)))", ((cpp_method_code)(&StreamTokenizer::nextP)), ((cpp_method_code)(NULL)));
    defineFunctionObject("WITH-STELLA-TOKENIZER", "(DEFUN WITH-STELLA-TOKENIZER ((INPUT OBJECT) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&withStellaTokenizer)), NULL);
    defineFunctionObject("GET-NEXT-STELLA-TOKEN", "(DEFUN GET-NEXT-STELLA-TOKEN (|&BODY| (OPTIONS CONS)) :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&getNextStellaToken)), NULL);
    defineFunctionObject("GET-STELLA-TOKEN-TYPE", "(DEFUN GET-STELLA-TOKEN-TYPE () :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&getStellaTokenType)), NULL);
    defineFunctionObject("GET-QUALIFIED-SYMBOL-SEPARATOR-POSITION", "(DEFUN GET-QUALIFIED-SYMBOL-SEPARATOR-POSITION (|&BODY| (ESCAPEMODE CONS)) :TYPE OBJECT :MACRO? TRUE)", ((cpp_function_code)(&getQualifiedSymbolSeparatorPosition)), NULL);
    defineFunctionObject("GET-QUALIFIED-SYMBOL-SEPARATOR-POSITION-INTERNAL", "(DEFUN (GET-QUALIFIED-SYMBOL-SEPARATOR-POSITION-INTERNAL INTEGER) ((BUFFER TOKENIZER-BYTE-ARRAY) (TOKENSTART INTEGER) (TOKENEND INTEGER) (SIZE INTEGER) (ESCAPEMODE KEYWORD)))", ((cpp_function_code)(&getQualifiedSymbolSeparatorPositionInternal)), NULL);
    defineFunctionObject("TOKENIZE-S-EXPRESSION", "(DEFUN (TOKENIZE-S-EXPRESSION STELLA-TOKEN) ((STREAM INPUT-STREAM) (TOKENLIST STELLA-TOKEN)))", ((cpp_function_code)(&tokenizeSExpression)), NULL);
    defineFunctionObject("STELLA-TOKEN-LIST-TO-S-EXPRESSION", "(DEFUN (STELLA-TOKEN-LIST-TO-S-EXPRESSION OBJECT) ((TOKENLIST STELLA-TOKEN)))", ((cpp_function_code)(&stellaTokenListToSExpression)), NULL);
    defineFunctionObject("EXPAND-QUOTE-MACRO-TOKEN", "(DEFUN EXPAND-QUOTE-MACRO-TOKEN ((QUOTEDLIST STELLA-TOKEN)))", ((cpp_function_code)(&expandQuoteMacroToken)), NULL);
    defineFunctionObject("STRING-TO-CHARACTER", "(DEFUN (STRING-TO-CHARACTER CHARACTER) ((NAME STRING)))", ((cpp_function_code)(&stringToCharacter)), NULL);
    defineFunctionObject("READ-S-EXPRESSION", "(DEFUN (READ-S-EXPRESSION OBJECT BOOLEAN) ((STREAM INPUT-STREAM)) :DOCUMENTATION \"Read one STELLA s-expression from `stream' and return\nthe result.  Return `true' as the second value on EOF.\" :PUBLIC? TRUE)", ((cpp_function_code)(&readSExpression)), NULL);
    defineFunctionObject("EAT-NEXT-CHARACTER-IF-WHITESPACE", "(DEFUN (EAT-NEXT-CHARACTER-IF-WHITESPACE BOOLEAN) ((STREAM INPUT-STREAM)))", ((cpp_function_code)(&eatNextCharacterIfWhitespace)), NULL);
    defineFunctionObject("CONSUME-WHITESPACE", "(DEFUN (CONSUME-WHITESPACE BOOLEAN) ((STREAM INPUT-STREAM)))", ((cpp_function_code)(&consumeWhitespace)), NULL);
    defineFunctionObject("READ-S-EXPRESSION-FROM-STRING", "(DEFUN (READ-S-EXPRESSION-FROM-STRING OBJECT) ((STRING STRING)) :DOCUMENTATION \"Read one STELLA s-expression from `string' and\nreturn the result.\" :PUBLIC? TRUE)", ((cpp_function_code)(&readSExpressionFromString)), NULL);
    defineFunctionObject("MAKE-TOKENIZER-STRING-STREAM", "(DEFUN (MAKE-TOKENIZER-STRING-STREAM STRING-INPUT-STREAM) ((STRING STRING)))", ((cpp_function_code)(&makeTokenizerStringStream)), NULL);
    defineFunctionObject("READ-LINE", "(DEFUN (READ-LINE STRING BOOLEAN) ((INPUTSTREAM INPUT-STREAM)) :DOCUMENTATION \"Read one line from `inputStream' and return the result.\nReturn `true' as the second value on EOF.\" :PUBLIC? TRUE)", ((cpp_function_code)(&readLine)), NULL);
    defineFunctionObject("READ-CHARACTER", "(DEFUN (READ-CHARACTER CHARACTER BOOLEAN) ((INPUTSTREAM INPUT-STREAM)) :DOCUMENTATION \"Read one character from `inputStream' and return the result.\nReturn `true' as the second value on EOF.\" :PUBLIC? TRUE)", ((cpp_function_code)(&readCharacter)), NULL);
    defineFunctionObject("UNREAD-CHARACTER", "(DEFUN UNREAD-CHARACTER ((CH CHARACTER) (INPUTSTREAM INPUT-STREAM)) :DOCUMENTATION \"Unread `ch' from `inputStream'.  Signal an error if `ch'\nwas not the last character read.\" :PUBLIC? TRUE)", ((cpp_function_code)(&unreadCharacter)), NULL);
    defineFunctionObject("YES-OR-NO?", "(DEFUN (YES-OR-NO? BOOLEAN) ((MESSAGE STRING)) :DOCUMENTATION \"Read a line of input from STANDARD-INPUT and return `true'\nif the input was `yes' or `false' if the input was `no'.  Loop until either\n`yes' or `no' was entered.  If 'message' is non-`null' prompt with it before\nthe input is read.  See also special variable `*USER-QUERY-ACTION*'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&yesOrNoP)), NULL);
    defineFunctionObject("Y-OR-N?", "(DEFUN (Y-OR-N? BOOLEAN) ((MESSAGE STRING)) :DOCUMENTATION \"Read a line of input from STANDARD-INPUT and return `true'\nif the input was `y' or `false' if the input was `n'.  Loop until either\n`y' or `n' was entered.  If 'message' is non-`null' prompt with it before\nthe input is read.  See also special variable `*USER-QUERY-ACTION*'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&yOrNP)), NULL);
    defineFunctionObject("STARTUP-READ", "(DEFUN STARTUP-READ () :PUBLIC? TRUE)", ((cpp_function_code)(&startupRead)), NULL);
    { MethodSlot* function = lookupFunction(SYM_READ_STELLA_STARTUP_READ);

      setDynamicSlotValue(function->dynamicSlots, SYM_READ_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Read"), NULL_STRING_WRAPPER);
    }
  }
}

void startupRead() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oSTELLA_MODULEo);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupRead1();
      helpStartupRead2();
      helpStartupRead3();
      helpStartupRead4();
    }
    if (currentStartupTimePhaseP(4)) {
      oSTELLA_TOKENIZER_TABLE_DEFINITIONo = listO(65, listO(6, KWD_READ_START, KWD_READ_INCLUDE, KWD_READ_DELIMITER, KWD_READ_INCLUDE, KWD_READ_ATOM, NIL), listO(31, KWD_READ_DELIMITER, SYM_READ_STELLA_o, wrapString("("), KWD_READ_OPEN_PAREN, SYM_READ_STELLA_o, wrapString(")"), KWD_READ_CLOSE_PAREN, SYM_READ_STELLA_o, wrapString("\""), listO(3, KWD_READ_OPEN_STRING, KWD_READ_STRING, NIL), SYM_READ_STELLA_o, wrapString("'"), KWD_READ_SINGLE_QUOTE, SYM_READ_STELLA_o, wrapString("`"), KWD_READ_BACK_QUOTE, SYM_READ_STELLA_o, wrapString(","), KWD_READ_COMMA, SYM_READ_STELLA_x, wrapString(";"), KWD_READ_COMMENT, SYM_READ_STELLA_x, wrapString("#"), KWD_READ_HASH, SYM_READ_STELLA_x, listO(5, wrapCharacter(' '), wrapCharacter('\t'), wrapCharacter('\n'), wrapCharacter('\r'), NIL), KWD_READ_WHITE_SPACE, KWD_READ_EOF, KWD_READ_EOF, NIL), listO(4, KWD_READ_WHITE_SPACE, KWD_READ_INCLUDE, KWD_READ_START, NIL), listO(8, KWD_READ_COMMENT, listO(3, wrapCharacter('\n'), wrapCharacter('\r'), NIL), KWD_READ_START, KWD_READ_EOF, KWD_READ_EOF, KWD_READ_OTHERWISE, KWD_READ_COMMENT, NIL), listO(8, KWD_READ_PAREN_COMMENT, wrapString("\\"), KWD_READ_PAREN_COMMENT_ESCAPE, wrapString("|"), KWD_READ_PAREN_COMMENT_BAR, KWD_READ_OTHERWISE, KWD_READ_PAREN_COMMENT, NIL), listO(4, KWD_READ_PAREN_COMMENT_ESCAPE, KWD_READ_ANY, KWD_READ_PAREN_COMMENT, NIL), listO(10, KWD_READ_PAREN_COMMENT_BAR, wrapString("#"), KWD_READ_START, wrapString("\\"), KWD_READ_PAREN_COMMENT_ESCAPE, wrapString("|"), KWD_READ_PAREN_COMMENT_BAR, KWD_READ_OTHERWISE, KWD_READ_PAREN_COMMENT, NIL), listO(4, KWD_READ_OPEN_PAREN, KWD_READ_INCLUDE, KWD_READ_START, NIL), listO(4, KWD_READ_CLOSE_PAREN, KWD_READ_INCLUDE, KWD_READ_START, NIL), listO(4, KWD_READ_SINGLE_QUOTE, KWD_READ_INCLUDE, KWD_READ_START, NIL), listO(4, KWD_READ_BACK_QUOTE, KWD_READ_INCLUDE, KWD_READ_START, NIL), listO(33, KWD_READ_COMMA, wrapString("."), KWD_READ_COMMA_SPLICE, KWD_READ_INCLUDE, KWD_READ_DELIMITER, SYM_READ_STELLA_o, wrapString("-+"), listO(3, KWD_READ_SYMBOL_OR_SIGNED_NUMBER, KWD_READ_SYMBOL, NIL), SYM_READ_STELLA_o, wrapString("0123456789"), listO(3, KWD_READ_SYMBOL_OR_NUMBER, KWD_READ_INTEGER, NIL), SYM_READ_STELLA_o, wrapString("cC"), listO(3, KWD_READ_SYMBOL_OR_CL_SYMBOL, KWD_READ_SYMBOL, NIL), SYM_READ_STELLA_o, wrapString("|"), listO(3, KWD_READ_OPEN_FULLY_ESCAPED_SYMBOL, KWD_READ_FULLY_ESCAPED_SYMBOL, NIL), SYM_READ_STELLA_o, wrapString("\\"), KWD_READ_ESCAPED_SYMBOL_ESCAPE, SYM_READ_STELLA_o, wrapString("/"), KWD_READ_QUALIFIED_NAME, SYM_READ_STELLA_o, wrapString(":"), listO(3, KWD_READ_OPEN_KEYWORD, KWD_READ_KEYWORD, NIL), SYM_READ_STELLA_o, wrapString("@"), listO(3, KWD_READ_OPEN_SURROGATE, KWD_READ_SURROGATE, NIL), SYM_READ_STELLA_o, KWD_READ_OTHERWISE, KWD_READ_SYMBOL, NIL), listO(4, KWD_READ_COMMA_SPLICE, KWD_READ_INCLUDE, KWD_READ_START, NIL), listO(9, KWD_READ_OPEN_STRING, SYM_READ_STELLA_o, wrapString("\""), KWD_READ_CLOSE_STRING, wrapString("\\"), KWD_READ_STRING_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_STRING, NIL), listO(9, KWD_READ_STRING, SYM_READ_STELLA_o, wrapString("\""), KWD_READ_CLOSE_STRING, wrapString("\\"), KWD_READ_STRING_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_STRING, NIL), listO(4, KWD_READ_CLOSE_STRING, KWD_READ_INCLUDE, KWD_READ_START, NIL), listO(4, KWD_READ_STRING_ESCAPE, KWD_READ_ANY, KWD_READ_ESCAPED_STRING, NIL), listO(9, KWD_READ_ESCAPED_STRING, SYM_READ_STELLA_o, wrapString("\""), KWD_READ_CLOSE_STRING, wrapString("\\"), KWD_READ_STRING_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_ESCAPED_STRING, NIL), listO(6, KWD_READ_HASH, wrapString("\\"), KWD_READ_CHARACTER_CONSTANT, wrapString("|"), KWD_READ_PAREN_COMMENT, NIL), listO(5, KWD_READ_CHARACTER_CONSTANT, SYM_READ_STELLA_o, KWD_READ_ANY, KWD_READ_CHARACTER, NIL), listO(6, KWD_READ_CHARACTER, KWD_READ_INCLUDE, KWD_READ_DELIMITER, KWD_READ_OTHERWISE, KWD_READ_CHARACTER, NIL), listO(32, KWD_READ_ATOM, SYM_READ_STELLA_o, wrapString("-+"), listO(3, KWD_READ_SYMBOL_OR_SIGNED_NUMBER, KWD_READ_SYMBOL, NIL), SYM_READ_STELLA_o, wrapString("0123456789"), listO(3, KWD_READ_SYMBOL_OR_NUMBER, KWD_READ_INTEGER, NIL), SYM_READ_STELLA_o, wrapString("."), listO(3, KWD_READ_SYMBOL_OR_MANTISSA, KWD_READ_SYMBOL, NIL), SYM_READ_STELLA_o, wrapString("cC"), listO(3, KWD_READ_SYMBOL_OR_CL_SYMBOL, KWD_READ_SYMBOL, NIL), SYM_READ_STELLA_o, wrapString("|"), listO(3, KWD_READ_OPEN_FULLY_ESCAPED_SYMBOL, KWD_READ_FULLY_ESCAPED_SYMBOL, NIL), SYM_READ_STELLA_o, wrapString("\\"), KWD_READ_ESCAPED_SYMBOL_ESCAPE, SYM_READ_STELLA_o, wrapString("/"), KWD_READ_QUALIFIED_NAME, SYM_READ_STELLA_o, wrapString(":"), listO(3, KWD_READ_OPEN_KEYWORD, KWD_READ_KEYWORD, NIL), SYM_READ_STELLA_o, wrapString("@"), listO(3, KWD_READ_OPEN_SURROGATE, KWD_READ_SURROGATE, NIL), SYM_READ_STELLA_o, KWD_READ_OTHERWISE, KWD_READ_SYMBOL, NIL), listO(16, KWD_READ_SYMBOL_OR_SIGNED_NUMBER, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/"), KWD_READ_QUALIFIED_NAME, wrapString("\\"), KWD_READ_ESCAPED_SYMBOL_ESCAPE, wrapString("0123456789"), listO(3, KWD_READ_SYMBOL_OR_NUMBER, KWD_READ_INTEGER, NIL), wrapString("."), listO(3, KWD_READ_SYMBOL_OR_MANTISSA, KWD_READ_SYMBOL, NIL), wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_SYMBOL, NIL), listO(18, KWD_READ_SYMBOL_OR_NUMBER, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/"), KWD_READ_QUALIFIED_NAME, wrapString("\\"), KWD_READ_ESCAPED_SYMBOL_ESCAPE, wrapString("0123456789"), listO(3, KWD_READ_SYMBOL_OR_NUMBER, KWD_READ_INTEGER, NIL), wrapString("."), listO(3, KWD_READ_SYMBOL_OR_MANTISSA2, KWD_READ_FLOAT, NIL), wrapString("eE"), listO(3, KWD_READ_SYMBOL_OR_EXPONENT_DELIMITER, KWD_READ_SYMBOL, NIL), wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_SYMBOL, NIL), listO(16, KWD_READ_SYMBOL_OR_MANTISSA, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/"), KWD_READ_QUALIFIED_NAME, wrapString("\\"), KWD_READ_ESCAPED_SYMBOL_ESCAPE, wrapString("0123456789"), listO(3, KWD_READ_SYMBOL_OR_MANTISSA2, KWD_READ_FLOAT, NIL), wrapString("eE"), listO(3, KWD_READ_SYMBOL_OR_EXPONENT_DELIMITER, KWD_READ_SYMBOL, NIL), wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_SYMBOL, NIL), listO(4, KWD_READ_SYMBOL_OR_MANTISSA2, KWD_READ_INCLUDE, KWD_READ_SYMBOL_OR_MANTISSA, NIL), listO(16, KWD_READ_SYMBOL_OR_EXPONENT_DELIMITER, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/"), KWD_READ_QUALIFIED_NAME, wrapString("\\"), KWD_READ_ESCAPED_SYMBOL_ESCAPE, wrapString("+-"), listO(3, KWD_READ_SYMBOL_OR_EXPONENT, KWD_READ_SYMBOL, NIL), wrapString("0123456789"), listO(3, KWD_READ_SYMBOL_OR_EXPONENT2, KWD_READ_FLOAT, NIL), wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_SYMBOL, NIL), listO(14, KWD_READ_SYMBOL_OR_EXPONENT, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/"), KWD_READ_QUALIFIED_NAME, wrapString("\\"), KWD_READ_ESCAPED_SYMBOL_ESCAPE, wrapString("0123456789"), listO(3, KWD_READ_SYMBOL_OR_EXPONENT2, KWD_READ_FLOAT, NIL), wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_SYMBOL, NIL), listO(4, KWD_READ_SYMBOL_OR_EXPONENT2, KWD_READ_INCLUDE, KWD_READ_SYMBOL_OR_EXPONENT, NIL), listO(14, KWD_READ_SYMBOL_OR_CL_SYMBOL, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/"), KWD_READ_QUALIFIED_NAME, wrapString("\\"), KWD_READ_ESCAPED_SYMBOL_ESCAPE, wrapString("lL"), listO(3, KWD_READ_SYMBOL_OR_CL_SYMBOL2, KWD_READ_SYMBOL, NIL), wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_SYMBOL, NIL), listO(14, KWD_READ_SYMBOL_OR_CL_SYMBOL2, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/"), KWD_READ_QUALIFIED_NAME, wrapString("\\"), KWD_READ_ESCAPED_SYMBOL_ESCAPE, wrapString(":"), listO(3, KWD_READ_SYMBOL_OR_CL_SYMBOL3, KWD_READ_SYMBOL, NIL), wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_SYMBOL, NIL), listO(8, KWD_READ_SYMBOL_OR_CL_SYMBOL3, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_CL_SYMBOL, NIL), listO(8, KWD_READ_CL_SYMBOL, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_CL_SYMBOL, NIL), listO(4, KWD_READ_ESCAPED_SYMBOL_ESCAPE, KWD_READ_ANY, KWD_READ_ESCAPED_SYMBOL, NIL), listO(10, KWD_READ_ESCAPED_SYMBOL, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/|"), KWD_READ_ERROR, wrapString("\\"), KWD_READ_ESCAPED_SYMBOL_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_ESCAPED_SYMBOL, NIL), listO(9, KWD_READ_OPEN_FULLY_ESCAPED_SYMBOL, SYM_READ_STELLA_o, wrapString("|"), KWD_READ_CLOSE_FULLY_ESCAPED_NAME, wrapString("\\"), KWD_READ_FULLY_ESCAPED_SYMBOL_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_FULLY_ESCAPED_SYMBOL, NIL), listO(4, KWD_READ_FULLY_ESCAPED_SYMBOL_ESCAPE, KWD_READ_ANY, KWD_READ_FULLY_ESCAPED_SYMBOL, NIL), listO(9, KWD_READ_FULLY_ESCAPED_SYMBOL, SYM_READ_STELLA_o, wrapString("|"), KWD_READ_CLOSE_FULLY_ESCAPED_NAME, wrapString("\\"), KWD_READ_FULLY_ESCAPED_SYMBOL_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_FULLY_ESCAPED_SYMBOL, NIL), listO(4, KWD_READ_CLOSE_FULLY_ESCAPED_NAME, KWD_READ_INCLUDE, KWD_READ_START, NIL), listO(12, KWD_READ_SYMBOL, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/"), KWD_READ_QUALIFIED_NAME, wrapString("\\"), KWD_READ_ESCAPED_SYMBOL_ESCAPE, wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_SYMBOL, NIL), listO(10, KWD_READ_OPEN_KEYWORD, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("|"), KWD_READ_FULLY_ESCAPED_KEYWORD, wrapString("\\"), KWD_READ_ESCAPED_KEYWORD_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_KEYWORD, NIL), listO(10, KWD_READ_KEYWORD, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("\\"), KWD_READ_ESCAPED_KEYWORD_ESCAPE, wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_KEYWORD, NIL), listO(4, KWD_READ_ESCAPED_KEYWORD_ESCAPE, KWD_READ_ANY, KWD_READ_ESCAPED_KEYWORD, NIL), listO(10, KWD_READ_ESCAPED_KEYWORD, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("\\"), KWD_READ_ESCAPED_KEYWORD_ESCAPE, wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_ESCAPED_KEYWORD, NIL), listO(9, KWD_READ_FULLY_ESCAPED_KEYWORD, SYM_READ_STELLA_o, wrapString("|"), KWD_READ_CLOSE_FULLY_ESCAPED_NAME, wrapString("\\"), KWD_READ_FULLY_ESCAPED_KEYWORD_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_FULLY_ESCAPED_KEYWORD, NIL), listO(4, KWD_READ_FULLY_ESCAPED_KEYWORD_ESCAPE, KWD_READ_ANY, KWD_READ_FULLY_ESCAPED_KEYWORD, NIL), listO(10, KWD_READ_OPEN_SURROGATE, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("|"), KWD_READ_FULLY_ESCAPED_SURROGATE, wrapString("\\"), KWD_READ_ESCAPED_SURROGATE_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_SURROGATE, NIL), listO(10, KWD_READ_SURROGATE, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/|"), KWD_READ_ERROR, wrapString("\\"), KWD_READ_ESCAPED_SURROGATE_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_SURROGATE, NIL), listO(10, KWD_READ_ESCAPED_SURROGATE, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/|"), KWD_READ_ERROR, wrapString("\\"), KWD_READ_ESCAPED_SURROGATE_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_ESCAPED_SURROGATE, NIL), listO(4, KWD_READ_ESCAPED_SURROGATE_ESCAPE, KWD_READ_ANY, KWD_READ_ESCAPED_SURROGATE, NIL), listO(9, KWD_READ_FULLY_ESCAPED_SURROGATE, SYM_READ_STELLA_o, wrapString("|"), KWD_READ_CLOSE_FULLY_ESCAPED_NAME, wrapString("\\"), KWD_READ_FULLY_ESCAPED_SURROGATE_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_FULLY_ESCAPED_SURROGATE, NIL), listO(4, KWD_READ_FULLY_ESCAPED_SURROGATE_ESCAPE, KWD_READ_ANY, KWD_READ_FULLY_ESCAPED_SURROGATE, NIL), listO(16, KWD_READ_QUALIFIED_NAME, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("@"), KWD_READ_QUALIFIED_SURROGATE, wrapString(":"), KWD_READ_ERROR, wrapString("\\"), KWD_READ_QUALIFIED_ESCAPED_SYMBOL_ESCAPE, wrapString("|"), KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL, wrapString("/"), KWD_READ_QUALIFIED_NAME, KWD_READ_OTHERWISE, KWD_READ_QUALIFIED_SYMBOL, NIL), listO(12, KWD_READ_QUALIFIED_SYMBOL, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/"), KWD_READ_QUALIFIED_NAME, wrapString("\\"), KWD_READ_QUALIFIED_ESCAPED_SYMBOL_ESCAPE, wrapString("|"), KWD_READ_ERROR, KWD_READ_OTHERWISE, KWD_READ_QUALIFIED_SYMBOL, NIL), listO(12, KWD_READ_QUALIFIED_SURROGATE, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/"), KWD_READ_ERROR, wrapString("\\"), KWD_READ_QUALIFIED_ESCAPED_SURROGATE_ESCAPE, wrapString("|"), KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE, KWD_READ_OTHERWISE, KWD_READ_QUALIFIED_SURROGATE, NIL), listO(10, KWD_READ_QUALIFIED_ESCAPED_SYMBOL, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/|"), KWD_READ_ERROR, wrapString("\\"), KWD_READ_QUALIFIED_ESCAPED_SYMBOL_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_QUALIFIED_ESCAPED_SYMBOL, NIL), listO(4, KWD_READ_QUALIFIED_ESCAPED_SYMBOL_ESCAPE, KWD_READ_ANY, KWD_READ_QUALIFIED_ESCAPED_SYMBOL, NIL), listO(10, KWD_READ_QUALIFIED_ESCAPED_SURROGATE, KWD_READ_INCLUDE, KWD_READ_DELIMITER, wrapString("/|"), KWD_READ_ERROR, wrapString("\\"), KWD_READ_QUALIFIED_ESCAPED_SURROGATE_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_QUALIFIED_ESCAPED_SURROGATE, NIL), listO(4, KWD_READ_QUALIFIED_ESCAPED_SURROGATE_ESCAPE, KWD_READ_ANY, KWD_READ_QUALIFIED_ESCAPED_SURROGATE, NIL), listO(9, KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL, SYM_READ_STELLA_o, wrapString("|"), KWD_READ_CLOSE_FULLY_ESCAPED_NAME, wrapString("\\"), KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL, NIL), listO(4, KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL_ESCAPE, KWD_READ_ANY, KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL, NIL), listO(9, KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE, SYM_READ_STELLA_o, wrapString("|"), KWD_READ_CLOSE_FULLY_ESCAPED_NAME, wrapString("\\"), KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE_ESCAPE, KWD_READ_OTHERWISE, KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE, NIL), listO(4, KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE_ESCAPE, KWD_READ_ANY, KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE, NIL), listO(4, KWD_READ_ERROR, KWD_READ_INCLUDE, KWD_READ_START, NIL), NIL);
      oSTELLA_TOKENIZER_TABLEo = unstringifyTokenizerTable("32768|EJEJEJEJEJEJEJEJEJKMKMEJEJKMEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMEJEIJMEJEJEJFICIDIEJLIHILINIBJMIMIMIMIMIMIMIMIMIMICJIMEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJGIEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMKMEJEJKMEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMEJEIJMEJEJEJFICIDIEJLIHILINIBJMIMIMIMIMIMIMIMIMIMICJIMEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJGIEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMKMEJEJKMEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMEJEIJMEJEJEJFICIDIEJLIHILINIBJMIMIMIMIMIMIMIMIMIMICJIMEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJGIEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMKMEJEJKMEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMEJEIJMEJEJEJFICIDIEJLIHILINIBJMIMIMIMIMIMIMIMIMIMICJIMEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJGIEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBKJMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBLBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBEJEJEJEJEJEJEJEJEJKMKMEJEJKMEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMEJEIJMEJEJEJFICIDIEJLIHILINIBJMIMIMIMIMIMIMIMIMIMICJIMEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJGIEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMKMEJEJKMEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMEJEIJMEJEJEJFICIDIEJLIHILINIBJMIMIMIMIMIMIMIMIMIMICJIMEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJGIEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMKMEJEJKMEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMEJEIJMEJEJEJFICIDIEJLIHILIJBBJMIMIMIMIMIMIMIMIMIMICJIMEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJGIEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJIAIAIAIAIAIAIAIAIAIABAIAIABAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAGBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEJEJEJEJEJEJEJEJEJKMKMEJEJKMEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMEJEIJMEJEJEJFICIDIEJLIHILINIBJMIMIMIMIMIMIMIMIMIMICJIMEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJGIEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEBEBEBEBEBEBEBEBEBKMKMEBEBKMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMEBEIJMEBEBEBFICIDIEBEBHIEBNABBMAMAMAMAMAMAMAMAMAMAEBIMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBABEBEBEBGIEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBAAEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMKMEBEBKMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMEBEIJMEBEBEBFICIDIEBEBHIEBBCBBMAMAMAMAMAMAMAMAMAMAEBIMEBEBEBEBEBEBEBEBEBCCEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBABEBEBEBGIEBEBEBEBCCEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBAAEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMKMEBEBKMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMEBEIJMEBEBEBFICIDIEBEBHIEBEBBBBCBCBCBCBCBCBCBCBCBCEBIMEBEBEBEBEBEBEBEBEBCCEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBABEBEBEBGIEBEBEBEBCCEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBAAEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMKMEBEBKMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMEBEIJMEBEBEBFICIDIEBEBHIEBEBBBEBEBEBEBEBEBEBEBEBEBEBIMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBFCEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBABEBEBEBGIEBEBEBEBEBEBEBEBEBEBEBFCEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBAAEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCKCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCJKLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICJDJDJDJDJDJDJDJDJDKMKMJDJDKMJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDKMJDEIJMJDJDJDFICIDIJDJDHIJDJDBBJDJDJDJDJDJDJDJDJDJDAAIMJDJDJDJDGDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDHDJDJDJDGIJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDIDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDOCOCOCOCOCOCOCOCOCKMKMOCOCKMOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCKMOCEIJMOCOCOCFICIDIOCOCHIOCOCOCOCOCOCOCOCOCOCOCOCOCOCIMOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCNCOCOCOCGIOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCMCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCDDDDDDDDDDDDDDDDDDKMKMDDDDKMDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDKMDDEIJMDDDDDDFICIDIDDDDHIDDDDDDDDDDDDDDDDDDDDDDDDDDDDIMDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDCDDDDDDDGIDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDBDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDEBEBEBEBEBEBEBEBEBKMKMEBEBKMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMEBEIJMEBEBEBFICIDIEBEBHIEBEBBBEBEBEBEBEBEBEBEBEBEBEBIMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBABEBEBEBGIEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBAAEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBAAAAAAAAAAAAAAAAAAKMKMAAAAKMAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAKMAAEIJMAAAAAAFICIDIAAAAHIAAAAAAAAAAAAAAAAAAAAAAAAAAAAIMAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAGIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBHBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBIBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBBAGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBHBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBIBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBEJEJEJEJEJEJEJEJEJKMKMEJEJKMEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMEJEIJMEJEJEJFICIDIEJLIHILINIBJMIMIMIMIMIMIMIMIMIMICJIMEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJGIEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMKMEJEJKMEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMEJEIJMEJEJEJFICIDIEJLIHILINIBJMIMIMIMIMIMIMIMIMIMICJIMEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJGIEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBKJMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBLBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBKJNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBLBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBNBPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPJPBPBPBPBPBPBPBPBPBKMKMPBPBKMPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBKMPBEIJMPBPBPBFICIDIPBPBHIPBPBPBPBPBPBPBPBPBPBPBPBPBPBIMPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBGIPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBPBEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJLIEJLINIBJMIMIMIMIMIMIMIMIMIMICJEJEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJEJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEBEBEBEBEBEBEBEBEBKMKMEBEBKMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMEBEIJMEBEBEBFICIDIEBEBHIEBEBBBBCBCBCBCBCBCBCBCBCBCEBIMEBEBEBEBEBEBEBEBEBCCEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBABEBEBEBGIEBEBEBEBCCEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBAAEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMKMEBEBKMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMEBEIJMEBEBEBFICIDIEBDCHIDCEBBBECECECECECECECECECECEBIMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBABEBEBEBGIEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBAAEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMKMEBEBKMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMEBEIJMEBEBEBFICIDIEBEBHIEBEBBBECECECECECECECECECECEBIMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBABEBEBEBGIEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBAAEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMKMEBEBKMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMEBEIJMEBEBEBFICIDIEBEBHIEBEBBBECECECECECECECECECECEBIMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBABEBEBEBGIEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBAAEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMKMEBEBKMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBKMEBEIJMEBEBEBFICIDIEBEBHIEBEBBBEBEBEBEBEBEBEBEBEBEBGCIMEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBABEBEBEBGIEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBAAEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBHCHCHCHCHCHCHCHCHCKMKMHCHCKMHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCKMHCEIJMHCHCHCFICIDIHCHCHIHCHCHCHCHCHCHCHCHCHCHCHCHCHCIMHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCGIHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCAAHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCKMKMHCHCKMHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCKMHCEIJMHCHCHCFICIDIHCHCHIHCHCHCHCHCHCHCHCHCHCHCHCHCHCIMHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCGIHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCAAHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCHCICICICICICICICICICKMKMICICKMICICICICICICICICICICICICICICICICICICKMICEIJMICICICFICIDIICICHIICICAAICICICICICICICICICICICIMICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICABICICICGIICICICICICICICICICICICICICICICICICICICICICICICICICICICAAICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICEJEJEJEJEJEJEJEJEJKMKMEJEJKMEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJKMEJEIJMEJEJEJFICIDIEJLIHILINIBJMIMIMIMIMIMIMIMIMIMICJIMEJEJEJEJDJEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJAJEJEJEJGIEJEJOIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJPIEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJEJLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCKCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCJKLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCLCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCADMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCJKMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCOCOCOCOCOCOCOCOCOCKMKMOCOCKMOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCKMOCEIJMOCOCOCFICIDIOCOCHIOCOCOCOCOCOCOCOCOCOCOCOCOCOCIMOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCNCOCOCOCGIOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCAAOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCOCPCPCPCPCPCPCPCPCPCKMKMPCPCKMPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCKMPCEIJMPCPCPCFICIDIPCPCHIPCPCPCPCPCPCPCPCPCPCPCPCPCPCIMPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCNCPCPCPCGIPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCAAPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCPCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDFDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDJKBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDDDDDDDDDDDDDDDDDDDKMKMDDDDKMDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDKMDDEIJMDDDDDDFICIDIDDDDHIDDDDAADDDDDDDDDDDDDDDDDDDDDDIMDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDCDDDDDDDGIDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDAADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDEDEDEDEDEDEDEDEDEDKMKMEDEDKMEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDKMEDEIJMEDEDEDFICIDIEDEDHIEDEDAAEDEDEDEDEDEDEDEDEDEDEDIMEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDCDEDEDEDGIEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDAAEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDGDGDGDGDGDGDGDGDGDKMKMGDGDKMGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDKMGDEIJMGDGDGDFICIDIGDGDHIGDGDAAGDGDGDGDGDGDGDGDGDGDGDIMGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDKDGDGDGDGIGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDLDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDGDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDODIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDJKIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDJDJDJDJDJDJDJDJDJDKMKMJDJDKMJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDKMJDEIJMJDJDJDFICIDIJDJDHIJDJDBBJDJDJDJDJDJDJDJDJDJDJDIMJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDHDJDJDJDGIJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDAAJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDJDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDPDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDJKLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDMDMDMDMDMDMDMDMDMDKMKMMDMDKMMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDKMMDEIJMMDMDMDFICIDIMDMDHIMDMDAAMDMDMDMDMDMDMDMDMDMDMDIMMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDHDMDMDMDGIMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDAAMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDMDNDNDNDNDNDNDNDNDNDKMKMNDNDKMNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDKMNDEIJMNDNDNDFICIDINDNDHINDNDAANDNDNDNDNDNDNDNDNDNDNDIMNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDKDNDNDNDGINDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDAANDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDNDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLDLD|64|ERROR|START|OPEN-PAREN|CLOSE-PAREN|OPEN-STRING|SINGLE-QUOTE|BACK-QUOTE|COMMA|COMMENT|HASH|WHITE-SPACE|SYMBOL-OR-SIGNED-NUMBER|SYMBOL-OR-NUMBER|SYMBOL-OR-MANTISSA|SYMBOL-OR-CL-SYMBOL|OPEN-FULLY-ESCAPED-SYMBOL|ESCAPED-SYMBOL-ESCAPE|QUALIFIED-NAME|OPEN-KEYWORD|OPEN-SURROGATE|SYMBOL|DELIMITER|PAREN-COMMENT|PAREN-COMMENT-ESCAPE|PAREN-COMMENT-BAR|COMMA-SPLICE|CLOSE-STRING|STRING-ESCAPE|STRING|ESCAPED-STRING|CHARACTER-CONSTANT|CHARACTER|ATOM|SYMBOL-OR-MANTISSA2|SYMBOL-OR-EXPONENT-DELIMITER|SYMBOL-OR-EXPONENT|SYMBOL-OR-EXPONENT2|SYMBOL-OR-CL-SYMBOL2|SYMBOL-OR-CL-SYMBOL3|CL-SYMBOL|ESCAPED-SYMBOL|CLOSE-FULLY-ESCAPED-NAME|FULLY-ESCAPED-SYMBOL-ESCAPE|FULLY-ESCAPED-SYMBOL|FULLY-ESCAPED-KEYWORD|ESCAPED-KEYWORD-ESCAPE|KEYWORD|ESCAPED-KEYWORD|FULLY-ESCAPED-KEYWORD-ESCAPE|FULLY-ESCAPED-SURROGATE|ESCAPED-SURROGATE-ESCAPE|SURROGATE|ESCAPED-SURROGATE|FULLY-ESCAPED-SURROGATE-ESCAPE|QUALIFIED-SURROGATE|QUALIFIED-ESCAPED-SYMBOL-ESCAPE|QUALIFIED-FULLY-ESCAPED-SYMBOL|QUALIFIED-SYMBOL|QUALIFIED-ESCAPED-SURROGATE-ESCAPE|QUALIFIED-FULLY-ESCAPED-SURROGATE|QUALIFIED-ESCAPED-SYMBOL|QUALIFIED-ESCAPED-SURROGATE|QUALIFIED-FULLY-ESCAPED-SYMBOL-ESCAPE|QUALIFIED-FULLY-ESCAPED-SURROGATE-ESCAPE|64|ERROR|START|OPEN-PAREN|CLOSE-PAREN|STRING|SINGLE-QUOTE|BACK-QUOTE|COMMA|COMMENT|HASH|WHITE-SPACE|SYMBOL|INTEGER|SYMBOL|SYMBOL|FULLY-ESCAPED-SYMBOL|ESCAPED-SYMBOL-ESCAPE|QUALIFIED-NAME|KEYWORD|SURROGATE|SYMBOL|DELIMITER|PAREN-COMMENT|PAREN-COMMENT-ESCAPE|PAREN-COMMENT-BAR|COMMA-SPLICE|CLOSE-STRING|STRING-ESCAPE|STRING|ESCAPED-STRING|CHARACTER-CONSTANT|CHARACTER|ATOM|FLOAT|SYMBOL|SYMBOL|FLOAT|SYMBOL|SYMBOL|CL-SYMBOL|ESCAPED-SYMBOL|CLOSE-FULLY-ESCAPED-NAME|FULLY-ESCAPED-SYMBOL-ESCAPE|FULLY-ESCAPED-SYMBOL|FULLY-ESCAPED-KEYWORD|ESCAPED-KEYWORD-ESCAPE|KEYWORD|ESCAPED-KEYWORD|FULLY-ESCAPED-KEYWORD-ESCAPE|FULLY-ESCAPED-SURROGATE|ESCAPED-SURROGATE-ESCAPE|SURROGATE|ESCAPED-SURROGATE|FULLY-ESCAPED-SURROGATE-ESCAPE|QUALIFIED-SURROGATE|QUALIFIED-ESCAPED-SYMBOL-ESCAPE|QUALIFIED-FULLY-ESCAPED-SYMBOL|QUALIFIED-SYMBOL|QUALIFIED-ESCAPED-SURROGATE-ESCAPE|QUALIFIED-FULLY-ESCAPED-SURROGATE|QUALIFIED-ESCAPED-SYMBOL|QUALIFIED-ESCAPED-SURROGATE|QUALIFIED-FULLY-ESCAPED-SYMBOL-ESCAPE|QUALIFIED-FULLY-ESCAPED-SURROGATE-ESCAPE|64|TTTTFTTTTFTTTTTFFTTTTTFFFTTFFFFTFTTTTTTTTTFFFFTTFFFTTFTFFTFFTTFF|");
      { PropertyList* self049 = newPropertyList();

        self049->thePlist = listO(63, KWD_READ_SYMBOL, KWD_READ_SYMBOL, KWD_READ_ESCAPED_SYMBOL, KWD_READ_SYMBOL, KWD_READ_FULLY_ESCAPED_SYMBOL, KWD_READ_SYMBOL, KWD_READ_QUALIFIED_SYMBOL, KWD_READ_SYMBOL, KWD_READ_QUALIFIED_ESCAPED_SYMBOL, KWD_READ_SYMBOL, KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL, KWD_READ_SYMBOL, KWD_READ_CL_SYMBOL, KWD_READ_SYMBOL, KWD_READ_SURROGATE, KWD_READ_SURROGATE, KWD_READ_ESCAPED_SURROGATE, KWD_READ_SURROGATE, KWD_READ_QUALIFIED_SURROGATE, KWD_READ_SURROGATE, KWD_READ_QUALIFIED_ESCAPED_SURROGATE, KWD_READ_SURROGATE, KWD_READ_FULLY_ESCAPED_SURROGATE, KWD_READ_SURROGATE, KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE, KWD_READ_SURROGATE, KWD_READ_KEYWORD, KWD_READ_KEYWORD, KWD_READ_ESCAPED_KEYWORD, KWD_READ_KEYWORD, KWD_READ_FULLY_ESCAPED_KEYWORD, KWD_READ_KEYWORD, KWD_READ_QUALIFIED_NAME, KWD_READ_QUALIFIED_NAME, KWD_READ_STRING, KWD_READ_STRING, KWD_READ_ESCAPED_STRING, KWD_READ_STRING, KWD_READ_INTEGER, KWD_READ_INTEGER, KWD_READ_FLOAT, KWD_READ_FLOAT, KWD_READ_CHARACTER, KWD_READ_CHARACTER, KWD_READ_OPEN_PAREN, KWD_READ_OPEN_PAREN, KWD_READ_CLOSE_PAREN, KWD_READ_CLOSE_PAREN, KWD_READ_SINGLE_QUOTE, KWD_READ_SINGLE_QUOTE, KWD_READ_BACK_QUOTE, KWD_READ_BACK_QUOTE, KWD_READ_COMMA, KWD_READ_COMMA, KWD_READ_COMMA_SPLICE, KWD_READ_COMMA_SPLICE, KWD_READ_CLOSE_STRING, KWD_READ_CLOSE_BALANCED_QUOTE, KWD_READ_CLOSE_FULLY_ESCAPED_NAME, KWD_READ_CLOSE_BALANCED_QUOTE, KWD_READ_ERROR, KWD_READ_ERROR, NIL);
        oSTELLA_LOGICAL_STATE_NAMES_TABLEo = self049;
      }
      oSTELLA_LOGICAL_STATE_NAMESo = newVector(oSTELLA_TOKENIZER_TABLEo->stateNames->length());
      { int i = NULL_INTEGER;
        int iter051 = 0;
        int upperBound052 = oSTELLA_LOGICAL_STATE_NAMESo->length() - 1;

        while (iter051 <= upperBound052) {
          i = iter051;
          iter051 = iter051 + 1;
          (oSTELLA_LOGICAL_STATE_NAMESo->theArray)[i] = (((Keyword*)(oSTELLA_LOGICAL_STATE_NAMES_TABLEo->lookup(((Keyword*)(((GeneralizedSymbol*)((oSTELLA_TOKENIZER_TABLEo->stateNames->theArray)[i]))))))));
          if (!((boolean)(((Keyword*)((oSTELLA_LOGICAL_STATE_NAMESo->theArray)[i]))))) {
            (oSTELLA_LOGICAL_STATE_NAMESo->theArray)[i] = KWD_READ_ERROR;
          }
        }
      }
      oSTELLA_TOKENIZER_WHITE_SPACE_STATEo = oSTELLA_TOKENIZER_TABLEo->stateNames->position(KWD_READ_WHITE_SPACE, 0);
      oUSER_QUERY_ACTIONo.set(KWD_READ_ASK);
    }
    if (currentStartupTimePhaseP(5)) {
      helpStartupRead5();
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupRead6();
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *MAX-TOKENIZER-STATES* INTEGER 64)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *MAX-TOKENIZER-CHARACTERS* INTEGER 256)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *TOKENIZER-INITIAL-BUFFER-SIZE* INTEGER 2048)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *WITHTOKENIZERINPUTTYPE* TYPE NULL)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STELLA-TOKENIZER-TABLE-DEFINITION* CONS (BQUOTE ((:START :INCLUDE :DELIMITER :INCLUDE :ATOM) (:DELIMITER * \"(\" :OPEN-PAREN * \")\" :CLOSE-PAREN * \"\\\"\" (:OPEN-STRING :STRING) * \"'\" :SINGLE-QUOTE * \"`\" :BACK-QUOTE * \",\" :COMMA ! \";\" :COMMENT ! \"#\" :HASH ! (#\\  #\\Tab #\\Linefeed #\\Return) :WHITE-SPACE :EOF :EOF) (:WHITE-SPACE :INCLUDE :START) (:COMMENT (#\\Linefeed #\\Return) :START :EOF :EOF :OTHERWISE :COMMENT) (:PAREN-COMMENT \"\\\\\" :PAREN-COMMENT-ESCAPE \"|\" :PAREN-COMMENT-BAR :OTHERWISE :PAREN-COMMENT) (:PAREN-COMMENT-ESCAPE :ANY :PAREN-COMMENT) (:PAREN-COMMENT-BAR \"#\" :START \"\\\\\" :PAREN-COMMENT-ESCAPE \"|\" :PAREN-COMMENT-BAR :OTHERWISE :PAREN-COMMENT) (:OPEN-PAREN :INCLUDE :START) (:CLOSE-PAREN :INCLUDE :START) (:SINGLE-QUOTE :INCLUDE :START) (:BACK-QUOTE :INCLUDE :START) (:COMMA \".\" :COMMA-SPLICE :INCLUDE :DELIMITER * \"-+\" (:SYMBOL-OR-SIGNED-NUMBER :SYMBOL) * \"0123456789\" (:SYMBOL-OR-NUMBER :INTEGER) * \"cC\" (:SYMBOL-OR-CL-SYMBOL :SYMBOL) * \"|\" (:OPEN-FULLY-ESCAPED-SYMBOL :FULLY-ESCAPED-SYMBOL) * \"\\\\\" :ESCAPED-SYMBOL-ESCAPE * \"/\" :QUALIFIED-NAME * \":\" (:OPEN-KEYWORD :KEYWORD) * \"@\" (:OPEN-SURROGATE :SURROGATE) * :OTHERWISE :SYMBOL) (:COMMA-SPLICE :INCLUDE :START) (:OPEN-STRING * \"\\\"\" :CLOSE-STRING \"\\\\\" :STRING-ESCAPE :OTHERWISE :STRING) (:STRING * \"\\\"\" :CLOSE-STRING \"\\\\\" :STRING-ESCAPE :OTHERWISE :STRING) (:CLOSE-STRING :INCLUDE :START) (:STRING-ESCAPE :ANY :ESCAPED-STRING) (:ESCAPED-STRING * \"\\\"\" :CLOSE-STRING \"\\\\\" :STRING-ESCAPE :OTHERWISE :ESCAPED-STRING) (:HASH \"\\\\\" :CHARACTER-CONSTANT \"|\" :PAREN-COMMENT) (:CHARACTER-CONSTANT * :ANY :CHARACTER) (:CHARACTER :INCLUDE :DELIMITER :OTHERWISE :CHARACTER) (:ATOM * \"-+\" (:SYMBOL-OR-SIGNED-NUMBER :SYMBOL) * \"0123456789\" (:SYMBOL-OR-NUMBER :INTEGER) * \".\" (:SYMBOL-OR-MANTISSA :SYMBOL) * \"cC\" (:SYMBOL-OR-CL-SYMBOL :SYMBOL) * \"|\" (:OPEN-FULLY-ESCAPED-SYMBOL :FULLY-ESCAPED-SYMBOL) * \"\\\\\" :ESCAPED-SYMBOL-ESCAPE * \"/\" :QUALIFIED-NAME * \":\" (:OPEN-KEYWORD :KEYWORD) * \"@\" (:OPEN-SURROGATE :SURROGATE) * :OTHERWISE :SYMBOL) (:SYMBOL-OR-SIGNED-NUMBER :INCLUDE :DELIMITER \"/\" :QUALIFIED-NAME \"\\\\\" :ESCAPED-SYMBOL-ESCAPE \"0123456789\" (:SYMBOL-OR-NUMBER :INTEGER) \".\" (:SYMBOL-OR-MANTISSA :SYMBOL) \"|\" :ERROR :OTHERWISE :SYMBOL) (:SYMBOL-OR-NUMBER :INCLUDE :DELIMITER \"/\" :QUALIFIED-NAME \"\\\\\" :ESCAPED-SYMBOL-ESCAPE \"0123456789\" (:SYMBOL-OR-NUMBER :INTEGER) \".\" (:SYMBOL-OR-MANTISSA2 :FLOAT) \"eE\" (:SYMBOL-OR-EXPONENT-DELIMITER :SYMBOL) \"|\" :ERROR :OTHERWISE :SYMBOL) (:SYMBOL-OR-MANTISSA :INCLUDE :DELIMITER \"/\" :QUALIFIED-NAME \"\\\\\" :ESCAPED-SYMBOL-ESCAPE \"0123456789\" (:SYMBOL-OR-MANTISSA2 :FLOAT) \"eE\" (:SYMBOL-OR-EXPONENT-DELIMITER :SYMBOL) \"|\" :ERROR :OTHERWISE :SYMBOL) (:SYMBOL-OR-MANTISSA2 :INCLUDE :SYMBOL-OR-MANTISSA) (:SYMBOL-OR-EXPONENT-DELIMITER :INCLUDE :DELIMITER \"/\" :QUALIFIED-NAME \"\\\\\" :ESCAPED-SYMBOL-ESCAPE \"+-\" (:SYMBOL-OR-EXPONENT :SYMBOL) \"0123456789\" (:SYMBOL-OR-EXPONENT2 :FLOAT) \"|\" :ERROR :OTHERWISE :SYMBOL) (:SYMBOL-OR-EXPONENT :INCLUDE :DELIMITER \"/\" :QUALIFIED-NAME \"\\\\\" :ESCAPED-SYMBOL-ESCAPE \"0123456789\" (:SYMBOL-OR-EXPONENT2 :FLOAT) \"|\" :ERROR :OTHERWISE :SYMBOL) (:SYMBOL-OR-EXPONENT2 :INCLUDE :SYMBOL-OR-EXPONENT) (:SYMBOL-OR-CL-SYMBOL :INCLUDE :DELIMITER \"/\" :QUALIFIED-NAME \"\\\\\" :ESCAPED-SYMBOL-ESCAPE \"lL\" (:SYMBOL-OR-CL-SYMBOL2 :SYMBOL) \"|\" :ERROR :OTHERWISE :SYMBOL) (:SYMBOL-OR-CL-SYMBOL2 :INCLUDE :DELIMITER \"/\" :QUALIFIED-NAME \"\\\\\" :ESCAPED-SYMBOL-ESCAPE \":\" (:SYMBOL-OR-CL-SYMBOL3 :SYMBOL) \"|\" :ERROR :OTHERWISE :SYMBOL) (:SYMBOL-OR-CL-SYMBOL3 :INCLUDE :DELIMITER \"|\" :ERROR :OTHERWISE :CL-SYMBOL) (:CL-SYMBOL :INCLUDE :DELIMITER \"|\" :ERROR :OTHERWISE :CL-SYMBOL) (:ESCAPED-SYMBOL-ESCAPE :ANY :ESCAPED-SYMBOL) (:ESCAPED-SYMBOL :INCLUDE :DELIMITER \"/|\" :ERROR \"\\\\\" :ESCAPED-SYMBOL-ESCAPE :OTHERWISE :ESCAPED-SYMBOL) (:OPEN-FULLY-ESCAPED-SYMBOL * \"|\" :CLOSE-FULLY-ESCAPED-NAME \"\\\\\" :FULLY-ESCAPED-SYMBOL-ESCAPE :OTHERWISE :FULLY-ESCAPED-SYMBOL) (:FULLY-ESCAPED-SYMBOL-ESCAPE :ANY :FULLY-ESCAPED-SYMBOL) (:FULLY-ESCAPED-SYMBOL * \"|\" :CLOSE-FULLY-ESCAPED-NAME \"\\\\\" :FULLY-ESCAPED-SYMBOL-ESCAPE :OTHERWISE :FULLY-ESCAPED-SYMBOL) (:CLOSE-FULLY-ESCAPED-NAME :INCLUDE :START) (:SYMBOL :INCLUDE :DELIMITER \"/\" :QUALIFIED-NAME \"\\\\\" :ESCAPED-SYMBOL-ESCAPE \"|\" :ERROR :OTHERWISE :SYMBOL) (:OPEN-KEYWORD :INCLUDE :DELIMITER \"|\" :FULLY-ESCAPED-KEYWORD \"\\\\\" :ESCAPED-KEYWORD-ESCAPE :OTHERWISE :KEYWORD) (:KEYWORD :INCLUDE :DELIMITER \"\\\\\" :ESCAPED-KEYWORD-ESCAPE \"|\" :ERROR :OTHERWISE :KEYWORD) (:ESCAPED-KEYWORD-ESCAPE :ANY :ESCAPED-KEYWORD) (:ESCAPED-KEYWORD :INCLUDE :DELIMITER \"\\\\\" :ESCAPED-KEYWORD-ESCAPE \"|\" :ERROR :OTHERWISE :ESCAPED-KEYWORD) (:FULLY-ESCAPED-KEYWORD * \"|\" :CLOSE-FULLY-ESCAPED-NAME \"\\\\\" :FULLY-ESCAPED-KEYWORD-ESCAPE :OTHERWISE :FULLY-ESCAPED-KEYWORD) (:FULLY-ESCAPED-KEYWORD-ESCAPE :ANY :FULLY-ESCAPED-KEYWORD) (:OPEN-SURROGATE :INCLUDE :DELIMITER \"|\" :FULLY-ESCAPED-SURROGATE \"\\\\\" :ESCAPED-SURROGATE-ESCAPE :OTHERWISE :SURROGATE) (:SURROGATE :INCLUDE :DELIMITER \"/|\" :ERROR \"\\\\\" :ESCAPED-SURROGATE-ESCAPE :OTHERWISE :SURROGATE) (:ESCAPED-SURROGATE :INCLUDE :DELIMITER \"/|\" :ERROR \"\\\\\" :ESCAPED-SURROGATE-ESCAPE :OTHERWISE :ESCAPED-SURROGATE) (:ESCAPED-SURROGATE-ESCAPE :ANY :ESCAPED-SURROGATE) (:FULLY-ESCAPED-SURROGATE * \"|\" :CLOSE-FULLY-ESCAPED-NAME \"\\\\\" :FULLY-ESCAPED-SURROGATE-ESCAPE :OTHERWISE :FULLY-ESCAPED-SURROGATE) (:FULLY-ESCAPED-SURROGATE-ESCAPE :ANY :FULLY-ESCAPED-SURROGATE) (:QUALIFIED-NAME :INCLUDE :DELIMITER \"@\" :QUALIFIED-SURROGATE \":\" :ERROR \"\\\\\" :QUALIFIED-ESCAPED-SYMBOL-ESCAPE \"|\" :QUALIFIED-FULLY-ESCAPED-SYMBOL \"/\" :QUALIFIED-NAME :OTHERWISE :QUALIFIED-SYMBOL) (:QUALIFIED-SYMBOL :INCLUDE :DELIMITER \"/\" :QUALIFIED-NAME \"\\\\\" :QUALIFIED-ESCAPED-SYMBOL-ESCAPE \"|\" :ERROR :OTHERWISE :QUALIFIED-SYMBOL) (:QUALIFIED-SURROGATE :INCLUDE :DELIMITER \"/\" :ERROR \"\\\\\" :QUALIFIED-ESCAPED-SURROGATE-ESCAPE \"|\" :QUALIFIED-FULLY-ESCAPED-SURROGATE :OTHERWISE :QUALIFIED-SURROGATE) (:QUALIFIED-ESCAPED-SYMBOL :INCLUDE :DELIMITER \"/|\" :ERROR \"\\\\\" :QUALIFIED-ESCAPED-SYMBOL-ESCAPE :OTHERWISE :QUALIFIED-ESCAPED-SYMBOL) (:QUALIFIED-ESCAPED-SYMBOL-ESCAPE :ANY :QUALIFIED-ESCAPED-SYMBOL) (:QUALIFIED-ESCAPED-SURROGATE :INCLUDE :DELIMITER \"/|\" :ERROR \"\\\\\" :QUALIFIED-ESCAPED-SURROGATE-ESCAPE :OTHERWISE :QUALIFIED-ESCAPED-SURROGATE) (:QUALIFIED-ESCAPED-SURROGATE-ESCAPE :ANY :QUALIFIED-ESCAPED-SURROGATE) (:QUALIFIED-FULLY-ESCAPED-SYMBOL * \"|\" :CLOSE-FULLY-ESCAPED-NAME \"\\\\\" :QUALIFIED-FULLY-ESCAPED-SYMBOL-ESCAPE :OTHERWISE :QUALIFIED-FULLY-ESCAPED-SYMBOL) (:QUALIFIED-FULLY-ESCAPED-SYMBOL-ESCAPE :ANY :QUALIFIED-FULLY-ESCAPED-SYMBOL) (:QUALIFIED-FULLY-ESCAPED-SURROGATE * \"|\" :CLOSE-FULLY-ESCAPED-NAME \"\\\\\" :QUALIFIED-FULLY-ESCAPED-SURROGATE-ESCAPE :OTHERWISE :QUALIFIED-FULLY-ESCAPED-SURROGATE) (:QUALIFIED-FULLY-ESCAPED-SURROGATE-ESCAPE :ANY :QUALIFIED-FULLY-ESCAPED-SURROGATE) (:ERROR :INCLUDE :START))))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STELLA-TOKENIZER-TABLE* TOKENIZER-TABLE NULL)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STELLA-LOGICAL-STATE-NAMES* (VECTOR OF KEYWORD) NULL)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STELLA-LOGICAL-STATE-NAMES-TABLE* (PROPERTY-LIST OF KEYWORD KEYWORD) (NEW (PROPERTY-LIST OF KEYWORD KEYWORD) :THE-PLIST (BQUOTE (:SYMBOL :SYMBOL :ESCAPED-SYMBOL :SYMBOL :FULLY-ESCAPED-SYMBOL :SYMBOL :QUALIFIED-SYMBOL :SYMBOL :QUALIFIED-ESCAPED-SYMBOL :SYMBOL :QUALIFIED-FULLY-ESCAPED-SYMBOL :SYMBOL :CL-SYMBOL :SYMBOL :SURROGATE :SURROGATE :ESCAPED-SURROGATE :SURROGATE :QUALIFIED-SURROGATE :SURROGATE :QUALIFIED-ESCAPED-SURROGATE :SURROGATE :FULLY-ESCAPED-SURROGATE :SURROGATE :QUALIFIED-FULLY-ESCAPED-SURROGATE :SURROGATE :KEYWORD :KEYWORD :ESCAPED-KEYWORD :KEYWORD :FULLY-ESCAPED-KEYWORD :KEYWORD :QUALIFIED-NAME :QUALIFIED-NAME :STRING :STRING :ESCAPED-STRING :STRING :INTEGER :INTEGER :FLOAT :FLOAT :CHARACTER :CHARACTER :OPEN-PAREN :OPEN-PAREN :CLOSE-PAREN :CLOSE-PAREN :SINGLE-QUOTE :SINGLE-QUOTE :BACK-QUOTE :BACK-QUOTE :COMMA :COMMA :COMMA-SPLICE :COMMA-SPLICE :CLOSE-STRING :CLOSE-BALANCED-QUOTE :CLOSE-FULLY-ESCAPED-NAME :CLOSE-BALANCED-QUOTE :ERROR :ERROR))))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STELLA-TOKENIZER-WHITE-SPACE-STATE* INTEGER (POSITION (STATE-NAMES *STELLA-TOKENIZER-TABLE*) :WHITE-SPACE 0))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *USER-QUERY-ACTION* KEYWORD :ASK :PUBLIC? TRUE :DOCUMENTATION \"Controls the behavior of interactive queries.  The default is :ASK\nwhich asks the user.  Other options are :YES, :NO, :YES-VERBOSE, :NO-VERBOSE.  These\nreturn the answer indicated, with the verbose versions printing the message and answer.\")");
    }
  }
}

Surrogate* SGT_READ_STELLA_TOKENIZER_TABLE = NULL;

Symbol* SYM_READ_STELLA_TRANSITIONS = NULL;

Symbol* SYM_READ_STELLA_UNIQUE_STATE_NAMES = NULL;

Symbol* SYM_READ_STELLA_STATE_NAMES = NULL;

Symbol* SYM_READ_STELLA_LEGAL_EOF_STATES = NULL;

Symbol* SYM_READ_STELLA_CHARACTER_SET = NULL;

Keyword* KWD_READ_ERROR = NULL;

Keyword* KWD_READ_START = NULL;

Keyword* KWD_READ_EOF = NULL;

Surrogate* SGT_READ_STELLA_GENERALIZED_SYMBOL = NULL;

Surrogate* SGT_READ_STELLA_CONS = NULL;

Keyword* KWD_READ_BLOCK = NULL;

Keyword* KWD_READ_LINE = NULL;

Keyword* KWD_READ_CHARACTER = NULL;

Surrogate* SGT_READ_STELLA_TOKENIZER_TOKEN = NULL;

Symbol* SYM_READ_STELLA_TYPE = NULL;

Symbol* SYM_READ_STELLA_CONTENT = NULL;

Symbol* SYM_READ_STELLA_NEXT = NULL;

Surrogate* SGT_READ_STELLA_TOKENIZER_STREAM_STATE = NULL;

Symbol* SYM_READ_STELLA_BUFFER_SIZE = NULL;

Symbol* SYM_READ_STELLA_CURSOR = NULL;

Symbol* SYM_READ_STELLA_END = NULL;

Symbol* SYM_READ_STELLA_STATE = NULL;

Symbol* SYM_READ_STELLA_TOKEN_LIST = NULL;

Surrogate* SGT_READ_STELLA_INPUT_STREAM = NULL;

Surrogate* SGT_READ_STELLA_STRING = NULL;

Surrogate* SGT_READ_STELLA_VOID = NULL;

Surrogate* SGT_READ_STELLA_MUTABLE_STRING = NULL;

Symbol* SYM_READ_STELLA_LET = NULL;

Symbol* SYM_READ_STELLA_TOK_TABLE_ = NULL;

Symbol* SYM_READ_STELLA_TOK_TRANSITIONS_ = NULL;

Symbol* SYM_READ_STELLA_TOK_STATENAMES_ = NULL;

Symbol* SYM_READ_STELLA_THE_ARRAY = NULL;

Symbol* SYM_READ_STELLA_TOK_TOKENSTART_ = NULL;

Symbol* SYM_READ_STELLA_TOK_ENDOFTOKENSp_ = NULL;

Symbol* SYM_READ_STELLA_FALSE = NULL;

Symbol* SYM_READ_STELLA_IGNORE = NULL;

Symbol* SYM_READ_STELLA_TOK_STREAMSTATE_ = NULL;

Symbol* SYM_READ_STELLA_TOKENIZER_STREAM_STATE = NULL;

Symbol* SYM_READ_STELLA_NULL = NULL;

Symbol* SYM_READ_STELLA_TOK_BUFFER_ = NULL;

Symbol* SYM_READ_STELLA_STRING_TO_TOKENIZER_BYTE_ARRAY = NULL;

Symbol* SYM_READ_STELLA_TOK_STATE_ = NULL;

Symbol* SYM_READ_STELLA_TOK_NEXTSTATE_ = NULL;

Symbol* SYM_READ_STELLA_TOK_CURSOR_ = NULL;

Symbol* SYM_READ_STELLA_TOK_SIZE_ = NULL;

Symbol* SYM_READ_STELLA_LENGTH = NULL;

Symbol* SYM_READ_STELLA_TOK_END_ = NULL;

Symbol* SYM_READ_STELLA_TOK_INPUTSTREAM_ = NULL;

Symbol* SYM_READ_STELLA_TOK_ECHOSTREAM_ = NULL;

Symbol* SYM_READ_STELLA_ECHO_STREAM = NULL;

Symbol* SYM_READ_STELLA_CHOOSE = NULL;

Symbol* SYM_READ_STELLA_NULLp = NULL;

Symbol* SYM_READ_STELLA_TOKENIZER_STATE = NULL;

Symbol* SYM_READ_STELLA_SETF = NULL;

Symbol* SYM_READ_STELLA_NEW = NULL;

Symbol* SYM_READ_STELLA_BUFFER = NULL;

Symbol* SYM_READ_STELLA_TOK_CHECKPOINT_ = NULL;

Symbol* SYM_READ_STELLA_le = NULL;

Symbol* SYM_READ_STELLA_END_OF_TOKENSp = NULL;

Symbol* SYM_READ_STELLA_GET_TOKEN_TEXT = NULL;

Symbol* SYM_READ_STELLA_GET_TOKEN_TEXT_INTERNAL = NULL;

Symbol* SYM_READ_STELLA_i = NULL;

Symbol* SYM_READ_STELLA_l = NULL;

Symbol* SYM_READ_STELLA_GET_TOKEN_TYPE = NULL;

Symbol* SYM_READ_STELLA_NTH = NULL;

Symbol* SYM_READ_STELLA_WHEN = NULL;

Symbol* SYM_READ_STELLA_DEFINEDp = NULL;

Symbol* SYM_READ_STELLA_GET_NEXT_TOKEN = NULL;

Symbol* SYM_READ_STELLA_SAVE_TOKENIZER_STREAM_STATE = NULL;

Symbol* SYM_READ_STELLA_TRUE = NULL;

Symbol* SYM_READ_STELLA_PROGN = NULL;

Symbol* SYM_READ_STELLA_SETQ = NULL;

Symbol* SYM_READ_STELLA_LOOP = NULL;

Symbol* SYM_READ_STELLA_CHARACTER_CODE = NULL;

Symbol* SYM_READ_STELLA_LOGOR = NULL;

Symbol* SYM_READ_STELLA_SHIFT_LEFT = NULL;

Symbol* SYM_READ_STELLA_BYTE_ARRAY_NTH = NULL;

Symbol* SYM_READ_STELLA_COND = NULL;

Symbol* SYM_READ_STELLA_e = NULL;

Symbol* SYM_READ_STELLA_LOGAND = NULL;

Symbol* SYM_READ_STELLA_ii = NULL;

Symbol* SYM_READ_STELLA_OTHERWISE = NULL;

Symbol* SYM_READ_STELLA_BREAK = NULL;

Symbol* SYM_READ_STELLA_READ_INTO_TOKENIZER_BUFFER = NULL;

Symbol* SYM_READ_STELLA_MOD = NULL;

Symbol* SYM_READ_STELLA_UNLESS = NULL;

Symbol* SYM_READ_STELLA_IF = NULL;

Symbol* SYM_READ_STELLA_ge = NULL;

Symbol* SYM_READ_STELLA_PRINT_STREAM = NULL;

Symbol* SYM_READ_STELLA_1_ = NULL;

Surrogate* SGT_READ_STELLA_STREAM_TOKENIZER = NULL;

Symbol* SYM_READ_STELLA_STREAM = NULL;

Symbol* SYM_READ_STELLA_TABLE = NULL;

Keyword* KWD_READ_INCLUDE = NULL;

Keyword* KWD_READ_DELIMITER = NULL;

Keyword* KWD_READ_ATOM = NULL;

Symbol* SYM_READ_STELLA_o = NULL;

Keyword* KWD_READ_OPEN_PAREN = NULL;

Keyword* KWD_READ_CLOSE_PAREN = NULL;

Keyword* KWD_READ_OPEN_STRING = NULL;

Keyword* KWD_READ_STRING = NULL;

Keyword* KWD_READ_SINGLE_QUOTE = NULL;

Keyword* KWD_READ_BACK_QUOTE = NULL;

Keyword* KWD_READ_COMMA = NULL;

Symbol* SYM_READ_STELLA_x = NULL;

Keyword* KWD_READ_COMMENT = NULL;

Keyword* KWD_READ_HASH = NULL;

Keyword* KWD_READ_WHITE_SPACE = NULL;

Keyword* KWD_READ_OTHERWISE = NULL;

Keyword* KWD_READ_PAREN_COMMENT = NULL;

Keyword* KWD_READ_PAREN_COMMENT_ESCAPE = NULL;

Keyword* KWD_READ_PAREN_COMMENT_BAR = NULL;

Keyword* KWD_READ_ANY = NULL;

Keyword* KWD_READ_COMMA_SPLICE = NULL;

Keyword* KWD_READ_SYMBOL_OR_SIGNED_NUMBER = NULL;

Keyword* KWD_READ_SYMBOL = NULL;

Keyword* KWD_READ_SYMBOL_OR_NUMBER = NULL;

Keyword* KWD_READ_INTEGER = NULL;

Keyword* KWD_READ_SYMBOL_OR_CL_SYMBOL = NULL;

Keyword* KWD_READ_OPEN_FULLY_ESCAPED_SYMBOL = NULL;

Keyword* KWD_READ_FULLY_ESCAPED_SYMBOL = NULL;

Keyword* KWD_READ_ESCAPED_SYMBOL_ESCAPE = NULL;

Keyword* KWD_READ_QUALIFIED_NAME = NULL;

Keyword* KWD_READ_OPEN_KEYWORD = NULL;

Keyword* KWD_READ_KEYWORD = NULL;

Keyword* KWD_READ_OPEN_SURROGATE = NULL;

Keyword* KWD_READ_SURROGATE = NULL;

Keyword* KWD_READ_CLOSE_STRING = NULL;

Keyword* KWD_READ_STRING_ESCAPE = NULL;

Keyword* KWD_READ_ESCAPED_STRING = NULL;

Keyword* KWD_READ_CHARACTER_CONSTANT = NULL;

Keyword* KWD_READ_SYMBOL_OR_MANTISSA = NULL;

Keyword* KWD_READ_SYMBOL_OR_MANTISSA2 = NULL;

Keyword* KWD_READ_FLOAT = NULL;

Keyword* KWD_READ_SYMBOL_OR_EXPONENT_DELIMITER = NULL;

Keyword* KWD_READ_SYMBOL_OR_EXPONENT = NULL;

Keyword* KWD_READ_SYMBOL_OR_EXPONENT2 = NULL;

Keyword* KWD_READ_SYMBOL_OR_CL_SYMBOL2 = NULL;

Keyword* KWD_READ_SYMBOL_OR_CL_SYMBOL3 = NULL;

Keyword* KWD_READ_CL_SYMBOL = NULL;

Keyword* KWD_READ_ESCAPED_SYMBOL = NULL;

Keyword* KWD_READ_CLOSE_FULLY_ESCAPED_NAME = NULL;

Keyword* KWD_READ_FULLY_ESCAPED_SYMBOL_ESCAPE = NULL;

Keyword* KWD_READ_FULLY_ESCAPED_KEYWORD = NULL;

Keyword* KWD_READ_ESCAPED_KEYWORD_ESCAPE = NULL;

Keyword* KWD_READ_ESCAPED_KEYWORD = NULL;

Keyword* KWD_READ_FULLY_ESCAPED_KEYWORD_ESCAPE = NULL;

Keyword* KWD_READ_FULLY_ESCAPED_SURROGATE = NULL;

Keyword* KWD_READ_ESCAPED_SURROGATE_ESCAPE = NULL;

Keyword* KWD_READ_ESCAPED_SURROGATE = NULL;

Keyword* KWD_READ_FULLY_ESCAPED_SURROGATE_ESCAPE = NULL;

Keyword* KWD_READ_QUALIFIED_SURROGATE = NULL;

Keyword* KWD_READ_QUALIFIED_ESCAPED_SYMBOL_ESCAPE = NULL;

Keyword* KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL = NULL;

Keyword* KWD_READ_QUALIFIED_SYMBOL = NULL;

Keyword* KWD_READ_QUALIFIED_ESCAPED_SURROGATE_ESCAPE = NULL;

Keyword* KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE = NULL;

Keyword* KWD_READ_QUALIFIED_ESCAPED_SYMBOL = NULL;

Keyword* KWD_READ_QUALIFIED_ESCAPED_SURROGATE = NULL;

Keyword* KWD_READ_QUALIFIED_FULLY_ESCAPED_SYMBOL_ESCAPE = NULL;

Keyword* KWD_READ_QUALIFIED_FULLY_ESCAPED_SURROGATE_ESCAPE = NULL;

Keyword* KWD_READ_CLOSE_BALANCED_QUOTE = NULL;

Symbol* SYM_READ_STELLA_WITH_TOKENIZER = NULL;

Symbol* SYM_READ_STELLA_oSTELLA_TOKENIZER_TABLEo = NULL;

Symbol* SYM_READ_STELLA_TOK_STELLALOGICALSTATENAMES_ = NULL;

Symbol* SYM_READ_STELLA_oSTELLA_LOGICAL_STATE_NAMESo = NULL;

Symbol* SYM_READ_STELLA_TOK_STELLALOGICALSTATENAME_ = NULL;

Symbol* SYM_READ_STELLA_KEYWORD = NULL;

Keyword* KWD_READ_NONE = NULL;

Symbol* SYM_READ_STELLA_GET_QUALIFIED_SYMBOL_SEPARATOR_POSITION_INTERNAL = NULL;

Keyword* KWD_READ_FULLY_ESCAPED = NULL;

Surrogate* SGT_READ_STELLA_STELLA_TOKEN = NULL;

Symbol* SYM_READ_STELLA_LOGICAL_TOKEN_TYPE = NULL;

Symbol* SYM_READ_STELLA_MODULE = NULL;

Symbol* SYM_READ_STELLA_ESCAPE_MODE = NULL;

Keyword* KWD_READ_FULL = NULL;

Keyword* KWD_READ_PARTIAL = NULL;

Keyword* KWD_READ_ESCAPED = NULL;

Symbol* SYM_READ_STELLA_a = NULL;

Symbol* SYM_READ_STELLA_aa = NULL;

Keyword* KWD_READ_ASK = NULL;

Keyword* KWD_READ_YES = NULL;

Keyword* KWD_READ_NO = NULL;

Keyword* KWD_READ_YES_VERBOSE = NULL;

Keyword* KWD_READ_NO_VERBOSE = NULL;

Symbol* SYM_READ_STELLA_STARTUP_READ = NULL;

Symbol* SYM_READ_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace stella
