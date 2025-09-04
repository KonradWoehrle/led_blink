#include "uart_driver.h"

UART_Driver AppUart;

extern "C" int _write(int file, char *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        AppUart.getUartHAL().sendByte(static_cast<uint8_t>(ptr[i]));
    }
    return len;
}

UART_Driver::UART_Driver() : Uart()
{

}

void UART_Driver::init()
{
    Uart.init();
}

void UART_Driver::loop()
{
    char* msg;
    while(1)
    {
        msg = Uart.receiveBuffer();

        Uart.sendBuffer(msg, strlen(msg));
    }
}

void UART_Driver::send()
{
    while (1)
    {
        Uart.sendBuffer("abcdefghijklmnopqrstuvwxyz\n", 26);
        for (volatile int i = 0; i < 500000; ++i);
    }
}

UartHAL& UART_Driver::getUartHAL()
{
    return Uart;
}
