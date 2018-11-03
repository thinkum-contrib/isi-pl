//  -*- Mode: Java -*-
//
// ObjectStore.java

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

public abstract class ObjectStore extends StandardObject {
    public Module module;

  public void storeModuleHeader(Module module) {
    { ObjectStore store = this;

      module = module;
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("store-module-header: not implemented on `" + store + "'");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public void storeAssertion(Proposition proposition) {
    { ObjectStore store = this;

      proposition = proposition;
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("store-proposition: not implemented on `" + store + "'");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public void storeRelation(NamedDescription relation) {
    { ObjectStore store = this;

      relation = relation;
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("store-relation: not implemented on `" + store + "'");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public void storeNativeRelation(Relation relation) {
    { ObjectStore store = this;

      relation = relation;
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("store-native-relation: not implemented on `" + store + "'");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  /** Fetch the instance identified by <code>name</code> (a string or symbol) from <code>store</code>
   * and return it as an appropriate logic object.  This needs to be appropriately
   * specialized on actual OBJECT-STORE implementations.
   * @param name
   * @return Stella_Object
   */
  public Stella_Object fetchInstance(Stella_Object name) {
    { ObjectStore store = this;

      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("Don't know how to fetch instance `" + name + "' from `" + store + "'");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  /** Fetch the relation identified by <code>name</code> (a string or symbol) from <code>store</code>
   * and return it as a named description.  This needs to be appropriately 
   * specialized on actual OBJECT-STORE implementations.
   * @param name
   * @return NamedDescription
   */
  public NamedDescription fetchRelation(Stella_Object name) {
    { ObjectStore store = this;

      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("Don't know how to fetch relation `" + name + "' from `" + store + "'");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public SequenceIndex objectStoreDcreateSequenceIndex(Cons pattern) {
    { ObjectStore store = this;

      { PagingIndex self000 = PagingIndex.newPagingIndex();

        self000.store = store;
        self000.selectionPattern = pattern;
        { PagingIndex value000 = self000;

          return (value000);
        }
      }
    }
  }

  public static Stella_Object accessObjectStoreSlotValue(ObjectStore self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_STELLA_MODULE) {
      if (setvalueP) {
        self.module = ((Module)(value));
      }
      else {
        value = self.module;
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

}

