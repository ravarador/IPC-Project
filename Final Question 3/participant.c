#include "participant.h"

//lists all participants and events

//find participant
int findParticipant(const struct Participant participants[], int count, char name[MAX_ACTIVITY_NAME_LEN]) {
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

double getTotalOfParticipant(const struct Participant participants[], char name[], char activityType) {
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

void displayTotalDistance(const struct Participant participants[], int numberOfParticipants, char activityType[]) {
	printf("        *** TOTAL %s ***\n", toupper(activityType));

	int i;
	for (i = 0; i < numberOfParticipants; i++) {
		printf("%20s", participants[i].name);
		printf("%7.1lf\n", getTotalOfParticipant(participants, participants[i].name, activityType[0]));
	}
	puts("");
}