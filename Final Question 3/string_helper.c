#include "string_helper.h"

char findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int maxActivities, char activity[])
{
    int i;
    for (i = 0; i < maxActivities; i++)
    {
        if (strcmp(activNames[i], activity) == 0)
            return activity[0];
    }
    return "";
}