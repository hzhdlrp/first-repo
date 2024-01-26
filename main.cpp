#include <iostream>
#include "LongNum.cpp"

int main() {
    std::string num1String ("11111111");
    LongNum num1 = num1String;
    std::cout<<num1.digits[0];
}