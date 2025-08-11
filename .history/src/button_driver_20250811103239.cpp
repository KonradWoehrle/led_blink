#include "button_driver.h"



ButtonDriver::ButtonDriver(uint8_t ButtonPin) : ButtonHAL(ButtonPin)
{

}
void ButtonDriver::init()
{
    ButtonHAL.ActivateClock();
    ButtonHAL.ConfigurateAsButton();
}

bool ButtonDriver::IsPressed()
{
    return ButtonHAL.CheckStatusButton();
}