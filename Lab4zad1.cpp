#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0) {
        cout << "Размер массива должен быть положительным.\n";
        return 0;
    }

    vector<int> a(n);

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Формирование массива с помощью rand() (числа от 0 до 100)
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 101; 
    }


    cout << "\nИсходный массив:\n";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (a[i] < a[minIndex]) {
            minIndex = i;
        }
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }
    }

    // Меняем местами через функцию swap
    swap(a[minIndex], a[maxIndex]);

    cout << "\nПосле обмена минимального и максимального элементов:\n";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    // Удалить из массива все элементы, превышающие его среднее значение более, чем на 10%
    double sum = 0;
    for (int x : a) {
        sum += x;
    }

    double average = sum / a.size();
    double limit = average * 1.10; 

    vector<int> newArray;
    for (int x : a) {
        
        if (x <= limit) {
            newArray.push_back(x);
        }
    }

    a = newArray;

    // Распечатать полученный массив
    cout << "\nСреднее значение: " << fixed << setprecision(2) << average << endl;
    cout << "Порог удаления (> среднее на 10%): " << limit << endl;

    cout << "Итоговый массив после удаления:\n";
    if (a.empty()) {
        cout << "Массив стал пустым." << endl;
    } else {
        for (int x : a) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}