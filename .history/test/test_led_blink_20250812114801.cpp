#include <gtest.h>
#include "led_application.h"
#include "button_driver.h"
#include "delay_driver.h"
#include "led_driver_GPIO.h"
#include <vector>
#include <string>


class TestButtonDriver : public ButtonDriver
{
    TestButtonDriver() = default;
public:
    int counter = 0;
    bool IsPressed() override
    {
        return ++counter >= 3;
    }
};

class TestDelayDriver : public DelayDriver
{
    TestDelayDriver() = default;
public:
    std::vector<uint64_t> delays;
    void delay_1ms(uint64_t ms) override
    {
        delays.push_back(ms);
    }
};

class TestLedDriver : public LedDriver_GPIO
{
public:
    std::vector<std::string> actions;
    void turnOn() override
    {
        actions.push_back("on");
    }
    void turnOff() override
    {
        actions.push_back("off");
    }
};

TEST(BlinkLedTest, RunsThreeCyclesThenStops)
{
    TestLedDriver led;
    TestDelayDriver delay;
    TestButtonDriver button;

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
