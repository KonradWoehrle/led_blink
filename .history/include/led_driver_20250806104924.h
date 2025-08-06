#include <cstdint>

class LedDriver
{
public:
    LedDriver() = default;
    virtual ~LedDriver() = default;

    virtual void init() = 0;
    virtual void setBrightness(int brightness) = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool isOn() const = 0;

    private:
    bool ledState = false;      // State of the LED
    uint32_t ledPin = 0;        // GPIO pin for the LED
};