/**
 * decryptTest.c
 *
 * First step of decryption
 *
 * Read a properly formated crypted file and pseudo-decrypts it.
 *
 * Dominic Letourneau 2016
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv)
{
	FILE* inptr = fopen("test.txt", "r");
	if (inptr == NULL)
	{
		printf("Can't open text.txt");
		return 1;
	}

	FILE* outptr = fopen("target.txt", "w");
	if (outptr == NULL)
	{
		fclose(inptr);
		printf("Can't open target.txt");
		return 2;
	}
	
	char c;
	int charCount = 0;
	int allCount = 0;
	while (fread(&c, sizeof(c), 1, inptr) > 0)
	{
		if ((allCount >= 20) && (charCount % 2 == 0))
			fwrite(&c, sizeof(c), 1, outptr);
		if (!iscntrl(c))
			charCount++;
		allCount++;
	}

	fclose(inptr);
	fclose(outptr);
}
