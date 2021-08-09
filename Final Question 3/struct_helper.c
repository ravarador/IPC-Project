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

#include "struct_helper.h"

void sortStruct(struct toSortStruct toSortStruct[], int size) {
	int i, j;
	struct toSortStruct toSortStructTemp;
	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (toSortStruct[j].valueToSort < toSortStruct[j + 1].valueToSort) {
				toSortStructTemp = toSortStruct[j];
				toSortStruct[j] = toSortStruct[j + 1];
				toSortStruct[j + 1] = toSortStructTemp;
			}
		}
	}
}