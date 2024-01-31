#include <vector>

#ifndef PROJECT1_LONGNUM_H
#define PROJECT1_LONGNUM_H

#endif //PROJECT1_LONGNUM_H

class LongNum {
public:
    std::vector<int> digits;
    int sign = 1;
    int power = 0;

    explicit LongNum(const char *str);
    LongNum();

    LongNum& operator=(const char *number);
    LongNum operator+(const LongNum &num);
    LongNum operator-(LongNum num);
    LongNum operator*(const LongNum &num);
    LongNum operator/(const LongNum &num);
    bool operator<(const LongNum &num);
    bool operator>(const LongNum &num);
    bool operator ==(const LongNum &num);
    bool operator >=(const LongNum &num);
    bool operator <=(const LongNum &num);
    friend std::ostream &operator<<(std::ostream &os, const LongNum &num);

private:
    char not_zero_flag = 0;
    char dot_flag = 0;
};
