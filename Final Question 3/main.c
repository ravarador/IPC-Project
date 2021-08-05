#define _CRT_SECURE_NO_WARNINGS

#include "file.h"
#include "date.h"
#include "menu.h"

int main() {
	struct Participant participants[MAX_PARTICIPANTS] = { { 0 } };
	int count;
	FILE* fp = NULL;
	fp = fopen(FILE_NAME, "r");
	char activities[][MAX_ACTIVITY_NAME_LEN + 1] = { "run", "walk", "swim" };
	//char activities[MAX_ACTIVITY_NAME_LEN + 1];

	if (fp != NULL) {
		printf("Read %d participants \n\n", count = readActivityFile(fp, participants, activities));

		fclose(fp);
	}

	int flag = 0;

	do
	{
		switch (menu())
		{
		case 0:
			//exit the program
			flag = 1;
			break;

		case 1:
			//list all participants and events
			break;

		case 2:
			//list total run distances
			displayTotalDistance(participants, count, "RUN");
			break;

		case 3:
			//list total swim distances
			displayTotalDistance(participants, count, "SWIM");
			break;

		case 4:
			//list total bike distances
			displayTotalDistance(participants, count, "BIKE");
			break;

		case 5:
			//list best run distances
			break;

		case 6:
			//list best swim distances
			break;

		case 7:
			//list best bike distances
			break;

		default:
			break;
		}

	} while (!flag);
}