#include "led_application.h"

constexpr uint8_t PA5 = 5;

int main()
{
    BlinkLedApplication BlinkLight{PA5};
    BlinkLight.init();

    while(1)
    {
        BlinkLight.LedBlink();
    }
}
