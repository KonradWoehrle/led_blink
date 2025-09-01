#include "config.h"
#include "uart_application.h"

int main()
{
    UART_Application Uart{};
    Uart.init();

    printf("Hello World\n");
    
    while (1)
    {
        Uart.loop();
    }
}