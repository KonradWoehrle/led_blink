#include "uart_hal.h"


void UartHAL::init()
{
    // activate tact
    RCC->APB1ENR1 |= RCC_APB1ENR1_UART4EN;

    // configurate GPIO
    GPIOA->MODER   &= ~(GPIO_MODER_MODE0_Msk | GPIO_MODER_MODE1_Msk);               // reset
    GPIOA->MODER   |=  (GPIO_MODER_MODE0_1 | GPIO_MODER_MODE1_1);                   // AF mode
    GPIOA->AFR[0]  |=  (8 << GPIO_AFRL_AFSEL0_Pos) | (8 << GPIO_AFRL_AFSEL1_Pos);   // AF8 for UART4

    // set baudrate
    UART4->BRR = UART4_CLK_FREQ / UART4_BAUDRATE;

    // activate Rx Tx
    UART4->CR1 |= USART_CR1_TE | USART_CR1_RE;

    // activate UART
    UART4->CR1 |= USART_CR1_UE;
}

void UartHAL::sendByte(char c)
{

}

void UartHAL::sendBuffer(const char* data, size_t len)
{

}