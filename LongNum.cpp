#include <iostream>
#include <vector>
#include <cstring>
#include "LongNum.h"


LongNum::LongNum(const char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        if (i == 0 && str[i] == '-') {
            this->sign = -1;
            continue;
        }
        if (str[i] == '.') {
            if (this->not_zero_flag) {
                this->power = i;
                if (this->sign == -1) this->power--;
                this->dot_flag = -1;
            } else {
                this->dot_flag = 1;
            }
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            if (str[i] != '0') {
                if (this->dot_flag == 1) {
                    this->power = - i + 2;
                    this->dot_flag = -1;
                    if (this->sign == -1) this->power++;
                }

                this->not_zero_flag = 1;
                this->digits.insert(this->digits.begin(), int(str[i] - '0'));
            } else {
                if (this->not_zero_flag) {
                    this->digits.insert(this->digits.begin(), int(str[i] - '0'));
                }
            }


            if (this->dot_flag == 0 && i == strlen(str) - 1) {
                this->power = i + 1;
                if (this->sign == -1) this->power--;
            }
        }
    }
}

LongNum &LongNum::operator=(const char *number) {
    LongNum lNum = LongNum(number);
    this->power = lNum.power;
    this->digits = lNum.digits;
    this->sign = lNum.sign;
}

LongNum LongNum::operator+(LongNum &num) {
    LongNum operand1 = (this->power > num.power ? *this : num);
    LongNum operand2 = (this->power > num.power ? num : *this);
    //power of operand1 is more than operand2
    int decimal_places_diff = (operand1.digits.size() - operand1.power) - (operand2.digits.size() - operand2.power);
    //разница в количестве знаков после запятой восполняется добавлением нулей
    if (decimal_places_diff > 0) {
        for (int i = 0; i < decimal_places_diff; ++i) {
            operand2.digits.insert(operand2.digits.begin(), 0);
        }
    } else {
        for (int i = 0; i < -decimal_places_diff; ++i) {
            operand1.digits.insert(operand1.digits.begin(), 0);
        }
    }


    if (operand1.sign == operand2.sign) {
        for (int i = 0; i < operand2.digits.size(); ++i) {
            operand1.digits[i] += operand2.digits[i];
            if (i < operand2.digits.size() - 1) {
                if (operand1.digits[i] > 10) {
                    operand1.digits[i + 1]++;
                    operand1.digits[i] %= 10;
                }
            } else if (i == operand2.digits.size() - 1) {
                if (operand1.digits[i] > 10) {
                    if (operand1.digits.size() > operand2.digits.size()) {
                        operand1.digits[i + 1]++;
                        int j = 1;
                        while (operand1.digits[i + j] > 10) {
                            operand1.digits[i + j] %= 10;
                            operand1.digits[i + j + 1]++;
                            ++j;
                        }
                        operand1.digits[i] %= 10;
                    } else {
                        operand1.digits.insert(operand1.digits.end(), 1);
                        operand1.digits[i] %= 10;
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < operand2.digits.size(); ++i) {
            operand1.digits[i] -= operand2.digits[i];
            if (i < operand2.digits.size() - 1) {
                if (operand1.digits[i] < 0) {
                    operand1.digits[i + 1]--;
                    operand1.digits[i] += 10;
                }
            } else if (i == operand2.digits.size() - 1) {
                if (operand1.digits[i] < 0) {
                    if (operand1.digits.size() > operand2.digits.size()) {
                        operand1.digits[i + 1]--;
                        int j = 1;
                        while (operand1.digits[i + j] < 0) {
                            operand1.digits[i + j] += 10;
                            operand1.digits[i + j + 1]--;
                            ++j;
                        }
                        if (operand1.digits[i + j] == 0 && i + j == operand1.digits.size() - 1) operand1.digits.pop_back();
                        operand1.digits[i] += 10;
                    } else {
                        operand1.digits[i]++;
                        operand1.digits[i] *= -1;
                        for (int j = 0; j < i; ++j) {
                            operand1.digits[j] = 10 - operand1.digits[j];
                        }
                        if (operand1.digits[i] == 0) operand1.digits.pop_back();
                        operand1.sign *= -1;
                    }
                }
            }
        }
    }
    return operand1;
}

LongNum LongNum::operator-(LongNum num) {
    num.sign *= -1;
    LongNum a = *this + num;
    return a;
}

int LongNum::display() {
    if (this->sign == -1) {
        std::cout << '-';
    }
    if (this->power > 0) {
        for (int i = this->digits.size() - 1; i >= 0; --i) {
            if (i == this->digits.size() - this->power - 1) {
                std::cout << '.';
            }
            std::cout << this->digits[i];
        }
    } else {
        std::cout << "0.";
        for (int i = 0; i <= - this->power - 1; ++i) {
            std::cout << '0';
        }
        for (int i = this->digits.size() - 1; i >= 0; --i) {
            std::cout << this->digits[i];
        }
    }
    return 0;
}

