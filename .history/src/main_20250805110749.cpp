#include "stm32l4xx_hal.h"

#define RCC_AHB1ENR   (*((volatile uint32_t*)0x40023830))
#define GPIOA_MODER   (*((volatile uint32_t*)0x40020000))
#define GPIOA_ODR     (*((volatile uint32_t*)0x40020014))

int main() {
    HAL_Init();

        RCC_AHB1ENR |= (1 << 0);        // Enable GPIOA clock
    GPIOA_MODER |= (1 << (5 * 2));  // Set PA5 as output

    while (1) {
        GPIOA_ODR ^= (1 << 5);      // Toggle PA5
        for (volatile int i = 0; i < 100000; ++i); // crude delay
    }
    
    return 0;
}
