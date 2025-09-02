#include "wogtest/gtest.h"
#include "led_hal.h"


TEST(LedHAL_GPIO_Test, ActivateClock_activates_Clock)
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    EXPECT_EQ(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN);
}
/*
TEST(LedHAL_GPIO_Test, ConfugurateAsOutput_resets_moder)
{

}

TEST(LedHAL_GPIO_Test, TurnOnSetsLedOn)
{
    LedDriver_GPIO led(5);
    led.init();
    led.turnOn();
    EXPECT_TRUE(led.getLedState());
}

TEST(LedHAL_GPIO_Test, SwitchStateTogglesLed)
{
    LedDriver_GPIO led(5);
    led.init();
    bool initial = led.getLedState();

    led.switchState();
    EXPECT_NE(led.getLedState(), initial);

    led.switchState();
    EXPECT_EQ(led.getLedState(), initial);
}
*/

// EXPECT_FALSE
