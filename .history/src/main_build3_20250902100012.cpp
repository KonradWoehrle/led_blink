#include "config.h"
#include "uart_driver.h"

extern UART_Application AppUart;

int main()
{
    AppUart.init();

    printf("Hello World\n");

    while (1)
    {
        AppUart.loop();
    }

    return 0;
}