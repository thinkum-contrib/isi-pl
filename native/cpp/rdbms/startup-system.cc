//  -*- Mode: C++ -*-

// startup-system.cc

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
 | The Original Code is the PowerLoom KR&R System.                            |
 |                                                                            |
 | The Initial Developer of the Original Code is                              |
 | UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
 | 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
 |                                                                            |
 | Portions created by the Initial Developer are Copyright (C) 1997-2012      |
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
 +----------------------------- END LICENSE BLOCK ----------------------------+
*/

#include "rdbms/rdbms-system.hh"

namespace rdbms {
  using namespace stella;
  using namespace logic;

void startupRdbmsSystem() {
  // Should be synchronized on process lock oBOOTSTRAP_LOCKo
  {
    if (currentStartupTimePhaseP(0)) {
      if (!(systemStartedUpP("stella", "/STELLA"))) {
        startupStellaSystem();
      }
      if (!(systemStartedUpP("logic", "/LOGIC"))) {
        startupLogicSystem();
      }
      if (!(systemStartedUpP("utilities", "/UTILITIES"))) {
        stella_utilities::startupUtilitiesSystem();
      }
      if (!(systemStartedUpP("sdbc", "/SDBC"))) {
        sdbc::startupSdbcSystem();
      }
    }
    if (currentStartupTimePhaseP(1)) {
      defineModuleFromStringifiedSource("/RDBMS", "(:LISP-PACKAGE \"STELLA\" :CPP-PACKAGE \"rdbms\" :JAVA-PACKAGE \"edu.isi.powerloom.rdbms\" :JAVA-CATCHALL-CLASS \"RDBMS\" :USES (\"LOGIC\" \"STELLA\") :SHADOW (HOST PORT))");
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/RDBMS", oSTARTUP_TIME_PHASEo > 1));
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
      if (currentStartupTimePhaseP(2)) {
        SYM_STARTUP_SYSTEM_RDBMS_STARTUP_RDBMS_SYSTEM = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-RDBMS-SYSTEM", NULL, 0)));
        SYM_STARTUP_SYSTEM_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", true), 0)));
      }
      if (currentStartupTimePhaseP(6)) {
        finalizeClasses();
      }
      if (currentStartupTimePhaseP(7)) {
        defineFunctionObject("STARTUP-RDBMS-SYSTEM", "(DEFUN STARTUP-RDBMS-SYSTEM () :PUBLIC? TRUE)", ((cpp_function_code)(&startupRdbmsSystem)), NULL);
        { MethodSlot* function = lookupFunction(SYM_STARTUP_SYSTEM_RDBMS_STARTUP_RDBMS_SYSTEM);

          setDynamicSlotValue(function->dynamicSlots, SYM_STARTUP_SYSTEM_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("StartupRdbmsSystem"), NULL_STRING_WRAPPER);
        }
      }
      if (currentStartupTimePhaseP(8)) {
        finalizeSlots();
        cleanupUnfinalizedClasses();
      }
      if (currentStartupTimePhaseP(9)) {
        inModule(((StringWrapper*)(copyConsTree(wrapString("/RDBMS")))));
        { int phase = NULL_INTEGER;
          int iter000 = 0;
          int upperBound001 = 9;

          for  (phase, iter000, upperBound001; 
                iter000 <= upperBound001; 
                iter000 = iter000 + 1) {
            phase = iter000;
            oSTARTUP_TIME_PHASEo = phase;
            startupOntology();
            startupRdbms();
            startupFetchInterface();
          }
        }
        oSTARTUP_TIME_PHASEo = 999;
      }
    }
  }
}

Symbol* SYM_STARTUP_SYSTEM_RDBMS_STARTUP_RDBMS_SYSTEM = NULL;

Symbol* SYM_STARTUP_SYSTEM_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace rdbms
