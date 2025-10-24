#include "eliuds_eggs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int egg_count(int dec)
{
    // dec to bin
    char *bin = malloc(32); // puede ser pero tengo que comprobarlo
    if (bin == NULL)
    {
        return 1;
    }
    
    int dec_to_bin = dec;
    int i = 0;
    while (dec_to_bin > 0)
    {
        if (dec_to_bin % 2 == 1)
        {
            bin[i] = '1';
            dec_to_bin = (dec_to_bin - 1) / 2;
        }
        else if (dec_to_bin % 2 == 0)
        {
            bin[i] = '0';
            dec_to_bin /= 2;
        }
        i++;
    }

    char *bin_tmp = malloc(i * sizeof(char) + 1);
    if (bin_tmp == NULL)
    {
        return 1;
    }
    for (int l = 0; l < i; l++)
    {
        bin_tmp[l] = bin[l];
    }
    bin_tmp[i] = '\0';
    free(bin);

    // 1 in bin
    int count = 0;
    for (int j = 0; j < (int) strlen(bin_tmp) + 1; j++)
    {
        if (bin_tmp[j] == '1')
        {
            count++;
        }
    }
    printf("BIN: %s ", bin_tmp);
    free(bin_tmp);
    return count;

}
