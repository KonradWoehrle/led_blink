#include "config.h"
#include "uart_application.h"
#include "uart_application.cpp"

int main()
{
    UART_Application Uart{};
    Uart.init();

    Uart.loop();
}
