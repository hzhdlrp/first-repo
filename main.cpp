#include <iostream>
#include "LongNum.cpp"

int main() {
    std::string num1String ("-1111.1111");
    std::string num2String ("-0.0005");
    std::string num3String ("1234.5");
    LongNum num1 = num1String, num2 = num2String, num3 = num3String;
    for (int digit : num1.digits) {
        std::cout << digit;
    }
    std::cout << std::endl <<  num1.sign << std::endl;
    std::cout << num1.power<<std::endl<<std::endl;

    for (int digit : num2.digits) {
        std::cout << digit;
    }
    std::cout << std::endl <<  num2.sign << std::endl;
    std::cout << num2.power<<std::endl<<std::endl;

    for (int digit : num3.digits) {
        std::cout << digit;
    }
    std::cout << std::endl <<  num3.sign << std::endl;
    std::cout << num3.power<<std::endl;
}