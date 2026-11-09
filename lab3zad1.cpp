#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const int n = 35;
    const double eps = 0.0001;
    const double pi = acos(-1.0);

    const double a = 0.1;
    const double b = 0.8;
    const int k = 10;
    const double h = (b - a) / k;

    cout << fixed << setprecision(8);
    cout << "      x       S(n=35)       S(eps)       Exact y\n";

    for (int j = 0; j <= k; ++j) {
        // Вычисляем x так, чтобы последняя точка точно была 0.8
        double x = (j == k) ? b : a + j * h;

        // Сумма с заданным количеством членов n = 35
        double sumN = 0.0;

        for (int i = 1; i <= n; ++i) {
            sumN += pow(x, i) * cos(i * pi / 3.0) / i;
        }

        // Сумма с заданной точностью eps
        double sumEps = 0.0;
        double power = 1.0;
        int i = 1;

        while (true) {
            power *= x;
            double term = power * cos(i * pi / 3.0) / i;
            sumEps += term;

            // Оценка остатка ряда:
            // сумма модулей оставшихся членов не больше этой величины
            double remainderBound =
                pow(x, i + 1) / ((i + 1) * (1.0 - x));

            if (remainderBound < eps) {
                break;
            }

            ++i;
        }

        // Точное значение функции
        double exact = -0.5 * log(
            1.0 - 2.0 * x * cos(pi / 3.0) + x * x
        );

        cout << setw(8) << x
             << setw(15) << sumN
             << setw(15) << sumEps
             << setw(15) << exact << '\n';
    }

    return 0;
}
