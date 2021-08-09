#ifndef _STRINGHELPER_H
#define _STRINGHELPER_H

#include <stdio.h>
#include <string.h>

#include "participant.h"

char findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int max_activity, char activity[]);

#endif 