
#include "led_hal.h"

LedHAL_GPIO::LedHAL_GPIO(uint8_t ledPin) : PortA_Pin_c(ledPin)
{
    state_c = false;
}

void LedHAL_GPIO::ActivateClock()
{
    // hardware dependent
}

void LedHAL_GPIO::ConfigureAsOutput()
{
    // hardware dependent
}

void LedHAL_GPIO::SetState(bool state)
{
    state_c = state;
}

bool LedHAL_GPIO::GetState() const
{
    return state_c;
}