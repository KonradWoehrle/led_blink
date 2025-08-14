#pragma once

#include "uart_hal.h"

class UART_Application
{
    public:
    UART_Application();
    ~UART_Application() = default;

    void init();
    void loop();
    void send();

private:
    UartHAL Uart;
};
