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
    while(1)
    {
        char* msg = Uart.receiveBuffer();

        if (strcmp(msg, "ping\n") == 0)
        {
            Uart.sendBuffer("pong\n", 5);
        }
    }
}