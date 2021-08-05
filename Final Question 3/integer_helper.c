#define _CRT_SECURE_NO_WARNINGS

#include "integer_helper.h"

void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

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


int getIntPositive(char* err) {
    int num = getInt();

    while (num < 0) {
        printf(err);
        num = getInt();
    }

    return num;
}