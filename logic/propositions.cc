// propositions.cc

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

Symbol* SYM_PROPOSITIONS_ALL_ROOT_TYPES = NULL;

Symbol* SYM_PROPOSITIONS_ALL_SURROGATE_VALUE_INVERSES = NULL;

Symbol* SYM_PROPOSITIONS_ROOT_TYPE = NULL;

Symbol* SYM_PROPOSITIONS_DEPENDENT_ATTRIBUTE_PROPOSITIONS = NULL;

Symbol* SYM_PROPOSITIONS_DEPENDENT_PROPOSITIONS = NULL;

Symbol* SYM_PROPOSITIONS_VARIABLE_VALUE = NULL;

Symbol* SYM_PROPOSITIONS_VARIABLE_VALUE_INVERSE = NULL;

Surrogate* SGT_PROPOSITIONS_LOGIC_OBJECT = NULL;

Symbol* SYM_PROPOSITIONS_SKOLEM_TYPE = NULL;

Symbol* SYM_PROPOSITIONS_NOT_BOTTOMp = NULL;

Symbol* SYM_PROPOSITIONS_DEFINING_PROPOSITION = NULL;

Surrogate* SGT_PROPOSITIONS_SKOLEM = NULL;

Symbol* SYM_PROPOSITIONS_BOUND_TO_OFFSET = NULL;

Surrogate* SGT_PROPOSITIONS_PATTERN_VARIABLE = NULL;

Symbol* SYM_PROPOSITIONS_OBJECT_VECTOR = NULL;

Symbol* SYM_PROPOSITIONS_ARGUMENTS_VECTOR = NULL;

Symbol* SYM_PROPOSITIONS_VARIABLES_VECTOR = NULL;

Vector* ZERO_VARIABLES_VECTOR = NULL;

Symbol* SYM_PROPOSITIONS_EXTENSION = NULL;

Symbol* SYM_PROPOSITIONS_IOTAp = NULL;

Symbol* SYM_PROPOSITIONS_PROPOSITION = NULL;

Symbol* SYM_PROPOSITIONS_IO_VARIABLES = NULL;

Symbol* SYM_PROPOSITIONS_INTERNAL_VARIABLES = NULL;

Symbol* SYM_PROPOSITIONS_KIND = NULL;

Symbol* SYM_PROPOSITIONS_NATIVE_RELATION = NULL;

Symbol* SYM_PROPOSITIONS_QUERY_PATTERNS = NULL;

Symbol* SYM_PROPOSITIONS_REFERENCED_BY = NULL;

Symbol* SYM_PROPOSITIONS_TAXONOMY_NODE = NULL;

Surrogate* SGT_PROPOSITIONS_DESCRIPTION = NULL;

Surrogate* SGT_PROPOSITIONS_SLOT = NULL;

Symbol* SYM_PROPOSITIONS_PARTIAL_MATCH_SCORE = NULL;

Symbol* SYM_PROPOSITIONS_SET_OF_SUPPORT = NULL;

Symbol* SYM_PROPOSITIONS_TIME_STAMP = NULL;

Symbol* SYM_PROPOSITIONS_POSITIVE_SCORE = NULL;

Symbol* SYM_PROPOSITIONS_NEGATIVE_SCORE = NULL;

Symbol* SYM_PROPOSITIONS_POSITIVE_SET_OF_SUPPORT = NULL;

Symbol* SYM_PROPOSITIONS_NEGATIVE_SET_OF_SUPPORT = NULL;

Surrogate* SGT_PROPOSITIONS_TRUTH_VALUE = NULL;

Symbol* SYM_PROPOSITIONS_VARIABLE_TYPEp = NULL;

Symbol* SYM_PROPOSITIONS_SUBRELATION_LINKp = NULL;

Symbol* SYM_PROPOSITIONS_SUBSUMPTION_LINKp = NULL;

Symbol* SYM_PROPOSITIONS_SATELLITE_PROPOSITIONS = NULL;

Symbol* SYM_PROPOSITIONS_DONT_OPTIMIZEp = NULL;

Symbol* SYM_PROPOSITIONS_FORWARD_ONLYp = NULL;

Symbol* SYM_PROPOSITIONS_BACKWARD_ONLYp = NULL;

Symbol* SYM_PROPOSITIONS_TRUTH_VALUE = NULL;

Symbol* SYM_PROPOSITIONS_ARGUMENTS = NULL;

Symbol* SYM_PROPOSITIONS_OPERATOR = NULL;

Symbol* SYM_PROPOSITIONS_SLOTREF = NULL;

Surrogate* SGT_PROPOSITIONS_PROPOSITION = NULL;

Symbol* SYM_PROPOSITIONS_FUNCTION = NULL;

Symbol* SYM_PROPOSITIONS_PREDICATE = NULL;

Symbol* SYM_PROPOSITIONS_CONTEXT_ASSUMED_PROPOSITIONS = NULL;

Symbol* SYM_PROPOSITIONS_MONOTONICp = NULL;

Symbol* SYM_PROPOSITIONS_TRUTH_MAINTAINEDp = NULL;

Symbol* SYM_PROPOSITIONS_UP_TO_DATE_INFERENCESp = NULL;

Symbol* SYM_PROPOSITIONS_LOCALLY_CONCEIVED_PROPOSITIONS = NULL;

Symbol* SYM_PROPOSITIONS_LOCALLY_BOUND_PROPOSITIONS = NULL;

Symbol* SYM_PROPOSITIONS_LOCALLY_BOUND_SKOLEMS = NULL;

int oNOW_TIME_STAMPo = 0;

Keyword* oLAST_KB_ACTIONo = NULL;

Keyword* KWD_PROPOSITIONS_UPDATE_PROPOSITION = NULL;

Keyword* KWD_PROPOSITIONS_EXECUTE_QUERY = NULL;

Logic_Object* BOTTOM = NULL;

Symbol* SYM_PROPOSITIONS_BOTTOM = NULL;

Surrogate* SGT_PROPOSITIONS_LITERAL_WRAPPER = NULL;

Surrogate* SGT_PROPOSITIONS_LITERAL = NULL;

Keyword* KWD_PROPOSITIONS_OPEN_WORLD = NULL;

Keyword* KWD_PROPOSITIONS_CLOSED_WORLD = NULL;

Keyword* oEVALUATIONMODEo = NULL;

Keyword* KWD_PROPOSITIONS_EXTENSIONAL_ASSERTION = NULL;

Symbol* SYM_PROPOSITIONS_oEVALUATIONMODEo = NULL;

Keyword* KWD_PROPOSITIONS_DESCRIPTION = NULL;

Keyword* KWD_PROPOSITIONS_QUERY = NULL;

Keyword* KWD_PROPOSITIONS_CONCEIVE = NULL;

boolean oCLIPPING_ENABLEDo = TRUE;

boolean oCONTEXT_DEPENDENT_SEARCH_MODEpo = FALSE;

Keyword* KWD_PROPOSITIONS_IMPLIES = NULL;

Keyword* KWD_PROPOSITIONS_RETRACT_TRUE = NULL;

Symbol* SYM_PROPOSITIONS_MASTER_PROPOSITION = NULL;

Keyword* KWD_PROPOSITIONS_ASSERT_TRUE = NULL;

Keyword* KWD_PROPOSITIONS_ASSERT_FALSE = NULL;

Keyword* KWD_PROPOSITIONS_RETRACT_FALSE = NULL;

Symbol* SYM_PROPOSITIONS_STRICT_INFERENCE_CACHE = NULL;

Surrogate* SGT_PROPOSITIONS_MODULE = NULL;

Keyword* KWD_PROPOSITIONS_STRICT = NULL;

Keyword* KWD_PROPOSITIONS_FUNCTION = NULL;

Keyword* KWD_PROPOSITIONS_CONSTANT = NULL;

Symbol* SYM_PROPOSITIONS_DESCRIPTION = NULL;

Keyword* KWD_PROPOSITIONS_PRIMITIVE = NULL;

Surrogate* SGT_PROPOSITIONS_STORAGE_SLOT = NULL;

Symbol* SYM_PROPOSITIONS_COMPLEMENT_DESCRIPTION = NULL;

Keyword* KWD_PROPOSITIONS_IN = NULL;

Surrogate* SGT_PROPOSITIONS_UNKNOWN = NULL;

Surrogate* SGT_PROPOSITIONS_RELATION = NULL;

int oSKOLEM_ID_COUNTERo = 0;

Cons* oFREESKOLEMSo = NULL;

Symbol* SYM_PROPOSITIONS_oFREESKOLEMSo = NULL;

Symbol* SYM_PROPOSITIONS_SKOLEM_NAME = NULL;

Truth_Value* TRUE_TRUTH_VALUE = NULL;

Truth_Value* FALSE_TRUTH_VALUE = NULL;

Surrogate* SGT_PROPOSITIONS_COLLECTION = NULL;

Surrogate* SGT_PROPOSITIONS_SURROGATE = NULL;

Keyword* KWD_PROPOSITIONS_AND = NULL;

Keyword* KWD_PROPOSITIONS_OR = NULL;

Proposition* TRUE_PROPOSITION = NULL;

Surrogate* SGT_PROPOSITIONS_TRUE = NULL;

Proposition* FALSE_PROPOSITION = NULL;

Surrogate* SGT_PROPOSITIONS_FALSE = NULL;

Symbol* SYM_PROPOSITIONS_PERMUTATION_TABLE = NULL;

Keyword* KWD_PROPOSITIONS_NOT = NULL;

Keyword* KWD_PROPOSITIONS_EQUIVALENT = NULL;

Keyword* KWD_PROPOSITIONS_PREDICATE = NULL;

Surrogate* SGT_PROPOSITIONS_TRAP_DOOR_SURROGATE = NULL;

Symbol* SYM_PROPOSITIONS_SETOFALL = NULL;

Symbol* SYM_PROPOSITIONS_THE_ONLY = NULL;

Symbol* SYM_PROPOSITIONS_KAPPA = NULL;

Symbol* SYM_PROPOSITIONS_SETOF = NULL;

Symbol* SYM_PROPOSITIONS_LISTOF = NULL;

Symbol* SYM_PROPOSITIONS_CREATE = NULL;

Keyword* KWD_PROPOSITIONS_INTENSIONAL_ASSERTION = NULL;

Symbol* ANONYMOUS_VARIABLE_NAME = NULL;

Symbol* SYM_PROPOSITIONS_p = NULL;

Symbol* SYM_PROPOSITIONS_EVALUATOR_WRAPPER_CODE = NULL;

Symbol* SYM_PROPOSITIONS_NON_DISJOINTNESS_KLUDGEp = NULL;

Symbol* SYM_PROPOSITIONS_CLASS_EXTENSION = NULL;

Symbol* SYM_PROPOSITIONS_TRANSFER_LOGIC_INFORMATION_FROM_RELATION_HOOK = NULL;

Symbol* SYM_PROPOSITIONS_IMPLIES = NULL;

Symbol* SYM_PROPOSITIONS_RELATION_ORIGINATED_PROPOSITIONS = NULL;

Symbol* SYM_PROPOSITIONS_ISA = NULL;

Symbol* SYM_PROPOSITIONS_SURROGATE_VALUE_INVERSE = NULL;

Object* oPROPOSITIONUNDERCONSTRUCTIONo = NULL;

Symbol* SYM_PROPOSITIONS_oPROPOSITIONUNDERCONSTRUCTIONo = NULL;

Cons* oTOPLEVELPROPOSITIONSo = NULL;

Symbol* SYM_PROPOSITIONS_oTOPLEVELPROPOSITIONSo = NULL;

Surrogate* SGT_PROPOSITIONS_STRING_WRAPPER = NULL;

Surrogate* SGT_PROPOSITIONS_LOGIC_EXCEPTION = NULL;

Keyword* KWD_PROPOSITIONS_EXCEPTIONS = NULL;

Surrogate* SGT_PROPOSITIONS_READ_EXCEPTION = NULL;

Symbol* SYM_PROPOSITIONS_CONSTANT = NULL;

Symbol* SYM_PROPOSITIONS_TRUE = NULL;

Symbol* SYM_PROPOSITIONS_FALSE = NULL;

Surrogate* SGT_PROPOSITIONS_SYMBOL = NULL;

Symbol* SYM_PROPOSITIONS_e = NULL;

Symbol* SYM_PROPOSITIONS_AND = NULL;

Symbol* SYM_PROPOSITIONS_OR = NULL;

Symbol* SYM_PROPOSITIONS_NOT = NULL;

Symbol* SYM_PROPOSITIONS_IN = NULL;

Symbol* SYM_PROPOSITIONS_SUBSET_OF = NULL;

Symbol* SYM_PROPOSITIONS_EXISTS = NULL;

Symbol* SYM_PROPOSITIONS_FORALL = NULL;

Keyword* KWD_PROPOSITIONS_EXISTS = NULL;

Symbol* SYM_PROPOSITIONS_EQUIVALENT = NULL;

Surrogate* SGT_PROPOSITIONS_FUNCTION = NULL;

Symbol* SYM_PROPOSITIONS_SECOND_ORDER = NULL;

Surrogate* SGT_PROPOSITIONS_ANY = NULL;

Surrogate* SGT_PROPOSITIONS_BOOLEAN = NULL;

Surrogate* SGT_PROPOSITIONS_BOOLEAN_WRAPPER = NULL;

Keyword* KWD_PROPOSITIONS_FORALL = NULL;

Symbol* SYM_PROPOSITIONS_ALWAYS = NULL;

Symbol* SYM_PROPOSITIONS_WHERE = NULL;

Symbol* SYM_PROPOSITIONS_SOME = NULL;

Symbol* SYM_PROPOSITIONS_DELETED_OBJECTp = NULL;

Keyword* KWD_PROPOSITIONS_DELETED = NULL;

Symbol* SYM_PROPOSITIONS_DEFINITION = NULL;

Symbol* SYM_PROPOSITIONS_CLEAR_LOGIC_MODULE_HOOK = NULL;

Symbol* SYM_PROPOSITIONS_TOTALp = NULL;

Symbol* SYM_PROPOSITIONS_INDEX_ON_VALUESp = NULL;

Logic_Object* new_logic_object() {
  { Logic_Object* self = NULL;

    self = new Logic_Object;
    self->home_context = oMODULEo;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->variable_value_inverse = NULL;
    self->variable_value = NULL;
    self->dependent_propositions = new_list();
    self->dependent_attribute_propositions = new_list();
    self->root_type = NULL;
    return (self);
  }
}

List* Logic_Object::all_root_types_reader() {
  { Logic_Object* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_PROPOSITIONS_ALL_ROOT_TYPES, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

Cons* Logic_Object::variable_value_inverse_reader() {
  { Logic_Object* self = this;

    { Cons* answer = ((Cons*)(access_in_context(self->variable_value_inverse, self, FALSE)));

      if (answer == NULL) {
        return (NIL);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Logic_Object::all_surrogate_value_inverses_reader() {
  { Logic_Object* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_PROPOSITIONS_ALL_SURROGATE_VALUE_INVERSES, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_logic_object_slot_value(Logic_Object* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_PROPOSITIONS_ROOT_TYPE) {
      if (setvalueP) {
        self->root_type = ((Surrogate*)(value));
      }
      else {
        return (self->root_type);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_ALL_ROOT_TYPES) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_ALL_ROOT_TYPES, ((List*)(value)), NULL);
      }
      else {
        return (self->all_root_types_reader());
      }
    }
    else if (slotname == SYM_PROPOSITIONS_DEPENDENT_ATTRIBUTE_PROPOSITIONS) {
      if (setvalueP) {
        self->dependent_attribute_propositions = ((List*)(value));
      }
      else {
        return (self->dependent_attribute_propositions);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_DEPENDENT_PROPOSITIONS) {
      if (setvalueP) {
        self->dependent_propositions = ((List*)(value));
      }
      else {
        return (self->dependent_propositions);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_VARIABLE_VALUE) {
      if (setvalueP) {
        { Logic_Object* object_001 = self;
          Object* value_001 = value;
          Object* old_value_001 = object_001->variable_value;
          Object* new_value_001 = update_in_context(old_value_001, value_001, object_001, FALSE);

          if (!cs_valueP(old_value_001)) {
            object_001->variable_value = new_value_001;
          }
        }
      }
      else {
        return (((Object*)(access_in_context(self->variable_value, self, FALSE))));
      }
    }
    else if (slotname == SYM_PROPOSITIONS_VARIABLE_VALUE_INVERSE) {
      if (setvalueP) {
        { Logic_Object* object_002 = self;
          Cons* value_002 = ((Cons*)(value));
          Object* old_value_003 = object_002->variable_value_inverse;
          Object* new_value_002 = update_in_context(old_value_003, value_002, object_002, FALSE);

          if (!cs_valueP(old_value_003)) {
            object_002->variable_value_inverse = new_value_002;
          }
        }
      }
      else {
        return (self->variable_value_inverse_reader());
      }
    }
    else if (slotname == SYM_PROPOSITIONS_ALL_SURROGATE_VALUE_INVERSES) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_ALL_SURROGATE_VALUE_INVERSES, ((List*)(value)), NULL);
      }
      else {
        return (self->all_surrogate_value_inverses_reader());
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Logic_Object::primary_type() {
  { Logic_Object* self = this;

    return (SGT_PROPOSITIONS_LOGIC_OBJECT);
  }
}

void Logic_Object::print_object(ostream* stream) {
  { Logic_Object* self = this;

    print_top_level_object(self, stream);
  }
}

Skolem* new_skolem() {
  { Skolem* self = NULL;

    self = new Skolem;
    self->home_context = oMODULEo;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->variable_value_inverse = NULL;
    self->variable_value = NULL;
    self->dependent_propositions = new_list();
    self->dependent_attribute_propositions = new_list();
    self->defining_proposition = NULL;
    self->not_bottomP = wrap_boolean(FALSE);
    self->root_type = NULL;
    return (self);
  }
}

Object* access_skolem_slot_value(Skolem* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_PROPOSITIONS_SKOLEM_TYPE) {
      if (setvalueP) {
        self->root_type = ((Surrogate*)(value));
      }
      else {
        return (self->root_type);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_NOT_BOTTOMp) {
      if (setvalueP) {
        { Skolem* object_001 = self;
          boolean value_001 = ((Boolean_Wrapper*)(value))->wrapper_value;
          Object* old_value_001 = object_001->not_bottomP;
          Object* new_value_001 = update_in_context(old_value_001, wrap_boolean(value_001), object_001, FALSE);

          if (!cs_valueP(old_value_001)) {
            object_001->not_bottomP = new_value_001;
          }
        }
      }
      else {
        return (wrap_boolean(((Boolean_Wrapper*)(access_in_context(self->not_bottomP, self, FALSE)))->wrapper_value));
      }
    }
    else if (slotname == SYM_PROPOSITIONS_DEFINING_PROPOSITION) {
      if (setvalueP) {
        self->defining_proposition = ((Proposition*)(value));
      }
      else {
        return (self->defining_proposition);
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Skolem::primary_type() {
  { Skolem* self = this;

    return (SGT_PROPOSITIONS_SKOLEM);
  }
}

Pattern_Variable* new_pattern_variable() {
  { Pattern_Variable* self = NULL;

    self = new Pattern_Variable;
    self->home_context = oMODULEo;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->variable_value_inverse = NULL;
    self->variable_value = NULL;
    self->dependent_propositions = new_list();
    self->dependent_attribute_propositions = new_list();
    self->defining_proposition = NULL;
    self->not_bottomP = wrap_boolean(FALSE);
    self->root_type = NULL;
    self->bound_to_offset = NULL_INTEGER;
    return (self);
  }
}

Object* access_pattern_variable_slot_value(Pattern_Variable* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_PROPOSITIONS_BOUND_TO_OFFSET) {
      if (setvalueP) {
        self->bound_to_offset = ((Integer_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (integer_wrap_literal(self->bound_to_offset));
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Pattern_Variable::primary_type() {
  { Pattern_Variable* self = this;

    return (SGT_PROPOSITIONS_PATTERN_VARIABLE);
  }
}

Object* Pattern_Variable::binding_to_constant() {
  { Pattern_Variable* self = this;

    return ((native_valueP(((Object*)(access_in_context(self->variable_value, self, FALSE)))) ? ((Object*)(((Object*)(access_in_context(self->variable_value, self, FALSE))))) : ((Object*)(NULL))));
  }
}

Description* new_description() {
  { Description* self = NULL;

    self = new Description;
    self->home_context = oMODULEo;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->variable_value_inverse = NULL;
    self->variable_value = NULL;
    self->dependent_propositions = new_list();
    self->dependent_attribute_propositions = new_list();
    self->root_type = NULL;
    self->taxonomy_node = NULL;
    self->referenced_by = new_list();
    self->query_patterns = NULL;
    self->native_relation = NULL;
    self->kind = NULL;
    self->internal_variables = ZERO_VARIABLES_VECTOR;
    self->io_variables = NULL;
    self->proposition = NULL;
    return (self);
  }
}

List* Description::extension_reader() {
  { Description* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_PROPOSITIONS_EXTENSION, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Description::iotaP_reader() {
  { Description* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_IOTAp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_description_slot_value(Description* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_PROPOSITIONS_PROPOSITION) {
      if (setvalueP) {
        self->proposition = ((Proposition*)(value));
      }
      else {
        return (self->proposition);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_IO_VARIABLES) {
      if (setvalueP) {
        self->io_variables = ((Vector*)(value));
      }
      else {
        return (self->io_variables);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_INTERNAL_VARIABLES) {
      if (setvalueP) {
        self->internal_variables = ((Vector*)(value));
      }
      else {
        return (self->internal_variables);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_KIND) {
      if (setvalueP) {
        self->kind = ((Keyword*)(value));
      }
      else {
        return (self->kind);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_NATIVE_RELATION) {
      if (setvalueP) {
        self->native_relation = ((Relation*)(value));
      }
      else {
        return (self->native_relation);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_EXTENSION) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_EXTENSION, ((List*)(value)), NULL);
      }
      else {
        return (self->extension_reader());
      }
    }
    else if (slotname == SYM_PROPOSITIONS_QUERY_PATTERNS) {
      if (setvalueP) {
        self->query_patterns = ((Key_Value_List*)(value));
      }
      else {
        return (self->query_patterns);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_REFERENCED_BY) {
      if (setvalueP) {
        self->referenced_by = ((List*)(value));
      }
      else {
        return (self->referenced_by);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_TAXONOMY_NODE) {
      if (setvalueP) {
        self->taxonomy_node = ((Taxonomy_Node*)(value));
      }
      else {
        return (self->taxonomy_node);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_IOTAp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_IOTAp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->iotaP_reader()));
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Description::primary_type() {
  { Description* self = this;

    return (SGT_PROPOSITIONS_DESCRIPTION);
  }
}

int Description::arity() {
  { Description* self = this;

    return (self->io_variables->length());
  }
}

Pattern_Variable* Description::representative() {
  { Description* self = this;

    return (((Pattern_Variable*)(self->io_variables->first())));
  }
}

boolean Description::relationP() {
  { Description* self = this;

    return ((self->native_relation != NULL) &&
        (isaP(self->native_relation, SGT_PROPOSITIONS_SLOT) &&
         get_quoted_tree("((/STELLA/@BOOLEAN /STELLA/@BOOLEAN-WRAPPER) \"/LOGIC\")", "/LOGIC")->memberP(((Slot*)(self->native_relation))->slot_base_type)));
  }
}

boolean Description::functionP() {
  { Description* self = this;

    return ((self->native_relation != NULL) &&
        (isaP(self->native_relation, SGT_PROPOSITIONS_SLOT) &&
         (!get_quoted_tree("((/STELLA/@BOOLEAN /STELLA/@BOOLEAN-WRAPPER) \"/LOGIC\")", "/LOGIC")->memberP(((Slot*)(self->native_relation))->slot_base_type))));
  }
}

Surrogate* Description::description_surrogate() {
  { Description* self = this;

    { Relation* nativerelation = self->native_relation;

      if (nativerelation != NULL) {
        { Relation* nativerelation_001 = nativerelation;

          if (classP(nativerelation)) {
            { Class* nativerelation = NULL;

              nativerelation = ((Class*)(nativerelation_001));
              return (nativerelation->class_type);
            }
          }
          else if (taxonomy_isaP(nativerelation, SGT_PROPOSITIONS_SLOT)) {
            { Slot* nativerelation = NULL;

              nativerelation = ((Slot*)(nativerelation_001));
              return (nativerelation->slot_slotref);
            }
          }
          else {
          }
        }
      }
      return (NULL);
    }
  }
}

Truth_Value* new_truth_value() {
  { Truth_Value* self = NULL;

    self = new Truth_Value;
    self->home_context = oMODULEo;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->variable_value_inverse = NULL;
    self->variable_value = NULL;
    self->dependent_propositions = new_list();
    self->dependent_attribute_propositions = new_list();
    self->root_type = NULL;
    self->time_stamp = NULL_INTEGER;
    self->negative_set_of_support = NULL;
    self->positive_set_of_support = NULL;
    self->negative_score = 0.0;
    self->positive_score = 0.0;
    return (self);
  }
}

Object* access_truth_value_slot_value(Truth_Value* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_PROPOSITIONS_POSITIVE_SCORE) {
      if (setvalueP) {
        self->positive_score = ((Float_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (float_wrap_literal(self->positive_score));
      }
    }
    else if (slotname == SYM_PROPOSITIONS_NEGATIVE_SCORE) {
      if (setvalueP) {
        self->negative_score = ((Float_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (float_wrap_literal(self->negative_score));
      }
    }
    else if (slotname == SYM_PROPOSITIONS_POSITIVE_SET_OF_SUPPORT) {
      if (setvalueP) {
        self->positive_set_of_support = ((List*)(value));
      }
      else {
        return (self->positive_set_of_support);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_NEGATIVE_SET_OF_SUPPORT) {
      if (setvalueP) {
        self->negative_set_of_support = ((List*)(value));
      }
      else {
        return (self->negative_set_of_support);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_TIME_STAMP) {
      if (setvalueP) {
        self->time_stamp = ((Integer_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (integer_wrap_literal(self->time_stamp));
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Truth_Value::primary_type() {
  { Truth_Value* self = this;

    return (SGT_PROPOSITIONS_TRUTH_VALUE);
  }
}

Proposition* new_proposition() {
  { Proposition* self = NULL;

    self = new Proposition;
    self->home_context = oMODULEo;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->dependent_propositions = new_list();
    self->renamed_Operator = NULL;
    self->arguments = NULL;
    self->truth_value = NULL;
    self->kind = NULL;
    return (self);
  }
}

boolean Proposition::variable_typeP_reader() {
  { Proposition* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_VARIABLE_TYPEp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Proposition::subrelation_linkP_reader() {
  { Proposition* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_SUBRELATION_LINKp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Proposition::subsumption_linkP_reader() {
  { Proposition* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_SUBSUMPTION_LINKp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Proposition::satellite_propositions_reader() {
  { Proposition* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_PROPOSITIONS_SATELLITE_PROPOSITIONS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Proposition::dont_optimizeP_reader() {
  { Proposition* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_DONT_OPTIMIZEp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Proposition::forward_onlyP_reader() {
  { Proposition* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_FORWARD_ONLYp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Proposition::backward_onlyP_reader() {
  { Proposition* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_BACKWARD_ONLYp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_proposition_slot_value(Proposition* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_PROPOSITIONS_KIND) {
      if (setvalueP) {
        self->kind = ((Keyword*)(value));
      }
      else {
        return (self->kind);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_TRUTH_VALUE) {
      if (setvalueP) {
        { Proposition* object_001 = self;
          Truth_Value* value_001 = ((Truth_Value*)(value));
          Object* old_value_001 = object_001->truth_value;
          Object* new_value_001 = update_in_context(old_value_001, value_001, object_001, FALSE);

          if (!cs_valueP(old_value_001)) {
            object_001->truth_value = new_value_001;
          }
        }
      }
      else {
        return (((Truth_Value*)(access_in_context(self->truth_value, self, FALSE))));
      }
    }
    else if (slotname == SYM_PROPOSITIONS_ARGUMENTS) {
      if (setvalueP) {
        self->arguments = ((Vector*)(value));
      }
      else {
        return (self->arguments);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_OPERATOR) {
      if (setvalueP) {
        self->renamed_Operator = value;
      }
      else {
        return (self->renamed_Operator);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_SLOTREF) {
      if (setvalueP) {
        self->renamed_Operator = ((Surrogate*)(value));
      }
      else {
        return (((Surrogate*)(self->renamed_Operator)));
      }
    }
    else if (slotname == SYM_PROPOSITIONS_DEPENDENT_PROPOSITIONS) {
      if (setvalueP) {
        self->dependent_propositions = ((List*)(value));
      }
      else {
        return (self->dependent_propositions);
      }
    }
    else if (slotname == SYM_PROPOSITIONS_VARIABLE_TYPEp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_VARIABLE_TYPEp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->variable_typeP_reader()));
      }
    }
    else if (slotname == SYM_PROPOSITIONS_SUBRELATION_LINKp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_SUBRELATION_LINKp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->subrelation_linkP_reader()));
      }
    }
    else if (slotname == SYM_PROPOSITIONS_SUBSUMPTION_LINKp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_SUBSUMPTION_LINKp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->subsumption_linkP_reader()));
      }
    }
    else if (slotname == SYM_PROPOSITIONS_SATELLITE_PROPOSITIONS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_SATELLITE_PROPOSITIONS, ((List*)(value)), NULL);
      }
      else {
        return (self->satellite_propositions_reader());
      }
    }
    else if (slotname == SYM_PROPOSITIONS_DONT_OPTIMIZEp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_DONT_OPTIMIZEp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->dont_optimizeP_reader()));
      }
    }
    else if (slotname == SYM_PROPOSITIONS_FORWARD_ONLYp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_FORWARD_ONLYp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->forward_onlyP_reader()));
      }
    }
    else if (slotname == SYM_PROPOSITIONS_BACKWARD_ONLYp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_BACKWARD_ONLYp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->backward_onlyP_reader()));
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Proposition::primary_type() {
  { Proposition* self = this;

    return (SGT_PROPOSITIONS_PROPOSITION);
  }
}

void Proposition::print_object(ostream* stream) {
  { Proposition* self = this;

    print_top_level_object(self, stream);
  }
}

Proposition* create_proposition(Symbol* kind, int argumentcount) {
  { Proposition* proposition = new_proposition();

    proposition->arguments = new_vector(argumentcount);
    proposition->kind = intern_keyword(kind->symbol_name);
    if ((kind == SYM_PROPOSITIONS_FUNCTION) ||
        (kind == SYM_PROPOSITIONS_PREDICATE)) {
    }
    else {
      proposition->renamed_Operator = intern_surrogate(kind->symbol_name);
    }
    return (proposition);
  }
}

List* Context::context_assumed_propositions_reader() {
  { Context* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_PROPOSITIONS_CONTEXT_ASSUMED_PROPOSITIONS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean World::monotonicP_reader() {
  { World* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_MONOTONICp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean World::truth_maintainedP_reader() {
  { World* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_TRUTH_MAINTAINEDp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean World::up_to_date_inferencesP_reader() {
  { World* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_UP_TO_DATE_INFERENCESp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Module::locally_conceived_propositions_getter() {
  { Module* self = this;

    { List* propositions = ((List*)(dynamic_slot_value(self, SYM_PROPOSITIONS_LOCALLY_CONCEIVED_PROPOSITIONS, NULL)));

      if (propositions == NULL) {
        propositions = list(0);
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_LOCALLY_CONCEIVED_PROPOSITIONS, propositions, NULL);
      }
      return (propositions);
    }
  }
}

List* World::locally_bound_propositions_getter() {
  { World* self = this;

    { List* propositions = ((List*)(dynamic_slot_value(self, SYM_PROPOSITIONS_LOCALLY_BOUND_PROPOSITIONS, NULL)));

      if (propositions == NULL) {
        propositions = list(0);
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_LOCALLY_BOUND_PROPOSITIONS, propositions, NULL);
      }
      return (propositions);
    }
  }
}

List* World::locally_bound_skolems_getter() {
  { World* self = this;

    { List* propositions = ((List*)(dynamic_slot_value(self, SYM_PROPOSITIONS_LOCALLY_BOUND_SKOLEMS, NULL)));

      if (propositions == NULL) {
        propositions = list(0);
        set_dynamic_slot_value(self, SYM_PROPOSITIONS_LOCALLY_BOUND_SKOLEMS, propositions, NULL);
      }
      return (propositions);
    }
  }
}

void increment_now_time_stamp() {
  oNOW_TIME_STAMPo = oNOW_TIME_STAMPo + 1;
}

int get_now_time_stamp() {
  return (oNOW_TIME_STAMPo);
}

void update_now_time_stamp(Keyword* kbaction) {
  if (kbaction == oLAST_KB_ACTIONo) {
    return;
  }
  if (kbaction == KWD_PROPOSITIONS_UPDATE_PROPOSITION) {
    increment_now_time_stamp();
  }
  else if (kbaction == KWD_PROPOSITIONS_EXECUTE_QUERY) {
  }
  else {
    cerr << "`" << kbaction << "'" << " is not a valid case option";
  }
  oLAST_KB_ACTIONo = kbaction;
}

boolean bottomP(Object* self) {
  // Return TRUE if 'self' is the undefined individual BOTTOM.
  return (self == BOTTOM);
}

boolean Logic_Object::monadicP() {
  { Logic_Object* self = this;

    return (FALSE);
  }
}

boolean Collection::monadicP() {
  { Collection* self = this;

    return (TRUE);
  }
}

boolean Description::monadicP() {
  { Description* self = this;

    return (self->arity() == 1);
  }
}

boolean logic_slotP(Slot* slot) {
  return (slot->abstractP);
}

boolean type_has_backlinksP(Surrogate* type) {
  return ((!subtype_ofP(type, SGT_PROPOSITIONS_LITERAL_WRAPPER)) &&
      (!subtype_ofP(type, SGT_PROPOSITIONS_LITERAL)));
}

boolean no_backlinksP(Object* self) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        return (!type_has_backlinksP(logical_type(self)));
      }
    }
    else {
      return (TRUE);
    }
  }
}

boolean logic_object_permits_backlinksP(Logic_Object* object) {
  { Logic_Object* object_001 = object;

    if (taxonomy_isaP(object, SGT_PROPOSITIONS_SKOLEM)) {
      { Skolem* object = NULL;

        object = ((Skolem*)(object_001));
        return (TRUE);
      }
    }
    else {
      return (type_has_backlinksP(logical_type(object)));
    }
  }
}

boolean Slot::closedP() {
  // Return TRUE if the closed world assumption applies to
  // a function or relation.
  { Slot* self = this;

    return ((oMODULEo->closed_world_assumptionP() ? ((boolean)(!(self->closure_assumption() == KWD_PROPOSITIONS_OPEN_WORLD))) : ((boolean)(self->closure_assumption() == KWD_PROPOSITIONS_CLOSED_WORLD))));
  }
}

boolean Slot::open_worldP() {
  // Return TRUE if the closed world assumption does not
  // apply to a function or relation.
  { Slot* self = this;

    return (!self->closedP());
  }
}

Keyword* read_OevaluationmodeO() {
  return (oEVALUATIONMODEo);
}

Keyword* write_OevaluationmodeO(Keyword* value) {
  oEVALUATIONMODEo = value;
  return (value);
}

boolean description_modeP() {
  return ((oEVALUATIONMODEo == KWD_PROPOSITIONS_DESCRIPTION) ||
      (oEVALUATIONMODEo == KWD_PROPOSITIONS_QUERY));
}

boolean conceiving_updateP(Keyword* updatemode) {
  return ((updatemode == NULL) ||
      (updatemode == KWD_PROPOSITIONS_CONCEIVE));
}

boolean descriptive_updateP(Keyword* updatemode) {
  return (conceiving_updateP(updatemode) ||
      description_modeP());
}

boolean propagate_constraints_incrementallyP(World* self) {
  return (self->monotonicP_reader() ||
      self->truth_maintainedP_reader());
}

boolean context_dependent_search_modeP() {
  return (oCONTEXT_DEPENDENT_SEARCH_MODEpo);
}

void log_newly_conceived_proposition(Module* self, Proposition* proposition) {
  self->locally_conceived_propositions_getter()->insert(proposition);
}

void Context::log_newly_bound_proposition(Proposition* proposition) {
  { Context* self = this;

    proposition = proposition;
  }
}

void World::log_newly_bound_proposition(Proposition* proposition) {
  { World* self = this;

    self->locally_bound_propositions_getter()->insert(proposition);
  }
}

void run_goes_true_demons(Proposition* proposition) {
  { Keyword* test_value_001 = proposition->kind;

    if (test_value_001 == KWD_PROPOSITIONS_IMPLIES) {
      if (!description_modeP()) {
        add_taxonomy_implies_subsumes_link(((Description*)(proposition->arguments->nth(0))), ((Description*)(proposition->arguments->nth(1))));
      }
      { Proposition* p = NULL;
        Cons* iter_001 = proposition->satellite_propositions_reader()->the_cons_list;

        while (!nilP(iter_001)) {
          {
            p = ((Proposition*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          assign_truth_value(p, TRUE);
        }
      }
    }
    else {
    }
  }
  return;
}

void run_goes_false_demons(Proposition* proposition) {
  proposition = proposition;
  return;
}

void run_goes_unknown_demons(Proposition* proposition) {
  { Keyword* test_value_001 = proposition->kind;

    if (test_value_001 == KWD_PROPOSITIONS_IMPLIES) {
      drop_taxonomy_implies_subsumes_link(((Description*)(proposition->arguments->nth(0))), ((Description*)(proposition->arguments->nth(1))));
      { Proposition* p = NULL;
        Cons* iter_001 = proposition->satellite_propositions_reader()->the_cons_list;

        while (!nilP(iter_001)) {
          {
            p = ((Proposition*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          deassign_truth_value(p, KWD_PROPOSITIONS_RETRACT_TRUE);
        }
      }
      { Proposition* p = ((Proposition*)(dynamic_slot_value(proposition, SYM_PROPOSITIONS_MASTER_PROPOSITION, NULL)));

        if (p != NULL) {
          deassign_truth_value(p, KWD_PROPOSITIONS_RETRACT_TRUE);
        }
      }
    }
    else {
    }
  }
  return;
}

void react_to_proposition_update(Proposition* proposition, Keyword* updatemode) {
  if (proposition == NULL) {
    return;
  }
  if (!description_modeP()) {
    update_now_time_stamp(KWD_PROPOSITIONS_UPDATE_PROPOSITION);
  }
  if (updatemode == KWD_PROPOSITIONS_ASSERT_TRUE) {
    if (!description_modeP()) {
      oCONTEXTo->log_newly_bound_proposition(proposition);
    }
    run_goes_true_demons(proposition);
  }
  else if (updatemode == KWD_PROPOSITIONS_ASSERT_FALSE) {
    if (!description_modeP()) {
      oCONTEXTo->log_newly_bound_proposition(proposition);
    }
    run_goes_false_demons(proposition);
  }
  else if (updatemode == KWD_PROPOSITIONS_RETRACT_TRUE) {
    run_goes_unknown_demons(proposition);
  }
  else if (updatemode == KWD_PROPOSITIONS_RETRACT_FALSE) {
    run_goes_unknown_demons(proposition);
  }
  else {
    cerr << "`" << updatemode << "'" << " is not a valid case option";
  }
}

void Object::propagate_kb_constraints(Context* context) {
  { Object* self = this;

    context = context;
  }
}

void Skolem::propagate_kb_constraints(Context* context) {
  { Skolem* self = this;

    { Object* assertedvalue = ((Object*)(access_in_context(self->variable_value, self, FALSE)));

      { Context* old_OcontextO_001 = oCONTEXTo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oCONTEXTo = context;
              { Object* derivedvalue = self->value_of();

                if ((assertedvalue != NULL) &&
                    (!eqlP(assertedvalue, derivedvalue))) {
                  equate_values(assertedvalue->value_of(), derivedvalue);
                }
              }
              oCONTEXTo = old_OcontextO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oCONTEXTo = old_OcontextO_001;
            resignal();
          }
        }
      }
    }
  }
}

void Proposition::propagate_kb_constraints(Context* context) {
  { Proposition* self = this;

    { Truth_Value* parenttruthvalue = ((Truth_Value*)(access_in_context(self->truth_value, self, FALSE)));

      { Context* old_OcontextO_001 = oCONTEXTo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oCONTEXTo = context;
              if ((!(parenttruthvalue == ((Truth_Value*)(access_in_context(self->truth_value, self, FALSE))))) &&
                  (parenttruthvalue != NULL)) {
                signal_truth_value_clash(self);
              }
              evaluate_proposition(self);
              { Proposition* prop = NULL;
                Cons* iter_001 = self->dependent_propositions->the_cons_list;

                while (!nilP(iter_001)) {
                  {
                    prop = ((Proposition*)(iter_001->value));
                    iter_001 = iter_001->rest;
                  }
                  evaluate_proposition(prop);
                }
              }
              oCONTEXTo = old_OcontextO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oCONTEXTo = old_OcontextO_001;
            resignal();
          }
        }
      }
    }
  }
}

void Context::react_to_kb_update(Object* object) {
  { Context* self = this;

    object = object;
  }
}

void Module::react_to_kb_update(Object* object) {
  { Module* self = this;

    if (description_modeP()) {
      object->propagate_kb_constraints(oCONTEXTo);
      return;
    }
    { World* cache = ((World*)(dynamic_slot_value(self, SYM_PROPOSITIONS_STRICT_INFERENCE_CACHE, NULL)));

      if (cache != NULL) {
        if (!propagate_constraints_incrementallyP(cache)) {
          cerr << "Safety violation: " << "INTERNAL ERROR: `react-to-kb-update' encountered " << "bad cache state.";
        }
        object->propagate_kb_constraints(cache);
        { Context* child = NULL;
          Cons* iter_001 = self->child_contexts->the_cons_list;

          while (!nilP(iter_001)) {
            {
              child = ((Context*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            if (isaP(child, SGT_PROPOSITIONS_MODULE)) {
              { World* childcache = lookup_inference_cache(((Module*)(child)), KWD_PROPOSITIONS_STRICT);

                if (childcache != NULL) {
                  object->propagate_kb_constraints(childcache);
                }
              }
            }
          }
        }
      }
    }
  }
}

void World::react_to_kb_update(Object* object) {
  { World* self = this;

    if (propagate_constraints_incrementallyP(self)) {
      object->propagate_kb_constraints(self);
    }
  }
}

void assign_truth_value(Proposition* self, boolean valueP) {
  { Truth_Value* oldtruthvalue = ((Truth_Value*)(access_in_context(self->truth_value, self, FALSE)));
    Truth_Value* newtruthvalue = (valueP ? ((Truth_Value*)(TRUE_TRUTH_VALUE)) : ((Truth_Value*)(FALSE_TRUTH_VALUE)));

    if (oldtruthvalue == newtruthvalue) {
    }
    else if (oldtruthvalue != NULL) {
      signal_truth_value_clash(self);
    }
    else if (self->kind == KWD_PROPOSITIONS_FUNCTION) {
      { Proposition* object_001 = self;
        Truth_Value* value_001 = TRUE_TRUTH_VALUE;
        Object* old_value_002 = object_001->truth_value;
        Object* new_value_001 = update_in_context(old_value_002, value_001, object_001, FALSE);

        if (!cs_valueP(old_value_002)) {
          object_001->truth_value = new_value_001;
        }
      }
    }
    else if (description_modeP() &&
        (self->kind == KWD_PROPOSITIONS_CONSTANT)) {
    }
    else {
      { Proposition* object_002 = self;
        Truth_Value* value_002 = newtruthvalue;
        Object* old_value_003 = object_002->truth_value;
        Object* new_value_002 = update_in_context(old_value_003, value_002, object_002, FALSE);

        if (!cs_valueP(old_value_003)) {
          object_002->truth_value = new_value_002;
        }
      }
      react_to_proposition_update(self, (valueP ? ((Keyword*)(KWD_PROPOSITIONS_ASSERT_TRUE)) : ((Keyword*)(KWD_PROPOSITIONS_ASSERT_FALSE))));
      oCONTEXTo->react_to_kb_update(self);
    }
  }
}

void deassign_truth_value(Proposition* self, Keyword* updatemode) {
  { Proposition* object_001 = self;
    Truth_Value* value_001 = NULL;
    Object* old_value_001 = object_001->truth_value;
    Object* new_value_001 = update_in_context(old_value_001, value_001, object_001, FALSE);

    if (!cs_valueP(old_value_001)) {
      object_001->truth_value = new_value_001;
    }
  }
  check_for_out_of_date_inference_cache();
  react_to_proposition_update(self, updatemode);
}

void update_proposition_truth_value(Proposition* self, Keyword* updatemode) {
  { Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oCONTEXTo = get_top_level_update_context();
          if (updatemode == KWD_PROPOSITIONS_ASSERT_TRUE) {
            assign_truth_value(self, TRUE);
          }
          else if (updatemode == KWD_PROPOSITIONS_ASSERT_FALSE) {
            assign_truth_value(self, FALSE);
          }
          else if (updatemode == KWD_PROPOSITIONS_RETRACT_TRUE) {
            if (trueP(self) &&
                (!(self->kind == KWD_PROPOSITIONS_FUNCTION))) {
              deassign_truth_value(self, updatemode);
            }
          }
          else if (updatemode == KWD_PROPOSITIONS_RETRACT_FALSE) {
            if (falseP(self)) {
              deassign_truth_value(self, updatemode);
            }
          }
          else if (updatemode == KWD_PROPOSITIONS_CONCEIVE) {
          }
          else {
            cerr << "`" << updatemode << "'" << " is not a valid case option";
          }
          oCONTEXTo = old_OcontextO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oCONTEXTo = old_OcontextO_001;
        resignal();
      }
    }
  }
}

void run_slot_inference_demons(Object* self, Storage_Slot* slot, Object* oldvalue, Object* newvalue) {
  {
    self = self;
    slot = slot;
    oldvalue = oldvalue;
    newvalue = newvalue;
  }
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
      }
    }
    else {
    }
  }
}

void react_to_attribute_proposition_update(Skolem* skolem, Object* oldvalue, Object* newvalue, boolean toplevelupdateP) {
  { Proposition* proposition = skolem->defining_proposition;
    Vector* arguments = proposition->arguments;
    Slot* slot = ((Slot*)(((Surrogate*)(proposition->renamed_Operator))->surrogate_value));
    Object* firstarg = arguments->nth(0);
    Object* nativefirstargvalue = native_value_of(firstarg);

    if (toplevelupdateP &&
        ((nativefirstargvalue != NULL) &&
         attribute_propositionP(proposition))) {
      if (newvalue != NULL) {
        assign_attribute_value(((Standard_Object*)(nativefirstargvalue)), ((Storage_Slot*)(slot)), newvalue);
      }
      else {
        drop_attribute_value(((Standard_Object*)(nativefirstargvalue)), ((Storage_Slot*)(slot)), oldvalue);
      }
    }
  }
}

boolean primitive_slotP(Slot* slot) {
  return ((((Description*)(dynamic_slot_value(slot, SYM_PROPOSITIONS_DESCRIPTION, NULL))) == NULL) ||
      (((Description*)(dynamic_slot_value(slot, SYM_PROPOSITIONS_DESCRIPTION, NULL)))->kind == KWD_PROPOSITIONS_PRIMITIVE));
}

boolean attribute_propositionP(Proposition* proposition) {
  { Slot* slot = ((Slot*)(((Surrogate*)(proposition->renamed_Operator))->surrogate_value));

    return ((slot != NULL) &&
        (isaP(slot, SGT_PROPOSITIONS_STORAGE_SLOT) &&
         primitive_slotP(slot)));
  }
}

void add_dependent_proposition_link(Object* self, Proposition* proposition) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PROPOSITIONS_PROPOSITION)) {
      { Proposition* self = NULL;

        self = ((Proposition*)(self_001));
        if (!(self->kind == KWD_PROPOSITIONS_CONSTANT)) {
          self->dependent_propositions->insert_new(proposition);
        }
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_DESCRIPTION)) {
      { Description* self = NULL;

        self = ((Description*)(self_001));
        if ((!description_modeP()) ||
            ((self->native_relation == NULL) &&
             (((Description*)(dynamic_slot_value(self, SYM_PROPOSITIONS_COMPLEMENT_DESCRIPTION, NULL))) == NULL))) {
          if ((self == proposition->arguments->nth(0)) &&
              attribute_propositionP(proposition)) {
            add_dependent_attribute_link(self, proposition);
          }
          else {
            self->dependent_propositions->insert_new(proposition);
          }
        }
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        if (logic_object_permits_backlinksP(self)) {
          if (!(isaP(self, SGT_PROPOSITIONS_PATTERN_VARIABLE) ||
              (!description_modeP()))) {
            cerr << "Safety violation: " << "INTERNAL ERROR: A LOGIC-OBJECT or SKOLEM should never be " << "a proposition argument within a description.";
          }
          if ((self == proposition->arguments->nth(0)) &&
              attribute_propositionP(proposition)) {
            add_dependent_attribute_link(self, proposition);
          }
          else {
            { List* collection = self->dependent_propositions;

              if (!(collection->memberP(proposition))) {
                collection->insert(proposition);
              }
            }
          }
        }
      }
    }
    else {
    }
  }
}

void remove_dependent_proposition_link(Object* self, Proposition* proposition) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PROPOSITIONS_PROPOSITION)) {
      { Proposition* self = NULL;

        self = ((Proposition*)(self_001));
        self->dependent_propositions->remove(proposition);
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        if ((self == proposition->arguments->nth(0)) &&
            attribute_propositionP(proposition)) {
          remove_dependent_attribute_link(self, proposition);
        }
        else {
          self->dependent_propositions->remove(proposition);
        }
      }
    }
    else {
    }
  }
}

boolean slotref_less_or_equalP(Surrogate* slot1, Surrogate* slot2) {
  return (slot1->symbol_id <= slot2->symbol_id);
}

boolean slotref_less_thanP(Surrogate* slot1, Surrogate* slot2) {
  return (slot1->symbol_id < slot2->symbol_id);
}

void insert_sorted_by_slotref(List* self, Proposition* proposition) {
  { Cons* cursor = self->the_cons_list;
    Cons* trailer = NULL;
    Surrogate* key = ((Surrogate*)(proposition->renamed_Operator));
    Surrogate* slotref = NULL;

    if (cursor->emptyP()) {
      self->the_cons_list = cons_list(1, proposition);
      return;
    }
    while (cursor->non_emptyP()) {
      slotref = ((Surrogate*)(((Proposition*)(cursor->value))->renamed_Operator));
      if (slotref_less_or_equalP(key, slotref)) {
        if (key == slotref) {
          cursor->value = proposition;
          return;
        }
        if (trailer == NULL) {
          self->the_cons_list = cons(proposition, cursor);
        }
        else {
          trailer->rest = cons(proposition, cursor);
        }
        return;
      }
      trailer = cursor;
      cursor = cursor->rest;
    }
    trailer->rest = cons_list(1, proposition);
  }
}

void add_dependent_attribute_link(Logic_Object* object, Proposition* proposition) {
  insert_sorted_by_slotref(object->dependent_attribute_propositions, proposition);
}

void remove_dependent_attribute_link(Logic_Object* object, Proposition* proposition) {
  object->dependent_attribute_propositions->remove(proposition);
}

void signal_undefined_slot_value_failure(Object* object, Surrogate* slotref) {
  signal_fail();
  { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRINTREADABLYpo = TRUE;
          cout << "Error in logical expression." << endl;
          cout << "   " << "Null value for slot " << slotref << " applied to " << object << endl;
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

void assign_attribute_value(Standard_Object* self, Storage_Slot* slot, Object* value) {
  if (skolemP(value)) {
    return;
  }
  { Object* oldvalue = read_slot_value(self, slot);

    if (eqlP(oldvalue, value)) {
      return;
    }
    if (oldvalue != NULL) {
      signal_unification_clash(oldvalue, value);
    }
    put_slot_value(self, slot, value);
  }
}

void clear_attribute_value(Standard_Object* object, Storage_Slot* slot) {
  put_slot_value(object, slot, NULL);
}

void drop_attribute_value(Standard_Object* self, Storage_Slot* slot, Object* value) {
  { Object* oldvalue = read_slot_value(self, slot);

    if (eqlP(value, oldvalue)) {
      clear_attribute_value(self, slot);
    }
  }
}

Surrogate* lookup_slotref_on_instance(Object* term, Symbol* slotname) {
  { Surrogate* termtype = NULL;

    termtype = logical_type(term);
    if (termtype == NULL) {
      signal_undefined_term(term);
      return (NULL);
    }
    if (((Class*)(termtype->surrogate_value)) == NULL) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              cout << "Error in logical expression." << endl;
              cout << "   " << "Reference to undefined class named " << termtype->symbol_name << endl;
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
      return (NULL);
    }
    if (subtype_ofP(termtype, SGT_PROPOSITIONS_LITERAL)) {
      termtype = termtype->type_to_wrapped_type();
    }
    { Surrogate* slotref = lookup_slotref(termtype, slotname);

      if (slotref != NULL) {
        return (slotref);
      }
      { Object* term_001 = term;

        if (taxonomy_isaP(term, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
          { Logic_Object* term = NULL;

            term = ((Logic_Object*)(term_001));
            { Proposition* prop = NULL;
              Cons* iter_001 = term->dependent_propositions->the_cons_list;

              while (!nilP(iter_001)) {
                {
                  prop = ((Proposition*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                if ((prop->kind == KWD_PROPOSITIONS_IN) &&
                    typeP(prop->arguments->nth(1))) {
                  slotref = lookup_slotref(((Surrogate*)(prop->arguments->nth(1))), slotname);
                  if (slotref != NULL) {
                    return (slotref);
                  }
                }
              }
            }
          }
        }
        else {
        }
      }
      if (logical_type(term) == SGT_PROPOSITIONS_UNKNOWN) {
        { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                cout << "Error in logical expression." << endl;
                cout << "   " << "Can't find a slot " << slotname << " on the term " << term << " because the " << endl << "   type of " << term << " is unknown." << endl;
                cout << "   Error occured while parsing the proposition: " << endl;
                cout << "   " << oPROPOSITIONUNDERCONSTRUCTIONo << endl;
                signal(oTHE_PROPOSITION_ERRORo);
                oPRINTREADABLYpo = old_OprintreadablyPO_002;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_002;
              resignal();
            }
          }
        }
      }
      else {
        { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                cout << "Error in logical expression." << endl;
                cout << "   " << "Reference to undefined slot " << termtype->symbol_name << "." << slotname << " applied to " << term << endl;
                cout << "   Error occured while parsing the proposition: " << endl;
                cout << "   " << oPROPOSITIONUNDERCONSTRUCTIONo << endl;
                signal(oTHE_PROPOSITION_ERRORo);
                oPRINTREADABLYpo = old_OprintreadablyPO_003;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_003;
              resignal();
            }
          }
        }
      }
    }
  }
}

Object* Slot::apply_slot_to_native_arguments(Vector* arguments) {
  { Slot* slot = this;

    arguments = arguments;
    return (BOTTOM);
  }
}

Object* Storage_Slot::apply_slot_to_native_arguments(Vector* arguments) {
  { Storage_Slot* slot = this;

    if (logic_slotP(slot)) {
      return (BOTTOM);
    }
    { Object* firstarg = native_value_of(arguments->nth(0));

      if (firstarg != NULL) {
        return (read_slot_value(((Standard_Object*)(firstarg)), slot));
      }
      else {
        return (BOTTOM);
      }
    }
  }
}

Object* Method_Slot::apply_slot_to_native_arguments(Vector* arguments) {
  { Method_Slot* slot = this;

    if (logic_slotP(slot)) {
      return (BOTTOM);
    }
    { cpp_method_code code = slot->method_code;

      switch (slot->method_argument_count()) {
        case 1: 
          { Object* firstarg = native_value_of(arguments->nth(0));

            if (firstarg != NULL) {
              return ((firstarg->*((Object* (Object::*) ()) code)) ());
            }
            else {
              return (BOTTOM);
            }
          }
        break;
        case 2: 
          { Object* firstarg = native_value_of(arguments->nth(0));
            Object* secondarg = native_value_of(arguments->nth(1));

            if ((firstarg != NULL) &&
                (secondarg != NULL)) {
              return ((firstarg->*((Object* (Object::*) (Object*)) code)) (secondarg));
            }
            else {
              return (BOTTOM);
            }
          }
        break;
        case 3: 
          { Object* firstarg = native_value_of(arguments->nth(0));
            Object* secondarg = native_value_of(arguments->nth(1));
            Object* thirdarg = native_value_of(arguments->nth(2));

            if ((firstarg != NULL) &&
                ((secondarg != NULL) &&
                 (thirdarg != NULL))) {
              return ((firstarg->*((Object* (Object::*) (Object*, Object*)) code)) (secondarg, thirdarg));
            }
            else {
              return (BOTTOM);
            }
          }
        break;
        case 4: 
          { Object* firstarg = native_value_of(arguments->nth(0));
            Object* secondarg = native_value_of(arguments->nth(1));
            Object* thirdarg = native_value_of(arguments->nth(2));
            Object* fourtharg = native_value_of(arguments->nth(3));

            if ((firstarg != NULL) &&
                ((secondarg != NULL) &&
                 ((thirdarg != NULL) &&
                  (fourtharg != NULL)))) {
              return ((firstarg->*((Object* (Object::*) (Object*, Object*, Object*)) code)) (secondarg, thirdarg, fourtharg));
            }
            else {
              return (BOTTOM);
            }
          }
        break;
        case 5: 
          { Object* firstarg = native_value_of(arguments->nth(0));
            Object* secondarg = native_value_of(arguments->nth(1));
            Object* thirdarg = native_value_of(arguments->nth(2));
            Object* fourtharg = native_value_of(arguments->nth(3));
            Object* fiftharg = native_value_of(arguments->nth(4));

            if ((firstarg != NULL) &&
                ((secondarg != NULL) &&
                 ((thirdarg != NULL) &&
                  ((fourtharg != NULL) &&
                   (fiftharg != NULL))))) {
              return ((firstarg->*((Object* (Object::*) (Object*, Object*, Object*, Object*)) code)) (secondarg, thirdarg, fourtharg, fiftharg));
            }
            else {
              return (BOTTOM);
            }
          }
        break;
        default:
          cerr << "Too many arguments in predication.  Max 5.  Slot is " << "`" << slot << "'";
          return (BOTTOM);
      }
    }
  }
}

boolean unboundP(Skolem* skolem) {
  return (((Object*)(access_in_context(skolem->variable_value, skolem, FALSE))) == NULL);
}

Object* Object::value_of() {
  { Object* self = this;

    return (self);
  }
}

Object* Surrogate::value_of() {
  { Surrogate* self = this;

    { Object* value = self->surrogate_value;

      if (value != NULL) {
        return (value->value_of());
      }
      else {
        {
          cerr << "Unbound surrogate: " << "`" << self->symbol_name << "'" << endl;
          return (NULL);
        }
      }
    }
  }
}

Object* Skolem::value_of() {
  { Skolem* self = this;

    if (((Object*)(access_in_context(self->variable_value, self, FALSE))) == NULL) {
      return (self);
    }
    else {
      return (((Object*)(access_in_context(self->variable_value, self, FALSE)))->value_of());
    }
  }
}

Object* Relation::value_of() {
  { Relation* self = this;

    { Description* description = ((Description*)(dynamic_slot_value(self, SYM_PROPOSITIONS_DESCRIPTION, NULL)));

      if (description != NULL) {
        return (description);
      }
      { Relation* self_001 = self;

        if (taxonomy_isaP(self, SGT_PROPOSITIONS_RELATION)) {
          { Relation* self = NULL;

            self = ((Relation*)(self_001));
            description = self->get_description();
          }
        }
        else {
        }
      }
      if (description != NULL) {
        return (description);
      }
      cerr << "VALUE-OF encountered missing description on class or relation " << "`" << self->name() << "'";
      return (NULL);
    }
  }
}

boolean skolemP(Object* self) {
  return (isaP(self, SGT_PROPOSITIONS_SKOLEM));
}

boolean variableP(Object* self) {
  return (isaP(self, SGT_PROPOSITIONS_PATTERN_VARIABLE));
}

boolean native_valueP(Object* self) {
  if (self != NULL) {
    return (!isaP(self, SGT_PROPOSITIONS_LOGIC_OBJECT));
  }
  else {
    return (FALSE);
  }
}

Object* native_value_of(Object* self) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PROPOSITIONS_DESCRIPTION)) {
      { Description* self = NULL;

        self = ((Description*)(self_001));
        return (self->native_relation);
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_SKOLEM)) {
      { Skolem* self = NULL;

        self = ((Skolem*)(self_001));
        { Object* value = ((Object*)(access_in_context(self->variable_value, self, FALSE)));

          if (value != NULL) {
            return (native_value_of(value));
          }
          else {
            return (NULL);
          }
        }
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        return (((Object*)(access_in_context(self->variable_value, self, FALSE))));
      }
    }
    else if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        { Object* value = self->surrogate_value;

          if (value != NULL) {
            return (native_value_of(value));
          }
          else {
            return (NULL);
          }
        }
      }
    }
    else {
      return (self);
    }
  }
}

Logic_Object* equivalent_of(Logic_Object* self) {
  { Logic_Object* equivalent = self;
    Object* value = NULL;

    for (;;) {
      value = ((Object*)(access_in_context(equivalent->variable_value, equivalent, FALSE)));
      if ((value == NULL) ||
          (!isaP(value, SGT_PROPOSITIONS_LOGIC_OBJECT))) {
        return (equivalent);
      }
      equivalent = ((Logic_Object*)(value));
    }
  }
}

Pattern_Variable* innermost_variable_of(Pattern_Variable* self) {
  for (;;) {
    { Pattern_Variable* tightestvariable = self;
      Object* value = NULL;

      for (;;) {
        value = ((Object*)(access_in_context(tightestvariable->variable_value, tightestvariable, FALSE)));
        if ((value != NULL) &&
            variableP(value)) {
          tightestvariable = ((Pattern_Variable*)(value));
        }
        else {
          return (tightestvariable);
        }
      }
    }
  }
}

Object* innermost_of(Object* self) {
  if (description_modeP()) {
    { Object* nextvalue = self;
      Pattern_Variable* tightestvariable = NULL;
      Object* equivalent = NULL;

      for (;;) {
        { Object* nextvalue_001 = nextvalue;

          if (taxonomy_isaP(nextvalue, SGT_PROPOSITIONS_PATTERN_VARIABLE)) {
            { Pattern_Variable* nextvalue = NULL;

              nextvalue = ((Pattern_Variable*)(nextvalue_001));
              equivalent = ((Object*)(access_in_context(nextvalue->variable_value, nextvalue, FALSE)));
              if (equivalent == NULL) {
                return (nextvalue);
              }
              tightestvariable = nextvalue;
            }
          }
          else if (taxonomy_isaP(nextvalue, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
            { Logic_Object* nextvalue = NULL;

              nextvalue = ((Logic_Object*)(nextvalue_001));
              return (tightestvariable);
            }
          }
          else if (surrogateP(nextvalue)) {
            { Surrogate* nextvalue = NULL;

              nextvalue = ((Surrogate*)(nextvalue_001));
              return (nextvalue);
            }
          }
          else {
            return (nextvalue);
          }
        }
        nextvalue = equivalent;
      }
    }
  }
  else {
    { Object* tightestvalue = self;
      Object* equivalent = NULL;

      for (;;) {
        { Object* tightestvalue_001 = tightestvalue;

          if (taxonomy_isaP(tightestvalue, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
            { Logic_Object* tightestvalue = NULL;

              tightestvalue = ((Logic_Object*)(tightestvalue_001));
              if (((Object*)(access_in_context(tightestvalue->variable_value, tightestvalue, FALSE))) == NULL) {
                return (tightestvalue);
              }
              equivalent = ((Object*)(access_in_context(tightestvalue->variable_value, tightestvalue, FALSE)));
            }
          }
          else if (surrogateP(tightestvalue)) {
            { Surrogate* tightestvalue = NULL;

              tightestvalue = ((Surrogate*)(tightestvalue_001));
              if (tightestvalue->surrogate_value == NULL) {
                return (tightestvalue);
              }
              equivalent = tightestvalue->surrogate_value;
            }
          }
          else {
            return (tightestvalue);
          }
        }
        tightestvalue = equivalent;
      }
    }
  }
}

Object* compute_function_value(Proposition* self) {
  return (((Slot*)(((Surrogate*)(self->renamed_Operator))->surrogate_value))->apply_slot_to_native_arguments(self->arguments));
}

Object* last_argument(Proposition* proposition) {
  return (proposition->arguments->nth(proposition->arguments->length() - 1));
}

Object* function_value(Proposition* self) {
  { Object* outputvalue = last_argument(self);

    if (!(oEVALUATIONMODEo == KWD_PROPOSITIONS_EXTENSIONAL_ASSERTION)) {
      return (outputvalue);
    }
    outputvalue = outputvalue->value_of();
    if (!skolemP(outputvalue)) {
      return (outputvalue);
    }
    { Object* computedvalue = compute_function_value(self);

      if (!bottomP(computedvalue)) {
        bind_skolem_to_value(((Skolem*)(outputvalue)), computedvalue, FALSE);
        return (computedvalue);
      }
    }
    return (outputvalue);
  }
}

Object* function_representative(Proposition* self) {
  return (last_argument(self));
}

boolean compute_predicate_value(Proposition* self, boolean& return1) {
  { Object* value = NULL;

    value = ((Slot*)(((Surrogate*)(self->renamed_Operator))->surrogate_value))->apply_slot_to_native_arguments(self->arguments);
    if (bottomP(value)) {
      { boolean return_temp = FALSE;

        return1 = FALSE;
        return (return_temp);
      }
    }
    else {
      { boolean return_temp = ((Boolean_Wrapper*)(value))->wrapper_value;

        return1 = TRUE;
        return (return_temp);
      }
    }
  }
}

Symbol* yield_anonymous_skolem_name(boolean variableP) {
  oSKOLEM_ID_COUNTERo = oSKOLEM_ID_COUNTERo + 1;
  return (intern_symbol(string_concatenate((variableP ? ((char*)("?V")) : ((char*)("SK"))), integer_to_string(oSKOLEM_ID_COUNTERo))));
}

Cons* read_OfreeskolemsO() {
  return (oFREESKOLEMSo);
}

Cons* write_OfreeskolemsO(Cons* value) {
  oFREESKOLEMSo = value;
  return (value);
}

Skolem* help_create_skolem(Skolem* self, Surrogate* type, Symbol* name, boolean assertinP) {
  if (!((type == NULL) ||
      (!subtype_ofP(type, SGT_PROPOSITIONS_LITERAL_WRAPPER)))) {
    cerr << "Safety violation: " << "INTERNAL ERROR: Need to copy unwrapping logic from " << "`create-function-proposition' into `help-create-skolem'.";
  }
  if (!(name != NULL)) {
    name = yield_anonymous_skolem_name(variableP(self));
  }
  set_dynamic_slot_value(self, SYM_PROPOSITIONS_SKOLEM_NAME, name, NULL);
  if (assertinP) {
    assert_isa_proposition(self, type);
  }
  return (self);
}

Skolem* create_skolem(Surrogate* type, Symbol* name) {
  if (!(!description_modeP())) {
    cerr << "Safety violation: " << "INTERNAL ERROR: Trying to create a skolem in description mode.";
  }
  { Skolem* skolem = new_skolem();

    oFREESKOLEMSo = cons(skolem, oFREESKOLEMSo);
    help_create_skolem(skolem, type, name, TRUE);
    return (skolem);
  }
}

Pattern_Variable* create_variable(Surrogate* type, Symbol* name, boolean assertinP) {
  { Keyword* evaluationmode = oEVALUATIONMODEo;

    { Keyword* old_OevaluationmodeO_001 = oEVALUATIONMODEo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oEVALUATIONMODEo = evaluationmode;
            if (assertinP &&
                (!description_modeP())) {
              oEVALUATIONMODEo = KWD_PROPOSITIONS_DESCRIPTION;
            }
            { Skolem* return_value_001 = help_create_skolem(new_pattern_variable(), type, name, assertinP);

              oEVALUATIONMODEo = old_OevaluationmodeO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (((Pattern_Variable*)(return_value_001)));
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

boolean trueP(Proposition* self) {
  return (((Truth_Value*)(access_in_context(self->truth_value, self, FALSE))) == TRUE_TRUTH_VALUE);
}

boolean falseP(Proposition* self) {
  return (((Truth_Value*)(access_in_context(self->truth_value, self, FALSE))) == FALSE_TRUTH_VALUE);
}

boolean unknownP(Proposition* self) {
  return ((((Truth_Value*)(access_in_context(self->truth_value, self, FALSE))) == NULL) ||
      ((!(((Truth_Value*)(access_in_context(self->truth_value, self, FALSE))) == TRUE_TRUTH_VALUE)) &&
       (!(((Truth_Value*)(access_in_context(self->truth_value, self, FALSE))) == FALSE_TRUTH_VALUE))));
}

void signal_unification_clash(Object* term1, Object* term2) {
  if ((term1 != NULL) &&
      (term2 != NULL)) {
    cerr << "`" << term1 << "'" << " clashes with " << "`" << term2 << "'";
  }
  signal(oTHE_CLASH_EXCEPTIONo);
}

void signal_variable_value_clash(Skolem* skolem, Object* value1, Object* value2) {
  if ((value1 != NULL) &&
      (value2 != NULL)) {
    cerr << "Skolem " << "`" << skolem << "'" << " is equated with multiple values:" << endl << "   " << "`" << value1 << "'" << " and " << "`" << value2 << "'" << ".";
  }
  signal(oTHE_CLASH_EXCEPTIONo);
}

void signal_truth_value_clash(Proposition* proposition) {
  cerr << "Derived both TRUE and FALSE for the proposition " << "`" << proposition << "'";
  signal(oTHE_CLASH_EXCEPTIONo);
}

void signal_fail() {
  cout << "FAIL" << endl;
  signal(oTHE_FAIL_EXCEPTIONo);
}

Surrogate* logical_type(Object* self) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PROPOSITIONS_DESCRIPTION)) {
      { Description* self = NULL;

        self = ((Description*)(self_001));
        if (self->monadicP()) {
          return ((self->iotaP_reader() ? ((Surrogate*)(self->representative()->root_type)) : ((Surrogate*)(SGT_PROPOSITIONS_COLLECTION))));
        }
        else {
          return (((self->root_type != NULL) ? ((Surrogate*)(self->root_type)) : ((Surrogate*)(SGT_PROPOSITIONS_RELATION))));
        }
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_PATTERN_VARIABLE)) {
      { Pattern_Variable* self = NULL;

        self = ((Pattern_Variable*)(self_001));
        { Proposition* p = NULL;
          Cons* iter_001 = self->dependent_propositions->the_cons_list;

          while (!nilP(iter_001)) {
            {
              p = ((Proposition*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            if ((p->kind == KWD_PROPOSITIONS_IN) &&
                p->variable_typeP_reader()) {
              return (((Surrogate*)(p->arguments->second())));
            }
          }
        }
        return (self->root_type);
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        return (self->root_type);
      }
    }
    else if (wrapperP(self)) {
      { Wrapper* self = NULL;

        self = ((Wrapper*)(self_001));
        return (wrapper_value_type(self));
      }
    }
    else if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        if (self->surrogate_value != NULL) {
          return (logical_type(self->surrogate_value));
        }
        else {
          return (SGT_PROPOSITIONS_UNKNOWN);
        }
      }
    }
    else {
      return (self->primary_type());
    }
  }
}

void unify_types(Skolem* term1, Object* term2) {
  { Surrogate* type1 = logical_type(term1);
    Surrogate* type2 = logical_type(term2);

    if ((type1 == type2) ||
        (subtype_ofP(type1, type2) ||
         subtype_ofP(type2, type1))) {
    }
    else if (type1 == SGT_PROPOSITIONS_UNKNOWN) {
      if (isaP(term1, SGT_PROPOSITIONS_SKOLEM)) {
      }
      ((Skolem*)(term1))->root_type = type2;
    }
    else if (type2 == SGT_PROPOSITIONS_UNKNOWN) {
      if (isaP(term2, SGT_PROPOSITIONS_SKOLEM)) {
        ((Skolem*)(term2))->root_type = type1;
      }
    }
    else {
      if (bottomP(term2) &&
          (!((Boolean_Wrapper*)(access_in_context(term1->not_bottomP, term1, FALSE)))->wrapper_value)) {
        return;
      }
      signal_unification_clash(term1, term2);
    }
  }
}

void scan_for_attributes_clash(List* attributes1, List* attributes2) {
  if (attributes1->emptyP() ||
      attributes2->emptyP()) {
    return;
  }
  { Cons* cursor1 = attributes1->the_cons_list;
    Surrogate* slotref1 = ((Surrogate*)(((Proposition*)(cursor1->value))->renamed_Operator));
    Cons* cursor2 = attributes2->the_cons_list;
    Surrogate* slotref2 = ((Surrogate*)(((Proposition*)(cursor2->value))->renamed_Operator));

    for (;;) {
      if (slotref_less_or_equalP(slotref1, slotref2)) {
        {
          if (slotref1 == slotref2) {
            { Proposition* p1 = ((Proposition*)(cursor1->value));
              Object* v1 = function_value(p1);
              Proposition* p2 = ((Proposition*)(cursor2->value));
              Object* v2 = function_value(p2);

              if ((!eqlP(v1, v2)) &&
                  ((!skolemP(v1)) &&
                   (!skolemP(v2)))) {
                signal_unification_clash(v1, v2);
                return;
              }
            }
          }
          cursor1 = cursor1->rest;
          if (cursor1 == NULL) {
            return;
          }
          slotref1 = ((Surrogate*)(((Proposition*)(cursor1->value))->renamed_Operator));
        }
      }
      else {
        {
          cursor2 = cursor2->rest;
          if (cursor2 == NULL) {
            return;
          }
          slotref2 = ((Surrogate*)(((Proposition*)(cursor2->value))->renamed_Operator));
        }
      }
    }
  }
}

void unify_attribute_propositions(List* attributes1, List* attributes2) {
  if (attributes1->emptyP() ||
      attributes2->emptyP()) {
    return;
  }
  { Cons* cursor1 = attributes1->the_cons_list;
    Surrogate* slotref1 = ((Surrogate*)(((Proposition*)(cursor1->value))->renamed_Operator));
    Cons* cursor2 = attributes2->the_cons_list;
    Surrogate* slotref2 = ((Surrogate*)(((Proposition*)(cursor2->value))->renamed_Operator));

    for (;;) {
      if (slotref_less_or_equalP(slotref1, slotref2)) {
        {
          if (slotref1 == slotref2) {
            { Proposition* p1 = ((Proposition*)(cursor1->value));
              Proposition* p2 = ((Proposition*)(cursor2->value));

              equate_values(function_value(p1), function_value(p2));
            }
          }
          cursor1 = cursor1->rest;
          if (cursor1 == NULL) {
            return;
          }
          slotref1 = ((Surrogate*)(((Proposition*)(cursor1->value))->renamed_Operator));
        }
      }
      else {
        {
          cursor2 = cursor2->rest;
          if (cursor2 == NULL) {
            return;
          }
          slotref2 = ((Surrogate*)(((Proposition*)(cursor2->value))->renamed_Operator));
        }
      }
    }
  }
}

void unify_skolem_and_value(Skolem* skolem, Object* value) {
  { Object* value_001 = value;

    if (taxonomy_isaP(value, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
      { Logic_Object* value = NULL;

        value = ((Logic_Object*)(value_001));
        unify_attribute_propositions(skolem->dependent_attribute_propositions, value->dependent_attribute_propositions);
      }
    }
    else {
    }
  }
  { Proposition* prop = NULL;
    Cons* iter_001 = skolem->dependent_propositions->the_cons_list;

    while (!nilP(iter_001)) {
      {
        prop = ((Proposition*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      evaluate_proposition(prop);
    }
  }
}

void bind_skolem_to_value(Skolem* fromskolem, Object* tovalue, boolean toplevelupdateP) {
  if (!unboundP(fromskolem)) {
    cerr << "Safety violation: " << "INTERNAL ERROR: Bound skolem passed to `bind-skolem-to-value'.";
  }
  { Skolem* object_001 = fromskolem;
    Object* value_001 = tovalue;
    Object* old_value_001 = object_001->variable_value;
    Object* new_value_001 = update_in_context(old_value_001, value_001, object_001, FALSE);

    if (!cs_valueP(old_value_001)) {
      object_001->variable_value = new_value_001;
    }
  }
  { Object* tovalue_001 = tovalue;

    if (taxonomy_isaP(tovalue, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
      { Logic_Object* tovalue = NULL;

        tovalue = ((Logic_Object*)(tovalue_001));
        if (logic_object_permits_backlinksP(tovalue)) {
          if (skolemP(tovalue)) {
            { Object* equivalentskolem = ((Object*)(access_in_context(tovalue->variable_value, tovalue, FALSE)));

              for (;;) {
                if (equivalentskolem == NULL) {
                  break;
                }
                { Object* equivalentskolem_001 = equivalentskolem;

                  if (taxonomy_isaP(equivalentskolem, SGT_PROPOSITIONS_SKOLEM)) {
                    { Skolem* equivalentskolem = NULL;

                      equivalentskolem = ((Skolem*)(equivalentskolem_001));
                      if (equivalentskolem == tovalue) {
                        { Skolem* object_002 = fromskolem;
                          Object* value_002 = NULL;
                          Object* old_value_003 = object_002->variable_value;
                          Object* new_value_002 = update_in_context(old_value_003, value_002, object_002, FALSE);

                          if (!cs_valueP(old_value_003)) {
                            object_002->variable_value = new_value_002;
                          }
                        }
                        return;
                      }
                      equivalentskolem = ((Skolem*)(((Object*)(access_in_context(equivalentskolem->variable_value, equivalentskolem, FALSE)))));
                    }
                  }
                  else {
                    break;
                  }
                }
              }
            }
          }
          { Logic_Object* object_003 = tovalue;
            Cons* value_003 = cons(fromskolem, tovalue->variable_value_inverse_reader());
            Object* old_value_005 = object_003->variable_value_inverse;
            Object* new_value_003 = update_in_context(old_value_005, value_003, object_003, FALSE);

            if (!cs_valueP(old_value_005)) {
              object_003->variable_value_inverse = new_value_003;
            }
          }
          if (tovalue->root_type == NULL) {
            assert_isa_proposition(tovalue, fromskolem->root_type);
          }
        }
      }
    }
    else {
    }
  }
  oCONTEXTo->react_to_kb_update(fromskolem);
  if (!skolemP(tovalue)) {
    if (fromskolem->defining_proposition != NULL) {
      assign_truth_value(fromskolem->defining_proposition, TRUE);
      react_to_attribute_proposition_update(fromskolem, NULL, tovalue, toplevelupdateP);
    }
  }
}

void unbind_skolem_value(Skolem* skolem, boolean toplevelupdateP) {
  { Object* oldvalue = skolem->value_of();

    { Skolem* object_001 = skolem;
      Object* value_001 = NULL;
      Object* old_value_001 = object_001->variable_value;
      Object* new_value_001 = update_in_context(old_value_001, value_001, object_001, FALSE);

      if (!cs_valueP(old_value_001)) {
        object_001->variable_value = new_value_001;
      }
    }
    { Object* oldvalue_001 = oldvalue;

      if (taxonomy_isaP(oldvalue, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
        { Logic_Object* oldvalue = NULL;

          oldvalue = ((Logic_Object*)(oldvalue_001));
          if (oldvalue->variable_value_inverse_reader()->first() == skolem) {
            { Logic_Object* object_002 = oldvalue;
              Cons* value_002 = oldvalue->variable_value_inverse_reader()->rest;
              Object* old_value_002 = object_002->variable_value_inverse;
              Object* new_value_002 = update_in_context(old_value_002, value_002, object_002, FALSE);

              if (!cs_valueP(old_value_002)) {
                object_002->variable_value_inverse = new_value_002;
              }
            }
          }
          else {
            { Logic_Object* object_003 = oldvalue;
              Cons* value_003 = copy_cons_list(oldvalue->variable_value_inverse_reader())->remove(skolem);
              Object* old_value_003 = object_003->variable_value_inverse;
              Object* new_value_003 = update_in_context(old_value_003, value_003, object_003, FALSE);

              if (!cs_valueP(old_value_003)) {
                object_003->variable_value_inverse = new_value_003;
              }
            }
          }
        }
      }
      else {
      }
    }
    check_for_out_of_date_inference_cache();
    if (skolem->defining_proposition != NULL) {
      if (!(skolem->defining_proposition->kind == KWD_PROPOSITIONS_FUNCTION)) {
        cerr << "Safety violation: " << "INTERNAL ERROR: Skolem has illegal defining proposition.";
      }
      react_to_attribute_proposition_update(skolem, oldvalue, NULL, toplevelupdateP);
    }
  }
}

void constrain_as_subset(Sequence* set1, Sequence* set2) {
  if (set1->length() > set2->length()) {
    signal_unification_clash(set1, set2);
  }
  { Cons* copy1 = NIL;
    Cons* copy2 = NIL;

    { Object* i2 = NULL;
      Iterator* iter_001 = ((Iterator*)(set2->allocate_iterator()));

      while (iter_001->nextP()) {
        {
          i2 = iter_001->value;
        }
        copy2 = cons(i2, copy2);
      }
    }
    { Object* i1 = NULL;
      Iterator* iter_002 = ((Iterator*)(set1->allocate_iterator()));

      while (iter_002->nextP()) {
        {
          i1 = iter_002->value;
        }
        if (copy2->memberP(i1)) {
          copy2 = copy2->remove(i1);
        }
        else {
          copy1 = cons(i1, copy1);
        }
      }
    }
    if (copy1->emptyP()) {
      return;
    }
    if (copy2->length() == 1) {
      { Object* item1 = copy1->first();
        Object* item2 = copy2->first();

        free_cons_list(copy1);
        free_cons_list(copy2);
        equate_values(item1, item2);
        return;
      }
    }
    { int skolemcount1 = 0;
      int skolemcount2 = 0;

      { Object* i1 = NULL;
        Cons* iter_003 = copy1;

        while (!nilP(iter_003)) {
          {
            i1 = iter_003->value;
            iter_003 = iter_003->rest;
          }
          if (skolemP(i1)) {
            skolemcount1 = skolemcount1 + 1;
          }
        }
      }
      { Object* i2 = NULL;
        Cons* iter_004 = copy2;

        while (!nilP(iter_004)) {
          {
            i2 = iter_004->value;
            iter_004 = iter_004->rest;
          }
          if (skolemP(i2)) {
            skolemcount2 = skolemcount2 + 1;
          }
        }
      }
      free_cons_list(copy1);
      free_cons_list(copy2);
      if ((skolemcount1 + skolemcount2) == 0) {
        signal_unification_clash(set1, set2);
      }
    }
  }
}

void equate_collections(Collection* col1, Collection* col2) {
  if (col1->orderedP() &&
      col2->orderedP()) {
    { Object* i2 = NULL;
      Object* i1 = NULL;
      Iterator* iter_001 = ((Iterator*)(col1->allocate_iterator()));
      Iterator* iter_002 = ((Iterator*)(col2->allocate_iterator()));

      while (iter_001->nextP() &&
          iter_002->nextP()) {
        {
          i1 = iter_001->value;
        }
        {
          i2 = iter_002->value;
        }
        equate_values(i1, i2);
      }
    }
    return;
  }
  if (col1->no_duplicatesP() &&
      col2->no_duplicatesP()) {
    constrain_as_subset(((Sequence*)(col1)), ((Sequence*)(col2)));
    constrain_as_subset(((Sequence*)(col2)), ((Sequence*)(col1)));
  }
}

void equate_values(Object* term1, Object* term2) {
  if (skolemP(term1)) {
    bind_skolem_to_value(((Skolem*)(term1)), term2, FALSE);
  }
  else if (skolemP(term2)) {
    bind_skolem_to_value(((Skolem*)(term2)), term1, FALSE);
  }
  else if (collectionP(term1) &&
      collectionP(term2)) {
    equate_collections(((Collection*)(term1)), ((Collection*)(term2)));
  }
  else {
    if (!(eqlP(term1, term2))) {
      signal_unification_clash(term1, term2);
    }
  }
}

boolean unequate_valuesP(Object* term1, Object* term2) {
  { Object* term1_001 = term1;

    if (taxonomy_isaP(term1, SGT_PROPOSITIONS_SKOLEM)) {
      { Skolem* term1 = NULL;

        term1 = ((Skolem*)(term1_001));
        if (eqlP(((Object*)(access_in_context(term1->variable_value, term1, FALSE))), term2)) {
          unbind_skolem_value(term1, FALSE);
          return (TRUE);
        }
      }
    }
    else {
    }
  }
  return (FALSE);
}

boolean description_equals_descriptionP(Object* arg1, Object* arg2) {
  return (specializesP(arg1, arg2) &&
      specializesP(arg2, arg1));
}

boolean argument_equals_argumentP(Object* arg1, Object* arg2) {
  if (isaP(arg1, SGT_PROPOSITIONS_SURROGATE)) {
    arg1 = ((Surrogate*)(arg1))->surrogate_value;
  }
  if (isaP(arg2, SGT_PROPOSITIONS_SURROGATE)) {
    arg2 = ((Surrogate*)(arg2))->surrogate_value;
  }
  if (eqlP(arg1, arg2)) {
    return (TRUE);
  }
  if (isaP(arg1, SGT_PROPOSITIONS_DESCRIPTION) &&
      isaP(arg2, SGT_PROPOSITIONS_DESCRIPTION)) {
    return (description_equals_descriptionP(arg1, arg2));
  }
  return (FALSE);
}

boolean proposition_eqlP(Proposition* self, Proposition* other) {
  { Keyword* test_value_001 = self->kind;

    if ((test_value_001 == KWD_PROPOSITIONS_AND) ||
        (test_value_001 == KWD_PROPOSITIONS_OR)) {
      return (commutative_proposition_eqlP(self, other));
    }
    else {
      if (self == other) {
        return (TRUE);
      }
      else {
        { boolean test_value_002 = FALSE;

          test_value_002 = eqlP(self->renamed_Operator, other->renamed_Operator);
          if (test_value_002) {
            { boolean alwaysP_001 = TRUE;

              { Object* arg2 = NULL;
                Object* arg1 = NULL;
                Vector* vector_001 = self->arguments;
                int index_001 = 0;
                int length_001 = vector_001->length();
                Vector* vector_002 = other->arguments;
                int index_002 = 0;
                int length_002 = vector_002->length();

                while ((index_001 < length_001) &&
                    (index_002 < length_002)) {
                  {
                    arg1 = vector_001->nth(index_001);
                    index_001 = index_001 + 1;
                  }
                  {
                    arg2 = vector_002->nth(index_002);
                    index_002 = index_002 + 1;
                  }
                  if (!argument_equals_argumentP(arg1, arg2)) {
                    alwaysP_001 = FALSE;
                    break;
                  }
                }
              }
              test_value_002 = alwaysP_001;
            }
          }
          { boolean value_001 = test_value_002;

            return (value_001);
          }
        }
      }
    }
  }
}

boolean commutative_proposition_eqlP(Proposition* self, Proposition* other) {
  if (self == other) {
    return (TRUE);
  }
  else {
    { boolean test_value_001 = FALSE;

      test_value_001 = eqlP(self->renamed_Operator, other->renamed_Operator);
      if (test_value_001) {
        test_value_001 = self->arguments->length() == other->arguments->length();
        if (test_value_001) {
          { boolean alwaysP_001 = TRUE;

            { Object* arg1 = NULL;
              Vector* vector_001 = self->arguments;
              int index_001 = 0;
              int length_001 = vector_001->length();

              while (index_001 < length_001) {
                {
                  arg1 = vector_001->nth(index_001);
                  index_001 = index_001 + 1;
                }
                { boolean test_value_002 = FALSE;

                  { boolean foundP_001 = FALSE;

                    { Object* arg2 = NULL;
                      Vector* vector_002 = other->arguments;
                      int index_002 = 0;
                      int length_002 = vector_002->length();

                      while (index_002 < length_002) {
                        {
                          arg2 = vector_002->nth(index_002);
                          index_002 = index_002 + 1;
                        }
                        if (proposition_eqlP(((Proposition*)(arg1)), ((Proposition*)(arg2)))) {
                          foundP_001 = TRUE;
                          break;
                        }
                      }
                    }
                    test_value_002 = foundP_001;
                  }
                  test_value_002 = !test_value_002;
                  if (test_value_002) {
                    alwaysP_001 = FALSE;
                    break;
                  }
                }
              }
            }
            test_value_001 = alwaysP_001;
          }
        }
      }
      { boolean value_001 = test_value_001;

        return (value_001);
      }
    }
  }
}

List* find_dependents_of_some_argument(Proposition* self) {
  { boolean firstargP = TRUE;

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

          if (taxonomy_isaP(term, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
            { Logic_Object* term = NULL;

              term = ((Logic_Object*)(term_001));
              if (firstargP &&
                  attribute_propositionP(self)) {
                return (term->dependent_attribute_propositions);
              }
              else {
                return (term->dependent_propositions);
              }
            }
          }
          else if (taxonomy_isaP(term, SGT_PROPOSITIONS_PROPOSITION)) {
            { Proposition* term = NULL;

              term = ((Proposition*)(term_001));
              return (term->dependent_propositions);
            }
          }
          else {
            return (NIL_LIST);
            { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    cout << "Error in logical expression." << endl;
                    cout << "   " << "In proposition: " << self << endl << "At least one argument to the proposition must be of type LOGIC-OBJECT\nor PROPOSITION." << endl;
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
            return (NULL);
          }
        }
        firstargP = FALSE;
      }
    }
    return (NIL_LIST);
  }
}

Proposition* find_duplicate_proposition(Proposition* self) {
  { Proposition* value_001 = NULL;

    { Proposition* p = NULL;
      Cons* iter_001 = find_dependents_of_some_argument(self)->the_cons_list;

      while (!nilP(iter_001)) {
        {
          p = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (proposition_eqlP(self, p)) {
          value_001 = p;
          break;
        }
      }
    }
    { Proposition* value_002 = value_001;

      return (value_002);
    }
  }
}

void evaluate_and_proposition(Proposition* self) {
  { Vector* arguments = self->arguments;

    if (trueP(self)) {
      { Proposition* arg = NULL;
        Vector* vector_001 = arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            arg = ((Proposition*)(vector_001->nth(index_001)));
            index_001 = index_001 + 1;
          }
          assign_truth_value(arg, TRUE);
        }
      }
    }
    else if (falseP(self)) {
      { Proposition* onlyunboundarg = NULL;

        { Proposition* arg = NULL;
          Vector* vector_002 = arguments;
          int index_002 = 0;
          int length_002 = vector_002->length();

          while (index_002 < length_002) {
            {
              arg = ((Proposition*)(vector_002->nth(index_002)));
              index_002 = index_002 + 1;
            }
            if (falseP(arg)) {
              return;
            }
            else if (unknownP(arg)) {
              if (onlyunboundarg != NULL) {
                return;
              }
              onlyunboundarg = arg;
            }
          }
        }
        if (onlyunboundarg != NULL) {
          assign_truth_value(onlyunboundarg, FALSE);
        }
        else {
          assign_truth_value(self, TRUE);
        }
      }
    }
    else {
      { boolean unboundargP = FALSE;

        { Proposition* arg = NULL;
          Vector* vector_003 = arguments;
          int index_003 = 0;
          int length_003 = vector_003->length();

          while (index_003 < length_003) {
            {
              arg = ((Proposition*)(vector_003->nth(index_003)));
              index_003 = index_003 + 1;
            }
            if (falseP(arg)) {
              assign_truth_value(self, FALSE);
              return;
            }
            else if (unknownP(arg)) {
              unboundargP = TRUE;
            }
          }
        }
        if (!unboundargP) {
          assign_truth_value(self, TRUE);
        }
      }
    }
  }
}

void evaluate_or_proposition(Proposition* self) {
  { Vector* arguments = self->arguments;

    if (falseP(self)) {
      { Proposition* arg = NULL;
        Vector* vector_001 = arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            arg = ((Proposition*)(vector_001->nth(index_001)));
            index_001 = index_001 + 1;
          }
          assign_truth_value(arg, FALSE);
        }
      }
    }
    else if (trueP(self)) {
      { Proposition* onlyunboundarg = NULL;

        { Proposition* arg = NULL;
          Vector* vector_002 = arguments;
          int index_002 = 0;
          int length_002 = vector_002->length();

          while (index_002 < length_002) {
            {
              arg = ((Proposition*)(vector_002->nth(index_002)));
              index_002 = index_002 + 1;
            }
            if (trueP(arg)) {
              return;
            }
            else if (unknownP(arg)) {
              if (onlyunboundarg != NULL) {
                return;
              }
              onlyunboundarg = arg;
            }
          }
        }
        if (onlyunboundarg != NULL) {
          assign_truth_value(onlyunboundarg, TRUE);
        }
        else {
          assign_truth_value(self, FALSE);
        }
      }
    }
    else {
      { boolean unboundargP = FALSE;

        { Proposition* arg = NULL;
          Vector* vector_003 = arguments;
          int index_003 = 0;
          int length_003 = vector_003->length();

          while (index_003 < length_003) {
            {
              arg = ((Proposition*)(vector_003->nth(index_003)));
              index_003 = index_003 + 1;
            }
            if (trueP(arg)) {
              assign_truth_value(self, TRUE);
              return;
            }
            else if (unknownP(arg)) {
              unboundargP = TRUE;
            }
          }
        }
        if (!unboundargP) {
          assign_truth_value(self, FALSE);
        }
      }
    }
  }
}

void evaluate_not_proposition(Proposition* self) {
  { Proposition* argument = ((Proposition*)(self->arguments->nth(0)));

    if (trueP(argument)) {
      assign_truth_value(self, FALSE);
    }
    else if (falseP(argument)) {
      assign_truth_value(self, TRUE);
    }
    else if (trueP(self)) {
      assign_truth_value(argument, FALSE);
    }
    else if (falseP(self)) {
      assign_truth_value(argument, TRUE);
    }
  }
}

void evaluate_equivalent_proposition(Proposition* self) {
  { Vector* arguments = self->arguments;
    Object* firstarg = innermost_of(arguments->nth(0));
    Object* secondarg = innermost_of(arguments->nth(1));

    if (trueP(self)) {
      equate_values(firstarg, secondarg);
    }
    else if (eqlP(firstarg, secondarg)) {
      assign_truth_value(self, TRUE);
    }
    else if ((!skolemP(firstarg)) &&
        (!skolemP(secondarg))) {
      assign_truth_value(self, FALSE);
    }
  }
}

void evaluate_function_proposition(Proposition* self) {
  { Object* computedvalue = compute_function_value(self);
    Object* storedvalue = last_argument(self)->value_of();

    if ((!eqlP(computedvalue, storedvalue)) &&
        (!bottomP(computedvalue))) {
      equate_values(computedvalue, storedvalue);
    }
  }
}

void Slot::evaluate_slot_permutations(Vector* arguments) {
  { Slot* self = this;

    arguments = arguments;
  }
}

void Method_Slot::evaluate_slot_permutations(Vector* originalarguments) {
  { Method_Slot* self = this;

    if (((Key_Value_List*)(dynamic_slot_value(self, SYM_PROPOSITIONS_PERMUTATION_TABLE, NULL))) == NULL) {
      return;
    }
    { int lastindex = originalarguments->length() - 1;
      int nonnativeargcount = 0;

      { int i = NULL_INTEGER;
        int iter_001 = 0;
        int upper_bound_001 = lastindex;
        boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

        while (unboundedP_001 ||
            (iter_001 <= upper_bound_001)) {
          {
            i = iter_001;
            iter_001 = iter_001 + 1;
          }
          if (!(native_value_of(originalarguments->nth(i)) != NULL)) {
            nonnativeargcount = nonnativeargcount + 1;
          }
        }
      }
      if (nonnativeargcount > 1) {
        return;
      }
      { Vector* permutedarguments = new_vector(lastindex + 1);
        Object* computedvalue = NULL;

        { Slot* permutationslot = NULL;
          Vector* permutation = NULL;
          Kv_Cons* iter_002 = ((Key_Value_List*)(dynamic_slot_value(self, SYM_PROPOSITIONS_PERMUTATION_TABLE, NULL)))->the_kv_list;

          while (iter_002 != NULL) {
            permutation = ((Vector*)(iter_002->key));
            {
              permutationslot = ((Slot*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            { int i = NULL_INTEGER;
              int iter_003 = 0;
              int upper_bound_002 = lastindex;
              boolean unboundedP_002 = upper_bound_002 == NULL_INTEGER;

              while (unboundedP_002 ||
                  (iter_003 <= upper_bound_002)) {
                {
                  i = iter_003;
                  iter_003 = iter_003 + 1;
                }
                permutedarguments->nth_setter(originalarguments->nth(((Integer_Wrapper*)(permutation->nth(i)))->wrapper_value - 1), i);
              }
            }
            computedvalue = permutationslot->apply_slot_to_native_arguments(permutedarguments);
            if (!bottomP(computedvalue)) {
              { Object* storedvalue = permutedarguments->nth(lastindex)->value_of();

                if (!eqlP(computedvalue, storedvalue)) {
                  equate_values(computedvalue, storedvalue);
                }
              }
              break;
            }
          }
        }
      }
    }
  }
}

void evaluate_predicate_proposition(Proposition* self) {
  { boolean result = FALSE;
    boolean knownP = FALSE;

    result = compute_predicate_value(self, knownP);
    if (knownP) {
      assign_truth_value(self, result);
    }
  }
}

void evaluate_proposition(Proposition* self) {
  { Keyword* test_value_001 = self->kind;

    if (test_value_001 == KWD_PROPOSITIONS_AND) {
      evaluate_and_proposition(self);
    }
    else if (test_value_001 == KWD_PROPOSITIONS_OR) {
      evaluate_or_proposition(self);
    }
    else if (test_value_001 == KWD_PROPOSITIONS_NOT) {
      evaluate_not_proposition(self);
    }
    else if (test_value_001 == KWD_PROPOSITIONS_EQUIVALENT) {
      evaluate_equivalent_proposition(self);
    }
    else if (test_value_001 == KWD_PROPOSITIONS_FUNCTION) {
      evaluate_function_proposition(self);
    }
    else if (test_value_001 == KWD_PROPOSITIONS_PREDICATE) {
      evaluate_predicate_proposition(self);
    }
    else {
    }
  }
}

Object* evaluate_term(Object* self) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PROPOSITIONS_LITERAL_WRAPPER)) {
      { Literal_Wrapper* self = NULL;

        self = ((Literal_Wrapper*)(self_001));
        return (evaluate_wrapped_literal_term(self));
      }
    }
    else if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        if (self == SGT_PROPOSITIONS_TRAP_DOOR_SURROGATE) {
          return (self->surrogate_value);
        }
        else {
          return (evaluate_surrogate_term(self));
        }
      }
    }
    else if (symbolP(self)) {
      { Symbol* self = NULL;

        self = ((Symbol*)(self_001));
        return (evaluate_symbol_term(self));
      }
    }
    else if (consP(self)) {
      { Cons* self = NULL;

        self = ((Cons*)(self_001));
        { Object* test_value_001 = self->first();

          if ((test_value_001 == SYM_PROPOSITIONS_SETOFALL) ||
              ((test_value_001 == SYM_PROPOSITIONS_THE_ONLY) ||
               (test_value_001 == SYM_PROPOSITIONS_KAPPA))) {
            return (evaluate_description_term(self, TRUE));
          }
          else if ((test_value_001 == SYM_PROPOSITIONS_SETOF) ||
              (test_value_001 == SYM_PROPOSITIONS_LISTOF)) {
            return (evaluate_setof_term(self));
          }
          else if (test_value_001 == SYM_PROPOSITIONS_CREATE) {
            return (evaluate_create_term(self));
          }
          else {
            return (evaluate_function_term(self));
          }
        }
      }
    }
    else {
      cerr << "Missing 'evaluate-term' method on " << "`" << self << "'";
    }
  }
}

Object* evaluate_wrapped_literal_term(Literal_Wrapper* self) {
  return (((Literal_Wrapper*)(self->permanentify())));
}

Object* evaluate_surrogate_term(Surrogate* self) {
  if (oEVALUATIONMODEo == KWD_PROPOSITIONS_EXTENSIONAL_ASSERTION) {
    { Object* value = self->surrogate_value;

      if (value == BOTTOM) {
        value = NULL;
        self->surrogate_value = NULL;
      }
      if (value != NULL) {
        { Object* value_001 = value;

          if (taxonomy_isaP(value, SGT_PROPOSITIONS_RELATION)) {
            { Relation* value = NULL;

              value = ((Relation*)(value_001));
              return (self->get_description());
            }
          }
          else {
            return (value);
          }
        }
      }
      create_logic_object(NULL, self, NULL);
      return (self->surrogate_value);
    }
  }
  else if (oEVALUATIONMODEo == KWD_PROPOSITIONS_QUERY) {
    { Object* surrogatevalue = self->surrogate_value;

      if (surrogatevalue == NULL) {
        self->surrogate_value = BOTTOM;
        return (self);
      }
      else if (isaP(surrogatevalue, SGT_PROPOSITIONS_LITERAL_WRAPPER)) {
        return (surrogatevalue);
      }
      else {
        return (self);
      }
    }
  }
  else if (oEVALUATIONMODEo == KWD_PROPOSITIONS_DESCRIPTION) {
    { Object* surrogatevalue = self->surrogate_value;

      if ((surrogatevalue != NULL) &&
          isaP(surrogatevalue, SGT_PROPOSITIONS_LITERAL_WRAPPER)) {
        return (surrogatevalue);
      }
      else {
        return (self);
      }
    }
  }
  else if (oEVALUATIONMODEo == KWD_PROPOSITIONS_INTENSIONAL_ASSERTION) {
    { Object* directvalue = self->surrogate_value;
      Skolem* intensionalskolem = NULL;

      if (skolemP(directvalue)) {
        return (directvalue);
      }
      intensionalskolem = create_skolem(((directvalue != NULL) ? ((Surrogate*)(logical_type(directvalue->value_of()))) : ((Surrogate*)(NULL))), NULL);
      self->surrogate_value = intensionalskolem;
      bind_skolem_to_value(intensionalskolem, directvalue, FALSE);
      return (intensionalskolem);
    }
  }
  else {
    cerr << "`" << oEVALUATIONMODEo << "'" << " is not a valid case option";
  }
}

boolean anonymous_variableP(Skolem* self) {
  return ((dynamic_slot_value(self, SYM_PROPOSITIONS_SKOLEM_NAME, NULL) == ANONYMOUS_VARIABLE_NAME) &&
      variableP(self));
}

Object* evaluate_symbol_term(Symbol* self) {
  { Object* value = lookup_logic_variable_binding(self);

    if (value != NULL) {
      return (value);
    }
    else if (self == ANONYMOUS_VARIABLE_NAME) {
      return (create_variable(NULL, ANONYMOUS_VARIABLE_NAME, FALSE));
    }
    else {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              cout << "Error in logical expression." << endl;
              cout << "   " << "Reference to undeclared variable: " << self << endl;
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
  }
}

void signal_undefined_term(Object* term) {
  { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRINTREADABLYpo = TRUE;
          cout << "Error in logical expression." << endl;
          cout << "   " << "Undefined term: " << term << endl;
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

Object* evaluate_setof_term(Cons* term) {
  { Object* test_value_001 = term->first();

    if (test_value_001 == SYM_PROPOSITIONS_SETOF) {
      { Set* collection = new_set();

        { Object* i = NULL;
          Cons* iter_001 = term->rest;

          while (!nilP(iter_001)) {
            {
              i = iter_001->value;
              iter_001 = iter_001->rest;
            }
            collection->insert(evaluate_term(i));
          }
        }
        collection->reverse();
        return (collection);
      }
    }
    else if (test_value_001 == SYM_PROPOSITIONS_LISTOF) {
      { List* collection = new_list();

        { Object* i = NULL;
          Cons* iter_002 = term->rest;

          while (!nilP(iter_002)) {
            {
              i = iter_002->value;
              iter_002 = iter_002->rest;
            }
            collection->insert(evaluate_term(i));
          }
        }
        collection->reverse();
        return (collection);
      }
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

Logic_Object* evaluate_create_term(Cons* term) {
  { Surrogate* type = term->second()->surrogatify();
    Surrogate* name = ((term->length() > 2) ? ((Surrogate*)(term->third()->surrogatify())) : ((Surrogate*)(NULL)));

    return (create_logic_object(type, name, NULL));
  }
}

Logic_Object* create(Generalized_Symbol* type, Cons* name) {
  // Create a logic object of logical type `type' and return it.
  // If `name' is also supplied, convert it into a surrogate and bind it to the 
  // newly created object.
  { Cons* createtree = listO(3, SYM_PROPOSITIONS_CREATE, type, name->concatenate(NIL));
    Logic_Object* result = evaluate_create_term(createtree);

    free_cons_tree(createtree);
    return (result);
  }
}

Logic_Object* create_evaluator_wrapper(Cons* arguments) {
  return (create(((Generalized_Symbol*)(arguments->value)), ((Cons*)(arguments->rest))));
}

Class* leftmost_concrete_superclass(Class* self) {
  { Class* rootclass = self;
    Surrogate* leftsupertype = NULL;
    Class* leftsuperclass = NULL;

    for (;;) {
      leftsupertype = ((Surrogate*)(rootclass->class_direct_supers->first()));
      if (leftsupertype == NULL) {
        return (rootclass);
      }
      leftsuperclass = ((Class*)(leftsupertype->surrogate_value));
      if (leftsuperclass->abstractP &&
          leftsuperclass->primitiveP()) {
        return (rootclass);
      }
      rootclass = leftsuperclass;
    }
  }
}

boolean has_multiple_root_classesP(Class* self) {
  { Class* rootclass = self;
    Surrogate* leftsupertype = NULL;
    Surrogate* secondsupertype = NULL;

    for (;;) {
      leftsupertype = ((Surrogate*)(rootclass->class_direct_supers->first()));
      if ((leftsupertype == NULL) ||
          ((Class*)(leftsupertype->surrogate_value))->abstractP) {
        return (FALSE);
      }
      secondsupertype = ((Surrogate*)(rootclass->class_direct_supers->rest()->first()));
      if ((secondsupertype != NULL) &&
          (!((Class*)(secondsupertype->surrogate_value))->abstractP)) {
        return (TRUE);
      }
      rootclass = ((Class*)(leftsupertype->surrogate_value));
    }
  }
}

void help_collect_root_classes(Class* self, List* allclasseslist, List* beenthere) {
  { List* directsupers = self->class_direct_supers;

    beenthere->insert(self);
    if (directsupers->emptyP()) {
      return;
    }
    if (((Class*)(((Surrogate*)(directsupers->first()))->surrogate_value))->abstractP) {
      allclasseslist->insert(self);
      return;
    }
    { Surrogate* supertype = NULL;
      Cons* iter_001 = directsupers->the_cons_list;

      while (!nilP(iter_001)) {
        {
          supertype = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        { Class* superclass = ((Class*)(supertype->surrogate_value));

          if (superclass->abstractP) {
            return;
          }
          if (!beenthere->memberP(superclass)) {
            help_collect_root_classes(superclass, allclasseslist, beenthere);
          }
        }
      }
    }
  }
}

Iterator* all_root_classes(Class* self) {
  { Cons* classlist = NIL;

    if (self->class_direct_supers->non_emptyP()) {
      if (has_multiple_root_classesP(self)) {
        { List* allclasseslist = new_list();
          List* beenthere = new_list();

          help_collect_root_classes(self, allclasseslist, beenthere);
          beenthere->free();
          classlist = allclasseslist->the_cons_list;
        }
      }
      else {
        { Class* super = leftmost_concrete_superclass(self);

          if (super != NULL) {
            classlist = cons(super, NIL);
          }
        }
      }
    }
    { Class* c = NULL;
      Cons* iter_001 = classlist;

      while (!nilP(iter_001)) {
        {
          c = ((Class*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        set_dynamic_slot_value(c, SYM_PROPOSITIONS_NON_DISJOINTNESS_KLUDGEp, wrap_boolean(TRUE), NULL);
      }
    }
    return (((Iterator*)(classlist->allocate_destructive_list_iterator())));
  }
}

List* get_description_extension(Class* rootclass) {
  { Description* description = ((Description*)(dynamic_slot_value(rootclass, SYM_PROPOSITIONS_DESCRIPTION, NULL)));
    List* extension = NULL;

    if (description == NULL) {
      description = rootclass->get_description();
    }
    extension = description->extension_reader();
    if (extension->emptyP() &&
        (extension == NIL_LIST)) {
      extension = new_list();
      set_dynamic_slot_value(description, SYM_PROPOSITIONS_EXTENSION, extension, NULL);
    }
    return (extension);
  }
}

boolean indexed_by_logical_extensionsP(Logic_Object* self) {
  { Logic_Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PROPOSITIONS_PATTERN_VARIABLE)) {
      { Pattern_Variable* self = NULL;

        self = ((Pattern_Variable*)(self_001));
        return (subsumption_modeP());
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_SKOLEM)) {
      { Skolem* self = NULL;

        self = ((Skolem*)(self_001));
        return (self->defining_proposition == NULL);
      }
    }
    else {
      return (TRUE);
    }
  }
}

void Logic_Object::update_logical_class_extension(Surrogate* type) {
  { Logic_Object* self = this;

    if (indexed_by_logical_extensionsP(self)) {
      get_description_extension(((Class*)(type->surrogate_value)))->insert(self);
    }
  }
}

void Pattern_Variable::update_logical_class_extension(Surrogate* type) {
  { Pattern_Variable* self = this;

    type = type;
  }
}

void help_update_root_types(Logic_Object* self, Surrogate* newroottype) {
  if (newroottype == self->root_type) {
    return;
  }
  { Surrogate* roottype = self->root_type;
    List* allroottypes = self->all_root_types_reader();

    if ((self->root_type == SGT_PROPOSITIONS_UNKNOWN) ||
        (self->root_type == NULL)) {
      self->root_type = newroottype;
      self->update_logical_class_extension(newroottype);
    }
    else if (allroottypes->emptyP()) {
      set_dynamic_slot_value(self, SYM_PROPOSITIONS_ALL_ROOT_TYPES, list(2, roottype, newroottype), NULL);
      self->update_logical_class_extension(newroottype);
    }
    else if (self->all_root_types_reader()->memberP(newroottype)) {
    }
    else {
      { List* newallroottypes = self->all_root_types_reader()->copy();

        newallroottypes->insert(newroottype);
        self->update_logical_class_extension(newroottype);
      }
    }
  }
}

void update_root_types(Logic_Object* self, Surrogate* type) {
  { Class* renamed_Class = ((Class*)(type->surrogate_value));

    if (has_multiple_root_classesP(renamed_Class)) {
      { Class* rc = NULL;
        Iterator* iter_001 = all_root_classes(renamed_Class);

        while (iter_001->nextP()) {
          {
            rc = ((Class*)(iter_001->value));
          }
          help_update_root_types(self, rc->class_type);
        }
      }
    }
    else {
      help_update_root_types(self, leftmost_concrete_superclass(renamed_Class)->class_type);
    }
  }
}

void transfer_logic_information_from_relation_hook(List* relationslist) {
  { Relation* oldrelation = ((Relation*)(relationslist->first()));
    Relation* newrelation = ((Relation*)(relationslist->second()));
    Description* olddescription = ((Description*)(dynamic_slot_value(oldrelation, SYM_PROPOSITIONS_DESCRIPTION, NULL)));
    Description* newdescription = ((Description*)(dynamic_slot_value(newrelation, SYM_PROPOSITIONS_DESCRIPTION, NULL)));

    if (olddescription != NULL) {
      retract_relation_axioms(oldrelation);
      if (newdescription != NULL) {
        {
          if (!(!(olddescription == newdescription))) {
            cerr << "Safety violation: " << "INTERNAL ERROR: Redefined relation uses old description.";
          }
          transfer_propositions_to_logic_object(((Description*)(dynamic_slot_value(oldrelation, SYM_PROPOSITIONS_DESCRIPTION, NULL))), ((Description*)(dynamic_slot_value(newrelation, SYM_PROPOSITIONS_DESCRIPTION, NULL))));
          destroy_instance(olddescription);
        }
      }
      else {
        {
          set_dynamic_slot_value(newrelation, SYM_PROPOSITIONS_DESCRIPTION, olddescription, NULL);
          olddescription->native_relation = newrelation;
          finalize_superrelation_links(newrelation);
        }
      }
      set_dynamic_slot_value(oldrelation, SYM_PROPOSITIONS_DESCRIPTION, NULL, NULL);
    }
    { Relation* oldrelation_001 = oldrelation;

      if (classP(oldrelation)) {
        { Class* oldrelation = NULL;

          oldrelation = ((Class*)(oldrelation_001));
          set_dynamic_slot_value(((Class*)(newrelation)), SYM_PROPOSITIONS_CLASS_EXTENSION, ((Class_Extension*)(dynamic_slot_value(oldrelation, SYM_PROPOSITIONS_CLASS_EXTENSION, NULL))), NULL);
          set_dynamic_slot_value(oldrelation, SYM_PROPOSITIONS_CLASS_EXTENSION, NULL, NULL);
        }
      }
      else {
      }
    }
  }
}

void retract_relation_axioms(Relation* oldrelation) {
  { List* originatedpropositions = oldrelation->relation_originated_propositions_reader();

    if (originatedpropositions != NULL) {
      { Proposition* proposition = NULL;
        Cons* iter_001 = originatedpropositions->the_cons_list;

        while (!nilP(iter_001)) {
          {
            proposition = ((Proposition*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          unassert_fact(proposition);
        }
      }
    }
  }
}

Proposition* assert_description_implies_description(Description* sub, Description* super) {
  { Proposition* impliesprop = create_proposition(SYM_PROPOSITIONS_IMPLIES, 2);

    impliesprop->arguments->nth_setter(sub, 0);
    impliesprop->arguments->nth_setter(super, 1);
    impliesprop = fasten_down_proposition(impliesprop);
    assign_truth_value(impliesprop, TRUE);
    return (impliesprop);
  }
}

Proposition* assert_implies_link_between_relations(Relation* sub, Relation* super) {
  { Proposition* impliesprop = assert_description_implies_description(sub->get_description(), super->get_description());

    set_dynamic_slot_value(impliesprop, SYM_PROPOSITIONS_SUBRELATION_LINKp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
    if (null_listP(sub->relation_originated_propositions_reader())) {
      set_dynamic_slot_value(sub, SYM_PROPOSITIONS_RELATION_ORIGINATED_PROPOSITIONS, new_list(), NULL);
    }
    sub->relation_originated_propositions_reader()->push(impliesprop);
    return (impliesprop);
  }
}

void finalize_superrelation_links(Relation* self) {
  { Keyword* old_OevaluationmodeO_001 = oEVALUATIONMODEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oEVALUATIONMODEo = KWD_PROPOSITIONS_EXTENSIONAL_ASSERTION;
          { Module* old_OmoduleO_001 = oMODULEo;
            Context* old_OcontextO_001 = oCONTEXTo;

            { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oMODULEo = ((Module*)(((Description*)(dynamic_slot_value(self, SYM_PROPOSITIONS_DESCRIPTION, NULL)))->home_context));
                  oCONTEXTo = oMODULEo;
                  { Relation* super = NULL;
                    Iterator* iter_001 = self->direct_superrelations();

                    while (iter_001->nextP()) {
                      {
                        super = ((Relation*)(iter_001->value));
                      }
                      super->get_description();
                      assert_implies_link_between_relations(self, super);
                    }
                  }
                  oCONTEXTo = old_OcontextO_001;
                  oMODULEo = old_OmoduleO_001;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oCONTEXTo = old_OcontextO_001;
                oMODULEo = old_OmoduleO_001;
                resignal();
              }
            }
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

Surrogate* verify_logical_and_native_types(Surrogate* logicaltype, Surrogate* nativetype) {
  if ((logicaltype != NULL) &&
      ((nativetype == NULL) ||
       (subtype_ofP(logicaltype, nativetype) &&
        (!(logicaltype == nativetype))))) {
    { Class* renamed_Class = ((Class*)(logicaltype->surrogate_value));

      if (renamed_Class == NULL) {
        return (NULL);
      }
      if (renamed_Class->abstractP) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                cout << "Error in logical expression." << endl;
                cout << "   " << "Illegal creation type: " << logicaltype->symbol_name << endl << "   The creation type of a logic object cannot be abstract." << endl;
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
        return (NULL);
      }
      return (logicaltype);
    }
  }
  else if ((logicaltype == NULL) ||
      ((logicaltype == nativetype) ||
       ((nativetype != NULL) &&
        subtype_ofP(nativetype, logicaltype)))) {
    return (nativetype);
  }
  else {
    { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            cout << "Error in logical expression." << endl;
            cout << "   " << "Creation type error.  Attempt to bind a logic object of type " << logicaltype->symbol_name << endl << "   to a native object of type " << nativetype << endl;
            cout << "   Error occured while parsing the proposition: " << endl;
            cout << "   " << oPROPOSITIONUNDERCONSTRUCTIONo << endl;
            signal(oTHE_PROPOSITION_ERRORo);
            oPRINTREADABLYpo = old_OprintreadablyPO_002;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPRINTREADABLYpo = old_OprintreadablyPO_002;
          resignal();
        }
      }
    }
    return (nativetype);
  }
}

Proposition* update_isa_proposition(Logic_Object* self, Surrogate* type, Keyword* updatemode) {
  if (type == NULL) {
    if (self->root_type == NULL) {
      self->root_type = SGT_PROPOSITIONS_UNKNOWN;
    }
    return (NULL);
  }
  { Cons* isapropositiontree = NULL;
    Proposition* proposition = NULL;

    SGT_PROPOSITIONS_TRAP_DOOR_SURROGATE->surrogate_value = self;
    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            isapropositiontree = listO(4, SYM_PROPOSITIONS_ISA, SGT_PROPOSITIONS_TRAP_DOOR_SURROGATE, type, NIL);
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
    proposition = build_top_level_proposition(isapropositiontree, updatemode);
    isapropositiontree->free_parse_tree();
    return (proposition);
  }
}

Proposition* assert_isa_proposition(Logic_Object* self, Surrogate* type) {
  return (update_isa_proposition(self, type, KWD_PROPOSITIONS_ASSERT_TRUE));
}

void update_property(Logic_Object* instance, Symbol* property, Keyword* updatemode) {
  SGT_PROPOSITIONS_TRAP_DOOR_SURROGATE->surrogate_value = instance;
  { Cons* propositiontree = NULL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            propositiontree = cons(property, cons(SGT_PROPOSITIONS_TRAP_DOOR_SURROGATE, NIL));
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
    build_top_level_proposition(propositiontree, updatemode);
    propositiontree->free_parse_tree();
  }
}

void assert_property(Logic_Object* instance, Symbol* property) {
  update_property(instance, property, KWD_PROPOSITIONS_ASSERT_TRUE);
}

Logic_Object* create_logic_object(Surrogate* type, Surrogate* name, Object* nativevalue) {
  { Logic_Object* object = new_logic_object();
    Surrogate* nativetype = NULL;

    if (nativevalue != NULL) {
      { Logic_Object* object_001 = object;
        Object* value_001 = nativevalue;
        Object* old_value_001 = object_001->variable_value;
        Object* new_value_001 = update_in_context(old_value_001, value_001, object_001, FALSE);

        if (!cs_valueP(old_value_001)) {
          object_001->variable_value = new_value_001;
        }
      }
      nativetype = nativevalue->primary_type();
    }
    type = verify_logical_and_native_types(type, nativetype);
    assert_isa_proposition(object, type);
    if (name != NULL) {
      if (name->surrogate_value != NULL) {
        cout << "Redefining the surrogate " << name->symbol_name << " will cause the existing" << endl << "   object named " << name->symbol_name << " to be destroyed. ";
        if (!y_or_nP("Do it? ")) {
          cout << "Returning existing object:" << endl;
          return (((Logic_Object*)(name->surrogate_value)));
        }
        destroy_instance(((Logic_Object*)(name->surrogate_value)));
      }
      name->surrogate_value = object;
      set_dynamic_slot_value(object, SYM_PROPOSITIONS_SURROGATE_VALUE_INVERSE, name, NULL);
    }
    return (object);
  }
}

Object* read_OpropositionunderconstructionO() {
  return (oPROPOSITIONUNDERCONSTRUCTIONo);
}

Object* write_OpropositionunderconstructionO(Object* value) {
  oPROPOSITIONUNDERCONSTRUCTIONo = value;
  return (value);
}

Cons* read_OtoplevelpropositionsO() {
  return (oTOPLEVELPROPOSITIONSo);
}

Cons* write_OtoplevelpropositionsO(Cons* value) {
  oTOPLEVELPROPOSITIONSo = value;
  return (value);
}

Proposition* build_top_level_proposition(Object* tree, Keyword* updatemode) {
  if (isaP(tree, SGT_PROPOSITIONS_STRING_WRAPPER)) {
    return (build_top_level_proposition(unstringify(((String_Wrapper*)(tree))->wrapper_value), updatemode));
  }
  { Proposition* proposition = NULL;
    Cons* logicvariabletable = oLOGICVARIABLETABLEo;

    { Cons* old_OlogicvariabletableO_001 = oLOGICVARIABLETABLEo;
      Object* old_OpropositionunderconstructionO_001 = oPROPOSITIONUNDERCONSTRUCTIONo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oLOGICVARIABLETABLEo = ((logicvariabletable != NULL) ? ((Cons*)(logicvariabletable)) : ((Cons*)(NIL)));
            oPROPOSITIONUNDERCONSTRUCTIONo = tree;
            {
              { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;
                boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                oPENDINGEXCEPTIONHANDLERpo = TRUE;
                if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  proposition = build_proposition(tree, updatemode);
                  oEXCEPTIONo = NULL;
                }
                oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
              }
              if (oEXCEPTIONo != NULL) {
                if (subtype_ofP(oEXCEPTION_TYPEo, SGT_PROPOSITIONS_LOGIC_EXCEPTION)) {
                  { Logic_Exception* e = ((Logic_Exception*)(oEXCEPTIONo));

                    if ((oTRACED_KEYWORDSo != NULL) &&
                        oTRACED_KEYWORDSo->memberP(KWD_PROPOSITIONS_EXCEPTIONS)) {
                      cout << "build-top-level-proposition: Caught " << e->primary_type() << endl;
                    }
                    if (oEVALUATIONMODEo == KWD_PROPOSITIONS_QUERY) {
                      signal(e);
                    }
                  }
                }
                else if (subtype_ofP(oEXCEPTION_TYPEo, SGT_PROPOSITIONS_READ_EXCEPTION)) {
                  if ((oTRACED_KEYWORDSo != NULL) &&
                      oTRACED_KEYWORDSo->memberP(KWD_PROPOSITIONS_EXCEPTIONS)) {
                    cout << "build-top-level-proposition: Caught READ-EXCEPTION" << endl;
                  }
                }
                else if (TRUE) {
                  { Exception* e = oEXCEPTIONo;

                    cerr << "build-top-level-proposition: Caught " << "`" << e->primary_type() << "'" << endl;
                  }
                }
              }
            }
            if (!(logicvariabletable != NULL)) {
              free_cons_list(oLOGICVARIABLETABLEo);
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
    if (!(proposition == NULL)) {
      update_proposition_truth_value(proposition, updatemode);
      if (oTOPLEVELPROPOSITIONSo != NULL) {
        oTOPLEVELPROPOSITIONSo = cons(proposition, oTOPLEVELPROPOSITIONSo);
      }
    }
    return (proposition);
  }
}

Proposition* fasten_down_proposition(Proposition* self) {
  { Proposition* duplicate = find_duplicate_proposition(self);

    if (duplicate != NULL) {
      {
        if (!(self == duplicate)) {
          self->free();
        }
        return (duplicate);
      }
    }
    else {
      {
        if (!description_modeP()) {
          log_newly_conceived_proposition(oMODULEo, self);
        }
        { Object* arg = NULL;
          Vector* vector_001 = self->arguments;
          int index_001 = 0;
          int length_001 = vector_001->length();

          while (index_001 < length_001) {
            {
              arg = vector_001->nth(index_001);
              index_001 = index_001 + 1;
            }
            add_dependent_proposition_link(arg, self);
          }
        }
        oCONTEXTo->react_to_kb_update(self);
        return (self);
      }
    }
  }
}

Proposition* build_proposition(Object* tree, Keyword* updatemode) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        return (consDbuild_proposition(tree, updatemode));
      }
    }
    else if (surrogateP(tree)) {
      { Surrogate* tree = NULL;

        tree = ((Surrogate*)(tree_001));
        return (surrogateDbuild_proposition(tree, updatemode));
      }
    }
    else if (symbolP(tree)) {
      { Symbol* tree = NULL;

        tree = ((Symbol*)(tree_001));
        return (symbolDbuild_proposition(tree, updatemode));
      }
    }
    else {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              cout << "Error in logical expression." << endl;
              cout << "   " << "Illegal logical sentence: " << tree << endl;
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
  }
}

Proposition* surrogateDbuild_proposition(Surrogate* self, Keyword* updatemode) {
  { Object* value = self->surrogate_value;
    Proposition* proposition = NULL;

    if (value == BOTTOM) {
      value = NULL;
      self->surrogate_value = NULL;
    }
    if (updatemode == NULL) {
      updatemode = KWD_PROPOSITIONS_CONCEIVE;
    }
    if (value != NULL) {
      { Object* value_001 = value;

        if (taxonomy_isaP(value, SGT_PROPOSITIONS_PROPOSITION)) {
          { Proposition* value = NULL;

            value = ((Proposition*)(value_001));
            proposition = value;
          }
        }
        else {
          { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  cout << "Error in logical expression." << endl;
                  cout << "   " << "Expected " << self->symbol_name << " to have type proposition" << endl;
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
      }
    }
    else {
      if ((updatemode == KWD_PROPOSITIONS_ASSERT_TRUE) ||
          (updatemode == KWD_PROPOSITIONS_CONCEIVE)) {
        proposition = create_proposition(SYM_PROPOSITIONS_CONSTANT, 0);
        proposition->renamed_Operator = self;
        self->surrogate_value = proposition;
        set_dynamic_slot_value(proposition, SYM_PROPOSITIONS_SURROGATE_VALUE_INVERSE, self, NULL);
      }
      else {
        { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                cout << "Error in logical expression." << endl;
                cout << "   " << "Reference to undefined constant " << self->symbol_name << endl;
                cout << "   Error occured while parsing the proposition: " << endl;
                cout << "   " << oPROPOSITIONUNDERCONSTRUCTIONo << endl;
                signal(oTHE_PROPOSITION_ERRORo);
                oPRINTREADABLYpo = old_OprintreadablyPO_002;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_002;
              resignal();
            }
          }
        }
      }
    }
    return (fasten_down_proposition(proposition));
  }
}

Proposition* symbolDbuild_proposition(Symbol* symbol, Keyword* updatemode) {
  { Proposition* proposition = NULL;

    if (symbol == SYM_PROPOSITIONS_TRUE) {
      if (updatemode == KWD_PROPOSITIONS_ASSERT_FALSE) {
        signal_truth_value_clash(TRUE_PROPOSITION);
      }
      else {
        proposition = TRUE_PROPOSITION;
      }
    }
    else if (symbol == SYM_PROPOSITIONS_FALSE) {
      if (updatemode == KWD_PROPOSITIONS_ASSERT_TRUE) {
        signal_truth_value_clash(FALSE_PROPOSITION);
      }
      else {
        proposition = FALSE_PROPOSITION;
      }
    }
    else {
    }
    if (!(proposition == NULL)) {
      if (oTOPLEVELPROPOSITIONSo != NULL) {
        oTOPLEVELPROPOSITIONSo = cons(proposition, oTOPLEVELPROPOSITIONSo);
      }
    }
    return (proposition);
  }
}

Proposition* consDbuild_proposition(Cons* tree, Keyword* updatemode) {
  { Proposition* proposition = NULL;

    if (!isaP(tree->first(), SGT_PROPOSITIONS_SYMBOL)) {
      cerr << "Safety violation: " << "INTERNAL ERROR: Illegal operator in proposition tree.";
    }
    { Object* test_value_001 = tree->first();

      if (test_value_001 == SYM_PROPOSITIONS_e) {
        proposition = build_equivalence_proposition(tree, updatemode);
      }
      else if ((test_value_001 == SYM_PROPOSITIONS_AND) ||
          ((test_value_001 == SYM_PROPOSITIONS_OR) ||
           (test_value_001 == SYM_PROPOSITIONS_NOT))) {
        proposition = build_and_or_not_proposition(tree, updatemode);
      }
      else if ((test_value_001 == SYM_PROPOSITIONS_IN) ||
          (test_value_001 == SYM_PROPOSITIONS_ISA)) {
        proposition = build_in_proposition(tree, updatemode);
      }
      else if ((test_value_001 == SYM_PROPOSITIONS_IMPLIES) ||
          (test_value_001 == SYM_PROPOSITIONS_SUBSET_OF)) {
        proposition = build_implies_proposition(tree, updatemode);
      }
      else if (test_value_001 == SYM_PROPOSITIONS_EXISTS) {
        proposition = build_exists_proposition(tree, updatemode);
      }
      else if (test_value_001 == SYM_PROPOSITIONS_FORALL) {
        proposition = build_forall_proposition(tree, updatemode);
      }
      else {
        proposition = build_predicate_proposition(tree);
      }
    }
    if (proposition == NULL) {
      return (NULL);
    }
    if (descriptive_updateP(updatemode) &&
        contains_nested_argumentP(proposition)) {
      proposition = fasten_down_proposition(proposition);
      proposition = flatten_nested_function_arguments(proposition);
    }
    return (fasten_down_proposition(proposition));
  }
}

void verify_collection_argument(Object* self, Object* original) {
  if (original == NULL) {
    original = self;
  }
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        if (!subtype_ofP(logical_type(self), SGT_PROPOSITIONS_COLLECTION)) {
          if (bottomP(self)) {
            { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    cout << "Error in logical expression." << endl;
                    cout << "   " << "The object " << original << " is undefined." << endl;
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
          else {
            { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    cerr << "The object " << "`" << original << "'" << " is not a collection.";
                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_002;
                  resignal();
                }
              }
            }
          }
        }
      }
    }
    else if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        if (!isaP(self->surrogate_value, SGT_PROPOSITIONS_RELATION)) {
          verify_collection_argument(self->value_of(), self);
        }
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_COLLECTION)) {
      { Collection* self = NULL;

        self = ((Collection*)(self_001));
      }
    }
    else {
      { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              cerr << "The object" << "`" << original << "'" << " is not a collection.";
              oPRINTREADABLYpo = old_OprintreadablyPO_003;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_003;
            resignal();
          }
        }
      }
    }
  }
}

void verify_relation_argument(Object* self) {
  { Object* self_001 = self;

    if (classP(self)) {
      { Class* self = NULL;

        self = ((Class*)(self_001));
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_RELATION)) {
      { Relation* self = NULL;

        self = ((Relation*)(self_001));
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_DESCRIPTION)) {
      { Description* self = NULL;

        self = ((Description*)(self_001));
      }
    }
    else if (taxonomy_isaP(self, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        if (!(subtype_ofP(logical_type(self), SGT_PROPOSITIONS_RELATION) ||
            subtype_ofP(logical_type(self), SGT_PROPOSITIONS_DESCRIPTION))) {
          { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  cerr << "The object " << "`" << self << "'" << " is not a relation.";
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
      }
    }
    else {
      { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              cerr << "The object" << "`" << self << "'" << " is not a relation.";
              oPRINTREADABLYpo = old_OprintreadablyPO_002;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_002;
            resignal();
          }
        }
      }
    }
  }
}

void verify_number_of_proposition_arguments(Cons* tree, int correctnumber) {
  if (!(tree->length() == (correctnumber + 1))) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            cout << "Error in logical expression." << endl;
            cout << "   " << "Wrong number of arguments in proposition: " << tree << endl;
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
}

Proposition* build_in_proposition(Cons* tree, Keyword* updatemode) {
  verify_number_of_proposition_arguments(tree, 2);
  if (tree->first() == SYM_PROPOSITIONS_ISA) {
    { Object* symbol = tree->third();

      { Object* symbol_001 = symbol;

        if (typeP(symbol)) {
          { Surrogate* symbol = NULL;

            symbol = ((Surrogate*)(symbol_001));
            if (symbol->get_class(FALSE) == NULL) {
              { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      cout << "Error in logical expression." << endl;
                      cout << "   " << "No class is associated with the symbol " << symbol << endl;
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
          }
        }
        else if (symbolP(symbol)) {
          { Symbol* symbol = NULL;

            symbol = ((Symbol*)(symbol_001));
            if (symbol->get_class(FALSE) == NULL) {
              { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      cout << "Error in logical expression." << endl;
                      cout << "   " << "No class is associated with the symbol " << symbol << endl;
                      cout << "   Error occured while parsing the proposition: " << endl;
                      cout << "   " << oPROPOSITIONUNDERCONSTRUCTIONo << endl;
                      signal(oTHE_PROPOSITION_ERRORo);
                      oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    resignal();
                  }
                }
              }
            }
          }
        }
        else {
          { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  cout << "Error in logical expression." << endl;
                  cout << "   " << "Illegal token where symbol expected: " << symbol << endl;
                  cout << "   Error occured while parsing the proposition: " << endl;
                  cout << "   " << oPROPOSITIONUNDERCONSTRUCTIONo << endl;
                  signal(oTHE_PROPOSITION_ERRORo);
                  oPRINTREADABLYpo = old_OprintreadablyPO_003;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oPRINTREADABLYpo = old_OprintreadablyPO_003;
                resignal();
              }
            }
          }
          return (NULL);
        }
      }
      tree->first_setter(SYM_PROPOSITIONS_IN);
      tree->third_setter(symbol->surrogatify());
    }
  }
  { Proposition* proposition = create_proposition(SYM_PROPOSITIONS_IN, 2);
    Vector* argumentsvector = proposition->arguments;
    Object* individual = evaluate_term(tree->second());
    Object* collection = evaluate_term(tree->third());

    verify_collection_argument(collection, NULL);
    argumentsvector->nth_setter(individual, 0);
    argumentsvector->nth_setter(collection, 1);
    { Object* collection_001 = collection;

      if (taxonomy_isaP(collection, SGT_PROPOSITIONS_DESCRIPTION)) {
        { Description* collection = NULL;

          collection = ((Description*)(collection_001));
          if (collection->description_surrogate() != NULL) {
            argumentsvector->nth_setter(collection->description_surrogate(), 1);
          }
        }
      }
      else {
      }
    }
    if (!isaP(individual, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
      return (proposition);
    }
    if (updatemode == NULL) {
      update_root_types(((Logic_Object*)(individual)), member_type_from_collection(collection));
      return (proposition);
    }
    if ((updatemode == KWD_PROPOSITIONS_ASSERT_TRUE) ||
        (updatemode == KWD_PROPOSITIONS_CONCEIVE)) {
      update_root_types(((Logic_Object*)(individual)), member_type_from_collection(collection));
    }
    else {
    }
    return (proposition);
  }
}

Proposition* embed_negation_within_function_induced_exists(Proposition* existsproposition) {
  { Proposition* andprop = ((Proposition*)(existsproposition->arguments->first()));
    Vector* andarguments = andprop->arguments;

    { Object* value_001 = NULL;

      { Object* arg = NULL;
        Vector* vector_001 = andarguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            arg = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          if (!(((Proposition*)(arg))->kind == KWD_PROPOSITIONS_FUNCTION)) {
            value_001 = arg;
            break;
          }
        }
      }
      { Object* predicateprop = value_001;

        { boolean test_value_001 = FALSE;

          test_value_001 = andarguments->length() == 2;
          if (test_value_001) {
            { boolean foundP_001 = FALSE;

              { Object* arg = NULL;
                Vector* vector_002 = andarguments;
                int index_002 = 0;
                int length_002 = vector_002->length();

                while (index_002 < length_002) {
                  {
                    arg = vector_002->nth(index_002);
                    index_002 = index_002 + 1;
                  }
                  if (((Proposition*)(arg))->kind == KWD_PROPOSITIONS_FUNCTION) {
                    foundP_001 = TRUE;
                    break;
                  }
                }
              }
              test_value_001 = foundP_001;
            }
          }
          test_value_001 = !test_value_001;
          if (test_value_001) {
            cerr << "Safety violation: " << "INTERNAL ERROR: `embed-negation-within-function-induced-exists' " << "called with wrong kind of proposition.";
          }
        }
        invert_proposition(((Proposition*)(predicateprop)));
        return (existsproposition);
      }
    }
  }
}

Proposition* build_and_or_not_proposition(Cons* tree, Keyword* updatemode) {
  { Proposition* term = NULL;
    Cons* arguments = NIL;
    Proposition* proposition = NULL;
    Vector* argumentsvector = NULL;

    if (!(conceiving_updateP(updatemode) ||
        (description_modeP() ||
         ((tree->first() == SYM_PROPOSITIONS_OR) ||
          ((tree->first() == SYM_PROPOSITIONS_AND) &&
           ((updatemode == KWD_PROPOSITIONS_ASSERT_FALSE) ||
            (updatemode == KWD_PROPOSITIONS_RETRACT_FALSE))))))) {
      cerr << "Safety violation: " << "INTERNAL ERROR: `build-and-or-not-proposition' called with " << "update mode " << "`" << updatemode << "'" << " which is illegal for " << "`" << tree << "'" << ".";
    }
    updatemode = NULL;
    { Object* arg = NULL;
      Cons* iter_001 = tree->rest;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          arg = iter_001->value;
          iter_001 = iter_001->rest;
        }
        { 
          term = build_proposition(arg, updatemode);
          if (term != NULL) {
            if (collect_001 == NULL) {
              {
                collect_001 = cons(term, NIL);
                if (nilP(arguments)) {
                  arguments = collect_001;
                }
                else {
                  add_cons_to_end_of_cons_list(arguments, collect_001);
                }
              }
            }
            else {
              {
                collect_001->rest = cons(term, NIL);
                collect_001 = collect_001->rest;
              }
            }
          }
        }
      }
    }
    if (arguments->emptyP()) {
      return (NULL);
    }
    if ((tree->first() == SYM_PROPOSITIONS_NOT) &&
        (((Proposition*)(arguments->first()))->kind == KWD_PROPOSITIONS_EXISTS)) {
      return (embed_negation_within_function_induced_exists(((Proposition*)(arguments->first()))));
    }
    proposition = create_proposition(((Symbol*)(tree->first())), arguments->length());
    argumentsvector = proposition->arguments;
    { int i = NULL_INTEGER;
      Object* arg = NULL;
      Cons* iter_002 = arguments;
      int iter_003 = 0;

      while (!nilP(iter_002)) {
        {
          arg = iter_002->value;
          iter_002 = iter_002->rest;
        }
        {
          i = iter_003;
          iter_003 = iter_003 + 1;
        }
        argumentsvector->nth_setter(arg, i);
      }
    }
    free_cons_list(arguments);
    return (proposition);
  }
}

boolean functional_termP(Object* term) {
  { Object* term_001 = term;

    if (consP(term)) {
      { Cons* term = NULL;

        term = ((Cons*)(term_001));
        { Object* test_value_001 = term->first();

          if ((test_value_001 == SYM_PROPOSITIONS_SETOFALL) ||
              ((test_value_001 == SYM_PROPOSITIONS_THE_ONLY) ||
               ((test_value_001 == SYM_PROPOSITIONS_SETOF) ||
                ((test_value_001 == SYM_PROPOSITIONS_LISTOF) ||
                 (test_value_001 == SYM_PROPOSITIONS_KAPPA))))) {
            return (FALSE);
          }
          else {
            return (TRUE);
          }
        }
      }
    }
    else {
      return (FALSE);
    }
  }
}

boolean clip_valueP(Object* term1, Object* term2) {
  { Object* term1_001 = term1;

    if (taxonomy_isaP(term1, SGT_PROPOSITIONS_SKOLEM)) {
      { Skolem* term1 = NULL;

        term1 = ((Skolem*)(term1_001));
        { Object* value1 = term1->value_of();

          if (eqlP(value1, term2)) {
            return (TRUE);
          }
          if ((!skolemP(value1)) &&
              ((term1->defining_proposition != NULL) &&
               oCLIPPING_ENABLEDo)) {
            unbind_skolem_value(term1, TRUE);
            bind_skolem_to_value(term1, term2->value_of(), TRUE);
            return (TRUE);
          }
        }
      }
    }
    else {
    }
  }
  return (FALSE);
}

Proposition* finish_building_equivalence_proposition(Object* term1, Object* term2) {
  { Proposition* proposition = create_proposition(SYM_PROPOSITIONS_EQUIVALENT, 2);
    Vector* argumentsvector = proposition->arguments;

    argumentsvector->nth_setter(term1, 0);
    argumentsvector->nth_setter(term2, 1);
    return (proposition);
  }
}

Proposition* substitute_function_for_equivalence(Pattern_Variable* functionvariable, Object* term) {
  { Proposition* proposition = functionvariable->defining_proposition;

    remove_dependent_proposition_link(functionvariable, proposition);
    functionvariable->free();
    proposition->arguments->last_setter(term);
    add_dependent_proposition_link(term, proposition);
    return (proposition);
  }
}

Proposition* build_equivalence_proposition(Cons* tree, Keyword* updatemode) {
  if (tree->length() > 3) {
    return (build_conjunction_of_equality_propositions(tree, updatemode));
  }
  { Object* term1 = evaluate_term(tree->second());
    Object* term2 = evaluate_term(tree->third());

    if (eqlP(term1, term2)) {
      return (NULL);
    }
    if (function_output_variableP(term1) &&
        (!function_output_variableP(term2))) {
      return (substitute_function_for_equivalence(((Pattern_Variable*)(term1)), term2));
    }
    if (function_output_variableP(term2) &&
        (!function_output_variableP(term1))) {
      return (substitute_function_for_equivalence(((Pattern_Variable*)(term2)), term1));
    }
    if (descriptive_updateP(updatemode) ||
        (skolemP(term1) &&
         skolemP(term2))) {
      return (finish_building_equivalence_proposition(term1, term2));
    }
    if (updatemode == KWD_PROPOSITIONS_ASSERT_TRUE) {
      if (!(clip_valueP(term1, term2) ||
          clip_valueP(term2, term1))) {
        equate_values(term1->value_of(), term2->value_of());
      }
      if (function_output_skolemP(term1) &&
          (!function_output_skolemP(term2))) {
        return (((Skolem*)(term1))->defining_proposition);
      }
      if (function_output_skolemP(term2) &&
          (!function_output_skolemP(term1))) {
        return (((Skolem*)(term2))->defining_proposition);
      }
    }
    else if (updatemode == KWD_PROPOSITIONS_RETRACT_TRUE) {
      if (unequate_valuesP(term1, term2) ||
          unequate_valuesP(term2, term1)) {
      }
    }
    else {
      return (finish_building_equivalence_proposition(term1, term2));
    }
    return (NULL);
  }
}

Proposition* build_conjunction_of_equality_propositions(Cons* tree, Keyword* updatemode) {
  {
    tree = tree;
    updatemode = updatemode;
  }
  cerr << "build-conjunction-of-equality-propositions: Write me, I am a dummy!";
  return (NULL);
}

Skolem* verify_second_order_variable(Skolem* variable, Keyword* kind) {
  if (kind == KWD_PROPOSITIONS_PREDICATE) {
    variable->root_type = SGT_PROPOSITIONS_RELATION;
  }
  else if (kind == KWD_PROPOSITIONS_FUNCTION) {
    variable->root_type = SGT_PROPOSITIONS_FUNCTION;
  }
  else {
    cerr << "`" << kind << "'" << " is not a valid case option";
  }
  return (variable);
}

Proposition* build_predicate_proposition(Cons* tree) {
  { int argcount = tree->rest->length();
    Object* variablepredicate = lookup_logic_variable_binding(((Symbol*)(tree->first())));
    boolean secondorderP = variablepredicate != NULL;
    Proposition* proposition = create_proposition((secondorderP ? ((Symbol*)(SYM_PROPOSITIONS_SECOND_ORDER)) : ((Symbol*)(SYM_PROPOSITIONS_PREDICATE))), argcount);
    Vector* argumentsvector = proposition->arguments;
    Object* firstarg = tree->second();

    if (secondorderP) {
      {
        proposition->renamed_Operator = verify_second_order_variable(((Skolem*)(variablepredicate)), KWD_PROPOSITIONS_PREDICATE);
        { int i = NULL_INTEGER;
          Object* arg = NULL;
          Cons* iter_001 = tree->rest;
          int iter_002 = 0;

          while (!nilP(iter_001)) {
            {
              arg = iter_001->value;
              iter_001 = iter_001->rest;
            }
            {
              i = iter_002;
              iter_002 = iter_002 + 1;
            }
            argumentsvector->nth_setter(evaluate_term(arg), i);
          }
        }
      }
    }
    else {
      { Method_Slot* slot = ((Symbol*)(tree->first()))->lookup_function();
        Surrogate* slotref = ((slot != NULL) ? ((Surrogate*)(lookup_slotref(SGT_PROPOSITIONS_ANY, slot->slot_name))) : ((Surrogate*)(NULL)));
        Object* firstargument = (((slotref != NULL) &&
            (slot_column_types(((Slot*)(slotref->surrogate_value)))->pop() == SGT_PROPOSITIONS_PROPOSITION)) ? ((Object*)(build_proposition(firstarg, KWD_PROPOSITIONS_CONCEIVE))) : ((Object*)(evaluate_term(firstarg))));

        argumentsvector->nth_setter(firstargument, 0);
        if (firstargument->value_of() == BOTTOM) {
          signal_undefined_term(firstargument);
        }
        if (slotref == NULL) {
          slotref = lookup_slotref_on_instance(firstargument->value_of(), ((Symbol*)(tree->first())));
        }
        if (slotref == NULL) {
          proposition->free();
          signal_undefined_term(tree);
        }
        if (!((slotref_type(slotref) == SGT_PROPOSITIONS_BOOLEAN) ||
            (slotref_type(slotref) == SGT_PROPOSITIONS_BOOLEAN_WRAPPER))) {
          proposition->free();
          { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  cout << "Error in logical expression." << endl;
                  cout << "   " << "Function term encountered where predicate expected: " << endl << "   " << tree << endl;
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
        proposition->renamed_Operator = slotref;
        { Surrogate* type = NULL;
          int i = NULL_INTEGER;
          Object* arg = NULL;
          Cons* iter_003 = tree->rest->rest;
          int iter_004 = 1;
          Iterator* iter_005 = slot_column_types(((Slot*)(slotref->surrogate_value)))->advance(1);

          while ((!nilP(iter_003)) &&
              iter_005->nextP()) {
            {
              arg = iter_003->value;
              iter_003 = iter_003->rest;
            }
            {
              i = iter_004;
              iter_004 = iter_004 + 1;
            }
            {
              type = ((Surrogate*)(iter_005->value));
            }
            if (type == SGT_PROPOSITIONS_PROPOSITION) {
              argumentsvector->nth_setter(build_proposition(arg, KWD_PROPOSITIONS_CONCEIVE), i);
            }
            else {
              argumentsvector->nth_setter(evaluate_term(arg), i);
            }
          }
        }
      }
    }
    return (proposition);
  }
}

Proposition* build_exists_proposition(Cons* tree, Keyword* updatemode) {
  { boolean descriptiveP = descriptive_updateP(updatemode);

    if (descriptiveP) {
      updatemode = KWD_PROPOSITIONS_CONCEIVE;
    }
    { Cons* variables = NULL;
      Proposition* proposition = NULL;
      Proposition* unused = NULL;

      variables = build_quantified_proposition(tree, updatemode, proposition, unused);
      unused = unused;
      if (descriptiveP) {
        { Proposition* existsprop = create_proposition(SYM_PROPOSITIONS_EXISTS, 1);

          existsprop->kind = KWD_PROPOSITIONS_EXISTS;
          existsprop->arguments->nth_setter(proposition, 0);
          set_dynamic_slot_value(existsprop, SYM_PROPOSITIONS_IO_VARIABLES, copy_cons_list_to_variables_vector(variables), NULL);
          free_cons_list(variables);
          return (existsprop);
        }
      }
      else {
        {
          free_cons_list(variables);
          return (proposition);
        }
      }
    }
  }
}

boolean top_level_exists_propositionP(Proposition* proposition) {
  return ((!unknownP(proposition)) &&
      help_collect_skolemized_exists_variablesP(proposition, NULL));
}

Vector* collect_skolemized_exists_variables(Proposition* proposition) {
  { List* skolems = new_list();
    Vector* result = NULL;

    help_collect_skolemized_exists_variablesP(proposition, skolems);
    if (skolems->emptyP()) {
      result = ZERO_VARIABLES_VECTOR;
    }
    else {
      result = new_vector(skolems->length());
    }
    { int i = NULL_INTEGER;
      Skolem* skolem = NULL;
      Cons* iter_001 = skolems->the_cons_list;
      int iter_002 = 0;

      while (!nilP(iter_001)) {
        {
          skolem = ((Skolem*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        {
          i = iter_002;
          iter_002 = iter_002 + 1;
        }
        result->nth_setter(skolem, i);
      }
    }
    skolems->free();
    return (result);
  }
}

boolean help_collect_skolemized_exists_variablesP(Proposition* proposition, List* result) {
  { Vector* arguments = proposition->arguments;
    int argumentcount = arguments->length();

    if (proposition->kind == KWD_PROPOSITIONS_FUNCTION) {
      argumentcount = argumentcount - 1;
    }
    { int i = NULL_INTEGER;
      Object* arg = NULL;
      Vector* vector_001 = arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();
      int iter_001 = 1;
      int upper_bound_001 = argumentcount;
      boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

      while ((index_001 < length_001) &&
          (unboundedP_001 ||
           (iter_001 <= upper_bound_001))) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        i = i;
        { Object* arg_001 = arg;

          if (taxonomy_isaP(arg, SGT_PROPOSITIONS_PROPOSITION)) {
            { Proposition* arg = NULL;

              arg = ((Proposition*)(arg_001));
              if (help_collect_skolemized_exists_variablesP(arg, result) &&
                  (result == NULL)) {
                return (TRUE);
              }
            }
          }
          else if (taxonomy_isaP(arg, SGT_PROPOSITIONS_PATTERN_VARIABLE)) {
            { Pattern_Variable* arg = NULL;

              arg = ((Pattern_Variable*)(arg_001));
            }
          }
          else if (taxonomy_isaP(arg, SGT_PROPOSITIONS_SKOLEM)) {
            { Skolem* arg = NULL;

              arg = ((Skolem*)(arg_001));
              { boolean foundP_001 = FALSE;

                { Proposition* prop = NULL;
                  Cons* iter_002 = arg->dependent_propositions->the_cons_list;

                  while (!nilP(iter_002)) {
                    {
                      prop = ((Proposition*)(iter_002->value));
                      iter_002 = iter_002->rest;
                    }
                    if (trueP(prop) &&
                        prop->variable_typeP_reader()) {
                      foundP_001 = TRUE;
                      break;
                    }
                  }
                }
                if (foundP_001) {
                  if (result != NULL) {
                    result->insert_new(arg);
                  }
                  else {
                    return (TRUE);
                  }
                }
              }
            }
          }
          else {
          }
        }
      }
    }
    if (result != NULL) {
      return (result->non_emptyP());
    }
    else {
      return (FALSE);
    }
  }
}

Proposition* build_forall_proposition(Cons* tree, Keyword* updatemode) {
  { Proposition* forallprop = create_proposition(SYM_PROPOSITIONS_FORALL, 2);

    { Keyword* old_OevaluationmodeO_001 = oEVALUATIONMODEo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oEVALUATIONMODEo = KWD_PROPOSITIONS_QUERY;
            { Cons* variables = NULL;
              Proposition* whereproposition = NULL;
              Proposition* alwaysproposition = NULL;

              variables = build_quantified_proposition(tree, KWD_PROPOSITIONS_CONCEIVE, whereproposition, alwaysproposition);
              forallprop->kind = KWD_PROPOSITIONS_FORALL;
              set_dynamic_slot_value(forallprop, SYM_PROPOSITIONS_IO_VARIABLES, copy_cons_list_to_variables_vector(variables), NULL);
              free_cons_list(variables);
              forallprop->arguments->nth_setter(((whereproposition != NULL) ? ((Proposition*)(whereproposition)) : ((Proposition*)(TRUE_PROPOSITION))), 0);
              forallprop->arguments->nth_setter(alwaysproposition, 1);
              normalize_forall_proposition(forallprop);
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
    return (derive_implies_propositions(forallprop, updatemode));
  }
}

void verify_implies_argument(Object* self, Symbol* renamed_Operator) {
  if (renamed_Operator == SYM_PROPOSITIONS_SUBSET_OF) {
    verify_collection_argument(self, NULL);
  }
  else if (renamed_Operator == SYM_PROPOSITIONS_IMPLIES) {
    verify_relation_argument(self);
  }
  else {
    cerr << "`" << renamed_Operator << "'" << " is not a valid case option";
  }
}

Proposition* build_implies_proposition(Cons* tree, Keyword* updatemode) {
  updatemode = updatemode;
  verify_number_of_proposition_arguments(tree, 2);
  { Object* tailarg = evaluate_term(tree->second());
    Object* headarg = evaluate_term(tree->third());

    verify_implies_argument(headarg, ((Symbol*)(tree->first())));
    verify_implies_argument(tailarg, ((Symbol*)(tree->first())));
    return (finish_building_implies_proposition(headarg, tailarg, NULL, TRUE));
  }
}

Proposition* find_duplicate_function_proposition(Surrogate* slotref, Cons* arguments) {
  { Logic_Object* logicobjargument = NULL;

    { Object* arg = NULL;
      Cons* iter_001 = arguments;

      while (!nilP(iter_001)) {
        {
          arg = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if (isaP(arg, SGT_PROPOSITIONS_LOGIC_OBJECT)) {
          logicobjargument = ((Logic_Object*)(arg));
          break;
        }
      }
    }
    if (logicobjargument == NULL) {
      return (NULL);
    }
    else if ((logicobjargument == arguments->first()) &&
        arguments->rest->emptyP()) {
      { Proposition* value_001 = NULL;

        { Proposition* prop = NULL;
          Cons* iter_002 = logicobjargument->dependent_attribute_propositions->the_cons_list;

          while (!nilP(iter_002)) {
            {
              prop = ((Proposition*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            if (prop->renamed_Operator == slotref) {
              value_001 = prop;
              break;
            }
          }
        }
        { Proposition* value_002 = value_001;

          return (value_002);
        }
      }
    }
    else {
      { Proposition* p = NULL;
        Cons* iter_003 = logicobjargument->dependent_propositions->the_cons_list;

        while (!nilP(iter_003)) {
          {
            p = ((Proposition*)(iter_003->value));
            iter_003 = iter_003->rest;
          }
          { Keyword* test_value_001 = p->kind;

            if (test_value_001 == KWD_PROPOSITIONS_FUNCTION) {
              { boolean test_value_002 = FALSE;

                test_value_002 = p->renamed_Operator == slotref;
                if (test_value_002) {
                  { boolean alwaysP_001 = TRUE;

                    { Object* arg2 = NULL;
                      Object* arg1 = NULL;
                      Vector* vector_001 = p->arguments;
                      int index_001 = 0;
                      int length_001 = vector_001->length();
                      Cons* iter_004 = arguments;

                      while ((index_001 < length_001) &&
                          (!nilP(iter_004))) {
                        {
                          arg1 = vector_001->nth(index_001);
                          index_001 = index_001 + 1;
                        }
                        {
                          arg2 = iter_004->value;
                          iter_004 = iter_004->rest;
                        }
                        if (!eqlP(arg1, arg2)) {
                          alwaysP_001 = FALSE;
                          break;
                        }
                      }
                    }
                    test_value_002 = alwaysP_001;
                  }
                  if (test_value_002) {
                    test_value_002 = arguments->length() == p->arguments->length();
                  }
                }
                if (test_value_002) {
                  return (p);
                }
              }
            }
            else {
            }
          }
        }
      }
    }
    return (NULL);
  }
}

Proposition* create_function_proposition(Surrogate* slotref, Cons* inputarguments) {
  { int argcount = inputarguments->length() + 1;
    Proposition* proposition = create_proposition(SYM_PROPOSITIONS_FUNCTION, argcount);
    Vector* argumentsvector = proposition->arguments;
    Slot* slot = ((Slot*)(slotref->surrogate_value));
    Surrogate* type = slot->slot_base_type;
    Skolem* skolem = NULL;

    if ((type != NULL) &&
        subtype_ofP(type, SGT_PROPOSITIONS_LITERAL_WRAPPER)) {
      type = wrapped_type_to_type(type);
    }
    skolem = (description_modeP() ? ((Skolem*)(create_variable(type, NULL, FALSE))) : ((Skolem*)(create_skolem(type, NULL))));
    update_root_types(skolem, type);
    proposition->renamed_Operator = slotref;
    { int i = NULL_INTEGER;
      Object* arg = NULL;
      Cons* iter_001 = inputarguments;
      int iter_002 = 0;

      while (!nilP(iter_001)) {
        {
          arg = iter_001->value;
          iter_001 = iter_001->rest;
        }
        {
          i = iter_002;
          iter_002 = iter_002 + 1;
        }
        argumentsvector->nth_setter(arg, i);
      }
    }
    argumentsvector->nth_setter(skolem, argcount - 1);
    skolem->defining_proposition = proposition;
    fasten_down_proposition(proposition);
    { Object* term = NULL;
      Vector* vector_001 = argumentsvector;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          term = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        add_dependent_proposition_link(term, proposition);
      }
    }
    return (proposition);
  }
}

Proposition* create_second_order_function_proposition(Object* variablefunction, Cons* inputarguments) {
  { int argcount = inputarguments->length() + 1;
    Proposition* proposition = create_proposition(SYM_PROPOSITIONS_FUNCTION, argcount);
    Vector* argumentsvector = proposition->arguments;
    Pattern_Variable* variable = create_variable(SGT_PROPOSITIONS_UNKNOWN, NULL, FALSE);

    proposition->renamed_Operator = verify_second_order_variable(((Skolem*)(variablefunction)), KWD_PROPOSITIONS_FUNCTION);
    { int i = NULL_INTEGER;
      Object* arg = NULL;
      Cons* iter_001 = inputarguments;
      int iter_002 = 0;

      while (!nilP(iter_001)) {
        {
          arg = iter_001->value;
          iter_001 = iter_001->rest;
        }
        {
          i = iter_002;
          iter_002 = iter_002 + 1;
        }
        argumentsvector->nth_setter(arg, i);
      }
    }
    argumentsvector->nth_setter(variable, argcount - 1);
    variable->defining_proposition = proposition;
    { Object* term = NULL;
      Vector* vector_001 = argumentsvector;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          term = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        add_dependent_proposition_link(term, proposition);
      }
    }
    return (proposition);
  }
}

Object* finish_evaluating_function_term(Surrogate* slotref, Cons* inputarguments) {
  { Proposition* proposition = NULL;

    if (!description_modeP()) {
      proposition = find_duplicate_function_proposition(slotref, inputarguments);
    }
    if (proposition == NULL) {
      proposition = create_function_proposition(slotref, inputarguments);
      oCONTEXTo->react_to_kb_update(proposition);
    }
    return (function_representative(proposition));
  }
}

Object* evaluate_function_term(Cons* tree) {
  { Object* variablefunction = lookup_logic_variable_binding(((Symbol*)(tree->first())));
    boolean secondorderP = variablefunction != NULL;
    Cons* inputarguments = NIL;
    Surrogate* slotref = NULL;

    { Object* arg = NULL;
      Cons* iter_001 = tree->rest;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          arg = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(evaluate_term(arg), NIL);
            if (nilP(inputarguments)) {
              inputarguments = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(inputarguments, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(evaluate_term(arg), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    if (secondorderP) {
      return (function_value(create_second_order_function_proposition(variablefunction, inputarguments)));
    }
    if (inputarguments->first()->value_of() == BOTTOM) {
      signal_undefined_term(inputarguments->first());
    }
    slotref = lookup_slotref_on_instance(inputarguments->first()->value_of(), ((Symbol*)(tree->first())));
    if (slotref == NULL) {
      signal_undefined_term(tree);
    }
    return (finish_evaluating_function_term(slotref, inputarguments));
  }
}

boolean function_output_variableP(Object* self) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PROPOSITIONS_PATTERN_VARIABLE)) {
      { Pattern_Variable* self = NULL;

        self = ((Pattern_Variable*)(self_001));
        return (((self->defining_proposition != NULL) ? ((boolean)(TRUE)) : ((boolean)(FALSE))));
      }
    }
    else {
      return (FALSE);
    }
  }
}

boolean function_output_skolemP(Object* self) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PROPOSITIONS_SKOLEM)) {
      { Skolem* self = NULL;

        self = ((Skolem*)(self_001));
        return (((self->defining_proposition != NULL) ? ((boolean)(TRUE)) : ((boolean)(FALSE))));
      }
    }
    else {
      return (FALSE);
    }
  }
}

Object* remove_true_and_false(Cons* tree, boolean& return1) {
  { Symbol* t = SYM_PROPOSITIONS_TRUE;
    Symbol* f = SYM_PROPOSITIONS_FALSE;

    { boolean test_value_001 = FALSE;

      { boolean foundP_001 = FALSE;

        { Object* arg = NULL;
          Cons* iter_001 = tree->rest;

          while (!nilP(iter_001)) {
            {
              arg = iter_001->value;
              iter_001 = iter_001->rest;
            }
            if ((arg == t) ||
                (arg == f)) {
              foundP_001 = TRUE;
              break;
            }
          }
        }
        test_value_001 = foundP_001;
      }
      test_value_001 = !test_value_001;
      if (test_value_001) {
        { Object* return_temp = tree;

          return1 = FALSE;
          return (return_temp);
        }
      }
    }
    { Symbol* test_value_002 = ((Symbol*)(tree->first()));

      if (test_value_002 == SYM_PROPOSITIONS_AND) {
        tree->rest = tree->rest->remove(t);
        { boolean foundP_002 = FALSE;

          { Object* arg = NULL;
            Cons* iter_002 = tree->rest;

            while (!nilP(iter_002)) {
              {
                arg = iter_002->value;
                iter_002 = iter_002->rest;
              }
              if (arg == f) {
                foundP_002 = TRUE;
                break;
              }
            }
          }
          if (foundP_002) {
            free_cons_tree(tree);
            { Object* return_temp = SYM_PROPOSITIONS_FALSE;

              return1 = TRUE;
              return (return_temp);
            }
          }
        }
      }
      else if (test_value_002 == SYM_PROPOSITIONS_OR) {
        tree->rest = tree->rest->remove(f);
        { boolean foundP_003 = FALSE;

          { Object* arg = NULL;
            Cons* iter_003 = tree->rest;

            while (!nilP(iter_003)) {
              {
                arg = iter_003->value;
                iter_003 = iter_003->rest;
              }
              if (arg == t) {
                foundP_003 = TRUE;
                break;
              }
            }
          }
          if (foundP_003) {
            free_cons_tree(tree);
            { Object* return_temp = SYM_PROPOSITIONS_TRUE;

              return1 = TRUE;
              return (return_temp);
            }
          }
        }
      }
      else if (test_value_002 == SYM_PROPOSITIONS_NOT) {
        { Symbol* test_value_003 = ((Symbol*)(tree->second()));

          if (test_value_003 == SYM_PROPOSITIONS_TRUE) {
            free_cons_tree(tree);
            { Object* return_temp = SYM_PROPOSITIONS_FALSE;

              return1 = TRUE;
              return (return_temp);
            }
          }
          else if (test_value_003 == SYM_PROPOSITIONS_FALSE) {
            free_cons_tree(tree);
            { Object* return_temp = SYM_PROPOSITIONS_TRUE;

              return1 = FALSE;
              return (return_temp);
            }
          }
          else {
            cerr << "`" << test_value_003 << "'" << " is not a valid case option";
          }
        }
      }
      else {
        cerr << "`" << test_value_002 << "'" << " is not a valid case option";
      }
    }
    { Object* return_temp = canonicalize_proposition_tree(tree);

      return1 = TRUE;
      return (return_temp);
    }
  }
}

Object* flatten_nested_operators(Cons* tree, boolean& return1) {
  { boolean test_value_001 = FALSE;

    { boolean foundP_001 = FALSE;

      { Object* arg = NULL;
        Cons* iter_001 = tree->rest;

        while (!nilP(iter_001)) {
          {
            arg = iter_001->value;
            iter_001 = iter_001->rest;
          }
          if (consP(arg) &&
              eqlP(((Cons*)(arg))->first(), tree->first())) {
            foundP_001 = TRUE;
            break;
          }
        }
      }
      test_value_001 = foundP_001;
    }
    test_value_001 = !test_value_001;
    if (test_value_001) {
      { Object* return_temp = tree;

        return1 = FALSE;
        return (return_temp);
      }
    }
  }
  { Symbol* targetoperator = ((Symbol*)(tree->first()));
    Cons* matchingarg = NULL;

    { Object* arg = NULL;
      Cons* iter_002 = tree->rest;

      while (!nilP(iter_002)) {
        {
          arg = iter_002->value;
          iter_002 = iter_002->rest;
        }
        if (consP(arg) &&
            (((Cons*)(arg))->first() == targetoperator)) {
          matchingarg = ((Cons*)(arg));
          break;
        }
      }
    }
    tree = tree->remove(matchingarg);
    { Object* arg = NULL;
      Cons* iter_003 = matchingarg->rest;

      while (!nilP(iter_003)) {
        {
          arg = iter_003->value;
          iter_003 = iter_003->rest;
        }
        tree->rest = cons(arg, tree->rest);
      }
    }
    free_cons_list(matchingarg);
    { Object* return_temp = canonicalize_proposition_tree(tree);

      return1 = TRUE;
      return (return_temp);
    }
  }
}

Object* canonicalize_and_or_tree(Cons* tree) {
  { Symbol* renamed_Operator = ((Symbol*)(tree->first()));
    int argcount = tree->rest->length();
    boolean canonicalP = FALSE;
    Object* resulttree = NULL;
    Object* arg = NULL;

    resulttree = remove_true_and_false(tree, canonicalP);
    if (canonicalP) {
      return (resulttree);
    }
    else {
      tree = ((Cons*)(resulttree));
    }
    if (argcount > 1) {
      resulttree = flatten_nested_operators(tree, canonicalP);
      return (resulttree);
    }
    else if (argcount == 1) {
      arg = tree->second();
      free_cons_list(tree);
      return (canonicalize_proposition_tree(arg));
    }
    else {
      free_cons_list(tree);
      if (renamed_Operator == SYM_PROPOSITIONS_AND) {
        return (SYM_PROPOSITIONS_TRUE);
      }
      else if (renamed_Operator == SYM_PROPOSITIONS_OR) {
        return (SYM_PROPOSITIONS_FALSE);
      }
      else {
        cerr << "`" << renamed_Operator << "'" << " is not a valid case option";
      }
    }
  }
}

Object* canonicalize_negation_tree(Cons* tree) {
  { Cons* argument = ((Cons*)(tree->second()));
    Symbol* nestedoperator = ((Symbol*)(argument->first()));

    if (nestedoperator == SYM_PROPOSITIONS_NOT) {
      free_cons_list(tree);
      return (canonicalize_proposition_tree(argument->second()));
    }
    else if ((nestedoperator == SYM_PROPOSITIONS_AND) ||
        (nestedoperator == SYM_PROPOSITIONS_OR)) {
      { Cons_Iterator* it = argument->rest->allocate_iterator();

        while (it->nextP()) {
          it->value_setter(listO(3, SYM_PROPOSITIONS_NOT, it->value, NIL));
        }
      }
      if (nestedoperator == SYM_PROPOSITIONS_AND) {
        argument->first_setter(SYM_PROPOSITIONS_OR);
      }
      else if (nestedoperator == SYM_PROPOSITIONS_OR) {
        argument->first_setter(SYM_PROPOSITIONS_AND);
      }
      else {
        cerr << "`" << nestedoperator << "'" << " is not a valid case option";
      }
    }
    else if (nestedoperator == SYM_PROPOSITIONS_EXISTS) {
      { Object* whereclause = extract_where_clause(argument);

        argument->first_setter(SYM_PROPOSITIONS_FORALL);
        last_cons(argument)->rest = cons(listO(3, SYM_PROPOSITIONS_ALWAYS, listO(3, SYM_PROPOSITIONS_NOT, whereclause, NIL), NIL), NIL);
      }
    }
    else if (nestedoperator == SYM_PROPOSITIONS_FORALL) {
      { Object* whereclause = extract_where_clause(argument);
        Object* alwaysclause = extract_always_clause(argument);

        argument->first_setter(SYM_PROPOSITIONS_EXISTS);
        last_cons(argument)->rest = ((whereclause != NULL) ? ((Cons*)(cons(listO(3, SYM_PROPOSITIONS_WHERE, listO(3, SYM_PROPOSITIONS_AND, whereclause, cons(listO(3, SYM_PROPOSITIONS_NOT, alwaysclause, NIL), NIL)), NIL), NIL))) : ((Cons*)(cons(listO(3, SYM_PROPOSITIONS_WHERE, listO(3, SYM_PROPOSITIONS_NOT, alwaysclause, NIL), NIL), NIL))));
      }
    }
    else {
      return (tree);
    }
    free_cons_list(tree);
    return (canonicalize_proposition_tree(argument));
  }
}

boolean quantifier_symbolP(Symbol* self) {
  return ((self == SYM_PROPOSITIONS_EXISTS) ||
      ((self == SYM_PROPOSITIONS_FORALL) ||
       ((self == SYM_PROPOSITIONS_SETOFALL) ||
        ((self == SYM_PROPOSITIONS_THE_ONLY) ||
         ((self == SYM_PROPOSITIONS_KAPPA) ||
          (self == SYM_PROPOSITIONS_SOME))))));
}

Cons* canonicalize_quantification_tree(Cons* tree) {
  { Object* whereclause = extract_where_clause(tree);
    Object* alwaysclause = extract_always_clause(tree);

    if (whereclause != NULL) {
      last_cons(tree)->rest = cons(listO(3, SYM_PROPOSITIONS_WHERE, canonicalize_proposition_tree(whereclause), NIL), NIL);
    }
    if (alwaysclause != NULL) {
      last_cons(tree)->rest = cons(listO(3, SYM_PROPOSITIONS_ALWAYS, canonicalize_proposition_tree(alwaysclause), NIL), NIL);
    }
    return (tree);
  }
}

Object* consDcanonicalize_proposition_tree(Cons* tree) {
  { Symbol* renamed_Operator = ((Symbol*)(tree->first()));

    if (quantifier_symbolP(renamed_Operator)) {
      return (canonicalize_quantification_tree(tree));
    }
    { Cons_Iterator* it = tree->rest->allocate_iterator();

      while (it->nextP()) {
        it->value_setter(canonicalize_proposition_tree(it->value));
      }
    }
    if ((renamed_Operator == SYM_PROPOSITIONS_AND) ||
        (renamed_Operator == SYM_PROPOSITIONS_OR)) {
      return (canonicalize_and_or_tree(tree));
    }
    else if (renamed_Operator == SYM_PROPOSITIONS_NOT) {
      { Object* arg = tree->second();

        if (consP(arg)) {
          return (canonicalize_negation_tree(tree));
        }
        { Surrogate* test_value_001 = ((Surrogate*)(arg));

          if (test_value_001 == SGT_PROPOSITIONS_TRUE) {
            free_cons_tree(tree);
            return (SGT_PROPOSITIONS_FALSE);
          }
          else if (test_value_001 == SGT_PROPOSITIONS_FALSE) {
            free_cons_tree(tree);
            return (SGT_PROPOSITIONS_TRUE);
          }
          else {
            return (tree);
          }
        }
      }
    }
    else {
    }
    return (tree);
  }
}

Object* canonicalize_proposition_tree(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        return (consDcanonicalize_proposition_tree(tree));
      }
    }
    else {
      return (tree);
    }
  }
}

Proposition* update_proposition(Object* tree, Keyword* updatemode) {
  {
    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;
      boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      oPENDINGEXCEPTIONHANDLERpo = TRUE;
      if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        { Object* tree_001 = tree;

          if (stringP(tree)) {
            { String_Wrapper* tree = NULL;

              tree = ((String_Wrapper*)(tree_001));
              { Proposition* return_value_001 = update_proposition(unstringify(tree->wrapper_value), updatemode);

                oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (return_value_001);
              }
            }
          }
          else {
            { Object* standardizedtree = NULL;
              Proposition* proposition = NULL;

              standardizedtree = standardize_logical_parse_tree(tree);
              if (consP(tree)) {
                { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

                  { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oTRANSIENTOBJECTSpo = TRUE;
                        standardizedtree = canonicalize_proposition_tree(tree);
                        oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                      resignal();
                    }
                  }
                }
              }
              proposition = help_update_proposition(standardizedtree, updatemode);
              free_cons_tree(standardizedtree);
              { 
                oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (proposition);
              }
            }
          }
        }
        oEXCEPTIONo = NULL;
      }
      oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (subtype_ofP(oEXCEPTION_TYPEo, SGT_PROPOSITIONS_LOGIC_EXCEPTION)) {
        { Logic_Exception* e = ((Logic_Exception*)(oEXCEPTIONo));

          if ((oTRACED_KEYWORDSo != NULL) &&
              oTRACED_KEYWORDSo->memberP(KWD_PROPOSITIONS_EXCEPTIONS)) {
            cout << "update-proposition: Caught " << e->primary_type() << endl;
          }
        }
      }
      else if (subtype_ofP(oEXCEPTION_TYPEo, SGT_PROPOSITIONS_READ_EXCEPTION)) {
        if ((oTRACED_KEYWORDSo != NULL) &&
            oTRACED_KEYWORDSo->memberP(KWD_PROPOSITIONS_EXCEPTIONS)) {
          cout << "update-proposition: Caught READ-EXCEPTION" << endl;
        }
      }
      else if (TRUE) {
        { Exception* e = oEXCEPTIONo;

          cerr << "update-proposition: Caught " << "`" << e->primary_type() << "'" << endl;
        }
      }
    }
  }
}

Proposition* help_update_proposition(Object* tree, Keyword* updatemode) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Object* test_value_001 = tree->first();

          if (test_value_001 == SYM_PROPOSITIONS_NOT) {
            if (descriptive_updateP(updatemode)) {
              return (build_top_level_proposition(tree, updatemode));
            }
            else {
              {
                if (updatemode == KWD_PROPOSITIONS_ASSERT_TRUE) {
                  help_update_proposition(tree->second(), KWD_PROPOSITIONS_ASSERT_FALSE);
                }
                else if (updatemode == KWD_PROPOSITIONS_ASSERT_FALSE) {
                  help_update_proposition(tree->second(), KWD_PROPOSITIONS_ASSERT_TRUE);
                }
                else if (updatemode == KWD_PROPOSITIONS_RETRACT_TRUE) {
                  help_update_proposition(tree->second(), KWD_PROPOSITIONS_RETRACT_FALSE);
                }
                else if (updatemode == KWD_PROPOSITIONS_RETRACT_FALSE) {
                  help_update_proposition(tree->second(), KWD_PROPOSITIONS_RETRACT_TRUE);
                }
                else {
                  cerr << "`" << updatemode << "'" << " is not a valid case option";
                }
                return (NULL);
              }
            }
          }
          else if (test_value_001 == SYM_PROPOSITIONS_AND) {
            if ((updatemode == KWD_PROPOSITIONS_ASSERT_TRUE) ||
                (updatemode == KWD_PROPOSITIONS_RETRACT_TRUE)) {
              { Object* subtree = NULL;
                Cons* iter_001 = tree->rest;

                while (!nilP(iter_001)) {
                  {
                    subtree = iter_001->value;
                    iter_001 = iter_001->rest;
                  }
                  help_update_proposition(subtree, updatemode);
                }
              }
              return (NULL);
            }
            else {
              return (build_top_level_proposition(tree, updatemode));
            }
          }
          else {
            return (build_top_level_proposition(tree, updatemode));
          }
        }
      }
    }
    else {
      return (build_top_level_proposition(tree, updatemode));
    }
  }
}

Object* smart_update_proposition(Object* tree, Keyword* updatemode) {
  { Cons* old_OtoplevelpropositionsO_001 = oTOPLEVELPROPOSITIONSo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTOPLEVELPROPOSITIONSo = NIL;
          { Proposition* proposition = update_proposition(tree, updatemode);

            if (proposition != NULL) {
              free_cons_list(oTOPLEVELPROPOSITIONSo);
              { 
                oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (proposition);
              }
            }
            switch (oTOPLEVELPROPOSITIONSo->length()) {
              case 0: 
                { 
                  oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  return (NULL);
                }
              break;
              case 1: 
                proposition = ((Proposition*)(oTOPLEVELPROPOSITIONSo->first()));
                free_cons_list(oTOPLEVELPROPOSITIONSo);
                { 
                  oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  return (proposition);
                }
              break;
              default:
                { Cons* return_value_001 = oTOPLEVELPROPOSITIONSo;

                  oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  return (return_value_001);
                }
              break;
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

Object* assert(Object* proposition) {
  // Assert the truth of `proposition'.  Return the asserted proposition object.
  // KIF example:  `(assert (happy Fred))' asserts that Fred is indeed happy.
  // Note, that for this assertion to succeed, the logic constant `Fred' must
  // already be defined, e.g., as a side-effect of a type assertion such as
  // `(assert (Person Fred))', and the relation (or slot) `happy' must be defined
  // on objects of `Fred's type, e.g., on the class `Person'.
  return (smart_update_proposition(proposition, KWD_PROPOSITIONS_ASSERT_TRUE));
}

Proposition* retract(Object* proposition) {
  // Retract the truth of `proposition'.  Return the retracted proposition
  // object.  KIF example:  `(retract (happy Fred))' retracts that Fred is
  // happy.  Note, that for this to succeed, the logic constant `Fred' and the
  // relation (or slot) `happy' must already be defined (see `assert').
  return (((Proposition*)(smart_update_proposition(proposition, KWD_PROPOSITIONS_RETRACT_TRUE))));
}

Proposition* deny(Object* proposition) {
  // Assert the falsity of `proposition'.  Return the asserted proposition
  // object.  KIF example:  `(deny (happy Fred))' asserts that Fred is not happy,
  // which could have been done equivalently by `(assert (not (happy Fred)))'.
  // Note, that for this to succeed, the logic constant `Fred' and the
  // relation (or slot) `happy' must already be defined (see `assert').
  return (((Proposition*)(smart_update_proposition(proposition, KWD_PROPOSITIONS_ASSERT_FALSE))));
}

Proposition* conceive(Object* proposition) {
  // Build `proposition' without asserting its truth value.  Return the
  // conceived proposition object.  KIF example: `(conceive (happy Fred))' builds
  // the proposition expressing that Fred is happy without explictly asserting or
  // denying it.  Note, that for this to succeed, the logic constant `Fred' and
  // the relation (or slot) `happy' must already be defined (see `assert').
  return (((Proposition*)(smart_update_proposition(proposition, KWD_PROPOSITIONS_CONCEIVE))));
}

void unassert(Object* proposition) {
  // Retract the truth or falsity of `proposition'.  This is a more general
  // version of `retract' that also handles falsity.
  unassert_fact(update_proposition(proposition, KWD_PROPOSITIONS_CONCEIVE));
}

void unassert_fact(Proposition* self) {
  // Retract the truth or falsity of the proposition 'self'
  if (self != NULL) {
    if (self->kind == KWD_PROPOSITIONS_FUNCTION) {
      { Skolem* outputskolem = ((Skolem*)(last_argument(self)));

        if (((Object*)(access_in_context(outputskolem->variable_value, outputskolem, FALSE))) != NULL) {
          unequate_valuesP(outputskolem, ((Object*)(access_in_context(outputskolem->variable_value, outputskolem, FALSE))));
        }
      }
    }
    else if (trueP(self)) {
      deassign_truth_value(self, KWD_PROPOSITIONS_RETRACT_TRUE);
    }
    else if (falseP(self)) {
      deassign_truth_value(self, KWD_PROPOSITIONS_RETRACT_FALSE);
    }
  }
}

boolean Logic_Object::deletedP() {
  { Logic_Object* self = this;

    { boolean deletedP = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_DELETED_OBJECTp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (deletedP != NULL_BOOLEAN) {
        return (deletedP);
      }
      else {
        return (FALSE);
      }
    }
  }
}

boolean Logic_Object::deletedP_setter(boolean value) {
  { Logic_Object* self = this;

    set_dynamic_slot_value(self, SYM_PROPOSITIONS_DELETED_OBJECTp, wrap_boolean(value), NULL_BOOLEAN_WRAPPER);
    return (value);
  }
}

boolean Proposition::deletedP() {
  { Proposition* self = this;

    return (self->kind == KWD_PROPOSITIONS_DELETED);
  }
}

boolean Proposition::deletedP_setter(boolean value) {
  { Proposition* self = this;

    if (value) {
      self->kind = KWD_PROPOSITIONS_DELETED;
    }
    return (value);
  }
}

void destroy_proposition(Proposition* proposition) {
  // Retract and destroy the proposition 'proposition'.
  // Recursively destroy all propositions that reference 'proposition'.
  if (proposition->deletedP()) {
    return;
  }
  proposition->deletedP_setter(TRUE);
  { Object* arg = NULL;
    Vector* vector_001 = proposition->arguments;
    int index_001 = 0;
    int length_001 = vector_001->length();

    while (index_001 < length_001) {
      {
        arg = vector_001->nth(index_001);
        index_001 = index_001 + 1;
      }
      if (arg != NULL) {
        remove_dependent_proposition_link(arg, proposition);
      }
    }
  }
  { Proposition* dep = NULL;
    Cons* iter_001 = proposition->dependent_propositions->the_cons_list;

    while (!nilP(iter_001)) {
      {
        dep = ((Proposition*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      destroy_proposition(dep);
    }
  }
}

void destroy_instance(Logic_Object* object) {
  // Destroy all propositions that reference 'object',
  // and mark it as 'deleted?', thereby making it invisible within class
  // extensions.
  if ((object == NULL) ||
      object->deletedP()) {
    return;
  }
  object->deletedP_setter(TRUE);
  { Proposition* p = NULL;
    Cons* iter_001 = object->dependent_attribute_propositions->copy()->the_cons_list;

    while (!nilP(iter_001)) {
      {
        p = ((Proposition*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      destroy_proposition(p);
    }
  }
  { Proposition* p = NULL;
    Cons* iter_002 = object->dependent_propositions->copy()->the_cons_list;

    while (!nilP(iter_002)) {
      {
        p = ((Proposition*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      destroy_proposition(p);
    }
  }
  { Logic_Object* equivalent = NULL;
    Cons* iter_003 = object->variable_value_inverse_reader();

    while (!nilP(iter_003)) {
      {
        equivalent = ((Logic_Object*)(iter_003->value));
        iter_003 = iter_003->rest;
      }
      { Logic_Object* object_001 = equivalent;
        Object* value_001 = NULL;
        Object* old_value_001 = object_001->variable_value;
        Object* new_value_001 = update_in_context(old_value_001, value_001, object_001, FALSE);

        if (!cs_valueP(old_value_001)) {
          object_001->variable_value = new_value_001;
        }
      }
    }
  }
  if (((Surrogate*)(dynamic_slot_value(object, SYM_PROPOSITIONS_SURROGATE_VALUE_INVERSE, NULL))) != NULL) {
    ((Surrogate*)(dynamic_slot_value(object, SYM_PROPOSITIONS_SURROGATE_VALUE_INVERSE, NULL)))->surrogate_value = NULL;
  }
}

void destroy_term(Logic_Object* object) {
  // Destroy all propositions that reference 'object',
  // and mark it as 'deleted?', thereby making it invisible within class
  // extensions.  Unlink descriptions from native relations.
  destroy_instance(object);
  { Logic_Object* object_001 = object;

    if (taxonomy_isaP(object, SGT_PROPOSITIONS_DESCRIPTION)) {
      { Description* object = NULL;

        object = ((Description*)(object_001));
        { Relation* nativerelation = object->native_relation;

          if (nativerelation != NULL) {
            set_dynamic_slot_value(nativerelation, SYM_PROPOSITIONS_DESCRIPTION, NULL, NULL);
            set_dynamic_slot_value(nativerelation, SYM_PROPOSITIONS_DEFINITION, NULL, NULL);
            nativerelation->relation_originated_propositions_reader()->remove_deleted_members();
          }
        }
      }
    }
    else {
    }
  }
}

void clear_logic_module_hook(Module* module) {
  { Module* old_OmoduleO_001 = oMODULEo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = module;
          oCONTEXTo = oMODULEo;
          { World* cache = ((World*)(dynamic_slot_value(module, SYM_PROPOSITIONS_STRICT_INFERENCE_CACHE, NULL)));

            if (cache != NULL) {
              destroy_inference_cache(cache);
              set_dynamic_slot_value(module, SYM_PROPOSITIONS_STRICT_INFERENCE_CACHE, NULL, NULL);
            }
          }
          { Logic_Object* term = NULL;
            Iterator* iter_001 = all_terms(module, TRUE);

            while (iter_001->nextP()) {
              {
                term = ((Logic_Object*)(iter_001->value));
              }
              destroy_term(term);
            }
          }
          { Proposition* proposition = NULL;
            Iterator* iter_002 = all_propositions(module, TRUE);

            while (iter_002->nextP()) {
              {
                proposition = ((Proposition*)(iter_002->value));
              }
              destroy_proposition(proposition);
            }
          }
          module->locally_conceived_propositions_getter()->remove_deleted_members();
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

void clear_instances(Cons* name) {
  // Destroy all instances belonging to module `name' or any of its children.
  // If no `name' is supplied, the current module will be cleared after
  // confirming with the user.
  { Module* module = coerce_to_module(name->first(), TRUE);

    if (module != NULL) {
      if (name->non_emptyP() ||
          y_or_nP(string_concatenate("Really clear instances of module ", string_concatenate(module->module_full_name, "? ")))) {
        do_clear_instances(module);
      }
    }
  }
}

void clear_instances_evaluator_wrapper(Cons* arguments) {
  clear_instances(((Cons*)(arguments)));
}

void do_clear_instances(Module* module) {
  // Function version of `clear-instances' that evaluates its argument.
  { Context* child = NULL;
    Cons* iter_001 = module->child_contexts->the_cons_list;

    while (!nilP(iter_001)) {
      {
        child = ((Context*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (isaP(child, SGT_PROPOSITIONS_MODULE)) {
        do_clear_instances(((Module*)(child)));
      }
    }
  }
  { Module* old_OmoduleO_001 = oMODULEo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = module;
          oCONTEXTo = oMODULEo;
          { World* cache = ((World*)(dynamic_slot_value(module, SYM_PROPOSITIONS_STRICT_INFERENCE_CACHE, NULL)));

            if (cache != NULL) {
              destroy_inference_cache(cache);
              set_dynamic_slot_value(module, SYM_PROPOSITIONS_STRICT_INFERENCE_CACHE, NULL, NULL);
            }
          }
          { Logic_Object* instance = NULL;
            Iterator* iter_002 = all_instances(module, TRUE);

            while (iter_002->nextP()) {
              {
                instance = ((Logic_Object*)(iter_002->value));
              }
              destroy_instance(instance);
            }
          }
          module->locally_conceived_propositions_getter()->remove_deleted_members();
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

void help_transfer_proposition_arguments(Proposition* proposition, Logic_Object* fromobject, Logic_Object* toobject) {
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
      if (arg == fromobject) {
        proposition->arguments->nth_setter(toobject, i);
      }
    }
  }
}

void transfer_propositions_to_logic_object(Logic_Object* fromobject, Logic_Object* toobject) {
  { Proposition* p = NULL;
    Cons* iter_001 = fromobject->dependent_propositions->the_cons_list;

    while (!nilP(iter_001)) {
      {
        p = ((Proposition*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      help_transfer_proposition_arguments(p, fromobject, toobject);
      toobject->dependent_propositions->insert_new(p);
    }
  }
  { Proposition* p = NULL;
    Cons* iter_002 = fromobject->dependent_attribute_propositions->the_cons_list;

    while (!nilP(iter_002)) {
      {
        p = ((Proposition*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      help_transfer_proposition_arguments(p, fromobject, toobject);
      toobject->dependent_attribute_propositions->insert_new(p);
    }
  }
  fromobject->dependent_propositions->clear();
  fromobject->dependent_attribute_propositions->clear();
}

boolean Slot::totalP_reader() {
  { Slot* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_TOTALp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Slot::index_on_valuesP_reader() {
  { Slot* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_PROPOSITIONS_INDEX_ON_VALUESp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

double Number_Wrapper::number_value() {
  { Number_Wrapper* wrappednumber = this;

    { double result = NULL_FLOAT;

      { Number_Wrapper* wrappednumber_001 = wrappednumber;

        if (integerP(wrappednumber)) {
          { Integer_Wrapper* wrappednumber = NULL;

            wrappednumber = ((Integer_Wrapper*)(wrappednumber_001));
            result = wrappednumber->wrapper_value;
          }
        }
        else if (floatP(wrappednumber)) {
          { Float_Wrapper* wrappednumber = NULL;

            wrappednumber = ((Float_Wrapper*)(wrappednumber_001));
            result = wrappednumber->wrapper_value;
          }
        }
        else {
          cerr << "`" << wrappednumber << "'" << " is not a valid case option";
        }
      }
      return (result);
    }
  }
}

Boolean_Wrapper* Number_Wrapper::greater_thanP(Number_Wrapper* y) {
  { Number_Wrapper* x = this;

    return (wrap_boolean(x->number_value() > y->number_value()));
  }
}

Boolean_Wrapper* Number_Wrapper::greater_or_equalP(Number_Wrapper* y) {
  { Number_Wrapper* x = this;

    return (wrap_boolean(x->number_value() >= y->number_value()));
  }
}

Boolean_Wrapper* Number_Wrapper::less_thanP(Number_Wrapper* y) {
  { Number_Wrapper* x = this;

    return (wrap_boolean(x->number_value() < y->number_value()));
  }
}

Boolean_Wrapper* Number_Wrapper::less_or_equalP(Number_Wrapper* y) {
  { Number_Wrapper* x = this;

    return (wrap_boolean(x->number_value() <= y->number_value()));
  }
}

Number_Wrapper* Number_Wrapper::plus(Number_Wrapper* y) {
  { Number_Wrapper* x = this;

    { double floatresult = NULL_FLOAT;

      { Number_Wrapper* x_001 = x;

        if (integerP(x)) {
          { Integer_Wrapper* x = NULL;

            x = ((Integer_Wrapper*)(x_001));
            { Number_Wrapper* y_001 = y;

              if (integerP(y)) {
                { Integer_Wrapper* y = NULL;

                  y = ((Integer_Wrapper*)(y_001));
                  return (integer_wrap_literal(((int)(x->wrapper_value + y->wrapper_value))));
                }
              }
              else if (floatP(y)) {
                { Float_Wrapper* y = NULL;

                  y = ((Float_Wrapper*)(y_001));
                  floatresult = x->wrapper_value + y->wrapper_value;
                }
              }
              else {
                cerr << "`" << y << "'" << " is not a valid case option";
              }
            }
          }
        }
        else if (floatP(x)) {
          { Float_Wrapper* x = NULL;

            x = ((Float_Wrapper*)(x_001));
            { Number_Wrapper* y_002 = y;

              if (integerP(y)) {
                { Integer_Wrapper* y = NULL;

                  y = ((Integer_Wrapper*)(y_002));
                  floatresult = x->wrapper_value + y->wrapper_value;
                }
              }
              else if (floatP(y)) {
                { Float_Wrapper* y = NULL;

                  y = ((Float_Wrapper*)(y_002));
                  floatresult = x->wrapper_value + y->wrapper_value;
                }
              }
              else {
                cerr << "`" << y << "'" << " is not a valid case option";
              }
            }
          }
        }
        else {
          cerr << "`" << x << "'" << " is not a valid case option";
        }
      }
      return (float_wrap_literal(floatresult));
    }
  }
}

Number_Wrapper* Number_Wrapper::minus(Number_Wrapper* y) {
  { Number_Wrapper* x = this;

    { double floatresult = NULL_FLOAT;

      { Number_Wrapper* x_001 = x;

        if (integerP(x)) {
          { Integer_Wrapper* x = NULL;

            x = ((Integer_Wrapper*)(x_001));
            { Number_Wrapper* y_001 = y;

              if (integerP(y)) {
                { Integer_Wrapper* y = NULL;

                  y = ((Integer_Wrapper*)(y_001));
                  return (integer_wrap_literal(((int)(x->wrapper_value - y->wrapper_value))));
                }
              }
              else if (floatP(y)) {
                { Float_Wrapper* y = NULL;

                  y = ((Float_Wrapper*)(y_001));
                  floatresult = x->wrapper_value - y->wrapper_value;
                }
              }
              else {
                cerr << "`" << y << "'" << " is not a valid case option";
              }
            }
          }
        }
        else if (floatP(x)) {
          { Float_Wrapper* x = NULL;

            x = ((Float_Wrapper*)(x_001));
            { Number_Wrapper* y_002 = y;

              if (integerP(y)) {
                { Integer_Wrapper* y = NULL;

                  y = ((Integer_Wrapper*)(y_002));
                  floatresult = x->wrapper_value - y->wrapper_value;
                }
              }
              else if (floatP(y)) {
                { Float_Wrapper* y = NULL;

                  y = ((Float_Wrapper*)(y_002));
                  floatresult = x->wrapper_value - y->wrapper_value;
                }
              }
              else {
                cerr << "`" << y << "'" << " is not a valid case option";
              }
            }
          }
        }
        else {
          cerr << "`" << x << "'" << " is not a valid case option";
        }
      }
      return (float_wrap_literal(floatresult));
    }
  }
}

Number_Wrapper* Number_Wrapper::times(Number_Wrapper* y) {
  { Number_Wrapper* x = this;

    { double floatresult = NULL_FLOAT;

      { Number_Wrapper* x_001 = x;

        if (integerP(x)) {
          { Integer_Wrapper* x = NULL;

            x = ((Integer_Wrapper*)(x_001));
            { Number_Wrapper* y_001 = y;

              if (integerP(y)) {
                { Integer_Wrapper* y = NULL;

                  y = ((Integer_Wrapper*)(y_001));
                  return (integer_wrap_literal(((int)(x->wrapper_value * y->wrapper_value))));
                }
              }
              else if (floatP(y)) {
                { Float_Wrapper* y = NULL;

                  y = ((Float_Wrapper*)(y_001));
                  floatresult = x->wrapper_value * y->wrapper_value;
                }
              }
              else {
                cerr << "`" << y << "'" << " is not a valid case option";
              }
            }
          }
        }
        else if (floatP(x)) {
          { Float_Wrapper* x = NULL;

            x = ((Float_Wrapper*)(x_001));
            { Number_Wrapper* y_002 = y;

              if (integerP(y)) {
                { Integer_Wrapper* y = NULL;

                  y = ((Integer_Wrapper*)(y_002));
                  floatresult = x->wrapper_value * y->wrapper_value;
                }
              }
              else if (floatP(y)) {
                { Float_Wrapper* y = NULL;

                  y = ((Float_Wrapper*)(y_002));
                  floatresult = x->wrapper_value * y->wrapper_value;
                }
              }
              else {
                cerr << "`" << y << "'" << " is not a valid case option";
              }
            }
          }
        }
        else {
          cerr << "`" << x << "'" << " is not a valid case option";
        }
      }
      return (float_wrap_literal(floatresult));
    }
  }
}

Number_Wrapper* Number_Wrapper::divide(Number_Wrapper* y) {
  { Number_Wrapper* x = this;

    { double floatresult = NULL_FLOAT;

      { Number_Wrapper* x_001 = x;

        if (integerP(x)) {
          { Integer_Wrapper* x = NULL;

            x = ((Integer_Wrapper*)(x_001));
            { Number_Wrapper* y_001 = y;

              if (integerP(y)) {
                { Integer_Wrapper* y = NULL;

                  y = ((Integer_Wrapper*)(y_001));
                  if (mod(x->wrapper_value, y->wrapper_value) == 0) {
                    return (integer_wrap_literal(((int)((x->wrapper_value / 1.0) / y->wrapper_value))));
                  }
                  else {
                    floatresult = ((x->wrapper_value / 1.0) / y->wrapper_value) * 1.0;
                  }
                }
              }
              else if (floatP(y)) {
                { Float_Wrapper* y = NULL;

                  y = ((Float_Wrapper*)(y_001));
                  floatresult = x->wrapper_value / y->wrapper_value;
                }
              }
              else {
                cerr << "`" << y << "'" << " is not a valid case option";
              }
            }
          }
        }
        else if (floatP(x)) {
          { Float_Wrapper* x = NULL;

            x = ((Float_Wrapper*)(x_001));
            { Number_Wrapper* y_002 = y;

              if (integerP(y)) {
                { Integer_Wrapper* y = NULL;

                  y = ((Integer_Wrapper*)(y_002));
                  floatresult = x->wrapper_value / y->wrapper_value;
                }
              }
              else if (floatP(y)) {
                { Float_Wrapper* y = NULL;

                  y = ((Float_Wrapper*)(y_002));
                  floatresult = x->wrapper_value / y->wrapper_value;
                }
              }
              else {
                cerr << "`" << y << "'" << " is not a valid case option";
              }
            }
          }
        }
        else {
          cerr << "`" << x << "'" << " is not a valid case option";
        }
      }
      return (float_wrap_literal(floatresult));
    }
  }
}

void startup_propositions() {
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
            SYM_PROPOSITIONS_ALL_ROOT_TYPES = ((Symbol*)(intern_rigid_symbol_wrt_module("ALL-ROOT-TYPES", NULL, 0)));
            SYM_PROPOSITIONS_ALL_SURROGATE_VALUE_INVERSES = ((Symbol*)(intern_rigid_symbol_wrt_module("ALL-SURROGATE-VALUE-INVERSES", NULL, 0)));
            SYM_PROPOSITIONS_ROOT_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("ROOT-TYPE", NULL, 0)));
            SYM_PROPOSITIONS_DEPENDENT_ATTRIBUTE_PROPOSITIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("DEPENDENT-ATTRIBUTE-PROPOSITIONS", NULL, 0)));
            SYM_PROPOSITIONS_DEPENDENT_PROPOSITIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("DEPENDENT-PROPOSITIONS", NULL, 0)));
            SYM_PROPOSITIONS_VARIABLE_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-VALUE", NULL, 0)));
            SYM_PROPOSITIONS_VARIABLE_VALUE_INVERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-VALUE-INVERSE", NULL, 0)));
            SGT_PROPOSITIONS_LOGIC_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-OBJECT", NULL, 1)));
            SYM_PROPOSITIONS_SKOLEM_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("SKOLEM-TYPE", NULL, 0)));
            SYM_PROPOSITIONS_NOT_BOTTOMp = ((Symbol*)(intern_rigid_symbol_wrt_module("NOT-BOTTOM?", NULL, 0)));
            SYM_PROPOSITIONS_DEFINING_PROPOSITION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINING-PROPOSITION", NULL, 0)));
            SGT_PROPOSITIONS_SKOLEM = ((Surrogate*)(intern_rigid_symbol_wrt_module("SKOLEM", NULL, 1)));
            SYM_PROPOSITIONS_BOUND_TO_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("BOUND-TO-OFFSET", NULL, 0)));
            SGT_PROPOSITIONS_PATTERN_VARIABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("PATTERN-VARIABLE", NULL, 1)));
            SYM_PROPOSITIONS_OBJECT_VECTOR = ((Symbol*)(intern_rigid_symbol_wrt_module("OBJECT-VECTOR", NULL, 0)));
            SYM_PROPOSITIONS_ARGUMENTS_VECTOR = ((Symbol*)(intern_rigid_symbol_wrt_module("ARGUMENTS-VECTOR", NULL, 0)));
            SYM_PROPOSITIONS_VARIABLES_VECTOR = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLES-VECTOR", NULL, 0)));
            SYM_PROPOSITIONS_EXTENSION = ((Symbol*)(intern_rigid_symbol_wrt_module("EXTENSION", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_IOTAp = ((Symbol*)(intern_rigid_symbol_wrt_module("IOTA?", NULL, 0)));
            SYM_PROPOSITIONS_PROPOSITION = ((Symbol*)(intern_rigid_symbol_wrt_module("PROPOSITION", NULL, 0)));
            SYM_PROPOSITIONS_IO_VARIABLES = ((Symbol*)(intern_rigid_symbol_wrt_module("IO-VARIABLES", NULL, 0)));
            SYM_PROPOSITIONS_INTERNAL_VARIABLES = ((Symbol*)(intern_rigid_symbol_wrt_module("INTERNAL-VARIABLES", NULL, 0)));
            SYM_PROPOSITIONS_KIND = ((Symbol*)(intern_rigid_symbol_wrt_module("KIND", NULL, 0)));
            SYM_PROPOSITIONS_NATIVE_RELATION = ((Symbol*)(intern_rigid_symbol_wrt_module("NATIVE-RELATION", NULL, 0)));
            SYM_PROPOSITIONS_QUERY_PATTERNS = ((Symbol*)(intern_rigid_symbol_wrt_module("QUERY-PATTERNS", NULL, 0)));
            SYM_PROPOSITIONS_REFERENCED_BY = ((Symbol*)(intern_rigid_symbol_wrt_module("REFERENCED-BY", NULL, 0)));
            SYM_PROPOSITIONS_TAXONOMY_NODE = ((Symbol*)(intern_rigid_symbol_wrt_module("TAXONOMY-NODE", string_get_module("/STELLA", TRUE), 0)));
            SGT_PROPOSITIONS_DESCRIPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 1)));
            SGT_PROPOSITIONS_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("SLOT", string_get_module("/STELLA", TRUE), 1)));
            SYM_PROPOSITIONS_PARTIAL_MATCH_SCORE = ((Symbol*)(intern_rigid_symbol_wrt_module("PARTIAL-MATCH-SCORE", NULL, 0)));
            SYM_PROPOSITIONS_SET_OF_SUPPORT = ((Symbol*)(intern_rigid_symbol_wrt_module("SET-OF-SUPPORT", NULL, 0)));
            SYM_PROPOSITIONS_TIME_STAMP = ((Symbol*)(intern_rigid_symbol_wrt_module("TIME-STAMP", NULL, 0)));
            SYM_PROPOSITIONS_POSITIVE_SCORE = ((Symbol*)(intern_rigid_symbol_wrt_module("POSITIVE-SCORE", NULL, 0)));
            SYM_PROPOSITIONS_NEGATIVE_SCORE = ((Symbol*)(intern_rigid_symbol_wrt_module("NEGATIVE-SCORE", NULL, 0)));
            SYM_PROPOSITIONS_POSITIVE_SET_OF_SUPPORT = ((Symbol*)(intern_rigid_symbol_wrt_module("POSITIVE-SET-OF-SUPPORT", NULL, 0)));
            SYM_PROPOSITIONS_NEGATIVE_SET_OF_SUPPORT = ((Symbol*)(intern_rigid_symbol_wrt_module("NEGATIVE-SET-OF-SUPPORT", NULL, 0)));
            SGT_PROPOSITIONS_TRUTH_VALUE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRUTH-VALUE", NULL, 1)));
            SYM_PROPOSITIONS_VARIABLE_TYPEp = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-TYPE?", NULL, 0)));
            SYM_PROPOSITIONS_SUBRELATION_LINKp = ((Symbol*)(intern_rigid_symbol_wrt_module("SUBRELATION-LINK?", NULL, 0)));
            SYM_PROPOSITIONS_SUBSUMPTION_LINKp = ((Symbol*)(intern_rigid_symbol_wrt_module("SUBSUMPTION-LINK?", NULL, 0)));
            SYM_PROPOSITIONS_SATELLITE_PROPOSITIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("SATELLITE-PROPOSITIONS", NULL, 0)));
            SYM_PROPOSITIONS_DONT_OPTIMIZEp = ((Symbol*)(intern_rigid_symbol_wrt_module("DONT-OPTIMIZE?", NULL, 0)));
            SYM_PROPOSITIONS_FORWARD_ONLYp = ((Symbol*)(intern_rigid_symbol_wrt_module("FORWARD-ONLY?", NULL, 0)));
            SYM_PROPOSITIONS_BACKWARD_ONLYp = ((Symbol*)(intern_rigid_symbol_wrt_module("BACKWARD-ONLY?", NULL, 0)));
            SYM_PROPOSITIONS_TRUTH_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUTH-VALUE", NULL, 0)));
            SYM_PROPOSITIONS_ARGUMENTS = ((Symbol*)(intern_rigid_symbol_wrt_module("ARGUMENTS", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_OPERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("OPERATOR", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_SLOTREF = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOTREF", string_get_module("/STELLA", TRUE), 0)));
            SGT_PROPOSITIONS_PROPOSITION = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPOSITION", NULL, 1)));
            SYM_PROPOSITIONS_FUNCTION = ((Symbol*)(intern_rigid_symbol_wrt_module("FUNCTION", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_PREDICATE = ((Symbol*)(intern_rigid_symbol_wrt_module("PREDICATE", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_CONTEXT_ASSUMED_PROPOSITIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CONTEXT-ASSUMED-PROPOSITIONS", NULL, 0)));
            SYM_PROPOSITIONS_MONOTONICp = ((Symbol*)(intern_rigid_symbol_wrt_module("MONOTONIC?", NULL, 0)));
            SYM_PROPOSITIONS_TRUTH_MAINTAINEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUTH-MAINTAINED?", NULL, 0)));
            SYM_PROPOSITIONS_UP_TO_DATE_INFERENCESp = ((Symbol*)(intern_rigid_symbol_wrt_module("UP-TO-DATE-INFERENCES?", NULL, 0)));
            SYM_PROPOSITIONS_LOCALLY_CONCEIVED_PROPOSITIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("LOCALLY-CONCEIVED-PROPOSITIONS", NULL, 0)));
            SYM_PROPOSITIONS_LOCALLY_BOUND_PROPOSITIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("LOCALLY-BOUND-PROPOSITIONS", NULL, 0)));
            SYM_PROPOSITIONS_LOCALLY_BOUND_SKOLEMS = ((Symbol*)(intern_rigid_symbol_wrt_module("LOCALLY-BOUND-SKOLEMS", NULL, 0)));
            KWD_PROPOSITIONS_UPDATE_PROPOSITION = ((Keyword*)(intern_rigid_symbol_wrt_module("UPDATE-PROPOSITION", NULL, 2)));
            KWD_PROPOSITIONS_EXECUTE_QUERY = ((Keyword*)(intern_rigid_symbol_wrt_module("EXECUTE-QUERY", NULL, 2)));
            SYM_PROPOSITIONS_BOTTOM = ((Symbol*)(intern_rigid_symbol_wrt_module("BOTTOM", NULL, 0)));
            SGT_PROPOSITIONS_LITERAL_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("LITERAL-WRAPPER", string_get_module("/STELLA", TRUE), 1)));
            SGT_PROPOSITIONS_LITERAL = ((Surrogate*)(intern_rigid_symbol_wrt_module("LITERAL", string_get_module("/STELLA", TRUE), 1)));
            KWD_PROPOSITIONS_OPEN_WORLD = ((Keyword*)(intern_rigid_symbol_wrt_module("OPEN-WORLD", NULL, 2)));
            KWD_PROPOSITIONS_CLOSED_WORLD = ((Keyword*)(intern_rigid_symbol_wrt_module("CLOSED-WORLD", NULL, 2)));
            KWD_PROPOSITIONS_EXTENSIONAL_ASSERTION = ((Keyword*)(intern_rigid_symbol_wrt_module("EXTENSIONAL-ASSERTION", NULL, 2)));
            SYM_PROPOSITIONS_oEVALUATIONMODEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*EVALUATIONMODE*", NULL, 0)));
            KWD_PROPOSITIONS_DESCRIPTION = ((Keyword*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 2)));
            KWD_PROPOSITIONS_QUERY = ((Keyword*)(intern_rigid_symbol_wrt_module("QUERY", NULL, 2)));
            KWD_PROPOSITIONS_CONCEIVE = ((Keyword*)(intern_rigid_symbol_wrt_module("CONCEIVE", NULL, 2)));
            KWD_PROPOSITIONS_IMPLIES = ((Keyword*)(intern_rigid_symbol_wrt_module("IMPLIES", NULL, 2)));
            KWD_PROPOSITIONS_RETRACT_TRUE = ((Keyword*)(intern_rigid_symbol_wrt_module("RETRACT-TRUE", NULL, 2)));
            SYM_PROPOSITIONS_MASTER_PROPOSITION = ((Symbol*)(intern_rigid_symbol_wrt_module("MASTER-PROPOSITION", NULL, 0)));
            KWD_PROPOSITIONS_ASSERT_TRUE = ((Keyword*)(intern_rigid_symbol_wrt_module("ASSERT-TRUE", NULL, 2)));
            KWD_PROPOSITIONS_ASSERT_FALSE = ((Keyword*)(intern_rigid_symbol_wrt_module("ASSERT-FALSE", NULL, 2)));
            KWD_PROPOSITIONS_RETRACT_FALSE = ((Keyword*)(intern_rigid_symbol_wrt_module("RETRACT-FALSE", NULL, 2)));
            SYM_PROPOSITIONS_STRICT_INFERENCE_CACHE = ((Symbol*)(intern_rigid_symbol_wrt_module("STRICT-INFERENCE-CACHE", NULL, 0)));
            SGT_PROPOSITIONS_MODULE = ((Surrogate*)(intern_rigid_symbol_wrt_module("MODULE", string_get_module("/STELLA", TRUE), 1)));
            KWD_PROPOSITIONS_STRICT = ((Keyword*)(intern_rigid_symbol_wrt_module("STRICT", NULL, 2)));
            KWD_PROPOSITIONS_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            KWD_PROPOSITIONS_CONSTANT = ((Keyword*)(intern_rigid_symbol_wrt_module("CONSTANT", NULL, 2)));
            SYM_PROPOSITIONS_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 0)));
            KWD_PROPOSITIONS_PRIMITIVE = ((Keyword*)(intern_rigid_symbol_wrt_module("PRIMITIVE", NULL, 2)));
            SGT_PROPOSITIONS_STORAGE_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT", string_get_module("/STELLA", TRUE), 1)));
            SYM_PROPOSITIONS_COMPLEMENT_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("COMPLEMENT-DESCRIPTION", NULL, 0)));
            KWD_PROPOSITIONS_IN = ((Keyword*)(intern_rigid_symbol_wrt_module("IN", NULL, 2)));
            SGT_PROPOSITIONS_UNKNOWN = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNKNOWN", string_get_module("/STELLA", TRUE), 1)));
            SGT_PROPOSITIONS_RELATION = ((Surrogate*)(intern_rigid_symbol_wrt_module("RELATION", string_get_module("/STELLA", TRUE), 1)));
            SYM_PROPOSITIONS_oFREESKOLEMSo = ((Symbol*)(intern_rigid_symbol_wrt_module("*FREESKOLEMS*", NULL, 0)));
            SYM_PROPOSITIONS_SKOLEM_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SKOLEM-NAME", NULL, 0)));
            SGT_PROPOSITIONS_COLLECTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION", string_get_module("/STELLA", TRUE), 1)));
            SGT_PROPOSITIONS_SURROGATE = ((Surrogate*)(intern_rigid_symbol_wrt_module("SURROGATE", string_get_module("/STELLA", TRUE), 1)));
            KWD_PROPOSITIONS_AND = ((Keyword*)(intern_rigid_symbol_wrt_module("AND", NULL, 2)));
            KWD_PROPOSITIONS_OR = ((Keyword*)(intern_rigid_symbol_wrt_module("OR", NULL, 2)));
            SGT_PROPOSITIONS_TRUE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRUE", string_get_module("/STELLA", TRUE), 1)));
            SGT_PROPOSITIONS_FALSE = ((Surrogate*)(intern_rigid_symbol_wrt_module("FALSE", string_get_module("/STELLA", TRUE), 1)));
            SYM_PROPOSITIONS_PERMUTATION_TABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("PERMUTATION-TABLE", NULL, 0)));
            KWD_PROPOSITIONS_NOT = ((Keyword*)(intern_rigid_symbol_wrt_module("NOT", NULL, 2)));
            KWD_PROPOSITIONS_EQUIVALENT = ((Keyword*)(intern_rigid_symbol_wrt_module("EQUIVALENT", NULL, 2)));
            KWD_PROPOSITIONS_PREDICATE = ((Keyword*)(intern_rigid_symbol_wrt_module("PREDICATE", NULL, 2)));
            SGT_PROPOSITIONS_TRAP_DOOR_SURROGATE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRAP-DOOR-SURROGATE", NULL, 1)));
            SYM_PROPOSITIONS_SETOFALL = ((Symbol*)(intern_rigid_symbol_wrt_module("SETOFALL", NULL, 0)));
            SYM_PROPOSITIONS_THE_ONLY = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-ONLY", NULL, 0)));
            SYM_PROPOSITIONS_KAPPA = ((Symbol*)(intern_rigid_symbol_wrt_module("KAPPA", NULL, 0)));
            SYM_PROPOSITIONS_SETOF = ((Symbol*)(intern_rigid_symbol_wrt_module("SETOF", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_LISTOF = ((Symbol*)(intern_rigid_symbol_wrt_module("LISTOF", NULL, 0)));
            SYM_PROPOSITIONS_CREATE = ((Symbol*)(intern_rigid_symbol_wrt_module("CREATE", NULL, 0)));
            KWD_PROPOSITIONS_INTENSIONAL_ASSERTION = ((Keyword*)(intern_rigid_symbol_wrt_module("INTENSIONAL-ASSERTION", NULL, 2)));
            SYM_PROPOSITIONS_p = ((Symbol*)(intern_rigid_symbol_wrt_module("?", NULL, 0)));
            SYM_PROPOSITIONS_EVALUATOR_WRAPPER_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("EVALUATOR-WRAPPER-CODE", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_NON_DISJOINTNESS_KLUDGEp = ((Symbol*)(intern_rigid_symbol_wrt_module("NON-DISJOINTNESS-KLUDGE?", NULL, 0)));
            SYM_PROPOSITIONS_CLASS_EXTENSION = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-EXTENSION", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_TRANSFER_LOGIC_INFORMATION_FROM_RELATION_HOOK = ((Symbol*)(intern_rigid_symbol_wrt_module("TRANSFER-LOGIC-INFORMATION-FROM-RELATION-HOOK", NULL, 0)));
            SYM_PROPOSITIONS_IMPLIES = ((Symbol*)(intern_rigid_symbol_wrt_module("IMPLIES", NULL, 0)));
            SYM_PROPOSITIONS_RELATION_ORIGINATED_PROPOSITIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("RELATION-ORIGINATED-PROPOSITIONS", NULL, 0)));
            SYM_PROPOSITIONS_ISA = ((Symbol*)(intern_rigid_symbol_wrt_module("ISA", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_SURROGATE_VALUE_INVERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE-VALUE-INVERSE", NULL, 0)));
            SYM_PROPOSITIONS_oPROPOSITIONUNDERCONSTRUCTIONo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PROPOSITIONUNDERCONSTRUCTION*", NULL, 0)));
            SYM_PROPOSITIONS_oTOPLEVELPROPOSITIONSo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TOPLEVELPROPOSITIONS*", NULL, 0)));
            SGT_PROPOSITIONS_STRING_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("STRING-WRAPPER", string_get_module("/STELLA", TRUE), 1)));
            SGT_PROPOSITIONS_LOGIC_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-EXCEPTION", NULL, 1)));
            KWD_PROPOSITIONS_EXCEPTIONS = ((Keyword*)(intern_rigid_symbol_wrt_module("EXCEPTIONS", NULL, 2)));
            SGT_PROPOSITIONS_READ_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("READ-EXCEPTION", string_get_module("/STELLA", TRUE), 1)));
            SYM_PROPOSITIONS_CONSTANT = ((Symbol*)(intern_rigid_symbol_wrt_module("CONSTANT", NULL, 0)));
            SYM_PROPOSITIONS_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", string_get_module("/STELLA", TRUE), 0)));
            SGT_PROPOSITIONS_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("SYMBOL", string_get_module("/STELLA", TRUE), 1)));
            SYM_PROPOSITIONS_e = ((Symbol*)(intern_rigid_symbol_wrt_module("=", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_AND = ((Symbol*)(intern_rigid_symbol_wrt_module("AND", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_OR = ((Symbol*)(intern_rigid_symbol_wrt_module("OR", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_NOT = ((Symbol*)(intern_rigid_symbol_wrt_module("NOT", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_IN = ((Symbol*)(intern_rigid_symbol_wrt_module("IN", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_SUBSET_OF = ((Symbol*)(intern_rigid_symbol_wrt_module("SUBSET-OF", NULL, 0)));
            SYM_PROPOSITIONS_EXISTS = ((Symbol*)(intern_rigid_symbol_wrt_module("EXISTS", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_FORALL = ((Symbol*)(intern_rigid_symbol_wrt_module("FORALL", string_get_module("/STELLA", TRUE), 0)));
            KWD_PROPOSITIONS_EXISTS = ((Keyword*)(intern_rigid_symbol_wrt_module("EXISTS", NULL, 2)));
            SYM_PROPOSITIONS_EQUIVALENT = ((Symbol*)(intern_rigid_symbol_wrt_module("EQUIVALENT", NULL, 0)));
            SGT_PROPOSITIONS_FUNCTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("FUNCTION", string_get_module("/STELLA", TRUE), 1)));
            SYM_PROPOSITIONS_SECOND_ORDER = ((Symbol*)(intern_rigid_symbol_wrt_module("SECOND-ORDER", NULL, 0)));
            SGT_PROPOSITIONS_ANY = ((Surrogate*)(intern_rigid_symbol_wrt_module("ANY", string_get_module("/STELLA", TRUE), 1)));
            SGT_PROPOSITIONS_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", string_get_module("/STELLA", TRUE), 1)));
            SGT_PROPOSITIONS_BOOLEAN_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN-WRAPPER", string_get_module("/STELLA", TRUE), 1)));
            KWD_PROPOSITIONS_FORALL = ((Keyword*)(intern_rigid_symbol_wrt_module("FORALL", NULL, 2)));
            SYM_PROPOSITIONS_ALWAYS = ((Symbol*)(intern_rigid_symbol_wrt_module("ALWAYS", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_WHERE = ((Symbol*)(intern_rigid_symbol_wrt_module("WHERE", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_SOME = ((Symbol*)(intern_rigid_symbol_wrt_module("SOME", string_get_module("/STELLA", TRUE), 0)));
            SYM_PROPOSITIONS_DELETED_OBJECTp = ((Symbol*)(intern_rigid_symbol_wrt_module("DELETED-OBJECT?", string_get_module("/STELLA", TRUE), 0)));
            KWD_PROPOSITIONS_DELETED = ((Keyword*)(intern_rigid_symbol_wrt_module("DELETED", NULL, 2)));
            SYM_PROPOSITIONS_DEFINITION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINITION", NULL, 0)));
            SYM_PROPOSITIONS_CLEAR_LOGIC_MODULE_HOOK = ((Symbol*)(intern_rigid_symbol_wrt_module("CLEAR-LOGIC-MODULE-HOOK", NULL, 0)));
            SYM_PROPOSITIONS_TOTALp = ((Symbol*)(intern_rigid_symbol_wrt_module("TOTAL?", NULL, 0)));
            SYM_PROPOSITIONS_INDEX_ON_VALUESp = ((Symbol*)(intern_rigid_symbol_wrt_module("INDEX-ON-VALUES?", NULL, 0)));
          }
          if (current_startup_time_phaseP(4)) {
            ZERO_VARIABLES_VECTOR = new_vector(0);
            oLAST_KB_ACTIONo = KWD_PROPOSITIONS_UPDATE_PROPOSITION;
            BOTTOM = create_skolem(NULL, SYM_PROPOSITIONS_BOTTOM);
            oEVALUATIONMODEo = KWD_PROPOSITIONS_EXTENSIONAL_ASSERTION;
            TRUE_TRUTH_VALUE = new_truth_value();
            FALSE_TRUTH_VALUE = new_truth_value();
            { Proposition* self_019 = new_proposition();

              self_019->kind = KWD_PROPOSITIONS_CONSTANT;
              self_019->renamed_Operator = SGT_PROPOSITIONS_TRUE;
              self_019->arguments = new_vector(0);
              { Proposition* object_021 = self_019;
                Truth_Value* value_022 = TRUE_TRUTH_VALUE;
                Object* old_value_023 = object_021->truth_value;
                Object* new_value_024 = update_in_context(old_value_023, value_022, object_021, FALSE);

                if (!cs_valueP(old_value_023)) {
                  object_021->truth_value = new_value_024;
                }
              }
              TRUE_PROPOSITION = self_019;
            }
            { Proposition* self_025 = new_proposition();

              self_025->kind = KWD_PROPOSITIONS_CONSTANT;
              self_025->renamed_Operator = SGT_PROPOSITIONS_FALSE;
              self_025->arguments = new_vector(0);
              { Proposition* object_027 = self_025;
                Truth_Value* value_028 = FALSE_TRUTH_VALUE;
                Object* old_value_029 = object_027->truth_value;
                Object* new_value_030 = update_in_context(old_value_029, value_028, object_027, FALSE);

                if (!cs_valueP(old_value_029)) {
                  object_027->truth_value = new_value_030;
                }
              }
              FALSE_PROPOSITION = self_025;
            }
            ANONYMOUS_VARIABLE_NAME = SYM_PROPOSITIONS_p;
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("LOGIC-OBJECT", "(DEFCLASS LOGIC-OBJECT (CONTEXT-SENSITIVE-OBJECT DYNAMIC-SLOTS-MIXIN) :DOCUMENTATION \"Object with propositions, and possibly a variable value.\" :SLOTS ((ROOT-TYPE :TYPE TYPE) (ALL-ROOT-TYPES :TYPE (LIST OF TYPE) :ALLOCATION :DYNAMIC) (DEPENDENT-ATTRIBUTE-PROPOSITIONS :TYPE (LIST OF PROPOSITION) :ALLOCATION :EMBEDDED) (DEPENDENT-PROPOSITIONS :TYPE (LIST OF PROPOSITION) :ALLOCATION :EMBEDDED) (VARIABLE-VALUE :TYPE OBJECT :CONTEXT-SENSITIVE? TRUE) (VARIABLE-VALUE-INVERSE :TYPE (CONS OF LOGIC-OBJECT) :DEFAULT NIL :CONTEXT-SENSITIVE? TRUE) (SURROGATE-VALUE-INVERSE :TYPE SURROGATE :ALLOCATION :DYNAMIC) (ALL-SURROGATE-VALUE-INVERSES :TYPE (LIST OF SURROGATE) :ALLOCATION :DYNAMIC)) :PRINT-FORM (PRINT-TOP-LEVEL-OBJECT SELF STREAM))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_logic_object));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_logic_object_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("SKOLEM", "(DEFCLASS SKOLEM (LOGIC-OBJECT) :DOCUMENTATION \"Object whose identity and type are not fixed at creation time.\nPotentially unifiable with any other object.\" :SLOTS ((SKOLEM-TYPE :RENAMES ROOT-TYPE) (SKOLEM-NAME :TYPE SYMBOL :ALLOCATION :DYNAMIC) (NOT-BOTTOM? :TYPE BOOLEAN :CONTEXT-SENSITIVE? TRUE :DEFAULT FALSE) (DEFINING-PROPOSITION :TYPE PROPOSITION)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_skolem));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_skolem_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("PATTERN-VARIABLE", "(DEFCLASS PATTERN-VARIABLE (SKOLEM) :SLOTS ((BOUND-TO-OFFSET :TYPE INTEGER)) :METHODS ((BINDING-TO-CONSTANT ((SELF PATTERN-VARIABLE)) :TYPE OBJECT (RETURN (CHOOSE (NATIVE-VALUE? (VARIABLE-VALUE SELF)) (VARIABLE-VALUE SELF) NULL)))))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_pattern_variable));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_pattern_variable_slot_value));
            }
            define_stella_type_from_stringified_source("(DEFTYPE OBJECT-VECTOR (VECTOR OF OBJECT))");
            define_stella_type_from_stringified_source("(DEFTYPE ARGUMENTS-VECTOR OBJECT-VECTOR)");
            define_stella_type_from_stringified_source("(DEFTYPE VARIABLES-VECTOR (VECTOR OF PATTERN-VARIABLE))");
            { Class* renamed_Class = define_class_from_stringified_source("DESCRIPTION", "(DEFCLASS DESCRIPTION (LOGIC-OBJECT) :SLOTS ((PROPOSITION :TYPE PROPOSITION) (IO-VARIABLES :TYPE VARIABLES-VECTOR) (INTERNAL-VARIABLES :TYPE VARIABLES-VECTOR :INITIALLY ZERO-VARIABLES-VECTOR) (KIND :TYPE KEYWORD) (NATIVE-RELATION :TYPE RELATION) (EXTENSION :TYPE LIST :ALLOCATION :DYNAMIC) (QUERY-PATTERNS :TYPE (KEY-VALUE-LIST OF BOOLEAN-VECTOR DESCRIPTION)) (COMPLEMENT-DESCRIPTION :TYPE DESCRIPTION :ALLOCATION :DYNAMIC) (RELATIVE-COMPLEMENT-DESCRIPTIONS :TYPE (KEY-VALUE-LIST OF TYPE DESCRIPTION) :ALLOCATION :DYNAMIC) (REFERENCED-BY :TYPE (LIST OF DESCRIPTION) :ALLOCATION :EMBEDDED) (TAXONOMY-NODE :TYPE TAXONOMY-NODE) (IOTA? :TYPE BOOLEAN :ALLOCATION :DYNAMIC)) :METHODS ((ARITY ((SELF DESCRIPTION)) :TYPE INTEGER :GLOBALLY-INLINE? TRUE (RETURN (LENGTH (IO-VARIABLES SELF)))) (REPRESENTATIVE ((SELF DESCRIPTION)) :TYPE PATTERN-VARIABLE (RETURN (FIRST (IO-VARIABLES SELF)))) (RELATION? ((SELF DESCRIPTION)) :TYPE BOOLEAN (RETURN (AND (DEFINED? (NATIVE-RELATION SELF)) (ISA? (NATIVE-RELATION SELF) /STELLA/@SLOT) (MEMBER? (QUOTE (/STELLA/@BOOLEAN /STELLA/@BOOLEAN-WRAPPER)) (SLOT-BASE-TYPE (CAST (NATIVE-RELATION SELF) SLOT)))))) (FUNCTION? ((SELF DESCRIPTION)) :TYPE BOOLEAN (RETURN (AND (DEFINED? (NATIVE-RELATION SELF)) (ISA? (NATIVE-RELATION SELF) /STELLA/@SLOT) (NOT (MEMBER? (QUOTE (/STELLA/@BOOLEAN /STELLA/@BOOLEAN-WRAPPER)) (SLOT-BASE-TYPE (CAST (NATIVE-RELATION SELF) SLOT))))))) (DESCRIPTION-SURROGATE ((SELF DESCRIPTION)) :TYPE TYPE (LET ((NATIVERELATION (NATIVE-RELATION SELF))) (WHEN (DEFINED? NATIVERELATION) (TYPECASE NATIVERELATION (CLASS (RETURN (CLASS-TYPE NATIVERELATION))) (SLOT (RETURN (SLOT-SLOTREF NATIVERELATION))) (OTHERWISE NULL))) (RETURN NULL)))))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_description));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_description_slot_value));
            }
            define_stella_type_from_stringified_source("(DEFTYPE PARTIAL-MATCH-SCORE FLOAT)");
            define_stella_type_from_stringified_source("(DEFTYPE SET-OF-SUPPORT LIST)");
            define_stella_type_from_stringified_source("(DEFTYPE TIME-STAMP INTEGER)");
            { Class* renamed_Class = define_class_from_stringified_source("TRUTH-VALUE", "(DEFCLASS TRUTH-VALUE (LOGIC-OBJECT) :SLOTS ((POSITIVE-SCORE :TYPE PARTIAL-MATCH-SCORE :INITIALLY 0.0) (NEGATIVE-SCORE :TYPE PARTIAL-MATCH-SCORE :INITIALLY 0.0) (POSITIVE-SET-OF-SUPPORT :TYPE SET-OF-SUPPORT) (NEGATIVE-SET-OF-SUPPORT :TYPE SET-OF-SUPPORT) (TIME-STAMP :TYPE TIME-STAMP)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_truth_value));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_truth_value_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("PROPOSITION", "(DEFCLASS PROPOSITION (CONTEXT-SENSITIVE-OBJECT DYNAMIC-SLOTS-MIXIN) :DOCUMENTATION \"\" :SLOTS ((KIND :TYPE KEYWORD) (TRUTH-VALUE :TYPE TRUTH-VALUE :CONTEXT-SENSITIVE? TRUE) (ARGUMENTS :TYPE VECTOR) (OPERATOR :TYPE OBJECT) (SLOTREF :TYPE SLOTREF :RENAMES OPERATOR) (DEPENDENT-PROPOSITIONS :TYPE (LIST OF PROPOSITION) :ALLOCATION :EMBEDDED) (IO-VARIABLES :TYPE VARIABLES-VECTOR :ALLOCATION :DYNAMIC) (VARIABLE-TYPE? :TYPE BOOLEAN :ALLOCATION :DYNAMIC) (SUBRELATION-LINK? :TYPE BOOLEAN :ALLOCATION :DYNAMIC) (SUBSUMPTION-LINK? :TYPE BOOLEAN :ALLOCATION :DYNAMIC) (SURROGATE-VALUE-INVERSE :TYPE SURROGATE :ALLOCATION :DYNAMIC) (SATELLITE-PROPOSITIONS :TYPE (LIST OF PROPOSITION) :ALLOCATION :DYNAMIC) (MASTER-PROPOSITION :TYPE PROPOSITION :ALLOCATION :DYNAMIC) (DONT-OPTIMIZE? :TYPE BOOLEAN :ALLOCATION :DYNAMIC) (FORWARD-ONLY? :TYPE BOOLEAN :ALLOCATION :DYNAMIC) (BACKWARD-ONLY? :TYPE BOOLEAN :ALLOCATION :DYNAMIC)) :PRINT-FORM (PRINT-TOP-LEVEL-OBJECT SELF STREAM))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_proposition));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_proposition_slot_value));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("CREATE-PROPOSITION", "SYMBOL", "(DEFUN (CREATE-PROPOSITION PROPOSITION) ((KIND SYMBOL) (ARGUMENTCOUNT INTEGER)))");

              method->function_code = ((cpp_function_code)(&create_proposition));
            }
            define_external_slot_from_stringified_source("(DEFSLOT CONTEXT CONTEXT-ASSUMED-PROPOSITIONS :TYPE (LIST OF PROPOSITION) :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT MODULE LOCALLY-CONCEIVED-PROPOSITIONS :TYPE (LIST OF PROPOSITION) :READER LOCALLY-CONCEIVED-PROPOSITIONS-GETTER :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT MODULE STRICT-INFERENCE-CACHE :TYPE WORLD :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT MODULE DEFAULT-INFERENCE-CACHE :TYPE WORLD :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT WORLD MONOTONIC? :TYPE BOOLEAN :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT WORLD TRUTH-MAINTAINED? :TYPE BOOLEAN :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT WORLD UP-TO-DATE-INFERENCES? :TYPE BOOLEAN :ALLOCATION :DYNAMIC)");
            { Method_Slot* method = define_method_from_stringified_source("LOCALLY-CONCEIVED-PROPOSITIONS-GETTER", "MODULE", "(DEFMETHOD (LOCALLY-CONCEIVED-PROPOSITIONS-GETTER (LIST OF PROPOSITION)) ((SELF MODULE)))");

              method->method_code = ((cpp_method_code)(&Module::locally_conceived_propositions_getter));
            }
            define_external_slot_from_stringified_source("(DEFSLOT WORLD LOCALLY-BOUND-PROPOSITIONS :TYPE (LIST OF PROPOSITION) :READER LOCALLY-BOUND-PROPOSITIONS-GETTER :ALLOCATION :DYNAMIC)");
            { Method_Slot* method = define_method_from_stringified_source("LOCALLY-BOUND-PROPOSITIONS-GETTER", "WORLD", "(DEFMETHOD (LOCALLY-BOUND-PROPOSITIONS-GETTER (LIST OF PROPOSITION)) ((SELF WORLD)))");

              method->method_code = ((cpp_method_code)(&World::locally_bound_propositions_getter));
            }
            define_external_slot_from_stringified_source("(DEFSLOT WORLD LOCALLY-BOUND-SKOLEMS :TYPE (LIST OF SKOLEM) :READER LOCALLY-BOUND-SKOLEMS-GETTER :ALLOCATION :DYNAMIC)");
            { Method_Slot* method = define_method_from_stringified_source("LOCALLY-BOUND-SKOLEMS-GETTER", "WORLD", "(DEFMETHOD (LOCALLY-BOUND-SKOLEMS-GETTER (LIST OF SKOLEM)) ((SELF WORLD)))");

              method->method_code = ((cpp_method_code)(&World::locally_bound_skolems_getter));
            }
            { Method_Slot* method = define_method_from_stringified_source("INCREMENT-NOW-TIME-STAMP", NULL, "(DEFUN INCREMENT-NOW-TIME-STAMP ())");

              method->function_code = ((cpp_function_code)(&increment_now_time_stamp));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-NOW-TIME-STAMP", NULL, "(DEFUN (GET-NOW-TIME-STAMP TIME-STAMP) ())");

              method->function_code = ((cpp_function_code)(&get_now_time_stamp));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPDATE-NOW-TIME-STAMP", "KEYWORD", "(DEFUN UPDATE-NOW-TIME-STAMP ((KBACTION KEYWORD)))");

              method->function_code = ((cpp_function_code)(&update_now_time_stamp));
            }
            { Method_Slot* method = define_method_from_stringified_source("BOTTOM?", "OBJECT", "(DEFUN (BOTTOM? BOOLEAN) ((SELF OBJECT)) :DOCUMENTATION \"Return TRUE if 'self' is the undefined individual BOTTOM.\")");

              method->function_code = ((cpp_function_code)(&bottomP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MONADIC?", "LOGIC-OBJECT", "(DEFMETHOD (MONADIC? BOOLEAN) ((SELF LOGIC-OBJECT)))");

              method->method_code = ((cpp_method_code)(&Logic_Object::monadicP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MONADIC?", "COLLECTION", "(DEFMETHOD (MONADIC? BOOLEAN) ((SELF COLLECTION)))");

              method->method_code = ((cpp_method_code)(&Collection::monadicP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MONADIC?", "DESCRIPTION", "(DEFMETHOD (MONADIC? BOOLEAN) ((SELF DESCRIPTION)) :GLOBALLY-INLINE? TRUE)");

              method->method_code = ((cpp_method_code)(&Description::monadicP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOGIC-SLOT?", "SLOT", "(DEFUN (LOGIC-SLOT? BOOLEAN) ((SLOT SLOT)) :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&logic_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TYPE-HAS-BACKLINKS?", "TYPE", "(DEFUN (TYPE-HAS-BACKLINKS? BOOLEAN) ((TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&type_has_backlinksP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NO-BACKLINKS?", "OBJECT", "(DEFUN (NO-BACKLINKS? BOOLEAN) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&no_backlinksP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOGIC-OBJECT-PERMITS-BACKLINKS?", "LOGIC-OBJECT", "(DEFUN (LOGIC-OBJECT-PERMITS-BACKLINKS? BOOLEAN) ((OBJECT LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&logic_object_permits_backlinksP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLOSED?", "SLOT", "(DEFMETHOD (CLOSED? BOOLEAN) ((SELF SLOT)) :DOCUMENTATION \"Return TRUE if the closed world assumption applies to\na function or relation.\")");

              method->method_code = ((cpp_method_code)(&Slot::closedP));
            }
            { Method_Slot* method = define_method_from_stringified_source("OPEN-WORLD?", "SLOT", "(DEFMETHOD (OPEN-WORLD? BOOLEAN) ((SELF SLOT)) :DOCUMENTATION \"Return TRUE if the closed world assumption does not\napply to a function or relation.\")");

              method->method_code = ((cpp_method_code)(&Slot::open_worldP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIPTION-MODE?", NULL, "(DEFUN (DESCRIPTION-MODE? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&description_modeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONCEIVING-UPDATE?", "KEYWORD", "(DEFUN (CONCEIVING-UPDATE? BOOLEAN) ((UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&conceiving_updateP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIPTIVE-UPDATE?", "KEYWORD", "(DEFUN (DESCRIPTIVE-UPDATE? BOOLEAN) ((UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&descriptive_updateP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PROPAGATE-CONSTRAINTS-INCREMENTALLY?", "WORLD", "(DEFUN (PROPAGATE-CONSTRAINTS-INCREMENTALLY? BOOLEAN) ((SELF WORLD)))");

              method->function_code = ((cpp_function_code)(&propagate_constraints_incrementallyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTEXT-DEPENDENT-SEARCH-MODE?", NULL, "(DEFUN (CONTEXT-DEPENDENT-SEARCH-MODE? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&context_dependent_search_modeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOG-NEWLY-CONCEIVED-PROPOSITION", "MODULE", "(DEFUN LOG-NEWLY-CONCEIVED-PROPOSITION ((SELF MODULE) (PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&log_newly_conceived_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOG-NEWLY-BOUND-PROPOSITION", "CONTEXT", "(DEFMETHOD LOG-NEWLY-BOUND-PROPOSITION ((SELF CONTEXT) (PROPOSITION PROPOSITION)))");

              method->method_code = ((cpp_method_code)(&Context::log_newly_bound_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOG-NEWLY-BOUND-PROPOSITION", "WORLD", "(DEFMETHOD LOG-NEWLY-BOUND-PROPOSITION ((SELF WORLD) (PROPOSITION PROPOSITION)))");

              method->method_code = ((cpp_method_code)(&World::log_newly_bound_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-GOES-TRUE-DEMONS", "PROPOSITION", "(DEFUN RUN-GOES-TRUE-DEMONS ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&run_goes_true_demons));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-GOES-FALSE-DEMONS", "PROPOSITION", "(DEFUN RUN-GOES-FALSE-DEMONS ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&run_goes_false_demons));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-GOES-UNKNOWN-DEMONS", "PROPOSITION", "(DEFUN RUN-GOES-UNKNOWN-DEMONS ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&run_goes_unknown_demons));
            }
            { Method_Slot* method = define_method_from_stringified_source("REACT-TO-PROPOSITION-UPDATE", "PROPOSITION", "(DEFUN REACT-TO-PROPOSITION-UPDATE ((PROPOSITION PROPOSITION) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&react_to_proposition_update));
            }
            { Method_Slot* method = define_method_from_stringified_source("PROPAGATE-KB-CONSTRAINTS", "OBJECT", "(DEFMETHOD PROPAGATE-KB-CONSTRAINTS ((SELF OBJECT) (CONTEXT CONTEXT)))");

              method->method_code = ((cpp_method_code)(&Object::propagate_kb_constraints));
            }
            { Method_Slot* method = define_method_from_stringified_source("PROPAGATE-KB-CONSTRAINTS", "SKOLEM", "(DEFMETHOD PROPAGATE-KB-CONSTRAINTS ((SELF SKOLEM) (CONTEXT CONTEXT)))");

              method->method_code = ((cpp_method_code)(&Skolem::propagate_kb_constraints));
            }
            { Method_Slot* method = define_method_from_stringified_source("PROPAGATE-KB-CONSTRAINTS", "PROPOSITION", "(DEFMETHOD PROPAGATE-KB-CONSTRAINTS ((SELF PROPOSITION) (CONTEXT CONTEXT)))");

              method->method_code = ((cpp_method_code)(&Proposition::propagate_kb_constraints));
            }
            { Method_Slot* method = define_method_from_stringified_source("REACT-TO-KB-UPDATE", "CONTEXT", "(DEFMETHOD REACT-TO-KB-UPDATE ((SELF CONTEXT) (OBJECT OBJECT)))");

              method->method_code = ((cpp_method_code)(&Context::react_to_kb_update));
            }
            { Method_Slot* method = define_method_from_stringified_source("REACT-TO-KB-UPDATE", "MODULE", "(DEFMETHOD REACT-TO-KB-UPDATE ((SELF MODULE) (OBJECT OBJECT)))");

              method->method_code = ((cpp_method_code)(&Module::react_to_kb_update));
            }
            { Method_Slot* method = define_method_from_stringified_source("REACT-TO-KB-UPDATE", "WORLD", "(DEFMETHOD REACT-TO-KB-UPDATE ((SELF WORLD) (OBJECT OBJECT)))");

              method->method_code = ((cpp_method_code)(&World::react_to_kb_update));
            }
            { Method_Slot* method = define_method_from_stringified_source("ASSIGN-TRUTH-VALUE", "PROPOSITION", "(DEFUN ASSIGN-TRUTH-VALUE ((SELF PROPOSITION) (VALUE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&assign_truth_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEASSIGN-TRUTH-VALUE", "PROPOSITION", "(DEFUN DEASSIGN-TRUTH-VALUE ((SELF PROPOSITION) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&deassign_truth_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPDATE-PROPOSITION-TRUTH-VALUE", "PROPOSITION", "(DEFUN UPDATE-PROPOSITION-TRUTH-VALUE ((SELF PROPOSITION) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&update_proposition_truth_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-SLOT-INFERENCE-DEMONS", "OBJECT", "(DEFUN RUN-SLOT-INFERENCE-DEMONS ((SELF OBJECT) (SLOT STORAGE-SLOT) (OLDVALUE OBJECT) (NEWVALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&run_slot_inference_demons));
            }
            { Method_Slot* method = define_method_from_stringified_source("REACT-TO-ATTRIBUTE-PROPOSITION-UPDATE", "SKOLEM", "(DEFUN REACT-TO-ATTRIBUTE-PROPOSITION-UPDATE ((SKOLEM SKOLEM) (OLDVALUE OBJECT) (NEWVALUE OBJECT) (TOPLEVELUPDATE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&react_to_attribute_proposition_update));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRIMITIVE-SLOT?", "SLOT", "(DEFUN (PRIMITIVE-SLOT? BOOLEAN) ((SLOT SLOT)) :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&primitive_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ATTRIBUTE-PROPOSITION?", "PROPOSITION", "(DEFUN (ATTRIBUTE-PROPOSITION? BOOLEAN) ((PROPOSITION PROPOSITION)) :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&attribute_propositionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-DEPENDENT-PROPOSITION-LINK", "OBJECT", "(DEFUN ADD-DEPENDENT-PROPOSITION-LINK ((SELF OBJECT) (PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&add_dependent_proposition_link));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-DEPENDENT-PROPOSITION-LINK", "OBJECT", "(DEFUN REMOVE-DEPENDENT-PROPOSITION-LINK ((SELF OBJECT) (PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&remove_dependent_proposition_link));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOTREF-LESS-OR-EQUAL?", "SLOTREF", "(DEFUN (SLOTREF-LESS-OR-EQUAL? BOOLEAN) ((SLOT1 SLOTREF) (SLOT2 SLOTREF)))");

              method->function_code = ((cpp_function_code)(&slotref_less_or_equalP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOTREF-LESS-THAN?", "SLOTREF", "(DEFUN (SLOTREF-LESS-THAN? BOOLEAN) ((SLOT1 SLOTREF) (SLOT2 SLOTREF)))");

              method->function_code = ((cpp_function_code)(&slotref_less_thanP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT-SORTED-BY-SLOTREF", "LIST", "(DEFUN INSERT-SORTED-BY-SLOTREF ((SELF (LIST OF PROPOSITION)) (PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&insert_sorted_by_slotref));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-DEPENDENT-ATTRIBUTE-LINK", "LOGIC-OBJECT", "(DEFUN ADD-DEPENDENT-ATTRIBUTE-LINK ((OBJECT LOGIC-OBJECT) (PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&add_dependent_attribute_link));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-DEPENDENT-ATTRIBUTE-LINK", "LOGIC-OBJECT", "(DEFUN REMOVE-DEPENDENT-ATTRIBUTE-LINK ((OBJECT LOGIC-OBJECT) (PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&remove_dependent_attribute_link));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-UNDEFINED-SLOT-VALUE-FAILURE", "OBJECT", "(DEFUN SIGNAL-UNDEFINED-SLOT-VALUE-FAILURE ((OBJECT OBJECT) (SLOTREF SLOTREF)))");

              method->function_code = ((cpp_function_code)(&signal_undefined_slot_value_failure));
            }
            { Method_Slot* method = define_method_from_stringified_source("ASSIGN-ATTRIBUTE-VALUE", "STANDARD-OBJECT", "(DEFUN ASSIGN-ATTRIBUTE-VALUE ((SELF STANDARD-OBJECT) (SLOT STORAGE-SLOT) (VALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&assign_attribute_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-ATTRIBUTE-VALUE", "STANDARD-OBJECT", "(DEFUN CLEAR-ATTRIBUTE-VALUE ((OBJECT STANDARD-OBJECT) (SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&clear_attribute_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("DROP-ATTRIBUTE-VALUE", "STANDARD-OBJECT", "(DEFUN DROP-ATTRIBUTE-VALUE ((SELF STANDARD-OBJECT) (SLOT STORAGE-SLOT) (VALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&drop_attribute_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-SLOTREF-ON-INSTANCE", "OBJECT", "(DEFUN (LOOKUP-SLOTREF-ON-INSTANCE SLOTREF) ((TERM OBJECT) (SLOTNAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&lookup_slotref_on_instance));
            }
            { Method_Slot* method = define_method_from_stringified_source("APPLY-SLOT-TO-NATIVE-ARGUMENTS", "SLOT", "(DEFMETHOD (APPLY-SLOT-TO-NATIVE-ARGUMENTS OBJECT) ((SLOT SLOT) (ARGUMENTS VECTOR)))");

              method->method_code = ((cpp_method_code)(&Slot::apply_slot_to_native_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("APPLY-SLOT-TO-NATIVE-ARGUMENTS", "STORAGE-SLOT", "(DEFMETHOD (APPLY-SLOT-TO-NATIVE-ARGUMENTS OBJECT) ((SLOT STORAGE-SLOT) (ARGUMENTS VECTOR)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::apply_slot_to_native_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("APPLY-SLOT-TO-NATIVE-ARGUMENTS", "METHOD-SLOT", "(DEFMETHOD (APPLY-SLOT-TO-NATIVE-ARGUMENTS OBJECT) ((SLOT METHOD-SLOT) (ARGUMENTS VECTOR)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::apply_slot_to_native_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNBOUND?", "SKOLEM", "(DEFUN (UNBOUND? BOOLEAN) ((SKOLEM SKOLEM)) :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&unboundP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALUE-OF", "OBJECT", "(DEFMETHOD (VALUE-OF OBJECT) ((SELF OBJECT)))");

              method->method_code = ((cpp_method_code)(&Object::value_of));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALUE-OF", "SURROGATE", "(DEFMETHOD (VALUE-OF OBJECT) ((SELF SURROGATE)))");

              method->method_code = ((cpp_method_code)(&Surrogate::value_of));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALUE-OF", "SKOLEM", "(DEFMETHOD (VALUE-OF OBJECT) ((SELF SKOLEM)))");

              method->method_code = ((cpp_method_code)(&Skolem::value_of));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALUE-OF", "RELATION", "(DEFMETHOD (VALUE-OF OBJECT) ((SELF RELATION)))");

              method->method_code = ((cpp_method_code)(&Relation::value_of));
            }
            { Method_Slot* method = define_method_from_stringified_source("SKOLEM?", "OBJECT", "(DEFUN (SKOLEM? BOOLEAN) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&skolemP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VARIABLE?", "OBJECT", "(DEFUN (VARIABLE? BOOLEAN) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&variableP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NATIVE-VALUE?", "OBJECT", "(DEFUN (NATIVE-VALUE? BOOLEAN) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&native_valueP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NATIVE-VALUE-OF", "OBJECT", "(DEFUN (NATIVE-VALUE-OF OBJECT) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&native_value_of));
            }
            { Method_Slot* method = define_method_from_stringified_source("EQUIVALENT-OF", "LOGIC-OBJECT", "(DEFUN (EQUIVALENT-OF LOGIC-OBJECT) ((SELF LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&equivalent_of));
            }
            { Method_Slot* method = define_method_from_stringified_source("INNERMOST-VARIABLE-OF", "PATTERN-VARIABLE", "(DEFUN (INNERMOST-VARIABLE-OF PATTERN-VARIABLE) ((SELF PATTERN-VARIABLE)))");

              method->function_code = ((cpp_function_code)(&innermost_variable_of));
            }
            { Method_Slot* method = define_method_from_stringified_source("INNERMOST-OF", "OBJECT", "(DEFUN (INNERMOST-OF OBJECT) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&innermost_of));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-FUNCTION-VALUE", "PROPOSITION", "(DEFUN (COMPUTE-FUNCTION-VALUE OBJECT) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&compute_function_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("LAST-ARGUMENT", "PROPOSITION", "(DEFUN (LAST-ARGUMENT OBJECT) ((PROPOSITION PROPOSITION)) :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&last_argument));
            }
            { Method_Slot* method = define_method_from_stringified_source("FUNCTION-VALUE", "PROPOSITION", "(DEFUN (FUNCTION-VALUE OBJECT) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&function_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("FUNCTION-REPRESENTATIVE", "PROPOSITION", "(DEFUN (FUNCTION-REPRESENTATIVE OBJECT) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&function_representative));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-PREDICATE-VALUE", "PROPOSITION", "(DEFUN (COMPUTE-PREDICATE-VALUE BOOLEAN BOOLEAN) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&compute_predicate_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-ANONYMOUS-SKOLEM-NAME", "BOOLEAN", "(DEFUN (YIELD-ANONYMOUS-SKOLEM-NAME SYMBOL) ((VARIABLE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&yield_anonymous_skolem_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-CREATE-SKOLEM", "SKOLEM", "(DEFUN (HELP-CREATE-SKOLEM SKOLEM) ((SELF SKOLEM) (TYPE TYPE) (NAME SYMBOL) (ASSERTIN? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&help_create_skolem));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-SKOLEM", "TYPE", "(DEFUN (CREATE-SKOLEM SKOLEM) ((TYPE TYPE) (NAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&create_skolem));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-VARIABLE", "TYPE", "(DEFUN (CREATE-VARIABLE PATTERN-VARIABLE) ((TYPE TYPE) (NAME SYMBOL) (ASSERTIN? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&create_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRUE?", "PROPOSITION", "(DEFUN (TRUE? BOOLEAN) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&trueP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FALSE?", "PROPOSITION", "(DEFUN (FALSE? BOOLEAN) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&falseP));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNKNOWN?", "PROPOSITION", "(DEFUN (UNKNOWN? BOOLEAN) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&unknownP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-UNIFICATION-CLASH", "OBJECT", "(DEFUN SIGNAL-UNIFICATION-CLASH ((TERM1 OBJECT) (TERM2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&signal_unification_clash));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-VARIABLE-VALUE-CLASH", "SKOLEM", "(DEFUN SIGNAL-VARIABLE-VALUE-CLASH ((SKOLEM SKOLEM) (VALUE1 OBJECT) (VALUE2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&signal_variable_value_clash));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-TRUTH-VALUE-CLASH", "PROPOSITION", "(DEFUN SIGNAL-TRUTH-VALUE-CLASH ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&signal_truth_value_clash));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-FAIL", NULL, "(DEFUN SIGNAL-FAIL ())");

              method->function_code = ((cpp_function_code)(&signal_fail));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOGICAL-TYPE", "OBJECT", "(DEFUN (LOGICAL-TYPE TYPE) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&logical_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNIFY-TYPES", "SKOLEM", "(DEFUN UNIFY-TYPES ((TERM1 SKOLEM) (TERM2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&unify_types));
            }
            { Method_Slot* method = define_method_from_stringified_source("SCAN-FOR-ATTRIBUTES-CLASH", "LIST", "(DEFUN SCAN-FOR-ATTRIBUTES-CLASH ((ATTRIBUTES1 (LIST OF PROPOSITION)) (ATTRIBUTES2 (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&scan_for_attributes_clash));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNIFY-ATTRIBUTE-PROPOSITIONS", "LIST", "(DEFUN UNIFY-ATTRIBUTE-PROPOSITIONS ((ATTRIBUTES1 (LIST OF PROPOSITION)) (ATTRIBUTES2 (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&unify_attribute_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNIFY-SKOLEM-AND-VALUE", "SKOLEM", "(DEFUN UNIFY-SKOLEM-AND-VALUE ((SKOLEM SKOLEM) (VALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&unify_skolem_and_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("BIND-SKOLEM-TO-VALUE", "SKOLEM", "(DEFUN BIND-SKOLEM-TO-VALUE ((FROMSKOLEM SKOLEM) (TOVALUE OBJECT) (TOPLEVELUPDATE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&bind_skolem_to_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNBIND-SKOLEM-VALUE", "SKOLEM", "(DEFUN UNBIND-SKOLEM-VALUE ((SKOLEM SKOLEM) (TOPLEVELUPDATE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&unbind_skolem_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONSTRAIN-AS-SUBSET", "SEQUENCE", "(DEFUN CONSTRAIN-AS-SUBSET ((SET1 SEQUENCE) (SET2 SEQUENCE)))");

              method->function_code = ((cpp_function_code)(&constrain_as_subset));
            }
            { Method_Slot* method = define_method_from_stringified_source("EQUATE-COLLECTIONS", "COLLECTION", "(DEFUN EQUATE-COLLECTIONS ((COL1 COLLECTION) (COL2 COLLECTION)))");

              method->function_code = ((cpp_function_code)(&equate_collections));
            }
            { Method_Slot* method = define_method_from_stringified_source("EQUATE-VALUES", "OBJECT", "(DEFUN EQUATE-VALUES ((TERM1 OBJECT) (TERM2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&equate_values));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNEQUATE-VALUES?", "OBJECT", "(DEFUN (UNEQUATE-VALUES? BOOLEAN) ((TERM1 OBJECT) (TERM2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&unequate_valuesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIPTION-EQUALS-DESCRIPTION?", "OBJECT", "(DEFUN (DESCRIPTION-EQUALS-DESCRIPTION? BOOLEAN) ((ARG1 OBJECT) (ARG2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&description_equals_descriptionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ARGUMENT-EQUALS-ARGUMENT?", "OBJECT", "(DEFUN (ARGUMENT-EQUALS-ARGUMENT? BOOLEAN) ((ARG1 OBJECT) (ARG2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&argument_equals_argumentP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PROPOSITION-EQL?", "PROPOSITION", "(DEFUN (PROPOSITION-EQL? BOOLEAN) ((SELF PROPOSITION) (OTHER PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&proposition_eqlP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMMUTATIVE-PROPOSITION-EQL?", "PROPOSITION", "(DEFUN (COMMUTATIVE-PROPOSITION-EQL? BOOLEAN) ((SELF PROPOSITION) (OTHER PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&commutative_proposition_eqlP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-DEPENDENTS-OF-SOME-ARGUMENT", "PROPOSITION", "(DEFUN (FIND-DEPENDENTS-OF-SOME-ARGUMENT (LIST OF PROPOSITION)) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&find_dependents_of_some_argument));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-DUPLICATE-PROPOSITION", "PROPOSITION", "(DEFUN (FIND-DUPLICATE-PROPOSITION PROPOSITION) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&find_duplicate_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-AND-PROPOSITION", "PROPOSITION", "(DEFUN EVALUATE-AND-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&evaluate_and_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-OR-PROPOSITION", "PROPOSITION", "(DEFUN EVALUATE-OR-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&evaluate_or_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-NOT-PROPOSITION", "PROPOSITION", "(DEFUN EVALUATE-NOT-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&evaluate_not_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-EQUIVALENT-PROPOSITION", "PROPOSITION", "(DEFUN EVALUATE-EQUIVALENT-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&evaluate_equivalent_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-FUNCTION-PROPOSITION", "PROPOSITION", "(DEFUN EVALUATE-FUNCTION-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&evaluate_function_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-SLOT-PERMUTATIONS", "SLOT", "(DEFMETHOD EVALUATE-SLOT-PERMUTATIONS ((SELF SLOT) (ARGUMENTS (VECTOR OF OBJECT))))");

              method->method_code = ((cpp_method_code)(&Slot::evaluate_slot_permutations));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-SLOT-PERMUTATIONS", "METHOD-SLOT", "(DEFMETHOD EVALUATE-SLOT-PERMUTATIONS ((SELF METHOD-SLOT) (ORIGINALARGUMENTS (VECTOR OF OBJECT))))");

              method->method_code = ((cpp_method_code)(&Method_Slot::evaluate_slot_permutations));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-PREDICATE-PROPOSITION", "PROPOSITION", "(DEFUN EVALUATE-PREDICATE-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&evaluate_predicate_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-PROPOSITION", "PROPOSITION", "(DEFUN EVALUATE-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&evaluate_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-TERM", "OBJECT", "(DEFUN (EVALUATE-TERM OBJECT) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&evaluate_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-WRAPPED-LITERAL-TERM", "LITERAL-WRAPPER", "(DEFUN (EVALUATE-WRAPPED-LITERAL-TERM OBJECT) ((SELF LITERAL-WRAPPER)))");

              method->function_code = ((cpp_function_code)(&evaluate_wrapped_literal_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-SURROGATE-TERM", "SURROGATE", "(DEFUN (EVALUATE-SURROGATE-TERM OBJECT) ((SELF SURROGATE)))");

              method->function_code = ((cpp_function_code)(&evaluate_surrogate_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("ANONYMOUS-VARIABLE?", "SKOLEM", "(DEFUN (ANONYMOUS-VARIABLE? BOOLEAN) ((SELF SKOLEM)))");

              method->function_code = ((cpp_function_code)(&anonymous_variableP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-SYMBOL-TERM", "SYMBOL", "(DEFUN (EVALUATE-SYMBOL-TERM OBJECT) ((SELF SYMBOL)))");

              method->function_code = ((cpp_function_code)(&evaluate_symbol_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-UNDEFINED-TERM", "OBJECT", "(DEFUN SIGNAL-UNDEFINED-TERM ((TERM OBJECT)))");

              method->function_code = ((cpp_function_code)(&signal_undefined_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-SETOF-TERM", "CONS", "(DEFUN (EVALUATE-SETOF-TERM OBJECT) ((TERM CONS)))");

              method->function_code = ((cpp_function_code)(&evaluate_setof_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-CREATE-TERM", "CONS", "(DEFUN (EVALUATE-CREATE-TERM LOGIC-OBJECT) ((TERM CONS)))");

              method->function_code = ((cpp_function_code)(&evaluate_create_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE", "GENERALIZED-SYMBOL", "(DEFUN (CREATE LOGIC-OBJECT) ((TYPE GENERALIZED-SYMBOL) |&REST| (NAME GENERALIZED-SYMBOL)) :DOCUMENTATION \"Create a logic object of logical type `type' and return it.\nIf `name' is also supplied, convert it into a surrogate and bind it to the \nnewly created object.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)");

              method->function_code = ((cpp_function_code)(&create));
              set_dynamic_slot_value(method, SYM_PROPOSITIONS_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&create_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("LEFTMOST-CONCRETE-SUPERCLASS", "CLASS", "(DEFUN (LEFTMOST-CONCRETE-SUPERCLASS CLASS) ((SELF CLASS)))");

              method->function_code = ((cpp_function_code)(&leftmost_concrete_superclass));
            }
            { Method_Slot* method = define_method_from_stringified_source("HAS-MULTIPLE-ROOT-CLASSES?", "CLASS", "(DEFUN (HAS-MULTIPLE-ROOT-CLASSES? BOOLEAN) ((SELF CLASS)))");

              method->function_code = ((cpp_function_code)(&has_multiple_root_classesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-COLLECT-ROOT-CLASSES", "CLASS", "(DEFUN HELP-COLLECT-ROOT-CLASSES ((SELF CLASS) (ALLCLASSESLIST LIST) (BEENTHERE LIST)))");

              method->function_code = ((cpp_function_code)(&help_collect_root_classes));
            }
            define_external_slot_from_stringified_source("(DEFSLOT CLASS NON-DISJOINTNESS-KLUDGE? :TYPE BOOLEAN-WRAPPER :DOCUMENTATION \"True if one or more instances multiply inherits\nfrom this root class and at least one other root class.  Used to\nderail the current 'disjoint-classes?' test.\" :ALLOCATION :DYNAMIC)");
            { Method_Slot* method = define_method_from_stringified_source("ALL-ROOT-CLASSES", "CLASS", "(DEFUN (ALL-ROOT-CLASSES (ITERATOR OF CLASS)) ((SELF CLASS)))");

              method->function_code = ((cpp_function_code)(&all_root_classes));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-DESCRIPTION-EXTENSION", "CLASS", "(DEFUN (GET-DESCRIPTION-EXTENSION (LIST OF LOGIC-OBJECT)) ((ROOTCLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&get_description_extension));
            }
            { Method_Slot* method = define_method_from_stringified_source("INDEXED-BY-LOGICAL-EXTENSIONS?", "LOGIC-OBJECT", "(DEFUN (INDEXED-BY-LOGICAL-EXTENSIONS? BOOLEAN) ((SELF LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&indexed_by_logical_extensionsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPDATE-LOGICAL-CLASS-EXTENSION", "LOGIC-OBJECT", "(DEFMETHOD UPDATE-LOGICAL-CLASS-EXTENSION ((SELF LOGIC-OBJECT) (TYPE TYPE)))");

              method->method_code = ((cpp_method_code)(&Logic_Object::update_logical_class_extension));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPDATE-LOGICAL-CLASS-EXTENSION", "PATTERN-VARIABLE", "(DEFMETHOD UPDATE-LOGICAL-CLASS-EXTENSION ((SELF PATTERN-VARIABLE) (TYPE TYPE)))");

              method->method_code = ((cpp_method_code)(&Pattern_Variable::update_logical_class_extension));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-UPDATE-ROOT-TYPES", "LOGIC-OBJECT", "(DEFUN HELP-UPDATE-ROOT-TYPES ((SELF LOGIC-OBJECT) (NEWROOTTYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&help_update_root_types));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPDATE-ROOT-TYPES", "LOGIC-OBJECT", "(DEFUN UPDATE-ROOT-TYPES ((SELF LOGIC-OBJECT) (TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&update_root_types));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSFER-LOGIC-INFORMATION-FROM-RELATION-HOOK", "LIST", "(DEFUN TRANSFER-LOGIC-INFORMATION-FROM-RELATION-HOOK ((RELATIONSLIST (LIST OF RELATION))))");

              method->function_code = ((cpp_function_code)(&transfer_logic_information_from_relation_hook));
            }
            { Method_Slot* method = define_method_from_stringified_source("RETRACT-RELATION-AXIOMS", "RELATION", "(DEFUN RETRACT-RELATION-AXIOMS ((OLDRELATION RELATION)))");

              method->function_code = ((cpp_function_code)(&retract_relation_axioms));
            }
            { Method_Slot* method = define_method_from_stringified_source("ASSERT-DESCRIPTION-IMPLIES-DESCRIPTION", "DESCRIPTION", "(DEFUN (ASSERT-DESCRIPTION-IMPLIES-DESCRIPTION PROPOSITION) ((SUB DESCRIPTION) (SUPER DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&assert_description_implies_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("ASSERT-IMPLIES-LINK-BETWEEN-RELATIONS", "RELATION", "(DEFUN (ASSERT-IMPLIES-LINK-BETWEEN-RELATIONS PROPOSITION) ((SUB RELATION) (SUPER RELATION)))");

              method->function_code = ((cpp_function_code)(&assert_implies_link_between_relations));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-SUPERRELATION-LINKS", "RELATION", "(DEFUN FINALIZE-SUPERRELATION-LINKS ((SELF RELATION)))");

              method->function_code = ((cpp_function_code)(&finalize_superrelation_links));
            }
            { Method_Slot* method = define_method_from_stringified_source("VERIFY-LOGICAL-AND-NATIVE-TYPES", "TYPE", "(DEFUN (VERIFY-LOGICAL-AND-NATIVE-TYPES TYPE) ((LOGICALTYPE TYPE) (NATIVETYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&verify_logical_and_native_types));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPDATE-ISA-PROPOSITION", "LOGIC-OBJECT", "(DEFUN (UPDATE-ISA-PROPOSITION PROPOSITION) ((SELF LOGIC-OBJECT) (TYPE TYPE) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&update_isa_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("ASSERT-ISA-PROPOSITION", "LOGIC-OBJECT", "(DEFUN (ASSERT-ISA-PROPOSITION PROPOSITION) ((SELF LOGIC-OBJECT) (TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&assert_isa_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPDATE-PROPERTY", "LOGIC-OBJECT", "(DEFUN UPDATE-PROPERTY ((INSTANCE LOGIC-OBJECT) (PROPERTY SYMBOL) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&update_property));
            }
            { Method_Slot* method = define_method_from_stringified_source("ASSERT-PROPERTY", "LOGIC-OBJECT", "(DEFUN ASSERT-PROPERTY ((INSTANCE LOGIC-OBJECT) (PROPERTY SYMBOL)))");

              method->function_code = ((cpp_function_code)(&assert_property));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-LOGIC-OBJECT", "TYPE", "(DEFUN (CREATE-LOGIC-OBJECT LOGIC-OBJECT) ((TYPE TYPE) (NAME SURROGATE) (NATIVEVALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&create_logic_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-TOP-LEVEL-PROPOSITION", "OBJECT", "(DEFUN (BUILD-TOP-LEVEL-PROPOSITION PROPOSITION) ((TREE OBJECT) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&build_top_level_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("FASTEN-DOWN-PROPOSITION", "PROPOSITION", "(DEFUN (FASTEN-DOWN-PROPOSITION PROPOSITION) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&fasten_down_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-PROPOSITION", "OBJECT", "(DEFUN (BUILD-PROPOSITION PROPOSITION) ((TREE OBJECT) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&build_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("SURROGATE.BUILD-PROPOSITION", "SURROGATE", "(DEFUN (SURROGATE.BUILD-PROPOSITION PROPOSITION) ((SELF SURROGATE) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&surrogateDbuild_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYMBOL.BUILD-PROPOSITION", "SYMBOL", "(DEFUN (SYMBOL.BUILD-PROPOSITION PROPOSITION) ((SYMBOL SYMBOL) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&symbolDbuild_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONS.BUILD-PROPOSITION", "CONS", "(DEFUN (CONS.BUILD-PROPOSITION PROPOSITION) ((TREE CONS) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&consDbuild_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("VERIFY-COLLECTION-ARGUMENT", "OBJECT", "(DEFUN VERIFY-COLLECTION-ARGUMENT ((SELF OBJECT) (ORIGINAL OBJECT)))");

              method->function_code = ((cpp_function_code)(&verify_collection_argument));
            }
            { Method_Slot* method = define_method_from_stringified_source("VERIFY-RELATION-ARGUMENT", "OBJECT", "(DEFUN VERIFY-RELATION-ARGUMENT ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&verify_relation_argument));
            }
            { Method_Slot* method = define_method_from_stringified_source("VERIFY-NUMBER-OF-PROPOSITION-ARGUMENTS", "CONS", "(DEFUN VERIFY-NUMBER-OF-PROPOSITION-ARGUMENTS ((TREE CONS) (CORRECTNUMBER INTEGER)))");

              method->function_code = ((cpp_function_code)(&verify_number_of_proposition_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-IN-PROPOSITION", "CONS", "(DEFUN (BUILD-IN-PROPOSITION PROPOSITION) ((TREE CONS) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&build_in_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("EMBED-NEGATION-WITHIN-FUNCTION-INDUCED-EXISTS", "PROPOSITION", "(DEFUN (EMBED-NEGATION-WITHIN-FUNCTION-INDUCED-EXISTS PROPOSITION) ((EXISTSPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&embed_negation_within_function_induced_exists));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-AND-OR-NOT-PROPOSITION", "CONS", "(DEFUN (BUILD-AND-OR-NOT-PROPOSITION PROPOSITION) ((TREE CONS) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&build_and_or_not_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("FUNCTIONAL-TERM?", "OBJECT", "(DEFUN (FUNCTIONAL-TERM? BOOLEAN) ((TERM OBJECT)))");

              method->function_code = ((cpp_function_code)(&functional_termP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLIP-VALUE?", "OBJECT", "(DEFUN (CLIP-VALUE? BOOLEAN) ((TERM1 OBJECT) (TERM2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&clip_valueP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINISH-BUILDING-EQUIVALENCE-PROPOSITION", "OBJECT", "(DEFUN (FINISH-BUILDING-EQUIVALENCE-PROPOSITION PROPOSITION) ((TERM1 OBJECT) (TERM2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&finish_building_equivalence_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBSTITUTE-FUNCTION-FOR-EQUIVALENCE", "PATTERN-VARIABLE", "(DEFUN (SUBSTITUTE-FUNCTION-FOR-EQUIVALENCE PROPOSITION) ((FUNCTIONVARIABLE PATTERN-VARIABLE) (TERM OBJECT)))");

              method->function_code = ((cpp_function_code)(&substitute_function_for_equivalence));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-EQUIVALENCE-PROPOSITION", "CONS", "(DEFUN (BUILD-EQUIVALENCE-PROPOSITION PROPOSITION) ((TREE CONS) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&build_equivalence_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-CONJUNCTION-OF-EQUALITY-PROPOSITIONS", "CONS", "(DEFUN (BUILD-CONJUNCTION-OF-EQUALITY-PROPOSITIONS PROPOSITION) ((TREE CONS) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&build_conjunction_of_equality_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("VERIFY-SECOND-ORDER-VARIABLE", "SKOLEM", "(DEFUN (VERIFY-SECOND-ORDER-VARIABLE SKOLEM) ((VARIABLE SKOLEM) (KIND KEYWORD)))");

              method->function_code = ((cpp_function_code)(&verify_second_order_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-PREDICATE-PROPOSITION", "CONS", "(DEFUN (BUILD-PREDICATE-PROPOSITION PROPOSITION) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&build_predicate_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-EXISTS-PROPOSITION", "CONS", "(DEFUN (BUILD-EXISTS-PROPOSITION PROPOSITION) ((TREE CONS) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&build_exists_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("TOP-LEVEL-EXISTS-PROPOSITION?", "PROPOSITION", "(DEFUN (TOP-LEVEL-EXISTS-PROPOSITION? BOOLEAN) ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&top_level_exists_propositionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-SKOLEMIZED-EXISTS-VARIABLES", "PROPOSITION", "(DEFUN (COLLECT-SKOLEMIZED-EXISTS-VARIABLES (VECTOR OF SKOLEM)) ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&collect_skolemized_exists_variables));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-COLLECT-SKOLEMIZED-EXISTS-VARIABLES?", "PROPOSITION", "(DEFUN (HELP-COLLECT-SKOLEMIZED-EXISTS-VARIABLES? BOOLEAN) ((PROPOSITION PROPOSITION) (RESULT (LIST OF SKOLEM))))");

              method->function_code = ((cpp_function_code)(&help_collect_skolemized_exists_variablesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-FORALL-PROPOSITION", "CONS", "(DEFUN (BUILD-FORALL-PROPOSITION PROPOSITION) ((TREE CONS) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&build_forall_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("VERIFY-IMPLIES-ARGUMENT", "OBJECT", "(DEFUN VERIFY-IMPLIES-ARGUMENT ((SELF OBJECT) (OPERATOR SYMBOL)))");

              method->function_code = ((cpp_function_code)(&verify_implies_argument));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-IMPLIES-PROPOSITION", "CONS", "(DEFUN (BUILD-IMPLIES-PROPOSITION PROPOSITION) ((TREE CONS) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&build_implies_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-DUPLICATE-FUNCTION-PROPOSITION", "SLOTREF", "(DEFUN (FIND-DUPLICATE-FUNCTION-PROPOSITION PROPOSITION) ((SLOTREF SLOTREF) (ARGUMENTS CONS)))");

              method->function_code = ((cpp_function_code)(&find_duplicate_function_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-FUNCTION-PROPOSITION", "SLOTREF", "(DEFUN (CREATE-FUNCTION-PROPOSITION PROPOSITION) ((SLOTREF SLOTREF) (INPUTARGUMENTS CONS)))");

              method->function_code = ((cpp_function_code)(&create_function_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-SECOND-ORDER-FUNCTION-PROPOSITION", "OBJECT", "(DEFUN (CREATE-SECOND-ORDER-FUNCTION-PROPOSITION PROPOSITION) ((VARIABLEFUNCTION OBJECT) (INPUTARGUMENTS CONS)))");

              method->function_code = ((cpp_function_code)(&create_second_order_function_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINISH-EVALUATING-FUNCTION-TERM", "SLOTREF", "(DEFUN (FINISH-EVALUATING-FUNCTION-TERM OBJECT) ((SLOTREF SLOTREF) (INPUTARGUMENTS CONS)))");

              method->function_code = ((cpp_function_code)(&finish_evaluating_function_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-FUNCTION-TERM", "CONS", "(DEFUN (EVALUATE-FUNCTION-TERM OBJECT) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&evaluate_function_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("FUNCTION-OUTPUT-VARIABLE?", "OBJECT", "(DEFUN (FUNCTION-OUTPUT-VARIABLE? BOOLEAN) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&function_output_variableP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FUNCTION-OUTPUT-SKOLEM?", "OBJECT", "(DEFUN (FUNCTION-OUTPUT-SKOLEM? BOOLEAN) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&function_output_skolemP));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-TRUE-AND-FALSE", "CONS", "(DEFUN (REMOVE-TRUE-AND-FALSE OBJECT BOOLEAN) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&remove_true_and_false));
            }
            { Method_Slot* method = define_method_from_stringified_source("FLATTEN-NESTED-OPERATORS", "CONS", "(DEFUN (FLATTEN-NESTED-OPERATORS OBJECT BOOLEAN) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&flatten_nested_operators));
            }
            { Method_Slot* method = define_method_from_stringified_source("CANONICALIZE-AND-OR-TREE", "CONS", "(DEFUN (CANONICALIZE-AND-OR-TREE OBJECT) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&canonicalize_and_or_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CANONICALIZE-NEGATION-TREE", "CONS", "(DEFUN (CANONICALIZE-NEGATION-TREE OBJECT) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&canonicalize_negation_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("QUANTIFIER-SYMBOL?", "SYMBOL", "(DEFUN (QUANTIFIER-SYMBOL? BOOLEAN) ((SELF SYMBOL)))");

              method->function_code = ((cpp_function_code)(&quantifier_symbolP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CANONICALIZE-QUANTIFICATION-TREE", "CONS", "(DEFUN (CANONICALIZE-QUANTIFICATION-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&canonicalize_quantification_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONS.CANONICALIZE-PROPOSITION-TREE", "CONS", "(DEFUN (CONS.CANONICALIZE-PROPOSITION-TREE OBJECT) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&consDcanonicalize_proposition_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CANONICALIZE-PROPOSITION-TREE", "OBJECT", "(DEFUN (CANONICALIZE-PROPOSITION-TREE OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&canonicalize_proposition_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPDATE-PROPOSITION", "OBJECT", "(DEFUN (UPDATE-PROPOSITION PROPOSITION) ((TREE OBJECT) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&update_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-UPDATE-PROPOSITION", "OBJECT", "(DEFUN (HELP-UPDATE-PROPOSITION PROPOSITION) ((TREE OBJECT) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&help_update_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("SMART-UPDATE-PROPOSITION", "OBJECT", "(DEFUN (SMART-UPDATE-PROPOSITION OBJECT) ((TREE OBJECT) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&smart_update_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("ASSERT", "OBJECT", "(DEFUN (ASSERT OBJECT) ((PROPOSITION PARSE-TREE)) :DOCUMENTATION \"Assert the truth of `proposition'.  Return the asserted proposition object.\nKIF example:  `(assert (happy Fred))' asserts that Fred is indeed happy.\nNote, that for this assertion to succeed, the logic constant `Fred' must\nalready be defined, e.g., as a side-effect of a type assertion such as\n`(assert (Person Fred))', and the relation (or slot) `happy' must be defined\non objects of `Fred's type, e.g., on the class `Person'.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)");

              method->function_code = ((cpp_function_code)(&assert));
            }
            { Method_Slot* method = define_method_from_stringified_source("RETRACT", "OBJECT", "(DEFUN (RETRACT PROPOSITION) ((PROPOSITION PARSE-TREE)) :DOCUMENTATION \"Retract the truth of `proposition'.  Return the retracted proposition\nobject.  KIF example:  `(retract (happy Fred))' retracts that Fred is\nhappy.  Note, that for this to succeed, the logic constant `Fred' and the\nrelation (or slot) `happy' must already be defined (see `assert').\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)");

              method->function_code = ((cpp_function_code)(&retract));
            }
            { Method_Slot* method = define_method_from_stringified_source("DENY", "OBJECT", "(DEFUN (DENY PROPOSITION) ((PROPOSITION PARSE-TREE)) :DOCUMENTATION \"Assert the falsity of `proposition'.  Return the asserted proposition\nobject.  KIF example:  `(deny (happy Fred))' asserts that Fred is not happy,\nwhich could have been done equivalently by `(assert (not (happy Fred)))'.\nNote, that for this to succeed, the logic constant `Fred' and the\nrelation (or slot) `happy' must already be defined (see `assert').\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)");

              method->function_code = ((cpp_function_code)(&deny));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONCEIVE", "OBJECT", "(DEFUN (CONCEIVE PROPOSITION) ((PROPOSITION PARSE-TREE)) :DOCUMENTATION \"Build `proposition' without asserting its truth value.  Return the\nconceived proposition object.  KIF example: `(conceive (happy Fred))' builds\nthe proposition expressing that Fred is happy without explictly asserting or\ndenying it.  Note, that for this to succeed, the logic constant `Fred' and\nthe relation (or slot) `happy' must already be defined (see `assert').\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)");

              method->function_code = ((cpp_function_code)(&conceive));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNASSERT", "OBJECT", "(DEFUN UNASSERT ((PROPOSITION PARSE-TREE)) :DOCUMENTATION \"Retract the truth or falsity of `proposition'.  This is a more general\nversion of `retract' that also handles falsity.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)");

              method->function_code = ((cpp_function_code)(&unassert));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNASSERT-FACT", "PROPOSITION", "(DEFUN UNASSERT-FACT ((SELF PROPOSITION)) :DOCUMENTATION \"Retract the truth or falsity of the proposition 'self'\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&unassert_fact));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETED?", "LOGIC-OBJECT", "(DEFMETHOD (DELETED? BOOLEAN) ((SELF LOGIC-OBJECT)))");

              method->method_code = ((cpp_method_code)(&Logic_Object::deletedP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETED?-SETTER", "LOGIC-OBJECT", "(DEFMETHOD (DELETED?-SETTER BOOLEAN) ((SELF LOGIC-OBJECT) (VALUE BOOLEAN)))");

              method->method_code = ((cpp_method_code)(&Logic_Object::deletedP_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETED?", "PROPOSITION", "(DEFMETHOD (DELETED? BOOLEAN) ((SELF PROPOSITION)))");

              method->method_code = ((cpp_method_code)(&Proposition::deletedP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETED?-SETTER", "PROPOSITION", "(DEFMETHOD (DELETED?-SETTER BOOLEAN) ((SELF PROPOSITION) (VALUE BOOLEAN)))");

              method->method_code = ((cpp_method_code)(&Proposition::deletedP_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-PROPOSITION", "PROPOSITION", "(DEFUN DESTROY-PROPOSITION ((PROPOSITION PROPOSITION)) :DOCUMENTATION \"Retract and destroy the proposition 'proposition'.\nRecursively destroy all propositions that reference 'proposition'.\")");

              method->function_code = ((cpp_function_code)(&destroy_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-INSTANCE", "LOGIC-OBJECT", "(DEFUN DESTROY-INSTANCE ((OBJECT LOGIC-OBJECT)) :DOCUMENTATION \"Destroy all propositions that reference 'object',\nand mark it as 'deleted?', thereby making it invisible within class\nextensions.\")");

              method->function_code = ((cpp_function_code)(&destroy_instance));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-TERM", "LOGIC-OBJECT", "(DEFUN DESTROY-TERM ((OBJECT LOGIC-OBJECT)) :DOCUMENTATION \"Destroy all propositions that reference 'object',\nand mark it as 'deleted?', thereby making it invisible within class\nextensions.  Unlink descriptions from native relations.\")");

              method->function_code = ((cpp_function_code)(&destroy_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-LOGIC-MODULE-HOOK", "MODULE", "(DEFUN CLEAR-LOGIC-MODULE-HOOK ((MODULE MODULE)))");

              method->function_code = ((cpp_function_code)(&clear_logic_module_hook));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-INSTANCES", "ARGUMENT-LIST", "(DEFUN CLEAR-INSTANCES (|&REST| (NAME NAME)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Destroy all instances belonging to module `name' or any of its children.\nIf no `name' is supplied, the current module will be cleared after\nconfirming with the user.\")");

              method->function_code = ((cpp_function_code)(&clear_instances));
              set_dynamic_slot_value(method, SYM_PROPOSITIONS_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&clear_instances_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("DO-CLEAR-INSTANCES", "MODULE", "(DEFUN DO-CLEAR-INSTANCES ((MODULE MODULE)) :DOCUMENTATION \"Function version of `clear-instances' that evaluates its argument.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&do_clear_instances));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-TRANSFER-PROPOSITION-ARGUMENTS", "PROPOSITION", "(DEFUN HELP-TRANSFER-PROPOSITION-ARGUMENTS ((PROPOSITION PROPOSITION) (FROMOBJECT LOGIC-OBJECT) (TOOBJECT LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&help_transfer_proposition_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSFER-PROPOSITIONS-TO-LOGIC-OBJECT", "LOGIC-OBJECT", "(DEFUN TRANSFER-PROPOSITIONS-TO-LOGIC-OBJECT ((FROMOBJECT LOGIC-OBJECT) (TOOBJECT LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&transfer_propositions_to_logic_object));
            }
            define_external_slot_from_stringified_source("(DEFSLOT SLOT TOTAL? :TYPE BOOLEAN :OPTION-KEYWORD :TOTAL? :DOCUMENTATION \"Applies to functions, not predicates.  True if the range\nof the slot is defined for all combinations of arguments (domain values).\" :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT SLOT INDEX-ON-VALUES? :TYPE BOOLEAN :OPTION-KEYWORD :INDEX-ON-VALUES? :DOCUMENTATION \"Tells PowerLoom to install a hash index on the slot\nvalues, enabling retrieval of the slot argument given its value.\" :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT SLOT PERMUTATION-TABLE :TYPE (KEY-VALUE-LIST OF VECTOR SLOT) :OPTION-KEYWORD :PERMUTATION-TABLE :ALLOCATION :DYNAMIC)");
            { Method_Slot* method = define_method_from_stringified_source("NUMBER-VALUE", "NUMBER-WRAPPER", "(DEFMETHOD (NUMBER-VALUE FLOAT) ((WRAPPEDNUMBER NUMBER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Number_Wrapper::number_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("GREATER-THAN?", "NUMBER-WRAPPER", "(DEFMETHOD (GREATER-THAN? BOOLEAN-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Number_Wrapper::greater_thanP));
            }
            { Method_Slot* method = define_method_from_stringified_source("GREATER-OR-EQUAL?", "NUMBER-WRAPPER", "(DEFMETHOD (GREATER-OR-EQUAL? BOOLEAN-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Number_Wrapper::greater_or_equalP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LESS-THAN?", "NUMBER-WRAPPER", "(DEFMETHOD (LESS-THAN? BOOLEAN-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Number_Wrapper::less_thanP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LESS-OR-EQUAL?", "NUMBER-WRAPPER", "(DEFMETHOD (LESS-OR-EQUAL? BOOLEAN-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Number_Wrapper::less_or_equalP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PLUS", "NUMBER-WRAPPER", "(DEFMETHOD (PLUS NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Number_Wrapper::plus));
            }
            { Method_Slot* method = define_method_from_stringified_source("MINUS", "NUMBER-WRAPPER", "(DEFMETHOD (MINUS NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Number_Wrapper::minus));
            }
            { Method_Slot* method = define_method_from_stringified_source("TIMES", "NUMBER-WRAPPER", "(DEFMETHOD (TIMES NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Number_Wrapper::times));
            }
            { Method_Slot* method = define_method_from_stringified_source("DIVIDE", "NUMBER-WRAPPER", "(DEFMETHOD (DIVIDE NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Number_Wrapper::divide));
            }
            define_method_from_stringified_source("STARTUP-PROPOSITIONS", NULL, "(DEFUN STARTUP-PROPOSITIONS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT ZERO-VARIABLES-VECTOR VARIABLES-VECTOR (NEW VARIABLES-VECTOR :ARRAY-SIZE 0) :DOCUMENTATION \"Save space by structure-sharing zero-length variable vectors.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *NOW-TIME-STAMP* TIME-STAMP 0 :DOCUMENTATION \"The NOW time stamp is incremented whenever a series\nof one or more updates is followed by a query.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *LAST-KB-ACTION* KEYWORD :UPDATE-PROPOSITION :DOCUMENTATION \"Records whether the last KB access was a query or\nan update.  Used to determine when to increment the NOW time stamp\ncounter.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT BOTTOM LOGIC-OBJECT (CREATE-SKOLEM NULL (QUOTE BOTTOM)) :DOCUMENTATION \"The undefined individual.  Denotes the non-existence of\nan individual in whatever slot it occupies.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *EVALUATIONMODE* KEYWORD :EXTENSIONAL-ASSERTION :DOCUMENTATION \"Indicates the context for evaluating a proposition.  One\nof :DESCRIPTION, :QUERY, :INTENSIONAL-ASSERTION, or :EXTENSIONAL-ASSERTION.\")");
            { Global_Variable* global = SYM_PROPOSITIONS_oEVALUATIONMODEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OevaluationmodeO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OevaluationmodeO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CLIPPING-ENABLED* BOOLEAN TRUE :DOCUMENTATION \"When enabled, slot-value assertions can be retracted\nby later conflicting assertions.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CONTEXT-DEPENDENT-SEARCH-MODE?* BOOLEAN FALSE :DOCUMENTATION \"Signals that we are performing search across multiple\ncontexts.  Used to disable retraction from collections, since that increases\nthe overhead of the context mechanism.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *SKOLEM-ID-COUNTER* INTEGER 0)");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *FREESKOLEMS* CONS NULL :DOCUMENTATION \"Cons-list of top-level existentially-quantified skolems.\")");
            { Global_Variable* global = SYM_PROPOSITIONS_oFREESKOLEMSo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OfreeskolemsO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OfreeskolemsO));
            }
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT TRUE-TRUTH-VALUE TRUTH-VALUE (NEW TRUTH-VALUE) :DOCUMENTATION \"Value representing TRUE.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT FALSE-TRUTH-VALUE TRUTH-VALUE (NEW TRUTH-VALUE) :DOCUMENTATION \"Value representing FALSE.\")");
            TRUE_TRUTH_VALUE->positive_score = 1.0;
            FALSE_TRUTH_VALUE->negative_score = -1.0;
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT TRUE-PROPOSITION PROPOSITION (NEW PROPOSITION :KIND :CONSTANT :OPERATOR /STELLA/@TRUE :ARGUMENTS (NEW ARGUMENTS-VECTOR :ARRAY-SIZE 0) :TRUTH-VALUE TRUE-TRUTH-VALUE))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT FALSE-PROPOSITION PROPOSITION (NEW PROPOSITION :KIND :CONSTANT :OPERATOR /STELLA/@FALSE :ARGUMENTS (NEW ARGUMENTS-VECTOR :ARRAY-SIZE 0) :TRUTH-VALUE FALSE-TRUTH-VALUE))");
            SGT_PROPOSITIONS_TRUE->surrogate_value = TRUE_PROPOSITION;
            SGT_PROPOSITIONS_FALSE->surrogate_value = FALSE_PROPOSITION;
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT ANONYMOUS-VARIABLE-NAME SYMBOL (QUOTE ?) :DOCUMENTATION \"Variables with name 'ANONYMOUS-VARIABLE-NAME' are considered\nanonymous, and are not assumed to be identical to any other variable also named\n'ANONYMOUS-VARIABLE-NAME'.\")");
            add_hook(oREDEFINE_RELATION_HOOKSo, SYM_PROPOSITIONS_TRANSFER_LOGIC_INFORMATION_FROM_RELATION_HOOK);
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *PROPOSITIONUNDERCONSTRUCTION* OBJECT NULL :DOCUMENTATION \"Points to the parse tree which is the input to the\nproposition being constructed.\")");
            { Global_Variable* global = SYM_PROPOSITIONS_oPROPOSITIONUNDERCONSTRUCTIONo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OpropositionunderconstructionO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OpropositionunderconstructionO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *TOPLEVELPROPOSITIONS* (CONS OF PROPOSITION) NULL :DOCUMENTATION \"If non-NULL newly built top-level propositions are\npushed onto this list.\")");
            { Global_Variable* global = SYM_PROPOSITIONS_oTOPLEVELPROPOSITIONSo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OtoplevelpropositionsO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OtoplevelpropositionsO));
            }
            add_hook(oCLEAR_MODULE_HOOKSo, SYM_PROPOSITIONS_CLEAR_LOGIC_MODULE_HOOK);
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

