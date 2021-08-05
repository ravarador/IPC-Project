#include "string_helper.h"

//findString
char* findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int numActivityNames, char activity[]) {
	int i;
	for (i = 0; i < numActivityNames; i++) {
		int isMatch = strcmp(&activity[i], &activity[i]);

		if (isMatch == 0) {
			return activity;
		}
	}

	return "";
};