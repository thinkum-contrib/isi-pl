//  -*- Mode: C++ -*-

// sequence-indices.cc

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
 | The Original Code is the PowerLoom KR&R System.                            |
 |                                                                            |
 | The Initial Developer of the Original Code is                              |
 | UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
 | 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
 |                                                                            |
 | Portions created by the Initial Developer are Copyright (C) 1997-2006      |
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
 +----------------------------- END LICENSE BLOCK ----------------------------+
*/

#include "logic/logic-system.hh"

namespace logic {
  using namespace stella;

Object* accessSequenceIndexSlotValue(SequenceIndex* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_SEQUENCE_INDICES_LOGIC_THE_SEQUENCE) {
    if (setvalueP) {
      self->theSequence = ((Cons*)(value));
    }
    else {
      value = self->theSequence;
    }
  }
  else if (slotname == SYM_SEQUENCE_INDICES_LOGIC_THE_SEQUENCE_LENGTH) {
    if (setvalueP) {
      self->theSequenceLength = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->theSequenceLength);
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

void SequenceIndex::printObject(std::ostream* stream) {
  { SequenceIndex* self = this;

    printSequenceIndex(self, stream);
  }
}

NonPagingIndex* newNonPagingIndex() {
  { NonPagingIndex* self = NULL;

    self = new NonPagingIndex();
    self->theSequenceLength = NULL_INTEGER;
    self->theSequence = NIL;
    return (self);
  }
}

Surrogate* NonPagingIndex::primaryType() {
  { NonPagingIndex* self = this;

    return (SGT_SEQUENCE_INDICES_LOGIC_NON_PAGING_INDEX);
  }
}

PagingIndex* newPagingIndex() {
  { PagingIndex* self = NULL;

    self = new PagingIndex();
    self->theSequenceLength = NULL_INTEGER;
    self->theSequence = NIL;
    self->store = NULL;
    self->selectionPattern = NULL;
    return (self);
  }
}

Surrogate* PagingIndex::primaryType() {
  { PagingIndex* self = this;

    return (SGT_SEQUENCE_INDICES_LOGIC_PAGING_INDEX);
  }
}

Object* accessPagingIndexSlotValue(PagingIndex* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_SEQUENCE_INDICES_LOGIC_SELECTION_PATTERN) {
    if (setvalueP) {
      self->selectionPattern = ((Cons*)(value));
    }
    else {
      value = self->selectionPattern;
    }
  }
  else if (slotname == SYM_SEQUENCE_INDICES_LOGIC_STORE) {
    if (setvalueP) {
      self->store = ((ObjectStore*)(value));
    }
    else {
      value = self->store;
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

void PagingIndex::printObject(std::ostream* stream) {
  { PagingIndex* self = this;

    printPagingIndex(self, stream);
  }
}

// Returns a non-writable empty sequence.
NonPagingIndex* NIL_NON_PAGING_INDEX = NULL;

// Returns a non-writable empty sequence.
PagingIndex* NIL_PAGING_INDEX = NULL;

void SequenceIndex::insert(Object* value) {
  { SequenceIndex* self = this;

    if (!(!(self == NIL_NON_PAGING_INDEX))) {
      std::cerr << "Safety violation: " << "Attempt to insert into NIL-NON-PAGING-INDEX";
    }
    self->theSequence = cons(value, self->theSequence);
    { int length = self->theSequenceLength;

      if (length != NULL_INTEGER) {
        self->theSequenceLength = length + 1;
      }
    }
  }
}

void SequenceIndex::push(Object* value) {
  { SequenceIndex* self = this;

    self->insert(value);
  }
}

Object* SequenceIndex::first() {
  { SequenceIndex* self = this;

    { Object* item = NULL;
      Iterator* iter000 = self->allocateIterator();

      for (item, iter000; iter000->nextP(); ) {
        item = iter000->value;
        return (item);
      }
    }
    return (NULL);
  }
}

boolean SequenceIndex::emptyP() {
  { SequenceIndex* self = this;

    if (self->theSequence == NIL) {
      return (true);
    }
    if (!self->theSequence->value->deletedP()) {
      return (false);
    }
    self->removeDeletedMembers();
    return (self->theSequence == NIL);
  }
}

int SequenceIndex::estimatedLength() {
  { SequenceIndex* self = this;

    return (sequenceIndexDestimatedLength(self));
  }
}

int sequenceIndexDestimatedLength(SequenceIndex* self) {
  { int length = self->theSequenceLength;

    if (length == NULL_INTEGER) {
      length = self->theSequence->length();
      self->theSequenceLength = length;
    }
    return (length);
  }
}

SequenceIndex* SequenceIndex::removeDeletedMembers() {
  { SequenceIndex* self = this;

    { Cons* sequence = self->theSequence->removeDeletedMembers();

      self->theSequence = sequence;
      self->theSequenceLength = NULL_INTEGER;
      return (self);
    }
  }
}

SequenceIndex* SequenceIndex::remove(Object* value) {
  { SequenceIndex* self = this;

    self->theSequence = self->theSequence->remove(value);
    self->theSequenceLength = NULL_INTEGER;
    return (self);
  }
}

Cons* SequenceIndex::consify() {
  { SequenceIndex* self = this;

    { Cons* value000 = NIL;

      { Object* i = NULL;
        Iterator* iter000 = self->allocateIterator();
        Cons* collect000 = NULL;

        for  (i, iter000, collect000; 
              iter000->nextP(); ) {
          i = iter000->value;
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(i, NIL);
              if (value000 == NIL) {
                value000 = collect000;
              }
              else {
                addConsToEndOfConsList(value000, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(i, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      { Cons* value001 = value000;

        return (value001);
      }
    }
  }
}

void printSequenceIndex(SequenceIndex* self, std::ostream* stream) {
  { int limit = 10;

    *(stream) << "|SEQ-IDX|(";
    { Object* elt = NULL;
      Cons* iter000 = self->theSequence;
      int i = NULL_INTEGER;
      int iter001 = 1;
      int upperBound000 = limit;
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;

      for  (elt, iter000, i, iter001, upperBound000, unboundedP000; 
            (!(iter000 == NIL)) &&
                (unboundedP000 ||
                 (iter001 <= upperBound000)); 
            iter000 = iter000->rest,
            iter001 = iter001 + 1) {
        elt = iter000->value;
        i = iter001;
        if (i > 1) {
          *(stream) << " ";
        }
        *(stream) << elt;
        if (i == limit) {
          *(stream) << "...";
        }
      }
    }
    *(stream) << ")";
  }
}

SequenceIndexIterator* newSequenceIndexIterator() {
  { SequenceIndexIterator* self = NULL;

    self = new SequenceIndexIterator();
    self->firstIterationP = true;
    self->value = NULL;
    self->listIteratorCursor = NULL;
    return (self);
  }
}

Surrogate* SequenceIndexIterator::primaryType() {
  { SequenceIndexIterator* self = this;

    return (SGT_SEQUENCE_INDICES_LOGIC_SEQUENCE_INDEX_ITERATOR);
  }
}

Object* accessSequenceIndexIteratorSlotValue(SequenceIndexIterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_SEQUENCE_INDICES_STELLA_LIST_ITERATOR_CURSOR) {
    if (setvalueP) {
      self->listIteratorCursor = ((Cons*)(value));
    }
    else {
      value = self->listIteratorCursor;
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

Iterator* SequenceIndex::allocateIterator() {
  { SequenceIndex* self = this;

    { SequenceIndexIterator* self000 = newSequenceIndexIterator();

      self000->listIteratorCursor = self->theSequence;
      { SequenceIndexIterator* value000 = self000;

        return (value000);
      }
    }
  }
}

boolean SequenceIndexIterator::nextP() {
  { SequenceIndexIterator* self = this;

    { Cons* cursor = self->listIteratorCursor;
      Object* value = NULL;

      for (;;) {
        if (cursor == NIL) {
          return (false);
        }
        value = cursor->value;
        if (!value->deletedP()) {
          self->value = value;
          self->listIteratorCursor = cursor->rest;
          return (true);
        }
        cursor = cursor->rest;
      }
    }
  }
}

boolean SequenceIndexIterator::emptyP() {
  { SequenceIndexIterator* self = this;

    return (self->listIteratorCursor == NIL);
  }
}

NonPagingIndex* NonPagingIndex::copy() {
  { NonPagingIndex* self = this;

    { NonPagingIndex* self000 = newNonPagingIndex();

      self000->theSequence = copyConsList(self->theSequence);
      { NonPagingIndex* value000 = self000;

        return (value000);
      }
    }
  }
}

void NonPagingIndex::clear() {
  { NonPagingIndex* self = this;

    self->theSequence = NIL;
  }
}

void PagingIndex::insert(Object* value) {
  { PagingIndex* self = this;

    if (!(!(self == NIL_PAGING_INDEX))) {
      std::cerr << "Safety violation: " << "Attempt to insert into NIL-PAGING-INDEX";
    }
    self->theSequence = cons(value, self->theSequence);
  }
}

void PagingIndex::push(Object* value) {
  { PagingIndex* self = this;

    self->insert(value);
  }
}

int PagingIndex::estimatedLength() {
  // Return the estimated length of the sequences in 'self',
  // which could be too large if some of the members have been deleted.
  { PagingIndex* self = this;

    { int length = self->theSequenceLength;

      if (length == NULL_INTEGER) {
        length = self->theSequence->length();
        self->theSequenceLength = length;
      }
      return (length);
    }
  }
}

SequenceIndex* PagingIndex::removeDeletedMembers() {
  // Destructively remove all deleted members of `self'.
  { PagingIndex* self = this;

    { Cons* sequence = self->theSequence->removeDeletedMembers();

      self->theSequence = sequence;
      self->theSequenceLength = NULL_INTEGER;
      return (self);
    }
  }
}

SequenceIndex* PagingIndex::remove(Object* value) {
  { PagingIndex* self = this;

    { Cons* sequence = self->theSequence->remove(value);

      self->theSequence = sequence;
      self->theSequenceLength = NULL_INTEGER;
      return (self);
    }
  }
}

void printPagingIndex(PagingIndex* self, std::ostream* stream) {
  { int limit = 10;

    *(stream) << "|PAGING-IDX|(" << self->selectionPattern;
    { Object* elt = NULL;
      Cons* iter000 = self->theSequence;
      int i = NULL_INTEGER;
      int iter001 = 1;
      int upperBound000 = limit;
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;

      for  (elt, iter000, i, iter001, upperBound000, unboundedP000; 
            (!(iter000 == NIL)) &&
                (unboundedP000 ||
                 (iter001 <= upperBound000)); 
            iter000 = iter000->rest,
            iter001 = iter001 + 1) {
        elt = iter000->value;
        i = iter001;
        *(stream) << " " << elt;
        if (i == limit) {
          *(stream) << "...";
        }
      }
    }
    *(stream) << ")";
  }
}

PagingIndexIterator* newPagingIndexIterator() {
  { PagingIndexIterator* self = NULL;

    self = new PagingIndexIterator();
    self->firstIterationP = true;
    self->value = NULL;
    self->listIteratorCursor = NULL;
    return (self);
  }
}

Surrogate* PagingIndexIterator::primaryType() {
  { PagingIndexIterator* self = this;

    return (SGT_SEQUENCE_INDICES_LOGIC_PAGING_INDEX_ITERATOR);
  }
}

Iterator* PagingIndex::allocateIterator() {
  { PagingIndex* self = this;

    { PagingIndexIterator* self000 = newPagingIndexIterator();

      self000->listIteratorCursor = self->theSequence;
      { PagingIndexIterator* value000 = self000;

        return (value000);
      }
    }
  }
}

Object* accessObjectStoreSlotValue(ObjectStore* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_SEQUENCE_INDICES_STELLA_MODULE) {
    if (setvalueP) {
      self->module = ((Module*)(value));
    }
    else {
      value = self->module;
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

// If TRUE, objects being created are regenerable,
// and should not be indexed using the backlinks procedures.
DEFINE_STELLA_SPECIAL(oLOADINGREGENERABLEOBJECTSpo, boolean , false);

ObjectStore* homeObjectStore(Object* self) {
  { Module* module = self->homeModule();

    return ((((boolean)(module)) ? ((ObjectStore*)(dynamicSlotValue(module->dynamicSlots, SYM_SEQUENCE_INDICES_LOGIC_OBJECT_STORE, NULL))) : NULL));
  }
}

SequenceIndex* createSequenceIndex(Object* self, Cons* pattern) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfKeywordP(testValue000)) {
      { Object* self000 = self;
        Keyword* self = ((Keyword*)(self000));

        return (keywordDcreateSequenceIndex(self, pattern));
      }
    }
    else if (subtypeOfP(testValue000, SGT_SEQUENCE_INDICES_STELLA_MODULE)) {
      { Object* self001 = self;
        Module* self = ((Module*)(self001));

        return (moduleDcreateSequenceIndex(self, pattern));
      }
    }
    else if (subtypeOfP(testValue000, SGT_SEQUENCE_INDICES_LOGIC_OBJECT_STORE)) {
      { Object* self002 = self;
        ObjectStore* self = ((ObjectStore*)(self002));

        return (self->objectStoreDcreateSequenceIndex(pattern));
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Don't know how to create a sequence index on " << "`" << self << "'";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

SequenceIndex* keywordDcreateSequenceIndex(Keyword* kind, Cons* pattern) {
  if (kind == KWD_SEQUENCE_INDICES_PAGING) {
    { Object* anchor = pattern->rest->rest->value;
      ObjectStore* store = NULL;

      if (!((boolean)(anchor))) {
        std::cerr << "Safety violation: " << "Null argument passed into paging index pattern";
      }
      store = homeObjectStore(anchor);
      if (((boolean)(store))) {
        return (createSequenceIndex(store, pattern));
      }
      else {
        return (newNonPagingIndex());
      }
    }
  }
  else if (kind == KWD_SEQUENCE_INDICES_NON_PAGING) {
    return (newNonPagingIndex());
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << kind << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

SequenceIndex* moduleDcreateSequenceIndex(Module* module, Cons* pattern) {
  { ObjectStore* store = ((ObjectStore*)(dynamicSlotValue(module->dynamicSlots, SYM_SEQUENCE_INDICES_LOGIC_OBJECT_STORE, NULL)));

    if (((boolean)(store))) {
      return (createSequenceIndex(store, pattern));
    }
    else {
      return (createSequenceIndex(KWD_SEQUENCE_INDICES_PAGING, pattern));
    }
  }
}

SequenceIndex* ObjectStore::objectStoreDcreateSequenceIndex(Cons* pattern) {
  { ObjectStore* store = this;

    { PagingIndex* self000 = newPagingIndex();

      self000->store = store;
      self000->selectionPattern = pattern;
      { PagingIndex* value000 = self000;

        return (value000);
      }
    }
  }
}

NamedDescription* ObjectStore::fetchRelation(Object* name) {
  // Fetch the relation identified by `name' (a string or symbol) from `store'
  // and return it as a named description.  This needs to be appropriately 
  // specialized on actual OBJECT-STORE implementations.
  { ObjectStore* store = this;

    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "Don't know how to fetch relation " << "`" << name << "'" << " from " << "`" << store << "'";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

Object* ObjectStore::fetchInstance(Object* name) {
  // Fetch the instance identified by `name' (a string or symbol) from `store'
  // and return it as an appropriate logic object.  This needs to be appropriately
  // specialized on actual OBJECT-STORE implementations.
  { ObjectStore* store = this;

    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "Don't know how to fetch instance " << "`" << name << "'" << " from " << "`" << store << "'";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

void ObjectStore::updatePropositionInStore(Proposition* proposition, Keyword* updateMode) {
  // A module with `store' has had the truth value of `proposition'
  // change according to `update-mode'.  The default method does nothing.
  { ObjectStore* store = this;

    {
      proposition = proposition;
      updateMode = updateMode;
    }
    return;
  }
}

void helpStartupSequenceIndices1() {
  {
    SYM_SEQUENCE_INDICES_LOGIC_SELECTION_PATTERN = ((Symbol*)(internRigidSymbolWrtModule("SELECTION-PATTERN", NULL, 0)));
    SYM_SEQUENCE_INDICES_LOGIC_THE_SEQUENCE = ((Symbol*)(internRigidSymbolWrtModule("THE-SEQUENCE", NULL, 0)));
    SYM_SEQUENCE_INDICES_LOGIC_THE_SEQUENCE_LENGTH = ((Symbol*)(internRigidSymbolWrtModule("THE-SEQUENCE-LENGTH", NULL, 0)));
    SGT_SEQUENCE_INDICES_LOGIC_NON_PAGING_INDEX = ((Surrogate*)(internRigidSymbolWrtModule("NON-PAGING-INDEX", NULL, 1)));
    SGT_SEQUENCE_INDICES_LOGIC_PAGING_INDEX = ((Surrogate*)(internRigidSymbolWrtModule("PAGING-INDEX", NULL, 1)));
    SYM_SEQUENCE_INDICES_LOGIC_STORE = ((Symbol*)(internRigidSymbolWrtModule("STORE", NULL, 0)));
    SGT_SEQUENCE_INDICES_LOGIC_SEQUENCE_INDEX_ITERATOR = ((Surrogate*)(internRigidSymbolWrtModule("SEQUENCE-INDEX-ITERATOR", NULL, 1)));
    SYM_SEQUENCE_INDICES_STELLA_LIST_ITERATOR_CURSOR = ((Symbol*)(internRigidSymbolWrtModule("LIST-ITERATOR-CURSOR", getStellaModule("/STELLA", true), 0)));
    SGT_SEQUENCE_INDICES_LOGIC_PAGING_INDEX_ITERATOR = ((Surrogate*)(internRigidSymbolWrtModule("PAGING-INDEX-ITERATOR", NULL, 1)));
    SYM_SEQUENCE_INDICES_STELLA_MODULE = ((Symbol*)(internRigidSymbolWrtModule("MODULE", getStellaModule("/STELLA", true), 0)));
    SYM_SEQUENCE_INDICES_LOGIC_OBJECT_STORE = ((Symbol*)(internRigidSymbolWrtModule("OBJECT-STORE", NULL, 0)));
    SGT_SEQUENCE_INDICES_STELLA_MODULE = ((Surrogate*)(internRigidSymbolWrtModule("MODULE", getStellaModule("/STELLA", true), 1)));
    SGT_SEQUENCE_INDICES_LOGIC_OBJECT_STORE = ((Surrogate*)(internRigidSymbolWrtModule("OBJECT-STORE", NULL, 1)));
    KWD_SEQUENCE_INDICES_PAGING = ((Keyword*)(internRigidSymbolWrtModule("PAGING", NULL, 2)));
    KWD_SEQUENCE_INDICES_NON_PAGING = ((Keyword*)(internRigidSymbolWrtModule("NON-PAGING", NULL, 2)));
    SYM_SEQUENCE_INDICES_LOGIC_STARTUP_SEQUENCE_INDICES = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-SEQUENCE-INDICES", NULL, 0)));
    SYM_SEQUENCE_INDICES_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", true), 0)));
  }
}

void startupSequenceIndices() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupSequenceIndices1();
    }
    if (currentStartupTimePhaseP(4)) {
      NIL_NON_PAGING_INDEX = newNonPagingIndex();
      { PagingIndex* self001 = newPagingIndex();

        self001->selectionPattern = getQuotedTree("((:NIL-SEQUENCE) \"/LOGIC\")", "/LOGIC");
        NIL_PAGING_INDEX = self001;
      }
    }
    if (currentStartupTimePhaseP(5)) {
      defineStellaTypeFromStringifiedSource("(DEFTYPE SELECTION-PATTERN CONS)");
      { Class* clasS = defineClassFromStringifiedSource("SEQUENCE-INDEX", "(DEFCLASS SEQUENCE-INDEX (STANDARD-OBJECT) :DOCUMENTATION \"Abstract class for managing a sequence of objects.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :ABSTRACT? TRUE :SLOTS ((THE-SEQUENCE :TYPE CONS :INITIALLY NIL) (THE-SEQUENCE-LENGTH :TYPE INTEGER :INITIALLY NULL)) :PRINT-FORM (PRINT-SEQUENCE-INDEX SELF STREAM))");

        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessSequenceIndexSlotValue));
      }
      { Class* clasS = defineClassFromStringifiedSource("NON-PAGING-INDEX", "(DEFCLASS NON-PAGING-INDEX (SEQUENCE-INDEX) :DOCUMENTATION \"Index that manages an always-in-memory data\nstrucure containing a sequence of objects.\")");

        clasS->classConstructorCode = ((cpp_function_code)(&newNonPagingIndex));
      }
      { Class* clasS = defineClassFromStringifiedSource("PAGING-INDEX", "(DEFCLASS PAGING-INDEX (SEQUENCE-INDEX) :DOCUMENTATION \"Index that manages a sequence of objects retrievable from\npersistent storage.  Needs to be appropriately subclassed by actual store\nimplementations and facilitated with a proper iterator class.\" :SLOTS ((SELECTION-PATTERN :TYPE SELECTION-PATTERN) (STORE :TYPE OBJECT-STORE)) :PRINT-FORM (PRINT-PAGING-INDEX SELF STREAM))");

        clasS->classConstructorCode = ((cpp_function_code)(&newPagingIndex));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessPagingIndexSlotValue));
      }
      { Class* clasS = defineClassFromStringifiedSource("SEQUENCE-INDEX-ITERATOR", "(DEFCLASS SEQUENCE-INDEX-ITERATOR (ITERATOR) :DOCUMENTATION \"Iterator that generates successive members of a sequence index.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((LIST-ITERATOR-CURSOR :TYPE CONS)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newSequenceIndexIterator));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessSequenceIndexIteratorSlotValue));
      }
      { Class* clasS = defineClassFromStringifiedSource("PAGING-INDEX-ITERATOR", "(DEFCLASS PAGING-INDEX-ITERATOR (SEQUENCE-INDEX-ITERATOR) :DOCUMENTATION \"Iterator that generates successive members of a paging index.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newPagingIndexIterator));
      }
      { Class* clasS = defineClassFromStringifiedSource("OBJECT-STORE", "(DEFCLASS OBJECT-STORE (STANDARD-OBJECT) :ABSTRACT? TRUE :SLOTS ((MODULE :TYPE MODULE)))");

        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessObjectStoreSlotValue));
      }
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineMethodObject("(DEFMETHOD INSERT ((SELF SEQUENCE-INDEX) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)", ((cpp_method_code)(&SequenceIndex::insert)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD PUSH ((SELF SEQUENCE-INDEX) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)", ((cpp_method_code)(&SequenceIndex::push)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (FIRST OBJECT) ((SELF SEQUENCE-INDEX)) :PUBLIC? TRUE)", ((cpp_method_code)(&SequenceIndex::first)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (EMPTY? BOOLEAN) ((SELF SEQUENCE-INDEX)) :PUBLIC? TRUE)", ((cpp_method_code)(&SequenceIndex::emptyP)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (ESTIMATED-LENGTH INTEGER) ((SELF SEQUENCE-INDEX)))", ((cpp_method_code)(&SequenceIndex::estimatedLength)), ((cpp_method_code)(NULL)));
      defineFunctionObject("SEQUENCE-INDEX.ESTIMATED-LENGTH", "(DEFUN (SEQUENCE-INDEX.ESTIMATED-LENGTH INTEGER) ((SELF SEQUENCE-INDEX)))", ((cpp_function_code)(&sequenceIndexDestimatedLength)), NULL);
      defineMethodObject("(DEFMETHOD (REMOVE-DELETED-MEMBERS (LIKE SELF)) ((SELF SEQUENCE-INDEX)) :PUBLIC? TRUE)", ((cpp_method_code)(&SequenceIndex::removeDeletedMembers)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (REMOVE (LIKE SELF)) ((SELF SEQUENCE-INDEX) (VALUE OBJECT)))", ((cpp_method_code)(&SequenceIndex::remove)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (CONSIFY (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF SEQUENCE-INDEX)))", ((cpp_method_code)(&SequenceIndex::consify)), ((cpp_method_code)(NULL)));
      defineFunctionObject("PRINT-SEQUENCE-INDEX", "(DEFUN PRINT-SEQUENCE-INDEX ((SELF SEQUENCE-INDEX) (STREAM NATIVE-OUTPUT-STREAM)))", ((cpp_function_code)(&printSequenceIndex)), NULL);
      defineMethodObject("(DEFMETHOD (ALLOCATE-ITERATOR (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF SEQUENCE-INDEX)))", ((cpp_method_code)(&SequenceIndex::allocateIterator)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF SEQUENCE-INDEX-ITERATOR)))", ((cpp_method_code)(&SequenceIndexIterator::nextP)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (EMPTY? BOOLEAN) ((SELF SEQUENCE-INDEX-ITERATOR)))", ((cpp_method_code)(&SequenceIndexIterator::emptyP)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (COPY NON-PAGING-INDEX) ((SELF NON-PAGING-INDEX)))", ((cpp_method_code)(&NonPagingIndex::copy)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD CLEAR ((SELF NON-PAGING-INDEX)))", ((cpp_method_code)(&NonPagingIndex::clear)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD INSERT ((SELF PAGING-INDEX) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)", ((cpp_method_code)(&PagingIndex::insert)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD PUSH ((SELF PAGING-INDEX) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)", ((cpp_method_code)(&PagingIndex::push)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (ESTIMATED-LENGTH INTEGER) ((SELF PAGING-INDEX)) :DOCUMENTATION \"Return the estimated length of the sequences in 'self',\nwhich could be too large if some of the members have been deleted.\" :PUBLIC? TRUE)", ((cpp_method_code)(&PagingIndex::estimatedLength)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (REMOVE-DELETED-MEMBERS (LIKE SELF)) ((SELF PAGING-INDEX)) :DOCUMENTATION \"Destructively remove all deleted members of `self'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&PagingIndex::removeDeletedMembers)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (REMOVE (LIKE SELF)) ((SELF PAGING-INDEX) (VALUE OBJECT)))", ((cpp_method_code)(&PagingIndex::remove)), ((cpp_method_code)(NULL)));
      defineFunctionObject("PRINT-PAGING-INDEX", "(DEFUN PRINT-PAGING-INDEX ((SELF PAGING-INDEX) (STREAM NATIVE-OUTPUT-STREAM)))", ((cpp_function_code)(&printPagingIndex)), NULL);
      defineMethodObject("(DEFMETHOD (ALLOCATE-ITERATOR (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF PAGING-INDEX)))", ((cpp_method_code)(&PagingIndex::allocateIterator)), ((cpp_method_code)(NULL)));
      defineExternalSlotFromStringifiedSource("(DEFSLOT MODULE OBJECT-STORE :TYPE OBJECT-STORE :ALLOCATION :DYNAMIC)");
      defineFunctionObject("HOME-OBJECT-STORE", "(DEFUN (HOME-OBJECT-STORE OBJECT-STORE) ((SELF OBJECT)))", ((cpp_function_code)(&homeObjectStore)), NULL);
      defineFunctionObject("CREATE-SEQUENCE-INDEX", "(DEFUN (CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ((SELF OBJECT) (PATTERN SELECTION-PATTERN)))", ((cpp_function_code)(&createSequenceIndex)), NULL);
      defineFunctionObject("KEYWORD.CREATE-SEQUENCE-INDEX", "(DEFUN (KEYWORD.CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ((KIND KEYWORD) (PATTERN SELECTION-PATTERN)))", ((cpp_function_code)(&keywordDcreateSequenceIndex)), NULL);
      defineFunctionObject("MODULE.CREATE-SEQUENCE-INDEX", "(DEFUN (MODULE.CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ((MODULE MODULE) (PATTERN SELECTION-PATTERN)))", ((cpp_function_code)(&moduleDcreateSequenceIndex)), NULL);
      defineMethodObject("(DEFMETHOD (OBJECT-STORE.CREATE-SEQUENCE-INDEX SEQUENCE-INDEX) ((STORE OBJECT-STORE) (PATTERN SELECTION-PATTERN)))", ((cpp_method_code)(&ObjectStore::objectStoreDcreateSequenceIndex)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (FETCH-RELATION NAMED-DESCRIPTION) ((STORE OBJECT-STORE) (NAME OBJECT)) :DOCUMENTATION \"Fetch the relation identified by `name' (a string or symbol) from `store'\nand return it as a named description.  This needs to be appropriately \nspecialized on actual OBJECT-STORE implementations.\" :PUBLIC? TRUE)", ((cpp_method_code)(&ObjectStore::fetchRelation)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (FETCH-INSTANCE OBJECT) ((STORE OBJECT-STORE) (NAME OBJECT)) :DOCUMENTATION \"Fetch the instance identified by `name' (a string or symbol) from `store'\nand return it as an appropriate logic object.  This needs to be appropriately\nspecialized on actual OBJECT-STORE implementations.\" :PUBLIC? TRUE)", ((cpp_method_code)(&ObjectStore::fetchInstance)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD UPDATE-PROPOSITION-IN-STORE ((STORE OBJECT-STORE) (PROPOSITION PROPOSITION) (UPDATE-MODE KEYWORD)) :DOCUMENTATION \"A module with `store' has had the truth value of `proposition'\nchange according to `update-mode'.  The default method does nothing.\" :PUBLIC? TRUE)", ((cpp_method_code)(&ObjectStore::updatePropositionInStore)), ((cpp_method_code)(NULL)));
      defineFunctionObject("STARTUP-SEQUENCE-INDICES", "(DEFUN STARTUP-SEQUENCE-INDICES () :PUBLIC? TRUE)", ((cpp_function_code)(&startupSequenceIndices)), NULL);
      { MethodSlot* function = lookupFunction(SYM_SEQUENCE_INDICES_LOGIC_STARTUP_SEQUENCE_INDICES);

        setDynamicSlotValue(function->dynamicSlots, SYM_SEQUENCE_INDICES_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupSequenceIndices"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NIL-NON-PAGING-INDEX NON-PAGING-INDEX (NEW NON-PAGING-INDEX) :DOCUMENTATION \"Returns a non-writable empty sequence.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT NIL-PAGING-INDEX PAGING-INDEX (NEW PAGING-INDEX :SELECTION-PATTERN (QUOTE (:NIL-SEQUENCE))) :DOCUMENTATION \"Returns a non-writable empty sequence.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *LOADINGREGENERABLEOBJECTS?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE, objects being created are regenerable,\nand should not be indexed using the backlinks procedures.\")");
    }
  }
}

Symbol* SYM_SEQUENCE_INDICES_LOGIC_SELECTION_PATTERN = NULL;

Symbol* SYM_SEQUENCE_INDICES_LOGIC_THE_SEQUENCE = NULL;

Symbol* SYM_SEQUENCE_INDICES_LOGIC_THE_SEQUENCE_LENGTH = NULL;

Surrogate* SGT_SEQUENCE_INDICES_LOGIC_NON_PAGING_INDEX = NULL;

Surrogate* SGT_SEQUENCE_INDICES_LOGIC_PAGING_INDEX = NULL;

Symbol* SYM_SEQUENCE_INDICES_LOGIC_STORE = NULL;

Surrogate* SGT_SEQUENCE_INDICES_LOGIC_SEQUENCE_INDEX_ITERATOR = NULL;

Symbol* SYM_SEQUENCE_INDICES_STELLA_LIST_ITERATOR_CURSOR = NULL;

Surrogate* SGT_SEQUENCE_INDICES_LOGIC_PAGING_INDEX_ITERATOR = NULL;

Symbol* SYM_SEQUENCE_INDICES_STELLA_MODULE = NULL;

Symbol* SYM_SEQUENCE_INDICES_LOGIC_OBJECT_STORE = NULL;

Surrogate* SGT_SEQUENCE_INDICES_STELLA_MODULE = NULL;

Surrogate* SGT_SEQUENCE_INDICES_LOGIC_OBJECT_STORE = NULL;

Keyword* KWD_SEQUENCE_INDICES_PAGING = NULL;

Keyword* KWD_SEQUENCE_INDICES_NON_PAGING = NULL;

Symbol* SYM_SEQUENCE_INDICES_LOGIC_STARTUP_SEQUENCE_INDICES = NULL;

Symbol* SYM_SEQUENCE_INDICES_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
