#include <stdint.h>
#include "delay_hal.h"

class Delay
{
public:
    Delay() = default;
    ~Delay() = default;

    void delay_1s(uint64_t pause);
    void delay_1ms(uint64_t pause);
};