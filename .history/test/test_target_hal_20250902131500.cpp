#include "wogtest/gtest.h"
#include "led_hal.h"

LedHAL_GPIO TestObject(LedPin);

TEST(LedHAL_GPIO_Test, ActivateClock_activates_Clock)
{
    TestObject.ActivateClock();
    EXPECT_EQ(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN);
}

TEST(LedHAL_GPIO_Test, SetStateFalse)
{
    TestObject.SetState(false);
    //EXPECT_FALSE(TestObject.GetStateForTest());
    EXPECT_EQ(GPIOA->ODR & (BIT_MASK_1_BIT << LedPin), 0);
}

TEST(LedHAL_GPIO_Test, SetStateTrue)
{
    TestObject.SetState(true);
    //EXPECT_TRUE(TestObject.GetStateForTest());
    EXPECT_EQ(GPIOA->ODR & (BIT_MASK_1_BIT << LedPin), 1);
}
/*
TEST(LedHAL_GPIO_Test, GetState)
{
    TestObject.SetState(true);
    EXPECT_TRUE(TestObject.GetStateForTest());
    EXPECT_EQ(GPIOA->ODR &= (BIT_MASK_1_BIT << LedPin), false);
}
/*
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
