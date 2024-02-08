#include <iostream>
#include <ctime>
#include "long-number-library/LongNum.hpp"

LongNum calcPi() {
    clock_t start = clock();

    LongNum::accuracy = 100;
    LongNum Pi(0);
    for (int i = 0; i < 100; ++i) {
        LongNum deg16(1);
//        for (int j = 0 ; j < i; ++j) {
//            deg16 = deg16 / 16_ln;
//        }
//        std::cout << i << std::endl;
        Pi = Pi + deg16 * (4_ln/LongNum(8*i + 1) - 2_ln/LongNum(8*i + 4) - 1_ln/LongNum(8*i + 5) - 1_ln/LongNum(8*i + 6));
    }
    reduceTo100(Pi);
    std::cout << Pi << std::endl;

    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    std::cout << std::endl << elapsed_secs << " sec " << std::endl;
}

int main() {

    std::string comparison = "3,1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    std::cout << comparison << std::endl;
    calcPi();

    return 0;
}