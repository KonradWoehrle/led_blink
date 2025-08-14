#pragma once

#include "config.h"

class UartHAL
{
public:
    UartHAL() = default;
    ~UartHAL() = default;

    void init();
    void sendByte(char c);
    void sendBuffer(const char* data, size_t len);

private:
};