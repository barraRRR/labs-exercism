#include "resistor_color_trio.h"
#include <math.h>
#include <stdio.h>

resistor_value_t color_code(resistor_band_t color[])
{
	resistor_value_t actual;
    	int digits = color[0] * 10 + color[1];
    	int multiplier = 1;

	if (digits == 99)
	{
    		multiplier = 1;
	}
       	else
	{
    		for (int i = 0; i < color[2]; i++)
        		multiplier *= 10;
	}

	actual.value = digits * multiplier;

    	if (actual.value >= 1000000000)
    	{
        	actual.value /= 1000000000;
        	actual.unit = "GIGAOHMS";
    	}
    	else if (actual.value >= 1000000)
    	{
        	actual.value /= 1000000;
        	actual.unit = "MEGAOHMS";
    	}
    	else if (actual.value >= 1000)
    	{
        	actual.value /= 1000;
        	actual.unit = "KILOOHMS";
    	}
    	else
    	{
        	actual.unit = "OHMS";
    	}

    	return actual;
}

