#pragma once

#include "uart_hal.h"

class UART_Driver
{
    public:
    UART_Driver();
    ~UART_Driver() = default;

    void init();
    void loop();
    void send();
    UartHAL& getUartHAL();

private:
    UartHAL Uart;
};
