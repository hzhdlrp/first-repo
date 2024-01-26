#include <iostream>
#include <vector>
#include "LongNum.h"

LongNum init(std::string number) {
    LongNum lNumber;
    int len = number.size();
    lNumber.digits.resize(len);
    for (int i = 0; number[i] != '\0'; ++i) {
        if (number[i] == '-') {
            lNumber.sign = -1;
            continue;
        } else {
            lNumber.sign = 1;
        }
        if (number[i] == '.') {
            lNumber.power = i;
            continue;
        } else {
            lNumber.digits.insert(lNumber.digits.begin(), number[i] - '0');
        }
    }
    return lNumber;
}

LongNum &LongNum::operator=(std::string number) {
    LongNum a = init(number);
    this->sign = a.sign;
    this->power = a.power;
    this->digits = a.digits;
    return *this;
}

LongNum add(LongNum &a, LongNum &b) {
    LongNum first;
    LongNum second; //first is longer number
    a.digits.size() > b.digits.size() ? first = a , second = b : first = b, second = a;
    if (first.sign == b.sign) {
        for (int i = 0; i < second.digits.size(); ++i) {

        }
    }
    return first;
}


LongNum operator+(const LongNum &a) {

}


