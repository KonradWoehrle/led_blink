#include "led_hal.h"

LedHAL_GPIO::LedHAL_GPIO(uint8_t ledPin) : ledPin_c(ledPin)
{

}

void LedHAL_GPIO::ActivateClock()
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;    // new value = (old value | 0x00000001)
}

void LedHAL_GPIO::ConfigurateAsOutput()
{
    // reset moder -> set moder -> output
    GPIOA->MODER    &= ~(BIT_MASK_2_BIT << (GpioConfig::PA5_c * 2));
    GPIOA->MODER    |= (GpioConfig::ModeOutput  << (GpioConfig::PA5_c * 2));

    // set otyper -> push/pull
    GPIOA->OTYPER   &= ~(BIT_MASK_1_BIT << GpioConfig::PA5_c);

    // reset ospeedr -> set ospeedr -> high speed
    GPIOA->OSPEEDR  &= ~(BIT_MASK_2_BIT << (GpioConfig::PA5_c * 2));
    GPIOA->OSPEEDR  |= (GpioConfig::SpeedHigh << (GpioConfig::PA5_c * 2));

    // reset pupdr -> set pupdr -> deactivate (no pull)
    GPIOA->PUPDR    &= ~(BIT_MASK_2_BIT << (GpioConfig::PA5_c * 2));
    GPIOA->PUPDR    |= (GpioConfig::NoPull << (GpioConfig::PA5_c * 2));
}

void LedHAL_GPIO::Set(bool state)
{
    if(state)
    {
        GPIOA->ODR |= (BIT_MASK_1_BIT << 5);     // turn on
    }
    else
    {
        GPIOA->ODR &= (BIT_MASK_1_BIT << 5);
    }
}