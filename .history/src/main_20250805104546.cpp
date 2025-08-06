#include "stm32l4xx_hal.h"

int main() {
    HAL_Init(); // Initialisiere HAL

    __HAL_RCC_GPIOA_CLK_ENABLE(); // Aktiviere GPIOA Clock

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_5; // z. B. PA5 (oft mit LED verbunden)
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    while (1) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // LED toggeln
        HAL_Delay(500); // 500 ms warten
    }
}
