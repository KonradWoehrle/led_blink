#include "config.h"
#include "uart_application.h"

extern UART_Application AppUart;

int main()
{
    AppUart.init();

    printf("Hello Worl5%d\n", 53);

    while (1)
    {
        AppUart.loop();
    }
}