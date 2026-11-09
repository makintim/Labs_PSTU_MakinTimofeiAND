#include <iostream>
#include <cmath> // Для функции pow()
using namespace std;

// Функция для быстрого подсчёта факториала (без переполнения)
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    
    long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    
    return result;
}

int main() {
    int n;

    cout << "Введите целое положительное число n: ";
    cin >> n;

    // Вычисляем числитель и знаменатель отдельно
    double numerator = pow(2, n) * factorial(n);
    double denominator = pow(n, n);

    // Находим итоговое значение элемента a_n
    double element = numerator / denominator;

    // Выводим результат с заголовком
    cout << "\\nЭлемент ряда при n=" << n << ": " << element << endl;

    return 0;
}