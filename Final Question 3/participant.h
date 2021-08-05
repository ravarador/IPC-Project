#ifndef _PARTICIPANT_H
#define _PARTICIPANT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ACTIVITY_NAME_LEN 4
#define NUM_ACTIVITY_NAMES 14
#define MAX_NAME_LEN 20
#define MAX_PARTICIPANTS 9
#define MAX_ACTIVITIES 3

struct Date {
	int year;
	int month;
	int day;
};

struct Activity {
	struct Date date;
	char activityType; //TODO CHANGE ALL ACTIVITYTYPE IMPLEMENTATION TO CHAR
	double distance;
};

struct Participant {
	char name[MAX_NAME_LEN];
	struct Activity activities[NUM_ACTIVITY_NAMES];
	int numActivities;
};

//lists all participants and events

//find participant
int findParticipant(const struct Participant participants[], int count, char name[MAX_ACTIVITY_NAME_LEN]);

double getTotalOfParticipant(const struct Participant participants[], char name[], char activityType);

void displayTotalDistance(const struct Participant participants[], int numberOfParticipants, char activityType[]);

#endif 