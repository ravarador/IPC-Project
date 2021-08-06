#include "struct_helper.h"

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