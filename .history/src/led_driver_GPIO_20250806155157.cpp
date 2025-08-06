#include "led_driver_GPIO.h"

LedDriver_GPIO::LedDriver_GPIO(uint8_t ledPin) : ledPin_c(ledPin), ledHAL(ledPin)
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
/*
void LedDriver_GPIO::toggle()
{
    // GPIO Pin toggeln, um den Zustand der LED zu ändern
    ledState_c = !ledState_c;
}
*/
uint8_t LedDriver_GPIO::getLedPin() const
{
    return ledPin_c;
}

void LedDriver_GPIO::setLedPin(uint8_t ledPin)
{
    ledPin_c = ledPin;
}

bool LedDriver_GPIO::getLedState() const
{
    return ledState_c;
}
