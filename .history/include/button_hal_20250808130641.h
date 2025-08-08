#include "config.h"

class ButtonHAL_GPIO
{
public:
    ButtonHAL_GPIO(uint8_t PortC_Pin);
    ~ButtonHAL_GPIO() = default;

    void ActivateClock();
    void ConfigurateAsButton();
    bool CheckStatusButton();

private:
    uint8_t PortC_Pin_c;
};