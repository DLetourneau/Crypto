/**
 * decryptTest.c
 *
 * First step of decryption
 *
 * Read 2 files (1 key set and 1 source text) and outputs a 
 * pseudo-encrypted version of it.
 *
 * Dominic Letourneau 2016
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv)
{
	FILE* inptr = fopen("keys.txt", "r");
	if (inptr == NULL)
	{
		printf("Can't open keys.txt");
		return 1;
	}

	FILE* outptr = fopen("output.txt", "w");
	if (outptr == NULL)
	{
		fclose(inptr);
		printf("Can't open output.txt");
		return 2;
	}
	
	char c;
	int charCount = 0;
	while (fread(&c, sizeof(c), 1, inptr) > 0)
	{
		fwrite(&c, sizeof(c), 1, outptr);
	}

	fclose(inptr);

	FILE* source = fopen("source.txt", "r");
	if (source == NULL)
	{
		fclose(outptr);
		printf("Can't open source.txt");
		return 3;
	}

	while (fread(&c, sizeof(c), 1, source) > 0)
	{
		fwrite(&c, sizeof(c), 1, outptr);
		if (!iscntrl(c))
		{
			charCount++;
			char crypt = (charCount % 10) + '0';
			fwrite(&crypt, sizeof(crypt), 1, outptr);
		}
	}
	fclose(source);
	fclose(outptr);
}
