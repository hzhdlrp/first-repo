#include <iostream>
#include <vector>
#include "LongNum.h"

LongNum LongNum::init(std::string number) {
    LongNum *lNumber;
    int len = number.size();
    lNumber->digits.resize(len);
    for (int i = 0; number[i] != '\0'; ++i) {
        if (number[i] == '-') {
            lNumber->sign = -1;
            continue;
        } else {
            lNumber->sign = 1;
        }
        if (number[i] == '.') {
            lNumber->power = i;
            continue;
        } else {
            lNumber->digits.insert(lNumber->digits.begin(), number[i] - '0');
        }
    }
    return *lNumber;
}

LongNum &LongNum::operator=(std::string number) {
    LongNum a = init(number);
    this->sign = a.sign;
    this->power = a.power;
    this->digits = a.digits;
    return *this;
}


LongNum add(const LongNum &a,const LongNum &b) {
    LongNum *first;
    LongNum *second; //first is longer number
    a.digits.size() > b.digits.size() ? *first = a , *second = b : *first = b, *second = a;
    if (first->sign == b.sign) {
        for (int i = 0; i < second->digits.size(); ++i) {
            first->digits[i] += second->digits[i];
            if (first->digits[i] > 9) {
                first->digits[i] %= 10;
                if (i == second->digits.size() - 1) {
                    if (first->digits.size() > second->digits.size() + 1) {
                        first->digits[i + 1]++;
                        if (first->digits[i + 1] > 9) {
                            first->digits[i + 1] %= 10;
                            first->digits[i + 2]++;
                        }
                    } else if (first->digits.size() == second->digits.size() + 1) {
                        first->digits[i + 1]++;
                        if (first->digits[i + 1] > 9) {
                            first->digits[i + 1] %= 10;
                            first->digits.push_back(1);
                        }
                    } else {
                        first->digits.push_back(1);
                    }
                } else {
                    first->digits[i + 1]++;
                }
            }
        }

    }
    return *first;
}


LongNum operator+(const LongNum &a, const LongNum &b) {
    return add(a, b);
}

