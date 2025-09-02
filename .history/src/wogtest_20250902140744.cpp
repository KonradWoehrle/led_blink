#include "../test/wogtest/wogtest.hpp"

namespace testing {

gTests gtests;

// Definition der statischen Member
TestCase* gTests::pTestCases_ = nullptr;
bool gTests::tn_fatal_ = 1;

}