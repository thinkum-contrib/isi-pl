//  -*- Mode: C++ -*-

// primal.cc

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
+---------------------------- END LICENSE BLOCK -----------------------------+
*/

#include "stella/stella-system.hh"

namespace stella {

// Represents the boolean true truth value.
boolean TRUE = 1;

// Represents the boolean false truth value.
boolean FALSE = 0;

// A float approximation of the mathematical constant pi.
double PI = 3.141592653589793;

int NULL_INTEGER = 1 << (sizeof (int) / sizeof (char) * 8 - 1);

short int NULL_SHORT_INTEGER = 1 << (sizeof (short int) / sizeof (char) * 8 - 1);

long int NULL_LONG_INTEGER = 1 << (sizeof (long int) / sizeof (char) * 8 - 1);

unsigned short int NULL_UNSIGNED_SHORT_INTEGER = (unsigned short int) -1;

unsigned long int NULL_UNSIGNED_LONG_INTEGER = (unsigned long int) -1;

double NULL_FLOAT = -HUGE_VAL /* IEEE infinity, defined in <math.h> */;

float NULL_SINGLE_FLOAT = -HUGE_VAL /* IEEE infinity, defined in <math.h> */;

double NULL_DOUBLE_FLOAT = -HUGE_VAL /* IEEE infinity, defined in <math.h> */;

char NULL_CHARACTER = '\0';

char NULL_BYTE = 255;

char NULL_OCTET = 255;

boolean eqlP(Object* x, Object* y) {
  // Return true if `x' and `y' are `eq?' or equivalent literals
  // such as strings that also might be wrapped in non-identical wrappers.  For
  // the case where `x' or `y' are plain literals such as strings or integers, the
  // STELLA translator substitutes the equality test appropriate for the particular
  // target language and does not actually call this function.  For cases where
  // `x' or `y' are known to be of type STANDARD-OBJECT, the STELLA translator
  // substitutes the faster `eq?' test inline.
  return (((!((boolean)(x))) ? (!((boolean)(y))) : ((x == y) ||
      x->objectEqlP(y))));
}

boolean equalP(Object* x, Object* y) {
  // Return true if `x' and `y' are `eql?' or considered equal
  // by a user-defined `object-equal?' method.  This implements a fully extensible
  // equality test similar to Java's `equals' method.  Note that writers of custom
  // `object-equal?' methods must also implement a corresponding `equal-hash-code'
  // method.
  return (((!((boolean)(x))) ? (!((boolean)(y))) : ((x == y) ||
      x->objectEqualP(y))));
}

boolean Object::objectEqualP(Object* y) {
  // Return true if `x' and `y' are `eq?'.
  { Object* x = this;

    return (x == y);
  }
}

boolean Wrapper::objectEqualP(Object* y) {
  // Return true if `x' and `y' are literal wrappers whose
  // literals are considered `eql?'.
  { Wrapper* x = this;

    return (x->objectEqlP(y));
  }
}

boolean zeroP(int x) {
  // Return true if `x' is 0.
  return ((!x));
}

boolean plusP(int x) {
  // Return true if `x' is greater than 0.
  return ((x > 0));
}

boolean evenP(int x) {
  // Return true if `x' is an even number.
  return (!(x % 2));
}

boolean oddP(int x) {
  // Return true if `x' is an odd number.
  return ((x % 2));
}

int div(int x, int y) {
  // Return the integer quotient from dividing `x' by `y'.
  return ((x / y));
}

int rem(int x, int y) {
  // Return the remainder from dividing `x' by `y'.  The
  // sign of the result is always the same as the sign of `x'.  This has slightly
  // different behavior than the `mod' function, and has less overhead in C++ and
  // Java, which don't have direct support for a true modulus function.
  return ((x % y));
}

int mod(int x, int modulus) {
  // True modulus.  Return the result of `x' mod `modulo'.
  // Note: In C++ and Java, `mod' has more overhead than the similar
  // function `rem'.  The  answers returned by `mod' and `rem' are only
  // different when the signs of `x' and `modulo' are different.
  { int remainder = (x % modulus);

    if (remainder > 0) {
      if (modulus < 0) {
        remainder = modulus + remainder;
      }
    }
    else if (remainder < 0) {
      if (modulus > 0) {
        remainder = modulus + remainder;
      }
    }
    return (remainder);
  }
}

int gcd(int x, int y) {
  // Return the greatest common divisor of `x' and `y'.
  if (x < 0) {
    x = 0 - x;
  }
  if (y < 0) {
    y = 0 - y;
  }
  { int temp = 0;

    while (!(y == 0)) {
      temp = (x % y);
      x = y;
      y = temp;
    }
    return (x);
  }
}

int stella::random(int n) {
  // Generate a random integer in the interval [0..n-1].
  // `n' must be <= 2^15.
  if (n > 32768) {
    throw *newStellaException("random: Can only generate random numbers between 0 and (2^15)-1.");
  }
  { int rnum = abs(rand()) % n;

    return (rnum);
  }
}

void seedRandomNumberGenerator() {
  // Seeds the random number generator with the current time.
  srand(time(NULL));;
}

double stella::sqrt(double n) {
  // Return the square root of `n'.
  return (::sqrt(n));
}

double stella::cos(double n) {
  // Return the cosine of `n' radians.
  return (::cos(n));
}

double stella::sin(double n) {
  // Return the sine of `n' radians.
  return (::sin(n));
}

double stella::tan(double n) {
  // Return the tangent of `n' radians.
  return (::tan(n));
}

double stella::acos(double n) {
  // Return the arccosine of `n' in radians.
  return (::acos(n));
}

double stella::asin(double n) {
  // Return the arcsine of `n' in radians.
  return (::asin(n));
}

double stella::atan(double n) {
  // Return the arc tangent of `n' in radians.
  return (::atan(n));
}

double stella::atan2(double x, double y) {
  // Return the arc tangent of `x' / `y' in radians.
  return (::atan2(x,y));
}

// 1 / (log 10) Reciprocal of the Log base e of 10.
// Used for log 10 conversions.
double RECIPROCAL_NL10 = NULL_FLOAT;

double stella::log(double n) {
  // Return the natural logarithm (base e) of `n'.
  return (::log(n));
}

double log10(double n) {
  // Return the logarithm (base 10) of `n'.
  return (::log(n) * RECIPROCAL_NL10);
}

double stella::exp(double n) {
  // Return the e to the power `n'.
  return (::exp(n));
}

double expt(double x, double y) {
  // Return `x' ^ `y'.
  return (::pow(x,y));
}

int stella::min(int x, int y) {
  // Return the minimum of `x' and `y'.  If either is NULL, return the other.
  if (x == NULL_INTEGER) {
    return (y);
  }
  if (y == NULL_INTEGER) {
    return (x);
  }
  return (((x < y) ? x : y));
}

int stella::max(int x, int y) {
  // Return the maximum of `x' and `y'.  If either is NULL, return the other.
  if (x == NULL_INTEGER) {
    return (y);
  }
  if (y == NULL_INTEGER) {
    return (x);
  }
  return (((x > y) ? x : y));
}

int integerAbs(int x) {
  // Return the absolute value of `x'.
  return (((x < 0) ? (0 - x) : x));
}

double floatAbs(double x) {
  // Return the absolute value of `x'.
  return (((x < 0.0) ? (0.0 - x) : x));
}

int characterCode(char ch) {
  // Return the 8-bit ASCII code of `ch' as an integer.
  return ((int)(unsigned char) ch);
}

char codeCharacter(int code) {
  // Return the character encoded by `code' (0 <= `code' <= 255).
  return ((char) code);
}

char characterDowncase(char ch) {
  // If `ch' is lowercase, return its uppercase version,
  // otherwise, return 'ch' unmodified.
  return (oCHARACTER_DOWNCASE_TABLEo[((int)(unsigned char) ch)]);
}

char characterUpcase(char ch) {
  // If `ch' is uppercase, return its lowercase version,
  // otherwise, return 'ch' unmodified.  If only the first character of
  // a sequence of characters is to be capitalized, `character-capitalize'
  // should be used instead.
  return (oCHARACTER_UPCASE_TABLEo[((int)(unsigned char) ch)]);
}

char characterCapitalize(char ch) {
  // Return the capitalized character for `ch'.  This is generally the same
  // as the uppercase character, except for obscure non-English characters in Java.  It should
  // be used if only the first character of a sequence of characters is to be capitalized.
  return (oCHARACTER_UPCASE_TABLEo[((int)(unsigned char) ch)]);
}

DEFINE_STELLA_SPECIAL(oTRANSIENTOBJECTSpo, boolean , FALSE);

boolean stringEqlP(char* x, char* y) {
  // Return true if `x' and `y' are equal strings or are both undefined.  This
  // test is substituted automatically by the STELLA translator if `eql?' is applied
  // to strings.
  if (x == NULL) {
    return (y == NULL);
  }
  else {
    return ((y != NULL) &&
        !strcmp(x, y));
  }
}

boolean stringEqualP(char* x, char* y) {
  // Return true if `x' and `y' are equal strings ignoring character case or
  // are both undefined.
  if (x == NULL) {
    return (y == NULL);
  }
  else {
    return ((y != NULL) &&
        !strcasecmp(x, y));
  }
}

int stringCompare(char* x, char* y, boolean caseSensitiveP) {
  // Compare `x' and `y' lexicographically, and return -1, 0, 
  // or 1, depending on whether `x' is less than, equal, or greater than `y'.
  // If `case-sensitive?' is true, then case does matter for the comparison
  if (caseSensitiveP) {
    return (strcmp(x, y));
  }
  else {
    return (strcasecmp(x, y));
  }
}

boolean stringEmptyP(char* x) {
  // Return true if `x' is the empty string ""
  return (stringEqlP(x, ""));
}

boolean stringNonEmptyP(char* x) {
  // Return true if `x' is not the empty string ""
  return (!stringEqlP(x, ""));
}

boolean StringWrapper::emptyP() {
  // Return true if `x' is the wrapped empty string ""
  { StringWrapper* x = this;

    return (stringEqlP(x->wrapperValue, ""));
  }
}

boolean StringWrapper::nonEmptyP() {
  // Return true if `x' is not the wrapped empty string ""
  { StringWrapper* x = this;

    return (!stringEqlP(x->wrapperValue, ""));
  }
}

boolean stringL(char* x, char* y) {
  // Return true if `x' is lexicographically < `y', considering case.
  return (stringCompare(x, y, TRUE) < 0);
}

boolean stringLE(char* x, char* y) {
  // Return true if `x' is lexicographically <= `y', considering case.
  return (stringCompare(x, y, TRUE) <= 0);
}

boolean stringGE(char* x, char* y) {
  // Return true if `x' is lexicographically >= `y', considering case.
  return (stringCompare(x, y, TRUE) >= 0);
}

boolean stringG(char* x, char* y) {
  // Return true if `x' is lexicographically > `y', considering case.
  return (stringCompare(x, y, TRUE) > 0);
}

boolean stringLessP(char* x, char* y) {
  // Return true if `x' is lexicographically < `y', ignoring case.
  return (stringCompare(x, y, FALSE) < 0);
}

boolean stringLessEqualP(char* x, char* y) {
  // Return true if `x' is lexicographically <= `y', ignoring case.
  return (stringCompare(x, y, FALSE) <= 0);
}

boolean stringGreaterEqualP(char* x, char* y) {
  // Return true if `x' is lexicographically >= `y', ignoring case.
  return (stringCompare(x, y, FALSE) >= 0);
}

boolean stringGreaterP(char* x, char* y) {
  // Return true if `x' is lexicographically > `y', ignoring case.
  return (stringCompare(x, y, FALSE) > 0);
}

char* makeMutableString(int size, char initchar) {
  // Return a new mutable string filled with `size' `initchar's.
  return (makeString(size, initchar));
}

char* makeRawMutableString(int size) {
  // Return a new uninitialized mutable string of `size'.
  { char* s = NULL;

    s = new (GC) char[size+1]; s[size]='\0';
    return (s);
  }
}

char* stringConcatenate(char* string1, char* string2, int otherstrings, ...) {
  // Return a new string representing the concatenation
  // of `string1', `string2', and `otherStrings'.  The two mandatory parameters
  // allow us to optimize the common binary case by not relying on the somewhat
  // less efficient variable arguments mechanism.
  if (otherstrings == 0) {
    return (stringConcatenate(string1, string2));
  }
  { char* result = NULL;
    int length = strlen(string1) + strlen(string2);
    int index = 0;

    { char* string = NULL;
      va_list iter000;
      int iter000Count = otherstrings;

      va_start(iter000, otherstrings);
      while ((iter000Count--) > 0) {
        string = va_arg(iter000, char*);
        length = length + strlen(string);
      }
      va_end(iter000);
    }
    result = makeRawMutableString(length);
    { char ch = NULL_CHARACTER;
      char* vector000 = string1;
      int index000 = 0;
      int length000 = strlen(vector000);

      while (index000 < length000) {
        ch = vector000[index000];
        index000 = index000 + 1;
        result[index] = ch;
        index = index + 1;
      }
    }
    { char ch = NULL_CHARACTER;
      char* vector001 = string2;
      int index001 = 0;
      int length001 = strlen(vector001);

      while (index001 < length001) {
        ch = vector001[index001];
        index001 = index001 + 1;
        result[index] = ch;
        index = index + 1;
      }
    }
    { char* string = NULL;
      va_list iter001;
      int iter001Count = otherstrings;

      va_start(iter001, otherstrings);
      while ((iter001Count--) > 0) {
        string = va_arg(iter001, char*);
        { char ch = NULL_CHARACTER;
          char* vector002 = string;
          int index002 = 0;
          int length002 = strlen(vector002);

          while (index002 < length002) {
            ch = vector002[index002];
            index002 = index002 + 1;
            result[index] = ch;
            index = index + 1;
          }
        }
      }
      va_end(iter001);
    }
    return (result);
  }
}

char* helpSubstituteCharacters(char* self, char* newChars, char* oldChars) {
  { int pos = NULL_INTEGER;

    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = strlen(self) - 1;

      while (iter000 <= upperBound000) {
        i = iter000;
        iter000 = iter000 + 1;
        pos = stringPosition(oldChars, self[i], 0);
        if (pos != NULL_INTEGER) {
          self[i] = (newChars[pos]);
        }
      }
    }
    return (self);
  }
}

char* mutableStringSubstituteCharacters(char* self, char* newChars, char* oldChars) {
  // Substitute all occurences of of a member of `old-chars' with the 
  // corresponding member of `new-chars' in the string `self'.  IMPORTANT:  The return
  // value should be used instead of relying on destructive substitution, since the
  // substitution will not be destructive in all translated languages.
  return (helpSubstituteCharacters(self, newChars, oldChars));
}

char* stringSubstituteCharacters(char* self, char* newChars, char* oldChars) {
  // Substitute all occurences of of a member of `old-chars' with the 
  // corresponding member of `new-chars' in the string `self'.  Returns a new string.
  return ((helpSubstituteCharacters(strcpy(new (GC) char[strlen(self)+1], self), newChars, oldChars)));
}

char* replaceSubstrings(char* string, char* neW, char* old) {
  // Replace all occurrences of `old' in `string' with `new'.
  { int stringlength = strlen(string);
    int oldlength = strlen(old);
    int newlength = strlen(neW);
    int nofoccurrences = 0;
    int oldstart = 0;
    int cursor = 0;
    int resultcursor = 0;
    char* result = NULL;

    while ((oldstart = stringSearch(string, old, cursor)) != NULL_INTEGER) {
      nofoccurrences = nofoccurrences + 1;
      cursor = oldstart + oldlength;
    }
    if (nofoccurrences == 0) {
      return (string);
    }
    result = makeRawMutableString(stringlength + (nofoccurrences * (newlength - oldlength)));
    cursor = 0;
    while ((oldstart = stringSearch(string, old, cursor)) != NULL_INTEGER) {
      { int i = NULL_INTEGER;
        int iter000 = cursor;
        int upperBound000 = oldstart - 1;

        while (iter000 <= upperBound000) {
          i = iter000;
          iter000 = iter000 + 1;
          result[resultcursor] = (string[i]);
          resultcursor = resultcursor + 1;
        }
      }
      { char chaR = NULL_CHARACTER;
        char* vector000 = neW;
        int index000 = 0;
        int length000 = strlen(vector000);

        while (index000 < length000) {
          chaR = vector000[index000];
          index000 = index000 + 1;
          result[resultcursor] = chaR;
          resultcursor = resultcursor + 1;
        }
      }
      cursor = oldstart + oldlength;
    }
    { int i = NULL_INTEGER;
      int iter001 = cursor;
      int upperBound001 = stringlength - 1;

      while (iter001 <= upperBound001) {
        i = iter001;
        iter001 = iter001 + 1;
        result[resultcursor] = (string[i]);
        resultcursor = resultcursor + 1;
      }
    }
    return (result);
  }
}

int insertString(char* source, int start, int end, char* target, int targetIndex, Keyword* caseConversion) {
  // Inserts characters from `source' begining at `start' and
  // ending at `end' into `target' starting at `target-index'.  If `end' is `null',
  // then the entire length of the string is used. The copy of characters is affected
  // by the `case-conversion' keyword which should be one of
  //    :UPCASE :DOWNCASE :CAPITALIZE :PRESERVE.
  // 
  // The final value of target-index is returned.
  if (end == NULL_INTEGER) {
    end = strlen(source) - 1;
  }
  if (end < start) {
    return (targetIndex);
  }
  if (caseConversion == KWD_PRIMAL_UPCASE) {
    { int j = NULL_INTEGER;
      int iter000 = start;
      int upperBound000 = end;
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;

      while (unboundedP000 ||
          (iter000 <= upperBound000)) {
        j = iter000;
        iter000 = iter000 + 1;
        target[targetIndex] = (oCHARACTER_UPCASE_TABLEo[((int)(unsigned char) (source[j]))]);
        targetIndex = targetIndex + 1;
      }
    }
  }
  else if (caseConversion == KWD_PRIMAL_DOWNCASE) {
    { int j = NULL_INTEGER;
      int iter001 = start;
      int upperBound001 = end;
      boolean unboundedP001 = upperBound001 == NULL_INTEGER;

      while (unboundedP001 ||
          (iter001 <= upperBound001)) {
        j = iter001;
        iter001 = iter001 + 1;
        target[targetIndex] = (oCHARACTER_DOWNCASE_TABLEo[((int)(unsigned char) (source[j]))]);
        targetIndex = targetIndex + 1;
      }
    }
  }
  else if (caseConversion == KWD_PRIMAL_CAPITALIZE) {
    target[targetIndex] = (oCHARACTER_UPCASE_TABLEo[((int)(unsigned char) (source[start]))]);
    targetIndex = targetIndex + 1;
    { int j = NULL_INTEGER;
      int iter002 = start + 1;
      int upperBound002 = end;
      boolean unboundedP002 = upperBound002 == NULL_INTEGER;

      while (unboundedP002 ||
          (iter002 <= upperBound002)) {
        j = iter002;
        iter002 = iter002 + 1;
        target[targetIndex] = (oCHARACTER_DOWNCASE_TABLEo[((int)(unsigned char) (source[j]))]);
        targetIndex = targetIndex + 1;
      }
    }
  }
  else if (caseConversion == KWD_PRIMAL_PRESERVE) {
    { int j = NULL_INTEGER;
      int iter003 = start;
      int upperBound003 = end;
      boolean unboundedP003 = upperBound003 == NULL_INTEGER;

      while (unboundedP003 ||
          (iter003 <= upperBound003)) {
        j = iter003;
        iter003 = iter003 + 1;
        target[targetIndex] = (source[j]);
        targetIndex = targetIndex + 1;
      }
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << caseConversion << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (targetIndex);
}

char* characterToString(char c) {
  // Convert `c' into a one-element string and return the result.
  return (makeString(1, c));
}

char* formatWithPadding(char* input, int length, char padchar, Keyword* align, boolean truncateP) {
  // Formats `input' to be (at least) `length' long, using `padchar' to
  // fill if necessary.  `align' must be one of :LEFT, :RIGHT, :CENTER and will control
  // how `input' will be justified in the resulting string.  If `truncate?' is true, then
  // then an overlength string will be truncated, using the opposite of `align' to pick
  // the truncation direction.
  { int len = strlen(input);

    if (len == length) {
      return (input);
    }
    else if (len > length) {
      if (truncateP) {
        if (align == KWD_PRIMAL_LEFT) {
          return (stringSubsequence(input, len - length, len));
        }
        else if (align == KWD_PRIMAL_RIGHT) {
          return (stringSubsequence(input, 0, len - length));
        }
        else if (align == KWD_PRIMAL_CENTER) {
          { int left = ((int)((len - length) / 2.0));

            return (stringSubsequence(input, left, left + length));
          }
        }
        else {
          { OutputStringStream* stream000 = newOutputStringStream();

            *(stream000->nativeStream) << "`" << align << "'" << " is not a valid case option";
            throw *newStellaException(stream000->theStringReader());
          }
        }
      }
      else {
        return (input);
      }
    }
    else {
      if (align == KWD_PRIMAL_LEFT) {
        return (stringConcatenate(input, makeString(length - len, padchar), 0));
      }
      else if (align == KWD_PRIMAL_RIGHT) {
        return (stringConcatenate(makeString(length - len, padchar), input, 0));
      }
      else if (align == KWD_PRIMAL_CENTER) {
        { int left = ((int)((length - len) / 2.0));

          return (stringConcatenate(makeString(left, padchar), input, 1, makeString((length - len) - left, padchar)));
        }
      }
      else {
        { OutputStringStream* stream001 = newOutputStringStream();

          *(stream001->nativeStream) << "`" << align << "'" << " is not a valid case option";
          throw *newStellaException(stream001->theStringReader());
        }
      }
    }
  }
}

char stringFirst(char* self) {
  // Return the first character of `self'.
  return (self[0]);
}

char mutableStringFirst(char* self) {
  // Return the first character of `self' (settable via `setf').
  return (self[0]);
}

char mutableStringFirstSetter(char* self, char ch) {
  // Set the first character of `self' to `ch' and return `ch'.
  return (self[0] = ch);
}

char stringSecond(char* self) {
  // Return the second character of `self'.
  return (self[1]);
}

char mutableStringSecond(char* self) {
  // Return the second character of `self' (settable via `setf').
  return (self[1]);
}

char mutableStringSecondSetter(char* self, char ch) {
  // Set the second character of `self' to `ch' and return `ch'.
  return (self[1] = ch);
}

char stringThird(char* self) {
  // Return the third character of `self'.
  return (self[2]);
}

char mutableStringThird(char* self) {
  // Return the third character of `self' (settable via `setf').
  return (self[2]);
}

char mutableStringThirdSetter(char* self, char ch) {
  // Set the third character of `self' to `ch' and return `ch'.
  return (self[2] = ch);
}

char stringFourth(char* self) {
  // Return the fourth character of `self'.
  return (self[3]);
}

char mutableStringFourth(char* self) {
  // Return the fourth character of `self' (settable via `setf').
  return (self[3]);
}

char mutableStringFourthSetter(char* self, char ch) {
  // Set the fourth character of `self' to `ch' and return `ch'.
  return (self[3] = ch);
}

char stringFifth(char* self) {
  // Return the fifth character of `self'.
  return (self[4]);
}

char mutableStringFifth(char* self) {
  // Return the fifth character of `self' (settable via `setf').
  return (self[4]);
}

char mutableStringFifthSetter(char* self, char ch) {
  // Set the fifth character of `self' to `ch' and return `ch'.
  return (self[4] = ch);
}

char stringNth(char* self, int position) {
  // Return the character in `self' at `position'.
  return (self[position]);
}

char mutableStringNth(char* self, int position) {
  // Return the character in `self' at `position'.
  return (self[position]);
}

char mutableStringNthSetter(char* self, char ch, int position) {
  // Set the character in `self' at `position' to `ch'.
  return (self[position] = ch);
}

int stringLength(char* self) {
  // Return the length of the string `self'.
  return (strlen(self));
}

int mutableStringLength(char* self) {
  // Return the length of the string `self'.
  return (strlen(self));
}

Object* unstringify(char* string) {
  // Read a STELLA expression from `string' and return the result.
  // This is identical to `read-s-expression-from-string'.
  return (readSExpressionFromString(string));
}

# include "stella/cpp-lib/cpp-hashtable.hh"
void AbstractHashTable::freeHashTableValues() {
  // Call free on each value in the hash table `self'.
  { AbstractHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      return;
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      std::cout << "WARNING: freeHashTableValues not yet implemented" << std::endl;;
    }
  }
}

void AbstractHashTable::initializeHashTable() {
  // Insert a newly-created native hash table into `self'.
  { AbstractHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      self->theStellaHashTable = newStellaHashTable();
      return;
    }
    self->theHashTable = (cpp_hash_table*)(new Native_EQL_Hash_Table<Object*, Object*>);
  }
}

Object* HashTable::lookup(Object* key) {
  { HashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      return (stellaHashTableLookup(self->theStellaHashTable, key));
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      return (((Native_EQL_Hash_Table<Object*, Object*>*)nativeTable)->get(key));
    }
  }
}

void HashTable::insertAt(Object* key, Object* value) {
  { HashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      stellaHashTableInsertAt(self->theStellaHashTable, key, value);
      return;
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      (*((Native_EQL_Hash_Table<Object*, Object*>*)nativeTable))[key] = value;;
    }
  }
}

void HashTable::removeAt(Object* key) {
  { HashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      stellaHashTableRemoveAt(self->theStellaHashTable, key);
      return;
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      ((Native_EQL_Hash_Table<Object*, Object*>*)nativeTable)->erase(key);;
    }
  }
}

void IntegerHashTable::initializeHashTable() {
  // Insert a newly-created native hash table into `self'.
  { IntegerHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      self->theStellaHashTable = newStellaHashTable();
      return;
    }
    self->theHashTable = ((cpp_hash_table*)(new Native_EQL_Hash_Table<int, Object*>));
  }
}

Object* IntegerHashTable::lookup(int key) {
  { IntegerHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      return (stellaHashTableLookup(self->theStellaHashTable, wrapInteger(key)));
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      return (((Native_EQL_Hash_Table<int, Object*>*)nativeTable)->get(key));
    }
  }
}

void IntegerHashTable::insertAt(int key, Object* value) {
  { IntegerHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      stellaHashTableInsertAt(self->theStellaHashTable, wrapInteger(key), value);
      return;
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      (*((Native_EQL_Hash_Table<int, Object*>*)nativeTable))[key] = value;;
    }
  }
}

void IntegerHashTable::removeAt(int key) {
  { IntegerHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      stellaHashTableRemoveAt(self->theStellaHashTable, wrapInteger(key));
      return;
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      ((Native_EQL_Hash_Table<int, Object*>*)nativeTable)->erase(key);;
    }
  }
}

void FloatHashTable::initializeHashTable() {
  // Insert a newly-created native hash table into `self'.
  { FloatHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      self->theStellaHashTable = newStellaHashTable();
      return;
    }
    self->theHashTable = (cpp_hash_table*)(new Native_EQL_Hash_Table<double, Object*>);
  }
}

Object* FloatHashTable::lookup(double key) {
  { FloatHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      return (stellaHashTableLookup(self->theStellaHashTable, wrapFloat(key)));
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      return (((Native_EQL_Hash_Table<double, Object*>*)nativeTable)->get(key));
    }
  }
}

void FloatHashTable::insertAt(double key, Object* value) {
  { FloatHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      stellaHashTableInsertAt(self->theStellaHashTable, wrapFloat(key), value);
      return;
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      (*((Native_EQL_Hash_Table<double, Object*>*)nativeTable))[key] = value;;
    }
  }
}

void FloatHashTable::removeAt(double key) {
  { FloatHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      stellaHashTableRemoveAt(self->theStellaHashTable, wrapFloat(key));
      return;
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      ((Native_EQL_Hash_Table<double, Object*>*)nativeTable)->erase(key);;
    }
  }
}

void StringHashTable::initializeHashTable() {
  // Insert a newly-created native hash table into `self'.
  { StringHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      self->theStellaHashTable = newStellaHashTable();
      return;
    }
    self->theHashTable = (cpp_hash_table*)(new Native_EQL_Hash_Table<char*, Object*>);
  }
}

Object* StringHashTable::lookup(char* key) {
  { StringHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      return (stellaStringHashTableLookup(self->theStellaHashTable, key));
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      return (((Native_EQL_Hash_Table<char*, Object*>*)nativeTable)->get(key));
    }
  }
}

void StringHashTable::insertAt(char* key, Object* value) {
  { StringHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      stellaHashTableInsertAt(self->theStellaHashTable, wrapString(key), value);
      return;
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      (*((Native_EQL_Hash_Table<char*, Object*>*)nativeTable))[key] = value;;
    }
  }
}

void StringHashTable::removeAt(char* key) {
  { StringHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      stellaHashTableRemoveAt(self->theStellaHashTable, wrapString(key));
      return;
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      ((Native_EQL_Hash_Table<char*, Object*>*)nativeTable)->erase(key);;
    }
  }
}

void StringToIntegerHashTable::initializeHashTable() {
  // Insert a newly-created native hash table into `self'.
  { StringToIntegerHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      self->theStellaHashTable = newStellaHashTable();
      return;
    }
    self->theHashTable = (cpp_hash_table*)(new Native_EQL_Hash_Table<char*, int>(NULL_INTEGER));
  }
}

int StringToIntegerHashTable::lookup(char* key) {
  { StringToIntegerHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      return (unwrapInteger(((IntegerWrapper*)(stellaStringHashTableLookup(self->theStellaHashTable, key)))));
    }
    { cpp_hash_table* nativeTable = self->theHashTable;
      int result = NULL_INTEGER;

      result = ((Native_EQL_Hash_Table<char*, int>*)nativeTable)->get(key);
      return (result);
    }
  }
}

void StringToIntegerHashTable::insertAt(char* key, int value) {
  { StringToIntegerHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      stellaHashTableInsertAt(self->theStellaHashTable, wrapString(key), wrapInteger(value));
      return;
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      (*((Native_EQL_Hash_Table<char*, int>*)nativeTable))[key] = value;;
    }
  }
}

void StringToIntegerHashTable::removeAt(char* key) {
  { StringToIntegerHashTable* self = this;

    if (oUSE_STELLA_HASH_TABLESpo) {
      stellaHashTableRemoveAt(self->theStellaHashTable, wrapString(key));
      return;
    }
    { cpp_hash_table* nativeTable = self->theHashTable;

      ((Native_EQL_Hash_Table<char*, int>*)nativeTable)->erase(key);;
    }
  }
}

// A table of 256 26-bit random numbers that can be used to
// hash sequences of bytes.  Each bit-column in the table has an approximately
// even number of 0's and 1's.
int* oHASH_BYTE_RANDOM_TABLEo = NULL;

// The most significant bit of a regular integer (FIXNUM
// in Common-Lisp).  In C++ and Java this corresponds to the sign bit, in
// Lisp this corresponds to the left-most bit of `CL:most-positive-fixnum'.
int oINTEGER_MSB_MASKo = 1 << (sizeof (int) / sizeof (char) * 8 - 1);

// Mask that covers all the unsigned bits of an integer.
int oINTEGER_UNSIGNED_BITS_MASKo = (~ oINTEGER_MSB_MASKo);

int hashmod(int code, int size) {
  // Map the hash code `code' onto a bucket index for a hash table
  // of `size' (i.e., onto the interval [0..size-1].  This is just like `rem' for
  // positive hash codes but also works for negative hash codes by mapping those
  // onto a positive number first.  Note, that the sign conversion mapping is not
  // equivalent to calling the `abs' function (it simply masks the sign bit for
  // speed) and therefore really only makes sense for hash codes.
  return ((((unsigned int) code) % size));
}

int rotateHashCode(int arg) {
  // Rotate `arg' to the right by 1 position.  This means shift `arg' to the right
  // by one and feed in `arg's bit zero from the left.  In Lisp the result will stay
  // in positive FIXNUM range.  In C++ and Java this might return a negative
  // value which might be equal to NULL-INTEGER.  Important: to make this inlinable,
  // it must be called with an atom (i.e., constant or variable) as its argument.
  // This function is primarily useful for hashing sequences of items where the hash
  // code should take the sequential order of elements into account (e.g., lists).
  return ((((arg & 1) == 0) ? ((unsigned int)arg >> 1) : (((arg >> 1)) | oINTEGER_MSB_MASKo)));
}

int objectHashCode(Object* self) {
  // Return a hash code for `self' (can be negative).  Two objects that are `eq?'
  // are guaranteed to generate the same hash code.  Two objects that are not `eq?'
  // do not necessarily generate different hash codes.  Similar to `hash-code' but
  // always hashes on the address of `self' even if it is a wrapper.
  return ((size_t)self);
}

int Object::hashCode() {
  // Return a hash code for `self' (can be negative).  Two objects that are `eql?'
  // are guaranteed to generate the same hash code.  Two objects that are not `eql?'
  // do not necessarily generate different hash codes.
  { Object* self = this;

    return ((size_t)self);
  }
}

int safeHashCode(Object* self) {
  // Return a hash code for `self'.  Just like `hash-code'
  // - which see, but also works for NULL.
  if (!((boolean)(self))) {
    return (63842277);
  }
  else {
    return (self->hashCode());
  }
}

int StandardObject::hashCode() {
  { StandardObject* self = this;

    return ((size_t)self);
  }
}

int Wrapper::hashCode() {
  { Wrapper* self = this;

    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "WRAPPER.hash-code: Don't know how to hash on " << "`" << self << "'";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

int StringWrapper::hashCode() {
  { StringWrapper* self = this;

    return (native_hash_string((self->wrapperValue)));
  }
}

int IntegerWrapper::hashCode() {
  { IntegerWrapper* self = this;

    return (self->wrapperValue);
  }
}

int FloatWrapper::hashCode() {
  { FloatWrapper* self = this;

    return ((size_t)(self->wrapperValue));
  }
}

int CharacterWrapper::hashCode() {
  { CharacterWrapper* self = this;

    return (((oHASH_BYTE_RANDOM_TABLEo[(int)(unsigned char) (self->wrapperValue)]) ^ 33485726));
  }
}

int BooleanWrapper::hashCode() {
  { BooleanWrapper* self = this;

    return ((self->wrapperValue ? 27333705 : 31891526));
  }
}

int stringHashCode(char* self) {
  return (native_hash_string(self));
}

int integerHashCode(int self) {
  return (self);
}

int floatHashCode(double self) {
  return ((size_t)self);
}

int characterHashCode(char self) {
  return (((oHASH_BYTE_RANDOM_TABLEo[(int)(unsigned char) self]) ^ 33485726));
}

int Object::equalHashCode() {
  // Return a hash code for `self' (can be negative).  Two objects that are `equal?'
  // are guaranteed to generate the same hash code (provided, that writers of
  // `object-equal?' methods also implemented the appropriate `equal-hash-code'
  // method).  Two objects that are not `equal?'do not necessarily generate different
  // hash codes.
  { Object* self = this;

    return (self->hashCode());
  }
}

int safeEqualHashCode(Object* self) {
  // Return a hash code for `self'.  Just like `equal-hash-code'
  // - which see, but also works for NULL.  `equal-hash-code' methods that expect to
  // handle NULL components should use this function for recursive calls.
  if (!((boolean)(self))) {
    return (63842277);
  }
  else {
    return (self->equalHashCode());
  }
}

int hashString(char* string, int seedcode) {
  // Generate a hash-code for `string' and return it.
  // Two strings that are equal but not eq will generate the same code.
  // The hash-code is based on `seedCode' which usually will be 0.  However,
  // `seedCode' can also be used to supply the result of a previous hash
  // operation to achieve hashing on sequences of strings without actually
  // having to concatenate them.
  { int code = seedcode;
    int cursor = strlen(string);

    if (cursor == 0) {
      return (4303803);
    }
    else {
      cursor = cursor - 1;
    }
    for (;;) {
      code = (code ^ (oHASH_BYTE_RANDOM_TABLEo[(int)(unsigned char) (string[cursor])]));
      if (cursor == 0) {
        break;
      }
      else {
        cursor = cursor - 1;
      }
      code = (((code & 1) == 0) ? ((unsigned int)code >> 1) : (((code >> 1)) | oINTEGER_MSB_MASKo));
    }
    return (code);
  }
}

// List of prime numbers approximately growing by a factor of 2
// that are suitable to be used as hash table sizes.
Vector* oHASH_TABLE_SIZE_PRIMESo = NULL;

int pickHashTableSizePrime(int minsize) {
  // Return a hash table prime of at least `minSize'.
  { IntegerWrapper* prime = NULL;
    Vector* vector000 = oHASH_TABLE_SIZE_PRIMESo;
    int index000 = 0;
    int length000 = vector000->length();

    while (index000 < length000) {
      prime = ((IntegerWrapper*)((vector000->theArray)[index000]));
      index000 = index000 + 1;
      if (prime->wrapperValue >= minsize) {
        return (prime->wrapperValue);
      }
    }
  }
  throw *newStellaException("pick-hash-table-size-prime: minimum size is too large");
}

void Vector::initializeVector() {
  { Vector* self = this;

    { int size = self->arraySize;

      self->theArray = new (GC) Object*[size];
      { Object** array = self->theArray;

        { int i = NULL_INTEGER;
          int iter000 = 0;
          int upperBound000 = size - 1;

          while (iter000 <= upperBound000) {
            i = iter000;
            iter000 = iter000 + 1;
            array[i] = NULL;
          }
        }
      }
    }
  }
}

void resizeVector(Vector* self, int size) {
  // Change the size of `self' to `size'.  If `size' is smaller
  // than the current size of `self' the vector will be truncated.  Otherwise, 
  // the internal array of `self' will be grown to `size' and unused elements
  // will be initialized to NULL.
  { int old_size = self->arraySize;
    int i = old_size;
    Object** old_array = self->theArray;
    Object** new_array = old_array;

    if (size == old_size) {
      return;
    }
    new_array = new (GC) Object*[size];
    if (size < old_size) {
      old_size = size;
      i = old_size;
    }
    while ((i = i - 1) >= 0) {
      new_array[i] = (old_array[i]);
    }
    { int i = NULL_INTEGER;
      int iter000 = old_size;
      int upperBound000 = size - 1;

      while (iter000 <= upperBound000) {
        i = iter000;
        iter000 = iter000 + 1;
        new_array[i] = NULL;
      }
    }
    self->theArray = new_array;
    self->arraySize = size;
  }
}

Object* nativeVectorNth(Object** self, int position) {
  // Return the element in `self' at `position'.
  return (self[position]);
}

Object* nativeVectorNthSetter(Object** self, Object* value, int position) {
  // Set the element in `self' at `position' to `value'.
  return (self[position] = value);
}

void unmake(Object* self) {
  self = self;
}

void copyFile(char* fromfile, char* tofile) {
  // Copy file `fromFile' to file `toFile', clobbering
  // any data already in `toFile'.
  if (!probeFileP(fromfile)) {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "Can't copy non-existent file: " << "`" << fromfile << "'" << std::endl;
      throw *newStellaException(stream000->theStringReader());
    }
  }
  { InputFileStream* from = NULL;

    try {
      from = newInputFileStream(fromfile);
      { OutputFileStream* to = NULL;

        try {
          to = newOutputFileStream(tofile);
          { char* buffer = new (GC) char[oTOKENIZER_INITIAL_BUFFER_SIZEo];
            int bytesRead = 0;

            for (;;) {
              bytesRead = byteArrayReadSequence(buffer, from->nativeStream, 0, oTOKENIZER_INITIAL_BUFFER_SIZEo);
              if (bytesRead > 0) {
                byteArrayWriteSequence(buffer, to->nativeStream, 0, bytesRead);
              }
              else {
                break;
              }
            }
          }
        }
catch (...) {
          if (((boolean)(to))) {
            to->free();
          }
          throw;
        }
        if (((boolean)(to))) {
          to->free();
        }
      }
    }
catch (...) {
      if (((boolean)(from))) {
        from->free();
      }
      throw;
    }
    if (((boolean)(from))) {
      from->free();
    }
  }
}

int lognot(int arg) {
  return ((~ arg));
}

int logand(int arg1, int arg2) {
  return ((arg1 & arg2));
}

int logor(int arg1, int arg2) {
  return ((arg1 | arg2));
}

int logxor(int arg1, int arg2) {
  return ((arg1 ^ arg2));
}

int shiftLeft(int arg, int count) {
  return ((arg << count));
}

int shiftRight(int arg, int count) {
  // Shift `arg' to the right by `count' positions and
  // 0-extend from the left if `arg' is positive or 1-extend if it is
  // negative.  This is an arithmetic shift that preserve the sign of `arg'
  // and is equivalent to dividing `arg' by 2** `count'.
  return ((arg >> count));
}

int unsignedShiftRightBy1(int arg) {
  // Shift `arg' to the right by 1 position and 0-extend
  // from the left.  This does not preserve the sign of `arg' and shifts
  // the sign-bit just like a regular bit.  In Common-Lisp we can't do that
  // directly and need to do some extra masking.
  return (((unsigned int)arg >> 1));
}

Object* stellify(Object* self) {
  // Convert a Lisp object into a STELLA object.
  { Object* result = self;

    return (result);
  }
}

boolean stellaObjectP(Object* self) {
  // Return true if `self' is a member of the STELLA class `OBJECT'.
  { boolean resultP = TRUE;

    return (resultP);
  }
}

boolean runningAsLispP() {
  // Return true if the executable code is a Common Lisp application.
  { boolean resultP = FALSE;

    return (resultP);
  }
}

void stella::sleep(double seconds) {
  // The program will sleep for the indicated number of seconds.
  // Fractional values are allowed, but the results are implementation dependent:
  // Common Lisp uses the fractions natively, Java with a resolution of 0.001,
  // and C++ can only use integral values.
  sleep((unsigned int)seconds);
}

char* exceptionMessage(std::exception* e) {
  // Accesses the error message of the exception `e'.
  return ((char*)e->what());
}

void printExceptionContext(std::exception* e, OutputStream* stream) {
  // Prints a system dependent information about the context of the specified
  // exception.  For example, in Java it prints a stack trace.  In Lisp, it is vendor dependent.
  { std::ostream* s = stream->nativeStream;

    *(stream->nativeStream) << "No exception context available" << std::endl;
  }
}

char* makeProcessLock() {
  return (NULL);
}

// Process lock object for bootstrap use.
char* oBOOTSTRAP_LOCKo = NULL;

void helpStartupPrimal1() {
  {
    SYM_PRIMAL_STELLA_FLOOR = ((Symbol*)(internRigidSymbolWrtModule("FLOOR", NULL, 0)));
    KWD_PRIMAL_CPP = ((Keyword*)(internRigidSymbolWrtModule("CPP", NULL, 2)));
    KWD_PRIMAL_FUNCTION = ((Keyword*)(internRigidSymbolWrtModule("FUNCTION", NULL, 2)));
    SYM_PRIMAL_STELLA_ROUND = ((Symbol*)(internRigidSymbolWrtModule("ROUND", NULL, 0)));
    SYM_PRIMAL_STELLA_RANDOM = ((Symbol*)(internRigidSymbolWrtModule("RANDOM", NULL, 0)));
    SYM_PRIMAL_STELLA_SQRT = ((Symbol*)(internRigidSymbolWrtModule("SQRT", NULL, 0)));
    SYM_PRIMAL_STELLA_COS = ((Symbol*)(internRigidSymbolWrtModule("COS", NULL, 0)));
    SYM_PRIMAL_STELLA_SIN = ((Symbol*)(internRigidSymbolWrtModule("SIN", NULL, 0)));
    SYM_PRIMAL_STELLA_TAN = ((Symbol*)(internRigidSymbolWrtModule("TAN", NULL, 0)));
    SYM_PRIMAL_STELLA_ACOS = ((Symbol*)(internRigidSymbolWrtModule("ACOS", NULL, 0)));
    SYM_PRIMAL_STELLA_ASIN = ((Symbol*)(internRigidSymbolWrtModule("ASIN", NULL, 0)));
    SYM_PRIMAL_STELLA_ATAN = ((Symbol*)(internRigidSymbolWrtModule("ATAN", NULL, 0)));
    SYM_PRIMAL_STELLA_ATAN2 = ((Symbol*)(internRigidSymbolWrtModule("ATAN2", NULL, 0)));
    SYM_PRIMAL_STELLA_EXP = ((Symbol*)(internRigidSymbolWrtModule("EXP", NULL, 0)));
    SYM_PRIMAL_STELLA_LOG = ((Symbol*)(internRigidSymbolWrtModule("LOG", NULL, 0)));
    SYM_PRIMAL_STELLA_MIN = ((Symbol*)(internRigidSymbolWrtModule("MIN", NULL, 0)));
    SYM_PRIMAL_STELLA_MAX = ((Symbol*)(internRigidSymbolWrtModule("MAX", NULL, 0)));
    KWD_PRIMAL_UPCASE = ((Keyword*)(internRigidSymbolWrtModule("UPCASE", NULL, 2)));
    KWD_PRIMAL_DOWNCASE = ((Keyword*)(internRigidSymbolWrtModule("DOWNCASE", NULL, 2)));
    KWD_PRIMAL_CAPITALIZE = ((Keyword*)(internRigidSymbolWrtModule("CAPITALIZE", NULL, 2)));
    KWD_PRIMAL_PRESERVE = ((Keyword*)(internRigidSymbolWrtModule("PRESERVE", NULL, 2)));
    KWD_PRIMAL_LEFT = ((Keyword*)(internRigidSymbolWrtModule("LEFT", NULL, 2)));
    KWD_PRIMAL_RIGHT = ((Keyword*)(internRigidSymbolWrtModule("RIGHT", NULL, 2)));
    KWD_PRIMAL_CENTER = ((Keyword*)(internRigidSymbolWrtModule("CENTER", NULL, 2)));
    SYM_PRIMAL_STELLA_HASH_CODE = ((Symbol*)(internRigidSymbolWrtModule("HASH-CODE", NULL, 0)));
    KWD_PRIMAL_JAVA = ((Keyword*)(internRigidSymbolWrtModule("JAVA", NULL, 2)));
    SYM_PRIMAL_STELLA_SLEEP = ((Symbol*)(internRigidSymbolWrtModule("SLEEP", NULL, 0)));
    SYM_PRIMAL_STELLA_STARTUP_PRIMAL = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-PRIMAL", NULL, 0)));
    SYM_PRIMAL_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", NULL, 0)));
  }
}

void helpStartupPrimal2() {
  {
    defineMethodObject("(DEFMETHOD (NULL? BOOLEAN) ((X UNKNOWN)) :DOCUMENTATION \"Return true if `x' is undefined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NULL? BOOLEAN) ((X OBJECT)) :DOCUMENTATION \"Return true if `x' is undefined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NULL? BOOLEAN) ((X SECOND-CLASS-OBJECT)) :DOCUMENTATION \"Return true if `x' is undefined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NULL? BOOLEAN) ((X NATIVE-VECTOR)) :DOCUMENTATION \"Return true if `x' is undefined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NULL? BOOLEAN) ((X STRING)) :DOCUMENTATION \"Return true if `x' is undefined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NULL? BOOLEAN) ((X MUTABLE-STRING)) :DOCUMENTATION \"Return true if `x' is undefined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NULL? BOOLEAN) ((X CHARACTER)) :DOCUMENTATION \"Return true if `x' is undefined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NULL? BOOLEAN) ((X CODE)) :DOCUMENTATION \"Return true if `x' is undefined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NULL? BOOLEAN) ((X INTEGER)) :DOCUMENTATION \"Return true if `x' is undefined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NULL? BOOLEAN) ((X FLOAT)) :DOCUMENTATION \"Return true if `x' is undefined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DEFINED? BOOLEAN) ((X UNKNOWN)) :DOCUMENTATION \"Return true if `x' is defined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DEFINED? BOOLEAN) ((X OBJECT)) :DOCUMENTATION \"Return true if `x' is defined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DEFINED? BOOLEAN) ((X SECOND-CLASS-OBJECT)) :DOCUMENTATION \"Return true if `x' is defined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DEFINED? BOOLEAN) ((X NATIVE-VECTOR)) :DOCUMENTATION \"Return true if `x' is defined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DEFINED? BOOLEAN) ((X STRING)) :DOCUMENTATION \"Return true if `x' is defined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DEFINED? BOOLEAN) ((X MUTABLE-STRING)) :DOCUMENTATION \"Return true if `x' is defined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DEFINED? BOOLEAN) ((X CHARACTER)) :DOCUMENTATION \"Return true if `x' is defined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DEFINED? BOOLEAN) ((X CODE)) :DOCUMENTATION \"Return true if `x' is defined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DEFINED? BOOLEAN) ((X INTEGER)) :DOCUMENTATION \"Return true if `x' is defined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DEFINED? BOOLEAN) ((X FLOAT)) :DOCUMENTATION \"Return true if `x' is defined (handled specially by all translators).\" :PUBLIC? TRUE :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineFunctionObject("EQ?", "(DEFUN (EQ? BOOLEAN) ((X UNKNOWN) (Y UNKNOWN)) :DOCUMENTATION \"Return true if `x' and `y' are literally the same object (or\nsimple number).  Analogue to the Common Lisp EQL and C++ and Java's ==.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
    defineFunctionObject("=", "(DEFUN (= BOOLEAN) ((X NUMBER) (Y NUMBER)) :DOCUMENTATION \"Return true if `x' and `y' are numbers of exactly the same magnitude.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
    defineFunctionObject("EQL?", "(DEFUN (EQL? BOOLEAN) ((X OBJECT) (Y OBJECT)) :DOCUMENTATION \"Return true if `x' and `y' are `eq?' or equivalent literals\nsuch as strings that also might be wrapped in non-identical wrappers.  For\nthe case where `x' or `y' are plain literals such as strings or integers, the\nSTELLA translator substitutes the equality test appropriate for the particular\ntarget language and does not actually call this function.  For cases where\n`x' or `y' are known to be of type STANDARD-OBJECT, the STELLA translator\nsubstitutes the faster `eq?' test inline.\" :PUBLIC? TRUE)", ((cpp_function_code)(&eqlP)), NULL);
    defineFunctionObject("EQUAL?", "(DEFUN (EQUAL? BOOLEAN) ((X OBJECT) (Y OBJECT)) :DOCUMENTATION \"Return true if `x' and `y' are `eql?' or considered equal\nby a user-defined `object-equal?' method.  This implements a fully extensible\nequality test similar to Java's `equals' method.  Note that writers of custom\n`object-equal?' methods must also implement a corresponding `equal-hash-code'\nmethod.\" :PUBLIC? TRUE)", ((cpp_function_code)(&equalP)), NULL);
    defineMethodObject("(DEFMETHOD (OBJECT-EQUAL? BOOLEAN) ((X OBJECT) (Y OBJECT)) :DOCUMENTATION \"Return true if `x' and `y' are `eq?'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&Object::objectEqualP)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (OBJECT-EQUAL? BOOLEAN) ((X WRAPPER) (Y OBJECT)) :DOCUMENTATION \"Return true if `x' and `y' are literal wrappers whose\nliterals are considered `eql?'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&Wrapper::objectEqualP)), ((cpp_method_code)(NULL)));
    defineFunctionObject(">", "(DEFUN (> BOOLEAN) ((X NUMBER) (Y NUMBER)) :DOCUMENTATION \"Return true if `x' is greater than `y'.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
    defineFunctionObject(">=", "(DEFUN (>= BOOLEAN) ((X NUMBER) (Y NUMBER)) :DOCUMENTATION \"Return true if `x' is greater than or equal to `y'.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
    defineFunctionObject("<", "(DEFUN (< BOOLEAN) ((X NUMBER) (Y NUMBER)) :DOCUMENTATION \"Return true if `x' is less than `y'.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
    defineFunctionObject("<=", "(DEFUN (<= BOOLEAN) ((X NUMBER) (Y NUMBER)) :DOCUMENTATION \"Return true if `x' is less than or equal to `y'.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
    defineFunctionObject("+", "(DEFUN (+ NUMBER) (|&REST| (ARGUMENTS NUMBER)) :DOCUMENTATION \"Return the sum of all `arguments'.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
    defineFunctionObject("-", "(DEFUN (- NUMBER) ((X NUMBER) |&REST| (ARGUMENTS NUMBER)) :DOCUMENTATION \"If only `x' was supplied return the result of 0 - `x'.\nOtherwise, return the result of (...((`x' - arg1) - arg2) - ... - argN).\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
    defineFunctionObject("*", "(DEFUN (* NUMBER) (|&REST| (ARGUMENTS NUMBER)) :DOCUMENTATION \"Return the product of all `arguments'.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
    defineFunctionObject("/", "(DEFUN (/ NUMBER) ((X NUMBER) |&REST| (ARGUMENTS NUMBER)) :DOCUMENTATION \"If only `x' was supplied return the result of 1 / `x'.\nOtherwise, return the result of (...((`x' / arg1) / arg2 ) / ... / argN).\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
    defineFunctionObject("ZERO?", "(DEFUN (ZERO? BOOLEAN) ((X INTEGER)) :DOCUMENTATION \"Return true if `x' is 0.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:= X 0) :CPP \"(!x)\" :JAVA \"(x == 0)\")))", ((cpp_function_code)(&zeroP)), NULL);
    defineFunctionObject("PLUS?", "(DEFUN (PLUS? BOOLEAN) ((X INTEGER)) :DOCUMENTATION \"Return true if `x' is greater than 0.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:> X 0) :CPP \"(x > 0)\" :JAVA \"(x > 0)\")))", ((cpp_function_code)(&plusP)), NULL);
    defineFunctionObject("EVEN?", "(DEFUN (EVEN? BOOLEAN) ((X INTEGER)) :DOCUMENTATION \"Return true if `x' is an even number.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:NOT (CL:LOGBITP 0 X)) :CPP \"!(x % 2)\" :JAVA \"((x % 2) == 0)\")))", ((cpp_function_code)(&evenP)), NULL);
    defineFunctionObject("ODD?", "(DEFUN (ODD? BOOLEAN) ((X INTEGER)) :DOCUMENTATION \"Return true if `x' is an odd number.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:LOGBITP 0 X) :CPP \"(x % 2)\" :JAVA \"((x % 2) == 1)\")))", ((cpp_function_code)(&oddP)), NULL);
    defineFunctionObject("DIV", "(DEFUN (DIV INTEGER) ((X INTEGER) (Y INTEGER)) :DOCUMENTATION \"Return the integer quotient from dividing `x' by `y'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:VALUES (CL:TRUNCATE X Y)) :CPP \"(x / y)\" :JAVA \"(x / y)\")))", ((cpp_function_code)(&div)), NULL);
    defineFunctionObject("REM", "(DEFUN (REM INTEGER) ((X INTEGER) (Y INTEGER)) :DOCUMENTATION \"Return the remainder from dividing `x' by `y'.  The\nsign of the result is always the same as the sign of `x'.  This has slightly\ndifferent behavior than the `mod' function, and has less overhead in C++ and\nJava, which don't have direct support for a true modulus function.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:REM X Y) :CPP \"(x % y)\" :JAVA \"(x % y)\")))", ((cpp_function_code)(&rem)), NULL);
    defineFunctionObject("MOD", "(DEFUN (MOD INTEGER) ((X INTEGER) (MODULUS INTEGER)) :DOCUMENTATION \"True modulus.  Return the result of `x' mod `modulo'.\nNote: In C++ and Java, `mod' has more overhead than the similar\nfunction `rem'.  The  answers returned by `mod' and `rem' are only\ndifferent when the signs of `x' and `modulo' are different.\" :PUBLIC? TRUE)", ((cpp_function_code)(&mod)), NULL);
    defineFunctionObject("GCD", "(DEFUN (GCD INTEGER) ((X INTEGER) (Y INTEGER)) :DOCUMENTATION \"Return the greatest common divisor of `x' and `y'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&gcd)), NULL);
    defineFunctionObject("CEILING", "(DEFUN (CEILING INTEGER) ((N NUMBER)) :DOCUMENTATION \"Return the smallest integer >= `n'.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineFunctionObject("FLOOR", "(DEFUN (FLOOR INTEGER) ((N NUMBER)) :DOCUMENTATION \"Return the biggest integer <= `n'.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineFunctionObject("ROUND", "(DEFUN (ROUND INTEGER) ((N NUMBER)) :DOCUMENTATION \"Round `n' to the closest integer and return the result.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineFunctionObject("RANDOM", "(DEFUN (RANDOM INTEGER) ((N INTEGER)) :PUBLIC? TRUE :DOCUMENTATION \"Generate a random integer in the interval [0..n-1].\n`n' must be <= 2^15.\")", ((cpp_function_code)(&stella::random)), NULL);
    defineFunctionObject("SEED-RANDOM-NUMBER-GENERATOR", "(DEFUN SEED-RANDOM-NUMBER-GENERATOR () :PUBLIC? TRUE :DOCUMENTATION \"Seeds the random number generator with the current time.\")", ((cpp_function_code)(&seedRandomNumberGenerator)), NULL);
    defineFunctionObject("SQRT", "(DEFUN (SQRT FLOAT) ((N FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return the square root of `n'.\" (RETURN (VERBATIM :COMMON-LISP (CL:SQRT N) :CPP \"::sqrt(n)\" :JAVA \"Math.sqrt(n)\")))", ((cpp_function_code)(&stella::sqrt)), NULL);
    defineFunctionObject("COS", "(DEFUN (COS FLOAT) ((N FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return the cosine of `n' radians.\" (RETURN (VERBATIM :COMMON-LISP (CL:COS N) :CPP \"::cos(n)\" :JAVA \"Math.cos(n)\")))", ((cpp_function_code)(&stella::cos)), NULL);
    defineFunctionObject("SIN", "(DEFUN (SIN FLOAT) ((N FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return the sine of `n' radians.\" (RETURN (VERBATIM :COMMON-LISP (CL:SIN N) :CPP \"::sin(n)\" :JAVA \"Math.sin(n)\")))", ((cpp_function_code)(&stella::sin)), NULL);
    defineFunctionObject("TAN", "(DEFUN (TAN FLOAT) ((N FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return the tangent of `n' radians.\" (RETURN (VERBATIM :COMMON-LISP (CL:TAN N) :CPP \"::tan(n)\" :JAVA \"Math.tan(n)\")))", ((cpp_function_code)(&stella::tan)), NULL);
    defineFunctionObject("ACOS", "(DEFUN (ACOS FLOAT) ((N FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return the arccosine of `n' in radians.\" (RETURN (VERBATIM :COMMON-LISP (CL:ACOS N) :CPP \"::acos(n)\" :JAVA \"Math.acos(n)\")))", ((cpp_function_code)(&stella::acos)), NULL);
    defineFunctionObject("ASIN", "(DEFUN (ASIN FLOAT) ((N FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return the arcsine of `n' in radians.\" (RETURN (VERBATIM :COMMON-LISP (CL:ASIN N) :CPP \"::asin(n)\" :JAVA \"Math.asin(n)\")))", ((cpp_function_code)(&stella::asin)), NULL);
    defineFunctionObject("ATAN", "(DEFUN (ATAN FLOAT) ((N FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return the arc tangent of `n' in radians.\" (RETURN (VERBATIM :COMMON-LISP (CL:ATAN N) :CPP \"::atan(n)\" :JAVA \"Math.atan(n)\")))", ((cpp_function_code)(&stella::atan)), NULL);
    defineFunctionObject("ATAN2", "(DEFUN (ATAN2 FLOAT) ((X FLOAT) (Y FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return the arc tangent of `x' / `y' in radians.\" (RETURN (VERBATIM :COMMON-LISP (CL:ATAN X Y) :CPP \"::atan2(x,y)\" :JAVA \"Math.atan2(x,y)\")))", ((cpp_function_code)(&stella::atan2)), NULL);
    defineFunctionObject("LOG", "(DEFUN (LOG FLOAT) ((N FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return the natural logarithm (base e) of `n'.\" (RETURN (VERBATIM :COMMON-LISP (CL:LOG N) :CPP \"::log(n)\" :JAVA \"Math.log(n)\")))", ((cpp_function_code)(&stella::log)), NULL);
    defineFunctionObject("LOG10", "(DEFUN (LOG10 FLOAT) ((N FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return the logarithm (base 10) of `n'.\" (RETURN (VERBATIM :COMMON-LISP (CL:LOG N 10.0D0) :OTHERWISE (* (LOG N) RECIPROCAL-NL10))))", ((cpp_function_code)(&log10)), NULL);
    defineFunctionObject("EXP", "(DEFUN (EXP FLOAT) ((N FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return the e to the power `n'.\" (RETURN (VERBATIM :COMMON-LISP (CL:EXP N) :CPP \"::exp(n)\" :JAVA \"Math.exp(n)\")))", ((cpp_function_code)(&stella::exp)), NULL);
    defineFunctionObject("EXPT", "(DEFUN (EXPT FLOAT) ((X FLOAT) (Y FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE :DOCUMENTATION \"Return `x' ^ `y'.\" (RETURN (VERBATIM :COMMON-LISP (CL:EXPT X Y) :CPP \"::pow(x,y)\" :JAVA \"Math.pow(x,y)\")))", ((cpp_function_code)(&expt)), NULL);
    defineFunctionObject("MIN", "(DEFUN (MIN INTEGER) ((X INTEGER) (Y INTEGER)) :DOCUMENTATION \"Return the minimum of `x' and `y'.  If either is NULL, return the other.\" :PUBLIC? TRUE)", ((cpp_function_code)(&stella::min)), NULL);
  }
}

void helpStartupPrimal3() {
  {
    defineFunctionObject("MAX", "(DEFUN (MAX INTEGER) ((X INTEGER) (Y INTEGER)) :DOCUMENTATION \"Return the maximum of `x' and `y'.  If either is NULL, return the other.\" :PUBLIC? TRUE)", ((cpp_function_code)(&stella::max)), NULL);
    defineMethodObject("(DEFMETHOD (ABS INTEGER) ((X INTEGER)) :DOCUMENTATION \"Return the absolute value of `x'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (CHOOSE (< X 0) (- 0 X) X)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (ABS FLOAT) ((X FLOAT)) :DOCUMENTATION \"Return the absolute value of `x'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (CHOOSE (< X 0.0) (- 0.0 X) X)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineFunctionObject("CHARACTER-CODE", "(DEFUN (CHARACTER-CODE INTEGER) ((CH CHARACTER)) :DOCUMENTATION \"Return the 8-bit ASCII code of `ch' as an integer.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:CHAR-CODE CH) :CPP \"(int)(unsigned char) ch\" :JAVA \"(int) ch\")))", ((cpp_function_code)(&characterCode)), NULL);
    defineFunctionObject("CODE-CHARACTER", "(DEFUN (CODE-CHARACTER CHARACTER) ((CODE INTEGER)) :DOCUMENTATION \"Return the character encoded by `code' (0 <= `code' <= 255).\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:CODE-CHAR CODE) :CPP \"(char) code\" :JAVA \"(char) code\")))", ((cpp_function_code)(&codeCharacter)), NULL);
    defineFunctionObject("CHARACTER-DOWNCASE", "(DEFUN (CHARACTER-DOWNCASE CHARACTER) ((CH CHARACTER)) :DOCUMENTATION \"If `ch' is lowercase, return its uppercase version,\notherwise, return 'ch' unmodified.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (DOWNCASE-CHARACTER CH)))", ((cpp_function_code)(&characterDowncase)), NULL);
    defineFunctionObject("CHARACTER-UPCASE", "(DEFUN (CHARACTER-UPCASE CHARACTER) ((CH CHARACTER)) :DOCUMENTATION \"If `ch' is uppercase, return its lowercase version,\notherwise, return 'ch' unmodified.  If only the first character of\na sequence of characters is to be capitalized, `character-capitalize'\nshould be used instead.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (UPCASE-CHARACTER CH)))", ((cpp_function_code)(&characterUpcase)), NULL);
    defineFunctionObject("CHARACTER-CAPITALIZE", "(DEFUN (CHARACTER-CAPITALIZE CHARACTER) ((CH CHARACTER)) :DOCUMENTATION \"Return the capitalized character for `ch'.  This is generally the same\nas the uppercase character, except for obscure non-English characters in Java.  It should\nbe used if only the first character of a sequence of characters is to be capitalized.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :JAVA \"Character.toTitleCase(ch)\" :OTHERWISE (CHARACTER-UPCASE CH))))", ((cpp_function_code)(&characterCapitalize)), NULL);
    defineFunctionObject("STRING-EQL?", "(DEFUN (STRING-EQL? BOOLEAN) ((X STRING) (Y STRING)) :DOCUMENTATION \"Return true if `x' and `y' are equal strings or are both undefined.  This\ntest is substituted automatically by the STELLA translator if `eql?' is applied\nto strings.\" :PUBLIC? TRUE)", ((cpp_function_code)(&stringEqlP)), NULL);
    defineFunctionObject("STRING-EQUAL?", "(DEFUN (STRING-EQUAL? BOOLEAN) ((X STRING) (Y STRING)) :DOCUMENTATION \"Return true if `x' and `y' are equal strings ignoring character case or\nare both undefined.\" :PUBLIC? TRUE)", ((cpp_function_code)(&stringEqualP)), NULL);
    defineFunctionObject("STRING-COMPARE", "(DEFUN (STRING-COMPARE INTEGER) ((X STRING) (Y STRING) (CASE-SENSITIVE? BOOLEAN)) :PUBLIC? TRUE :DOCUMENTATION \"Compare `x' and `y' lexicographically, and return -1, 0, \nor 1, depending on whether `x' is less than, equal, or greater than `y'.\nIf `case-sensitive?' is true, then case does matter for the comparison\")", ((cpp_function_code)(&stringCompare)), NULL);
    defineMethodObject("(DEFMETHOD (EMPTY? BOOLEAN) ((X STRING)) :DOCUMENTATION \"Return true if `x' is the empty string \\\"\\\"\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (STRING-EQL? X \"\")))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NON-EMPTY? BOOLEAN) ((X STRING)) :DOCUMENTATION \"Return true if `x' is not the empty string \\\"\\\"\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (NOT (EMPTY? X))))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (EMPTY? BOOLEAN) ((X STRING-WRAPPER)) :DOCUMENTATION \"Return true if `x' is the wrapped empty string \\\"\\\"\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (STRING-EQL? (WRAPPER-VALUE X) \"\")))", ((cpp_method_code)(&StringWrapper::emptyP)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NON-EMPTY? BOOLEAN) ((X STRING-WRAPPER)) :DOCUMENTATION \"Return true if `x' is not the wrapped empty string \\\"\\\"\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (NOT (EMPTY? X))))", ((cpp_method_code)(&StringWrapper::nonEmptyP)), ((cpp_method_code)(NULL)));
    defineFunctionObject("STRING<", "(DEFUN (STRING< BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return true if `x' is lexicographically < `y', considering case.\")", ((cpp_function_code)(&stringL)), NULL);
    defineFunctionObject("STRING<=", "(DEFUN (STRING<= BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return true if `x' is lexicographically <= `y', considering case.\")", ((cpp_function_code)(&stringLE)), NULL);
    defineFunctionObject("STRING>=", "(DEFUN (STRING>= BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return true if `x' is lexicographically >= `y', considering case.\")", ((cpp_function_code)(&stringGE)), NULL);
    defineFunctionObject("STRING>", "(DEFUN (STRING> BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return true if `x' is lexicographically > `y', considering case.\")", ((cpp_function_code)(&stringG)), NULL);
    defineFunctionObject("STRING-LESS?", "(DEFUN (STRING-LESS? BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return true if `x' is lexicographically < `y', ignoring case.\")", ((cpp_function_code)(&stringLessP)), NULL);
    defineFunctionObject("STRING-LESS-EQUAL?", "(DEFUN (STRING-LESS-EQUAL? BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return true if `x' is lexicographically <= `y', ignoring case.\")", ((cpp_function_code)(&stringLessEqualP)), NULL);
    defineFunctionObject("STRING-GREATER-EQUAL?", "(DEFUN (STRING-GREATER-EQUAL? BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return true if `x' is lexicographically >= `y', ignoring case.\")", ((cpp_function_code)(&stringGreaterEqualP)), NULL);
    defineFunctionObject("STRING-GREATER?", "(DEFUN (STRING-GREATER? BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return true if `x' is lexicographically > `y', ignoring case.\")", ((cpp_function_code)(&stringGreaterP)), NULL);
    defineFunctionObject("MAKE-STRING", "(DEFUN (MAKE-STRING STRING) ((SIZE INTEGER) (INITCHAR CHARACTER)) :DOCUMENTATION \"Return a new string filled with `size' `initchar's.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
    defineFunctionObject("MAKE-MUTABLE-STRING", "(DEFUN (MAKE-MUTABLE-STRING MUTABLE-STRING) ((SIZE INTEGER) (INITCHAR CHARACTER)) :DOCUMENTATION \"Return a new mutable string filled with `size' `initchar's.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:MAKE-STRING SIZE :INITIAL-ELEMENT INITCHAR) :CPP \"makeString(size, initchar)\" :JAVA \"#$(STELLAROOT).javalib.Native.makeMutableString(size, initchar)\")))", ((cpp_function_code)(&makeMutableString)), NULL);
    defineFunctionObject("MAKE-RAW-MUTABLE-STRING", "(DEFUN (MAKE-RAW-MUTABLE-STRING MUTABLE-STRING) ((SIZE INTEGER)) :DOCUMENTATION \"Return a new uninitialized mutable string of `size'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (LET ((S MUTABLE-STRING NULL)) (VERBATIM :COMMON-LISP (SETQ S (CL:MAKE-STRING SIZE)) :CPP \"s = new (GC) char[size+1]; s[size]='\\\\0'\" :JAVA \"s = new StringBuffer(size); s.setLength(size)\") (RETURN S)))", ((cpp_function_code)(&makeRawMutableString)), NULL);
    defineFunctionObject("STRING-CONCATENATE", "(DEFUN (STRING-CONCATENATE STRING) ((STRING1 STRING) (STRING2 STRING)) :DOCUMENTATION \"Return a new string representing the concatenation of\n`string1' and `string2'.\" :NATIVE? TRUE)", NULL, NULL);
    defineMethodObject("(DEFMETHOD (CONCATENATE STRING) ((STRING1 STRING) (STRING2 STRING) |&REST| (OTHERSTRINGS STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return a new string representing the concatenation\nof `string1', `string2', and `otherStrings'.  The two mandatory parameters\nallow us to optimize the common binary case by not relying on the somewhat\nless efficient variable arguments mechanism.\")", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineFunctionObject("STRING-UPCASE", "(DEFUN (STRING-UPCASE STRING) ((STRING STRING)) :DOCUMENTATION \"Return an upper-case copy of `string'.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineFunctionObject("STRING-DOWNCASE", "(DEFUN (STRING-DOWNCASE STRING) ((STRING STRING)) :DOCUMENTATION \"Return a lower-case copy of `string'.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineFunctionObject("STRING-CAPITALIZE", "(DEFUN (STRING-CAPITALIZE STRING) ((STRING STRING)) :DOCUMENTATION \"Return a capitalized version of `string'.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineMethodObject("(DEFMETHOD (COPY STRING) ((STRING STRING)) :DOCUMENTATION \"Return a copy of `string'.\" :NATIVE? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (SUBSTITUTE STRING) ((SELF STRING) (NEW-CHAR CHARACTER) (OLD-CHAR CHARACTER)) :DOCUMENTATION \"Substitute all occurences of `old-char' with `new-char'\nin the string `self'.\" :NATIVE? TRUE :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (SUBSTITUTE MUTABLE-STRING) ((SELF MUTABLE-STRING) (NEW-CHAR CHARACTER) (OLD-CHAR CHARACTER)) :DOCUMENTATION \"Substitute all occurences of `old-char' with `new-char'\nin the string `self'.\" :NATIVE? TRUE :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineFunctionObject("HELP-SUBSTITUTE-CHARACTERS", "(DEFUN (HELP-SUBSTITUTE-CHARACTERS MUTABLE-STRING) ((SELF MUTABLE-STRING) (NEW-CHARS STRING) (OLD-CHARS STRING)) :PUBLIC? FALSE :GLOBALLY-INLINE? TRUE (LET ((POS INTEGER NULL)) (FOREACH I IN (INTERVAL 0 (1- (LENGTH SELF))) DO (SETQ POS (POSITION OLD-CHARS (NTH SELF I) 0)) (WHEN (DEFINED? POS) (SETF (NTH SELF I) (NTH NEW-CHARS POS)))) (RETURN SELF)))", ((cpp_function_code)(&helpSubstituteCharacters)), NULL);
    defineMethodObject("(DEFMETHOD (SUBSTITUTE-CHARACTERS MUTABLE-STRING) ((SELF MUTABLE-STRING) (NEW-CHARS STRING) (OLD-CHARS STRING)) :DOCUMENTATION \"Substitute all occurences of of a member of `old-chars' with the \ncorresponding member of `new-chars' in the string `self'.  IMPORTANT:  The return\nvalue should be used instead of relying on destructive substitution, since the\nsubstitution will not be destructive in all translated languages.\" :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (SUBSTITUTE-CHARACTERS STRING) ((SELF STRING) (NEW-CHARS STRING) (OLD-CHARS STRING)) :DOCUMENTATION \"Substitute all occurences of of a member of `old-chars' with the \ncorresponding member of `new-chars' in the string `self'.  Returns a new string.\" :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineFunctionObject("REPLACE-SUBSTRINGS", "(DEFUN (REPLACE-SUBSTRINGS STRING) ((STRING STRING) (NEW STRING) (OLD STRING)) :DOCUMENTATION \"Replace all occurrences of `old' in `string' with `new'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&replaceSubstrings)), NULL);
    defineFunctionObject("INSERT-STRING", "(DEFUN (INSERT-STRING INTEGER) ((SOURCE STRING) (START INTEGER) (END INTEGER) (TARGET MUTABLE-STRING) (TARGET-INDEX INTEGER) (CASE-CONVERSION KEYWORD)) :DOCUMENTATION \"Inserts characters from `source' begining at `start' and\nending at `end' into `target' starting at `target-index'.  If `end' is `null',\nthen the entire length of the string is used. The copy of characters is affected\nby the `case-conversion' keyword which should be one of\n   :UPCASE :DOWNCASE :CAPITALIZE :PRESERVE.\n\nThe final value of target-index is returned.\")", ((cpp_function_code)(&insertString)), NULL);
    defineFunctionObject("INTEGER-TO-STRING", "(DEFUN (INTEGER-TO-STRING STRING) ((I INTEGER)) :DOCUMENTATION \"Print `i' to a string and return the result.  This is more\nefficient than using a string stream.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineFunctionObject("FLOAT-TO-STRING", "(DEFUN (FLOAT-TO-STRING STRING) ((F FLOAT)) :DOCUMENTATION \"Print `f' to a string and return the result.  This is more\nefficient than using a string stream.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineFunctionObject("CHARACTER-TO-STRING", "(DEFUN (CHARACTER-TO-STRING STRING) ((C CHARACTER)) :DOCUMENTATION \"Convert `c' into a one-element string and return the result.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (MAKE-STRING 1 C)))", ((cpp_function_code)(&characterToString)), NULL);
    defineFunctionObject("STRING-TO-INTEGER", "(DEFUN (STRING-TO-INTEGER INTEGER) ((STRING STRING)) :DOCUMENTATION \"Convert a `string' representation of an integer into an integer.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineFunctionObject("STRING-TO-FLOAT", "(DEFUN (STRING-TO-FLOAT FLOAT) ((STRING STRING)) :DOCUMENTATION \"Convert a `string' representation of a float into a float.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineFunctionObject("FORMAT-FLOAT", "(DEFUN (FORMAT-FLOAT STRING) ((F FLOAT) (NDECIMALS INTEGER)) :DOCUMENTATION \"Print `f' in fixed-point format with `nDecimals' behind the decimal point\nand return the result as a string.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineFunctionObject("FORMAT-WITH-PADDING", "(DEFUN (FORMAT-WITH-PADDING STRING) ((INPUT STRING) (LENGTH INTEGER) (PADCHAR CHARACTER) (ALIGN KEYWORD) (TRUNCATE? BOOLEAN)) :PUBLIC? TRUE :DOCUMENTATION \"Formats `input' to be (at least) `length' long, using `padchar' to\nfill if necessary.  `align' must be one of :LEFT, :RIGHT, :CENTER and will control\nhow `input' will be justified in the resulting string.  If `truncate?' is true, then\nthen an overlength string will be truncated, using the opposite of `align' to pick\nthe truncation direction.\")", ((cpp_function_code)(&formatWithPadding)), NULL);
    defineMethodObject("(DEFMETHOD (MEMBER? BOOLEAN) ((SELF STRING) (CHAR CHARACTER)) :NATIVE? TRUE :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (FIRST CHARACTER) ((SELF STRING)) :DOCUMENTATION \"Return the first character of `self'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH SELF 0)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (FIRST CHARACTER) ((SELF MUTABLE-STRING)) :DOCUMENTATION \"Return the first character of `self' (settable via `setf').\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH SELF 0)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (FIRST-SETTER CHARACTER) ((SELF MUTABLE-STRING) (CH CHARACTER)) :DOCUMENTATION \"Set the first character of `self' to `ch' and return `ch'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (SETF (NTH SELF 0) CH)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (SECOND CHARACTER) ((SELF STRING)) :DOCUMENTATION \"Return the second character of `self'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH SELF 1)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (SECOND CHARACTER) ((SELF MUTABLE-STRING)) :DOCUMENTATION \"Return the second character of `self' (settable via `setf').\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH SELF 1)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (SECOND-SETTER CHARACTER) ((SELF MUTABLE-STRING) (CH CHARACTER)) :DOCUMENTATION \"Set the second character of `self' to `ch' and return `ch'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (SETF (NTH SELF 1) CH)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (THIRD CHARACTER) ((SELF STRING)) :DOCUMENTATION \"Return the third character of `self'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH SELF 2)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (THIRD CHARACTER) ((SELF MUTABLE-STRING)) :DOCUMENTATION \"Return the third character of `self' (settable via `setf').\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH SELF 2)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (THIRD-SETTER CHARACTER) ((SELF MUTABLE-STRING) (CH CHARACTER)) :DOCUMENTATION \"Set the third character of `self' to `ch' and return `ch'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (SETF (NTH SELF 2) CH)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (FOURTH CHARACTER) ((SELF STRING)) :DOCUMENTATION \"Return the fourth character of `self'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH SELF 3)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (FOURTH CHARACTER) ((SELF MUTABLE-STRING)) :DOCUMENTATION \"Return the fourth character of `self' (settable via `setf').\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH SELF 3)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (FOURTH-SETTER CHARACTER) ((SELF MUTABLE-STRING) (CH CHARACTER)) :DOCUMENTATION \"Set the fourth character of `self' to `ch' and return `ch'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (SETF (NTH SELF 3) CH)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (FIFTH CHARACTER) ((SELF STRING)) :DOCUMENTATION \"Return the fifth character of `self'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH SELF 4)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
  }
}

void helpStartupPrimal4() {
  {
    defineMethodObject("(DEFMETHOD (FIFTH CHARACTER) ((SELF MUTABLE-STRING)) :DOCUMENTATION \"Return the fifth character of `self' (settable via `setf').\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH SELF 4)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (FIFTH-SETTER CHARACTER) ((SELF MUTABLE-STRING) (CH CHARACTER)) :DOCUMENTATION \"Set the fifth character of `self' to `ch' and return `ch'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (SETF (NTH SELF 4) CH)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NTH CHARACTER) ((SELF STRING) (POSITION INTEGER)) :DOCUMENTATION \"Return the character in `self' at `position'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:SCHAR (CL:THE CL:SIMPLE-STRING SELF) (CL:THE CL:FIXNUM POSITION)) :CPP \"self[position]\" :JAVA \"self.charAt(position)\")))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NTH CHARACTER) ((SELF MUTABLE-STRING) (POSITION INTEGER)) :DOCUMENTATION \"Return the character in `self' at `position'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:SCHAR (CL:THE CL:SIMPLE-STRING SELF) (CL:THE CL:FIXNUM POSITION)) :CPP \"self[position]\" :JAVA \"self.charAt(position)\")))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NTH-SETTER CHARACTER) ((SELF MUTABLE-STRING) (CH CHARACTER) (POSITION INTEGER)) :DOCUMENTATION \"Set the character in `self' at `position' to `ch'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (SETF (CL:SCHAR (CL:THE CL:SIMPLE-STRING SELF) (CL:THE CL:FIXNUM POSITION)) (CL:THE CL:CHARACTER CH)) :CPP \"self[position] = ch\" :JAVA \"#$(STELLAROOT).javalib.Native.mutableString_nthSetter(self, ch, position)\")))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (REST STRING) ((SELF STRING)) :NATIVE? TRUE :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (LENGTH INTEGER) ((SELF STRING)) :DOCUMENTATION \"Return the length of the string `self'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:LENGTH SELF) :CPP \"strlen(self)\" :JAVA \"self.length()\")))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (LENGTH INTEGER) ((SELF MUTABLE-STRING)) :DOCUMENTATION \"Return the length of the string `self'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:LENGTH SELF) :CPP \"strlen(self)\" :JAVA \"self.length()\")))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (POSITION INTEGER) ((STRING STRING) (CHARACTER CHARACTER) (START INTEGER)) :DOCUMENTATION \"Return the position of `character' within `string' (counting\nfrom zero); or return NULL if `character' does not occur within `string'.\nIf `start' was supplied as non-NULL, only consider the substring starting\nat `start', however, the returned position will always be relative to the\nentire string.\" :NATIVE? TRUE :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineFunctionObject("STRING-SEARCH", "(DEFUN (STRING-SEARCH INTEGER) ((STRING STRING) (SUBSTRING STRING) (START INTEGER)) :DOCUMENTATION \"Return start position of the left-most occurrence of\n`substring' in `string', beginning from `start'.  Return NULL if it is not\na substring.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineMethodObject("(DEFMETHOD (SUBSEQUENCE STRING) ((STRING STRING) (START INTEGER) (END INTEGER)) :DOCUMENTATION \"Return a substring of `string' beginning at position `start'\nand ending up to but not including position `end', counting from zero.  An\n`end' value of NULL stands for the rest of the string.\" :NATIVE? TRUE :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (SUBSEQUENCE STRING) ((STRING MUTABLE-STRING) (START INTEGER) (END INTEGER)) :DOCUMENTATION \"Return a substring of `string' beginning at position `start'\nand ending up to but not including position `end', counting from zero.  An\n`end' value of NULL stands for the rest of the string.\" :NATIVE? TRUE :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineFunctionObject("STRINGIFY", "(DEFUN (STRINGIFY STRING) ((EXPRESSION OBJECT)) :DOCUMENTATION \"Print `expression' onto a string and return the result.\nPrinting is done with `*printReadably?*' set to true and with `*printPretty?*'\nset to false.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
    defineFunctionObject("UNSTRINGIFY", "(DEFUN (UNSTRINGIFY OBJECT) ((STRING STRING)) :DOCUMENTATION \"Read a STELLA expression from `string' and return the result.\nThis is identical to `read-s-expression-from-string'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (READ-S-EXPRESSION-FROM-STRING STRING)))", ((cpp_function_code)(&unstringify)), NULL);
    defineMethodObject("(DEFMETHOD FREE-HASH-TABLE-VALUES ((SELF ABSTRACT-HASH-TABLE)) :DOCUMENTATION \"Call free on each value in the hash table `self'.\")", ((cpp_method_code)(&AbstractHashTable::freeHashTableValues)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD INITIALIZE-HASH-TABLE ((SELF ABSTRACT-HASH-TABLE)) :DOCUMENTATION \"Insert a newly-created native hash table into `self'.\")", ((cpp_method_code)(&AbstractHashTable::initializeHashTable)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF HASH-TABLE) (KEY (LIKE (ANY-KEY SELF)))) :PUBLIC? TRUE)", ((cpp_method_code)(&HashTable::lookup)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD INSERT-AT ((SELF HASH-TABLE) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)", ((cpp_method_code)(&HashTable::insertAt)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD REMOVE-AT ((SELF HASH-TABLE) (KEY (LIKE (ANY-KEY SELF)))) :PUBLIC? TRUE)", ((cpp_method_code)(&HashTable::removeAt)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD INITIALIZE-HASH-TABLE ((SELF INTEGER-HASH-TABLE)) :DOCUMENTATION \"Insert a newly-created native hash table into `self'.\")", ((cpp_method_code)(&IntegerHashTable::initializeHashTable)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF INTEGER-HASH-TABLE) (KEY INTEGER)) :PUBLIC? TRUE)", ((cpp_method_code)(&IntegerHashTable::lookup)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD INSERT-AT ((SELF INTEGER-HASH-TABLE) (KEY INTEGER) (VALUE OBJECT)) :PUBLIC? TRUE)", ((cpp_method_code)(&IntegerHashTable::insertAt)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD REMOVE-AT ((SELF INTEGER-HASH-TABLE) (KEY (LIKE (ANY-KEY SELF)))))", ((cpp_method_code)(&IntegerHashTable::removeAt)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD INITIALIZE-HASH-TABLE ((SELF FLOAT-HASH-TABLE)) :DOCUMENTATION \"Insert a newly-created native hash table into `self'.\")", ((cpp_method_code)(&FloatHashTable::initializeHashTable)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF FLOAT-HASH-TABLE) (KEY FLOAT)) :PUBLIC? TRUE)", ((cpp_method_code)(&FloatHashTable::lookup)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD INSERT-AT ((SELF FLOAT-HASH-TABLE) (KEY FLOAT) (VALUE OBJECT)) :PUBLIC? TRUE)", ((cpp_method_code)(&FloatHashTable::insertAt)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD REMOVE-AT ((SELF FLOAT-HASH-TABLE) (KEY (LIKE (ANY-KEY SELF)))))", ((cpp_method_code)(&FloatHashTable::removeAt)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD INITIALIZE-HASH-TABLE ((SELF STRING-HASH-TABLE)) :DOCUMENTATION \"Insert a newly-created native hash table into `self'.\")", ((cpp_method_code)(&StringHashTable::initializeHashTable)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF STRING-HASH-TABLE) (KEY STRING)) :PUBLIC? TRUE)", ((cpp_method_code)(&StringHashTable::lookup)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD INSERT-AT ((SELF STRING-HASH-TABLE) (KEY STRING) (VALUE OBJECT)) :PUBLIC? TRUE)", ((cpp_method_code)(&StringHashTable::insertAt)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD REMOVE-AT ((SELF STRING-HASH-TABLE) (KEY STRING)) :PUBLIC? TRUE)", ((cpp_method_code)(&StringHashTable::removeAt)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD INITIALIZE-HASH-TABLE ((SELF STRING-TO-INTEGER-HASH-TABLE)) :DOCUMENTATION \"Insert a newly-created native hash table into `self'.\")", ((cpp_method_code)(&StringToIntegerHashTable::initializeHashTable)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (LOOKUP INTEGER) ((SELF STRING-TO-INTEGER-HASH-TABLE) (KEY STRING)) :PUBLIC? TRUE)", ((cpp_method_code)(&StringToIntegerHashTable::lookup)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD INSERT-AT ((SELF STRING-TO-INTEGER-HASH-TABLE) (KEY STRING) (VALUE INTEGER)) :PUBLIC? TRUE)", ((cpp_method_code)(&StringToIntegerHashTable::insertAt)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD REMOVE-AT ((SELF STRING-TO-INTEGER-HASH-TABLE) (KEY STRING)) :PUBLIC? TRUE)", ((cpp_method_code)(&StringToIntegerHashTable::removeAt)), ((cpp_method_code)(NULL)));
    defineFunctionObject("HASHMOD", "(DEFUN (HASHMOD INTEGER) ((CODE INTEGER) (SIZE INTEGER)) :DOCUMENTATION \"Map the hash code `code' onto a bucket index for a hash table\nof `size' (i.e., onto the interval [0..size-1].  This is just like `rem' for\npositive hash codes but also works for negative hash codes by mapping those\nonto a positive number first.  Note, that the sign conversion mapping is not\nequivalent to calling the `abs' function (it simply masks the sign bit for\nspeed) and therefore really only makes sense for hash codes.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:REM (CL:THE CL:FIXNUM (CL:LOGAND CODE *INTEGER-UNSIGNED-BITS-MASK*)) SIZE) :CPP \"(((unsigned int) code) % size)\" :JAVA \"((code & 0x7FFFFFFF) % size)\")))", ((cpp_function_code)(&hashmod)), NULL);
    defineFunctionObject("ROTATE-HASH-CODE", "(DEFUN (ROTATE-HASH-CODE INTEGER) ((ARG INTEGER)) :DOCUMENTATION \"Rotate `arg' to the right by 1 position.  This means shift `arg' to the right\nby one and feed in `arg's bit zero from the left.  In Lisp the result will stay\nin positive FIXNUM range.  In C++ and Java this might return a negative\nvalue which might be equal to NULL-INTEGER.  Important: to make this inlinable,\nit must be called with an atom (i.e., constant or variable) as its argument.\nThis function is primarily useful for hashing sequences of items where the hash\ncode should take the sequential order of elements into account (e.g., lists).\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (CHOOSE (= (LOGAND ARG 1) 0) (UNSIGNED-SHIFT-RIGHT-BY-1 ARG) (LOGOR (SHIFT-RIGHT ARG 1) *INTEGER-MSB-MASK*))))", ((cpp_function_code)(&rotateHashCode)), NULL);
    defineFunctionObject("OBJECT-HASH-CODE", "(DEFUN (OBJECT-HASH-CODE INTEGER) ((SELF OBJECT)) :DOCUMENTATION \"Return a hash code for `self' (can be negative).  Two objects that are `eq?'\nare guaranteed to generate the same hash code.  Two objects that are not `eq?'\ndo not necessarily generate different hash codes.  Similar to `hash-code' but\nalways hashes on the address of `self' even if it is a wrapper.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP \"(STELLA::%%OBJECT-HASH-CODE SELF)\" :CPP \"(size_t)self\" :JAVA \"self.hashCode()\")))", ((cpp_function_code)(&objectHashCode)), NULL);
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF OBJECT)) :DOCUMENTATION \"Return a hash code for `self' (can be negative).  Two objects that are `eql?'\nare guaranteed to generate the same hash code.  Two objects that are not `eql?'\ndo not necessarily generate different hash codes.\" :PUBLIC? TRUE)", ((cpp_method_code)(&Object::hashCode)), ((cpp_method_code)(NULL)));
    defineFunctionObject("SAFE-HASH-CODE", "(DEFUN (SAFE-HASH-CODE INTEGER) ((SELF OBJECT)) :DOCUMENTATION \"Return a hash code for `self'.  Just like `hash-code'\n- which see, but also works for NULL.\" :PUBLIC? TRUE)", ((cpp_function_code)(&safeHashCode)), NULL);
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF STANDARD-OBJECT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (OBJECT-HASH-CODE SELF)))", ((cpp_method_code)(&StandardObject::hashCode)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF WRAPPER)) :PUBLIC? TRUE)", ((cpp_method_code)(&Wrapper::hashCode)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF STRING-WRAPPER)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (HASH-CODE (WRAPPER-VALUE SELF))))", ((cpp_method_code)(&StringWrapper::hashCode)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF INTEGER-WRAPPER)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (HASH-CODE (WRAPPER-VALUE SELF))))", ((cpp_method_code)(&IntegerWrapper::hashCode)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF FLOAT-WRAPPER)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (HASH-CODE (WRAPPER-VALUE SELF))))", ((cpp_method_code)(&FloatWrapper::hashCode)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF CHARACTER-WRAPPER)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (HASH-CODE (WRAPPER-VALUE SELF))))", ((cpp_method_code)(&CharacterWrapper::hashCode)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF BOOLEAN-WRAPPER)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (CHOOSE (WRAPPER-VALUE SELF) 27333705 31891526)))", ((cpp_method_code)(&BooleanWrapper::hashCode)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF STRING)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:SXHASH SELF) :JAVA \"self.hashCode()\" :CPP \"native_hash_string(self)\" :OTHERWISE (HASH-STRING SELF 0))))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF INTEGER)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN SELF))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF FLOAT)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:SXHASH SELF) :CPP \"(size_t)self\" :JAVA \"(int)(Double.doubleToLongBits(self)^(Double.doubleToLongBits(self)>>>32))\")))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF CHARACTER)) :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (LOGXOR (AREF *HASH-BYTE-RANDOM-TABLE* (CHARACTER-CODE SELF)) 33485726)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (EQUAL-HASH-CODE INTEGER) ((SELF OBJECT)) :DOCUMENTATION \"Return a hash code for `self' (can be negative).  Two objects that are `equal?'\nare guaranteed to generate the same hash code (provided, that writers of\n`object-equal?' methods also implemented the appropriate `equal-hash-code'\nmethod).  Two objects that are not `equal?'do not necessarily generate different\nhash codes.\" :PUBLIC? TRUE)", ((cpp_method_code)(&Object::equalHashCode)), ((cpp_method_code)(NULL)));
    defineFunctionObject("SAFE-EQUAL-HASH-CODE", "(DEFUN (SAFE-EQUAL-HASH-CODE INTEGER) ((SELF OBJECT)) :DOCUMENTATION \"Return a hash code for `self'.  Just like `equal-hash-code'\n- which see, but also works for NULL.  `equal-hash-code' methods that expect to\nhandle NULL components should use this function for recursive calls.\" :PUBLIC? TRUE)", ((cpp_function_code)(&safeEqualHashCode)), NULL);
    defineFunctionObject("HASH-STRING", "(DEFUN (HASH-STRING INTEGER) ((STRING STRING) (SEEDCODE INTEGER)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Generate a hash-code for `string' and return it.\nTwo strings that are equal but not eq will generate the same code.\nThe hash-code is based on `seedCode' which usually will be 0.  However,\n`seedCode' can also be used to supply the result of a previous hash\noperation to achieve hashing on sequences of strings without actually\nhaving to concatenate them.\" (LET ((CODE SEEDCODE) (CURSOR (LENGTH STRING))) (IF (= CURSOR 0) (RETURN 4303803) (-- CURSOR)) (LOOP (SETQ CODE (LOGXOR CODE (AREF *HASH-BYTE-RANDOM-TABLE* (CHARACTER-CODE (NTH STRING CURSOR))))) (IF (= CURSOR 0) (BREAK) (-- CURSOR)) (SETQ CODE (ROTATE-HASH-CODE CODE))) (RETURN CODE)))", ((cpp_function_code)(&hashString)), NULL);
    defineFunctionObject("PICK-HASH-TABLE-SIZE-PRIME", "(DEFUN (PICK-HASH-TABLE-SIZE-PRIME INTEGER) ((MINSIZE INTEGER)) :DOCUMENTATION \"Return a hash table prime of at least `minSize'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&pickHashTableSizePrime)), NULL);
    defineMethodObject("(DEFMETHOD INITIALIZE-VECTOR ((SELF VECTOR)))", ((cpp_method_code)(&Vector::initializeVector)), ((cpp_method_code)(NULL)));
    defineFunctionObject("RESIZE-VECTOR", "(DEFUN RESIZE-VECTOR ((SELF VECTOR) (SIZE INTEGER)) :DOCUMENTATION \"Change the size of `self' to `size'.  If `size' is smaller\nthan the current size of `self' the vector will be truncated.  Otherwise, \nthe internal array of `self' will be grown to `size' and unused elements\nwill be initialized to NULL.\" :PUBLIC? TRUE)", ((cpp_function_code)(&resizeVector)), NULL);
    defineMethodObject("(DEFMETHOD (NTH (LIKE (ANY-VALUE SELF))) ((SELF NATIVE-VECTOR) (POSITION INTEGER)) :DOCUMENTATION \"Return the element in `self' at `position'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:AREF SELF POSITION) :CPP \"self[position]\" :JAVA \"self[position]\")))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF NATIVE-VECTOR) (VALUE (LIKE (ANY-VALUE SELF))) (POSITION INTEGER)) :DOCUMENTATION \"Set the element in `self' at `position' to `value'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:SETF (CL:AREF SELF POSITION) VALUE) :CPP \"self[position] = value\" :JAVA \"self[position] = value\")))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineFunctionObject("UNMAKE", "(DEFUN UNMAKE ((SELF OBJECT)))", ((cpp_function_code)(&unmake)), NULL);
  }
}

void startupPrimal() {
  if (currentStartupTimePhaseP(0)) {
    oHASH_BYTE_RANDOM_TABLEo = new (GC)(int[256]);
    { int i = NULL_INTEGER;
      int iter007 = 0;
      int upperBound008 = 255;

      while (iter007 <= upperBound008) {
        i = iter007;
        iter007 = iter007 + 1;
        oHASH_BYTE_RANDOM_TABLEo[i] = 0;
      }
    }
    { int bit = NULL_INTEGER;
      int iter009 = 0;
      int upperBound010 = 25;

      while (iter009 <= upperBound010) {
        bit = iter009;
        iter009 = iter009 + 1;
        { int i = NULL_INTEGER;
          int iter011 = 0;
          int upperBound012 = 255;

          while (iter011 <= upperBound012) {
            i = iter011;
            iter011 = iter011 + 1;
            oHASH_BYTE_RANDOM_TABLEo[i] = ((oHASH_BYTE_RANDOM_TABLEo[i]) | (((stella::random(2)) << bit)));
          }
        }
      }
    }
    oHASH_TABLE_SIZE_PRIMESo = stella::vector(25, wrapInteger(29), wrapInteger(53), wrapInteger(97), wrapInteger(193), wrapInteger(389), wrapInteger(769), wrapInteger(1543), wrapInteger(3079), wrapInteger(6151), wrapInteger(12289), wrapInteger(24593), wrapInteger(49157), wrapInteger(98317), wrapInteger(196613), wrapInteger(393241), wrapInteger(786433), wrapInteger(1572869), wrapInteger(3145739), wrapInteger(6291469), wrapInteger(12582917), wrapInteger(25165843), wrapInteger(50331653), wrapInteger(100663319), wrapInteger(201326611), wrapInteger(402653189));
  }
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oSTELLA_MODULEo);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupPrimal1();
    }
    if (currentStartupTimePhaseP(4)) {
      RECIPROCAL_NL10 = 1.0 / ::log(10.0);
      oTRANSIENTOBJECTSpo.set(FALSE);
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupPrimal2();
      helpStartupPrimal3();
      helpStartupPrimal4();
      defineFunctionObject("PROBE-FILE?", "(DEFUN (PROBE-FILE? BOOLEAN) ((FILENAME FILE-NAME)) :DOCUMENTATION \"Return true if file `fileName' exists.  Note that this does\nnot necessarily mean that the file can also be read.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
      defineFunctionObject("FILE-WRITE-DATE", "(DEFUN (FILE-WRITE-DATE CALENDAR-DATE) ((FILENAME FILE-NAME)) :DOCUMENTATION \"Return the time at which file `fileName' was last modified or\nNULL if that cannot be determined.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
      defineFunctionObject("FILE-LENGTH", "(DEFUN (FILE-LENGTH INTEGER) ((FILENAME FILE-NAME)) :DOCUMENTATION \"Return the length of file `fileName' in bytes or NULL if that\ncannot be determined.  Note that this will currently overrun for files that\nare longer than what can be represented by a STELLA integer.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
      defineFunctionObject("DELETE-FILE", "(DEFUN DELETE-FILE ((FILENAME FILE-NAME)) :DOCUMENTATION \"Delete the file `fileName'.\" :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
      defineFunctionObject("COPY-FILE", "(DEFUN COPY-FILE ((FROMFILE FILE-NAME) (TOFILE FILE-NAME)) :DOCUMENTATION \"Copy file `fromFile' to file `toFile', clobbering\nany data already in `toFile'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&copyFile)), NULL);
      defineFunctionObject("LOGNOT", "(DEFUN (LOGNOT INTEGER) ((ARG INTEGER)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:LOGNOT ARG) :CPP \"(~ arg)\" :JAVA \"(~ arg)\")))", ((cpp_function_code)(&lognot)), NULL);
      defineFunctionObject("LOGAND", "(DEFUN (LOGAND INTEGER) ((ARG1 INTEGER) (ARG2 INTEGER)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:LOGAND ARG1 ARG2) :CPP \"(arg1 & arg2)\" :JAVA \"(arg1 & arg2)\")))", ((cpp_function_code)(&logand)), NULL);
      defineFunctionObject("LOGOR", "(DEFUN (LOGOR INTEGER) ((ARG1 INTEGER) (ARG2 INTEGER)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:LOGIOR ARG1 ARG2) :CPP \"(arg1 | arg2)\" :JAVA \"(arg1 | arg2)\")))", ((cpp_function_code)(&logor)), NULL);
      defineFunctionObject("LOGXOR", "(DEFUN (LOGXOR INTEGER) ((ARG1 INTEGER) (ARG2 INTEGER)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:LOGXOR ARG1 ARG2) :CPP \"(arg1 ^ arg2)\" :JAVA \"(arg1 ^ arg2)\")))", ((cpp_function_code)(&logxor)), NULL);
      defineFunctionObject("INTEGER-LENGTH", "(DEFUN (INTEGER-LENGTH INTEGER) ((ARG INTEGER)) :NATIVE? TRUE :PUBLIC? TRUE)", NULL, NULL);
      defineFunctionObject("SHIFT-LEFT", "(DEFUN (SHIFT-LEFT INTEGER) ((ARG INTEGER) (COUNT INTEGER)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:ASH ARG COUNT) :CPP \"(arg << count)\" :JAVA \"(arg << count)\")))", ((cpp_function_code)(&shiftLeft)), NULL);
      defineFunctionObject("SHIFT-RIGHT", "(DEFUN (SHIFT-RIGHT INTEGER) ((ARG INTEGER) (COUNT INTEGER)) :DOCUMENTATION \"Shift `arg' to the right by `count' positions and\n0-extend from the left if `arg' is positive or 1-extend if it is\nnegative.  This is an arithmetic shift that preserve the sign of `arg'\nand is equivalent to dividing `arg' by 2** `count'.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:ASH ARG (CL:THE CL:FIXNUM (CL:- COUNT))) :CPP \"(arg >> count)\" :JAVA \"(arg >> count)\")))", ((cpp_function_code)(&shiftRight)), NULL);
      defineFunctionObject("UNSIGNED-SHIFT-RIGHT-BY-1", "(DEFUN (UNSIGNED-SHIFT-RIGHT-BY-1 INTEGER) ((ARG INTEGER)) :DOCUMENTATION \"Shift `arg' to the right by 1 position and 0-extend\nfrom the left.  This does not preserve the sign of `arg' and shifts\nthe sign-bit just like a regular bit.  In Common-Lisp we can't do that\ndirectly and need to do some extra masking.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (VERBATIM :COMMON-LISP (CL:LOGAND (CL:THE CL:FIXNUM (CL:ASH ARG -1)) *INTEGER-UNSIGNED-BITS-MASK*) :CPP \"((unsigned int)arg >> 1)\" :JAVA \"(arg >>> 1)\")))", ((cpp_function_code)(&unsignedShiftRightBy1)), NULL);
      defineFunctionObject("STELLIFY", "(DEFUN (STELLIFY OBJECT) ((SELF OBJECT)) :DOCUMENTATION \"Convert a Lisp object into a STELLA object.\" :PUBLIC? TRUE)", ((cpp_function_code)(&stellify)), NULL);
      defineFunctionObject("STELLA-OBJECT?", "(DEFUN (STELLA-OBJECT? BOOLEAN) ((SELF OBJECT)) :DOCUMENTATION \"Return true if `self' is a member of the STELLA class `OBJECT'.\")", ((cpp_function_code)(&stellaObjectP)), NULL);
      defineFunctionObject("RUNNING-AS-LISP?", "(DEFUN (RUNNING-AS-LISP? BOOLEAN) () :DOCUMENTATION \"Return true if the executable code is a Common Lisp application.\")", ((cpp_function_code)(&runningAsLispP)), NULL);
      defineFunctionObject("GET-TICKTOCK", "(DEFUN (GET-TICKTOCK TICKTOCK) () :DOCUMENTATION \"Return the current CPU time.  If the current OS/Language\ncombination does not support measuring of CPU time, return real time instead.\nUse `ticktock-difference' to measure the time difference between values\nreturned by this function.  This is an attempt to provide some platform\nindependent support to measure (at least approximately) consumed CPU time.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
      defineFunctionObject("TICKTOCK-DIFFERENCE", "(DEFUN (TICKTOCK-DIFFERENCE FLOAT) ((T1 TICKTOCK) (T2 TICKTOCK)) :DOCUMENTATION \"The difference in two TICKTOCK time values in seconds where\n`t1' is the earlier time.  The resolution is implementation dependent but will\nnormally be some fractional value of a second.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
      defineFunctionObject("TICKTOCK-RESOLUTION", "(DEFUN (TICKTOCK-RESOLUTION FLOAT) () :DOCUMENTATION \"The minimum theoretically detectable resolution of the\ndifference in two TICKTOCK time values in seconds.  This\nresolution is implementation dependent.  It may also not\nbe realizable in practice, since the timing grain size may\nbe larger than this resolution.\" :PUBLIC? TRUE :NATIVE? TRUE)", NULL, NULL);
      defineFunctionObject("SLEEP", "(DEFUN SLEEP ((SECONDS FLOAT)) :DOCUMENTATION \"The program will sleep for the indicated number of seconds.\nFractional values are allowed, but the results are implementation dependent:\nCommon Lisp uses the fractions natively, Java with a resolution of 0.001,\nand C++ can only use integral values.\")", ((cpp_function_code)(&stella::sleep)), NULL);
      defineFunctionObject("EXCEPTION-MESSAGE", "(DEFUN (EXCEPTION-MESSAGE STRING) ((E NATIVE-EXCEPTION)) :PUBLIC? TRUE :DOCUMENTATION \"Accesses the error message of the exception `e'.\")", ((cpp_function_code)(&exceptionMessage)), NULL);
      defineFunctionObject("PRINT-EXCEPTION-CONTEXT", "(DEFUN PRINT-EXCEPTION-CONTEXT ((E NATIVE-EXCEPTION) (STREAM OUTPUT-STREAM)) :PUBLIC? TRUE :DOCUMENTATION \"Prints a system dependent information about the context of the specified\nexception.  For example, in Java it prints a stack trace.  In Lisp, it is vendor dependent.\")", ((cpp_function_code)(&printExceptionContext)), NULL);
      defineFunctionObject("MAKE-PROCESS-LOCK", "(DEFUN (MAKE-PROCESS-LOCK PROCESS-LOCK-OBJECT) () :PUBLIC? TRUE)", ((cpp_function_code)(&makeProcessLock)), NULL);
      defineFunctionObject("STARTUP-PRIMAL", "(DEFUN STARTUP-PRIMAL () :PUBLIC? TRUE)", ((cpp_function_code)(&startupPrimal)), NULL);
      { MethodSlot* function = lookupFunction(SYM_PRIMAL_STELLA_STARTUP_PRIMAL);

        setDynamicSlotValue(function->dynamicSlots, SYM_PRIMAL_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Primal"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT TRUE BOOLEAN (VERBATIM :COMMON-LISP CL:T :CPP \"1\" :JAVA \"true\") :PUBLIC? TRUE :DOCUMENTATION \"Represents the boolean true truth value.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT FALSE BOOLEAN (VERBATIM :COMMON-LISP CL:NIL :CPP \"0\" :JAVA \"false\") :PUBLIC? TRUE :DOCUMENTATION \"Represents the boolean false truth value.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT PI FLOAT (VERBATIM :COMMON-LISP \"(cl:float CL:PI 0.0d0)\" :CPP \"3.141592653589793\" :JAVA \"java.lang.Math.PI\") :PUBLIC? TRUE :DOCUMENTATION \"A float approximation of the mathematical constant pi.\")");
      defineStellaGlobalVariableFromStringifiedSource("(defconstant NULL UNKNOWN NULL\n       :public? TRUE\n       :documentation\n       \"Generic undefined value for any STELLA data type.  The STELLA\ntranslator substitutes specific NULL-values appropriate for a particular data\ntype.  For example, NULL-INTEGER represents the undefined INTEGER value.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NULL-INTEGER INTEGER (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-FIXNUM :CPP \"1 << (sizeof (int) / sizeof (char) * 8 - 1)\" :JAVA \"Integer.MIN_VALUE\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NULL-SHORT-INTEGER SHORT-INTEGER (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-FIXNUM :CPP \"1 << (sizeof (short int) / sizeof (char) * 8 - 1)\" :JAVA \"Short.MIN_VALUE\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NULL-LONG-INTEGER LONG-INTEGER (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-FIXNUM :CPP \"1 << (sizeof (long int) / sizeof (char) * 8 - 1)\" :JAVA \"Long.MIN_VALUE\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NULL-UNSIGNED-SHORT-INTEGER UNSIGNED-SHORT-INTEGER (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-FIXNUM :CPP \"(unsigned short int) -1\" :JAVA \"Short.MIN_VALUE\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NULL-UNSIGNED-LONG-INTEGER UNSIGNED-LONG-INTEGER (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-FIXNUM :CPP \"(unsigned long int) -1\" :JAVA \"Long.MIN_VALUE\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NULL-FLOAT FLOAT (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-DOUBLE-FLOAT :CPP \"-HUGE_VAL /* IEEE infinity, defined in <math.h> */\" :JAVA \"Double.NEGATIVE_INFINITY; /* IEEE Infinity */\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NULL-SINGLE-FLOAT SINGLE-FLOAT (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-SINGLE-FLOAT :CPP \"-HUGE_VAL /* IEEE infinity, defined in <math.h> */\" :JAVA \"Float.NEGATIVE_INFINITY; /* IEEE Infinity */\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NULL-DOUBLE-FLOAT DOUBLE-FLOAT (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-DOUBLE-FLOAT :CPP \"-HUGE_VAL /* IEEE infinity, defined in <math.h> */\" :JAVA \"Double.NEGATIVE_INFINITY; /* IEEE Infinity */\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NULL-CHARACTER CHARACTER (VERBATIM :COMMON-LISP (CL:CODE-CHAR 0) :CPP \"'\\\\0'\" :JAVA \"Character.MIN_VALUE\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NULL-BYTE BYTE (VERBATIM :COMMON-LISP \"255\" :CPP \"255\" :JAVA \"-128\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NULL-OCTET OCTET (VERBATIM :COMMON-LISP \"255\" :CPP \"255\" :JAVA \"-128\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT RECIPROCAL-NL10 FLOAT (/ 1.0 (LOG 10.0)) :DOCUMENTATION \"1 / (log 10) Reciprocal of the Log base e of 10.\nUsed for log 10 conversions.\")");
      registerNativeName(SYM_PRIMAL_STELLA_FLOOR, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_ROUND, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_RANDOM, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_SQRT, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_COS, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_SIN, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_TAN, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_ACOS, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_ASIN, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_ATAN, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_ATAN2, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_EXP, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_LOG, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_MIN, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      registerNativeName(SYM_PRIMAL_STELLA_MAX, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *TRANSIENTOBJECTS?* BOOLEAN FALSE :PUBLIC? TRUE)");
      registerNativeName(SYM_PRIMAL_STELLA_HASH_CODE, KWD_PRIMAL_JAVA, KWD_PRIMAL_FUNCTION);
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *HASH-BYTE-RANDOM-TABLE* (ARRAY (256) OF INTEGER) NULL :DOCUMENTATION \"A table of 256 26-bit random numbers that can be used to\nhash sequences of bytes.  Each bit-column in the table has an approximately\neven number of 0's and 1's.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT *INTEGER-MSB-MASK* INTEGER (VERBATIM :COMMON-LISP \"#.(CL:ash 1 (CL:1- (CL:integer-length CL:most-positive-fixnum)))\" :CPP \"1 << (sizeof (int) / sizeof (char) * 8 - 1)\" :JAVA \"0x80000000\") :DOCUMENTATION \"The most significant bit of a regular integer (FIXNUM\nin Common-Lisp).  In C++ and Java this corresponds to the sign bit, in\nLisp this corresponds to the left-most bit of `CL:most-positive-fixnum'.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT *INTEGER-UNSIGNED-BITS-MASK* INTEGER (VERBATIM :COMMON-LISP (CL:LOGIOR (CL:1- *INTEGER-MSB-MASK*) *INTEGER-MSB-MASK*) :OTHERWISE (LOGNOT *INTEGER-MSB-MASK*)) :DOCUMENTATION \"Mask that covers all the unsigned bits of an integer.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *HASH-TABLE-SIZE-PRIMES* (VECTOR OF INTEGER-WRAPPER) NULL :DOCUMENTATION \"List of prime numbers approximately growing by a factor of 2\nthat are suitable to be used as hash table sizes.\" :PUBLIC? TRUE)");
      registerNativeName(SYM_PRIMAL_STELLA_SLEEP, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *BOOTSTRAP-LOCK* PROCESS-LOCK-OBJECT (VERBATIM :COMMON-LISP \"(%make-process-lock)\" :JAVA \"new java.lang.Object()\" :CPP \"NULL\") :PUBLIC? TRUE :DOCUMENTATION \"Process lock object for bootstrap use.\")");
    }
  }
}

Symbol* SYM_PRIMAL_STELLA_FLOOR = NULL;

Keyword* KWD_PRIMAL_CPP = NULL;

Keyword* KWD_PRIMAL_FUNCTION = NULL;

Symbol* SYM_PRIMAL_STELLA_ROUND = NULL;

Symbol* SYM_PRIMAL_STELLA_RANDOM = NULL;

Symbol* SYM_PRIMAL_STELLA_SQRT = NULL;

Symbol* SYM_PRIMAL_STELLA_COS = NULL;

Symbol* SYM_PRIMAL_STELLA_SIN = NULL;

Symbol* SYM_PRIMAL_STELLA_TAN = NULL;

Symbol* SYM_PRIMAL_STELLA_ACOS = NULL;

Symbol* SYM_PRIMAL_STELLA_ASIN = NULL;

Symbol* SYM_PRIMAL_STELLA_ATAN = NULL;

Symbol* SYM_PRIMAL_STELLA_ATAN2 = NULL;

Symbol* SYM_PRIMAL_STELLA_EXP = NULL;

Symbol* SYM_PRIMAL_STELLA_LOG = NULL;

Symbol* SYM_PRIMAL_STELLA_MIN = NULL;

Symbol* SYM_PRIMAL_STELLA_MAX = NULL;

Keyword* KWD_PRIMAL_UPCASE = NULL;

Keyword* KWD_PRIMAL_DOWNCASE = NULL;

Keyword* KWD_PRIMAL_CAPITALIZE = NULL;

Keyword* KWD_PRIMAL_PRESERVE = NULL;

Keyword* KWD_PRIMAL_LEFT = NULL;

Keyword* KWD_PRIMAL_RIGHT = NULL;

Keyword* KWD_PRIMAL_CENTER = NULL;

Symbol* SYM_PRIMAL_STELLA_HASH_CODE = NULL;

Keyword* KWD_PRIMAL_JAVA = NULL;

Symbol* SYM_PRIMAL_STELLA_SLEEP = NULL;

Symbol* SYM_PRIMAL_STELLA_STARTUP_PRIMAL = NULL;

Symbol* SYM_PRIMAL_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace stella
