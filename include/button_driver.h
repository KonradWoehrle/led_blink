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
    uint8_t ButtonPin_c;        // GPIO pin for the Button
    ButtonHAL_GPIO  ButtonHAL;
};