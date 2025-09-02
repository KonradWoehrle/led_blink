#include "wogtest/gtest.h"
#include "led_hal.h"
#include "uart_driver.h"
#include "uart_hal.h"


TEST(LedHAL_GPIO_Test, InitSetsLedOff)
{
    led.init();
    EXPECT_FALSE(led.getLedState());  // Nach Init soll LED aus sein
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
