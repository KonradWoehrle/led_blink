#include "config.h"
#include "uart_application.h"

extern UART_Application AppUart;

int main()
{
    AppUart.init();

    printf("Hello World");

    while (1)
    {
        AppUart.loop();
    }
}