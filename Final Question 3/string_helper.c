#include "string_helper.h"

//findString
char findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int numActivityNames, char activity[]) {
	return activity[0];
};

void sortStruct(struct toSortStruct toSortStruct[], int size) {
	int i, j;
	struct toSortStruct toSortStructTemp;
	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (toSortStruct[j].valueToSort < toSortStruct[j + 1].valueToSort) {
				toSortStructTemp = toSortStruct[j];
				toSortStruct[j] = toSortStruct[j + 1];
				toSortStruct[j + 1] = toSortStructTemp;
			}
		}
	}
}