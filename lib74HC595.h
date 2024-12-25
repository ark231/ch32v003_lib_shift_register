#ifndef CH32V003_LIB_SHIFT_REGISTER_LIB74HC595
#define CH32V003_LIB_SHIFT_REGISTER_LIB74HC595
#include <stdint.h>
typedef struct {
    uint8_t srclk;
    uint8_t ser;
    uint8_t rclk;
    uint8_t srclr;
} Lib74HC595;
#endif
