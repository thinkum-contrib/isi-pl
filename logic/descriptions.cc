// descriptions.cc

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | 
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

#include "stella-includes.hh"

Vector* FAKE_IO_VARIABLES = NULL;

Cons* SYSTEM_DEFINED_ARGUMENT_NAMES = NULL;

Symbol* SYM_DESCRIPTIONS_pX1 = NULL;

Symbol* SYM_DESCRIPTIONS_pX2 = NULL;

Symbol* SYM_DESCRIPTIONS_pX3 = NULL;

Symbol* SYM_DESCRIPTIONS_pX4 = NULL;

Symbol* SYM_DESCRIPTIONS_pX5 = NULL;

Symbol* SYM_DESCRIPTIONS_pX6 = NULL;

Symbol* SYM_DESCRIPTIONS_pX7 = NULL;

Symbol* SYM_DESCRIPTIONS_pX8 = NULL;

Symbol* SYM_DESCRIPTIONS_pX9 = NULL;

Symbol* SYM_DESCRIPTIONS_pX10 = NULL;

Symbol* SYM_DESCRIPTIONS_pX11 = NULL;

Symbol* SYM_DESCRIPTIONS_pX12 = NULL;

Symbol* SYM_DESCRIPTIONS_pX13 = NULL;

Symbol* SYM_DESCRIPTIONS_pX14 = NULL;

Symbol* SYM_DESCRIPTIONS_pX15 = NULL;

Symbol* SYM_DESCRIPTIONS_pX16 = NULL;

Symbol* SYM_DESCRIPTIONS_pX17 = NULL;

Symbol* SYM_DESCRIPTIONS_pX18 = NULL;

Symbol* SYM_DESCRIPTIONS_pX19 = NULL;

Symbol* SYM_DESCRIPTIONS_pX20 = NULL;

Symbol* SYM_DESCRIPTIONS_SETOFALL = NULL;

Symbol* SYM_DESCRIPTIONS_ISA = NULL;

Symbol* SYM_DESCRIPTIONS_pX = NULL;

Surrogate* SGT_DESCRIPTIONS_SLOT = NULL;

Surrogate* SGT_DESCRIPTIONS_BOOLEAN = NULL;

Surrogate* SGT_DESCRIPTIONS_TABLE = NULL;

Symbol* SYM_DESCRIPTIONS_KAPPA = NULL;

Symbol* SYM_DESCRIPTIONS_COMMA = NULL;

Symbol* SYM_DESCRIPTIONS_WHERE = NULL;

Surrogate* SGT_DESCRIPTIONS_COLLECTION = NULL;

Symbol* SYM_DESCRIPTIONS_IN = NULL;

Symbol* SYM_DESCRIPTIONS_e = NULL;

Keyword* KWD_DESCRIPTIONS_PREFIX_STELLA = NULL;

Keyword* KWD_DESCRIPTIONS_PRIMITIVE = NULL;

Symbol* SYM_DESCRIPTIONS_DESCRIPTION = NULL;

Surrogate* SGT_DESCRIPTIONS_DESCRIPTION = NULL;

Surrogate* SGT_DESCRIPTIONS_RELATION = NULL;

Symbol* SYM_DESCRIPTIONS_DEFINITION_STRING = NULL;

Symbol* SYM_DESCRIPTIONS_DEFINITION = NULL;

Surrogate* SGT_DESCRIPTIONS_LOGIC_OBJECT = NULL;

Symbol* SYM_DESCRIPTIONS_ANY_VALUE = NULL;

Surrogate* SGT_DESCRIPTIONS_ITERATOR = NULL;

Cons* oLOGICVARIABLETABLEo = NULL;

Symbol* SYM_DESCRIPTIONS_oLOGICVARIABLETABLEo = NULL;

Symbol* SYM_DESCRIPTIONS_SKOLEM_NAME = NULL;

Symbol* SYM_DESCRIPTIONS_VARIABLE_TYPEp = NULL;

Keyword* KWD_DESCRIPTIONS_CONCEIVE = NULL;

Keyword* KWD_DESCRIPTIONS_FUNCTION = NULL;

Keyword* KWD_DESCRIPTIONS_PREDICATE = NULL;

Keyword* KWD_DESCRIPTIONS_IN = NULL;

Keyword* KWD_DESCRIPTIONS_EQUIVALENT = NULL;

Surrogate* SGT_DESCRIPTIONS_PATTERN_VARIABLE = NULL;

Symbol* SYM_DESCRIPTIONS_EXISTS = NULL;

Symbol* SYM_DESCRIPTIONS_AND = NULL;

Symbol* SYM_DESCRIPTIONS_IO_VARIABLES = NULL;

Surrogate* SGT_DESCRIPTIONS_SKOLEM = NULL;

Surrogate* SGT_DESCRIPTIONS_PROPOSITION = NULL;

Keyword* KWD_DESCRIPTIONS_EQUIVALENCE = NULL;

Keyword* KWD_DESCRIPTIONS_AND = NULL;

Keyword* KWD_DESCRIPTIONS_EXISTS = NULL;

Keyword* KWD_DESCRIPTIONS_DEFINITION = NULL;

Keyword* KWD_DESCRIPTIONS_QUERY = NULL;

Symbol* SYM_DESCRIPTIONS_THE_ONLY = NULL;

Symbol* SYM_DESCRIPTIONS_IOTAp = NULL;

Keyword* KWD_DESCRIPTIONS_DESCRIPTION = NULL;

Surrogate* SGT_DESCRIPTIONS_PROPOSITION_ERROR = NULL;

Keyword* KWD_DESCRIPTIONS_ASSERT_TRUE = NULL;

Keyword* KWD_DESCRIPTIONS_ENUMERATION = NULL;

Keyword* KWD_DESCRIPTIONS_RETRACT_TRUE = NULL;

Surrogate* SGT_DESCRIPTIONS_UNKNOWN = NULL;

Symbol* SYM_DESCRIPTIONS_EXTENSION = NULL;

Symbol* SYM_DESCRIPTIONS_CLOSED = NULL;

Symbol* SYM_DESCRIPTIONS_LISTOF = NULL;

Symbol* SYM_DESCRIPTIONS_SETOF = NULL;

Symbol* SYM_DESCRIPTIONS_ORDERED = NULL;

Symbol* SYM_DESCRIPTIONS_DUPLICATE_FREE = NULL;

Symbol* SYM_DESCRIPTIONS_COMPLEMENT_DESCRIPTION = NULL;

Description* create_description(int arity, Keyword* kind) {
  { Description* description = new_description();

    description->io_variables = ((arity != NULL_INTEGER) ? ((Vector*)(new_vector(arity))) : ((Vector*)(FAKE_IO_VARIABLES)));
    description->kind = kind;
    return (description);
  }
}

Description* create_description_for_relation(Relation* self) {
  { Description* description = NULL;
    Cons* expression = NULL;
    Module* nativemodule = NULL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            { Relation* self_001 = self;

              if (classP(self)) {
                { Class* self = NULL;

                  self = ((Class*)(self_001));
                  nativemodule = ((Module*)(self->class_type->home_context));
                  expression = listO(3, SYM_DESCRIPTIONS_SETOFALL, listO(4, SYM_DESCRIPTIONS_ISA, SYM_DESCRIPTIONS_pX, self->class_type, NIL), NIL);
                }
              }
              else if (taxonomy_isaP(self, SGT_DESCRIPTIONS_SLOT)) {
                { Slot* self = NULL;

                  self = ((Slot*)(self_001));
                  nativemodule = ((Module*)(self->slot_owner->home_context));
                  { int arity = self->method_argument_count() + 1;
                    Symbol* slotname = self->slot_name;
                    Surrogate* slottype = wrapped_type_to_type(self->slot_base_type);
                    boolean predicateP = slottype == SGT_DESCRIPTIONS_BOOLEAN;
                    Cons* typelist = NIL;
                    Cons* typedvariables = NIL;
                    Cons* arguments = NIL;

                    if (arity > SYSTEM_DEFINED_ARGUMENT_NAMES->length()) {
                      cerr << "PowerLoom can't handle relations with arity > " << "`" << SYSTEM_DEFINED_ARGUMENT_NAMES->length() << "'" << endl;
                    }
                    { Slot* self_002 = self;

                      if (storage_slotP(self)) {
                        { Storage_Slot* self = NULL;

                          self = ((Storage_Slot*)(self_002));
                          if (predicateP) {
                            typelist = cons(self->slot_owner, NIL);
                          }
                          else {
                            typelist = cons(self->slot_owner, cons(slottype, NIL));
                          }
                        }
                      }
                      else if (method_slotP(self)) {
                        { Method_Slot* self = NULL;

                          self = ((Method_Slot*)(self_002));
                          { Standard_Object* ts = NULL;
                            Cons* iter_001 = self->method_parameter_type_specifiers_reader()->the_cons_list;
                            Cons* collect_001 = NULL;

                            while (!nilP(iter_001)) {
                              {
                                ts = ((Standard_Object*)(iter_001->value));
                                iter_001 = iter_001->rest;
                              }
                              if (collect_001 == NULL) {
                                {
                                  collect_001 = cons(wrapped_type_to_type(type_spec_to_base_type(ts)), NIL);
                                  if (nilP(typelist)) {
                                    typelist = collect_001;
                                  }
                                  else {
                                    add_cons_to_end_of_cons_list(typelist, collect_001);
                                  }
                                }
                              }
                              else {
                                {
                                  collect_001->rest = cons(wrapped_type_to_type(type_spec_to_base_type(ts)), NIL);
                                  collect_001 = collect_001->rest;
                                }
                              }
                            }
                          }
                          if (!predicateP) {
                            typelist = typelist->concatenate(cons(slottype, NIL));
                          }
                        }
                      }
                      else if (taxonomy_isaP(self, SGT_DESCRIPTIONS_TABLE)) {
                        { Table* self = NULL;

                          self = ((Table*)(self_002));
                          { Standard_Object* t = NULL;
                            Cons* iter_002 = self->tuple_domains->the_cons_list;
                            Cons* collect_002 = NULL;

                            while (!nilP(iter_002)) {
                              {
                                t = ((Standard_Object*)(iter_002->value));
                                iter_002 = iter_002->rest;
                              }
                              if (collect_002 == NULL) {
                                {
                                  collect_002 = cons(t, NIL);
                                  if (nilP(typelist)) {
                                    typelist = collect_002;
                                  }
                                  else {
                                    add_cons_to_end_of_cons_list(typelist, collect_002);
                                  }
                                }
                              }
                              else {
                                {
                                  collect_002->rest = cons(t, NIL);
                                  collect_002 = collect_002->rest;
                                }
                              }
                            }
                          }
                          if (!predicateP) {
                            typelist = typelist->concatenate(cons(slottype, NIL));
                          }
                        }
                      }
                      else {
                        cerr << "`" << self << "'" << " is not a valid case option";
                      }
                    }
                    { Object* vbltype = NULL;
                      Symbol* name = NULL;
                      int i = NULL_INTEGER;
                      int iter_003 = 1;
                      int upper_bound_001 = arity;
                      boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;
                      Cons* iter_004 = SYSTEM_DEFINED_ARGUMENT_NAMES;
                      Cons* iter_005 = typelist;
                      Cons* collect_003 = NULL;

                      while ((unboundedP_001 ||
                          (iter_003 <= upper_bound_001)) &&
                          ((!nilP(iter_004)) &&
                           (!nilP(iter_005)))) {
                        {
                          i = iter_003;
                          iter_003 = iter_003 + 1;
                        }
                        {
                          name = ((Symbol*)(iter_004->value));
                          iter_004 = iter_004->rest;
                        }
                        {
                          vbltype = iter_005->value;
                          iter_005 = iter_005->rest;
                        }
                        if (collect_003 == NULL) {
                          {
                            collect_003 = cons(listO(3, SYM_DESCRIPTIONS_ISA, name, cons(vbltype, NIL)), NIL);
                            if (nilP(typedvariables)) {
                              typedvariables = collect_003;
                            }
                            else {
                              add_cons_to_end_of_cons_list(typedvariables, collect_003);
                            }
                          }
                        }
                        else {
                          {
                            collect_003->rest = cons(listO(3, SYM_DESCRIPTIONS_ISA, name, cons(vbltype, NIL)), NIL);
                            collect_003 = collect_003->rest;
                          }
                        }
                      }
                    }
                    if (predicateP) {
                      {
                        { Cons* vblform = NIL;
                          Cons* iter_006 = typedvariables;
                          Cons* collect_004 = NULL;

                          while (!nilP(iter_006)) {
                            {
                              vblform = ((Cons*)(iter_006->value));
                              iter_006 = iter_006->rest;
                            }
                            if (collect_004 == NULL) {
                              {
                                collect_004 = cons(vblform->second(), NIL);
                                if (nilP(arguments)) {
                                  arguments = collect_004;
                                }
                                else {
                                  add_cons_to_end_of_cons_list(arguments, collect_004);
                                }
                              }
                            }
                            else {
                              {
                                collect_004->rest = cons(vblform->second(), NIL);
                                collect_004 = collect_004->rest;
                              }
                            }
                          }
                        }
                        expression = listO(4, SYM_DESCRIPTIONS_KAPPA, cons(SYM_DESCRIPTIONS_COMMA, typedvariables->concatenate(NIL)), listO(3, SYM_DESCRIPTIONS_WHERE, cons(slotname, arguments->concatenate(NIL)), NIL), NIL);
                      }
                    }
                    else {
                      { Object* outputarg = ((Cons*)(typedvariables->last()))->second();

                        { Cons* vblform = NIL;
                          Iterator* iter_007 = typedvariables->but_last();
                          Cons* collect_005 = NULL;

                          while (iter_007->nextP()) {
                            {
                              vblform = ((Cons*)(iter_007->value));
                            }
                            if (collect_005 == NULL) {
                              {
                                collect_005 = cons(vblform->second(), NIL);
                                if (nilP(arguments)) {
                                  arguments = collect_005;
                                }
                                else {
                                  add_cons_to_end_of_cons_list(arguments, collect_005);
                                }
                              }
                            }
                            else {
                              {
                                collect_005->rest = cons(vblform->second(), NIL);
                                collect_005 = collect_005->rest;
                              }
                            }
                          }
                        }
                        if (isaP(slottype, SGT_DESCRIPTIONS_COLLECTION)) {
                          expression = listO(4, SYM_DESCRIPTIONS_KAPPA, cons(SYM_DESCRIPTIONS_COMMA, typedvariables->concatenate(NIL)), listO(3, SYM_DESCRIPTIONS_WHERE, listO(3, SYM_DESCRIPTIONS_IN, outputarg, cons(cons(slotname, arguments->concatenate(NIL)), NIL)), NIL), NIL);
                        }
                        else {
                          expression = listO(4, SYM_DESCRIPTIONS_KAPPA, cons(SYM_DESCRIPTIONS_COMMA, typedvariables->concatenate(NIL)), listO(3, SYM_DESCRIPTIONS_WHERE, listO(3, SYM_DESCRIPTIONS_e, outputarg, cons(cons(slotname, arguments->concatenate(NIL)), NIL)), NIL), NIL);
                        }
                      }
                    }
                  }
                }
              }
              else {
                cerr << "`" << self << "'" << " is not a valid case option";
              }
            }
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          resignal();
        }
      }
    }
    { Keyword* old_Ologic_dialectO_001 = oLOGIC_DIALECTo;

      { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oLOGIC_DIALECTo = KWD_DESCRIPTIONS_PREFIX_STELLA;
            { Module* old_OmoduleO_001 = oMODULEo;
              Context* old_OcontextO_001 = oCONTEXTo;

              { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oMODULEo = nativemodule;
                    oCONTEXTo = oMODULEo;
                    description = create_top_level_description(expression, KWD_DESCRIPTIONS_PRIMITIVE, self);
                    oCONTEXTo = old_OcontextO_001;
                    oMODULEo = old_OmoduleO_001;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oCONTEXTo = old_OcontextO_001;
                  oMODULEo = old_OmoduleO_001;
                  resignal();
                }
              }
            }
            oLOGIC_DIALECTo = old_Ologic_dialectO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oLOGIC_DIALECTo = old_Ologic_dialectO_001;
          resignal();
        }
      }
    }
    set_dynamic_slot_value(self, SYM_DESCRIPTIONS_DESCRIPTION, description, NULL);
    description->native_relation = self;
    return (description);
  }
}

Description* Surrogate::get_description() {
  { Surrogate* self = this;

    { Object* value = self->surrogate_value;
      Description* description = NULL;

      if (value != NULL) {
        { Object* value_001 = value;

          if (taxonomy_isaP(value, SGT_DESCRIPTIONS_DESCRIPTION)) {
            { Description* value = NULL;

              value = ((Description*)(value_001));
              return (value);
            }
          }
          else if (taxonomy_isaP(value, SGT_DESCRIPTIONS_RELATION)) {
            { Relation* value = NULL;

              value = ((Relation*)(value_001));
              if (((Description*)(dynamic_slot_value(value, SYM_DESCRIPTIONS_DESCRIPTION, NULL))) != NULL) {
                return (((Description*)(dynamic_slot_value(value, SYM_DESCRIPTIONS_DESCRIPTION, NULL))));
              }
              else {
                { Description* description = create_description_for_relation(value);

                  finalize_superrelation_links(value);
                  return (description);
                }
              }
            }
          }
          else {
            return (NULL);
          }
        }
      }
      description = create_description(NULL_INTEGER, KWD_DESCRIPTIONS_PRIMITIVE);
      self->surrogate_value = description;
      return (description);
    }
  }
}

Description* Symbol::get_description() {
  { Symbol* self = this;

    return (string_get_description(self->symbol_name));
  }
}

Description* Generalized_Symbol::get_description() {
  { Generalized_Symbol* self = this;

    return (NULL);
  }
}

Description* string_get_description(char* self) {
  { Surrogate* surrogate = lookup_surrogate(self);

    if (surrogate != NULL) {
      return (surrogate->get_description());
    }
    else {
      return (NULL);
    }
  }
}

Description* Relation::get_description() {
  { Relation* self = this;

    return (NULL);
  }
}

Description* Class::get_description() {
  { Class* self = this;

    if (((Description*)(dynamic_slot_value(self, SYM_DESCRIPTIONS_DESCRIPTION, NULL))) != NULL) {
      return (((Description*)(dynamic_slot_value(self, SYM_DESCRIPTIONS_DESCRIPTION, NULL))));
    }
    else {
      return (self->class_type->get_description());
    }
  }
}

Description* Slot::get_description() {
  { Slot* self = this;

    if (((Description*)(dynamic_slot_value(self, SYM_DESCRIPTIONS_DESCRIPTION, NULL))) != NULL) {
      return (((Description*)(dynamic_slot_value(self, SYM_DESCRIPTIONS_DESCRIPTION, NULL))));
    }
    else if (self->slot_slotref != NULL) {
      return (self->slot_slotref->get_description());
    }
    else {
      return (lookup_slotref(self->slot_owner, self->slot_name)->get_description());
    }
  }
}

boolean Class::primitiveP() {
  // Return TRUE if 'self' is not a defined class.
  { Class* self = this;

    return (((String_Wrapper*)(dynamic_slot_value(self, SYM_DESCRIPTIONS_DEFINITION_STRING, NULL_STRING_WRAPPER)))->wrapper_value == NULL);
  }
}

boolean Slot::primitiveP() {
  // Return TRUE if 'self' is not a defined slot.
  { Slot* self = this;

    return (((String_Wrapper*)(dynamic_slot_value(self, SYM_DESCRIPTIONS_DEFINITION_STRING, NULL_STRING_WRAPPER)))->wrapper_value == NULL);
  }
}

boolean Description::primitiveP() {
  // Return TRUE if 'self' attached to a primitive
  // relation.  Definitions that enumerate their members are considered
  // primitive.
  { Description* self = this;

    return ((self->native_relation != NULL) &&
        (((Description*)(dynamic_slot_value(self->native_relation, SYM_DESCRIPTIONS_DEFINITION, NULL))) == NULL));
  }
}

Surrogate* description_owner_type(Description* description) {
  { Relation* owner = description->native_relation;

    if (owner != NULL) {
      { Relation* owner_001 = owner;

        if (classP(owner)) {
          { Class* owner = NULL;

            owner = ((Class*)(owner_001));
            return (owner->class_type);
          }
        }
        else {
        }
      }
    }
    return (NULL);
  }
}

Surrogate* logic_objectDmember_type_from_collection(Logic_Object* self) {
  { Surrogate* type = NULL;

    { Logic_Object* superset = NULL;
      Iterator* iter_001 = all_supercollections(self);

      while (iter_001->nextP()) {
        {
          superset = ((Logic_Object*)(iter_001->value));
        }
        { 
          type = member_type_from_collection(superset);
          if (type != NULL) {
            return (type);
          }
        }
      }
    }
    return (member_type_from_collection(logical_type(self)));
  }
}

Surrogate* descriptionDmember_type_from_collection(Description* self) {
  { Surrogate* ownertype = description_owner_type(self);

    if (ownertype != NULL) {
      return (ownertype);
    }
    else if (self->representative() != NULL) {
      return (self->representative()->root_type);
    }
    else {
      return (NULL);
    }
  }
}

Surrogate* member_type_from_collection(Object* self) {
  { Object* self_001 = self;

    if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        return (self);
      }
    }
    else if (taxonomy_isaP(self, SGT_DESCRIPTIONS_DESCRIPTION)) {
      { Description* self = NULL;

        self = ((Description*)(self_001));
        return (descriptionDmember_type_from_collection(self));
      }
    }
    else if (taxonomy_isaP(self, SGT_DESCRIPTIONS_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        return (logic_objectDmember_type_from_collection(self));
      }
    }
    else if (taxonomy_isaP(self, SGT_DESCRIPTIONS_COLLECTION)) {
      { Collection* self = NULL;

        self = ((Collection*)(self_001));
        { Surrogate* collectiontype = self->primary_type();
          Slot* slot = lookup_slot(((Class*)(collectiontype->surrogate_value)), SYM_DESCRIPTIONS_ANY_VALUE);

          return (((slot != NULL) ? ((Surrogate*)(slot->type())) : ((Surrogate*)(NULL))));
        }
      }
    }
    else if (taxonomy_isaP(self, SGT_DESCRIPTIONS_ITERATOR)) {
      { Iterator* self = NULL;

        self = ((Iterator*)(self_001));
        { Surrogate* collectiontype = self->primary_type();
          Slot* slot = lookup_slot(((Class*)(collectiontype->surrogate_value)), SYM_DESCRIPTIONS_ANY_VALUE);

          return (((slot != NULL) ? ((Surrogate*)(slot->type())) : ((Surrogate*)(NULL))));
        }
      }
    }
    else {
      cerr << "`" << self << "'" << " is not a valid case option";
    }
  }
}

Symbol* description_name(Description* self) {
  { Relation* relation = self->native_relation;

    if (relation == NULL) {
      return (NULL);
    }
    { Relation* relation_001 = relation;

      if (classP(relation)) {
        { Class* relation = NULL;

          relation = ((Class*)(relation_001));
          return (intern_symbol(class_name(relation)));
        }
      }
      else if (taxonomy_isaP(relation, SGT_DESCRIPTIONS_SLOT)) {
        { Slot* relation = NULL;

          relation = ((Slot*)(relation_001));
          return (relation->slot_name);
        }
      }
      else {
        cerr << "`" << relation << "'" << " is not a valid case option";
      }
    }
  }
}

Cons* read_OlogicvariabletableO() {
  return (oLOGICVARIABLETABLEo);
}

Cons* write_OlogicvariabletableO(Cons* value) {
  oLOGICVARIABLETABLEo = value;
  return (value);
}

void push_logic_variable_binding(Skolem* variable) {
  if (anonymous_variableP(variable)) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            cout << "Error in logical expression." << endl;
            cout << "   " << "Illegal nameless variable '?' found in list of\nquantified variables." << endl << "   Quantified variables must have names." << endl;
            cout << "   Error occured while parsing the proposition: " << endl;
            cout << "   " << oPROPOSITIONUNDERCONSTRUCTIONo << endl;
            signal(oTHE_PROPOSITION_ERRORo);
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
          resignal();
        }
      }
    }
  }
  oLOGICVARIABLETABLEo = cons(variable, oLOGICVARIABLETABLEo);
}

void pop_logic_variable_binding() {
  { Cons* headcons = oLOGICVARIABLETABLEo;

    oLOGICVARIABLETABLEo = headcons->rest;
    headcons->free();
  }
}

void pop_logic_variable_bindings(Cons* variables) {
  { int i = NULL_INTEGER;
    int iter_001 = 1;
    int upper_bound_001 = variables->length();

    while (iter_001 <= upper_bound_001) {
      {
        i = iter_001;
        iter_001 = iter_001 + 1;
      }
      i = i;
      pop_logic_variable_binding();
    }
  }
}

Object* lookup_logic_variable_binding(Symbol* variablename) {
  if (oLOGICVARIABLETABLEo != NULL) {
    { Skolem* vbl = NULL;
      Cons* iter_001 = oLOGICVARIABLETABLEo;

      while (!nilP(iter_001)) {
        {
          vbl = ((Skolem*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (dynamic_slot_value(vbl, SYM_DESCRIPTIONS_SKOLEM_NAME, NULL) == variablename) {
          return (vbl);
        }
      }
    }
  }
  return (NULL);
}

Cons* parse_logic_variable_declarations(Cons* tree, Keyword* updatemode, boolean variableP) {
  { Symbol* renamed_Operator = ((Symbol*)(tree->first()));

    if ((renamed_Operator == SYM_DESCRIPTIONS_ISA) ||
        (renamed_Operator == SYM_DESCRIPTIONS_IN)) {
      { Skolem* variable = (variableP ? ((Skolem*)(create_variable(NULL, ((Symbol*)(tree->second())), TRUE))) : ((Skolem*)(create_skolem(NULL, ((Symbol*)(tree->second()))))));
        Proposition* proposition = NULL;

        push_logic_variable_binding(variable);
        proposition = build_top_level_proposition(tree, updatemode);
        set_dynamic_slot_value(proposition, SYM_DESCRIPTIONS_VARIABLE_TYPEp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
        return (cons_list(1, variable));
      }
    }
    else if (renamed_Operator == SYM_DESCRIPTIONS_COMMA) {
      { Cons* conslist = NIL;

        { Object* term = NULL;
          Cons* iter_001 = tree->rest;

          while (!nilP(iter_001)) {
            {
              term = iter_001->value;
              iter_001 = iter_001->rest;
            }
            conslist = conslist->concatenate(parse_logic_variable_declarations(((Cons*)(term)), updatemode, variableP));
          }
        }
        return (conslist);
      }
    }
    else {
      cerr << "`" << renamed_Operator << "'" << " is not a valid case option";
    }
  }
}

Vector* copy_cons_list_to_variables_vector(Cons* conslist) {
  if (conslist->emptyP()) {
    return (ZERO_VARIABLES_VECTOR);
  }
  { Vector* vector = new_vector(conslist->length());

    { int i = NULL_INTEGER;
      Object* t = NULL;
      Cons* iter_001 = conslist;
      int iter_002 = 0;

      while (!nilP(iter_001)) {
        {
          t = iter_001->value;
          iter_001 = iter_001->rest;
        }
        {
          i = iter_002;
          iter_002 = iter_002 + 1;
        }
        vector->nth_setter(((Pattern_Variable*)(t)), i);
      }
    }
    return (vector);
  }
}

Cons* build_quantified_proposition(Cons* tree, Keyword* updatemode, Proposition*& return1, Proposition*& return2) {
  { Cons* old_OtoplevelpropositionsO_001 = oTOPLEVELPROPOSITIONSo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTOPLEVELPROPOSITIONSo = NIL;
          { boolean descriptiveP = updatemode == KWD_DESCRIPTIONS_CONCEIVE;
            Cons* variables = parse_logic_variable_declarations(((Cons*)(tree->second())), updatemode, descriptiveP);
            Object* whereclause = extract_where_clause(tree);
            Object* alwaysclause = extract_always_clause(tree);
            Proposition* whereproposition = NULL;
            Proposition* alwaysproposition = NULL;

            if (whereclause != NULL) {
              help_update_proposition(whereclause, updatemode);
            }
            if (alwaysclause != NULL) {
              alwaysproposition = build_proposition(alwaysclause, NULL);
            }
            pop_logic_variable_bindings(variables);
            if (oTOPLEVELPROPOSITIONSo->non_emptyP() &&
                descriptiveP) {
              oTOPLEVELPROPOSITIONSo = oTOPLEVELPROPOSITIONSo->reverse()->remove_duplicates();
              whereproposition = conjoin_propositions(oTOPLEVELPROPOSITIONSo);
            }
            free_cons_list(oTOPLEVELPROPOSITIONSo);
            { 
              oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              { Cons* return_temp = variables;

                return1 = whereproposition;
                return2 = alwaysproposition;
                return (return_temp);
              }
            }
          }
          oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
        resignal();
      }
    }
  }
}

Logic_Object* Description::find_duplicate_description() {
  { Description* self = this;

    return (NULL);
  }
}

boolean contains_nested_argumentP(Proposition* atomicproposition) {
  { Keyword* test_value_001 = atomicproposition->kind;

    if ((test_value_001 == KWD_DESCRIPTIONS_FUNCTION) ||
        ((test_value_001 == KWD_DESCRIPTIONS_PREDICATE) ||
         ((test_value_001 == KWD_DESCRIPTIONS_IN) ||
          (test_value_001 == KWD_DESCRIPTIONS_EQUIVALENT)))) {
      { Object* term = NULL;
        Vector* vector_001 = atomicproposition->arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            term = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          { Object* term_001 = term;

            if (taxonomy_isaP(term, SGT_DESCRIPTIONS_PATTERN_VARIABLE)) {
              { Pattern_Variable* term = NULL;

                term = ((Pattern_Variable*)(term_001));
                if (term->defining_proposition != NULL) {
                  return (TRUE);
                }
              }
            }
            else {
            }
          }
        }
      }
    }
    else {
    }
  }
  return (FALSE);
}

void help_collect_flattened_arguments(Proposition* self, List* flattenedarguments, List* beenthere) {
  { Object* term = NULL;
    Vector* vector_001 = self->arguments;
    int index_001 = 0;
    int length_001 = vector_001->length();

    while (index_001 < length_001) {
      {
        term = vector_001->nth(index_001);
        index_001 = index_001 + 1;
      }
      { Object* term_001 = term;

        if (taxonomy_isaP(term, SGT_DESCRIPTIONS_PATTERN_VARIABLE)) {
          { Pattern_Variable* term = NULL;

            term = ((Pattern_Variable*)(term_001));
            { Proposition* functionarg = term->defining_proposition;

              if ((functionarg != NULL) &&
                  (!beenthere->memberP(functionarg))) {
                beenthere->push(functionarg);
                help_collect_flattened_arguments(functionarg, flattenedarguments, beenthere);
                flattenedarguments->push(functionarg);
              }
            }
          }
        }
        else {
        }
      }
    }
  }
}

List* yield_flattened_arguments(Proposition* proposition) {
  { List* beenthere = list(1, proposition);
    List* flattenedarguments = new_list();

    help_collect_flattened_arguments(proposition, flattenedarguments, beenthere);
    beenthere->free();
    flattenedarguments->push(proposition);
    return (flattenedarguments->reverse());
  }
}

Proposition* flatten_nested_function_arguments(Proposition* proposition) {
  { Proposition* existsproposition = create_proposition(SYM_DESCRIPTIONS_EXISTS, 1);
    List* flattenedpropositions = yield_flattened_arguments(proposition);
    Proposition* andproposition = create_proposition(SYM_DESCRIPTIONS_AND, flattenedpropositions->length());
    Cons* variables = NIL;

    { int i = NULL_INTEGER;
      Proposition* prop = NULL;
      Cons* iter_001 = flattenedpropositions->the_cons_list;
      int iter_002 = 0;

      while (!nilP(iter_001)) {
        {
          prop = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        {
          i = iter_002;
          iter_002 = iter_002 + 1;
        }
        andproposition->arguments->nth_setter(prop, i);
        add_dependent_proposition_link(prop, andproposition);
      }
    }
    { Proposition* prop = NULL;
      Cons* iter_003 = flattenedpropositions->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_003)) {
        {
          prop = ((Proposition*)(iter_003->value));
          iter_003 = iter_003->rest;
        }
        if ((prop->kind == KWD_DESCRIPTIONS_FUNCTION) &&
            isaP(last_argument(prop), SGT_DESCRIPTIONS_PATTERN_VARIABLE)) {
          if (collect_001 == NULL) {
            {
              collect_001 = cons(last_argument(prop), NIL);
              if (nilP(variables)) {
                variables = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(variables, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = cons(last_argument(prop), NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
    }
    set_dynamic_slot_value(existsproposition, SYM_DESCRIPTIONS_IO_VARIABLES, copy_cons_list_to_variables_vector(variables), NULL);
    free_cons_list(variables);
    existsproposition->arguments->nth_setter(andproposition, 0);
    add_dependent_proposition_link(andproposition, existsproposition);
    return (existsproposition);
  }
}

void collapse_value_of_chains(Description* description) {
  tighten_argument_bindings(description->proposition);
  { Skolem* tightestskolem = NULL;

    { int i = NULL_INTEGER;
      Pattern_Variable* vbl = NULL;
      Vector* vector_001 = description->io_variables;
      int index_001 = 0;
      int length_001 = vector_001->length();
      int iter_001 = 0;

      while (index_001 < length_001) {
        {
          vbl = ((Pattern_Variable*)(vector_001->nth(index_001)));
          index_001 = index_001 + 1;
        }
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        if (!(vbl == innermost_variable_of(vbl))) {
          tightestskolem = innermost_variable_of(vbl);
          description->io_variables->nth_setter(((Pattern_Variable*)(tightestskolem)), i);
          set_dynamic_slot_value(tightestskolem, SYM_DESCRIPTIONS_SKOLEM_NAME, ((Symbol*)(dynamic_slot_value(vbl, SYM_DESCRIPTIONS_SKOLEM_NAME, NULL))), NULL);
          { Skolem* object_001 = tightestskolem;
            Cons* value_001 = NIL;
            Object* old_value_001 = object_001->variable_value_inverse;
            Object* new_value_001 = update_in_context(old_value_001, value_001, object_001, FALSE);

            if (!cs_valueP(old_value_001)) {
              object_001->variable_value_inverse = new_value_001;
            }
          }
          vbl->free();
        }
      }
    }
  }
  { Object* value = NULL;

    { int i = NULL_INTEGER;
      Pattern_Variable* vbl = NULL;
      Vector* vector_002 = description->internal_variables;
      int index_002 = 0;
      int length_002 = vector_002->length();
      int iter_002 = 0;

      while (index_002 < length_002) {
        {
          vbl = ((Pattern_Variable*)(vector_002->nth(index_002)));
          index_002 = index_002 + 1;
        }
        {
          i = iter_002;
          iter_002 = iter_002 + 1;
        }
        if ((((Object*)(access_in_context(vbl->variable_value, vbl, FALSE))) != NULL) &&
            isaP(((Object*)(access_in_context(vbl->variable_value, vbl, FALSE))), SGT_DESCRIPTIONS_SKOLEM)) {
          value = ((Object*)(access_in_context(vbl->variable_value, vbl, FALSE)));
          description->internal_variables->nth_setter(NULL, i);
          { Object* value_002 = value;

            if (taxonomy_isaP(value, SGT_DESCRIPTIONS_LOGIC_OBJECT)) {
              { Logic_Object* value = NULL;

                value = ((Logic_Object*)(value_002));
                if (!(description->io_variables->memberP(value->variable_value_inverse_reader()))) {
                  { Logic_Object* object_002 = value;
                    Cons* value_003 = NULL;
                    Object* old_value_005 = object_002->variable_value_inverse;
                    Object* new_value_002 = update_in_context(old_value_005, value_003, object_002, FALSE);

                    if (!cs_valueP(old_value_005)) {
                      object_002->variable_value_inverse = new_value_002;
                    }
                  }
                }
              }
            }
            else {
            }
          }
          vbl->free();
        }
      }
    }
    { int i = NULL_INTEGER;
      Pattern_Variable* vbl = NULL;
      Vector* vector_003 = description->internal_variables;
      int index_003 = 0;
      int length_003 = vector_003->length();
      int iter_003 = 0;

      while (index_003 < length_003) {
        {
          vbl = ((Pattern_Variable*)(vector_003->nth(index_003)));
          index_003 = index_003 + 1;
        }
        {
          i = iter_003;
          iter_003 = iter_003 + 1;
        }
        if (description->io_variables->memberP(vbl)) {
          value = vbl;
          description->internal_variables->nth_setter(NULL, i);
        }
      }
    }
    if (value != NULL) {
      { Cons* newvbllist = NIL;

        { Pattern_Variable* vbl = NULL;
          Vector* vector_004 = description->internal_variables;
          int index_004 = 0;
          int length_004 = vector_004->length();
          Cons* collect_001 = NULL;

          while (index_004 < length_004) {
            {
              vbl = ((Pattern_Variable*)(vector_004->nth(index_004)));
              index_004 = index_004 + 1;
            }
            if (vbl != NULL) {
              if (collect_001 == NULL) {
                {
                  collect_001 = cons(vbl, NIL);
                  if (nilP(newvbllist)) {
                    newvbllist = collect_001;
                  }
                  else {
                    add_cons_to_end_of_cons_list(newvbllist, collect_001);
                  }
                }
              }
              else {
                {
                  collect_001->rest = cons(vbl, NIL);
                  collect_001 = collect_001->rest;
                }
              }
            }
          }
        }
        description->internal_variables = copy_cons_list_to_variables_vector(newvbllist);
        free_cons_list(newvbllist);
      }
    }
  }
}

void tighten_argument_bindings(Proposition* proposition) {
  { int i = NULL_INTEGER;
    Object* arg = NULL;
    Vector* vector_001 = proposition->arguments;
    int index_001 = 0;
    int length_001 = vector_001->length();
    int iter_001 = 0;

    while (index_001 < length_001) {
      {
        arg = vector_001->nth(index_001);
        index_001 = index_001 + 1;
      }
      {
        i = iter_001;
        iter_001 = iter_001 + 1;
      }
      { Object* arg_001 = arg;

        if (taxonomy_isaP(arg, SGT_DESCRIPTIONS_PATTERN_VARIABLE)) {
          { Pattern_Variable* arg = NULL;

            arg = ((Pattern_Variable*)(arg_001));
            { Pattern_Variable* tightestvariable = innermost_variable_of(arg);

              if (!(tightestvariable == arg)) {
                proposition->arguments->nth_setter(tightestvariable, i);
                remove_dependent_proposition_link(arg, proposition);
                add_dependent_proposition_link(tightestvariable, proposition);
                if (arg->defining_proposition != NULL) {
                  if (!((tightestvariable->defining_proposition == NULL) ||
                      (arg->defining_proposition == tightestvariable->defining_proposition))) {
                    cerr << "Safety violation: " << "INTERNAL ERROR: Collapsed two skolems, each " << "having a defining proposition, onto one.";
                  }
                  tightestvariable->defining_proposition = arg->defining_proposition;
                }
                if ((arg->defining_proposition != NULL) &&
                    (!(arg->defining_proposition == proposition))) {
                  tighten_argument_bindings(arg->defining_proposition);
                }
              }
            }
          }
        }
        else if (taxonomy_isaP(arg, SGT_DESCRIPTIONS_PROPOSITION)) {
          { Proposition* arg = NULL;

            arg = ((Proposition*)(arg_001));
            tighten_argument_bindings(arg);
          }
        }
        else {
        }
      }
    }
  }
}

void collect_all_variables(Proposition* self, List* collection, List* beenthere) {
  beenthere->insert(self);
  { Object* arg = NULL;
    Vector* vector_001 = self->arguments;
    int index_001 = 0;
    int length_001 = vector_001->length();

    while (index_001 < length_001) {
      {
        arg = vector_001->nth(index_001);
        index_001 = index_001 + 1;
      }
      { Object* arg_001 = arg;

        if (taxonomy_isaP(arg, SGT_DESCRIPTIONS_PATTERN_VARIABLE)) {
          { Pattern_Variable* arg = NULL;

            arg = ((Pattern_Variable*)(arg_001));
            collection->insert_new(arg);
          }
        }
        else if (taxonomy_isaP(arg, SGT_DESCRIPTIONS_PROPOSITION)) {
          { Proposition* arg = NULL;

            arg = ((Proposition*)(arg_001));
            if (!(beenthere->memberP(arg))) {
              collect_all_variables(arg, collection, beenthere);
            }
          }
        }
        else {
        }
      }
    }
  }
}

void compute_internal_variables(Description* self) {
  { List* collection = new_list();
    List* beenthere = new_list();

    collect_all_variables(self->proposition, collection, beenthere);
    { Pattern_Variable* vbl = NULL;
      Vector* vector_001 = self->io_variables;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          vbl = ((Pattern_Variable*)(vector_001->nth(index_001)));
          index_001 = index_001 + 1;
        }
        collection->remove(vbl);
      }
    }
    self->internal_variables = copy_cons_list_to_variables_vector(collection->the_cons_list);
    collection->free();
    beenthere->free();
  }
}

void equate_top_level_equivalences(Proposition* proposition) {
  { Vector* arguments = proposition->arguments;

    { Keyword* test_value_001 = proposition->kind;

      if (test_value_001 == KWD_DESCRIPTIONS_EQUIVALENCE) {
        equate_values(arguments->first(), arguments->second());
      }
      else if (test_value_001 == KWD_DESCRIPTIONS_AND) {
        { Object* arg = NULL;
          Vector* vector_001 = arguments;
          int index_001 = 0;
          int length_001 = vector_001->length();

          while (index_001 < length_001) {
            {
              arg = vector_001->nth(index_001);
              index_001 = index_001 + 1;
            }
            equate_top_level_equivalences(((Proposition*)(arg)));
          }
        }
      }
      else if (test_value_001 == KWD_DESCRIPTIONS_EXISTS) {
        equate_top_level_equivalences(((Proposition*)(arguments->first())));
      }
      else if (test_value_001 == KWD_DESCRIPTIONS_FUNCTION) {
        evaluate_function_proposition(proposition);
      }
      else {
      }
    }
  }
}

Description* finish_building_description(Description* description, boolean checkforduplicateP) {
  { Proposition* proposition = description->proposition;

    normalize_proposition(proposition);
    if (proposition->kind == KWD_DESCRIPTIONS_EXISTS) {
      proposition = ((Proposition*)(proposition->arguments->first()));
      description->proposition = proposition;
    }
    equate_top_level_equivalences(proposition);
  }
  collapse_value_of_chains(description);
  simplify_description(description, FALSE);
  compute_internal_variables(description);
  if (checkforduplicateP) {
    { Logic_Object* duplicatedescription = description->find_duplicate_description();

      if (duplicatedescription != NULL) {
        description->free();
        return (((Description*)(duplicatedescription)));
      }
    }
  }
  return (description);
}

Description* evaluate_description_term(Cons* term, boolean checkforduplicateP) {
  { Description* description = create_description(NULL_INTEGER, KWD_DESCRIPTIONS_DEFINITION);
    boolean queryP = oEVALUATIONMODEo == KWD_DESCRIPTIONS_QUERY;

    { Object* test_value_001 = term->first();

      if (test_value_001 == SYM_DESCRIPTIONS_THE_ONLY) {
        set_dynamic_slot_value(description, SYM_DESCRIPTIONS_IOTAp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
      }
      else {
      }
    }
    { Keyword* old_OevaluationmodeO_001 = oEVALUATIONMODEo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oEVALUATIONMODEo = (queryP ? ((Keyword*)(KWD_DESCRIPTIONS_QUERY)) : ((Keyword*)(KWD_DESCRIPTIONS_DESCRIPTION)));
            { Cons* iovars = NULL;
              Proposition* proposition = NULL;
              Proposition* unused = NULL;

              iovars = build_quantified_proposition(term, KWD_DESCRIPTIONS_CONCEIVE, proposition, unused);
              {
              }
              description->io_variables = copy_cons_list_to_variables_vector(iovars);
              free_cons_list(iovars);
              description->proposition = ((proposition != NULL) ? ((Proposition*)(proposition)) : ((Proposition*)(TRUE_PROPOSITION)));
            }
            { Description* return_value_001 = finish_building_description(description, checkforduplicateP);

              oEVALUATIONMODEo = old_OevaluationmodeO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (return_value_001);
            }
            oEVALUATIONMODEo = old_OevaluationmodeO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oEVALUATIONMODEo = old_OevaluationmodeO_001;
          resignal();
        }
      }
    }
  }
}

Description* create_top_level_description(Cons* tree, Keyword* kind, Relation* relation) {
  tree = ((Cons*)(standardize_logical_parse_tree(tree)));
  { Description* description = NULL;

    { Cons* old_OlogicvariabletableO_001 = oLOGICVARIABLETABLEo;
      Object* old_OpropositionunderconstructionO_001 = oPROPOSITIONUNDERCONSTRUCTIONo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oLOGICVARIABLETABLEo = NIL;
            oPROPOSITIONUNDERCONSTRUCTIONo = tree;
            {
              { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;
                boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                oPENDINGEXCEPTIONHANDLERpo = TRUE;
                if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  if (get_quoted_tree("((SETOF LISTOF) \"/LOGIC\")", "/LOGIC")->memberP(tree->first())) {
                    description = create_top_level_collection(tree, ((Class*)(relation)));
                  }
                  else {
                    description = evaluate_description_term(tree, FALSE);
                  }
                  oEXCEPTIONo = NULL;
                }
                oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
              }
              if (oEXCEPTIONo != NULL) {
                if (subtype_ofP(oEXCEPTION_TYPEo, SGT_DESCRIPTIONS_PROPOSITION_ERROR)) {
                }
                else {
                  resignal();
                }
              }
            }
            free_cons_list(oLOGICVARIABLETABLEo);
            oPROPOSITIONUNDERCONSTRUCTIONo = old_OpropositionunderconstructionO_001;
            oLOGICVARIABLETABLEo = old_OlogicvariabletableO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPROPOSITIONUNDERCONSTRUCTIONo = old_OpropositionunderconstructionO_001;
          oLOGICVARIABLETABLEo = old_OlogicvariabletableO_001;
          resignal();
        }
      }
    }
    if (description != NULL) {
      description->kind = kind;
    }
    tree->free_parse_tree();
    return (description);
  }
}

void augment_top_level_description(Description* self, Cons* tree) {
  { Proposition* proposition = NULL;
    Cons* internalskolems = NULL;

    { Cons* old_OlogicvariabletableO_001 = oLOGICVARIABLETABLEo;
      Object* old_OpropositionunderconstructionO_001 = oPROPOSITIONUNDERCONSTRUCTIONo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oLOGICVARIABLETABLEo = NIL;
            oPROPOSITIONUNDERCONSTRUCTIONo = tree;
            { Pattern_Variable* v = NULL;
              Vector* vector_001 = self->io_variables;
              int index_001 = 0;
              int length_001 = vector_001->length();

              while (index_001 < length_001) {
                {
                  v = ((Pattern_Variable*)(vector_001->nth(index_001)));
                  index_001 = index_001 + 1;
                }
                push_logic_variable_binding(v);
              }
            }
            { Keyword* old_OevaluationmodeO_001 = oEVALUATIONMODEo;
              Cons* old_OfreeskolemsO_001 = oFREESKOLEMSo;

              { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oEVALUATIONMODEo = KWD_DESCRIPTIONS_DESCRIPTION;
                    oFREESKOLEMSo = NIL;
                    proposition = build_proposition(tree, KWD_DESCRIPTIONS_ASSERT_TRUE);
                    internalskolems = oFREESKOLEMSo;
                    oFREESKOLEMSo = old_OfreeskolemsO_001;
                    oEVALUATIONMODEo = old_OevaluationmodeO_001;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oFREESKOLEMSo = old_OfreeskolemsO_001;
                  oEVALUATIONMODEo = old_OevaluationmodeO_001;
                  resignal();
                }
              }
            }
            pop_logic_variable_bindings(oLOGICVARIABLETABLEo);
            if ((proposition != NULL) &&
                (!(proposition->dependent_propositions != NULL))) {
              if (self->proposition == NULL) {
                {
                  self->proposition = proposition;
                }
              }
              else {
                { boolean foundP_001 = FALSE;

                  { Object* arg = NULL;
                    Vector* vector_002 = self->proposition->arguments;
                    int index_002 = 0;
                    int length_002 = vector_002->length();

                    while (index_002 < length_002) {
                      {
                        arg = vector_002->nth(index_002);
                        index_002 = index_002 + 1;
                      }
                      if (arg == proposition) {
                        foundP_001 = TRUE;
                        {
                          break;
                        }
                      }
                    }
                  }
                  if (foundP_001) {
                    {
                      {
                        {
                          oPROPOSITIONUNDERCONSTRUCTIONo = old_OpropositionunderconstructionO_001;
                          oLOGICVARIABLETABLEo = old_OlogicvariabletableO_001;
                          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                        }
                        return;
                      }
                    }
                  }
                  else {
                    {
                      self->proposition = conjoin_two_propositions(proposition, self->proposition);
                    }
                  }
                }
              }
            }
            if (internalskolems->non_emptyP()) {
              { Pattern_Variable* sk = NULL;
                Vector* vector_003 = self->internal_variables;
                int index_003 = 0;
                int length_003 = vector_003->length();

                while (index_003 < length_003) {
                  {
                    sk = ((Pattern_Variable*)(vector_003->nth(index_003)));
                    index_003 = index_003 + 1;
                  }
                  internalskolems = cons(sk, internalskolems);
                }
              }
              self->internal_variables->free();
              self->internal_variables = copy_cons_list_to_variables_vector(internalskolems);
              free_cons_list(internalskolems);
            }
            oPROPOSITIONUNDERCONSTRUCTIONo = old_OpropositionunderconstructionO_001;
            oLOGICVARIABLETABLEo = old_OlogicvariabletableO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPROPOSITIONUNDERCONSTRUCTIONo = old_OpropositionunderconstructionO_001;
          oLOGICVARIABLETABLEo = old_OlogicvariabletableO_001;
          resignal();
        }
      }
    }
  }
}

Description* create_top_level_collection(Cons* tree, Class* renamed_Class) {
  { Description* description = ((Description*)(dynamic_slot_value(renamed_Class, SYM_DESCRIPTIONS_DESCRIPTION, NULL)));
    Collection* collection = ((Collection*)(evaluate_term(tree)));
    Symbol* renamed_Operator = ((Symbol*)(tree->first()));

    if (description == NULL) {
      description = create_description_for_relation(renamed_Class);
    }
    description->kind = KWD_DESCRIPTIONS_ENUMERATION;
    if (description->extension_reader()->non_emptyP()) {
      { Cons* tobedeleted = NIL;
        Surrogate* type = renamed_Class->class_type;

        { Object* oldm = NULL;
          Cons* iter_001 = description->extension_reader()->the_cons_list;

          while (!nilP(iter_001)) {
            {
              oldm = iter_001->value;
              iter_001 = iter_001->rest;
            }
            if (!collection->memberP(((Logic_Object*)(oldm)))) {
              tobedeleted = cons(oldm, tobedeleted);
            }
          }
        }
        { Logic_Object* oldm = NULL;
          Cons* iter_002 = tobedeleted;

          while (!nilP(iter_002)) {
            {
              oldm = ((Logic_Object*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            cout << "Removing " << oldm << " from the extension of " << class_name(renamed_Class) << "." << endl;
            update_isa_proposition(oldm, type, KWD_DESCRIPTIONS_RETRACT_TRUE);
            if (oldm->root_type == type) {
              oldm->root_type = SGT_DESCRIPTIONS_UNKNOWN;
            }
            else {
              oldm->all_root_types_reader()->remove(type);
            }
            description->extension_reader()->remove(oldm);
          }
        }
        free_cons_list(tobedeleted);
      }
    }
    else {
      set_dynamic_slot_value(description, SYM_DESCRIPTIONS_EXTENSION, new_list(), NULL);
    }
    { Logic_Object* m = NULL;
      Iterator* iter_003 = ((Iterator*)(collection->allocate_iterator()));

      while (iter_003->nextP()) {
        {
          m = ((Logic_Object*)(iter_003->value));
        }
        assert_isa_proposition(m, renamed_Class->class_type);
      }
    }
    collection->free();
    description->extension_reader()->reverse();
    assert_property(description, SYM_DESCRIPTIONS_CLOSED);
    if (renamed_Operator == SYM_DESCRIPTIONS_LISTOF) {
      assert_property(description, SYM_DESCRIPTIONS_ORDERED);
    }
    else if (renamed_Operator == SYM_DESCRIPTIONS_SETOF) {
      assert_property(description, SYM_DESCRIPTIONS_DUPLICATE_FREE);
    }
    else {
      cerr << "`" << renamed_Operator << "'" << " is not a valid case option";
    }
    return (NULL);
  }
}

Cons* extract_variable_type_propositions(Proposition* proposition) {
  { Cons* typedeclarations = NIL;

    { Keyword* test_value_001 = proposition->kind;

      if (test_value_001 == KWD_DESCRIPTIONS_AND) {
        { int i = NULL_INTEGER;
          Object* arg = NULL;
          Vector* vector_001 = proposition->arguments;
          int index_001 = 0;
          int length_001 = vector_001->length();
          int iter_001 = 0;

          while (index_001 < length_001) {
            {
              arg = vector_001->nth(index_001);
              index_001 = index_001 + 1;
            }
            {
              i = iter_001;
              iter_001 = iter_001 + 1;
            }
            if (((Proposition*)(arg))->variable_typeP_reader()) {
              typedeclarations = cons(arg, typedeclarations);
              remove_dependent_proposition_link(arg, proposition);
              proposition->arguments->nth_setter(TRUE_PROPOSITION, i);
            }
          }
        }
      }
      else if (test_value_001 == KWD_DESCRIPTIONS_EXISTS) {
        cout << "COMPLEMENT OF :EXISTS NOT YET IMPLEMENTED" << endl;
      }
      else {
      }
    }
    return (typedeclarations);
  }
}

Description* get_complement_description(Description* self) {
  { Description* complement = ((Description*)(dynamic_slot_value(self, SYM_DESCRIPTIONS_COMPLEMENT_DESCRIPTION, NULL)));

    if (complement != NULL) {
      return (complement);
    }
    complement = copy_description(self, NULL);
    { Proposition* proposition = complement->proposition;
      Cons* toplevelconjuncts = extract_variable_type_propositions(proposition);

      invert_atomic_proposition(proposition);
      toplevelconjuncts = cons(proposition, toplevelconjuncts);
      proposition = conjoin_propositions(toplevelconjuncts->reverse());
      normalize_proposition(proposition);
      reassign_truth_values(proposition);
      complement->proposition = proposition;
    }
    set_dynamic_slot_value(self, SYM_DESCRIPTIONS_COMPLEMENT_DESCRIPTION, complement, NULL);
    set_dynamic_slot_value(complement, SYM_DESCRIPTIONS_COMPLEMENT_DESCRIPTION, self, NULL);
    return (complement);
  }
}

Description* parse_logical_definition(char* definition, Relation* relation) {
  { Object* parsetree = unstringify(definition);

    return (create_top_level_description(((Cons*)(parsetree)), KWD_DESCRIPTIONS_DEFINITION, relation));
  }
}

void inherit_type_onto_description(Description* description, Surrogate* type) {
  augment_top_level_description(description, listO(3, SYM_DESCRIPTIONS_ISA, ((Symbol*)(dynamic_slot_value(description->representative(), SYM_DESCRIPTIONS_SKOLEM_NAME, NULL))), cons(type, NIL)));
}

void inherit_slot_onto_description(Description* description, Slot* slot) {
  { Cons* argumentnames = NIL;
    Symbol* lastargname = NULL;

    { Pattern_Variable* arg = NULL;
      Vector* vector_001 = description->io_variables;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          arg = ((Pattern_Variable*)(vector_001->nth(index_001)));
          index_001 = index_001 + 1;
        }
        argumentnames = cons(((Symbol*)(dynamic_slot_value(arg, SYM_DESCRIPTIONS_SKOLEM_NAME, NULL))), argumentnames);
      }
    }
    if (isaP(slot->type(), SGT_DESCRIPTIONS_BOOLEAN)) {
      augment_top_level_description(description, cons(string_wrap_literal(slot->name()), argumentnames->reverse()->concatenate(NIL)));
    }
    else {
      {
        lastargname = ((Symbol*)(argumentnames->first()));
        argumentnames = argumentnames->rest;
        augment_top_level_description(description, cons((slot->single_valuedP() ? ((Symbol*)(SYM_DESCRIPTIONS_e)) : ((Symbol*)(SYM_DESCRIPTIONS_IN))), cons(lastargname, cons(cons(string_wrap_literal(slot->name()), argumentnames->reverse()->concatenate(NIL)), NIL))));
      }
    }
    free_cons_list(argumentnames);
  }
}

void Relation::construct_relation_definition() {
  { Relation* self = this;

    { Description* definition = parse_logical_definition(((String_Wrapper*)(dynamic_slot_value(self, SYM_DESCRIPTIONS_DEFINITION_STRING, NULL_STRING_WRAPPER)))->wrapper_value, self);

      if (definition == NULL) {
        return;
      }
      { Relation* self_001 = self;

        if (classP(self)) {
          { Class* self = NULL;

            self = ((Class*)(self_001));
            { Surrogate* supertype = NULL;
              Cons* iter_001 = self->class_direct_supers->the_cons_list;

              while (!nilP(iter_001)) {
                {
                  supertype = ((Surrogate*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                if (!subtype_ofP(logical_type(definition->representative()), supertype)) {
                  inherit_type_onto_description(definition, supertype);
                }
              }
            }
          }
        }
        else if (taxonomy_isaP(self, SGT_DESCRIPTIONS_SLOT)) {
          { Slot* self = NULL;

            self = ((Slot*)(self_001));
            { Slot* superslot = NULL;
              Cons* iter_002 = self->slot_direct_supers_reader()->the_cons_list;

              while (!nilP(iter_002)) {
                {
                  superslot = ((Slot*)(iter_002->value));
                  iter_002 = iter_002->rest;
                }
                inherit_slot_onto_description(definition, superslot);
              }
            }
          }
        }
        else {
          cerr << "`" << self << "'" << " is not a valid case option";
        }
      }
      definition->native_relation = self;
      set_dynamic_slot_value(self, SYM_DESCRIPTIONS_DEFINITION, definition, NULL);
    }
  }
}

void preclassify_description(Description* description) {
  description = description;
}

Proposition* conjoin_two_propositions(Proposition* prop1, Proposition* prop2) {
  if (prop1 == NULL) {
    return (prop2);
  }
  else if (prop2 == NULL) {
    return (prop1);
  }
  else {
    return (conjoin_propositions(cons_list(2, prop1, prop2)));
  }
}

void delete_proposition(Proposition* self) {
  { Object* arg = NULL;
    Vector* vector_001 = self->arguments;
    int index_001 = 0;
    int length_001 = vector_001->length();

    while (index_001 < length_001) {
      {
        arg = vector_001->nth(index_001);
        index_001 = index_001 + 1;
      }
      { Object* arg_001 = arg;

        if (taxonomy_isaP(arg, SGT_DESCRIPTIONS_PROPOSITION)) {
          { Proposition* arg = NULL;

            arg = ((Proposition*)(arg_001));
            arg->dependent_propositions->remove(self);
          }
        }
        else {
        }
      }
    }
  }
  self->free();
}

void startup_descriptions() {
  { Module* old_OmoduleO_001 = oMODULEo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = string_get_module("/LOGIC", TRUE);
          oCONTEXTo = oMODULEo;
          if (current_startup_time_phaseP(2)) {
            SYM_DESCRIPTIONS_pX1 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X1", NULL, 0)));
            SYM_DESCRIPTIONS_pX2 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X2", NULL, 0)));
            SYM_DESCRIPTIONS_pX3 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X3", NULL, 0)));
            SYM_DESCRIPTIONS_pX4 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X4", NULL, 0)));
            SYM_DESCRIPTIONS_pX5 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X5", NULL, 0)));
            SYM_DESCRIPTIONS_pX6 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X6", NULL, 0)));
            SYM_DESCRIPTIONS_pX7 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X7", NULL, 0)));
            SYM_DESCRIPTIONS_pX8 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X8", NULL, 0)));
            SYM_DESCRIPTIONS_pX9 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X9", NULL, 0)));
            SYM_DESCRIPTIONS_pX10 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X10", NULL, 0)));
            SYM_DESCRIPTIONS_pX11 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X11", NULL, 0)));
            SYM_DESCRIPTIONS_pX12 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X12", NULL, 0)));
            SYM_DESCRIPTIONS_pX13 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X13", NULL, 0)));
            SYM_DESCRIPTIONS_pX14 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X14", NULL, 0)));
            SYM_DESCRIPTIONS_pX15 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X15", NULL, 0)));
            SYM_DESCRIPTIONS_pX16 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X16", NULL, 0)));
            SYM_DESCRIPTIONS_pX17 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X17", NULL, 0)));
            SYM_DESCRIPTIONS_pX18 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X18", NULL, 0)));
            SYM_DESCRIPTIONS_pX19 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X19", NULL, 0)));
            SYM_DESCRIPTIONS_pX20 = ((Symbol*)(intern_rigid_symbol_wrt_module("?X20", NULL, 0)));
            SYM_DESCRIPTIONS_SETOFALL = ((Symbol*)(intern_rigid_symbol_wrt_module("SETOFALL", NULL, 0)));
            SYM_DESCRIPTIONS_ISA = ((Symbol*)(intern_rigid_symbol_wrt_module("ISA", string_get_module("/STELLA", TRUE), 0)));
            SYM_DESCRIPTIONS_pX = ((Symbol*)(intern_rigid_symbol_wrt_module("?X", NULL, 0)));
            SGT_DESCRIPTIONS_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("SLOT", string_get_module("/STELLA", TRUE), 1)));
            SGT_DESCRIPTIONS_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", string_get_module("/STELLA", TRUE), 1)));
            SGT_DESCRIPTIONS_TABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TABLE", string_get_module("/STELLA", TRUE), 1)));
            SYM_DESCRIPTIONS_KAPPA = ((Symbol*)(intern_rigid_symbol_wrt_module("KAPPA", NULL, 0)));
            SYM_DESCRIPTIONS_COMMA = ((Symbol*)(intern_rigid_symbol_wrt_module("COMMA", string_get_module("/STELLA", TRUE), 0)));
            SYM_DESCRIPTIONS_WHERE = ((Symbol*)(intern_rigid_symbol_wrt_module("WHERE", string_get_module("/STELLA", TRUE), 0)));
            SGT_DESCRIPTIONS_COLLECTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION", string_get_module("/STELLA", TRUE), 1)));
            SYM_DESCRIPTIONS_IN = ((Symbol*)(intern_rigid_symbol_wrt_module("IN", string_get_module("/STELLA", TRUE), 0)));
            SYM_DESCRIPTIONS_e = ((Symbol*)(intern_rigid_symbol_wrt_module("=", string_get_module("/STELLA", TRUE), 0)));
            KWD_DESCRIPTIONS_PREFIX_STELLA = ((Keyword*)(intern_rigid_symbol_wrt_module("PREFIX-STELLA", NULL, 2)));
            KWD_DESCRIPTIONS_PRIMITIVE = ((Keyword*)(intern_rigid_symbol_wrt_module("PRIMITIVE", NULL, 2)));
            SYM_DESCRIPTIONS_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 0)));
            SGT_DESCRIPTIONS_DESCRIPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 1)));
            SGT_DESCRIPTIONS_RELATION = ((Surrogate*)(intern_rigid_symbol_wrt_module("RELATION", string_get_module("/STELLA", TRUE), 1)));
            SYM_DESCRIPTIONS_DEFINITION_STRING = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINITION-STRING", NULL, 0)));
            SYM_DESCRIPTIONS_DEFINITION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINITION", NULL, 0)));
            SGT_DESCRIPTIONS_LOGIC_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-OBJECT", NULL, 1)));
            SYM_DESCRIPTIONS_ANY_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("ANY-VALUE", string_get_module("/STELLA", TRUE), 0)));
            SGT_DESCRIPTIONS_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("ITERATOR", string_get_module("/STELLA", TRUE), 1)));
            SYM_DESCRIPTIONS_oLOGICVARIABLETABLEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*LOGICVARIABLETABLE*", NULL, 0)));
            SYM_DESCRIPTIONS_SKOLEM_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SKOLEM-NAME", NULL, 0)));
            SYM_DESCRIPTIONS_VARIABLE_TYPEp = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-TYPE?", NULL, 0)));
            KWD_DESCRIPTIONS_CONCEIVE = ((Keyword*)(intern_rigid_symbol_wrt_module("CONCEIVE", NULL, 2)));
            KWD_DESCRIPTIONS_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            KWD_DESCRIPTIONS_PREDICATE = ((Keyword*)(intern_rigid_symbol_wrt_module("PREDICATE", NULL, 2)));
            KWD_DESCRIPTIONS_IN = ((Keyword*)(intern_rigid_symbol_wrt_module("IN", NULL, 2)));
            KWD_DESCRIPTIONS_EQUIVALENT = ((Keyword*)(intern_rigid_symbol_wrt_module("EQUIVALENT", NULL, 2)));
            SGT_DESCRIPTIONS_PATTERN_VARIABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("PATTERN-VARIABLE", NULL, 1)));
            SYM_DESCRIPTIONS_EXISTS = ((Symbol*)(intern_rigid_symbol_wrt_module("EXISTS", string_get_module("/STELLA", TRUE), 0)));
            SYM_DESCRIPTIONS_AND = ((Symbol*)(intern_rigid_symbol_wrt_module("AND", string_get_module("/STELLA", TRUE), 0)));
            SYM_DESCRIPTIONS_IO_VARIABLES = ((Symbol*)(intern_rigid_symbol_wrt_module("IO-VARIABLES", NULL, 0)));
            SGT_DESCRIPTIONS_SKOLEM = ((Surrogate*)(intern_rigid_symbol_wrt_module("SKOLEM", NULL, 1)));
            SGT_DESCRIPTIONS_PROPOSITION = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPOSITION", NULL, 1)));
            KWD_DESCRIPTIONS_EQUIVALENCE = ((Keyword*)(intern_rigid_symbol_wrt_module("EQUIVALENCE", NULL, 2)));
            KWD_DESCRIPTIONS_AND = ((Keyword*)(intern_rigid_symbol_wrt_module("AND", NULL, 2)));
            KWD_DESCRIPTIONS_EXISTS = ((Keyword*)(intern_rigid_symbol_wrt_module("EXISTS", NULL, 2)));
            KWD_DESCRIPTIONS_DEFINITION = ((Keyword*)(intern_rigid_symbol_wrt_module("DEFINITION", NULL, 2)));
            KWD_DESCRIPTIONS_QUERY = ((Keyword*)(intern_rigid_symbol_wrt_module("QUERY", NULL, 2)));
            SYM_DESCRIPTIONS_THE_ONLY = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-ONLY", NULL, 0)));
            SYM_DESCRIPTIONS_IOTAp = ((Symbol*)(intern_rigid_symbol_wrt_module("IOTA?", NULL, 0)));
            KWD_DESCRIPTIONS_DESCRIPTION = ((Keyword*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 2)));
            SGT_DESCRIPTIONS_PROPOSITION_ERROR = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPOSITION-ERROR", NULL, 1)));
            KWD_DESCRIPTIONS_ASSERT_TRUE = ((Keyword*)(intern_rigid_symbol_wrt_module("ASSERT-TRUE", NULL, 2)));
            KWD_DESCRIPTIONS_ENUMERATION = ((Keyword*)(intern_rigid_symbol_wrt_module("ENUMERATION", NULL, 2)));
            KWD_DESCRIPTIONS_RETRACT_TRUE = ((Keyword*)(intern_rigid_symbol_wrt_module("RETRACT-TRUE", NULL, 2)));
            SGT_DESCRIPTIONS_UNKNOWN = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNKNOWN", string_get_module("/STELLA", TRUE), 1)));
            SYM_DESCRIPTIONS_EXTENSION = ((Symbol*)(intern_rigid_symbol_wrt_module("EXTENSION", string_get_module("/STELLA", TRUE), 0)));
            SYM_DESCRIPTIONS_CLOSED = ((Symbol*)(intern_rigid_symbol_wrt_module("CLOSED", string_get_module("/STELLA", TRUE), 0)));
            SYM_DESCRIPTIONS_LISTOF = ((Symbol*)(intern_rigid_symbol_wrt_module("LISTOF", NULL, 0)));
            SYM_DESCRIPTIONS_SETOF = ((Symbol*)(intern_rigid_symbol_wrt_module("SETOF", string_get_module("/STELLA", TRUE), 0)));
            SYM_DESCRIPTIONS_ORDERED = ((Symbol*)(intern_rigid_symbol_wrt_module("ORDERED", NULL, 0)));
            SYM_DESCRIPTIONS_DUPLICATE_FREE = ((Symbol*)(intern_rigid_symbol_wrt_module("DUPLICATE-FREE", NULL, 0)));
            SYM_DESCRIPTIONS_COMPLEMENT_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("COMPLEMENT-DESCRIPTION", NULL, 0)));
          }
          if (current_startup_time_phaseP(4)) {
            FAKE_IO_VARIABLES = new_vector(0);
            SYSTEM_DEFINED_ARGUMENT_NAMES = listO(21, SYM_DESCRIPTIONS_pX1, SYM_DESCRIPTIONS_pX2, SYM_DESCRIPTIONS_pX3, SYM_DESCRIPTIONS_pX4, SYM_DESCRIPTIONS_pX5, SYM_DESCRIPTIONS_pX6, SYM_DESCRIPTIONS_pX7, SYM_DESCRIPTIONS_pX8, SYM_DESCRIPTIONS_pX9, SYM_DESCRIPTIONS_pX10, SYM_DESCRIPTIONS_pX11, SYM_DESCRIPTIONS_pX12, SYM_DESCRIPTIONS_pX13, SYM_DESCRIPTIONS_pX14, SYM_DESCRIPTIONS_pX15, SYM_DESCRIPTIONS_pX16, SYM_DESCRIPTIONS_pX17, SYM_DESCRIPTIONS_pX18, SYM_DESCRIPTIONS_pX19, SYM_DESCRIPTIONS_pX20, NIL);
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            define_external_slot_from_stringified_source("(DEFSLOT RELATION DESCRIPTION :TYPE DESCRIPTION :DOCUMENTATION \"Maps a relation (class or slot or table) to a\nprimitive description.\" :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT RELATION DEFINITION :TYPE DESCRIPTION :DOCUMENTATION \"Maps a relation to a defining description.\" :ALLOCATION :DYNAMIC)");
            { Method_Slot* method = define_method_from_stringified_source("CREATE-DESCRIPTION", "INTEGER", "(DEFUN (CREATE-DESCRIPTION DESCRIPTION) ((ARITY INTEGER) (KIND KEYWORD)))");

              method->function_code = ((cpp_function_code)(&create_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-DESCRIPTION-FOR-RELATION", "RELATION", "(DEFUN (CREATE-DESCRIPTION-FOR-RELATION DESCRIPTION) ((SELF RELATION)))");

              method->function_code = ((cpp_function_code)(&create_description_for_relation));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-DESCRIPTION", "SURROGATE", "(DEFMETHOD (GET-DESCRIPTION DESCRIPTION) ((SELF SURROGATE)))");

              method->method_code = ((cpp_method_code)(&Surrogate::get_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-DESCRIPTION", "SYMBOL", "(DEFMETHOD (GET-DESCRIPTION DESCRIPTION) ((SELF SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Symbol::get_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-DESCRIPTION", "GENERALIZED-SYMBOL", "(DEFMETHOD (GET-DESCRIPTION DESCRIPTION) ((SELF GENERALIZED-SYMBOL)) :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Generalized_Symbol::get_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-DESCRIPTION", "STRING", "(DEFMETHOD (GET-DESCRIPTION DESCRIPTION) ((SELF STRING)) :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-DESCRIPTION", "RELATION", "(DEFMETHOD (GET-DESCRIPTION DESCRIPTION) ((SELF RELATION)))");

              method->method_code = ((cpp_method_code)(&Relation::get_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-DESCRIPTION", "CLASS", "(DEFMETHOD (GET-DESCRIPTION DESCRIPTION) ((SELF CLASS)))");

              method->method_code = ((cpp_method_code)(&Class::get_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-DESCRIPTION", "SLOT", "(DEFMETHOD (GET-DESCRIPTION DESCRIPTION) ((SELF SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::get_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRIMITIVE?", "CLASS", "(DEFMETHOD (PRIMITIVE? BOOLEAN) ((SELF CLASS)) :DOCUMENTATION \"Return TRUE if 'self' is not a defined class.\")");

              method->method_code = ((cpp_method_code)(&Class::primitiveP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRIMITIVE?", "SLOT", "(DEFMETHOD (PRIMITIVE? BOOLEAN) ((SELF SLOT)) :DOCUMENTATION \"Return TRUE if 'self' is not a defined slot.\")");

              method->method_code = ((cpp_method_code)(&Slot::primitiveP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRIMITIVE?", "DESCRIPTION", "(DEFMETHOD (PRIMITIVE? BOOLEAN) ((SELF DESCRIPTION)) :DOCUMENTATION \"Return TRUE if 'self' attached to a primitive\nrelation.  Definitions that enumerate their members are considered\nprimitive.\")");

              method->method_code = ((cpp_method_code)(&Description::primitiveP));
            }
            define_external_slot_from_stringified_source("(DEFSLOT COLLECTION CLOSED :TYPE BOOLEAN :PUBLIC? TRUE :ABSTRACT? TRUE :DOCUMENTATION \"Holds for collection if all of its members\nare known to the system.\")");
            define_external_slot_from_stringified_source("(DEFSLOT COLLECTION DUPLICATE-FREE :TYPE BOOLEAN :PUBLIC? TRUE :ABSTRACT? TRUE :DOCUMENTATION \"Holds for collection if no two members\ndenote the same object.\")");
            define_external_slot_from_stringified_source("(DEFSLOT COLLECTION ORDERED :TYPE BOOLEAN :PUBLIC? TRUE :ABSTRACT? TRUE :DOCUMENTATION \"Holds for collection ?c the ordering of its\nmembers is significant.\")");
            { Method_Slot* method = define_method_from_stringified_source("DESCRIPTION-OWNER-TYPE", "DESCRIPTION", "(DEFUN (DESCRIPTION-OWNER-TYPE TYPE) ((DESCRIPTION DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&description_owner_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOGIC-OBJECT.MEMBER-TYPE-FROM-COLLECTION", "LOGIC-OBJECT", "(DEFUN (LOGIC-OBJECT.MEMBER-TYPE-FROM-COLLECTION TYPE) ((SELF LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&logic_objectDmember_type_from_collection));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIPTION.MEMBER-TYPE-FROM-COLLECTION", "DESCRIPTION", "(DEFUN (DESCRIPTION.MEMBER-TYPE-FROM-COLLECTION TYPE) ((SELF DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&descriptionDmember_type_from_collection));
            }
            { Method_Slot* method = define_method_from_stringified_source("MEMBER-TYPE-FROM-COLLECTION", "OBJECT", "(DEFUN (MEMBER-TYPE-FROM-COLLECTION TYPE) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&member_type_from_collection));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIPTION-NAME", "DESCRIPTION", "(DEFUN (DESCRIPTION-NAME SYMBOL) ((SELF DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&description_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUSH-LOGIC-VARIABLE-BINDING", "SKOLEM", "(DEFUN PUSH-LOGIC-VARIABLE-BINDING ((VARIABLE SKOLEM)))");

              method->function_code = ((cpp_function_code)(&push_logic_variable_binding));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP-LOGIC-VARIABLE-BINDING", NULL, "(DEFUN POP-LOGIC-VARIABLE-BINDING ())");

              method->function_code = ((cpp_function_code)(&pop_logic_variable_binding));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP-LOGIC-VARIABLE-BINDINGS", "CONS", "(DEFUN POP-LOGIC-VARIABLE-BINDINGS ((VARIABLES (CONS OF SKOLEM))))");

              method->function_code = ((cpp_function_code)(&pop_logic_variable_bindings));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-LOGIC-VARIABLE-BINDING", "SYMBOL", "(DEFUN (LOOKUP-LOGIC-VARIABLE-BINDING OBJECT) ((VARIABLENAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&lookup_logic_variable_binding));
            }
            { Method_Slot* method = define_method_from_stringified_source("PARSE-LOGIC-VARIABLE-DECLARATIONS", "CONS", "(DEFUN (PARSE-LOGIC-VARIABLE-DECLARATIONS (CONS OF SKOLEM)) ((TREE CONS) (UPDATEMODE KEYWORD) (VARIABLE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&parse_logic_variable_declarations));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-CONS-LIST-TO-VARIABLES-VECTOR", "CONS", "(DEFUN (COPY-CONS-LIST-TO-VARIABLES-VECTOR VARIABLES-VECTOR) ((CONSLIST CONS)))");

              method->function_code = ((cpp_function_code)(&copy_cons_list_to_variables_vector));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-QUANTIFIED-PROPOSITION", "CONS", "(DEFUN (BUILD-QUANTIFIED-PROPOSITION (CONS OF SKOLEM) PROPOSITION PROPOSITION) ((TREE CONS) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&build_quantified_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-DUPLICATE-DESCRIPTION", "DESCRIPTION", "(DEFMETHOD (FIND-DUPLICATE-DESCRIPTION LOGIC-OBJECT) ((SELF DESCRIPTION)))");

              method->method_code = ((cpp_method_code)(&Description::find_duplicate_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTAINS-NESTED-ARGUMENT?", "PROPOSITION", "(DEFUN (CONTAINS-NESTED-ARGUMENT? BOOLEAN) ((ATOMICPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&contains_nested_argumentP));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-COLLECT-FLATTENED-ARGUMENTS", "PROPOSITION", "(DEFUN HELP-COLLECT-FLATTENED-ARGUMENTS ((SELF PROPOSITION) (FLATTENEDARGUMENTS (LIST OF PROPOSITION)) (BEENTHERE LIST)))");

              method->function_code = ((cpp_function_code)(&help_collect_flattened_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-FLATTENED-ARGUMENTS", "PROPOSITION", "(DEFUN (YIELD-FLATTENED-ARGUMENTS (LIST OF PROPOSITION)) ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&yield_flattened_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("FLATTEN-NESTED-FUNCTION-ARGUMENTS", "PROPOSITION", "(DEFUN (FLATTEN-NESTED-FUNCTION-ARGUMENTS PROPOSITION) ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&flatten_nested_function_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLAPSE-VALUE-OF-CHAINS", "DESCRIPTION", "(DEFUN COLLAPSE-VALUE-OF-CHAINS ((DESCRIPTION DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&collapse_value_of_chains));
            }
            { Method_Slot* method = define_method_from_stringified_source("TIGHTEN-ARGUMENT-BINDINGS", "PROPOSITION", "(DEFUN TIGHTEN-ARGUMENT-BINDINGS ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&tighten_argument_bindings));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-ALL-VARIABLES", "PROPOSITION", "(DEFUN COLLECT-ALL-VARIABLES ((SELF PROPOSITION) (COLLECTION (LIST OF PATTERN-VARIABLE)) (BEENTHERE LIST)))");

              method->function_code = ((cpp_function_code)(&collect_all_variables));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-INTERNAL-VARIABLES", "DESCRIPTION", "(DEFUN COMPUTE-INTERNAL-VARIABLES ((SELF DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&compute_internal_variables));
            }
            { Method_Slot* method = define_method_from_stringified_source("EQUATE-TOP-LEVEL-EQUIVALENCES", "PROPOSITION", "(DEFUN EQUATE-TOP-LEVEL-EQUIVALENCES ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&equate_top_level_equivalences));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINISH-BUILDING-DESCRIPTION", "DESCRIPTION", "(DEFUN (FINISH-BUILDING-DESCRIPTION DESCRIPTION) ((DESCRIPTION DESCRIPTION) (CHECKFORDUPLICATE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&finish_building_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-DESCRIPTION-TERM", "CONS", "(DEFUN (EVALUATE-DESCRIPTION-TERM DESCRIPTION) ((TERM CONS) (CHECKFORDUPLICATE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&evaluate_description_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-TOP-LEVEL-DESCRIPTION", "CONS", "(DEFUN (CREATE-TOP-LEVEL-DESCRIPTION DESCRIPTION) ((TREE CONS) (KIND KEYWORD) (RELATION RELATION)))");

              method->function_code = ((cpp_function_code)(&create_top_level_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("AUGMENT-TOP-LEVEL-DESCRIPTION", "DESCRIPTION", "(DEFUN AUGMENT-TOP-LEVEL-DESCRIPTION ((SELF DESCRIPTION) (TREE CONS)))");

              method->function_code = ((cpp_function_code)(&augment_top_level_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-TOP-LEVEL-COLLECTION", "CONS", "(DEFUN (CREATE-TOP-LEVEL-COLLECTION DESCRIPTION) ((TREE CONS) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&create_top_level_collection));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-VARIABLE-TYPE-PROPOSITIONS", "PROPOSITION", "(DEFUN (EXTRACT-VARIABLE-TYPE-PROPOSITIONS (CONS OF PROPOSITION)) ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&extract_variable_type_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-COMPLEMENT-DESCRIPTION", "DESCRIPTION", "(DEFUN (GET-COMPLEMENT-DESCRIPTION DESCRIPTION) ((SELF DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&get_complement_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("PARSE-LOGICAL-DEFINITION", "STRING", "(DEFUN (PARSE-LOGICAL-DEFINITION DESCRIPTION) ((DEFINITION STRING) (RELATION RELATION)))");

              method->function_code = ((cpp_function_code)(&parse_logical_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-TYPE-ONTO-DESCRIPTION", "DESCRIPTION", "(DEFUN INHERIT-TYPE-ONTO-DESCRIPTION ((DESCRIPTION DESCRIPTION) (TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&inherit_type_onto_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-SLOT-ONTO-DESCRIPTION", "DESCRIPTION", "(DEFUN INHERIT-SLOT-ONTO-DESCRIPTION ((DESCRIPTION DESCRIPTION) (SLOT SLOT)))");

              method->function_code = ((cpp_function_code)(&inherit_slot_onto_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONSTRUCT-RELATION-DEFINITION", "RELATION", "(DEFMETHOD CONSTRUCT-RELATION-DEFINITION ((SELF RELATION)))");

              method->method_code = ((cpp_method_code)(&Relation::construct_relation_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRECLASSIFY-DESCRIPTION", "DESCRIPTION", "(DEFUN PRECLASSIFY-DESCRIPTION ((DESCRIPTION DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&preclassify_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONJOIN-TWO-PROPOSITIONS", "PROPOSITION", "(DEFUN (CONJOIN-TWO-PROPOSITIONS PROPOSITION) ((PROP1 PROPOSITION) (PROP2 PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&conjoin_two_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETE-PROPOSITION", "PROPOSITION", "(DEFUN DELETE-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&delete_proposition));
            }
            define_method_from_stringified_source("STARTUP-DESCRIPTIONS", NULL, "(DEFUN STARTUP-DESCRIPTIONS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT FAKE-IO-VARIABLES VARIABLES-VECTOR (NEW VARIABLES-VECTOR :ARRAY-SIZE 0) :DOCUMENTATION \"Installed in a description with undetermined arity.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT SYSTEM-DEFINED-ARGUMENT-NAMES (CONS OF SYMBOL) (BQUOTE (?X1 ?X2 ?X3 ?X4 ?X5 ?X6 ?X7 ?X8 ?X9 ?X10 ?X11 ?X12 ?X13 ?X14 ?X15 ?X16 ?X17 ?X18 ?X19 ?X20)))");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *LOGICVARIABLETABLE* (CONS OF SKOLEM) NULL :DOCUMENTATION \"Table mapping logic variable names to variables or skolems.\nUsed during construction of a proposition or description.\")");
            { Global_Variable* global = SYM_DESCRIPTIONS_oLOGICVARIABLETABLEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OlogicvariabletableO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OlogicvariabletableO));
            }
          }
          oCONTEXTo = old_OcontextO_001;
          oMODULEo = old_OmoduleO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oCONTEXTo = old_OcontextO_001;
        oMODULEo = old_OmoduleO_001;
        resignal();
      }
    }
  }
}

