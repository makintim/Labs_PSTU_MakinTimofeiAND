#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

int findMaxInRow(int matrix[MAX_ROWS][MAX_COLS], int row, int cols) {
    int maxVal = matrix[row][0];
    for (int j = 1; j < cols; ++j) {
        if (matrix[row][j] > maxVal) {
            maxVal = matrix[row][j];
        }
    }
    return maxVal;
}

// Функция для циклического сдвига одной строки вправо на k позиций
void shiftRowRight(int row[], int cols, int k) {
    if (cols <= 0) return;
    
    // Эффективный сдвиг, если сдвиг больше длины строки
    k = k % cols;
    if (k < 0) k += cols; // на случай отрицательных максимумов

    int temp[MAX_COLS];
    for (int j = 0; j < cols; ++j) {
        temp[(j + k) % cols] = row[j];
    }
    for (int j = 0; j < cols; ++j) {
        row[j] = temp[j];
    }
}

// Функция для циклического сдвига всех строк матрицы
void shiftAllRows(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        int maxVal = findMaxInRow(matrix, i, cols);
        cout << "Строка " << i << ": макс. элемент = " << maxVal << endl;
        shiftRowRight(matrix[i], cols, maxVal);
    }
}

// Функция для вывода матрицы на экран
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    int rows, cols;
    cout << "Введите количество строк (до " << MAX_ROWS << "): ";
    cin >> rows;
    cout << "Введите количество столбцов (до " << MAX_COLS << "): ";
    cin >> cols;

    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        cout << "Некорректный размер матрицы!" << endl;
        return 0;
    }

    int matrix[MAX_ROWS][MAX_COLS];

    // Заполнение матрицы случайными числами от 0 до 9
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 10; 
        }
    }

    cout << "\nИсходная матрица:\n";
    printMatrix(matrix, rows, cols);

    cout << "\n--- Процесс обработки ---\n";
    shiftAllRows(matrix, rows, cols);

    cout << "\nМатрица после циклического сдвига строк вправо:\n";
    printMatrix(matrix, rows, cols);

    return 0;
}