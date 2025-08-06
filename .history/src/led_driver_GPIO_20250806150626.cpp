#include "led_driver_GPIO.h"

LedDriver_GPIO::LedDriver_GPIO(uint8_t ledPin) : ledPin_c(ledPin)
{
    LedHAL_GPIO Led(ledPin_c);
    ledState_c = Led.GetState();
}

void LedDriver_GPIO::init()
{
    LedHAL_GPIO Led(ledPin_c);
    Led.ActivateClock();
    Led.ConfigurateAsOutput();
    Led.SetState(static_cast<bool>(LedState::Off));
}

void LedDriver_GPIO::turnOn()
{
    LedHAL_GPIO Led(ledPin_c);
    Led.SetState(static_cast<bool>(LedState::On));
    ledState_c = true;
}

void LedDriver_GPIO::turnOff()
{
    LedHAL_GPIO Led(ledPin_c);
    Led.SetState(static_cast<bool>(LedState::Off));
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
