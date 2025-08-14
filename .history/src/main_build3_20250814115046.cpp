#include "config.h"
#include "uart_application.h"
#include "uart_application.cpp"

extern "C" int __io_putchar(int ch)
{
    while (!(UART4->ISR & USART_ISR_TXE)) {}
    UART4->TDR = ch;
    return ch;
}

int main()
{
    printf("Hello World");
    UART_Application Uart{};
    Uart.init();

    Uart.loop();
}
