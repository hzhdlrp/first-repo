#include <iostream>
#include <vector>
#include "LongNum.h"


LongNum::LongNum(std::string &str) {
    for (int i = 0; i < str.size(); ++i) {
        if (i == 0 && str[i] == '-') {
            this->sign = -1;
            continue;
        }
        if (str[i] == '.') {
            if (this->power_flag) {
                this->power = i;
                if (this->sign == -1) this->power--;
            }
            this->dot_flag = 1;
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            if (this->dot_flag == 1 && !power_flag) {
                this->power = - i + 1;
                this->dot_flag = -1;
                if (this->sign == -1) this->power++;
            }
            if (str[i] != '0') {
                this->power_flag = 1;
                this->digits.insert(this->digits.begin(), int(str[i] - '0'));
            }

            if (!this->dot_flag && i == str.size() - 1) {
                this->power = i + 1;
                if (this->sign == '-') this->power--;
            }
        }
    }
}

LongNum &LongNum::operator=(std::string number) {
    LongNum lNum = LongNum(number);
    this->power = lNum.power;
    this->digits = lNum.digits;
    this->sign = lNum.sign;
}
