#ifndef PERSOLIB_H
#define PERSOLIB_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>

#define KEY_LEN 70
#define KEY_NUM 4
#define KEY_SET_LEN (KEY_LEN+1)*KEY_NUM

int getKey(int count)
{
	int key;
	switch(count)
	{
		case 0: key=0; break;
		case 1: key=3; break;
		case 2: key=2; break;
		case 3: key=1; break;
	}
	return key;
}
#endif // PERSOLIB_H
