#pragma once

#include "button_hal.h"
#include "button_hal.cpp"
#include "delay_driver.h"
#include "delay_driver.cpp"

// enum class ButtonState : bool {Low = 0, High = 1};

class ButtonDriver
{
public:
    ButtonDriver(uint8_t ButtonPin);
    virtual ~ButtonDriver() = default;

    virtual void init();
    virtual bool IsPressed();

private:
    bool retVal_c = false;
    ButtonHAL_GPIO  ButtonHAL;
    DelayDriver delay;
};