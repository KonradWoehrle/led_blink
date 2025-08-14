#pragma once

#include "config.h"
#include "uart_hal.h"
#include "uart_hal.cpp"

class UartDriver
{
public:
    UartDriver(UartHAL& hal);
    ~UartDriver() = default;

    void print(const char* msg);

private:
    UartHAL& uartHAL;
};