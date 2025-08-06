#include "delay_driver.h"

void Delay::delay(uint64_t pause)
{
    for (volatile uint32_t i = 0; i < pause; ++i);
}