//  -*- Mode: C++ -*-

// date-time.hh

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


namespace stella {

// Class definitions:
class DecodedDateTime : public StandardObject {
// A data structure for holding decoded time values with fields
// for easy access of the components.
public:
  double dateTimeMillis;
  int dateTimeSecond;
  int dateTimeMinute;
  int dateTimeHour;
  int dateTimeDay;
  int dateTimeMonth;
  int dateTimeYear;
  double dateTimeZone;
  Keyword* dateTimeDow;
public:
  virtual CalendarDate* encodeCalendarDate();
  virtual int hashCode();
  virtual Surrogate* primaryType();
};

class DecodedTimeDuration : public StandardObject {
// A data structure for holding decoded time duration values with
// fields for easy access of the components.  Note that all non-zero values
// should have the same sign.
public:
  double durationMillis;
  int durationSeconds;
  int durationMinutes;
  int durationHours;
  int durationDays;
public:
  virtual TimeDuration* encodeTimeDuration();
  virtual int hashCode();
  virtual Surrogate* primaryType();
};

class DateTimeObject : public StandardObject {
};

class CalendarDate : public DateTimeObject {
// Representation of Date and Time with the date represented
// as a modified Julian day (starting at midnight instead of noon) and the
// time as the offset in milliseconds from midnight, UTC
public:
  int modifiedJulianDay;
  int timeMillis;
public:
  virtual void printObject(std::ostream* stream);
  virtual boolean objectEqlP(Object* x);
  virtual DecodedDateTime* decodeCalendarDate(double timezone);
  virtual int getTime(double timezone, int& _Return1, int& _Return2, int& _Return3);
  virtual int getCalendarDate(double timezone, int& _Return1, int& _Return2, Keyword*& _Return3);
  virtual int hashCode();
  virtual Surrogate* primaryType();
};

class TimeDuration : public DateTimeObject {
// Representation of Relative Days and Time with the date represented
// as a number of days and the time in milliseconds.
public:
  int days;
  int millis;
public:
  virtual void printObject(std::ostream* stream);
  virtual boolean objectEqlP(Object* x);
  virtual DecodedTimeDuration* decodeTimeDuration();
  virtual int hashCode();
  virtual Surrogate* primaryType();
};


// Global declarations:
extern int MILLIS_PER_DAY;
extern int MILLIS_PER_HOUR;
extern Vector* oMONTH_ABBREVIATION_VECTORo;

// Function signatures:
int computeJulianDay(int yyyy, int mm, int dd);
int julianDayToModifiedJulianDay(int julianDay);
int modifiedJulianDayToJulianDay(int modifiedJulianDay);
Keyword* computeDayOfWeekJulian(int julianDay);
Keyword* computeDayOfWeek(int yyyy, int mm, int dd);
int computeNextMoonPhase(int n, Keyword* phase, double& _Return1);
int computeCalendarDate(int julianDay, int& _Return1, int& _Return2, Keyword*& _Return3);
int getCurrentDateTime(int& _Return1, int& _Return2, Keyword*& _Return3, int& _Return4, int& _Return5, int& _Return6, int& _Return7);
double getLocalTimeZone();
double getLocalStandardTimeZone();
double getLocalTimeZoneForDate(int year, int month, int day, int hour, int minute, int second);
DecodedDateTime* newDecodedDateTime();
Object* accessDecodedDateTimeSlotValue(DecodedDateTime* self, Symbol* slotname, Object* value, boolean setvalueP);
void setCurrentTime(DecodedDateTime* valuesStructure);
void setCurrentDate(DecodedDateTime* valuesStructure);
void setCurrentDateTime(DecodedDateTime* valuesStructure);
DecodedTimeDuration* newDecodedTimeDuration();
Object* accessDecodedTimeDurationSlotValue(DecodedTimeDuration* self, Symbol* slotname, Object* value, boolean setvalueP);
CalendarDate* newCalendarDate();
Object* accessCalendarDateSlotValue(CalendarDate* self, Symbol* slotname, Object* value, boolean setvalueP);
char* calendarDateToString(CalendarDate* date, double timezone, boolean includeTimezoneP);
time_t calendarDateToNativeDateTime(CalendarDate* date);
CalendarDate* nativeDateTimeToCalendarDate(time_t date);
void printCalendarDate(CalendarDate* date, std::ostream* stream);
TimeDuration* newTimeDuration();
Object* accessTimeDurationSlotValue(TimeDuration* self, Symbol* slotname, Object* value, boolean setvalueP);
char* timeDurationToString(TimeDuration* date);
TimeDuration* stringToTimeDuration(char* duration);
void printTimeDuration(TimeDuration* date, std::ostream* stream);
CalendarDate* makeDateTime(int year, int month, int day, int hour, int minute, int second, int millis, double timezone);
CalendarDate* makeCurrentDateTime();
CalendarDate* makeCalendarDate(int day, int time);
TimeDuration* makeTimeDuration(int days, int millis);
int decodeTimeInMillis(int time, int& _Return1, int& _Return2, int& _Return3);
DateTimeObject* timeAdd(DateTimeObject* t1, DateTimeObject* t2);
DateTimeObject* timeSubtract(DateTimeObject* t1, DateTimeObject* t2);
TimeDuration* timeMultiply(Object* t1, Object* t2);
Object* timeDivide(TimeDuration* t1, Object* t2);
Object* defineTimeComparison(Symbol* name, Symbol* operatoR);
boolean timeEqlP(DateTimeObject* t1, DateTimeObject* t2);
boolean timeLessP(DateTimeObject* t1, DateTimeObject* t2);
boolean timeGreaterP(DateTimeObject* t1, DateTimeObject* t2);
boolean timeLessEqualP(DateTimeObject* t1, DateTimeObject* t2);
boolean timeGreaterEqualP(DateTimeObject* t1, DateTimeObject* t2);
void fillInDateSubstitution(KeyValueList* substitutionList);
void helpStartupDateTime1();
void helpStartupDateTime2();
void startupDateTime();

// Auxiliary global declarations:
extern Keyword* KWD_DATE_TIME_MONDAY;
extern Keyword* KWD_DATE_TIME_TUESDAY;
extern Keyword* KWD_DATE_TIME_WEDNESDAY;
extern Keyword* KWD_DATE_TIME_THURSDAY;
extern Keyword* KWD_DATE_TIME_FRIDAY;
extern Keyword* KWD_DATE_TIME_SATURDAY;
extern Keyword* KWD_DATE_TIME_SUNDAY;
extern Keyword* KWD_DATE_TIME_NEW_MOON;
extern Keyword* KWD_DATE_TIME_FIRST_QUARTER;
extern Keyword* KWD_DATE_TIME_FULL_MOON;
extern Keyword* KWD_DATE_TIME_LAST_QUARTER;
extern Surrogate* SGT_DATE_TIME_STELLA_DECODED_DATE_TIME;
extern Symbol* SYM_DATE_TIME_STELLA_DATE_TIME_MILLIS;
extern Symbol* SYM_DATE_TIME_STELLA_DATE_TIME_SECOND;
extern Symbol* SYM_DATE_TIME_STELLA_DATE_TIME_MINUTE;
extern Symbol* SYM_DATE_TIME_STELLA_DATE_TIME_HOUR;
extern Symbol* SYM_DATE_TIME_STELLA_DATE_TIME_DAY;
extern Symbol* SYM_DATE_TIME_STELLA_DATE_TIME_MONTH;
extern Symbol* SYM_DATE_TIME_STELLA_DATE_TIME_YEAR;
extern Symbol* SYM_DATE_TIME_STELLA_DATE_TIME_ZONE;
extern Symbol* SYM_DATE_TIME_STELLA_DATE_TIME_DOW;
extern Surrogate* SGT_DATE_TIME_STELLA_DECODED_TIME_DURATION;
extern Symbol* SYM_DATE_TIME_STELLA_DURATION_MILLIS;
extern Symbol* SYM_DATE_TIME_STELLA_DURATION_SECONDS;
extern Symbol* SYM_DATE_TIME_STELLA_DURATION_MINUTES;
extern Symbol* SYM_DATE_TIME_STELLA_DURATION_HOURS;
extern Symbol* SYM_DATE_TIME_STELLA_DURATION_DAYS;
extern Surrogate* SGT_DATE_TIME_STELLA_CALENDAR_DATE;
extern Symbol* SYM_DATE_TIME_STELLA_MODIFIED_JULIAN_DAY;
extern Symbol* SYM_DATE_TIME_STELLA_TIME_MILLIS;
extern Keyword* KWD_DATE_TIME_RIGHT;
extern Surrogate* SGT_DATE_TIME_STELLA_TIME_DURATION;
extern Symbol* SYM_DATE_TIME_STELLA_DAYS;
extern Symbol* SYM_DATE_TIME_STELLA_MILLIS;
extern Surrogate* SGT_DATE_TIME_STELLA_NUMBER_WRAPPER;
extern Symbol* SYM_DATE_TIME_STELLA_DEFUN;
extern Symbol* SYM_DATE_TIME_STELLA_BOOLEAN;
extern Symbol* SYM_DATE_TIME_STELLA_T1;
extern Symbol* SYM_DATE_TIME_STELLA_DATE_TIME_OBJECT;
extern Symbol* SYM_DATE_TIME_STELLA_T2;
extern Symbol* SYM_DATE_TIME_STELLA_TYPECASE;
extern Symbol* SYM_DATE_TIME_STELLA_CALENDAR_DATE;
extern Symbol* SYM_DATE_TIME_STELLA_IF;
extern Symbol* SYM_DATE_TIME_STELLA_e;
extern Symbol* SYM_DATE_TIME_STELLA_RETURN;
extern Symbol* SYM_DATE_TIME_STELLA_TIME_DURATION;
extern Symbol* SYM_DATE_TIME_STELLA_ERROR;
extern Symbol* SYM_DATE_TIME_STELLA_STARTUP_DATE_TIME;
extern Symbol* SYM_DATE_TIME_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace stella
