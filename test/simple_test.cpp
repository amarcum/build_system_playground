/// Very Simple test to verify dependencies are coming in correctly.
/// @file test/simple_test.cpp

#include <gtest/gtest.h>

TEST(simple_test, false_is_false)
{
  EXPECT_TRUE(false == false) << "This is really bad! false doesn't equal false?";
}
