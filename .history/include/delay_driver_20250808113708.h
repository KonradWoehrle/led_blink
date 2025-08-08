#include "delay_hal.h"

class DelayDriver
{
public:
    DelayDriver();
    ~DelayDriver() = default;

    void delay_1s(uint64_t pause);
    void delay_1ms(uint64_t pause);

private:
    Delay_HAL Delay;
};