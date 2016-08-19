/**
 * encrypt.c
 *
 * Second stage of the encryption tool
 *
 * Receives 3 files as arguments: key, source, output
 * 
 * Key: will be stored in memory for encryption and written in the outputfile
 * Source: Text to be encrypted
 * Output: file where the key and encrypyted text will be written.
 *
 * Simple swap encryption, follow the code to figure out the method
 * 
 * Dom Letourneau 2016
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char* argv[])
{
  // Argument validation
	if (argc != 4)
	{
		printf("Usage; ./encrypt keys source output\n");
		return 1;
	}
	char* fileKey = argv[1];
	char* fileSource = argv[2];
	char* fileOutput = argv[3];
	FILE* inptr = fopen(fileKey, "r");
	if (inptr == NULL)
	{
		printf("Can't open %s\n", fileKey);
		return 1;
	}
	FILE* outptr = fopen(fileOutput, "w");
	if (outptr == NULL)
	{
		fclose(inptr);
		printf("Can't open %s\n", fileOutput);
		return 2;
	}
	
	char key[4][70];	
	char c;
	int charCount = 0;
	int keyCount = 0;
	
	// Loads the keys into memory
	while (fread(&c, sizeof(c), 1, inptr) > 0)
	{
		fwrite(&c, sizeof(c), 1, outptr);
		if (charCount == 70)
		{
			keyCount++;
			charCount = 0;
		}
		else
		{
			key[keyCount][charCount] = c;
			charCount ++;
		}	
	}
	fclose(inptr);
	FILE* source = fopen(fileSource, "r");
	if (source == NULL)
	{
		fclose(outptr);
		printf("Can't open %s\n", fileSource);
		return 3;
	}
	
	// Base encryption key - any change will render the tools useless
	char baseKey[70] = {'G','B','y','d','T','m','X','Z','8','i','K','H','r','v',')','5',',','L',']','M','N','0','j','b','o','h','k','.','p','7','3','E','S','W','f','l','J','4','P','V','z','D','?','u','x','n','e','g','Y','2','s','a','(','[',' ','A','q','c','F','R','w','O','C','Q','U','1','t','I','9','6'};
	
	int index, keyToUse;
	char crypt;
	charCount = 0;
	
	// Seed the random generator
	struct timeval t1;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec * t1.tv_sec);
	
	// Encryption
	while (fread(&c, sizeof(c), 1, source) > 0)
	{
		if (!iscntrl(c))
		{
			switch (charCount%4)
			{
				case 0:	keyToUse = 0; break;
				case 1: keyToUse = 3; break;
				case 2: keyToUse = 2; break;
				case 3: keyToUse = 1; break;
			}
			
			// Swap the valid chars
			for(int i=0;i<70;i++)
			{
				if(c == key[keyToUse][i])
				{
					crypt = baseKey[i];
					break;
				}
				else
					crypt = c;
			}
			fwrite(&crypt, sizeof(crypt), 1, outptr);
			
			// Add the random noises
			index = rand()%70;
			crypt = baseKey[index];
			fwrite(&crypt, sizeof(crypt), 1, outptr);
			index = rand()%10000;
			fprintf(outptr, "%04d", index);
			charCount++;
		}
		else
			fwrite(&c, sizeof(c), 1, outptr);
	}
	fclose(source);
	fclose(outptr);
}
