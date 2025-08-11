/******************************************************************************
 * @project  wogtest
 * @file     sample_test.cpp
 * @version  V2.0f
 * @date     4th of December 2023
 * Author    Remo Markgraf
 * Copyright (C) 2025 MicroConsult Academy GmbH. All rights reserved.
 * Originally published (C) 2023 MicroConsult GmbH. All rights reserved.
 *****************************************************************************/
#include "gtest/gtest.h"

//#define WOGTEST_EXCEPTION   // -fexceptions needs to be set in compiler misc options
//#define WOGTEST_FAIL

TEST(foo, ASSERT_TRUE) {
  uint32_t i = 1;
  ASSERT_TRUE(i);  // pass!
  ASSERT_TRUE(42); // pass!
#ifdef WOGTEST_FAIL
  ASSERT_TRUE(0);  // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_FALSE) {
  uint32_t i = 0;
  ASSERT_FALSE(i); // pass!
#ifdef WOGTEST_FAIL
  ASSERT_FALSE(1); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_EQ) {
  uint32_t a = 42;
  uint32_t b = 42;
  ASSERT_EQ(a, b);     // pass!
  ASSERT_EQ(a, 42);    // pass!
  ASSERT_EQ(42, b);    // pass!
  ASSERT_EQ(42, 42);   // pass!
#ifdef WOGTEST_FAIL
  ASSERT_EQ(a, b + 1); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_NE) {
  uint32_t a = 42;
  uint32_t b = 13;
  ASSERT_NE(a, b);   // pass!
  ASSERT_NE(a, 27);  // pass!
  ASSERT_NE(69, b);  // pass!
  ASSERT_NE(42, 13); // pass!
#ifdef WOGTEST_FAIL
  ASSERT_NE(a, 42);  // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_LT) {
  uint32_t a = 13;
  uint32_t b = 42;
  ASSERT_LT(a, b);   // pass!
  ASSERT_LT(a, 27);  // pass!
  ASSERT_LT(27, b);  // pass!
  ASSERT_LT(13, 42); // pass!
#ifdef WOGTEST_FAIL
  ASSERT_LT(b, a);   // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_LE) {
  uint32_t a = 13;
  uint32_t b = 42;
  ASSERT_LE(a, b);   // pass!
  ASSERT_LE(a, 27);  // pass!
  ASSERT_LE(a, 13);  // pass!
  ASSERT_LE(27, b);  // pass!
  ASSERT_LE(42, b);  // pass!
  ASSERT_LE(13, 13); // pass!
  ASSERT_LE(13, 42); // pass!
#ifdef WOGTEST_FAIL
  ASSERT_LE(b, a);   // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_GT) {
  uint32_t a = 42;
  uint32_t b = 13;
  ASSERT_GT(a, b);   // pass!
  ASSERT_GT(a, 27);  // pass!
  ASSERT_GT(27, b);  // pass!
  ASSERT_GT(42, 13); // pass!
#ifdef WOGTEST_FAIL
  ASSERT_GT(b, a);   // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_GE) {
  uint32_t a = 42;
  uint32_t b = 13;
  ASSERT_GE(a, b);   // pass!
  ASSERT_GE(a, 27);  // pass!
  ASSERT_GE(a, 13);  // pass!
  ASSERT_GE(27, b);  // pass!
  ASSERT_GE(42, b);  // pass!
  ASSERT_GE(13, 13); // pass!
  ASSERT_GE(42, 13); // pass!
#ifdef WOGTEST_FAIL
  ASSERT_GE(b, a);   // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_STREQ) {
  const char* a = "foo";
  const char* b = "bar";
  const char* c = "bar";
  const char* d = "bAr";
  const char* e = "barrel";
  ASSERT_STREQ(a, a); // pass!
  ASSERT_STREQ(b, b); // pass!
  ASSERT_STREQ(b, c); // pass!
#ifdef WOGTEST_FAIL
  ASSERT_STREQ(a, b); // fail!
  ASSERT_STREQ(b, d); // did fail if previous line did not abort testing!
  ASSERT_STREQ(b, e); // did fail if previous line did not abort testing!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_STRNE) {
  const char* a = "foo";
  const char* b = "bar";
  ASSERT_STRNE(a, b); // pass!
#ifdef WOGTEST_FAIL
  ASSERT_STRNE(a, a); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_STRCASEEQ) {
  const char* a = "foo";
  const char* b = "bar";
  const char* c = "bAr";
  ASSERT_STRCASEEQ(a, a); // pass!
  ASSERT_STRCASEEQ(b, b); // pass!
  ASSERT_STRCASEEQ(b, c); // pass!
#ifdef WOGTEST_FAIL
  ASSERT_STRCASEEQ(a, b); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_STRCASENE) {
  const char* a = "foo";
  const char* b = "bar";
  const char* c = "bAr";
  ASSERT_STRCASENE(a, b); // pass!
#ifdef WOGTEST_FAIL
  ASSERT_STRCASENE(a, a); // fail!
  ASSERT_STRCASENE(b, c); // did fail if previous line did not abort! 
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_TRUE) {
  uint32_t i = 1;
  EXPECT_TRUE(i);  // pass!
  EXPECT_TRUE(42); // pass!
#ifdef WOGTEST_FAIL
  EXPECT_TRUE(0);  // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_FALSE) {
  uint32_t i = 0;
  EXPECT_FALSE(i); // pass!
#ifdef WOGTEST_FAIL
  EXPECT_FALSE(1); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_EQ) {
  uint32_t a = 42;
  uint32_t b = 42;
  EXPECT_EQ(a, b);     // pass!
  EXPECT_EQ(a, 42);    // pass!
  EXPECT_EQ(42, b);    // pass!
  EXPECT_EQ(42, 42);   // pass!
#ifdef WOGTEST_FAIL
  EXPECT_EQ(a, b + 1); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_NE) {
  uint32_t a = 42;
  uint32_t b = 13;
  EXPECT_NE(a, b);   // pass!
  EXPECT_NE(a, 27);  // pass!
  EXPECT_NE(69, b);  // pass!
  EXPECT_NE(42, 13); // pass!
#ifdef WOGTEST_FAIL
  EXPECT_NE(a, 42);  // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_LT) {
  uint32_t a = 13;
  uint32_t b = 42;
  EXPECT_LT(a, b);   // pass!
  EXPECT_LT(a, 27);  // pass!
  EXPECT_LT(27, b);  // pass!
  EXPECT_LT(13, 42); // pass!
#ifdef WOGTEST_FAIL
  EXPECT_LT(b, a);   // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_LE) {
  uint32_t a = 13;
  uint32_t b = 42;
  EXPECT_LE(a, b);   // pass!
  EXPECT_LE(a, 27);  // pass!
  EXPECT_LE(a, 13);  // pass!
  EXPECT_LE(27, b);  // pass!
  EXPECT_LE(42, b);  // pass!
  EXPECT_LE(13, 13); // pass!
  EXPECT_LE(13, 42); // pass!
#ifdef WOGTEST_FAIL
  EXPECT_LE(b, a);   // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_GT) {
  uint32_t a = 42;
  uint32_t b = 13;
  EXPECT_GT(a, b);   // pass!
  EXPECT_GT(a, 27);  // pass!
  EXPECT_GT(27, b);  // pass!
  EXPECT_GT(42, 13); // pass!
#ifdef WOGTEST_FAIL
  EXPECT_GT(b, a);   // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_GE) {
  uint32_t a = 42;
  uint32_t b = 13;
  EXPECT_GE(a, b);   // pass!
  EXPECT_GE(a, 27);  // pass!
  EXPECT_GE(a, 13);  // pass!
  EXPECT_GE(27, b);  // pass!
  EXPECT_GE(42, b);  // pass!
  EXPECT_GE(13, 13); // pass!
  EXPECT_GE(42, 13); // pass!
#ifdef WOGTEST_FAIL
  EXPECT_GE(b, a);   // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_STREQ) {
  const char* a = "foo";
  const char* b = "bar";
  const char* c = "bar";
  const char* d = "bAr";
  const char* e = "barrel";
  EXPECT_STREQ(a, a); // pass!
  EXPECT_STREQ(b, b); // pass!
  EXPECT_STREQ(b, c); // pass!
#ifdef WOGTEST_FAIL
  EXPECT_STREQ(a, b); // fail!
  EXPECT_STREQ(b, d); // fail!
  EXPECT_STREQ(b, e); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_STRNE) {
  const char* a = "foo";
  const char* b = "bar";
  EXPECT_STRNE(a, b); // pass!
#ifdef WOGTEST_FAIL
  EXPECT_STRNE(a, a); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_STRCASEEQ) {
  const char* a = "foo";
  const char* b = "bar";
  const char* c = "bAr";
  EXPECT_STRCASEEQ(a, a); // pass!
  EXPECT_STRCASEEQ(b, b); // pass!
  EXPECT_STRCASEEQ(b, c); // pass!
#ifdef WOGTEST_FAIL
  EXPECT_STRCASEEQ(a, b); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_STRCASENE) {
  const char* a = "foo";
  const char* b = "bar";
  const char* c = "bAr";
  EXPECT_STRCASENE(a, b); // pass!
#ifdef WOGTEST_FAIL
  EXPECT_STRCASENE(a, a); // fail!
  EXPECT_STRCASENE(b, c); // fail!
#endif //WOGTEST_FAIL
}

#ifdef WOGTEST_FLOAT

TEST(foo, ASSERT_FLOAT_EQ) {
  float a = 42.0f;
  float b = 42.00001f;
  float c = 42.0001f;
  ASSERT_FLOAT_EQ(a, b); // pass!
  ASSERT_FLOAT_EQ(a, b); // pass!   
#ifdef WOGTEST_FAIL
  //a evaluates to 42.0000000
  //c evaluates to 42.0000991
  ASSERT_FLOAT_EQ(a, c) << 1 << " FLOAT SHOULD FAIl"; // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_DOUBLE_EQ) {
  double a = 42.0f;
  double b = 42.000001f;
  double c = 42.00001f;
  ASSERT_DOUBLE_EQ(a, b); // pass!
#ifdef WOGTEST_FAIL
  //a evaluates to 42.00000000000000
  //c evaluates to 42.00001144491796
  ASSERT_DOUBLE_EQ(a, c) << 2 << " FLOAT SHOULD FAIl"; // fail!   
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_NEAR) {
  double a = 42.0f;
  double b = 42.01f;  
     //     a evaluates to 42.00000000000000
     //     b evaluates to 42.00999832133203    
     // 0.01f evaluates to  0.00999999976482
  ASSERT_NEAR(a, b, 0.01f);  // pass!  
#ifdef WOGTEST_FAIL
     //     a evaluates to 42.00000000000000
     //     b evaluates to 42.00999832133203
     //0.001f evaluates to  0.00100000047497
  ASSERT_NEAR(a, b, 0.001f) << 3 << " FLOAT SHOULD FAIl"; // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_FLOAT_EQ) {
  float a = 42.0f;
  float b = 42.00001f;
  float c = 42.0001f;
  EXPECT_FLOAT_EQ(a, b); // pass!
  EXPECT_FLOAT_EQ(a, b); // pass!   
#ifdef WOGTEST_FAIL
  //a evaluates to 42.0000000
  //c evaluates to 42.0000991
  EXPECT_FLOAT_EQ(a, c) << 4 << " FLOAT SHOULD FAIl"; // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_DOUBLE_EQ) {
  double a = 42.0f;
  double b = 42.000001f;
  double c = 42.00001f;
  EXPECT_DOUBLE_EQ(a, b); // pass!
#ifdef WOGTEST_FAIL
  //a evaluates to 42.00000000000000
  //c evaluates to 42.00001144491796
  EXPECT_DOUBLE_EQ(a, c) << 5 << " FLOAT SHOULD FAIl"; // fail!   
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_NEAR) {
  double a = 42.0f;
  double b = 42.01f;  
     //     a evaluates to 42.00000000000000
     //     b evaluates to 42.00999832133203    
     // 0.01f evaluates to  0.00999999976482
  EXPECT_NEAR(a, b, 0.01f);  // pass!  
#ifdef WOGTEST_FAIL
     //     a evaluates to 42.00000000000000
     //     b evaluates to 42.00999832133203
     //0.001f evaluates to  0.00100000047497
  EXPECT_NEAR(a, b, 0.001f) << 6 << " FLOAT SHOULD FAIl"; // fail!
#endif //WOGTEST_FAIL
}
#endif //WOGTEST_FLOAT

#ifdef WOGTEST_EXCEPTION
class foo
{
public:
    class fooExc { };
    class barExc { };
    void bar(int value) { if( value == 1) throw fooExc(); }
};

TEST(foo, ASSERT_THROW)
{
    foo fooObj;
    ASSERT_THROW(fooObj.bar(1), foo::fooExc); // pass!
#ifdef WOGTEST_FAIL
    ASSERT_THROW(fooObj.bar(1), foo::barExc); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_NO_THROW)
{
    foo fooObj;
    ASSERT_NO_THROW(fooObj.bar(0) ); // pass!
#ifdef WOGTEST_FAIL
    ASSERT_NO_THROW(fooObj.bar(1) ); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, ASSERT_ANY_THROW)
{
    foo fooObj;
    ASSERT_ANY_THROW(fooObj.bar(1) ); // pass!
#ifdef WOGTEST_FAIL
    ASSERT_ANY_THROW(fooObj.bar(0) ); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_THROW)
{
    foo fooObj;
    EXPECT_THROW(fooObj.bar(1), foo::fooExc); // pass!
#ifdef WOGTEST_FAIL
    EXPECT_THROW(fooObj.bar(1), foo::barExc); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_NO_THROW)
{
    foo fooObj;
    EXPECT_NO_THROW(fooObj.bar(0) ); // pass!
#ifdef WOGTEST_FAIL
    EXPECT_NO_THROW(fooObj.bar(1) ); // fail!
#endif //WOGTEST_FAIL
}

TEST(foo, EXPECT_ANY_THROW)
{
    foo fooObj;
    EXPECT_ANY_THROW(fooObj.bar(1) ); // pass!
#ifdef WOGTEST_FAIL
    EXPECT_ANY_THROW(fooObj.bar(0) ); // fail!
#endif //WOGTEST_EXCEPTION
}
#endif //WOGTEST_EXCEPTION

TEST(foo, SUCCEED)
{
    SUCCEED() << "Hello World"; // pass!
}

TEST(foo, FAIL)
{
#ifdef WOGTEST_FAIL
    FAIL() << 1 << " *** SHALL FAIL"; // fail!
#endif //WOGTEST_FAIL
    //never each this line
}

TEST(foo, ADD_FAILURE)
{
#ifdef WOGTEST_FAIL
    ADD_FAILURE() << 2 << " *** SHALL FAIL"; // fail!
#endif //WOGTEST_FAIL

    //this line is reached
}

TEST(foo, ADD_FAILURE_AT)
{
#ifdef WOGTEST_FAIL
    ADD_FAILURE_AT("myfile",123) << 3 << " *** SHALL FAIL"; // fail!
#endif //WOGTEST_FAIL

    //this line is reached
}

void foo_assert(void)
{
#ifdef WOGTEST_FAIL
    ASSERT_EQ(1,2) << 4 << " *** SHALL FAIL"; //fails!
#endif //WOGTEST_FAIL
}

TEST(foo, HasFatalFailure)
{
    foo_assert();
    if( HasFatalFailure() )
	return;

    //this line is reached only in case of no fatal failure
}

void foo_expect(void)
{
#ifdef WOGTEST_FAIL
    EXPECT_EQ(1,2)  << 5 << " *** SHALL FAIL"; //fails!
#endif //WOGTEST_FAIL
}

TEST(foo, HasNonfatalFailure)
{
    foo_expect();
    if( HasNonfatalFailure() ) return;

    //this line is reached only in case of no nonfatal failure
}

void foo_any(void)
{
#ifdef WOGTEST_FAIL
    EXPECT_EQ(1,2) << 6 << " *** SHALL FAIL"; //fails!
    ASSERT_EQ(1,2) << 7 << " *** SHALL FAIL"; //fails!
#endif //WOGTEST_FAIL
}

TEST(foo, HasFailure)
{
    foo_any();
    if( HasFailure() ) return;

    //this line is reached only in case of no failure
}

