#define _HAS_STD_BYTE 0
#define NOMINMAX
#include <iostream>
#include "LBWork4.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Matrix28
int taskMatrix28Console(vector<vector<int>> &matrix) {
    std::cout << "=== Задача №1 - Matrix28 === \n";
    if (matrix.empty()) {
        std::cout << "Матрица пуста. \n";
        return 1;
    }
    
    int n = matrix.size();
    int m = matrix[0].size();
    Matrix1(matrix, n, m);

    vector<int> MaxOfElCol(m);
    int MinOfMax = -100000;

    for (int j = 0; j < m; j++) {
        int MaxCol = -100000;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] > MaxCol) {
                MaxCol = matrix[i][j];
            }
        }
        MaxOfElCol[j] = MaxCol;
        if (j == 0 || MaxCol < MinOfMax) {
            MinOfMax = MaxCol;
        }
    }

    std::cout << "Максимальные элементы столбцов: ";
    for (int j = 0; j < m; j++) {
        std::cout << MaxOfElCol[j] << " ";
    }
    std::cout << "\n";
    std::cout << "Минимальный элемент среди максимальных в столбце: " << MinOfMax << "\n";
    return MinOfMax;
}

void taskMatrix28File(vector<vector<int>> &matrix) {
    ofstream f2("LBW4Answers.txt", ios::out);
    if (matrix.empty()) {
        std::cout << "Матрица пуста. \n";
        return;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> MaxOfElCol(m);
    int MinOfMax = -100000;
    for (int j = 0; j < m; j++) {
        int MaxCol = -100000;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] > MaxCol) {
                MaxCol = matrix[i][j];
            }
        }
        MaxOfElCol[j] = MaxCol;
        if (j == 0 || MaxCol < MinOfMax) {
            MinOfMax = MaxCol;
        }
    }

    f2 << "Максимальные элементы столбцов: ";
    for (int j = 0; j < m; j++) {
        f2 << MaxOfElCol[j] << " ";
    }
    f2 << "\n";
    f2 << "Минимальный элемент среди максимальных в столбце: " << MinOfMax << "\n";
    f2.close();
    std::cout << "Ответы на задачу записаны в файл 'LBW4Answers.txt'. \n";
    std::cout << "======= Конец задачи =======\n\n";
}

//Matrix55
int taskMatrix55(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        std::cout << "Матрица пуста. \n";
        return 1;
    }
    std::cout << "=== Задача №2 - Matrix55 ===";
    int n = matrix.size();
    int m = matrix[0].size();
    Matrix1(matrix, n, m);
    if (n % 2 != 0) {
        std::cout << "Ошибка, n должно быть чётным числом. Попробуйте ещё раз. \n";
        return 1;
    } else {
        int half = n / 2;
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < m; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i + half][j];
                matrix[i + half][j] = tmp;
            }
        }
        std::cout << "\n";
        Matrix2(matrix, n, m);
    }
    return 0;
}

void taskMatrix55File(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        std::cout << "Матрица пуста. \n";
        return;
    }
    ofstream f2("LBW4Answers.txt", ios::out);
    int n = matrix.size();
    int m = matrix[0].size();

    if (n % 2 != 0) {
        std::cout << "======= Конец задачи =======\n\n";
        return;
    } else {
        int half = n / 2;
        vector<vector<int>> result = matrix;
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < m; j++) {
                int temp = result[i][j];
                result[i][j] = result[i + half][j];
                result[i + half][j] = temp;
            }
        }
        f2 << "Итоговая матрица: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f2 << matrix[i][j] << " ";
            }
            f2 << "\n";
        }
        f2 << "\n";
    }
    f2.close();
    std::cout << "Результаты записаны в файл 'LBW4Answers.txt'.\n";
    std::cout << "======= Конец задачи =======\n\n";
}

//DArray6
int taskDArray6(vector<vector<int>> &matrixA) {
    if (matrixA.empty()) {
        std::cout << "Матрица пуста. \n";
        return 1;
    }
    std::cout << "=== Задача №3 - DArray6 ===\n";
    int n = matrixA.size();
    int m = matrixA[0].size();

    if (n != m) {
        std::cout << "Матрица должна быть квадратной!\n";
        return 1;
    } else {
        Matrix1(matrixA, n, m);
        vector<vector<int>> matrixB = matrixA;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i < j) { matrixB[i][j] = 0; }
            }
        }
        Matrix2(matrixB, n, m);
    }
    return 0;
}

int taskDArray6File(std::vector<std::vector<int>> &matrixA) {
    if (matrixA.empty()) {
        std::cout << "Матрица пуста. \n";
        return 1;
    }
    ofstream f2("LBW4Answers.txt", ios::out);
    int n = matrixA.size();
    int m = matrixA[0].size();

    if (n != m) {
        std::cout << "======= Конец задачи =======\n\n";
        return 1;
    } else {
        vector<vector<int>> matrixB = matrixA;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i < j) { matrixB[i][j] = 0; }
            }
        }
        f2 << "Итоговая матрица: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f2 << matrixB[i][j] << " ";
            }
            f2 << "\n";
        }
        std::cout << "Результаты записаны в файл 'LBW4Answers.txt'.\n";
        std::cout << "======= Конец задачи =======\n\n";
    }
    return 0;
}

//DArray16
int taskDArray16(vector<vector<int>> &matrix){
    std::cout << "=== Задача №4 - DArray16 ===\n";
    if (matrix.empty()) {
        std::cout << "Матрица пуста. \n";
        return 1;
    }

    int n = matrix.size();
    int m = matrix[0].size();
    Matrix1(matrix, n, m);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sumN = 0;
            int cntN = 0;
            if (i > 0) { //сверху
                sumN += matrix[i - 1][j];
                cntN++;
            }
            if (i < n - 1) { //снизу
                sumN += matrix[i + 1][j];
                cntN++;
            }
            if (j > 0) { //слева
                sumN += matrix[i][j - 1];
                cntN++;
            }
            if (j < m - 1) { //справа
                sumN += matrix[i][j + 1];
                cntN++;
            }
            if (cntN > 0 && matrix[i][j] == sumN) {
                cnt++;
                std::cout << "Элемент [" << i + 1 << "][" << j + 1 << "]" << " равен сумме соседей: " << sumN << "\n";
            }
        }
    }
    std::cout << "Кол-во таких элементов: " << cnt << "\n";
    std::cout << "\n";
    return 0;
}

int taskDArrey16File(vector<vector<int>> &matrix) {
    ofstream f2("LBW4Answers.txt", ios::out);
    if (matrix.empty()) {
        std::cout << "Матрица пуста. \n";
        return 1;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sumN = 0;
            int cntN = 0;
            if (i > 0) { // сверху
                sumN += matrix[i-1][j];
                cntN++;
            }
            if (i < n-1) { // снизу
                sumN += matrix[i+1][j];
                cntN++;
            }
            if (j > 0) { // слева
                sumN += matrix[i][j-1];
                cntN++;
            }
            if (j < m-1) { // справа
                sumN += matrix[i][j+1];
                cntN++;
            }
            if (cntN > 0 && matrix[i][j] == sumN) {
                cnt++;
                f2 << "Элемент [" << i + 1 << "][" << j + 1 << "]" << " равен сумме соседей: " << sumN << "\n";
            }
        }
    }
    f2 << "Кол-во таких элементов: " << cnt << "\n";
    std::cout << "Результаты записаны в файл 'LBW4Answers.txt'.\n";
    std::cout << "======= Конец задачи =======\n\n";
    return 0;
}

