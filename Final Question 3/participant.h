/*
    IPC144-NBB Take Home Test - Final Question 3
    Member 1:
    Jexequiel Ravni Arador
    127168219
    jrarador@myseneca.ca

    Member 2:
    Patel Aditya Dharmesh
    143595205
    adpatel31@myseneca.ca

    Member 3:
    Rishita Rajendrakumar Patel
    141921205
    rrpatel42@myseneca.ca
*/

#ifndef _PARTICIPANT_H
#define _PARTICIPANT_H

#define MAX_ACTIVITY_NAME_LEN 4
#define NUM_ACTIVITY_NAMES 14
#define MAX_NAME_LEN 20
#define MAX_PARTICIPANTS 9

#include <stdio.h>
#include <ctype.h>

#include "struct_helper.h"
#include "date.h"

struct Date {
	int year;
	int month;
	int day;
};

struct Activity {
	struct Date date;
	char activityType;
	double distance;
};

struct Participant {
	char name[MAX_NAME_LEN];
	struct Activity activities[NUM_ACTIVITY_NAMES];
	int numActivities;
};

void displayAllParticipantsWithEvents(const struct Participant participants[], const int numberOfParticipants);

int findParticipant(const struct Participant participants[], const int count, const char name[MAX_ACTIVITY_NAME_LEN]);

double getTotalOfParticipant(const struct Participant participants[], const char name[], const char activityType);

void displayTotalDistance(const struct Participant participants[], const int numberOfParticipants, const char activityType[]);

double getBestOfParticipant(const struct Participant participants[], const char name[], const char activityType);

void displayBestDistance(const struct Participant participants[], const int numberOfParticipants, const char activityType[]);

#endif 