#ifndef PROJECT1_LONGNUM_H
#define PROJECT1_LONGNUM_H

#endif //PROJECT1_LONGNUM_H

struct LongNum {
    std::vector<char> digits;
    int power = 0;
    int sign = 1;

    LongNum& operator=(std::string number);
};

LongNum add(LongNum &a, LongNum &b);
LongNum init( std::string number);

LongNum& operator+(const LongNum &a, const LongNum &b);