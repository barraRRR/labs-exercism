#include "hamming.h"
#include <stdio.h>
#include <string.h>

int compute(const char *lhs, const char *rhs)
{
    if (strlen(lhs) == strlen(rhs))
    {
        int hamming = 0;
        for (size_t i = 0; i < strlen(lhs) ; i++)
            if (lhs[i] != rhs[i])
            {
                hamming++;
            }
        return hamming;
    }
    else
    {
        return -1;
    }
}
