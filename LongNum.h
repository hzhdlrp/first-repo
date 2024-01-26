#include <vector>

#ifndef PROJECT1_LONGNUM_H
#define PROJECT1_LONGNUM_H

#endif //PROJECT1_LONGNUM_H

class LongNum {
public:
    std::vector<char> digits;
    int power = 0;
    int sign = 1;
    static LongNum init( std::string number);
    LongNum(const std::string& number) {
        *this = init(number);
    }
    LongNum& operator=(std::string number);
};

LongNum add(const LongNum &a, const LongNum &b);
LongNum operator+(const LongNum &a, const LongNum &b);