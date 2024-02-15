#include <gtest/gtest.h>
#include <stdexcept>
#include <long-number-library/LongNum.hpp>

TEST(eins, output) {
    LongNum num("-27674.283748");
    std::stringstream ss;
    ss << num;
    ASSERT_EQ(ss.str(), "-27674.283748");
}

TEST(zwei, ariphmetics) {
    LongNum num1(15);
    LongNum num2(21);
    LongNum num3 = num1 / num2;
    std::stringstream ss;
    ss << num3;
    //accuracy = 8
    ASSERT_EQ(ss.str(), "0.71428571");
}

TEST(drei, ariphmetics) {
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

TEST(vier, comparison) {
    LongNum num1("15.076");
    LongNum num2("15.00000001");
    ASSERT_EQ(num1 > num2, true);
    ASSERT_EQ(num1 >= num2, true);
    ASSERT_EQ(num1 <= num2, false);
    ASSERT_EQ(num1 < num2, false);
}

TEST(funf, comparsion) {
    LongNum num1 = 23874_ln;
    LongNum num2("23874");
    ASSERT_EQ(num1 == num2, true);
    ASSERT_EQ(num2 > num1, false);
    ASSERT_EQ(num1 >= num2, true);
    ASSERT_EQ(num1 <= num2, true);
}

TEST(sechs, reduceToFunction) {
    const char *str1 = "3.141592653589793238462643383";
    std::string str2 = "3.14159";
    LongNum num1(str1);
    reduceTo(5, num1);
    std::stringstream ss;
    ss << num1;
    ASSERT_EQ(ss.str(), str2);
}

TEST(sieben, _ln) {
    LongNum num = 123.456_ln;
    std::stringstream ss;
    ss << num;
    ASSERT_EQ(ss.str(), "123.456");
}

TEST(acht, idk) {
    LongNum num1(3);
    LongNum num2(4);
    num2 *= num1;
    std::stringstream ss;
    ss << num2;
    ASSERT_EQ(ss.str(), "12");
}

TEST(neun, divBy0) {
    LongNum num1("3445");
    LongNum num2("0");
    try {
        LongNum result = num1 / num2;
    } catch (const char *error) {
        ASSERT_EQ(error, "error: division by zero\n");
    }
}

TEST(zehn, multBy1) {
    LongNum num1("0.4200827");
    LongNum num2(1);
    LongNum num = num1 * num2;
    std::stringstream ss;
    ss << num;
    ASSERT_EQ(ss.str(), "0.4200827");
}

TEST(elf, multBy0) {
    LongNum num1(4563);
    LongNum num2("0");
    LongNum num = num1 * num2;
    std::stringstream ss;
    ss << num;
    ASSERT_EQ(ss.str(), "0");
}

TEST(zwolf, multBy0) {
    LongNum num1(-463);
    LongNum num2("0");
    LongNum num = num1 * num2;
    std::stringstream ss;
    ss << num;
    ASSERT_EQ(ss.str(), "0");
}

TEST(dreizehn, differenceOfEqual) {
    LongNum num1(1234);
    LongNum num2("1234");
    LongNum num = num2 - num1;
    std::stringstream ss;
    ss << num;
    ASSERT_EQ(ss.str(), "0");
}

TEST(vierzehn,sumOfOpposite) {
    LongNum num1("0.0054321");
    LongNum num2("-0.0054321");
    LongNum num = num1 + num2;
    std::stringstream ss;
    ss << num;
    ASSERT_EQ(ss.str(), "0");
}

TEST(funfzehn, notEq) {
    LongNum num1("762");
    LongNum num2(762);
    LongNum num3("76.2");
    ASSERT_EQ(num1 != num2, false);
    ASSERT_EQ(num1 != num3, true);
}

TEST(sechzehn, mult) {
    LongNum num1("34.43");
    LongNum num2("234.5");
    num1 *= num2;
    std::stringstream ss;
    ss << num1;
    ASSERT_EQ(ss.str(), "8073.835");
}

TEST(siebzehn, assignment) {
    LongNum num1("23874");
    LongNum num2;
    num2 = num1;
    std::stringstream ss;
    ss << num1;
    ASSERT_EQ(ss.str(), "23874");
}

TEST(achtzehn, anotherDiv) {
    const LongNum num1(0);
    LongNum num2 = num1;
    LongNum num3("345");
    LongNum num = num2 / num3;
    std::stringstream ss;
    ss << num;
    ASSERT_EQ(ss.str(), "0");
}

TEST(neunzehn, max) {
    int a = 2, b = -5;
    int c = max(a, b);
    ASSERT_EQ(c, a);
}

TEST(zwanzig, anotherAnotherDiv) {
    LongNum num1("23.456");
    LongNum num2("13653.12");
    LongNum num3 = num1 / num2;
    std::stringstream ss;
    ss << num3;
    ASSERT_EQ(ss.str(), "0.001717995");
}

TEST(einundzwanzig, anotherComparsion) {
    LongNum num1("123");
    LongNum num2("123.001");
    ASSERT_EQ(num2 > num1, true);
}

TEST(zweiundzwanzig, idk) {
    LongNum num1("11111");
    LongNum num2(11111);
    LongNum num3 = num1 - num2;
    LongNum num4(11122);
    LongNum num = num3 / num4;
    std::stringstream ss;
    ss << num;
    ASSERT_EQ(ss.str(), "0");
}