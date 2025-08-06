#include <cstdint>
#include "stm32l452xx.h"

// HAL for stm32nucleo L452RE

class LedHAL_GPIO
{
public:
    LedHAL_GPIO();
    ~LedHAL_GPIO() = default;

    void ActivateClock();

private:

};