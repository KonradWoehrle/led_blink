#include <gtest.h>
#include "led_application.h"
#include "button_driver.h"
#include "delay_driver.h"
#include "led_driver_GPIO.h"
#include <vector>
#include <string>



TEST(BlinkLedTest, RunsThreeCyclesThenStops)
{
    ButtonDriver button(13);
    DelayDriver delay();
    LedDriver led(5);


    BlinkLedApplication app;
    app.Led = led;
    app.delay = delay;
    app.Button = button;

    app.LedBlink(100, 200);

    EXPECT_EQ(led.actions.size(), 6); // 3x on + 3x off
    EXPECT_EQ(delay.delays.size(), 6); // 3x on + 3x off
    EXPECT_EQ(delay.delays[0], 100);
    EXPECT_EQ(delay.delays[1], 200);
}
