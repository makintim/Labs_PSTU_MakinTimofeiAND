#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::fixed << std::setprecision(8);
    std::cout << "zadacha 1" << std::endl;

    float a= 1000.0;
    float b = 0.0001;

    float t1 = a + b;            // a + b
    float t2 = t1 * t1;          // (a + b)^2
    float t3 = a * a;            // a^2
    float t4 = 2.0 * a * b;     // 2 * a * b
    float t5 = t3 + t4;          // a^2 + 2ab
    float t6 = t2 - t5;          // числитель
    float t7 = b * b;            // знаменатель b^2
    float res_float = t6 / t7;     // результат

    std::cout << "Result (float):  " << res_float << std::endl;

    double a = 1000.0;
    double b = 0.0001;

    double d1 = a + b;
    double d2 = d1 * d1;
    double d3 = a * a;
    double d4 = 2.0 * a * b;
    double d5 = d3 + d4;
    double d6 = d2 - d5;
    double d7 = b * b;
    double res_double = d6 / d7;

    std::cout << "Result (double): " << res_double << std::endl;
}