#include <iostream>
#include <ctime>
#include "LongNum.cpp"

int main() {
    clock_t start = clock();

    LongNum num1("5");
    LongNum num2( "0.001");
    std::cout << (num1 / num2);

    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    std::cout << std::endl << elapsed_secs << " sec ";
    return 0;
}