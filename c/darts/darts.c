#include "darts.h"
#include <stdio.h>
#include <math.h>

int score(coordinate_t landing_position)
{
    float x = landing_position.x;
    float y = landing_position.y;

    float d = sqrtf((x*x)+(y*y));

    if (d > 10 || d < -10)
    {
        printf("Distance = %f. MISS", d);
        return 0;
    }
    else if (d >= -1 && d <= 1)
    {
        printf("Distance = %f. 10 POINTS!", d);
        return 10;
    }
    else if (d >= -5 && d <= 5)
    {
        printf("Distance = %f. 5 POINTS", d);
        return 5;
    }
    else
    {
        printf("Distance = %f. 1 POINT", d);
        return 1;
    }
}
