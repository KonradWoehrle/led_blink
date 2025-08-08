#include <stdint.h>

typedef double f64_t;

class Delay_HAL
{
public:
    Delay_HAL() = default;
    ~Delay_HAL() = default;

    void delay(uint64_t pause);

private:
    f64_t delay_factor_c = 1687.5;
};