#include "delay_hal.h"

void Delay_HAL::delay_1000ms(uint64_t pause)
{
    pause *= 1000;
    pause *= static_cast<uint64_t>(delay_factor_c);

    for (volatile uint32_t i = 0; i < pause; ++i);
}

void Delay_HAL::delay_1ms(uint64_t pause)
{
    pause *= static_cast<uint64_t>(delay_factor_c);

    for (volatile uint32_t i = 0; i < pause; ++i);
}