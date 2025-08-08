#include "button_hal.h"

void ButtonHAL_GPIO::ActivateClock()
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
};

void ButtonHAL_GPIO::ConfigurateAsButton(uint8_t PortA_Pin_c)
{
    // set moder -> input
    GPIOC->MODER    &= ~(BIT_MASK_2_BIT << (PortA_Pin_c * 2));
}

bool ButtonHAL_GPIO::CheckStatusButton()
{
    // check status of butten
    return !((GPIOC->IDR & BIT_MASK_1_BIT << PortA_Pin_c));
}
