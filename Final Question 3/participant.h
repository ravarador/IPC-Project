#ifndef _PARTICIPANT_H
#define _PARTICIPANT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACTIVITY_NAME_LEN 20
#define NUM_ACTIVITY_NAMES 20
#define MAX_NAME_LEN 20

struct Date {
	int year;
	int month;
	int day;
};

struct Activity {
	struct Date date;
	char activityType[MAX_ACTIVITY_NAME_LEN];
	double distance;
};

struct Participant {
	char name[MAX_NAME_LEN];
	struct Activity activities[NUM_ACTIVITY_NAMES];
	int numActivities;
};

//lists all participants and events

//find participant
int findParticipant(const struct Participant *participant, int numOfActivityNames, char activity[MAX_ACTIVITY_NAME_LEN]);

#endif 