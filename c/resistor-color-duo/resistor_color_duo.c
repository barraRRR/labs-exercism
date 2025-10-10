#include "resistor_color_duo.h"
#include <stdio.h>

void color(resistor_band_t band[]);

int main(void)
{
	color((resistor_band_t[]){RED, ORANGE});
	return 0;
}

void color(resistor_band_t band[])
{
	for (int i = 0; i < COLOR_COUNT; i++)
		printf("The number is: %i", i);
}
