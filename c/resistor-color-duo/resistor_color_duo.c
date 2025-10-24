#include "resistor_color_duo.h"
#include <stdio.h>

int color_code(resistor_band_t band[])
{
	printf("Primer color: %d\n", band[0]);
    printf("Segundo color: %d\n", band[1]);
	return band[0] * 10 + band[1];
}
