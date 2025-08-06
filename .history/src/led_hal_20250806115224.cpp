#include "led_hal.h"

LedHAL_GPIO::LedHAL_GPIO()
{

}

void LedHAL_GPIO::ActivateClock()
{
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;    // new value = (old value | 0x00000001)
}