#include "button_driver.h"



ButtonDriver::ButtonDriver(uint8_t ButtonPin) : ButtonHAL(ButtonPin), delay()
{

}
void ButtonDriver::init()
{
    ButtonHAL.ActivateClock();
    ButtonHAL.ConfigurateAsButton();
}

bool ButtonDriver::IsPressed()
{
    if(retVal_c != ButtonHAL.CheckStatusButton())
    {
        while(retVal_c != ButtonHAL.CheckStatusButton());
        delay.delay_1ms(50);
        retVal_c = !retVal_c;
    }

    return retVal_c;
}