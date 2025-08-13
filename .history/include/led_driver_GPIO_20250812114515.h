#pragma once

#include "led_hal.h"

enum class LedState : bool {Off = 0, On = 1};

class LedDriver_GPIO
{
public:
    LedDriver_GPIO(uint8_t ledPin);
    virtual ~LedDriver_GPIO() = default;

    virtual void init();
    virtual void turnOn();
    virtual void turnOff();
    virtual void switchState();

    virtual bool getLedState() const;

private:
    bool ledState_c = false;     // State of the LED
    LedHAL_GPIO  ledHAL;
};