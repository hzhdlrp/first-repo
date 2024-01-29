#include <iostream>
#include "LongNum.cpp"

int main() {
    LongNum num1 = "0.000007", num2 = "-0.0005";
    LongNum num3 = num1 + num2;
    std::cout << "num1 = ";
    num1.display();
    std::cout << std::endl << "num2 = ";
    num2.display();
    std::cout << std::endl << "num3 = num1 + num2" << std::endl << "num3 = ";
    num3.display();
    return 0;
}