//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include "contactHelpers.h"
#include "contacts.h"
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
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
int getIntPositive(char* err) {
    int num = getInt();

    while (num < 0) {
        printf(err);
        num = getInt();
    }

    return num;
}


// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;

    while (needInput == 1)
    {
        int numInput = getIntPositive("Enter a 10-digit phone number: ");
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
        {
            phoneNum = numInput;
            needInput = 0;
        }
        else
        {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
            return i;
        }
    }

    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact) {
    printf(" %s ", contact->name.firstName);
    printf(" %s ", contact->name.middleInitial);
    printf(" %s\n", contact->name.lastName);

    printf("    C: %-10s    H: %-10s    B: %-10s\n", contact->numbers.cell, 
        contact->numbers.home, 
        contact->numbers.business);

    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    printf("Apt# %d, ", contact->address.apartmentNumber > 0 ? contact->address.apartmentNumber : NULL);
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size) {
    displayContactHeader();
    
    int i;
    for (i = 0; i < size; i++) {
        displayContact(&contacts[i]);
    }

    displayContactFooter(size);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size) {

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size) {

}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size) {

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size) {

}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size) {

}