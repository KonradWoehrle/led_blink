#include "uart_hal.h"


void UartHAL::init()
{
    // activate tact
    RCC->APB1ENR1 |= RCC_APB1ENR1_UART4EN;
    RCC->AHB2ENR  |= RCC_AHB2ENR_GPIOAEN;

    // configurate GPIO
    GPIOA->MODER   &= ~(GPIO_MODER_MODE0_Msk | GPIO_MODER_MODE1_Msk);               // reset
    GPIOA->MODER   |=  (GPIO_MODER_MODE0_1 | GPIO_MODER_MODE1_1);                   // AF mode
    GPIOA->AFR[0] &= ~((0xF << GPIO_AFRL_AFSEL0_Pos) | (0xF << GPIO_AFRL_AFSEL1_Pos));
    GPIOA->AFR[0]  |=  (8 << GPIO_AFRL_AFSEL0_Pos) | (8 << GPIO_AFRL_AFSEL1_Pos);   // AF8 for UART4

    // set baudrate
    UART4->BRR = UART4_CLK_FREQ/UART4_BAUDRATE;
    //UART4->BRR = (uint32_t)((float)UART4_CLK_FREQ / UART4_BAUDRATE + 0.5f);

    // activate UART
    UART4->CR1 |= USART_CR1_UE;

    // activate Rx Tx
    UART4->CR1 |= USART_CR1_TE | USART_CR1_RE;

}

void UartHAL::sendByte(uint8_t byte)
{
    while (!(UART4->ISR & USART_ISR_TXE))
    {
        // wait until transmit data register is empty
    }

    // send byte
    UART4->TDR = byte;

}   // funktioniert

void UartHAL::sendBuffer(const char* data, size_t len)
{
    for(uint32_t i = 0; i < len; i++)
    {
        while (!(UART4->ISR & USART_ISR_TXE))
        {
            // wait until transmit data register is empty
        }

        // send byte
        UART4->TDR = data[i];
    }
}

char UartHAL::receiveByte()
{
    // Wait until a byte has been received
    while (!(UART4->ISR & USART_ISR_RXNE))
    {
        // RXNE = Receive data register not empty
    }

    // Return the received byte
    return UART4->RDR;
}

char* UartHAL::receiveBuffer()
{
    static char buffer[128];
    uint32_t index = 0;

    while (index < sizeof(buffer) - 1)
    {
        uint32_t timeout = 100000;

        while (!(UART4->ISR & USART_ISR_RXNE) && (timeout > 0))
        {
            timeout--;
        }

        if (timeout == 0) break;

        buffer[index++] = UART4->RDR;

    }
    this->flushRX();    // empty RX

    buffer[index] = '\0';
    return buffer;
}

void UartHAL::flushRX()
{
    // delete error flaggs
    if (UART4->ISR & USART_ISR_ORE)
        UART4->ICR |= USART_ICR_ORECF;

    if (UART4->ISR & USART_ISR_FE)
        UART4->ICR |= USART_ICR_FECF;

    if (UART4->ISR & USART_ISR_NE)
        UART4->ICR |= USART_ICR_NCF;
/*
    // delete fifo
    while (UART4->ISR & USART_ISR_RXNE)
    {
        volatile char dump = UART4->RDR; // Zeichen verwerfen
        dump += 1;
    }
*/}