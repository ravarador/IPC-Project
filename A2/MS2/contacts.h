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

//--------------------------------
// Structure Types
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        contents below...                        |
// +-------------------------------------------------+

// Structure type Name declaration (Milestone 1)
struct Name {
    char firstName[31];
    char middleInitial[7]; //char middleInitial[5]; to char middleInitial[7];// <- NO! Must accommodate 6 character + null terminator byte = 7
    char lastName[36];
};

// Structure type Address declaration (Milestone 1)
// Place your code here...
struct Address {
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};

// Structure type Numbers declaration (Milestone 1)
// Place your code here...
struct Numbers
{
    char cell[11];
    char home[11];
    char business[11];
};

// Structure type Contact declaration (Milestone 3)
// Place your code here...
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//--------------------------------
// Function Prototypes
//--------------------------------

// Get and store from standard input the values for Name
void getName(struct Name* name);

// Get and store from standard input the values for Address
void getAddress(struct Address* address);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers* numbers);

void getContact(struct Contact* contact);