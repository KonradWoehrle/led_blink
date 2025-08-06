#include "led_application.h"

BlinkLedApplication::BlinkLedApplication(uint8_t LedPin) : LedPin_c(LedPin)
{

}

void BlinkLedApplication::init()
{
    LedDriver_GPIO Led{LedPin_c};
    Led.init();
}

void BlinkLedApplication::LedBlink(uint8_t durationOn, uint8_t durationOff)
{
    LedDriver_GPIO Led{LedPin_c};
    Delay delay{};


    Led.turnOn();
    delay.delay(durationOn);
    Led.turnOff();
    delay.delay(durationOff);
}