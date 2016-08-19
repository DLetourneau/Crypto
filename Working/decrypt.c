/**
 * decrypt.c
 *
 * Second try at the decryptor
 *
 * Read a properly formated crypted file and decrypts it.
 *
 * Receives the crypted and output file as arguments
 * 
 * Pretty much the reverse of the encryption process, once again, follow the code
 * to figure out the method
 * 
 * Dom Letourneau 2016
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
  // Argument Control
	if (argc != 3)
	{
		printf("Usage: ./decrypt infile outfile\n");
		return 9;
	}
	FILE* inptr = fopen(argv[1], "r");
	if (inptr == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		return 1;
	}
	FILE* outptr = fopen(argv[2], "w");
	if (outptr == NULL)
	{
		fclose(inptr);
		printf("Can't open %s\n", argv[2]);
		return 2;
	}
	
	// Key, needs to be the same as the one in the encryptor
	char baseKey[70] = {'G','B','y','d','T','m','X','Z','8','i','K','H','r','v',')','5',',','L',']','M','N','0','j','b','o','h','k','.','p','7','3','E','S','W','f','l','J','4','P','V','z','D','?','u','x','n','e','g','Y','2','s','a','(','[',' ','A','q','c','F','R','w','O','C','Q','U','1','t','I','9','6'};
	
	char c, crypt;
	char key[4][70];
	int keyToUse;
	int keyCount = 0;
	int charCount = 0;
	int allCount = 0;
	
	while (fread(&c, sizeof(c), 1, inptr) > 0)
	{
	  // Loads the key into memory
		if (allCount < 284)
		{
			if (allCount%71 == 70)
			{
				keyCount++;
			}
			else
			{		
				key[keyCount][allCount%71] = c;
			}
		}
		// Respect the formatting
		else if ((allCount >= 284) && (iscntrl(c)))
		{
			fwrite(&c, sizeof(c), 1, outptr);
			continue;
		}
		// Swap the crypted char with the clear text, skip the noise
		else if ((allCount >= 284) && ((allCount - 284)%6 == 0))
		{
			switch(charCount%4)
			{
				case 0: keyToUse=0; break;
				case 1: keyToUse=3; break;
				case 2: keyToUse=2; break;
				case 3: keyToUse=1; break;
			}
			for(int i=0;i<70;i++)
			{
				if(c == baseKey[i])
				{
					crypt = key[keyToUse][i];
					break;
				}
				else
					crypt = c;
			}
			fwrite(&crypt, sizeof(crypt), 1, outptr);
			charCount++;
		}
		allCount++;
	}
	fclose(inptr);
	fclose(outptr);
}
