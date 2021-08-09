/*
    IPC144-NBB Take Home Test - Final Question 3
    Member 1: 
    Jexequiel Ravni Arador
    127168219
    jrarador@myseneca.ca

    Member 2:
    Patel Aditya Dharmesh
    143595205
    adpatel31@myseneca.ca

    Member 3:
    Rishita Rajendrakumar Patel
    141921205
    rrpatel42@myseneca.ca
*/

#define _CRT_SECURE_NO_WARNINGS

#include "date.h"

/*
    Get year, month, day values to compute for day of the week value
    0 - Saturday, 1 - Sunday, 2 - Monday, etc..
    Returns the computed day of the week value
*/
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

/*
    Receives day of the week (day) value and a char array pointer address
    Gets the textual equivalent by using the day value as index to map the days array
    Stores the textual equivalent to the passed address
*/
void convertDayToDayOfWeek(int day, char* dayOfWeek) {
    char days[9][4] = {
        "Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"
    };

    strcpy(dayOfWeek, days[day]); // stores days[day] value to dayOfWeek
}

/*
    Receives month value and a char array pointer address
    Gets the textual equivalent by using the month value as index to map the months array
    Stores the textual equivalent to the passed address
*/
void convertMonthValueToMMM(int month, char* monthInMMM) {
    char months[13][4] = {
        "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    strcpy(monthInMMM, months[month]); // stores months[month] to monthsInMMM
}