#include <iostream>
#include <cstring>
#include "LongNum.hpp"

 int LongNum::accuracy = 8;

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
    return *this;
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

LongNum LongNum::operator-(const LongNum &num) {
    LongNum result = num;
    result.sign *= -1;
    result = *this + result;
    return result;
}

LongNum LongNum::operator*(const LongNum& num) {
    if (digits.size() == 0 || num.digits.size() == 0) return LongNum("0");

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

std::ostream &operator<<(std::ostream &os, LongNum &num) {
    for (int i = num.digits.size() - 1; i >= 0; ++i) {
        if (num.digits[i]) break;
        num.digits.pop_back();
        num.power--;
    }
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
        if (num.power > num.digits.size()) {
            for (int i = 0; i < num.power - num.digits.size(); ++i) {
                os << '0';
            }
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

    if (digits.size() == 0) return LongNum("0");

    LongNum result;
    bool significant_digit_flag = false;
    int numpow = num.power;
    int nums = num.sign;
    num.sign = 1;
    num.power = num.digits.size();
    int len = num.digits.size();
    LongNum temp;
    temp.digits = {};
    int add_digit_iter = 0;
    while (add_digit_iter < len && add_digit_iter < digits.size()) {
        temp.digits.insert(temp.digits.begin(), *(digits.end() - add_digit_iter - 1));
        temp.power++;
        add_digit_iter++;
    }

    if (power < numpow) accuracy += (numpow - power); // как мог шаманил с этой дурацкой точностью,
    // вроде теперь во всех случаях ровное количество знаков после точки
    //если все нули, считается до первой знчащей цифры
    for (int i = 0; i <= power - numpow + accuracy; ++i) {
       int k = 0;
       while (temp >= num) {
           temp = temp - num;
           ++k;
       }
       //std::cout << temp << " " << num << " " << *this << " " << k << std::endl;
       if (k > 0) significant_digit_flag = true;
       if (significant_digit_flag) {
           result.digits.insert(result.digits.begin(), k);
           result.power++;
       }
//       if ((*this - result * num) == LongNum(0)) break;
       if (add_digit_iter < digits.size()) {
           temp.digits.insert(temp.digits.begin(), *(digits.end() - add_digit_iter - 1));
           add_digit_iter++;
       } else {
           temp.digits.insert(temp.digits.begin(), 0);
           add_digit_iter++;
           result.power--;
       }
        temp.power++;
       if (i == power - numpow + accuracy && significant_digit_flag == 0) accuracy++;
    }

    result.power -= digits.size() - power;
    result.power += len - numpow + 1;
    result.sign = sign * nums;
    return result;
}

// std::strong_ordering operator<=>(const LongNum& other)
// return std::strong_ordering::equal

// используется с++20, но компилятор не воспринимает std::strong_ordering
// упростил >= как !(<) и <= как !(>)
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
    return !(*this > num);
}

bool LongNum::operator>=(const LongNum &num) {
    return !(*this < num);
}

bool LongNum::operator==(const LongNum &num) {
    LongNum result = *this - num;
    for (auto &digit : result.digits) {
        if (digit) {
            return false;
        }
    }
    return true;
}

bool LongNum::operator!=(const LongNum &num) {
    return !(*this == num);
}

void reduceTo100(LongNum &num) {
    while (num.digits.size() > 101) {
        num.digits.erase(num.digits.begin());
    }
}

LongNum LongNum::operator*=(const LongNum &num) {
    (*this) = (*this) * num;
    return *this;
}

LongNum operator ""_ln(const char *str) {
    return LongNum(str);
}

LongNum::LongNum() = default;