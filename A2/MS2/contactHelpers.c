//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"
// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void) {
    printf(">(Press Enter to continue)<");
    clearKeyboard();
};


// getInt: Empty function definition goes here:
int getInt(void) {
    char NL;
    int intValue;
    do {
        int validateInput = scanf("%d%c", &intValue, &NL);

        if (validateInput == 2) {
            if (NL == '\n') {
                return intValue;
            }
            else {
                printf("*** INVALID INTEGER *** <Please enter an integer>:");
                clearKeyboard();
            }
        }
        else {
            printf("*** INVALID INTEGER *** <Please enter an integer>:");
            clearKeyboard();
        }
    }     while (NL != '\n');
};


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max) {

};


// yes: Empty function definition goes here:
int yes(void) {

};


// menu: Empty function definition goes here:
int menu(void) {

};


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void) {

};
