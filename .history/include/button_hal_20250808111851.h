#include "define.h"

class ButtonHAL_GPIO
{
public:
    ButtonHAL_GPIO(uint8_t ButtonPin);
    ~ButtonHAL_GPIO() = default;

    void ActivateClock();
    void ConfigurateAsButton(uint8_t PortA_Pin_c);
    bool CheckStatusButton();

private:
    uint8_t PortA_Pin_c = 13;
};