#include <iostream>
#include <iomanip>

using namespace std;

// Структура для представления обыкновенной дроби (числитель и знаменатель)
struct Fraction {
    int numerator;   // числитель
    int denominator; // знаменатель
};

// а) Перегруженная функция для деления десятичных дробей
double divide(double a, double b) {
    if (b == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return 0;
    }
    return a / b;
}

// б) Перегруженная функция для деления обыкновенных дробей
Fraction divide(Fraction f1, Fraction f2) {
    if (f2.numerator == 0) {
        cout << "Ошибка: деление на нулевую дробь (деление на ноль)!" << endl;
        return {0, 1};
    }
    if (f1.denominator == 0 || f2.denominator == 0) {
        cout << "Ошибка: знаменатель не может быть равен нулю!" << endl;
        return {0, 1};
    }

    Fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;

    // Сокращение знака (если знаменатель отрицательный, переносим минус в числитель)
    if (result.denominator < 0) {
        result.numerator = -result.numerator;
        result.denominator = -result.denominator;
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=== а) Деление десятичных дробей ===" << endl;
    double d1, d2;
    cout << "Введите делимое (десятичная дробь): ";
    cin >> d1;
    cout << "Введите делитель (десятичная дробь): ";
    cin >> d2;

    double decResult = divide(d1, d2);
    if (d2 != 0) {
        cout << fixed << setprecision(4);
        cout << "Результат деления: " << d1 << " / " << d2 << " = " << decResult << endl;
    }

    cout << "\n=== б) Деление обыкновенных дробей ===" << endl;
    Fraction f1, f2;
    cout << "Первая дробь (числитель и знаменатель через пробел): ";
    cin >> f1.numerator >> f1.denominator;
    cout << "Вторая дробь (числитель и знаменатель через пробел): ";
    cin >> f2.numerator >> f2.denominator;

    Fraction fracResult = divide(f1, f2);
    if (f2.numerator != 0 && f1.denominator != 0 && f2.denominator != 0) {
        cout << "Результат деления: (" << f1.numerator << "/" << f1.denominator 
             << ") / (" << f2.numerator << "/" << f2.denominator 
             << ") = " << fracResult.numerator << "/" << fracResult.denominator << endl;
    }

    return 0;
}
