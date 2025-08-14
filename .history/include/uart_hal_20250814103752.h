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
    void loop();

private:
};