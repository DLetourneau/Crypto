/**
 * yates.c
 *
 * Fisher & Yates Shuffle
 * Used to create a randomnized of an array of chars
 *
 * Based on the wikipedia descrioption of the algorithm.
 * Takes a random element, swap it with the last repeat with
 * a range of N - i (N = number of element, i = current index)
 *
 * Dominic Letourneau 16 August 2016
 *
 * Coded using vim on a rasp pi 3 running Raspbian Jessie
 *
 * Modified 17 August:
 * Added the requirement to specify the output filename
 * And removed the testing spacer (commented)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./yates output");
		return 1;
	}
	char* outFile = argv[1];
	
	// Unrandomnize key
	char baseKey[70] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9',' ',',','.','?','(',')','[',']'};
	char temp;
	int keyCount = 0;
	int roll;
	
	// Seed the random generator
	struct timeval t1;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec * t1.tv_sec);
	
	while (keyCount < 4)
	{
	  
	  // Randomize the array using the algorithm
		for (int i=70;i>1;i--)
		{
			roll = rand()%i;
			temp = baseKey[roll];
			baseKey[roll] = baseKey[i-1];
			baseKey[i-1] = temp;
		}
		
		// Write the key to the outfile
		FILE* keys = fopen(outFile, "a");
		if (keys == NULL)
		{
			printf("Couldn't open %s\n", outFile);
			return 1;
		}
		for (int i=0;i<70;i++)
			fwrite(&baseKey[i], sizeof(char), 1, keys);
		fwrite("\n",sizeof(char),1, keys);
		fclose(keys);
		keyCount++;
	}
}
