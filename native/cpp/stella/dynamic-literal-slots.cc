//  -*- Mode: C++ -*-

// dynamic-literal-slots.cc

/*
+---------------------------- BEGIN LICENSE BLOCK ---------------------------+
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
+---------------------------- END LICENSE BLOCK -----------------------------+
*/

#include "stella/stella-system.hh"

namespace stella {

void startupDynamicLiteralSlots() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oSTELLA_MODULEo);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      SYM_DYNAMIC_LITERAL_SLOTS_STELLA_STARTUP_DYNAMIC_LITERAL_SLOTS = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-DYNAMIC-LITERAL-SLOTS", NULL, 0)));
      SYM_DYNAMIC_LITERAL_SLOTS_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", NULL, 0)));
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("STARTUP-DYNAMIC-LITERAL-SLOTS", "(DEFUN STARTUP-DYNAMIC-LITERAL-SLOTS () :PUBLIC? TRUE)", ((cpp_function_code)(&startupDynamicLiteralSlots)), NULL);
      { MethodSlot* function = lookupFunction(SYM_DYNAMIC_LITERAL_SLOTS_STELLA_STARTUP_DYNAMIC_LITERAL_SLOTS);

        setDynamicSlotValue(function->dynamicSlots, SYM_DYNAMIC_LITERAL_SLOTS_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Dynamic-Literal-Slots"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
  }
}

Symbol* SYM_DYNAMIC_LITERAL_SLOTS_STELLA_STARTUP_DYNAMIC_LITERAL_SLOTS = NULL;

Symbol* SYM_DYNAMIC_LITERAL_SLOTS_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace stella
