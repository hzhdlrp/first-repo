#include <vector>

#ifndef PROJECT1_LONGNUM_H
#define PROJECT1_LONGNUM_H

#endif //PROJECT1_LONGNUM_H

class LongNum {
public:
    static int accuracy;
    explicit LongNum(const char *);
    explicit LongNum(int);
    LongNum();

    LongNum& operator=(const char *);
    LongNum operator+(const LongNum &);
    LongNum operator-(const LongNum &);
    LongNum operator*(const LongNum &);
    LongNum operator*=(const LongNum &);
    LongNum operator*(int);
    LongNum operator/(LongNum);

    bool operator<(const LongNum &);
    bool operator>(const LongNum &);
    bool operator ==(const LongNum &);
    bool operator !=(const LongNum &);
    bool operator >=(const LongNum &);
    bool operator <=(const LongNum &);

    friend std::ostream &operator<<(std::ostream &, LongNum &);


    friend void reduceTo(int, LongNum &);
private:
    std::vector<int> digits;
    int power = 0;
    int sign = 1;
    char not_zero_flag = 0;
    char dot_flag = 0;
};

LongNum operator ""_ln(const char *str);

