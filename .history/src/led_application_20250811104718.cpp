#include "led_application.h"

BlinkLedApplication::BlinkLedApplication(uint8_t LedPin, uint8_t ButtonPin) : LedPin_c(LedPin), Led(LedPin), delay(), Button(ButtonPin)
{

}

void BlinkLedApplication::init()
{
    Led.init();
    Button.init();
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
        while(!Button.IsPressed());
        Led.switchState();

        while(Button.IsPressed());
        Led.switchState();

    }
}