#include "../test/test_target_hal.cpp"
#include "uart_driver.h"

extern UART_Driver AppUart;

int main()
{
    AppUart.init();

    // printf("Testausgabe\n");

    while(1)
    {
        RUN_ALL_TESTS();
    }

    return 0;
}