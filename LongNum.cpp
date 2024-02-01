#include <iostream>
#include <vector>
#include <cstring>
#include "LongNum.h"

int max(int a, int b) {
    return a > b ? a : b;
}

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

LongNum::LongNum(int num) {
    if (num < 0) {
        this->sign = -1;
        num *= -1;
    } else {
        this->sign = 1;
    }
    int i = 0;
    while (num != 0) {
        this->digits.push_back( num % 10);
        num /= 10;
        ++i;
    }
    this->power = i;
}

LongNum &LongNum::operator=(const char *number) {
    LongNum lNum = LongNum(number);
    this->power = lNum.power;
    this->digits = lNum.digits;
    this->sign = lNum.sign;
}

LongNum LongNum::operator+(const LongNum &num) {
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
        }
        for (int i = 0; i < operand1.digits.size() - 1; ++i) {
            if (operand1.digits[i] >= 10) {
                operand1.digits[i + 1] += operand1.digits[i] / 10;
                operand1.digits[i] %= 10;
            }
        }
        if (operand1.digits[operand1.digits.size() - 1] >= 10) {
            int size = operand1.digits.size();
            operand1.digits.push_back(operand1.digits[size - 1] / 10);
            operand1.digits[size - 1] %= 10;
            operand1.power++;
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
                for (int j = 0; i + j < operand1.digits.size() - 1; ++j) {
                    if (operand1.digits[i + j] < 0) {
                        operand1.digits[i + j + 1]--;
                        operand1.digits[i + j] += 10;
                    }
                }
                if (operand1.digits[operand1.digits.size() - 1] < 0) {
                    operand1.digits[operand1.digits.size() - 1] *= -1;
                    for (int k = 0; k < operand1.digits.size() - 1; ++k) {
                        operand1.digits[k] *= -1;
                    }
                    for (int k = 0; k < operand1.digits.size() - 1; ++k) {
                        if (operand1.digits[k] < 0) {
                            operand1.digits[k + 1]--;
                            operand1.digits[k] += 10;
                        }

                    }
                    operand1.sign *= -1;
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

LongNum LongNum::operator*(const LongNum& num) {
    LongNum result = *this;
    result.sign *= num.sign;
    int after_point = (this->digits.size() - this->power) + num.digits.size() - num.power;

    for (int &digit : result.digits) {
        digit = 0;
    }

    for (int i = 0; i < num.digits.size(); ++i) {
        for (int j = 0; j < this->digits.size(); ++j) {
            if (j + i == result.digits.size()) {
                result.digits.push_back(num.digits[i] * this->digits[j]);
            } else {
                result.digits[j + i] += num.digits[i] * this->digits[j];
            }
        }
    }

    for (int i = 0; i < result.digits.size() - 1; ++i) {
        result.digits[i + 1] += result.digits[i] / 10;
        result.digits[i] %= 10;
    }

    while (result.digits[result.digits.size() - 1] > 10) {
        int size = result.digits.size();
        result.digits.push_back(result.digits[size - 1] / 10);
        result.digits[size - 1] %= 10;
    }

    result.power = result.digits.size() - after_point;
    return result;
}

LongNum LongNum::operator*(int i) {
    LongNum LongI = LongNum(i);
    return ((*this) * LongI);
}

std::ostream &operator<<(std::ostream &os, const LongNum &num) {
    if (num.sign == -1) {
        os << '-';
    }
    if (num.power > 0) {
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            if (i == num.digits.size() - num.power - 1) {
                os << '.';
            }
            os << num.digits[i];
        }
        for (int i = 0; i < num.power - num.digits.size(); ++i) {
            os << '0';
        }
    } else {
        os << "0.";
        for (int i = 0; i <= - num.power - 1; ++i) {
            os << '0';
        }
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            os << num.digits[i];
        }
    }
    return os;
}

LongNum LongNum::operator/(LongNum num) {
    if (num == LongNum(0)) {
        num.digits = {};
        throw std::invalid_argument("division by 0");
    }
    LongNum result;
    LongNum reciprocal;
    LongNum temp;
    int significant_dig_flag = 0;
    temp.sign = 1;
    temp.power = 1;
    temp.digits = {1};
    int pow = -num.power;
    num.power = 0;
    int s = num.sign;
    num.sign = 1;

//    int after_point = max(this->digits.size() - this->power, num.digits.size() - num.power);

    for (int i = 0; i < 10; ++i) {
        int k = 0;
        while (temp >= num * k) {
            ++k;
        }
        if (k > 0) significant_dig_flag = 1;
        if (significant_dig_flag) {
            if (k < 10) {
                reciprocal.digits.push_back(k);
            } else {
                reciprocal.digits.push_back(k/10);
                reciprocal.digits.push_back(k%10);
            }
        }
        temp = num - num * k;
        if (temp == LongNum(0)) break;
        temp.power++;
        pow--;
    }
//
//    std::cout << num << " " << k <<  std::endl << temp << std::endl;
    reciprocal.power = pow;
    reciprocal.sign = s;
    std::cout << std::endl;
    for (int digit : reciprocal.digits) {
        std::cout << digit << " ";
    }
//    std::cout << reciprocal << std::endl;
    result = *this * reciprocal;
    return result;
}

bool LongNum::operator<(const LongNum &num) {
    LongNum result = *this - num;
    for (int digit : result.digits) {
        if (digit) {
            if (result.sign == -1) return true;
            else return false;
        }
    }
    return false;
}

bool LongNum::operator>(const LongNum &num) {
    LongNum result = *this - num;
    for (int digit : result.digits) {
        if (digit) {
            if (result.sign == -1) return false;
            else return true;
        }
    }
    return false;
}

bool LongNum::operator<=(const LongNum &num) {
    LongNum result = *this - num;
    for (int digit : result.digits) {
        if (digit) {
            if (result.sign == -1) return true;
            else return false;
        }
    }
    return true;
}

bool LongNum::operator>=(const LongNum &num) {
    LongNum result = *this - num;
    for (int digit : result.digits) {
        if (digit) {
            if (result.sign == -1) return false;
            else return true;
        }
    }
    return true;
}

bool LongNum::operator==(const LongNum &num) {
    LongNum result = *this - num;
    for (int digit : result.digits) {
        if (digit) {
            return false;
        }
    }
    return true;
}

LongNum::LongNum() = default;

