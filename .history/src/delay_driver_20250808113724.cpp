#include "delay_driver.h"

DelayDriver::DelayDriver() : Delay()
{

}

void DelayDriver::delay_1ms(uint64_t pause)
{
    Delay.delay(pause);
}

void DelayDriver::delay_1s(uint64_t pause)
{
    pause *= 1000;

    Delay.delay(pause);
}