#include "space_age.h"
#include <stdio.h>

float age(planet_t planet, int64_t seconds)
{
    double planet_time[][8] = {{MERCURY, 0.2408467}, {VENUS, 0.61519726 }, {EARTH, 1}, {MARS, 1.8808158}, {JUPITER, 11.862615}, {SATURN, 29.447498}, {URANUS, 84.016846}, {NEPTUNE, 164.79132}};

    if (planet >= 0 && planet < 8 && seconds >= 0)
    {
        return seconds / (31557600 * planet_time[planet][1]);
    }
    else
    {
        return -1;
    }
}
