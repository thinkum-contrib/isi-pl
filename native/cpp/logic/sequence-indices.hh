//  -*- Mode: C++ -*-

// sequence-indices.hh

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997-2003              |
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


namespace logic {
  using namespace stella;

// Class definitions:
class SequenceIndex : public StandardObject {
// Abstract class for managing a sequence of objects.
public:
  Cons* theSequence;
  int theSequenceLength;
public:
  virtual void printObject(std::ostream* stream);
  virtual Iterator* allocateIterator();
  virtual Cons* consify();
  virtual SequenceIndex* removeDeletedMembers();
  virtual int estimatedLength();
  virtual boolean emptyP();
  virtual Object* first();
  virtual void push(Object* value);
  virtual void insert(Object* value);
};

class NonPagingIndex : public SequenceIndex {
// Index that manages an always-in-memory data
// strucure containing a sequence of objects.
public:
  virtual Surrogate* primaryType();
  virtual NonPagingIndex* remove(Object* value);
  virtual void clear();
  virtual NonPagingIndex* copy();
};

class PagingIndex : public SequenceIndex {
// Index that manages a sequence of objects retrievable from
// persistent storage.  Needs to be appropriately subclassed by actual store
// implementations and facilitated with a proper iterator class.
public:
  Cons* selectionPattern;
  ObjectStore* store;
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
  virtual Iterator* allocateIterator();
  virtual SequenceIndex* removeDeletedMembers();
  virtual int estimatedLength();
  virtual void push(Object* value);
  virtual void insert(Object* value);
};

class SequenceIndexIterator : public Iterator {
// Iterator that generates successive members of a sequence index.
public:
  Cons* listIteratorCursor;
public:
  virtual Surrogate* primaryType();
  virtual boolean emptyP();
  virtual boolean nextP();
};

class PagingIndexIterator : public SequenceIndexIterator {
// Iterator that generates successive members of a paging index.
public:
  virtual Surrogate* primaryType();
};

class ObjectStore : public StandardObject {
public:
  Module* module;
public:
  virtual void storeModuleHeader(Module* module);
  virtual void storeAssertion(Proposition* proposition);
  virtual void storeRelation(NamedDescription* relation);
  virtual void storeNativeRelation(Relation* relation);
  virtual Object* fetchInstance(Object* name);
  virtual NamedDescription* fetchRelation(Object* name);
  virtual SequenceIndex* objectStoreDcreateSequenceIndex(Cons* pattern);
};


// Global declarations:
extern NonPagingIndex* NIL_NON_PAGING_INDEX;
extern PagingIndex* NIL_PAGING_INDEX;
extern DECLARE_STELLA_SPECIAL(oLOADINGREGENERABLEOBJECTSpo, boolean );

// Function signatures:
Object* accessSequenceIndexSlotValue(SequenceIndex* self, Symbol* slotname, Object* value, boolean setvalueP);
NonPagingIndex* newNonPagingIndex();
PagingIndex* newPagingIndex();
Object* accessPagingIndexSlotValue(PagingIndex* self, Symbol* slotname, Object* value, boolean setvalueP);
int sequenceIndexDestimatedLength(SequenceIndex* self);
void printSequenceIndex(SequenceIndex* self, std::ostream* stream);
SequenceIndexIterator* newSequenceIndexIterator();
Object* accessSequenceIndexIteratorSlotValue(SequenceIndexIterator* self, Symbol* slotname, Object* value, boolean setvalueP);
void printPagingIndex(PagingIndex* self, std::ostream* stream);
PagingIndexIterator* newPagingIndexIterator();
Object* accessObjectStoreSlotValue(ObjectStore* self, Symbol* slotname, Object* value, boolean setvalueP);
ObjectStore* homeObjectStore(Object* self);
SequenceIndex* createSequenceIndex(Object* self, Cons* pattern);
SequenceIndex* keywordDcreateSequenceIndex(Keyword* kind, Cons* pattern);
SequenceIndex* moduleDcreateSequenceIndex(Module* module, Cons* pattern);
void helpStartupSequenceIndices1();
void startupSequenceIndices();

// Auxiliary global declarations:
extern Symbol* SYM_SEQUENCE_INDICES_LOGIC_SELECTION_PATTERN;
extern Symbol* SYM_SEQUENCE_INDICES_LOGIC_THE_SEQUENCE;
extern Symbol* SYM_SEQUENCE_INDICES_LOGIC_THE_SEQUENCE_LENGTH;
extern Surrogate* SGT_SEQUENCE_INDICES_LOGIC_NON_PAGING_INDEX;
extern Surrogate* SGT_SEQUENCE_INDICES_LOGIC_PAGING_INDEX;
extern Symbol* SYM_SEQUENCE_INDICES_LOGIC_STORE;
extern Surrogate* SGT_SEQUENCE_INDICES_LOGIC_SEQUENCE_INDEX_ITERATOR;
extern Symbol* SYM_SEQUENCE_INDICES_STELLA_LIST_ITERATOR_CURSOR;
extern Surrogate* SGT_SEQUENCE_INDICES_LOGIC_PAGING_INDEX_ITERATOR;
extern Symbol* SYM_SEQUENCE_INDICES_STELLA_MODULE;
extern Symbol* SYM_SEQUENCE_INDICES_LOGIC_OBJECT_STORE;
extern Surrogate* SGT_SEQUENCE_INDICES_STELLA_MODULE;
extern Surrogate* SGT_SEQUENCE_INDICES_LOGIC_OBJECT_STORE;
extern Keyword* KWD_SEQUENCE_INDICES_PAGING;
extern Keyword* KWD_SEQUENCE_INDICES_NON_PAGING;
extern Symbol* SYM_SEQUENCE_INDICES_LOGIC_STARTUP_SEQUENCE_INDICES;
extern Symbol* SYM_SEQUENCE_INDICES_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
