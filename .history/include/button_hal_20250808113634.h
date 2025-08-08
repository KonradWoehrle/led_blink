#include "define.h"

class ButtonHAL_GPIO
{
public:
    ButtonHAL_GPIO();
    ~ButtonHAL_GPIO() = default;

    void ActivateClock();
    void ConfigurateAsButton(uint8_t);
    bool CheckStatusButton();

private:
    uint8_t PortC_Pin_c = 13;
};