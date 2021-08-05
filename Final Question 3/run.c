#include "run.h"
#include "participant.h"

//lists total run distance
void displayTotalRunDistance(const struct Participant participants[], int numberOfParticipants) {
	puts("        *** TOTAL RUNS ***");

	int i;
	for (i = 0; i < numberOfParticipants; i++) {
		printf("%20s", participants[i].name);
		printf("%7.1lf\n\n", getTotalRunOfParticipant(participants, participants[i].name));
		
	}
}

double getTotalRunOfParticipant(const struct Participant participants[], char name[]) {
	int i, t; double sum = 0;
	for (i = 0; i < NUM_ACTIVITY_NAMES; i++) {
		if (strcmp(participants[i].name, name) == 0) {
			for (t = 0; t < NUM_ACTIVITY_NAMES; t++) {
				if (participants[i].activities[t].activityType == 'r') {
					sum += participants[i].activities[t].distance;
				}
			}
		}
	}
	return sum;
}


//lists best record of run then sorts it