#include "integer_helper.h"
#include "menu.h"

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