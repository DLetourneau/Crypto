/*
 * decrypt.c
 *
 * Second try at the decryptor
 *
 * Read a properly formated crypted file and decrypts it.
 *
 * Receives the crypted and output file as arguments
 */

#include ".persolib.h"

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Usage: ./decrypt infile outfile\n");
		return 9;
	}
	// Tries to open the source and output files
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
	// Define the variables
	char baseKey[KEY_LEN] = {'G','B','y','d','T','m','X','Z','8','i','K','H','r','v',')','5',',','L',']','M','N','0','j','b','o','h','k','.','p','7','3','E','S','W','f','l','J','4','P','V','z','D','?','u','x','n','e','g','Y','2','s','a','(','[',' ','A','q','c','F','R','w','O','C','Q','U','1','t','I','9','6'};
	char c, crypt;
	char key[KEY_NUM][KEY_LEN];
	int keyToUse;
	int keyCount = 0;
	int charCount = 0;
	int allCount = 0;
	// Decrypts the cyphered text
	while (fread(&c, sizeof(c), 1, inptr) > 0)
	{	
		// Read and Loads the key set (first 4 lines (70 chars))
		if (allCount < KEY_SET_LEN)
		{
			if (allCount%(KEY_LEN+1) == KEY_LEN)
			{
				keyCount++;
			}
			else
			{		
				key[keyCount][allCount%(KEY_LEN+1)] = c;
			}
		}
		// Copies the control
		else if ((allCount >= KEY_SET_LEN) && (iscntrl(c)))
		{
			fwrite(&c, sizeof(c), 1, outptr);
			continue;
		}
		// Decypher the text (every 6th char is valid)
		else if ((allCount >= KEY_SET_LEN) && ((allCount - KEY_SET_LEN)%6 == 0))
		{
			// Looks for the cyphered char in the baseKey
			// Replaces it with the one on the same index
			// On the defined key
			for(int i=0;i<KEY_LEN;i++)
			{
				if(c == baseKey[i])
				{
					crypt = key[getKey(charCount%4)][i];
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
	// Close the opened files
	fclose(inptr);
	fclose(outptr);
}
