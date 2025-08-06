#include <cstdint>
#include "led_hal.h"

enum class LedState : bool {Off = 0, On = 1};

class LedDriver_GPIO
{
public:
    LedDriver_GPIO(uint8_t ledPin);
    ~LedDriver_GPIO() = default;

    void init();
    void turnOn();
    void turnOff();
    // void toggle();
    uint8_t getLedPin() const;
    void setLedPin(uint8_t ledPin);
    bool getLedState() const;

    private:
    bool ledState_c = false;     // State of the LED
    uint8_t ledPin_c = 0;        // GPIO pin for the LED
};