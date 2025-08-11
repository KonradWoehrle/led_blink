/******************************************************************************
 * @file     main_test.cpp
 * @version  V2.0f
 * @date     2nd of Feb 2024
 * Author    Remo Markgraf
 * Copyright (C) 2025 MicroConsult Academy GmbH. All rights reserved.
 * Originally published (C) 2023 MicroConsult GmbH. All rights reserved.
 *****************************************************************************/
#include "gtest/gtest.h"
//#include "configHardware.h"

GTEST_API_ int main(void)
{
	//configHardware();

#ifdef __cplusplus
    testing::InitGoogleTest();  //not supported in C environment
#endif

    return RUN_ALL_TESTS();
}
