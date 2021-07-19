//==============================================
//Name: Jexequiel Ravni Arador
//Student number : 127168219
//Email : jrarador@myseneca.ca
//Section : NBB
//Date : July 19, 2021
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
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void) {
    printf("(Press Enter to Continue)");
    clearKeyboard();
};


// getInt: Empty function definition goes here:
int getInt(void) {
    char NL;
    int intValue;
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


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max) {
    int isValidated = 0;
    do {
        int intValue = getInt();

        if (intValue >= min && intValue <= max) {
            return intValue;
        }
        else {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        }
    } while (!isValidated);
    return 0;
};


// yes: Empty function definition goes here:
int yes(void) {
    char charInput; char charInput2;

    do {
        scanf("%c%c", &charInput, &charInput2);

        if (charInput2 != '\n' || (charInput != 'y' && charInput != 'Y' && charInput != 'n' && charInput != 'N')) {
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }

    } while (charInput2 != '\n' || (charInput != 'y' && charInput != 'Y' && charInput != 'n' && charInput != 'N'));

    if (charInput == 'y' || charInput == 'Y') {
        return 1;
    }
    
    return 0;
};

// menu: Empty function definition goes here:
int menu(void) {
    puts("Contact Management System");
    puts("-------------------------");
    puts("1. Display contacts");
    puts("2. Add a contact");
    puts("3. Update a contact");
    puts("4. Delete a contact");
    puts("5. Search contacts by cell phone number");
    puts("6. Sort contacts by cell phone number");
    puts("0. Exit");
    puts("");
    printf("Select an option:> ");
    return getIntInRange(0, 6);
};


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void) {

    int flag = 0; 

    do
    {
        switch (menu())
        {
        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            flag = yes();
            puts("");
            break;

        case 1:
            puts("\n<<< Feature 1 is unavailable >>>\n");
            pause();
            puts("");
            break;

        case 2:
            puts("\n<<< Feature 2 is unavailable >>>\n");
            pause();
            puts("");
            break;

        case 3:
            puts("\n<<< Feature 3 is unavailable >>>\n");
            pause();
            puts("");
            break;

        case 4:
            puts("\n<<< Feature 4 is unavailable >>>\n");
            pause();
            puts("");
            break;

        case 5:
            puts("\n<<< Feature 5 is unavailable >>>\n");
            pause();
            puts("");
            break;

        case 6:
            puts("\n<<< Feature 6 is unavailable >>>\n");
            pause();
            puts("");
            break;

        default:
            break;
        }
    } while (!flag);

    puts("Contact Management System: terminated");
};


//extra definitions
int getIntPositive(char * err) {
    int num = getInt();

    while (num < 0) {
        printf(err);
        num = getInt();
    }

    return num;
}