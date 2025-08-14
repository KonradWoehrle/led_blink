#include "config.h"
#include "uart_application.h"

extern "C" int __io_putchar(int ch)
{
    UartHAL uart;
    uart.sendByte(ch);   // sendet ein Zeichen über UART
    return ch;
}


int main()
{
    UART_Application Uart{};
    Uart.init();
    printf("Hello %d\n", 123);

    while (1)
    {
        Uart.send();
    }




/*
    printf("Hello World");
    UART_Application Uart{};
    Uart.init();

    Uart.loop();*/
}
