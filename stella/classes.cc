// classes.cc

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

Surrogate* SGT_CLASSES_CLASS = NULL;

boolean oWARN_IF_REDEFINEpo = TRUE;

Symbol* SYM_CLASSES_TRUE = NULL;

Symbol* SYM_CLASSES_FALSE = NULL;

Keyword* KWD_CLASSES_PARAMETERS = NULL;

Symbol* SYM_CLASSES_SLOT_TYPE_SPECIFIER = NULL;

Keyword* KWD_CLASSES_PUBLICp = NULL;

Keyword* KWD_CLASSES_REQUIREDp = NULL;

Keyword* KWD_CLASSES_COMPONENTp = NULL;

Keyword* KWD_CLASSES_READ_ONLYp = NULL;

Keyword* KWD_CLASSES_ACTIVEp = NULL;

Symbol* SYM_CLASSES_STORED_ACTIVEp = NULL;

Keyword* KWD_CLASSES_CONTEXT_SENSITIVEp = NULL;

Keyword* KWD_CLASSES_HARDWIREDp = NULL;

Keyword* KWD_CLASSES_ABSTRACTp = NULL;

Keyword* KWD_CLASSES_ALLOCATION = NULL;

Keyword* KWD_CLASSES_CLASS = NULL;

Symbol* SYM_CLASSES_SLOT_ALLOCATION = NULL;

Keyword* KWD_CLASSES_INITIALLY = NULL;

Symbol* SYM_CLASSES_SLOT_INITIAL_VALUE = NULL;

Keyword* KWD_CLASSES_DEFAULT = NULL;

Symbol* SYM_CLASSES_SLOT_DEFAULT_EXPRESSION = NULL;

Keyword* KWD_CLASSES_READER = NULL;

Symbol* SYM_CLASSES_SLOT_READER = NULL;

Keyword* KWD_CLASSES_WRITER = NULL;

Symbol* SYM_CLASSES_SLOT_WRITER = NULL;

Keyword* KWD_CLASSES_INVERSE = NULL;

Symbol* SYM_CLASSES_SLOT_INVERSE = NULL;

Keyword* KWD_CLASSES_RENAMES = NULL;

Symbol* SYM_CLASSES_SLOT_RENAMES = NULL;

Keyword* KWD_CLASSES_DOCUMENTATION = NULL;

Symbol* SYM_CLASSES_DOCUMENTATION = NULL;

Keyword* KWD_CLASSES_PROPERTIES = NULL;

Symbol* SYM_CLASSES_PROPERTIES = NULL;

Keyword* KWD_CLASSES_META_ATTRIBUTES = NULL;

Symbol* SYM_CLASSES_META_ATTRIBUTES = NULL;

Keyword* KWD_CLASSES_OPTION_KEYWORD = NULL;

Symbol* SYM_CLASSES_SLOT_OPTION_KEYWORD = NULL;

Keyword* KWD_CLASSES_OPTION_HANDLER = NULL;

Symbol* SYM_CLASSES_SLOT_OPTION_HANDLER = NULL;

Surrogate* SGT_CLASSES_BOOLEAN = NULL;

Keyword* KWD_CLASSES_BIT = NULL;

Keyword* KWD_CLASSES_CL_NATIVE_TYPE = NULL;

Symbol* SYM_CLASSES_CLASS_CL_NATIVE_TYPE = NULL;

Keyword* KWD_CLASSES_CPP_NATIVE_TYPE = NULL;

Symbol* SYM_CLASSES_CLASS_CPP_NATIVE_TYPE = NULL;

Keyword* KWD_CLASSES_IDL_NATIVE_TYPE = NULL;

Symbol* SYM_CLASSES_CLASS_IDL_NATIVE_TYPE = NULL;

Keyword* KWD_CLASSES_JAVA_NATIVE_TYPE = NULL;

Symbol* SYM_CLASSES_CLASS_JAVA_NATIVE_TYPE = NULL;

Keyword* KWD_CLASSES_CL_STRUCTp = NULL;

Keyword* KWD_CLASSES_MIXINp = NULL;

Keyword* KWD_CLASSES_RECYCLE_METHOD = NULL;

Symbol* SYM_CLASSES_CLASS_RECYCLE_METHOD = NULL;

Keyword* KWD_CLASSES_EXTENSION = NULL;

Symbol* SYM_CLASSES_CLASS_EXTENSION_NAME = NULL;

Keyword* KWD_CLASSES_CREATOR = NULL;

Symbol* SYM_CLASSES_CLASS_CREATOR = NULL;

Keyword* KWD_CLASSES_INITIALIZER = NULL;

Symbol* SYM_CLASSES_CLASS_INITIALIZER = NULL;

Keyword* KWD_CLASSES_TERMINATOR = NULL;

Symbol* SYM_CLASSES_CLASS_TERMINATOR = NULL;

Keyword* KWD_CLASSES_DESTRUCTOR = NULL;

Symbol* SYM_CLASSES_CLASS_DESTRUCTOR = NULL;

Keyword* KWD_CLASSES_INITIAL_VALUE = NULL;

Symbol* SYM_CLASSES_CLASS_INITIAL_VALUE = NULL;

Keyword* KWD_CLASSES_PRINT_FORM = NULL;

Symbol* SYM_CLASSES_PRINT_FORM = NULL;

Keyword* KWD_CLASSES_EQUALITY_TEST = NULL;

Keyword* KWD_CLASSES_KEY = NULL;

Symbol* SYM_CLASSES_CLASS_KEY = NULL;

Symbol* SYM_CLASSES_CLASS_PARAMETERS = NULL;

Keyword* KWD_CLASSES_SYNONYMS = NULL;

Symbol* SYM_CLASSES_CLASS_SYNONYMS = NULL;

Keyword* KWD_CLASSES_CHILDREN = NULL;

Surrogate* SGT_CLASSES_METHOD_SLOT = NULL;

Symbol* SYM_CLASSES_SLOT_GUARD_DEMONS = NULL;

Symbol* SYM_CLASSES_SLOT_DEMONS = NULL;

Symbol* SYM_CLASSES_CLASS_CONSTRUCTOR_DEMONS = NULL;

Symbol* SYM_CLASSES_CLASS_GUARD_CONSTRUCTOR_DEMONS = NULL;

Symbol* SYM_CLASSES_CLASS_DESTRUCTOR_DEMONS = NULL;

Symbol* SYM_CLASSES_CLASS_GUARD_DESTRUCTOR_DEMONS = NULL;

List* oUNFINALIZED_CLASSESo = NULL;

boolean oNEWLY_UNFINALIZED_CLASSESpo = FALSE;

List* oCLASSES_WITH_UNRESOLVED_CHILDREN_REFERENCESo = NULL;

Surrogate* SGT_CLASSES_ACTIVE_OBJECT = NULL;

Surrogate* SGT_CLASSES_OBJECT = NULL;

Surrogate* SGT_CLASSES_STANDARD_OBJECT = NULL;

Symbol* SYM_CLASSES_PRIMARY_TYPE = NULL;

Symbol* SYM_CLASSES_SELF = NULL;

Keyword* KWD_CLASSES_TYPE = NULL;

Symbol* SYM_CLASSES_TYPE = NULL;

Keyword* KWD_CLASSES_AUXILIARYp = NULL;

Symbol* SYM_CLASSES_RETURN = NULL;

Symbol* SYM_CLASSES_CLASS_EXTENSION = NULL;

Surrogate* SGT_CLASSES_SET = NULL;

Surrogate* SGT_CLASSES_ACTIVE_SET = NULL;

Surrogate* SGT_CLASSES_LIST = NULL;

Surrogate* SGT_CLASSES_ACTIVE_LIST = NULL;

Surrogate* SGT_CLASSES_UNKNOWN = NULL;

Surrogate* SGT_CLASSES_COLLECTION = NULL;

Surrogate* SGT_CLASSES_SET_MIXIN = NULL;

Symbol* SYM_CLASSES_INVERSE = NULL;

Surrogate* SGT_CLASSES_DYNAMIC_SLOTS_MIXIN = NULL;

Keyword* KWD_CLASSES_INSTANCE = NULL;

Surrogate* SGT_CLASSES_CONTEXT_SENSITIVE_OBJECT = NULL;

Surrogate* SGT_CLASSES_VOID = NULL;

int oSYMBOL_SLOT_OFFSET_COUNTERo = 0;

int oSLOT_CACHE_SIZEo = 20;

Keyword* KWD_CLASSES_DYNAMIC = NULL;

Surrogate* SGT_CLASSES_TABLE = NULL;

Symbol* SYM_CLASSES_CLASS_REQUIRED_SLOT_NAMES = NULL;

Surrogate* SGT_CLASSES_GENERALIZED_SYMBOL = NULL;

Symbol* SYM_CLASSES_EVALUATOR_WRAPPER_CODE = NULL;

Taxonomy_Graph* oCLASS_TAXONOMY_GRAPHo = NULL;

Symbol* SYM_CLASSES_ANY = NULL;

Surrogate* SGT_CLASSES_ANY = NULL;

char* class_name(Class* renamed_Class) {
  return (renamed_Class->class_type->symbol_name);
}

Symbol* class_symbol(Class* renamed_Class) {
  return (type_to_symbol(renamed_Class->class_type));
}

Symbol* type_to_symbol(Surrogate* type) {
  return (intern_derived_symbol(type, type->symbol_name));
}

Class* Object::primary_class() {
  { Object* self = this;

    if (self->primary_type() != NULL) {
      return (((Class*)(self->primary_type()->surrogate_value)));
    }
    return (NULL);
  }
}

Class* string_lookup_class(char* name) {
  // Return a class with name 'name'.  Scan all
  // visible surrogates looking for one that has a class defined for it.
  { Class* renamed_Class = NULL;
    Surrogate* surrogate = NULL;

    { Module* module = NULL;
      Iterator* iter_001 = visible_modules(oMODULEo);

      while (iter_001->nextP()) {
        {
          module = ((Module*)(iter_001->value));
        }
        { boolean test_value_001 = FALSE;

          { 
            surrogate = ((Surrogate*)(lookup_rigid_symbol_locally(name, module, SURROGATE_SYM)));
            test_value_001 = surrogate != NULL;
          }
          if (test_value_001) {
            { 
              renamed_Class = ((Class*)(surrogate->surrogate_value));
              test_value_001 = renamed_Class != NULL;
            }
            if (test_value_001) {
              test_value_001 = isaP(renamed_Class, SGT_CLASSES_CLASS);
            }
          }
          if (test_value_001) {
            return (renamed_Class);
          }
        }
      }
    }
    return (NULL);
  }
}

Class* Symbol::lookup_class() {
  // Return a class with name 'name'.  Scan all
  // visible surrogates looking for one that has a class defined for it.
  { Symbol* name = this;

    { Module* old_OmoduleO_001 = oMODULEo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oMODULEo = ((Module*)(name->home_context));
            { Class* return_value_001 = string_lookup_class(name->symbol_name);

              oMODULEo = old_OmoduleO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (return_value_001);
            }
            oMODULEo = old_OmoduleO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oMODULEo = old_OmoduleO_001;
          resignal();
        }
      }
    }
  }
}

Class* type_to_class(Surrogate* type) {
  return (((Class*)(type->surrogate_value)));
}

Class* Surrogate::get_class(boolean errorP) {
  // Return a class with name 'className'.  If none exists, break
  // if 'error?', else return NULL.
  { Surrogate* classname = this;

    { Object* renamed_Class = classname->surrogate_value;

      if ((renamed_Class != NULL) &&
          classP(renamed_Class)) {
        return (((Class*)(renamed_Class)));
      }
      if (errorP) {
        cerr << "Class " << "`" << classname << "'" << " does not exist.";
      }
      else {
        return (NULL);
      }
    }
  }
}

Class* string_get_class(char* classname, boolean errorP) {
  // Return a class with name 'className'.  If none exists, break
  // if 'error?', else return NULL.
  { Surrogate* type = lookup_surrogate(classname);

    if (type != NULL) {
      return (type->get_class(errorP));
    }
    if (errorP) {
      cerr << "Class " << "`" << classname << "'" << " does not exist.";
    }
    else {
      return (NULL);
    }
  }
}

Class* Symbol::get_class(boolean errorP) {
  // Return a class with name 'className'.  If non exists, break
  // if 'error?', else return NULL.
  { Symbol* classname = this;

    return (string_get_class(classname->symbol_name, errorP));
  }
}

boolean bind_to_surrogateP(Object* self, char* name, boolean clipoldvalueP, boolean warnonfailureP, Object*& return1, Surrogate*& return2) {
  { Surrogate* oldsurrogate = lookup_surrogate(name);
    Object* oldvalue = ((oldsurrogate != NULL) ? ((Object*)(oldsurrogate->surrogate_value)) : ((Object*)(NULL)));
    Surrogate* surrogate = shadow_surrogate(name);
    Module* oldmodule = NULL;

    if (oldvalue == NULL) {
      surrogate->surrogate_value = self;
      { boolean return_temp = TRUE;

        return1 = NULL;
        return2 = surrogate;
        return (return_temp);
      }
    }
    if (eqlP(oldvalue, self)) {
      { boolean return_temp = TRUE;

        return1 = NULL;
        return2 = surrogate;
        return (return_temp);
      }
    }
    oldmodule = ((Module*)(oldsurrogate->home_context));
    if (!(oldmodule == oMODULEo)) {
      surrogate->surrogate_value = self;
      if (oWARN_IF_REDEFINEpo) {
        cerr << "Shadowing the " << "`" << self->primary_type()->symbol_name << "'" << " named " << "`" << name << "'";
        cout << "CAUTION: Automatic shadowing can be dangerous, because forward " << endl << "   references to a shadowed object may be bound to the now-shadowed " << endl << "   object.  Suggestion: Explicitly shadow the name using" << endl << "   DEFMODULE's `:shadow' option." << endl;
      }
      { boolean return_temp = TRUE;

        return1 = NULL;
        return2 = surrogate;
        return (return_temp);
      }
    }
    else if (clipoldvalueP) {
      if (oWARN_IF_REDEFINEpo) {
        cout << "Redefining the " << "`" << self->primary_type()->symbol_name << "'" << " named " << "`" << name << "'" << endl;
      }
      surrogate->surrogate_value = self;
      if (!(self->primary_type() == oldvalue->primary_type())) {
        oldvalue = NULL;
      }
      { boolean return_temp = TRUE;

        return1 = oldvalue;
        return2 = surrogate;
        return (return_temp);
      }
    }
    else {
      if (warnonfailureP) {
        cerr << "Can't define the " << "`" << self->primary_type()->symbol_name << "'" << " named " << "`" << name << "'" << " in module " << "`" << oMODULEo << "'" << endl << "   because it is already defined.";
      }
      { boolean return_temp = FALSE;

        return1 = NULL;
        return2 = surrogate;
        return (return_temp);
      }
    }
  }
}

void Class::unbind_from_surrogate() {
  { Class* self = this;

    { Surrogate* surrogate = self->class_type;

      if (surrogate != NULL) {
        surrogate->surrogate_value = NULL;
        self->class_type = NULL;
      }
    }
  }
}

Symbol* shadow_symbol(char* name) {
  return (((Symbol*)(intern_rigid_symbol_locally(name, oMODULEo, SYMBOL_SYM))));
}

Surrogate* shadow_surrogate(char* name) {
  shadow_symbol(name);
  return (((Surrogate*)(intern_rigid_symbol_locally(name, oMODULEo, SURROGATE_SYM))));
}

boolean bind_to_indexicalP(Object* self, char* name, boolean clipoldvalueP, boolean warnonfailureP, Object*& return1) {
  { Indexical* oldindexical = lookup_indexical(name);
    Object* oldvalue = ((oldindexical != NULL) ? ((Object*)(((Object*)(access_in_context(oldindexical->indexical_value, oldindexical, FALSE))))) : ((Object*)(NULL)));
    Indexical* indexical = shadow_indexical(name);
    Module* oldmodule = NULL;

    if (oldvalue == NULL) {
      { Indexical* object_001 = indexical;
        Object* value_001 = self;
        Object* old_value_002 = object_001->indexical_value;
        Object* new_value_001 = update_in_context(old_value_002, value_001, object_001, FALSE);

        if (!cs_valueP(old_value_002)) {
          object_001->indexical_value = new_value_001;
        }
      }
      { boolean return_temp = TRUE;

        return1 = NULL;
        return (return_temp);
      }
    }
    if (eqlP(oldvalue, self)) {
      { boolean return_temp = TRUE;

        return1 = NULL;
        return (return_temp);
      }
    }
    if (!(self->primary_type() == oldvalue->primary_type())) {
      if (warnonfailureP) {
        cerr << "Can't define the " << "`" << self->primary_type()->symbol_name << "'" << " named " << "`" << name << "'" << " in module " << "`" << oMODULEo << "'" << endl << "   because it is already defined as a " << "`" << oldvalue->primary_type()->symbol_name << "'";
      }
      { boolean return_temp = FALSE;

        return1 = oldvalue;
        return (return_temp);
      }
    }
    oldmodule = ((Module*)(((oldindexical == indexical) ? ((Context*)(compute_nearest_context(indexical->indexical_value, indexical, oMODULEo))) : ((Context*)(((Module*)(oldindexical->home_context)))))));
    if (!(oldmodule == oMODULEo)) {
      { Indexical* object_002 = indexical;
        Object* value_002 = self;
        Object* old_value_004 = object_002->indexical_value;
        Object* new_value_002 = update_in_context(old_value_004, value_002, object_002, FALSE);

        if (!cs_valueP(old_value_004)) {
          object_002->indexical_value = new_value_002;
        }
      }
      if (oWARN_IF_REDEFINEpo) {
        cout << "Shadowing the " << "`" << self->primary_type()->symbol_name << "'" << " named " << "`" << name << "'" << endl;
      }
      { boolean return_temp = TRUE;

        return1 = NULL;
        return (return_temp);
      }
    }
    else if (clipoldvalueP) {
      if (oWARN_IF_REDEFINEpo) {
        cout << "Redefining the " << "`" << self->primary_type()->symbol_name << "'" << " named " << "`" << name << "'" << endl;
      }
      { Indexical* object_003 = indexical;
        Object* value_003 = self;
        Object* old_value_005 = object_003->indexical_value;
        Object* new_value_003 = update_in_context(old_value_005, value_003, object_003, FALSE);

        if (!cs_valueP(old_value_005)) {
          object_003->indexical_value = new_value_003;
        }
      }
      { boolean return_temp = TRUE;

        return1 = oldvalue;
        return (return_temp);
      }
    }
    else {
      if (warnonfailureP) {
        cerr << "Can't define the " << "`" << self->primary_type()->symbol_name << "'" << " named " << "`" << name << "'" << " in module " << "`" << oMODULEo << "'" << endl << "   because it is already defined.";
      }
      { boolean return_temp = FALSE;

        return1 = NULL;
        return (return_temp);
      }
    }
  }
}

Indexical* shadow_indexical(char* name) {
  { Indexical* indexical = lookup_indexical(name);

    if ((indexical == NULL) ||
        (!(indexical->home_context == oMODULEo))) {
      { Extensible_Symbol_Array* array = select_symbol_array(INDEXICAL_SYM);
        int offset = next_free_offset(array);

        indexical = ((Indexical*)(help_intern_generalized_symbol(name, INDEXICAL_SYM, array, offset, oMODULEo)));
      }
    }
    { Object* storedvalue = indexical->indexical_value;

      if (!(compute_nearest_context(storedvalue, indexical, oMODULEo) == oMODULEo)) {
        { Indexical* object_001 = indexical;
          Object* value_001 = NULL;
          Object* old_value_002 = object_001->indexical_value;
          Object* new_value_001 = update_in_context(old_value_002, value_001, object_001, FALSE);

          if (!cs_valueP(old_value_002)) {
            object_001->indexical_value = new_value_001;
          }
        }
      }
    }
    return (indexical);
  }
}

cpp_function_code get_constructor(Class* renamed_Class, boolean warnP) {
  { cpp_function_code constructor = renamed_Class->class_constructor_code;

    if (constructor != NULL) {
      return (constructor);
    }
    if (warnP) {
      if (renamed_Class->abstractP) {
        cerr << "The abstract class " << "`" << class_symbol(renamed_Class) << "'" << " cannot have a constructor.";
        return (NULL);
      }
      cerr << "The " << "`" << ((renamed_Class->privateP() ? ((char*)("private ")) : ((char*)("")))) << "'" << "class " << "`" << class_symbol(renamed_Class) << "'" << " does not have a callable constructor.";
    }
    return (NULL);
  }
}

Object* create_object(Surrogate* type, int alternatingsymbolsandvalues, ...) {
  // Flexible, user-friendly version of 'new'.
  // Return an instance of the class named with type 'type'.
  // Fill in values using 'alternatingKeywordsAndValues' and call the
  // initialization function, if one exists. Any arguments required by 'new'
  // for this type must be included.  'create' runs more slowly than 'new'.
  { Class* renamed_Class = type->get_class(TRUE);
    cpp_function_code constructorcode = get_constructor(renamed_Class, TRUE);
    Cons* options = NIL;
    Object* newobject = NULL;
    Cons* cursor = NULL;

    if (!(constructorcode != NULL)) {
      return (NULL);
    }
    if (renamed_Class->class_required_slot_names_reader()->non_emptyP()) {
      cerr << "Can't call 'create' on a class having required slots.";
      return (NULL);
    }
    newobject = ((Object* (*) ())constructorcode)();
    { va_list ap;
      Object* item;
      Cons* collect_001 = NULL;

      va_start(ap, alternatingsymbolsandvalues);
      while (alternatingsymbolsandvalues > 0) {
        item = va_arg(ap, Object*);
        alternatingsymbolsandvalues = alternatingsymbolsandvalues - 1;
        if (collect_001 == NULL) {
          {
            collect_001 = cons(item, NIL);
            if (nilP(options)) {
              options = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(options, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(item, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
      va_end(ap);
    }
    cursor = options;
    while (cursor->non_emptyP()) {
      put_slot_value(((Standard_Object*)(newobject)), ((Storage_Slot*)(cursor->value)), cursor->rest->value);
      cursor = cursor->rest->rest;
    }
    free_cons_list(options);
    return (newobject);
  }
}

void Object::free() {
  // Default method.  Deallocate storage for 'self'.
  { Object* self = this;

    unmake(self);
  }
}

void Active_Object::free() {
  // Remove all pointers between 'self' and other objects,
  // and then deallocate the storage for self.
  { Active_Object* self = this;

    unmake(self);
  }
}

Boolean_Wrapper* symbol_to_wrapped_boolean(Object* object) {
  { Symbol* test_value_001 = ((Symbol*)(object));

    if (test_value_001 == SYM_CLASSES_TRUE) {
      return (TRUE_WRAPPER);
    }
    else if (test_value_001 == SYM_CLASSES_FALSE) {
      return (FALSE_WRAPPER);
    }
    else {
      cerr << "`" << object << "'" << " found where Boolean symbol expected.";
    }
  }
}

Class* define_stella_class(Surrogate* name, List* supers, List* slots, Keyword_Key_Value_List* options) {
  // Return a Stella class with name 'name'.
  // Caution:  If the class already exists, the Stella class object gets
  // redefined, but the native C++ class is not redefined.
  { Class* renamed_Class = new_class();
    List* parameterslots = ((List*)(options->lookup(KWD_CLASSES_PARAMETERS)));
    Class* oldclass = NULL;
    boolean successP = FALSE;

    if ((!(name->home_context == oMODULEo)) &&
        (!visible_fromP(((Module*)(name->home_context)), oMODULEo))) {
      cerr << "Can't define a class named " << "`" << name << "'" << " because the module " << endl << "   " << "`" << name->home_context->context_name() << "'" << " is not visible from the current module " << "`" << oMODULEo->context_name() << "'" << "." << endl;
      return (NULL);
    }
    { boolean value_001 = FALSE;
      Object* value_002 = NULL;
      Surrogate* value_003 = NULL;

      value_001 = bind_to_surrogateP(renamed_Class, name->symbol_name, TRUE, TRUE, value_002, value_003);
      {
        successP = value_001;
        oldclass = ((Class*)(value_002));
        name = value_003;
      }
    }
    if (!successP) {
      return (NULL);
    }
    renamed_Class->class_type = name;
    if (parameterslots != NULL) {
      { Slot* s = NULL;
        Cons* iter_001 = parameterslots->the_cons_list;

        while (!nilP(iter_001)) {
          {
            s = ((Slot*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          s->abstractP = TRUE;
          slots->insert_last(s);
        }
      }
    }
    initialize_slot_and_method_cache(renamed_Class);
    { Surrogate* s = NULL;
      Cons* iter_002 = supers->the_cons_list;
      List* into_001 = renamed_Class->class_direct_supers;
      Cons* collect_001 = NULL;

      while (!nilP(iter_002)) {
        {
          s = ((Surrogate*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = permanent_cons(s, NIL);
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
            collect_001->rest = permanent_cons(s, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    incorporate_class_options(renamed_Class, options);
    { boolean test_value_001 = FALSE;

      test_value_001 = !renamed_Class->primitiveP();
      if (test_value_001) {
        { boolean foundP_001 = FALSE;

          { Slot* slot = NULL;
            Cons* iter_003 = slots->the_cons_list;

            while (!nilP(iter_003)) {
              {
                slot = ((Slot*)(iter_003->value));
                iter_003 = iter_003->rest;
              }
              if (slot->primitiveP()) {
                foundP_001 = TRUE;
                break;
              }
            }
          }
          test_value_001 = foundP_001;
        }
      }
      if (test_value_001) {
        cerr << "Defined class " << "`" << renamed_Class << "'" << " illegally specifies primitive slots.";
      }
    }
    renamed_Class->class_local_slots = slots;
    if (oldclass != NULL) {
      undefine_old_class(oldclass, renamed_Class);
    }
    { Slot* slot = NULL;
      Cons* iter_004 = slots->the_cons_list;

      while (!nilP(iter_004)) {
        {
          slot = ((Slot*)(iter_004->value));
          iter_004 = iter_004->rest;
        }
        register_slot_name(slot);
      }
    }
    remember_unfinalized_class(renamed_Class, TRUE);
    return (renamed_Class);
  }
}

Slot* define_stella_slot(Symbol* name, Surrogate* owner, Surrogate* basetype, Cons* typespecifier, Keyword_Key_Value_List* options) {
  { Storage_Slot* slot = new_storage_slot();

    slot->slot_name = name;
    slot->slot_owner = owner;
    slot->slot_base_type = basetype;
    if (typespecifier->non_emptyP()) {
      set_dynamic_slot_value(slot, SYM_CLASSES_SLOT_TYPE_SPECIFIER, ((Compound_Type_Specifier*)(typespecifier->yield_type_specifier())), NULL);
    }
    { Object* value = NULL;
      Keyword* key = NULL;
      Kv_List_Iterator* iter_001 = ((Kv_List_Iterator*)(options->allocate_iterator()));

      while (iter_001->nextP()) {
        key = ((Keyword*)(iter_001->key));
        {
          value = iter_001->value;
        }
        if (key == KWD_CLASSES_PUBLICp) {
          slot->slot_publicP = ((Boolean_Wrapper*)(value))->wrapper_value;
        }
        else if (key == KWD_CLASSES_REQUIREDp) {
          slot->slot_requiredP = ((Boolean_Wrapper*)(value))->wrapper_value;
        }
        else if (key == KWD_CLASSES_COMPONENTp) {
          slot->slot_componentP = ((Boolean_Wrapper*)(value))->wrapper_value;
        }
        else if (key == KWD_CLASSES_READ_ONLYp) {
          slot->slot_read_onlyP = ((Boolean_Wrapper*)(value))->wrapper_value;
        }
        else if (key == KWD_CLASSES_ACTIVEp) {
          set_dynamic_slot_value(slot, SYM_CLASSES_STORED_ACTIVEp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
        }
        else if (key == KWD_CLASSES_CONTEXT_SENSITIVEp) {
          slot->slot_context_sensitiveP = ((Boolean_Wrapper*)(value))->wrapper_value;
        }
        else if (key == KWD_CLASSES_HARDWIREDp) {
          slot->slot_hardwiredP = ((Boolean_Wrapper*)(value))->wrapper_value;
        }
        else if (key == KWD_CLASSES_ABSTRACTp) {
          slot->abstractP = ((Boolean_Wrapper*)(value))->wrapper_value;
        }
        else if (key == KWD_CLASSES_ALLOCATION) {
          if (value == KWD_CLASSES_CLASS) {
            cerr << "In definition of slot " << "`" << slot << "'" << ": ':class' allocation is unsupported right now." << endl << " Maybe use ':hardwired? TRUE' for read-only slots.";
          }
          else {
            set_dynamic_slot_value(slot, SYM_CLASSES_SLOT_ALLOCATION, ((Keyword*)(value)), NULL);
          }
        }
        else if (key == KWD_CLASSES_INITIALLY) {
          set_dynamic_slot_value(slot, SYM_CLASSES_SLOT_INITIAL_VALUE, value, NULL);
        }
        else if (key == KWD_CLASSES_DEFAULT) {
          set_dynamic_slot_value(slot, SYM_CLASSES_SLOT_DEFAULT_EXPRESSION, value, NULL);
        }
        else if (key == KWD_CLASSES_READER) {
          set_dynamic_slot_value(slot, SYM_CLASSES_SLOT_READER, ((Symbol*)(value)), NULL);
        }
        else if (key == KWD_CLASSES_WRITER) {
          set_dynamic_slot_value(slot, SYM_CLASSES_SLOT_WRITER, ((Symbol*)(value)), NULL);
        }
        else if (key == KWD_CLASSES_INVERSE) {
          set_dynamic_slot_value(slot, SYM_CLASSES_SLOT_INVERSE, ((Symbol*)(value)), NULL);
        }
        else if (key == KWD_CLASSES_RENAMES) {
          set_dynamic_slot_value(slot, SYM_CLASSES_SLOT_RENAMES, ((Symbol*)(value)), NULL);
        }
        else if (key == KWD_CLASSES_DOCUMENTATION) {
          set_dynamic_slot_value(slot, SYM_CLASSES_DOCUMENTATION, wrap_string(((String_Wrapper*)(value))->wrapper_value), NULL_STRING_WRAPPER);
        }
        else if (key == KWD_CLASSES_PROPERTIES) {
          set_dynamic_slot_value(slot, SYM_CLASSES_PROPERTIES, ((List*)(value)), NULL);
        }
        else if (key == KWD_CLASSES_META_ATTRIBUTES) {
          set_dynamic_slot_value(slot, SYM_CLASSES_META_ATTRIBUTES, ((Key_Value_List*)(value)), NULL);
        }
        else if (key == KWD_CLASSES_OPTION_KEYWORD) {
          set_dynamic_slot_value(slot, SYM_CLASSES_SLOT_OPTION_KEYWORD, ((Keyword*)(value)), NULL);
        }
        else if (key == KWD_CLASSES_OPTION_HANDLER) {
          set_dynamic_slot_value(slot, SYM_CLASSES_SLOT_OPTION_HANDLER, ((Symbol*)(value)), NULL);
        }
        else {
          if (!(run_option_handlerP(slot, key, value))) {
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
                      cout << endl << " " << "Skipping invalid slot option " << "`" << de_uglify_parse_tree(key) << "'" << endl << "in the definition of slot " << "`" << type_to_symbol(owner) << "'" << "." << "`" << de_uglify_parse_tree(name) << "'" << "." << endl;
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
    if ((slot->slot_allocation_reader() == NULL) &&
        (basetype == SGT_CLASSES_BOOLEAN)) {
      set_dynamic_slot_value(slot, SYM_CLASSES_SLOT_ALLOCATION, KWD_CLASSES_BIT, NULL);
    }
    return (slot);
  }
}

void incorporate_class_options(Class* renamed_Class, Keyword_Key_Value_List* options) {
  { Object* value = NULL;
    Keyword* key = NULL;
    Kv_List_Iterator* iter_001 = ((Kv_List_Iterator*)(options->allocate_iterator()));

    while (iter_001->nextP()) {
      key = ((Keyword*)(iter_001->key));
      {
        value = iter_001->value;
      }
      if (key == KWD_CLASSES_DOCUMENTATION) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_DOCUMENTATION, wrap_string(((String_Wrapper*)(value))->wrapper_value), NULL_STRING_WRAPPER);
      }
      else if (key == KWD_CLASSES_CL_NATIVE_TYPE) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_CL_NATIVE_TYPE, wrap_string(((String_Wrapper*)(value))->wrapper_value), NULL_STRING_WRAPPER);
      }
      else if (key == KWD_CLASSES_CPP_NATIVE_TYPE) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_CPP_NATIVE_TYPE, wrap_string(((String_Wrapper*)(value))->wrapper_value), NULL_STRING_WRAPPER);
      }
      else if (key == KWD_CLASSES_IDL_NATIVE_TYPE) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_IDL_NATIVE_TYPE, wrap_string(((String_Wrapper*)(value))->wrapper_value), NULL_STRING_WRAPPER);
      }
      else if (key == KWD_CLASSES_JAVA_NATIVE_TYPE) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_JAVA_NATIVE_TYPE, wrap_string(((String_Wrapper*)(value))->wrapper_value), NULL_STRING_WRAPPER);
      }
      else if (key == KWD_CLASSES_PUBLICp) {
        renamed_Class->class_publicP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else if (key == KWD_CLASSES_ABSTRACTp) {
        renamed_Class->abstractP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else if (key == KWD_CLASSES_ACTIVEp) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_STORED_ACTIVEp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else if (key == KWD_CLASSES_CL_STRUCTp) {
        renamed_Class->cl_structP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else if (key == KWD_CLASSES_MIXINp) {
        renamed_Class->mixinP = ((Boolean_Wrapper*)(value))->wrapper_value;
        if (renamed_Class->mixinP) {
          renamed_Class->abstractP = TRUE;
        }
      }
      else if (key == KWD_CLASSES_RECYCLE_METHOD) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_RECYCLE_METHOD, ((Keyword*)(value)), NULL);
      }
      else if (key == KWD_CLASSES_EXTENSION) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_EXTENSION_NAME, ((Symbol*)(value)), NULL);
      }
      else if (key == KWD_CLASSES_CREATOR) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_CREATOR, ((Symbol*)(value)), NULL);
      }
      else if (key == KWD_CLASSES_INITIALIZER) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_INITIALIZER, ((Symbol*)(value)), NULL);
      }
      else if (key == KWD_CLASSES_TERMINATOR) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_TERMINATOR, ((Symbol*)(value)), NULL);
      }
      else if (key == KWD_CLASSES_DESTRUCTOR) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_DESTRUCTOR, ((Symbol*)(value)), NULL);
      }
      else if (key == KWD_CLASSES_INITIAL_VALUE) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_INITIAL_VALUE, value, NULL);
      }
      else if (key == KWD_CLASSES_PRINT_FORM) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_PRINT_FORM, value, NULL);
      }
      else if (key == KWD_CLASSES_EQUALITY_TEST) {
      }
      else if (key == KWD_CLASSES_KEY) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_KEY, new_list(), NULL);
        { Object* slotname = NULL;
          Cons* iter_002 = ((Cons*)(value));
          List* into_001 = renamed_Class->class_key_reader();
          Cons* collect_001 = NULL;

          while (!nilP(iter_002)) {
            {
              slotname = iter_002->value;
              iter_002 = iter_002->rest;
            }
            if (collect_001 == NULL) {
              {
                collect_001 = permanent_cons(slotname, NIL);
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
                collect_001->rest = permanent_cons(slotname, NIL);
                collect_001 = collect_001->rest;
              }
            }
          }
        }
      }
      else if (key == KWD_CLASSES_PARAMETERS) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_PARAMETERS, new_list(), NULL);
        { Slot* slot = NULL;
          Cons* iter_003 = ((List*)(value))->the_cons_list;
          List* into_002 = renamed_Class->class_parameters_reader();
          Cons* collect_002 = NULL;

          while (!nilP(iter_003)) {
            {
              slot = ((Slot*)(iter_003->value));
              iter_003 = iter_003->rest;
            }
            if (collect_002 == NULL) {
              {
                collect_002 = permanent_cons(slot->slot_name, NIL);
                if (into_002->the_cons_list->emptyP()) {
                  into_002->the_cons_list = collect_002;
                }
                else {
                  add_cons_to_end_of_cons_list(into_002->the_cons_list, collect_002);
                }
              }
            }
            else {
              {
                collect_002->rest = permanent_cons(slot->slot_name, NIL);
                collect_002 = collect_002->rest;
              }
            }
          }
        }
      }
      else if (key == KWD_CLASSES_SYNONYMS) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_SYNONYMS, new_list(), NULL);
        { Surrogate* type = NULL;
          Cons* iter_004 = ((Cons*)(value));
          List* into_003 = renamed_Class->class_synonyms_reader();
          Cons* collect_003 = NULL;

          while (!nilP(iter_004)) {
            {
              type = ((Surrogate*)(iter_004->value));
              iter_004 = iter_004->rest;
            }
            if (collect_003 == NULL) {
              {
                collect_003 = permanent_cons(type, NIL);
                if (into_003->the_cons_list->emptyP()) {
                  into_003->the_cons_list = collect_003;
                }
                else {
                  add_cons_to_end_of_cons_list(into_003->the_cons_list, collect_003);
                }
              }
            }
            else {
              {
                collect_003->rest = permanent_cons(type, NIL);
                collect_003 = collect_003->rest;
              }
            }
          }
        }
      }
      else if (key == KWD_CLASSES_PROPERTIES) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_PROPERTIES, ((List*)(value)), NULL);
      }
      else if (key == KWD_CLASSES_META_ATTRIBUTES) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_META_ATTRIBUTES, ((Key_Value_List*)(value)), NULL);
      }
      else if (key == KWD_CLASSES_CHILDREN) {
        renamed_Class->class_direct_subs = ((List*)(value));
        oCLASSES_WITH_UNRESOLVED_CHILDREN_REFERENCESo->push(renamed_Class);
      }
      else {
        if (!(run_option_handlerP(renamed_Class, key, value))) {
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
                    cout << endl << " " << "Skipping invalid class option " << "`" << de_uglify_parse_tree(key) << "'" << endl << "in the definition of class " << "`" << class_symbol(renamed_Class) << "'" << "." << endl;
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

boolean inline_methodP(Slot* slot) {
  return ((!slot->slot_externalP) &&
      (isaP(slot, SGT_CLASSES_METHOD_SLOT) &&
       ((!((Method_Slot*)(slot))->method_functionP) &&
        (!string_eqlP(((Method_Slot*)(slot))->method_stringified_source, "")))));
}

void transfer_external_slot_to_new_class(Slot* externalslot, Class* newclass) {
  { Slot* newclassslot = lookup_local_slot(newclass, externalslot->slot_name);

    if (newclassslot == NULL) {
      newclass->class_local_slots->insert(externalslot);
    }
    else if (inline_methodP(newclassslot) ||
        ((!(newclassslot->primary_type() == externalslot->primary_type())) ||
         FALSE)) {
    }
    else {
      newclass->class_local_slots->substitute(externalslot, newclassslot);
      newclassslot->free();
    }
  }
}

void transfer_demons_from_oldclass(Class* oldclass, Class* newclass) {
  { Slot* newslot = NULL;

    { Slot* oldslot = NULL;
      Cons* iter_001 = oldclass->class_local_slots->the_cons_list;

      while (!nilP(iter_001)) {
        {
          oldslot = ((Slot*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        { 
          newslot = lookup_local_slot(newclass, oldslot->slot_name);
          if (newslot != NULL) {
            { Slot* oldslot_001 = oldslot;

              if (storage_slotP(oldslot)) {
                { Storage_Slot* oldslot = NULL;

                  oldslot = ((Storage_Slot*)(oldslot_001));
                  { Slot* newslot_001 = newslot;

                    if (storage_slotP(newslot)) {
                      { Storage_Slot* newslot = NULL;

                        newslot = ((Storage_Slot*)(newslot_001));
                        set_dynamic_slot_value(newslot, SYM_CLASSES_SLOT_GUARD_DEMONS, oldslot->slot_guard_demons_reader(), NULL);
                        set_dynamic_slot_value(oldslot, SYM_CLASSES_SLOT_GUARD_DEMONS, NULL, NULL);
                        set_dynamic_slot_value(newslot, SYM_CLASSES_SLOT_DEMONS, oldslot->slot_demons_reader(), NULL);
                        set_dynamic_slot_value(oldslot, SYM_CLASSES_SLOT_DEMONS, NULL, NULL);
                      }
                    }
                    else {
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
    }
  }
  set_dynamic_slot_value(newclass, SYM_CLASSES_CLASS_CONSTRUCTOR_DEMONS, oldclass->class_constructor_demons_reader(), NULL);
  set_dynamic_slot_value(oldclass, SYM_CLASSES_CLASS_CONSTRUCTOR_DEMONS, NULL, NULL);
  set_dynamic_slot_value(newclass, SYM_CLASSES_CLASS_GUARD_CONSTRUCTOR_DEMONS, oldclass->class_guard_constructor_demons_reader(), NULL);
  set_dynamic_slot_value(oldclass, SYM_CLASSES_CLASS_GUARD_CONSTRUCTOR_DEMONS, NULL, NULL);
  set_dynamic_slot_value(newclass, SYM_CLASSES_CLASS_DESTRUCTOR_DEMONS, oldclass->class_destructor_demons_reader(), NULL);
  set_dynamic_slot_value(oldclass, SYM_CLASSES_CLASS_DESTRUCTOR_DEMONS, NULL, NULL);
  set_dynamic_slot_value(newclass, SYM_CLASSES_CLASS_GUARD_DESTRUCTOR_DEMONS, oldclass->class_guard_destructor_demons_reader(), NULL);
  set_dynamic_slot_value(oldclass, SYM_CLASSES_CLASS_GUARD_DESTRUCTOR_DEMONS, NULL, NULL);
}

void undefine_old_class(Class* oldclass, Class* newclass) {
  { Cons* newsubs = copy_cons_list(newclass->class_direct_subs->the_cons_list);

    unfinalize_class_and_subclasses(oldclass);
    forget_unfinalized_class(oldclass);
    { Surrogate* oldsub = NULL;
      Cons* iter_001 = oldclass->class_direct_subs->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          oldsub = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(oldsub, NIL);
            if (nilP(newsubs)) {
              newsubs = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(newsubs, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(oldsub, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    newclass->class_direct_subs->clear();
    newclass->class_direct_subs->the_cons_list = newsubs->remove_duplicates();
    oldclass->class_direct_subs->clear();
  }
  { Slot* oldslot = NULL;
    Cons* iter_002 = oldclass->class_local_slots->the_cons_list;

    while (!nilP(iter_002)) {
      {
        oldslot = ((Slot*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      if (oldslot->slot_externalP) {
        transfer_external_slot_to_new_class(oldslot, newclass);
      }
    }
  }
  newclass->class_constructor_code = oldclass->class_constructor_code;
  transfer_demons_from_oldclass(oldclass, newclass);
  run_hooks(oREDEFINE_RELATION_HOOKSo, list(2, oldclass, newclass));
  oldclass->free();
}

void Class::destroy_class() {
  // Destroy the Stella class 'self'.  
  // Unfinalize its subclasses (if it has any).
  { Class* self = this;

    if (self->deletedP()) {
      return;
    }
    if (self->class_type->home_context == oSTELLA_MODULEo) {
      cerr << "Can't delete STELLA class " << "`" << class_name(self) << "'" << ".";
      return;
    }
    self->deletedP_setter(TRUE);
    unfinalize_class_and_subclasses(self);
    self->unbind_from_surrogate();
    finalize_classes_and_slots();
    self->free();
  }
}

void Surrogate::destroy_class() {
  { Surrogate* self = this;

    { Class* renamed_Class = ((Class*)(self->surrogate_value));

      if (renamed_Class == NULL) {
        cout << "Can't destroy non-existent class " << "`" << self << "'" << "." << endl;
      }
      else {
        renamed_Class->destroy_class();
      }
    }
  }
}

void destroy_class_and_subclasses(Class* self) {
  // Destroy the Stella class 'self' and all its subclasses.
  { Surrogate* subtype = NULL;
    Cons* iter_001 = self->class_direct_subs->the_cons_list;

    while (!nilP(iter_001)) {
      {
        subtype = ((Surrogate*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (((Class*)(subtype->surrogate_value)) != NULL) {
        destroy_class_and_subclasses(((Class*)(subtype->surrogate_value)));
      }
    }
  }
  self->destroy_class();
}

boolean Relation::primitiveP() {
  // Return TRUE if 'self' is not a defined relation.
  { Relation* self = this;

    return (TRUE);
  }
}

void insert_primitive_super(Surrogate* newsuper, List* supers) {
  { boolean foundP_001 = FALSE;

    { Surrogate* sup = NULL;
      Cons* iter_001 = supers->the_cons_list;

      while (!nilP(iter_001)) {
        {
          sup = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (subtype_ofP(newsuper, sup)) {
          foundP_001 = TRUE;
          break;
        }
      }
    }
    if (!(foundP_001)) {
      { Surrogate* subsumedsuper = NULL;

        for (;;) {
          { 
            { Surrogate* value_001 = NULL;

              { Surrogate* sup = NULL;
                Cons* iter_002 = supers->the_cons_list;

                while (!nilP(iter_002)) {
                  {
                    sup = ((Surrogate*)(iter_002->value));
                    iter_002 = iter_002->rest;
                  }
                  if (subtype_ofP(sup, newsuper)) {
                    value_001 = sup;
                    break;
                  }
                }
              }
              subsumedsuper = value_001;
            }
            if (!(subsumedsuper != NULL)) {
              break;
            }
          }
          supers = ((List*)(supers->remove(subsumedsuper)));
        }
        supers->insert(newsuper);
      }
    }
  }
}

void collect_most_specific_primitive_supers(Class* renamed_Class, List* supers) {
  { Surrogate* super = NULL;
    Cons* iter_001 = renamed_Class->class_direct_supers->the_cons_list;

    while (!nilP(iter_001)) {
      {
        super = ((Surrogate*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (type_to_class(super)->primitiveP()) {
        insert_primitive_super(super, supers);
      }
      else {
        collect_most_specific_primitive_supers(type_to_class(super), supers);
      }
    }
  }
}

List* most_specific_primitive_supers(Class* renamed_Class) {
  { List* supers = new_list();

    collect_most_specific_primitive_supers(renamed_Class, supers);
    return (supers->reverse());
  }
}

Iterator* class_native_supers(Class* renamed_Class) {
  { boolean alwaysP_001 = TRUE;

    { Surrogate* super = NULL;
      Cons* iter_001 = renamed_Class->class_direct_supers->the_cons_list;

      while (!nilP(iter_001)) {
        {
          super = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (!type_to_class(super)->primitiveP()) {
          alwaysP_001 = FALSE;
          break;
        }
      }
    }
    if (alwaysP_001) {
      return (((List_Iterator*)(renamed_Class->class_direct_supers->allocate_iterator())));
    }
    else {
      return (most_specific_primitive_supers(renamed_Class)->allocate_destructive_list_iterator());
    }
  }
}

void remember_unfinalized_class(Class* renamed_Class, boolean forceP) {
  if (forceP ||
      (renamed_Class->class_finalizedP &&
       renamed_Class->class_slots_finalizedP)) {
    oUNFINALIZED_CLASSESo->push(renamed_Class);
    oNEWLY_UNFINALIZED_CLASSESpo = TRUE;
  }
}

void forget_unfinalized_class(Class* renamed_Class) {
  if (!(renamed_Class->class_finalizedP &&
      renamed_Class->class_slots_finalizedP)) {
    oUNFINALIZED_CLASSESo->remove(renamed_Class);
  }
}

void finalize_classes() {
  // Finalize all currently unfinalized classes.
  if (!oNEWLY_UNFINALIZED_CLASSESpo) {
    return;
  }
  { boolean hierarchymighthavechangedP = FALSE;

    oUNFINALIZED_CLASSESo->remove_deleted_members();
    resolve_children_references();
    { Class* renamed_Class = NULL;
      Cons* iter_001 = oUNFINALIZED_CLASSESo->the_cons_list;

      while (!nilP(iter_001)) {
        {
          renamed_Class = ((Class*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (!renamed_Class->class_finalizedP) {
          finalize_class(renamed_Class);
          hierarchymighthavechangedP = TRUE;
        }
      }
    }
    if (hierarchymighthavechangedP) {
      create_class_taxonomy();
    }
  }
}

void resolve_children_references() {
  if (oCLASSES_WITH_UNRESOLVED_CHILDREN_REFERENCESo->emptyP() ||
      oUNFINALIZED_CLASSESo->emptyP()) {
    return;
  }
  { Cons* unresolvableclasses = NIL;

    oCLASSES_WITH_UNRESOLVED_CHILDREN_REFERENCESo->remove_deleted_members();
    { Class* renamed_Class = NULL;
      Cons* iter_001 = oCLASSES_WITH_UNRESOLVED_CHILDREN_REFERENCESo->the_cons_list;

      while (!nilP(iter_001)) {
        {
          renamed_Class = ((Class*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        add_direct_subs_back_links(renamed_Class);
        { boolean foundP_001 = FALSE;

          { Surrogate* sub = NULL;
            Cons* iter_002 = renamed_Class->class_direct_subs->the_cons_list;

            while (!nilP(iter_002)) {
              {
                sub = ((Surrogate*)(iter_002->value));
                iter_002 = iter_002->rest;
              }
              if (!(type_to_class(sub) != NULL)) {
                foundP_001 = TRUE;
                break;
              }
            }
          }
          if (foundP_001) {
            unresolvableclasses = cons(renamed_Class, unresolvableclasses);
          }
        }
      }
    }
    oCLASSES_WITH_UNRESOLVED_CHILDREN_REFERENCESo->clear();
    oCLASSES_WITH_UNRESOLVED_CHILDREN_REFERENCESo->the_cons_list = unresolvableclasses;
  }
}

void finalize_slots() {
  // Finalize all currently unfinalized slots.
  if (!oNEWLY_UNFINALIZED_CLASSESpo) {
    return;
  }
  { Class* renamed_Class = NULL;
    Cons* iter_001 = oUNFINALIZED_CLASSESo->the_cons_list;

    while (!nilP(iter_001)) {
      {
        renamed_Class = ((Class*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (renamed_Class->class_finalizedP &&
          (!renamed_Class->class_slots_finalizedP)) {
        finalize_class_slots(renamed_Class);
      }
    }
  }
}

void cleanup_unfinalized_classes() {
  // Remove all finalized classes from '*unfinalized-classes*',
  // and set '*newly-unfinalized-classes?*' to FALSE.
  { Cons* unfinalizedclasses = NIL;

    { Class* renamed_Class = NULL;
      Cons* iter_001 = oUNFINALIZED_CLASSESo->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          renamed_Class = ((Class*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if ((!renamed_Class->class_finalizedP) ||
            (!renamed_Class->class_slots_finalizedP)) {
          if (collect_001 == NULL) {
            {
              collect_001 = cons(renamed_Class, NIL);
              if (nilP(unfinalizedclasses)) {
                unfinalizedclasses = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(unfinalizedclasses, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = cons(renamed_Class, NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
    }
    oUNFINALIZED_CLASSESo->clear();
    oUNFINALIZED_CLASSESo->the_cons_list = unfinalizedclasses;
    oNEWLY_UNFINALIZED_CLASSESpo = FALSE;
  }
}

void finalize_classes_and_slots() {
  // Finalize all currently unfinalized classes and slots.
  finalize_classes();
  finalize_slots();
  cleanup_unfinalized_classes();
}

void activate_class(Class* renamed_Class) {
  { Class* activeobjectclass = type_to_class(SGT_CLASSES_ACTIVE_OBJECT);
    List* supers = renamed_Class->class_direct_supers;

    if ((activeobjectclass != NULL) &&
        subclass_ofP(renamed_Class, activeobjectclass)) {
      return;
    }
    if (supers->length() == 0) {
      supers->insert(SGT_CLASSES_ACTIVE_OBJECT);
    }
    else if ((supers->length() == 1) &&
        ((supers->first() == SGT_CLASSES_OBJECT) ||
         (supers->first() == SGT_CLASSES_STANDARD_OBJECT))) {
      remove_direct_supers_back_links(renamed_Class);
      supers->clear();
      supers->insert(SGT_CLASSES_ACTIVE_OBJECT);
    }
    else {
      set_dynamic_slot_value(renamed_Class, SYM_CLASSES_STORED_ACTIVEp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
      if (((Symbol*)(dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_EXTENSION_NAME, NULL))) != NULL) {
        set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_EXTENSION_NAME, NULL, NULL);
      }
      cerr << "Cannot convert " << "`" << renamed_Class << "'" << " into an ACTIVE-OBJECT." << endl << "You have to modify its superclasses by hand.";
      return;
    }
    add_direct_supers_back_links(renamed_Class);
    inherit_superclasses(renamed_Class);
  }
}

void add_primary_type(Class* renamed_Class) {
  { Surrogate* classtype = renamed_Class->class_type;
    Cons* slottree = NULL;

    { boolean test_value_001 = FALSE;

      test_value_001 = !renamed_Class->abstractP;
      if (test_value_001) {
        test_value_001 = subtype_ofP(classtype, SGT_CLASSES_OBJECT);
        if (test_value_001) {
          { boolean foundP_001 = FALSE;

            { Slot* slot = NULL;
              Cons* iter_001 = renamed_Class->class_local_slots->the_cons_list;

              while (!nilP(iter_001)) {
                {
                  slot = ((Slot*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                if (slot->slot_name == SYM_CLASSES_PRIMARY_TYPE) {
                  foundP_001 = TRUE;
                  break;
                }
              }
            }
            test_value_001 = foundP_001;
          }
          test_value_001 = !test_value_001;
        }
      }
      if (test_value_001) {
        { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oTRANSIENTOBJECTSpo = TRUE;
                slottree = listO(7, cons(listO(3, SYM_CLASSES_SELF, type_to_symbol(classtype), NIL), NIL), KWD_CLASSES_TYPE, SYM_CLASSES_TYPE, KWD_CLASSES_AUXILIARYp, SYM_CLASSES_TRUE, listO(3, SYM_CLASSES_RETURN, classtype, NIL), NIL);
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
        renamed_Class->class_local_slots->push(define_inline_method(SYM_CLASSES_PRIMARY_TYPE, slottree));
      }
    }
  }
}

void finalize_one_class(Class* renamed_Class) {
  if (((Symbol*)(dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_EXTENSION_NAME, NULL))) != NULL) {
    set_dynamic_slot_value(renamed_Class, SYM_CLASSES_STORED_ACTIVEp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
  }
  add_direct_supers_back_links(renamed_Class);
  inherit_superclasses(renamed_Class);
  if ((renamed_Class->stored_activeP_reader() != NULL_BOOLEAN) &&
      renamed_Class->stored_activeP_reader()) {
    activate_class(renamed_Class);
  }
  add_primary_type(renamed_Class);
  { Surrogate* alias = NULL;
    Cons* iter_001 = renamed_Class->class_synonyms_reader()->the_cons_list;

    while (!nilP(iter_001)) {
      {
        alias = ((Surrogate*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if ((((Class*)(alias->surrogate_value)) != NULL) &&
          ((!(alias->surrogate_value == renamed_Class)) &&
           (!string_eqlP(class_name(((Class*)(alias->surrogate_value))), class_name(renamed_Class))))) {
        cerr << "Alias " << "`" << type_to_symbol(alias) << "'" << " can't point to " << "`" << class_symbol(renamed_Class) << "'" << " because it already points to " << endl << "the class " << "`" << class_symbol(((Class*)(alias->surrogate_value))) << "'" << ".";
      }
      else {
        alias->surrogate_value = renamed_Class;
      }
    }
  }
  if ((((Symbol*)(dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_EXTENSION_NAME, NULL))) != NULL) &&
      (((Class_Extension*)(dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_EXTENSION, NULL))) == NULL)) {
    set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_EXTENSION, new_class_extension(), NULL);
  }
  renamed_Class->class_finalizedP = TRUE;
}

boolean finalize_class(Class* renamed_Class) {
  return (help_finalize_class(renamed_Class, NULL));
}

boolean help_finalize_class(Class* renamed_Class, Surrogate* finalizedparent) {
  if (renamed_Class->class_finalizedP) {
    return (TRUE);
  }
  { Surrogate* super = NULL;
    Cons* iter_001 = renamed_Class->class_direct_supers->the_cons_list;

    while (!nilP(iter_001)) {
      {
        super = ((Surrogate*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (!(super == finalizedparent)) {
        { Class* superclass = type_to_class(super);

          if (superclass != NULL) {
            if (!(help_finalize_class(superclass, NULL))) {
              return (FALSE);
            }
          }
          else {
            return (FALSE);
          }
        }
      }
    }
  }
  if (!(renamed_Class->class_finalizedP)) {
    finalize_one_class(renamed_Class);
    { Surrogate* sub = NULL;
      Cons* iter_002 = renamed_Class->class_direct_subs->the_cons_list;

      while (!nilP(iter_002)) {
        {
          sub = ((Surrogate*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        { Class* subclass = type_to_class(sub);

          if (subclass != NULL) {
            help_finalize_class(subclass, renamed_Class->class_type);
          }
        }
      }
    }
    return (TRUE);
  }
}

void unfinalize_class_and_subclasses(Class* renamed_Class) {
  if (!renamed_Class->class_finalizedP) {
    return;
  }
  remove_direct_supers_back_links(renamed_Class);
  { List* subs = renamed_Class->class_direct_subs->copy();

    { Surrogate* subtype = NULL;
      Cons* iter_001 = subs->the_cons_list;

      while (!nilP(iter_001)) {
        {
          subtype = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (((Class*)(subtype->surrogate_value)) != NULL) {
          unfinalize_class_and_subclasses(((Class*)(subtype->surrogate_value)));
        }
      }
    }
    subs->free();
  }
  { Surrogate* alias = NULL;
    Cons* iter_002 = renamed_Class->class_synonyms_reader()->the_cons_list;

    while (!nilP(iter_002)) {
      {
        alias = ((Surrogate*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      if (alias->surrogate_value == renamed_Class) {
        alias->surrogate_value = NULL;
      }
    }
  }
  uninherit_superclasses(renamed_Class);
  unfinalize_class_slots(renamed_Class);
  remember_unfinalized_class(renamed_Class, FALSE);
  renamed_Class->class_finalizedP = FALSE;
}

Slot* attach_slot_to_owner(Slot* newslot) {
  { Symbol* name = newslot->slot_name;
    Class* ownerclass = ((Class*)(newslot->slot_owner->surrogate_value));
    Slot* oldslot = lookup_local_slot(ownerclass, name);

    newslot->slot_externalP = TRUE;
    register_slot_name(newslot);
    if (oldslot == NULL) {
      ownerclass->class_local_slots->insert(newslot);
      unfinalize_class_slots(ownerclass);
      return (newslot);
    }
    else if (!local_slotP(oldslot, ownerclass)) {
      ownerclass->class_local_slots->insert(newslot);
      unfinalize_class_slots(ownerclass);
      return (newslot);
    }
    else if (!(newslot->primary_type() == oldslot->primary_type())) {
      cerr << "Can't define a " << "`" << newslot->primary_type() << "'" << " named " << "`" << name << "'" << " on the class " << "`" << class_name(ownerclass) << "'" << endl << "because it already has a " << "`" << oldslot->primary_type() << "'" << " with the same name.";
      return (NULL);
    }
    else {
      ownerclass->class_local_slots->substitute(newslot, oldslot);
      run_hooks(oREDEFINE_RELATION_HOOKSo, list(2, oldslot, newslot));
      oldslot->free();
      help_unfinalize_class_slots(ownerclass);
      return (newslot);
    }
  }
}

void compute_slot_direct_equivalent(Slot* self) {
  { Class* renamed_Class = ((Class*)(self->slot_owner->surrogate_value));
    Symbol* slotname = self->slot_name;
    Symbol* slotrenames = ((Symbol*)(dynamic_slot_value(self, SYM_CLASSES_SLOT_RENAMES, NULL)));
    Slot* renamesslot = NULL;

    if (slotrenames != NULL) {
      { Slot* value_001 = NULL;

        { Slot* s = NULL;
          Iterator* iter_001 = renamed_Class->class_slots();

          while (iter_001->nextP()) {
            {
              s = ((Slot*)(iter_001->value));
            }
            if (s->slot_name == slotrenames) {
              value_001 = s;
              break;
            }
          }
        }
        renamesslot = value_001;
      }
      if (renamesslot != NULL) {
        self->slot_direct_equivalent = renamesslot;
        renamesslot->slot_renamedP = TRUE;
      }
      else {
        cerr << "Slot " << "`" << slotname << "'" << " renames a non-existent self: " << "`" << slotrenames << "'" << "." << endl << "Cancelling the renames option.";
        set_dynamic_slot_value(self, SYM_CLASSES_SLOT_RENAMES, NULL, NULL);
      }
    }
    else {
      { Slot* value_002 = NULL;

        { Slot* s = NULL;
          Iterator* iter_002 = renamed_Class->class_slots();

          while (iter_002->nextP()) {
            {
              s = ((Slot*)(iter_002->value));
            }
            if ((!(s == self)) &&
                (s->slot_name == slotname)) {
              value_002 = s;
              break;
            }
          }
        }
        self->slot_direct_equivalent = value_002;
      }
    }
  }
}

void check_conformance_of_slot_signature(Slot* self) {
  { Slot* equivalentslot = self->slot_direct_equivalent;

    if ((equivalentslot != NULL) &&
        (!self->conforming_signaturesP(equivalentslot))) {
      cerr << "The signature of slot " << "`" << self << "'" << " does not conform to the" << endl << "   signature of the inherited slot " << "`" << equivalentslot << "'";
    }
  }
}

Surrogate* collection_to_active_collection(Surrogate* type) {
  if ((type == SGT_CLASSES_SET) ||
      (type == SGT_CLASSES_ACTIVE_SET)) {
    return (SGT_CLASSES_ACTIVE_SET);
  }
  else if ((type == SGT_CLASSES_LIST) ||
      (type == SGT_CLASSES_ACTIVE_LIST)) {
    return (SGT_CLASSES_ACTIVE_LIST);
  }
  else {
    return (NULL);
  }
}

void activate_slot(Storage_Slot* self) {
  if (!self->single_valuedP()) {
    { Surrogate* activecollection = collection_to_active_collection(self->slot_base_type);

      if (activecollection == NULL) {
        cerr << "No active collection defined for " << "`" << self->slot_base_type << "'" << "." << endl << "   Cannot activate slot " << "`" << self << "'" << ".";
        set_dynamic_slot_value(self, SYM_CLASSES_STORED_ACTIVEp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
        return;
      }
      self->slot_base_type = collection_to_active_collection(self->slot_base_type);
    }
  }
  set_dynamic_slot_value(self, SYM_CLASSES_STORED_ACTIVEp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
}

void Slot::finalize_slot_type_computations() {
  { Slot* self = this;

  }
}

void Storage_Slot::finalize_slot_type_computations() {
  { Storage_Slot* self = this;

    if (((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_CLASSES_SLOT_TYPE_SPECIFIER, NULL))) != NULL) {
      self->slot_base_type = validate_type_specifier(((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_CLASSES_SLOT_TYPE_SPECIFIER, NULL))), ((Class*)(self->slot_owner->surrogate_value)), FALSE);
    }
    if (self->slot_base_type == NULL) {
      self->slot_base_type = self->type();
    }
    if (self->slot_base_type == NULL) {
      if (!self->abstractP) {
        cerr << "Missing type specification for the slot " << "`" << self << "'";
      }
      self->slot_base_type = SGT_CLASSES_UNKNOWN;
      return;
    }
    if (self->activeP()) {
      activate_slot(self);
    }
  }
}

boolean multi_valued_slot_with_duplicatesP(Slot* self) {
  return (subtype_ofP(self->type(), SGT_CLASSES_COLLECTION) &&
      (!subtype_ofP(self->type(), SGT_CLASSES_SET_MIXIN)));
}

void compute_slot_inverses(Slot* self) {
  if (((Symbol*)(dynamic_slot_value(self, SYM_CLASSES_SLOT_INVERSE, NULL))) == NULL) {
    return;
  }
  if (multi_valued_slot_with_duplicatesP(self)) {
    cerr << "Can't define an inverse on slot " << "`" << self << "'" << " because it allows duplicate values.";
    set_dynamic_slot_value(self, SYM_CLASSES_SLOT_INVERSE, NULL, NULL);
    return;
  }
  { Class* inverseclass = ((Class*)(self->type()->surrogate_value));
    Slot* inverseslot = safe_lookup_slot(inverseclass, ((Symbol*)(dynamic_slot_value(self, SYM_CLASSES_SLOT_INVERSE, NULL))));

    if (inverseslot != NULL) {
      if (multi_valued_slot_with_duplicatesP(inverseslot)) {
        cerr << "Can't define an inverse on slot " << "`" << inverseslot << "'" << " because it allows duplicate values.";
        set_dynamic_slot_value(self, SYM_CLASSES_SLOT_INVERSE, NULL, NULL);
        set_dynamic_slot_value(inverseslot, SYM_CLASSES_SLOT_INVERSE, NULL, NULL);
        return;
      }
      if (!inverseslot->activeP()) {
        set_dynamic_slot_value(inverseslot, SYM_CLASSES_SLOT_INVERSE, self->slot_name, NULL);
        inverseslot->finalize_slot_type_computations();
      }
      set_dynamic_slot_value(inverseslot, SYM_CLASSES_INVERSE, self, NULL);
      attach_inverse_slot_demon(self);
      set_dynamic_slot_value(self, SYM_CLASSES_INVERSE, inverseslot, NULL);
      attach_inverse_slot_demon(inverseslot);
      return;
    }
    if (inverseclass == NULL) {
      cerr << "Can't finalize inverse slot computation for slot " << "`" << self << "'" << endl << " because the class " << "`" << self->type() << "'" << " is not defined.";
    }
    else {
      cerr << "Can't finalize inverse slot computation for slot " << "`" << self << "'" << endl << " because the inverse slot " << "`" << ((Symbol*)(dynamic_slot_value(self, SYM_CLASSES_SLOT_INVERSE, NULL))) << "'" << " does not exist.";
    }
  }
}

void Slot::help_finalize_local_slot() {
  { Slot* self = this;

  }
}

void Storage_Slot::help_finalize_local_slot() {
  { Storage_Slot* self = this;

    { Class* owner = ((Class*)(self->slot_owner->surrogate_value));

      if (dynamic_slotP(self) &&
          ((!subtype_ofP(owner->class_type, SGT_CLASSES_DYNAMIC_SLOTS_MIXIN)) &&
           (!owner->abstractP))) {
        cerr << "Slot " << "`" << self->slot_name << "'" << " on the class " << "`" << class_symbol(owner) << "'" << endl << "   can't have :dynamic slot allocation because the class doesn't" << endl << "   inherit the class 'DYNAMIC-SLOTS-MIXIN'.  Resetting the" << endl << "   allocation to ':instance'.";
        set_dynamic_slot_value(self, SYM_CLASSES_SLOT_ALLOCATION, KWD_CLASSES_INSTANCE, NULL);
      }
      if (((Symbol*)(dynamic_slot_value(self, SYM_CLASSES_SLOT_RENAMES, NULL))) != NULL) {
        { Storage_Slot* renamesslot = ((Storage_Slot*)(safe_lookup_slot(owner, ((Symbol*)(dynamic_slot_value(self, SYM_CLASSES_SLOT_RENAMES, NULL))))));

          if (!(self->primary_type() == renamesslot->primary_type())) {
            cerr << "Slot " << "`" << self->slot_name << "'" << " renames a slot of a different kind" << endl << "   (e.g., a storage slot renaming a method slot, or vice-versa)." << endl << "  Cancelling the renames option.";
            set_dynamic_slot_value(self, SYM_CLASSES_SLOT_RENAMES, NULL, NULL);
          }
          else if (!(self->allocation() == renamesslot->allocation())) {
            cerr << "Slot " << "`" << self->slot_name << "'" << " renames a slot with a different" << endl << "   allocation.  Changing its allocation to " << "`" << renamesslot->allocation() << "'" << ".";
            set_dynamic_slot_value(self, SYM_CLASSES_SLOT_ALLOCATION, renamesslot->allocation(), NULL);
          }
        }
      }
      if (self->slot_context_sensitiveP &&
          (!subtype_ofP(self->slot_owner, SGT_CLASSES_CONTEXT_SENSITIVE_OBJECT))) {
        cerr << "Class " << "`" << self->slot_owner->symbol_name << "'" << " must inherit the " << "class CONTEXT-SENSITIVE-OBJECT" << endl << "   because it contains the context sensitive slot " << "`" << self->slot_name << "'" << " " << endl;
      }
    }
  }
}

void finalize_local_slot(Slot* self) {
  compute_slot_direct_equivalent(self);
  self->finalize_slot_type_computations();
  check_conformance_of_slot_signature(self);
  compute_slot_inverses(self);
  self->help_finalize_local_slot();
}

void Slot::unfinalize_local_slot() {
  { Slot* self = this;

  }
}

void Storage_Slot::unfinalize_local_slot() {
  { Storage_Slot* self = this;

  }
}

void finalize_class_slots(Class* renamed_Class) {
  { Surrogate* super = NULL;
    Cons* iter_001 = renamed_Class->class_direct_supers->the_cons_list;

    while (!nilP(iter_001)) {
      {
        super = ((Surrogate*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (!((Class*)(super->surrogate_value))->class_slots_finalizedP) {
        finalize_class_slots(((Class*)(super->surrogate_value)));
      }
    }
  }
  compute_required_slot_names(renamed_Class);
  { Surrogate* classtype = renamed_Class->class_type;

    { Slot* slot = NULL;
      Cons* iter_002 = renamed_Class->class_local_slots->the_cons_list;

      while (!nilP(iter_002)) {
        {
          slot = ((Slot*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        register_slot_name(slot);
        slot->slot_owner = classtype;
      }
    }
  }
  { Slot* slot = NULL;
    Cons* iter_003 = renamed_Class->class_local_slots->the_cons_list;

    while (!nilP(iter_003)) {
      {
        slot = ((Slot*)(iter_003->value));
        iter_003 = iter_003->rest;
      }
      finalize_local_slot(slot);
    }
  }
  renamed_Class->class_slots_finalizedP = TRUE;
}

void unfinalize_class_slots(Class* renamed_Class) {
  if (!renamed_Class->class_slots_finalizedP) {
    return;
  }
  { Surrogate* subtype = NULL;
    Cons* iter_001 = renamed_Class->class_direct_subs->the_cons_list;

    while (!nilP(iter_001)) {
      {
        subtype = ((Surrogate*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (((Class*)(subtype->surrogate_value)) != NULL) {
        unfinalize_class_slots(((Class*)(subtype->surrogate_value)));
      }
    }
  }
  help_unfinalize_class_slots(renamed_Class);
}

void help_unfinalize_class_slots(Class* renamed_Class) {
  clear_slot_and_method_cache(renamed_Class);
  if (!renamed_Class->class_slots_finalizedP) {
    return;
  }
  free_required_slot_names(renamed_Class);
  { Slot* slot = NULL;
    Cons* iter_001 = renamed_Class->local_slots()->the_cons_list;

    while (!nilP(iter_001)) {
      {
        slot = ((Slot*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      slot->unfinalize_local_slot();
    }
  }
  remember_unfinalized_class(renamed_Class, FALSE);
  renamed_Class->class_slots_finalizedP = FALSE;
}

boolean Class::multiple_parentsP() {
  // Return TRUE if 'class' has more than one direct superclass.
  { Class* renamed_Class = this;

    return (renamed_Class->class_direct_supers->rest()->non_emptyP());
  }
}

void add_direct_supers_back_links(Class* renamed_Class) {
  { List* directsupers = renamed_Class->class_direct_supers;
    Surrogate* classtype = renamed_Class->class_type;

    directsupers->remove_duplicates();
    { Surrogate* supertype = NULL;
      Cons* iter_001 = directsupers->the_cons_list;

      while (!nilP(iter_001)) {
        {
          supertype = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (((Class*)(supertype->surrogate_value)) != NULL) {
          { Class* superclass = ((Class*)(supertype->surrogate_value));

            superclass->class_direct_subs->insert_new(classtype);
          }
        }
      }
    }
  }
}

void add_direct_subs_back_links(Class* renamed_Class) {
  { List* directsubs = renamed_Class->class_direct_subs;
    Surrogate* classtype = renamed_Class->class_type;

    directsubs->remove_duplicates();
    { Surrogate* subtype = NULL;
      Cons* iter_001 = directsubs->the_cons_list;

      while (!nilP(iter_001)) {
        {
          subtype = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (((Class*)(subtype->surrogate_value)) != NULL) {
          { Class* subclass = ((Class*)(subtype->surrogate_value));

            if (subclass->class_finalizedP) {
              if (!(subclass->class_all_super_classes->memberP(renamed_Class))) {
                subclass->class_direct_supers->insert(classtype);
                unfinalize_class_and_subclasses(renamed_Class);
              }
            }
            else {
              subclass->class_direct_supers->insert_new(classtype);
            }
          }
        }
      }
    }
  }
}

void remove_direct_supers_back_links(Class* renamed_Class) {
  { Surrogate* classtype = renamed_Class->class_type;

    { Surrogate* supertype = NULL;
      Cons* iter_001 = renamed_Class->class_direct_supers->the_cons_list;

      while (!nilP(iter_001)) {
        {
          supertype = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (((Class*)(supertype->surrogate_value)) != NULL) {
          ((Class*)(supertype->surrogate_value))->class_direct_subs->remove(classtype);
        }
      }
    }
  }
}

void collect_direct_super_classes(Class* renamed_Class, List* parents) {
  { List* directsupertypes = renamed_Class->class_direct_supers;
    List* nondirectparents = new_list();

    { Surrogate* supertype = NULL;
      Cons* iter_001 = directsupertypes->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          supertype = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (((Class*)(supertype->surrogate_value)) != NULL) {
          if (collect_001 == NULL) {
            {
              collect_001 = permanent_cons(((Class*)(supertype->surrogate_value)), NIL);
              if (parents->the_cons_list->emptyP()) {
                parents->the_cons_list = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(parents->the_cons_list, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = permanent_cons(((Class*)(supertype->surrogate_value)), NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
    }
    { Class* superclass = NULL;
      Cons* iter_002 = parents->the_cons_list;

      while (!nilP(iter_002)) {
        {
          superclass = ((Class*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        { Class* othersuperclass = NULL;
          Cons* iter_003 = parents->the_cons_list;

          while (!nilP(iter_003)) {
            {
              othersuperclass = ((Class*)(iter_003->value));
              iter_003 = iter_003->rest;
            }
            if (!(othersuperclass == superclass)) {
              if (superclass->class_all_super_classes->memberP(othersuperclass)) {
                nondirectparents->insert(othersuperclass);
              }
            }
          }
        }
      }
    }
    { Class* p = NULL;
      Cons* iter_004 = nondirectparents->the_cons_list;

      while (!nilP(iter_004)) {
        {
          p = ((Class*)(iter_004->value));
          iter_004 = iter_004->rest;
        }
        parents->remove(p);
      }
    }
    nondirectparents->free();
  }
}

void inherit_superclasses(Class* renamed_Class) {
  { List* parentclasses = new_list();

    collect_direct_super_classes(renamed_Class, parentclasses);
    if (!renamed_Class->multiple_parentsP()) {
      { Class* onlyparent = ((Class*)(parentclasses->first()));

        if (onlyparent == NULL) {
          return;
        }
        renamed_Class->class_all_super_classes = cons(onlyparent, onlyparent->class_all_super_classes);
        return;
      }
    }
    parentclasses = parentclasses->reverse();
    { Cons* allsuperclasses = NIL;
      Cons* sublist = NULL;

      { Class* parent = NULL;
        Cons* iter_001 = parentclasses->the_cons_list;

        while (!nilP(iter_001)) {
          {
            parent = ((Class*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          sublist = NIL;
          { Class* ancestor = NULL;
            Cons* iter_002 = parent->class_all_super_classes;
            Cons* collect_001 = NULL;

            while (!nilP(iter_002)) {
              {
                ancestor = ((Class*)(iter_002->value));
                iter_002 = iter_002->rest;
              }
              if (!allsuperclasses->memberP(ancestor)) {
                if (collect_001 == NULL) {
                  {
                    collect_001 = cons(ancestor, NIL);
                    if (nilP(sublist)) {
                      sublist = collect_001;
                    }
                    else {
                      add_cons_to_end_of_cons_list(sublist, collect_001);
                    }
                  }
                }
                else {
                  {
                    collect_001->rest = cons(ancestor, NIL);
                    collect_001 = collect_001->rest;
                  }
                }
              }
            }
          }
          sublist = cons(parent, sublist);
          allsuperclasses = sublist->concatenate(allsuperclasses);
        }
      }
      renamed_Class->class_all_super_classes = allsuperclasses;
    }
  }
}

void uninherit_superclasses(Class* renamed_Class) {
  if (renamed_Class->multiple_parentsP()) {
    free_cons_list(renamed_Class->class_all_super_classes);
  }
  else if (renamed_Class->class_all_super_classes->non_emptyP()) {
    renamed_Class->class_all_super_classes->free_cons();
  }
  renamed_Class->class_all_super_classes = NIL;
}

boolean subclass_ofP(Class* subclass, Class* superclass) {
  // Return TRUE iff the class named 'subClass' is a subclass of the
  // class named 'superClass'.
  return (taxonomy_subclass_ofP(subclass, superclass));
}

boolean subtype_ofP(Surrogate* subtype, Surrogate* supertype) {
  // Return TRUE iff the class named 'subType' is a subclass 
  // of the class named 'superType'.
  // inline method
  return (subclass_ofP(type_to_class(subtype), type_to_class(supertype)));
}

boolean isaP(Object* object, Surrogate* type) {
  // Return TRUE iff 'object' is an instance of the class named
  // 'type'.
  return (subtype_ofP(object->primary_type(), type));
}

Class* two_argument_least_common_superclass(Class* class1, Class* class2) {
  // Return the most specific class that is a superclass of
  // both 'class1' and 'class2'.  If there is more than one, arbitrarily pick one.
  // If there is none, return NULL.
  if (subclass_ofP(class1, class2)) {
    return (class2);
  }
  if (subclass_ofP(class2, class1)) {
    return (class1);
  }
  { Class* c = NULL;
    Cons* iter_001 = class1->class_all_super_classes;

    while (!nilP(iter_001)) {
      {
        c = ((Class*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      c->class_markedP = FALSE;
    }
  }
  { Class* c = NULL;
    Cons* iter_002 = class2->class_all_super_classes;

    while (!nilP(iter_002)) {
      {
        c = ((Class*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      c->class_markedP = TRUE;
    }
  }
  { Class* c = NULL;
    Cons* iter_003 = class1->class_all_super_classes;

    while (!nilP(iter_003)) {
      {
        c = ((Class*)(iter_003->value));
        iter_003 = iter_003->rest;
      }
      if (c->class_markedP) {
        return (c);
      }
    }
  }
  return (NULL);
}

Surrogate* two_argument_least_common_supertype(Surrogate* type1, Surrogate* type2) {
  // Return the most specific type that is a supertype of
  // both 'type1' and 'type2'.  If there is more than one, arbitrarily pick one.
  // If there is none, return @VOID.
  { Class* renamed_Class = two_argument_least_common_superclass(((Class*)(type1->surrogate_value)), ((Class*)(type2->surrogate_value)));

    if (renamed_Class != NULL) {
      return (renamed_Class->class_type);
    }
    else {
      return (SGT_CLASSES_VOID);
    }
  }
}

void inherit_slots(Class* renamed_Class) {
  { Cons* slots = copy_cons_list(renamed_Class->class_local_slots->the_cons_list);

    if (renamed_Class->class_direct_supers->emptyP()) {
    }
    else if (renamed_Class->multiple_parentsP()) {
      { Surrogate* supertype = NULL;
        Cons* iter_001 = renamed_Class->class_direct_supers->the_cons_list;

        while (!nilP(iter_001)) {
          {
            supertype = ((Surrogate*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          slots = slots->concatenate(copy_cons_list(((Class*)(supertype->surrogate_value))->class_all_slots));
        }
      }
      slots = slots->reverse();
      slots->remove_duplicates();
      slots = slots->reverse();
    }
    else {
      { Cons* parentslots = ((Class*)(((Surrogate*)(renamed_Class->class_direct_supers->first()))->surrogate_value))->class_all_slots;

        slots = slots->concatenate(parentslots);
      }
    }
    renamed_Class->class_all_slots = slots;
  }
}

boolean local_slotP(Slot* slot, Class* renamed_Class) {
  return (slot->slot_owner->surrogate_value == renamed_Class);
}

void uninherit_slots(Class* renamed_Class) {
  { Cons* slotscursor = renamed_Class->class_all_slots;

    if (slotscursor != NULL) {
      if (!(renamed_Class->multiple_parentsP())) {
        { Slot* slot = NULL;
          Cons* iter_001 = renamed_Class->class_all_slots;

          while (!nilP(iter_001)) {
            {
              slot = ((Slot*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            if (slotscursor->rest->non_emptyP() &&
                local_slotP(((Slot*)(slotscursor->rest->first())), renamed_Class)) {
              slotscursor = slotscursor->rest;
            }
            else {
              break;
            }
          }
        }
        slotscursor->rest = NIL;
      }
      free_cons_list(renamed_Class->class_all_slots);
      renamed_Class->class_all_slots = NULL;
    }
  }
}

void initialize_slot_and_method_cache(Class* renamed_Class) {
  renamed_Class->class_slot_and_method_cache = new_vector(oSLOT_CACHE_SIZEo + 1);
}

void register_slot_name(Slot* slot) {
  // Register the name symbol of 'slot' as a slot name, and
  // initialize its 'symbol-slot-offset' so that it can be used by 'lookup-slot'.
  slot->slot_name->symbol_slot_offset = 0;
}

void unregister_slot_name(Slot* slot) {
  // Unregister the name symbol of 'slot' as a slot name,
  // so that it can no longer be used by 'lookup-slot'.
  slot->slot_name->symbol_slot_offset = NULL_INTEGER;
}

boolean registered_slot_nameP(Symbol* slotname) {
  // Return TRUE if 'slotName' is the name of some registered
  // slot in the system.
  return (slotname->symbol_slot_offset != NULL_INTEGER);
}

Slot* lookup_slot(Class* renamed_Class, Symbol* slotname) {
  // Return a slot owned by the class 'class' with name 'slotName'.
  { Slot* cachedslot = ((Slot*)(renamed_Class->class_slot_and_method_cache->nth(slotname->symbol_slot_offset)));

    if ((cachedslot != NULL) &&
        (cachedslot->slot_name == slotname)) {
      return (cachedslot);
    }
    cachedslot = NULL;
    { Slot* slot = NULL;
      Iterator* iter_001 = renamed_Class->class_slots();

      while (iter_001->nextP()) {
        {
          slot = ((Slot*)(iter_001->value));
        }
        if (slot->slot_name == slotname) {
          cachedslot = slot;
          break;
        }
      }
    }
    if (cachedslot == NULL) {
      return (NULL);
    }
    { int newoffset = mod(oSYMBOL_SLOT_OFFSET_COUNTERo + 1, oSLOT_CACHE_SIZEo);

      oSYMBOL_SLOT_OFFSET_COUNTERo = newoffset;
      slotname->symbol_slot_offset = newoffset;
      renamed_Class->class_slot_and_method_cache->insert_at(newoffset, cachedslot);
      renamed_Class->class_slot_and_method_cache->insert_at(oSLOT_CACHE_SIZEo, cachedslot);
      return (cachedslot);
    }
  }
}

Slot* safe_lookup_slot(Class* renamed_Class, Symbol* slotname) {
  // Verify that at least one slot has the name 'slotName',
  // and then call 'lookup-slot'.
  slotname = slotname->soft_permanentify();
  return ((((slotname->symbol_slot_offset != NULL_INTEGER) &&
      (renamed_Class != NULL)) ? ((Slot*)(lookup_slot(renamed_Class, slotname))) : ((Slot*)(NULL))));
}

Slot* lookup_local_slot(Class* renamed_Class, Symbol* slotname) {
  // Lookup a local slot with 'slotName' on 'class'.
  { Slot* slot = NULL;
    Cons* iter_001 = renamed_Class->class_local_slots->the_cons_list;

    while (!nilP(iter_001)) {
      {
        slot = ((Slot*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (slot->slot_name == slotname) {
        return (slot);
      }
    }
  }
  return (NULL);
}

void clear_slot_and_method_cache(Class* renamed_Class) {
  if (((Slot*)(renamed_Class->class_slot_and_method_cache->nth(oSLOT_CACHE_SIZEo))) != NULL) {
    renamed_Class->class_slot_and_method_cache->clear();
  }
}

boolean dynamic_slotP(Storage_Slot* slot) {
  return (slot->allocation() == KWD_CLASSES_DYNAMIC);
}

void erase_dynamic_slot(Dynamic_Slots_Mixin* self, Symbol* slotname) {
  self->dynamic_slots->remove_at(slotname);
}

void resize_slot_caches(int size) {
  // Reset all slot caches to have size 'size'.
  oSLOT_CACHE_SIZEo = size;
  { Class* c = NULL;
    Iterator* iter_001 = all_classes(NULL, FALSE);

    while (iter_001->nextP()) {
      {
        c = ((Class*)(iter_001->value));
      }
      c->class_slot_and_method_cache = new_vector(size);
      { Slot* s = NULL;
        Cons* iter_002 = c->local_slots()->the_cons_list;

        while (!nilP(iter_002)) {
          {
            s = ((Slot*)(iter_002->value));
            iter_002 = iter_002->rest;
          }
          s->slot_name->symbol_slot_offset = 0;
        }
      }
    }
  }
}

Slot* get_slot(Standard_Object* self, Symbol* slotname) {
  // Return the slot named 'slotName' on the class
  // representing the type of 'self'.
  return (lookup_slot(self->primary_class(), slotname));
}

boolean conforming_type_specP(Standard_Object* subtypespec, Standard_Object* supertypespec) {
  return ((subtypespec == NULL) ||
      ((subtypespec == SGT_CLASSES_UNKNOWN) ||
       ((typeP(subtypespec) &&
      (((Class*)(((Surrogate*)(subtypespec))->surrogate_value)) == NULL)) ||
        (anchored_type_specifierP(subtypespec) ||
         ((supertypespec == NULL) ||
          ((supertypespec == SGT_CLASSES_UNKNOWN) ||
           ((typeP(supertypespec) &&
      (((Class*)(((Surrogate*)(supertypespec))->surrogate_value)) == NULL)) ||
            (anchored_type_specifierP(supertypespec) ||
             sub_type_spec_ofP(subtypespec, supertypespec)))))))));
}

boolean Slot::conforming_signaturesP(Slot* superslot) {
  { Slot* self = this;

    superslot = superslot;
    cerr << "conforming-signatures?: Not defined on " << "`" << self << "'";
    return (FALSE);
  }
}

boolean Storage_Slot::conforming_signaturesP(Slot* superslot) {
  { Storage_Slot* self = this;

    return (conforming_type_specP(self->slot_base_type, superslot->type()) &&
        (conforming_type_specP(((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_CLASSES_SLOT_TYPE_SPECIFIER, NULL))), ((Compound_Type_Specifier*)(dynamic_slot_value(superslot, SYM_CLASSES_SLOT_TYPE_SPECIFIER, NULL)))) &&
         (superslot->method_argument_count() == 1)));
  }
}

boolean Method_Slot::conforming_signaturesP(Slot* superslot) {
  { Method_Slot* self = this;

    if (conforming_type_specP(self->slot_base_type, superslot->type()) &&
        (conforming_type_specP(((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_CLASSES_SLOT_TYPE_SPECIFIER, NULL))), ((Compound_Type_Specifier*)(dynamic_slot_value(superslot, SYM_CLASSES_SLOT_TYPE_SPECIFIER, NULL)))) &&
         (self->method_argument_count() == superslot->method_argument_count()))) {
      { Slot* superslot_001 = superslot;

        if (storage_slotP(superslot)) {
          { Storage_Slot* superslot = NULL;

            superslot = ((Storage_Slot*)(superslot_001));
            return (self->method_return_type_specifiers_reader()->length() == 1);
          }
        }
        else if (method_slotP(superslot)) {
          { Method_Slot* superslot = NULL;

            superslot = ((Method_Slot*)(superslot_001));
            { boolean test_value_001 = FALSE;

              { boolean alwaysP_001 = TRUE;

                { Standard_Object* ts2 = NULL;
                  Standard_Object* ts1 = NULL;
                  Cons* iter_001 = self->method_parameter_type_specifiers_reader()->rest();
                  Cons* iter_002 = superslot->method_parameter_type_specifiers_reader()->rest();

                  while ((!nilP(iter_001)) &&
                      (!nilP(iter_002))) {
                    {
                      ts1 = ((Standard_Object*)(iter_001->value));
                      iter_001 = iter_001->rest;
                    }
                    {
                      ts2 = ((Standard_Object*)(iter_002->value));
                      iter_002 = iter_002->rest;
                    }
                    if (!conforming_type_specP(ts2, ts1)) {
                      alwaysP_001 = FALSE;
                      break;
                    }
                  }
                }
                test_value_001 = alwaysP_001;
              }
              if (test_value_001) {
                { boolean alwaysP_002 = TRUE;

                  { Standard_Object* ts2 = NULL;
                    Standard_Object* ts1 = NULL;
                    Cons* iter_003 = self->method_return_type_specifiers_reader()->the_cons_list;
                    Cons* iter_004 = superslot->method_return_type_specifiers_reader()->the_cons_list;

                    while ((!nilP(iter_003)) &&
                        (!nilP(iter_004))) {
                      {
                        ts1 = ((Standard_Object*)(iter_003->value));
                        iter_003 = iter_003->rest;
                      }
                      {
                        ts2 = ((Standard_Object*)(iter_004->value));
                        iter_004 = iter_004->rest;
                      }
                      if (!conforming_type_specP(ts1, ts2)) {
                        alwaysP_002 = FALSE;
                        break;
                      }
                    }
                  }
                  test_value_001 = alwaysP_002;
                }
              }
              { boolean value_001 = test_value_001;

                return (value_001);
              }
            }
          }
        }
        else {
        }
      }
    }
    return (FALSE);
  }
}

boolean Table::conforming_signaturesP(Slot* superslot) {
  { Table* self = this;

    if (conforming_type_specP(self->slot_base_type, superslot->type()) &&
        (conforming_type_specP(((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_CLASSES_SLOT_TYPE_SPECIFIER, NULL))), ((Compound_Type_Specifier*)(dynamic_slot_value(superslot, SYM_CLASSES_SLOT_TYPE_SPECIFIER, NULL)))) &&
         (self->method_argument_count() == superslot->method_argument_count()))) {
      { Slot* superslot_001 = superslot;

        if (taxonomy_isaP(superslot, SGT_CLASSES_TABLE)) {
          { Table* superslot = NULL;

            superslot = ((Table*)(superslot_001));
            { boolean alwaysP_001 = TRUE;

              { Standard_Object* ts2 = NULL;
                Standard_Object* ts1 = NULL;
                Cons* iter_001 = self->tuple_domains->rest();
                Cons* iter_002 = superslot->tuple_domains->rest();

                while ((!nilP(iter_001)) &&
                    (!nilP(iter_002))) {
                  {
                    ts1 = ((Standard_Object*)(iter_001->value));
                    iter_001 = iter_001->rest;
                  }
                  {
                    ts2 = ((Standard_Object*)(iter_002->value));
                    iter_002 = iter_002->rest;
                  }
                  if (!conforming_type_specP(ts2, ts1)) {
                    alwaysP_001 = FALSE;
                    break;
                  }
                }
              }
              { boolean value_001 = alwaysP_001;

                return (value_001);
              }
            }
          }
        }
        else {
        }
      }
    }
    return (FALSE);
  }
}

boolean identical_signaturesP(Method_Slot* method1, Method_Slot* method2) {
  { boolean test_value_001 = FALSE;

    { boolean alwaysP_001 = TRUE;

      { Standard_Object* ts2 = NULL;
        Standard_Object* ts1 = NULL;
        Cons* iter_001 = method1->method_parameter_type_specifiers_reader()->rest();
        Cons* iter_002 = method2->method_parameter_type_specifiers_reader()->rest();

        while ((!nilP(iter_001)) &&
            (!nilP(iter_002))) {
          {
            ts1 = ((Standard_Object*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          {
            ts2 = ((Standard_Object*)(iter_002->value));
            iter_002 = iter_002->rest;
          }
          if (!(sub_type_spec_ofP(ts1, ts2) &&
              sub_type_spec_ofP(ts2, ts1))) {
            alwaysP_001 = FALSE;
            break;
          }
        }
      }
      test_value_001 = alwaysP_001;
    }
    if (test_value_001) {
      { boolean alwaysP_002 = TRUE;

        { Standard_Object* ts2 = NULL;
          Standard_Object* ts1 = NULL;
          Cons* iter_003 = method1->method_return_type_specifiers_reader()->the_cons_list;
          Cons* iter_004 = method2->method_return_type_specifiers_reader()->the_cons_list;

          while ((!nilP(iter_003)) &&
              (!nilP(iter_004))) {
            {
              ts1 = ((Standard_Object*)(iter_003->value));
              iter_003 = iter_003->rest;
            }
            {
              ts2 = ((Standard_Object*)(iter_004->value));
              iter_004 = iter_004->rest;
            }
            if (!(sub_type_spec_ofP(ts1, ts2) &&
                sub_type_spec_ofP(ts2, ts1))) {
              alwaysP_002 = FALSE;
              break;
            }
          }
        }
        test_value_001 = alwaysP_002;
      }
    }
    { boolean value_001 = test_value_001;

      return (value_001);
    }
  }
}

void compute_required_slot_names(Class* renamed_Class) {
  { List* slotnames = new_list();

    { Slot* slot = NULL;
      Iterator* iter_001 = renamed_Class->class_slots();

      while (iter_001->nextP()) {
        {
          slot = ((Slot*)(iter_001->value));
        }
        if (storage_slotP(slot) &&
            (((Storage_Slot*)(slot))->slot_requiredP &&
             (!slotnames->memberP(slot->slot_name)))) {
          slotnames->push(slot->slot_name);
        }
      }
    }
    if (slotnames->emptyP()) {
      slotnames->free();
    }
    else {
      set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_REQUIRED_SLOT_NAMES, slotnames->reverse(), NULL);
    }
  }
}

void free_required_slot_names(Class* renamed_Class) {
  if (renamed_Class->class_required_slot_names_reader()->non_emptyP()) {
    renamed_Class->class_required_slot_names_reader()->free();
    set_dynamic_slot_value(renamed_Class, SYM_CLASSES_CLASS_REQUIRED_SLOT_NAMES, NULL, NULL);
  }
}

boolean Storage_Slot::dynamic_storageP() {
  { Storage_Slot* self = this;

    { Keyword* allocation = self->allocation();

      return ((allocation == KWD_CLASSES_DYNAMIC) ||
          (allocation == KWD_CLASSES_BIT));
    }
  }
}

boolean Relation::privateP() {
  // Return TRUE if 'self' is not public.
  { Relation* self = this;

    return (!self->publicP());
  }
}

boolean Slot::publicP() {
  // True if 'self' or one it its ancestors is marked public.
  { Slot* self = this;

    return (self->slot_publicP ||
        ((self->slot_direct_equivalent != NULL) &&
         self->slot_direct_equivalent->publicP()));
  }
}

Iterator* Class::public_slots() {
  // Return an iterator over public slots of 'self'.
  { Class* self = this;

    { Cons* publicslots = ((Cons*)(NIL));
      All_Purpose_Iterator* iterator = new_all_purpose_iterator();

      { Slot* slot = NULL;
        Iterator* iter_001 = self->class_slots();

        while (iter_001->nextP()) {
          {
            slot = ((Slot*)(iter_001->value));
          }
          { boolean test_value_001 = FALSE;

            test_value_001 = slot->slot_publicP;
            if (test_value_001) {
              { boolean foundP_001 = FALSE;

                { Slot* ps = NULL;
                  Cons* iter_002 = publicslots;

                  while (!nilP(iter_002)) {
                    {
                      ps = ((Slot*)(iter_002->value));
                      iter_002 = iter_002->rest;
                    }
                    if (ps->slot_name == slot->slot_name) {
                      foundP_001 = TRUE;
                      break;
                    }
                  }
                }
                test_value_001 = foundP_001;
              }
              test_value_001 = !test_value_001;
            }
            if (test_value_001) {
              publicslots = ((Cons*)(cons(slot, publicslots)));
            }
          }
        }
      }
      iterator->iterator_next_code = ((cpp_function_code)(&iterator_cons_list_nextP));
      iterator->iterator_cons_list = publicslots;
      iterator->first_iterationP = TRUE;
      return (iterator);
    }
  }
}

Iterator* Object::public_slots() {
  // Return an iterator over public slots of 'self'.
  { Object* self = this;

    return (self->primary_class()->public_slots());
  }
}

Iterator* Class::all_class_slots() {
  { Class* self = this;

    { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

      iterator->iterator_next_code = ((cpp_function_code)(&all_class_slots_nextP));
      iterator->iterator_object = NIL;
      iterator->iterator_cons_list = cons(self->class_type, NIL);
      iterator->first_iterationP = TRUE;
      return (iterator);
    }
  }
}

boolean all_class_slots_nextP(All_Purpose_Iterator* self) {
  { Cons* classes = self->iterator_cons_list;
    Class* renamed_Class = NULL;
    Cons* localslots = ((Cons*)(self->iterator_object));

    if (localslots->emptyP()) {
      while (classes->non_emptyP() &&
          localslots->emptyP()) {
        renamed_Class = type_to_class(((Surrogate*)(classes->first())));
        { Cons* headcons = classes;

          classes = classes->rest;
          headcons->free_cons();
        }
        localslots = renamed_Class->class_local_slots->the_cons_list;
        { Surrogate* super = NULL;
          Cons* iter_001 = renamed_Class->class_direct_supers->the_cons_list;

          while (!nilP(iter_001)) {
            {
              super = ((Surrogate*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            classes = cons(super, classes);
          }
        }
      }
      if (classes->emptyP()) {
        if (localslots->emptyP()) {
          self->value = NULL;
          self->iterator_object = NULL;
          return (FALSE);
        }
      }
      self->iterator_cons_list = classes;
      self->value = ((Slot*)(localslots->value));
      self->iterator_object = localslots->rest;
      return (TRUE);
    }
    else {
      self->value = ((Slot*)(localslots->value));
      self->iterator_object = localslots->rest;
      return (TRUE);
    }
  }
}

Iterator* Class::class_slots() {
  { Class* self = this;

    return (self->all_class_slots());
  }
}

List* Class::local_slots() {
  { Class* self = this;

    return (self->class_local_slots);
  }
}

Iterator* Class::direct_super_classes() {
  // Returns an iterator that generates all direct
  // super classes of 'self'.
  { Class* self = this;

    return (new_types_to_classes_iterator(self->class_direct_supers->the_cons_list));
  }
}

Iterator* Class::super_classes() {
  // Returns an iterator that generates all super classes
  // of 'self'.  Non-reflexive.
  { Class* self = this;

    { List_Iterator* iterator = new_list_iterator();

      iterator->list_iterator_cursor = self->class_all_super_classes;
      return (iterator);
    }
  }
}

boolean Slot::activeP() {
  { Slot* slot = this;

    return (((slot->stored_activeP_reader() != NULL_BOOLEAN) ? ((boolean)(slot->stored_activeP_reader())) : ((boolean)((((Class*)(SGT_CLASSES_COLLECTION->surrogate_value)) != NULL) &&
        ((((Class*)(slot->slot_base_type->surrogate_value)) != NULL) &&
         ((((Class*)(slot->slot_owner->surrogate_value)) != NULL) &&
          (slot->primitiveP() &&
           ((((Symbol*)(dynamic_slot_value(slot, SYM_CLASSES_SLOT_INVERSE, NULL))) != NULL) ||
            ((slot->slot_direct_equivalent != NULL) &&
             slot->slot_direct_equivalent->activeP())))))))));
  }
}

Object* Storage_Slot::initial_value() {
  // Return an initial value for 'self', or NULL.  The
  // initial value can be defined by the slot itself, inherited from an
  // equivalent slot, or inherit from the :initial-value option for the 
  // class representing the type of 'self'.
  { Storage_Slot* self = this;

    { Storage_Slot* slot = self;
      Object* value = dynamic_slot_value(slot, SYM_CLASSES_SLOT_INITIAL_VALUE, NULL);

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        slot = ((Storage_Slot*)(slot->slot_direct_equivalent));
        if (slot != NULL) {
          value = dynamic_slot_value(slot, SYM_CLASSES_SLOT_INITIAL_VALUE, NULL);
        }
        else {
          break;
        }
      }
      return (dynamic_slot_value(((Class*)(self->type()->surrogate_value)), SYM_CLASSES_CLASS_INITIAL_VALUE, NULL));
    }
  }
}

Object* Slot::system_default_value() {
  // Return a default value expression, or if 'self'
  // has dynamic storage, an initial value expression.
  { Slot* self = this;

    return (dynamic_slot_value(((Class*)(self->type()->surrogate_value)), SYM_CLASSES_CLASS_INITIAL_VALUE, NULL));
  }
}

Object* Storage_Slot::system_default_value() {
  // Return a default value expression, or if 'self'
  // has dynamic storage, an initial value expression.
  { Storage_Slot* self = this;

    { Object* value = self->default_form();

      if (value != NULL) {
        return (value);
      }
      else if (self->dynamic_storageP() &&
          (((Class*)(self->type()->surrogate_value)) != NULL)) {
        return (dynamic_slot_value(((Class*)(self->type()->surrogate_value)), SYM_CLASSES_CLASS_INITIAL_VALUE, NULL));
      }
      else {
        return (NULL);
      }
    }
  }
}

Object* Storage_Slot::initially() {
  // Defines the value of a slot before it has been assigned
  // a value.
  { Storage_Slot* self = this;

    { Object* value = dynamic_slot_value(self, SYM_CLASSES_SLOT_INITIAL_VALUE, NULL);

      if (value != NULL) {
        return (value);
      }
      else if (self->slot_direct_equivalent != NULL) {
        return (((Storage_Slot*)(self->slot_direct_equivalent))->initially());
      }
      else if (self->slot_base_type == SGT_CLASSES_BOOLEAN) {
        return (permanentify_form(SYM_CLASSES_FALSE));
      }
      else {
        return (NULL);
      }
    }
  }
}

void repair_slots() {
  { Class* top = ((Class*)(SGT_CLASSES_OBJECT->surrogate_value));

    unfinalize_class_slots(top);
    finalize_classes_and_slots();
  }
}

void disconnect_classes() {
  { Surrogate* surrogate = NULL;
    Iterator* iter_001 = all_surrogates(oMODULEo, FALSE);

    while (iter_001->nextP()) {
      {
        surrogate = ((Surrogate*)(iter_001->value));
      }
      if ((surrogate->surrogate_value != NULL) &&
          classP(surrogate->surrogate_value)) {
        surrogate->surrogate_value = NULL;
      }
    }
  }
}

boolean filter_unbound_surrogateP(Surrogate* self, All_Purpose_Iterator* iterator) {
  iterator = iterator;
  return (!(self->surrogate_value != NULL));
}

Iterator* unbound_surrogates(Module* module, boolean localP) {
  // Iterate over all unbound surrogates visible from 'module'.
  // Look at all modules if 'module' is NULL.  If 'local?', only consider
  // surrogates interned in 'module'.
  { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

    iterator->iterator_nested_iterator = all_surrogates(module, localP);
    iterator->iterator_next_code = ((cpp_function_code)(&filtered_nested_iterator_nextP));
    iterator->iterator_filter_code = ((cpp_function_code)(&filter_unbound_surrogateP));
    return (iterator);
  }
}

char* name_to_string(Object* name) {
  // Return the string represented by 'name'.  Return NULL
  // if 'name' is undefined or does not represent a string.
  if (name != NULL) {
    { Object* name_001 = name;

      if (taxonomy_isaP(name, SGT_CLASSES_GENERALIZED_SYMBOL)) {
        { Generalized_Symbol* name = NULL;

          name = ((Generalized_Symbol*)(name_001));
          return (name->symbol_name);
        }
      }
      else if (stringP(name)) {
        { String_Wrapper* name = NULL;

          name = ((String_Wrapper*)(name_001));
          return (name->wrapper_value);
        }
      }
      else {
      }
    }
  }
  return (NULL);
}

void print_unbound_surrogates(Cons* args) {
  // Print all unbound surrogates visible from the module named by the first
  // argument (a symbol or string).  Look at all modules if no module name or
  // NULL was supplied.  If the second argument is TRUE, only consider
  // surrogates interned in the specified module.
  { char* name = name_to_string(args->first());
    Module* module = ((name != NULL) ? ((Module*)(string_get_module(name, TRUE))) : ((Module*)(NULL)));
    boolean localP = FALSE;

    if (args->second() == SYM_CLASSES_TRUE) {
      localP = TRUE;
    }
    { Surrogate* surrogate = NULL;
      Iterator* iter_001 = unbound_surrogates(module, localP);

      while (iter_001->nextP()) {
        {
          surrogate = ((Surrogate*)(iter_001->value));
        }
        cout << surrogate << endl;
      }
    }
  }
}

void print_unbound_surrogates_evaluator_wrapper(Cons* arguments) {
  print_unbound_surrogates(((Cons*)(arguments)));
}

boolean root_classP(Class* renamed_Class) {
  return (renamed_Class->class_direct_supers->emptyP() &&
      (!renamed_Class->mixinP));
}

void clear_class_taxonomy() {
  { Class* renamed_Class = NULL;
    Iterator* iter_001 = all_classes(NULL, FALSE);

    while (iter_001->nextP()) {
      {
        renamed_Class = ((Class*)(iter_001->value));
      }
      renamed_Class->class_taxonomy_node = NULL;
    }
  }
}

void help_create_class_taxonomy(Class* renamed_Class, Class* parent) {
  { Taxonomy_Node* mynode = renamed_Class->class_taxonomy_node;
    Taxonomy_Node* parentnode = NULL;

    if (parent != NULL) {
      if (parent->class_taxonomy_node == NULL) {
        cerr << "`help-create-class-taxonomy': parent should have taxonomy-node";
      }
      parentnode = parent->class_taxonomy_node;
    }
    if (mynode == NULL) {
      renamed_Class->class_taxonomy_node = create_and_intern_node(oCLASS_TAXONOMY_GRAPHo, parentnode, renamed_Class);
    }
    else {
      link_nodes(oCLASS_TAXONOMY_GRAPHo, parent->class_taxonomy_node, mynode);
    }
    { Surrogate* child = NULL;
      Cons* iter_001 = renamed_Class->class_direct_subs->the_cons_list;

      while (!nilP(iter_001)) {
        {
          child = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        help_create_class_taxonomy(((Class*)(child->surrogate_value)), renamed_Class);
      }
    }
  }
}

void create_class_taxonomy() {
  oCLASS_TAXONOMY_GRAPHo = new_taxonomy_graph();
  clear_class_taxonomy();
  { Class* renamed_Class = NULL;
    Iterator* iter_001 = all_classes(NULL, FALSE);

    while (iter_001->nextP()) {
      {
        renamed_Class = ((Class*)(iter_001->value));
      }
      if (root_classP(renamed_Class) ||
          renamed_Class->mixinP) {
        help_create_class_taxonomy(renamed_Class, NULL);
      }
    }
  }
  create_spanning_forest(oCLASS_TAXONOMY_GRAPHo);
}

boolean taxonomy_subclass_ofP(Class* subclass, Class* superclass) {
  if (subclass == superclass) {
    return (TRUE);
  }
  { Taxonomy_Node* subnode = subclass->class_taxonomy_node;
    Taxonomy_Node* supernode = superclass->class_taxonomy_node;
    int sublabel = NULL_INTEGER;

    if ((subnode == NULL) ||
        (supernode == NULL)) {
      return (subclass->class_all_super_classes->membP(superclass));
    }
    sublabel = subnode->label;
    if ((sublabel >= supernode->first_interval_lower_bound) &&
        (sublabel <= supernode->first_interval_upper_bound)) {
      return (TRUE);
    }
    { Interval* interval = NULL;
      Cons* iter_001 = supernode->intervals;

      while (!nilP(iter_001)) {
        {
          interval = ((Interval*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if ((sublabel >= interval->lower_bound) &&
            (sublabel <= interval->upper_bound)) {
          return (TRUE);
        }
      }
    }
    return (FALSE);
  }
}

boolean fast_taxonomy_subclass_ofP(Class* subclass, Class* superclass) {
  { Taxonomy_Node* subnode = subclass->class_taxonomy_node;
    Taxonomy_Node* supernode = superclass->class_taxonomy_node;
    int sublabel = subnode->label;

    if ((sublabel >= supernode->first_interval_lower_bound) &&
        (sublabel <= supernode->first_interval_upper_bound)) {
      return (TRUE);
    }
    else {
      if (supernode->intervals == NIL) {
        return (FALSE);
      }
      else {
        { boolean foundP_001 = FALSE;

          { Interval* interval = NULL;
            Cons* iter_001 = supernode->intervals;

            while (!nilP(iter_001)) {
              {
                interval = ((Interval*)(iter_001->value));
                iter_001 = iter_001->rest;
              }
              if ((sublabel >= interval->lower_bound) &&
                  (sublabel <= interval->upper_bound)) {
                foundP_001 = TRUE;
                break;
              }
            }
          }
          { boolean value_001 = foundP_001;

            return (value_001);
          }
        }
      }
    }
  }
}

boolean taxonomy_isaP(Object* object, Surrogate* type) {
  // Return TRUE iff 'object' is an instance of the class named
  // 'type'.  Assumes a fast class interval test can be used.
  return (taxonomy_subclass_ofP(((Class*)(object->primary_type()->surrogate_value)), ((Class*)(type->surrogate_value))));
}

Surrogate* intern_slotref(char* classname, char* slotname) {
  return (intern_surrogate(string_concatenate(classname, string_concatenate(".", slotname))));
}

Surrogate* lookup_slotref(Surrogate* self, Symbol* slotname) {
  self = ((Surrogate*)(real_type_specifier(self)));
  { Class* renamed_Class = ((Class*)(self->surrogate_value));
    Slot* slot = NULL;
    Surrogate* slotref = NULL;

    slot = slotname->lookup_function();
    if (slot != NULL) {
      self = SGT_CLASSES_ANY;
    }
    if (slot == NULL) {
      slot = safe_lookup_slot(renamed_Class, slotname);
    }
    if (slot == NULL) {
      if (renamed_Class != NULL) {
        return (NULL);
      }
    }
    else {
      self = slot->slot_owner;
      slotref = slot->slot_slotref;
    }
    if (slotref == NULL) {
      { Module* old_OmoduleO_001 = oMODULEo;
        Context* old_OcontextO_001 = oCONTEXTo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oMODULEo = ((slot != NULL) ? ((Module*)(slot->home_module())) : ((Module*)(((Module*)(((Symbol*)(slotname->permanentify()))->home_context)))));
              oCONTEXTo = oMODULEo;
              slotref = intern_slotref(self->symbol_name, slotname->symbol_name);
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
      slotref->surrogate_value = slot;
      if (slot != NULL) {
        slot->slot_slotref = slotref;
      }
    }
    return (slotref);
  }
}

boolean slot_surrogateP(Surrogate* self) {
  return (string_position(self->symbol_name, '.', 0) != NULL_INTEGER);
}

Surrogate* slotref_type(Surrogate* slotref) {
  return (((Slot*)(slotref->surrogate_value))->type());
}

void startup_classes() {
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
            SGT_CLASSES_CLASS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CLASS", NULL, 1)));
            SYM_CLASSES_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            SYM_CLASSES_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", NULL, 0)));
            KWD_CLASSES_PARAMETERS = ((Keyword*)(intern_rigid_symbol_wrt_module("PARAMETERS", NULL, 2)));
            SYM_CLASSES_SLOT_TYPE_SPECIFIER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-TYPE-SPECIFIER", NULL, 0)));
            KWD_CLASSES_PUBLICp = ((Keyword*)(intern_rigid_symbol_wrt_module("PUBLIC?", NULL, 2)));
            KWD_CLASSES_REQUIREDp = ((Keyword*)(intern_rigid_symbol_wrt_module("REQUIRED?", NULL, 2)));
            KWD_CLASSES_COMPONENTp = ((Keyword*)(intern_rigid_symbol_wrt_module("COMPONENT?", NULL, 2)));
            KWD_CLASSES_READ_ONLYp = ((Keyword*)(intern_rigid_symbol_wrt_module("READ-ONLY?", NULL, 2)));
            KWD_CLASSES_ACTIVEp = ((Keyword*)(intern_rigid_symbol_wrt_module("ACTIVE?", NULL, 2)));
            SYM_CLASSES_STORED_ACTIVEp = ((Symbol*)(intern_rigid_symbol_wrt_module("STORED-ACTIVE?", NULL, 0)));
            KWD_CLASSES_CONTEXT_SENSITIVEp = ((Keyword*)(intern_rigid_symbol_wrt_module("CONTEXT-SENSITIVE?", NULL, 2)));
            KWD_CLASSES_HARDWIREDp = ((Keyword*)(intern_rigid_symbol_wrt_module("HARDWIRED?", NULL, 2)));
            KWD_CLASSES_ABSTRACTp = ((Keyword*)(intern_rigid_symbol_wrt_module("ABSTRACT?", NULL, 2)));
            KWD_CLASSES_ALLOCATION = ((Keyword*)(intern_rigid_symbol_wrt_module("ALLOCATION", NULL, 2)));
            KWD_CLASSES_CLASS = ((Keyword*)(intern_rigid_symbol_wrt_module("CLASS", NULL, 2)));
            SYM_CLASSES_SLOT_ALLOCATION = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-ALLOCATION", NULL, 0)));
            KWD_CLASSES_INITIALLY = ((Keyword*)(intern_rigid_symbol_wrt_module("INITIALLY", NULL, 2)));
            SYM_CLASSES_SLOT_INITIAL_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-INITIAL-VALUE", NULL, 0)));
            KWD_CLASSES_DEFAULT = ((Keyword*)(intern_rigid_symbol_wrt_module("DEFAULT", NULL, 2)));
            SYM_CLASSES_SLOT_DEFAULT_EXPRESSION = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-DEFAULT-EXPRESSION", NULL, 0)));
            KWD_CLASSES_READER = ((Keyword*)(intern_rigid_symbol_wrt_module("READER", NULL, 2)));
            SYM_CLASSES_SLOT_READER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-READER", NULL, 0)));
            KWD_CLASSES_WRITER = ((Keyword*)(intern_rigid_symbol_wrt_module("WRITER", NULL, 2)));
            SYM_CLASSES_SLOT_WRITER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-WRITER", NULL, 0)));
            KWD_CLASSES_INVERSE = ((Keyword*)(intern_rigid_symbol_wrt_module("INVERSE", NULL, 2)));
            SYM_CLASSES_SLOT_INVERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-INVERSE", NULL, 0)));
            KWD_CLASSES_RENAMES = ((Keyword*)(intern_rigid_symbol_wrt_module("RENAMES", NULL, 2)));
            SYM_CLASSES_SLOT_RENAMES = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-RENAMES", NULL, 0)));
            KWD_CLASSES_DOCUMENTATION = ((Keyword*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 2)));
            SYM_CLASSES_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 0)));
            KWD_CLASSES_PROPERTIES = ((Keyword*)(intern_rigid_symbol_wrt_module("PROPERTIES", NULL, 2)));
            SYM_CLASSES_PROPERTIES = ((Symbol*)(intern_rigid_symbol_wrt_module("PROPERTIES", NULL, 0)));
            KWD_CLASSES_META_ATTRIBUTES = ((Keyword*)(intern_rigid_symbol_wrt_module("META-ATTRIBUTES", NULL, 2)));
            SYM_CLASSES_META_ATTRIBUTES = ((Symbol*)(intern_rigid_symbol_wrt_module("META-ATTRIBUTES", NULL, 0)));
            KWD_CLASSES_OPTION_KEYWORD = ((Keyword*)(intern_rigid_symbol_wrt_module("OPTION-KEYWORD", NULL, 2)));
            SYM_CLASSES_SLOT_OPTION_KEYWORD = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-OPTION-KEYWORD", NULL, 0)));
            KWD_CLASSES_OPTION_HANDLER = ((Keyword*)(intern_rigid_symbol_wrt_module("OPTION-HANDLER", NULL, 2)));
            SYM_CLASSES_SLOT_OPTION_HANDLER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-OPTION-HANDLER", NULL, 0)));
            SGT_CLASSES_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", NULL, 1)));
            KWD_CLASSES_BIT = ((Keyword*)(intern_rigid_symbol_wrt_module("BIT", NULL, 2)));
            KWD_CLASSES_CL_NATIVE_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("CL-NATIVE-TYPE", NULL, 2)));
            SYM_CLASSES_CLASS_CL_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CL-NATIVE-TYPE", NULL, 0)));
            KWD_CLASSES_CPP_NATIVE_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("CPP-NATIVE-TYPE", NULL, 2)));
            SYM_CLASSES_CLASS_CPP_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CPP-NATIVE-TYPE", NULL, 0)));
            KWD_CLASSES_IDL_NATIVE_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("IDL-NATIVE-TYPE", NULL, 2)));
            SYM_CLASSES_CLASS_IDL_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-IDL-NATIVE-TYPE", NULL, 0)));
            KWD_CLASSES_JAVA_NATIVE_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("JAVA-NATIVE-TYPE", NULL, 2)));
            SYM_CLASSES_CLASS_JAVA_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-JAVA-NATIVE-TYPE", NULL, 0)));
            KWD_CLASSES_CL_STRUCTp = ((Keyword*)(intern_rigid_symbol_wrt_module("CL-STRUCT?", NULL, 2)));
            KWD_CLASSES_MIXINp = ((Keyword*)(intern_rigid_symbol_wrt_module("MIXIN?", NULL, 2)));
            KWD_CLASSES_RECYCLE_METHOD = ((Keyword*)(intern_rigid_symbol_wrt_module("RECYCLE-METHOD", NULL, 2)));
            SYM_CLASSES_CLASS_RECYCLE_METHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-RECYCLE-METHOD", NULL, 0)));
            KWD_CLASSES_EXTENSION = ((Keyword*)(intern_rigid_symbol_wrt_module("EXTENSION", NULL, 2)));
            SYM_CLASSES_CLASS_EXTENSION_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-EXTENSION-NAME", NULL, 0)));
            KWD_CLASSES_CREATOR = ((Keyword*)(intern_rigid_symbol_wrt_module("CREATOR", NULL, 2)));
            SYM_CLASSES_CLASS_CREATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CREATOR", NULL, 0)));
            KWD_CLASSES_INITIALIZER = ((Keyword*)(intern_rigid_symbol_wrt_module("INITIALIZER", NULL, 2)));
            SYM_CLASSES_CLASS_INITIALIZER = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-INITIALIZER", NULL, 0)));
            KWD_CLASSES_TERMINATOR = ((Keyword*)(intern_rigid_symbol_wrt_module("TERMINATOR", NULL, 2)));
            SYM_CLASSES_CLASS_TERMINATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-TERMINATOR", NULL, 0)));
            KWD_CLASSES_DESTRUCTOR = ((Keyword*)(intern_rigid_symbol_wrt_module("DESTRUCTOR", NULL, 2)));
            SYM_CLASSES_CLASS_DESTRUCTOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-DESTRUCTOR", NULL, 0)));
            KWD_CLASSES_INITIAL_VALUE = ((Keyword*)(intern_rigid_symbol_wrt_module("INITIAL-VALUE", NULL, 2)));
            SYM_CLASSES_CLASS_INITIAL_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-INITIAL-VALUE", NULL, 0)));
            KWD_CLASSES_PRINT_FORM = ((Keyword*)(intern_rigid_symbol_wrt_module("PRINT-FORM", NULL, 2)));
            SYM_CLASSES_PRINT_FORM = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-FORM", NULL, 0)));
            KWD_CLASSES_EQUALITY_TEST = ((Keyword*)(intern_rigid_symbol_wrt_module("EQUALITY-TEST", NULL, 2)));
            KWD_CLASSES_KEY = ((Keyword*)(intern_rigid_symbol_wrt_module("KEY", NULL, 2)));
            SYM_CLASSES_CLASS_KEY = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-KEY", NULL, 0)));
            SYM_CLASSES_CLASS_PARAMETERS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-PARAMETERS", NULL, 0)));
            KWD_CLASSES_SYNONYMS = ((Keyword*)(intern_rigid_symbol_wrt_module("SYNONYMS", NULL, 2)));
            SYM_CLASSES_CLASS_SYNONYMS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-SYNONYMS", NULL, 0)));
            KWD_CLASSES_CHILDREN = ((Keyword*)(intern_rigid_symbol_wrt_module("CHILDREN", NULL, 2)));
            SGT_CLASSES_METHOD_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("METHOD-SLOT", NULL, 1)));
            SYM_CLASSES_SLOT_GUARD_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-GUARD-DEMONS", NULL, 0)));
            SYM_CLASSES_SLOT_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-DEMONS", NULL, 0)));
            SYM_CLASSES_CLASS_CONSTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CONSTRUCTOR-DEMONS", NULL, 0)));
            SYM_CLASSES_CLASS_GUARD_CONSTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-GUARD-CONSTRUCTOR-DEMONS", NULL, 0)));
            SYM_CLASSES_CLASS_DESTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-DESTRUCTOR-DEMONS", NULL, 0)));
            SYM_CLASSES_CLASS_GUARD_DESTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-GUARD-DESTRUCTOR-DEMONS", NULL, 0)));
            SGT_CLASSES_ACTIVE_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("ACTIVE-OBJECT", NULL, 1)));
            SGT_CLASSES_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("OBJECT", NULL, 1)));
            SGT_CLASSES_STANDARD_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("STANDARD-OBJECT", NULL, 1)));
            SYM_CLASSES_PRIMARY_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("PRIMARY-TYPE", NULL, 0)));
            SYM_CLASSES_SELF = ((Symbol*)(intern_rigid_symbol_wrt_module("SELF", NULL, 0)));
            KWD_CLASSES_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("TYPE", NULL, 2)));
            SYM_CLASSES_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPE", NULL, 0)));
            KWD_CLASSES_AUXILIARYp = ((Keyword*)(intern_rigid_symbol_wrt_module("AUXILIARY?", NULL, 2)));
            SYM_CLASSES_RETURN = ((Symbol*)(intern_rigid_symbol_wrt_module("RETURN", NULL, 0)));
            SYM_CLASSES_CLASS_EXTENSION = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-EXTENSION", NULL, 0)));
            SGT_CLASSES_SET = ((Surrogate*)(intern_rigid_symbol_wrt_module("SET", NULL, 1)));
            SGT_CLASSES_ACTIVE_SET = ((Surrogate*)(intern_rigid_symbol_wrt_module("ACTIVE-SET", NULL, 1)));
            SGT_CLASSES_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("LIST", NULL, 1)));
            SGT_CLASSES_ACTIVE_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("ACTIVE-LIST", NULL, 1)));
            SGT_CLASSES_UNKNOWN = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNKNOWN", NULL, 1)));
            SGT_CLASSES_COLLECTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION", NULL, 1)));
            SGT_CLASSES_SET_MIXIN = ((Surrogate*)(intern_rigid_symbol_wrt_module("SET-MIXIN", NULL, 1)));
            SYM_CLASSES_INVERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("INVERSE", NULL, 0)));
            SGT_CLASSES_DYNAMIC_SLOTS_MIXIN = ((Surrogate*)(intern_rigid_symbol_wrt_module("DYNAMIC-SLOTS-MIXIN", NULL, 1)));
            KWD_CLASSES_INSTANCE = ((Keyword*)(intern_rigid_symbol_wrt_module("INSTANCE", NULL, 2)));
            SGT_CLASSES_CONTEXT_SENSITIVE_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONTEXT-SENSITIVE-OBJECT", NULL, 1)));
            SGT_CLASSES_VOID = ((Surrogate*)(intern_rigid_symbol_wrt_module("VOID", NULL, 1)));
            KWD_CLASSES_DYNAMIC = ((Keyword*)(intern_rigid_symbol_wrt_module("DYNAMIC", NULL, 2)));
            SGT_CLASSES_TABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TABLE", NULL, 1)));
            SYM_CLASSES_CLASS_REQUIRED_SLOT_NAMES = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-REQUIRED-SLOT-NAMES", NULL, 0)));
            SGT_CLASSES_GENERALIZED_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("GENERALIZED-SYMBOL", NULL, 1)));
            SYM_CLASSES_EVALUATOR_WRAPPER_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("EVALUATOR-WRAPPER-CODE", NULL, 0)));
            SYM_CLASSES_ANY = ((Symbol*)(intern_rigid_symbol_wrt_module("ANY", NULL, 0)));
            SGT_CLASSES_ANY = ((Surrogate*)(intern_rigid_symbol_wrt_module("ANY", NULL, 1)));
          }
          if (current_startup_time_phaseP(4)) {
            oUNFINALIZED_CLASSESo = new_list();
            oCLASSES_WITH_UNRESOLVED_CHILDREN_REFERENCESo = new_list();
          }
          if (current_startup_time_phaseP(5)) {
            define_stella_type_from_stringified_source("(DEFTYPE ANY UNKNOWN)");
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("CLASS-NAME", "CLASS", "(DEFUN (CLASS-NAME STRING) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&class_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-SYMBOL", "CLASS", "(DEFUN (CLASS-SYMBOL SYMBOL) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&class_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("TYPE-TO-SYMBOL", "TYPE", "(DEFUN (TYPE-TO-SYMBOL SYMBOL) ((TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&type_to_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRIMARY-CLASS", "OBJECT", "(DEFMETHOD (PRIMARY-CLASS CLASS) ((SELF OBJECT)))");

              method->method_code = ((cpp_method_code)(&Object::primary_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-CLASS", "STRING", "(DEFMETHOD (LOOKUP-CLASS CLASS) ((NAME STRING)) :DOCUMENTATION \"Return a class with name 'name'.  Scan all\nvisible surrogates looking for one that has a class defined for it.\")");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-CLASS", "SYMBOL", "(DEFMETHOD (LOOKUP-CLASS CLASS) ((NAME SYMBOL)) :DOCUMENTATION \"Return a class with name 'name'.  Scan all\nvisible surrogates looking for one that has a class defined for it.\")");

              method->method_code = ((cpp_method_code)(&Symbol::lookup_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("TYPE-TO-CLASS", "TYPE", "(DEFUN (TYPE-TO-CLASS CLASS) ((TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&type_to_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-CLASS", "SURROGATE", "(DEFMETHOD (GET-CLASS CLASS) ((CLASSNAME TYPE) (ERROR? BOOLEAN)) :DOCUMENTATION \"Return a class with name 'className'.  If none exists, break\nif 'error?', else return NULL.\")");

              method->method_code = ((cpp_method_code)(&Surrogate::get_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-CLASS", "STRING", "(DEFMETHOD (GET-CLASS CLASS) ((CLASSNAME STRING) (ERROR? BOOLEAN)) :DOCUMENTATION \"Return a class with name 'className'.  If none exists, break\nif 'error?', else return NULL.\")");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-CLASS", "SYMBOL", "(DEFMETHOD (GET-CLASS CLASS) ((CLASSNAME SYMBOL) (ERROR? BOOLEAN)) :DOCUMENTATION \"Return a class with name 'className'.  If non exists, break\nif 'error?', else return NULL.\")");

              method->method_code = ((cpp_method_code)(&Symbol::get_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("BIND-TO-SURROGATE?", "OBJECT", "(DEFUN (BIND-TO-SURROGATE? BOOLEAN OBJECT SURROGATE) ((SELF OBJECT) (NAME STRING) (CLIPOLDVALUE? BOOLEAN) (WARNONFAILURE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&bind_to_surrogateP));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNBIND-FROM-SURROGATE", "CLASS", "(DEFMETHOD UNBIND-FROM-SURROGATE ((SELF CLASS)))");

              method->method_code = ((cpp_method_code)(&Class::unbind_from_surrogate));
            }
            { Method_Slot* method = define_method_from_stringified_source("SHADOW-SYMBOL", "STRING", "(DEFUN (SHADOW-SYMBOL SYMBOL) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&shadow_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("SHADOW-SURROGATE", "STRING", "(DEFUN (SHADOW-SURROGATE SURROGATE) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&shadow_surrogate));
            }
            { Method_Slot* method = define_method_from_stringified_source("BIND-TO-INDEXICAL?", "OBJECT", "(DEFUN (BIND-TO-INDEXICAL? BOOLEAN OBJECT) ((SELF OBJECT) (NAME STRING) (CLIPOLDVALUE? BOOLEAN) (WARNONFAILURE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&bind_to_indexicalP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SHADOW-INDEXICAL", "STRING", "(DEFUN (SHADOW-INDEXICAL INDEXICAL) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&shadow_indexical));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-CONSTRUCTOR", "CLASS", "(DEFUN (GET-CONSTRUCTOR FUNCTION-CODE) ((CLASS CLASS) (WARN? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&get_constructor));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-OBJECT", "TYPE", "(DEFUN (CREATE-OBJECT OBJECT) ((TYPE TYPE) |&REST| (ALTERNATINGSYMBOLSANDVALUES OBJECT)) :DOCUMENTATION \"Flexible, user-friendly version of 'new'.\nReturn an instance of the class named with type 'type'.\nFill in values using 'alternatingKeywordsAndValues' and call the\ninitialization function, if one exists. Any arguments required by 'new'\nfor this type must be included.  'create' runs more slowly than 'new'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&create_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE", "OBJECT", "(DEFMETHOD FREE ((SELF OBJECT)) :DOCUMENTATION \"Default method.  Deallocate storage for 'self'.\")");

              method->method_code = ((cpp_method_code)(&Object::free));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE", "ACTIVE-OBJECT", "(DEFMETHOD FREE ((SELF ACTIVE-OBJECT)) :DOCUMENTATION \"Remove all pointers between 'self' and other objects,\nand then deallocate the storage for self.\")");

              method->method_code = ((cpp_method_code)(&Active_Object::free));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYMBOL-TO-WRAPPED-BOOLEAN", "OBJECT", "(DEFUN (SYMBOL-TO-WRAPPED-BOOLEAN BOOLEAN-WRAPPER) ((OBJECT OBJECT)))");

              method->function_code = ((cpp_function_code)(&symbol_to_wrapped_boolean));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-STELLA-CLASS", "TYPE", "(DEFUN (DEFINE-STELLA-CLASS CLASS) ((NAME TYPE) (SUPERS (LIST OF TYPE)) (SLOTS (LIST OF SLOT)) (OPTIONS KEYWORD-KEY-VALUE-LIST)) :DOCUMENTATION \"Return a Stella class with name 'name'.\nCaution:  If the class already exists, the Stella class object gets\nredefined, but the native C++ class is not redefined.\")");

              method->function_code = ((cpp_function_code)(&define_stella_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-STELLA-SLOT", "SYMBOL", "(DEFUN (DEFINE-STELLA-SLOT SLOT) ((NAME SYMBOL) (OWNER TYPE) (BASETYPE TYPE) (TYPESPECIFIER CONS) (OPTIONS KEYWORD-KEY-VALUE-LIST)))");

              method->function_code = ((cpp_function_code)(&define_stella_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("INCORPORATE-CLASS-OPTIONS", "CLASS", "(DEFUN INCORPORATE-CLASS-OPTIONS ((CLASS CLASS) (OPTIONS KEYWORD-KEY-VALUE-LIST)))");

              method->function_code = ((cpp_function_code)(&incorporate_class_options));
            }
            { Method_Slot* method = define_method_from_stringified_source("INLINE-METHOD?", "SLOT", "(DEFUN (INLINE-METHOD? BOOLEAN) ((SLOT SLOT)))");

              method->function_code = ((cpp_function_code)(&inline_methodP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSFER-EXTERNAL-SLOT-TO-NEW-CLASS", "SLOT", "(DEFUN TRANSFER-EXTERNAL-SLOT-TO-NEW-CLASS ((EXTERNALSLOT SLOT) (NEWCLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&transfer_external_slot_to_new_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSFER-DEMONS-FROM-OLDCLASS", "CLASS", "(DEFUN TRANSFER-DEMONS-FROM-OLDCLASS ((OLDCLASS CLASS) (NEWCLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&transfer_demons_from_oldclass));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNDEFINE-OLD-CLASS", "CLASS", "(DEFUN UNDEFINE-OLD-CLASS ((OLDCLASS CLASS) (NEWCLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&undefine_old_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-CLASS", "CLASS", "(DEFMETHOD DESTROY-CLASS ((SELF CLASS)) :DOCUMENTATION \"Destroy the Stella class 'self'.  \nUnfinalize its subclasses (if it has any).\")");

              method->method_code = ((cpp_method_code)(&Class::destroy_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-CLASS", "SURROGATE", "(DEFMETHOD DESTROY-CLASS ((SELF TYPE)))");

              method->method_code = ((cpp_method_code)(&Surrogate::destroy_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-CLASS-AND-SUBCLASSES", "CLASS", "(DEFUN DESTROY-CLASS-AND-SUBCLASSES ((SELF CLASS)) :DOCUMENTATION \"Destroy the Stella class 'self' and all its subclasses.\")");

              method->function_code = ((cpp_function_code)(&destroy_class_and_subclasses));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRIMITIVE?", "RELATION", "(DEFMETHOD (PRIMITIVE? BOOLEAN) ((SELF RELATION)) :DOCUMENTATION \"Return TRUE if 'self' is not a defined relation.\")");

              method->method_code = ((cpp_method_code)(&Relation::primitiveP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT-PRIMITIVE-SUPER", "TYPE", "(DEFUN INSERT-PRIMITIVE-SUPER ((NEWSUPER TYPE) (SUPERS (LIST OF TYPE))))");

              method->function_code = ((cpp_function_code)(&insert_primitive_super));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-MOST-SPECIFIC-PRIMITIVE-SUPERS", "CLASS", "(DEFUN COLLECT-MOST-SPECIFIC-PRIMITIVE-SUPERS ((CLASS CLASS) (SUPERS (LIST OF TYPE))))");

              method->function_code = ((cpp_function_code)(&collect_most_specific_primitive_supers));
            }
            { Method_Slot* method = define_method_from_stringified_source("MOST-SPECIFIC-PRIMITIVE-SUPERS", "CLASS", "(DEFUN (MOST-SPECIFIC-PRIMITIVE-SUPERS (LIST OF TYPE)) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&most_specific_primitive_supers));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-NATIVE-SUPERS", "CLASS", "(DEFUN (CLASS-NATIVE-SUPERS (ITERATOR OF TYPE)) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&class_native_supers));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMEMBER-UNFINALIZED-CLASS", "CLASS", "(DEFUN REMEMBER-UNFINALIZED-CLASS ((CLASS CLASS) (FORCE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&remember_unfinalized_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("FORGET-UNFINALIZED-CLASS", "CLASS", "(DEFUN FORGET-UNFINALIZED-CLASS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&forget_unfinalized_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-CLASSES", NULL, "(DEFUN FINALIZE-CLASSES () :DOCUMENTATION \"Finalize all currently unfinalized classes.\")");

              method->function_code = ((cpp_function_code)(&finalize_classes));
            }
            { Method_Slot* method = define_method_from_stringified_source("RESOLVE-CHILDREN-REFERENCES", NULL, "(DEFUN RESOLVE-CHILDREN-REFERENCES ())");

              method->function_code = ((cpp_function_code)(&resolve_children_references));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-SLOTS", NULL, "(DEFUN FINALIZE-SLOTS () :DOCUMENTATION \"Finalize all currently unfinalized slots.\")");

              method->function_code = ((cpp_function_code)(&finalize_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEANUP-UNFINALIZED-CLASSES", NULL, "(DEFUN CLEANUP-UNFINALIZED-CLASSES () :DOCUMENTATION \"Remove all finalized classes from '*unfinalized-classes*',\nand set '*newly-unfinalized-classes?*' to FALSE.\")");

              method->function_code = ((cpp_function_code)(&cleanup_unfinalized_classes));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-CLASSES-AND-SLOTS", NULL, "(DEFUN FINALIZE-CLASSES-AND-SLOTS () :DOCUMENTATION \"Finalize all currently unfinalized classes and slots.\")");

              method->function_code = ((cpp_function_code)(&finalize_classes_and_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("ACTIVATE-CLASS", "CLASS", "(DEFUN ACTIVATE-CLASS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&activate_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-PRIMARY-TYPE", "CLASS", "(DEFUN ADD-PRIMARY-TYPE ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&add_primary_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-ONE-CLASS", "CLASS", "(DEFUN FINALIZE-ONE-CLASS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&finalize_one_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-CLASS", "CLASS", "(DEFUN (FINALIZE-CLASS BOOLEAN) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&finalize_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-FINALIZE-CLASS", "CLASS", "(DEFUN (HELP-FINALIZE-CLASS BOOLEAN) ((CLASS CLASS) (FINALIZEDPARENT TYPE)))");

              method->function_code = ((cpp_function_code)(&help_finalize_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNFINALIZE-CLASS-AND-SUBCLASSES", "CLASS", "(DEFUN UNFINALIZE-CLASS-AND-SUBCLASSES ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&unfinalize_class_and_subclasses));
            }
            { Method_Slot* method = define_method_from_stringified_source("ATTACH-SLOT-TO-OWNER", "SLOT", "(DEFUN (ATTACH-SLOT-TO-OWNER SLOT) ((NEWSLOT SLOT)))");

              method->function_code = ((cpp_function_code)(&attach_slot_to_owner));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-SLOT-DIRECT-EQUIVALENT", "SLOT", "(DEFUN COMPUTE-SLOT-DIRECT-EQUIVALENT ((SELF SLOT)))");

              method->function_code = ((cpp_function_code)(&compute_slot_direct_equivalent));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHECK-CONFORMANCE-OF-SLOT-SIGNATURE", "SLOT", "(DEFUN CHECK-CONFORMANCE-OF-SLOT-SIGNATURE ((SELF SLOT)))");

              method->function_code = ((cpp_function_code)(&check_conformance_of_slot_signature));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECTION-TO-ACTIVE-COLLECTION", "TYPE", "(DEFUN (COLLECTION-TO-ACTIVE-COLLECTION TYPE) ((TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&collection_to_active_collection));
            }
            { Method_Slot* method = define_method_from_stringified_source("ACTIVATE-SLOT", "STORAGE-SLOT", "(DEFUN ACTIVATE-SLOT ((SELF STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&activate_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-SLOT-TYPE-COMPUTATIONS", "SLOT", "(DEFMETHOD FINALIZE-SLOT-TYPE-COMPUTATIONS ((SELF SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::finalize_slot_type_computations));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-SLOT-TYPE-COMPUTATIONS", "STORAGE-SLOT", "(DEFMETHOD FINALIZE-SLOT-TYPE-COMPUTATIONS ((SELF STORAGE-SLOT)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::finalize_slot_type_computations));
            }
            { Method_Slot* method = define_method_from_stringified_source("MULTI-VALUED-SLOT-WITH-DUPLICATES?", "SLOT", "(DEFUN (MULTI-VALUED-SLOT-WITH-DUPLICATES? BOOLEAN) ((SELF SLOT)))");

              method->function_code = ((cpp_function_code)(&multi_valued_slot_with_duplicatesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-SLOT-INVERSES", "SLOT", "(DEFUN COMPUTE-SLOT-INVERSES ((SELF SLOT)))");

              method->function_code = ((cpp_function_code)(&compute_slot_inverses));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-FINALIZE-LOCAL-SLOT", "SLOT", "(DEFMETHOD HELP-FINALIZE-LOCAL-SLOT ((SELF SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::help_finalize_local_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-FINALIZE-LOCAL-SLOT", "STORAGE-SLOT", "(DEFMETHOD HELP-FINALIZE-LOCAL-SLOT ((SELF STORAGE-SLOT)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::help_finalize_local_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-LOCAL-SLOT", "SLOT", "(DEFUN FINALIZE-LOCAL-SLOT ((SELF SLOT)))");

              method->function_code = ((cpp_function_code)(&finalize_local_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNFINALIZE-LOCAL-SLOT", "SLOT", "(DEFMETHOD UNFINALIZE-LOCAL-SLOT ((SELF SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::unfinalize_local_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNFINALIZE-LOCAL-SLOT", "STORAGE-SLOT", "(DEFMETHOD UNFINALIZE-LOCAL-SLOT ((SELF STORAGE-SLOT)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::unfinalize_local_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-CLASS-SLOTS", "CLASS", "(DEFUN FINALIZE-CLASS-SLOTS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&finalize_class_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNFINALIZE-CLASS-SLOTS", "CLASS", "(DEFUN UNFINALIZE-CLASS-SLOTS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&unfinalize_class_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-UNFINALIZE-CLASS-SLOTS", "CLASS", "(DEFUN HELP-UNFINALIZE-CLASS-SLOTS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&help_unfinalize_class_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("MULTIPLE-PARENTS?", "CLASS", "(DEFMETHOD (MULTIPLE-PARENTS? BOOLEAN) ((CLASS CLASS)) :DOCUMENTATION \"Return TRUE if 'class' has more than one direct superclass.\")");

              method->method_code = ((cpp_method_code)(&Class::multiple_parentsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-DIRECT-SUPERS-BACK-LINKS", "CLASS", "(DEFUN ADD-DIRECT-SUPERS-BACK-LINKS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&add_direct_supers_back_links));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-DIRECT-SUBS-BACK-LINKS", "CLASS", "(DEFUN ADD-DIRECT-SUBS-BACK-LINKS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&add_direct_subs_back_links));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-DIRECT-SUPERS-BACK-LINKS", "CLASS", "(DEFUN REMOVE-DIRECT-SUPERS-BACK-LINKS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&remove_direct_supers_back_links));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-DIRECT-SUPER-CLASSES", "CLASS", "(DEFUN COLLECT-DIRECT-SUPER-CLASSES ((CLASS CLASS) (PARENTS (LIST OF CLASS))))");

              method->function_code = ((cpp_function_code)(&collect_direct_super_classes));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-SUPERCLASSES", "CLASS", "(DEFUN INHERIT-SUPERCLASSES ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&inherit_superclasses));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNINHERIT-SUPERCLASSES", "CLASS", "(DEFUN UNINHERIT-SUPERCLASSES ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&uninherit_superclasses));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBCLASS-OF?", "CLASS", "(DEFUN (SUBCLASS-OF? BOOLEAN) ((SUBCLASS CLASS) (SUPERCLASS CLASS)) :DOCUMENTATION \"Return TRUE iff the class named 'subClass' is a subclass of the\nclass named 'superClass'.\")");

              method->function_code = ((cpp_function_code)(&subclass_ofP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBTYPE-OF?", "TYPE", "(DEFUN (SUBTYPE-OF? BOOLEAN) ((SUBTYPE TYPE) (SUPERTYPE TYPE)) :DOCUMENTATION \"Return TRUE iff the class named 'subType' is a subclass \nof the class named 'superType'.\")");

              method->function_code = ((cpp_function_code)(&subtype_ofP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ISA?", "OBJECT", "(DEFUN (ISA? BOOLEAN) ((OBJECT OBJECT) (TYPE TYPE)) :DOCUMENTATION \"Return TRUE iff 'object' is an instance of the class named\n'type'.\")");

              method->function_code = ((cpp_function_code)(&isaP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TWO-ARGUMENT-LEAST-COMMON-SUPERCLASS", "CLASS", "(DEFUN (TWO-ARGUMENT-LEAST-COMMON-SUPERCLASS CLASS) ((CLASS1 CLASS) (CLASS2 CLASS)) :DOCUMENTATION \"Return the most specific class that is a superclass of\nboth 'class1' and 'class2'.  If there is more than one, arbitrarily pick one.\nIf there is none, return NULL.\")");

              method->function_code = ((cpp_function_code)(&two_argument_least_common_superclass));
            }
            { Method_Slot* method = define_method_from_stringified_source("TWO-ARGUMENT-LEAST-COMMON-SUPERTYPE", "TYPE", "(DEFUN (TWO-ARGUMENT-LEAST-COMMON-SUPERTYPE TYPE) ((TYPE1 TYPE) (TYPE2 TYPE)) :DOCUMENTATION \"Return the most specific type that is a supertype of\nboth 'type1' and 'type2'.  If there is more than one, arbitrarily pick one.\nIf there is none, return @VOID.\")");

              method->function_code = ((cpp_function_code)(&two_argument_least_common_supertype));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-SLOTS", "CLASS", "(DEFUN INHERIT-SLOTS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&inherit_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOCAL-SLOT?", "SLOT", "(DEFUN (LOCAL-SLOT? BOOLEAN) ((SLOT SLOT) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&local_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNINHERIT-SLOTS", "CLASS", "(DEFUN UNINHERIT-SLOTS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&uninherit_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-SLOT-AND-METHOD-CACHE", "CLASS", "(DEFUN INITIALIZE-SLOT-AND-METHOD-CACHE ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&initialize_slot_and_method_cache));
            }
            { Method_Slot* method = define_method_from_stringified_source("REGISTER-SLOT-NAME", "SLOT", "(DEFUN REGISTER-SLOT-NAME ((SLOT SLOT)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Register the name symbol of 'slot' as a slot name, and\ninitialize its 'symbol-slot-offset' so that it can be used by 'lookup-slot'.\")");

              method->function_code = ((cpp_function_code)(&register_slot_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNREGISTER-SLOT-NAME", "SLOT", "(DEFUN UNREGISTER-SLOT-NAME ((SLOT SLOT)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Unregister the name symbol of 'slot' as a slot name,\nso that it can no longer be used by 'lookup-slot'.\")");

              method->function_code = ((cpp_function_code)(&unregister_slot_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("REGISTERED-SLOT-NAME?", "SYMBOL", "(DEFUN (REGISTERED-SLOT-NAME? BOOLEAN) ((SLOTNAME SYMBOL)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if 'slotName' is the name of some registered\nslot in the system.\")");

              method->function_code = ((cpp_function_code)(&registered_slot_nameP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-SLOT", "CLASS", "(DEFUN (LOOKUP-SLOT SLOT) ((CLASS CLASS) (SLOTNAME SYMBOL)) :DOCUMENTATION \"Return a slot owned by the class 'class' with name 'slotName'.\")");

              method->function_code = ((cpp_function_code)(&lookup_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("SAFE-LOOKUP-SLOT", "CLASS", "(DEFUN (SAFE-LOOKUP-SLOT SLOT) ((CLASS CLASS) (SLOTNAME SYMBOL)) :DOCUMENTATION \"Verify that at least one slot has the name 'slotName',\nand then call 'lookup-slot'.\")");

              method->function_code = ((cpp_function_code)(&safe_lookup_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-LOCAL-SLOT", "CLASS", "(DEFUN (LOOKUP-LOCAL-SLOT SLOT) ((CLASS CLASS) (SLOTNAME SYMBOL)) :DOCUMENTATION \"Lookup a local slot with 'slotName' on 'class'.\")");

              method->function_code = ((cpp_function_code)(&lookup_local_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-SLOT-AND-METHOD-CACHE", "CLASS", "(DEFUN CLEAR-SLOT-AND-METHOD-CACHE ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&clear_slot_and_method_cache));
            }
            { Method_Slot* method = define_method_from_stringified_source("DYNAMIC-SLOT?", "STORAGE-SLOT", "(DEFUN (DYNAMIC-SLOT? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&dynamic_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ERASE-DYNAMIC-SLOT", "DYNAMIC-SLOTS-MIXIN", "(DEFUN ERASE-DYNAMIC-SLOT ((SELF DYNAMIC-SLOTS-MIXIN) (SLOTNAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&erase_dynamic_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("RESIZE-SLOT-CACHES", "INTEGER", "(DEFUN RESIZE-SLOT-CACHES ((SIZE INTEGER)) :DOCUMENTATION \"Reset all slot caches to have size 'size'.\")");

              method->function_code = ((cpp_function_code)(&resize_slot_caches));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-SLOT", "STANDARD-OBJECT", "(DEFUN (GET-SLOT SLOT) ((SELF STANDARD-OBJECT) (SLOTNAME SYMBOL)) :DOCUMENTATION \"Return the slot named 'slotName' on the class\nrepresenting the type of 'self'.\")");

              method->function_code = ((cpp_function_code)(&get_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONFORMING-TYPE-SPEC?", "TYPE-SPEC", "(DEFUN (CONFORMING-TYPE-SPEC? BOOLEAN) ((SUBTYPESPEC TYPE-SPEC) (SUPERTYPESPEC TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&conforming_type_specP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONFORMING-SIGNATURES?", "SLOT", "(DEFMETHOD (CONFORMING-SIGNATURES? BOOLEAN) ((SELF SLOT) (SUPERSLOT SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::conforming_signaturesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONFORMING-SIGNATURES?", "STORAGE-SLOT", "(DEFMETHOD (CONFORMING-SIGNATURES? BOOLEAN) ((SELF STORAGE-SLOT) (SUPERSLOT SLOT)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::conforming_signaturesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONFORMING-SIGNATURES?", "METHOD-SLOT", "(DEFMETHOD (CONFORMING-SIGNATURES? BOOLEAN) ((SELF METHOD-SLOT) (SUPERSLOT SLOT)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::conforming_signaturesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONFORMING-SIGNATURES?", "TABLE", "(DEFMETHOD (CONFORMING-SIGNATURES? BOOLEAN) ((SELF TABLE) (SUPERSLOT SLOT)))");

              method->method_code = ((cpp_method_code)(&Table::conforming_signaturesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("IDENTICAL-SIGNATURES?", "METHOD-SLOT", "(DEFUN (IDENTICAL-SIGNATURES? BOOLEAN) ((METHOD1 METHOD-SLOT) (METHOD2 METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&identical_signaturesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-REQUIRED-SLOT-NAMES", "CLASS", "(DEFUN COMPUTE-REQUIRED-SLOT-NAMES ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&compute_required_slot_names));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-REQUIRED-SLOT-NAMES", "CLASS", "(DEFUN FREE-REQUIRED-SLOT-NAMES ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&free_required_slot_names));
            }
            { Method_Slot* method = define_method_from_stringified_source("DYNAMIC-STORAGE?", "STORAGE-SLOT", "(DEFMETHOD (DYNAMIC-STORAGE? BOOLEAN) ((SELF STORAGE-SLOT)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::dynamic_storageP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRIVATE?", "RELATION", "(DEFMETHOD (PRIVATE? BOOLEAN) ((SELF RELATION)) :DOCUMENTATION \"Return TRUE if 'self' is not public.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Relation::privateP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUBLIC?", "SLOT", "(DEFMETHOD (PUBLIC? BOOLEAN) ((SELF SLOT)) :DOCUMENTATION \"True if 'self' or one it its ancestors is marked public.\")");

              method->method_code = ((cpp_method_code)(&Slot::publicP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUBLIC-SLOTS", "CLASS", "(DEFMETHOD (PUBLIC-SLOTS (ITERATOR OF SLOT)) ((SELF CLASS)) :DOCUMENTATION \"Return an iterator over public slots of 'self'.\")");

              method->method_code = ((cpp_method_code)(&Class::public_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUBLIC-SLOTS", "OBJECT", "(DEFMETHOD (PUBLIC-SLOTS (ITERATOR OF SLOT)) ((SELF OBJECT)) :DOCUMENTATION \"Return an iterator over public slots of 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Object::public_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-CLASS-SLOTS", "CLASS", "(DEFMETHOD (ALL-CLASS-SLOTS (ITERATOR OF SLOT)) ((SELF CLASS)))");

              method->method_code = ((cpp_method_code)(&Class::all_class_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-CLASS-SLOTS-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ALL-CLASS-SLOTS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&all_class_slots_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-SLOTS", "CLASS", "(DEFMETHOD (CLASS-SLOTS (ITERATOR OF SLOT)) ((SELF CLASS)))");

              method->method_code = ((cpp_method_code)(&Class::class_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOCAL-SLOTS", "CLASS", "(DEFMETHOD (LOCAL-SLOTS (LIST OF SLOT)) ((SELF CLASS)))");

              method->method_code = ((cpp_method_code)(&Class::local_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("DIRECT-SUPER-CLASSES", "CLASS", "(DEFMETHOD (DIRECT-SUPER-CLASSES (ITERATOR OF CLASS)) ((SELF CLASS)) :PUBLIC? TRUE :DOCUMENTATION \"Returns an iterator that generates all direct\nsuper classes of 'self'.\")");

              method->method_code = ((cpp_method_code)(&Class::direct_super_classes));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUPER-CLASSES", "CLASS", "(DEFMETHOD (SUPER-CLASSES (ITERATOR OF CLASS)) ((SELF CLASS)) :PUBLIC? TRUE :DOCUMENTATION \"Returns an iterator that generates all super classes\nof 'self'.  Non-reflexive.\")");

              method->method_code = ((cpp_method_code)(&Class::super_classes));
            }
            { Method_Slot* method = define_method_from_stringified_source("ACTIVE?", "SLOT", "(DEFMETHOD (ACTIVE? BOOLEAN) ((SLOT SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::activeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIAL-VALUE", "STORAGE-SLOT", "(DEFMETHOD (INITIAL-VALUE OBJECT) ((SELF STORAGE-SLOT)) :DOCUMENTATION \"Return an initial value for 'self', or NULL.  The\ninitial value can be defined by the slot itself, inherited from an\nequivalent slot, or inherit from the :initial-value option for the \nclass representing the type of 'self'.\")");

              method->method_code = ((cpp_method_code)(&Storage_Slot::initial_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYSTEM-DEFAULT-VALUE", "SLOT", "(DEFMETHOD (SYSTEM-DEFAULT-VALUE OBJECT) ((SELF SLOT)) :DOCUMENTATION \"Return a default value expression, or if 'self'\nhas dynamic storage, an initial value expression.\")");

              method->method_code = ((cpp_method_code)(&Slot::system_default_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYSTEM-DEFAULT-VALUE", "STORAGE-SLOT", "(DEFMETHOD (SYSTEM-DEFAULT-VALUE OBJECT) ((SELF STORAGE-SLOT)) :DOCUMENTATION \"Return a default value expression, or if 'self'\nhas dynamic storage, an initial value expression.\")");

              method->method_code = ((cpp_method_code)(&Storage_Slot::system_default_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALLY", "STORAGE-SLOT", "(DEFMETHOD (INITIALLY OBJECT) ((SELF STORAGE-SLOT)) :DOCUMENTATION \"Defines the value of a slot before it has been assigned\na value.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Storage_Slot::initially));
            }
            { Method_Slot* method = define_method_from_stringified_source("REPAIR-SLOTS", NULL, "(DEFUN REPAIR-SLOTS ())");

              method->function_code = ((cpp_function_code)(&repair_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("DISCONNECT-CLASSES", NULL, "(DEFUN DISCONNECT-CLASSES ())");

              method->function_code = ((cpp_function_code)(&disconnect_classes));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-UNBOUND-SURROGATE?", "SURROGATE", "(DEFUN (FILTER-UNBOUND-SURROGATE? BOOLEAN) ((SELF SURROGATE) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_unbound_surrogateP));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNBOUND-SURROGATES", "MODULE", "(DEFUN (UNBOUND-SURROGATES (ITERATOR OF SURROGATE)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :PUBLIC? TRUE :DOCUMENTATION \"Iterate over all unbound surrogates visible from 'module'.\nLook at all modules if 'module' is NULL.  If 'local?', only consider\nsurrogates interned in 'module'.\")");

              method->function_code = ((cpp_function_code)(&unbound_surrogates));
            }
            { Method_Slot* method = define_method_from_stringified_source("NAME-TO-STRING", "OBJECT", "(DEFUN (NAME-TO-STRING STRING) ((NAME OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the string represented by 'name'.  Return NULL\nif 'name' is undefined or does not represent a string.\")");

              method->function_code = ((cpp_function_code)(&name_to_string));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-UNBOUND-SURROGATES", "ARGUMENT-LIST", "(DEFUN PRINT-UNBOUND-SURROGATES (|&REST| (ARGS OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Print all unbound surrogates visible from the module named by the first\nargument (a symbol or string).  Look at all modules if no module name or\nNULL was supplied.  If the second argument is TRUE, only consider\nsurrogates interned in the specified module.\")");

              method->function_code = ((cpp_function_code)(&print_unbound_surrogates));
              set_dynamic_slot_value(method, SYM_CLASSES_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&print_unbound_surrogates_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("ROOT-CLASS?", "CLASS", "(DEFUN (ROOT-CLASS? BOOLEAN) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&root_classP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-CLASS-TAXONOMY", NULL, "(DEFUN CLEAR-CLASS-TAXONOMY ())");

              method->function_code = ((cpp_function_code)(&clear_class_taxonomy));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-CREATE-CLASS-TAXONOMY", "CLASS", "(DEFUN HELP-CREATE-CLASS-TAXONOMY ((CLASS CLASS) (PARENT CLASS)))");

              method->function_code = ((cpp_function_code)(&help_create_class_taxonomy));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-CLASS-TAXONOMY", NULL, "(DEFUN CREATE-CLASS-TAXONOMY ())");

              method->function_code = ((cpp_function_code)(&create_class_taxonomy));
            }
            { Method_Slot* method = define_method_from_stringified_source("TAXONOMY-SUBCLASS-OF?", "CLASS", "(DEFUN (TAXONOMY-SUBCLASS-OF? BOOLEAN) ((SUBCLASS CLASS) (SUPERCLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&taxonomy_subclass_ofP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FAST-TAXONOMY-SUBCLASS-OF?", "CLASS", "(DEFUN (FAST-TAXONOMY-SUBCLASS-OF? BOOLEAN) ((SUBCLASS CLASS) (SUPERCLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&fast_taxonomy_subclass_ofP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TAXONOMY-ISA?", "OBJECT", "(DEFUN (TAXONOMY-ISA? BOOLEAN) ((OBJECT OBJECT) (TYPE TYPE)) :DOCUMENTATION \"Return TRUE iff 'object' is an instance of the class named\n'type'.  Assumes a fast class interval test can be used.\")");

              method->function_code = ((cpp_function_code)(&taxonomy_isaP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-SLOTREF", "STRING", "(DEFUN (INTERN-SLOTREF SLOTREF) ((CLASSNAME STRING) (SLOTNAME STRING)))");

              method->function_code = ((cpp_function_code)(&intern_slotref));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-SLOTREF", "TYPE", "(DEFUN (LOOKUP-SLOTREF SLOTREF) ((SELF TYPE) (SLOTNAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&lookup_slotref));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOT-SURROGATE?", "SURROGATE", "(DEFUN (SLOT-SURROGATE? BOOLEAN) ((SELF SURROGATE)))");

              method->function_code = ((cpp_function_code)(&slot_surrogateP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOTREF-TYPE", "SLOTREF", "(DEFUN (SLOTREF-TYPE TYPE) ((SLOTREF SLOTREF)))");

              method->function_code = ((cpp_function_code)(&slotref_type));
            }
            define_method_from_stringified_source("STARTUP-CLASSES", NULL, "(DEFUN STARTUP-CLASSES ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *WARN-IF-REDEFINE?* BOOLEAN TRUE :DOCUMENTATION \"If set, warn about each redefinition.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *UNFINALIZED-CLASSES* (LIST OF CLASS) (NEW LIST) :DOCUMENTATION \"List of classes whose class or slot inheritance is\ncurrently unfinalized.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *NEWLY-UNFINALIZED-CLASSES?* BOOLEAN FALSE :DOCUMENTATION \"Set to TRUE by 'remember-unfinalized-class'; set\nto FALSE by 'cleanup-unfinalized-classes'.  Minimizes the time that\n'finalize-classes' spends searching for classes to finalize.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CLASSES-WITH-UNRESOLVED-CHILDREN-REFERENCES* (LIST OF CLASS) (NEW LIST) :DOCUMENTATION \"List of classes defined with a :children option\nwhich still have some of their children references unresolved.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *SYMBOL-SLOT-OFFSET-COUNTER* INTEGER 0)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *SLOT-CACHE-SIZE* INTEGER 20)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CLASS-TAXONOMY-GRAPH* TAXONOMY-GRAPH NULL)");
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

