#include "button_driver.h"



ButtonDriver::ButtonDriver(uint8_t ButtonPin) : ButtonPin_c(ButtonPin)
{

}
void ButtonDriver::init()
{
    ButtonHAL.ActivateClock();
    ButtonHAL.ConfigurateAsButton(ButtonPin_c);
}

bool ButtonDriver::IsPressed()
{
    return ButtonHAL.CheckStatusButton();
}