//  -*- Mode: Java -*-
//
// BacklinksIndex.java

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

package edu.isi.powerloom.logic;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.stella.*;

/** Contains several types of indices pointing at dependent propositions.
 * @author Stella Java Translator
 */
public class BacklinksIndex extends StandardObject {
    public SequenceIndex dependentPropositionsList;
    public SequenceIndex dependentIsaPropositionsList;
    public HashTable predicatePropositionsTable;

  public static BacklinksIndex newBacklinksIndex() {
    { BacklinksIndex self = null;

      self = new BacklinksIndex();
      self.predicatePropositionsTable = null;
      self.dependentIsaPropositionsList = null;
      self.dependentPropositionsList = null;
      return (self);
    }
  }

  public static void helpRemoveDependentProposition(BacklinksIndex index, Proposition proposition) {
    { SequenceIndex list = index.dependentPropositionsList;
      HashTable table = index.predicatePropositionsTable;

      if (list != null) {
        if (Surrogate.subtypeOfP(Stella_Object.safePrimaryType(list), Logic.SGT_LOGIC_NON_PAGING_INDEX)) {
          { NonPagingIndex list000 = ((NonPagingIndex)(list));

            list000.remove(proposition);
          }
        }
        else {
          { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

            stream000.nativeStream.print("INTERNAL ERROR: `remove' not yet implemented for paging indices");
            throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
          }
        }
      }
      if (table != null) {
        if (proposition.kind == Logic.KWD_ISA) {
          list = index.dependentIsaPropositionsList;
          if (list != null) {
            if (Surrogate.subtypeOfP(Stella_Object.safePrimaryType(list), Logic.SGT_LOGIC_NON_PAGING_INDEX)) {
              { NonPagingIndex list000 = ((NonPagingIndex)(list));

                list000.remove(proposition);
              }
            }
            else {
              { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

                stream001.nativeStream.print("INTERNAL ERROR: `remove' not yet implemented for paging indices");
                throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
        else {
          list = ((SequenceIndex)(table.lookup(((Surrogate)(proposition.operator)))));
          if (list != null) {
            if (Surrogate.subtypeOfP(Stella_Object.safePrimaryType(list), Logic.SGT_LOGIC_NON_PAGING_INDEX)) {
              { NonPagingIndex list000 = ((NonPagingIndex)(list));

                list000.remove(proposition);
              }
            }
            else {
              { OutputStringStream stream002 = OutputStringStream.newOutputStringStream();

                stream002.nativeStream.print("INTERNAL ERROR: `remove' not yet implemented for paging indices");
                throw ((StellaException)(StellaException.newStellaException(stream002.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
      }
    }
  }

  public static void helpAddDependentProposition(BacklinksIndex index, Proposition proposition, Stella_Object argument) {
    { SequenceIndex alldependentpropositions = index.dependentPropositionsList;
      HashTable table = index.predicatePropositionsTable;

      if (table == null) {
        if (SequenceIndex.sequenceIndexDestimatedLength(alldependentpropositions) < Logic.$SPECIALIZED_BACKLINKS_CROSSOVER_POINT$) {
          alldependentpropositions.insert(proposition);
          return;
        }
      }
      BacklinksIndex.addDependentPropositionToSpecializedIndex(index, proposition, argument);
      alldependentpropositions.insert(proposition);
    }
  }

  public static void addDependentPropositionToSpecializedIndex(BacklinksIndex index, Proposition proposition, Stella_Object argument) {
    { HashTable table = index.predicatePropositionsTable;

      if (table == null) {
        table = HashTable.newHashTable();
        index.predicatePropositionsTable = table;
        { Proposition prop = null;
          Iterator iter000 = index.dependentPropositionsList.allocateIterator();

          while (iter000.nextP()) {
            prop = ((Proposition)(iter000.value));
            BacklinksIndex.addDependentPropositionToSpecializedIndex(index, prop, argument);
          }
        }
      }
      if (proposition.kind == Logic.KWD_ISA) {
        if (index.dependentIsaPropositionsList == null) {
          index.dependentIsaPropositionsList = Logic.createSequenceIndex(((Module)(Stella.$MODULE$.get())), Stella_Object.cons(Logic.KWD_ISA, Stella_Object.cons(((Stella.NIL == null) ? Stella.NIL : Stella.NIL), Stella_Object.cons(argument, Stella.NIL))));
        }
        index.dependentIsaPropositionsList.insert(proposition);
      }
      else {
        { Surrogate surrogate = ((Surrogate)(proposition.operator));
          SequenceIndex bucket = null;

          bucket = ((SequenceIndex)(table.lookup(surrogate)));
          if (bucket == null) {
            bucket = Logic.createSequenceIndex(((Module)(Stella.$MODULE$.get())), Stella_Object.cons(Logic.KWD_RELATION, Stella_Object.cons(((Stella.NIL == null) ? Stella.NIL : Stella.NIL), Stella_Object.cons(surrogate, Stella_Object.cons(argument, Stella.NIL)))));
            table.insertAt(surrogate, bucket);
          }
          bucket.insert(proposition);
        }
      }
    }
  }

  public static Stella_Object accessBacklinksIndexSlotValue(BacklinksIndex self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_DEPENDENT_PROPOSITIONS_LIST) {
      if (setvalueP) {
        self.dependentPropositionsList = ((SequenceIndex)(value));
      }
      else {
        value = self.dependentPropositionsList;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_DEPENDENT_ISA_PROPOSITIONS_LIST) {
      if (setvalueP) {
        self.dependentIsaPropositionsList = ((SequenceIndex)(value));
      }
      else {
        value = self.dependentIsaPropositionsList;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_PREDICATE_PROPOSITIONS_TABLE) {
      if (setvalueP) {
        self.predicatePropositionsTable = ((HashTable)(value));
      }
      else {
        value = self.predicatePropositionsTable;
      }
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + slotname + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
    return (value);
  }

  public Surrogate primaryType() {
    { BacklinksIndex self = this;

      return (Logic.SGT_LOGIC_BACKLINKS_INDEX);
    }
  }

}

