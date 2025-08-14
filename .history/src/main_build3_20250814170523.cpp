#include "config.h"
#include "uart_application.h"


extern "C" int __io_putchar(int ch)
{
    Uart.getUartHAL().sendByte(ch);
    return ch;
}


int main()
{
    UART_Application Uart{};
    Uart.init();

    while (1)
    {
        Uart.send();
    }


}

/*
    printf("Hello World");
    UART_Application Uart{};
    Uart.init();

    Uart.loop();
}
*/