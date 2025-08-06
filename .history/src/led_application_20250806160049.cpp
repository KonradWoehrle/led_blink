#include "led_application.h"

BlinkLedApplication::BlinkLedApplication(uint8_t LedPin) : LedPin_c(LedPin), Led(LedPin), delay()
{

}

void BlinkLedApplication::init()
{
    Led.init();
}

void BlinkLedApplication::LedBlink(uint64_t durationOn, uint64_t durationOff)
{
    while (1)
    {
        for (volatile uint32_t i = 0; i < 1000000; ++i);
        Led.turnOn();
        delay.delay(durationOn);
        for (volatile uint32_t i = 0; i < 1000000; ++i);
        Led.turnOff();
        delay.delay(durationOff);
    }
}