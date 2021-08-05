#define _CRT_SECURE_NO_WARNINGS

#include "file.h"
#include "date.h"
#include "bike.h"
#include "run.h"
#include "swim.h"
#include "menu.h"

int main() {
	struct Participant participants[MAX_PARTICIPANTS] = { { 0 } };

	FILE* fp = NULL;
	fp = fopen(FILE_NAME, "r");
	//char activities[][MAX_ACTIVITY_NAME_LEN + 1] = { "run", "walk", "swim" };
	char activities[MAX_ACTIVITY_NAME_LEN + 1];

	if (fp != NULL) {
		readActivityFile(fp, participants, &activities);

		fclose(fp);
	}

    int flag = 0;

    do
    {
        switch (menu())
        {
        case 0:
            flag = 1;
            break;

        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        default:
            break;
        }

    } while (!flag);
}