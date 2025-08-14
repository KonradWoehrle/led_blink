#include "config.h"
#include "uart_application.h"

UART_Application Uart{};

extern "C" int __io_putchar(int ch)
{
    Uart.getUartHAL().sendByte(ch);
    return ch;
}


int main()
{
    Uart.init();
    printf("Hello %d\n", 123);

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