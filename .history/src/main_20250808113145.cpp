#include "led_application.h"

constexpr uint8_t PA5 = 5;
constexpr uint8_t PC13 = 13;

int main()
{
    BlinkLedApplication BlinkLight{PA5};
    BlinkLight.init();

    BlinkLight.LedBlink();
}
