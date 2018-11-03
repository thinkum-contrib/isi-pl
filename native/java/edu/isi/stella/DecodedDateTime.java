//  -*- Mode: Java -*-
//
// DecodedDateTime.java

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

package edu.isi.stella;

import edu.isi.stella.javalib.*;

/** A data structure for holding decoded time values with fields
 * for easy access of the components.
 * @author Stella Java Translator
 */
public class DecodedDateTime extends StandardObject {
    public double dateTimeMillis;
    public int dateTimeSecond;
    public int dateTimeMinute;
    public int dateTimeHour;
    public int dateTimeDay;
    public int dateTimeMonth;
    public int dateTimeYear;
    public double dateTimeZone;
    public Keyword dateTimeDow;

  public static DecodedDateTime newDecodedDateTime() {
    { DecodedDateTime self = null;

      self = new DecodedDateTime();
      self.dateTimeDow = Stella.KWD_SUNDAY;
      self.dateTimeZone = 0.0;
      self.dateTimeYear = 1900;
      self.dateTimeMonth = 1;
      self.dateTimeDay = 1;
      self.dateTimeHour = 0;
      self.dateTimeMinute = 0;
      self.dateTimeSecond = 0;
      self.dateTimeMillis = 0.0;
      return (self);
    }
  }

  public static void now(DecodedDateTime parsedValues) {
    { double timeZone = parsedValues.dateTimeZone;

      if (timeZone == Stella.NULL_FLOAT) {
        timeZone = Stella.getLocalTimeZone();
      }
      { int hour = Stella.NULL_INTEGER;
        int minute = Stella.NULL_INTEGER;
        int second = Stella.NULL_INTEGER;
        int millis = Stella.NULL_INTEGER;

        { Object [] caller_MV_returnarray = new Object[3];

          hour = CalendarDate.makeCurrentDateTime().getTime(timeZone, caller_MV_returnarray);
          minute = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
          second = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
          millis = ((int)(((IntegerWrapper)(caller_MV_returnarray[2])).wrapperValue));
        }
        parsedValues.dateTimeMillis = ((double)(millis));
        parsedValues.dateTimeSecond = second;
        parsedValues.dateTimeMinute = minute;
        parsedValues.dateTimeHour = hour;
      }
    }
  }

  public static void tomorrow(DecodedDateTime parsedValues) {
    DecodedDateTime.today(parsedValues);
    { int jd = Stella.computeJulianDay(parsedValues.dateTimeYear, parsedValues.dateTimeMonth, parsedValues.dateTimeDay);

      { int year = Stella.NULL_INTEGER;
        int month = Stella.NULL_INTEGER;
        int day = Stella.NULL_INTEGER;
        Keyword dow = null;

        { Object [] caller_MV_returnarray = new Object[3];

          year = Stella.computeCalendarDate(jd + 1, caller_MV_returnarray);
          month = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
          day = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
          dow = ((Keyword)(caller_MV_returnarray[2]));
        }
        parsedValues.dateTimeDay = day;
        parsedValues.dateTimeMonth = month;
        parsedValues.dateTimeYear = year;
        parsedValues.dateTimeDow = dow;
      }
    }
  }

  public static void today(DecodedDateTime parsedValues) {
    { double timeZone = parsedValues.dateTimeZone;

      if (timeZone == Stella.NULL_FLOAT) {
        timeZone = Stella.getLocalTimeZone();
      }
      { int year = Stella.NULL_INTEGER;
        int month = Stella.NULL_INTEGER;
        int day = Stella.NULL_INTEGER;
        Keyword dow = null;

        { Object [] caller_MV_returnarray = new Object[3];

          year = CalendarDate.makeCurrentDateTime().getCalendarDate(timeZone, caller_MV_returnarray);
          month = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
          day = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
          dow = ((Keyword)(caller_MV_returnarray[2]));
        }
        parsedValues.dateTimeDay = day;
        parsedValues.dateTimeMonth = month;
        parsedValues.dateTimeYear = year;
        parsedValues.dateTimeDow = dow;
      }
    }
  }

  public static void yesterday(DecodedDateTime parsedValues) {
    DecodedDateTime.today(parsedValues);
    { int jd = Stella.computeJulianDay(parsedValues.dateTimeYear, parsedValues.dateTimeMonth, parsedValues.dateTimeDay);

      { int year = Stella.NULL_INTEGER;
        int month = Stella.NULL_INTEGER;
        int day = Stella.NULL_INTEGER;
        Keyword dow = null;

        { Object [] caller_MV_returnarray = new Object[3];

          year = Stella.computeCalendarDate(jd - 1, caller_MV_returnarray);
          month = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
          day = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
          dow = ((Keyword)(caller_MV_returnarray[2]));
        }
        parsedValues.dateTimeDay = day;
        parsedValues.dateTimeMonth = month;
        parsedValues.dateTimeYear = year;
        parsedValues.dateTimeDow = dow;
      }
    }
  }

  /** Returns a calendar date object for <code>timeStructure</code>.
   * @return CalendarDate
   */
  public CalendarDate encodeCalendarDate() {
    { DecodedDateTime timeStructure = this;

      return (CalendarDate.makeDateTime(timeStructure.dateTimeYear, timeStructure.dateTimeMonth, timeStructure.dateTimeDay, timeStructure.dateTimeHour, timeStructure.dateTimeMinute, timeStructure.dateTimeSecond, Native.round(timeStructure.dateTimeMillis), timeStructure.dateTimeZone));
    }
  }

  public static void setCurrentDateTime(DecodedDateTime valuesStructure) {
    { int year = Stella.NULL_INTEGER;
      int mon = Stella.NULL_INTEGER;
      int day = Stella.NULL_INTEGER;
      Keyword dow = null;
      int hour = Stella.NULL_INTEGER;
      int min = Stella.NULL_INTEGER;
      int sec = Stella.NULL_INTEGER;
      int millis = Stella.NULL_INTEGER;

      { Object [] caller_MV_returnarray = new Object[7];

        year = Stella.getCurrentDateTime(caller_MV_returnarray);
        mon = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
        day = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
        dow = ((Keyword)(caller_MV_returnarray[2]));
        hour = ((int)(((IntegerWrapper)(caller_MV_returnarray[3])).wrapperValue));
        min = ((int)(((IntegerWrapper)(caller_MV_returnarray[4])).wrapperValue));
        sec = ((int)(((IntegerWrapper)(caller_MV_returnarray[5])).wrapperValue));
        millis = ((int)(((IntegerWrapper)(caller_MV_returnarray[6])).wrapperValue));
      }
      valuesStructure.dateTimeMillis = ((double)(millis));
      valuesStructure.dateTimeSecond = sec;
      valuesStructure.dateTimeMinute = min;
      valuesStructure.dateTimeHour = hour;
      valuesStructure.dateTimeDow = dow;
      valuesStructure.dateTimeDay = day;
      valuesStructure.dateTimeMonth = mon;
      valuesStructure.dateTimeYear = year;
    }
  }

  public static void setCurrentDate(DecodedDateTime valuesStructure) {
    { int year = Stella.NULL_INTEGER;
      int mon = Stella.NULL_INTEGER;
      int day = Stella.NULL_INTEGER;
      Keyword dow = null;
      int hour = Stella.NULL_INTEGER;
      int min = Stella.NULL_INTEGER;
      int sec = Stella.NULL_INTEGER;
      int millis = Stella.NULL_INTEGER;

      { Object [] caller_MV_returnarray = new Object[7];

        year = Stella.getCurrentDateTime(caller_MV_returnarray);
        mon = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
        day = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
        dow = ((Keyword)(caller_MV_returnarray[2]));
        hour = ((int)(((IntegerWrapper)(caller_MV_returnarray[3])).wrapperValue));
        min = ((int)(((IntegerWrapper)(caller_MV_returnarray[4])).wrapperValue));
        sec = ((int)(((IntegerWrapper)(caller_MV_returnarray[5])).wrapperValue));
        millis = ((int)(((IntegerWrapper)(caller_MV_returnarray[6])).wrapperValue));
      }
      {
        hour = hour;
        min = min;
        sec = sec;
        millis = millis;
      }
      valuesStructure.dateTimeDow = dow;
      valuesStructure.dateTimeDay = day;
      valuesStructure.dateTimeMonth = mon;
      valuesStructure.dateTimeYear = year;
    }
  }

  public static void setCurrentTime(DecodedDateTime valuesStructure) {
    { int year = Stella.NULL_INTEGER;
      int mon = Stella.NULL_INTEGER;
      int day = Stella.NULL_INTEGER;
      Keyword dow = null;
      int hour = Stella.NULL_INTEGER;
      int min = Stella.NULL_INTEGER;
      int sec = Stella.NULL_INTEGER;
      int millis = Stella.NULL_INTEGER;

      { Object [] caller_MV_returnarray = new Object[7];

        year = Stella.getCurrentDateTime(caller_MV_returnarray);
        mon = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
        day = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
        dow = ((Keyword)(caller_MV_returnarray[2]));
        hour = ((int)(((IntegerWrapper)(caller_MV_returnarray[3])).wrapperValue));
        min = ((int)(((IntegerWrapper)(caller_MV_returnarray[4])).wrapperValue));
        sec = ((int)(((IntegerWrapper)(caller_MV_returnarray[5])).wrapperValue));
        millis = ((int)(((IntegerWrapper)(caller_MV_returnarray[6])).wrapperValue));
      }
      {
        year = year;
        mon = mon;
        day = day;
        dow = dow;
      }
      valuesStructure.dateTimeMillis = ((double)(millis));
      valuesStructure.dateTimeSecond = sec;
      valuesStructure.dateTimeMinute = min;
      valuesStructure.dateTimeHour = hour;
    }
  }

  public int hashCode_() {
    { DecodedDateTime self = this;

      return (((((((((self.dateTimeYear) << 9)) | (((self.dateTimeMonth) << 5)))) | (self.dateTimeDay))) ^ (((((((self.dateTimeHour) << 12)) | (((self.dateTimeMinute) << 6)))) | (self.dateTimeSecond)))));
    }
  }

  public static Stella_Object accessDecodedDateTimeSlotValue(DecodedDateTime self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Stella.SYM_STELLA_DATE_TIME_MILLIS) {
      if (setvalueP) {
        self.dateTimeMillis = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.dateTimeMillis);
      }
    }
    else if (slotname == Stella.SYM_STELLA_DATE_TIME_SECOND) {
      if (setvalueP) {
        self.dateTimeSecond = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.dateTimeSecond);
      }
    }
    else if (slotname == Stella.SYM_STELLA_DATE_TIME_MINUTE) {
      if (setvalueP) {
        self.dateTimeMinute = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.dateTimeMinute);
      }
    }
    else if (slotname == Stella.SYM_STELLA_DATE_TIME_HOUR) {
      if (setvalueP) {
        self.dateTimeHour = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.dateTimeHour);
      }
    }
    else if (slotname == Stella.SYM_STELLA_DATE_TIME_DAY) {
      if (setvalueP) {
        self.dateTimeDay = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.dateTimeDay);
      }
    }
    else if (slotname == Stella.SYM_STELLA_DATE_TIME_MONTH) {
      if (setvalueP) {
        self.dateTimeMonth = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.dateTimeMonth);
      }
    }
    else if (slotname == Stella.SYM_STELLA_DATE_TIME_YEAR) {
      if (setvalueP) {
        self.dateTimeYear = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.dateTimeYear);
      }
    }
    else if (slotname == Stella.SYM_STELLA_DATE_TIME_ZONE) {
      if (setvalueP) {
        self.dateTimeZone = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.dateTimeZone);
      }
    }
    else if (slotname == Stella.SYM_STELLA_DATE_TIME_DOW) {
      if (setvalueP) {
        self.dateTimeDow = ((Keyword)(value));
      }
      else {
        value = self.dateTimeDow;
      }
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + slotname + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
    return (value);
  }

  public Surrogate primaryType() {
    { DecodedDateTime self = this;

      return (Stella.SGT_STELLA_DECODED_DATE_TIME);
    }
  }

}

