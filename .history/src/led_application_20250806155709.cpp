#include "led_application.h"

BlinkLedApplication::BlinkLedApplication(uint8_t LedPin) : LedPin_c(LedPin)
{

}

void BlinkLedApplication::init()
{
    LedDriver_GPIO Led{LedPin_c};
    Led.init();
}

void BlinkLedApplication::LedBlink(uint64_t durationOn, uint64_t durationOff)
{
    LedDriver_GPIO Led{LedPin_c};
    Delay delay{};

    while (1)
    {
        Led.turnOn();
        delay.delay(durationOn);
        Led.turnOff();
        delay.delay(durationOff);
    }
}