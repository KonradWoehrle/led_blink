#include "led_driver_GPIO.h"
#include "delay_driver.h"

class BlinkLedApplication
{
    public:
    BlinkLedApplication(uint8_t);
    ~BlinkLedApplication() = default;

    void init();
    void LedBlink(uint64_t durationOn = 100, uint64_t durationOff = 900);

private:
    uint8_t LedPin_c;
    LedDriver_GPIO Led;
    Delay delay;
};