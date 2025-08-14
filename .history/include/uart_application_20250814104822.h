#pragma once

#include "uart_hal.h"

class UART_Application
{
    public:
    UART_Application() = default;
    ~UART_Application() = default;

    void init();
    void loop();

private:
    UartHAL Uart;
};
