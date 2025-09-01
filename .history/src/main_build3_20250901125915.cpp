#include "config.h"
#include "uart_application.h"

extern UART_Application AppUart;

int main()
{
    AppUart.init();

    printf("Hello World\n");

    while (1)
    {
        AppUart.loop();
    }
}