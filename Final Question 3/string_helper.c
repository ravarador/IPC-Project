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