#include "config.h"
#include "led_application.h"

int main()
{
    BlinkLedApplication BlinkLight{LedPin, ButtonPin};
    BlinkLight.init();

    BlinkLight.PressButtonForLED();

    return 0;
}
