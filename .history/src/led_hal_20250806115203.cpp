#include "led_hal.h"

LedHAL_GPIO::LedHAL_GPIO()
{

}

void LedHAL_GPIO::ActivateClock()
{
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;    // neuer Wert = (alter Wert | 0x00000001)
}

void LedHAL_GPIO::ConfigurateOutput()
{
        
}