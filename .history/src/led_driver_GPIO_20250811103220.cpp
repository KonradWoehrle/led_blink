#include "led_driver_GPIO.h"

LedDriver_GPIO::LedDriver_GPIO(uint8_t ledPin) : ledHAL(ledPin)
{
    ledState_c = ledHAL.GetState();
}

void LedDriver_GPIO::init()
{
    ledHAL.ActivateClock();
    ledHAL.ConfigureAsOutput();
    // LedState is an enum, so we cast to bool for SetState compatibility
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

// Toggles the current state of the LED between On and Off
void LedDriver_GPIO::switchState()
{
    if (ledState_c)
    {
        ledHAL.SetState(static_cast<bool>(LedState::Off));
        ledState_c = false;
    }
    else
    {
        ledHAL.SetState(static_cast<bool>(LedState::On));
        ledState_c = true;
    }
}

bool LedDriver_GPIO::getLedState() const
{
    return ledState_c;
}
