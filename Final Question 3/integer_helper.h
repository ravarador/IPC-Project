#ifndef _INTEGER_H
#define _INTEGER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clearKeyboard(void);
int getInt(void);
int getIntInRange(int min, int max);
int getIntPositive(char* err);

#endif 