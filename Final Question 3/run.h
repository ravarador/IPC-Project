#ifndef _RUN_H
#define _RUN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//lists total run distance
void displayTotalRunDistance(const struct Participant participants[], int numberOfParticipants);

double getTotalRunOfParticipant(const struct Participant participants[], char name[]);
//lists best record of run then sorts it

#endif 