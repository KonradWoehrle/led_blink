#pragma once

#include "led_hal.h"
#include "led_hal.cpp"

enum class LedState : bool {Off = 0, On = 1};

class LedDriver_GPIO
{
public:
    LedDriver_GPIO(uint8_t ledPin);
    ~LedDriver_GPIO() = default;

    void init();
    void turnOn();
    void turnOff();
    void switchState();

    bool getLedState() const;

private:
    bool ledState_c = false;     // State of the LED
    LedHAL_GPIO  ledHAL;
};