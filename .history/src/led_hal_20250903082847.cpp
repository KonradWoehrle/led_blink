#include "led_hal.h"

LedHAL_GPIO::LedHAL_GPIO(uint8_t ledPin) : PortA_Pin_c(ledPin)
{
    state_c = false;
}

void LedHAL_GPIO::ActivateClock()
{
    // Enables the clock for GPIOA peripheral to allow configuration and usage of GPIOA pins.
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
}

void LedHAL_GPIO::ConfigureAsOutput()
{
    // reset moder -> set moder -> output
    GPIOA->MODER    &= ~(BIT_MASK_2_BIT << (PortA_Pin_c * 2));
    GPIOA->MODER    |= (GpioConfig::ModeOutput  << (PortA_Pin_c * 2));

    // set otyper -> push/pull
    GPIOA->OTYPER   &= ~(BIT_MASK_1_BIT << PortA_Pin_c);

    // reset ospeedr -> set ospeedr -> high speed
    GPIOA->OSPEEDR  &= ~(BIT_MASK_2_BIT << (PortA_Pin_c * 2));
    GPIOA->OSPEEDR  |= (GpioConfig::SpeedHigh << (PortA_Pin_c * 2));

    // reset pupdr -> set pupdr -> deactivate (no pull)
    GPIOA->PUPDR    &= ~(BIT_MASK_2_BIT << (PortA_Pin_c * 2));
    GPIOA->PUPDR    |= (GpioConfig::NoPull << (PortA_Pin_c * 2));
}

void LedHAL_GPIO::SetState(bool state)
{
    if(state)
    {
        GPIOA->ODR |= (BIT_MASK_1_BIT << PortA_Pin_c);     // turn on
        state_c = true;
    }
    else
    {
        GPIOA->ODR &= ~(BIT_MASK_1_BIT << PortA_Pin_c);     // turn off
        state_c = false;
    }
}

bool LedHAL_GPIO::GetState() const
{
    return (GPIOA->ODR & (BIT_MASK_1_BIT << PortA_Pin_c)) != 0;
}

bool LedHAL_GPIO::GetStateForTest() const
{
    return state_c;
}

uint8_t LedHAL_GPIO::GetPortPin() const
{
    return PortA_Pin_c;
}
