#include "led_driver_GPIO.h"
#include "delay_driver.h"

class BlinkLedApplication
{
    public:
    BlinkLedApplication(uint8_t);
    ~BlinkLedApplication() = default;

    void init();
    void LedBlink(uint8_t durationOn = 50000, uint8_t durationOff = 1000000);

private:
    uint8_t LedPin_c;
};