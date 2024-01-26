#include <iostream>
#include <string>
#include <vector>


class LongNum {
public:
    std::vector<char> digits;
    int power;
    static void init(LongNum lNumber, std::string number);
    static LongNum add(LongNum a, LongNum b);
};

void LongNum::init(LongNum lNumber, std::string number) {
    int len = 2;
    lNumber.digits.resize(len);
    for (int i = 0; i <= strlen(number); ++i) {
        if (i >= len) {
            len *= 2;
            lNumber.digits.resize(len);
        }
        if (number[i] == '.') {
            lNumber.power = i;
            continue;
        }

        lNumber.digits[i] = number[i] - '0';
    }

}
LongNum LongNum::add(LongNum a, LongNum b) {
    LongNum c ;
    return c;
}

LongNum operator+(const LongNum a, const LongNum b) {
    return LongNum::add(a, b);
}

LongNum operator=(LongNum lNumber, std::string number) {
    LongNum::init(lNumber, number);
    return lNumber;
}

int main() {
    std::cout<<"hi"<<std::endl;
    std::cout<<"?";
    int a[5] = {1, 45 ,24 , 345 ,435};

    for (int i : a) {
        std::cout<<i<<std::endl;
    }
}