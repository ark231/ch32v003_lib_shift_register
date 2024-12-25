#include "simple.h"

#include <ch32v003fun.h>

#define FREQ     10'000
#define LOOP_US  (1'000'000 / FREQ)
#define micros() (SysTick->CNT / DELAY_US_TIME)
#define millis() (SysTick->CNT / DELAY_MS_TIME)

void shift_out(uint8_t data_pin, uint8_t clk_pin, uint8_t flags, uint8_t value) {
    uint32_t current_time    = micros();
    uint32_t loop_start_time = micros();
    uint8_t b;
    for (int i = 0; i < 8; i++) {
        funDigitalWrite(clk_pin, FUN_LOW);
        // serial input is read on rising edges of the clock
        if ((flags & SHIFT_LSBFIRST) != 0) {
            b = ((value >> i) & 1) == 0 ? FUN_LOW : FUN_HIGH;
        } else {
            b = ((value << i) & 0x80) == 0 ? FUN_LOW : FUN_HIGH;
        }
        funDigitalWrite(data_pin, b);

        while (micros() - loop_start_time < (LOOP_US / 2)) {
        }
        current_time = micros();

        funDigitalWrite(clk_pin, FUN_HIGH);
        while (current_time - loop_start_time < (LOOP_US)) {
            current_time = micros();
        }
    }
    funDigitalWrite(clk_pin, FUN_LOW);
}
