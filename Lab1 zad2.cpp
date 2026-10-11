#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::fixed << std::setprecision(8);
    std::cout << "ZADACHA 2" << std::endl;

    int m = 5, n = 3;
    std::cout << "Initial values: m = " << m << ", n = " << n << std::endl;

    int res1 = --m - ++n;
    std::cout << "1) --m - ++n = " << res1 << " (now m = " << m << ", n = " << n << ")" << std::endl;

    bool res2 = (m * n < n++);
    std::cout << std::boolalpha; 
    std::cout << "2) m * n < n++ = " << res2 << " (now m = " << m << ", n = " << n << ")" << std::endl;

    bool res3 = (n-- > m++);
    std::cout << "3) n-- > m++ = " << res3 << " (now m = " << m << ", n = " << n << ")" << std::endl;

    return 0;
}