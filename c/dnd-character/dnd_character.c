#include "dnd_character.h"
#include <stdlib.h>
#include <math.h>

int ability(void)
{
    // Rolls four d6 dices
    const int DICES = 4;
    int rolls[DICES];
    for (int i = 0; i < DICES; i++)
    {
        int d6 = 1 + rand() % 6;
        rolls[i] = d6;
    }

    // Sorts dices
    int tmp, min_index;
    for (int j = 0; j < DICES - 1; j++)
    {
        min_index = j;
        for (int k = j; k < DICES; k++)
            if (rolls[k] < rolls[min_index])
                min_index = k;
        tmp = rolls[j];
        rolls[j] = rolls[min_index];
        rolls[min_index] = tmp; 
    }

    // Records the sum of the three largest and returns sum
    int sum = 0;
    for (int l = 1; l < DICES; l++)
        sum += rolls[l];
    
    return sum;
}

int modifier(int score)
{
    int mod = floor((score - 10) / 2.0);
    
    return mod; 
}

dnd_character_t make_dnd_character(void)
{
    // Populates abilities
    dnd_character_t crankonara;
    crankonara.strength = ability();
    crankonara.dexterity = ability();
    crankonara.constitution = ability();
    crankonara.intelligence = ability();
    crankonara.wisdom = ability();
    crankonara.charisma = ability();

    // Calculates hitpoints
    crankonara.hitpoints = 10 + modifier(crankonara.constitution);

    return crankonara;
}
