#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>

#include "participant.h"
#include "date.h"

#define FILE_NAME "data.txt"

int readActivityFile(FILE* fp, struct Participant participants[], const char activNames[][MAX_ACTIVITY_NAME_LEN + 1]);

#endif 