#include "delay_driver.h"

void DelayDriver::delay_1ms(uint64_t pause)
{
    Delay_HAL.delay(pause);
}

void DelayDriver::delay_1s(uint64_t pause)
{
    pause *= 1000;

    Delay_HAL.delay(pause);
}