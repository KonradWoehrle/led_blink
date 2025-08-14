#pragma once

#include "led_driver_GPIO.h"
#include "led_driver_GPIO.cpp"
#include "delay_driver.h"
#include "delay_driver.cpp"
#include "button_driver.h"
#include "button_driver.cpp"

class BlinkLedApplication
{
    public:
    BlinkLedApplication(uint8_t LedPin, uint8_t ButtonPin);
    ~BlinkLedApplication() = default;

    void init();
    void LedBlink(uint64_t durationOn = 100, uint64_t durationOff = 900);
    void PressButtonForLED();

#ifdef TEST_SUITE_ENABLED
    uint8_t GetLedPin();
#endif

private:
    uint8_t LedPin_c;
    LedDriver_GPIO Led;
    DelayDriver delay;
    ButtonDriver Button;
};
