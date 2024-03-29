#include <iostream>
#include <ctime>
#include "long-number-library/LongNum.hpp"

LongNum calcPi(int acc) {
    LongNum::accuracy = 101;
    clock_t start = clock();

    LongNum Pi(0);

    for (int i = 0; i < 80; ++i) {
        LongNum deg16(1);
        LongNum base("0.0625");
        int e = i;
        while (e > 0) {
            if (e % 2 == 1)
                deg16 *= base;
            base *= base;
            e /= 2;
        }

        Pi = Pi + deg16 * (4_ln/LongNum(8*i + 1) - 2_ln/LongNum(8*i + 4) - 1_ln/LongNum(8*i + 5) - 1_ln/LongNum(8*i + 6));
    }
    reduceTo(acc, Pi);
    std::cout << Pi << std::endl;

    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    std::cout << std::endl << elapsed_secs << " sec " << std::endl;
}

int main() {

    int acc;
    std::cout << "enter number of digits after point" << std::endl;
    std::cin >> acc;
    std::string comparison = "3,1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    std::cout << comparison << std::endl;
    calcPi(acc);
    return 0;
}