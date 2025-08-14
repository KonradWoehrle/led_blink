#include "config.h"
#include "led_application.h"
#include "led_application.cpp"

int main()
{
    BlinkLedApplication BlinkLight{LedPin, ButtonPin};
    BlinkLight.init();

    BlinkLight.LedBlink();
}
