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
 * Dom Letourneau 2016
 */

#include ".persolib.h"

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		printf("Usage; ./encrypt keys source output\n");
		return 1;
	}
	char* fileKey = argv[1];
	char* fileSource = argv[2];
	char* fileOutput = argv[3];
	// Tries to open the key and output files
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
	char key[KEY_NUM][KEY_LEN];	
	char c;
	int charCount = 0;
	int keyCount = 0;
	// Reads and stores the key set from the key file
	while (fread(&c, sizeof(c), 1, inptr) > 0)
	{
		fwrite(&c, sizeof(c), 1, outptr);
		if (charCount == KEY_LEN)
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
	// Closes the key file and open the source file
	fclose(inptr);
	FILE* source = fopen(fileSource, "r");
	if (source == NULL)
	{
		fclose(outptr);
		printf("Can't open %s\n", fileSource);
		return 3;
	}
	char baseKey[KEY_LEN] = {'G','B','y','d','T','m','X','Z','8','i','K','H','r','v',')','5',',','L',']','M','N','0','j','b','o','h','k','.','p','7','3','E','S','W','f','l','J','4','P','V','z','D','?','u','x','n','e','g','Y','2','s','a','(','[',' ','A','q','c','F','R','w','O','C','Q','U','1','t','I','9','6'};
	int index;
	char crypt;
	charCount = 0;
	struct timeval t1;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec * t1.tv_sec);
	// Encrypts the source text using the loaded key set
	while (fread(&c, sizeof(c), 1, source) > 0)
	{	
		// Cypher the text and copy the controls
		if (!iscntrl(c))
		{
			// Look for the target in the defined key
			// Get the index on the key and swap the char with the
			// one on the same index on the baseKey.
			for(int i=0;i<KEY_LEN;i++)
			{
				if(c == key[getKey(charCount%KEY_NUM)][i])
				{
					crypt = baseKey[i];
					break;
				}
				else
					crypt = c;
			}
			// Write the crypted char and the noise
			fwrite(&crypt, sizeof(crypt), 1, outptr);
			index = rand()%KEY_LEN;
			crypt = baseKey[index];
			fwrite(&crypt, sizeof(crypt), 1, outptr);
			index = rand()%10000;
			fprintf(outptr, "%04d", index);

			charCount++;
		}
		else
			fwrite(&c, sizeof(c), 1, outptr);
	}
	// Closes all opened files
	fclose(source);
	fclose(outptr);
}
