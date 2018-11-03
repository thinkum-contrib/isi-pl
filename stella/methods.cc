// methods.cc

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996, 1997             | 
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

Surrogate* SGT_METHODS_SURROGATE = NULL;

Surrogate* SGT_METHODS_PARAMETRIC_TYPE_SPECIFIER = NULL;

Surrogate* SGT_METHODS_ANCHORED_TYPE_SPECIFIER = NULL;

Surrogate* SGT_METHODS_OBJECT = NULL;

Surrogate* SGT_METHODS_VOID = NULL;

Symbol* SYM_METHODS_LIKE = NULL;

Symbol* SYM_METHODS_SIZE = NULL;

Symbol* SYM_METHODS_OF = NULL;

Symbol* SYM_METHODS_SELF = NULL;

Symbol* SYM_METHODS_IN = NULL;

Symbol* SYM_METHODS_OUT = NULL;

Symbol* SYM_METHODS_INOUT = NULL;

Symbol* SYM_METHODS_METHOD_PARAMETER_DIRECTIONS = NULL;

Symbol* SYM_METHODS_ARGUMENT_LIST = NULL;

Symbol* SYM_METHODS_aREST = NULL;

Symbol* SYM_METHODS_METHOD_VARIABLE_ARGUMENTSp = NULL;

Symbol* SYM_METHODS_aBODY = NULL;

Symbol* SYM_METHODS_METHOD_BODY_ARGUMENTp = NULL;

Surrogate* SGT_METHODS_UNKNOWN = NULL;

Keyword* KWD_METHODS_TYPE = NULL;

Keyword* KWD_METHODS_RETURN_TYPES = NULL;

Symbol* SYM_METHODS_SLOT_TYPE_SPECIFIER = NULL;

Keyword* KWD_METHODS_PUBLICp = NULL;

Keyword* KWD_METHODS_NATIVEp = NULL;

Symbol* SYM_METHODS_METHOD_NATIVEp = NULL;

Keyword* KWD_METHODS_GLOBALLY_INLINEp = NULL;

Symbol* SYM_METHODS_METHOD_GLOBALLY_INLINEp = NULL;

Keyword* KWD_METHODS_INLINE = NULL;

Symbol* SYM_METHODS_METHOD_INLINED_FUNCTIONS = NULL;

Keyword* KWD_METHODS_AUXILIARYp = NULL;

Symbol* SYM_METHODS_SLOT_AUXILIARYp = NULL;

Keyword* KWD_METHODS_DOCUMENTATION = NULL;

Symbol* SYM_METHODS_DOCUMENTATION = NULL;

Keyword* KWD_METHODS_RETURNS = NULL;

Keyword* KWD_METHODS_STORAGE_SLOT = NULL;

Symbol* SYM_METHODS_STORAGE_SLOT = NULL;

Keyword* KWD_METHODS_INHERITS_THROUGH = NULL;

Symbol* SYM_METHODS_METHOD_INHERITS_THROUGH = NULL;

Keyword* KWD_METHODS_PROPERTIES = NULL;

Symbol* SYM_METHODS_PROPERTIES = NULL;

Keyword* KWD_METHODS_META_ATTRIBUTES = NULL;

Symbol* SYM_METHODS_META_ATTRIBUTES = NULL;

Keyword* KWD_METHODS_COMMANDp = NULL;

Symbol* SYM_METHODS_METHOD_COMMANDp = NULL;

Keyword* KWD_METHODS_LISP_MACROp = NULL;

Symbol* SYM_METHODS_METHOD_LISP_MACROp = NULL;

Keyword* KWD_METHODS_EVALUATE_ARGUMENTSp = NULL;

Symbol* SYM_METHODS_METHOD_EVALUATE_ARGUMENTSp = NULL;

int oMAXIMUM_STRING_CONSTANT_SIZEo = 4000;

Symbol* SYM_METHODS_CONCATENATE = NULL;

Symbol* SYM_METHODS_NULL = NULL;

Symbol* SYM_METHODS_DEFINE_METHOD_FROM_STRINGIFIED_SOURCE = NULL;

Surrogate* SGT_METHODS_BOOLEAN = NULL;

Symbol* SYM_METHODS_SUPER_CLASSES = NULL;

Symbol* SYM_METHODS_EQUIVALENT_SLOT = NULL;

Symbol* SYM_METHODS_CLASS_ALL_SUPER_CLASSES = NULL;

Symbol* SYM_METHODS_SLOT_DIRECT_EQUIVALENT = NULL;

Symbol* SYM_METHODS_LET = NULL;

Symbol* SYM_METHODS_CURSOR = NULL;

Symbol* SYM_METHODS_VALUE = NULL;

Symbol* SYM_METHODS_SLOT_VALUE = NULL;

Symbol* SYM_METHODS_LOOP = NULL;

Symbol* SYM_METHODS_WHEN = NULL;

Symbol* SYM_METHODS_RETURN = NULL;

Symbol* SYM_METHODS_SETQ = NULL;

Symbol* SYM_METHODS_IF = NULL;

Symbol* SYM_METHODS_DEFINEDp = NULL;

Surrogate* SGT_METHODS_COLLECTION = NULL;

Surrogate* SGT_METHODS_CONS = NULL;

Symbol* SYM_METHODS_FIRST = NULL;

Hash_Table* oFUNCTION_LOOKUP_TABLEo = NULL;

Hash_Table* oGLOBAL_VARIABLE_LOOKUP_TABLEo = NULL;

Symbol* SYM_METHODS_VARIABLE_TYPE_SPECIFIER = NULL;

Symbol* SYM_METHODS_DEFSPECIAL = NULL;

Symbol* SYM_METHODS_DEFCONSTANT = NULL;

Keyword* KWD_METHODS_UNBOUND_SPECIAL_VARIABLE = NULL;

Object* apply(cpp_function_code code, Cons* arguments) {
  // Apply `code' to `arguments', returning a value of type
  // OBJECT.
  switch (arguments->length()) {
    case 0: 
      return (((Object* (*) ())code)());
    case 1: 
      return (((Object* (*) (Object*))code)(arguments->first()));
    case 2: 
      return (((Object* (*) (Object*, Object*))code)(arguments->first(), arguments->second()));
    case 3: 
      return (((Object* (*) (Object*, Object*, Object*))code)(arguments->first(), arguments->second(), arguments->nth(2)));
    case 4: 
      return (((Object* (*) (Object*, Object*, Object*, Object*))code)(arguments->first(), arguments->second(), arguments->nth(2), arguments->nth(3)));
    case 5: 
      return (((Object* (*) (Object*, Object*, Object*, Object*, Object*))code)(arguments->first(), arguments->second(), arguments->nth(2), arguments->nth(3), arguments->nth(4)));
    default:
      cerr << "Too many function arguments in `apply'.  Max is 5.";
    break;
  }
}

Parametric_Type_Specifier* make_parametric_type_specifier() {
  // Return a transient or permanent instance of
  // 'PARAMETRIC-TYPE-SPECIFIER'.
  { Parametric_Type_Specifier* typespec = NULL;

    if (oTRANSIENTOBJECTSpo) {
      typespec = new_transient_type_specifier();
      typespec->specifier_parameter_types->free();
    }
    else {
      typespec = new Parametric_Type_Specifier;
    }
    return (typespec);
  }
}

boolean terminate_transient_type_specifierP(Transient_Type_Specifier* self) {
  self->specifier_parameter_types->free();
  return (TRUE);
}

boolean defined_typeP(Surrogate* type) {
  { Object* value = type->surrogate_value;
    Surrogate* valuetype = NULL;

    if (value != NULL) {
      valuetype = value->primary_type();
      return ((SGT_METHODS_SURROGATE == valuetype) ||
          ((SGT_METHODS_PARAMETRIC_TYPE_SPECIFIER == valuetype) ||
           (SGT_METHODS_ANCHORED_TYPE_SPECIFIER == valuetype)));
    }
    return (FALSE);
  }
}

Standard_Object* real_type_specifier(Surrogate* type) {
  { Object* value = type->surrogate_value;

    if (defined_typeP(type)) {
      if (typeP(value)) {
        return (real_type_specifier(((Surrogate*)(value))));
      }
      else {
        return (((Standard_Object*)(value)));
      }
    }
    else {
      return (type);
    }
  }
}

Surrogate* canonical_type(Surrogate* type) {
  { Class* renamed_Class = ((Class*)(type->surrogate_value));

    if (renamed_Class != NULL) {
      return (renamed_Class->class_type);
    }
    else {
      return (type);
    }
  }
}

Standard_Object* Surrogate::yield_type_specifier() {
  { Surrogate* typespectree = this;

    return (real_type_specifier(typespectree));
  }
}

Standard_Object* Symbol::yield_type_specifier() {
  { Symbol* typespectree = this;

    return (real_type_specifier(typify(typespectree)));
  }
}

Standard_Object* Parametric_Type_Specifier::yield_type_specifier() {
  { Parametric_Type_Specifier* typespectree = this;

    return (typespectree);
  }
}

Standard_Object* Anchored_Type_Specifier::yield_type_specifier() {
  { Anchored_Type_Specifier* typespectree = this;

    return (typespectree);
  }
}

Standard_Object* Object::yield_type_specifier() {
  { Object* typespectree = this;

    cerr << "Illegal type specification " << "`" << typespectree << "'";
    return (SGT_METHODS_OBJECT);
  }
}

Standard_Object* Cons::yield_type_specifier() {
  { Cons* typespectree = this;

    if (typespectree->emptyP()) {
      return (SGT_METHODS_VOID);
    }
    else if (typespectree->value == SYM_METHODS_LIKE) {
      return (yield_anchored_type_specifier(typespectree));
    }
    else {
      return (yield_parametric_type_specifier(typespectree));
    }
  }
}

Parametric_Type_Specifier* yield_parametric_type_specifier(Cons* typespectree) {
  { Parametric_Type_Specifier* typespec = new_parametric_type_specifier();

    { Object* cons_001 = typespectree->value;

      typespectree = typespectree->rest;
      { Object* basetype = cons_001;

        { Object* cons_002 = typespectree->value;

          typespectree = typespectree->rest;
          { Symbol* renamed_Operator = ((Symbol*)(cons_002));
            Integer_Wrapper* size = NULL;

            typespec->specifier_base_type = verify_type(typify(basetype));
            if (renamed_Operator == SYM_METHODS_SIZE) {
              { Object* cons_003 = typespectree->value;

                typespectree = typespectree->rest;
                size = ((Integer_Wrapper*)(cons_003));
              }
              typespec->specifier_sequence_size = size->wrapper_value;
              { Object* cons_004 = typespectree->value;

                typespectree = typespectree->rest;
                renamed_Operator = ((Symbol*)(cons_004));
              }
            }
            if (!(renamed_Operator == SYM_METHODS_OF)) {
              cerr << "Bad type specifier " << "`" << typespectree << "'";
              return (NULL);
            }
            { Object* p = NULL;
              Cons* iter_001 = typespectree;
              List* into_001 = typespec->specifier_parameter_types;
              Cons* collect_001 = NULL;

              while (!nilP(iter_001)) {
                {
                  p = iter_001->value;
                  iter_001 = iter_001->rest;
                }
                if (collect_001 == NULL) {
                  {
                    collect_001 = permanent_cons(p->yield_type_specifier(), NIL);
                    if (into_001->the_cons_list->emptyP()) {
                      into_001->the_cons_list = collect_001;
                    }
                    else {
                      add_cons_to_end_of_cons_list(into_001->the_cons_list, collect_001);
                    }
                  }
                }
                else {
                  {
                    collect_001->rest = permanent_cons(p->yield_type_specifier(), NIL);
                    collect_001 = collect_001->rest;
                  }
                }
              }
            }
            return (typespec);
          }
        }
      }
    }
  }
}

Anchored_Type_Specifier* yield_anchored_type_specifier(Cons* typespectree) {
  { Anchored_Type_Specifier* typespec = new_anchored_type_specifier();
    Object* likeargument = typespectree->second();

    if (!(likeargument == SYM_METHODS_SELF)) {
      typespec->specifier_parameter_name = ((Symbol*)(((Cons*)(likeargument))->first()->permanentify()));
    }
    return (typespec);
  }
}

void incorporate_input_parameters(Method_Slot* method, Cons* parameters) {
  if (parameters->emptyP()) {
    return;
  }
  { Symbol* name = NULL;
    Standard_Object* ts = NULL;
    Symbol* direction = NULL;
    boolean variableargsP = FALSE;

    method->method_parameter_names = new_list();
    method->method_parameter_type_specifiers = new_list();
    { Object* p = NULL;
      Cons* iter_001 = parameters;

      while (!nilP(iter_001)) {
        {
          p = iter_001->value;
          iter_001 = iter_001->rest;
        }
        { Object* p_001 = p;

          if (consP(p)) {
            { Cons* p = NULL;

              p = ((Cons*)(p_001));
              switch (p->length()) {
                case 2: 
                  direction = SYM_METHODS_IN;
                break;
                case 3: 
                  if ((p->first() == SYM_METHODS_IN) ||
                      ((p->first() == SYM_METHODS_OUT) ||
                       (p->first() == SYM_METHODS_INOUT))) {
                    direction = ((Symbol*)(p->first()));
                    if (null_listP(method->method_parameter_directions_reader())) {
                      set_dynamic_slot_value(method, SYM_METHODS_METHOD_PARAMETER_DIRECTIONS, new_list(), NULL);
                      { Object* par = NULL;
                        Cons* iter_002 = parameters;

                        while (!nilP(iter_002)) {
                          {
                            par = iter_002->value;
                            iter_002 = iter_002->rest;
                          }
                          if (par == p) {
                            break;
                          }
                          else {
                            method->method_parameter_directions_reader()->insert(SYM_METHODS_IN);
                          }
                        }
                      }
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
                            signal_translation_error();
                            if (!(suppress_warningsP())) {
                              print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                              cout << endl << " " << "Illegal direction for method parameter: " << "`" << de_uglify_parse_tree(p) << "'" << "." << endl;
                            }
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
                    direction = SYM_METHODS_IN;
                  }
                  p = p->rest;
                break;
                default:
                  { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                    { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oPRINTREADABLYpo = TRUE;
                          signal_translation_error();
                          if (!(suppress_warningsP())) {
                            print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                            cout << endl << " " << "Illegal method parameter: " << "`" << de_uglify_parse_tree(p) << "'" << "." << endl;
                          }
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
                  continue;
                break;
              }
              if (variableargsP) {
                { Cons* varargtype = listO(4, SYM_METHODS_ARGUMENT_LIST, SYM_METHODS_OF, p->second(), NIL);

                  name = ((Symbol*)(p->first()));
                  ts = varargtype->yield_type_specifier();
                  free_cons_list(varargtype);
                }
              }
              else {
                {
                  if (!(symbolP(p->first()) &&
                      (symbolP(p->second()) ||
                       (surrogateP(p->second()) ||
                        consP(p->second()))))) {
                    { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

                      { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                        oEXCEPTIONHANDLERADDRESSo = NULL;
                        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                          {
                            oPRINTREADABLYpo = TRUE;
                            signal_translation_error();
                            if (!(suppress_warningsP())) {
                              print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                              cout << endl << " " << "Illegal method parameter: " << "`" << de_uglify_parse_tree(p) << "'" << "." << endl;
                            }
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
                    continue;
                  }
                  name = ((Symbol*)(p->first()));
                  ts = p->second()->yield_type_specifier();
                }
              }
            }
          }
          else if (symbolP(p)) {
            { Symbol* p = NULL;

              p = ((Symbol*)(p_001));
              if (p == SYM_METHODS_aREST) {
                set_dynamic_slot_value(method, SYM_METHODS_METHOD_VARIABLE_ARGUMENTSp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
                variableargsP = TRUE;
                continue;
              }
              else if (p == SYM_METHODS_aBODY) {
                set_dynamic_slot_value(method, SYM_METHODS_METHOD_BODY_ARGUMENTp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
                continue;
              }
              else {
                { boolean old_OprintreadablyPO_004 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_error();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Untyped parameter in parameter list: " << "`" << de_uglify_parse_tree(parameters) << "'" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_004;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_004;
                      resignal();
                    }
                  }
                }
                name = p;
                ts = SGT_METHODS_UNKNOWN;
              }
            }
          }
          else {
            { boolean old_OprintreadablyPO_005 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_005 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Illegal parameter list: " << "`" << de_uglify_parse_tree(parameters) << "'" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_005;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_005;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_005;
                  resignal();
                }
              }
            }
            continue;
          }
        }
        method->method_parameter_type_specifiers_reader()->insert(ts);
        method->method_parameter_names_reader()->insert(((Symbol*)(name->permanentify())));
        if (defined_listP(method->method_parameter_directions_reader())) {
          method->method_parameter_directions_reader()->insert(direction);
        }
      }
    }
    method->method_parameter_names_reader()->reverse();
    method->method_parameter_type_specifiers_reader()->reverse();
    method->method_parameter_directions_reader()->reverse();
  }
}

void incorporate_first_input_parameter(Method_Slot* method) {
  { List* parametertypespecs = method->method_parameter_type_specifiers_reader();
    Standard_Object* firstargtype = ((Standard_Object*)(parametertypespecs->first()));

    if (!method->method_functionP) {
      if (parametertypespecs->emptyP()) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Method has no input parameters, converting it into a function" << "." << endl;
                }
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
        method->method_functionP = TRUE;
        return;
      }
      else if ((firstargtype != NULL) &&
          (!typeP(firstargtype))) {
        { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Illegal complex argument type for the first method parameter: " << endl << "   " << "`" << de_uglify_parse_tree(firstargtype) << "'" << "." << endl;
                }
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
        if (anchored_type_specifierP(firstargtype)) {
          method->method_parameter_type_specifiers_reader()->first_setter(SGT_METHODS_UNKNOWN);
          firstargtype = SGT_METHODS_UNKNOWN;
        }
      }
    }
    method->slot_owner = ((firstargtype != NULL) ? ((Surrogate*)(type_spec_to_base_type(firstargtype))) : ((Surrogate*)(NULL)));
  }
}

Method_Slot* define_stella_method_slot(Symbol* inputname, Cons* returntypes, boolean functionP, Cons* inputparameters, Keyword_Key_Value_List* options, Cons* methodbody) {
  // Define a new Stella method object (a slot), and attach it
  // to the class identified by the first parameter in 'inputParameters'.
  // Storage note: Copies 'options', but attaches to 'inputParameters' and
  // 'methodBody'.
  methodbody = methodbody;
  { Method_Slot* newmethod = new_method_slot();
    Symbol* name = ((Symbol*)(inputname->permanentify()));

    newmethod->slot_name = name;
    newmethod->method_functionP = functionP;
    incorporate_input_parameters(newmethod, inputparameters);
    incorporate_first_input_parameter(newmethod);
    if (returntypes->emptyP()) {
      if (options->lookup(KWD_METHODS_TYPE) != NULL) {
        returntypes = local_cons(options->lookup(KWD_METHODS_TYPE), NIL);
      }
      else if (options->lookup(KWD_METHODS_RETURN_TYPES) != NULL) {
        returntypes = local_cons(options->lookup(KWD_METHODS_RETURN_TYPES), NIL);
      }
    }
    { Standard_Object* typespec = (returntypes->emptyP() ? ((Standard_Object*)(SGT_METHODS_VOID)) : ((Standard_Object*)(returntypes->first()->yield_type_specifier())));

      if (typeP(typespec)) {
        newmethod->slot_base_type = ((Surrogate*)(typespec));
      }
      else {
        set_dynamic_slot_value(newmethod, SYM_METHODS_SLOT_TYPE_SPECIFIER, ((Compound_Type_Specifier*)(typespec)), NULL);
      }
    }
    if (!(returntypes->emptyP())) {
      newmethod->method_return_type_specifiers = new_list();
    }
    { Object* ts = NULL;
      Cons* iter_001 = returntypes;
      List* into_001 = newmethod->method_return_type_specifiers_reader();
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          ts = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = permanent_cons(ts->yield_type_specifier(), NIL);
            if (into_001->the_cons_list->emptyP()) {
              into_001->the_cons_list = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(into_001->the_cons_list, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = permanent_cons(ts->yield_type_specifier(), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    { Object* value = NULL;
      Keyword* key = NULL;
      Kv_List_Iterator* iter_002 = ((Kv_List_Iterator*)(options->allocate_iterator()));

      while (iter_002->nextP()) {
        key = ((Keyword*)(iter_002->key));
        {
          value = iter_002->value;
        }
        { Keyword* test_value_001 = ((Keyword*)(key));

          if (test_value_001 == KWD_METHODS_PUBLICp) {
            newmethod->slot_publicP = ((Boolean_Wrapper*)(value))->wrapper_value;
          }
          else if (test_value_001 == KWD_METHODS_NATIVEp) {
            set_dynamic_slot_value(newmethod, SYM_METHODS_METHOD_NATIVEp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
          }
          else if (test_value_001 == KWD_METHODS_GLOBALLY_INLINEp) {
            set_dynamic_slot_value(newmethod, SYM_METHODS_METHOD_GLOBALLY_INLINEp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
          }
          else if (test_value_001 == KWD_METHODS_INLINE) {
            if (newmethod->method_inlined_functions_reader()->emptyP()) {
              set_dynamic_slot_value(newmethod, SYM_METHODS_METHOD_INLINED_FUNCTIONS, new_list(), NULL);
            }
            { Object* value_001 = value;

              if (consP(value)) {
                { Cons* value = NULL;

                  value = ((Cons*)(value_001));
                  { Object* fnname = NULL;
                    Cons* iter_003 = value;

                    while (!nilP(iter_003)) {
                      {
                        fnname = iter_003->value;
                        iter_003 = iter_003->rest;
                      }
                      newmethod->method_inlined_functions_reader()->insert(((Symbol*)(fnname)));
                    }
                  }
                }
              }
              else if (symbolP(value)) {
                { Symbol* value = NULL;

                  value = ((Symbol*)(value_001));
                  newmethod->method_inlined_functions_reader()->insert(value);
                }
              }
              else {
                cerr << "Illegal :inline argument: " << "`" << value << "'";
              }
            }
          }
          else if (test_value_001 == KWD_METHODS_AUXILIARYp) {
            set_dynamic_slot_value(newmethod, SYM_METHODS_SLOT_AUXILIARYp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
          }
          else if (test_value_001 == KWD_METHODS_DOCUMENTATION) {
            set_dynamic_slot_value(newmethod, SYM_METHODS_DOCUMENTATION, wrap_string(((String_Wrapper*)(value))->wrapper_value), NULL_STRING_WRAPPER);
          }
          else if ((test_value_001 == KWD_METHODS_TYPE) ||
              (test_value_001 == KWD_METHODS_RETURNS)) {
          }
          else if (test_value_001 == KWD_METHODS_STORAGE_SLOT) {
            set_dynamic_slot_value(newmethod, SYM_METHODS_STORAGE_SLOT, ((Symbol*)(((Symbol*)(value))->permanentify())), NULL);
          }
          else if (test_value_001 == KWD_METHODS_INHERITS_THROUGH) {
            set_dynamic_slot_value(newmethod, SYM_METHODS_METHOD_INHERITS_THROUGH, ((Symbol*)(((Symbol*)(value))->permanentify())), NULL);
          }
          else if (test_value_001 == KWD_METHODS_PROPERTIES) {
            set_dynamic_slot_value(newmethod, SYM_METHODS_PROPERTIES, ((List*)(value)), NULL);
          }
          else if (test_value_001 == KWD_METHODS_META_ATTRIBUTES) {
            set_dynamic_slot_value(newmethod, SYM_METHODS_META_ATTRIBUTES, ((Key_Value_List*)(value)), NULL);
          }
          else if (test_value_001 == KWD_METHODS_COMMANDp) {
            set_dynamic_slot_value(newmethod, SYM_METHODS_METHOD_COMMANDp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
          }
          else if (test_value_001 == KWD_METHODS_LISP_MACROp) {
            set_dynamic_slot_value(newmethod, SYM_METHODS_METHOD_LISP_MACROp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
          }
          else if (test_value_001 == KWD_METHODS_EVALUATE_ARGUMENTSp) {
            set_dynamic_slot_value(newmethod, SYM_METHODS_METHOD_EVALUATE_ARGUMENTSp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
          }
          else {
            if (!(run_option_handlerP(newmethod, key, value))) {
              { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_warning();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Skipping invalid method option " << "`" << de_uglify_parse_tree(key) << "'" << endl << "in the definition of method " << "`" << newmethod->slot_owner << "'" << "." << "`" << de_uglify_parse_tree(name) << "'" << "." << endl;
                      }
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
      }
    }
    return (newmethod);
  }
}

Method_Slot* attach_method_slot_to_owner(Method_Slot* newmethod) {
  if (newmethod->method_functionP) {
    return (attach_function(newmethod));
  }
  if (newmethod->slot_owner->surrogate_value == NULL) {
    return (newmethod);
  }
  return (((Method_Slot*)(attach_slot_to_owner(newmethod))));
}

Object* yield_string_constant_tree(char* string) {
  { int length = string_length(string);
    Cons* chunks = NIL;
    int start = 0;
    Object* stringtree = NULL;

    if (length <= oMAXIMUM_STRING_CONSTANT_SIZEo) {
      return (string_wrap_literal(string));
    }
    while ((start + oMAXIMUM_STRING_CONSTANT_SIZEo) < length) {
      chunks = cons(string_wrap_literal(string_subsequence(string, start, start + oMAXIMUM_STRING_CONSTANT_SIZEo)), chunks);
      start = start + oMAXIMUM_STRING_CONSTANT_SIZEo;
    }
    if (start < length) {
      chunks = cons(string_wrap_literal(string_subsequence(string, start, length)), chunks);
    }
    stringtree = chunks->first();
    { Object* chunk = NULL;
      Cons* iter_001 = chunks->rest;

      while (!nilP(iter_001)) {
        {
          chunk = iter_001->value;
          iter_001 = iter_001->rest;
        }
        stringtree = listO(3, SYM_METHODS_CONCATENATE, chunk, cons(stringtree, NIL));
      }
    }
    free_cons_list(chunks);
    return (stringtree);
  }
}

Cons* yield_define_stella_method(Method_Slot* method) {
  { Object* wrappedclassname = ((method->slot_owner != NULL) ? ((Object*)(string_wrap_literal(method->slot_owner->symbol_name))) : ((Object*)(SYM_METHODS_NULL)));

    return (listO(3, SYM_METHODS_DEFINE_METHOD_FROM_STRINGIFIED_SOURCE, string_wrap_literal(method->name()), cons(wrappedclassname, cons(yield_string_constant_tree(method->method_stringified_source), NIL))));
  }
}

Cons* yield_class_parameter_types(Class* renamed_Class) {
  { Cons* types = NIL;

    { Symbol* pname = NULL;
      Cons* iter_001 = renamed_Class->parameters()->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          pname = ((Symbol*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(lookup_slot(renamed_Class, pname)->slot_base_type, NIL);
            if (nilP(types)) {
              types = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(types, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(lookup_slot(renamed_Class, pname)->slot_base_type, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    return (types);
  }
}

boolean optimistic_subtype_ofP(Surrogate* subtype, Surrogate* supertype) {
  if ((((Class*)(subtype->surrogate_value)) != NULL) &&
      ((((Class*)(supertype->surrogate_value)) != NULL) &&
       ((Class*)(subtype->surrogate_value))->class_finalizedP)) {
    return (subtype_ofP(subtype, supertype));
  }
  else {
    return (TRUE);
  }
}

void warn_of_parameter_mismatch(Parametric_Type_Specifier* self, char* message) {
  { Cons* inheritedtypes = yield_class_parameter_types(((Class*)(self->specifier_base_type->surrogate_value)));

    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            cerr << "`" << message << "'" << endl << "Type " << "`" << self->specifier_base_type << "'" << " takes parameters of type " << endl << "`" << inheritedtypes << "'" << " but was modified by a list of types " << "`" << self->specifier_parameter_types->the_cons_list << "'";
            free_cons_list(inheritedtypes);
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

Surrogate* validate_type_specifier(Standard_Object* self, Class* anchorclass, boolean skipanchoredtypeP) {
  { Standard_Object* self_001 = self;

    if (parametric_type_specifierP(self)) {
      { Parametric_Type_Specifier* self = NULL;

        self = ((Parametric_Type_Specifier*)(self_001));
        if (((Class*)(self->specifier_base_type->surrogate_value)) == NULL) {
          return (SGT_METHODS_UNKNOWN);
        }
        { int parameterdifferential = self->specifier_parameter_types->length() - ((Class*)(self->specifier_base_type->surrogate_value))->parameters()->length();

          if (parameterdifferential > 0) {
            warn_of_parameter_mismatch(self, "Too many parameters in type specification.");
          }
          else if (parameterdifferential < 0) {
            warn_of_parameter_mismatch(self, "Not enough parameters in type specification.");
          }
          else {
            { Class* baseclass = ((Class*)(type_spec_to_base_type(self)->surrogate_value));

              if (baseclass->class_slots_finalizedP) {
                { Cons* inheritedtypes = yield_class_parameter_types(baseclass);

                  { Standard_Object* subtypespec = NULL;
                    Surrogate* supertype = NULL;
                    Cons* iter_001 = inheritedtypes;
                    Cons* iter_002 = self->specifier_parameter_types->the_cons_list;

                    while ((!nilP(iter_001)) &&
                        (!nilP(iter_002))) {
                      {
                        supertype = ((Surrogate*)(iter_001->value));
                        iter_001 = iter_001->rest;
                      }
                      {
                        subtypespec = ((Standard_Object*)(iter_002->value));
                        iter_002 = iter_002->rest;
                      }
                      if ((!anchored_type_specifierP(subtypespec)) &&
                          (!optimistic_subtype_ofP(type_spec_to_base_type(subtypespec), supertype))) {
                        warn_of_parameter_mismatch(self, "Parameteric subtype(s) don't specialize supertype(s)");
                      }
                    }
                  }
                  free_cons_list(inheritedtypes);
                }
              }
            }
          }
          return (self->specifier_base_type);
        }
      }
    }
    else if (anchored_type_specifierP(self)) {
      { Anchored_Type_Specifier* self = NULL;

        self = ((Anchored_Type_Specifier*)(self_001));
        if (skipanchoredtypeP) {
          return (NULL);
        }
        if (anchorclass == NULL) {
          cerr << "Illegal use of anchored type for function that has no first\nargument (and hence nothing to anchor onto).";
          return (NULL);
        }
        { Symbol* slotname = self->specifier_parameter_name;
          Slot* anchorslot = NULL;

          if (slotname == NULL) {
            return (anchorclass->class_type);
          }
          { 
            anchorslot = lookup_slot(anchorclass, slotname);
            if (!(anchorslot != NULL)) {
              cerr << "Can't find a slot named " << "`" << slotname << "'" << " on the class " << "`" << class_name(anchorclass) << "'";
            }
          }
          return (anchorslot->slot_base_type);
        }
      }
    }
    else if (typeP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        return (self);
      }
    }
    else {
      cerr << "validate-type-specifier: Not defined on " << "`" << self << "'";
    }
  }
}

Cons* synthesize_method_body(Method_Slot* method) {
  if (((Class*)(SGT_METHODS_BOOLEAN->surrogate_value)) == NULL) {
    return (NIL);
  }
  { Symbol* storageslotname = ((Symbol*)(dynamic_slot_value(method, SYM_METHODS_STORAGE_SLOT, NULL)));
    Symbol* inheritanceslotname = ((Symbol*)(dynamic_slot_value(method, SYM_METHODS_METHOD_INHERITS_THROUGH, NULL)));
    Storage_Slot* storageslot = NULL;
    Slot* inheritanceslot = NULL;
    Object* defaultvalue = NULL;

    if (inheritanceslotname == SYM_METHODS_SUPER_CLASSES) {
      inheritanceslotname = SYM_METHODS_CLASS_ALL_SUPER_CLASSES;
    }
    else if (inheritanceslotname == SYM_METHODS_EQUIVALENT_SLOT) {
      inheritanceslotname = SYM_METHODS_SLOT_DIRECT_EQUIVALENT;
    }
    else {
    }
    storageslot = ((Storage_Slot*)(safe_lookup_slot(((Class*)(method->slot_owner->surrogate_value)), storageslotname)));
    if (storageslot == NULL) {
      cerr << ":storage-slot references non-existent slot " << "`" << storageslotname << "'" << " on the class " << "`" << method->slot_owner << "'";
      return (NIL);
    }
    inheritanceslot = safe_lookup_slot(((Class*)(method->slot_owner->surrogate_value)), inheritanceslotname);
    if (inheritanceslot == NULL) {
      cerr << ":inherits-through references non-existent slot " << "`" << inheritanceslotname << "'" << " on the class " << "`" << method->slot_owner << "'";
      return (NIL);
    }
    defaultvalue = storageslot->system_default_value();
    return (cons(listO(4, SYM_METHODS_LET, listO(3, listO(3, SYM_METHODS_CURSOR, SYM_METHODS_SELF, NIL), listO(3, SYM_METHODS_VALUE, listO(4, SYM_METHODS_SLOT_VALUE, SYM_METHODS_CURSOR, storageslotname, NIL), NIL), NIL), listO(5, SYM_METHODS_LOOP, cons(SYM_METHODS_WHEN, (subtype_ofP(storageslot->type(), SGT_METHODS_BOOLEAN) ? ((Cons*)(cons(SYM_METHODS_VALUE, NIL))) : ((Cons*)(cons(listO(3, SYM_METHODS_DEFINEDp, SYM_METHODS_VALUE, NIL), NIL))))->concatenate(cons(listO(3, SYM_METHODS_RETURN, SYM_METHODS_VALUE, NIL), NIL))), listO(4, SYM_METHODS_SETQ, SYM_METHODS_CURSOR, ((subtype_ofP(inheritanceslot->type(), SGT_METHODS_COLLECTION) ||
        subtype_ofP(inheritanceslot->type(), SGT_METHODS_CONS)) ? ((Cons*)(listO(3, SYM_METHODS_FIRST, cons(inheritanceslotname, cons(SYM_METHODS_CURSOR, NIL)), NIL))) : ((Cons*)(cons(inheritanceslotname, cons(SYM_METHODS_CURSOR, NIL))))), NIL), listO(5, SYM_METHODS_IF, listO(3, SYM_METHODS_DEFINEDp, SYM_METHODS_CURSOR, NIL), listO(4, SYM_METHODS_SETQ, SYM_METHODS_VALUE, listO(4, SYM_METHODS_SLOT_VALUE, SYM_METHODS_CURSOR, storageslotname, NIL), NIL), listO(3, SYM_METHODS_RETURN, ((defaultvalue != NULL) ? ((Object*)(defaultvalue)) : ((Object*)(SYM_METHODS_NULL))), NIL), NIL), NIL), NIL), NIL));
  }
}

void Method_Slot::finalize_slot_type_computations() {
  { Method_Slot* self = this;

    { Class* ownerclass = ((self->slot_owner != NULL) ? ((Class*)(((Class*)(self->slot_owner->surrogate_value)))) : ((Class*)(NULL)));

      { Standard_Object* ts = NULL;
        Cons* iter_001 = self->method_parameter_type_specifiers_reader()->the_cons_list;

        while (!nilP(iter_001)) {
          {
            ts = ((Standard_Object*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          validate_type_specifier(ts, ownerclass, FALSE);
        }
      }
      if (((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_METHODS_SLOT_TYPE_SPECIFIER, NULL))) != NULL) {
        self->slot_base_type = validate_type_specifier(((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_METHODS_SLOT_TYPE_SPECIFIER, NULL))), ownerclass, FALSE);
      }
      { Standard_Object* ts = NULL;
        Cons* iter_002 = self->method_return_type_specifiers_reader()->rest();

        while (!nilP(iter_002)) {
          {
            ts = ((Standard_Object*)(iter_002->value));
            iter_002 = iter_002->rest;
          }
          validate_type_specifier(ts, ownerclass, FALSE);
        }
      }
    }
  }
}

void Method_Slot::help_finalize_local_slot() {
  { Method_Slot* self = this;

  }
}

void Method_Slot::unfinalize_local_slot() {
  { Method_Slot* self = this;

  }
}

int Slot::method_argument_count() {
  { Slot* self = this;

    cerr << "method-argument-count: Not defined on " << "`" << self << "'";
    return (NULL_INTEGER);
  }
}

int Storage_Slot::method_argument_count() {
  { Storage_Slot* self = this;

    return (1);
  }
}

int Method_Slot::method_argument_count() {
  { Method_Slot* self = this;

    return (self->method_parameter_names_reader()->length());
  }
}

int Table::method_argument_count() {
  { Table* self = this;

    return (self->tuple_domains->length() - 1);
  }
}

boolean Storage_Slot::method_variable_argumentsP() {
  { Storage_Slot* self = this;

    return (FALSE);
  }
}

boolean Storage_Slot::method_body_argumentP() {
  { Storage_Slot* self = this;

    return (FALSE);
  }
}

int Storage_Slot::arity() {
  { Storage_Slot* self = this;

    return (2);
  }
}

int Method_Slot::arity() {
  { Method_Slot* self = this;

    { int returntypecount = self->method_return_type_specifiers_reader()->length();
      int result = self->method_parameter_type_specifiers_reader()->length() + returntypecount;

      switch (returntypecount) {
        case 1: 
          if (self->method_return_type_specifiers_reader()->first() == SGT_METHODS_BOOLEAN) {
            return (result - 1);
          }
          else {
            return (result);
          }
        break;
        case 0: 
          return (result);
        default:
          if (self->method_return_type_specifiers_reader()->last() == SGT_METHODS_BOOLEAN) {
            return (result - 1);
          }
          else {
            return (result);
          }
        break;
      }
    }
  }
}

int Table::arity() {
  { Table* self = this;

    return (self->tuple_domains->length());
  }
}

Surrogate* type_spec_to_base_type(Standard_Object* self) {
  { Standard_Object* self_001 = self;

    if (typeP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        return (self);
      }
    }
    else if (parametric_type_specifierP(self)) {
      { Parametric_Type_Specifier* self = NULL;

        self = ((Parametric_Type_Specifier*)(self_001));
        return (self->specifier_base_type);
      }
    }
    else {
      cerr << "type-spec-to-base-type: Not defined on " << "`" << self << "'";
    }
  }
}

Class* type_spec_to_class(Standard_Object* self) {
  return (((Class*)(type_spec_to_base_type(self)->surrogate_value)));
}

boolean compatible_parameter_typesP(Standard_Object* subtype, Standard_Object* supertype) {
  { boolean dummy1;
    boolean dummy2;

    if (typeP(subtype) ||
        typeP(supertype)) {
      return (TRUE);
    }
    { Class* subclass = NULL;
      Class* superclass = NULL;

      { Standard_Object* subtype_001 = subtype;

        if (typeP(subtype)) {
          { Surrogate* subtype = NULL;

            subtype = ((Surrogate*)(subtype_001));
            subclass = ((Class*)(subtype->surrogate_value));
          }
        }
        else if (parametric_type_specifierP(subtype)) {
          { Parametric_Type_Specifier* subtype = NULL;

            subtype = ((Parametric_Type_Specifier*)(subtype_001));
            subclass = ((Class*)(subtype->specifier_base_type->surrogate_value));
          }
        }
        else {
          cerr << "`" << subtype << "'" << " is not a valid case option";
        }
      }
      { Standard_Object* supertype_001 = supertype;

        if (typeP(supertype)) {
          { Surrogate* supertype = NULL;

            supertype = ((Surrogate*)(supertype_001));
            superclass = ((Class*)(supertype->surrogate_value));
          }
        }
        else if (parametric_type_specifierP(supertype)) {
          { Parametric_Type_Specifier* supertype = NULL;

            supertype = ((Parametric_Type_Specifier*)(supertype_001));
            superclass = ((Class*)(supertype->specifier_base_type->surrogate_value));
          }
        }
        else {
          cerr << "`" << supertype << "'" << " is not a valid case option";
        }
      }
      { Symbol* suppar = NULL;
        Cons* iter_001 = superclass->parameters()->the_cons_list;

        while (!nilP(iter_001)) {
          {
            suppar = ((Symbol*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          { boolean test_value_001 = FALSE;

            { boolean foundP_001 = FALSE;

              { Symbol* subpar = NULL;
                Cons* iter_002 = subclass->parameters()->the_cons_list;

                while (!nilP(iter_002)) {
                  {
                    subpar = ((Symbol*)(iter_002->value));
                    iter_002 = iter_002->rest;
                  }
                  if (suppar == subpar) {
                    foundP_001 = TRUE;
                    break;
                  }
                }
              }
              test_value_001 = foundP_001;
            }
            if (test_value_001) {
              test_value_001 = sub_type_spec_ofP(extract_parameter_type(subtype, suppar, dummy1), extract_parameter_type(supertype, suppar, dummy2));
            }
            if (!(test_value_001)) {
              return (FALSE);
            }
          }
        }
      }
      return (TRUE);
    }
  }
}

boolean sub_type_spec_ofP(Standard_Object* subtype, Standard_Object* supertype) {
  if (subtype == supertype) {
    return (TRUE);
  }
  { Standard_Object* subtype_001 = subtype;

    if (typeP(subtype)) {
      { Surrogate* subtype = NULL;

        subtype = ((Surrogate*)(subtype_001));
        { Standard_Object* supertype_001 = supertype;

          if (typeP(supertype)) {
            { Surrogate* supertype = NULL;

              supertype = ((Surrogate*)(supertype_001));
              return (subtype_ofP(subtype, supertype) &&
                  compatible_parameter_typesP(subtype, supertype));
            }
          }
          else if (parametric_type_specifierP(supertype)) {
            { Parametric_Type_Specifier* supertype = NULL;

              supertype = ((Parametric_Type_Specifier*)(supertype_001));
              return (subtype_ofP(subtype, supertype->specifier_base_type) &&
                  compatible_parameter_typesP(subtype, supertype));
            }
          }
          else {
            return (FALSE);
          }
        }
      }
    }
    else if (parametric_type_specifierP(subtype)) {
      { Parametric_Type_Specifier* subtype = NULL;

        subtype = ((Parametric_Type_Specifier*)(subtype_001));
        { Standard_Object* supertype_002 = supertype;

          if (typeP(supertype)) {
            { Surrogate* supertype = NULL;

              supertype = ((Surrogate*)(supertype_002));
              return (subtype_ofP(subtype->specifier_base_type, supertype) &&
                  compatible_parameter_typesP(subtype, supertype));
            }
          }
          else if (parametric_type_specifierP(supertype)) {
            { Parametric_Type_Specifier* supertype = NULL;

              supertype = ((Parametric_Type_Specifier*)(supertype_002));
              return (subtype_ofP(subtype->specifier_base_type, supertype->specifier_base_type) &&
                  compatible_parameter_typesP(subtype, supertype));
            }
          }
          else {
            cerr << "`" << supertype << "'" << " is not a valid case option";
          }
        }
      }
    }
    else if (anchored_type_specifierP(subtype)) {
      { Anchored_Type_Specifier* subtype = NULL;

        subtype = ((Anchored_Type_Specifier*)(subtype_001));
        return (anchored_type_specifierP(supertype) &&
            (subtype->specifier_parameter_name == ((Anchored_Type_Specifier*)(supertype))->specifier_parameter_name));
      }
    }
    else {
      cerr << "sub-type-spec-of?: Not defined on " << "`" << subtype << "'";
    }
  }
}

boolean voidP(Standard_Object* type) {
  return (type == SGT_METHODS_VOID);
}

Standard_Object* extract_parameter_type(Standard_Object* self, Symbol* parameter, boolean& return1) {
  { Standard_Object* self_001 = self;

    if (typeP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        { Slot* slot = lookup_slot(((Class*)(self->surrogate_value)), parameter);

          if (slot != NULL) {
            { Standard_Object* return_temp = slot->type();

              return1 = TRUE;
              return (return_temp);
            }
          }
          else {
            { Standard_Object* return_temp = SGT_METHODS_OBJECT;

              return1 = FALSE;
              return (return_temp);
            }
          }
        }
      }
    }
    else if (parametric_type_specifierP(self)) {
      { Parametric_Type_Specifier* self = NULL;

        self = ((Parametric_Type_Specifier*)(self_001));
        { Standard_Object* ptype = NULL;
          Symbol* pname = NULL;
          Cons* iter_001 = ((Class*)(self->specifier_base_type->surrogate_value))->parameters()->the_cons_list;
          Cons* iter_002 = self->specifier_parameter_types->the_cons_list;

          while ((!nilP(iter_001)) &&
              (!nilP(iter_002))) {
            {
              pname = ((Symbol*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            {
              ptype = ((Standard_Object*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            if (pname == parameter) {
              { Standard_Object* return_temp = ptype;

                return1 = TRUE;
                return (return_temp);
              }
            }
          }
        }
        { Standard_Object* return_temp = SGT_METHODS_OBJECT;

          return1 = FALSE;
          return (return_temp);
        }
      }
    }
    else {
      cerr << "extract-parameter-type: Not defined on " << "`" << self << "'";
    }
  }
}

Standard_Object* compute_anchored_type_spec(Standard_Object* ownertype, Anchored_Type_Specifier* reltype) {
  { Standard_Object* ownertype_001 = ownertype;

    if (typeP(ownertype)) {
      { Surrogate* ownertype = NULL;

        ownertype = ((Surrogate*)(ownertype_001));
        if (reltype->specifier_parameter_name == NULL) {
          return (ownertype);
        }
        { Slot* slot = lookup_slot(((Class*)(ownertype->surrogate_value)), reltype->specifier_parameter_name);

          return (slot->slot_base_type);
        }
      }
    }
    else if (parametric_type_specifierP(ownertype)) {
      { Parametric_Type_Specifier* ownertype = NULL;

        ownertype = ((Parametric_Type_Specifier*)(ownertype_001));
        if (reltype->specifier_parameter_name == NULL) {
          return (ownertype);
        }
        { Standard_Object* ptype = NULL;
          Symbol* pname = NULL;
          Cons* iter_001 = ((Class*)(ownertype->specifier_base_type->surrogate_value))->parameters()->the_cons_list;
          Cons* iter_002 = ownertype->specifier_parameter_types->the_cons_list;

          while ((!nilP(iter_001)) &&
              (!nilP(iter_002))) {
            {
              pname = ((Symbol*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            {
              ptype = ((Standard_Object*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            if (pname == reltype->specifier_parameter_name) {
              return (ptype);
            }
          }
        }
        return (compute_anchored_type_spec(ownertype->specifier_base_type, reltype));
      }
    }
    else {
      cerr << "compute-anchored-type-spec: Not defined on " << "`" << ownertype << "'";
    }
  }
}

Standard_Object* compute_relative_type_spec(Standard_Object* relativetype, Standard_Object* ownertype) {
  { Standard_Object* relativetype_001 = relativetype;

    if (parametric_type_specifierP(relativetype)) {
      { Parametric_Type_Specifier* relativetype = NULL;

        relativetype = ((Parametric_Type_Specifier*)(relativetype_001));
        { boolean alwaysP_001 = TRUE;

          { Standard_Object* ts = NULL;
            Cons* iter_001 = relativetype->specifier_parameter_types->the_cons_list;

            while (!nilP(iter_001)) {
              {
                ts = ((Standard_Object*)(iter_001->value));
                iter_001 = iter_001->rest;
              }
              if (!typeP(ts)) {
                alwaysP_001 = FALSE;
                break;
              }
            }
          }
          if (alwaysP_001) {
            return (relativetype);
          }
        }
        { List* typeslist = new_list();
          Standard_Object* relativets = NULL;
          boolean foundrelativistictypeP = FALSE;

          { Standard_Object* ts = NULL;
            Cons* iter_002 = relativetype->specifier_parameter_types->the_cons_list;
            Cons* collect_001 = NULL;

            while (!nilP(iter_002)) {
              {
                ts = ((Standard_Object*)(iter_002->value));
                iter_002 = iter_002->rest;
              }
              relativets = compute_relative_type_spec(ts, ownertype);
              if (!(relativets == ts)) {
                foundrelativistictypeP = TRUE;
              }
              if (collect_001 == NULL) {
                {
                  collect_001 = permanent_cons(relativets, NIL);
                  if (typeslist->the_cons_list->emptyP()) {
                    typeslist->the_cons_list = collect_001;
                  }
                  else {
                    add_cons_to_end_of_cons_list(typeslist->the_cons_list, collect_001);
                  }
                }
              }
              else {
                {
                  collect_001->rest = permanent_cons(relativets, NIL);
                  collect_001 = collect_001->rest;
                }
              }
            }
          }
          if (foundrelativistictypeP) {
            { Transient_Type_Specifier* newts = new_transient_type_specifier();

              newts->specifier_base_type = relativetype->specifier_base_type;
              newts->specifier_parameter_types = typeslist;
              return (newts);
            }
          }
          else {
            {
              typeslist->free();
              return (relativetype);
            }
          }
        }
      }
    }
    else if (anchored_type_specifierP(relativetype)) {
      { Anchored_Type_Specifier* relativetype = NULL;

        relativetype = ((Anchored_Type_Specifier*)(relativetype_001));
        return (compute_anchored_type_spec(ownertype, relativetype));
      }
    }
    else if (typeP(relativetype)) {
      { Surrogate* relativetype = NULL;

        relativetype = ((Surrogate*)(relativetype_001));
        return (relativetype);
      }
    }
    else {
      cerr << "compute-relative-type-spec: Not defined on " << "`" << relativetype << "'";
    }
  }
}

Standard_Object* Slot::compute_return_type_spec(Standard_Object* firstargtype) {
  { Slot* self = this;

    firstargtype = firstargtype;
    cerr << "compute-return-type-spec: Not defined on " << "`" << self << "'";
    return (NULL);
  }
}

Standard_Object* Method_Slot::compute_return_type_spec(Standard_Object* firstargtype) {
  { Method_Slot* self = this;

    if (((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_METHODS_SLOT_TYPE_SPECIFIER, NULL))) == NULL) {
      return (self->slot_base_type);
    }
    else {
      return (compute_relative_type_spec(((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_METHODS_SLOT_TYPE_SPECIFIER, NULL))), firstargtype));
    }
  }
}

Standard_Object* Storage_Slot::compute_return_type_spec(Standard_Object* firstargtype) {
  { Storage_Slot* self = this;

    if (((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_METHODS_SLOT_TYPE_SPECIFIER, NULL))) == NULL) {
      return (self->type());
    }
    else {
      return (compute_relative_type_spec(((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_METHODS_SLOT_TYPE_SPECIFIER, NULL))), firstargtype));
    }
  }
}

Object* yield_type_spec_tree(Standard_Object* self) {
  { Standard_Object* self_001 = self;

    if (typeP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        return (type_to_symbol(self));
      }
    }
    else if (parametric_type_specifierP(self)) {
      { Parametric_Type_Specifier* self = NULL;

        self = ((Parametric_Type_Specifier*)(self_001));
        { Cons* listoftypes = NIL;

          { Standard_Object* ts = NULL;
            Cons* iter_001 = self->specifier_parameter_types->the_cons_list;
            Cons* collect_001 = NULL;

            while (!nilP(iter_001)) {
              {
                ts = ((Standard_Object*)(iter_001->value));
                iter_001 = iter_001->rest;
              }
              if (collect_001 == NULL) {
                {
                  collect_001 = cons(yield_type_spec_tree(ts), NIL);
                  if (nilP(listoftypes)) {
                    listoftypes = collect_001;
                  }
                  else {
                    add_cons_to_end_of_cons_list(listoftypes, collect_001);
                  }
                }
              }
              else {
                {
                  collect_001->rest = cons(yield_type_spec_tree(ts), NIL);
                  collect_001 = collect_001->rest;
                }
              }
            }
          }
          return (cons(type_to_symbol(self->specifier_base_type), ((self->specifier_sequence_size != NULL_INTEGER) ? ((Cons*)(listO(3, SYM_METHODS_SIZE, integer_wrap_literal(self->specifier_sequence_size), NIL))) : ((Cons*)(NIL)))->concatenate(cons(SYM_METHODS_OF, listoftypes->concatenate(NIL)))));
        }
      }
    }
    else if (anchored_type_specifierP(self)) {
      { Anchored_Type_Specifier* self = NULL;

        self = ((Anchored_Type_Specifier*)(self_001));
        if (self->specifier_parameter_name != NULL) {
          return (listO(3, SYM_METHODS_LIKE, cons(self->specifier_parameter_name, cons(SYM_METHODS_SELF, NIL)), NIL));
        }
        else {
          return (listO(3, SYM_METHODS_LIKE, SYM_METHODS_SELF, NIL));
        }
      }
    }
    else {
      cerr << "validate-type-specifier: Not defined on " << "`" << self << "'";
    }
  }
}

Method_Slot* attach_function(Method_Slot* newfunction) {
  { Symbol* name = newfunction->slot_name;
    Method_Slot* oldfunction = ((Method_Slot*)(oFUNCTION_LOOKUP_TABLEo->lookup(name)));

    oFUNCTION_LOOKUP_TABLEo->insert_at(name, newfunction);
    unregister_slot_name(newfunction);
    newfunction->finalize_slot_type_computations();
    if (oldfunction != NULL) {
      run_hooks(oREDEFINE_RELATION_HOOKSo, list(2, oldfunction, newfunction));
      oldfunction->free();
    }
    return (newfunction);
  }
}

Method_Slot* string_lookup_function(char* name) {
  // Return a function with name 'name'.  Scan all
  // visible symbols looking for one that has a function defined for it.
  { Method_Slot* function = NULL;
    Symbol* symbol = NULL;

    { Module* module = NULL;
      Iterator* iter_001 = visible_modules(oMODULEo);

      while (iter_001->nextP()) {
        {
          module = ((Module*)(iter_001->value));
        }
        { boolean test_value_001 = FALSE;

          { 
            symbol = ((Symbol*)(lookup_rigid_symbol_locally(name, module, SYMBOL_SYM)));
            test_value_001 = symbol != NULL;
          }
          if (test_value_001) {
            { 
              function = ((Method_Slot*)(oFUNCTION_LOOKUP_TABLEo->lookup(symbol)));
              test_value_001 = function != NULL;
            }
          }
          if (test_value_001) {
            return (function);
          }
        }
      }
    }
    return (NULL);
  }
}

Method_Slot* Symbol::lookup_function() {
  // Return the function defined for 'functionSymbol', if
  // one exists.
  { Symbol* functionsymbol = this;

    return (((Method_Slot*)(oFUNCTION_LOOKUP_TABLEo->lookup(functionsymbol->soft_permanentify()))));
  }
}

Method_Slot* lookup_function_or_stella_function(Symbol* functionsymbol) {
  functionsymbol = functionsymbol->soft_permanentify();
  { Method_Slot* entry = ((Method_Slot*)(oFUNCTION_LOOKUP_TABLEo->lookup(functionsymbol)));

    return (entry);
  }
}

void destroy_function(Method_Slot* function) {
  { Symbol* functionname = function->slot_name;
    Surrogate* slotref = function->slot_slotref;
    Method_Slot* realfunction = functionname->lookup_function();

    if (function == realfunction) {
      oFUNCTION_LOOKUP_TABLEo->remove_at(functionname);
    }
    if ((slotref != NULL) &&
        (function == slotref->surrogate_value)) {
      slotref->surrogate_value = NULL;
    }
    function->deletedP_setter(TRUE);
    function->free();
  }
}

Global_Variable* intern_global_variable(Global_Variable* global) {
  { Symbol* name = global->variable_name;
    Global_Variable* oldglobal = name->lookup_global_variable();

    if (oldglobal != NULL) {
      if (string_eqlP(global->variable_stringified_source, oldglobal->variable_stringified_source)) {
        global->free();
        return (oldglobal);
      }
      else {
        cout << "Redefining the global variable " << "`" << global->variable_name << "'" << endl;
        oldglobal->free();
      }
    }
    oGLOBAL_VARIABLE_LOOKUP_TABLEo->insert_at(name, global);
    return (global);
  }
}

Global_Variable* Generalized_Symbol::lookup_global_variable() {
  // Return a global variable with name 'self'.
  { Generalized_Symbol* self = this;

    return (((Global_Variable*)(oGLOBAL_VARIABLE_LOOKUP_TABLEo->lookup(((Symbol*)(self))))));
  }
}

Global_Variable* Surrogate::lookup_global_variable() {
  // Return a global variable with name 'self'.
  { Surrogate* self = this;

    { Symbol* symbol = ((Symbol*)(lookup_rigid_symbol_wrt_module(self->symbol_name, ((Module*)(self->home_context)), SYMBOL_SYM)));

      if (symbol != NULL) {
        return (symbol->lookup_global_variable());
      }
      else {
        return (NULL);
      }
    }
  }
}

Global_Variable* string_lookup_global_variable(char* self) {
  // Return a global variable with name 'self'.
  { Symbol* symbol = lookup_symbol(self);

    if (symbol != NULL) {
      return (symbol->lookup_global_variable());
    }
    else {
      return (NULL);
    }
  }
}

Standard_Object* lookup_global_variable_type(Symbol* name) {
  { Global_Variable* global = name->lookup_global_variable();

    if (global != NULL) {
      if (((Standard_Object*)(dynamic_slot_value(global, SYM_METHODS_VARIABLE_TYPE_SPECIFIER, NULL))) != NULL) {
        return (((Standard_Object*)(dynamic_slot_value(global, SYM_METHODS_VARIABLE_TYPE_SPECIFIER, NULL))));
      }
      else {
        return (global->variable_type);
      }
    }
    return (NULL);
  }
}

Global_Variable* define_stella_global_variable_from_parse_tree(Cons* tree, char* stringifiedsource, Object*& return1) {
  { Object* typetree = tree->third();
    Object* initialvaluetree = tree->fourth();
    Cons* optionstree = tree->nth_rest(4);
    boolean specialP = tree->first() == SYM_METHODS_DEFSPECIAL;
    boolean constantP = tree->first() == SYM_METHODS_DEFCONSTANT;
    boolean noinitialvalueP = FALSE;
    Global_Variable* global = new_global_variable();
    Global_Variable* internedglobal = NULL;

    if ((tree->length() <= 3) ||
        (get_quoted_tree("((:DOCUMENTATION :PUBLIC? :AUXILIARY?) \"/STELLA\")", "/STELLA")->memberP(initialvaluetree) &&
         oddP(optionstree->length()))) {
      noinitialvalueP = TRUE;
      initialvaluetree = (specialP ? ((Keyword*)(KWD_METHODS_UNBOUND_SPECIAL_VARIABLE)) : ((Keyword*)(NULL)));
      optionstree = tree->nth_rest(3);
    }
    global->variable_name = ((Symbol*)(tree->second()->permanentify()));
    global->variable_stringified_source = stringifiedsource;
    internedglobal = intern_global_variable(global);
    if (noinitialvalueP &&
        (!specialP)) {
      if (constantP) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Missing value in constant declaration" << "." << endl;
                }
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
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Missing initial value in variable declaration" << "." << endl;
                }
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
      { Global_Variable* return_temp = internedglobal;

        return1 = initialvaluetree;
        return (return_temp);
      }
    }
    if (!(global == internedglobal)) {
      { Global_Variable* return_temp = internedglobal;

        return1 = initialvaluetree;
        return (return_temp);
      }
    }
    typetree = typetree->yield_type_specifier();
    validate_type_specifier(((Standard_Object*)(typetree)), NULL, TRUE);
    if (typeP(typetree)) {
      global->variable_type = ((Surrogate*)(typetree));
    }
    else {
      {
        set_dynamic_slot_value(global, SYM_METHODS_VARIABLE_TYPE_SPECIFIER, ((Standard_Object*)(typetree)), NULL);
        global->variable_type = type_spec_to_base_type(((Standard_Object*)(typetree)));
      }
    }
    global->variable_specialP = specialP;
    global->variable_constantP = constantP;
    if (optionstree->non_emptyP()) {
      { Property_List* options = new_property_list();

        options->the_plist = optionstree;
        { Object* value = NULL;
          Object* key = NULL;
          Cons* iter_001 = options->the_plist;

          while (!nilP(iter_001)) {
            key = iter_001->value;
            {
              value = iter_001->rest->value;
              iter_001 = iter_001->rest->rest;
            }
            { Keyword* test_value_001 = ((Keyword*)(key));

              if (test_value_001 == KWD_METHODS_DOCUMENTATION) {
                global->documentation = ((String_Wrapper*)(value))->wrapper_value;
              }
              else if (test_value_001 == KWD_METHODS_PUBLICp) {
                global->variable_publicP = symbol_to_wrapped_boolean(value)->wrapper_value;
              }
              else if (test_value_001 == KWD_METHODS_AUXILIARYp) {
                global->variable_auxiliaryP = symbol_to_wrapped_boolean(value)->wrapper_value;
              }
              else {
                cerr << "`" << test_value_001 << "'" << " is not a valid case option";
              }
            }
          }
        }
        options->the_plist = NULL;
      }
    }
    { Global_Variable* return_temp = global;

      return1 = initialvaluetree;
      return (return_temp);
    }
  }
}

void define_stella_global_variable_from_stringified_source(char* stringifiedsource) {
  { Object* dummy1;

    { Object* parsetree = NULL;

      { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oTRANSIENTOBJECTSpo = TRUE;
              parsetree = unstringify(stringifiedsource);
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
      define_stella_global_variable_from_parse_tree(((Cons*)(parsetree)), stringifiedsource, dummy1);
      parsetree->free_parse_tree();
    }
  }
}

Object* get_global_value(Surrogate* self) {
  // Return the (possibly-wrapped) value of the global
  // variable for the surrogate 'self'.
  return (((Object* (*) ())self->lookup_global_variable()->variable_get_value_code)());
}

Object* set_global_value(Surrogate* self, Object* value) {
  // Set the value of the global variable for the surrogate
  // 'self' to 'value'.
  return (((Object* (*) (Object*))self->lookup_global_variable()->variable_set_value_code)(value));
}

void destroy_variable(Global_Variable* variable) {
  { Symbol* variablename = variable->variable_name;
    Global_Variable* realvariable = variablename->lookup_global_variable();

    if (variable == realvariable) {
      oGLOBAL_VARIABLE_LOOKUP_TABLEo->remove_at(variablename);
    }
    variable->deletedP_setter(TRUE);
    variable->free();
  }
}

Surrogate* define_stella_type_from_parse_tree(Cons* tree) {
  { Object* renamed_Typename = tree->second();
    Standard_Object* typedefinition = tree->third()->yield_type_specifier();
    Surrogate* type = NULL;

    { Object* typename_001 = renamed_Typename;

      if (symbolP(renamed_Typename)) {
        { Symbol* renamed_Typename = NULL;

          renamed_Typename = ((Symbol*)(typename_001));
          type = typify(renamed_Typename);
          if ((!defined_typeP(type)) &&
              (type->surrogate_value != NULL)) {
            { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Cannot define type " << "`" << de_uglify_parse_tree(renamed_Typename) << "'" << ", since " << "`" << de_uglify_parse_tree(type) << "'" << endl << "   already points to " << "`" << type->surrogate_value << "'" << "." << endl;
                    }
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
          type->surrogate_value = typedefinition;
          return (type);
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
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Illegal type name: " << "`" << de_uglify_parse_tree(renamed_Typename) << "'" << "." << endl;
                }
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
        return (NULL);
      }
    }
  }
}

void define_stella_type_from_stringified_source(char* stringifiedsource) {
  { Object* parsetree = NULL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            parsetree = unstringify(stringifiedsource);
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
    define_stella_type_from_parse_tree(((Cons*)(parsetree)));
    parsetree->free_parse_tree();
  }
}

void startup_methods() {
  { Module* old_OmoduleO_001 = oMODULEo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = oSTELLA_MODULEo;
          oCONTEXTo = oMODULEo;
          if (current_startup_time_phaseP(2)) {
            SGT_METHODS_SURROGATE = ((Surrogate*)(intern_rigid_symbol_wrt_module("SURROGATE", NULL, 1)));
            SGT_METHODS_PARAMETRIC_TYPE_SPECIFIER = ((Surrogate*)(intern_rigid_symbol_wrt_module("PARAMETRIC-TYPE-SPECIFIER", NULL, 1)));
            SGT_METHODS_ANCHORED_TYPE_SPECIFIER = ((Surrogate*)(intern_rigid_symbol_wrt_module("ANCHORED-TYPE-SPECIFIER", NULL, 1)));
            SGT_METHODS_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("OBJECT", NULL, 1)));
            SGT_METHODS_VOID = ((Surrogate*)(intern_rigid_symbol_wrt_module("VOID", NULL, 1)));
            SYM_METHODS_LIKE = ((Symbol*)(intern_rigid_symbol_wrt_module("LIKE", NULL, 0)));
            SYM_METHODS_SIZE = ((Symbol*)(intern_rigid_symbol_wrt_module("SIZE", NULL, 0)));
            SYM_METHODS_OF = ((Symbol*)(intern_rigid_symbol_wrt_module("OF", NULL, 0)));
            SYM_METHODS_SELF = ((Symbol*)(intern_rigid_symbol_wrt_module("SELF", NULL, 0)));
            SYM_METHODS_IN = ((Symbol*)(intern_rigid_symbol_wrt_module("IN", NULL, 0)));
            SYM_METHODS_OUT = ((Symbol*)(intern_rigid_symbol_wrt_module("OUT", NULL, 0)));
            SYM_METHODS_INOUT = ((Symbol*)(intern_rigid_symbol_wrt_module("INOUT", NULL, 0)));
            SYM_METHODS_METHOD_PARAMETER_DIRECTIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-PARAMETER-DIRECTIONS", NULL, 0)));
            SYM_METHODS_ARGUMENT_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("ARGUMENT-LIST", NULL, 0)));
            SYM_METHODS_aREST = ((Symbol*)(intern_rigid_symbol_wrt_module("&REST", NULL, 0)));
            SYM_METHODS_METHOD_VARIABLE_ARGUMENTSp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-VARIABLE-ARGUMENTS?", NULL, 0)));
            SYM_METHODS_aBODY = ((Symbol*)(intern_rigid_symbol_wrt_module("&BODY", NULL, 0)));
            SYM_METHODS_METHOD_BODY_ARGUMENTp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-BODY-ARGUMENT?", NULL, 0)));
            SGT_METHODS_UNKNOWN = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNKNOWN", NULL, 1)));
            KWD_METHODS_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("TYPE", NULL, 2)));
            KWD_METHODS_RETURN_TYPES = ((Keyword*)(intern_rigid_symbol_wrt_module("RETURN-TYPES", NULL, 2)));
            SYM_METHODS_SLOT_TYPE_SPECIFIER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-TYPE-SPECIFIER", NULL, 0)));
            KWD_METHODS_PUBLICp = ((Keyword*)(intern_rigid_symbol_wrt_module("PUBLIC?", NULL, 2)));
            KWD_METHODS_NATIVEp = ((Keyword*)(intern_rigid_symbol_wrt_module("NATIVE?", NULL, 2)));
            SYM_METHODS_METHOD_NATIVEp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-NATIVE?", NULL, 0)));
            KWD_METHODS_GLOBALLY_INLINEp = ((Keyword*)(intern_rigid_symbol_wrt_module("GLOBALLY-INLINE?", NULL, 2)));
            SYM_METHODS_METHOD_GLOBALLY_INLINEp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-GLOBALLY-INLINE?", NULL, 0)));
            KWD_METHODS_INLINE = ((Keyword*)(intern_rigid_symbol_wrt_module("INLINE", NULL, 2)));
            SYM_METHODS_METHOD_INLINED_FUNCTIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-INLINED-FUNCTIONS", NULL, 0)));
            KWD_METHODS_AUXILIARYp = ((Keyword*)(intern_rigid_symbol_wrt_module("AUXILIARY?", NULL, 2)));
            SYM_METHODS_SLOT_AUXILIARYp = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-AUXILIARY?", NULL, 0)));
            KWD_METHODS_DOCUMENTATION = ((Keyword*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 2)));
            SYM_METHODS_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 0)));
            KWD_METHODS_RETURNS = ((Keyword*)(intern_rigid_symbol_wrt_module("RETURNS", NULL, 2)));
            KWD_METHODS_STORAGE_SLOT = ((Keyword*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT", NULL, 2)));
            SYM_METHODS_STORAGE_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT", NULL, 0)));
            KWD_METHODS_INHERITS_THROUGH = ((Keyword*)(intern_rigid_symbol_wrt_module("INHERITS-THROUGH", NULL, 2)));
            SYM_METHODS_METHOD_INHERITS_THROUGH = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-INHERITS-THROUGH", NULL, 0)));
            KWD_METHODS_PROPERTIES = ((Keyword*)(intern_rigid_symbol_wrt_module("PROPERTIES", NULL, 2)));
            SYM_METHODS_PROPERTIES = ((Symbol*)(intern_rigid_symbol_wrt_module("PROPERTIES", NULL, 0)));
            KWD_METHODS_META_ATTRIBUTES = ((Keyword*)(intern_rigid_symbol_wrt_module("META-ATTRIBUTES", NULL, 2)));
            SYM_METHODS_META_ATTRIBUTES = ((Symbol*)(intern_rigid_symbol_wrt_module("META-ATTRIBUTES", NULL, 0)));
            KWD_METHODS_COMMANDp = ((Keyword*)(intern_rigid_symbol_wrt_module("COMMAND?", NULL, 2)));
            SYM_METHODS_METHOD_COMMANDp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-COMMAND?", NULL, 0)));
            KWD_METHODS_LISP_MACROp = ((Keyword*)(intern_rigid_symbol_wrt_module("LISP-MACRO?", NULL, 2)));
            SYM_METHODS_METHOD_LISP_MACROp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-LISP-MACRO?", NULL, 0)));
            KWD_METHODS_EVALUATE_ARGUMENTSp = ((Keyword*)(intern_rigid_symbol_wrt_module("EVALUATE-ARGUMENTS?", NULL, 2)));
            SYM_METHODS_METHOD_EVALUATE_ARGUMENTSp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-EVALUATE-ARGUMENTS?", NULL, 0)));
            SYM_METHODS_CONCATENATE = ((Symbol*)(intern_rigid_symbol_wrt_module("CONCATENATE", NULL, 0)));
            SYM_METHODS_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", NULL, 0)));
            SYM_METHODS_DEFINE_METHOD_FROM_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINE-METHOD-FROM-STRINGIFIED-SOURCE", NULL, 0)));
            SGT_METHODS_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", NULL, 1)));
            SYM_METHODS_SUPER_CLASSES = ((Symbol*)(intern_rigid_symbol_wrt_module("SUPER-CLASSES", NULL, 0)));
            SYM_METHODS_EQUIVALENT_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("EQUIVALENT-SLOT", NULL, 0)));
            SYM_METHODS_CLASS_ALL_SUPER_CLASSES = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-ALL-SUPER-CLASSES", NULL, 0)));
            SYM_METHODS_SLOT_DIRECT_EQUIVALENT = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-DIRECT-EQUIVALENT", NULL, 0)));
            SYM_METHODS_LET = ((Symbol*)(intern_rigid_symbol_wrt_module("LET", NULL, 0)));
            SYM_METHODS_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CURSOR", NULL, 0)));
            SYM_METHODS_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE", NULL, 0)));
            SYM_METHODS_SLOT_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-VALUE", NULL, 0)));
            SYM_METHODS_LOOP = ((Symbol*)(intern_rigid_symbol_wrt_module("LOOP", NULL, 0)));
            SYM_METHODS_WHEN = ((Symbol*)(intern_rigid_symbol_wrt_module("WHEN", NULL, 0)));
            SYM_METHODS_RETURN = ((Symbol*)(intern_rigid_symbol_wrt_module("RETURN", NULL, 0)));
            SYM_METHODS_SETQ = ((Symbol*)(intern_rigid_symbol_wrt_module("SETQ", NULL, 0)));
            SYM_METHODS_IF = ((Symbol*)(intern_rigid_symbol_wrt_module("IF", NULL, 0)));
            SYM_METHODS_DEFINEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINED?", NULL, 0)));
            SGT_METHODS_COLLECTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION", NULL, 1)));
            SGT_METHODS_CONS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONS", NULL, 1)));
            SYM_METHODS_FIRST = ((Symbol*)(intern_rigid_symbol_wrt_module("FIRST", NULL, 0)));
            SYM_METHODS_VARIABLE_TYPE_SPECIFIER = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-TYPE-SPECIFIER", NULL, 0)));
            SYM_METHODS_DEFSPECIAL = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFSPECIAL", NULL, 0)));
            SYM_METHODS_DEFCONSTANT = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFCONSTANT", NULL, 0)));
            KWD_METHODS_UNBOUND_SPECIAL_VARIABLE = ((Keyword*)(intern_rigid_symbol_wrt_module("UNBOUND-SPECIAL-VARIABLE", NULL, 2)));
          }
          if (current_startup_time_phaseP(4)) {
            oFUNCTION_LOOKUP_TABLEo = new_hash_table();
            oGLOBAL_VARIABLE_LOOKUP_TABLEo = new_hash_table();
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("APPLY", "FUNCTION-CODE", "(DEFUN (APPLY OBJECT) ((CODE FUNCTION-CODE) (ARGUMENTS (CONS OF OBJECT))) :DOCUMENTATION \"Apply `code' to `arguments', returning a value of type\nOBJECT.\")");

              method->function_code = ((cpp_function_code)(&apply));
            }
            { Method_Slot* method = define_method_from_stringified_source("MAKE-PARAMETRIC-TYPE-SPECIFIER", NULL, "(DEFUN (MAKE-PARAMETRIC-TYPE-SPECIFIER PARAMETRIC-TYPE-SPECIFIER) () :DOCUMENTATION \"Return a transient or permanent instance of\n'PARAMETRIC-TYPE-SPECIFIER'.\")");

              method->function_code = ((cpp_function_code)(&make_parametric_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-TRANSIENT-TYPE-SPECIFIER?", "TRANSIENT-TYPE-SPECIFIER", "(DEFUN (TERMINATE-TRANSIENT-TYPE-SPECIFIER? BOOLEAN) ((SELF TRANSIENT-TYPE-SPECIFIER)))");

              method->function_code = ((cpp_function_code)(&terminate_transient_type_specifierP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINED-TYPE?", "TYPE", "(DEFUN (DEFINED-TYPE? BOOLEAN) ((TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&defined_typeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("REAL-TYPE-SPECIFIER", "TYPE", "(DEFUN (REAL-TYPE-SPECIFIER TYPE-SPEC) ((TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&real_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("CANONICAL-TYPE", "TYPE", "(DEFUN (CANONICAL-TYPE TYPE) ((TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&canonical_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-TYPE-SPECIFIER", "SURROGATE", "(DEFMETHOD (YIELD-TYPE-SPECIFIER TYPE-SPEC) ((TYPESPECTREE TYPE)))");

              method->method_code = ((cpp_method_code)(&Surrogate::yield_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-TYPE-SPECIFIER", "SYMBOL", "(DEFMETHOD (YIELD-TYPE-SPECIFIER TYPE-SPEC) ((TYPESPECTREE SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Symbol::yield_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-TYPE-SPECIFIER", "PARAMETRIC-TYPE-SPECIFIER", "(DEFMETHOD (YIELD-TYPE-SPECIFIER TYPE-SPEC) ((TYPESPECTREE PARAMETRIC-TYPE-SPECIFIER)))");

              method->method_code = ((cpp_method_code)(&Parametric_Type_Specifier::yield_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-TYPE-SPECIFIER", "ANCHORED-TYPE-SPECIFIER", "(DEFMETHOD (YIELD-TYPE-SPECIFIER TYPE-SPEC) ((TYPESPECTREE ANCHORED-TYPE-SPECIFIER)))");

              method->method_code = ((cpp_method_code)(&Anchored_Type_Specifier::yield_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-TYPE-SPECIFIER", "OBJECT", "(DEFMETHOD (YIELD-TYPE-SPECIFIER TYPE-SPEC) ((TYPESPECTREE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Object::yield_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-TYPE-SPECIFIER", "CONS", "(DEFMETHOD (YIELD-TYPE-SPECIFIER TYPE-SPEC) ((TYPESPECTREE CONS)))");

              method->method_code = ((cpp_method_code)(&Cons::yield_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-PARAMETRIC-TYPE-SPECIFIER", "CONS", "(DEFUN (YIELD-PARAMETRIC-TYPE-SPECIFIER PARAMETRIC-TYPE-SPECIFIER) ((TYPESPECTREE CONS)))");

              method->function_code = ((cpp_function_code)(&yield_parametric_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-ANCHORED-TYPE-SPECIFIER", "CONS", "(DEFUN (YIELD-ANCHORED-TYPE-SPECIFIER ANCHORED-TYPE-SPECIFIER) ((TYPESPECTREE CONS)))");

              method->function_code = ((cpp_function_code)(&yield_anchored_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("INCORPORATE-INPUT-PARAMETERS", "METHOD-SLOT", "(DEFUN INCORPORATE-INPUT-PARAMETERS ((METHOD METHOD-SLOT) (PARAMETERS CONS)))");

              method->function_code = ((cpp_function_code)(&incorporate_input_parameters));
            }
            { Method_Slot* method = define_method_from_stringified_source("INCORPORATE-FIRST-INPUT-PARAMETER", "METHOD-SLOT", "(DEFUN INCORPORATE-FIRST-INPUT-PARAMETER ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&incorporate_first_input_parameter));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-STELLA-METHOD-SLOT", "SYMBOL", "(DEFUN (DEFINE-STELLA-METHOD-SLOT METHOD-SLOT) ((INPUTNAME SYMBOL) (RETURNTYPES CONS) (FUNCTION? BOOLEAN) (INPUTPARAMETERS CONS) (OPTIONS KEYWORD-KEY-VALUE-LIST) (METHODBODY CONS)) :DOCUMENTATION \"Define a new Stella method object (a slot), and attach it\nto the class identified by the first parameter in 'inputParameters'.\nStorage note: Copies 'options', but attaches to 'inputParameters' and\n'methodBody'.\")");

              method->function_code = ((cpp_function_code)(&define_stella_method_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("ATTACH-METHOD-SLOT-TO-OWNER", "METHOD-SLOT", "(DEFUN (ATTACH-METHOD-SLOT-TO-OWNER METHOD-SLOT) ((NEWMETHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&attach_method_slot_to_owner));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-STRING-CONSTANT-TREE", "STRING", "(DEFUN (YIELD-STRING-CONSTANT-TREE OBJECT) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&yield_string_constant_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-DEFINE-STELLA-METHOD", "METHOD-SLOT", "(DEFUN (YIELD-DEFINE-STELLA-METHOD CONS) ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_define_stella_method));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CLASS-PARAMETER-TYPES", "CLASS", "(DEFUN (YIELD-CLASS-PARAMETER-TYPES (CONS OF TYPE)) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_class_parameter_types));
            }
            { Method_Slot* method = define_method_from_stringified_source("OPTIMISTIC-SUBTYPE-OF?", "TYPE", "(DEFUN (OPTIMISTIC-SUBTYPE-OF? BOOLEAN) ((SUBTYPE TYPE) (SUPERTYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&optimistic_subtype_ofP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WARN-OF-PARAMETER-MISMATCH", "PARAMETRIC-TYPE-SPECIFIER", "(DEFUN WARN-OF-PARAMETER-MISMATCH ((SELF PARAMETRIC-TYPE-SPECIFIER) (MESSAGE STRING)))");

              method->function_code = ((cpp_function_code)(&warn_of_parameter_mismatch));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALIDATE-TYPE-SPECIFIER", "TYPE-SPEC", "(DEFUN (VALIDATE-TYPE-SPECIFIER TYPE) ((SELF TYPE-SPEC) (ANCHORCLASS CLASS) (SKIPANCHOREDTYPE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&validate_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYNTHESIZE-METHOD-BODY", "METHOD-SLOT", "(DEFUN (SYNTHESIZE-METHOD-BODY CONS) ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&synthesize_method_body));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-SLOT-TYPE-COMPUTATIONS", "METHOD-SLOT", "(DEFMETHOD FINALIZE-SLOT-TYPE-COMPUTATIONS ((SELF METHOD-SLOT)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::finalize_slot_type_computations));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-FINALIZE-LOCAL-SLOT", "METHOD-SLOT", "(DEFMETHOD HELP-FINALIZE-LOCAL-SLOT ((SELF METHOD-SLOT)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::help_finalize_local_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNFINALIZE-LOCAL-SLOT", "METHOD-SLOT", "(DEFMETHOD UNFINALIZE-LOCAL-SLOT ((SELF METHOD-SLOT)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::unfinalize_local_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("METHOD-ARGUMENT-COUNT", "SLOT", "(DEFMETHOD (METHOD-ARGUMENT-COUNT INTEGER) ((SELF SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::method_argument_count));
            }
            { Method_Slot* method = define_method_from_stringified_source("METHOD-ARGUMENT-COUNT", "STORAGE-SLOT", "(DEFMETHOD (METHOD-ARGUMENT-COUNT INTEGER) ((SELF STORAGE-SLOT)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::method_argument_count));
            }
            { Method_Slot* method = define_method_from_stringified_source("METHOD-ARGUMENT-COUNT", "METHOD-SLOT", "(DEFMETHOD (METHOD-ARGUMENT-COUNT INTEGER) ((SELF METHOD-SLOT)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::method_argument_count));
            }
            { Method_Slot* method = define_method_from_stringified_source("METHOD-ARGUMENT-COUNT", "TABLE", "(DEFMETHOD (METHOD-ARGUMENT-COUNT INTEGER) ((SELF TABLE)))");

              method->method_code = ((cpp_method_code)(&Table::method_argument_count));
            }
            { Method_Slot* method = define_method_from_stringified_source("METHOD-VARIABLE-ARGUMENTS?", "STORAGE-SLOT", "(DEFMETHOD (METHOD-VARIABLE-ARGUMENTS? BOOLEAN) ((SELF STORAGE-SLOT)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::method_variable_argumentsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("METHOD-BODY-ARGUMENT?", "STORAGE-SLOT", "(DEFMETHOD (METHOD-BODY-ARGUMENT? BOOLEAN) ((SELF STORAGE-SLOT)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::method_body_argumentP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ARITY", "STORAGE-SLOT", "(DEFMETHOD (ARITY INTEGER) ((SELF STORAGE-SLOT)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::arity));
            }
            { Method_Slot* method = define_method_from_stringified_source("ARITY", "METHOD-SLOT", "(DEFMETHOD (ARITY INTEGER) ((SELF METHOD-SLOT)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::arity));
            }
            { Method_Slot* method = define_method_from_stringified_source("ARITY", "TABLE", "(DEFMETHOD (ARITY INTEGER) ((SELF TABLE)))");

              method->method_code = ((cpp_method_code)(&Table::arity));
            }
            { Method_Slot* method = define_method_from_stringified_source("TYPE-SPEC-TO-BASE-TYPE", "TYPE-SPEC", "(DEFUN (TYPE-SPEC-TO-BASE-TYPE TYPE) ((SELF TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&type_spec_to_base_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("TYPE-SPEC-TO-CLASS", "TYPE-SPEC", "(DEFUN (TYPE-SPEC-TO-CLASS CLASS) ((SELF TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&type_spec_to_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPATIBLE-PARAMETER-TYPES?", "TYPE-SPEC", "(DEFUN (COMPATIBLE-PARAMETER-TYPES? BOOLEAN) ((SUBTYPE TYPE-SPEC) (SUPERTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&compatible_parameter_typesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUB-TYPE-SPEC-OF?", "TYPE-SPEC", "(DEFUN (SUB-TYPE-SPEC-OF? BOOLEAN) ((SUBTYPE TYPE-SPEC) (SUPERTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&sub_type_spec_ofP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VOID?", "TYPE-SPEC", "(DEFUN (VOID? BOOLEAN) ((TYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&voidP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-PARAMETER-TYPE", "TYPE-SPEC", "(DEFUN (EXTRACT-PARAMETER-TYPE TYPE-SPEC BOOLEAN) ((SELF TYPE-SPEC) (PARAMETER SYMBOL)))");

              method->function_code = ((cpp_function_code)(&extract_parameter_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-ANCHORED-TYPE-SPEC", "TYPE-SPEC", "(DEFUN (COMPUTE-ANCHORED-TYPE-SPEC TYPE-SPEC) ((OWNERTYPE TYPE-SPEC) (RELTYPE ANCHORED-TYPE-SPECIFIER)))");

              method->function_code = ((cpp_function_code)(&compute_anchored_type_spec));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-RELATIVE-TYPE-SPEC", "TYPE-SPEC", "(DEFUN (COMPUTE-RELATIVE-TYPE-SPEC TYPE-SPEC) ((RELATIVETYPE TYPE-SPEC) (OWNERTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&compute_relative_type_spec));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-RETURN-TYPE-SPEC", "SLOT", "(DEFMETHOD (COMPUTE-RETURN-TYPE-SPEC TYPE-SPEC) ((SELF SLOT) (FIRSTARGTYPE TYPE-SPEC)))");

              method->method_code = ((cpp_method_code)(&Slot::compute_return_type_spec));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-RETURN-TYPE-SPEC", "METHOD-SLOT", "(DEFMETHOD (COMPUTE-RETURN-TYPE-SPEC TYPE-SPEC) ((SELF METHOD-SLOT) (FIRSTARGTYPE TYPE-SPEC)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::compute_return_type_spec));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-RETURN-TYPE-SPEC", "STORAGE-SLOT", "(DEFMETHOD (COMPUTE-RETURN-TYPE-SPEC TYPE-SPEC) ((SELF STORAGE-SLOT) (FIRSTARGTYPE TYPE-SPEC)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::compute_return_type_spec));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-TYPE-SPEC-TREE", "TYPE-SPEC", "(DEFUN (YIELD-TYPE-SPEC-TREE OBJECT) ((SELF TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&yield_type_spec_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("ATTACH-FUNCTION", "METHOD-SLOT", "(DEFUN (ATTACH-FUNCTION METHOD-SLOT) ((NEWFUNCTION METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&attach_function));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-FUNCTION", "STRING", "(DEFMETHOD (LOOKUP-FUNCTION FUNCTION) ((NAME STRING)) :DOCUMENTATION \"Return a function with name 'name'.  Scan all\nvisible symbols looking for one that has a function defined for it.\")");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-FUNCTION", "SYMBOL", "(DEFMETHOD (LOOKUP-FUNCTION FUNCTION) ((FUNCTIONSYMBOL SYMBOL)) :DOCUMENTATION \"Return the function defined for 'functionSymbol', if\none exists.\")");

              method->method_code = ((cpp_method_code)(&Symbol::lookup_function));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-FUNCTION-OR-STELLA-FUNCTION", "SYMBOL", "(DEFUN (LOOKUP-FUNCTION-OR-STELLA-FUNCTION FUNCTION) ((FUNCTIONSYMBOL SYMBOL)))");

              method->function_code = ((cpp_function_code)(&lookup_function_or_stella_function));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-FUNCTION", "METHOD-SLOT", "(DEFUN DESTROY-FUNCTION ((FUNCTION METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&destroy_function));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-GLOBAL-VARIABLE", "GLOBAL-VARIABLE", "(DEFUN (INTERN-GLOBAL-VARIABLE GLOBAL-VARIABLE) ((GLOBAL GLOBAL-VARIABLE)))");

              method->function_code = ((cpp_function_code)(&intern_global_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-GLOBAL-VARIABLE", "GENERALIZED-SYMBOL", "(DEFMETHOD (LOOKUP-GLOBAL-VARIABLE GLOBAL-VARIABLE) ((SELF GENERALIZED-SYMBOL)) :DOCUMENTATION \"Return a global variable with name 'self'.\")");

              method->method_code = ((cpp_method_code)(&Generalized_Symbol::lookup_global_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-GLOBAL-VARIABLE", "SURROGATE", "(DEFMETHOD (LOOKUP-GLOBAL-VARIABLE GLOBAL-VARIABLE) ((SELF SURROGATE)) :DOCUMENTATION \"Return a global variable with name 'self'.\")");

              method->method_code = ((cpp_method_code)(&Surrogate::lookup_global_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-GLOBAL-VARIABLE", "STRING", "(DEFMETHOD (LOOKUP-GLOBAL-VARIABLE GLOBAL-VARIABLE) ((SELF STRING)) :DOCUMENTATION \"Return a global variable with name 'self'.\")");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-GLOBAL-VARIABLE-TYPE", "SYMBOL", "(DEFUN (LOOKUP-GLOBAL-VARIABLE-TYPE TYPE-SPEC) ((NAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&lookup_global_variable_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-STELLA-GLOBAL-VARIABLE-FROM-PARSE-TREE", "CONS", "(DEFUN (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-PARSE-TREE GLOBAL-VARIABLE OBJECT) ((TREE CONS) (STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&define_stella_global_variable_from_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE", "STRING", "(DEFUN DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE ((STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&define_stella_global_variable_from_stringified_source));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-GLOBAL-VALUE", "SURROGATE", "(DEFUN (GET-GLOBAL-VALUE OBJECT) ((SELF SURROGATE)) :DOCUMENTATION \"Return the (possibly-wrapped) value of the global\nvariable for the surrogate 'self'.\")");

              method->function_code = ((cpp_function_code)(&get_global_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("SET-GLOBAL-VALUE", "SURROGATE", "(DEFUN (SET-GLOBAL-VALUE OBJECT) ((SELF SURROGATE) (VALUE OBJECT)) :DOCUMENTATION \"Set the value of the global variable for the surrogate\n'self' to 'value'.\")");

              method->function_code = ((cpp_function_code)(&set_global_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-VARIABLE", "GLOBAL-VARIABLE", "(DEFUN DESTROY-VARIABLE ((VARIABLE GLOBAL-VARIABLE)))");

              method->function_code = ((cpp_function_code)(&destroy_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-STELLA-TYPE-FROM-PARSE-TREE", "CONS", "(DEFUN (DEFINE-STELLA-TYPE-FROM-PARSE-TREE TYPE) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&define_stella_type_from_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-STELLA-TYPE-FROM-STRINGIFIED-SOURCE", "STRING", "(DEFUN DEFINE-STELLA-TYPE-FROM-STRINGIFIED-SOURCE ((STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&define_stella_type_from_stringified_source));
            }
            define_method_from_stringified_source("STARTUP-METHODS", NULL, "(DEFUN STARTUP-METHODS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *MAXIMUM-STRING-CONSTANT-SIZE* INTEGER 4000 :DOCUMENTATION \"Maximum size for a string constant in the target language.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *FUNCTION-LOOKUP-TABLE* (HASH-TABLE OF SYMBOL FUNCTION) (NEW (HASH-TABLE OF SYMBOL FUNCTION)) :DOCUMENTATION \"Lookup table for functions.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *GLOBAL-VARIABLE-LOOKUP-TABLE* (HASH-TABLE OF SYMBOL GLOBAL-VARIABLE) (NEW (HASH-TABLE OF SYMBOL GLOBAL-VARIABLE)) :DOCUMENTATION \"Lookup table for global variables.\")");
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

