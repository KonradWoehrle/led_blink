#pragma once

#include "uart_hal.h"

class UARD_Application
{
    public:
    UARD_Application() = default;
    ~UARD_Application() = default;

    void init();
    void loop();

private:
    UartHAL Uart;
};
