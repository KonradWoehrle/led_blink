#include "uart_driver.h"

UART_Application AppUart;

extern "C" int _write(int file, char *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        AppUart.getUartHAL().sendByte(static_cast<uint8_t>(ptr[i]));
    }
    return len;
}

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

        Uart.sendBuffer(msg, strlen(msg));
    }
}

void UART_Application::send()
{
    while (1)
    {
        Uart.sendBuffer("abcdefghijklmnopqrstuvwxyz\n", 26);
        for (volatile int i = 0; i < 500000; ++i);
    }
}

UartHAL& UART_Application::getUartHAL()
{
    return Uart;
}
