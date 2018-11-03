// symbols.cc

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

Extensible_Symbol_Array* oSYMBOL_ARRAYo = NULL;

Symbol* SYM_SYMBOLS_oSYMBOL_ARRAYo = NULL;

Extensible_Symbol_Array* oSURROGATE_ARRAYo = NULL;

Symbol* SYM_SYMBOLS_oSURROGATE_ARRAYo = NULL;

Extensible_Symbol_Array* oKEYWORD_ARRAYo = NULL;

Symbol* SYM_SYMBOLS_oKEYWORD_ARRAYo = NULL;

Extensible_Symbol_Array* oINDEXICAL_ARRAYo = NULL;

Symbol* SYM_SYMBOLS_oINDEXICAL_ARRAYo = NULL;

String_To_Integer_Hash_Table* oKEYWORD_OFFSET_TABLEo = NULL;

Symbol* SYM_SYMBOLS_oKEYWORD_OFFSET_TABLEo = NULL;

Extensible_Symbol_Array* oFIXED_SYMBOL_ARRAYo = NULL;

Symbol* SYM_SYMBOLS_oFIXED_SYMBOL_ARRAYo = NULL;

Extensible_Symbol_Array* oFIXED_SURROGATE_ARRAYo = NULL;

Symbol* SYM_SYMBOLS_oFIXED_SURROGATE_ARRAYo = NULL;

Extensible_Symbol_Array* oFIXED_KEYWORD_ARRAYo = NULL;

Symbol* SYM_SYMBOLS_oFIXED_KEYWORD_ARRAYo = NULL;

Extensible_Symbol_Array* oFIXED_INDEXICAL_ARRAYo = NULL;

Symbol* SYM_SYMBOLS_oFIXED_INDEXICAL_ARRAYo = NULL;

String_Hash_Table* oTRANSIENT_SYMBOL_LOOKUP_TABLEo = NULL;

String_Hash_Table* oCOMMON_LISP_SYMBOL_LOOKUP_TABLEo = NULL;

String_Hash_Table* oTRANSIENT_KEYWORD_LOOKUP_TABLEo = NULL;

int SYMBOL_SYM = 0;

int SURROGATE_SYM = 1;

int KEYWORD_SYM = 2;

int INDEXICAL_SYM = 3;

Module* oROOT_MODULEo = NULL;

Module* oSTELLA_MODULEo = NULL;

Module* oCOMMON_LISP_MODULEo = NULL;

Module* oALTERNATE_STELLA_MODULEo = NULL;

Context* oCONTEXTo = NULL;

Symbol* SYM_SYMBOLS_oCONTEXTo = NULL;

Module* oMODULEo = NULL;

Symbol* SYM_SYMBOLS_oMODULEo = NULL;

char SURROGATE_PREFIX_CHARACTER = '@';

char MODULE_SEPARATOR_CHARACTER = '/';

char* MODULE_SEPARATOR_STRING = "/";

int oCONTEXT_NUMBER_COUNTERo = -2;

int oGENSYM_COUNTERo = 0;

char ESCAPE_CHARACTER = '!';

Keyword* KWD_SYMBOLS_OTHER = NULL;

Keyword* KWD_SYMBOLS_DIGIT = NULL;

Keyword* KWD_SYMBOLS_LETTER = NULL;

Keyword* KWD_SYMBOLS_SYMBOL_CONSTITUENT = NULL;

Keyword* KWD_SYMBOLS_SYMBOL_QUALIFIER = NULL;

Keyword* KWD_SYMBOLS_ESCAPE = NULL;

Keyword* KWD_SYMBOLS_OPEN_DELIMITER = NULL;

Keyword* KWD_SYMBOLS_CLOSE_DELIMITER = NULL;

Keyword* KWD_SYMBOLS_PAIRED_DELIMITER = NULL;

Keyword* KWD_SYMBOLS_WHITE_SPACE = NULL;

Vector* oCHARACTER_TYPE_TABLEo = NULL;

int oINITIAL_SYMBOL_ARRAY_SIZEo = 100;

Symbol* SYM_SYMBOLS_NAME = NULL;

Symbol* SYM_SYMBOLS_SYMBOL_ARRAY = NULL;

Symbol* SYM_SYMBOLS_SURROGATE_ARRAY = NULL;

Symbol* SYM_SYMBOLS_KEYWORD_ARRAY = NULL;

Symbol* SYM_SYMBOLS_KEYWORD_OFFSET_TABLE = NULL;

Symbol* SYM_SYMBOLS_INDEXICAL_ARRAY = NULL;

Symbol* SYM_SYMBOLS_CARDINAL_MODULES = NULL;

Symbol* SYM_SYMBOLS_CURRENT_CONTEXT = NULL;

Surrogate* SGT_SYMBOLS_SYMBOL_PROCESSING_ENVIRONMENT = NULL;

Symbol_Processing_Environment* oSYMBOL_PROCESSING_ENVIRONMENTo = NULL;

Symbol_Processing_Environment* oSTELLA_TRANSLATION_ENVIRONMENTo = NULL;

int next_free_offset(Extensible_Symbol_Array* self) {
  { int topoffset = self->top_symbol_offset;
    int freeoffset = topoffset + 1;

    { int i = NULL_INTEGER;
      int iter_001 = self->potential_free_symbol_offset;
      int upper_bound_001 = topoffset;
      boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

      while (unboundedP_001 ||
          (iter_001 <= upper_bound_001)) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        if (self->nth(i) == NULL) {
          freeoffset = i;
          break;
        }
      }
    }
    self->potential_free_symbol_offset = freeoffset + 1;
    return (freeoffset);
  }
}

void free_symbol_offset(Extensible_Symbol_Array* self, int offset) {
  self->nth_setter(NULL, offset);
  if (offset < self->potential_free_symbol_offset) {
    self->potential_free_symbol_offset = offset;
  }
}

void add_to_symbol_array_at(Extensible_Symbol_Array* array, int offset, Generalized_Symbol* symbol) {
  array->insert_at(offset, symbol);
  symbol->symbol_id = offset;
}

int add_to_symbol_array(Extensible_Symbol_Array* array, Generalized_Symbol* symbol) {
  { int offset = next_free_offset(array);

    add_to_symbol_array_at(array, offset, symbol);
    return (offset);
  }
}

boolean legal_symbol_array_offsetP(Extensible_Symbol_Array* array, int offset) {
  return (offset <= array->top_symbol_offset);
}

Extensible_Symbol_Array* read_Osymbol_arrayO() {
  return (oSYMBOL_ARRAYo);
}

Extensible_Symbol_Array* write_Osymbol_arrayO(Extensible_Symbol_Array* value) {
  oSYMBOL_ARRAYo = value;
  return (value);
}

Extensible_Symbol_Array* read_Osurrogate_arrayO() {
  return (oSURROGATE_ARRAYo);
}

Extensible_Symbol_Array* write_Osurrogate_arrayO(Extensible_Symbol_Array* value) {
  oSURROGATE_ARRAYo = value;
  return (value);
}

Extensible_Symbol_Array* read_Okeyword_arrayO() {
  return (oKEYWORD_ARRAYo);
}

Extensible_Symbol_Array* write_Okeyword_arrayO(Extensible_Symbol_Array* value) {
  oKEYWORD_ARRAYo = value;
  return (value);
}

Extensible_Symbol_Array* read_Oindexical_arrayO() {
  return (oINDEXICAL_ARRAYo);
}

Extensible_Symbol_Array* write_Oindexical_arrayO(Extensible_Symbol_Array* value) {
  oINDEXICAL_ARRAYo = value;
  return (value);
}

String_To_Integer_Hash_Table* read_Okeyword_offset_tableO() {
  return (oKEYWORD_OFFSET_TABLEo);
}

String_To_Integer_Hash_Table* write_Okeyword_offset_tableO(String_To_Integer_Hash_Table* value) {
  oKEYWORD_OFFSET_TABLEo = value;
  return (value);
}

Extensible_Symbol_Array* read_Ofixed_symbol_arrayO() {
  return (oFIXED_SYMBOL_ARRAYo);
}

Extensible_Symbol_Array* write_Ofixed_symbol_arrayO(Extensible_Symbol_Array* value) {
  oFIXED_SYMBOL_ARRAYo = value;
  return (value);
}

Extensible_Symbol_Array* read_Ofixed_surrogate_arrayO() {
  return (oFIXED_SURROGATE_ARRAYo);
}

Extensible_Symbol_Array* write_Ofixed_surrogate_arrayO(Extensible_Symbol_Array* value) {
  oFIXED_SURROGATE_ARRAYo = value;
  return (value);
}

Extensible_Symbol_Array* read_Ofixed_keyword_arrayO() {
  return (oFIXED_KEYWORD_ARRAYo);
}

Extensible_Symbol_Array* write_Ofixed_keyword_arrayO(Extensible_Symbol_Array* value) {
  oFIXED_KEYWORD_ARRAYo = value;
  return (value);
}

Extensible_Symbol_Array* read_Ofixed_indexical_arrayO() {
  return (oFIXED_INDEXICAL_ARRAYo);
}

Extensible_Symbol_Array* write_Ofixed_indexical_arrayO(Extensible_Symbol_Array* value) {
  oFIXED_INDEXICAL_ARRAYo = value;
  return (value);
}

Context* read_OcontextO() {
  return (oCONTEXTo);
}

Context* write_OcontextO(Context* value) {
  oCONTEXTo = value;
  return (value);
}

Module* read_OmoduleO() {
  return (oMODULEo);
}

Module* write_OmoduleO(Module* value) {
  oMODULEo = value;
  return (value);
}

Symbol* get_sym(int offset) {
  return (((Symbol*)(oFIXED_SYMBOL_ARRAYo->nth(offset))));
}

Surrogate* get_sgt(int offset) {
  return (((Surrogate*)(oFIXED_SURROGATE_ARRAYo->nth(offset))));
}

Keyword* get_kwd(int offset) {
  return (((Keyword*)(oFIXED_KEYWORD_ARRAYo->nth(offset))));
}

Indexical* get_idx(int offset) {
  return (((Indexical*)(oFIXED_INDEXICAL_ARRAYo->nth(offset))));
}

Generalized_Symbol* get_generalized_symbol_from_offset(Extensible_Symbol_Array* symbolarray, int offset) {
  return (((Generalized_Symbol*)(symbolarray->nth(offset))));
}

Symbol* get_sym_from_offset(int offset) {
  return (((Symbol*)(get_generalized_symbol_from_offset(oSYMBOL_ARRAYo, offset))));
}

Surrogate* get_sgt_from_offset(int offset) {
  return (((Surrogate*)(get_generalized_symbol_from_offset(oSURROGATE_ARRAYo, offset))));
}

Keyword* get_kwd_from_offset(int offset) {
  return (((Keyword*)(get_generalized_symbol_from_offset(oKEYWORD_ARRAYo, offset))));
}

Indexical* get_idx_from_offset(int offset) {
  return (((Indexical*)(get_generalized_symbol_from_offset(oINDEXICAL_ARRAYo, offset))));
}

String_To_Integer_Hash_Table* select_symbol_offset_table(Module* module, int kindofsym) {
  switch (kindofsym) {
    case 0: 
      return (module->symbol_offset_table);
    case 1: 
      return (module->surrogate_offset_table);
    case 2: 
      return (oKEYWORD_OFFSET_TABLEo);
    case 3: 
      return (module->cardinal_module->indexical_offset_table);
  }
}

Extensible_Symbol_Array* select_symbol_array(int kindofsym) {
  switch (kindofsym) {
    case 0: 
      return (oSYMBOL_ARRAYo);
    case 1: 
      return (oSURROGATE_ARRAYo);
    case 2: 
      return (oKEYWORD_ARRAYo);
    case 3: 
      return (oINDEXICAL_ARRAYo);
  }
}

Generalized_Symbol* lookup_rigid_symbol_locally(char* name, Module* module, int kindofsym) {
  { String_To_Integer_Hash_Table* offsettable = select_symbol_offset_table(module, kindofsym);
    int offset = offsettable->lookup(name);

    if (offset != NULL_INTEGER) {
      switch (kindofsym) {
        case 0: 
          return (get_sym_from_offset(offset));
        case 1: 
          return (get_sgt_from_offset(offset));
        case 2: 
          return (get_kwd_from_offset(offset));
      }
    }
    return (NULL);
  }
}

Cons* yield_visible_rigid_symbols_wrt_module(char* name, Module* module, int kindofsym) {
  { Cons* listofsymbols = NIL;
    Generalized_Symbol* symbol = NULL;

    { Module* visiblemodule = NULL;
      Iterator* iter_001 = visible_modules(module);

      while (iter_001->nextP()) {
        {
          visiblemodule = ((Module*)(iter_001->value));
        }
        { 
          symbol = lookup_rigid_symbol_locally(name, visiblemodule, kindofsym);
          if (symbol != NULL) {
            listofsymbols = cons(symbol, listofsymbols);
          }
        }
      }
    }
    return (listofsymbols->reverse());
  }
}

Iterator* visible_rigid_symbols_wrt_module(char* name, Module* module, int kindofsym) {
  return (yield_visible_rigid_symbols_wrt_module(name, module, kindofsym)->allocate_destructive_list_iterator());
}

int lookup_rigid_symbol_offset_wrt_module(char* name, Module* module, int kindofsym) {
  { String_To_Integer_Hash_Table* offsettable = select_symbol_offset_table(module, kindofsym);
    int offset = offsettable->lookup(name);

    if (offset != NULL_INTEGER) {
      return (offset);
    }
    { Module* super = NULL;
      Iterator* iter_001 = visible_modules(module)->advance(1);

      while (iter_001->nextP()) {
        {
          super = ((Module*)(iter_001->value));
        }
        offset = select_symbol_offset_table(super, kindofsym)->lookup(name);
        if (offset != NULL_INTEGER) {
          return (offset);
        }
      }
    }
    return (NULL_INTEGER);
  }
}

Generalized_Symbol* lookup_rigid_symbol_wrt_module(char* name, Module* module, int kindofsym) {
  { int offset = lookup_rigid_symbol_offset_wrt_module(name, module, kindofsym);

    if (offset != NULL_INTEGER) {
      switch (kindofsym) {
        case 0: 
          return (get_sym_from_offset(offset));
        case 1: 
          return (get_sgt_from_offset(offset));
        case 2: 
          return (get_kwd_from_offset(offset));
      }
    }
    else {
      return (NULL);
    }
  }
}

Generalized_Symbol* lookup_rigid_symbol(char* name, int kindofsym) {
  // Return the symbol named 'name'.  Case sensitive.
  { Module* module = oMODULEo;

    if (qualified_nameP(name)) {
      module = compute_module_and_bare_name(name, name);
    }
    if (module != NULL) {
      return (lookup_rigid_symbol_wrt_module(name, module, kindofsym));
    }
    else {
      return (NULL);
    }
  }
}

int lookup_indexical_symbol_offset_wrt_module(char* name, Module* module, int kindofsym) {
  { Module* cardinalmodule = module->cardinal_module;
    String_To_Integer_Hash_Table* table = select_symbol_offset_table(cardinalmodule, kindofsym);
    int offset = NULL_INTEGER;

    offset = table->lookup(name);
    if (offset != NULL_INTEGER) {
      return (offset);
    }
    { Module* usee = NULL;
      Cons* iter_001 = module->uses->the_cons_list;

      while (!nilP(iter_001)) {
        {
          usee = ((Module*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        cardinalmodule = usee->cardinal_module;
        table = select_symbol_offset_table(cardinalmodule, kindofsym);
        offset = table->lookup(name);
        if (offset != NULL_INTEGER) {
          return (offset);
        }
      }
    }
    return (NULL_INTEGER);
  }
}

Generalized_Symbol* lookup_indexical_symbol_wrt_module(char* name, Module* module, int kindofsym) {
  { int offset = lookup_indexical_symbol_offset_wrt_module(name, module, kindofsym);

    if (offset != NULL_INTEGER) {
      switch (kindofsym) {
        case 3: 
          return (get_idx_from_offset(offset));
      }
    }
    else {
      return (NULL);
    }
  }
}

Generalized_Symbol* lookup_indexical_symbol(char* name, int kindofsym) {
  // Return the indexical named 'name'.
  { int offset = lookup_indexical_symbol_offset_wrt_module(name, oMODULEo, kindofsym);

    if (offset != NULL_INTEGER) {
      switch (kindofsym) {
        case 3: 
          return (get_idx(offset));
      }
    }
    return (NULL);
  }
}

Symbol* lookup_symbol(char* name) {
  return (((Symbol*)(lookup_rigid_symbol(name, SYMBOL_SYM))));
}

Symbol* lookup_symbol_in_module(char* name, Module* module, boolean localP) {
  if (module == NULL) {
    module = oMODULEo;
  }
  if (localP) {
    return (((Symbol*)(lookup_rigid_symbol_locally(name, module, SYMBOL_SYM))));
  }
  else {
    return (((Symbol*)(lookup_rigid_symbol_wrt_module(name, module, SYMBOL_SYM))));
  }
}

Surrogate* lookup_surrogate(char* name) {
  return (((Surrogate*)(lookup_rigid_symbol(name, SURROGATE_SYM))));
}

Surrogate* lookup_surrogate_in_module(char* name, Module* module, boolean localP) {
  if (module == NULL) {
    module = oMODULEo;
  }
  if (localP) {
    return (((Surrogate*)(lookup_rigid_symbol_locally(name, module, SURROGATE_SYM))));
  }
  else {
    return (((Surrogate*)(lookup_rigid_symbol_wrt_module(name, module, SURROGATE_SYM))));
  }
}

Keyword* lookup_keyword(char* name) {
  return (((Keyword*)(lookup_rigid_symbol(name, KEYWORD_SYM))));
}

Indexical* lookup_indexical(char* name) {
  return (((Indexical*)(lookup_indexical_symbol(name, INDEXICAL_SYM))));
}

Generalized_Symbol* help_intern_generalized_symbol(char* name, int kindofsym, Extensible_Symbol_Array* array, int offset, Module* module) {
  { Generalized_Symbol* symbol = NULL;
    String_To_Integer_Hash_Table* table = select_symbol_offset_table(module, kindofsym);

    switch (kindofsym) {
      case 0: 
        symbol = new_symbol(name);
        table->insert_at(name, offset);
      break;
      case 1: 
        symbol = new_surrogate(name);
        table->insert_at(name, offset);
      break;
      case 2: 
        symbol = new_keyword(name);
        table->insert_at(name, offset);
      break;
      case 3: 
        symbol = new_indexical(name);
        module = module->cardinal_module;
        table->insert_at(name, offset);
      break;
    }
    add_to_symbol_array_at(array, offset, symbol);
    symbol->home_context = module;
    return (symbol);
  }
}

Generalized_Symbol* intern_rigid_symbol_wrt_module(char* name, Module* module, int kindofsym) {
  // Return a newly-created or existing rigid symbol with
  // name 'name'.
  if (module == NULL) {
    module = oMODULEo;
  }
  { int offset = lookup_rigid_symbol_offset_wrt_module(name, module, kindofsym);

    if (offset != NULL_INTEGER) {
      switch (kindofsym) {
        case 0: 
          return (get_sym_from_offset(offset));
        case 1: 
          return (get_sgt_from_offset(offset));
        case 2: 
          return (get_kwd_from_offset(offset));
      }
    }
    { Extensible_Symbol_Array* array = select_symbol_array(kindofsym);

      offset = next_free_offset(array);
      return (help_intern_generalized_symbol(name, kindofsym, array, offset, module));
    }
  }
}

Generalized_Symbol* intern_rigid_symbol_locally(char* name, Module* module, int kindofsym) {
  // Return a newly-created or existing rigid symbol
  // interned into the module 'module' with name 'name'.
  if (module == NULL) {
    module = oMODULEo;
  }
  { Generalized_Symbol* symbol = lookup_rigid_symbol_locally(name, module, kindofsym);

    if (symbol != NULL) {
      return (symbol);
    }
    { Extensible_Symbol_Array* array = select_symbol_array(kindofsym);

      return (help_intern_generalized_symbol(name, kindofsym, array, next_free_offset(array), module));
    }
  }
}

Generalized_Symbol* intern_indexical_symbol_wrt_module(char* name, Module* module, int kindofsym) {
  // Return a newly-created or existing indexical with
  // name 'name'.
  if (module == NULL) {
    module = oMODULEo;
  }
  { Generalized_Symbol* symbol = lookup_indexical_symbol_wrt_module(name, module, kindofsym);

    module = module->cardinal_module;
    if ((symbol != NULL) &&
        (symbol->home_context == module)) {
      return (symbol);
    }
    { Extensible_Symbol_Array* array = select_symbol_array(kindofsym);
      int offset = next_free_offset(array);

      return (help_intern_generalized_symbol(name, kindofsym, array, offset, module));
    }
  }
}

Generalized_Symbol* intern_rigid_symbol_case_sensitively(char* name, int kindofsym) {
  { Generalized_Symbol* symbol = NULL;
    char* namecopy = NULL;

    symbol = lookup_rigid_symbol(name, kindofsym);
    if (symbol != NULL) {
      return (symbol);
    }
    switch (kindofsym) {
      case 0: 
        if (oTRANSIENTOBJECTSpo) {
          symbol = lookup_transient_symbol(name);
        }
        if (symbol != NULL) {
          return (symbol);
        }
        if (oTRANSIENTOBJECTSpo) {
          namecopy = string_upcase(name);
        }
        else {
          namecopy = permanent_string_upcase(name);
        }
      break;
      case 1: 
        namecopy = permanent_string_upcase(name);
      break;
    }
    { int i = NULL_INTEGER;
      int iter_001 = 0;
      int upper_bound_001 = string_length(name) - 1;

      while (iter_001 <= upper_bound_001) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        string_nth_setter(namecopy, string_nth(name, i), i);
      }
    }
    switch (kindofsym) {
      case 0: 
        if (oTRANSIENTOBJECTSpo) {
          return (intern_transient_symbol(namecopy));
        }
        else {
          return (intern_permanent_symbol(namecopy));
        }
      break;
      case 1: 
        return (intern_rigid_symbol_wrt_module(namecopy, oMODULEo, SURROGATE_SYM));
    }
  }
}

Symbol* intern_permanent_symbol(char* name) {
  // Return a newly-created or existing permanent symbol with
  // name 'name'.
  return (((Symbol*)(intern_rigid_symbol_wrt_module(name, oMODULEo, SYMBOL_SYM))));
}

Symbol* intern_symbol(char* name) {
  // Return a newly-created or existing symbol with name
  // 'name'.  Storage note: a COPY of 'name' is stored in the symbol.
  if (oMODULEo->case_sensitiveP) {
    return (((Symbol*)(intern_rigid_symbol_case_sensitively(name, SYMBOL_SYM))));
  }
  else {
    if (oTRANSIENTOBJECTSpo) {
      return (intern_transient_symbol(string_upcase(name)));
    }
    else {
      return (intern_permanent_symbol(permanent_string_upcase(name)));
    }
  }
}

Symbol* intern_derived_symbol(Generalized_Symbol* basesymbol, char* newname) {
  // Return a newly-created or existing symbol with name
  // 'newName' which is interned in the same module as 'baseSymbol'.
  { Module* currentmodule = oMODULEo;

    { Module* old_OmoduleO_001 = oMODULEo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oMODULEo = ((Module*)(basesymbol->home_context));
            if (oMODULEo != NULL) {
              { Generalized_Symbol* return_value_001 = intern_rigid_symbol_locally((oMODULEo->case_sensitiveP ? ((char*)(newname)) : ((char*)(permanent_string_upcase(newname)))), oMODULEo, SYMBOL_SYM);

                oMODULEo = old_OmoduleO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (((Symbol*)(return_value_001)));
              }
            }
            oMODULEo = currentmodule;
            { Symbol* return_value_002 = intern_symbol(newname);

              oMODULEo = old_OmoduleO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (return_value_002);
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

Surrogate* intern_surrogate(char* name) {
  // Return a newly-created or existing surrogate with
  // name 'name'.
  if (oMODULEo->case_sensitiveP) {
    return (((Surrogate*)(intern_rigid_symbol_case_sensitively(name, SURROGATE_SYM))));
  }
  else {
    return (((Surrogate*)(intern_rigid_symbol_wrt_module(permanent_string_upcase(name), oMODULEo, SURROGATE_SYM))));
  }
}

Indexical* intern_indexical(char* name) {
  // Return a newly-created or existing indexical with
  // name 'name', interned in '(cardinal-module *module*)'.
  if (!oMODULEo->case_sensitiveP) {
    name = permanent_string_upcase(name);
  }
  return (((Indexical*)(intern_indexical_symbol_wrt_module(name, oMODULEo, INDEXICAL_SYM))));
}

Keyword* intern_permanent_keyword(char* name) {
  // Return a newly-created or existing permanent keyword with
  // name 'name'.
  return (((Keyword*)(intern_rigid_symbol_wrt_module(name, oMODULEo, KEYWORD_SYM))));
}

Keyword* intern_keyword(char* name) {
  // Return a newly-created or existing keyword with name
  // 'name'.  Storage note: a COPY of 'name' is stored in the keyword
  if (oTRANSIENTOBJECTSpo) {
    return (intern_transient_keyword(string_upcase(name)));
  }
  else {
    return (intern_permanent_keyword(permanent_string_upcase(name)));
  }
}

void unintern_symbol(Symbol* self) {
  // Remove `self' from its home module and the symbol table.
  { Extensible_Symbol_Array* symbolarray = select_symbol_array(SYMBOL_SYM);
    String_To_Integer_Hash_Table* offsettable = ((((Module*)(self->home_context)) != NULL) ? ((String_To_Integer_Hash_Table*)(select_symbol_offset_table(((Module*)(self->home_context)), SYMBOL_SYM))) : ((String_To_Integer_Hash_Table*)(NULL)));
    int symbolid = self->symbol_id;
    Symbol* realsymbol = get_sym_from_offset(symbolid);

    if (self == realsymbol) {
      free_symbol_offset(symbolarray, symbolid);
    }
    if ((offsettable != NULL) &&
        (symbolid == offsettable->lookup(self->symbol_name))) {
      offsettable->remove_at(self->symbol_name);
    }
    self->symbol_value_and_plist = NULL;
  }
}

void unintern_surrogate(Surrogate* self) {
  // Remove `self' from its home module and the surrogate table.
  { Extensible_Symbol_Array* surrogatearray = select_symbol_array(SURROGATE_SYM);
    String_To_Integer_Hash_Table* offsettable = ((((Module*)(self->home_context)) != NULL) ? ((String_To_Integer_Hash_Table*)(select_symbol_offset_table(((Module*)(self->home_context)), SURROGATE_SYM))) : ((String_To_Integer_Hash_Table*)(NULL)));
    int surrogateid = self->symbol_id;
    Surrogate* realsurrogate = get_sgt_from_offset(surrogateid);

    if (self == realsurrogate) {
      free_symbol_offset(surrogatearray, surrogateid);
    }
    if ((offsettable != NULL) &&
        (surrogateid == offsettable->lookup(self->symbol_name))) {
      offsettable->remove_at(self->symbol_name);
    }
    self->surrogate_value = NULL;
  }
}

Generalized_Symbol* intern_bootstrap_symbol_at(char* name, int offset, int kindofsym) {
  // Interns a symbol, or keyword with
  // name' and symbol-id 'offset'.
  // If a symbol with that ID already existed, an error is signaled.  This
  // function is used to recreate the symbol table in a way where symbol IDs
  // which got hardwired into translated code will refer to the correct objects.
  { Extensible_Symbol_Array* symbolarray = NULL;
    Generalized_Symbol* symbol = NULL;

    switch (kindofsym) {
      case 0: 
        symbol = lookup_symbol(name);
      break;
      case 1: 
        symbol = lookup_surrogate(name);
      break;
      case 2: 
        symbol = lookup_keyword(name);
      break;
      case 3: 
        symbol = lookup_indexical(name);
      break;
    }
    if (symbol != NULL) {
      if (!(symbol->symbol_id == offset)) {
        cerr << "intern-bootstrap-symbol-at: " << "`" << symbol << "'" << " is already interned at offset " << "`" << symbol->symbol_id << "'";
      }
      return (symbol);
    }
    symbolarray = select_symbol_array(kindofsym);
    if (legal_symbol_array_offsetP(symbolarray, offset) &&
        (get_generalized_symbol_from_offset(symbolarray, offset) != NULL)) {
      symbol = get_generalized_symbol_from_offset(symbolarray, offset);
      cerr << "intern-bootstrap-symbol-at: " << "`" << symbol << "'" << " is already interned at offset " << "`" << offset << "'";
      return (symbol);
    }
    { Extensible_Symbol_Array* array = select_symbol_array(kindofsym);

      return (help_intern_generalized_symbol(name, kindofsym, array, offset, oMODULEo));
    }
  }
}

Symbol* intern_symbol_at(char* name, int offset) {
  return (((Symbol*)(intern_bootstrap_symbol_at(name, offset, SYMBOL_SYM))));
}

Surrogate* intern_surrogate_at(char* name, int offset) {
  return (((Surrogate*)(intern_bootstrap_symbol_at(name, offset, SURROGATE_SYM))));
}

Keyword* intern_keyword_at(char* name, int offset) {
  return (((Keyword*)(intern_bootstrap_symbol_at(name, offset, KEYWORD_SYM))));
}

Indexical* intern_indexical_at(char* name, int offset) {
  return (((Indexical*)(intern_bootstrap_symbol_at(name, offset, INDEXICAL_SYM))));
}

void initialize_kernel_module(Module* module, char* name, char* fullname, Module* parent) {
  module->module_name = name;
  module->module_full_name = fullname;
  if (parent != NULL) {
    parent->child_contexts->insert(module);
    module->cardinal_module = module;
  }
  module->symbol_offset_table = new_string_to_integer_hash_table();
  module->surrogate_offset_table = new_string_to_integer_hash_table();
  module->indexical_offset_table = new_string_to_integer_hash_table();
  module->all_super_contexts = NIL;
  module->base_module = module;
  oCONTEXT_NUMBER_COUNTERo = oCONTEXT_NUMBER_COUNTERo + 2;
  module->context_number = oCONTEXT_NUMBER_COUNTERo;
  module->stringified_options = "";
}

void initialize_modules() {
  oROOT_MODULEo = new_module();
  initialize_kernel_module(oROOT_MODULEo, "ROOT-MODULE", "/", NULL);
  oSTELLA_MODULEo = new_module();
  initialize_kernel_module(oSTELLA_MODULEo, "STELLA", "/STELLA", oROOT_MODULEo);
  oSTELLA_MODULEo->module_native_package = "STELLA";
  oCOMMON_LISP_MODULEo = new_module();
  initialize_kernel_module(oCOMMON_LISP_MODULEo, "COMMON-LISP", "/COMMON-LISP", oROOT_MODULEo);
  oCOMMON_LISP_MODULEo->module_native_package = "CL";
  oROOT_MODULEo->cardinal_module = oSTELLA_MODULEo;
  oMODULEo = oSTELLA_MODULEo;
  oCONTEXTo = oMODULEo;
}

void initialize_symbols_and_modules() {
  oFIXED_SYMBOL_ARRAYo = new_extensible_symbol_array(100);
  oFIXED_SURROGATE_ARRAYo = new_extensible_symbol_array(100);
  oFIXED_KEYWORD_ARRAYo = new_extensible_symbol_array(100);
  oKEYWORD_OFFSET_TABLEo = new_string_to_integer_hash_table();
  oFIXED_INDEXICAL_ARRAYo = new_extensible_symbol_array(100);
  oSYMBOL_ARRAYo = oFIXED_SYMBOL_ARRAYo;
  oSURROGATE_ARRAYo = oFIXED_SURROGATE_ARRAYo;
  oKEYWORD_ARRAYo = oFIXED_KEYWORD_ARRAYo;
  oINDEXICAL_ARRAYo = oFIXED_INDEXICAL_ARRAYo;
  initialize_modules();
}

Symbol* lookup_transient_symbol(char* name) {
  if (oTRANSIENT_SYMBOL_LOOKUP_TABLEo != NULL) {
    return (((Symbol*)(oTRANSIENT_SYMBOL_LOOKUP_TABLEo->lookup(name))));
  }
  else {
    {
      cerr << "Looking for a transient symbol when the parsing tables have\nnot been initialized.";
      return (NULL);
    }
  }
}

Keyword* lookup_transient_keyword(char* name) {
  if (oTRANSIENT_KEYWORD_LOOKUP_TABLEo != NULL) {
    return (((Keyword*)(oTRANSIENT_KEYWORD_LOOKUP_TABLEo->lookup(name))));
  }
  else {
    {
      cerr << "Looking for a transient keyword when the parsing tables have\nnot been initialized.";
      return (NULL);
    }
  }
}

Symbol* intern_transient_symbol(char* name) {
  { Symbol* symbol = lookup_symbol(name);

    if (symbol != NULL) {
      return (symbol);
    }
    symbol = lookup_transient_symbol(name);
    if (symbol != NULL) {
      return (symbol);
    }
    symbol = new_transient_symbol(name);
    symbol->home_context = NULL;
    oTRANSIENT_SYMBOL_LOOKUP_TABLEo->insert_at(name, symbol);
    return (symbol);
  }
}

Keyword* intern_transient_keyword(char* name) {
  { Keyword* keyword = lookup_keyword(name);

    if (keyword != NULL) {
      return (keyword);
    }
    keyword = lookup_transient_keyword(name);
    if (keyword != NULL) {
      return (keyword);
    }
    keyword = new_transient_keyword(name);
    oTRANSIENT_KEYWORD_LOOKUP_TABLEo->insert_at(name, keyword);
    return (keyword);
  }
}

void free_transient_symbols() {
  oTRANSIENT_SYMBOL_LOOKUP_TABLEo->free_hash_table_values();
}

void free_transient_keywords() {
  oTRANSIENT_KEYWORD_LOOKUP_TABLEo->free_hash_table_values();
}

Symbol* intern_common_lisp_symbol(char* name) {
  { Symbol* symbol = ((Symbol*)(lookup_rigid_symbol_wrt_module(name, oCOMMON_LISP_MODULEo, SYMBOL_SYM)));

    if (symbol != NULL) {
      return (symbol);
    }
    symbol = ((Symbol*)(intern_rigid_symbol_wrt_module(name, oCOMMON_LISP_MODULEo, SYMBOL_SYM)));
    return (symbol);
  }
}

boolean symbol_common_lispP(Symbol* self) {
  return (self->home_context == oCOMMON_LISP_MODULEo);
}

boolean common_lisp_symbolP(Object* self) {
  return (symbolP(self) &&
      symbol_common_lispP(((Symbol*)(self))));
}

void initialize_parsing_tables() {
  // Create indices for recording transient symbols and
  // Common Lisp symbols while parsing.
  oTRANSIENT_SYMBOL_LOOKUP_TABLEo = new_string_hash_table();
  oCOMMON_LISP_SYMBOL_LOOKUP_TABLEo = new_string_hash_table();
  oTRANSIENT_KEYWORD_LOOKUP_TABLEo = new_string_hash_table();
}

char* yield_gensym_name(char* prefix, int counter) {
  { char* mask = "-000";
    char* suffix = integer_to_string(counter);
    int maskend = 4 - string_length(suffix);

    if (maskend < 1) {
      maskend = 1;
    }
    return (string_concatenate(prefix, string_concatenate(string_subsequence(mask, 0, maskend), suffix)));
  }
}

Symbol* gensym(char* prefix) {
  // Return a transient symbol with a name beginning with
  // 'prefix' and ending with a globally gensym'd integer.
  return (intern_transient_symbol(yield_gensym_name(prefix, oGENSYM_COUNTERo = oGENSYM_COUNTERo + 1)));
}

Surrogate* Surrogate::surrogatify() {
  { Surrogate* self = this;

    return (self);
  }
}

Surrogate* Symbol::surrogatify() {
  { Symbol* self = this;

    return (((Surrogate*)(intern_rigid_symbol_locally(self->symbol_name, ((Module*)(self->home_context)), SURROGATE_SYM))));
  }
}

Surrogate* string_surrogatify(char* self) {
  return (intern_surrogate(self));
}

Surrogate* Cons::surrogatify() {
  { Cons* self = this;

    if (nilP(self)) {
      return (intern_surrogate("NIL"));
    }
    else {
      cerr << "Cons passed to 'surrogatify'";
    }
  }
}

Surrogate* Object::surrogatify() {
  { Object* self = this;

    cerr << "OBJECT passed to 'surrogatify'";
    return (NULL);
  }
}

Surrogate* typify(Object* self) {
  return (self->surrogatify());
}

Keyword* Keyword::keywordify() {
  { Keyword* self = this;

    return (self);
  }
}

Keyword* Transient_Keyword::keywordify() {
  { Transient_Keyword* self = this;

    return (intern_permanent_keyword(self->symbol_name));
  }
}

Keyword* Symbol::keywordify() {
  { Symbol* self = this;

    return (intern_permanent_keyword(self->symbol_name));
  }
}

Keyword* string_keywordify(char* self) {
  return (intern_permanent_keyword(self));
}

void in_place_objects_to_symbols(Cons* conslist) {
  { Cons* cursor = conslist;

    while (cursor->non_emptyP()) {
      cursor->value = cursor->value->permanentify();
      cursor = cursor->rest;
    }
  }
}

void in_place_objects_to_types(Cons* conslist) {
  { Cons* cursor = conslist;

    while (cursor->non_emptyP()) {
      cursor->value = typify(cursor->value);
      cursor = cursor->rest;
    }
  }
}

boolean surrogate_nameP(char* name) {
  return (string_nth(name, 0) == SURROGATE_PREFIX_CHARACTER);
}

boolean qualified_nameP(char* name) {
  return ((string_memberP(name, MODULE_SEPARATOR_CHARACTER) &&
      (string_length(name) > 1)) ||
      (string_nth(name, 0) == '.'));
}

boolean keyword_nameP(char* name) {
  return (string_nth(name, 0) == ':');
}

Generalized_Symbol* intern_generalized_symbol(char* name) {
  if (qualified_nameP(name)) {
    return (intern_qualified_name(name));
  }
  else if (keyword_nameP(name)) {
    return (intern_keyword(string_rest(name)));
  }
  else if (surrogate_nameP(name)) {
    return (intern_surrogate(string_rest(name)));
  }
  else {
    return (intern_symbol(name));
  }
}

char* compute_full_name(char* name, Module* module) {
  if (module == NULL) {
    return (name);
  }
  { char* pathname = name;

    while (module != NULL) {
      if (string_eqlP(pathname, "")) {
        pathname = module->module_name;
      }
      else {
        pathname = string_concatenate(module->module_name, string_concatenate(MODULE_SEPARATOR_STRING, pathname));
      }
      module = ((Module*)(module->parent_modules->first()));
    }
    pathname = string_concatenate(MODULE_SEPARATOR_STRING, pathname);
    return (pathname);
  }
}

char* Generalized_Symbol::local_print_name() {
  { Generalized_Symbol* self = this;

    return (self->symbol_name);
  }
}

char* Surrogate::local_print_name() {
  { Surrogate* self = this;

    return (string_concatenate("@", self->symbol_name));
  }
}

char* Generalized_Symbol::relative_name() {
  { Generalized_Symbol* self = this;

    if (self->home_context == oMODULEo) {
      return (self->local_print_name());
    }
    else {
      return (compute_full_name(self->local_print_name(), ((Module*)(self->home_context))));
    }
  }
}

char* Generalized_Symbol::visible_name() {
  { Generalized_Symbol* self = this;

    if (visible_fromP(((Module*)(self->home_context)), oMODULEo)) {
      return (self->local_print_name());
    }
    else {
      return (compute_full_name(self->local_print_name(), ((Module*)(self->home_context))));
    }
  }
}

boolean escaped_characterP(char* string, int position) {
  { int nofescapes = 0;

    position = position - 1;
    while ((position >= 0) &&
        (ESCAPE_CHARACTER == string_nth(string, position))) {
      nofescapes = nofescapes + 1;
      position = position - 1;
    }
    return (oddP(nofescapes));
  }
}

char* unescape_character(char* string, char character) {
  { int escapeposition = string_position(string, ESCAPE_CHARACTER, 0);

    if (escapeposition != NULL_INTEGER) {
      { int stringlength = string_length(string);
        char* unescapedstring = string_subsequence(string, 0, escapeposition);

        if (escapeposition < (stringlength - 1)) {
          unescapedstring = string_concatenate(unescapedstring, string_subsequence(string, (((character == NULL_CHARACTER) ||
              (character == string_nth(string, escapeposition + 1))) ? ((int)(escapeposition + 1)) : ((int)(escapeposition))), escapeposition + 2));
        }
        if (escapeposition < (stringlength - 2)) {
          unescapedstring = string_concatenate(unescapedstring, unescape_character(string_subsequence(string, escapeposition + 2, NULL_INTEGER), character));
        }
        return (unescapedstring);
      }
    }
    else {
      return (string);
    }
  }
}

Object* symbol_value(Symbol* symbol) {
  // Return the value of 'symbol'.  Note, that this value is not
  // visible to code that references a variable with the same name as 'symbol'.
  // The 'symbol-value' is simply a special property that can always be accessed
  // in constant time.  The 'symbol-value' of a symbol can be changed with 'setf'.
  return (symbol->symbol_value_and_plist->value);
}

Object* symbol_value_setter(Symbol* symbol, Object* value) {
  { Cons* vplist = symbol->symbol_value_and_plist;

    if (vplist == NIL) {
      vplist = permanent_cons(NULL, NIL);
      symbol->symbol_value_and_plist = vplist;
    }
    return (vplist->value = value);
  }
}

Cons* symbol_plist(Symbol* symbol) {
  // Return the property list of 'symbol'.  The 'symbol-plist'
  // of a symbol can be set with 'setf'.  IMPORTANT: Property list are modified 
  // destructively, hence, if you supply it as a whole make sure to always supply
  // a modfiable copy, e.g., by using 'bquote'.
  return (symbol->symbol_value_and_plist->rest);
}

Cons* symbol_plist_setter(Symbol* symbol, Cons* plist) {
  { Cons* vplist = symbol->symbol_value_and_plist;

    if (vplist == NIL) {
      vplist = permanent_cons(NULL, NIL);
      symbol->symbol_value_and_plist = vplist;
    }
    return (vplist->rest = plist);
  }
}

Object* symbol_property(Symbol* symbol, Standard_Object* key) {
  // Return the property of 'symbol' whose key is 'eq?' to 'key'.
  // Symbol properties can be set with 'setf'.
  { Cons* plist = symbol->symbol_value_and_plist->rest;

    while (!(plist == NIL)) {
      if (plist->value == key) {
        return (plist->rest->value);
      }
      plist = plist->rest->rest;
    }
    return (NULL);
  }
}

Object* symbol_property_setter(Symbol* symbol, Object* value, Standard_Object* key) {
  { Cons* vplist = symbol->symbol_value_and_plist;
    Cons* plist = vplist->rest;

    while (!(plist == NIL)) {
      if (plist->value == key) {
        if (value != NULL) {
          plist->rest->value = value;
        }
        else if (!(plist->rest->rest == NIL)) {
          { Cons* restplist = plist->rest;

            plist->value = restplist->rest->value;
            plist->rest = restplist->rest->rest;
            restplist->rest->free_cons();
            restplist->free_cons();
          }
        }
        else if (plist == vplist->rest) {
          plist->rest->free_cons();
          plist->free_cons();
          vplist->rest = NIL;
        }
        else {
          plist->rest->value = value;
        }
        return (value);
      }
      plist = plist->rest->rest;
    }
    if (value != NULL) {
      if (vplist == NIL) {
        vplist = permanent_cons(NULL, NIL);
        symbol->symbol_value_and_plist = vplist;
      }
      vplist->rest = permanent_cons(key, permanent_cons(value, vplist->rest));
    }
    return (value);
  }
}

Vector* create_character_type_table() {
  { Vector* table = new_vector(256);

    { int code = NULL_INTEGER;
      int iter_001 = 0;
      int upper_bound_001 = 255;

      while (iter_001 <= upper_bound_001) {
        {
          code = iter_001;
          iter_001 = iter_001 + 1;
        }
        table->nth_setter(KWD_SYMBOLS_OTHER, code);
      }
    }
    { int code = NULL_INTEGER;
      int iter_002 = character_code('0');
      int upper_bound_002 = character_code('9');
      boolean unboundedP_001 = upper_bound_002 == NULL_INTEGER;

      while (unboundedP_001 ||
          (iter_002 <= upper_bound_002)) {
        {
          code = iter_002;
          iter_002 = iter_002 + 1;
        }
        table->nth_setter(KWD_SYMBOLS_DIGIT, code);
      }
    }
    { int code = NULL_INTEGER;
      int iter_003 = character_code('A');
      int upper_bound_003 = character_code('Z');
      boolean unboundedP_002 = upper_bound_003 == NULL_INTEGER;

      while (unboundedP_002 ||
          (iter_003 <= upper_bound_003)) {
        {
          code = iter_003;
          iter_003 = iter_003 + 1;
        }
        table->nth_setter(KWD_SYMBOLS_LETTER, code);
      }
    }
    { int code = NULL_INTEGER;
      int iter_004 = character_code('a');
      int upper_bound_004 = character_code('z');
      boolean unboundedP_003 = upper_bound_004 == NULL_INTEGER;

      while (unboundedP_003 ||
          (iter_004 <= upper_bound_004)) {
        {
          code = iter_004;
          iter_004 = iter_004 + 1;
        }
        table->nth_setter(KWD_SYMBOLS_LETTER, code);
      }
    }
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('$'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('%'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('<'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('>'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('='));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('?'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('['));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code(']'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('^'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('_'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('{'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('}'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('~'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('.'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('+'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('-'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_CONSTITUENT, character_code('*'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_QUALIFIER, character_code(':'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_QUALIFIER, character_code('/'));
    table->nth_setter(KWD_SYMBOLS_SYMBOL_QUALIFIER, character_code('@'));
    table->nth_setter(KWD_SYMBOLS_ESCAPE, character_code('!'));
    table->nth_setter(KWD_SYMBOLS_ESCAPE, character_code('\\'));
    table->nth_setter(KWD_SYMBOLS_OPEN_DELIMITER, character_code('('));
    table->nth_setter(KWD_SYMBOLS_CLOSE_DELIMITER, character_code(')'));
    table->nth_setter(KWD_SYMBOLS_PAIRED_DELIMITER, character_code('"'));
    table->nth_setter(KWD_SYMBOLS_PAIRED_DELIMITER, character_code('|'));
    table->nth_setter(KWD_SYMBOLS_WHITE_SPACE, character_code(' '));
    table->nth_setter(KWD_SYMBOLS_WHITE_SPACE, character_code('\t'));
    table->nth_setter(KWD_SYMBOLS_WHITE_SPACE, character_code('\n'));
    table->nth_setter(KWD_SYMBOLS_WHITE_SPACE, character_code('\r'));
    table->nth_setter(KWD_SYMBOLS_WHITE_SPACE, character_code('\n'));
    table->nth_setter(KWD_SYMBOLS_WHITE_SPACE, character_code('\f'));
    return (table);
  }
}

boolean symbol_constituent_characterP(char character) {
  { Keyword* test_value_001 = ((Keyword*)(oCHARACTER_TYPE_TABLEo->nth(character_code(character))));

    if ((test_value_001 == KWD_SYMBOLS_LETTER) ||
        ((test_value_001 == KWD_SYMBOLS_DIGIT) ||
         (test_value_001 == KWD_SYMBOLS_SYMBOL_CONSTITUENT))) {
      return (TRUE);
    }
    else {
      return (FALSE);
    }
  }
}

void print_symbol(Symbol* self, ostream* stream) {
  if (oPRINTREADABLYpo &&
      symbol_common_lispP(self)) {
    *(stream) << "CL:" << self->symbol_name;
  }
  else {
    { Module* module = ((((Module*)(self->home_context)) == NULL) ? ((Module*)(oMODULEo)) : ((Module*)(((Module*)(self->home_context)))));
      char* name = ((module == oMODULEo) ? ((char*)(self->symbol_name)) : ((char*)(self->visible_name())));

      { boolean test_value_001 = FALSE;

        test_value_001 = oPRINTREADABLYpo;
        if (test_value_001) {
          if ((!(module == oMODULEo)) &&
              module->case_sensitiveP) {
            test_value_001 = TRUE;
          }
          else {
            { boolean foundP_001 = FALSE;

              { char renamed_Char = NULL_CHARACTER;
                char* vector_001 = name;
                int index_001 = 0;
                int length_001 = string_length(vector_001);

                while (index_001 < length_001) {
                  {
                    renamed_Char = string_nth(vector_001, index_001);
                    index_001 = index_001 + 1;
                  }
                  if (!symbol_constituent_characterP(renamed_Char)) {
                    foundP_001 = TRUE;
                    break;
                  }
                }
              }
              test_value_001 = foundP_001;
            }
          }
        }
        if (test_value_001) {
          *(stream) << "|" << name << "|";
        }
        else {
          *(stream) << name;
        }
      }
    }
  }
}

Symbol_Processing_Environment* new_symbol_processing_environment() {
  { Symbol_Processing_Environment* self = NULL;

    self = new Symbol_Processing_Environment;
    self->current_context = NULL;
    self->cardinal_modules = new_list();
    self->indexical_array = NULL;
    self->keyword_offset_table = new_string_to_integer_hash_table();
    self->keyword_array = NULL;
    self->surrogate_array = NULL;
    self->symbol_array = NULL;
    self->name = NULL;
    initialize_symbol_processing_environment(self);
    return (self);
  }
}

Object* access_symbol_processing_environment_slot_value(Symbol_Processing_Environment* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_SYMBOLS_NAME) {
    if (setvalueP) {
      self->name = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->name));
    }
  }
  else if (slotname == SYM_SYMBOLS_SYMBOL_ARRAY) {
    if (setvalueP) {
      self->symbol_array = ((Extensible_Symbol_Array*)(value));
    }
    else {
      return (self->symbol_array);
    }
  }
  else if (slotname == SYM_SYMBOLS_SURROGATE_ARRAY) {
    if (setvalueP) {
      self->surrogate_array = ((Extensible_Symbol_Array*)(value));
    }
    else {
      return (self->surrogate_array);
    }
  }
  else if (slotname == SYM_SYMBOLS_KEYWORD_ARRAY) {
    if (setvalueP) {
      self->keyword_array = ((Extensible_Symbol_Array*)(value));
    }
    else {
      return (self->keyword_array);
    }
  }
  else if (slotname == SYM_SYMBOLS_KEYWORD_OFFSET_TABLE) {
    if (setvalueP) {
      self->keyword_offset_table = ((String_To_Integer_Hash_Table*)(value));
    }
    else {
      return (self->keyword_offset_table);
    }
  }
  else if (slotname == SYM_SYMBOLS_INDEXICAL_ARRAY) {
    if (setvalueP) {
      self->indexical_array = ((Extensible_Symbol_Array*)(value));
    }
    else {
      return (self->indexical_array);
    }
  }
  else if (slotname == SYM_SYMBOLS_CARDINAL_MODULES) {
    if (setvalueP) {
      self->cardinal_modules = ((List*)(value));
    }
    else {
      return (self->cardinal_modules);
    }
  }
  else if (slotname == SYM_SYMBOLS_CURRENT_CONTEXT) {
    if (setvalueP) {
      self->current_context = ((Context*)(value));
    }
    else {
      return (self->current_context);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Symbol_Processing_Environment::primary_type() {
  { Symbol_Processing_Environment* self = this;

    return (SGT_SYMBOLS_SYMBOL_PROCESSING_ENVIRONMENT);
  }
}

void initialize_symbol_processing_environment(Symbol_Processing_Environment* self) {
  self->symbol_array = new_extensible_symbol_array(oINITIAL_SYMBOL_ARRAY_SIZEo);
  self->surrogate_array = new_extensible_symbol_array(oINITIAL_SYMBOL_ARRAY_SIZEo);
  self->keyword_array = new_extensible_symbol_array(oINITIAL_SYMBOL_ARRAY_SIZEo);
  self->indexical_array = new_extensible_symbol_array(oINITIAL_SYMBOL_ARRAY_SIZEo);
}

void switch_to_symbol_processing_environment(Symbol_Processing_Environment* env) {
  oSYMBOL_PROCESSING_ENVIRONMENTo->current_context = oCONTEXTo;
  oSYMBOL_ARRAYo = env->symbol_array;
  oSURROGATE_ARRAYo = env->surrogate_array;
  oKEYWORD_ARRAYo = env->keyword_array;
  oKEYWORD_OFFSET_TABLEo = env->keyword_offset_table;
  oINDEXICAL_ARRAYo = env->indexical_array;
  env->current_context->change_context();
  oSYMBOL_PROCESSING_ENVIRONMENTo = env;
}

void Extensible_Symbol_Array::free() {
  { Extensible_Symbol_Array* table = this;

    { Object* entry = NULL;

      { int i = NULL_INTEGER;
        int iter_001 = 0;
        int upper_bound_001 = table->top_symbol_offset;
        boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

        while (unboundedP_001 ||
            (iter_001 <= upper_bound_001)) {
          {
            i = iter_001;
            iter_001 = iter_001 + 1;
          }
          entry = table->nth(i);
          if (entry != NULL) {
            entry->free();
          }
        }
      }
      unmake(table);
    }
  }
}

void Symbol_Processing_Environment::free() {
  { Symbol_Processing_Environment* env = this;

    env->symbol_array->free();
    env->surrogate_array->free();
    env->keyword_array->free();
    env->keyword_offset_table->free();
    env->indexical_array->free();
    unmake(env);
  }
}

Symbol_Processing_Environment* create_stella_translation_environment() {
  { Symbol_Processing_Environment* env = new_symbol_processing_environment();

    env->name = "Stella system translation environment";
    oALTERNATE_STELLA_MODULEo = define_module("/ALTERNATE-STELLA", ((Cons*)(unstringify("(:uses ())"))));
    env->cardinal_modules->insert(oALTERNATE_STELLA_MODULEo);
    oSTELLA_TRANSLATION_ENVIRONMENTo = env;
    return (env);
  }
}

void destroy_stella_translation_environment() {
  destroy_module(((Module*)(oSTELLA_TRANSLATION_ENVIRONMENTo->cardinal_modules->first())));
  oSTELLA_TRANSLATION_ENVIRONMENTo->free();
}

void startup_symbols() {
  if (current_startup_time_phaseP(0)) {
    if (oFIXED_SYMBOL_ARRAYo == NULL) {
      initialize_symbols_and_modules();
    }
    initialize_parsing_tables();
  }
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
            SYM_SYMBOLS_oSYMBOL_ARRAYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*SYMBOL-ARRAY*", NULL, 0)));
            SYM_SYMBOLS_oSURROGATE_ARRAYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*SURROGATE-ARRAY*", NULL, 0)));
            SYM_SYMBOLS_oKEYWORD_ARRAYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*KEYWORD-ARRAY*", NULL, 0)));
            SYM_SYMBOLS_oINDEXICAL_ARRAYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*INDEXICAL-ARRAY*", NULL, 0)));
            SYM_SYMBOLS_oKEYWORD_OFFSET_TABLEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*KEYWORD-OFFSET-TABLE*", NULL, 0)));
            SYM_SYMBOLS_oFIXED_SYMBOL_ARRAYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*FIXED-SYMBOL-ARRAY*", NULL, 0)));
            SYM_SYMBOLS_oFIXED_SURROGATE_ARRAYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*FIXED-SURROGATE-ARRAY*", NULL, 0)));
            SYM_SYMBOLS_oFIXED_KEYWORD_ARRAYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*FIXED-KEYWORD-ARRAY*", NULL, 0)));
            SYM_SYMBOLS_oFIXED_INDEXICAL_ARRAYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*FIXED-INDEXICAL-ARRAY*", NULL, 0)));
            SYM_SYMBOLS_oCONTEXTo = ((Symbol*)(intern_rigid_symbol_wrt_module("*CONTEXT*", NULL, 0)));
            SYM_SYMBOLS_oMODULEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*MODULE*", NULL, 0)));
            KWD_SYMBOLS_OTHER = ((Keyword*)(intern_rigid_symbol_wrt_module("OTHER", NULL, 2)));
            KWD_SYMBOLS_DIGIT = ((Keyword*)(intern_rigid_symbol_wrt_module("DIGIT", NULL, 2)));
            KWD_SYMBOLS_LETTER = ((Keyword*)(intern_rigid_symbol_wrt_module("LETTER", NULL, 2)));
            KWD_SYMBOLS_SYMBOL_CONSTITUENT = ((Keyword*)(intern_rigid_symbol_wrt_module("SYMBOL-CONSTITUENT", NULL, 2)));
            KWD_SYMBOLS_SYMBOL_QUALIFIER = ((Keyword*)(intern_rigid_symbol_wrt_module("SYMBOL-QUALIFIER", NULL, 2)));
            KWD_SYMBOLS_ESCAPE = ((Keyword*)(intern_rigid_symbol_wrt_module("ESCAPE", NULL, 2)));
            KWD_SYMBOLS_OPEN_DELIMITER = ((Keyword*)(intern_rigid_symbol_wrt_module("OPEN-DELIMITER", NULL, 2)));
            KWD_SYMBOLS_CLOSE_DELIMITER = ((Keyword*)(intern_rigid_symbol_wrt_module("CLOSE-DELIMITER", NULL, 2)));
            KWD_SYMBOLS_PAIRED_DELIMITER = ((Keyword*)(intern_rigid_symbol_wrt_module("PAIRED-DELIMITER", NULL, 2)));
            KWD_SYMBOLS_WHITE_SPACE = ((Keyword*)(intern_rigid_symbol_wrt_module("WHITE-SPACE", NULL, 2)));
            SYM_SYMBOLS_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("NAME", NULL, 0)));
            SYM_SYMBOLS_SYMBOL_ARRAY = ((Symbol*)(intern_rigid_symbol_wrt_module("SYMBOL-ARRAY", NULL, 0)));
            SYM_SYMBOLS_SURROGATE_ARRAY = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE-ARRAY", NULL, 0)));
            SYM_SYMBOLS_KEYWORD_ARRAY = ((Symbol*)(intern_rigid_symbol_wrt_module("KEYWORD-ARRAY", NULL, 0)));
            SYM_SYMBOLS_KEYWORD_OFFSET_TABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("KEYWORD-OFFSET-TABLE", NULL, 0)));
            SYM_SYMBOLS_INDEXICAL_ARRAY = ((Symbol*)(intern_rigid_symbol_wrt_module("INDEXICAL-ARRAY", NULL, 0)));
            SYM_SYMBOLS_CARDINAL_MODULES = ((Symbol*)(intern_rigid_symbol_wrt_module("CARDINAL-MODULES", NULL, 0)));
            SYM_SYMBOLS_CURRENT_CONTEXT = ((Symbol*)(intern_rigid_symbol_wrt_module("CURRENT-CONTEXT", NULL, 0)));
            SGT_SYMBOLS_SYMBOL_PROCESSING_ENVIRONMENT = ((Surrogate*)(intern_rigid_symbol_wrt_module("SYMBOL-PROCESSING-ENVIRONMENT", NULL, 1)));
          }
          if (current_startup_time_phaseP(4)) {
            oCHARACTER_TYPE_TABLEo = create_character_type_table();
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("SYMBOL-PROCESSING-ENVIRONMENT", "(DEFCLASS SYMBOL-PROCESSING-ENVIRONMENT (STANDARD-OBJECT) :DOCUMENTATION \"Contains symbol arrays and other environment pointers\nsufficient to save the state of a Stella symbolic process.\" :SLOTS ((NAME :TYPE STRING) (SYMBOL-ARRAY :TYPE (EXTENSIBLE-SYMBOL-ARRAY OF SYMBOL)) (SURROGATE-ARRAY :TYPE (EXTENSIBLE-SYMBOL-ARRAY OF SURROGATE)) (KEYWORD-ARRAY :TYPE (EXTENSIBLE-SYMBOL-ARRAY OF KEYWORD)) (KEYWORD-OFFSET-TABLE :TYPE STRING-TO-INTEGER-HASH-TABLE :ALLOCATION :EMBEDDED) (INDEXICAL-ARRAY :TYPE (EXTENSIBLE-SYMBOL-ARRAY OF INDEXICAL)) (CARDINAL-MODULES :TYPE (LIST OF MODULE) :ALLOCATION :EMBEDDED) (CURRENT-CONTEXT :TYPE CONTEXT)) :INITIALIZER INITIALIZE-SYMBOL-PROCESSING-ENVIRONMENT)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_symbol_processing_environment));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_symbol_processing_environment_slot_value));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("NEXT-FREE-OFFSET", "EXTENSIBLE-SYMBOL-ARRAY", "(DEFUN (NEXT-FREE-OFFSET INTEGER) ((SELF EXTENSIBLE-SYMBOL-ARRAY)))");

              method->function_code = ((cpp_function_code)(&next_free_offset));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-SYMBOL-OFFSET", "EXTENSIBLE-SYMBOL-ARRAY", "(DEFUN FREE-SYMBOL-OFFSET ((SELF EXTENSIBLE-SYMBOL-ARRAY) (OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&free_symbol_offset));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-TO-SYMBOL-ARRAY-AT", "EXTENSIBLE-SYMBOL-ARRAY", "(DEFUN ADD-TO-SYMBOL-ARRAY-AT ((ARRAY EXTENSIBLE-SYMBOL-ARRAY) (OFFSET INTEGER) (SYMBOL GENERALIZED-SYMBOL)))");

              method->function_code = ((cpp_function_code)(&add_to_symbol_array_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-TO-SYMBOL-ARRAY", "EXTENSIBLE-SYMBOL-ARRAY", "(DEFUN (ADD-TO-SYMBOL-ARRAY INTEGER) ((ARRAY EXTENSIBLE-SYMBOL-ARRAY) (SYMBOL GENERALIZED-SYMBOL)))");

              method->function_code = ((cpp_function_code)(&add_to_symbol_array));
            }
            { Method_Slot* method = define_method_from_stringified_source("LEGAL-SYMBOL-ARRAY-OFFSET?", "EXTENSIBLE-SYMBOL-ARRAY", "(DEFUN (LEGAL-SYMBOL-ARRAY-OFFSET? BOOLEAN) ((ARRAY EXTENSIBLE-SYMBOL-ARRAY) (OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&legal_symbol_array_offsetP));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-SYM", "INTEGER", "(DEFUN (GET-SYM SYMBOL) ((OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&get_sym));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-SGT", "INTEGER", "(DEFUN (GET-SGT SURROGATE) ((OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&get_sgt));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-KWD", "INTEGER", "(DEFUN (GET-KWD KEYWORD) ((OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&get_kwd));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-IDX", "INTEGER", "(DEFUN (GET-IDX INDEXICAL) ((OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&get_idx));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-GENERALIZED-SYMBOL-FROM-OFFSET", "EXTENSIBLE-SYMBOL-ARRAY", "(DEFUN (GET-GENERALIZED-SYMBOL-FROM-OFFSET GENERALIZED-SYMBOL) ((SYMBOLARRAY EXTENSIBLE-SYMBOL-ARRAY) (OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&get_generalized_symbol_from_offset));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-SYM-FROM-OFFSET", "INTEGER", "(DEFUN (GET-SYM-FROM-OFFSET SYMBOL) ((OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&get_sym_from_offset));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-SGT-FROM-OFFSET", "INTEGER", "(DEFUN (GET-SGT-FROM-OFFSET SURROGATE) ((OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&get_sgt_from_offset));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-KWD-FROM-OFFSET", "INTEGER", "(DEFUN (GET-KWD-FROM-OFFSET KEYWORD) ((OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&get_kwd_from_offset));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-IDX-FROM-OFFSET", "INTEGER", "(DEFUN (GET-IDX-FROM-OFFSET INDEXICAL) ((OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&get_idx_from_offset));
            }
            { Method_Slot* method = define_method_from_stringified_source("SELECT-SYMBOL-OFFSET-TABLE", "MODULE", "(DEFUN (SELECT-SYMBOL-OFFSET-TABLE STRING-TO-INTEGER-HASH-TABLE) ((MODULE MODULE) (KINDOFSYM INTEGER)))");

              method->function_code = ((cpp_function_code)(&select_symbol_offset_table));
            }
            { Method_Slot* method = define_method_from_stringified_source("SELECT-SYMBOL-ARRAY", "INTEGER", "(DEFUN (SELECT-SYMBOL-ARRAY EXTENSIBLE-SYMBOL-ARRAY) ((KINDOFSYM INTEGER)))");

              method->function_code = ((cpp_function_code)(&select_symbol_array));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-RIGID-SYMBOL-LOCALLY", "STRING", "(DEFUN (LOOKUP-RIGID-SYMBOL-LOCALLY GENERALIZED-SYMBOL) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))");

              method->function_code = ((cpp_function_code)(&lookup_rigid_symbol_locally));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-VISIBLE-RIGID-SYMBOLS-WRT-MODULE", "STRING", "(DEFUN (YIELD-VISIBLE-RIGID-SYMBOLS-WRT-MODULE (CONS OF GENERALIZED-SYMBOL)) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))");

              method->function_code = ((cpp_function_code)(&yield_visible_rigid_symbols_wrt_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("VISIBLE-RIGID-SYMBOLS-WRT-MODULE", "STRING", "(DEFUN (VISIBLE-RIGID-SYMBOLS-WRT-MODULE (ITERATOR OF GENERALIZED-SYMBOL)) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))");

              method->function_code = ((cpp_function_code)(&visible_rigid_symbols_wrt_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-RIGID-SYMBOL-OFFSET-WRT-MODULE", "STRING", "(DEFUN (LOOKUP-RIGID-SYMBOL-OFFSET-WRT-MODULE INTEGER) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))");

              method->function_code = ((cpp_function_code)(&lookup_rigid_symbol_offset_wrt_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-RIGID-SYMBOL-WRT-MODULE", "STRING", "(DEFUN (LOOKUP-RIGID-SYMBOL-WRT-MODULE GENERALIZED-SYMBOL) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))");

              method->function_code = ((cpp_function_code)(&lookup_rigid_symbol_wrt_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-RIGID-SYMBOL", "STRING", "(DEFUN (LOOKUP-RIGID-SYMBOL GENERALIZED-SYMBOL) ((NAME STRING) (KINDOFSYM INTEGER)) :DOCUMENTATION \"Return the symbol named 'name'.  Case sensitive.\")");

              method->function_code = ((cpp_function_code)(&lookup_rigid_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-INDEXICAL-SYMBOL-OFFSET-WRT-MODULE", "STRING", "(DEFUN (LOOKUP-INDEXICAL-SYMBOL-OFFSET-WRT-MODULE INTEGER) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))");

              method->function_code = ((cpp_function_code)(&lookup_indexical_symbol_offset_wrt_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-INDEXICAL-SYMBOL-WRT-MODULE", "STRING", "(DEFUN (LOOKUP-INDEXICAL-SYMBOL-WRT-MODULE GENERALIZED-SYMBOL) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))");

              method->function_code = ((cpp_function_code)(&lookup_indexical_symbol_wrt_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-INDEXICAL-SYMBOL", "STRING", "(DEFUN (LOOKUP-INDEXICAL-SYMBOL GENERALIZED-SYMBOL) ((NAME STRING) (KINDOFSYM INTEGER)) :DOCUMENTATION \"Return the indexical named 'name'.\")");

              method->function_code = ((cpp_function_code)(&lookup_indexical_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-SYMBOL", "STRING", "(DEFUN (LOOKUP-SYMBOL SYMBOL) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&lookup_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-SYMBOL-IN-MODULE", "STRING", "(DEFUN (LOOKUP-SYMBOL-IN-MODULE SYMBOL) ((NAME STRING) (MODULE MODULE) (LOCAL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&lookup_symbol_in_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-SURROGATE", "STRING", "(DEFUN (LOOKUP-SURROGATE SURROGATE) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&lookup_surrogate));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-SURROGATE-IN-MODULE", "STRING", "(DEFUN (LOOKUP-SURROGATE-IN-MODULE SURROGATE) ((NAME STRING) (MODULE MODULE) (LOCAL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&lookup_surrogate_in_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-KEYWORD", "STRING", "(DEFUN (LOOKUP-KEYWORD KEYWORD) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&lookup_keyword));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-INDEXICAL", "STRING", "(DEFUN (LOOKUP-INDEXICAL INDEXICAL) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&lookup_indexical));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-INTERN-GENERALIZED-SYMBOL", "STRING", "(DEFUN (HELP-INTERN-GENERALIZED-SYMBOL GENERALIZED-SYMBOL) ((NAME STRING) (KINDOFSYM INTEGER) (ARRAY EXTENSIBLE-SYMBOL-ARRAY) (OFFSET INTEGER) (MODULE MODULE)))");

              method->function_code = ((cpp_function_code)(&help_intern_generalized_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-RIGID-SYMBOL-WRT-MODULE", "STRING", "(DEFUN (INTERN-RIGID-SYMBOL-WRT-MODULE GENERALIZED-SYMBOL) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)) :DOCUMENTATION \"Return a newly-created or existing rigid symbol with\nname 'name'.\")");

              method->function_code = ((cpp_function_code)(&intern_rigid_symbol_wrt_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-RIGID-SYMBOL-LOCALLY", "STRING", "(DEFUN (INTERN-RIGID-SYMBOL-LOCALLY GENERALIZED-SYMBOL) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)) :DOCUMENTATION \"Return a newly-created or existing rigid symbol\ninterned into the module 'module' with name 'name'.\")");

              method->function_code = ((cpp_function_code)(&intern_rigid_symbol_locally));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-INDEXICAL-SYMBOL-WRT-MODULE", "STRING", "(DEFUN (INTERN-INDEXICAL-SYMBOL-WRT-MODULE GENERALIZED-SYMBOL) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)) :DOCUMENTATION \"Return a newly-created or existing indexical with\nname 'name'.\")");

              method->function_code = ((cpp_function_code)(&intern_indexical_symbol_wrt_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-RIGID-SYMBOL-CASE-SENSITIVELY", "STRING", "(DEFUN (INTERN-RIGID-SYMBOL-CASE-SENSITIVELY GENERALIZED-SYMBOL) ((NAME STRING) (KINDOFSYM INTEGER)))");

              method->function_code = ((cpp_function_code)(&intern_rigid_symbol_case_sensitively));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-PERMANENT-SYMBOL", "STRING", "(DEFUN (INTERN-PERMANENT-SYMBOL SYMBOL) ((NAME STRING)) :DOCUMENTATION \"Return a newly-created or existing permanent symbol with\nname 'name'.\")");

              method->function_code = ((cpp_function_code)(&intern_permanent_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-SYMBOL", "STRING", "(DEFUN (INTERN-SYMBOL SYMBOL) ((NAME STRING)) :DOCUMENTATION \"Return a newly-created or existing symbol with name\n'name'.  Storage note: a COPY of 'name' is stored in the symbol.\")");

              method->function_code = ((cpp_function_code)(&intern_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-DERIVED-SYMBOL", "GENERALIZED-SYMBOL", "(DEFUN (INTERN-DERIVED-SYMBOL SYMBOL) ((BASESYMBOL GENERALIZED-SYMBOL) (NEWNAME STRING)) :DOCUMENTATION \"Return a newly-created or existing symbol with name\n'newName' which is interned in the same module as 'baseSymbol'.\")");

              method->function_code = ((cpp_function_code)(&intern_derived_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-SURROGATE", "STRING", "(DEFUN (INTERN-SURROGATE SURROGATE) ((NAME STRING)) :DOCUMENTATION \"Return a newly-created or existing surrogate with\nname 'name'.\")");

              method->function_code = ((cpp_function_code)(&intern_surrogate));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-INDEXICAL", "STRING", "(DEFUN (INTERN-INDEXICAL INDEXICAL) ((NAME STRING)) :DOCUMENTATION \"Return a newly-created or existing indexical with\nname 'name', interned in '(cardinal-module *module*)'.\")");

              method->function_code = ((cpp_function_code)(&intern_indexical));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-PERMANENT-KEYWORD", "STRING", "(DEFUN (INTERN-PERMANENT-KEYWORD KEYWORD) ((NAME STRING)) :DOCUMENTATION \"Return a newly-created or existing permanent keyword with\nname 'name'.\")");

              method->function_code = ((cpp_function_code)(&intern_permanent_keyword));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-KEYWORD", "STRING", "(DEFUN (INTERN-KEYWORD KEYWORD) ((NAME STRING)) :DOCUMENTATION \"Return a newly-created or existing keyword with name\n'name'.  Storage note: a COPY of 'name' is stored in the keyword\")");

              method->function_code = ((cpp_function_code)(&intern_keyword));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNINTERN-SYMBOL", "SYMBOL", "(DEFUN UNINTERN-SYMBOL ((SELF SYMBOL)) :DOCUMENTATION \"Remove `self' from its home module and the symbol table.\")");

              method->function_code = ((cpp_function_code)(&unintern_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNINTERN-SURROGATE", "SURROGATE", "(DEFUN UNINTERN-SURROGATE ((SELF SURROGATE)) :DOCUMENTATION \"Remove `self' from its home module and the surrogate table.\")");

              method->function_code = ((cpp_function_code)(&unintern_surrogate));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-BOOTSTRAP-SYMBOL-AT", "STRING", "(DEFUN (INTERN-BOOTSTRAP-SYMBOL-AT GENERALIZED-SYMBOL) ((NAME STRING) (OFFSET INTEGER) (KINDOFSYM INTEGER)) :DOCUMENTATION \"Interns a symbol, or keyword with\nname' and symbol-id 'offset'.\nIf a symbol with that ID already existed, an error is signaled.  This\nfunction is used to recreate the symbol table in a way where symbol IDs\nwhich got hardwired into translated code will refer to the correct objects.\")");

              method->function_code = ((cpp_function_code)(&intern_bootstrap_symbol_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-SYMBOL-AT", "STRING", "(DEFUN (INTERN-SYMBOL-AT SYMBOL) ((NAME STRING) (OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&intern_symbol_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-SURROGATE-AT", "STRING", "(DEFUN (INTERN-SURROGATE-AT SURROGATE) ((NAME STRING) (OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&intern_surrogate_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-KEYWORD-AT", "STRING", "(DEFUN (INTERN-KEYWORD-AT KEYWORD) ((NAME STRING) (OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&intern_keyword_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-INDEXICAL-AT", "STRING", "(DEFUN (INTERN-INDEXICAL-AT INDEXICAL) ((NAME STRING) (OFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&intern_indexical_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-KERNEL-MODULE", "MODULE", "(DEFUN INITIALIZE-KERNEL-MODULE ((MODULE MODULE) (NAME STRING) (FULLNAME STRING) (PARENT MODULE)))");

              method->function_code = ((cpp_function_code)(&initialize_kernel_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-MODULES", NULL, "(DEFUN INITIALIZE-MODULES ())");

              method->function_code = ((cpp_function_code)(&initialize_modules));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-SYMBOLS-AND-MODULES", NULL, "(DEFUN INITIALIZE-SYMBOLS-AND-MODULES ())");

              method->function_code = ((cpp_function_code)(&initialize_symbols_and_modules));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-TRANSIENT-SYMBOL", "STRING", "(DEFUN (LOOKUP-TRANSIENT-SYMBOL SYMBOL) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&lookup_transient_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-TRANSIENT-KEYWORD", "STRING", "(DEFUN (LOOKUP-TRANSIENT-KEYWORD KEYWORD) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&lookup_transient_keyword));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-TRANSIENT-SYMBOL", "STRING", "(DEFUN (INTERN-TRANSIENT-SYMBOL SYMBOL) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&intern_transient_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-TRANSIENT-KEYWORD", "STRING", "(DEFUN (INTERN-TRANSIENT-KEYWORD KEYWORD) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&intern_transient_keyword));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-TRANSIENT-SYMBOLS", NULL, "(DEFUN FREE-TRANSIENT-SYMBOLS ())");

              method->function_code = ((cpp_function_code)(&free_transient_symbols));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-TRANSIENT-KEYWORDS", NULL, "(DEFUN FREE-TRANSIENT-KEYWORDS ())");

              method->function_code = ((cpp_function_code)(&free_transient_keywords));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-COMMON-LISP-SYMBOL", "STRING", "(DEFUN (INTERN-COMMON-LISP-SYMBOL SYMBOL) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&intern_common_lisp_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYMBOL-COMMON-LISP?", "SYMBOL", "(DEFUN (SYMBOL-COMMON-LISP? BOOLEAN) ((SELF SYMBOL)))");

              method->function_code = ((cpp_function_code)(&symbol_common_lispP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMMON-LISP-SYMBOL?", "OBJECT", "(DEFUN (COMMON-LISP-SYMBOL? BOOLEAN) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&common_lisp_symbolP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-PARSING-TABLES", NULL, "(DEFUN INITIALIZE-PARSING-TABLES () :DOCUMENTATION \"Create indices for recording transient symbols and\nCommon Lisp symbols while parsing.\")");

              method->function_code = ((cpp_function_code)(&initialize_parsing_tables));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-GENSYM-NAME", "STRING", "(DEFUN (YIELD-GENSYM-NAME STRING) ((PREFIX STRING) (COUNTER INTEGER)))");

              method->function_code = ((cpp_function_code)(&yield_gensym_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("GENSYM", "STRING", "(DEFUN (GENSYM SYMBOL) ((PREFIX STRING)) :DOCUMENTATION \"Return a transient symbol with a name beginning with\n'prefix' and ending with a globally gensym'd integer.\")");

              method->function_code = ((cpp_function_code)(&gensym));
            }
            { Method_Slot* method = define_method_from_stringified_source("SURROGATIFY", "SURROGATE", "(DEFMETHOD (SURROGATIFY SURROGATE) ((SELF SURROGATE)))");

              method->method_code = ((cpp_method_code)(&Surrogate::surrogatify));
            }
            { Method_Slot* method = define_method_from_stringified_source("SURROGATIFY", "SYMBOL", "(DEFMETHOD (SURROGATIFY SURROGATE) ((SELF SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Symbol::surrogatify));
            }
            { Method_Slot* method = define_method_from_stringified_source("SURROGATIFY", "STRING", "(DEFMETHOD (SURROGATIFY SURROGATE) ((SELF STRING)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("SURROGATIFY", "CONS", "(DEFMETHOD (SURROGATIFY SURROGATE) ((SELF CONS)))");

              method->method_code = ((cpp_method_code)(&Cons::surrogatify));
            }
            { Method_Slot* method = define_method_from_stringified_source("SURROGATIFY", "OBJECT", "(DEFMETHOD (SURROGATIFY SURROGATE) ((SELF OBJECT)))");

              method->method_code = ((cpp_method_code)(&Object::surrogatify));
            }
            { Method_Slot* method = define_method_from_stringified_source("TYPIFY", "OBJECT", "(DEFUN (TYPIFY TYPE) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&typify));
            }
            { Method_Slot* method = define_method_from_stringified_source("KEYWORDIFY", "KEYWORD", "(DEFMETHOD (KEYWORDIFY KEYWORD) ((SELF KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Keyword::keywordify));
            }
            { Method_Slot* method = define_method_from_stringified_source("KEYWORDIFY", "TRANSIENT-KEYWORD", "(DEFMETHOD (KEYWORDIFY KEYWORD) ((SELF TRANSIENT-KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Transient_Keyword::keywordify));
            }
            { Method_Slot* method = define_method_from_stringified_source("KEYWORDIFY", "SYMBOL", "(DEFMETHOD (KEYWORDIFY KEYWORD) ((SELF SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Symbol::keywordify));
            }
            { Method_Slot* method = define_method_from_stringified_source("KEYWORDIFY", "STRING", "(DEFMETHOD (KEYWORDIFY KEYWORD) ((SELF STRING)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("IN-PLACE-OBJECTS-TO-SYMBOLS", "CONS", "(DEFUN IN-PLACE-OBJECTS-TO-SYMBOLS ((CONSLIST CONS)))");

              method->function_code = ((cpp_function_code)(&in_place_objects_to_symbols));
            }
            { Method_Slot* method = define_method_from_stringified_source("IN-PLACE-OBJECTS-TO-TYPES", "CONS", "(DEFUN IN-PLACE-OBJECTS-TO-TYPES ((CONSLIST CONS)))");

              method->function_code = ((cpp_function_code)(&in_place_objects_to_types));
            }
            { Method_Slot* method = define_method_from_stringified_source("SURROGATE-NAME?", "STRING", "(DEFUN (SURROGATE-NAME? BOOLEAN) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&surrogate_nameP));
            }
            { Method_Slot* method = define_method_from_stringified_source("QUALIFIED-NAME?", "STRING", "(DEFUN (QUALIFIED-NAME? BOOLEAN) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&qualified_nameP));
            }
            { Method_Slot* method = define_method_from_stringified_source("KEYWORD-NAME?", "STRING", "(DEFUN (KEYWORD-NAME? BOOLEAN) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&keyword_nameP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-GENERALIZED-SYMBOL", "STRING", "(DEFUN (INTERN-GENERALIZED-SYMBOL GENERALIZED-SYMBOL) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&intern_generalized_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-FULL-NAME", "STRING", "(DEFUN (COMPUTE-FULL-NAME STRING) ((NAME STRING) (MODULE MODULE)))");

              method->function_code = ((cpp_function_code)(&compute_full_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOCAL-PRINT-NAME", "GENERALIZED-SYMBOL", "(DEFMETHOD (LOCAL-PRINT-NAME STRING) ((SELF GENERALIZED-SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Generalized_Symbol::local_print_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOCAL-PRINT-NAME", "SURROGATE", "(DEFMETHOD (LOCAL-PRINT-NAME STRING) ((SELF SURROGATE)))");

              method->method_code = ((cpp_method_code)(&Surrogate::local_print_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("RELATIVE-NAME", "GENERALIZED-SYMBOL", "(DEFMETHOD (RELATIVE-NAME STRING) ((SELF GENERALIZED-SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Generalized_Symbol::relative_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("VISIBLE-NAME", "GENERALIZED-SYMBOL", "(DEFMETHOD (VISIBLE-NAME STRING) ((SELF GENERALIZED-SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Generalized_Symbol::visible_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("ESCAPED-CHARACTER?", "STRING", "(DEFUN (ESCAPED-CHARACTER? BOOLEAN) ((STRING STRING) (POSITION INTEGER)))");

              method->function_code = ((cpp_function_code)(&escaped_characterP));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNESCAPE-CHARACTER", "STRING", "(DEFUN (UNESCAPE-CHARACTER STRING) ((STRING STRING) (CHARACTER CHARACTER)))");

              method->function_code = ((cpp_function_code)(&unescape_character));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYMBOL-VALUE", "SYMBOL", "(DEFUN (SYMBOL-VALUE OBJECT) ((SYMBOL SYMBOL)) :DOCUMENTATION \"Return the value of 'symbol'.  Note, that this value is not\nvisible to code that references a variable with the same name as 'symbol'.\nThe 'symbol-value' is simply a special property that can always be accessed\nin constant time.  The 'symbol-value' of a symbol can be changed with 'setf'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&symbol_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYMBOL-VALUE-SETTER", "SYMBOL", "(DEFUN (SYMBOL-VALUE-SETTER OBJECT) ((SYMBOL SYMBOL) (VALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&symbol_value_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYMBOL-PLIST", "SYMBOL", "(DEFUN (SYMBOL-PLIST CONS) ((SYMBOL SYMBOL)) :DOCUMENTATION \"Return the property list of 'symbol'.  The 'symbol-plist'\nof a symbol can be set with 'setf'.  IMPORTANT: Property list are modified \ndestructively, hence, if you supply it as a whole make sure to always supply\na modfiable copy, e.g., by using 'bquote'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&symbol_plist));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYMBOL-PLIST-SETTER", "SYMBOL", "(DEFUN (SYMBOL-PLIST-SETTER CONS) ((SYMBOL SYMBOL) (PLIST CONS)))");

              method->function_code = ((cpp_function_code)(&symbol_plist_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYMBOL-PROPERTY", "SYMBOL", "(DEFUN (SYMBOL-PROPERTY OBJECT) ((SYMBOL SYMBOL) (KEY STANDARD-OBJECT)) :DOCUMENTATION \"Return the property of 'symbol' whose key is 'eq?' to 'key'.\nSymbol properties can be set with 'setf'.\")");

              method->function_code = ((cpp_function_code)(&symbol_property));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYMBOL-PROPERTY-SETTER", "SYMBOL", "(DEFUN (SYMBOL-PROPERTY-SETTER OBJECT) ((SYMBOL SYMBOL) (VALUE OBJECT) (KEY STANDARD-OBJECT)))");

              method->function_code = ((cpp_function_code)(&symbol_property_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-CHARACTER-TYPE-TABLE", NULL, "(DEFUN (CREATE-CHARACTER-TYPE-TABLE (VECTOR OF KEYWORD)) ())");

              method->function_code = ((cpp_function_code)(&create_character_type_table));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYMBOL-CONSTITUENT-CHARACTER?", "CHARACTER", "(DEFUN (SYMBOL-CONSTITUENT-CHARACTER? BOOLEAN) ((CHARACTER CHARACTER)))");

              method->function_code = ((cpp_function_code)(&symbol_constituent_characterP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-SYMBOL", "SYMBOL", "(DEFUN PRINT-SYMBOL ((SELF SYMBOL) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-SYMBOL-PROCESSING-ENVIRONMENT", "SYMBOL-PROCESSING-ENVIRONMENT", "(DEFUN INITIALIZE-SYMBOL-PROCESSING-ENVIRONMENT ((SELF SYMBOL-PROCESSING-ENVIRONMENT)))");

              method->function_code = ((cpp_function_code)(&initialize_symbol_processing_environment));
            }
            { Method_Slot* method = define_method_from_stringified_source("SWITCH-TO-SYMBOL-PROCESSING-ENVIRONMENT", "SYMBOL-PROCESSING-ENVIRONMENT", "(DEFUN SWITCH-TO-SYMBOL-PROCESSING-ENVIRONMENT ((ENV SYMBOL-PROCESSING-ENVIRONMENT)))");

              method->function_code = ((cpp_function_code)(&switch_to_symbol_processing_environment));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE", "EXTENSIBLE-SYMBOL-ARRAY", "(DEFMETHOD FREE ((TABLE EXTENSIBLE-SYMBOL-ARRAY)))");

              method->method_code = ((cpp_method_code)(&Extensible_Symbol_Array::free));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE", "SYMBOL-PROCESSING-ENVIRONMENT", "(DEFMETHOD FREE ((ENV SYMBOL-PROCESSING-ENVIRONMENT)))");

              method->method_code = ((cpp_method_code)(&Symbol_Processing_Environment::free));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-STELLA-TRANSLATION-ENVIRONMENT", NULL, "(DEFUN (CREATE-STELLA-TRANSLATION-ENVIRONMENT SYMBOL-PROCESSING-ENVIRONMENT) ())");

              method->function_code = ((cpp_function_code)(&create_stella_translation_environment));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-STELLA-TRANSLATION-ENVIRONMENT", NULL, "(DEFUN DESTROY-STELLA-TRANSLATION-ENVIRONMENT ())");

              method->function_code = ((cpp_function_code)(&destroy_stella_translation_environment));
            }
            define_method_from_stringified_source("STARTUP-SYMBOLS", NULL, "(DEFUN STARTUP-SYMBOLS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *SYMBOL-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF SYMBOL) NULL)");
            { Global_Variable* global = SYM_SYMBOLS_oSYMBOL_ARRAYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Osymbol_arrayO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Osymbol_arrayO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *SURROGATE-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF SURROGATE) NULL)");
            { Global_Variable* global = SYM_SYMBOLS_oSURROGATE_ARRAYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Osurrogate_arrayO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Osurrogate_arrayO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *KEYWORD-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF KEYWORD) NULL)");
            { Global_Variable* global = SYM_SYMBOLS_oKEYWORD_ARRAYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Okeyword_arrayO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Okeyword_arrayO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *INDEXICAL-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF INDEXICAL) NULL)");
            { Global_Variable* global = SYM_SYMBOLS_oINDEXICAL_ARRAYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Oindexical_arrayO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Oindexical_arrayO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *KEYWORD-OFFSET-TABLE* STRING-TO-INTEGER-HASH-TABLE NULL)");
            { Global_Variable* global = SYM_SYMBOLS_oKEYWORD_OFFSET_TABLEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Okeyword_offset_tableO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Okeyword_offset_tableO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *FIXED-SYMBOL-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF SYMBOL) NULL)");
            { Global_Variable* global = SYM_SYMBOLS_oFIXED_SYMBOL_ARRAYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Ofixed_symbol_arrayO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Ofixed_symbol_arrayO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *FIXED-SURROGATE-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF SURROGATE) NULL)");
            { Global_Variable* global = SYM_SYMBOLS_oFIXED_SURROGATE_ARRAYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Ofixed_surrogate_arrayO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Ofixed_surrogate_arrayO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *FIXED-KEYWORD-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF KEYWORD) NULL)");
            { Global_Variable* global = SYM_SYMBOLS_oFIXED_KEYWORD_ARRAYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Ofixed_keyword_arrayO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Ofixed_keyword_arrayO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *FIXED-INDEXICAL-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF INDEXICAL) NULL)");
            { Global_Variable* global = SYM_SYMBOLS_oFIXED_INDEXICAL_ARRAYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Ofixed_indexical_arrayO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Ofixed_indexical_arrayO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *TRANSIENT-SYMBOL-LOOKUP-TABLE* STRING-HASH-TABLE NULL)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *COMMON-LISP-SYMBOL-LOOKUP-TABLE* STRING-HASH-TABLE NULL)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *TRANSIENT-KEYWORD-LOOKUP-TABLE* STRING-HASH-TABLE NULL)");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT SYMBOL-SYM INTEGER 0)");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT SURROGATE-SYM INTEGER 1)");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT KEYWORD-SYM INTEGER 2)");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT INDEXICAL-SYM INTEGER 3)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *ROOT-MODULE* MODULE NULL :DOCUMENTATION \"Pointer to the top-most module ROOT-MODULE.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-MODULE* MODULE NULL :DOCUMENTATION \"Pointer to the module STELLA containing definitions of \nSTELLA classes and methods.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *COMMON-LISP-MODULE* MODULE NULL :DOCUMENTATION \"Pointer to the module COMMON-LISP containing Common\nLisp symbols (and maybe other things).\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *ALTERNATE-STELLA-MODULE* MODULE NULL :DOCUMENTATION \"Pointer to the module ALTERNATE-STELLA containing\ndefinitions of STELLA classes and methods generated during the\ntranslation of STELLA files.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *CONTEXT* CONTEXT NULL :DOCUMENTATION \"Points to the current context (either a module or a\nworld).  Set by calls to 'change-world' and 'change-module'.\")");
            { Global_Variable* global = SYM_SYMBOLS_oCONTEXTo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OcontextO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OcontextO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *MODULE* MODULE NULL :DOCUMENTATION \"Points to the current module.  Set by calls to\n'change-context' and 'change-module'.\" :PUBLIC? TRUE)");
            { Global_Variable* global = SYM_SYMBOLS_oMODULEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OmoduleO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OmoduleO));
            }
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT SURROGATE-PREFIX-CHARACTER CHARACTER #\\@ :DOCUMENTATION \"Character used to prefix the name of a surrogate.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT MODULE-SEPARATOR-CHARACTER CHARACTER #\\/ :DOCUMENTATION \"Character used to concatenate a module name\nto a symbol or surrogate name to form a qualified name.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT MODULE-SEPARATOR-STRING STRING \"/\" :DOCUMENTATION \"String containing character used to concatenate a module name\nto a symbol or surrogate name to form a qualified name.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CONTEXT-NUMBER-COUNTER* INTEGER -2 :DOCUMENTATION \"Contains the number of the last-created\ncontext (all 'live' contexts are even-numbered).\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *GENSYM-COUNTER* INTEGER 0 :DOCUMENTATION \"Incremented once for each gensym call.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT ESCAPE-CHARACTER CHARACTER #\\!)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CHARACTER-TYPE-TABLE* (VECTOR OF KEYWORD) (CREATE-CHARACTER-TYPE-TABLE) :DOCUMENTATION \"Table of character types.  Entry 'i' represents the type\nof the character whose 'char-code' equals 'i'.  Each character is classified \nby one of the following keywords: :DIGIT, :LETTER, :SYMBOL-CONSTITUENT, \n:SYMBOL-QUALIFIER, :ESCAPE, :OPEN-DELIMITER, :CLOSE-DELIMITER, \n:PAIRED-DELIMITER, :WHITE-SPACE, or :OTHER.\" :PUBLIC? TRUE)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *INITIAL-SYMBOL-ARRAY-SIZE* INTEGER 100 :DOCUMENTATION \"Determines the default inital size of an\nEXTENSIBLE-SYMBOL-ARRAY\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *SYMBOL-PROCESSING-ENVIRONMENT* SYMBOL-PROCESSING-ENVIRONMENT NULL :DOCUMENTATION \"Points to the current symbol processing environment.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-TRANSLATION-ENVIRONMENT* SYMBOL-PROCESSING-ENVIRONMENT NULL :DOCUMENTATION \"Points to the symbol processing environment\nused to translate the Stella system.\")");
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

