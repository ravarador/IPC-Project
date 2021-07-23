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
#include <stdlib.h>
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
    struct Contact contacts[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" }, { 11, "Trailer Park", 0, "A7A 2J2", "King City" }, { "4161112222", "4162223333", "4163334444" } },
                                             { { "Maggie", "R.", "Greene" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9051112222", "9052223333", "9053334444" } },
                                             { { "Morgan", "A.", "Jones" }, { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" }, { "7051112222", "7052223333", "7053334444" } },
                                             { { "Sasha", {'\0'}, "Williams" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9052223333", "9052223333", "9054445555" } } };


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
            displayContacts(contacts, MAXCONTACTS);
            pause();
            puts("");
            break;

        case 2:
            addContact(contacts, MAXCONTACTS);
            pause();
            puts("");
            break;

        case 3:
            updateContact(contacts, MAXCONTACTS);
            pause();
            puts("");
            break;

        case 4:
            deleteContact(contacts, MAXCONTACTS);
            pause();
            puts("");
            break;

        case 5:
            searchContacts(contacts, MAXCONTACTS);
            pause();
            puts("");
            break;

        case 6:
            sortContacts(contacts, MAXCONTACTS);
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
    printf("Enter a 10-digit phone number: ");

    while (needInput == 1) {
        scanf("%10s", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10) {
            
            needInput = 0;
        }
        else {
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

    if (strlen(contact->name.middleInitial) > 0) {
        printf("%s ", contact->name.middleInitial);
    }

    printf("%s\n", contact->name.lastName);

    printf("    C: %-10s    H: %-10s    B: %-10s\n", contact->numbers.cell, 
        contact->numbers.home, 
        contact->numbers.business);

    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

    contact->address.apartmentNumber > 0 ? printf("Apt# %d, ", contact->address.apartmentNumber) : //do nothing ;

    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size) {
    int arraySize = 0;

    displayContactHeader();
    
    int i;
    for (i = 0; i < size; i++) {
        if (atoi(contacts[i].numbers.cell) > 0) { //atoi is used to convert string to int
            displayContact(&contacts[i]);
            arraySize++;
        }
    }

    displayContactFooter(arraySize);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size) {
    char phoneNumber[11];
    int contactIndex = -1;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNumber);

    contactIndex = findContactIndex(contacts, size, phoneNumber);

    if (contactIndex > -1) {
        displayContact(&contacts[contactIndex]);
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size) {
    int indexEmpty = -1;
    indexEmpty = findContactIndex(contacts, size, "");

    if (indexEmpty != -1) {
        getContact(&contacts[indexEmpty]);
        printf("--- New contact added! ---\n");
    }
    else {
        printf("*** ERROR: The contact list is full! ***\n");
    }
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size) {
    int indexToUpdate = -1;
    char contactNumber[11];

    getTenDigitPhone(contactNumber);

    indexToUpdate = findContactIndex(contacts, size, contactNumber);

    if (indexToUpdate != -1) {
        printf("\nContact found:\n");

        displayContact(&contacts[indexToUpdate]);

        printf("Do you want to update the name? (y or n): ");

        if (yes()) {
            getName(&contacts[indexToUpdate].name);
        }

        printf("Do you want to update the address? (y or n): ");

        if (yes()) {
            getAddress(&contacts[indexToUpdate].address);
        }

        printf("Do you want to update the numbers? (y or n): ");

        if (yes()) {
            getNumbers(&contacts[indexToUpdate].numbers);
        }

        printf("--- Contact Updated! ---\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size) {
    int indexToDelete = -1;
    char contactNumber[11];

    getTenDigitPhone(contactNumber);

    indexToDelete = findContactIndex(contacts, size, contactNumber);

    if (indexToDelete != -1) {
        printf("\nContact found:\n");

        displayContact(&contacts[indexToDelete]);

        printf("CONFIRM: Delete this contact? (y or n): ");

        if (yes()) {
            contacts[indexToDelete].numbers.cell[0] = '\0';
        }

        printf("--- Contact Deleted! ---\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
}

//SORTING ALGORITHM

// selectSort sorts the elements of a[n] in ascending order
void selectSort(struct Contact contacts[], int n)
{
    int smallerNum = 0, i = 0, j = 0;
    struct Contact tempContact;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (atoi(contacts[j].numbers.cell) < atoi(contacts[i].numbers.cell)) {
                smallerNum = j;

            }

            if (smallerNum != i) {
                tempContact = contacts[i];
                contacts[i] = contacts[smallerNum];
                contacts[smallerNum] = tempContact;
            }
        }
    }
}
// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size) {
    selectSort(contacts, size);
    printf("--- Contacts sorted! ---\n");
}