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
        Led.turnOn();
        delay.delay_1ms(durationOn);
        Led.turnOff();
        delay.delay_1ms(durationOff);
    }
}

void BlinkLedApplication::PressButtonForLED()
{
    while(1)
    {
        if(button.IsPressed())
        {
            delay.delay_1ms(100);
            while(button.IsPressed())
            delay.delay_1ms(100);

            Led.switchState();
        }
    }
}