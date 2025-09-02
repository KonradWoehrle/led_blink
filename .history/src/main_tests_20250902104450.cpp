#include "../test/test_target_hal.cpp"

extern UART_Application AppUart;

int main()
{
    AppUart.init();

    printf("Testausgabe");

    return RUN_ALL_TESTS();
}