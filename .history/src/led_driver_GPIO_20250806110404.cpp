#include "led_driver_GPIO.h"

LedDriver_GPIO::LedDriver_GPIO(uint8_t ledPin) : ledPin_c(ledPin)
{
    // ledState_c = ;           objekt von HAL aufrufen und den Pin abfragen
}

void LedDriver_GPIO::init()
{
    // This method should be overridden in derived classes
    // Zustand festlegen
    // Pin konfigurieren
}

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
