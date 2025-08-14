#include "uart_hal.h"


void UartHAL::init()
{
    RCC->APB1ENR1 |= RCC_APB1ENR1_UART4EN;
    
}

void UartHAL::sendByte(char c)
{

}

void UartHAL::sendBuffer(const char* data, size_t len)
{

}