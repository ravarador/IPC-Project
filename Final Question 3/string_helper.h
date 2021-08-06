#ifndef _STRINGHELPER_H
#define _STRINGHELPER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "participant.h"

struct toSortStruct {
	char name[MAX_NAME_LEN];
	double valueToSort;
};

//findString
char findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int numActivityNames, char activity[]);

void sortStruct(struct toSortStruct toSortStruct[], int size);
#endif 