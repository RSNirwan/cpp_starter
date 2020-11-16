#include <gtest/gtest.h>

#include <Module1.hpp>

TEST(Module1Tests, square) {
    int aInt{2};
    double aDouble{3.1};
    EXPECT_EQ(4, module1::square(aInt));
    EXPECT_EQ(3.1 * 3.1, module1::square(aDouble));
}