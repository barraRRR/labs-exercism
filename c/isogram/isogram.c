#include "isogram.h"
#include <ctype.h>
#include <string.h>

bool is_isogram(const char phrase[])
{
	if (phrase == NULL)
		return false;
	int len = 0, i = 0, j, k;
	while (phrase[i] !=  '\0')
	{
		len++;
		i++;
	}
	for (j = 0; j < len ; j++)
	{
		for (k = j + 1; k < len; k++)
		{
			if (isalpha(phrase[k]) && (toupper(phrase[k]) == toupper(phrase[j])))
					return false;
		}
	}
	return true;	
}

