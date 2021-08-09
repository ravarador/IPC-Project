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

#include "integer_helper.h"
#include "menu.h"

/*
    Display menu with range of 0-7
    Asks user to choose from 0-7, if outside range,
    display validation message then ask again
*/
int menu() {
	int choice;

	puts("Select one of the following options:");
	puts("0 - Exit");
	puts("1 - list all participants and events");
	puts("2 - list total run distances");
	puts("3 - list total swim distances");
	puts("4 - list total bike distances");
	puts("5 - list best run distances");
	puts("6 - list best swim distances");
	puts("7 - list best bike distances");

	return getIntInRange(0, 7);
}