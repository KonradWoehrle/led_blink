#include "led_application.h"

constexpr uint8_t PA5 = 5;

int main()
{
    BlinkLedApplication BlinkLight{PA5};
    BlinkLight.init();

    while(1)
    {
    LedDriver_GPIO Led{PA5};
    Delay delay{};


    Led.turnOn();
    delay.delay(500000);
    Led.turnOff();
    delay.delay(500000);
   }
}
