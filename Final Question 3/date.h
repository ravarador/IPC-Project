#ifndef _DATE_H
#define _DATE_H

#include <stdio.h>
#include <string.h>

#include "participant.h"

int zeller(const struct Date* date);

void convertDayToDayOfWeek(int day, char* dayOfWeek);

void convertMonthValueToMMM(int month, char* monthInMMM);

#endif 