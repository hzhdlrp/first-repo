#include <iostream>
#include "LongNum.cpp"

int main() {
    LongNum num1 = "0.00506", num2 = "-0.0005";

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

    LongNum num3 = num1 + num2;

    for (int digit : num3.digits) {
        std::cout << digit;
    }
    std::cout << std::endl <<  num3.sign << std::endl;
    std::cout << num3.power<<std::endl;


    return 0;
}