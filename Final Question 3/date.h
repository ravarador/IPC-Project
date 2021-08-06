#ifndef _DATE_H
#define _DATE_H
#define SAT 0
#define SUN 1
#define MON 2
#define TUE 3
#define WED 4
#define THU 5
#define FRI 6

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "participant.h"

int zeller(const struct Date* date);

void convertDayToDayOfWeek(int day, char* dayOfWeek);

#endif 