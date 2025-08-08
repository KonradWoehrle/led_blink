#include "led_driver_GPIO.h"
#include "delay_driver.h"
#include "button_driver.h"

class BlinkLedApplication
{
    public:
    BlinkLedApplication(uint8_t LedPin, uint8_t ButtonPin);
    ~BlinkLedApplication() = default;

    void init();
    void LedBlink(uint64_t durationOn = 100, uint64_t durationOff = 900);
    void PressButtonForLED();

private:
    uint8_t LedPin_c;
    LedDriver_GPIO Led;
    DelayDriver delay;
    ButtonDriver Button;
};