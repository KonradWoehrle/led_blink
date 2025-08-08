#include "delay_driver.h"

void Delay::delay_1ms(uint64_t pause)
{
    Delay_HAL delay;
    delay.delay(pause);
}

void Delay::delay_1s(uint64_t pause)
{
    pause *= 1000;

    Delay_HAL delay;
    delay.delay(pause);
}