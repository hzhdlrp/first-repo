#include <iostream>
#include <ctime>
#include "long-number-library/LongNum.hpp"

int main() {
    clock_t start = clock();

    LongNum num1("77827.92863");
    LongNum num2("277.02883");
    LongNum num3("-0.00002877");
    LongNum num4("-7837.0001");
    LongNum num5(0);
    LongNum num6 = num1 / num2 + num3 * num4 - num5;
    std::cout << num1 / num2;


    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    std::cout << std::endl << elapsed_secs << " sec ";
    return 0;
}