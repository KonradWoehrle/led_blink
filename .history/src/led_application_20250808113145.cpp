#include "led_application.h"

BlinkLedApplication::BlinkLedApplication(uint8_t LedPin, uint8_t ButtonPin) : LedPin_c(LedPin), Led(LedPin), delay(), Button(ButtonPin)
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
        if(Button.IsPressed())
        {
            delay.delay_1ms(100);
            while(Button.IsPressed())
            delay.delay_1ms(100);

            Led.switchState();
        }
    }
}