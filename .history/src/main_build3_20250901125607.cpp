#include "config.h"
#include "uart_application.h"


int main()
{
    UART_Application AppUart;
    
    AppUart.init();

    printf("Hello World\n");

    while (1)
    {
        AppUart.loop();
    }
}