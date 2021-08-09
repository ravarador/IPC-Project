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

#ifndef _STRINGHELPER_H
#define _STRINGHELPER_H

#include <stdio.h>
#include <string.h>

#include "participant.h"

char findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int max_activity, char activity[]);

#endif 