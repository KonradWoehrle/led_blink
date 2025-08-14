#include "uart_application.h"

UART_Application::UART_Application() : Uart()
{

}

void UART_Application::init()
{
    Uart.init();
}

void UART_Application::loop()
{
    char* msg;
    while(1)
    {
        msg = Uart.receiveBuffer();

        if (strcmp(msg, "ping\n") == 0)
        {
            Uart.sendBuffer("pong\n", 5);
        }
    }
}

void UART_Application::send()
{
    while (1)
    {
        Uart.sendBuffer("abcdefghijklmnopqrstuvwxyz", 26);
        for (volatile int i = 0; i < 500000; ++i);
    }
}

UartHAL& UART_Application::getUartHAL()
{
    return Uart;
}
