#include "wogtest/gtest.h"
#include "led_hal.h"

LedHAL_GPIO TestObject(LedPin);

TEST(LedHAL_GPIO_Test, ActivateClock_activates_Clock)
{
    TestObject.ActivateClock();
    EXPECT_EQ(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN);
}

TEST(LedHAL_GPIO_Test, GetPortPin)
{
    EXPECT_EQ(TestObject.GetPortPin(), LedPin);
}

TEST(LedHAL_GPIO_Test, SetStateFalse)
{
    TestObject.ConfigureAsOutput();
    TestObject.SetState(false);
    EXPECT_FALSE(TestObject.GetStateForTest());
    EXPECT_EQ((GPIOA->ODR & (BIT_MASK_1_BIT << LedPin)), 0);
}

TEST(LedHAL_GPIO_Test, SetStateTrue)
{
    TestObject.SetState(true);
    EXPECT_TRUE(TestObject.GetStateForTest());
    EXPECT_EQ((GPIOA->ODR & (BIT_MASK_1_BIT << LedPin)), BIT_MASK_1_BIT << LedPin);
}