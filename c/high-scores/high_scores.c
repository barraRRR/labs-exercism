#include "high_scores.h"
#include <stdio.h>


//Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len)
{ 
	return scores[scores_len - 1];
}

// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len)
{
	int32_t high = 0;
	for (int i = 0; i < (int) scores_len; i++)
	{
		if (scores[i] > high)
		{
			high = scores[i];
		}
	}
	return high;
}

 /// Write the highest scores to `output` (in non-ascending order).
 /// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
	int i, k, swaps = 1;
        int32_t temp;
	int32_t scores_temp[scores_len];

	// copies pointes lo local array
	for (k = 0; k < (int)scores_len; k++)
	{
		scores_temp[k] = scores[k];
	}
        while (swaps > 0)
        {
        	swaps = 0;
                for (i = 0; i < (int)scores_len - 1; i++)
                {       
                	if (scores_temp[i] > scores_temp[i + 1])
                        {       
                        	temp = scores_temp[i];
                                scores_temp[i] = scores_temp[i + 1];
                                scores_temp[i + 1] = temp;
                    		swaps++;
		 	}
             	}
 	}
	if (scores_len >= 3)
	{
		for (int j = 0; j < 3; j++)
		{
			output[j] = scores_temp[(int)scores_len - j - 1];
		}
	return 3;
	}
	else
	{
		for (int l = 0; l < (int)scores_len; l++)
		{
			output[l] = scores_temp[(int)scores_len - l - 1];
		}
	return scores_len;
	}
}

