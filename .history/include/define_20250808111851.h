#include <stm32l452xx.h>
#include <stdint.h>

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
