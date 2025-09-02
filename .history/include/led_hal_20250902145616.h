#pragma once

#include "config.h"

class LedHAL_GPIO
{
public:
    LedHAL_GPIO(uint8_t ledPin);
    ~LedHAL_GPIO() = default;

    void ActivateClock();
    void ConfigureAsOutput();
    void SetState(bool state);
    bool GetState() const;
    bool GetStateForTest() const;
    uint8_t GetPortPin() const;

private:
    uint8_t PortA_Pin_c;
    bool state_c;
};