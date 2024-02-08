#include <gtest/gtest.h>
#include <long-number-library/LongNum.hpp>

TEST(first, output) {
    LongNum num("-27674.283748");
    std::stringstream ss;
    ss << num;
    ASSERT_EQ(ss.str(), "-27674.283748");
}

TEST(second, ariphmetics) {
    LongNum num1(15);
    LongNum num2(21);
    LongNum num3 = num1 / num2;
    std::stringstream ss;
    ss << num3;
    ASSERT_EQ(ss.str(), "0.71428571");
}

TEST(third, ariphmetics) {
    LongNum num1("77827.92863");
    LongNum num2("277.02883");
    LongNum num3("0.02877");
    LongNum num4("-7837.0001");
    LongNum num5(0);
    LongNum num6 = num1 / num2 + num3 * num4 - num5;
    std::stringstream ss;
    ss << num6;
    ASSERT_EQ(ss.str(), "55.467518623");
}

TEST(fourth, comparison) {
    LongNum num1("15.076");
    LongNum num2("15.00000001");
    ASSERT_EQ(num1 > num2, true);
    ASSERT_EQ(num1 >= num2, true);
    ASSERT_EQ(num1 <= num2, false);
    ASSERT_EQ(num1 < num2, false);
}

TEST(fifth, comparsion) {
    LongNum num1 = 23874_ln;
    LongNum num2("23874");
    ASSERT_EQ(num1 == num2, true);
    ASSERT_EQ(num2 > num1, false);
    ASSERT_EQ(num1 >= num2, true);
}

