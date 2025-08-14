#include "uart_hal.h"


void UartHAL::init()
{
    // activate UART 4
    RCC->APB1ENR1 |= RCC_APB1ENR1_UART4EN;

    // set baudrate
    UART4->BRR = UART4_CLK_FREQ / UART4_BAUDRATE;

    // activate UART
    UART4->CR1 |= USART_CR1_UE;

    // activate Rx Tx
    UART4->CR1 |= USART_CR1_TE | USART_CR1_RE;
}

void UartHAL::sendByte(char c)
{

}

void UartHAL::sendBuffer(const char* data, size_t len)
{

}