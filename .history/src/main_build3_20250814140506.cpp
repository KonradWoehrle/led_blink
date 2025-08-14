#include "config.h"
#include "uart_application.h"
#include "uart_application.cpp"
#include "uart_hal.h"
#include "uart_hal.cpp"

extern "C" int __io_putchar(int ch)
{
    ITM_SendChar(ch);
    return ch;
}

int main()
{
    UartHAL Uart{};
    Uart.init();

    while (1)
    {
        Uart.sendBuffer("Hello\r\n", 7);
        for (volatile int i = 0; i < 1000000; ++i);
    }




/*
    printf("Hello World");
    UART_Application Uart{};
    Uart.init();

    Uart.loop();*/
}
