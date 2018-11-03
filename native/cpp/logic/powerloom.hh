//  -*- Mode: C++ -*-

// powerloom.hh

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
 | Portions created by the Initial Developer are Copyright (C) 1997-2006      |
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



namespace logic {
  using namespace stella;

// Global declarations:
extern int oPOWERLOOM_MAJOR_VERSION_NUMBERo;
extern int oPOWERLOOM_MINOR_VERSION_NUMBERo;
extern char* oPOWERLOOM_RELEASE_STATEo;
extern int oPOWERLOOM_PATCH_LEVELo;
extern char* oPOWERLOOM_VERSION_STRINGo;
extern Keyword* oPOWERLOOM_EXECUTION_MODEo;
extern char* oPOWERLOOM_LOCKo;

// Function signatures:
void plLog(Keyword* loglevel, int message, ...);
char* powerloomInformation();
StringWrapper* powerloomInformationEvaluatorWrapper(Cons* arguments);
char* powerloomCopyrightHeader();
void copyright();
char* copyrightYears();
void powerloom();
void startupPowerloom();

// Auxiliary global declarations:
extern Keyword* KWD_POWERLOOM_RELEASE;
extern Keyword* KWD_POWERLOOM_LOG_LEVELS;
extern Keyword* KWD_POWERLOOM_LEVEL;
extern Keyword* KWD_POWERLOOM_DEVELOPMENT;
extern Keyword* KWD_POWERLOOM_MEDIUM;
extern Keyword* KWD_POWERLOOM_LOW;
extern Keyword* KWD_POWERLOOM_PREFIX;
extern Keyword* KWD_POWERLOOM_MAX_WIDTH;
extern Symbol* SYM_POWERLOOM_LOGIC_STARTUP_POWERLOOM;
extern Symbol* SYM_POWERLOOM_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
