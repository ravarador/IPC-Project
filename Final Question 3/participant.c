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

	//return count;
};