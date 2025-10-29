#include "perfect_numbers.h"
#include <stdlib.h>


int classify_number(int n)
{
	// ignores negative number and zero
	if (n <= 0)
	{
		return ERROR;
	}
	
	// loops over the nubr to find out total number of divisors
	int i, divisor_count = 0;

	for (i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			divisor_count++;
		}
	}

	// creates an array of divisors
	int *divisor_array = malloc(divisor_count * sizeof(int));
	if (divisor_array == NULL)
	{
		return ERROR;
	}
	int j; 
	divisor_count = 0;
	for (j = 1; j < n; j++)
	{
		if (n % j == 0)
		{
			divisor_array[divisor_count] = j;
			divisor_count++;
		}		
	}

	// calculates aliquot_sum(n)
	int k, aliquot_sum = 0;
	for (k = 0; k < divisor_count; k++)
	{
		aliquot_sum += divisor_array[k];
	}
	
	// compares number with aliquot_sum
	
	if (aliquot_sum == n)
	{
		return PERFECT_NUMBER;
	}
	else if (aliquot_sum > n)
	{
		return ABUNDANT_NUMBER;
	}
	else if (aliquot_sum < n)
	{
		return DEFICIENT_NUMBER;
	}
	else
	{
		return ERROR;
	}
	free(divisor_array);
}

