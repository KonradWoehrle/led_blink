#pragma once

#include "config.h"
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <cstdarg>

class UartHAL
{
public:
    UartHAL() = default;
    ~UartHAL() = default;

    void init();
    void sendByte(uint8_t byte);
    void sendBuffer(const char* data, size_t len);
    char receiveByte();
    char* receiveBuffer();
    void flushRX();
private:
};