#include <vector>
#include <compare>

#ifndef PROJECT1_LONGNUM_H
#define PROJECT1_LONGNUM_H

#endif //PROJECT1_LONGNUM_H

class LongNum {
public:
    static int accuracy;
    explicit LongNum(const char *str);
    explicit LongNum(int num);
    LongNum();

    LongNum& operator=(const char *number);
    LongNum operator+(const LongNum &num);
    LongNum operator-(const LongNum &num);
    LongNum operator*(const LongNum& num);
    LongNum operator*(int i);
    LongNum operator/(LongNum num);

    bool operator<(const LongNum &num);
    bool operator>(const LongNum &num);
    bool operator ==(const LongNum &num);
    bool operator !=(const LongNum &num);
    bool operator >=(const LongNum &num);
    bool operator <=(const LongNum &num);

    friend std::ostream &operator<<(std::ostream &os, LongNum &num);
private:
    std::vector<int> digits;
    int power = 0;
    int sign = 1;
    char not_zero_flag = 0;
    char dot_flag = 0;
};

LongNum operator ""_ln(const char *str);

