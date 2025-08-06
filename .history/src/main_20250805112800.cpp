#include "stm32l4xx_hal.h"

void SystemClock_Config(void);

int main(void) {
    HAL_Init();
    SystemClock_Config();  // Falls nötig für Delay-Funktion

    __HAL_RCC_GPIOA_CLK_ENABLE();  // Takt für GPIOA aktivieren

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_5;  // PA5 = LD2 auf Nucleo
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    while (1) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);  // LED toggeln
        HAL_Delay(500);  // 500 ms warten
    }

    return 0;
}
