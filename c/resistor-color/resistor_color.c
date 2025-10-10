#include "resistor_color.h"

resistor_band_t *colors(void);
int color_code(resistor_band_t color);

resistor_band_t *colors(void) {
    static resistor_band_t all_colors[] = {
        BLACK,
        BROWN,
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        BLUE,
        VIOLET,
        GREY,
        WHITE
    };
    return all_colors;
}

int color_code(resistor_band_t color) {
   return color;
}
