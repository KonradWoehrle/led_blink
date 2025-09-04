#pragma once

#include "button_hal.h"
#include "delay_driver.h"

// enum class ButtonState : bool {Low = 0, High = 1};

class ButtonDriver
{
public:
    ButtonDriver(uint8_t ButtonPin);
    ~ButtonDriver() = default;

    void init();
    bool IsPressed();

private:
    bool retVal_c = false;
    ButtonHAL_GPIO  ButtonHAL;
    DelayDriver delay;
};