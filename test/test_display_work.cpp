#include <gtest/gtest.h>
#include <long-number-library/LongNum.hpp>

TEST(teststtstst, ahhraharha) {
    LongNum nu1("27674.283748");

    std::stringstream ss;
    ss << nu1;

    ASSERT_EQ(ss.str(), "27674.283748");
}