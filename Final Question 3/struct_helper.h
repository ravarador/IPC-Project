#ifndef _STRUCTHELPER_H
#define _STRUCTHELPER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "participant.h"

struct toSortStruct {
	char name[MAX_NAME_LEN];
	double valueToSort;
};

void sortStruct(struct toSortStruct toSortStruct[], int size);
#endif 