#include "define.h"

class ButtonHAL_GPIO
{
public:
    ButtonHAL_GPIO();
    ~ButtonHAL_GPIO() = default;

    void ActivateClock();
    void ConfigurateAsButton(uint8_t PortA_Pin_c);
    bool CheckStatusButton();

private:
};