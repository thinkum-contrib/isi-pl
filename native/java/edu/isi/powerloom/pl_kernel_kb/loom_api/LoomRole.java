//  -*- Mode: Java -*-
//
// LoomRole.java

/*
 +--------------------------------------------------------------------------+
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
 +--------------------------------------------------------------------------+
*/

package edu.isi.powerloom.pl_kernel_kb.loom_api;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.powerloom.logic.*;
import edu.isi.stella.*;
import edu.isi.powerloom.pl_kernel_kb.*;

/** 
 * @author Stella Java Translator
 */
public class LoomRole extends Thing {
  public static LoomRole newLoomRole() {
    { LoomRole self = null;

      self = new LoomRole();
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.surrogateValueInverse = null;
      return (self);
    }
  }

  /** Return the relation for the Loom role 'role'.
   * @param role
   * @return NamedDescription
   */
  public static NamedDescription relationOfLoomRole(LoomRole role) {
    return (((NamedDescription)(Logic.applyCachedRetrieve(Stella.list$(Stella_Object.cons(LoomApi.SYM_LOOM_API_pR, Stella_Object.cons(LoomApi.SYM_LOOM_API_pROLE, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.list$(Stella_Object.cons(Logic.SYM_STELLA_EXISTS, Stella_Object.cons(LoomApi.SYM_LOOM_API_pI, Stella_Object.cons(Stella.list$(Stella_Object.cons(LoomApi.SYM_LOOM_API_LOOM_ROLE_OF, Stella_Object.cons(LoomApi.SYM_LOOM_API_pI, Stella_Object.cons(LoomApi.SYM_LOOM_API_pR, Stella_Object.cons(LoomApi.SYM_LOOM_API_pROLE, Stella_Object.cons(Stella.NIL, Stella.NIL)))))), Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.consList(Stella_Object.cons(null, Stella_Object.cons(role, Stella.NIL))), Stella.consList(Stella.NIL), LoomApi.SYM_LOOM_API_F_RELATION_OF_LOOM_ROLE_QUERY_000, new Object[1]).value)));
  }

  public static Stella_Object accessLoomRoleSlotValue(LoomRole self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (true) {
      if (setvalueP) {
        KeyValueList.setDynamicSlotValue(self.dynamicSlots, slotname, value, null);
      }
      else {
        value = self.dynamicSlots.lookup(slotname);
      }
    }
    return (value);
  }

  public Surrogate primaryType() {
    { LoomRole self = this;

      return (LoomApi.SGT_LOOM_API_LOOM_ROLE);
    }
  }

}

