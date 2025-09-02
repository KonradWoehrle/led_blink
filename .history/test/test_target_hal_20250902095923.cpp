#include "wogtest/gtest.h"
#include "led_hal.h"
#include "uart_driver.h"
#include "uart_hal.h"


TEST(LedDriverGPIOTest, InitSetsLedOff)
{
    LedDriver_GPIO led(5);
    led.init();
    EXPECT_FALSE(led.getLedState());  // Nach Init soll LED aus sein
}

TEST(LedDriverGPIOTest, TurnOnSetsLedOn)
{
    LedDriver_GPIO led(5);
    led.init();
    led.turnOn();
    EXPECT_TRUE(led.getLedState());
}

TEST(LedDriverGPIOTest, TurnOffSetsLedOff)
{
    LedDriver_GPIO led(5);
    led.init();
    led.turnOn();
    led.turnOff();
    EXPECT_FALSE(led.getLedState());
}

TEST(LedDriverGPIOTest, SwitchStateTogglesLed)
{
    LedDriver_GPIO led(5);
    led.init();
    bool initial = led.getLedState();

    led.switchState();
    EXPECT_NE(led.getLedState(), initial);

    led.switchState();
    EXPECT_EQ(led.getLedState(), initial);
}
