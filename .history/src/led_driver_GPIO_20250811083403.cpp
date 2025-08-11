#include "led_driver_GPIO.h"

LedDriver_GPIO::LedDriver_GPIO(uint8_t ledPin) : ledHAL(ledPin)
{
    ledState_c = ledHAL.GetState();
}

void LedDriver_GPIO::init()
{
    ledHAL.ActivateClock();
    ledHAL.ConfigurateAsOutput();
    ledHAL.SetState(static_cast<bool>(LedState::Off));
}

void LedDriver_GPIO::turnOn()
{
    ledHAL.SetState(static_cast<bool>(LedState::On));
    ledState_c = true;
}

void LedDriver_GPIO::turnOff()
{
    ledHAL.SetState(static_cast<bool>(LedState::Off));
    ledState_c = false;
}

void LedDriver_GPIO::switchState()
{
    if(!ledState_c)
    {
        ledHAL.SetState(static_cast<bool>(LedState::On));
        ledState_c = true;
    }
    else
    {
        ledHAL.SetState(static_cast<bool>(LedState::Off));
        ledState_c = false;
    }
}


bool LedDriver_GPIO::getLedState() const
{
    return ledState_c;
}
