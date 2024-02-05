#include <iostream>
#include <ctime>
#include "LongNum.cpp"

int main() {
    clock_t start = clock();

    int acc;
    std::cout << __cplusplus << std::endl;
    std::cout << "enter accuracy" << std::endl;
    std::cin >> acc;
    LongNum::accuracy = acc;
    LongNum num1 = 23457.35_ln;
    LongNum num2("10.34");
    LongNum num3("-0.006");
    LongNum num4 = num1 / num2;
    std::cout << num4 << std::endl <<  num4.power << std::endl << num1.power << std::endl << num2;


    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    std::cout << std::endl << elapsed_secs << " sec ";
    return 0;
}