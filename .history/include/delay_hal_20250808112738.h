#include "define.h"

class Delay_HAL
{
public:
    Delay_HAL() = default;
    ~Delay_HAL() = default;

    void delay(uint64_t pause);

private:
    uint64_t delay_factor_c = 290;
};