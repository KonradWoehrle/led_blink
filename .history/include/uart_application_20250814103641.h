#pragma once

#include "uart_hal.h"

class UARD_Application
{
    public:
    UARD_Application(uint8_t LedPin, uint8_t ButtonPin);
    ~UARD_Application() = default;

    void init();
    void LedBlink(uint64_t durationOn = 100, uint64_t durationOff = 900);
    void PressButtonForLED();

private:
    UartHAL Uart;

};
