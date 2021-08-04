#ifndef _STRINGHELPER_H
#define _STRINGHELPER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "participant.h"

//findString
const char* findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int numActivityNames, char activity[]);

#endif 