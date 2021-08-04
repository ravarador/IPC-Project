#define _CRT_SECURE_NO_WARNINGS

#include "file.h"
#include "date.h"
#include "bike.h"
#include "run.h"
#include "swim.h"

int main() {
	struct Participant participants[10] = { { 0 } };
	FILE* fp = NULL;
	fp = fopen(FILE_NAME, "r+");
	char activities[MAX_ACTIVITY_NAME_LEN + 1];

	if (fp != NULL) {
		readActivityFile(fp, participants, &activities);
	}

}