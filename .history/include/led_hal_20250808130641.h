#include "config.h"

class LedHAL_GPIO
{
public:
    LedHAL_GPIO(uint8_t ledPin);
    ~LedHAL_GPIO() = default;

    void ActivateClock();
    void ConfigurateAsOutput();
    void SetState(bool state);
    bool GetState() const;

private:
    uint8_t PortA_Pin_c;
};