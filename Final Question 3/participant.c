#define _CRT_SECURE_NO_WARNINGS

#include "participant.h"
#include "string_helper.h"

//lists all participants and events

//find participant
int findParticipant(const struct Participant participants[], const int count, const char name[MAX_ACTIVITY_NAME_LEN]) {
	int i;
	for (i = 0; i < count; i++) {
		int isFound = strcmp(participants[i].name, name);

		if (isFound == 0) {
			return i;
		}

		if (participants[i].name[0] == '\0') {
			return i;
		}
	}

	return -1;
};

double getTotalOfParticipant(const struct Participant participants[], const char name[], const char activityType) {
	int i, t; double sum = 0;
	for (i = 0; i < NUM_ACTIVITY_NAMES; i++) {
		if (strcmp(participants[i].name, name) == 0) {
			for (t = 0; t < NUM_ACTIVITY_NAMES; t++) {
				if (participants[i].activities[t].activityType == activityType) {
					sum += participants[i].activities[t].distance;
				}
			}
		}
	}
	return sum;
}

void displayTotalDistance(const struct Participant participants[], const int numberOfParticipants, const char activityType[]) {
	struct toSortStruct sortedStruct[MAX_PARTICIPANTS];

	printf("        *** TOTAL %s ***\n", activityType);

	int i;
	for (i = 0; i < numberOfParticipants; i++) {
		strcpy(sortedStruct[i].name, participants[i].name);
		sortedStruct[i].valueToSort = getTotalOfParticipant(participants, participants[i].name, tolower(activityType[0]));
	}

	sortStruct(&sortedStruct, numberOfParticipants);

	for (i = 0; i < numberOfParticipants; i++) {
		printf("%20s", sortedStruct[i].name);
		printf("%7.1lf\n", sortedStruct[i].valueToSort);
	}

	puts("");
}

double getBestOfParticipant(const struct Participant participants[], const char name[], const char activityType) {
	int i, t; double top = 0, low = 0;
	for (i = 0; i < NUM_ACTIVITY_NAMES; i++) {
		if (strcmp(participants[i].name, name) == 0) {
			for (t = 0; t < NUM_ACTIVITY_NAMES; t++) {
				if (participants[i].activities[t].activityType == activityType) {
					if (participants[i].activities[t].distance > top) {
						top = participants[i].activities[t].distance;
					}
				}
			}
		}
	}
	return top;
}

void displayBestDistance(const struct Participant participants[], const int numberOfParticipants, const char activityType[]) {
	struct toSortStruct sortedStruct[MAX_PARTICIPANTS];

	printf("        *** TOP %s ***\n", activityType);

	int i;
	for (i = 0; i < numberOfParticipants; i++) {
		strcpy(sortedStruct[i].name, participants[i].name);
		sortedStruct[i].valueToSort = getBestOfParticipant(participants, participants[i].name, tolower(activityType[0]));
	}

	sortStruct(&sortedStruct, numberOfParticipants);

	for (i = 0; i < numberOfParticipants; i++) {
		printf("%20s", sortedStruct[i].name);
		printf("%7.1lf\n", sortedStruct[i].valueToSort);
	}

	puts("");
}