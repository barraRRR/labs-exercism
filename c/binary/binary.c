#include "binary.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int convert(const char *input)
{
    int len = 0;
    int sum = 0;

    while (input[len] != '\0') len++;
    for (int i = 0; i < len; i++)
    {
        char c = input[i];
        if (c != '0' && c != '1') return INVALID;

        int bit_val = c - '0';
        sum += bit_val << (len - 1 - i);
    }
    return sum;
}
