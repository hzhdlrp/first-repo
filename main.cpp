#include <iostream>
#include <ctime>
#include "long-number-library/LongNum.hpp"

LongNum calcPi() {
    LongNum::accuracy = 100;
    LongNum Pi(0);
    for (int i = 0; i < 10; ++i) {
        LongNum deg16(1);
        for (int j = 0 ; j < i; ++j) {
            deg16 = deg16 / 16_ln;
        }
        //std::cout << i << std::endl;
        LongNum k1 = 8_ln * LongNum(i) + 1_ln;
        LongNum k2 = 8_ln * LongNum(i) + 4_ln;
        LongNum k3 = 8_ln * LongNum(i) + 5_ln;
        LongNum k4 = 8_ln * LongNum(i) + 6_ln;
        Pi = Pi + deg16 * (4_ln/k1 - 2_ln/k2 - 1_ln/k3 - 1_ln/k4);
    }
    reduceTo100(Pi);
    std::cout << Pi << std::endl;
}

int main() {
    clock_t start = clock();

    std::string comparison = "3,1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    std::cout << comparison << std::endl;
    calcPi();

    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    std::cout << std::endl << elapsed_secs << " sec ";
    return 0;
}