#define _CRT_SECURE_NO_WARNINGS

#include "date.h"

int zeller(const struct Date* date)
{
      int month = date->month;
      int year = date->year;
	  
      if (date->month < 3)
      {
            year--;
            month += 12;
      }

      int yr = year % 100;
      int century = year / 100;
      int result = date->day;
      result += 13 * (month + 1) / 5;
      result += yr;
      result += yr / 4;
      result += century / 4;
      result -= 2 * century;
      result = result % 7;

      return result;
}

void convertDayToDayOfWeek(int day, char* dayOfWeek) {
    char days[9][4] = {
        "Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"
    };

    strcpy(dayOfWeek, days[day]);
}

void convertMonthValueToMMM(int month, char* monthInMMM) {
    char months[14][4] = {
        "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "July", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    strcpy(monthInMMM, months[month]);
}