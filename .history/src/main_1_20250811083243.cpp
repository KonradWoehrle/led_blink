#include "led_application.h"

constexpr uint8_t PA5 = 5;      // led pin
constexpr uint8_t PC13 = 13;    // button pin

int main()
{
    BlinkLedApplication BlinkLight{PA5, PC13};
    BlinkLight.init();

    BlinkLight.PressButtonForLED();
}
