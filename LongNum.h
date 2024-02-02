#include <vector>

#ifndef PROJECT1_LONGNUM_H
#define PROJECT1_LONGNUM_H

#endif //PROJECT1_LONGNUM_H

class LongNum {
public:
    static int accuracy;
    int power = 0;
    explicit LongNum(const char *str);
    explicit LongNum(int num);
    explicit LongNum(float num);
    LongNum();

    LongNum& operator=(const char *number);
    LongNum operator+(const LongNum &num);
    LongNum operator-(LongNum num);
    LongNum operator*(const LongNum& num);
    LongNum operator*(int i);
    LongNum operator/(LongNum num);

    bool operator<(const LongNum &num);
    bool operator>(const LongNum &num);
    bool operator ==(const LongNum &num);
    bool operator !=(const LongNum &num);
    bool operator >=(const LongNum &num);
    bool operator <=(const LongNum &num);

    friend std::ostream &operator<<(std::ostream &os, const LongNum &num);
private:
    std::vector<int> digits;
    int sign = 1;
    char not_zero_flag = 0;
    char dot_flag = 0;
};

