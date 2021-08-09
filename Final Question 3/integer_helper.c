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

#define _CRT_SECURE_NO_WARNINGS

#include "integer_helper.h"

// Clears buffer
void clearKeyboard(void)
{
    while (getchar() != '\n');
}

/*
    Asks for integer value, if not integer, 
    display validation message then ask again
*/
int getInt(void) {
    char NL = 'X';
    int intValue = 0;
    do {
        int validateInput = scanf("%d%c", &intValue, &NL);

        if (validateInput == 2) {
            if (NL != '\n') {
                clearKeyboard();
                printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            }
            else {
                return intValue;
            }
        }
        else {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    } while (NL != '\n');
    return 0;
};

/*
    Asks for integer value, if not integer,
    display validation message then ask again
    Also validates if within range, if not within range,
    display validation message then ask again
*/
int getIntInRange(int min, int max) {
    int isValidated = 0;
    do {
        int intValue = getInt();

        if (intValue >= min && intValue <= max) {
            return intValue;
        }
        else {
            printf("Enter a number between %d and %d: ", min, max);
        }
    } while (!isValidated);
    return 0;
};

/*
    Asks for integer value, validates if positive integer, if not,
    display CUSTOM validation message then ask again
*/
int getIntPositive(char* err) {
    int num = getInt();

    while (num < 0) {
        printf(err);
        num = getInt();
    }

    return num;
}