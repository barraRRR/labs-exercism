#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna)
{
    size_t len = strlen(dna);
    char *new = malloc(len + 1);
    if (!new) return NULL;

    for (size_t i = 0; i < len; i++) {
        
        switch (dna[i])
        {
            case 'A':
                new[i] = 'U';
                break;
            case 'T':
                new[i] = 'A';
                break;
            case 'C':
                new[i] = 'G';
                break;
            case 'G':
                new[i] = 'C';
                break;
            default:
                free(new);
                return NULL;
        }
    }
    new[len] = '\0';
    return new;

}
