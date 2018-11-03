// kif-out.cc

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

Surrogate* SGT_KIF_OUT_LITERAL_WRAPPER = NULL;

Surrogate* SGT_KIF_OUT_LOGIC_OBJECT = NULL;

Keyword* KWD_KIF_OUT_FUNCTION = NULL;

Surrogate* SGT_KIF_OUT_PROPOSITION = NULL;

Symbol* SYM_KIF_OUT_DESCRIPTION = NULL;

Surrogate* SGT_KIF_OUT_SLOT = NULL;

boolean oPRETTYPRINTLOGICALFORMSpo = FALSE;

Symbol* SYM_KIF_OUT_oPRETTYPRINTLOGICALFORMSpo = NULL;

boolean oPRETTYPRINTKIFpo = FALSE;

Symbol* SYM_KIF_OUT_oPRETTYPRINTKIFpo = NULL;

Output_Stream* oPRINTLOGICALFORMSTREAMo = NULL;

Symbol* SYM_KIF_OUT_oPRINTLOGICALFORMSTREAMo = NULL;

boolean oDOWNCASEOPERATORSpo = FALSE;

Symbol* SYM_KIF_OUT_oDOWNCASEOPERATORSpo = NULL;

int oINDENTCOUNTERo = 0;

Symbol* SYM_KIF_OUT_oINDENTCOUNTERo = NULL;

int oINDENT_QUANTUMo = 3;

Keyword* KWD_KIF_OUT_KIF = NULL;

Keyword* KWD_KIF_OUT_STELLA = NULL;

Keyword* KWD_KIF_OUT_PREFIX_STELLA = NULL;

Keyword* KWD_KIF_OUT_SQL = NULL;

Surrogate* SGT_KIF_OUT_DESCRIPTION = NULL;

Surrogate* SGT_KIF_OUT_PATTERN_VARIABLE = NULL;

Surrogate* SGT_KIF_OUT_SKOLEM = NULL;

Surrogate* SGT_KIF_OUT_COLLECTION = NULL;

Keyword* KWD_KIF_OUT_IN = NULL;

Keyword* KWD_KIF_OUT_REALISTIC = NULL;

Keyword* KWD_KIF_OUT_ORIGINAL = NULL;

boolean oTOPLEVELPRINTKIFPROPOSITIONpo = TRUE;

Symbol* SYM_KIF_OUT_oTOPLEVELPRINTKIFPROPOSITIONpo = NULL;

Keyword* KWD_KIF_OUT_AND = NULL;

Keyword* KWD_KIF_OUT_OR = NULL;

Keyword* KWD_KIF_OUT_NOT = NULL;

Keyword* KWD_KIF_OUT_EQUIVALENT = NULL;

Keyword* KWD_KIF_OUT_PREDICATE = NULL;

Keyword* KWD_KIF_OUT_IMPLIES = NULL;

Keyword* KWD_KIF_OUT_FORALL = NULL;

Keyword* KWD_KIF_OUT_EXISTS = NULL;

Keyword* KWD_KIF_OUT_CONSTANT = NULL;

Keyword* KWD_KIF_OUT_CONTAINED_BY = NULL;

Keyword* KWD_KIF_OUT_DELETED = NULL;

Surrogate* SGT_KIF_OUT_TYPE = NULL;

Symbol* SYM_KIF_OUT_IO_VARIABLES = NULL;

Symbol* SYM_KIF_OUT_SURROGATE_VALUE_INVERSE = NULL;

Keyword* KWD_KIF_OUT_ENUMERATION = NULL;

Surrogate* SGT_KIF_OUT_COLLECTIONdORDERED = NULL;

Surrogate* SGT_KIF_OUT_COLLECTIONdDUPLICATE_FREE = NULL;

Vector* FAKE_VARIABLES = NULL;

Symbol* SYM_KIF_OUT_pX = NULL;

Symbol* SYM_KIF_OUT_pY = NULL;

Symbol* SYM_KIF_OUT_pZ = NULL;

Symbol* SYM_KIF_OUT_SKOLEM_NAME = NULL;

Key_Value_List* REUSABLE_SKOLEM_MAPPING_TABLE = NULL;

Hash_Table* oEXCLUDEDPROPOSITIONSo = NULL;

Symbol* SYM_KIF_OUT_oEXCLUDEDPROPOSITIONSo = NULL;

Symbol* SYM_KIF_OUT_MASTER_PROPOSITION = NULL;

Surrogate* SGT_KIF_OUT_COLLECTIONdCLOSED = NULL;

Symbol* SYM_KIF_OUT_RELATION_STRINGIFIED_SOURCE = NULL;

Keyword* KWD_KIF_OUT_SLOTS = NULL;

Keyword* KWD_KIF_OUT_PUBLIC_SLOTS = NULL;

Keyword* KWD_KIF_OUT_METHODS = NULL;

Keyword* KWD_KIF_OUT_PUBLIC_METHODS = NULL;

Symbol* SYM_KIF_OUT_ASSERT = NULL;

Symbol* SYM_KIF_OUT_DEFRULE = NULL;

Symbol* SYM_KIF_OUT_EVALUATOR_WRAPPER_CODE = NULL;

void collect_function_proposition_facts(Proposition* self, List* facts, List* beenthere) {
  beenthere->insert(self);
  { Object* outputskolem = last_argument(self);
    Object* value = outputskolem->value_of();
    boolean hasassertedvalueP = !eqlP(value, outputskolem);

    if (hasassertedvalueP) {
      if (!facts->memberP(self)) {
        facts->insert(self);
      }
    }
    if ((!hasassertedvalueP) ||
        (native_valueP(value) &&
         (!isaP(value, SGT_KIF_OUT_LITERAL_WRAPPER)))) {
      help_collect_facts(outputskolem, facts, beenthere);
    }
  }
}

void help_collect_facts(Object* self, List* facts, List* beenthere) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_KIF_OUT_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        { Proposition* p = NULL;
          Cons* iter_001 = self->dependent_attribute_propositions->the_cons_list;

          while (!nilP(iter_001)) {
            {
              p = ((Proposition*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            if (!beenthere->memberP(p)) {
              if (p->kind == KWD_KIF_OUT_FUNCTION) {
                collect_function_proposition_facts(p, facts, beenthere);
              }
              else {
                help_collect_facts(p, facts, beenthere);
              }
            }
          }
        }
        { Proposition* p = NULL;
          Cons* iter_002 = self->dependent_propositions->the_cons_list;

          while (!nilP(iter_002)) {
            {
              p = ((Proposition*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            if (!beenthere->memberP(p)) {
              help_collect_facts(p, facts, beenthere);
            }
          }
        }
        { Logic_Object* equivalent = NULL;
          Cons* iter_003 = self->variable_value_inverse_reader();

          while (!nilP(iter_003)) {
            {
              equivalent = ((Logic_Object*)(iter_003->value));
              iter_003 = iter_003->rest;
            }
            help_collect_facts(equivalent, facts, beenthere);
          }
        }
      }
    }
    else if (taxonomy_isaP(self, SGT_KIF_OUT_PROPOSITION)) {
      { Proposition* self = NULL;

        self = ((Proposition*)(self_001));
        beenthere->insert(self);
        if (!unknownP(self)) {
          facts->insert(self);
        }
        { Proposition* p = NULL;
          Cons* iter_004 = self->dependent_propositions->the_cons_list;

          while (!nilP(iter_004)) {
            {
              p = ((Proposition*)(iter_004->value));
              iter_004 = iter_004->rest;
            }
            if (!beenthere->memberP(p)) {
              help_collect_facts(p, facts, beenthere);
            }
          }
        }
      }
    }
    else if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        if (self->surrogate_value != NULL) {
          help_collect_facts(self->surrogate_value, facts, beenthere);
        }
      }
    }
    else if (classP(self)) {
      { Class* self = NULL;

        self = ((Class*)(self_001));
        if (((Description*)(dynamic_slot_value(self, SYM_KIF_OUT_DESCRIPTION, NULL))) != NULL) {
          help_collect_facts(((Description*)(dynamic_slot_value(self, SYM_KIF_OUT_DESCRIPTION, NULL))), facts, beenthere);
        }
      }
    }
    else if (taxonomy_isaP(self, SGT_KIF_OUT_SLOT)) {
      { Slot* self = NULL;

        self = ((Slot*)(self_001));
        if (((Description*)(dynamic_slot_value(self, SYM_KIF_OUT_DESCRIPTION, NULL))) != NULL) {
          help_collect_facts(((Description*)(dynamic_slot_value(self, SYM_KIF_OUT_DESCRIPTION, NULL))), facts, beenthere);
        }
      }
    }
    else {
    }
  }
}

List* all_facts_of_object(Logic_Object* self) {
  // Return a list of all definite (TRUE or FALSE) propositions
  // attached to `self'.
  { List* facts = new_list();
    List* beenthere = new_list();

    help_collect_facts(self, facts, beenthere);
    beenthere->free();
    return (facts);
  }
}

Logic_Object* get_logic_object(char* name) {
  // Return the logic object named 'name'.
  { Surrogate* surrogate = lookup_surrogate(name);

    if (surrogate != NULL) {
      return (((Logic_Object*)(surrogate->surrogate_value->value_of())));
    }
  }
}

List* all_facts_of(Object* name) {
  // Return a list of all definite (TRUE or FALSE) propositions
  // that reference the logic-object named `name'.
  { Logic_Object* instance = coerce_to_instance(name, NULL);

    if (instance != NULL) {
      return (all_facts_of_object(instance));
    }
    else {
      return (NULL);
    }
  }
}

void retract_facts_of_object(Logic_Object* self) {
  // Retract all definite (TRUE or FALSE) propositions attached to `self'.
  if (self == NULL) {
    return;
  }
  { Proposition* p = NULL;
    Cons* iter_001 = all_facts_of_object(self)->the_cons_list;

    while (!nilP(iter_001)) {
      {
        p = ((Proposition*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      { Keyword* test_value_001 = p->kind;

        if (test_value_001 == KWD_KIF_OUT_FUNCTION) {
          { Skolem* skolem = ((Skolem*)(p->arguments->last()));

            if (skolem == self) {
              continue;
            }
            if ((skolem != NULL) &&
                (((Object*)(access_in_context(skolem->variable_value, skolem, FALSE))) != NULL)) {
              unassert_fact(p);
            }
            retract_facts_of_object(skolem);
          }
        }
        else {
          unassert_fact(p);
        }
      }
    }
  }
}

void retract_facts_of(Object* name) {
  // Retract all definite (TRUE or FALSE) propositions
  // that reference the logic-object named `name'.
  { Logic_Object* instance = coerce_to_instance(name, NULL);

    if (instance != NULL) {
      retract_facts_of_object(instance);
    }
  }
}

boolean read_OprettyprintlogicalformsPO() {
  return (oPRETTYPRINTLOGICALFORMSpo);
}

boolean write_OprettyprintlogicalformsPO(boolean value) {
  oPRETTYPRINTLOGICALFORMSpo = value;
  return (value);
}

boolean read_OprettyprintkifPO() {
  return (oPRETTYPRINTKIFpo);
}

boolean write_OprettyprintkifPO(boolean value) {
  oPRETTYPRINTKIFpo = value;
  return (value);
}

Output_Stream* read_OprintlogicalformstreamO() {
  return (oPRINTLOGICALFORMSTREAMo);
}

Output_Stream* write_OprintlogicalformstreamO(Output_Stream* value) {
  oPRINTLOGICALFORMSTREAMo = value;
  return (value);
}

boolean read_OdowncaseoperatorsPO() {
  return (oDOWNCASEOPERATORSpo);
}

boolean write_OdowncaseoperatorsPO(boolean value) {
  oDOWNCASEOPERATORSpo = value;
  return (value);
}

char* maybe_downcase(char* string) {
  if (oDOWNCASEOPERATORSpo) {
    return (string_downcase(string));
  }
  else {
    return (string);
  }
}

int read_OindentcounterO() {
  return (oINDENTCOUNTERo);
}

int write_OindentcounterO(int value) {
  oINDENTCOUNTERo = value;
  return (value);
}

void increase_indent(int indent) {
  if (indent == NULL_INTEGER) {
    indent = oINDENT_QUANTUMo;
  }
  oINDENTCOUNTERo = oINDENTCOUNTERo + indent;
}

void decrease_indent(int indent) {
  if (indent == NULL_INTEGER) {
    indent = oINDENT_QUANTUMo;
  }
  oINDENTCOUNTERo = oINDENTCOUNTERo - indent;
}

void print_indent(Output_Stream* stream, int indent) {
  if (indent == NULL_INTEGER) {
    indent = oINDENTCOUNTERo;
  }
  { int i = NULL_INTEGER;
    int iter_001 = 1;
    int upper_bound_001 = indent;
    boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

    while (unboundedP_001 ||
        (iter_001 <= upper_bound_001)) {
      {
        i = iter_001;
        iter_001 = iter_001 + 1;
      }
      i = i;
      *(stream->native_stream) << " ";
    }
  }
}

void print_logical_form_in_dialect(Object* self, Keyword* dialect, Output_Stream* stream) {
  // Produce a stringified version of a logical representation
  // of 'self' and write it to the stream 'stream'.  Use the dialect 'dialect',
  // or use the current dialect if 'dialect' is NULL.
  if (self == NULL) {
    return;
  }
  if (dialect == NULL) {
    dialect = oLOGIC_DIALECTo;
  }
  { int currentindentcounter = oINDENTCOUNTERo;

    { Output_Stream* old_OprintlogicalformstreamO_001 = oPRINTLOGICALFORMSTREAMo;
      int old_OindentcounterO_001 = oINDENTCOUNTERo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTLOGICALFORMSTREAMo = stream;
            oINDENTCOUNTERo = currentindentcounter;
            if (dialect == KWD_KIF_OUT_KIF) {
              { boolean old_OprettyprintkifPO_001 = oPRETTYPRINTKIFpo;

                { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRETTYPRINTKIFpo = oPRETTYPRINTLOGICALFORMSpo;
                      print_as_kif(self);
                      oPRETTYPRINTKIFpo = old_OprettyprintkifPO_001;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRETTYPRINTKIFpo = old_OprettyprintkifPO_001;
                    resignal();
                  }
                }
              }
            }
            else if ((dialect == KWD_KIF_OUT_STELLA) ||
                (dialect == KWD_KIF_OUT_PREFIX_STELLA)) {
              print_as_kif(self);
            }
            else if (dialect == KWD_KIF_OUT_SQL) {
            }
            else {
              cerr << "`" << dialect << "'" << " is not a valid case option";
            }
            oINDENTCOUNTERo = old_OindentcounterO_001;
            oPRINTLOGICALFORMSTREAMo = old_OprintlogicalformstreamO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oINDENTCOUNTERo = old_OindentcounterO_001;
          oPRINTLOGICALFORMSTREAMo = old_OprintlogicalformstreamO_001;
          resignal();
        }
      }
    }
  }
}

void print_logical_form(Object* form, Output_Stream* stream) {
  // Print the logical form `form' to `stream' according to
  // the current setting of `*logic-dialect*'.  Pretty-printing is controlled
  // by the current setting of `*prettyPrintLogicalForms?*'.
  print_logical_form_in_dialect(form, oLOGIC_DIALECTo, stream);
}

void pretty_print_logical_form(Object* form, Output_Stream* stream) {
  // Pretty-print the logical form `form' to `stream' according
  // to the current setting of `*logic-dialect*'.
  { boolean old_OprettyprintlogicalformsPO_001 = oPRETTYPRINTLOGICALFORMSpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRETTYPRINTLOGICALFORMSpo = TRUE;
          print_logical_form_in_dialect(form, oLOGIC_DIALECTo, stream);
          oPRETTYPRINTLOGICALFORMSpo = old_OprettyprintlogicalformsPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPRETTYPRINTLOGICALFORMSpo = old_OprettyprintlogicalformsPO_001;
        resignal();
      }
    }
  }
}

void print_unformatted_logical_form(Object* form, Output_Stream* stream) {
  // Print the logical form `form' to `stream' according to
  // the current setting of `*logic-dialect*'.  Pretty-printing is explicitly
  // forced to be turned off.
  { boolean old_OprettyprintlogicalformsPO_001 = oPRETTYPRINTLOGICALFORMSpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRETTYPRINTLOGICALFORMSpo = FALSE;
          print_logical_form_in_dialect(form, oLOGIC_DIALECTo, stream);
          oPRETTYPRINTLOGICALFORMSpo = old_OprettyprintlogicalformsPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPRETTYPRINTLOGICALFORMSpo = old_OprettyprintlogicalformsPO_001;
        resignal();
      }
    }
  }
}

void print_as_kif(Object* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;

    if (self == NULL) {
      *(stream->native_stream) << "NULL";
      return;
    }
    { Object* self_001 = self;

      if (taxonomy_isaP(self, SGT_KIF_OUT_PROPOSITION)) {
        { Proposition* self = NULL;

          self = ((Proposition*)(self_001));
          print_kif_proposition(self);
        }
      }
      else if (taxonomy_isaP(self, SGT_KIF_OUT_LITERAL_WRAPPER)) {
        { Literal_Wrapper* self = NULL;

          self = ((Literal_Wrapper*)(self_001));
          print_kif_literal_wrapper(self);
        }
      }
      else if (taxonomy_isaP(self, SGT_KIF_OUT_DESCRIPTION)) {
        { Description* self = NULL;

          self = ((Description*)(self_001));
          print_kif_description(self);
        }
      }
      else if (taxonomy_isaP(self, SGT_KIF_OUT_PATTERN_VARIABLE)) {
        { Pattern_Variable* self = NULL;

          self = ((Pattern_Variable*)(self_001));
          print_kif_variable(self);
        }
      }
      else if (taxonomy_isaP(self, SGT_KIF_OUT_SKOLEM)) {
        { Skolem* self = NULL;

          self = ((Skolem*)(self_001));
          print_kif_skolem(self, FALSE);
        }
      }
      else if (taxonomy_isaP(self, SGT_KIF_OUT_LOGIC_OBJECT)) {
        { Logic_Object* self = NULL;

          self = ((Logic_Object*)(self_001));
          print_kif_logic_object(self);
        }
      }
      else if (surrogateP(self)) {
        { Surrogate* self = NULL;

          self = ((Surrogate*)(self_001));
          *(stream->native_stream) << self->symbol_name;
        }
      }
      else if (taxonomy_isaP(self, SGT_KIF_OUT_COLLECTION)) {
        { Collection* self = NULL;

          self = ((Collection*)(self_001));
          print_kif_enumeration(self);
        }
      }
      else {
        *(stream->native_stream) << "|Illegal Logical Form|: " << self;
      }
    }
  }
}

boolean visible_argumentP(Object* self) {
  if (self == NULL) {
    return (TRUE);
  }
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_KIF_OUT_PROPOSITION)) {
      { Proposition* self = NULL;

        self = ((Proposition*)(self_001));
        if ((self->kind == KWD_KIF_OUT_IN) &&
            self->variable_typeP_reader()) {
          if ((oPRINTMODEo == KWD_KIF_OUT_REALISTIC) ||
              (oPRINTMODEo == KWD_KIF_OUT_ORIGINAL)) {
            return (FALSE);
          }
          else {
          }
        }
      }
    }
    else {
    }
  }
  return (TRUE);
}

int visible_arguments_count(Vector* arguments) {
  { int count = 0;

    { Object* arg = NULL;
      Vector* vector_001 = arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        if (visible_argumentP(arg)) {
          count = count + 1;
        }
      }
    }
    return (count);
  }
}

void print_kif_arguments(Vector* arguments, boolean separatelinesP, boolean omitlastargumentP) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;
    Iterator* argumentsiterator = (omitlastargumentP ? ((Iterator*)(arguments->but_last())) : ((Iterator*)(((Iterator*)(arguments->allocate_iterator())))));
    int visibleargcount = visible_arguments_count(arguments);
    int argindex = 0;

    if (omitlastargumentP &&
        visible_argumentP(arguments->last())) {
      visibleargcount = visibleargcount - 1;
    }
    { Object* arg = NULL;
      Iterator* iter_001 = argumentsiterator;

      while (iter_001->nextP()) {
        {
          arg = iter_001->value;
        }
        if (visible_argumentP(arg) ||
            (visibleargcount == 0)) {
          argindex = argindex + 1;
          if (argindex > 1) {
            if (separatelinesP &&
                oPRETTYPRINTKIFpo) {
              *(stream->native_stream) << endl;
              print_indent(stream, NULL_INTEGER);
            }
            else {
              *(stream->native_stream) << " ";
            }
          }
          print_as_kif(arg);
        }
      }
    }
  }
}

void print_kif_operator_with_arguments(char* renamed_Operator, Vector* arguments, boolean separatelinesP, boolean omitlastargumentP) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;

    *(stream->native_stream) << "(" << renamed_Operator << " ";
    increase_indent(string_length(renamed_Operator) + 2);
    print_kif_arguments(arguments, separatelinesP, omitlastargumentP);
    decrease_indent(string_length(renamed_Operator) + 2);
    *(stream->native_stream) << ")";
  }
}

char* stringified_kif_operator(Proposition* self) {
  return (maybe_downcase(internal_stella_operator_to_kif(((Slot*)(((Surrogate*)(self->renamed_Operator))->surrogate_value))->slot_name)->symbol_name));
}

boolean read_OtoplevelprintkifpropositionPO() {
  return (oTOPLEVELPRINTKIFPROPOSITIONpo);
}

boolean write_OtoplevelprintkifpropositionPO(boolean value) {
  oTOPLEVELPRINTKIFPROPOSITIONpo = value;
  return (value);
}

void print_kif_proposition(Proposition* self) {
  if (self == NULL) {
    return;
  }
  { boolean toplevelP = oTOPLEVELPRINTKIFPROPOSITIONpo;
    Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;
    boolean printexplicitnegationP = toplevelP &&
        (falseP(self) &&
         (oPRINTMODEo == KWD_KIF_OUT_ORIGINAL));

    { boolean old_OtoplevelprintkifpropositionPO_001 = oTOPLEVELPRINTKIFPROPOSITIONpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTOPLEVELPRINTKIFPROPOSITIONpo = FALSE;
            if (printexplicitnegationP) {
              *(stream->native_stream) << "(not ";
              increase_indent(5);
            }
            if (((oPRINTMODEo == KWD_KIF_OUT_REALISTIC) ||
                (oPRINTMODEo == KWD_KIF_OUT_ORIGINAL)) &&
                (toplevelP &&
                 top_level_exists_propositionP(self))) {
              print_kif_top_level_exists_proposition(self);
            }
            else {
              help_print_kif_proposition(self);
            }
            if (printexplicitnegationP) {
              *(stream->native_stream) << ")";
              decrease_indent(5);
            }
            oTOPLEVELPRINTKIFPROPOSITIONpo = old_OtoplevelprintkifpropositionPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTOPLEVELPRINTKIFPROPOSITIONpo = old_OtoplevelprintkifpropositionPO_001;
          resignal();
        }
      }
    }
  }
}

void help_print_kif_proposition(Proposition* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;
    char* renamed_Operator = NULL;
    boolean separatelinesP = FALSE;

    { Keyword* test_value_001 = self->kind;

      if ((test_value_001 == KWD_KIF_OUT_AND) ||
          (test_value_001 == KWD_KIF_OUT_OR)) {
        if (self->kind == KWD_KIF_OUT_AND) {
          renamed_Operator = "and";
        }
        else {
          renamed_Operator = "or";
        }
        separatelinesP = TRUE;
        if (visible_arguments_count(self->arguments) == 1) {
          if ((oPRINTMODEo == KWD_KIF_OUT_REALISTIC) ||
              (oPRINTMODEo == KWD_KIF_OUT_ORIGINAL)) {
            print_kif_arguments(self->arguments, FALSE, FALSE);
            return;
          }
          else {
          }
        }
      }
      else if (test_value_001 == KWD_KIF_OUT_NOT) {
        renamed_Operator = "not";
      }
      else if (test_value_001 == KWD_KIF_OUT_EQUIVALENT) {
        renamed_Operator = "=";
      }
      else if (test_value_001 == KWD_KIF_OUT_PREDICATE) {
        renamed_Operator = stringified_kif_operator(self);
      }
      else if (test_value_001 == KWD_KIF_OUT_FUNCTION) {
        print_kif_function_proposition(self);
        return;
      }
      else if (test_value_001 == KWD_KIF_OUT_IN) {
        print_kif_in_proposition(self);
        return;
      }
      else if (test_value_001 == KWD_KIF_OUT_IMPLIES) {
        print_kif_implies_proposition(self);
        return;
      }
      else if ((test_value_001 == KWD_KIF_OUT_FORALL) ||
          (test_value_001 == KWD_KIF_OUT_EXISTS)) {
        print_kif_quantification(self);
        return;
      }
      else if (test_value_001 == KWD_KIF_OUT_CONSTANT) {
        *(stream->native_stream) << ((Surrogate*)(self->renamed_Operator))->symbol_name;
        return;
      }
      else if (test_value_001 == KWD_KIF_OUT_CONTAINED_BY) {
        renamed_Operator = ":CONTAINED-BY";
      }
      else if (test_value_001 == KWD_KIF_OUT_DELETED) {
        renamed_Operator = ":DELETED";
      }
      else {
        cerr << "`" << test_value_001 << "'" << " is not a valid case option";
      }
    }
    print_kif_operator_with_arguments(renamed_Operator, self->arguments, separatelinesP, FALSE);
  }
}

void print_kif_function_proposition(Proposition* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;
    char* downcasedname = stringified_kif_operator(self);
    Object* lastargument = last_argument(self);

    *(stream->native_stream) << "(= ";
    print_kif_operator_with_arguments(downcasedname, self->arguments, FALSE, TRUE);
    *(stream->native_stream) << " ";
    { Object* lastargument_001 = lastargument;

      if (taxonomy_isaP(lastargument, SGT_KIF_OUT_PATTERN_VARIABLE)) {
        { Pattern_Variable* lastargument = NULL;

          lastargument = ((Pattern_Variable*)(lastargument_001));
          print_kif_variable(lastargument);
        }
      }
      else if (taxonomy_isaP(lastargument, SGT_KIF_OUT_SKOLEM)) {
        { Skolem* lastargument = NULL;

          lastargument = ((Skolem*)(lastargument_001));
          print_kif_skolem(lastargument, TRUE);
        }
      }
      else {
        print_as_kif(lastargument);
      }
    }
    *(stream->native_stream) << ")";
  }
}

void print_kif_function_expression(Proposition* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;
    char* downcasedname = stringified_kif_operator(self);

    print_kif_operator_with_arguments(downcasedname, self->arguments, FALSE, TRUE);
  }
}

void print_kif_in_proposition(Proposition* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;
    Object* firstarg = self->arguments->nth(0);
    Object* secondarg = self->arguments->nth(1);
    boolean printaspropertyP = FALSE;

    { Object* secondarg_001 = secondarg;

      if (taxonomy_isaP(secondarg, SGT_KIF_OUT_PATTERN_VARIABLE)) {
        { Pattern_Variable* secondarg = NULL;

          secondarg = ((Pattern_Variable*)(secondarg_001));
          if ((secondarg->binding_to_constant() != NULL) &&
              isaP(secondarg->binding_to_constant(), SGT_KIF_OUT_TYPE)) {
            printaspropertyP = TRUE;
          }
        }
      }
      else if (typeP(secondarg)) {
        { Surrogate* secondarg = NULL;

          secondarg = ((Surrogate*)(secondarg_001));
          printaspropertyP = TRUE;
        }
      }
      else {
      }
    }
    if (printaspropertyP) {
      {
        *(stream->native_stream) << "(";
        print_as_kif(secondarg);
        *(stream->native_stream) << " ";
        print_as_kif(firstarg);
        *(stream->native_stream) << ")";
      }
    }
    else {
      {
        *(stream->native_stream) << "(member ";
        print_as_kif(firstarg);
        *(stream->native_stream) << " ";
        print_as_kif(secondarg);
        *(stream->native_stream) << ")";
      }
    }
  }
}

void print_kif_implies_proposition(Proposition* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;
    Object* tailarg = self->arguments->nth(0);
    Object* headarg = self->arguments->nth(1);

    if (isaP(headarg, SGT_KIF_OUT_DESCRIPTION) &&
        isaP(tailarg, SGT_KIF_OUT_DESCRIPTION)) {
      print_descriptions_as_kif_rule(((Description*)(headarg)), ((Description*)(tailarg)));
    }
    else {
      print_kif_operator_with_arguments("subset", self->arguments, TRUE, FALSE);
    }
  }
}

void print_kif_quantified_variables(Vector* variables) {
  if (variables == NULL) {
    return;
  }
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;

    *(stream->native_stream) << "(";
    { int i = NULL_INTEGER;
      Skolem* vbl = NULL;
      Vector* vector_001 = variables;
      int index_001 = 0;
      int length_001 = vector_001->length();
      int iter_001 = 1;

      while (index_001 < length_001) {
        {
          vbl = ((Skolem*)(vector_001->nth(index_001)));
          index_001 = index_001 + 1;
        }
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        *(stream->native_stream) << "(";
        { Skolem* vbl_001 = vbl;

          if (taxonomy_isaP(vbl, SGT_KIF_OUT_PATTERN_VARIABLE)) {
            { Pattern_Variable* vbl = NULL;

              vbl = ((Pattern_Variable*)(vbl_001));
              print_quantified_variable(vbl, stream);
            }
          }
          else if (taxonomy_isaP(vbl, SGT_KIF_OUT_SKOLEM)) {
            { Skolem* vbl = NULL;

              vbl = ((Skolem*)(vbl_001));
              print_value_of_chain(vbl, stream, vbl);
            }
          }
          else {
            cerr << "`" << vbl << "'" << " is not a valid case option";
          }
        }
        *(stream->native_stream) << " " << logical_type(vbl)->symbol_name << ")";
        if (i < variables->length()) {
          *(stream->native_stream) << " ";
        }
      }
    }
    *(stream->native_stream) << ")";
  }
}

void print_kif_quantification(Proposition* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;
    Proposition* tail = ((Proposition*)(self->arguments->nth(0)));
    Proposition* head = ((Proposition*)(((self->arguments->length() == 2) ? ((Object*)(self->arguments->nth(1))) : ((Object*)(NULL)))));

    { Keyword* test_value_001 = self->kind;

      if (test_value_001 == KWD_KIF_OUT_FORALL) {
        *(stream->native_stream) << "(forall ";
      }
      else if (test_value_001 == KWD_KIF_OUT_EXISTS) {
        *(stream->native_stream) << "(exists ";
      }
      else {
        cerr << "`" << test_value_001 << "'" << " is not a valid case option";
      }
    }
    print_kif_quantified_variables(((Vector*)(dynamic_slot_value(self, SYM_KIF_OUT_IO_VARIABLES, NULL))));
    *(stream->native_stream) << endl;
    increase_indent(NULL_INTEGER);
    print_indent(stream, NULL_INTEGER);
    print_kif_proposition(tail);
    if (head != NULL) {
      *(stream->native_stream) << endl;
      print_indent(stream, NULL_INTEGER);
      print_kif_proposition(head);
    }
    decrease_indent(NULL_INTEGER);
    *(stream->native_stream) << ")";
  }
}

void print_kif_top_level_exists_proposition(Proposition* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;

    *(stream->native_stream) << "(exists ";
    print_kif_quantified_variables(collect_skolemized_exists_variables(self));
    *(stream->native_stream) << endl;
    increase_indent(NULL_INTEGER);
    print_indent(stream, NULL_INTEGER);
    print_kif_proposition(self);
    decrease_indent(NULL_INTEGER);
    *(stream->native_stream) << ")";
  }
}

void print_kif_literal_wrapper(Literal_Wrapper* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;

    { Literal_Wrapper* self_001 = self;

      if (integerP(self)) {
        { Integer_Wrapper* self = NULL;

          self = ((Integer_Wrapper*)(self_001));
          *(stream->native_stream) << self->wrapper_value;
        }
      }
      else if (floatP(self)) {
        { Float_Wrapper* self = NULL;

          self = ((Float_Wrapper*)(self_001));
          *(stream->native_stream) << self->wrapper_value;
        }
      }
      else if (booleanP(self)) {
        { Boolean_Wrapper* self = NULL;

          self = ((Boolean_Wrapper*)(self_001));
          *(stream->native_stream) << self->wrapper_value;
        }
      }
      else if (stringP(self)) {
        { String_Wrapper* self = NULL;

          self = ((String_Wrapper*)(self_001));
          *(stream->native_stream) << self->wrapper_value;
        }
      }
      else if (characterP(self)) {
        { Character_Wrapper* self = NULL;

          self = ((Character_Wrapper*)(self_001));
          *(stream->native_stream) << self->wrapper_value;
        }
      }
      else {
        cerr << "`" << self << "'" << " is not a valid case option";
      }
    }
  }
}

void print_kif_logic_object(Logic_Object* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;

    if (((Surrogate*)(dynamic_slot_value(self, SYM_KIF_OUT_SURROGATE_VALUE_INVERSE, NULL))) != NULL) {
      *(stream->native_stream) << ((Surrogate*)(dynamic_slot_value(self, SYM_KIF_OUT_SURROGATE_VALUE_INVERSE, NULL)))->symbol_name;
    }
    else {
      *(stream->native_stream) << "Unnamed_Object";
    }
  }
}

void print_kif_skolem(Skolem* self, boolean suppressdefiningpropositionP) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;

    print_skolem(self, stream, FALSE);
  }
}

void print_kif_variable(Pattern_Variable* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;

    print_variable(self, stream);
  }
}

void print_kif_enumeration(Collection* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;

    *(stream->native_stream) << "(" << ((self->no_duplicatesP() ? ((char*)("SETOF")) : ((char*)("LISTOF"))));
    { Object* m = NULL;
      Iterator* iter_001 = ((Iterator*)(self->allocate_iterator()));

      while (iter_001->nextP()) {
        {
          m = iter_001->value;
        }
        *(stream->native_stream) << " ";
        print_as_kif(m);
      }
    }
    *(stream->native_stream) << ")";
  }
}

void print_kif_description(Description* self) {
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;

    if (self->native_relation != NULL) {
      *(stream->native_stream) << internal_stella_operator_to_kif(description_name(self));
    }
    else if (self->kind == KWD_KIF_OUT_ENUMERATION) {
      if (exists_property_propositionP(self, SGT_KIF_OUT_COLLECTIONdORDERED)) {
        *(stream->native_stream) << "(listof";
      }
      else if (exists_property_propositionP(self, SGT_KIF_OUT_COLLECTIONdDUPLICATE_FREE)) {
        *(stream->native_stream) << "(setof";
      }
      else {
        *(stream->native_stream) << "(bagof";
      }
      { Object* m = NULL;
        Cons* iter_001 = self->extension_reader()->the_cons_list;

        while (!nilP(iter_001)) {
          {
            m = iter_001->value;
            iter_001 = iter_001->rest;
          }
          cout << " ";
          print_as_kif(m);
        }
      }
      *(stream->native_stream) << ")";
    }
    else {
      *(stream->native_stream) << "(kappa ";
      print_kif_quantified_variables(self->io_variables);
      *(stream->native_stream) << " ";
      print_as_kif(self->proposition);
      *(stream->native_stream) << ")";
    }
  }
}

void print_descriptions_as_kif_rule(Description* head, Description* tail) {
  while (REUSABLE_SKOLEM_MAPPING_TABLE->length() < tail->arity()) {
    { Kv_Cons* self_001 = new_kv_cons();

      self_001->rest = REUSABLE_SKOLEM_MAPPING_TABLE->the_kv_list;
      REUSABLE_SKOLEM_MAPPING_TABLE->the_kv_list = self_001;
    }
  }
  { Output_Stream* stream = oPRINTLOGICALFORMSTREAMo;
    Vector* variables = tail->io_variables;
    int currentindentcounter = oINDENTCOUNTERo;

    { int old_OindentcounterO_001 = oINDENTCOUNTERo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oINDENTCOUNTERo = currentindentcounter;
            { Pattern_Variable* headvbl = NULL;
              Pattern_Variable* tailvbl = NULL;
              Vector* vector_001 = variables;
              int index_001 = 0;
              int length_001 = vector_001->length();
              Vector* vector_002 = head->io_variables;
              int index_002 = 0;
              int length_002 = vector_002->length();
              Kv_List_Iterator* it = ((Kv_List_Iterator*)(REUSABLE_SKOLEM_MAPPING_TABLE->allocate_iterator()));

              while ((index_001 < length_001) &&
                  ((index_002 < length_002) &&
                   it->nextP())) {
                {
                  tailvbl = ((Pattern_Variable*)(vector_001->nth(index_001)));
                  index_001 = index_001 + 1;
                }
                {
                  headvbl = ((Pattern_Variable*)(vector_002->nth(index_002)));
                  index_002 = index_002 + 1;
                }
                it->key_setter(headvbl);
                it->value_setter(tailvbl);
              }
            }
            *(stream->native_stream) << "(forall ";
            print_kif_quantified_variables(variables);
            *(stream->native_stream) << endl;
            increase_indent(NULL_INTEGER);
            print_indent(stream, NULL_INTEGER);
            *(stream->native_stream) << "(<= ";
            increase_indent(4);
            { Key_Value_List* old_OskolemnamemappingtableO_001 = oSKOLEMNAMEMAPPINGTABLEo;

              { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oSKOLEMNAMEMAPPINGTABLEo = REUSABLE_SKOLEM_MAPPING_TABLE;
                    if (head->internal_variables->non_emptyP()) {
                      *(stream->native_stream) << "(exists ";
                      print_kif_quantified_variables(head->internal_variables);
                      *(stream->native_stream) << endl;
                      increase_indent(NULL_INTEGER);
                      print_indent(stream, NULL_INTEGER);
                    }
                    print_kif_proposition(head->proposition);
                    if (head->internal_variables->non_emptyP()) {
                      *(stream->native_stream) << ")";
                      decrease_indent(NULL_INTEGER);
                    }
                    oSKOLEMNAMEMAPPINGTABLEo = old_OskolemnamemappingtableO_001;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oSKOLEMNAMEMAPPINGTABLEo = old_OskolemnamemappingtableO_001;
                  resignal();
                }
              }
            }
            REUSABLE_SKOLEM_MAPPING_TABLE->the_kv_list->value = NULL;
            *(stream->native_stream) << endl;
            if (tail->internal_variables->non_emptyP()) {
              print_indent(stream, NULL_INTEGER);
              *(stream->native_stream) << "(exists ";
              print_kif_quantified_variables(tail->internal_variables);
              *(stream->native_stream) << endl;
              increase_indent(NULL_INTEGER);
            }
            print_indent(stream, NULL_INTEGER);
            print_kif_proposition(tail->proposition);
            if (tail->internal_variables->non_emptyP()) {
              *(stream->native_stream) << ")";
              decrease_indent(NULL_INTEGER);
            }
            *(stream->native_stream) << "))";
            oINDENTCOUNTERo = old_OindentcounterO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oINDENTCOUNTERo = old_OindentcounterO_001;
          resignal();
        }
      }
    }
  }
}

Hash_Table* read_OexcludedpropositionsO() {
  return (oEXCLUDEDPROPOSITIONSo);
}

Hash_Table* write_OexcludedpropositionsO(Hash_Table* value) {
  oEXCLUDEDPROPOSITIONSo = value;
  return (value);
}

void exclude_relation_originated_propositions() {
  { Class* renamed_Class = NULL;
    Iterator* iter_001 = all_classes(NULL, FALSE);

    while (iter_001->nextP()) {
      {
        renamed_Class = ((Class*)(iter_001->value));
      }
      { Proposition* prop = NULL;
        Cons* iter_002 = renamed_Class->relation_originated_propositions_reader()->the_cons_list;

        while (!nilP(iter_002)) {
          {
            prop = ((Proposition*)(iter_002->value));
            iter_002 = iter_002->rest;
          }
          oEXCLUDEDPROPOSITIONSo->insert_at(prop, wrap_boolean(TRUE));
        }
      }
    }
  }
}

boolean excluded_propositionP(Proposition* proposition) {
  if (unknownP(proposition) ||
      ((((Boolean_Wrapper*)(oEXCLUDEDPROPOSITIONSo->lookup(proposition))) != NULL) ||
       (((Proposition*)(dynamic_slot_value(proposition, SYM_KIF_OUT_MASTER_PROPOSITION, NULL))) != NULL))) {
    return (TRUE);
  }
  { Keyword* test_value_001 = proposition->kind;

    if (test_value_001 == KWD_KIF_OUT_IN) {
      if (isaP(proposition->arguments->nth(0), SGT_KIF_OUT_LITERAL_WRAPPER) ||
          (function_output_skolemP(proposition->arguments->nth(0)) ||
           enumerated_classP(proposition->arguments->nth(1)))) {
        return (TRUE);
      }
    }
    else if (test_value_001 == KWD_KIF_OUT_FUNCTION) {
      { Object* lastarg = proposition->arguments->last();

        if (skolemP(lastarg) &&
            (eqlP(lastarg->value_of(), lastarg) &&
             (!top_level_exists_propositionP(proposition)))) {
          return (TRUE);
        }
      }
    }
    else if (test_value_001 == KWD_KIF_OUT_PREDICATE) {
      if ((proposition->renamed_Operator == SGT_KIF_OUT_COLLECTIONdCLOSED) &&
          enumerated_classP(proposition->arguments->nth(0))) {
        return (TRUE);
      }
    }
    else {
    }
  }
  return (FALSE);
}

boolean enumerated_classP(Object* collection) {
  collection = collection->value_of();
  { Object* collection_001 = collection;

    if (taxonomy_isaP(collection, SGT_KIF_OUT_DESCRIPTION)) {
      { Description* collection = NULL;

        collection = ((Description*)(collection_001));
        if ((collection->kind == KWD_KIF_OUT_ENUMERATION) &&
            (collection->native_relation != NULL)) {
          return (TRUE);
        }
      }
    }
    else {
    }
  }
  return (FALSE);
}

void pretty_print_relation_definition(Relation* self, Output_Stream* stream) {
  { char* definitionstring = ((String_Wrapper*)(dynamic_slot_value(self, SYM_KIF_OUT_RELATION_STRINGIFIED_SOURCE, NULL_STRING_WRAPPER)))->wrapper_value;

    if (definitionstring == NULL) {
      { Relation* self_001 = self;

        if (classP(self)) {
          { Class* self = NULL;

            self = ((Class*)(self_001));
            definitionstring = self->class_stringified_source;
          }
        }
        else {
        }
      }
    }
    if (definitionstring != NULL) {
      pretty_print_relation_definition_tree(((Cons*)(unstringify(definitionstring))), stream);
    }
  }
}

void pretty_print_relation_definition_tree(Cons* tree, Output_Stream* stream) {
  help_pretty_print_relation_definition_tree(tree, stream, 0, 2, TRUE);
  *(stream->native_stream) << endl;
  tree->free_parse_tree();
}

void help_pretty_print_relation_definition_tree(Cons* tree, Output_Stream* stream, int startindent, int keyindent, boolean forcefirstkeyonseparatelineP) {
  { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;
    boolean old_OprintprettyPO_001 = oPRINTPRETTYpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRINTREADABLYpo = TRUE;
          oPRINTPRETTYpo = TRUE;
          { Object* value_001 = NULL;

            { Object* element = NULL;
              Cons* iter_001 = tree;

              while (!nilP(iter_001)) {
                {
                  element = iter_001->value;
                  iter_001 = iter_001->rest;
                }
                if (keywordP(element)) {
                  value_001 = element;
                  {
                    break;
                  }
                }
              }
            }
            { int nofheaderelements = tree->position(value_001, 0);

              { Property_List* self_001 = new_property_list();

                self_001->the_plist = extract_options(tree, NULL);
                { Property_List* options = self_001;
                  int keylength = NULL_INTEGER;

                  if (nofheaderelements == NULL_INTEGER) {
                    nofheaderelements = tree->length();
                  }
                  forcefirstkeyonseparatelineP = forcefirstkeyonseparatelineP ||
                      (options->length() > 1);
                  *(stream->native_stream) << "(";
                  { int i = NULL_INTEGER;
                    Object* element = NULL;
                    Cons* iter_002 = tree;
                    int iter_003 = 1;
                    int upper_bound_001 = nofheaderelements;
                    boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

                    while ((!nilP(iter_002)) &&
                        (unboundedP_001 ||
                         (iter_003 <= upper_bound_001))) {
                      {
                        element = iter_002->value;
                        iter_002 = iter_002->rest;
                      }
                      {
                        i = iter_003;
                        iter_003 = iter_003 + 1;
                      }
                      if (i > 1) {
                        *(stream->native_stream) << " ";
                      }
                      *(stream->native_stream) << element;
                    }
                  }
                  { int i = NULL_INTEGER;
                    Object* value = NULL;
                    Object* key = NULL;
                    Cons* iter_004 = options->the_plist;
                    int iter_005 = 1;

                    while (!nilP(iter_004)) {
                      key = iter_004->value;
                      {
                        value = iter_004->rest->value;
                        iter_004 = iter_004->rest->rest;
                      }
                      {
                        i = iter_005;
                        iter_005 = iter_005 + 1;
                      }
                      if ((i == 1) &&
                          (!forcefirstkeyonseparatelineP)) {
                        if (nofheaderelements > 0) {
                          *(stream->native_stream) << " ";
                        }
                      }
                      else {
                        *(stream->native_stream) << endl;
                        print_indent(stream, startindent + keyindent);
                      }
                      { Object* key_001 = key;

                        if (keywordP(key)) {
                          { Keyword* key = NULL;

                            key = ((Keyword*)(key_001));
                            keylength = string_length(key->symbol_name) + 1;
                            *(stream->native_stream) << ":" << string_downcase(key->symbol_name);
                          }
                        }
                        else {
                          keylength = 4;
                          *(stream->native_stream) << key;
                        }
                      }
                      *(stream->native_stream) << " ";
                      if (((key == KWD_KIF_OUT_SLOTS) ||
                          ((key == KWD_KIF_OUT_PUBLIC_SLOTS) ||
                           ((key == KWD_KIF_OUT_METHODS) ||
                            (key == KWD_KIF_OUT_PUBLIC_METHODS)))) &&
                          consP(value)) {
                        *(stream->native_stream) << "(";
                        { int i = NULL_INTEGER;
                          Object* element = NULL;
                          Cons* iter_006 = ((Cons*)(value));
                          int iter_007 = 1;

                          while (!nilP(iter_006)) {
                            {
                              element = iter_006->value;
                              iter_006 = iter_006->rest;
                            }
                            {
                              i = iter_007;
                              iter_007 = iter_007 + 1;
                            }
                            if (i > 1) {
                              *(stream->native_stream) << endl;
                              print_indent(stream, keyindent + (keylength + 2));
                            }
                            if (consP(element)) {
                              help_pretty_print_relation_definition_tree(((Cons*)(element)), stream, startindent + (keyindent + (keylength + 2)), keyindent, FALSE);
                            }
                            else {
                              *(stream->native_stream) << value;
                            }
                          }
                        }
                        *(stream->native_stream) << ")";
                      }
                      else {
                        *(stream->native_stream) << value;
                      }
                    }
                  }
                  { Object* element = NULL;
                    Cons* iter_008 = tree->nth_rest(nofheaderelements);

                    while (!nilP(iter_008)) {
                      {
                        element = iter_008->value;
                        iter_008 = iter_008->rest;
                      }
                      *(stream->native_stream) << endl;
                      print_indent(stream, keyindent);
                      *(stream->native_stream) << element;
                    }
                  }
                  *(stream->native_stream) << ")";
                  options->free();
                }
              }
            }
          }
          oPRINTPRETTYpo = old_OprintprettyPO_001;
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPRINTPRETTYpo = old_OprintprettyPO_001;
        oPRINTREADABLYpo = old_OprintreadablyPO_001;
        resignal();
      }
    }
  }
}

void pretty_print_assertion(Proposition* proposition, Output_Stream* stream) {
  { Symbol* renamed_Operator = SYM_KIF_OUT_ASSERT;
    Surrogate* name = ((Surrogate*)(dynamic_slot_value(proposition, SYM_KIF_OUT_SURROGATE_VALUE_INVERSE, NULL)));

    if (name != NULL) {
      pretty_print_named_rule(name, stream);
      return;
    }
    { Keyword* old_OprintmodeO_001 = oPRINTMODEo;
      Output_Stream* old_OprintlogicalformstreamO_001 = oPRINTLOGICALFORMSTREAMo;
      int old_OindentcounterO_001 = oINDENTCOUNTERo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTMODEo = KWD_KIF_OUT_ORIGINAL;
            oPRINTLOGICALFORMSTREAMo = stream;
            oINDENTCOUNTERo = 8;
            *(stream->native_stream) << "(" << renamed_Operator << " ";
            pretty_print_logical_form(proposition, stream);
            *(stream->native_stream) << ")" << endl;
            oINDENTCOUNTERo = old_OindentcounterO_001;
            oPRINTLOGICALFORMSTREAMo = old_OprintlogicalformstreamO_001;
            oPRINTMODEo = old_OprintmodeO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oINDENTCOUNTERo = old_OindentcounterO_001;
          oPRINTLOGICALFORMSTREAMo = old_OprintlogicalformstreamO_001;
          oPRINTMODEo = old_OprintmodeO_001;
          resignal();
        }
      }
    }
  }
}

void pretty_print_named_rule(Surrogate* rulename, Output_Stream* stream) {
  { Symbol* renamed_Operator = SYM_KIF_OUT_DEFRULE;
    Proposition* proposition = ((Proposition*)(rulename->surrogate_value));

    { Keyword* old_OprintmodeO_001 = oPRINTMODEo;
      Output_Stream* old_OprintlogicalformstreamO_001 = oPRINTLOGICALFORMSTREAMo;
      int old_OindentcounterO_001 = oINDENTCOUNTERo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTMODEo = KWD_KIF_OUT_ORIGINAL;
            oPRINTLOGICALFORMSTREAMo = stream;
            oINDENTCOUNTERo = 2;
            *(stream->native_stream) << "(" << renamed_Operator << " " << type_to_symbol(rulename) << endl;
            print_indent(stream, NULL_INTEGER);
            pretty_print_logical_form(proposition, stream);
            *(stream->native_stream) << ")" << endl;
            oINDENTCOUNTERo = old_OindentcounterO_001;
            oPRINTLOGICALFORMSTREAMo = old_OprintlogicalformstreamO_001;
            oPRINTMODEo = old_OprintmodeO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oINDENTCOUNTERo = old_OindentcounterO_001;
          oPRINTLOGICALFORMSTREAMo = old_OprintlogicalformstreamO_001;
          oPRINTMODEo = old_OprintmodeO_001;
          resignal();
        }
      }
    }
  }
}

void do_save_module(Module* module, char* file) {
  // Save `module' to `file'.
  { Output_File_Stream* stream = new_output_file_stream(file);

    { Module* old_OmoduleO_001 = oMODULEo;
      Context* old_OcontextO_001 = oCONTEXTo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oMODULEo = module;
            oCONTEXTo = oMODULEo;
            cl_output_file_header(stream, "STELLA", FALSE, FALSE);
            module->print_definition(stream);
            *(stream->native_stream) << endl;
            *(stream->native_stream) << "(in-module \"" << module->module_full_name << "\")" << endl << endl << "(in-dialect " << oLOGIC_DIALECTo << ")" << endl << endl;
            { Class* renamed_Class = NULL;
              Iterator* iter_001 = all_classes(module, TRUE);

              while (iter_001->nextP()) {
                {
                  renamed_Class = ((Class*)(iter_001->value));
                }
                pretty_print_relation_definition(renamed_Class, stream);
                *(stream->native_stream) << endl;
                { Slot* slot = NULL;
                  Cons* iter_002 = renamed_Class->class_local_slots->the_cons_list;

                  while (!nilP(iter_002)) {
                    {
                      slot = ((Slot*)(iter_002->value));
                      iter_002 = iter_002->rest;
                    }
                    if (((String_Wrapper*)(dynamic_slot_value(slot, SYM_KIF_OUT_RELATION_STRINGIFIED_SOURCE, NULL_STRING_WRAPPER)))->wrapper_value != NULL) {
                      pretty_print_relation_definition(slot, stream);
                      *(stream->native_stream) << endl;
                    }
                  }
                }
              }
            }
            { Method_Slot* function = NULL;
              Iterator* iter_003 = all_functions(module, TRUE);

              while (iter_003->nextP()) {
                {
                  function = ((Method_Slot*)(iter_003->value));
                }
                if (((String_Wrapper*)(dynamic_slot_value(function, SYM_KIF_OUT_RELATION_STRINGIFIED_SOURCE, NULL_STRING_WRAPPER)))->wrapper_value != NULL) {
                  pretty_print_relation_definition(function, stream);
                  *(stream->native_stream) << endl;
                }
              }
            }
            { Hash_Table* old_OexcludedpropositionsO_001 = oEXCLUDEDPROPOSITIONSo;

              { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oEXCLUDEDPROPOSITIONSo = new_hash_table();
                    exclude_relation_originated_propositions();
                    { Proposition* proposition = NULL;
                      Cons* iter_004 = module->locally_conceived_propositions_getter()->copy()->reverse()->the_cons_list;

                      while (!nilP(iter_004)) {
                        {
                          proposition = ((Proposition*)(iter_004->value));
                          iter_004 = iter_004->rest;
                        }
                        if (!excluded_propositionP(proposition)) {
                          pretty_print_assertion(proposition, stream);
                          *(stream->native_stream) << endl;
                        }
                      }
                    }
                    oEXCLUDEDPROPOSITIONSo = old_OexcludedpropositionsO_001;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oEXCLUDEDPROPOSITIONSo = old_OexcludedpropositionsO_001;
                  resignal();
                }
              }
            }
            stream->free();
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
}

void save_module(Object* name, char* file) {
  // Save all definitions and assertions of module `name' to `file'.
  { Module* module = coerce_to_module(name, TRUE);

    if (module != NULL) {
      do_save_module(module, file);
    }
  }
}

void save_module_evaluator_wrapper(Cons* arguments) {
  save_module(arguments->value, ((String_Wrapper*)(arguments->rest->value))->wrapper_value);
}

void startup_kif_out() {
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
            SGT_KIF_OUT_LITERAL_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("LITERAL-WRAPPER", string_get_module("/STELLA", TRUE), 1)));
            SGT_KIF_OUT_LOGIC_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-OBJECT", NULL, 1)));
            KWD_KIF_OUT_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            SGT_KIF_OUT_PROPOSITION = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPOSITION", NULL, 1)));
            SYM_KIF_OUT_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 0)));
            SGT_KIF_OUT_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("SLOT", string_get_module("/STELLA", TRUE), 1)));
            SYM_KIF_OUT_oPRETTYPRINTLOGICALFORMSpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PRETTYPRINTLOGICALFORMS?*", NULL, 0)));
            SYM_KIF_OUT_oPRETTYPRINTKIFpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PRETTYPRINTKIF?*", NULL, 0)));
            SYM_KIF_OUT_oPRINTLOGICALFORMSTREAMo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PRINTLOGICALFORMSTREAM*", NULL, 0)));
            SYM_KIF_OUT_oDOWNCASEOPERATORSpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*DOWNCASEOPERATORS?*", NULL, 0)));
            SYM_KIF_OUT_oINDENTCOUNTERo = ((Symbol*)(intern_rigid_symbol_wrt_module("*INDENTCOUNTER*", NULL, 0)));
            KWD_KIF_OUT_KIF = ((Keyword*)(intern_rigid_symbol_wrt_module("KIF", NULL, 2)));
            KWD_KIF_OUT_STELLA = ((Keyword*)(intern_rigid_symbol_wrt_module("STELLA", NULL, 2)));
            KWD_KIF_OUT_PREFIX_STELLA = ((Keyword*)(intern_rigid_symbol_wrt_module("PREFIX-STELLA", NULL, 2)));
            KWD_KIF_OUT_SQL = ((Keyword*)(intern_rigid_symbol_wrt_module("SQL", NULL, 2)));
            SGT_KIF_OUT_DESCRIPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 1)));
            SGT_KIF_OUT_PATTERN_VARIABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("PATTERN-VARIABLE", NULL, 1)));
            SGT_KIF_OUT_SKOLEM = ((Surrogate*)(intern_rigid_symbol_wrt_module("SKOLEM", NULL, 1)));
            SGT_KIF_OUT_COLLECTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION", string_get_module("/STELLA", TRUE), 1)));
            KWD_KIF_OUT_IN = ((Keyword*)(intern_rigid_symbol_wrt_module("IN", NULL, 2)));
            KWD_KIF_OUT_REALISTIC = ((Keyword*)(intern_rigid_symbol_wrt_module("REALISTIC", NULL, 2)));
            KWD_KIF_OUT_ORIGINAL = ((Keyword*)(intern_rigid_symbol_wrt_module("ORIGINAL", NULL, 2)));
            SYM_KIF_OUT_oTOPLEVELPRINTKIFPROPOSITIONpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TOPLEVELPRINTKIFPROPOSITION?*", NULL, 0)));
            KWD_KIF_OUT_AND = ((Keyword*)(intern_rigid_symbol_wrt_module("AND", NULL, 2)));
            KWD_KIF_OUT_OR = ((Keyword*)(intern_rigid_symbol_wrt_module("OR", NULL, 2)));
            KWD_KIF_OUT_NOT = ((Keyword*)(intern_rigid_symbol_wrt_module("NOT", NULL, 2)));
            KWD_KIF_OUT_EQUIVALENT = ((Keyword*)(intern_rigid_symbol_wrt_module("EQUIVALENT", NULL, 2)));
            KWD_KIF_OUT_PREDICATE = ((Keyword*)(intern_rigid_symbol_wrt_module("PREDICATE", NULL, 2)));
            KWD_KIF_OUT_IMPLIES = ((Keyword*)(intern_rigid_symbol_wrt_module("IMPLIES", NULL, 2)));
            KWD_KIF_OUT_FORALL = ((Keyword*)(intern_rigid_symbol_wrt_module("FORALL", NULL, 2)));
            KWD_KIF_OUT_EXISTS = ((Keyword*)(intern_rigid_symbol_wrt_module("EXISTS", NULL, 2)));
            KWD_KIF_OUT_CONSTANT = ((Keyword*)(intern_rigid_symbol_wrt_module("CONSTANT", NULL, 2)));
            KWD_KIF_OUT_CONTAINED_BY = ((Keyword*)(intern_rigid_symbol_wrt_module("CONTAINED-BY", NULL, 2)));
            KWD_KIF_OUT_DELETED = ((Keyword*)(intern_rigid_symbol_wrt_module("DELETED", NULL, 2)));
            SGT_KIF_OUT_TYPE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TYPE", string_get_module("/STELLA", TRUE), 1)));
            SYM_KIF_OUT_IO_VARIABLES = ((Symbol*)(intern_rigid_symbol_wrt_module("IO-VARIABLES", NULL, 0)));
            SYM_KIF_OUT_SURROGATE_VALUE_INVERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE-VALUE-INVERSE", NULL, 0)));
            KWD_KIF_OUT_ENUMERATION = ((Keyword*)(intern_rigid_symbol_wrt_module("ENUMERATION", NULL, 2)));
            SGT_KIF_OUT_COLLECTIONdORDERED = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION.ORDERED", NULL, 1)));
            SGT_KIF_OUT_COLLECTIONdDUPLICATE_FREE = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION.DUPLICATE-FREE", NULL, 1)));
            SYM_KIF_OUT_pX = ((Symbol*)(intern_rigid_symbol_wrt_module("?X", NULL, 0)));
            SYM_KIF_OUT_pY = ((Symbol*)(intern_rigid_symbol_wrt_module("?Y", NULL, 0)));
            SYM_KIF_OUT_pZ = ((Symbol*)(intern_rigid_symbol_wrt_module("?Z", NULL, 0)));
            SYM_KIF_OUT_SKOLEM_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SKOLEM-NAME", NULL, 0)));
            SYM_KIF_OUT_oEXCLUDEDPROPOSITIONSo = ((Symbol*)(intern_rigid_symbol_wrt_module("*EXCLUDEDPROPOSITIONS*", NULL, 0)));
            SYM_KIF_OUT_MASTER_PROPOSITION = ((Symbol*)(intern_rigid_symbol_wrt_module("MASTER-PROPOSITION", NULL, 0)));
            SGT_KIF_OUT_COLLECTIONdCLOSED = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION.CLOSED", string_get_module("/STELLA", TRUE), 1)));
            SYM_KIF_OUT_RELATION_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("RELATION-STRINGIFIED-SOURCE", NULL, 0)));
            KWD_KIF_OUT_SLOTS = ((Keyword*)(intern_rigid_symbol_wrt_module("SLOTS", NULL, 2)));
            KWD_KIF_OUT_PUBLIC_SLOTS = ((Keyword*)(intern_rigid_symbol_wrt_module("PUBLIC-SLOTS", NULL, 2)));
            KWD_KIF_OUT_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("METHODS", NULL, 2)));
            KWD_KIF_OUT_PUBLIC_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("PUBLIC-METHODS", NULL, 2)));
            SYM_KIF_OUT_ASSERT = ((Symbol*)(intern_rigid_symbol_wrt_module("ASSERT", NULL, 0)));
            SYM_KIF_OUT_DEFRULE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFRULE", NULL, 0)));
            SYM_KIF_OUT_EVALUATOR_WRAPPER_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("EVALUATOR-WRAPPER-CODE", string_get_module("/STELLA", TRUE), 0)));
          }
          if (current_startup_time_phaseP(4)) {
            FAKE_VARIABLES = new_vector(3);
            REUSABLE_SKOLEM_MAPPING_TABLE = new_key_value_list();
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-FUNCTION-PROPOSITION-FACTS", "PROPOSITION", "(DEFUN COLLECT-FUNCTION-PROPOSITION-FACTS ((SELF PROPOSITION) (FACTS (LIST OF PROPOSITION)) (BEENTHERE (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&collect_function_proposition_facts));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-COLLECT-FACTS", "OBJECT", "(DEFUN HELP-COLLECT-FACTS ((SELF OBJECT) (FACTS (LIST OF PROPOSITION)) (BEENTHERE (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&help_collect_facts));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-FACTS-OF-OBJECT", "LOGIC-OBJECT", "(DEFUN (ALL-FACTS-OF-OBJECT (LIST OF PROPOSITION)) ((SELF LOGIC-OBJECT)) :DOCUMENTATION \"Return a list of all definite (TRUE or FALSE) propositions\nattached to `self'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_facts_of_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-LOGIC-OBJECT", "STRING", "(DEFUN (GET-LOGIC-OBJECT LOGIC-OBJECT) ((NAME STRING)) :DOCUMENTATION \"Return the logic object named 'name'.\")");

              method->function_code = ((cpp_function_code)(&get_logic_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-FACTS-OF", "OBJECT", "(DEFUN (ALL-FACTS-OF (LIST OF PROPOSITION)) ((NAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Return a list of all definite (TRUE or FALSE) propositions\nthat reference the logic-object named `name'.\")");

              method->function_code = ((cpp_function_code)(&all_facts_of));
            }
            { Method_Slot* method = define_method_from_stringified_source("RETRACT-FACTS-OF-OBJECT", "LOGIC-OBJECT", "(DEFUN RETRACT-FACTS-OF-OBJECT ((SELF LOGIC-OBJECT)) :DOCUMENTATION \"Retract all definite (TRUE or FALSE) propositions attached to `self'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&retract_facts_of_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("RETRACT-FACTS-OF", "OBJECT", "(DEFUN RETRACT-FACTS-OF ((NAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Retract all definite (TRUE or FALSE) propositions\nthat reference the logic-object named `name'.\")");

              method->function_code = ((cpp_function_code)(&retract_facts_of));
            }
            { Method_Slot* method = define_method_from_stringified_source("MAYBE-DOWNCASE", "STRING", "(DEFUN (MAYBE-DOWNCASE STRING) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&maybe_downcase));
            }
            { Method_Slot* method = define_method_from_stringified_source("INCREASE-INDENT", "INTEGER", "(DEFUN INCREASE-INDENT ((INDENT INTEGER)))");

              method->function_code = ((cpp_function_code)(&increase_indent));
            }
            { Method_Slot* method = define_method_from_stringified_source("DECREASE-INDENT", "INTEGER", "(DEFUN DECREASE-INDENT ((INDENT INTEGER)))");

              method->function_code = ((cpp_function_code)(&decrease_indent));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-INDENT", "OUTPUT-STREAM", "(DEFUN PRINT-INDENT ((STREAM OUTPUT-STREAM) (INDENT INTEGER)))");

              method->function_code = ((cpp_function_code)(&print_indent));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-LOGICAL-FORM-IN-DIALECT", "OBJECT", "(DEFUN PRINT-LOGICAL-FORM-IN-DIALECT ((SELF OBJECT) (DIALECT KEYWORD) (STREAM OUTPUT-STREAM)) :DOCUMENTATION \"Produce a stringified version of a logical representation\nof 'self' and write it to the stream 'stream'.  Use the dialect 'dialect',\nor use the current dialect if 'dialect' is NULL.\")");

              method->function_code = ((cpp_function_code)(&print_logical_form_in_dialect));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-LOGICAL-FORM", "OBJECT", "(DEFUN PRINT-LOGICAL-FORM ((FORM OBJECT) (STREAM OUTPUT-STREAM)) :DOCUMENTATION \"Print the logical form `form' to `stream' according to\nthe current setting of `*logic-dialect*'.  Pretty-printing is controlled\nby the current setting of `*prettyPrintLogicalForms?*'.\")");

              method->function_code = ((cpp_function_code)(&print_logical_form));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-LOGICAL-FORM", "OBJECT", "(DEFUN PRETTY-PRINT-LOGICAL-FORM ((FORM OBJECT) (STREAM OUTPUT-STREAM)) :DOCUMENTATION \"Pretty-print the logical form `form' to `stream' according\nto the current setting of `*logic-dialect*'.\")");

              method->function_code = ((cpp_function_code)(&pretty_print_logical_form));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-UNFORMATTED-LOGICAL-FORM", "OBJECT", "(DEFUN PRINT-UNFORMATTED-LOGICAL-FORM ((FORM OBJECT) (STREAM OUTPUT-STREAM)) :DOCUMENTATION \"Print the logical form `form' to `stream' according to\nthe current setting of `*logic-dialect*'.  Pretty-printing is explicitly\nforced to be turned off.\")");

              method->function_code = ((cpp_function_code)(&print_unformatted_logical_form));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-AS-KIF", "OBJECT", "(DEFUN PRINT-AS-KIF ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&print_as_kif));
            }
            { Method_Slot* method = define_method_from_stringified_source("VISIBLE-ARGUMENT?", "OBJECT", "(DEFUN (VISIBLE-ARGUMENT? BOOLEAN) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&visible_argumentP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VISIBLE-ARGUMENTS-COUNT", "VECTOR", "(DEFUN (VISIBLE-ARGUMENTS-COUNT INTEGER) ((ARGUMENTS ARGUMENTS-VECTOR)))");

              method->function_code = ((cpp_function_code)(&visible_arguments_count));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-ARGUMENTS", "VECTOR", "(DEFUN PRINT-KIF-ARGUMENTS ((ARGUMENTS ARGUMENTS-VECTOR) (SEPARATELINES? BOOLEAN) (OMITLASTARGUMENT? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&print_kif_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-OPERATOR-WITH-ARGUMENTS", "STRING", "(DEFUN PRINT-KIF-OPERATOR-WITH-ARGUMENTS ((OPERATOR STRING) (ARGUMENTS ARGUMENTS-VECTOR) (SEPARATELINES? BOOLEAN) (OMITLASTARGUMENT? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&print_kif_operator_with_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRINGIFIED-KIF-OPERATOR", "PROPOSITION", "(DEFUN (STRINGIFIED-KIF-OPERATOR STRING) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&stringified_kif_operator));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-PROPOSITION", "PROPOSITION", "(DEFUN PRINT-KIF-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&print_kif_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-PRINT-KIF-PROPOSITION", "PROPOSITION", "(DEFUN HELP-PRINT-KIF-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&help_print_kif_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-FUNCTION-PROPOSITION", "PROPOSITION", "(DEFUN PRINT-KIF-FUNCTION-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&print_kif_function_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-FUNCTION-EXPRESSION", "PROPOSITION", "(DEFUN PRINT-KIF-FUNCTION-EXPRESSION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&print_kif_function_expression));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-IN-PROPOSITION", "PROPOSITION", "(DEFUN PRINT-KIF-IN-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&print_kif_in_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-IMPLIES-PROPOSITION", "PROPOSITION", "(DEFUN PRINT-KIF-IMPLIES-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&print_kif_implies_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-QUANTIFIED-VARIABLES", "VECTOR", "(DEFUN PRINT-KIF-QUANTIFIED-VARIABLES ((VARIABLES (VECTOR OF SKOLEM))))");

              method->function_code = ((cpp_function_code)(&print_kif_quantified_variables));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-QUANTIFICATION", "PROPOSITION", "(DEFUN PRINT-KIF-QUANTIFICATION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&print_kif_quantification));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-TOP-LEVEL-EXISTS-PROPOSITION", "PROPOSITION", "(DEFUN PRINT-KIF-TOP-LEVEL-EXISTS-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&print_kif_top_level_exists_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-LITERAL-WRAPPER", "LITERAL-WRAPPER", "(DEFUN PRINT-KIF-LITERAL-WRAPPER ((SELF LITERAL-WRAPPER)))");

              method->function_code = ((cpp_function_code)(&print_kif_literal_wrapper));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-LOGIC-OBJECT", "LOGIC-OBJECT", "(DEFUN PRINT-KIF-LOGIC-OBJECT ((SELF LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&print_kif_logic_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-SKOLEM", "SKOLEM", "(DEFUN PRINT-KIF-SKOLEM ((SELF SKOLEM) (SUPPRESSDEFININGPROPOSITION? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&print_kif_skolem));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-VARIABLE", "PATTERN-VARIABLE", "(DEFUN PRINT-KIF-VARIABLE ((SELF PATTERN-VARIABLE)))");

              method->function_code = ((cpp_function_code)(&print_kif_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-ENUMERATION", "COLLECTION", "(DEFUN PRINT-KIF-ENUMERATION ((SELF COLLECTION)))");

              method->function_code = ((cpp_function_code)(&print_kif_enumeration));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KIF-DESCRIPTION", "DESCRIPTION", "(DEFUN PRINT-KIF-DESCRIPTION ((SELF DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&print_kif_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-DESCRIPTIONS-AS-KIF-RULE", "DESCRIPTION", "(DEFUN PRINT-DESCRIPTIONS-AS-KIF-RULE ((HEAD DESCRIPTION) (TAIL DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&print_descriptions_as_kif_rule));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXCLUDE-RELATION-ORIGINATED-PROPOSITIONS", NULL, "(DEFUN EXCLUDE-RELATION-ORIGINATED-PROPOSITIONS ())");

              method->function_code = ((cpp_function_code)(&exclude_relation_originated_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXCLUDED-PROPOSITION?", "PROPOSITION", "(DEFUN (EXCLUDED-PROPOSITION? BOOLEAN) ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&excluded_propositionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ENUMERATED-CLASS?", "OBJECT", "(DEFUN (ENUMERATED-CLASS? BOOLEAN) ((COLLECTION OBJECT)))");

              method->function_code = ((cpp_function_code)(&enumerated_classP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-RELATION-DEFINITION", "RELATION", "(DEFUN PRETTY-PRINT-RELATION-DEFINITION ((SELF RELATION) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&pretty_print_relation_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-RELATION-DEFINITION-TREE", "CONS", "(DEFUN PRETTY-PRINT-RELATION-DEFINITION-TREE ((TREE CONS) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&pretty_print_relation_definition_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-PRETTY-PRINT-RELATION-DEFINITION-TREE", "CONS", "(DEFUN HELP-PRETTY-PRINT-RELATION-DEFINITION-TREE ((TREE CONS) (STREAM OUTPUT-STREAM) (STARTINDENT INTEGER) (KEYINDENT INTEGER) (FORCEFIRSTKEYONSEPARATELINE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&help_pretty_print_relation_definition_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-ASSERTION", "PROPOSITION", "(DEFUN PRETTY-PRINT-ASSERTION ((PROPOSITION PROPOSITION) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&pretty_print_assertion));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-NAMED-RULE", "SURROGATE", "(DEFUN PRETTY-PRINT-NAMED-RULE ((RULENAME SURROGATE) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&pretty_print_named_rule));
            }
            { Method_Slot* method = define_method_from_stringified_source("DO-SAVE-MODULE", "MODULE", "(DEFUN DO-SAVE-MODULE ((MODULE MODULE) (FILE STRING)) :DOCUMENTATION \"Save `module' to `file'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&do_save_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("SAVE-MODULE", "OBJECT", "(DEFUN SAVE-MODULE ((NAME NAME) (FILE STRING)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Save all definitions and assertions of module `name' to `file'.\")");

              method->function_code = ((cpp_function_code)(&save_module));
              set_dynamic_slot_value(method, SYM_KIF_OUT_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&save_module_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            define_method_from_stringified_source("STARTUP-KIF-OUT", NULL, "(DEFUN STARTUP-KIF-OUT ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *PRETTYPRINTLOGICALFORMS?* BOOLEAN FALSE :DOCUMENTATION \"Controls whether logical forms print on single lines\n(unformatted) or multi-line indented.\")");
            { Global_Variable* global = SYM_KIF_OUT_oPRETTYPRINTLOGICALFORMSpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OprettyprintlogicalformsPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OprettyprintlogicalformsPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *PRETTYPRINTKIF?* BOOLEAN FALSE :DOCUMENTATION \"Controls whether KIF expressions print on single lines\n(unformatted) or multi-line indented.\")");
            { Global_Variable* global = SYM_KIF_OUT_oPRETTYPRINTKIFpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OprettyprintkifPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OprettyprintkifPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *PRINTLOGICALFORMSTREAM* OUTPUT-STREAM NULL :DOCUMENTATION \"Eliminates necessity of passing stream argument\nthroughout 'print-logical-form' functions.\" :PUBLIC? FALSE)");
            { Global_Variable* global = SYM_KIF_OUT_oPRINTLOGICALFORMSTREAMo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OprintlogicalformstreamO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OprintlogicalformstreamO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *DOWNCASEOPERATORS?* BOOLEAN FALSE :DOCUMENTATION \"Controls whether down-casing happens during logical\nform printing (leading to lots more string garbage).\")");
            { Global_Variable* global = SYM_KIF_OUT_oDOWNCASEOPERATORSpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OdowncaseoperatorsPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OdowncaseoperatorsPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *INDENTCOUNTER* INTEGER 0 :DOCUMENTATION \"The number of spaces prepended during printing a logical form.\")");
            { Global_Variable* global = SYM_KIF_OUT_oINDENTCOUNTERo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OindentcounterO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OindentcounterO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *INDENT-QUANTUM* INTEGER 3 :DOCUMENTATION \"The number of spaces added by a call to 'increase-indent'.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *TOPLEVELPRINTKIFPROPOSITION?* BOOLEAN TRUE)");
            { Global_Variable* global = SYM_KIF_OUT_oTOPLEVELPRINTKIFPROPOSITIONpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OtoplevelprintkifpropositionPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OtoplevelprintkifpropositionPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT FAKE-VARIABLES VARIABLES-VECTOR (NEW VARIABLES-VECTOR :ARRAY-SIZE 3) :DOCUMENTATION \"Used by 'print-descriptions-as-kif-rule' when there aren't\nany real variables to print.\")");
            { int i = NULL_INTEGER;
              Object* name = NULL;
              Cons* iter_038 = listO(4, SYM_KIF_OUT_pX, SYM_KIF_OUT_pY, SYM_KIF_OUT_pZ, NIL);
              int iter_039 = 0;

              while (!nilP(iter_038)) {
                {
                  name = iter_038->value;
                  iter_038 = iter_038->rest;
                }
                {
                  i = iter_039;
                  iter_039 = iter_039 + 1;
                }
                { Pattern_Variable* self_040 = new_pattern_variable();

                  set_dynamic_slot_value(self_040, SYM_KIF_OUT_SKOLEM_NAME, ((Symbol*)(name)), NULL);
                  FAKE_VARIABLES->nth_setter(self_040, i);
                }
              }
            }
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT REUSABLE-SKOLEM-MAPPING-TABLE (KEY-VALUE-LIST OF SKOLEM SKOLEM) (NEW KEY-VALUE-LIST) :DOCUMENTATION \"Stores reusable key-value list for use by\n'print-descriptions-as-kif-rule'.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *EXCLUDEDPROPOSITIONS* (HASH-TABLE OF PROPOSITION BOOLEAN-WRAPPER) NULL :DOCUMENTATION \"List of propositions that shouldn't be saved by `save-module'.\")");
            { Global_Variable* global = SYM_KIF_OUT_oEXCLUDEDPROPOSITIONSo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OexcludedpropositionsO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OexcludedpropositionsO));
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

