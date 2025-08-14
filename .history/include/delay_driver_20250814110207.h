#pragma once

#include "delay_hal.h"
#include "delay_hal.cpp"

class DelayDriver
{
public:
    DelayDriver();
    virtual ~DelayDriver() = default;

    virtual void delay_1s(uint64_t pause);
    virtual void delay_1ms(uint64_t pause);

private:
    Delay_HAL Delay;
};