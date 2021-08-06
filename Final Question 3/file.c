#define _CRT_SECURE_NO_WARNINGS

#include "file.h"
#include "date.h"

int readActivityFile(FILE* fp, struct Participant participants[], const char activNames[][MAX_ACTIVITY_NAME_LEN + 1])
{
	  int count = 0, ch, addPosn, actPosn;
	  char activity[16];
	  char name[MAX_NAME_LEN + 1];
	  int year=0, month=0, day=0;
	  double dist=0.0;

	  while (!feof(fp))
	  {
			fscanf(fp, "%[^~]s%*c", name);
			ch = fgetc(fp);
			fscanf(fp, "%[^~]s%*c", activity);
			ch = fgetc(fp);
			fscanf(fp, "%d", &year);
			ch = fgetc(fp);
			fscanf(fp, "%d", &month);
			ch = fgetc(fp);
			fscanf(fp, "%d", &day);
			ch = fgetc(fp);
			fscanf(fp, "%lf", &dist);
			ch = fgetc(fp);
			addPosn = findParticipant(participants, count, name);

			if (addPosn < 0)
			{
				  addPosn = count;
				  count++;
				  participants[addPosn].numActivities = 0;
				  strcpy(participants[addPosn].name, name);
			}

			actPosn = participants[addPosn].numActivities;
			participants[addPosn].activities[actPosn].activityType = activity[0];
			participants[addPosn].activities[actPosn].date.year = year;
			participants[addPosn].activities[actPosn].date.month = month;
			participants[addPosn].activities[actPosn].date.day = day;
			participants[addPosn].activities[actPosn].distance = dist;
			participants[addPosn].numActivities++;
			ch = fgetc(fp);
			
			if (!feof(fp)) ungetc(ch, fp);
	  }
	  
	  return count;
}