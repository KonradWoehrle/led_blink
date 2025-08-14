#include "config.h"
#include "led_application.h"
#include "uart_application.h"

int main()
{
    UART_Application Uart{};
    Uart.init();

    Uart.loop();
}
