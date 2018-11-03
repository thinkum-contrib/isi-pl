//  -*- Mode: Java -*-
//
// QuerySolutionTableIterator.java

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

public class QuerySolutionTableIterator extends DictionaryIterator {
    public QuerySolutionTable theTable;
    public QuerySolution cursor;

  public static QuerySolutionTableIterator newQuerySolutionTableIterator() {
    { QuerySolutionTableIterator self = null;

      self = new QuerySolutionTableIterator();
      self.firstIterationP = Stella.TRUE;
      self.value = null;
      self.key = null;
      self.cursor = null;
      self.theTable = null;
      return (self);
    }
  }

  public boolean nextP() {
    { QuerySolutionTableIterator self = this;

      { QuerySolutionTable table = self.theTable;
        QuerySolution cursor = self.cursor;
        QuerySolution previous = cursor;

        if (self.firstIterationP) {
          previous = null;
          cursor = table.first;
          self.firstIterationP = Stella.FALSE;
        }
        else {
          previous = cursor;
          cursor = cursor.next;
        }
        while ((cursor != null) &&
            cursor.deletedP()) {
          cursor = cursor.next;
        }
        self.cursor = cursor;
        if (cursor != null) {
          if (previous == null) {
            table.first = cursor;
          }
          else {
            previous.next = cursor;
          }
          self.key = cursor.bindings;
          self.value = cursor;
          return (Stella.TRUE);
        }
        else if (previous != null) {
          previous.next = null;
          table.last = previous;
        }
        return (Stella.FALSE);
      }
    }
  }

  public static Stella_Object accessQuerySolutionTableIteratorSlotValue(QuerySolutionTableIterator self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_STELLA_THE_TABLE) {
      if (setvalueP) {
        self.theTable = ((QuerySolutionTable)(value));
      }
      else {
        value = self.theTable;
      }
    }
    else if (slotname == Logic.SYM_STELLA_CURSOR) {
      if (setvalueP) {
        self.cursor = ((QuerySolution)(value));
      }
      else {
        value = self.cursor;
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
    { QuerySolutionTableIterator self = this;

      return (Logic.SGT_LOGIC_QUERY_SOLUTION_TABLE_ITERATOR);
    }
  }

}

