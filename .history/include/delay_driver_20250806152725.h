#include <stdint.h>

class Delay
{
public:
    Delay() = default;
    ~Delay() = default;

    void delay(uint32_t pause = 100000);
};