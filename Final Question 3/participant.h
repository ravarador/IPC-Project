#ifndef _PARTICIPANT_H
#define _PARTICIPANT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date {
	int year;
	int month;
	int day;
}

struct participants {
	char name[30];
	char activity[30];
	struct date;
	double distance;
	
};

//lists all participants and events

#endif 