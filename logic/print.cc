// print.cc

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

Output_Stream* oNON_STANDARD_OUTPUT_STREAM_WRAPPERo = NULL;

Surrogate* SGT_PRINT_DESCRIPTION = NULL;

Surrogate* SGT_PRINT_PATTERN_VARIABLE = NULL;

Surrogate* SGT_PRINT_SKOLEM = NULL;

Surrogate* SGT_PRINT_LOGIC_OBJECT = NULL;

Surrogate* SGT_PRINT_PROPOSITION = NULL;

Keyword* oPRINTMODEo = NULL;

Keyword* KWD_PRINT_FLAT = NULL;

Symbol* SYM_PRINT_oPRINTMODEo = NULL;

Symbol* SYM_PRINT_SURROGATE_VALUE_INVERSE = NULL;

Surrogate* SGT_PRINT_UNKNOWN = NULL;

char* VARIABLE_BINDING_SEPARATOR = "/";

char* VALUE_OF_SEPARATOR = "//";

Key_Value_List* oSKOLEMNAMEMAPPINGTABLEo = NULL;

Symbol* SYM_PRINT_oSKOLEMNAMEMAPPINGTABLEo = NULL;

Symbol* SYM_PRINT_SKOLEM_NAME = NULL;

Keyword* KWD_PRINT_REALISTIC = NULL;

Keyword* KWD_PRINT_ORIGINAL = NULL;

Keyword* KWD_PRINT_DEBUG_LOW = NULL;

Keyword* KWD_PRINT_DEBUG_HIGH = NULL;

Surrogate* SGT_PRINT_RELATION = NULL;

Symbol* SYM_PRINT_DESCRIPTION = NULL;

Control_Frame* oPRINTINFRAMEo = NULL;

Symbol* SYM_PRINT_oPRINTINFRAMEo = NULL;

Symbol* SYM_PRINT_DEFINITION = NULL;

void print_top_level_object(Object* self, ostream* nativestream) {
  { Output_Stream* stream = STANDARD_OUTPUT;

    if (!(nativestream == STANDARD_OUTPUT->native_stream)) {
      oNON_STANDARD_OUTPUT_STREAM_WRAPPERo->native_stream = nativestream;
      stream = oNON_STANDARD_OUTPUT_STREAM_WRAPPERo;
    }
    if (self->deletedP()) {
      *(stream->native_stream) << "#DELETED#";
    }
    { Object* self_001 = self;

      if (taxonomy_isaP(self, SGT_PRINT_DESCRIPTION)) {
        { Description* self = NULL;

          self = ((Description*)(self_001));
          print_description(self, stream, TRUE);
        }
      }
      else if (taxonomy_isaP(self, SGT_PRINT_PATTERN_VARIABLE)) {
        { Pattern_Variable* self = NULL;

          self = ((Pattern_Variable*)(self_001));
          *(stream->native_stream) << "|V|";
          print_variable(self, stream);
        }
      }
      else if (taxonomy_isaP(self, SGT_PRINT_SKOLEM)) {
        { Skolem* self = NULL;

          self = ((Skolem*)(self_001));
          print_skolem(self, stream, TRUE);
        }
      }
      else if (taxonomy_isaP(self, SGT_PRINT_LOGIC_OBJECT)) {
        { Logic_Object* self = NULL;

          self = ((Logic_Object*)(self_001));
          print_logic_object(self, stream, TRUE);
        }
      }
      else if (taxonomy_isaP(self, SGT_PRINT_PROPOSITION)) {
        { Proposition* self = NULL;

          self = ((Proposition*)(self_001));
          print_proposition(self, stream, TRUE);
        }
      }
      else {
        *(stream->native_stream) << self;
      }
    }
    oNON_STANDARD_OUTPUT_STREAM_WRAPPERo->native_stream = NULL;
  }
}

Keyword* read_OprintmodeO() {
  return (oPRINTMODEo);
}

Keyword* write_OprintmodeO(Keyword* value) {
  oPRINTMODEo = value;
  return (value);
}

void print_object_name(Object* self, Output_Stream* stream) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_PRINT_SKOLEM)) {
      { Skolem* self = NULL;

        self = ((Skolem*)(self_001));
        *(stream->native_stream) << string_downcase(get_skolem_print_name(self));
      }
    }
    else if (taxonomy_isaP(self, SGT_PRINT_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        print_logic_object(self, stream, FALSE);
      }
    }
    else if (integerP(self)) {
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
    else if (stringP(self)) {
      { String_Wrapper* self = NULL;

        self = ((String_Wrapper*)(self_001));
        *(stream->native_stream) << self->wrapper_value;
      }
    }
    else {
      *(stream->native_stream) << self;
    }
  }
}

void print_logic_object(Logic_Object* self, Output_Stream* stream, boolean toplevelP) {
  { char* prefix = (toplevelP ? ((char*)("|i|")) : ((char*)("")));

    if (((Surrogate*)(dynamic_slot_value(self, SYM_PRINT_SURROGATE_VALUE_INVERSE, NULL))) != NULL) {
      if (!(((Surrogate*)(dynamic_slot_value(self, SYM_PRINT_SURROGATE_VALUE_INVERSE, NULL)))->surrogate_value == self)) {
        prefix = "|BAD|";
      }
      *(stream->native_stream) << prefix << ((Surrogate*)(dynamic_slot_value(self, SYM_PRINT_SURROGATE_VALUE_INVERSE, NULL)))->symbol_name;
    }
    else if (self == TRUE_TRUTH_VALUE) {
      *(stream->native_stream) << "TRUE-TV";
    }
    else if (self == FALSE_TRUTH_VALUE) {
      *(stream->native_stream) << "FALSE-TV";
    }
    else {
      if (self->root_type != NULL) {
        *(stream->native_stream) << prefix << "_" << self->root_type->symbol_name;
      }
      else {
        *(stream->native_stream) << prefix << "_" << SGT_PRINT_UNKNOWN->symbol_name;
      }
    }
  }
}

Key_Value_List* read_OskolemnamemappingtableO() {
  return (oSKOLEMNAMEMAPPINGTABLEo);
}

Key_Value_List* write_OskolemnamemappingtableO(Key_Value_List* value) {
  oSKOLEMNAMEMAPPINGTABLEo = value;
  return (value);
}

char* get_skolem_print_name(Skolem* self) {
  if (oSKOLEMNAMEMAPPINGTABLEo != NULL) {
    { Skolem* substituteskolem = ((Skolem*)(oSKOLEMNAMEMAPPINGTABLEo->lookup(self)));

      return (((substituteskolem != NULL) ? ((Symbol*)(((Symbol*)(dynamic_slot_value(substituteskolem, SYM_PRINT_SKOLEM_NAME, NULL))))) : ((Symbol*)(((Symbol*)(dynamic_slot_value(self, SYM_PRINT_SKOLEM_NAME, NULL))))))->symbol_name);
    }
  }
  else {
    return (((Symbol*)(dynamic_slot_value(self, SYM_PRINT_SKOLEM_NAME, NULL)))->symbol_name);
  }
}

void print_value_of_chain(Skolem* self, Output_Stream* stream, Object* chainend) {
  if (chainend == NULL) {
    chainend = self;
  }
  if ((oPRINTMODEo == KWD_PRINT_REALISTIC) ||
      (oPRINTMODEo == KWD_PRINT_ORIGINAL)) {
    print_object_name(chainend, stream);
  }
  else if ((oPRINTMODEo == KWD_PRINT_FLAT) ||
      (oPRINTMODEo == KWD_PRINT_DEBUG_LOW)) {
    *(stream->native_stream) << string_downcase(get_skolem_print_name(self));
    if (self == chainend) {
      return;
    }
    *(stream->native_stream) << VALUE_OF_SEPARATOR;
    print_object_name(chainend, stream);
  }
  else if (oPRINTMODEo == KWD_PRINT_DEBUG_HIGH) {
    *(stream->native_stream) << get_skolem_print_name(self);
    if (self == chainend) {
      return;
    }
    { Object* cursor = self;
      Object* nextvalue = NULL;

      for (;;) {
        { Object* cursor_001 = cursor;

          if (taxonomy_isaP(cursor, SGT_PRINT_LOGIC_OBJECT)) {
            { Logic_Object* cursor = NULL;

              cursor = ((Logic_Object*)(cursor_001));
              nextvalue = ((Object*)(access_in_context(cursor->variable_value, cursor, FALSE)));
            }
          }
          else if (surrogateP(cursor)) {
            { Surrogate* cursor = NULL;

              cursor = ((Surrogate*)(cursor_001));
              nextvalue = cursor->surrogate_value;
            }
          }
          else if (taxonomy_isaP(cursor, SGT_PRINT_RELATION)) {
            { Relation* cursor = NULL;

              cursor = ((Relation*)(cursor_001));
              nextvalue = ((Description*)(dynamic_slot_value(cursor, SYM_PRINT_DESCRIPTION, NULL)));
            }
          }
          else {
            cerr << "`" << cursor << "'" << " is not a valid case option";
          }
        }
        *(stream->native_stream) << VALUE_OF_SEPARATOR;
        print_object_name(nextvalue, stream);
        if (eqlP(nextvalue, chainend)) {
          break;
        }
        cursor = nextvalue;
      }
    }
  }
  else {
    cerr << "`" << oPRINTMODEo << "'" << " is not a valid case option";
  }
}

void print_value(Object* self, Output_Stream* stream) {
  { Object* self_001 = self;

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
      *(stream->native_stream) << self;
    }
  }
}

void print_skolem(Skolem* self, Output_Stream* stream, boolean toplevelP) {
  { char* prefix = "|SK|";

    if ((oPRINTMODEo == KWD_PRINT_ORIGINAL) ||
        (oPRINTMODEo == KWD_PRINT_REALISTIC)) {
      prefix = "";
      if (native_value_of(self) != NULL) {
        print_value(native_value_of(self), stream);
        return;
      }
    }
    else {
    }
    if ((self->defining_proposition != NULL) &&
        (((Object*)(access_in_context(self->variable_value, self, FALSE))) == NULL)) {
      *(stream->native_stream) << prefix;
      { Output_Stream* old_OprintlogicalformstreamO_001 = oPRINTLOGICALFORMSTREAMo;
        int old_OindentcounterO_001 = oINDENTCOUNTERo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTLOGICALFORMSTREAMo = stream;
              oINDENTCOUNTERo = 20;
              print_kif_function_expression(self->defining_proposition);
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
      return;
    }
    print_value_of_chain(self, stream, innermost_of(self));
  }
}

Object* bound_to_in_frame(Pattern_Variable* self, Control_Frame* frame) {
  if (frame->parent_pattern_frame == NULL) {
    return (NULL);
  }
  else {
    return (oQUERYENVIRONMENTo->variable_frame_stack->nth(((Subquery_Frame*)(frame->parent_pattern_frame->iterator))->local_variable_frame_offset + self->bound_to_offset));
  }
}

Control_Frame* read_OprintinframeO() {
  return (oPRINTINFRAMEo);
}

Control_Frame* write_OprintinframeO(Control_Frame* value) {
  oPRINTINFRAMEo = value;
  return (value);
}

void print_variable(Pattern_Variable* self, Output_Stream* stream) {
  if ((self->bound_to_offset != NULL_INTEGER) &&
      (oQUERYENVIRONMENTo != NULL)) {
    { Object* value = ((oPRINTINFRAMEo != NULL) ? ((Object*)(bound_to_in_frame(self, oPRINTINFRAMEo))) : ((Object*)(bound_to(self))));

      if (value != NULL) {
        *(stream->native_stream) << string_downcase(get_skolem_print_name(self)) << VARIABLE_BINDING_SEPARATOR;
        if (isaP(value, SGT_PRINT_PATTERN_VARIABLE)) {
          *(stream->native_stream) << get_skolem_print_name(((Skolem*)(value)));
        }
        else {
          print_top_level_object(value, stream->native_stream);
        }
        return;
      }
    }
  }
  print_value_of_chain(self, stream, innermost_of(self));
}

void print_quantified_variable(Pattern_Variable* self, Output_Stream* stream) {
  print_variable(self, stream);
}

void print_proposition(Proposition* self, Output_Stream* stream, boolean toplevelP) {
  { char* prefix = NULL;

    if (toplevelP) {
      if (trueP(self)) {
        prefix = "|P|";
      }
      else if (falseP(self)) {
        prefix = "|P~|";
      }
      else {
        prefix = "|P?|";
      }
    }
    if ((((Surrogate*)(dynamic_slot_value(self, SYM_PRINT_SURROGATE_VALUE_INVERSE, NULL))) != NULL) &&
        (!(((Surrogate*)(dynamic_slot_value(self, SYM_PRINT_SURROGATE_VALUE_INVERSE, NULL)))->surrogate_value == self))) {
      prefix = "|BAD|";
    }
    if (prefix != NULL) {
      *(stream->native_stream) << prefix;
    }
  }
  print_logical_form(self, stream);
}

void print_description(Description* self, Output_Stream* stream, boolean toplevelP) {
  if (toplevelP) {
    if ((self->native_relation != NULL) &&
        (dynamic_slot_value(self->native_relation, SYM_PRINT_DEFINITION, NULL) == self)) {
      *(stream->native_stream) << "|D=|";
    }
    else {
      *(stream->native_stream) << "|D|";
    }
  }
  print_logical_form(self, stream);
}

void startup_print() {
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
            SGT_PRINT_DESCRIPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 1)));
            SGT_PRINT_PATTERN_VARIABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("PATTERN-VARIABLE", NULL, 1)));
            SGT_PRINT_SKOLEM = ((Surrogate*)(intern_rigid_symbol_wrt_module("SKOLEM", NULL, 1)));
            SGT_PRINT_LOGIC_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-OBJECT", NULL, 1)));
            SGT_PRINT_PROPOSITION = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPOSITION", NULL, 1)));
            KWD_PRINT_FLAT = ((Keyword*)(intern_rigid_symbol_wrt_module("FLAT", NULL, 2)));
            SYM_PRINT_oPRINTMODEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PRINTMODE*", NULL, 0)));
            SYM_PRINT_SURROGATE_VALUE_INVERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE-VALUE-INVERSE", NULL, 0)));
            SGT_PRINT_UNKNOWN = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNKNOWN", string_get_module("/STELLA", TRUE), 1)));
            SYM_PRINT_oSKOLEMNAMEMAPPINGTABLEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*SKOLEMNAMEMAPPINGTABLE*", NULL, 0)));
            SYM_PRINT_SKOLEM_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SKOLEM-NAME", NULL, 0)));
            KWD_PRINT_REALISTIC = ((Keyword*)(intern_rigid_symbol_wrt_module("REALISTIC", NULL, 2)));
            KWD_PRINT_ORIGINAL = ((Keyword*)(intern_rigid_symbol_wrt_module("ORIGINAL", NULL, 2)));
            KWD_PRINT_DEBUG_LOW = ((Keyword*)(intern_rigid_symbol_wrt_module("DEBUG-LOW", NULL, 2)));
            KWD_PRINT_DEBUG_HIGH = ((Keyword*)(intern_rigid_symbol_wrt_module("DEBUG-HIGH", NULL, 2)));
            SGT_PRINT_RELATION = ((Surrogate*)(intern_rigid_symbol_wrt_module("RELATION", string_get_module("/STELLA", TRUE), 1)));
            SYM_PRINT_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 0)));
            SYM_PRINT_oPRINTINFRAMEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PRINTINFRAME*", NULL, 0)));
            SYM_PRINT_DEFINITION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINITION", NULL, 0)));
          }
          if (current_startup_time_phaseP(4)) {
            oNON_STANDARD_OUTPUT_STREAM_WRAPPERo = new_output_stream();
            oPRINTMODEo = KWD_PRINT_FLAT;
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("PRINT-TOP-LEVEL-OBJECT", "OBJECT", "(DEFUN PRINT-TOP-LEVEL-OBJECT ((SELF OBJECT) (NATIVESTREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_top_level_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-OBJECT-NAME", "OBJECT", "(DEFUN PRINT-OBJECT-NAME ((SELF OBJECT) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_object_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-LOGIC-OBJECT", "LOGIC-OBJECT", "(DEFUN PRINT-LOGIC-OBJECT ((SELF LOGIC-OBJECT) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&print_logic_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-SKOLEM-PRINT-NAME", "SKOLEM", "(DEFUN (GET-SKOLEM-PRINT-NAME STRING) ((SELF SKOLEM)))");

              method->function_code = ((cpp_function_code)(&get_skolem_print_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-VALUE-OF-CHAIN", "SKOLEM", "(DEFUN PRINT-VALUE-OF-CHAIN ((SELF SKOLEM) (STREAM OUTPUT-STREAM) (CHAINEND OBJECT)))");

              method->function_code = ((cpp_function_code)(&print_value_of_chain));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-VALUE", "OBJECT", "(DEFUN PRINT-VALUE ((SELF OBJECT) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-SKOLEM", "SKOLEM", "(DEFUN PRINT-SKOLEM ((SELF SKOLEM) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&print_skolem));
            }
            { Method_Slot* method = define_method_from_stringified_source("BOUND-TO-IN-FRAME", "PATTERN-VARIABLE", "(DEFUN (BOUND-TO-IN-FRAME OBJECT) ((SELF PATTERN-VARIABLE) (FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&bound_to_in_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-VARIABLE", "PATTERN-VARIABLE", "(DEFUN PRINT-VARIABLE ((SELF PATTERN-VARIABLE) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-QUANTIFIED-VARIABLE", "PATTERN-VARIABLE", "(DEFUN PRINT-QUANTIFIED-VARIABLE ((SELF PATTERN-VARIABLE) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_quantified_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-PROPOSITION", "PROPOSITION", "(DEFUN PRINT-PROPOSITION ((SELF PROPOSITION) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&print_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-DESCRIPTION", "DESCRIPTION", "(DEFUN PRINT-DESCRIPTION ((SELF DESCRIPTION) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&print_description));
            }
            define_method_from_stringified_source("STARTUP-PRINT", NULL, "(DEFUN STARTUP-PRINT ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *NON-STANDARD-OUTPUT-STREAM-WRAPPER* OUTPUT-STREAM (NEW OUTPUT-STREAM) :DOCUMENTATION \"Used by 'print-top-level-object' to pass \na native stream to routines that require a STELLA stream.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *PRINTMODE* KEYWORD :FLAT :DOCUMENTATION \"Controls the kind of detail that gets printed about\nindividual objects.  Values are :ORIGINAL, :REALISTIC, :FLAT, :DEBUG-LOW, and\n :DEBUG-HIGH.\")");
            { Global_Variable* global = SYM_PRINT_oPRINTMODEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OprintmodeO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OprintmodeO));
            }
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT VARIABLE-BINDING-SEPARATOR STRING \"/\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT VALUE-OF-SEPARATOR STRING \"//\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *SKOLEMNAMEMAPPINGTABLE* (KEY-VALUE-LIST OF SKOLEM SKOLEM) NULL :DOCUMENTATION \"If set, maps some skolems to names other than\ntheir own.\")");
            { Global_Variable* global = SYM_PRINT_oSKOLEMNAMEMAPPINGTABLEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OskolemnamemappingtableO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OskolemnamemappingtableO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *PRINTINFRAME* CONTROL-FRAME NULL :DOCUMENTATION \"If set, controls diagnostic printing by making\nvariable bindings appear relative to the frame '*printInFrame*'.\")");
            { Global_Variable* global = SYM_PRINT_oPRINTINFRAMEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OprintinframeO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OprintinframeO));
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

