#include "uart_application.h"

UART_Application::UART_Application() : 
{

}

void UART_Application::init()
{

}

void UART_Application::loop()
{
    char* msg = receiveBuffer();

    if (strcmp(msg, "ping\n") == 0)
    {
        sendBuffer("pong\n", 5);
    }
}