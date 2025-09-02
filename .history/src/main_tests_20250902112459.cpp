#include "../test/test_target_hal.cpp"
#include "uart_driver.h"

extern UART_Application AppUart;

int main()
{
    AppUart.init();

    // printf("Testausgabe\n");

    return RUN_ALL_TESTS();
}