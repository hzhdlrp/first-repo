#include <iostream>
#include <ctime>
#include "LongNum.cpp"

int main() {
    clock_t start = clock();

    LongNum num1("0.005");
    LongNum num2( "-0.98");
    LongNum num3 = num1 * num2;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << '*' << std::endl;
    std::cout << num3;

    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    std::cout << std::endl << elapsed_secs << " sec ";
    return 0;
}