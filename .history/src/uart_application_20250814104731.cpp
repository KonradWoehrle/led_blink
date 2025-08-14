#include "uart_application.h"

void UARD_Application::init()
{

}

void UARD_Application::loop()
{
    char* msg = receiveBuffer();

    if (strcmp(msg, "ping\n") == 0)
    {
        sendBuffer("pong\n", 5);
    }
}