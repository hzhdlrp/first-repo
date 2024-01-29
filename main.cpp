#include <iostream>
#include <ctime>
#include "LongNum.cpp"

int main() {
    clock_t start = clock();

    LongNum num1 = "6", num2 = "8";
    LongNum num3 = num1 * num2;
    std::cout << "num1 = ";
    num1.display();
    std::cout << std::endl << "num2 = ";
    num2.display();
    std::cout << std::endl << "num3 = num1 * num2" << std::endl << "num3 = ";
    num3.display();

    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    std::cout << std::endl << elapsed_secs << " sec";
    return 0;
}