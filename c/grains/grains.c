#include "grains.h"

uint64_t square(uint8_t i) {
    uint64_t grain = 1;
    if (i == 0 || i > 64) {
        return 0;
    } else {
    for (uint8_t j = 1; j < i; j++) {
        grain *= 2;
    }
    return grain;
    }
}
uint64_t total(void) {
    uint64_t total_grain = 0;
    for (uint8_t i = 0; i <= 64; i++) {
        total_grain += square(i);
    }
    return total_grain;
}
