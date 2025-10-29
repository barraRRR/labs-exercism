#include "armstrong_numbers.h"
#include <math.h>

int digits(int number)
{
	if (number < 10 && number > -10)
		return 1;
	else
		return 1 + digits(number / 10);	
}

bool is_armstrong_number(int candidate)
{
	int numdigits = digits(candidate);
	int i, sum = 0;
	int candidateop = candidate;
	int last_digit;
	for (i = 0; i < numdigits; i++)
	{
	last_digit = candidateop % 10;
	sum += (int) pow(last_digit, numdigits);
	candidateop /= 10;
	}
	
	if (sum == candidate)
		return true;
	else
		return false;	
}

