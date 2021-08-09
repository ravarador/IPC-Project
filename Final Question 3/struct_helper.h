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

#ifndef _STRUCTHELPER_H
#define _STRUCTHELPER_H

#include <stdio.h>

#include "participant.h"

struct toSortStruct {
	char name[MAX_NAME_LEN];
	double valueToSort;
};

void sortStruct(struct toSortStruct toSortStruct[], int size);
#endif 