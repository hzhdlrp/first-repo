#include <vector>

#ifndef PROJECT1_LONGNUM_H
#define PROJECT1_LONGNUM_H

#endif //PROJECT1_LONGNUM_H

class LongNum {
public:
    std::vector<int> digits;
    int sign = 1;
    int power = 0;

    LongNum(std::string &str);

    LongNum& operator=(std::string number);
    LongNum operator+(LongNum&);
private:
    char power_flag = 0;
    char dot_flag = 0;
};
