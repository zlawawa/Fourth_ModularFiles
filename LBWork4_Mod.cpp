#define _HAS_STD_BYTE 0
#define NOMINMAX
#include <iostream>
#include "LBWork4.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void FillKeyboard(vector<vector<int>> &matrix) {
    matrix.clear();
    int n, m;
    std::cout << "Введите размер массива n * m \n";
    std::cout << "Введите количество строк: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов: ";
    std::cin >> m;
    matrix.resize(n);          
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);   
    }
    std::cout << "Введите элементы матрицы: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void FillRandom(vector<vector<int>> &matrix, int n, int m) {
    matrix.clear();
    matrix.resize(n);         
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m); 
    }
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10 - 0;
        }
    }
    std::cout << "\nМатрица заполнена случайными числами! \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void FillOutTFiles(vector<vector<int>> &matrix, int &n, int &m) {
    ifstream f1("LBWork4.txt", ios::in);
    if (f1.is_open()) {
        f1 >> n >> m;
        matrix.resize(n);
        for (int i = 0; i < n; i++){
            matrix[i].resize(m);
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                f1 >> matrix[i][j];
            }
        }
        f1.close();
    }else{
        std::cout << "Error! \n";
        return;
    }
    std::cout << "Матрица заполнена числами из файла 'LBWork4.txt'!\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

//Matrix28
int taskMatrix28Console(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        std::cout << "Матрица пуста. \n";
        return 1;
    }
    std::cout << "=== Задача №1 - Matrix28 === \n";
    vector<int> MaxOfElCol;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < m; i++){
        MaxOfElCol.push_back(-100000);
    }
    
    for (int j = 0; j < m; j++) { 
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] > MaxOfElCol[j]){
                MaxOfElCol[j] = matrix[i][j];
            }
        }
    }
    int MinOfMax = MaxOfElCol[0]; 
    for (int i = 1; i < m; i++) {
        if (MaxOfElCol[i] < MinOfMax) {
            MinOfMax = MaxOfElCol[i];
        }
    }
    std::cout << "Максимальные эл-ты столбцов: ";
    for (int i = 0; i < m; i++) {
        std::cout << MaxOfElCol[i];
        if (i < m - 1) {
            std::cout << " ";
        }
    }
    std::cout << "\n";
    std::cout << "Минимальный элемент среди максимальных в столбце: " << MinOfMax << "\n";
    return MinOfMax;
}

void taskMatrix28File(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        std::cout << "Матрица пуста. \n";
        return;
    }
    ofstream f2("LBW4Answers.txt", ios::out);
    vector<int> MaxOfElCol;

    if (f2.is_open()) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < m; i++) {
            MaxOfElCol.push_back(-10000);
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] > MaxOfElCol[j]) {
                    MaxOfElCol[j] = matrix[i][j];
                }
            }
        }
        int MinOfMax = MaxOfElCol[0];
        for (int i = 0; i < m; i++) {
            if (MaxOfElCol[i] < MinOfMax) {
                MinOfMax = MaxOfElCol[i];
            }
        }
        f2 << "Максимальные эл-ты столбцов: ";
        for (int i = 0; i < m; i++) {
            f2 << MaxOfElCol[i];
            if (i < m - 1) {
                f2 << " ";
            }
        }
        f2 << "\n";
        f2 << "Минимальный элемент среди максимальных в столбце: " << MinOfMax << "\n";
    }
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
        std::cout << "Итоговая матрица: \n\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
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
        vector<vector<int>> matrixB = matrixA;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i >= j) { matrixB[i][j] = 0; }
            }
        }
        std::cout << "Итоговая матрица: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << matrixB[i][j] << " ";
            }
            std::cout << "\n";
        }
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
                if (i >= j) { matrixB[i][j] = 0; }
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
                f2 << "Элемент [" << i + 1 << "][" << j + 1 << "]" << " равен сумме соседей: " << sumN << "\n";
            }
        }
    }
    f2 << "Кол-во таких элементов: " << cnt << "\n";
    std::cout << "Результаты записаны в файл 'LBW4Answers.txt'.\n";
    std::cout << "======= Конец задачи =======\n\n";
    return 0;
}
int cat() {
    std::cout << "  /\\_/\\     /\\_/\\     /\\_/\\" << "\n";
    std::cout << " ( ^.^ )   ( 0.0 )   ( ^.^ )" << "\n";
    std::cout << "  > ^ <     > ^ <     > ^ <" << "\n";
    std::cout << " /  |  \\ / /  |  \\ / /  |  \\ /" << "\n";
    std::cout << " \\  |  //  \\  |  //  \\  |  //" << "\n";
    std::cout << "  ^^ ^^     ^^ ^^     ^^ ^^" << "\n";
    return 0;
}

