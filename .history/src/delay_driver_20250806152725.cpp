#include "delay_driver.h"

void Delay::delay(uint32_t pause)
{
    while (pause--);
}