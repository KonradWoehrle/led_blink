#include "led_application.h"

constexpr uint8_t PA5 = 5;

int main()
{
    BlinkLedApplication BlinkLight{PA5};
    BlinkLight.init();
    LedDriver_GPIO Led{PA5};
    Delay delay{};

    while(1)
    {


    Led.turnOn();
    delay.delay(500000);
    Led.turnOff();
    delay.delay(500000);
   }
}
