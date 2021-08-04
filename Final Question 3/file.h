#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readActivityFile(FILE* fp, struct Participant participants[], const char activNames[][MAX_ACTIVITY_NAME_LEN + 1]);

#endif 