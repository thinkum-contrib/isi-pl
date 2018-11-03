//  -*- Mode: C++ -*-

// timepoint-support.hh

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


namespace timepoint {
  using namespace stella_utilities;
  using namespace stella;
  using namespace logic;

// Class definitions:
class DateTimeLogicWrapper : public QuantityLogicWrapper {
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
  virtual boolean objectEqlP(Object* x);
  virtual int hashCode();
  virtual Object* generateSpecializedTerm();
};


// Global declarations:
extern StellaHashTable* oDATE_TIME_HASH_TABLEo;

// Function signatures:
DateTimeLogicWrapper* newDateTimeLogicWrapper(DateTimeObject* wrapperValue);
Object* accessDateTimeLogicWrapperSlotValue(DateTimeLogicWrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
DateTimeLogicWrapper* wrapDateTime(DateTimeObject* value);
DateTimeLogicWrapper* helpGetCalendarTime(Object* item);
DateTimeLogicWrapper* helpGetTimeDuration(Object* item);
DateTimeLogicWrapper* helpGetTimeObject(Object* item);
int helpGetInteger(Object* obj);
double helpGetFloat(Object* obj);
double helpGetTimezone(Object* obj);
boolean canBindAllP(Cons* plObjects, Cons* values);
void timepointOfEvaluator(Proposition* self);
Keyword* timepointOfSpecialist(ControlFrame* frame, Keyword* lastmove);
void timepointOfOEvaluator(Proposition* self);
Keyword* timepointOfOSpecialist(ControlFrame* frame, Keyword* lastmove);
void durationOfEvaluator(Proposition* self);
Keyword* durationOfSpecialist(ControlFrame* frame, Keyword* lastmove);
void timeMinusEvaluator(Proposition* self);
void timeAddEvaluator(Proposition* self);
Object* timeMinusConstraint(IntegerWrapper* missingArgument, DateTimeLogicWrapper* x1, DateTimeLogicWrapper* x2, DateTimeLogicWrapper* x3);
Object* timeAddConstraint(IntegerWrapper* missingArgument, DateTimeLogicWrapper* x1, DateTimeLogicWrapper* x2, DateTimeLogicWrapper* x3);
double helpGetTimeZone(Object* timeZoneSpecifier);
LogicObject* dowKeywordToInstance(Keyword* dow);
Object* helpExtractDateTimeComponent(DateTimeLogicWrapper* timepoint, double timeZone, GeneralizedSymbol* predicate);
Keyword* timepointAccessorSpecialist(ControlFrame* frame, Keyword* lastmove);
void helpStartupTimepointSupport1();
void startupTimepointSupport();

// Auxiliary global declarations:
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER;
extern Symbol* SYM_TIMEPOINT_SUPPORT_STELLA_WRAPPER_VALUE;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_STELLA_CALENDAR_DATE;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_OF;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_STELLA_TIME_DURATION;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_DURATION_OF;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_UNIT_SUPPORT_DIM_NUMBER_LOGIC_WRAPPER;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_STELLA_CS_VALUE;
extern Keyword* KWD_TIMEPOINT_SUPPORT_FINAL_SUCCESS;
extern Keyword* KWD_TIMEPOINT_SUPPORT_TERMINAL_FAILURE;
extern Keyword* KWD_TIMEPOINT_SUPPORT_FAILURE;
extern Keyword* KWD_TIMEPOINT_SUPPORT_MONDAY;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_MONDAY;
extern Keyword* KWD_TIMEPOINT_SUPPORT_TUESDAY;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TUESDAY;
extern Keyword* KWD_TIMEPOINT_SUPPORT_WEDNESDAY;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_WEDNESDAY;
extern Keyword* KWD_TIMEPOINT_SUPPORT_THURSDAY;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_THURSDAY;
extern Keyword* KWD_TIMEPOINT_SUPPORT_FRIDAY;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_FRIDAY;
extern Keyword* KWD_TIMEPOINT_SUPPORT_SATURDAY;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_SATURDAY;
extern Keyword* KWD_TIMEPOINT_SUPPORT_SUNDAY;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_SUNDAY;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_YEAR;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_MONTH;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DAY;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_HOUR;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_MINUTE;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_SECOND;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DATE;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_TIME;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_STELLA_NUMBER_WRAPPER;
extern Surrogate* SGT_TIMEPOINT_SUPPORT_STELLA_STRING_WRAPPER;
extern Symbol* SYM_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_STARTUP_TIMEPOINT_SUPPORT;
extern Symbol* SYM_TIMEPOINT_SUPPORT_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace timepoint
