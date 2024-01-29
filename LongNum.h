#include <vector>

#ifndef PROJECT1_LONGNUM_H
#define PROJECT1_LONGNUM_H

#endif //PROJECT1_LONGNUM_H

class LongNum {
public:
    std::vector<int> digits;
    int sign = 1;
    int power = 0;

    LongNum(const char *str);

    LongNum& operator=(const char *number);
    LongNum operator+(LongNum &num);

    int display();
private:
    char not_zero_flag = 0;
    char dot_flag = 0;
};
