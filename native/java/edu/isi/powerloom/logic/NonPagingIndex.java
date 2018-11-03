//  -*- Mode: Java -*-
//
// NonPagingIndex.java

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

/** Index that manages an always-in-memory data
 * strucure containing a sequence of objects.
 * @author Stella Java Translator
 */
public class NonPagingIndex extends SequenceIndex {
  public static NonPagingIndex newNonPagingIndex() {
    { NonPagingIndex self = null;

      self = new NonPagingIndex();
      self.theSequenceLength = Stella.NULL_INTEGER;
      self.theSequence = Stella.NIL;
      return (self);
    }
  }

  public NonPagingIndex remove(Stella_Object value) {
    { NonPagingIndex self = this;

      self.theSequence = self.theSequence.remove(value);
      return (self);
    }
  }

  public void clear() {
    { NonPagingIndex self = this;

      self.theSequence = Stella.NIL;
    }
  }

  public NonPagingIndex copy() {
    { NonPagingIndex self = this;

      { NonPagingIndex self000 = NonPagingIndex.newNonPagingIndex();

        self000.theSequence = Cons.copyConsList(self.theSequence);
        { NonPagingIndex value000 = self000;

          return (value000);
        }
      }
    }
  }

  public Surrogate primaryType() {
    { NonPagingIndex self = this;

      return (Logic.SGT_LOGIC_NON_PAGING_INDEX);
    }
  }

}

