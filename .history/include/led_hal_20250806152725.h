#include <cstdint>
#include "stm32l452xx.h"

// HAL for stm32nucleo L452RE

#define BIT_MASK_1_BIT  0x01
#define BIT_MASK_2_BIT  0x03
#define BIT_MASK_3_BIT  0x07
#define BIT_MASK_4_BIT  0x0F

namespace GpioConfig
{
    constexpr uint32_t ModeInput        = 0x00;
    constexpr uint32_t ModeOutput       = 0x01;
    constexpr uint32_t OTypePushPull    = 0x00;
    constexpr uint32_t SpeedHigh        = 0x03;
    constexpr uint32_t NoPull           = 0x00;
}

namespace GpioRegister
{
    constexpr auto Moder    = &GPIOA->MODER;
    constexpr auto Otyper   = &GPIOA->OTYPER;
    constexpr auto Ospeedr  = &GPIOA->OSPEEDR;
    constexpr auto Pupdr    = &GPIOA->PUPDR;
}

class LedHAL_GPIO
{
public:
    LedHAL_GPIO(uint8_t ledPin);
    ~LedHAL_GPIO() = default;

    void ActivateClock();
    void ConfigurateAsOutput();
    void SetState(bool state);
    bool GetState() const;

private:
    uint8_t PortA_Pin_c;
};