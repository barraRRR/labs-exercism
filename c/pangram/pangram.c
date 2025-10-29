#include "pangram.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool is_pangram(const char *sentence)
{
	if (sentence == NULL)
		return false;
	// obtains len
	int len = strlen(sentence);
	// discards short sentences
	if (len < 26)
		return false;
	// creates alphabet array and populates it
	int alphab[ALPHABET];
	for (int j = 0; j < ALPHABET; j++)
	{
		alphab[j] = ' ';
	}
	// loops through the string
	char temp;
	for (int i = 0; i < len; i++)
	{
		if (	(sentence[i] >= 'A' && sentence[i] <= 'Z') ||
			(sentence[i] >= 'a' && sentence[i] <= 'z'))
		{
			temp = toupper(sentence[i]);	
			alphab[temp - (int) 'A'] = temp;
		}
		else
			continue;
	}
	// loops through alphab checking if all letters ar included
	for (int k = 0; k < ALPHABET; k++)
	{
		if (alphab[k] == ' ')
			return false;
	}
	return true;
}

