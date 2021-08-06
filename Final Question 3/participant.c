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
	printf("        *** TOTAL %s ***\n", activityType);

	int i;
	for (i = 0; i < numberOfParticipants; i++) {
		printf("%21s", participants[i].name);
		printf("%7.1lf\n", getTotalOfParticipant(participants, participants[i].name, tolower(activityType[0])));
	}
	puts("");
}

double getBestOfParticipant(const struct Participant participants[], char name[], char activityType) {
	int i, t; double top = 0;
	for (i = 0; i < NUM_ACTIVITY_NAMES; i++) {
		if (strcmp(participants[i].name, name) == 0) {
			for (t = 0; t < NUM_ACTIVITY_NAMES; t++) {
				if (participants[i].activities[t].activityType == activityType) {
					if (participants[i].activities[t].distance > participants[i].activities[t - 1].distance) {
						top = participants[i].activities[t].distance;
					}
				}
			}
		}
	}
	return top;
}

void displayBestDistance(const struct Participant participants[], int numberOfParticipants, char activityType[]) {
	printf("        *** TOP %s ***\n", activityType);

	int i;
	for (i = 0; i < numberOfParticipants; i++) {
		//store participant name to array1
		//store best value along with array1
		//then another loop to display the contents of array1
		printf("%21s", participants[i].name);
		printf("%7.1lf\n", getBestOfParticipant(participants, participants[i].name, tolower(activityType[0])));
	}
	puts("");
}