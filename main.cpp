#include <iostream>
#include <ctime>
#include "LongNum.cpp"

int main() {
    clock_t start = clock();

    LongNum num1 = 23457.3455_ln;
    LongNum num2("10.34");
    LongNum num3("-0.006");
    std::cout << num2 << "/" << "(" << num3 << ")" << " = " << num2 / num3;

    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    std::cout << std::endl << elapsed_secs << " sec ";
    return 0;
}