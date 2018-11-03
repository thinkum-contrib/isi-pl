//  -*- Mode: C++ -*-

// modules.cc

/*--------------------------- BEGIN LICENSE BLOCK ---------------------------+
|                                                                            |
| Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          |
|                                                                            |
| The contents of this file are subject to the Mozilla Public License        |
| Version 1.1 (the "License"); you may not use this file except in           |
| compliance with the License. You may obtain a copy of the License at       |
| http://www.mozilla.org/MPL/                                                |
|                                                                            |
| Software distributed under the License is distributed on an "AS IS" basis, |
| WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   |
| for the specific language governing rights and limitations under the       |
| License.                                                                   |
|                                                                            |
| The Original Code is the STELLA Programming Language.                      |
|                                                                            |
| The Initial Developer of the Original Code is                              |
| UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
| 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
|                                                                            |
| Portions created by the Initial Developer are Copyright (C) 1996-2003      |
| the Initial Developer. All Rights Reserved.                                |
|                                                                            |
| Contributor(s):                                                            |
|                                                                            |
| Alternatively, the contents of this file may be used under the terms of    |
| either the GNU General Public License Version 2 or later (the "GPL"), or   |
| the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   |
| in which case the provisions of the GPL or the LGPL are applicable instead |
| of those above. If you wish to allow use of your version of this file only |
| under the terms of either the GPL or the LGPL, and not to allow others to  |
| use your version of this file under the terms of the MPL, indicate your    |
| decision by deleting the provisions above and replace them with the notice |
| and other provisions required by the GPL or the LGPL. If you do not delete |
| the provisions above, a recipient may use your version of this file under  |
| the terms of any one of the MPL, the GPL or the LGPL.                      |
|                                                                            |
+---------------------------- END LICENSE BLOCK ----------------------------*/

#include "stella/stella-system.hh"

namespace stella {

// Controls actions reflexive transitive closure of
//    subcontexts when a context is revised.
//    Values are ':destroy' -- destroy subcontexts;
//    ':clear' -- clear contents of subcontexts;
//    ':preserve' -- don't disturb subcontexts.
Keyword* oSUBCONTEXT_REVISION_POLICYo = NULL;

Iterator* Context::parentContexts() {
  { Context* self = this;

    return (NULL);
  }
}

Iterator* Module::parentContexts() {
  { Module* self = this;

    return (((ListIterator*)(self->parentModules->allocateIterator())));
  }
}

Iterator* World::parentContexts() {
  { World* self = this;

    return (((Cons*)(cons(self->parentContext, NIL)))->allocateDestructiveListIterator());
  }
}

Context* computeContextOrModuleFromPathname(char* pathname, boolean moduleP, boolean symbolnameP, int& _Return1) {
  { Module* context = ((pathname[0] == MODULE_SEPARATOR_CHARACTER) ? oROOT_MODULEo : ((Module*)(NULL)));
    int componentend = (((boolean)(context)) ? 0 : -1);
    int componentstart = NULL_INTEGER;
    int lastcharpos = strlen(pathname) - 1;

    while (componentend < lastcharpos) {
      componentstart = componentend + 1;
      componentend = componentstart;
      { int i = NULL_INTEGER;
        int iter000 = componentstart;
        int upperBound000 = lastcharpos;
        boolean unboundedP000 = upperBound000 == NULL_INTEGER;

        while (unboundedP000 ||
            (iter000 <= upperBound000)) {
          i = iter000;
          iter000 = iter000 + 1;
          if (!(pathname[i] == MODULE_SEPARATOR_CHARACTER)) {
            componentend = componentend + 1;
          }
          else {
            break;
          }
        }
      }
      if (symbolnameP &&
          (componentend > lastcharpos)) {
        _Return1 = componentstart;
        return ((((boolean)(context)) ? context : ((moduleP ? oMODULEo.get() : oCONTEXTo.get()))));
      }
      if (!((boolean)(context))) {
        { char* startstring = stringSubsequence(pathname, componentstart, componentend);

          context = ((Module*)(stringGetStellaContextSlowly(startstring)));
        }
      }
      else {
        { Context* value000 = NULL;

          { Context* child = NULL;
            Cons* iter001 = context->childContexts->theConsList;

            while (!(iter001 == NIL)) {
              child = ((Context*)(iter001->value));
              iter001 = iter001->rest;
              { boolean testValue000 = FALSE;

                testValue000 = (!moduleP) ||
                    isaP(child, SGT_MODULES_STELLA_MODULE);
                if (testValue000) {
                  if (componentMatchP((moduleP ? ((Module*)(child))->moduleName : ((Context*)(child))->contextName()), pathname, componentstart, componentend)) {
                    testValue000 = TRUE;
                  }
                  else {
                    {
                      testValue000 = moduleP;
                      if (testValue000) {
                        testValue000 = ((boolean)(((Module*)(child))->nicknames));
                        if (testValue000) {
                          { boolean foundP000 = FALSE;

                            { StringWrapper* nickname = NULL;
                              Cons* iter002 = ((Module*)(child))->nicknames->theConsList;

                              while (!(iter002 == NIL)) {
                                nickname = ((StringWrapper*)(iter002->value));
                                iter002 = iter002->rest;
                                if (componentMatchP(nickname->wrapperValue, pathname, componentstart, componentend)) {
                                  foundP000 = TRUE;
                                  break;
                                }
                              }
                            }
                            testValue000 = foundP000;
                          }
                        }
                      }
                    }
                  }
                }
                if (testValue000) {
                  value000 = child;
                  break;
                }
              }
            }
          }
          context = ((Module*)(value000));
        }
      }
      if (!((boolean)(context))) {
        break;
      }
    }
    if (!((boolean)(context))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "No context with name " << "`" << pathname << "'";
        throw *newNoSuchContextException(stream000->theStringReader());
      }
    }
    else {
      _Return1 = NULL_INTEGER;
      return (context);
    }
  }
}

boolean componentMatchP(char* component, char* string, int start, int end) {
  { boolean testValue000 = FALSE;

    testValue000 = strlen(component) == (end - start);
    if (testValue000) {
      { boolean alwaysP000 = TRUE;

        { char chaR = NULL_CHARACTER;
          int i = NULL_INTEGER;
          char* vector000 = component;
          int index000 = 0;
          int length000 = strlen(vector000);
          int iter000 = start;

          while (index000 < length000) {
            chaR = vector000[index000];
            index000 = index000 + 1;
            i = iter000;
            iter000 = iter000 + 1;
            if (!(chaR == string[i])) {
              alwaysP000 = FALSE;
              break;
            }
          }
        }
        testValue000 = alwaysP000;
      }
    }
    { boolean value000 = testValue000;

      return (value000);
    }
  }
}

Module* computeModuleAndBareName(char* name, char*& _Return1) {
  { Context* module = NULL;
    int barenamestart = NULL_INTEGER;

    module = computeContextOrModuleFromPathname(name, TRUE, TRUE, barenamestart);
    { Module* _return_temp = ((Module*)(module));

      _Return1 = ((barenamestart != NULL_INTEGER) ? stringSubsequence(name, barenamestart, NULL_INTEGER) : ((char*)(NULL)));
      return (_return_temp);
    }
  }
}

char* qualifiedNameModuleName(char* qualifiedname) {
  { int end = strlen(qualifiedname);

    { int i = NULL_INTEGER;
      int iter000 = 1;
      int upperBound000 = end;
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;

      while (unboundedP000 ||
          (iter000 <= upperBound000)) {
        i = iter000;
        iter000 = iter000 + 1;
        if (qualifiedname[(end - i)] == MODULE_SEPARATOR_CHARACTER) {
          return (stringSubsequence(qualifiedname, 0, end - i));
        }
      }
    }
    return (NULL);
  }
}

char* qualifiedNameBareName(char* qualifiedname) {
  { int end = strlen(qualifiedname);

    { int i = NULL_INTEGER;
      int iter000 = 1;
      int upperBound000 = end;
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;

      while (unboundedP000 ||
          (iter000 <= upperBound000)) {
        i = iter000;
        iter000 = iter000 + 1;
        if (qualifiedname[(end - i)] == MODULE_SEPARATOR_CHARACTER) {
          return (stringSubsequence(qualifiedname, (end - i) + 1, end));
        }
      }
    }
    return (qualifiedname);
  }
}

Module* dwimModuleAndBareName(char* name, boolean warnP, char*& _Return1) {
  { Module* module = NULL;
    int barenamestart = NULL_INTEGER;

    try {
      { Context* value000 = NULL;
        int value001 = NULL_INTEGER;

        value000 = computeContextOrModuleFromPathname(name, TRUE, TRUE, value001);
        {
          module = ((Module*)(value000));
          barenamestart = value001;
        }
      }
    }
    catch (NoSuchContextException ) {
      if (barenamestart != NULL_INTEGER) {
        { char* modulename = qualifiedNameBareName(qualifiedNameModuleName(name));

          try {
            module = getStellaModule(modulename, FALSE);
          }
          catch (NoSuchContextException ) {
            module = getStellaModule(stringUpcase(modulename), FALSE);
          }
          if (warnP) {
            if (!((boolean)(module))) {
              *(STANDARD_WARNING->nativeStream) << "Warning: " << "Module " << "`" << stringSubsequence(name, 0, barenamestart - 1) << "'" << " of symbol " << "`" << name << "'" << " does not exist." << std::endl;
            }
            else {
              *(STANDARD_WARNING->nativeStream) << "Warning: " << "Module " << "`" << stringSubsequence(name, 0, barenamestart - 1) << "'" << " of symbol " << "`" << name << "'" << " does not exist." << std::endl << "    Assuming you mean " << "`" << ((Module*)(module))->moduleFullName << "'" << "." << std::endl;
            }
          }
        }
      }
    }
    { Module* _return_temp = module;

      _Return1 = ((barenamestart != NULL_INTEGER) ? stringSubsequence(name, barenamestart, NULL_INTEGER) : ((char*)(NULL)));
      return (_return_temp);
    }
  }
}

GeneralizedSymbol* internQualifiedName(char* name, boolean enableCaseConversionP) {
  { Module* module = NULL;
    char* barename = NULL;

    module = dwimModuleAndBareName(name, TRUE, barename);
    if (!((boolean)(module))) {
      if ((barename == NULL) ||
          surrogateNameP(barename)) {
        return (SGT_MODULES_STELLA_UNKNOWN_SURROGATE);
      }
      else {
        return (SYM_MODULES_STELLA_UNKNOWN_SYMBOL);
      }
    }
    if (stringEqlP(barename, "")) {
      if ((module == oMODULEo.get()) ||
          (module == oROOT_MODULEo)) {
        return (internRigidSymbolWrtModule("/", oSTELLA_MODULEo, SYMBOL_SYM));
      }
      else {
        {
          *(STANDARD_WARNING->nativeStream) << "Warning: " << "Empty symbol name encountered" << std::endl;
          return (SYM_MODULES_STELLA_UNKNOWN_SYMBOL);
        }
      }
    }
    if (enableCaseConversionP &&
        (!module->caseSensitiveP)) {
      barename = stringUpcase(barename);
    }
    if (surrogateNameP(barename)) {
      return (internRigidSymbolWrtModule(stringSubsequence(barename, 1, NULL_INTEGER), module, SURROGATE_SYM));
    }
    else {
      return (internRigidSymbolWrtModule(barename, module, SYMBOL_SYM));
    }
  }
}

Context* helpGetStellaContextOrModule(char* pathname, boolean moduleP) {
  { int dummy1;

    if (qualifiedNameP(pathname)) {
      return (computeContextOrModuleFromPathname(pathname, moduleP, FALSE, dummy1));
    }
    else {
      return (stringGetStellaContextSlowly(pathname));
    }
  }
}

Context* getStellaContext(char* pathname, boolean errorP) {
  // Return the context located at `pathName', or `null'
  // if no such context exists.  If `error?' is `true', throw an exception
  // if no context is found, otherwise silently return `null'.
  if (errorP) {
    return (helpGetStellaContextOrModule(pathname, FALSE));
  }
  else {
    try {
      return (helpGetStellaContextOrModule(pathname, FALSE));
    }
    catch (NoSuchContextException ) {
      return (NULL);
    }
  }
}

Module* getStellaModule(char* pathname, boolean errorP) {
  // Return the module located at `pathName', or `null'
  // if no such module exists.  The search looks at ancestors and top-most
  //  (cardinal) modules.  If `error?' is `true', throw an exception if no
  //  module is found.
  if (stringEqlP(pathname, oMODULEo.get()->moduleFullName)) {
    return (oMODULEo.get());
  }
  { Context* context = NULL;

    if (errorP) {
      context = helpGetStellaContextOrModule(pathname, TRUE);
    }
    else {
      try {
        context = helpGetStellaContextOrModule(pathname, TRUE);
      }
      catch (NoSuchContextException ) {
        return (NULL);
      }
    }
    if (isaP(context, SGT_MODULES_STELLA_MODULE)) {
      return (((Module*)(context)));
    }
    else if (errorP) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Context " << "`" << context << "'" << " is not a MODULE!";
        throw *newNoSuchContextException(stream000->theStringReader());
      }
    }
    else {
      return (NULL);
    }
  }
}

char* coerceToModuleName(Object* namespec, boolean warnP) {
  { Surrogate* testValue000 = safePrimaryType(namespec);

    if (subtypeOfStringP(testValue000)) {
      { Object* namespec000 = namespec;
        StringWrapper* namespec = ((StringWrapper*)(namespec000));

        return (namespec->wrapperValue);
      }
    }
    else if (subtypeOfP(testValue000, SGT_MODULES_STELLA_MUTABLE_STRING_WRAPPER)) {
      { Object* namespec001 = namespec;
        MutableStringWrapper* namespec = ((MutableStringWrapper*)(namespec001));

        return ((namespec->wrapperValue));
      }
    }
    else if (subtypeOfKeywordP(testValue000)) {
      { Object* namespec002 = namespec;
        Keyword* namespec = ((Keyword*)(namespec002));

        return (namespec->symbolName);
      }
    }
    else if (subtypeOfSymbolP(testValue000)) {
      { Object* namespec003 = namespec;
        Symbol* namespec = ((Symbol*)(namespec003));

        { Module* module = ((Module*)(namespec->homeContext));

          if (!((boolean)(module))) {
            return (namespec->symbolName);
          }
          else {
            return (namespec->visibleName());
          }
        }
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* namespec004 = namespec;
        Surrogate* namespec = ((Surrogate*)(namespec004));

        { Module* module = ((Module*)(namespec->homeContext));

          if (!((boolean)(module))) {
            return (namespec->symbolName);
          }
          else {
            return (namespec->visibleName());
          }
        }
      }
    }
    else {
      if (warnP) {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal module name: " << "`" << namespec << "'" << std::endl;
      }
      return (NULL);
    }
  }
}

Module* coerceToModule(Object* object, boolean warnP) {
  if (!((boolean)(object))) {
    return (oMODULEo.get());
  }
  if (subtypeOfP(safePrimaryType(object), SGT_MODULES_STELLA_MODULE)) {
    { Object* object000 = object;
      Module* object = ((Module*)(object000));

      return (object);
    }
  }
  else {
    { char* modulename = coerceToModuleName(object, warnP);

      if (modulename != NULL) {
        if (qualifiedNameP(modulename)) {
          return (getStellaModule(modulename, warnP));
        }
        return (getStellaModule(modulename, warnP));
      }
      return (NULL);
    }
  }
}

Module* findOrCreateModule(char* pathname) {
  // Return a module located at `pathname' if one exists,
  //   otherwise create one
  { Module* module = getStellaModule(pathname, FALSE);

    if (!(((boolean)(module)))) {
      module = defineModule(pathname, NIL);
    }
    return (module);
  }
}

Module* changeCurrentModule(Module* module) {
  oMODULEo.set(module);
  oCONTEXTo.set(module);
  runHooks(oCHANGE_MODULE_HOOKSo, module);
  return (module);
}

Context* changeCurrentContext(Context* context) {
  if (!(context->baseModule == oMODULEo.get())) {
    changeCurrentModule(context->baseModule);
  }
  oCONTEXTo.set(context);
  return (context);
}

Context* Context::changeContext() {
  // Change the current context to be the context
  // 'context'.
  { Context* context = this;

    if (context == oCONTEXTo.get()) {
      return (context);
    }
    else {
      return (changeCurrentContext(context));
    }
  }
}

Context* stringChangeContext(char* contextname) {
  // Change the current context to be the context named
  // 'contextName'.
  { Context* context = getStellaContext(contextname, TRUE);

    if (!((boolean)(context))) {
      return (oCONTEXTo.get());
    }
    else {
      return (changeCurrentContext(context));
    }
  }
}

Module* Module::changeModule() {
  // Change the current module to be the module
  // 'module'.
  { Module* module = this;

    return (changeCurrentModule(module));
  }
}

Module* stringChangeModule(char* modulename) {
  // Change the current module to be the module named
  // 'moduleName'.
  { Module* module = getStellaModule(modulename, TRUE);

    if (!((boolean)(module))) {
      return (oMODULEo.get());
    }
    else {
      return (changeCurrentModule(module));
    }
  }
}

boolean Module::multipleParentsP() {
  // Return TRUE if 'module' has more than one parent.
  { Module* module = this;

    return (!(module->parentModules->rest() == NIL));
  }
}

void normalizeParentModules(Module* self) {
  if (!self->multipleParentsP()) {
    return;
  }
  { List* parents = self->parentModules;

    { Module* supermodule = NULL;
      Cons* iter000 = parents->theConsList;

      while (!(iter000 == NIL)) {
        supermodule = ((Module*)(iter000->value));
        iter000 = iter000->rest;
        { Module* othersupermodule = NULL;
          Cons* iter001 = parents->theConsList;

          while (!(iter001 == NIL)) {
            othersupermodule = ((Module*)(iter001->value));
            iter001 = iter001->rest;
            if (!(othersupermodule == supermodule)) {
              if (supermodule->allSuperContexts->memberP(othersupermodule)) {
                parents->remove(othersupermodule);
              }
            }
          }
        }
      }
    }
  }
}

void inheritSupercontexts(Module* module) {
  if (!module->multipleParentsP()) {
    { Module* onlyparent = ((Module*)(module->parentModules->first()));

      if (((boolean)(onlyparent))) {
        module->allSuperContexts = cons(onlyparent, onlyparent->allSuperContexts);
        return;
      }
    }
  }
  { Cons* allsupercontexts = NIL;
    Cons* sublist = NULL;

    normalizeParentModules(module);
    module->parentModules->reverse();
    { Module* parent = NULL;
      Cons* iter000 = module->parentModules->theConsList;

      while (!(iter000 == NIL)) {
        parent = ((Module*)(iter000->value));
        iter000 = iter000->rest;
        sublist = NIL;
        { Context* ancestor = NULL;
          Cons* iter001 = parent->allSuperContexts;
          Cons* collect000 = NULL;

          while (!(iter001 == NIL)) {
            ancestor = ((Context*)(iter001->value));
            iter001 = iter001->rest;
            if (!allsupercontexts->memberP(ancestor)) {
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(ancestor, NIL);
                  if (sublist == NIL) {
                    sublist = collect000;
                  }
                  else {
                    addConsToEndOfConsList(sublist, collect000);
                  }
                }
              }
              else {
                {
                  collect000->rest = cons(ancestor, NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
        }
        sublist = cons(parent, sublist);
        allsupercontexts = sublist->concatenate(allsupercontexts, 0);
      }
    }
    module->allSuperContexts = allsupercontexts;
    module->parentModules->reverse();
  }
}

void uninheritSupercontexts(Module* module) {
  module->allSuperContexts = NIL;
}

void inheritUsedModules(Module* module) {
  { List* usees = module->uses;

    if (usees->emptyP()) {
      if (module->parentModules->emptyP()) {
        usees->push(oSTELLA_MODULEo);
        oSTELLA_MODULEo->usedBy->insertNew(module);
      }
      else {
        { Module* parent = NULL;
          Cons* iter000 = module->parentModules->theConsList;

          while (!(iter000 == NIL)) {
            parent = ((Module*)(iter000->value));
            iter000 = iter000->rest;
            { Module* parentusees = NULL;
              Cons* iter001 = parent->uses->theConsList;

              while (!(iter001 == NIL)) {
                parentusees = ((Module*)(iter001->value));
                iter001 = iter001->rest;
                usees->insertNew(parentusees);
                parentusees->usedBy->insertNew(module);
              }
            }
          }
        }
        usees->reverse();
      }
    }
    else if (usees->memberP(module)) {
      usees->remove(module);
    }
    else {
    }
  }
}

void uninheritUsedModules(Module* module) {
  { List* usees = module->uses;

    if (usees->emptyP()) {
      usees->push(module);
    }
    else if (stringSearch(module->stringifiedOptions, ":USES ", 0) == NULL_INTEGER) {
      { Module* usee = NULL;
        Cons* iter000 = usees->theConsList;

        while (!(iter000 == NIL)) {
          usee = ((Module*)(iter000->value));
          iter000 = iter000->rest;
          usee->usedBy->remove(module);
        }
      }
      usees->clear();
    }
  }
}

// Holds list of symbols representing surrogates
// to be shadowed during module finalization.
DEFINE_STELLA_SPECIAL(oSHADOWEDSURROGATESo, Cons* , NULL);

void finalizeModule(Module* self) {
  inheritSupercontexts(self);
  inheritUsedModules(self);
  oCONTEXT_NUMBER_COUNTERo = oCONTEXT_NUMBER_COUNTERo + 2;
  self->contextNumber = oCONTEXT_NUMBER_COUNTERo;
  self->cardinalModule = ((!((boolean)(self->parentModule()))) ? self : self->parentModule()->cardinalModule);
  self->symbolOffsetTable = newStringToIntegerHashTable();
  self->surrogateOffsetTable = newStringToIntegerHashTable();
  if (!(oSHADOWEDSURROGATESo.get() == NIL)) {
    setDynamicSlotValue(self->dynamicSlots, SYM_MODULES_STELLA_SHADOWED_SURROGATES, newList(), NULL);
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, self);
      { Symbol* sym = NULL;
        Cons* iter000 = oSHADOWEDSURROGATESo.get();

        while (!(iter000 == NIL)) {
          sym = ((Symbol*)(iter000->value));
          iter000 = iter000->rest;
          self->shadowedSurrogates_reader()->insertLast(shadowSurrogate(sym->symbolName));
        }
      }
    }
  }
}

void finalizeWorld(World* self) {
  { Context* parentcontext = self->parentContext;

    self->allSuperContexts = cons(parentcontext, parentcontext->allSuperContexts);
    oCONTEXT_NUMBER_COUNTERo = oCONTEXT_NUMBER_COUNTERo + 2;
    self->contextNumber = oCONTEXT_NUMBER_COUNTERo;
  }
}

void Module::unfinalizeModule() {
  { Module* self = this;

    uninheritSupercontexts(self);
    uninheritUsedModules(self);
    if (cardinalModuleP(self)) {
      oROOT_MODULEo->childContexts->remove(self);
    }
    else {
      { Module* parent = NULL;
        Cons* iter000 = self->parentModules->theConsList;

        while (!(iter000 == NIL)) {
          parent = ((Module*)(iter000->value));
          iter000 = iter000->rest;
          parent->childContexts->remove(self);
        }
      }
    }
    self->parentModules->clear();
    if (self->contextNumber != NULL_INTEGER) {
      self->contextNumber = self->contextNumber - 1;
    }
    self->moduleFullName = NULL;
    self->cardinalModule = NULL;
    self->symbolOffsetTable = NULL;
    self->surrogateOffsetTable = NULL;
  }
}

void World::unfinalizeWorld() {
  { World* self = this;

    self->parentContext->childContexts->remove(self);
    self->contextNumber = self->contextNumber - 1;
    self->allSuperContexts = NULL;
    self->parentContext = NULL;
  }
}

void destroyModule(Module* self) {
  // Destroy the module 'self', and recursively destroy
  // all contexts that inherit 'self'.
  if ((self == oROOT_MODULEo) ||
      (self == oSTELLA_MODULEo)) {
    *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't destroy the root module or the STELLA module." << std::endl;
    return;
  }
  clearContext(self);
  helpDestroyModule(self);
}

void helpDestroyModule(Module* self) {
  { Context* child = NULL;
    Cons* iter000 = self->childContexts->copy()->theConsList;

    while (!(iter000 == NIL)) {
      child = ((Context*)(iter000->value));
      iter000 = iter000->rest;
      if (subtypeOfP(safePrimaryType(child), SGT_MODULES_STELLA_MODULE)) {
        { Context* child000 = child;
          Module* child = ((Module*)(child000));

          helpDestroyModule(child);
        }
      }
      else {
        child->destroyContext();
      }
    }
  }
  { Module* parentmodule = self->parentModule();

    runHooks(oDESTROY_CONTEXT_HOOKSo, self);
    if (!((boolean)(parentmodule))) {
      parentmodule = self->cardinalModule;
    }
    if (!((boolean)(parentmodule))) {
      parentmodule = oSTELLA_MODULEo;
    }
    self->unfinalizeModule();
    if (self == oMODULEo.get()) {
      parentmodule->changeModule();
    }
  }
}

void destroyWorld(World* self) {
  if (self->childContexts->nonEmptyP()) {
    { World* child = NULL;
      Cons* iter000 = self->childContexts->copy()->theConsList;

      while (!(iter000 == NIL)) {
        child = ((World*)(iter000->value));
        iter000 = iter000->rest;
        if (!child->deletedP()) {
          destroyWorld(child);
        }
      }
    }
  }
  { Context* parentcontext = self->parentContext;

    runHooks(oDESTROY_CONTEXT_HOOKSo, self);
    self->unfinalizeWorld();
    if (self == oCONTEXTo.get()) {
      oCONTEXTo.set(parentcontext);
    }
  }
}

void Module::destroyContext() {
  // Destroy the context 'self', and recursively destroy
  // all contexts that inherit 'self'.
  { Module* self = this;

    destroyModule(self);
  }
}

void World::destroyContext() {
  // Destroy the context 'self', and recursively destroy
  // all contexts that inherit 'self'.
  { World* self = this;

    destroyWorld(self);
  }
}

void stringDestroyContext(char* self) {
  // Destroy the context 'self', and recursively destroy
  // all contexts that inherit 'self'.
  { Context* context = getStellaContext(self, TRUE);

    if (!(!((boolean)(context)))) {
      context->destroyContext();
    }
  }
}

void Context::destroyContext() {
  // Make the translator happy.
  { Context* self = this;

  }
}

void linkToParentModule(Module* self, Module* parent, boolean insertFirstP) {
  if ((!(parent == oROOT_MODULEo)) &&
      (!self->parentModules->memberP(parent))) {
    if (insertFirstP) {
      self->parentModules->insert(parent);
    }
    else {
      self->parentModules->insertLast(parent);
    }
  }
  parent->childContexts->insertNew(self);
}

void incorporateModuleName(Module* module, char* name) {
  { Module* parentmodule = NULL;
    char* barename = NULL;

    if (qualifiedNameP(name)) {
      {
        parentmodule = computeModuleAndBareName(name, barename);
        if (!((boolean)(parentmodule))) {
          *(STANDARD_WARNING->nativeStream) << "Warning: " << "Bad path name " << "`" << name << "'" << " when defining the module " << "`" << barename << "'" << std::endl;
          return;
        }
        { boolean testValue000 = FALSE;

          if ((parentmodule == oROOT_MODULEo) &&
              module->parentModules->nonEmptyP()) {
            testValue000 = TRUE;
          }
          else {
            { boolean foundP000 = FALSE;

              { Module* includedmodule = NULL;
                Cons* iter000 = module->parentModules->theConsList;

                while (!(iter000 == NIL)) {
                  includedmodule = ((Module*)(iter000->value));
                  iter000 = iter000->rest;
                  if ((!(includedmodule == parentmodule)) &&
                      ((includedmodule == parentmodule) ||
                       includedmodule->allSuperContexts->membP(parentmodule))) {
                    foundP000 = TRUE;
                    break;
                  }
                }
              }
              testValue000 = foundP000;
            }
          }
          if (testValue000) {
            *(STANDARD_WARNING->nativeStream) << "Warning: " << "Bad path name " << "`" << name << "'" << " when defining the module " << "`" << barename << "'" << "," << std::endl << "   since it points to a parent of an included module." << std::endl;
          }
          else {
            linkToParentModule(module, parentmodule, TRUE);
          }
        }
      }
    }
    else {
      {
        if (module->parentModules->emptyP()) {
          linkToParentModule(module, oROOT_MODULEo, TRUE);
        }
        barename = name;
      }
    }
    module->moduleName = barename;
    module->moduleFullName = computeFullName("", module);
  }
}

void incorporateIncludesModules(Module* module, Object* includees) {
  { Surrogate* testValue000 = safePrimaryType(includees);

    if (testValue000 == SGT_MODULES_STELLA_CONS) {
      { Object* includees000 = includees;
        Cons* includees = ((Cons*)(includees000));

        { Object* name = NULL;
          Cons* iter000 = includees;

          while (!(iter000 == NIL)) {
            name = iter000->value;
            iter000 = iter000->rest;
            incorporateIncludesModules(module, name);
          }
        }
      }
    }
    else if (subtypeOfStringP(testValue000)) {
      { Object* includees001 = includees;
        StringWrapper* includees = ((StringWrapper*)(includees001));

        { Module* includeemodule = coerceToModule(includees, TRUE);

          if (((boolean)(includeemodule))) {
            if (!module->parentModules->memberP(includeemodule)) {
              module->parentModules->insertLast(includeemodule);
            }
            includeemodule->childContexts->insertNew(module);
          }
        }
      }
    }
    else if (subtypeOfSymbolP(testValue000)) {
      { Object* includees002 = includees;
        Symbol* includees = ((Symbol*)(includees002));

        { Module* includeemodule = coerceToModule(includees, TRUE);

          if (((boolean)(includeemodule))) {
            if (!module->parentModules->memberP(includeemodule)) {
              module->parentModules->insertLast(includeemodule);
            }
            includeemodule->childContexts->insertNew(module);
          }
        }
      }
    }
    else {
      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
        signalTranslationError();
        if (!(suppressWarningsP())) {
          printErrorContext(">> ERROR: ", STANDARD_ERROR);
          *(STANDARD_ERROR->nativeStream) << std::endl << " " << "Illegal argument to ':includes' option" << "`" << deUglifyParseTree(includees) << "'" << "." << std::endl;
        }
      }
    }
  }
}

void incorporateUsesModules(Module* module, Object* usees) {
  { Surrogate* testValue000 = safePrimaryType(usees);

    if (testValue000 == SGT_MODULES_STELLA_CONS) {
      { Object* usees000 = usees;
        Cons* usees = ((Cons*)(usees000));

        { Object* name = NULL;
          Cons* iter000 = usees;

          while (!(iter000 == NIL)) {
            name = iter000->value;
            iter000 = iter000->rest;
            incorporateUsesModules(module, name);
          }
        }
        if (module->uses->emptyP()) {
          module->uses->insert(module);
        }
      }
    }
    else if (subtypeOfStringP(testValue000)) {
      { Object* usees001 = usees;
        StringWrapper* usees = ((StringWrapper*)(usees001));

        { Module* useemodule = coerceToModule(usees, TRUE);

          if (((boolean)(useemodule))) {
            if (!module->uses->memberP(useemodule)) {
              module->uses->insertLast(useemodule);
            }
            useemodule->usedBy->insertNew(module);
          }
        }
      }
    }
    else if (subtypeOfSymbolP(testValue000)) {
      { Object* usees002 = usees;
        Symbol* usees = ((Symbol*)(usees002));

        { Module* useemodule = coerceToModule(usees, TRUE);

          if (((boolean)(useemodule))) {
            if (!module->uses->memberP(useemodule)) {
              module->uses->insertLast(useemodule);
            }
            useemodule->usedBy->insertNew(module);
          }
        }
      }
    }
    else {
      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
        signalTranslationError();
        if (!(suppressWarningsP())) {
          printErrorContext(">> ERROR: ", STANDARD_ERROR);
          *(STANDARD_ERROR->nativeStream) << std::endl << " " << "Illegal argument to ':uses' option " << "." << std::endl;
        }
      }
    }
  }
}

void incorporateModuleOptions(Module* self, Cons* options) {
  { PropertyList* self000 = newPropertyList();

    self000->thePlist = options;
    { PropertyList* plist = vetOptions(self000, getQuotedTree("((:NICKNAME :INCLUDES :USES :DOCUMENTATION :SHADOW :CASE-SENSITIVE? :LISP-PACKAGE :CPP-PACKAGE :JAVA-PACKAGE :JAVA-CATCHALL-CLASS :API? :CLEARABLE? :PROTECT-SURROGATES? :CODE-ONLY?) \"/STELLA\")", "/STELLA"));

      { Object* key = NULL;
        Object* value = NULL;
        Cons* iter000 = plist->thePlist;

        while (!(iter000 == NIL)) {
          key = iter000->value;
          value = iter000->rest->value;
          iter000 = iter000->rest->rest;
          { Keyword* testValue000 = ((Keyword*)(key));

            if (testValue000 == KWD_MODULES_INCLUDES) {
              incorporateIncludesModules(self, value);
            }
            else if (testValue000 == KWD_MODULES_USES) {
              incorporateUsesModules(self, value);
            }
            else if (testValue000 == KWD_MODULES_SHADOW) {
              oSHADOWEDSURROGATESo.set(((Cons*)(value)));
            }
            else {
              value = permanentCopy(value);
              { Keyword* testValue001 = ((Keyword*)(key));

                if (testValue001 == KWD_MODULES_DOCUMENTATION) {
                  self->documentation = ((StringWrapper*)(value))->wrapperValue;
                }
                else if (testValue001 == KWD_MODULES_CASE_SENSITIVEp) {
                  self->caseSensitiveP = value == SYM_MODULES_STELLA_TRUE;
                }
                else if (testValue001 == KWD_MODULES_APIp) {
                  setDynamicSlotValue(self->dynamicSlots, SYM_MODULES_STELLA_APIp, ((value == SYM_MODULES_STELLA_TRUE) ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
                }
                else if (testValue001 == KWD_MODULES_LISP_PACKAGE) {
                  setDynamicSlotValue(self->dynamicSlots, SYM_MODULES_STELLA_MODULE_LISP_PACKAGE, wrapString(((StringWrapper*)(value))->wrapperValue), NULL_STRING_WRAPPER);
                }
                else if (testValue001 == KWD_MODULES_CPP_PACKAGE) {
                  setDynamicSlotValue(self->dynamicSlots, SYM_MODULES_STELLA_MODULE_CPP_PACKAGE, wrapString(((StringWrapper*)(value))->wrapperValue), NULL_STRING_WRAPPER);
                }
                else if (testValue001 == KWD_MODULES_JAVA_PACKAGE) {
                  setDynamicSlotValue(self->dynamicSlots, SYM_MODULES_STELLA_JAVA_PACKAGE, wrapString(((StringWrapper*)(value))->wrapperValue), NULL_STRING_WRAPPER);
                }
                else if (testValue001 == KWD_MODULES_JAVA_CATCHALL_CLASS) {
                  setDynamicSlotValue(self->dynamicSlots, SYM_MODULES_STELLA_JAVA_FLOTSAM_CLASS, wrapString(((StringWrapper*)(value))->wrapperValue), NULL_STRING_WRAPPER);
                }
                else if (testValue001 == KWD_MODULES_NICKNAME) {
                  if (!((boolean)(self->nicknames))) {
                    self->nicknames = newList();
                  }
                  self->nicknames->insert(((StringWrapper*)(value)));
                }
                else if (testValue001 == KWD_MODULES_CLEARABLEp) {
                  setDynamicSlotValue(self->dynamicSlots, SYM_MODULES_STELLA_CLEARABLEp, ((value == SYM_MODULES_STELLA_TRUE) ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
                }
                else if (testValue001 == KWD_MODULES_PROTECT_SURROGATESp) {
                  setDynamicSlotValue(self->dynamicSlots, SYM_MODULES_STELLA_PROTECT_SURROGATESp, ((value == SYM_MODULES_STELLA_TRUE) ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
                }
                else if (testValue001 == KWD_MODULES_CODE_ONLYp) {
                  setDynamicSlotValue(self->dynamicSlots, SYM_MODULES_STELLA_CODE_ONLYp, ((value == SYM_MODULES_STELLA_TRUE) ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
                }
                else if (testValue001 == KWD_MODULES_REQUIRES) {
                  self->requires = ((List*)(value));
                }
                else {
                  { OutputStringStream* stream000 = newOutputStringStream();

                    *(stream000->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
                    throw *newStellaException(stream000->theStringReader());
                  }
                }
              }
            }
          }
        }
      }
      plist->free();
    }
  }
}

void undefineModule(Module* oldmodule, Module* newmodule) {
  std::cout << "Redefining the module " << "`" << oldmodule->contextName() << "'" << std::endl;
  if (oSUBCONTEXT_REVISION_POLICYo == KWD_MODULES_DESTROY) {
    oldmodule->destroyContext();
    return;
  }
  else if (oSUBCONTEXT_REVISION_POLICYo == KWD_MODULES_PRESERVE) {
  }
  else if (oSUBCONTEXT_REVISION_POLICYo == KWD_MODULES_CLEAR) {
    { Context* c = NULL;
      AllPurposeIterator* iter000 = allSubcontexts(oldmodule, KWD_MODULES_PREORDER);

      while (iter000->nextP()) {
        c = ((Context*)(iter000->value));
        clearContext(c);
      }
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << oSUBCONTEXT_REVISION_POLICYo << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  if (cardinalModuleP(oldmodule)) {
    oROOT_MODULEo->childContexts->remove(oldmodule);
  }
  else {
    { Module* p = NULL;
      Cons* iter001 = oldmodule->parentModules->theConsList;

      while (!(iter001 == NIL)) {
        p = ((Module*)(iter001->value));
        iter001 = iter001->rest;
        p->childContexts->remove(oldmodule);
      }
    }
  }
  { Context* c = NULL;
    Cons* iter002 = oldmodule->childContexts->theConsList;

    while (!(iter002 == NIL)) {
      c = ((Context*)(iter002->value));
      iter002 = iter002->rest;
      { Surrogate* testValue000 = safePrimaryType(c);

        if (subtypeOfP(testValue000, SGT_MODULES_STELLA_MODULE)) {
          { Context* c000 = c;
            Module* c = ((Module*)(c000));

            c->parentModules->theConsList->substitute(newmodule, oldmodule);
          }
        }
        else if (subtypeOfP(testValue000, SGT_MODULES_STELLA_WORLD)) {
          { Context* c001 = c;
            World* c = ((World*)(c001));

            c->parentContext = newmodule;
          }
        }
        else {
          { OutputStringStream* stream001 = newOutputStringStream();

            *(stream001->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
            throw *newStellaException(stream001->theStringReader());
          }
        }
      }
    }
  }
  newmodule->childContexts->theConsList = oldmodule->childContexts->theConsList;
  oldmodule->childContexts->theConsList = NIL;
  oldmodule->surrogateValueInverse = NULL;
  oldmodule->free();
}

// HOOK-LIST called by 'define-module', applied to a
// 'module' argument.
HookList* oDEFINE_MODULE_HOOKSo = NULL;

Module* defineModule(char* name, Cons* options) {
  // Define or redefine a module named 'name' having the
  // options 'options'.  Return the new module.
  { 
    BIND_STELLA_SPECIAL(oSHADOWEDSURROGATESo, Cons*, NIL);
    { Module* module = NULL;
      char* stringifiedoptions = stringify(options);
      Module* oldmodule = NULL;

      oldmodule = getStellaModule(name, FALSE);
      if (((boolean)(oldmodule)) &&
          identicalModuleSignaturesP(oldmodule, NULL, stringifiedoptions)) {
        return (oldmodule);
      }
      module = newModule();
      module->stringifiedOptions = stringifiedoptions;
      incorporateModuleOptions(module, options);
      incorporateModuleName(module, name);
      module->baseModule = module;
      if (((boolean)(oldmodule))) {
        if (identicalModuleSignaturesP(oldmodule, module, NULL)) {
          module->unfinalizeModule();
          return (oldmodule);
        }
        if (oldmodule == oMODULEo.get()) {
          *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't define a module inside of itself." << std::endl;
          std::cout << "Skipping redefinition of module " << name << "." << std::endl;
          module->unfinalizeModule();
          return (oldmodule);
        }
        undefineModule(oldmodule, module);
      }
      finalizeModule(module);
      runHooks(oDEFINE_MODULE_HOOKSo, module);
      return (module);
    }
  }
}

boolean identicalModuleSignaturesP(Module* oldmodule, Module* newmodule, char* newoptions) {
  if (((boolean)(newmodule)) &&
      (!stringEqlP(oldmodule->moduleFullName, newmodule->moduleFullName))) {
    return (FALSE);
  }
  { char* oldoptions = oldmodule->stringifiedOptions;

    newoptions = ((!((boolean)(newmodule))) ? newoptions : newmodule->stringifiedOptions);
    if (newoptions == NULL) {
      return (FALSE);
    }
    if (stringEqlP(oldoptions, newoptions)) {
      return (TRUE);
    }
    if ((stringSearch(oldoptions, ":INCLUDES", 0) == NULL_INTEGER) &&
        (stringSearch(newoptions, ":INCLUDES", 0) == NULL_INTEGER)) {
      return (FALSE);
    }
    if (((boolean)(newmodule)) &&
        equalConsTreesP(oldmodule->parentModules->theConsList, newmodule->parentModules->theConsList)) {
      { PropertyList* self000 = newPropertyList();

        self000->thePlist = ((Cons*)(readSExpressionFromString(oldoptions)));
        { PropertyList* oldplist = self000;

          { PropertyList* self001 = newPropertyList();

            self001->thePlist = ((Cons*)(readSExpressionFromString(newoptions)));
            { PropertyList* newplist = self001;

              oldplist->removeAt(KWD_MODULES_INCLUDES);
              newplist->removeAt(KWD_MODULES_INCLUDES);
              if (!(oldplist->length() == newplist->length())) {
                return (FALSE);
              }
              { Object* key = NULL;
                Object* value = NULL;
                Cons* iter000 = oldplist->thePlist;

                while (!(iter000 == NIL)) {
                  key = iter000->value;
                  value = iter000->rest->value;
                  iter000 = iter000->rest->rest;
                  if (!equalConsTreesP(value, newplist->lookup(key))) {
                    return (FALSE);
                  }
                }
              }
              return (TRUE);
            }
          }
        }
      }
    }
    return (FALSE);
  }
}

Module* defineModuleFromStringifiedSource(char* name, char* stringifiedoptions) {
  return (defineModule(name, ((Cons*)(readSExpressionFromString(stringifiedoptions)))));
}

Cons* yieldDefineModule(Module* module) {
  return (listO(3, SYM_MODULES_STELLA_DEFINE_MODULE_FROM_STRINGIFIED_SOURCE, wrapString(module->moduleFullName), cons(yieldStringConstantTree(module->stringifiedOptions), NIL)));
}

void defmodule(Object* name, Cons* options) {
  // Define (or redefine) a module named `name'.
  // The accepted syntax is:
  // 	 
  //   (defmodule <module-name>
  //      [:documentation <docstring>]
  //      [:includes {<module-name> | (<module-name>*)}]
  //      [:uses {<module-name> | (<module-name>*)}]
  //      [:lisp-package <package-name-string>]
  //      [:java-package <package-specification-string>]
  //      [:cpp-namespace <namespace-name-string>]
  //      [:java-catchall-class
  //      [:api? {TRUE | FALSE}]
  //      [:case-sensitive? {TRUE | FALSE}]
  //      [:shadow (<symbol>*)]
  //      [:java-catchall-class <class-name-string>]
  //      [<other-options>*])
  // 	
  // `name' can be a string or a symbol.
  // 
  // Modules include objects from other modules via two separate mechanisms:
  // (1) they inherit from their parents specified via the `:includes' option
  // and/or a fully qualified module name, and (2) they inherit from used
  // modules specified via the `:uses' option.  The main difference between
  // the two mechanisms is that inheritance from parents is transitive, while
  // uses-links are only followed one level deep.  I.e., a module A that uses
  // B will see all objects of B (and any of B's parents) but not see anything
  // from modules used by B.  Another difference is that only objects declared
  // as public can be inherited via uses-links (this is not yet enforced).
  // Note that - contrary to Lisp - there are separate name spaces for classes,
  // functions, and variables.  For example, a module could inherit the class
  // `CONS' from the `STELLA' module, but shadow the function of the same name.
  // 
  // The above discussion of `:includes' and `:uses' semantics keyed on the
  // inheritance/visibility of symbols. The PowerLoom system makes another
  // very important distinction: If a module 'A' is inherited directly or
  // indirectly via `:includes' specification(s) by a submodule 'B', then all
  // definitions and facts asserted in 'A' are visible in 'B'. This is not the
  // cases for `:uses'; the `:uses' options does not impact inheritance of
  // propositions at all.
  // 
  // The list of modules specified in the
  // `:includes' option plus (if supplied) the parent in the path used for
  // `name' become the new module's parents. If no `:uses' option was
  // supplied, the new module will use the `STELLA' module by default,
  // otherwise, it will use the set of specified modules.
  // If `:case-sensitive?' is supplied as TRUE, symbols in the module will be
  // interned case-sensitively, otherwise (the default), they will be
  // converted to uppercase before they get interned. Modules can shadow
  // definitions of functions and classes inherited from parents or used
  // modules. Shadowing is done automatically, but generates a warning unless
  // the shadowed type or function name is listed in the `:shadow' option of
  // the module definition .
  // 
  // Examples:
  // 	 
  //   (defmodule "PL-KERNEL/PL-USER"
  //     :uses ("LOGIC" "STELLA")
  //     :package "PL-USER")
  // 
  //   (defmodule PL-USER/GENEALOGY)
  // 	
  // The remaining options are relevant only for modules that contain STELLA
  // code.  Modules used only to contain knowledge base definitions and assertions
  // have no use for them:
  // 
  // The keywords `:lisp-package', `:java-package', and `:cpp-package' specify
  // the name of a native package or name space in which symbols of the module
  // should be allocated when they get translated into one of Lisp, Java, or
  // C++. By default, Lisp symbols are allocated in the `STELLA' package, and
  // C++ names are translated without any prefixes. The rules that the STELLA
  // translator uses to attach translated Java objects to classes and packages
  // are somewhat complex. Use :java-package option to specify a list of
  // package names (separated by periods) that prefix the Java object in this
  // module.  Use :java-catchall-class to specify the name of the Java class to
  // contain all global & special variables, parameter-less functions and functions 
  // defined on arguments that are not classes in the current module.
  // The default value will be the name of the module.
  // 
  // When set to TRUE, the :api? option tells the PowerLoom User Manual
  // generator that all functions defined in this module should be included in
  // the API section. Additionally, the Java translator makes all API
  // functions `synchronized'.
  // 
  { char* modulename = coerceToModuleName(name, TRUE);

    if (modulename != NULL) {
      defineModule(modulename, options);
    }
  }
}

void defmoduleEvaluatorWrapper(Cons* arguments) {
  defmodule(arguments->value, arguments->rest);
}

Module* inModule(Object* name) {
  // Change the current module to the module named `name'.
  { char* modulename = coerceToModuleName(name, TRUE);
    Module* module = ((modulename != NULL) ? getStellaModule(modulename, FALSE) : ((Module*)(NULL)));

    if (((boolean)(module))) {
      oMODULEo.set(module);
      oCONTEXTo.set(module);
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Illegal or undefined module: " << "`" << name << "'";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    return (oMODULEo.get());
  }
}

World* createWorld(Context* parentcontext, char* name) {
  // Create a new world below the world or module 'parentContext'.
  // Optionally, specify a name.
  { World* world = newWorld();

    if (name != NULL) {
      setDynamicSlotValue(world->dynamicSlots, SYM_MODULES_STELLA_WORLD_NAME, wrapString(name), NULL_STRING_WRAPPER);
      { boolean foundP000 = FALSE;

        { Context* sibling = NULL;
          Cons* iter000 = parentcontext->childContexts->theConsList;

          while (!(iter000 == NIL)) {
            sibling = ((Context*)(iter000->value));
            iter000 = iter000->rest;
            if (stringEqlP(sibling->contextName(), name)) {
              foundP000 = TRUE;
              break;
            }
          }
        }
        if (foundP000) {
          *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't create a world named " << "`" << name << "'" << " because a sibling already has that name." << std::endl;
          return (NULL);
        }
      }
    }
    world->parentContext = parentcontext;
    parentcontext->childContexts->insert(world);
    world->baseModule = parentcontext->baseModule;
    finalizeWorld(world);
    return (world);
  }
}

World* pushWorld() {
  // Spawn a new world that is a child of the current context,
  // and change the current context to the new world.
  return (((World*)(oCONTEXTo.set(createWorld(oCONTEXTo.get(), NULL)))));
}

Context* popWorld() {
  // Destroy the current world and change the current
  // context to be its parent.  Return the current context. Nothing happens
  // if there is no current world.
  if (!(oCONTEXTo.get() == oMODULEo.get())) {
    { World* world = ((World*)(oCONTEXTo.get()));

      oCONTEXTo.set(world->parentContext);
      destroyWorld(world);
    }
  }
  return (oCONTEXTo.get());
}

AllPurposeIterator* allSubcontexts(Context* context, Keyword* traversal) {
  // Return an iterator that generates all subcontexts of
  // 'self' (not including 'self') in the order specified by 'traversal' (one
  // of :preorder, :inorder, or :postorder).
  { AllPurposeIterator* contextsiterator = newAllPurposeIterator();
    Cons* subcontexts = NIL;

    { Context* child = NULL;
      Cons* iter000 = context->childContexts->theConsList;
      Cons* collect000 = NULL;

      while (!(iter000 == NIL)) {
        child = ((Context*)(iter000->value));
        iter000 = iter000->rest;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(child, NIL);
            if (subcontexts == NIL) {
              subcontexts = collect000;
            }
            else {
              addConsToEndOfConsList(subcontexts, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(child, NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    if (traversal == KWD_MODULES_POSTORDER) {
      subcontexts = subcontexts->reverse();
    }
    contextsiterator->iteratorConsList = subcontexts;
    contextsiterator->iteratorObject = traversal;
    contextsiterator->iteratorNextCode = ((cpp_function_code)(&allSubcontextsNextP));
    return (contextsiterator);
  }
}

boolean allSubcontextsNextP(AllPurposeIterator* self) {
  { Keyword* traversal = ((Keyword*)(self->iteratorObject));
    Cons* remainingcontexts = self->iteratorConsList;
    Context* thiscontext = NULL;
    Cons* subcontexts = NIL;

    if (remainingcontexts == NIL) {
      self->value = NULL;
      return (FALSE);
    }
    thiscontext = ((Context*)(remainingcontexts->value));
    remainingcontexts = remainingcontexts->rest;
    { Context* child = NULL;
      Cons* iter000 = thiscontext->childContexts->theConsList;
      Cons* collect000 = NULL;

      while (!(iter000 == NIL)) {
        child = ((Context*)(iter000->value));
        iter000 = iter000->rest;
        if ((((Context*)(child->parentContexts()->pop())) == thiscontext) ||
            child->parentContexts()->emptyP()) {
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(child, NIL);
              if (subcontexts == NIL) {
                subcontexts = collect000;
              }
              else {
                addConsToEndOfConsList(subcontexts, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(child, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    if (subcontexts == NIL) {
      self->iteratorConsList = remainingcontexts;
    }
    else {
      if (traversal == KWD_MODULES_PREORDER) {
        lastCons(subcontexts)->rest = remainingcontexts;
        self->iteratorConsList = subcontexts;
      }
      else if (traversal == KWD_MODULES_POSTORDER) {
        subcontexts = subcontexts->reverse();
        lastCons(subcontexts)->rest = remainingcontexts;
        self->iteratorConsList = subcontexts;
      }
      else if (traversal == KWD_MODULES_INORDER) {
        if (remainingcontexts == NIL) {
          self->iteratorConsList = subcontexts;
        }
        else {
          lastCons(remainingcontexts)->rest = subcontexts;
          self->iteratorConsList = remainingcontexts;
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << traversal << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    self->value = thiscontext;
    return (TRUE);
  }
}

Iterator* allContexts() {
  // Return an iterator that generates all contexts.
  { AllPurposeIterator* iterator = allSubcontexts(oROOT_MODULEo, KWD_MODULES_PREORDER);

    iterator->iteratorConsList = cons(oROOT_MODULEo, NIL);
    return (iterator);
  }
}

boolean filterModuleP(Object* self, AllPurposeIterator* iterator) {
  iterator = iterator;
  return (self->primaryType() == SGT_MODULES_STELLA_MODULE);
}

Iterator* allModules() {
  // Return an iterator that generates all modules.
  { Iterator* contextsiterator = allContexts();
    AllPurposeIterator* iterator = newAllPurposeIterator();

    iterator->firstIterationP = TRUE;
    iterator->iteratorNestedIterator = contextsiterator;
    iterator->iteratorNextCode = ((cpp_function_code)(&filteredNestedIteratorNextP));
    iterator->iteratorFilterCode = ((cpp_function_code)(&filterModuleP));
    return (iterator);
  }
}

Iterator* allIncludedModules(Module* self) {
  // Generate a sequence of all modules included
  // by 'self', inclusive, starting from the highest ancestor and working
  // down to 'self' (which is last).
  { Cons* copy = copyConsList(((Cons*)(self->allSuperContexts)));

    copy = cons(self, copy);
    return (copy->reverse()->allocateDestructiveListIterator());
  }
}

Iterator* visibleModules(Module* from) {
  // Return an iterator that generates all modules visible from module `from'.
  // The generated modules are generated from most- to least-specific and 
  // will start with the module `from'.
  { Cons* visiblemodules = NIL;

    if (!((boolean)(from))) {
      from = oMODULEo.get();
    }
    visiblemodules = cons(from, visiblemodules);
    { Context* super = NULL;
      Cons* iter000 = from->allSuperContexts;

      while (!(iter000 == NIL)) {
        super = ((Context*)(iter000->value));
        iter000 = iter000->rest;
        visiblemodules = cons(super, visiblemodules);
      }
    }
    { Module* usee = NULL;
      Cons* iter001 = from->uses->theConsList;

      while (!(iter001 == NIL)) {
        usee = ((Module*)(iter001->value));
        iter001 = iter001->rest;
        if (!visiblemodules->membP(usee)) {
          visiblemodules = cons(usee, visiblemodules);
        }
        { Context* useesuper = NULL;
          Cons* iter002 = usee->allSuperContexts;

          while (!(iter002 == NIL)) {
            useesuper = ((Context*)(iter002->value));
            iter002 = iter002->rest;
            if (!visiblemodules->membP(useesuper)) {
              visiblemodules = cons(useesuper, visiblemodules);
            }
          }
        }
      }
    }
    return (visiblemodules->reverse()->allocateDestructiveListIterator());
  }
}

boolean cardinalModuleP(Module* self) {
  return (self->cardinalModule == self);
}

boolean visibleFromP(Context* viewedcontext, Context* fromcontext) {
  { boolean testValue000 = FALSE;

    if (viewedcontext == fromcontext) {
      testValue000 = TRUE;
    }
    else {
      if (fromcontext->allSuperContexts->membP(viewedcontext)) {
        testValue000 = TRUE;
      }
      else {
        { boolean foundP000 = FALSE;

          { Module* usesmodule = NULL;
            Cons* iter000 = ((isaP(fromcontext, SGT_MODULES_STELLA_MODULE) ? ((Module*)(fromcontext))->uses : fromcontext->baseModule->uses))->theConsList;

            while (!(iter000 == NIL)) {
              usesmodule = ((Module*)(iter000->value));
              iter000 = iter000->rest;
              if ((viewedcontext == usesmodule) ||
                  usesmodule->allSuperContexts->membP(viewedcontext)) {
                foundP000 = TRUE;
                break;
              }
            }
          }
          testValue000 = foundP000;
        }
      }
    }
    { boolean value000 = testValue000;

      return (value000);
    }
  }
}

void clearOneContext(Context* self) {
  if (subtypeOfP(safePrimaryType(self), SGT_MODULES_STELLA_MODULE)) {
    { Context* self000 = self;
      Module* self = ((Module*)(self000));

      if (!self->clearableP_reader()) {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Module " << "`" << self->moduleFullName << "'" << " cannot be cleared!" << std::endl;
        return;
      }
      runHooks(oCLEAR_MODULE_HOOKSo, self);
      { MethodSlot* function = NULL;
        Iterator* iter000 = allFunctions(self, TRUE);

        while (iter000->nextP()) {
          function = ((MethodSlot*)(iter000->value));
          destroyFunction(function);
        }
      }
      { GlobalVariable* variable = NULL;
        Iterator* iter001 = allVariables(self, TRUE);

        while (iter001->nextP()) {
          variable = ((GlobalVariable*)(iter001->value));
          destroyVariable(variable);
        }
      }
      { Class* clasS = NULL;
        Iterator* iter002 = allClasses(self, TRUE);

        while (iter002->nextP()) {
          clasS = ((Class*)(iter002->value));
          clasS->destroyClass();
        }
      }
      { Surrogate* surrogate = NULL;
        Iterator* iter003 = allSurrogates(self, TRUE);

        while (iter003->nextP()) {
          surrogate = ((Surrogate*)(iter003->value));
          if (self->protectSurrogatesP_reader()) {
            surrogate->surrogateValue = NULL;
          }
          else {
            uninternSurrogate(surrogate);
          }
        }
      }
      if (!(self->protectSurrogatesP_reader())) {
        { Symbol* symbol = NULL;
          Iterator* iter004 = allSymbols(self, TRUE);

          while (iter004->nextP()) {
            symbol = ((Symbol*)(iter004->value));
            uninternSymbol(symbol);
          }
        }
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, self);
        { ListIterator* it = ((ListIterator*)(self->shadowedSurrogates_reader()->allocateIterator()));

          while (it->nextP()) {
            it->valueSetter(shadowSurrogate(((Surrogate*)(it->value))->symbolName));
          }
        }
      }
    }
  }
  else {
  }
}

void helpClearContext(Context* self) {
  { Context* child = NULL;
    Cons* iter000 = self->childContexts->theConsList;

    while (!(iter000 == NIL)) {
      child = ((Context*)(iter000->value));
      iter000 = iter000->rest;
      helpClearContext(child);
    }
  }
  clearOneContext(self);
}

void clearContext(Context* self) {
  // Destroy all objects belonging to 'self' or any of its subcontexts.
  helpClearContext(self);
  finalizeClassesAndSlots();
}

void callClearModule(Cons* name) {
  // Destroy all objects belonging to module `name' or any of its children.
  // If no `name' is supplied, the current module will be cleared after
  // confirming with the user.  Important modules such as STELLA are protected
  // against accidental clearing.
  { Cons* arglist = name;
    Module* module = coerceToModule(arglist->value, TRUE);

    if (((boolean)(module))) {
      if ((!(arglist == NIL)) ||
          yOrNP(stringConcatenate("Really clear module ", stringConcatenate(module->moduleFullName, "? ", 0), 0))) {
        clearContext(module);
      }
    }
  }
}

void callClearModuleEvaluatorWrapper(Cons* arguments) {
  callClearModule(arguments);
}

void clearModule(Cons* name) {
  // Destroy all objects belonging to module `name' or any of its children.
  // If no `name' is supplied, the current module will be cleared after
  // confirming with the user.  Important modules such as STELLA are protected
  // against accidental clearing.
  if (name->length() == 0) {
    callClearModule(NIL);
  }
  else {
    callClearModule(consList(1, name->value));
  }
}

void clearModuleEvaluatorWrapper(Cons* arguments) {
  clearModule(arguments);
}

void helpStartupModules1() {
  {
    KWD_MODULES_CLEAR = ((Keyword*)(internRigidSymbolWrtModule("CLEAR", NULL, 2)));
    SGT_MODULES_STELLA_MODULE = ((Surrogate*)(internRigidSymbolWrtModule("MODULE", NULL, 1)));
    SGT_MODULES_STELLA_UNKNOWN_SURROGATE = ((Surrogate*)(internRigidSymbolWrtModule("UNKNOWN-SURROGATE", NULL, 1)));
    SYM_MODULES_STELLA_UNKNOWN_SYMBOL = ((Symbol*)(internRigidSymbolWrtModule("UNKNOWN-SYMBOL", NULL, 0)));
    SYM_MODULES_STELLA_NAME = ((Symbol*)(internRigidSymbolWrtModule("NAME", NULL, 0)));
    SGT_MODULES_STELLA_MUTABLE_STRING_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("MUTABLE-STRING-WRAPPER", NULL, 1)));
    SYM_MODULES_STELLA_SHADOWED_SURROGATES = ((Symbol*)(internRigidSymbolWrtModule("SHADOWED-SURROGATES", NULL, 0)));
    SGT_MODULES_STELLA_CONS = ((Surrogate*)(internRigidSymbolWrtModule("CONS", NULL, 1)));
    KWD_MODULES_INCLUDES = ((Keyword*)(internRigidSymbolWrtModule("INCLUDES", NULL, 2)));
    KWD_MODULES_USES = ((Keyword*)(internRigidSymbolWrtModule("USES", NULL, 2)));
    KWD_MODULES_SHADOW = ((Keyword*)(internRigidSymbolWrtModule("SHADOW", NULL, 2)));
    KWD_MODULES_DOCUMENTATION = ((Keyword*)(internRigidSymbolWrtModule("DOCUMENTATION", NULL, 2)));
    KWD_MODULES_CASE_SENSITIVEp = ((Keyword*)(internRigidSymbolWrtModule("CASE-SENSITIVE?", NULL, 2)));
    SYM_MODULES_STELLA_TRUE = ((Symbol*)(internRigidSymbolWrtModule("TRUE", NULL, 0)));
    KWD_MODULES_APIp = ((Keyword*)(internRigidSymbolWrtModule("API?", NULL, 2)));
    SYM_MODULES_STELLA_APIp = ((Symbol*)(internRigidSymbolWrtModule("API?", NULL, 0)));
    KWD_MODULES_LISP_PACKAGE = ((Keyword*)(internRigidSymbolWrtModule("LISP-PACKAGE", NULL, 2)));
    SYM_MODULES_STELLA_MODULE_LISP_PACKAGE = ((Symbol*)(internRigidSymbolWrtModule("MODULE-LISP-PACKAGE", NULL, 0)));
    KWD_MODULES_CPP_PACKAGE = ((Keyword*)(internRigidSymbolWrtModule("CPP-PACKAGE", NULL, 2)));
    SYM_MODULES_STELLA_MODULE_CPP_PACKAGE = ((Symbol*)(internRigidSymbolWrtModule("MODULE-CPP-PACKAGE", NULL, 0)));
    KWD_MODULES_JAVA_PACKAGE = ((Keyword*)(internRigidSymbolWrtModule("JAVA-PACKAGE", NULL, 2)));
    SYM_MODULES_STELLA_JAVA_PACKAGE = ((Symbol*)(internRigidSymbolWrtModule("JAVA-PACKAGE", NULL, 0)));
    KWD_MODULES_JAVA_CATCHALL_CLASS = ((Keyword*)(internRigidSymbolWrtModule("JAVA-CATCHALL-CLASS", NULL, 2)));
    SYM_MODULES_STELLA_JAVA_FLOTSAM_CLASS = ((Symbol*)(internRigidSymbolWrtModule("JAVA-FLOTSAM-CLASS", NULL, 0)));
    KWD_MODULES_NICKNAME = ((Keyword*)(internRigidSymbolWrtModule("NICKNAME", NULL, 2)));
    KWD_MODULES_CLEARABLEp = ((Keyword*)(internRigidSymbolWrtModule("CLEARABLE?", NULL, 2)));
    SYM_MODULES_STELLA_CLEARABLEp = ((Symbol*)(internRigidSymbolWrtModule("CLEARABLE?", NULL, 0)));
    KWD_MODULES_PROTECT_SURROGATESp = ((Keyword*)(internRigidSymbolWrtModule("PROTECT-SURROGATES?", NULL, 2)));
    SYM_MODULES_STELLA_PROTECT_SURROGATESp = ((Symbol*)(internRigidSymbolWrtModule("PROTECT-SURROGATES?", NULL, 0)));
    KWD_MODULES_CODE_ONLYp = ((Keyword*)(internRigidSymbolWrtModule("CODE-ONLY?", NULL, 2)));
    SYM_MODULES_STELLA_CODE_ONLYp = ((Symbol*)(internRigidSymbolWrtModule("CODE-ONLY?", NULL, 0)));
    KWD_MODULES_REQUIRES = ((Keyword*)(internRigidSymbolWrtModule("REQUIRES", NULL, 2)));
    KWD_MODULES_DESTROY = ((Keyword*)(internRigidSymbolWrtModule("DESTROY", NULL, 2)));
    KWD_MODULES_PRESERVE = ((Keyword*)(internRigidSymbolWrtModule("PRESERVE", NULL, 2)));
    KWD_MODULES_PREORDER = ((Keyword*)(internRigidSymbolWrtModule("PREORDER", NULL, 2)));
    SGT_MODULES_STELLA_WORLD = ((Surrogate*)(internRigidSymbolWrtModule("WORLD", NULL, 1)));
    SYM_MODULES_STELLA_DEFINE_MODULE_FROM_STRINGIFIED_SOURCE = ((Symbol*)(internRigidSymbolWrtModule("DEFINE-MODULE-FROM-STRINGIFIED-SOURCE", NULL, 0)));
    SYM_MODULES_STELLA_WORLD_NAME = ((Symbol*)(internRigidSymbolWrtModule("WORLD-NAME", NULL, 0)));
    KWD_MODULES_POSTORDER = ((Keyword*)(internRigidSymbolWrtModule("POSTORDER", NULL, 2)));
    KWD_MODULES_INORDER = ((Keyword*)(internRigidSymbolWrtModule("INORDER", NULL, 2)));
    SYM_MODULES_STELLA_STARTUP_MODULES = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-MODULES", NULL, 0)));
    SYM_MODULES_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", NULL, 0)));
  }
}

void helpStartupModules2() {
  {
    defineMethodObject("(DEFMETHOD (PARENT-CONTEXTS (ITERATOR OF CONTEXT)) ((SELF CONTEXT)))", ((cpp_method_code)(&Context::parentContexts)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (PARENT-CONTEXTS (ITERATOR OF CONTEXT)) ((SELF MODULE)) :PUBLIC? TRUE)", ((cpp_method_code)(&Module::parentContexts)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (PARENT-CONTEXTS (ITERATOR OF CONTEXT)) ((SELF WORLD)) :PUBLIC? TRUE)", ((cpp_method_code)(&World::parentContexts)), ((cpp_method_code)(NULL)));
    defineFunctionObject("COMPUTE-CONTEXT-OR-MODULE-FROM-PATHNAME", "(DEFUN (COMPUTE-CONTEXT-OR-MODULE-FROM-PATHNAME CONTEXT INTEGER) ((PATHNAME STRING) (MODULE? BOOLEAN) (SYMBOLNAME? BOOLEAN)))", ((cpp_function_code)(&computeContextOrModuleFromPathname)), NULL);
    defineFunctionObject("COMPONENT-MATCH?", "(DEFUN (COMPONENT-MATCH? BOOLEAN) ((COMPONENT STRING) (STRING STRING) (START INTEGER) (END INTEGER)))", ((cpp_function_code)(&componentMatchP)), NULL);
    defineFunctionObject("COMPUTE-MODULE-AND-BARE-NAME", "(DEFUN (COMPUTE-MODULE-AND-BARE-NAME MODULE STRING) ((NAME STRING)) :PUBLIC? TRUE)", ((cpp_function_code)(&computeModuleAndBareName)), NULL);
    defineFunctionObject("QUALIFIED-NAME-MODULE-NAME", "(DEFUN (QUALIFIED-NAME-MODULE-NAME STRING) ((QUALIFIEDNAME STRING)))", ((cpp_function_code)(&qualifiedNameModuleName)), NULL);
    defineFunctionObject("QUALIFIED-NAME-BARE-NAME", "(DEFUN (QUALIFIED-NAME-BARE-NAME STRING) ((QUALIFIEDNAME STRING)))", ((cpp_function_code)(&qualifiedNameBareName)), NULL);
    defineFunctionObject("DWIM-MODULE-AND-BARE-NAME", "(DEFUN (DWIM-MODULE-AND-BARE-NAME MODULE STRING) ((NAME STRING) (WARN? BOOLEAN)))", ((cpp_function_code)(&dwimModuleAndBareName)), NULL);
    defineFunctionObject("INTERN-QUALIFIED-NAME", "(DEFUN (INTERN-QUALIFIED-NAME GENERALIZED-SYMBOL) ((NAME STRING) (ENABLE-CASE-CONVERSION? BOOLEAN)))", ((cpp_function_code)(&internQualifiedName)), NULL);
    defineFunctionObject("HELP-GET-STELLA-CONTEXT-OR-MODULE", "(DEFUN (HELP-GET-STELLA-CONTEXT-OR-MODULE CONTEXT) ((PATHNAME STRING) (MODULE? BOOLEAN)))", ((cpp_function_code)(&helpGetStellaContextOrModule)), NULL);
    defineFunctionObject("GET-STELLA-CONTEXT", "(DEFUN (GET-STELLA-CONTEXT CONTEXT) ((PATHNAME STRING) (ERROR? BOOLEAN)) :DOCUMENTATION \"Return the context located at `pathName', or `null'\nif no such context exists.  If `error?' is `true', throw an exception\nif no context is found, otherwise silently return `null'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getStellaContext)), NULL);
    defineFunctionObject("GET-STELLA-MODULE", "(DEFUN (GET-STELLA-MODULE MODULE) ((PATHNAME STRING) (ERROR? BOOLEAN)) :DOCUMENTATION \"Return the module located at `pathName', or `null'\nif no such module exists.  The search looks at ancestors and top-most\n (cardinal) modules.  If `error?' is `true', throw an exception if no\n module is found.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getStellaModule)), NULL);
    defineFunctionObject("COERCE-TO-MODULE-NAME", "(DEFUN (COERCE-TO-MODULE-NAME STRING) ((NAMESPEC NAME) (WARN? BOOLEAN)))", ((cpp_function_code)(&coerceToModuleName)), NULL);
    defineFunctionObject("COERCE-TO-MODULE", "(DEFUN (COERCE-TO-MODULE MODULE) ((OBJECT OBJECT) (WARN? BOOLEAN)) :PUBLIC? TRUE)", ((cpp_function_code)(&coerceToModule)), NULL);
    defineFunctionObject("FIND-OR-CREATE-MODULE", "(DEFUN (FIND-OR-CREATE-MODULE MODULE) ((PATHNAME STRING)) :DOCUMENTATION \"Return a module located at `pathname' if one exists,\n  otherwise create one\")", ((cpp_function_code)(&findOrCreateModule)), NULL);
    defineFunctionObject("CHANGE-CURRENT-MODULE", "(DEFUN (CHANGE-CURRENT-MODULE MODULE) ((MODULE MODULE)))", ((cpp_function_code)(&changeCurrentModule)), NULL);
    defineFunctionObject("CHANGE-CURRENT-CONTEXT", "(DEFUN (CHANGE-CURRENT-CONTEXT CONTEXT) ((CONTEXT CONTEXT)))", ((cpp_function_code)(&changeCurrentContext)), NULL);
    defineMethodObject("(DEFMETHOD (CHANGE-CONTEXT CONTEXT) ((CONTEXT CONTEXT)) :DOCUMENTATION \"Change the current context to be the context\n'context'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&Context::changeContext)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (CHANGE-CONTEXT CONTEXT) ((CONTEXTNAME STRING)) :DOCUMENTATION \"Change the current context to be the context named\n'contextName'.\" :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (CHANGE-MODULE MODULE) ((MODULE MODULE)) :DOCUMENTATION \"Change the current module to be the module\n'module'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&Module::changeModule)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (CHANGE-MODULE MODULE) ((MODULENAME STRING)) :DOCUMENTATION \"Change the current module to be the module named\n'moduleName'.\" :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (MULTIPLE-PARENTS? BOOLEAN) ((MODULE MODULE)) :DOCUMENTATION \"Return TRUE if 'module' has more than one parent.\")", ((cpp_method_code)(&Module::multipleParentsP)), ((cpp_method_code)(NULL)));
    defineFunctionObject("NORMALIZE-PARENT-MODULES", "(DEFUN NORMALIZE-PARENT-MODULES ((SELF MODULE)))", ((cpp_function_code)(&normalizeParentModules)), NULL);
    defineFunctionObject("INHERIT-SUPERCONTEXTS", "(DEFUN INHERIT-SUPERCONTEXTS ((MODULE MODULE)))", ((cpp_function_code)(&inheritSupercontexts)), NULL);
    defineFunctionObject("UNINHERIT-SUPERCONTEXTS", "(DEFUN UNINHERIT-SUPERCONTEXTS ((MODULE MODULE)))", ((cpp_function_code)(&uninheritSupercontexts)), NULL);
    defineFunctionObject("INHERIT-USED-MODULES", "(DEFUN INHERIT-USED-MODULES ((MODULE MODULE)))", ((cpp_function_code)(&inheritUsedModules)), NULL);
    defineFunctionObject("UNINHERIT-USED-MODULES", "(DEFUN UNINHERIT-USED-MODULES ((MODULE MODULE)))", ((cpp_function_code)(&uninheritUsedModules)), NULL);
    defineFunctionObject("FINALIZE-MODULE", "(DEFUN FINALIZE-MODULE ((SELF MODULE)))", ((cpp_function_code)(&finalizeModule)), NULL);
    defineFunctionObject("FINALIZE-WORLD", "(DEFUN FINALIZE-WORLD ((SELF WORLD)))", ((cpp_function_code)(&finalizeWorld)), NULL);
    defineMethodObject("(DEFMETHOD UNFINALIZE-MODULE ((SELF MODULE)))", ((cpp_method_code)(&Module::unfinalizeModule)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD UNFINALIZE-WORLD ((SELF WORLD)))", ((cpp_method_code)(&World::unfinalizeWorld)), ((cpp_method_code)(NULL)));
    defineFunctionObject("DESTROY-MODULE", "(DEFUN DESTROY-MODULE ((SELF MODULE)) :DOCUMENTATION \"Destroy the module 'self', and recursively destroy\nall contexts that inherit 'self'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&destroyModule)), NULL);
    defineFunctionObject("HELP-DESTROY-MODULE", "(DEFUN HELP-DESTROY-MODULE ((SELF MODULE)))", ((cpp_function_code)(&helpDestroyModule)), NULL);
    defineFunctionObject("DESTROY-WORLD", "(DEFUN DESTROY-WORLD ((SELF WORLD)) :PUBLIC? TRUE)", ((cpp_function_code)(&destroyWorld)), NULL);
    defineMethodObject("(DEFMETHOD DESTROY-CONTEXT ((SELF MODULE)) :DOCUMENTATION \"Destroy the context 'self', and recursively destroy\nall contexts that inherit 'self'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&Module::destroyContext)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD DESTROY-CONTEXT ((SELF WORLD)) :DOCUMENTATION \"Destroy the context 'self', and recursively destroy\nall contexts that inherit 'self'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&World::destroyContext)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD DESTROY-CONTEXT ((SELF STRING)) :DOCUMENTATION \"Destroy the context 'self', and recursively destroy\nall contexts that inherit 'self'.\" :PUBLIC? TRUE)", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD DESTROY-CONTEXT ((SELF CONTEXT)) :PUBLIC? TRUE :DOCUMENTATION \"Make the translator happy.\")", ((cpp_method_code)(&Context::destroyContext)), ((cpp_method_code)(NULL)));
    defineFunctionObject("LINK-TO-PARENT-MODULE", "(DEFUN LINK-TO-PARENT-MODULE ((SELF MODULE) (PARENT MODULE) (INSERT-FIRST? BOOLEAN)))", ((cpp_function_code)(&linkToParentModule)), NULL);
    defineFunctionObject("INCORPORATE-MODULE-NAME", "(DEFUN INCORPORATE-MODULE-NAME ((MODULE MODULE) (NAME STRING)))", ((cpp_function_code)(&incorporateModuleName)), NULL);
    defineFunctionObject("INCORPORATE-INCLUDES-MODULES", "(DEFUN INCORPORATE-INCLUDES-MODULES ((MODULE MODULE) (INCLUDEES OBJECT)))", ((cpp_function_code)(&incorporateIncludesModules)), NULL);
    defineFunctionObject("INCORPORATE-USES-MODULES", "(DEFUN INCORPORATE-USES-MODULES ((MODULE MODULE) (USEES OBJECT)))", ((cpp_function_code)(&incorporateUsesModules)), NULL);
    defineFunctionObject("INCORPORATE-MODULE-OPTIONS", "(DEFUN INCORPORATE-MODULE-OPTIONS ((SELF MODULE) (OPTIONS CONS)))", ((cpp_function_code)(&incorporateModuleOptions)), NULL);
    defineFunctionObject("UNDEFINE-MODULE", "(DEFUN UNDEFINE-MODULE ((OLDMODULE MODULE) (NEWMODULE MODULE)))", ((cpp_function_code)(&undefineModule)), NULL);
    defineFunctionObject("DEFINE-MODULE", "(DEFUN (DEFINE-MODULE MODULE) ((NAME STRING) (OPTIONS CONS)) :DOCUMENTATION \"Define or redefine a module named 'name' having the\noptions 'options'.  Return the new module.\" :PUBLIC? TRUE)", ((cpp_function_code)(&defineModule)), NULL);
    defineFunctionObject("IDENTICAL-MODULE-SIGNATURES?", "(DEFUN (IDENTICAL-MODULE-SIGNATURES? BOOLEAN) ((OLDMODULE MODULE) (NEWMODULE MODULE) (NEWOPTIONS STRING)))", ((cpp_function_code)(&identicalModuleSignaturesP)), NULL);
    defineFunctionObject("DEFINE-MODULE-FROM-STRINGIFIED-SOURCE", "(DEFUN (DEFINE-MODULE-FROM-STRINGIFIED-SOURCE MODULE) ((NAME STRING) (STRINGIFIEDOPTIONS STRING)) :PUBLIC? TRUE)", ((cpp_function_code)(&defineModuleFromStringifiedSource)), NULL);
    defineFunctionObject("YIELD-DEFINE-MODULE", "(DEFUN (YIELD-DEFINE-MODULE CONS) ((MODULE MODULE)))", ((cpp_function_code)(&yieldDefineModule)), NULL);
    defineFunctionObject("DEFMODULE", stringConcatenate("(DEFUN DEFMODULE ((NAME NAME) |&REST| (OPTIONS OBJECT)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a module named `name'.\nThe accepted syntax is:\n	 \n  (defmodule <module-name>\n     [:documentation <docstring>]\n     [:includes {<module-name> | (<module-name>*)}]\n     [:uses {<module-name> | (<module-name>*)}]\n     [:lisp-package <package-name-string>]\n     [:java-package <package-specification-string>]\n     [:cpp-namespace <namespace-name-string>]\n     [:java-catchall-class\n     [:api? {TRUE | FALSE}]\n     [:case-sensitive? {TRUE | FALSE}]\n     [:shadow (<symbol>*)]\n     [:java-catchall-class <class-name-string>]\n     [<other-options>*])\n	\n`name' can be a string or a symbol.\n\nModules include objects from other modules via two separate mechanisms:\n(1) they inherit from their parents specified via the `:includes' option\nand/or a fully qualified module name, and (2) they inherit from used\nmodules specified via the `:uses' option.  The main difference between\nthe two mechanisms is that inheritance from parents is transitive, while\nuses-links are only followed one level deep.  I.e., a module A that uses\nB will see all objects of B (and any of B's parents) but not see anything\nfrom modules used by B.  Another difference is that only objects declared\nas public can be inherited via uses-links (this is not yet enforced).\nNote that - contrary to Lisp - there are separate name spaces for classes,\nfunctions, and variables.  For example, a module could inherit the class\n`CONS' from the `STELLA' module, but shadow the function of the same name.\n\nThe above discussion of `:includes' and `:uses' semantics keyed on the\ninheritance/visibility of symbols. The PowerLoom system makes another\nvery important distinction: If a module 'A' is inherited directly or\nindirectly via `:includes' specification(s) by a submodule 'B', then all\ndefinitions and facts asserted in 'A' are visible in 'B'. This is not the\ncases for `:uses'; the `:uses' options does not impact inheritance of\npropositions at all.\n\nThe list of modules specified in the\n`:includes' option plus (if supplied) the parent in the path used for\n`name' become the new module's parents. If no `:uses' option was\nsupplied, the new module will use the `STELLA' module by default,\notherwise, it will use the set of specified modules.\nIf `:case-sensitive?' is supplied as TRUE, symbols in the module will be\ninterned case-sensitively, otherwise (the default), they will be\nconverted to uppercase before they get interned. Modules can shadow\ndefinitions of functions and classes inherited from parents or used\nmodules. Shadowing is done automatically, but generates a warning unless\nthe shadowed type or function name is listed in the `:shadow' option of\nthe module definition .\n\nExamples:\n	 \n  (defmodule \\\"PL-KERNEL/PL-USER\\\"\n    :uses (\\\"LOGIC\\\" \\\"STELLA\\\")\n    :package \\\"PL-USER\\\")\n\n  (defmodule PL-USER/GENEALOGY)\n	\nThe remaining options are relevant only for modules that contain STELLA\ncode.  Modules used only to contain knowledge base definitions and assertions\nhave no use for them:\n\nThe keywords `:lisp-package', `:java-package', and `:cpp-package' specify\nthe name of a native package or name space in which symbols of the module\nshould be allocated when they get translated into one of Lisp, Java, or\nC++. By default, Lisp symbols are allocated in the `STELLA' package, and\nC++ names are translated without any prefixes. The rules that the STELLA\ntranslator uses to attach translated Java objects to classes and packages\nare somewhat complex. Use :java-package option to specify a list of\npackage names (separated by periods) that prefix the Java object in this\nmodule.  Use :java-catchall-class to specify the name of the Java class to\ncontain all global & special variables, parameter-less functions and functions \ndefined on arguments that are not classes in the current module.\nThe default value will be the name of the module.\n\nWhen set to TRUE, the :api? option tells t", "he PowerLoom User Manual\ngenerator that all functions defined in this module should be included in\nthe API section. Additionally, the Java translator makes all API\nfunctions `synchronized'.\n\")", 0), ((cpp_function_code)(&defmodule)), ((cpp_function_code)(&defmoduleEvaluatorWrapper)));
    defineFunctionObject("IN-MODULE", "(DEFUN (IN-MODULE MODULE) ((NAME NAME)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :LISP-MACRO? TRUE :DOCUMENTATION \"Change the current module to the module named `name'.\")", ((cpp_function_code)(&inModule)), NULL);
    defineFunctionObject("CREATE-WORLD", "(DEFUN (CREATE-WORLD WORLD) ((PARENTCONTEXT CONTEXT) (NAME STRING)) :DOCUMENTATION \"Create a new world below the world or module 'parentContext'.\nOptionally, specify a name.\" :PUBLIC? TRUE :INLINE FINALIZE-WORLD)", ((cpp_function_code)(&createWorld)), NULL);
    defineFunctionObject("PUSH-WORLD", "(DEFUN (PUSH-WORLD WORLD) () :DOCUMENTATION \"Spawn a new world that is a child of the current context,\nand change the current context to the new world.\" :PUBLIC? TRUE)", ((cpp_function_code)(&pushWorld)), NULL);
    defineFunctionObject("POP-WORLD", "(DEFUN (POP-WORLD CONTEXT) () :DOCUMENTATION \"Destroy the current world and change the current\ncontext to be its parent.  Return the current context. Nothing happens\nif there is no current world.\" :PUBLIC? TRUE)", ((cpp_function_code)(&popWorld)), NULL);
    defineFunctionObject("ALL-SUBCONTEXTS", "(DEFUN (ALL-SUBCONTEXTS (ALL-PURPOSE-ITERATOR OF CONTEXT)) ((CONTEXT CONTEXT) (TRAVERSAL KEYWORD)) :DOCUMENTATION \"Return an iterator that generates all subcontexts of\n'self' (not including 'self') in the order specified by 'traversal' (one\nof :preorder, :inorder, or :postorder).\")", ((cpp_function_code)(&allSubcontexts)), NULL);
    defineFunctionObject("ALL-SUBCONTEXTS-NEXT?", "(DEFUN (ALL-SUBCONTEXTS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))", ((cpp_function_code)(&allSubcontextsNextP)), NULL);
    defineFunctionObject("ALL-CONTEXTS", "(DEFUN (ALL-CONTEXTS (ITERATOR OF CONTEXT)) () :PUBLIC? TRUE :DOCUMENTATION \"Return an iterator that generates all contexts.\")", ((cpp_function_code)(&allContexts)), NULL);
    defineFunctionObject("FILTER-MODULE?", "(DEFUN (FILTER-MODULE? BOOLEAN) ((SELF OBJECT) (ITERATOR ALL-PURPOSE-ITERATOR)))", ((cpp_function_code)(&filterModuleP)), NULL);
    defineFunctionObject("ALL-MODULES", "(DEFUN (ALL-MODULES (ITERATOR OF MODULE)) () :PUBLIC? TRUE :DOCUMENTATION \"Return an iterator that generates all modules.\")", ((cpp_function_code)(&allModules)), NULL);
    defineFunctionObject("ALL-INCLUDED-MODULES", "(DEFUN (ALL-INCLUDED-MODULES (ITERATOR OF MODULE)) ((SELF MODULE)) :PUBLIC? TRUE :DOCUMENTATION \"Generate a sequence of all modules included\nby 'self', inclusive, starting from the highest ancestor and working\ndown to 'self' (which is last).\")", ((cpp_function_code)(&allIncludedModules)), NULL);
  }
}

void startupModules() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oSTELLA_MODULEo);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupModules1();
    }
    if (currentStartupTimePhaseP(4)) {
      oSUBCONTEXT_REVISION_POLICYo = KWD_MODULES_CLEAR;
      oDEFINE_MODULE_HOOKSo = newHookList();
    }
    if (currentStartupTimePhaseP(5)) {
      defineStellaTypeFromStringifiedSource("(DEFTYPE NAME OBJECT)");
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupModules2();
      defineFunctionObject("VISIBLE-MODULES", "(DEFUN (VISIBLE-MODULES (ITERATOR OF MODULE)) ((FROM MODULE)) :PUBLIC? TRUE :DOCUMENTATION \"Return an iterator that generates all modules visible from module `from'.\nThe generated modules are generated from most- to least-specific and \nwill start with the module `from'.\")", ((cpp_function_code)(&visibleModules)), NULL);
      defineFunctionObject("CARDINAL-MODULE?", "(DEFUN (CARDINAL-MODULE? BOOLEAN) ((SELF MODULE)))", ((cpp_function_code)(&cardinalModuleP)), NULL);
      defineFunctionObject("VISIBLE-FROM?", "(DEFUN (VISIBLE-FROM? BOOLEAN) ((VIEWEDCONTEXT CONTEXT) (FROMCONTEXT CONTEXT)) :PUBLIC? TRUE)", ((cpp_function_code)(&visibleFromP)), NULL);
      defineFunctionObject("CLEAR-ONE-CONTEXT", "(DEFUN CLEAR-ONE-CONTEXT ((SELF CONTEXT)))", ((cpp_function_code)(&clearOneContext)), NULL);
      defineFunctionObject("HELP-CLEAR-CONTEXT", "(DEFUN HELP-CLEAR-CONTEXT ((SELF CONTEXT)))", ((cpp_function_code)(&helpClearContext)), NULL);
      defineFunctionObject("CLEAR-CONTEXT", "(DEFUN CLEAR-CONTEXT ((SELF CONTEXT)) :PUBLIC? TRUE :DOCUMENTATION \"Destroy all objects belonging to 'self' or any of its subcontexts.\")", ((cpp_function_code)(&clearContext)), NULL);
      defineFunctionObject("CALL-CLEAR-MODULE", "(DEFUN CALL-CLEAR-MODULE (|&REST| (NAME NAME)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? TRUE :LISP-MACRO? FALSE :DOCUMENTATION \"Destroy all objects belonging to module `name' or any of its children.\nIf no `name' is supplied, the current module will be cleared after\nconfirming with the user.  Important modules such as STELLA are protected\nagainst accidental clearing.\")", ((cpp_function_code)(&callClearModule)), ((cpp_function_code)(&callClearModuleEvaluatorWrapper)));
      defineFunctionObject("CLEAR-MODULE", "(DEFUN CLEAR-MODULE (|&REST| (NAME NAME)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Destroy all objects belonging to module `name' or any of its children.\nIf no `name' is supplied, the current module will be cleared after\nconfirming with the user.  Important modules such as STELLA are protected\nagainst accidental clearing.\")", ((cpp_function_code)(&clearModule)), ((cpp_function_code)(&clearModuleEvaluatorWrapper)));
      defineFunctionObject("STARTUP-MODULES", "(DEFUN STARTUP-MODULES () :PUBLIC? TRUE)", ((cpp_function_code)(&startupModules)), NULL);
      { MethodSlot* function = lookupFunction(SYM_MODULES_STELLA_STARTUP_MODULES);

        setDynamicSlotValue(function->dynamicSlots, SYM_MODULES_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Modules"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SUBCONTEXT-REVISION-POLICY* KEYWORD :CLEAR :DOCUMENTATION \"Controls actions reflexive transitive closure of\n   subcontexts when a context is revised.\n   Values are ':destroy' -- destroy subcontexts;\n   ':clear' -- clear contents of subcontexts;\n   ':preserve' -- don't disturb subcontexts.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *SHADOWEDSURROGATES* (CONS OF SYMBOL) NULL :DOCUMENTATION \"Holds list of symbols representing surrogates\nto be shadowed during module finalization.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DEFINE-MODULE-HOOKS* HOOK-LIST (NEW HOOK-LIST) :DOCUMENTATION \"HOOK-LIST called by 'define-module', applied to a\n'module' argument.\")");
      setDynamicSlotValue(oROOT_MODULEo->dynamicSlots, SYM_MODULES_STELLA_CLEARABLEp, (FALSE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
      setDynamicSlotValue(oSTELLA_MODULEo->dynamicSlots, SYM_MODULES_STELLA_CLEARABLEp, (FALSE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
      setDynamicSlotValue(oCOMMON_LISP_MODULEo->dynamicSlots, SYM_MODULES_STELLA_CLEARABLEp, (FALSE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
    }
  }
}

Keyword* KWD_MODULES_CLEAR = NULL;

Surrogate* SGT_MODULES_STELLA_MODULE = NULL;

Surrogate* SGT_MODULES_STELLA_UNKNOWN_SURROGATE = NULL;

Symbol* SYM_MODULES_STELLA_UNKNOWN_SYMBOL = NULL;

Symbol* SYM_MODULES_STELLA_NAME = NULL;

Surrogate* SGT_MODULES_STELLA_MUTABLE_STRING_WRAPPER = NULL;

Symbol* SYM_MODULES_STELLA_SHADOWED_SURROGATES = NULL;

Surrogate* SGT_MODULES_STELLA_CONS = NULL;

Keyword* KWD_MODULES_INCLUDES = NULL;

Keyword* KWD_MODULES_USES = NULL;

Keyword* KWD_MODULES_SHADOW = NULL;

Keyword* KWD_MODULES_DOCUMENTATION = NULL;

Keyword* KWD_MODULES_CASE_SENSITIVEp = NULL;

Symbol* SYM_MODULES_STELLA_TRUE = NULL;

Keyword* KWD_MODULES_APIp = NULL;

Symbol* SYM_MODULES_STELLA_APIp = NULL;

Keyword* KWD_MODULES_LISP_PACKAGE = NULL;

Symbol* SYM_MODULES_STELLA_MODULE_LISP_PACKAGE = NULL;

Keyword* KWD_MODULES_CPP_PACKAGE = NULL;

Symbol* SYM_MODULES_STELLA_MODULE_CPP_PACKAGE = NULL;

Keyword* KWD_MODULES_JAVA_PACKAGE = NULL;

Symbol* SYM_MODULES_STELLA_JAVA_PACKAGE = NULL;

Keyword* KWD_MODULES_JAVA_CATCHALL_CLASS = NULL;

Symbol* SYM_MODULES_STELLA_JAVA_FLOTSAM_CLASS = NULL;

Keyword* KWD_MODULES_NICKNAME = NULL;

Keyword* KWD_MODULES_CLEARABLEp = NULL;

Symbol* SYM_MODULES_STELLA_CLEARABLEp = NULL;

Keyword* KWD_MODULES_PROTECT_SURROGATESp = NULL;

Symbol* SYM_MODULES_STELLA_PROTECT_SURROGATESp = NULL;

Keyword* KWD_MODULES_CODE_ONLYp = NULL;

Symbol* SYM_MODULES_STELLA_CODE_ONLYp = NULL;

Keyword* KWD_MODULES_REQUIRES = NULL;

Keyword* KWD_MODULES_DESTROY = NULL;

Keyword* KWD_MODULES_PRESERVE = NULL;

Keyword* KWD_MODULES_PREORDER = NULL;

Surrogate* SGT_MODULES_STELLA_WORLD = NULL;

Symbol* SYM_MODULES_STELLA_DEFINE_MODULE_FROM_STRINGIFIED_SOURCE = NULL;

Symbol* SYM_MODULES_STELLA_WORLD_NAME = NULL;

Keyword* KWD_MODULES_POSTORDER = NULL;

Keyword* KWD_MODULES_INORDER = NULL;

Symbol* SYM_MODULES_STELLA_STARTUP_MODULES = NULL;

Symbol* SYM_MODULES_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace stella
