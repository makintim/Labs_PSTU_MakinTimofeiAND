#include <iostream>
#include <iomanip>

int main() {
    // Включаем вывод булевых значений текстом (true / false)
    std::cout << std::boolalpha;
    std::cout << std::fixed << std::setprecision(4);

    std::cout << "===== CHAST' 1: TIP FLOAT =====" << std::endl;

    float m_f = 5.0f;
    float n_f = 3.0f;
    std::cout << "Start: m = " << m_f << ", n = " << n_f << std::endl;

    // Выражение 1: --m - ++n
    float res1_f = --m_f - ++n_f;
    std::cout << "1) --m - ++n  = " << res1_f 
              << " | m = " << m_f << ", n = " << n_f << std::endl;

    // Выражение 2: m * n < n++
    bool res2_f = (m_f * n_f < n_f++);
    std::cout << "2) m * n < n++ = " << res2_f 
              << " | m = " << m_f << ", n = " << n_f << std::endl;

    // Выражение 3: n-- > m++
    bool res3_f = (n_f-- > m_f++);
    std::cout << "3) n-- > m++   = " << res3_f 
              << " | m = " << m_f << ", n = " << n_f << std::endl;

    std::cout << "\n===== CHAST' 2: TIP DOUBLE =====" << std::endl;

    double m_d = 5.0;
    double n_d = 3.0;
    std::cout << "Start: m = " << m_d << ", n = " << n_d << std::endl;

    // Выражение 1: --m - ++n
    double res1_d = --m_d - ++n_d;
    std::cout << "1) --m - ++n  = " << res1_d 
              << " | m = " << m_d << ", n = " << n_d << std::endl;

    // Выражение 2: m * n < n++
    bool res2_d = (m_d * n_d < n_d++);
    std::cout << "2) m * n < n++ = " << res2_d 
              << " | m = " << m_d << ", n = " << n_d << std::endl;

    // Выражение 3: n-- > m++
    bool res3_d = (n_d-- > m_d++);
    std::cout << "3) n-- > m++   = " << res3_d 
              << " | m = " << m_d << ", n = " << n_d << std::endl;

    return 0;
}
