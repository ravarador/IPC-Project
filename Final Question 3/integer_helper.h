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

#ifndef _INTEGER_H
#define _INTEGER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clearKeyboard(void);
int getInt(void);
int getIntInRange(int min, int max);
int getIntPositive(char* err);

#endif 