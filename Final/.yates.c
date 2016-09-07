/**
 * yatesShuffle.c
 *
 * Attempt at creating a Fisher & Yates Shuffle
 * To create a randomnized of an array of chars
 *
 * Based on the wikipedia descrioption of the algorithm.
 *
 * Dominic Letourneau 16 August 2016
 *
 * Coded using vim on a rasp pi 3 running Raspbian Jessie
 *
 */

#include ".persolib.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./yates output");
		return 1;
	}
	char* outFile = argv[1];
	char temp;
	char  baseKey[KEY_LEN] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9',' ',',','.','?','(',')','[',']'};
	int keyCount = 0;
	int roll;
	struct timeval t1;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec * t1.tv_sec);
	while (keyCount < 4)
	{
		for (int i=KEY_LEN;i>1;i--)
		{
			roll = rand()%i;
			temp = baseKey[roll];
			baseKey[roll] = baseKey[i-1];
			baseKey[i-1] = temp;
		}
		
		FILE* keys = fopen(outFile, "a");
		if (keys == NULL)
		{
			printf("Couldn't open %s\n", outFile);
			return 1;
		}
		for (int i=0;i<KEY_LEN;i++)
			fwrite(&baseKey[i], sizeof(char), 1, keys);
		fwrite("\n",sizeof(char),1, keys);
		fclose(keys);
		keyCount++;
	}
}
