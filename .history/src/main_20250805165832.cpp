#include "stm32l452xx.h"
#define GPIOA_PIN 5
void delay(volatile uint32_t count)
{
    while (count--);
}

int main()
{
    // 1. GPIOA Clock aktivieren
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;    // neuer Wert = (alter Wert | 0x00000001)

    // 2. PA5 als Output konfigurieren
    GPIOA->MODER &= ~(3 << (GPIOA_PIN * 2));       // Clear MODER5
    GPIOA->MODER |=  (1 << (GPIOA_PIN * 2));       // Set MODER5 auf Output
    GPIOA->OTYPER &= ~(1 << GPIOA_PIN);            // Push-Pull
    GPIOA->OSPEEDR |=  (3 << (GPIOA_PIN * 2));     // High Speed
    GPIOA->PUPDR  &= ~(3 << (GPIOA_PIN * 2));      // No Pull-up/down

    // 3. Endlosschleife: LED toggeln
    while (1)
    {
        GPIOA->ODR ^= (1 << 5);            // Toggle PA5
        delay(150000);                     // Primitive Delay
    }
}
