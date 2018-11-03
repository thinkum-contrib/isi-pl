//  -*- Mode: Java -*-
//
// DescriptionExtensionIterator.java

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

/** Iterates over the extension of a description and
 * its subdescriptions, returning those propositions that are currently true.
 * @author Stella Java Translator
 */
public class DescriptionExtensionIterator extends Iterator {
    public NamedDescription rootDescription;
    public Cons subcollections;
    public Iterator extensionIterator;
    public Proposition referenceProposition;
    public List alreadyGeneratedList;
    public HashTable alreadyGeneratedTable;
    public boolean removingDuplicatesP;
    public TruthValue truthValue;

  public static DescriptionExtensionIterator newDescriptionExtensionIterator() {
    { DescriptionExtensionIterator self = null;

      self = new DescriptionExtensionIterator();
      self.firstIterationP = Stella.TRUE;
      self.value = null;
      self.truthValue = null;
      self.removingDuplicatesP = Stella.FALSE;
      self.alreadyGeneratedTable = null;
      self.alreadyGeneratedList = List.newList();
      self.referenceProposition = null;
      self.extensionIterator = null;
      self.subcollections = null;
      self.rootDescription = null;
      return (self);
    }
  }

  public boolean nextP() {
    { DescriptionExtensionIterator self = this;

      { boolean withinqueryP = ((QueryIterator)(Logic.$QUERYITERATOR$.get())) != null;
        PatternRecord patternrecord = (withinqueryP ? ((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentPatternRecord : ((PatternRecord)(null)));
        int ubstackoffset = (withinqueryP ? (patternrecord.topUnbindingStackOffset + 1) : ((int)(Stella.NULL_INTEGER)));

        loop000 : for (;;) {
          loop001 : for (;;) {
            if (!self.extensionIterator.nextP()) {
              break loop001;
            }
            { Proposition value = ((Proposition)(self.extensionIterator.value));

              if (!(((!value.deletedP()) &&
                  ((((Boolean)(Logic.$REVERSEPOLARITYp$.get())).booleanValue() ? Proposition.falseP(value) : (Proposition.trueP(value) ||
                  Proposition.functionWithDefinedValueP(value))))) &&
                  ((self.referenceProposition == null) ||
                   Proposition.argumentsMatchArgumentsP(value, self.referenceProposition)))) {
                continue loop001;
              }
              self.value = value;
              self.truthValue = Proposition.propositionTruthValue(value);
              if ((self.subcollections != null) &&
                  (!(self.subcollections == Stella.NIL))) {
                self.truthValue = TruthValue.conjoinTruthValues(self.truthValue, ((TruthValue)(((Cons)(self.subcollections.value)).rest.value)));
              }
              if (!self.removingDuplicatesP) {
                return (Stella.TRUE);
              }
              { Stella_Object instance = (value.arguments.theArray)[0];

                if ((self.alreadyGeneratedTable == null) &&
                    (self.alreadyGeneratedList.length() >= Logic.$DUPLICATEINSTANCESCACHECROSSOVERPOINT$)) {
                  { HashTable hashtable = HashTable.newHashTable();

                    { Stella_Object m = null;
                      Cons iter000 = self.alreadyGeneratedList.theConsList;

                      while (!(iter000 == Stella.NIL)) {
                        {
                          m = iter000.value;
                          iter000 = iter000.rest;
                        }
                        hashtable.insertAt(m, m);
                      }
                    }
                    self.alreadyGeneratedTable = hashtable;
                  }
                }
                if (self.alreadyGeneratedTable != null) {
                  if (!(self.alreadyGeneratedTable.lookup(instance) != null)) {
                    self.alreadyGeneratedTable.insertAt(instance, instance);
                    return (Stella.TRUE);
                  }
                }
                else {
                  if (!self.alreadyGeneratedList.memberP(instance)) {
                    self.alreadyGeneratedList.push(instance);
                    return (Stella.TRUE);
                  }
                }
                if (withinqueryP) {
                  PatternRecord.unbindVariablesBeginningAt(patternrecord, ubstackoffset);
                }
              }
            }
          }
          { Cons subcollections = self.subcollections;
            NamedDescription subcollection = null;

            if (subcollections == null) {
              subcollections = LogicObject.allSupportedNamedSubcollections(self.rootDescription);
            }
            else {
              subcollections = subcollections.rest;
            }
            loop003 : while (!(subcollections == Stella.NIL)) {
              subcollection = ((NamedDescription)(((Cons)(subcollections.value)).value));
              if (!NamedDescription.getDescriptionExtension(subcollection, Stella.TRUE).emptyP()) {
                break loop003;
              }
              else {
                subcollections = subcollections.rest;
              }
            }
            if (subcollection == null) {
              break loop000;
            }
            self.extensionIterator = NamedDescription.allExtensionMembers(subcollection);
            self.subcollections = subcollections;
          }
        }
        return (Stella.FALSE);
      }
    }
  }

  public static Stella_Object accessDescriptionExtensionIteratorSlotValue(DescriptionExtensionIterator self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_ROOT_DESCRIPTION) {
      if (setvalueP) {
        self.rootDescription = ((NamedDescription)(value));
      }
      else {
        value = self.rootDescription;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_SUBCOLLECTIONS) {
      if (setvalueP) {
        self.subcollections = ((Cons)(value));
      }
      else {
        value = self.subcollections;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_EXTENSION_ITERATOR) {
      if (setvalueP) {
        self.extensionIterator = ((Iterator)(value));
      }
      else {
        value = self.extensionIterator;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_REFERENCE_PROPOSITION) {
      if (setvalueP) {
        self.referenceProposition = ((Proposition)(value));
      }
      else {
        value = self.referenceProposition;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_ALREADY_GENERATED_LIST) {
      if (setvalueP) {
        self.alreadyGeneratedList = ((List)(value));
      }
      else {
        value = self.alreadyGeneratedList;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_ALREADY_GENERATED_TABLE) {
      if (setvalueP) {
        self.alreadyGeneratedTable = ((HashTable)(value));
      }
      else {
        value = self.alreadyGeneratedTable;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_REMOVING_DUPLICATESp) {
      if (setvalueP) {
        self.removingDuplicatesP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.removingDuplicatesP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_TRUTH_VALUE) {
      if (setvalueP) {
        self.truthValue = ((TruthValue)(value));
      }
      else {
        value = self.truthValue;
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
    { DescriptionExtensionIterator self = this;

      return (Logic.SGT_LOGIC_DESCRIPTION_EXTENSION_ITERATOR);
    }
  }

}

