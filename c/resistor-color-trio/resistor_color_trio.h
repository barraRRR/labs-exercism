#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h>

typedef enum {
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
} resistor_band_t;

typedef struct resistor_value_t {
	uint64_t value;
	char *unit;
} resistor_value_t;

#define OHMS "OHMS"
#define KILOOHMS "KILOOHMS"
#define MEGAOHMS "MEGAOHMS"
#define GIGAOHMS "GIGAOHMS"

resistor_value_t color_code(resistor_band_t color[]);

#endif
