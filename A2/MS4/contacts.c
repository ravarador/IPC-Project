//==============================================
// Name:           Jexequiel Ravni Arador
// Student Number: 127168219
// Email:          jrarador@myseneca.ca
// Section:        NBB
// Date:           July 22, 2021
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <stdlib.h>

#include "contactHelpers.h"
#include "contacts.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* name)
{
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");

    if (yes())
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else {
        name->middleInitial[0] = '\0';
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address)
{
    printf("Please enter the contact's street number: ");
    address->streetNumber = getIntPositive("*** INVALID STREET NUMBER *** <must be a positive number>: ");

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");

    if (yes())
    {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getIntPositive("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    printf("Please enter the contact's cell phone number: ");
    scanf("%10[^\n]", numbers->cell);
    clearKeyboard();

    if (!isNumber(numbers->cell) || strlen(numbers->cell) != 10) {
        numbers->cell[0] = '\0';
        printf("Enter a 10-digit phone number: ");
        getTenDigitPhone(numbers->cell);
    }

    printf("Do you want to enter a home phone number? (y or n): ");

    if (yes())
    {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]", numbers->home);
        clearKeyboard();

        if (!isNumber(numbers->home) || strlen(numbers->home) != 10) {
            numbers->home[0] = '\0';
            printf("Enter a 10-digit phone number: ");
            getTenDigitPhone(numbers->home);
        }
    }
    else {
        numbers->home[0] = '\0';
    }

    printf("Do you want to enter a business phone number? (y or n): ");

    if (yes())
    {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]", numbers->business);
        clearKeyboard();

        if (!isNumber(numbers->business) || strlen(numbers->business) != 10) {
            numbers->business[0] = '\0';
            printf("Enter a 10-digit phone number: ");
            getTenDigitPhone(numbers->business);
        }
    }
    else {
        numbers->business[0] = '\0';
    }
}

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact) {
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
};
