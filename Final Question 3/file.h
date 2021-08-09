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

#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>

#include "participant.h"
#include "date.h"

#define FILE_NAME "data.txt"

int readActivityFile(FILE* fp, struct Participant participants[], const char activNames[][MAX_ACTIVITY_NAME_LEN + 1]);

#endif 