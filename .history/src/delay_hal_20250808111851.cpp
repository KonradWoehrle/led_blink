#include "delay_hal.h"

void Delay_HAL::delay(uint64_t pause)
{
    pause *= delay_factor_c;

    for (volatile uint32_t i = 0; i < pause; ++i);
}
