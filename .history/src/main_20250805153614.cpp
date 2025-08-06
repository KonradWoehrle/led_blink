#include "stm32l452xx.h"

void delay(volatile uint32_t count)
{
    while (count--) {
    }
}

int main()
{
    // 1. GPIOA Clock aktivieren
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    // 2. PA5 als Output konfigurieren
    GPIOA->MODER &= ~(3 << (5 * 2));       // Clear MODER5
    GPIOA->MODER |=  (1 << (5 * 2));       // Set MODER5 auf Output
    GPIOA->OTYPER &= ~(1 << 5);            // Push-Pull
    GPIOA->OSPEEDR |=  (3 << (5 * 2));     // High Speed
    GPIOA->PUPDR  &= ~(3 << (5 * 2));      // No Pull-up/down

    // 3. Endlosschleife: LED toggeln
    while (1)
    {
        GPIOA->ODR ^= (1 << 5);            // Toggle PA5
        delay(100000);                     // Primitive Delay
    }
}
