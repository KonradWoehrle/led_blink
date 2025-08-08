#include "button_hal.h"

// enum class ButtonState : bool {Low = 0, High = 1};

class ButtonDriver
{
public:
    ButtonDriver(uint8_t ButtonPin);
    ~ButtonDriver() = default;

    void init();
    bool IsPressed();

private:
    ButtonHAL_GPIO  ButtonHAL;
};