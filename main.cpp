#include <iostream>
#include <ctime>
#include "LongNum.cpp"

int main() {
    clock_t start = clock();

    LongNum num1("10");
    LongNum num2( "6.257475467928");
    LongNum num3("43654.03845793757350253");
    LongNum num4 = num2 + num3;
    std::cout << (num4);

    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    std::cout << std::endl << elapsed_secs << " sec ";
    return 0;
}