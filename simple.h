#ifndef CH32V003_LIB_SHIFT_REGISTER_SIMPLE
#define CH32V003_LIB_SHIFT_REGISTER_SIMPLE
#include <stdint.h>

#define SHIFT_LSBFIRST 0b0000'0000
#define SHIFT_MSBFIRST 0b0000'0001

void shift_out(uint8_t data_pin, uint8_t clk_pin, uint8_t flags, uint8_t value);
#endif
