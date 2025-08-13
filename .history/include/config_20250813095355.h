#pragma once

#ifndef UNIT_TEST
#include "stm32l452xx.h"
#endif

#include <stdint.h>

typedef double f64_t;

constexpr uint8_t LedPin = 5;      // led pin
constexpr uint8_t ButtonPin = 13;    // button pin

#define BIT_MASK_1_BIT  0x01
#define BIT_MASK_2_BIT  0x03
#define BIT_MASK_3_BIT  0x07
#define BIT_MASK_4_BIT  0x0F

// HAL for stm32nucleo L452RE
namespace GpioConfig
{
    constexpr uint32_t ModeInput        = 0x00;
    constexpr uint32_t ModeOutput       = 0x01;
    constexpr uint32_t OTypePushPull    = 0x00;
    constexpr uint32_t SpeedHigh        = 0x03;
    constexpr uint32_t NoPull           = 0x00;
}
