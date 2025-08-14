#include "config.h"
#include "uart_application.h"

int main()
{
    UART_Application Uart{};
    Uart.init();

    while (1)
    {
        Uart.send();
    }
}